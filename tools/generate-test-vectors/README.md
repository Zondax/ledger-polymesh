# Polymesh Test Vector Generator

Generates test vectors for the Ledger Polymesh Generic app by auto-discovering all pallets/methods from the Polymesh runtime, building signing payloads with `CheckMetadataHash` + merkleized metadata proofs, and capturing the C++ parser output.

## Prerequisites

```bash
npm install
```

The C++ parser binary must be built first (from the repo root):

```bash
mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make
```

## Usage

```bash
node generate.mjs [options]
```

### Options

| Flag | Description | Default |
|------|-------------|---------|
| `--seed N` | Integer seed for deterministic random generation | `42` |
| `--endpoint wss://...` | WebSocket endpoint of a Polymesh node | `wss://dev.polymesh.tech/forked/staging/` |
| `--no-capture` | Skip the C++ capture step (`output`/`output_expert` will be empty) | disabled |
| `--only pallet.method,...` | Only generate vectors for these methods | all |
| `--skip pallet.method,...` | Skip these methods | none |

### Examples

```bash
# Generate all vectors (deterministic with default seed 42)
node generate.mjs

# Generate with a different seed
node generate.mjs --seed 123

# Quick run without C++ capture
node generate.mjs --no-capture

# Generate only specific methods
node generate.mjs --only balances.transferKeepAlive,staking.bond

# Skip problematic methods
node generate.mjs --skip contracts.callOldWeight,contracts.instantiateOldWeight
```

## Output

Test vectors are written to `tests/<spec_name>-<spec_version>.json` (e.g., `tests/polymesh_testnet-8000001.json`).

The JSON file contains:

```json
{
  "generated_at": "2026-02-25T12:00:00.000Z",
  "seed": 42,
  "chain": "Polymesh Staging-fork",
  "spec_name": "polymesh_testnet",
  "spec_version": 8000001,
  "genesis": "0x001f...",
  "metadata_digest": "b35f...",
  "total_vectors": 362,
  "vectors": [
    {
      "index": 0,
      "name": "asset_accept_asset_ownership_transfer",
      "blob": "1a02...",
      "metadata": "2c0c...",
      "digest": "b35f...",
      "output": ["0 | Chain : polymesh_testnet", "..."],
      "output_expert": ["0 | Chain : polymesh_testnet", "..."]
    }
  ]
}
```

## Type Overrides

Some methods require manual parameter overrides due to complex Polymesh types that can't be auto-generated. These are defined in `type-overrides.json`. Keys use `camelCase` format matching the Polkadot.js API (e.g., `asset.createAsset`).

## Deterministic Output

The generator uses a seeded PRNG (mulberry32) so that the same seed always produces identical output. This ensures test vectors don't change unnecessarily between runs. Use `--seed N` to generate a different set of random values.
