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

// @ts-ignore
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
import {APP_SEED} from "./common";
const addon = require('../../tests_tools/neon/native');

const Resolve = require("path").resolve;
const APP_PATH = Resolve("../app/output/app_sr25519.elf");

const defaultOptions = {
    ...DEFAULT_START_OPTIONS,
    logging: true,
    custom: `-s "${APP_SEED}"`,
    X11: false,
    model: 'nanos'
};

jest.setTimeout(60000)

describe('SR25519', function () {
    test('get address sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolymeshApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000, false, 1);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "2HM5HBpdm3nuMze95qGWPYNypPvhtTbxDwCdLCBXx5zadMSS";
            const expected_pk = "d8b89698f0deb2b2023ec1dd1a2ca06f01c4db6114648adb02e18dfd12dae77c";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test('show address sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolymeshApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-show_address_sr25519", 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "2HM5HBpdm3nuMze95qGWPYNypPvhtTbxDwCdLCBXx5zadMSS";
            const expected_pk = "d8b89698f0deb2b2023ec1dd1a2ca06f01c4db6114648adb02e18dfd12dae77c";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test('show address - reject sr25519', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolymeshApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());
            await sim.compareSnapshotsAndAccept(".", "s-show_address_reject_sr25519", 3, 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test('sign basic normal', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            const txBlobStr = "040000287e8d895a3e642fa19a9c5ed97bec0d7cfc63bdb3641fc98a9c926cf0e8e93c0b63ce64c10c05d503910133158139ae28a3dfaac5fe1560a5e9e05ce1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_normal", 5);

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
            const signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign basic expert', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            const txBlobStr = "040000287e8d895a3e642fa19a9c5ed97bec0d7cfc63bdb3641fc98a9c926cf0e8e93c0b63ce64c10c05d503910133158139ae28a3dfaac5fe1560a5e9e05ce1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_expert", 11);

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
            const signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test('sign large nomination', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start({...defaultOptions});
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            const txBlobStr = "080540006e34558d8a0255d837207a78038826d5d6d868803bf19b4ac79c1f25551b607e00ec437f7d7c48fdcc7a0ec4b81304509c2715e80c2eea6c037f12c8b6f82d721f004423c993381a2248ad4e932ad857a59885dcd7816511fc98f1508bc7f5a48629002898b4f6d6fe083f6519fbec6878b617bd78fa24374e17c890d0f9ed41a29871009009fbc535f95ad1de9c8a21a9065b6b75761c1a88e51185075a2cbf44d101420054f7a0a6bb84f3babb8a77d770f2f43f58dc5468bea686f94038cfc8084b6d7f0098e7890acb6a1f84116a7b551f92f4c172a965d390c9368b54d9163a1620677c009ed61e5fac1d7d5d3a7f49f493c193ed5a8638755d4aaa8ae962f5c1a137993600ecf83d0d9baef51d1e5b58b372994b021970074b703574c9b73c351279c6946f0052c204370e503d59a63f7309aeb42ba79ba21cab309d5356f2751178bca9fd7900304d53f51a0af0d280bcfc76ff307a1f6d8a5d4917bbe36cc157b3637f1e0f2200007e1bae1f1c9106734faec4c6ac2229bfa83d513d3c9edb14130ad825757b1c001603b70d5dd403242e01e428311746ed265c91135e4e2a0f74e5e520b741cc57000eea86b8cbf40083d66aff6631b6ac4c97ffe1dba7c04e67d6ba3ad0b9775648005ed646319954b783e397d2ae8dbf8d56e4868a7dbb57228d6c67be02b26712260008df51facad217e63431beeb63e42f7a3e03dfbedc1be252e83a61014f481e6ad503910100e1070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `s-sign_large_nomination_sr25519`, 33);

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
            const signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey, signingcontext, prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });
});
