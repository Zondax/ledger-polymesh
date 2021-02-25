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
import {blake2bFinal, blake2bInit, blake2bUpdate} from "blakejs";
var addon = require('../../tests_tools/neon/native');

const {newPolymeshApp} = require("@zondax/ledger-polkadot");
const Resolve = require("path").resolve;

const APP_PATH_S = Resolve("../app/output/app_sr25519.elf");
const APP_SEED = "equip will roof matter pink blind book anxiety banner elbow sun young"

var simOptions = {
    logging: true,
    start_delay: 3000,
    custom: `-s "${APP_SEED}"`,
    X11: true
};

let models = [
    ['S', {model: 'nanos', prefix: 'S', path: APP_PATH_S}],
]

jest.setTimeout(60000)

describe('SR25519', function () {
    test.each(models)('get address (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
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

    test.each(models)('show address (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
            const app = newPolymeshApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-show_address_sr25519`, 2);

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

    test.each(models)('show address - reject (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
            const app = newPolymeshApp(sim.getTransport());

            const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-show_address_reject_sr25519`, 3, 2);

            const resp = await respRequest;
            console.log(resp);

            expect(resp.return_code).toEqual(0x6986);
            expect(resp.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic normal (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "0000bd494f87d503ae1103008ed73e0ddd0700000500000012fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c712fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c7";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_normal_sr25519`, model === "nanos" ? 3 : 4);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic expert (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            // Change to expert mode so we can skip fields
            await sim.clickRight();
            await sim.clickBoth();
            await sim.clickLeft();

            let txBlobStr = "24026bc40000000000000127c1210001000800000000000001000800000000000008cce2bd1bf485643a80bcd14091326632501ef80fcff04d9ca08adedc6e65389c0140e2010000000000424e3d8c4553fcf20ef3694464333dcf9c4d3f0c16c47213221d9f37b9b5d5220140e2010000000000544b52415354000000000000a08601000000000000000000000000005992f519733534fed05d2d98ba21c4da22282d39a5a4a725779a5aacccba8b960140e20100000000006cb4e5edb9a93bdb9ab340c8cb7c0ab4001e19264823a0373d2b510a2661ee6a0140e2010000000000544b52415354420000000000a0860100000000000000000000000000d503ae11030033158139ae28a3dfaac5fe1560a5e9e05cdd0700000500000012fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c712fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c7";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false , 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);

            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_expert_sr25519`, model === "nanos" ? 29 : 30);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic - forward/backward (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "29000400002c000000d50391010b63ce64c10c05dd0700000500000012fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c712fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c7";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_FB_sr25519`, model === "nanos" ? 4 : 5, 1);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign basic - forward/backward-reject (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "29000800002c000000000058000000d503910100dd0700000500000012fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c712fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c7";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_basic_FB_reject_sr25519`, model === "nanos" ? 7 : 8, 1);

            let signatureResponse = await signatureRequest;
            console.log(signatureResponse);

            expect(signatureResponse.return_code).toEqual(0x6986);
            expect(signatureResponse.error_message).toEqual("Transaction rejected");
        } finally {
            await sim.close();
        }
    });

    test.each(models)('sign large nomination (%s)', async function (_, {model, prefix, path}) {
        const sim = new Zemu(path);
        try {
            await sim.start(simOptions);
            const app = newPolymeshApp(sim.getTransport());
            const pathAccount = 0x80000000;
            const pathChange = 0x80000000;
            const pathIndex = 0x80000000;

            let txBlobStr = "08054000f0c74a8500c5b8c96a648236886f8a92b96a9f52791ffc6ab801a034887ebf4f0080a01d8a0c982bb5168a76bc6387f6c5c07121b1708d2d6189fa4b4aa336113700ecf8fd4b9c748a7baf6d83933f4a470a394a4cb97375dc747be58222dae6fe660028ab7c39c82820284f6513a5709ce60db444127363fb62ea941a22bca777d95900a2a56d7e838653933fd36e5a0a307bd9c1fc196af9ed29eacfe31ea41540776600e63166b3416619b8fc5501054ba6ccabacf8168e221363ec7e12c95ea66b7623000ef4bd969740ccc4a860d2b60e2df766f92b075b985ca178ef5581c22681fe0b007ede40cfeb8592d7626347bfb8ebdfacaaaa3350c982d384d9ac6f183c0ab90c00be7b7b9260071da18923cbeb5ba56c8df53490c80baaf8f7a53b17756ec6ed0a008ab9ee1d7ddd0a41918baba2221b63758195cdef662e94cb1b0410bfad8da37e000e95f6bf1d64fb2765af2202a8f262f7e02d49c2d7a55de644dcbb26e658522f00365cb5c9480ab97bf756d4d14109e43285717d3e47073491af6134bd027bdc06008e97da96e2323b8ee4976da07cd1514bf4a7a123bdab1e2a74aec405d6ca644600f6ada0eec0bf9b898e8d51f5f3939a6b3cf2e0e17ed5b778c6002e6e97c1af0100dc12f0393490fc9254cbeb68d57151687927721f2bb751aed8e41f8bd47fd41100ea5a4502661aa5acfffff661832590c0d99b1e0c9a0f6fdcac4c00e58080e771d50391010b63ce64c10c05dd0700000500000012fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c712fddc9e2128b3fe571e4e5427addcb87fcaf08493867a68dd6ae44b406b39c7";

            const txBlob = Buffer.from(txBlobStr, "hex");

            const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex, false, 1);
            const pubKey = Buffer.from(responseAddr.pubKey, "hex");

            // do not wait here.. we need to navigate
            const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob, 1);
            // Wait until we are not in the main menu
            await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot());

            await sim.compareSnapshotsAndAccept(".", `${prefix.toLowerCase()}-sign_large_nomination_sr25519`, model === "nanos" ? 34 : 19);

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
            let signingcontext = Buffer.from([]);
            const valid = addon.schnorrkel_verify(pubKey,signingcontext,prehash, signatureResponse.signature.slice(1));
            expect(valid).toEqual(true);
        } finally {
            await sim.close();
        }
    });

});
