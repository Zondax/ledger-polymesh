#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "coin.h"
#include "crypto_helper.h"

#ifdef NDEBUG
#error "This fuzz target won't work correctly with NDEBUG defined, which will cause asserts to be eliminated"
#endif

using std::size_t;

namespace {
uint8_t SS58_BUFFER[SS58_ADDRESS_MAX_LEN];
}  // namespace

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
    // Need 2 bytes of prefix + 32 bytes of pubkey to drive both helpers.
    if (size < sizeof(uint16_t) + PK_LEN_25519) {
        return 0;
    }

    uint16_t addressType = 0;
    std::memcpy(&addressType, data, sizeof(addressType));

    uint8_t pubkey[PK_LEN_25519];
    std::memcpy(pubkey, data + sizeof(addressType), PK_LEN_25519);

    // Exercises the prefix encoder for the full uint16 range, including the
    // out-of-range path (>16383) that returns 0.
    uint8_t prefixBytes[2] = {0};
    (void)crypto_SS58CalculatePrefix(addressType, prefixBytes);

    // Drives the SS58 BLAKE2b-checksum + base58 path. For invalid prefixes the
    // function should fail cleanly (return 0) without writing past the buffer.
    (void)crypto_SS58EncodePubkey(SS58_BUFFER, sizeof(SS58_BUFFER), addressType, pubkey);

    return 0;
}
