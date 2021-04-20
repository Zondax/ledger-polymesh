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
    startDelay: 4000,
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

            const txBlobStr = "0500ff40f53afc3e2ac603eae342a2f18e4cc456cd12e77aaf4eddea2045c4fb5d39966d0fd5030000e2070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_normal", 4);

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

            const txBlobStr = "0500ff40f53afc3e2ac603eae342a2f18e4cc456cd12e77aaf4eddea2045c4fb5d39966d0fd5030000e2070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "s-sign_basic_expert", 10);

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

            const txBlobStr = "110520ff3a74572ba8f3136c8fadd394cea53e7f1e8b6cb0dd35969db363abf52fc99b30ff305429035c83eab3af45c8324d5bc36a659f2cedfb36198156d0287f7f501107ff1a81532ef75c44acf3e5bf12d614b91fd5019276879bc8f0eac5a046b0c15277ffc8ee4c5e6d3ae0468077fa791e0468c90efff0ad9d3098b58f578d97a6465801ffc4faf3ff6cea6d0cc39dce4af2f126087a5b4221a0fe9903d22aaf5bd248e010ff06ea6ede1e2dd9cc9ab286762ed6732db47df39fc0f9d5a47a53325100c94f75fff065ea2f702c2cdd21abcfc6867404423fe2c0ecce2fecbdcfee28d481994d18ff8a9170375fef6774fe9381eace15328d1a2cce7809ced520edd75be93567e82dd5038d2400e2070000070000009deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f9deeb940c92ae02111c3bd5baca89970384f4c9849f02a1b2e53e66414d30f9f";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `s-sign_large_nomination_sr25519`, 17);

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
