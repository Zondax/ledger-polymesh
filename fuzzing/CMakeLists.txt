cmake_minimum_required(VERSION 3.10)

project(PolymeshFuzzer VERSION 0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,bugprone-*,cert-*,clang-analyzer-*,-cert-err58-cpp,misc-*)

# BOLOS SDK
set(BOLOS_SDK $ENV{BOLOS_SDK})
add_compile_definitions(IO_HID_EP_LENGTH=64)

# Fuzzer target
set(APP_SRC_DIR "../")

add_compile_definitions(HAVE_ECC HAVE_HASH HAVE_SHA256 HAVE_RIPEMD160)
include_directories(.
        "${BOLOS_SDK}/include"
        "${BOLOS_SDK}/lib_cxng/include"
        "${APP_SRC_DIR}/deps/BLAKE2/ref/"
        "${APP_SRC_DIR}/deps/ledger-zxlib/include"
        "${APP_SRC_DIR}/app/src"
        "${APP_SRC_DIR}/app/src/lib"
        "${APP_SRC_DIR}/app/src/common"
)

add_compile_options(-g -ggdb2 -O3)

# Build with code coverage generation
if(CODE_COVERAGE)
    if(CMAKE_C_COMPILER_ID MATCHES "(Apple)?[Cc]lang")
        add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
        add_link_options(-fprofile-instr-generate -fcoverage-mapping)
    elseif(CMAKE_C_COMPILER_ID MATCHES "GNU")
        add_compile_options(-fprofile-arcs -ftest-coverage)
        link_libraries(gcov)
    else()
        message(FATAL_ERROR "Unsupported compiler used with code coverage generation")
    endif()
endif()

set(APP_SOURCES
    ${APP_SRC_DIR}/deps/ledger-zxlib/src/app_mode.c
    ${APP_SRC_DIR}/deps/ledger-zxlib/src/base58.c
    ${APP_SRC_DIR}/deps/ledger-zxlib/src/bignum.c
    ${APP_SRC_DIR}/deps/ledger-zxlib/src/hexutils.c
    ${APP_SRC_DIR}/deps/ledger-zxlib/src/zxmacros.c
    ${APP_SRC_DIR}/deps/ledger-zxlib/src/zxformat.c
    ${APP_SRC_DIR}/deps/BLAKE2/ref/blake2b-ref.c
    ${APP_SRC_DIR}/deps/BLAKE2/ref/blake2s-ref.c

    ${APP_SRC_DIR}/app/src/crypto_helper.c
    ${APP_SRC_DIR}/app/src/parser.c
    ${APP_SRC_DIR}/app/src/parser_impl.c
    ${APP_SRC_DIR}/app/src/substrate_dispatch_V1.c
    ${APP_SRC_DIR}/app/src/substrate_dispatch.c
    ${APP_SRC_DIR}/app/src/substrate_types_V1.c
    ${APP_SRC_DIR}/app/src/substrate_types.c
)

add_definitions(
    -DLEDGER_MAJOR_VERSION=1
    -DLEDGER_MINOR_VERSION=3000
)


add_executable(fuzz_message
        fuzz_polymesh.c
        os_mocks.c
        ${APP_SOURCES}
)

target_compile_options(fuzz_message PUBLIC -fsanitize=fuzzer,address,undefined)
target_link_options(fuzz_message PUBLIC -lbsd -fsanitize=fuzzer,address,undefined)
