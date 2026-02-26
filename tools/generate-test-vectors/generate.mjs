/**
 * Polymesh Test Vector Generator for Ledger Generic App
 *
 * Discovers all pallets/methods from the runtime, auto-generates dummy
 * parameters via a recursive type walker, builds signing payloads with
 * CheckMetadataHash + MetadataProof, and writes JSON test vectors.
 *
 * Usage:
 *   node generate.mjs [--endpoint wss://...] [--no-capture] [--only pallet.method,...] [--skip pallet.method,...]
 *
 * Options:
 *   --endpoint    WebSocket endpoint (default: wss://dev.polymesh.tech/forked/staging/)
 *   --no-capture  Skip the C++ capture step (output/output_expert fields will be empty)
 *   --only        Comma-separated list of pallet.method to generate (e.g., balances.transfer,system.remark)
 *   --skip        Comma-separated list of pallet.method to skip
 *   --seed        Integer seed for deterministic random generation (default: 42)
 */

import { ApiPromise, WsProvider } from '@polkadot/api'
import { u8aToHex } from '@polkadot/util'
import { merkleizeMetadata } from '@polkadot-api/merkleize-metadata'
import { writeFileSync, readFileSync } from 'fs'
import { join, dirname } from 'path'
import { fileURLToPath } from 'url'
import { execSync } from 'child_process'

const __dirname = dirname(fileURLToPath(import.meta.url))

// Parse CLI args
const args = process.argv.slice(2)
function getArg(name) {
  const idx = args.indexOf(name)
  return idx >= 0 ? args[idx + 1] : null
}
function hasFlag(name) {
  return args.includes(name)
}

const ENDPOINT = getArg('--endpoint') || 'wss://dev.polymesh.tech/forked/staging/'
const NO_CAPTURE = hasFlag('--no-capture')
const ONLY = getArg('--only')?.split(',').map(s => s.trim().toLowerCase()) || null
const SKIP = new Set(getArg('--skip')?.split(',').map(s => s.trim().toLowerCase()) || [])
const SEED = parseInt(getArg('--seed') || '42', 10)

// Load type overrides
let typeOverrides = {}
try {
  const raw = readFileSync(join(__dirname, 'type-overrides.json'), 'utf8')
  typeOverrides = JSON.parse(raw)
  delete typeOverrides._comment
} catch (e) {
  console.warn('Warning: Could not load type-overrides.json:', e.message)
}

// Well-known test addresses (sr25519 dev accounts, SS58 prefix 42)
const TEST_ADDRESSES = [
  '5GrwvaEF5zXb26Fz9rcQpDWS57CtERHpNehXCPcNoHGKutQY', // Alice
  '5FHneW46xGXgs5mUiveU4sbTyGBzmstUspZC92UhjJM694ty', // Bob
  '5FLSigC9HGRKVhB9FiEo4Y3koPsNmBmLJbpXg2mp1hXcS59Y', // Charlie
  '5DAAnrj7VHTznn2AWBemMuyBwZWs6FNFjdyVXUeYum3PTXFy', // Dave
  '5HGjWAeFDfFCWPsjFQdVV2Msvz2XtMktvgocEZcCj68kUMaw', // Eve
]
// Named aliases for use in JSON-like overrides
const ALICE = TEST_ADDRESSES[0] // eslint-disable-line no-unused-vars
const BOB = TEST_ADDRESSES[1]   // eslint-disable-line no-unused-vars

/** Pick a random test address */
function randomAddress() {
  return TEST_ADDRESSES[randomInt(0, TEST_ADDRESSES.length - 1)]
}

// Module-level api reference for nested Call generation
let _api = null

// --- Seeded PRNG (mulberry32) for deterministic test vector generation ---
// Using a seed ensures the same output on every run (unless --seed is changed).
function createSeededRandom(seed) {
  let s = seed | 0
  return function () {
    s = (s + 0x6D2B79F5) | 0
    let t = Math.imul(s ^ (s >>> 15), 1 | s)
    t = (t + Math.imul(t ^ (t >>> 7), 61 | t)) ^ t
    return ((t ^ (t >>> 14)) >>> 0) / 4294967296
  }
}

const rng = createSeededRandom(SEED)

/** Generate a random hex string of `len` bytes (e.g. 16 → 0x + 32 hex chars) */
function randomHex(len) {
  const buf = Buffer.alloc(len)
  for (let i = 0; i < len; i++) buf[i] = Math.floor(rng() * 256)
  return '0x' + buf.toString('hex')
}

/** Random integer in [min, max] (inclusive) */
function randomInt(min, max) {
  return Math.floor(rng() * (max - min + 1)) + min
}

/** Random boolean */
function randomBool() {
  return rng() < 0.5
}

/**
 * Recursive type walker: generates a valid JS value for a given Polkadot.js type.
 *
 * @param {object} registry - Polkadot.js type registry
 * @param {object} typeDef  - Type definition from registry
 * @param {number} depth    - Recursion depth (max 10)
 * @param {boolean} safe    - Safe mode: use conservative defaults for Option/Vec/Enum
 *                            (used on retry after complex generation fails)
 */
function generateDummyValue(registry, typeDef, depth = 0, safe = false) {
  if (depth > 10) return 0

  const type = typeDef.type || typeDef.lookupName || typeDef.toString?.() || ''
  const info = typeDef.info
  const sub = typeDef.sub
  const lookupName = (typeDef.lookupName || '').toLowerCase()

  // --- Polymesh-specific type overrides by lookupName (checked before generic handlers) ---
  // IMPORTANT: Only match direct types, not generic containers (Vec<X>, BTreeSet<X>, Option<X>).
  // Use !includes('<') to exclude container types that happen to contain the target name.
  const isDirectType = !lookupName.includes('<') && !type.includes('<')

  if (isDirectType) {
    // AssetId ([u8; 16])
    if (lookupName.includes('assetid') || type.toLowerCase().includes('assetid')) {
      return randomHex(16)
    }

    // IdentityId / DID ([u8; 32])
    if (lookupName.includes('identityid')) {
      return randomHex(32)
    }

    // CDD ID ([u8; 32])
    if (lookupName.includes('cddid')) {
      return randomHex(32)
    }

    // Ticker ([u8; 12])
    if (lookupName.includes('ticker') && !lookupName.includes('config')) {
      return randomHex(12)
    }

    // Memo ([u8; 32])
    if (lookupName.includes('memo')) {
      return randomHex(32)
    }

    // Session keys (sr25519/ed25519 public keys, 32 bytes)
    if (lookupName.includes('sr25519') || lookupName.includes('ed25519')) {
      if (lookupName.includes('public')) return randomHex(32)
      if (lookupName.includes('signature')) return randomHex(64)
    }

    // ECDSA signature (65 bytes)
    if (lookupName.includes('ecdsa') && lookupName.includes('signature')) {
      return randomHex(65)
    }

    // AuthorizationData enum
    if (lookupName.includes('authorizationdata')) {
      return { RotatePrimaryKey: null }
    }

    // ClaimScope
    if (lookupName.includes('claimscope')) {
      return { Asset: randomHex(16) }
    }

    // PortfolioId
    if (lookupName.includes('portfolioid')) {
      return { did: randomHex(32), kind: randomBool() ? { Default: null } : { User: randomInt(1, 100) } }
    }

    // Call / RuntimeCall - must intercept BEFORE Enum handler (Call is an Enum internally)
    if (lookupName.includes('runtimecall') || lookupName.endsWith('::call') ||
        type.toLowerCase() === 'call' || type.toLowerCase().includes('runtimecall')) {
      if (_api) {
        try {
          return _api.tx.system.remark(randomHex(randomInt(1, 4)))
        } catch { /* fall through to Enum handler */ }
      }
    }
  }

  // Handle by TypeDefInfo enum values from @polkadot/types
  // Info values: Plain=0, Compact=1, Enum=2, Option=3, Range=4, RangeInclusive=5,
  //              Set=6, Si=7, Struct=8, Tuple=9, Vec=10, VecFixed=11, BTreeMap=12,
  //              BTreeSet=13, HashMap=14, Linkage=15, Null=16, Result=17, WrapperKeepOpaque=18,
  //              WrapperOpaque=19, DoNotConstruct=20

  // Option => None or Some(value)
  if (info === 3 || type.startsWith('Option<')) {
    if (!safe && randomBool() && sub) {
      const inner = Array.isArray(sub) ? sub[0] : sub
      return generateDummyValue(registry, inner, depth + 1, safe)
    }
    return null
  }

  // Compact
  if (info === 1 || type.startsWith('Compact<')) {
    return randomInt(1, 10000)
  }

  // Vec / BTreeSet => empty or 1-2 random elements
  if (info === 10 || info === 13 || type.startsWith('Vec<') || type.startsWith('BTreeSet<')) {
    if (!safe && randomBool() && sub) {
      const inner = Array.isArray(sub) ? sub[0] : sub
      const count = randomInt(1, 2)
      return Array.from({ length: count }, () => generateDummyValue(registry, inner, depth + 1, safe))
    }
    return []
  }

  // VecFixed (e.g., [u8; 32])
  if (info === 11) {
    const len = typeDef.length || 32
    if (sub && (sub.type === 'u8' || sub.lookupName === 'u8')) {
      return randomHex(len)
    }
    return Array(len).fill(generateDummyValue(registry, sub || { type: 'u8' }, depth + 1, safe))
  }

  // Tuple
  if (info === 9) {
    if (Array.isArray(sub)) {
      return sub.map(s => generateDummyValue(registry, s, depth + 1, safe))
    }
    return []
  }

  // Struct
  if (info === 8) {
    if (Array.isArray(sub)) {
      // Newtype struct (single unnamed field) → return inner value directly
      // These are wrappers like IdentityId([u8;32]), CddId([u8;32]), etc.
      if (sub.length === 1 && (!sub[0].name || sub[0].name === '0')) {
        return generateDummyValue(registry, sub[0], depth + 1, safe)
      }
      const obj = {}
      for (const field of sub) {
        obj[field.name] = generateDummyValue(registry, field, depth + 1, safe)
      }
      return obj
    }
    return {}
  }

  // Enum - pick random variant (safe mode: first variant)
  if (info === 2) {
    if (Array.isArray(sub) && sub.length > 0) {
      // Filter out __Unused variants
      const usable = sub.filter(v => !v.name.startsWith('__Unused'))
      const candidates = usable.length > 0 ? usable : sub
      const variant = safe ? candidates[0] : candidates[randomInt(0, candidates.length - 1)]
      const variantValue = variant.type === 'Null'
        ? null
        : generateDummyValue(registry, variant, depth + 1, safe)
      return { [variant.name]: variantValue }
    }
    return 0
  }

  // BTreeMap / HashMap
  if (info === 12 || info === 14 || type.startsWith('BTreeMap<') || type.startsWith('HashMap<')) {
    return []
  }

  // Result
  if (info === 17) {
    if (Array.isArray(sub) && sub.length > 0) {
      return { Ok: generateDummyValue(registry, sub[0], depth + 1, safe) }
    }
    return { Ok: null }
  }

  // Null
  if (info === 16) {
    return null
  }

  // Si (scale-info) - resolve from registry
  if (info === 7 && typeDef.lookupIndex !== undefined) {
    try {
      const resolved = registry.lookup.getTypeDef(typeDef.lookupIndex)
      return generateDummyValue(registry, resolved, depth + 1, safe)
    } catch {
      // Fall through to string matching
    }
  }

  // String-based matching for common types
  const typeStr = type.toLowerCase()

  // --- Polymesh types that come through the string fallback path ---
  // (when registry.lookup.getTypeDef() fails, we only have the type name string)
  // Only match direct types, not generics like Vec<X>, Option<X>
  const isDirectTypeStr = !typeStr.includes('<')

  if (isDirectTypeStr) {
    // IdentityId / DID ([u8;32])
    if (typeStr.includes('identityid')) {
      return randomHex(32)
    }

    // CddId ([u8;32])
    if (typeStr.includes('cddid')) {
      return randomHex(32)
    }

    // Ticker ([u8;12])
    if (typeStr.includes('ticker') && !typeStr.includes('config')) {
      return randomHex(12)
    }

    // Memo ([u8;32])
    if (typeStr.includes('memo')) {
      return randomHex(32)
    }

    // Session keys (runtime-specific composite struct)
    if (typeStr.includes('sessionkeys') || typeStr.includes('runtimesessionkeys') || typeStr === 'keys') {
      // Polymesh session keys: grandpa(32) + babe(32) + im_online(32) + authority_discovery(32) + beefy(33)
      return randomHex(161)
    }

    // VenueType enum
    if (typeStr.includes('venuetype')) {
      const types = ['Other', 'Distribution', 'Sto', 'Exchange']
      return { [types[randomInt(0, types.length - 1)]]: null }
    }

    // PortfolioKind enum
    if (typeStr.includes('portfoliokind')) {
      return randomBool() ? { Default: null } : { User: randomInt(1, 100) }
    }

    // Permissions / ExtrinsicPermissions
    if (typeStr.includes('extrinsicpermissions')) {
      const variants = [{ Whole: null }, { These: [] }, { Except: [] }]
      return variants[randomInt(0, 2)]
    }
  }

  // MultiAddress - use explicit variant object for variety
  if (typeStr.includes('multiaddress') && !/^lookup\d+$/.test(typeStr)) {
    const roll = randomInt(0, 9)
    if (roll < 5) return { Id: randomAddress() }              // 50% Id (AccountId)
    if (roll < 7) return { Address32: randomHex(32) }         // 20% Address32
    if (roll < 9) return { Address20: randomHex(20) }         // 20% Address20
    return { Index: randomInt(0, 65535) }                     // 10% Index
  }

  // AccountId / Address types (but NOT bare Lookup123 which are scale-info refs)
  if ((typeStr.includes('accountid') || typeStr.includes('address') ||
      typeStr.includes('lookupof') || typeStr.includes('accountidlookupof') ||
      typeStr === 'address') &&
      !/^lookup\d+$/.test(typeStr)) {
    return randomAddress()
  }

  // Balance types
  if (typeStr.includes('balance') || typeStr === 'compact<u128>' || typeStr === 'balanceof') {
    return randomInt(1, 9999) * 1_000_000 // 1-9999 POLYX (6 decimals)
  }

  // Boolean
  if (typeStr === 'bool') {
    return randomBool()
  }

  // Bytes / Vec<u8>
  if (typeStr === 'bytes' || typeStr === 'vec<u8>') {
    return randomHex(randomInt(1, 8))
  }

  // Text / String
  if (typeStr === 'text' || typeStr === 'string') {
    const words = ['alpha', 'bravo', 'charlie', 'delta', 'echo', 'foxtrot', 'golf', 'hotel']
    return words[randomInt(0, words.length - 1)]
  }

  // Hash types (H256, H160, etc.)
  if (typeStr === 'h256' || typeStr === 'hash') {
    return randomHex(32)
  }
  if (typeStr === 'h160') {
    return randomHex(20)
  }
  if (typeStr === 'h512') {
    return randomHex(64)
  }

  // Numeric primitives
  if (/^(u8|u16|u32|u64|u128|u256)$/.test(typeStr)) {
    const maxByType = { u8: 255, u16: 65535, u32: 1000000, u64: 1000000, u128: 1000000, u256: 1000000 }
    return randomInt(1, maxByType[typeStr] || 1000)
  }
  if (/^(i8|i16|i32|i64|i128|i256)$/.test(typeStr)) {
    return randomInt(-1000, 1000)
  }

  // Perbill/Permill/etc
  if (typeStr.includes('perbill')) {
    return randomInt(1, 1_000_000_000)
  }
  if (typeStr.includes('permill')) {
    return randomInt(1, 1_000_000)
  }
  if (typeStr.includes('percent')) {
    return randomInt(1, 100)
  }

  // Weight
  if (typeStr.includes('weight') && !typeStr.includes('check')) {
    return { refTime: randomInt(1000, 500000), proofSize: randomInt(100, 50000) }
  }

  // Block number
  if (typeStr.includes('blocknumber') || typeStr.includes('blocknum')) {
    return randomInt(1, 10_000_000)
  }

  // Fixed-size byte arrays described as strings (e.g., "[u8;32]", "[u8;12]")
  const fixedMatch = typeStr.match(/^\[u8;\s*(\d+)\]$/)
  if (fixedMatch) {
    return randomHex(parseInt(fixedMatch[1], 10))
  }

  // Default: 0 is the safest fallback for unresolved/complex types
  if (typeStr.match(/^[ui]\d+$/)) {
    return randomInt(1, 1000)
  }

  return 0
}

/**
 * Generate dummy arguments for a method using its metadata args.
 * @param {boolean} safe - If true, use conservative defaults for complex types
 */
function generateArgsForMethod(registry, palletName, methodName, methodMeta, safe = false) {
  // Check for manual override first
  const overrideKey = `${palletName}.${methodName}`
  if (typeOverrides[overrideKey]) {
    return typeOverrides[overrideKey]
  }

  // Code-based overrides for methods needing dynamic randomization or live API objects
  {
    // --- Equivocation proof overrides (BABE, GRANDPA, BEEFY) ---
    // These types can't be resolved by the registry (lookupId is NaN)
    // so we build proper random structures manually.

    const randomHeader = () => ({
      parentHash: randomHex(32),
      number: randomInt(1, 10_000_000),
      stateRoot: randomHex(32),
      extrinsicsRoot: randomHex(32),
      digest: { logs: [] },
    })

    const randomKeyOwnerProof = () => ({
      session: randomInt(1, 1000),
      trieNodes: [],
      validatorCount: randomInt(10, 200),
    })

    // BABE: report_equivocation / report_equivocation_unsigned
    if (palletName === 'babe' && (methodName === 'reportEquivocation' || methodName === 'reportEquivocationUnsigned')) {
      return [
        {
          offender: randomHex(32),
          slot: randomInt(1, 10_000_000),
          firstHeader: randomHeader(),
          secondHeader: randomHeader(),
        },
        randomKeyOwnerProof(),
      ]
    }

    // GRANDPA: report_equivocation / report_equivocation_unsigned
    if (palletName === 'grandpa' && (methodName === 'reportEquivocation' || methodName === 'reportEquivocationUnsigned')) {
      const randomVote = () => ({
        targetHash: randomHex(32),
        targetNumber: randomInt(1, 10_000_000),
      })
      const randomSig = () => randomHex(64) // ed25519 signature
      const equivocationType = randomBool() ? 'Prevote' : 'Precommit'
      return [
        {
          setId: randomInt(1, 1000),
          equivocation: {
            [equivocationType]: {
              roundNumber: randomInt(1, 100000),
              identity: randomHex(32),
              first: [randomVote(), randomSig()],
              second: [randomVote(), randomSig()],
            },
          },
        },
        randomKeyOwnerProof(),
      ]
    }

    // BEEFY: report_double_voting / report_double_voting_unsigned
    if (palletName === 'beefy' && (methodName === 'reportDoubleVoting' || methodName === 'reportDoubleVotingUnsigned')) {
      const randomBeefyVote = () => ({
        commitment: {
          payload: [[randomHex(2), randomHex(32)]],
          blockNumber: randomInt(1, 10_000_000),
          validatorSetId: randomInt(1, 1000),
        },
        id: randomHex(33),         // ecdsa::Public (33 bytes)
        signature: randomHex(65),  // ecdsa::Signature (65 bytes)
      })
      return [
        {
          first: randomBeefyVote(),
          second: randomBeefyVote(),
        },
        randomKeyOwnerProof(),
      ]
    }

    // BEEFY: report_fork_voting / report_fork_voting_unsigned
    if (palletName === 'beefy' && (methodName === 'reportForkVoting' || methodName === 'reportForkVotingUnsigned')) {
      const randomBeefyVote = () => ({
        commitment: {
          payload: [[randomHex(2), randomHex(32)]],
          blockNumber: randomInt(1, 10_000_000),
          validatorSetId: randomInt(1, 1000),
        },
        id: randomHex(33),
        signature: randomHex(65),
      })
      return [
        {
          vote: randomBeefyVote(),
          ancestryProof: randomHeader(),
        },
        randomKeyOwnerProof(),
      ]
    }

    // BEEFY: report_future_block_voting / report_future_block_voting_unsigned
    if (palletName === 'beefy' && (methodName === 'reportFutureBlockVoting' || methodName === 'reportFutureBlockVotingUnsigned')) {
      const randomBeefyVote = () => ({
        commitment: {
          payload: [[randomHex(2), randomHex(32)]],
          blockNumber: randomInt(1, 10_000_000),
          validatorSetId: randomInt(1, 1000),
        },
        id: randomHex(33),
        signature: randomHex(65),
      })
      return [
        randomBeefyVote(),
        randomKeyOwnerProof(),
      ]
    }

    // Settlement overrides - randomize settlement_type and related params
    const settlementTypes = [
      { SettleOnAffirmation: null },
      { SettleOnBlock: randomInt(100, 10_000_000) },
      { SettleManual: randomInt(100, 10_000_000) },
    ]
    if (palletName === 'settlement' && methodName === 'addInstruction') {
      return [
        randomBool() ? null : randomInt(1, 1000),             // venue_id
        settlementTypes[randomInt(0, settlementTypes.length - 1)], // settlement_type
        randomBool() ? null : randomInt(1, 1_000_000),        // trade_date
        randomBool() ? null : randomInt(1, 1_000_000),        // value_date
        [],                                                     // legs
        randomBool() ? null : randomHex(32),                   // instruction_memo
      ]
    }
    if (palletName === 'settlement' && ['addAndAffirmInstruction', 'addAndAffirmWithMediators', 'addInstructionWithMediators'].includes(methodName)) {
      // Let the auto-generator handle these, but the settlement_type will now be random through the Enum handler
    }
  }
  if (_api) {
    const makeCall = () => _api.tx.system.remark(randomHex(randomInt(1, 4)))
    const calls = safe ? [] : [makeCall()]

    if (palletName === 'utility' && ['batch', 'batchAll', 'forceBatch'].includes(methodName)) {
      return [calls]
    }
    if (palletName === 'multiSig' && methodName === 'createProposal') {
      return [randomAddress(), makeCall(), null]
    }
    if (palletName === 'pips' && methodName === 'propose') {
      return [makeCall(), randomInt(1, 9999) * 1_000_000, null, null]
    }
    if (['polymeshCommittee', 'technicalCommittee', 'upgradeCommittee'].includes(palletName) && methodName === 'voteOrPropose') {
      return [randomBool(), makeCall()]
    }
    if (palletName === 'utility' && methodName === 'asDerivative') {
      return [randomInt(0, 5), makeCall()]
    }
    if (palletName === 'utility' && methodName === 'dispatchAs') {
      return [{ system: { Root: null } }, makeCall()]
    }
    if (palletName === 'utility' && methodName === 'withWeight') {
      return [makeCall(), { refTime: randomInt(1000, 500000), proofSize: randomInt(100, 50000) }]
    }
    if (palletName === 'utility' && methodName === 'relayTx') {
      // relayTx takes (target: AccountId, signature: OffChainSignature, call: UniqueCall)
      const sigVariants = [
        { Ed25519: randomHex(64) },
        { Sr25519: randomHex(64) },
        { Ecdsa: randomHex(65) },
      ]
      return [
        randomAddress(),
        sigVariants[randomInt(0, 2)],
        { nonce: randomInt(0, 100), call: makeCall() }
      ]
    }
    if (palletName === 'scheduler') {
      if (methodName === 'schedule' || methodName === 'scheduleAfter') {
        return [randomInt(1, 100), safe ? null : randomInt(1, 50), randomInt(0, 3), makeCall()]
      }
      if (methodName === 'scheduleNamed' || methodName === 'scheduleNamedAfter') {
        return [randomHex(32), randomInt(1, 100), safe ? null : randomInt(1, 50), randomInt(0, 3), makeCall()]
      }
    }
  }

  const args = []
  for (const arg of methodMeta.args) {
    const typeIndex = arg.type.toString()
    const typeName = arg.typeName?.toString() || typeIndex

    // Try to resolve the type via the registry lookup index
    try {
      const resolved = registry.lookup.getTypeDef(arg.type.toNumber())
      args.push(generateDummyValue(registry, resolved, 0, safe))
    } catch {
      // Fall back to string-based type matching using both typeName and type string
      // Pass typeName as both type and lookupName to maximize matching opportunities
      args.push(generateDummyValue(registry, { type: typeName, lookupName: typeName }, 0, safe))
    }
  }

  return args
}

/**
 * Discover all pallets and methods from the runtime, returning
 * an array of { pallet, method, call } with generated parameters.
 *
 * Uses a two-pass strategy: first try with full randomization (Option/Vec/Enum),
 * on failure retry with safe defaults to maximize coverage.
 */
function discoverAllTransactions(api) {
  _api = api
  const registry = api.registry
  const transactions = []
  const errors = []

  const pallets = Object.keys(api.tx).sort()
  console.log(`\nDiscovered ${pallets.length} pallets`)

  for (const palletName of pallets) {
    const methods = api.tx[palletName]
    if (!methods || typeof methods !== 'object') continue

    const methodNames = Object.keys(methods).filter(m => !m.startsWith('_')).sort()

    for (const methodName of methodNames) {
      const key = `${palletName}.${methodName}`.toLowerCase()

      // Apply --only / --skip filters
      if (ONLY && !ONLY.includes(key)) continue
      if (SKIP.has(key)) continue

      try {
        const fn = methods[methodName]
        if (typeof fn !== 'function') continue

        const meta = fn.meta
        if (!meta) continue

        let call
        let usedSafe = false

        // Pass 1: full randomization
        try {
          const fullArgs = generateArgsForMethod(registry, palletName, methodName, meta, false)
          call = fn(...fullArgs)
        } catch {
          // Pass 2: safe mode (conservative Option/Vec/Enum)
          try {
            const safeArgs = generateArgsForMethod(registry, palletName, methodName, meta, true)
            call = fn(...safeArgs)
            usedSafe = true
          } catch (retryErr) {
            errors.push({ pallet: palletName, method: methodName, error: `Call creation: ${retryErr.message}` })
            continue
          }
        }

        const snakeName = `${camelToSnake(palletName)}_${camelToSnake(methodName)}`
        transactions.push({
          pallet: palletName,
          method: methodName,
          name: snakeName + (usedSafe ? ' (safe)' : ''),
          call,
        })
      } catch (e) {
        errors.push({ pallet: palletName, method: methodName, error: e.message })
      }
    }
  }

  return { transactions, errors }
}

/** Convert camelCase to snake_case */
function camelToSnake(str) {
  return str
    .replace(/([A-Z])/g, '_$1')
    .toLowerCase()
    .replace(/^_/, '')
}

/**
 * Create the signing payload that the Ledger receives.
 * Randomizes era (mortal/immortal), period, phase, nonce, and tip for test coverage.
 */
async function createSigningPayload(api, tx, metadataDigest) {
  // Randomize mortality: ~15% immortal, ~85% mortal
  const isImmortal = rng() < 0.15

  // Era period: power of 2, from 4 to 65536 (common: 64, 256, 1024, 4096)
  const eraPowers = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536]
  const eraPeriod = eraPowers[randomInt(0, eraPowers.length - 1)]
  // Current block (era phase is derived as current % period)
  const currentBlock = randomInt(1, 10_000_000)

  let era, blockHash
  if (isImmortal) {
    era = api.registry.createType('ExtrinsicEra', new Uint8Array([0]))
    blockHash = api.genesisHash
  } else {
    era = api.registry.createType('ExtrinsicEra', { current: currentBlock, period: eraPeriod })
    // For mortal txs, blockHash is the checkpoint block hash (random for testing)
    blockHash = randomHex(32)
  }

  // Random nonce (1 to 999999)
  const nonce = randomInt(1, 999999)

  // Random tip: ~70% zero, ~30% non-zero (1-500 POLYX)
  const tip = rng() < 0.3 ? randomInt(1, 500) * 1_000_000 : 0

  const payload = api.registry.createType('ExtrinsicPayload', {
    method: tx.method.toHex(),
    era,
    nonce,
    tip,
    specVersion: api.runtimeVersion.specVersion,
    transactionVersion: api.runtimeVersion.transactionVersion,
    genesisHash: api.genesisHash,
    blockHash,
    mode: 1, // CheckMetadataHash: Enabled
    metadataHash: u8aToHex(metadataDigest),
  }, { version: 4 })

  return payload.toU8a({ method: true })
}

async function main() {
  console.log(`Seed: ${SEED}`)
  console.log(`Connecting to ${ENDPOINT}...`)

  const provider = new WsProvider(ENDPOINT)
  const api = await ApiPromise.create({ provider, noInitWarn: true })

  console.log(`Chain: ${api.runtimeChain}`)
  console.log(`Runtime: ${api.runtimeVersion.specName} v${api.runtimeVersion.specVersion}`)
  console.log(`Genesis: ${api.genesisHash.toHex()}`)

  // --- Fetch V15 metadata ---
  let rawMetadata
  console.log('\nFetching V15 metadata...')
  try {
    const v15Result = await api.call.metadata.metadataAtVersion(15)
    if (v15Result && !v15Result.isNone) {
      rawMetadata = v15Result.unwrap().toU8a(true)
      console.log(`  V15 metadata: ${rawMetadata.length} bytes`)
    }
  } catch (e) {
    console.log(`  V15 runtime call failed: ${e.message}`)
  }

  if (!rawMetadata) {
    console.error('\nERROR: V15 metadata not available. The generic app requires V15.')
    console.error('Ensure the Polymesh runtime supports Metadata API v2.')
    await api.disconnect()
    process.exit(1)
  }

  // --- Merkleize metadata ---
  console.log('\nMerkleizing metadata...')
  const chainSS58 = api.registry.chainSS58 ?? 12
  const chainDecimals = api.registry.chainDecimals?.[0] ?? 6
  const chainToken = api.registry.chainTokens?.[0] ?? 'POLYX'
  console.log(`  SS58=${chainSS58}, decimals=${chainDecimals}, token=${chainToken}`)

  const merkleized = merkleizeMetadata(rawMetadata, {
    base58Prefix: chainSS58,
    decimals: chainDecimals,
    specName: api.runtimeVersion.specName.toString(),
    specVersion: api.runtimeVersion.specVersion.toNumber(),
    tokenSymbol: chainToken,
  })

  const digest = merkleized.digest()
  const digestHex = u8aToHex(digest, -1, false)
  console.log(`  Digest: ${digestHex}`)

  // --- List signed extensions for reference ---
  const metadata = await api.rpc.state.getMetadata()
  const decoded = metadata.toJSON()
  const version = Object.keys(decoded.metadata).find(k => k.startsWith('v'))
  const extensions = decoded.metadata[version]?.extrinsic?.signedExtensions || []
  console.log(`\nSigned extensions (${extensions.length}):`)
  extensions.forEach((ext, i) => console.log(`  ${i + 1}. ${ext.identifier}`))

  // --- Discover all transactions ---
  console.log('\n=== Discovering all pallets and methods ===')
  const { transactions, errors: discoveryErrors } = discoverAllTransactions(api)
  console.log(`\nDiscovered ${transactions.length} callable methods`)
  if (discoveryErrors.length > 0) {
    console.log(`\n${discoveryErrors.length} methods failed parameter generation:`)
    for (const err of discoveryErrors) {
      console.log(`  ${err.pallet}.${err.method}: ${err.error}`)
    }
  }

  // --- Generate test vectors ---
  console.log('\n=== Generating test vectors ===')
  const testVectors = []
  const generationErrors = []

  for (const tx of transactions) {
    const displayName = tx.name.replace(' (safe)', '')
    process.stdout.write(`  ${tx.name}... `)
    try {
      const callData = tx.call.method.toU8a()

      const signingPayload = await createSigningPayload(api, tx.call, digest)
      const blobHex = u8aToHex(signingPayload, -1, false)

      // Generate the shortened metadata proof
      let proofHex
      try {
        const proof = merkleized.getProofForExtrinsicPayload(signingPayload)
        proofHex = u8aToHex(proof, -1, false)
      } catch (proofErr) {
        // Fallback: try with just call data
        try {
          const proof = merkleized.getProofForExtrinsicParts(
            callData,
            new Uint8Array(0),
            new Uint8Array(0)
          )
          proofHex = u8aToHex(proof, -1, false)
        } catch (fallbackErr) {
          throw new Error(`Proof generation failed: ${fallbackErr.message}`)
        }
      }

      testVectors.push({
        index: testVectors.length,
        name: displayName,
        blob: blobHex,
        metadata: proofHex,
        digest: digestHex,
        output: [],
        output_expert: [],
      })

      console.log('OK')
    } catch (e) {
      generationErrors.push({ name: displayName, error: e.message })
      console.log(`FAIL: ${e.message}`)
    }
  }

  // --- Write output ---
  const specVersion = api.runtimeVersion.specVersion.toNumber()
  const chainName = api.runtimeVersion.specName.toString().toLowerCase().replace(/\s+/g, '-')
  const outputFilename = `${chainName}-${specVersion}.json`
  const outputPath = join(__dirname, '..', '..', 'tests', outputFilename)

  console.log(`\n=== Writing ${testVectors.length} test vectors to ${outputFilename} ===`)
  const outputData = {
    generated_at: new Date().toISOString(),
    seed: SEED,
    chain: api.runtimeChain.toString(),
    spec_name: chainName,
    spec_version: specVersion,
    genesis: api.genesisHash.toHex(),
    metadata_digest: digestHex,
    total_vectors: testVectors.length,
    vectors: testVectors
  }
  writeFileSync(outputPath, JSON.stringify(outputData, null, 2))

  // --- Summary ---
  console.log(`\n=== Summary ===`)
  console.log(`Chain: ${api.runtimeChain}`)
  console.log(`Spec: ${chainName} v${specVersion}`)
  console.log(`Genesis: ${api.genesisHash.toHex()}`)
  console.log(`Digest: ${digestHex}`)
  console.log(`Test vectors generated: ${testVectors.length}`)
  console.log(`Parameter generation failures: ${discoveryErrors.length}`)
  console.log(`Signing/proof failures: ${generationErrors.length}`)
  console.log(`File: ${outputPath}`)

  if (generationErrors.length > 0) {
    console.log(`\nFailed methods:`)
    for (const err of generationErrors) {
      console.log(`  ${err.name}: ${err.error}`)
    }
  }

  // --- Run capture utility (default, skip with --no-capture) ---
  if (!NO_CAPTURE && testVectors.length > 0) {
    console.log('\n=== Building and running C++ capture utility ===')
    const projectRoot = join(__dirname, '..', '..')
    const buildDir = join(projectRoot, 'build')

    try {
      console.log('Building capture_output...')
      execSync(`cmake --build ${buildDir} --target capture_output`, {
        cwd: projectRoot,
        stdio: 'inherit',
      })

      console.log('Running capture_output...')
      execSync(`${buildDir}/capture_output ${outputPath}`, {
        cwd: projectRoot,
        stdio: 'inherit',
      })

      console.log('Capture complete. Output fields populated.')
    } catch (e) {
      console.error('Capture utility failed:', e.message)
      console.error('You can run it manually:')
      console.error(`  cmake --build build/ --target capture_output`)
      console.error(`  ./build/capture_output ${outputPath}`)
    }
  } else if (testVectors.length > 0) {
    console.log('\nNOTE: "output" and "output_expert" fields are empty (--no-capture).')
  }

  await api.disconnect()
}

main().catch((e) => {
  console.error('Fatal error:', e)
  process.exit(1)
})
