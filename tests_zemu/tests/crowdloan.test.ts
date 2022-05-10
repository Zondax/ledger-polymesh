/** ******************************************************************************
 *  (c) 2018 - 2022 Zondax GmbH
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

async function activateCrowdloanMode(sim: any) {
  // Crowdloan can be activate only when expert mode is enabled
  await sim.clickRight()
  await sim.clickRight()
  await sim.clickBoth('', false)
  await sim.clickBoth('', false)
  await sim.clickLeft()
  await sim.clickLeft()

  // Activale Expert mode
  await sim.clickRight()
  await sim.clickBoth()

  //Activate Crowdloan
  await sim.clickRight()
  await sim.clickBoth()

  // Review warning message
  const reviewSteps = sim.startOptions.model === 'nanos' ? 6 : 5
  for (let i = 0; i < reviewSteps; i += 1) {
    await sim.clickRight()
  }

  // Accept
  await sim.clickBoth()

  // Just go forward
  await sim.clickRight()
  await sim.clickRight()
}

describe('Crowdloan', function () {
  test.each(models)('crowdloan menu', async function (m) {
    const sim = new Zemu(m.path)
    try {
      await sim.start({ ...defaultOptions, model: m.name })
      const app = newPolymeshApp(sim.getTransport())

      const polymesh_expected_address = '2GufX4169bNZtEZowDhdWK7gknwKXa1zzAN5oij8tim8V2mr'
      const polymesh_expected_pk = 'c55777790670bfd6bf012d79fd65f29afe233694d5af0a5e74783f13849fe29a'
      const polkadot_expected_address = '2HYrbcQFUokNTpTBt49GA6sbgLj8Dfb6kCBgdWV7j5WqQfhL'
      const polkadot_expected_pk = 'e1b4d72d27b3e91b9b6116555b4ea17138ddc12ca7cdbab30e2e0509bd848419'

      let resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)
      expect(resp.address).toEqual(polymesh_expected_address)
      expect(resp.pubKey).toEqual(polymesh_expected_pk)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')

      await activateCrowdloanMode(sim)

      resp = await app.getAddress(0x80000000, 0x80000000, 0x80000000)

      console.log(resp)
      expect(resp.address).toEqual(polkadot_expected_address)
      expect(resp.pubKey).toEqual(polkadot_expected_pk)

      expect(resp.return_code).toEqual(0x9000)
      expect(resp.error_message).toEqual('No errors')
    } finally {
      await sim.close()
    }
  })
})
