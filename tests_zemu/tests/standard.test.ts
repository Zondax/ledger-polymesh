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

import Zemu, { DEFAULT_START_OPTIONS } from '@zondax/zemu'
import { newPolymeshApp } from '@zondax/ledger-substrate'
import { APP_SEED, models } from './common'

// @ts-ignore
import ed25519 from 'ed25519-supercop'
// @ts-ignore
import { blake2bFinal, blake2bInit, blake2bUpdate } from 'blakejs'
import { txBalances_transfer, txIdentity_addClaim, txSession_setKeys, txStaking_nominate, txUtility_batch } from './zemu_blobs'

const defaultOptions = {
  ...DEFAULT_START_OPTIONS,
  logging: true,
  custom: `-s "${APP_SEED}"`,
  X11: false,
}

jest.setTimeout(60000)

beforeAll(async () => {
  await Zemu.checkAndPullImage()
})

describe('Standard', function () {
  test.each(models)('can start and stop container', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
    } finally {
      await sim.close()
    }
  })

  test.each(models)('main menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      await sim.navigateAndCompareSnapshots('.', `${m.prefix.toLowerCase()}-mainmenu`, [1, 0, 0, 4, -5])
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get app version', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const resp = await app.getVersion()

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
      expect(resp).toHaveProperty('test_mode')
      expect(resp).toHaveProperty('major')
      expect(resp).toHaveProperty('minor')
      expect(resp).toHaveProperty('patch')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('get address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())

      const resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '2GufX4169bNZtEZowDhdWK7gknwKXa1zzAN5oij8tim8V2mr'
      const expected_pk = 'c55777790670bfd6bf012d79fd65f29afe233694d5af0a5e74783f13849fe29a'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-show_address`)

      const resp = await respRequest

      console.log(resp)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      const expected_address = '2GufX4169bNZtEZowDhdWK7gknwKXa1zzAN5oij8tim8V2mr'
      const expected_pk = 'c55777790670bfd6bf012d79fd65f29afe233694d5af0a5e74783f13849fe29a'

      expect(resp.address).toEqual(expected_address)
      expect(resp.pubKey).toEqual(expected_pk)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('show address - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())

      const respRequest = app.getAddress(0x80000000, 0x80000000, 0x80000000, true)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.navigateAndCompareUntilText('.', `${m.prefix.toLowerCase()}-show_address_reject`, 'REJECT')

      const resp = await respRequest
      console.log(resp)

      expect(resp.return_code).toEqual(0x6986)
      expect(resp.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic normal', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txBalances_transfer, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())

      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_normal`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign basic expert', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      // Change to expert mode so we can skip fields
      await sim.clickRight()
      await sim.clickBoth()
      await sim.clickLeft()

      const txBlob = Buffer.from(txBalances_transfer, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_basic_expert`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign utility.batch', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txUtility_batch, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_utility_batch_d3`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign utility.batch - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txUtility_batch, 'hex')

      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.navigateAndCompareUntilText('.', `${m.prefix.toLowerCase()}-sign_utility_batch_reject`, 'REJECT')

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x6986)
      expect(signatureResponse.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign identity.addClaim', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txIdentity_addClaim, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_identity_addclaim`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign identity.addClaim - reject', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txIdentity_addClaim, 'hex')

      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)

      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.navigateAndCompareUntilText('.', `${m.prefix.toLowerCase()}-sign_identity_addclaim_reject`, 'REJECT')

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x6986)
      expect(signatureResponse.error_message).toEqual('Transaction rejected')
    } finally {
      await sim.close()
    }
  })

  test.each(models)('sign large nomination', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txStaking_nominate, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-sign_nomination`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })

  test.each(models)('set keys', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())
      const pathAccount = 0x80000000
      const pathChange = 0x80000000
      const pathIndex = 0x80000000

      const txBlob = Buffer.from(txSession_setKeys, 'hex')

      const responseAddr = await app.getAddress(pathAccount, pathChange, pathIndex)
      const pubKey = Buffer.from(responseAddr.pubKey, 'hex')

      // do not wait here.. we need to navigate
      const signatureRequest = app.sign(pathAccount, pathChange, pathIndex, txBlob)
      // Wait until we are not in the main menu
      await sim.waitUntilScreenIsNot(sim.getMainMenuSnapshot())
      await sim.compareSnapshotsAndApprove('.', `${m.prefix.toLowerCase()}-set-keys`)

      const signatureResponse = await signatureRequest
      console.log(signatureResponse)

      expect(signatureResponse.return_code).toEqual(0x9000)
      expect(signatureResponse.error_message).toEqual('No errors')

      // Now verify the signature
      let prehash = txBlob
      if (txBlob.length > 256) {
        const context = blake2bInit(32)
        blake2bUpdate(context, txBlob)
        prehash = Buffer.from(blake2bFinal(context))
      }
      const valid = ed25519.verify(signatureResponse.signature.slice(1), prehash, pubKey)
      expect(valid).toEqual(true)
    } finally {
      await sim.close()
    }
  })
})
