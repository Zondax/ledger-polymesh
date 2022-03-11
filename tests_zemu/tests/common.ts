import { DeviceModel } from '@zondax/zemu'

const Resolve = require('path').resolve

export const APP_SEED = 'equip will roof matter pink blind book anxiety banner elbow sun young'

const APP_PATH_S = Resolve('../app/output/app_s.elf')
const APP_PATH_X = Resolve('../app/output/app_x.elf')
const APP_PATH_SP = Resolve('../app/output/app_s2.elf')

export const models: DeviceModel[] = [
  { name: 'nanos', prefix: 'S', path: APP_PATH_S },
  { name: 'nanox', prefix: 'X', path: APP_PATH_X },
  { name: 'nanosp', prefix: 'SP', path: APP_PATH_SP },
]

//    "name": "Balances_Transfer",
export const txBasic =
  '05000013a14fa0f1fe52528e09d5389421a0fa4bcdde72375d2ecc6e48749e6e24bb540b63ce64c10c05d50391018ed73e0dba0b0000020000006fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f40636fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f4063'

//     "name": "Staking_Nominate",
export const txNomination =
  '11052000c4b70322352027c627514442cd349ee8c094650837acb0b879892e2223764056009208606d2e8b73acd1acce74fb3320482b34645a1dc76caafceea2159b93fe71002c47fe26c704c761aa21eea816eda451753e86d5839d61895d4bab4a685aab67002a02b09bc988b0c166a6f012c303382924d259f85f5c4f4b57bd3472fd9a781200664a8d535548763f21bafd9ebc039bcab687a15591c69559b2a644c50ec4de5e007492ce58220ae11dbcd13b729faca6c0d44f9f950de5cdd7d7dafc510e5c837b001838ebcf5c582764f277154b04ed9f6cbd7159958f003209c4b117b3eec0c06b00b6776709523996361cec3aaf2b135d5852e6dd892c463fb7949597610f2c0078d5038d248ed73e0dba0b0000020000006fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f40636fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f4063'

//     "name": "Utility_Batch",
export const txBatch =
  '29000c110c31463758677235564d355269596d6b437853317857483647626342675341354a0101000000110c31463758677235564d355269596d6b437853317857483647626342675341354a0102000000110910d5038d2400ba0b0000020000006fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f40636fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f4063'

//     "name": "Add claim Jurisdiction",
export const txJurisdiction =
  '07071f84233414f7e3c7a68b7c1edbe7559f0d81daef8df4a3439b8795eb2f0e28970600015449434b45522d3537323132010008000000000000d50391016d0fba0b0000020000006fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f40636fbd74e5e1d0a61d52ccfe9d4adaed16dd3a7caa37c6bc4d0c2fa12e8b2f4063'
