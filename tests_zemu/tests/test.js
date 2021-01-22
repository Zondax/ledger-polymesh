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

import jest, {expect} from "jest";
import Zemu from "@zondax/zemu";
const {newPolymathApp} = require("@zondax/ledger-polkadot");

const ed25519 = require("ed25519-supercop");
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";

const Resolve = require("path").resolve;
const APP_PATH = Resolve("../app/bin/app.elf");

const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"
const sim_options = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    //X11: true
};

jest.setTimeout(60000)

describe('Basic checks', function () {
    test('can start and stop container', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
        } finally {
            await sim.close();
        }
    });

    test('get app version', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolymathApp(sim.getTransport());
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

    test('get address', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolymathApp(sim.getTransport());

            const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000);

            console.log(resp)

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "2DtHHz6WwfxB7JMzZ7mMw3cxzffBrvU9xTgqYqsaP4EEUGzD";
            const expected_pk = "3f94b432d8db17738656f93bb685094c3ad308c9607ef4a8807b6930a1304fb4";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);

        } finally {
            await sim.close();
        }
    });

    test('show address', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolymathApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "show_address", 3);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x9000);
            expect(resp.error_message).toEqual("No errors");

            const expected_address = "2DtHHz6WwfxB7JMzZ7mMw3cxzffBrvU9xTgqYqsaP4EEUGzD";
            const expected_pk = "3f94b432d8db17738656f93bb685094c3ad308c9607ef4a8807b6930a1304fb4";

            expect(resp.address).toEqual(expected_address);
            expect(resp.pubKey).toEqual(expected_pk);
        } finally {
            await sim.close();
        }
    });

    test('sign basic', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolymathApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0000bd494f87d503ae1103008ed73e0ddd0700000500000012fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c712fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c7";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "sign_basic", 4);

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

    test('sign large nomination', async function () {
        const sim = new Zemu(APP_PATH);
        try {
            await sim.start(sim_options);
            const app = newPolymathApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "24026bc40000000000000127c1210001000800000000000001000800000000000008cce2bd1bf485643a80bcd14091326632501ef80fcff04d9ca08adedc6e65389c0140e2010000000000424e3d8c4553fcf20ef3694464333dcf9c4d3f0c16c47213221d9f37b9b5d5220140e2010000000000544b52415354000000000000a08601000000000000000000000000005992f519733534fed05d2d98ba21c4da22282d39a5a4a725779a5aacccba8b960140e20100000000006cb4e5edb9a93bdb9ab340c8cb7c0ab4001e19264823a0373d2b510a2661ee6a0140e2010000000000544b52415354420000000000a0860100000000000000000000000000d503ae11030033158139ae28a3dfaac5fe1560a5e9e05cdd0700000500000012fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c712fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c7";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "sign_large_nomination", 24);

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

});
