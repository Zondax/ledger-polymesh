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
    custom: `-s "${APP_SEED}"`
    , X11: true
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

            let txBlobStr = "000009612869d50391018ed73e0dd107000001000000d561a98b341d86c642c5ac5a8603fc537c136c38472e451c73229a372197cfacd561a98b341d86c642c5ac5a8603fc537c136c38472e451c73229a372197cfac";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "sign_basic", 10);

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

            let txBlobStr = "090060b99a68869326e6fc07525dd343f61fa41758169c28cd9d8cf6a777514faff52c3eba74753062d6cefbeea096f3281e61ef7842403723da5a3234c29189afeece84b9d4038b5d490ceb885d0d4fcedc59234cb34dd0cf9eb9cce79d2c157464f601b26bdd489327ee761bd18620a7d036c8161535d6a4c2fe105ddf117c289f0102596125743536eeca69cc77b12286cd71b8d64ac56d316374e2ec98b8d5763c304fbeabbb80a50b5e9108dd849ffa45d26a80d0a0cfe2fbb893a2649a3ff303f1228ae387bd76994909da1dd73810dc8688a0fd898fc3d175f2132cd93c942b50983125698b3aa06cea209a3aaec6ab1b15159a7b7c657d8760262af970895ad1d5038d248ed73e0dd107000001000000d561a98b341d86c642c5ac5a8603fc537c136c38472e451c73229a372197cfacd561a98b341d86c642c5ac5a8603fc537c136c38472e451c73229a372197cfac";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", "sign_large_nomination", 25);

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
