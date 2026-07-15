#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "blake3.h"
#include "parser_common.h"
#include "zxblake3.h"

#ifdef NDEBUG
#error "This fuzz target won't work correctly with NDEBUG defined, which will cause asserts to be eliminated"
#endif

using std::size_t;

namespace {
uint8_t HASH_BUFFER[BLAKE3_OUT_LEN];
}  // namespace

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    if (size == 0 || size > UINT16_MAX) {
        return 0;
    }

    // One-shot path
    (void)zxblake3_hash(data, static_cast<uint16_t>(size), HASH_BUFFER, sizeof(HASH_BUFFER));

    // Streaming path: split the input in halves so the accumulator and bounds
    // checks on zxblake3_hash_update() are exercised across multiple chunks.
    if (zxblake3_hash_init() == parser_ok) {
        const uint16_t half = static_cast<uint16_t>(size / 2);
        if (half > 0) {
            (void)zxblake3_hash_update(data, half);
        }
        const uint16_t remaining = static_cast<uint16_t>(size - half);
        if (remaining > 0) {
            (void)zxblake3_hash_update(data + half, remaining);
        }
        (void)zxblake3_hash_finalize(HASH_BUFFER, sizeof(HASH_BUFFER));
    }

    return 0;
}
