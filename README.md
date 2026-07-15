# Ledger Polymesh App

[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

---

![zondax_light](docs/zondax_light.png#gh-light-mode-only)
![zondax_dark](docs/zondax_dark.png#gh-dark-mode-only)

_Please visit our website at [zondax.ch](https://www.zondax.ch)_

---

This project contains the Polymesh app (<https://polymesh.network/>) for Ledger Nano S+, Nano X, Flex, Stax, and Apex P.

This application is a Polymesh-branded fork of the generic Polkadot Ledger app, using the Polymesh SLIP44 coin type (595) and SS58 prefix (12). It uses the chain-agnostic metadata parsing approach (verifying metadata hash) which is fully compatible with Polymesh as a Polkadot SDK-based chain.

**Derivation path:** `m/44'/595'/account'/change/address_index`

This repository contains:

- Ledger (BOLOS) app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information:

- [How to build](docs/build.md)
- :warning:[Formatting Limitations](docs/format.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**
