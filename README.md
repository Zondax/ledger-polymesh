# Ledger Polymesh app
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GithubActions](https://github.com/Zondax/ledger-polymesh/actions/workflows/main.yml/badge.svg)](https://github.com/Zondax/ledger-polymesh/blob/master/.github/workflows/main.yml)
-------------------

![zondax](docs/zondax.jpg)

_Please visit our website at [zondax.ch](zondax.ch)_

------------------
This project contains the Polymesh app (https://polymath.network/) for Ledger Nano S and X.

- Ledger Nano S/X BOLOS app
- Specs / Documentation
- C++ unit tests
- Zemu tests

For more information: [How to build](docs/build.md)

## ATTENTION

Please:

- **Do not use in production**
- **Do not use a Ledger device with funds for development purposes.**
- **Have a separate and marked device that is used ONLY for development and testing**

# Polymesh  1.3000.x

## System

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|fill_block |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` _ratio <br/> | 
|remark |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` _remark <br/> | 
|set_heap_pages |    | :heavy_check_mark: | :heavy_check_mark: | `u64` pages <br/> | 
|set_code |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_code_without_checks |    | :heavy_check_mark: | :heavy_check_mark: | `Bytes` code <br/> | 
|set_changes_trie_config |    |   |   | `Option<ChangesTrieConfiguration>` changes_trie_config <br/> | 
|set_storage |    |   |   | `Vec<KeyValue>` items <br/> | 
|kill_storage |    |   |   | `Vec<Key>` keys <br/> | 
|kill_prefix |    |   |   | `Key` prefix <br/>`u32` _subkeys <br/> | 

## Babe

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `BabeEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 

## Timestamp

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<Moment>` now <br/> | 

## Indices

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIndex` index <br/> | 
|transfer |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/>`AccountIndex` index <br/> | 
|free |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIndex` index <br/> | 
|force_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` new <br/>`AccountIndex` index <br/>`bool` freeze <br/> | 
|freeze |    | :heavy_check_mark: | :heavy_check_mark: | `AccountIndex` index <br/> | 

## Authorship

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_uncles |    |   |   | `Vec<Header>` new_uncles <br/> | 

## Balances

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|transfer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|transfer_with_memo |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` dest <br/>`Compact<Balance>` value <br/>`Option<Memo>` memo <br/> | 
|deposit_block_reward_reserve_balance |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<Balance>` value <br/> | 
|set_balance |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` who <br/>`Compact<Balance>` new_free <br/>`Compact<Balance>` new_reserved <br/> | 
|force_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` source <br/>`LookupSource` dest <br/>`Compact<Balance>` value <br/> | 
|burn_account_balance |    | :heavy_check_mark: | :heavy_check_mark: | `Balance` amount <br/> | 

## TransactionPayment

Empty

## Identity

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|cdd_register_did |    |   |   | `AccountId` target_account <br/>`Vec<SecondaryKey>` secondary_keys <br/> | 
|invalidate_cdd_claims |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` cdd <br/>`Moment` disable_from <br/>`Option<Moment>` expiry <br/> | 
|remove_secondary_keys | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vec<Signatory>` signers_to_remove <br/> | 
|accept_primary_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `u64` rotation_auth_id <br/>`Option<u64>` optional_cdd_auth_id <br/> | 
|change_cdd_requirement_for_mk_rotation |    | :heavy_check_mark: | :heavy_check_mark: | `bool` auth_required <br/> | 
|join_identity_as_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `u64` auth_id <br/> | 
|leave_identity_as_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: |  | 
|add_claim | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` target <br/>`Claim` claim <br/>`Option<Moment>` expiry <br/> | 
|revoke_claim | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` target <br/>`Claim` claim <br/> | 
|set_permission_to_signer | :heavy_check_mark:  |   |   | `Signatory` signer <br/>`Permissions` permissions <br/> | 
|legacy_set_permission_to_signer | :heavy_check_mark:  |   |   | `Signatory` signer <br/>`LegacyPermissions` permissions <br/> | 
|freeze_secondary_keys | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: |  | 
|unfreeze_secondary_keys | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: |  | 
|add_authorization | :heavy_check_mark:  |   |   | `Signatory` target <br/>`AuthorizationData` authorization_data <br/>`Option<Moment>` expiry <br/> | 
|remove_authorization | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Signatory` target <br/>`u64` auth_id <br/>`bool` _auth_issuer_pays <br/> | 
|add_secondary_keys_with_authorization | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vec<SecondaryKeyWithAuth>` additional_keys <br/>`Moment` expires_at <br/> | 
|add_investor_uniqueness_claim | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` target <br/>`Claim` claim <br/>`InvestorZKProofData` proof <br/>`Option<Moment>` expiry <br/> | 
|gc_add_cdd_claim |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` target <br/> | 
|gc_revoke_cdd_claim |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` target <br/> | 
|add_investor_uniqueness_claim_v2 |    |   |   | `IdentityId` target <br/>`Scope` scope <br/>`Claim` claim <br/>`ScopeClaimProof` proof <br/>`Option<Moment>` expiry <br/> | 
|revoke_claim_by_index |    | :heavy_check_mark: |   | `IdentityId` target <br/>`ClaimType` claim_type <br/>`Option<Scope>` scope <br/> | 

## CddServiceProviders

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_active_members_limit |    | :heavy_check_mark: | :heavy_check_mark: | `MemberCount` limit <br/> | 
|disable_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/>`Option<Moment>` expiry <br/>`Option<Moment>` at <br/> | 
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` remove <br/>`IdentityId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<IdentityId>` members <br/> | 
|abdicate_membership |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## PolymeshCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_vote_threshold |    | :heavy_check_mark: | :heavy_check_mark: | `u32` n <br/>`u32` d <br/> | 
|set_release_coordinator |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` id <br/> | 
|set_expires_after |    | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlock` expiry <br/> | 
|vote_or_propose |    | :heavy_check_mark: | :heavy_check_mark: | `bool` approve <br/>`Call` call <br/> | 
|vote |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal <br/>`ProposalIndex` index <br/>`bool` approve <br/> | 

## CommitteeMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_active_members_limit |    | :heavy_check_mark: | :heavy_check_mark: | `MemberCount` limit <br/> | 
|disable_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/>`Option<Moment>` expiry <br/>`Option<Moment>` at <br/> | 
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` remove <br/>`IdentityId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<IdentityId>` members <br/> | 
|abdicate_membership |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## TechnicalCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_vote_threshold |    | :heavy_check_mark: | :heavy_check_mark: | `u32` n <br/>`u32` d <br/> | 
|set_release_coordinator |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` id <br/> | 
|set_expires_after |    | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlock` expiry <br/> | 
|vote_or_propose |    | :heavy_check_mark: | :heavy_check_mark: | `bool` approve <br/>`Call` call <br/> | 
|vote |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal <br/>`ProposalIndex` index <br/>`bool` approve <br/> | 

## TechnicalCommitteeMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_active_members_limit |    | :heavy_check_mark: | :heavy_check_mark: | `MemberCount` limit <br/> | 
|disable_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/>`Option<Moment>` expiry <br/>`Option<Moment>` at <br/> | 
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` remove <br/>`IdentityId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<IdentityId>` members <br/> | 
|abdicate_membership |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## UpgradeCommittee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_vote_threshold |    | :heavy_check_mark: | :heavy_check_mark: | `u32` n <br/>`u32` d <br/> | 
|set_release_coordinator |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` id <br/> | 
|set_expires_after |    | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlock` expiry <br/> | 
|vote_or_propose |    | :heavy_check_mark: | :heavy_check_mark: | `bool` approve <br/>`Call` call <br/> | 
|vote |    | :heavy_check_mark: | :heavy_check_mark: | `Hash` proposal <br/>`ProposalIndex` index <br/>`bool` approve <br/> | 

## UpgradeCommitteeMembership

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_active_members_limit |    | :heavy_check_mark: | :heavy_check_mark: | `MemberCount` limit <br/> | 
|disable_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/>`Option<Moment>` expiry <br/>`Option<Moment>` at <br/> | 
|add_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|remove_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` who <br/> | 
|swap_member |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` remove <br/>`IdentityId` add <br/> | 
|reset_members |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<IdentityId>` members <br/> | 
|abdicate_membership |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## MultiSig

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create_multisig | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vec<Signatory>` signers <br/>`u64` sigs_required <br/> | 
|create_or_approve_proposal_as_identity | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`Proposal` proposal <br/>`Option<Moment>` expiry <br/>`bool` auto_close <br/> | 
|create_or_approve_proposal_as_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`Proposal` proposal <br/>`Option<Moment>` expiry <br/>`bool` auto_close <br/> | 
|create_proposal_as_identity | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`Proposal` proposal <br/>`Option<Moment>` expiry <br/>`bool` auto_close <br/> | 
|create_proposal_as_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`Proposal` proposal <br/>`Option<Moment>` expiry <br/>`bool` auto_close <br/> | 
|approve_as_identity | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`u64` proposal_id <br/> | 
|approve_as_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`u64` proposal_id <br/> | 
|reject_as_identity | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`u64` proposal_id <br/> | 
|reject_as_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`u64` proposal_id <br/> | 
|accept_multisig_signer_as_identity | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `u64` auth_id <br/> | 
|accept_multisig_signer_as_key | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `u64` auth_id <br/> | 
|add_multisig_signer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Signatory` signer <br/> | 
|remove_multisig_signer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Signatory` signer <br/> | 
|add_multisig_signers_via_creator | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`Vec<Signatory>` signers <br/> | 
|remove_multisig_signers_via_creator | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`Vec<Signatory>` signers <br/> | 
|change_sigs_required | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `u64` sigs_required <br/> | 
|make_multisig_signer | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/> | 
|make_multisig_primary | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`Option<u64>` optional_cdd_auth_id <br/> | 
|execute_scheduled_proposal | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `AccountId` multisig <br/>`u64` proposal_id <br/>`IdentityId` multisig_did <br/>`Weight` _proposal_weight <br/> | 

## Bridge

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|change_controller |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` controller <br/> | 
|change_admin |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` admin <br/> | 
|change_timelock |    | :heavy_check_mark: | :heavy_check_mark: | `BlockNumber` timelock <br/> | 
|freeze |    | :heavy_check_mark: | :heavy_check_mark: |  | 
|unfreeze |    | :heavy_check_mark: | :heavy_check_mark: |  | 
|change_bridge_limit |    | :heavy_check_mark: | :heavy_check_mark: | `Balance` amount <br/>`BlockNumber` duration <br/> | 
|change_bridge_exempted |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<(IdentityId,bool)>` exempted <br/> | 
|force_handle_bridge_tx |    | :heavy_check_mark: | :heavy_check_mark: | `BridgeTx` bridge_tx <br/> | 
|batch_propose_bridge_tx |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<BridgeTx>` bridge_txs <br/> | 
|propose_bridge_tx |    | :heavy_check_mark: | :heavy_check_mark: | `BridgeTx` bridge_tx <br/> | 
|handle_bridge_tx |    | :heavy_check_mark: | :heavy_check_mark: | `BridgeTx` bridge_tx <br/> | 
|freeze_txs |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<BridgeTx>` bridge_txs <br/> | 
|unfreeze_txs |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<BridgeTx>` bridge_txs <br/> | 
|handle_scheduled_bridge_tx |    | :heavy_check_mark: | :heavy_check_mark: | `BridgeTx` bridge_tx <br/> | 
|add_freeze_admin |    | :heavy_check_mark: |   | `AccountId` freeze_admin <br/> | 
|remove_freeze_admin |    | :heavy_check_mark: |   | `AccountId` freeze_admin <br/> | 

## Staking

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|bond | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` controller <br/>`Compact<BalanceOf>` value <br/>`RewardDestination` payee <br/> | 
|bond_extra | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Compact<BalanceOf>` max_additional <br/> | 
|unbond | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Compact<BalanceOf>` value <br/> | 
|withdraw_unbonded | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `u32` num_slashing_spans <br/> | 
|validate | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `ValidatorPrefs` prefs <br/> | 
|nominate | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vec<LookupSource>` targets <br/> | 
|chill | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: |  | 
|set_payee | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `RewardDestination` payee <br/> | 
|set_controller | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `LookupSource` controller <br/> | 
|set_validator_count |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<u32>` new <br/> | 
|increase_validator_count |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<u32>` additional <br/> | 
|scale_validator_count |    |   |   | `Percent` factor <br/> | 
|add_permissioned_validator |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` identity <br/>`Option<u32>` intended_count <br/> | 
|remove_permissioned_validator |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` identity <br/> | 
|validate_cdd_expiry_nominators |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` targets <br/> | 
|set_commission_cap |    | :heavy_check_mark: | :heavy_check_mark: | `Perbill` new_cap <br/> | 
|set_min_bond_threshold |    | :heavy_check_mark: | :heavy_check_mark: | `BalanceOf` new_value <br/> | 
|force_no_eras |    | :heavy_check_mark: | :heavy_check_mark: |  | 
|force_new_era |    | :heavy_check_mark: | :heavy_check_mark: |  | 
|set_invulnerables |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<AccountId>` invulnerables <br/> | 
|force_unstake |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|force_new_era_always |    | :heavy_check_mark: | :heavy_check_mark: |  | 
|cancel_deferred_slash |    | :heavy_check_mark: | :heavy_check_mark: | `EraIndex` era <br/>`Vec<u32>` slash_indices <br/> | 
|payout_stakers |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|rebond | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Compact<BalanceOf>` value <br/> | 
|set_history_depth |    | :heavy_check_mark: | :heavy_check_mark: | `Compact<EraIndex>` new_history_depth <br/>`Compact<u32>` _era_items_deleted <br/> | 
|reap_stash |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` stash <br/>`u32` num_slashing_spans <br/> | 
|submit_election_solution |    |   |   | `Vec<ValidatorIndex>` winners <br/>`CompactAssignments` compact <br/>`ElectionScore` score <br/>`EraIndex` era <br/>`ElectionSize` size <br/> | 
|submit_election_solution_unsigned |    |   |   | `Vec<ValidatorIndex>` winners <br/>`CompactAssignments` compact <br/>`ElectionScore` score <br/>`EraIndex` era <br/>`ElectionSize` size <br/> | 
|payout_stakers_by_system |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` validator_stash <br/>`EraIndex` era <br/> | 
|change_slashing_allowed_for |    | :heavy_check_mark: | :heavy_check_mark: | `SlashingSwitch` slashing_switch <br/> | 
|update_permissioned_validator_intended_count |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` identity <br/>`u32` new_intended_count <br/> | 

## Offences

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Session

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_keys |    | :heavy_check_mark: | :heavy_check_mark: | `Keys` keys <br/>`Bytes` proof <br/> | 
|purge_keys |    | :heavy_check_mark: | :heavy_check_mark: |  | 

## AuthorityDiscovery

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Grandpa

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|report_equivocation |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|report_equivocation_unsigned |    |   |   | `GrandpaEquivocationProof` equivocation_proof <br/>`KeyOwnerProof` key_owner_proof <br/> | 
|note_stalled |    | :heavy_check_mark: | :heavy_check_mark: | `BlockNumber` delay <br/>`BlockNumber` best_finalized_block_number <br/> | 

## Historical

Empty

## ImOnline

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|heartbeat |    |   |   | `Heartbeat` heartbeat <br/>`Signature` _signature <br/> | 

## RandomnessCollectiveFlip

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## Sudo

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|sudo |    |   |   | `Call` call <br/> | 
|sudo_unchecked_weight |    |   |   | `Call` call <br/>`Weight` _weight <br/> | 
|set_key |    |   |   | `LookupSource` new <br/> | 
|sudo_as |    |   |   | `LookupSource` who <br/>`Call` call <br/> | 

## Asset

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|register_ticker |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|accept_ticker_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `u64` auth_id <br/> | 
|accept_asset_ownership_transfer |    | :heavy_check_mark: | :heavy_check_mark: | `u64` auth_id <br/> | 
|create_asset |    | :heavy_check_mark: | :heavy_check_mark: | `AssetName` name <br/>`Ticker` ticker <br/>`bool` divisible <br/>`AssetType` asset_type <br/>`Vec<AssetIdentifier>` identifiers <br/>`Option<FundingRoundName>` funding_round <br/>`bool` disable_iu <br/> | 
|freeze |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|unfreeze |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|rename_asset |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`AssetName` name <br/> | 
|issue |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Balance` amount <br/> | 
|redeem |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Balance` value <br/> | 
|make_divisible |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|add_documents |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<Document>` docs <br/>`Ticker` ticker <br/> | 
|remove_documents |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<DocumentId>` ids <br/>`Ticker` ticker <br/> | 
|set_funding_round |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`FundingRoundName` name <br/> | 
|update_identifiers |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Vec<AssetIdentifier>` identifiers <br/> | 
|claim_classic_ticker |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`EcdsaSignature` ethereum_signature <br/> | 
|reserve_classic_ticker |    | :heavy_check_mark: | :heavy_check_mark: | `ClassicTickerImport` classic_ticker_import <br/>`IdentityId` contract_did <br/>`TickerRegistrationConfig` config <br/> | 
|controller_transfer |    | :heavy_check_mark: |   | `Ticker` ticker <br/>`Balance` value <br/>`PortfolioId` from_portfolio <br/> | 
|register_custom_asset_type |    | :heavy_check_mark: |   | `Bytes` ty <br/> | 

## CapitalDistribution

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|distribute |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`Option<PortfolioNumber>` portfolio <br/>`Ticker` currency <br/>`Balance` per_share <br/>`Balance` amount <br/>`Moment` payment_at <br/>`Option<Moment>` expires_at <br/> | 
|claim |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/> | 
|push_benefit |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`IdentityId` holder <br/> | 
|reclaim |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/> | 
|remove_distribution |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/> | 

## Checkpoint

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create_checkpoint |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|set_schedules_max_complexity |    | :heavy_check_mark: | :heavy_check_mark: | `u64` max_complexity <br/> | 
|create_schedule |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`ScheduleSpec` schedule <br/> | 
|remove_schedule |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`ScheduleId` id <br/> | 

## ComplianceManager

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_compliance_requirement |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Vec<Condition>` sender_conditions <br/>`Vec<Condition>` receiver_conditions <br/> | 
|remove_compliance_requirement |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`u32` id <br/> | 
|replace_asset_compliance |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Vec<ComplianceRequirement>` asset_compliance <br/> | 
|reset_asset_compliance |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|pause_asset_compliance |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|resume_asset_compliance |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/> | 
|add_default_trusted_claim_issuer |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`TrustedIssuer` issuer <br/> | 
|remove_default_trusted_claim_issuer |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`IdentityId` issuer <br/> | 
|change_compliance_requirement |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`ComplianceRequirement` new_req <br/> | 

## CorporateAction

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_max_details_length |    | :heavy_check_mark: | :heavy_check_mark: | `u32` length <br/> | 
|set_default_targets |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`TargetIdentities` targets <br/> | 
|set_default_withholding_tax |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Tax` tax <br/> | 
|set_did_withholding_tax |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`IdentityId` taxed_did <br/>`Option<Tax>` tax <br/> | 
|initiate_corporate_action |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`CAKind` kind <br/>`Moment` decl_date <br/>`Option<RecordDateSpec>` record_date <br/>`CADetails` details <br/>`Option<TargetIdentities>` targets <br/>`Option<Tax>` default_withholding_tax <br/>`Option<Vec<(IdentityId,Tax)>>` withholding_tax <br/> | 
|link_ca_doc |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` id <br/>`Vec<DocumentId>` docs <br/> | 
|remove_ca |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/> | 
|change_record_date |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`Option<RecordDateSpec>` record_date <br/> | 

## CorporateBallot

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|attach_ballot |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`BallotTimeRange` range <br/>`BallotMeta` meta <br/>`bool` rcv <br/> | 
|vote |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`Vec<BallotVote>` votes <br/> | 
|change_end |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`Moment` end <br/> | 
|change_meta |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`BallotMeta` meta <br/> | 
|change_rcv |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/>`bool` rcv <br/> | 
|remove_ballot |    | :heavy_check_mark: | :heavy_check_mark: | `CAId` ca_id <br/> | 

## Permissions

Empty

## Pips

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_prune_historical_pips |    | :heavy_check_mark: | :heavy_check_mark: | `bool` prune <br/> | 
|set_min_proposal_deposit |    | :heavy_check_mark: | :heavy_check_mark: | `Balance` deposit <br/> | 
|set_default_enactment_period |    | :heavy_check_mark: | :heavy_check_mark: | `BlockNumber` duration <br/> | 
|set_pending_pip_expiry |    | :heavy_check_mark: | :heavy_check_mark: | `MaybeBlock` expiry <br/> | 
|set_max_pip_skip_count |    | :heavy_check_mark: | :heavy_check_mark: | `SkippedCount` max <br/> | 
|set_active_pip_limit |    | :heavy_check_mark: | :heavy_check_mark: | `u32` limit <br/> | 
|propose | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Proposal` proposal <br/>`Balance` deposit <br/>`Option<Url>` url <br/>`Option<PipDescription>` description <br/> | 
|vote | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `PipId` id <br/>`bool` aye_or_nay <br/>`Balance` deposit <br/> | 
|approve_committee_proposal |    | :heavy_check_mark: | :heavy_check_mark: | `PipId` id <br/> | 
|reject_proposal |    | :heavy_check_mark: | :heavy_check_mark: | `PipId` id <br/> | 
|prune_proposal |    | :heavy_check_mark: | :heavy_check_mark: | `PipId` id <br/> | 
|reschedule_execution |    | :heavy_check_mark: | :heavy_check_mark: | `PipId` id <br/>`Option<BlockNumber>` until <br/> | 
|clear_snapshot |    | :heavy_check_mark: | :heavy_check_mark: |  | 
|snapshot |    | :heavy_check_mark: | :heavy_check_mark: |  | 
|enact_snapshot_results |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<(PipId,SnapshotResult)>` results <br/> | 
|execute_scheduled_pip |    | :heavy_check_mark: | :heavy_check_mark: | `PipId` id <br/> | 
|expire_scheduled_pip |    | :heavy_check_mark: | :heavy_check_mark: | `IdentityId` did <br/>`PipId` id <br/> | 

## Portfolio

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create_portfolio |    | :heavy_check_mark: | :heavy_check_mark: | `PortfolioName` name <br/> | 
|delete_portfolio |    | :heavy_check_mark: | :heavy_check_mark: | `PortfolioNumber` num <br/> | 
|move_portfolio_funds |    | :heavy_check_mark: | :heavy_check_mark: | `PortfolioId` from <br/>`PortfolioId` to <br/>`Vec<MovePortfolioItem>` items <br/> | 
|rename_portfolio |    | :heavy_check_mark: | :heavy_check_mark: | `PortfolioNumber` num <br/>`PortfolioName` to_name <br/> | 
|quit_portfolio_custody |    | :heavy_check_mark: |   | `PortfolioId` pid <br/> | 
|accept_portfolio_custody |    | :heavy_check_mark: |   | `u64` auth_id <br/> | 

## ProtocolFee

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|change_coefficient |    | :heavy_check_mark: | :heavy_check_mark: | `PosRatio` coefficient <br/> | 
|change_base_fee |    |   |   | `ProtocolOp` op <br/>`Balance` base_fee <br/> | 

## Scheduler

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|schedule |    |   |   | `BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel |    |   |   | `BlockNumber` when <br/>`u32` index <br/> | 
|schedule_named |    |   |   | `Bytes` id <br/>`BlockNumber` when <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|cancel_named |    |   |   | `Bytes` id <br/> | 
|schedule_after |    |   |   | `BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 
|schedule_named_after |    |   |   | `Bytes` id <br/>`BlockNumber` after <br/>`Option<Period>` maybe_periodic <br/>`Priority` priority <br/>`Call` call <br/> | 

## Settlement

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create_venue |    | :heavy_check_mark: | :heavy_check_mark: | `VenueDetails` details <br/>`Vec<AccountId>` signers <br/>`VenueType` typ <br/> | 
|update_venue_details |    | :heavy_check_mark: |   | `u64` id <br/>`VenueDetails` details <br/> | 
|update_venue_type |    | :heavy_check_mark: |   | `u64` id <br/>`VenueType` typ <br/> | 
|add_instruction |    | :heavy_check_mark: | :heavy_check_mark: | `u64` venue_id <br/>`SettlementType` settlement_type <br/>`Option<Moment>` trade_date <br/>`Option<Moment>` value_date <br/>`Vec<Leg>` legs <br/> | 
|add_and_affirm_instruction |    | :heavy_check_mark: | :heavy_check_mark: | `u64` venue_id <br/>`SettlementType` settlement_type <br/>`Option<Moment>` trade_date <br/>`Option<Moment>` value_date <br/>`Vec<Leg>` legs <br/>`Vec<PortfolioId>` portfolios <br/> | 
|affirm_instruction |    | :heavy_check_mark: | :heavy_check_mark: | `u64` instruction_id <br/>`Vec<PortfolioId>` portfolios <br/>`u32` max_legs_count <br/> | 
|withdraw_affirmation |    | :heavy_check_mark: | :heavy_check_mark: | `u64` instruction_id <br/>`Vec<PortfolioId>` portfolios <br/>`u32` max_legs_count <br/> | 
|reject_instruction |    | :heavy_check_mark: | :heavy_check_mark: | `u64` instruction_id <br/>`PortfolioId` portfolio <br/>`u32` num_of_legs <br/> | 
|affirm_with_receipts |    | :heavy_check_mark: | :heavy_check_mark: | `u64` instruction_id <br/>`Vec<ReceiptDetails>` receipt_details <br/>`Vec<PortfolioId>` portfolios <br/>`u32` max_legs_count <br/> | 
|claim_receipt |    | :heavy_check_mark: | :heavy_check_mark: | `u64` instruction_id <br/>`ReceiptDetails` receipt_details <br/> | 
|unclaim_receipt |    | :heavy_check_mark: | :heavy_check_mark: | `u64` instruction_id <br/>`u64` leg_id <br/> | 
|set_venue_filtering |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`bool` enabled <br/> | 
|allow_venues |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Vec<u64>` venues <br/> | 
|disallow_venues |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`Vec<u64>` venues <br/> | 
|change_receipt_validity |    | :heavy_check_mark: |   | `u64` receipt_uid <br/>`bool` validity <br/> | 
|execute_scheduled_instruction |    | :heavy_check_mark: | :heavy_check_mark: | `u64` instruction_id <br/>`u32` _legs_count <br/> | 
|reschedule_instruction |    | :heavy_check_mark: |   | `u64` instruction_id <br/> | 

## Statistics

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|add_transfer_manager |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`TransferManager` new_transfer_manager <br/> | 
|remove_transfer_manager |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`TransferManager` transfer_manager <br/> | 
|add_exempted_entities |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`TransferManager` transfer_manager <br/>`Vec<ScopeId>` exempted_entities <br/> | 
|remove_exempted_entities |    | :heavy_check_mark: | :heavy_check_mark: | `Ticker` ticker <br/>`TransferManager` transfer_manager <br/>`Vec<ScopeId>` entities <br/> | 

## Sto

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create_fundraiser |    | :heavy_check_mark: |   | `PortfolioId` offering_portfolio <br/>`Ticker` offering_asset <br/>`PortfolioId` raising_portfolio <br/>`Ticker` raising_asset <br/>`Vec<PriceTier>` tiers <br/>`u64` venue_id <br/>`Option<Moment>` start <br/>`Option<Moment>` end <br/>`Balance` minimum_investment <br/>`FundraiserName` fundraiser_name <br/> | 
|invest |    | :heavy_check_mark: |   | `PortfolioId` investment_portfolio <br/>`PortfolioId` funding_portfolio <br/>`Ticker` offering_asset <br/>`u64` fundraiser_id <br/>`Balance` purchase_amount <br/>`Option<Balance>` max_price <br/>`Option<ReceiptDetails>` receipt <br/> | 
|freeze_fundraiser |    | :heavy_check_mark: |   | `Ticker` offering_asset <br/>`u64` fundraiser_id <br/> | 
|unfreeze_fundraiser |    | :heavy_check_mark: |   | `Ticker` offering_asset <br/>`u64` fundraiser_id <br/> | 
|modify_fundraiser_window |    | :heavy_check_mark: |   | `Ticker` offering_asset <br/>`u64` fundraiser_id <br/>`Moment` start <br/>`Option<Moment>` end <br/> | 
|stop |    | :heavy_check_mark: |   | `Ticker` offering_asset <br/>`u64` fundraiser_id <br/> | 

## Treasury

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|disbursement |    | :heavy_check_mark: | :heavy_check_mark: | `Vec<Beneficiary>` beneficiaries <br/> | 
|reimbursement |    | :heavy_check_mark: | :heavy_check_mark: | `BalanceOf` amount <br/> | 

## Utility

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|batch | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vec<Call>` calls <br/> | 
|batch_atomic | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vec<Call>` calls <br/> | 
|batch_optimistic | :heavy_check_mark:  | :heavy_check_mark: | :heavy_check_mark: | `Vec<Call>` calls <br/> | 
|relay_tx |    | :heavy_check_mark: | :heavy_check_mark: | `AccountId` target <br/>`OffChainSignature` signature <br/>`UniqueCall` call <br/> | 

## Base

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|

## ExternalAgents

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|create_group |    |   |   | `Ticker` ticker <br/>`ExtrinsicPermissions` perms <br/> | 
|set_group_permissions |    |   |   | `Ticker` ticker <br/>`AGId` id <br/>`ExtrinsicPermissions` perms <br/> | 
|remove_agent |    | :heavy_check_mark: |   | `Ticker` ticker <br/>`IdentityId` agent <br/> | 
|abdicate |    | :heavy_check_mark: |   | `Ticker` ticker <br/> | 
|change_group |    |   |   | `Ticker` ticker <br/>`IdentityId` agent <br/>`AgentGroup` group <br/> | 
|accept_become_agent |    | :heavy_check_mark: |   | `u64` auth_id <br/> | 

## Relayer

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|set_paying_key |    | :heavy_check_mark: |   | `AccountId` user_key <br/>`Balance` polyx_limit <br/> | 
|accept_paying_key |    | :heavy_check_mark: |   | `u64` auth_id <br/> | 
|remove_paying_key |    | :heavy_check_mark: |   | `AccountId` user_key <br/>`AccountId` paying_key <br/> | 
|update_polyx_limit |    | :heavy_check_mark: |   | `AccountId` user_key <br/>`Balance` polyx_limit <br/> | 
|increase_polyx_limit |    | :heavy_check_mark: |   | `AccountId` user_key <br/>`Balance` amount <br/> | 
|decrease_polyx_limit |    | :heavy_check_mark: |   | `AccountId` user_key <br/>`Balance` amount <br/> | 

## Rewards

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|claim_itn_reward |    | :heavy_check_mark: |   | `AccountId` reward_address <br/>`AccountId` itn_address <br/>`OffChainSignature` signature <br/> | 
|set_itn_reward_status |    |   |   | `AccountId` itn_address <br/>`ItnRewardStatus` status <br/> | 

## TestUtils

| Name        | Light | XL | Nesting | Arguments | 
| :---------- |:------------:|:--------:|:--------:|:--------|
|register_did |    |   |   | `InvestorUid` uid <br/>`Vec<SecondaryKey>` secondary_keys <br/> | 
|mock_cdd_register_did |    |   |   | `AccountId` target_account <br/> | 
|get_my_did |    |   |   |  | 
|get_cdd_of |    |   |   | `AccountId` of <br/> | 

