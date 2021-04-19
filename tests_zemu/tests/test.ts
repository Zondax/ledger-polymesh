/** ******************************************************************************
 *  (c) 2020 Zondax GmbH
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************* */

import Zemu, {DEFAULT_START_OPTIONS} from "@zondax/zemu";
import {newPolymeshApp} from "@zondax/ledger-polkadot";
import {APP_SEED, models} from "./common";

// @ts-ignore
import ed25519 from "ed25519-supercop";
// @ts-ignore
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";

const defaultOptions = {
    ...DEFAULT_START_OPTIONS,
    logging: true,
    custom: `-s "${APP_SEED}"`,
    X11: false,
};

jest.setTimeout(60000)

describe('Standard', function () {
    test.each(models)('can start and stop container', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
        } finally {
            await sim.close();
        }
    });

    test.each(models)('main menu', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-mainmenu`, 3);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('get app version', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const resp = await app.getVersion();

            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");
            expect(resp).toHaveProperty("test_mode");
            expect(resp).toHaveProperty("major");
            expect(resp).toHaveProperty("minor");
            expect(resp).toHaveProperty("patch");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('get address', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "2GufX4169bNZtEZowDhdWK7gknwKXa1zzAN5oij8tim8V2mr";
            const expected_pk = "c55777790670bfd6bf012d79fd65f29afe233694d5af0a5e74783f13849fe29a";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('show address', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-show_address`, 2);

            const resp = await respRequest;

            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "2GufX4169bNZtEZowDhdWK7gknwKXa1zzAN5oij8tim8V2mr";
            const expected_pk = "c55777790670bfd6bf012d79fd65f29afe233694d5af0a5e74783f13849fe29a";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('show address - reject', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-show_address_reject`, 3, 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic normal', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            const txBlobStr = "040000287e8d895a3e642fa19a9c5ed97bec0d7cfc63bdb3641fc98a9c926cf0e8e93c0b63ce64c10c05d503910133158139ae28a3dfaac5fe1560a5e9e05ce1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-sign_basic_normal`, m.name === "nanos" ? 6 : 6);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic expert (%s)', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            let txBlobStr = "040000287e8d895a3e642fa19a9c5ed97bec0d7cfc63bdb3641fc98a9c926cf0e8e93c0b63ce64c10c05d503910133158139ae28a3dfaac5fe1560a5e9e05ce1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-sign_basic_expert`, m.name === "nanos" ? 12 : 12);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign utility.batch (%s)', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            const txBlobStr = "29000c080c31463758677235564d355269596d6b437853317857483647626342675341354a0101000000080c31463758677235564d355269596d6b437853317857483647626342675341354a0102000000080910d5030400e1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-sign_utility_batch_d3`, m.name === "nanos" ? 11 : 12);

            const signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign utility.batch - reject (%s)', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            const txBlobStr = "29000c080c31463758677235564d355269596d6b437853317857483647626342675341354a0101000000080c31463758677235564d355269596d6b437853317857483647626342675341354a0102000000080910d5030400e1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";
            const txBlob = Buffer.from(txBlobStr, "hex");

            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);

            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-sign_utility_batch_reject`, m.name === "nanos" ? 12 : 13);

            const signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x6986);
            expect(signatureResponse.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign large nomination (%s)', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            const txBlobStr = "080540006e34558d8a0255d837207a78038826d5d6d868803bf19b4ac79c1f25551b607e00ec437f7d7c48fdcc7a0ec4b81304509c2715e80c2eea6c037f12c8b6f82d721f004423c993381a2248ad4e932ad857a59885dcd7816511fc98f1508bc7f5a48629002898b4f6d6fe083f6519fbec6878b617bd78fa24374e17c890d0f9ed41a29871009009fbc535f95ad1de9c8a21a9065b6b75761c1a88e51185075a2cbf44d101420054f7a0a6bb84f3babb8a77d770f2f43f58dc5468bea686f94038cfc8084b6d7f0098e7890acb6a1f84116a7b551f92f4c172a965d390c9368b54d9163a1620677c009ed61e5fac1d7d5d3a7f49f493c193ed5a8638755d4aaa8ae962f5c1a137993600ecf83d0d9baef51d1e5b58b372994b021970074b703574c9b73c351279c6946f0052c204370e503d59a63f7309aeb42ba79ba21cab309d5356f2751178bca9fd7900304d53f51a0af0d280bcfc76ff307a1f6d8a5d4917bbe36cc157b3637f1e0f2200007e1bae1f1c9106734faec4c6ac2229bfa83d513d3c9edb14130ad825757b1c001603b70d5dd403242e01e428311746ed265c91135e4e2a0f74e5e520b741cc57000eea86b8cbf40083d66aff6631b6ac4c97ffe1dba7c04e67d6ba3ad0b9775648005ed646319954b783e397d2ae8dbf8d56e4868a7dbb57228d6c67be02b26712260008df51facad217e63431beeb63e42f7a3e03dfbedc1be252e83a61014f481e6ad503910100e1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-sign_large_nomination`, m.name === "nanos" ? 33 : 18);

            const signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('nested tx - lvl2 - sign expert (%s)', async function (m) {
        const sim = new Zemu(m.path);
        try {
            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            const txBlobStr = "160300110300b816d6e5c9403379862c457a463b0c561e0af0708ed0069a0d7cba51ec44d7d6000058000000d50391018ed73e0de1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-sign_nested_2_expert`, m.name === "nanos" ? 14 : 14);

            const signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('nested tx - lvl3 - sign expert (%s)', async function (m) {
        const sim = new Zemu(m.path);
        try {

            if(m.name === "nanos") { // This level is only for nanoX
                return;
            }

            await sim.start({...defaultOptions, model: m.name,});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            const txBlobStr = "1603001103002f769ae07fff20645edc5319382b4bd4eca7f59ab2e7accc35f17ec856d91fb4110300a655dfa214bfce9f89a5fbaeb01312faf0437070570e37cc5dca70528c3ad228110300567c34919ecdf1e8b56ac3044e5b98b00e58e3a3364137e8c95dc3545de6b0c3000058000000d5038d248ed73e0de1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${m.prefix.toLowerCase()}-sign_nested_3_expert`, m.name === "nanos" ? 16 : 18);

            const signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x9000);
            expect(signatureResponse.error_message).toEqual("No errors");

            // Now verify the signature
            let prehash = txBlob;
            if (txBlob.length > 256) {
                const context = blake2bInit(32, null);
                blake2bUpdate(context, txBlob);
                prehash = Buffer.from(blake2bFinal(context));
            }
            const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey);
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });
});
