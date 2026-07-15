#!/usr/bin/env python3
"""
Local convenience wrapper for running fuzzers
"""

import hashlib
import os
import struct
import sys

# Add the common fuzzing module to path
current_dir = os.path.dirname(os.path.abspath(__file__))
project_root = os.path.dirname(current_dir)
common_fuzzing_path = os.path.join(project_root, "deps", "ledger-zxlib", "fuzzing")

sys.path.insert(0, common_fuzzing_path)


# Inputs that bootstrap libFuzzer with realistic shapes of data so coverage
# is non-trivial from the very first run. Defined inline (rather than checked
# in as binary blobs) to keep the repo clean. The runner writes them into the
# per-target corpus dir at startup; libFuzzer-discovered inputs accumulate
# alongside them across runs.
_PARSER_PARSE_BLOB_HEX = (
    "050000d43593c715fdd31c61141abd04a99fd6822c8558854ccde39a5684e7a56da27d0"
    "2093d001500a8000101127a0008000000001fc4a87cf62f41bd9e6180f9c24ee310234b"
    "09603898e79e987ce94d3446de001fc4a87cf62f41bd9e6180f9c24ee310234b0960389"
    "8e79e987ce94d3446de01b35f6ebaf822d9b90a4b657a3a8466df48ef715c7352e8d13a"
    "6096f27925751f"
)

_SS58_SEEDS = [
    # (address_type, pubkey_bytes) pairs covering Polymesh, single-byte,
    # dual-byte, and out-of-range prefixes plus a known reference key.
    (12, bytes(range(32))),
    (0, bytes(range(32))),
    (
        42,
        bytes.fromhex("c55777790670bfd6bf012d79fd65f29afe233694d5af0a5e74783f13849fe29a"),
    ),
    (16002, bytes(32)),
    (16384, bytes(32)),
]


def _seed_for_target(target):
    """Yield (filename, bytes) pairs to seed the given fuzz target with."""
    if target == "parser_parse":
        yield "balances_transfer_allow_death", bytes.fromhex(_PARSER_PARSE_BLOB_HEX)
    elif target == "zxblake3_hash":
        for payload in (b"a", b"hello world", b"\x00" * 32, bytes(range(256)), b"abc" * 100):
            yield None, payload
    elif target == "crypto_helper_ss58":
        for prefix, pubkey in _SS58_SEEDS:
            yield None, struct.pack("<H", prefix) + pubkey


def _seed_corpora():
    """Drop in-code seed inputs into each per-target corpus dir if missing."""
    corpus_root = os.path.join(current_dir, "corpora")
    for target in ("parser_parse", "zxblake3_hash", "crypto_helper_ss58"):
        dst = os.path.join(corpus_root, target)
        os.makedirs(dst, exist_ok=True)
        for name, payload in _seed_for_target(target):
            # libFuzzer keys inputs by content hash; reuse that convention so
            # a second run is a no-op rather than producing duplicate files.
            seed_name = name or hashlib.sha1(payload).hexdigest()
            seed_path = os.path.join(dst, seed_name)
            if not os.path.exists(seed_path):
                with open(seed_path, "wb") as fh:
                    fh.write(payload)


_seed_corpora()

try:
    from run_fuzzers import main
    from fuzz_config import MAX_SECONDS, FUZZER_JOBS

    # Override default arguments to point to this project root
    if "--fuzz-dir" not in sys.argv:
        sys.argv.extend(["--fuzz-dir", current_dir])

    # Override max-seconds if not provided
    if "--max-seconds" not in sys.argv:
        sys.argv.extend(["--max-seconds", str(MAX_SECONDS)])

    # Override jobs if not provided
    if "--jobs" not in sys.argv:
        sys.argv.extend(["--jobs", str(FUZZER_JOBS)])

    # Run the common fuzzer
    sys.exit(main())

except ImportError as e:
    print(f"Error: Cannot import common fuzzing module: {e}")
    print("Make sure deps/ledger-zxlib/fuzzing/run_fuzzers.py exists")
    sys.exit(1)
