/*******************************************************************************
 *  (c) 2019 Zondax GmbH
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
 ********************************************************************************/
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM 0
#define PD_CALL_BABE 1
#define PD_CALL_TIMESTAMP 2
#define PD_CALL_INDICES 3
#define PD_CALL_BALANCES 4
#define PD_CALL_AUTHORSHIP 6
#define PD_CALL_STAKING 7
#define PD_CALL_OFFENCES 8
#define PD_CALL_SESSION 9
#define PD_CALL_FINALITYTRACKER 10
#define PD_CALL_GRANDPA 11
#define PD_CALL_IMONLINE 12
#define PD_CALL_AUTHORITYDISCOVERY 13
#define PD_CALL_RANDOMNESSCOLLECTIVEFLIP 14
#define PD_CALL_SUDO 16
#define PD_CALL_MULTISIG 17
#define PD_CALL_CONTRACTS 19
#define PD_CALL_TREASURY 20
#define PD_CALL_POLYMESHCOMMITTEE 21
#define PD_CALL_COMMITTEEMEMBERSHIP 22
#define PD_CALL_PIPS 23
#define PD_CALL_TECHNICALCOMMITTEE 24
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP 25
#define PD_CALL_UPGRADECOMMITTEE 26
#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP 27
#define PD_CALL_ASSET 28
#define PD_CALL_DIVIDEND 29
#define PD_CALL_IDENTITY 30
#define PD_CALL_BRIDGE 31
#define PD_CALL_COMPLIANCEMANAGER 32
#define PD_CALL_VOTING 33
#define PD_CALL_STOCAPPED 34
#define PD_CALL_EXEMPTION 35
#define PD_CALL_SETTLEMENT 36
#define PD_CALL_STO 37
#define PD_CALL_CDDSERVICEPROVIDERS 38
#define PD_CALL_STATISTIC 39
#define PD_CALL_PROTOCOLFEE 40
#define PD_CALL_UTILITY 41
#define PD_CALL_PORTFOLIO 42
#define PD_CALL_CONFIDENTIAL 43
#define PD_CALL_SCHEDULER 45
#define PD_CALL_CORPORATEACTION 46
#define PD_CALL_CORPORATEBALLOT 47
#define PD_CALL_CAPITALDISTRIBUTION 48
#define PD_CALL_CHECKPOINT 49

#define PD_CALL_SYSTEM_FILL_BLOCK 0
typedef struct {
  pd_Perbill_t _ratio;
} pd_system_fill_block_t;

#define PD_CALL_SYSTEM_REMARK 1
typedef struct {
  pd_Bytes_t _remark;
} pd_system_remark_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES 2
typedef struct {
  pd_u64_t pages;
} pd_system_set_heap_pages_t;

#define PD_CALL_SYSTEM_SET_CODE 3
typedef struct {
  pd_Bytes_t code;
} pd_system_set_code_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS 4
typedef struct {
  pd_Bytes_t code;
} pd_system_set_code_without_checks_t;

#define PD_CALL_SYSTEM_SET_CHANGES_TRIE_CONFIG 5
typedef struct {
  pd_OptionChangesTrieConfiguration_t changes_trie_config;
} pd_system_set_changes_trie_config_t;

#define PD_CALL_SYSTEM_SET_STORAGE 6
typedef struct {
  pd_VecKeyValue_t items;
} pd_system_set_storage_t;

#define PD_CALL_SYSTEM_KILL_STORAGE 7
typedef struct {
  pd_VecKey_t keys;
} pd_system_kill_storage_t;

#define PD_CALL_SYSTEM_KILL_PREFIX 8
typedef struct {
  pd_Key_t prefix;
  pd_u32_t _subkeys;
} pd_system_kill_prefix_t;

#define PD_CALL_SYSTEM_SUICIDE 9
typedef struct {
} pd_system_suicide_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION 0
typedef struct {
  pd_EquivocationProof_t equivocation_proof;
  pd_KeyOwnerProof_t key_owner_proof;
} pd_babe_report_equivocation_t;

#define PD_CALL_BABE_REPORT_EQUIVOCATION_UNSIGNED 1
typedef struct {
  pd_EquivocationProof_t equivocation_proof;
  pd_KeyOwnerProof_t key_owner_proof;
} pd_babe_report_equivocation_unsigned_t;

#define PD_CALL_TIMESTAMP_SET 0
typedef struct {
  pd_CompactMoment_t now;
} pd_timestamp_set_t;

#define PD_CALL_INDICES_CLAIM 0
typedef struct {
  pd_AccountIndex_t index;
} pd_indices_claim_t;

#define PD_CALL_INDICES_TRANSFER 1
typedef struct {
  pd_AccountId_t new_;
  pd_AccountIndex_t index;
} pd_indices_transfer_t;

#define PD_CALL_INDICES_FREE 2
typedef struct {
  pd_AccountIndex_t index;
} pd_indices_free_t;

#define PD_CALL_INDICES_FORCE_TRANSFER 3
typedef struct {
  pd_AccountId_t new_;
  pd_AccountIndex_t index;
  pd_bool_t freeze;
} pd_indices_force_transfer_t;

#define PD_CALL_INDICES_FREEZE 4
typedef struct {
  pd_AccountIndex_t index;
} pd_indices_freeze_t;

#define PD_CALL_BALANCES_TRANSFER 0
typedef struct {
  pd_LookupSource_t dest;
  pd_CompactBalance_t value;
} pd_balances_transfer_t;

#define PD_CALL_BALANCES_TRANSFER_WITH_MEMO 1
typedef struct {
  pd_LookupSource_t dest;
  pd_CompactBalance_t value;
  pd_OptionMemo_t memo;
} pd_balances_transfer_with_memo_t;

#define PD_CALL_BALANCES_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE 2
typedef struct {
  pd_CompactBalance_t value;
} pd_balances_deposit_block_reward_reserve_balance_t;

#define PD_CALL_BALANCES_SET_BALANCE 3
typedef struct {
  pd_LookupSource_t who;
  pd_CompactBalance_t new_free;
  pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER 4
typedef struct {
  pd_LookupSource_t source;
  pd_LookupSource_t dest;
  pd_CompactBalance_t value;
} pd_balances_force_transfer_t;

#define PD_CALL_BALANCES_BURN_ACCOUNT_BALANCE 5
typedef struct {
  pd_Balance_t amount;
} pd_balances_burn_account_balance_t;

#define PD_CALL_AUTHORSHIP_SET_UNCLES 0
typedef struct {
  pd_VecHeader_t new_uncles;
} pd_authorship_set_uncles_t;

#define PD_CALL_STAKING_BOND 0
typedef struct {
  pd_LookupSource_t controller;
  pd_CompactBalanceOf_t value;
  pd_RewardDestination_t payee;
} pd_staking_bond_t;

#define PD_CALL_STAKING_BOND_EXTRA 1
typedef struct {
  pd_CompactBalanceOf_t max_additional;
} pd_staking_bond_extra_t;

#define PD_CALL_STAKING_UNBOND 2
typedef struct {
  pd_CompactBalanceOf_t value;
} pd_staking_unbond_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED 3
typedef struct {
  pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_t;

#define PD_CALL_STAKING_VALIDATE 4
typedef struct {
  pd_ValidatorPrefs_t prefs;
} pd_staking_validate_t;

#define PD_CALL_STAKING_NOMINATE 5
typedef struct {
  pd_VecLookupSource_t targets;
} pd_staking_nominate_t;

#define PD_CALL_STAKING_CHILL 6
typedef struct {
} pd_staking_chill_t;

#define PD_CALL_STAKING_SET_PAYEE 7
typedef struct {
  pd_RewardDestination_t payee;
} pd_staking_set_payee_t;

#define PD_CALL_STAKING_SET_CONTROLLER 8
typedef struct {
  pd_LookupSource_t controller;
} pd_staking_set_controller_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT 9
typedef struct {
  pd_Compactu32_t new_;
} pd_staking_set_validator_count_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT 10
typedef struct {
  pd_Compactu32_t additional;
} pd_staking_increase_validator_count_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT 11
typedef struct {
  pd_Percent_t factor;
} pd_staking_scale_validator_count_t;

#define PD_CALL_STAKING_ADD_PERMISSIONED_VALIDATOR 12
typedef struct {
  pd_IdentityId_t identity;
} pd_staking_add_permissioned_validator_t;

#define PD_CALL_STAKING_REMOVE_PERMISSIONED_VALIDATOR 13
typedef struct {
  pd_IdentityId_t identity;
} pd_staking_remove_permissioned_validator_t;

#define PD_CALL_STAKING_VALIDATE_CDD_EXPIRY_NOMINATORS 14
typedef struct {
  pd_VecAccountId_t targets;
} pd_staking_validate_cdd_expiry_nominators_t;

#define PD_CALL_STAKING_SET_COMMISSION_CAP 15
typedef struct {
  pd_Perbill_t new_cap;
} pd_staking_set_commission_cap_t;

#define PD_CALL_STAKING_SET_MIN_BOND_THRESHOLD 16
typedef struct {
  pd_BalanceOf_t new_value;
} pd_staking_set_min_bond_threshold_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS 17
typedef struct {
} pd_staking_force_no_eras_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA 18
typedef struct {
} pd_staking_force_new_era_t;

#define PD_CALL_STAKING_SET_INVULNERABLES 19
typedef struct {
  pd_VecAccountId_t validators;
} pd_staking_set_invulnerables_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE 20
typedef struct {
  pd_AccountId_t stash;
  pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS 21
typedef struct {
} pd_staking_force_new_era_always_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH 22
typedef struct {
  pd_EraIndex_t era;
  pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS 23
typedef struct {
  pd_AccountId_t validator_stash;
  pd_EraIndex_t era;
} pd_staking_payout_stakers_t;

#define PD_CALL_STAKING_REBOND 24
typedef struct {
  pd_CompactBalanceOf_t value;
} pd_staking_rebond_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH 25
typedef struct {
  pd_CompactEraIndex_t new_history_depth;
  pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_t;

#define PD_CALL_STAKING_REAP_STASH 26
typedef struct {
  pd_AccountId_t stash;
  pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION 27
typedef struct {
  pd_VecValidatorIndex_t winners;
  pd_CompactAssignments_t compact;
  pd_ElectionScore_t score;
  pd_EraIndex_t era;
  pd_ElectionSize_t size;
} pd_staking_submit_election_solution_t;

#define PD_CALL_STAKING_SUBMIT_ELECTION_SOLUTION_UNSIGNED 28
typedef struct {
  pd_VecValidatorIndex_t winners;
  pd_CompactAssignments_t compact;
  pd_ElectionScore_t score;
  pd_EraIndex_t era;
  pd_ElectionSize_t size;
} pd_staking_submit_election_solution_unsigned_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_SYSTEM 29
typedef struct {
  pd_AccountId_t validator_stash;
  pd_EraIndex_t era;
} pd_staking_payout_stakers_by_system_t;

#define PD_CALL_STAKING_CHANGE_SLASHING_ALLOWED_FOR 30
typedef struct {
  pd_SlashingSwitch_t slashing_switch;
} pd_staking_change_slashing_allowed_for_t;

#define PD_CALL_SESSION_SET_KEYS 0
typedef struct {
  pd_Keys_t keys;
  pd_Bytes_t proof;
} pd_session_set_keys_t;

#define PD_CALL_SESSION_PURGE_KEYS 1
typedef struct {
} pd_session_purge_keys_t;

#define PD_CALL_FINALITYTRACKER_FINAL_HINT 0
typedef struct {
  pd_CompactBlockNumber_t hint;
} pd_finalitytracker_final_hint_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION 0
typedef struct {
  pd_EquivocationProof_t equivocation_proof;
  pd_KeyOwnerProof_t key_owner_proof;
} pd_grandpa_report_equivocation_t;

#define PD_CALL_GRANDPA_REPORT_EQUIVOCATION_UNSIGNED 1
typedef struct {
  pd_EquivocationProof_t equivocation_proof;
  pd_KeyOwnerProof_t key_owner_proof;
} pd_grandpa_report_equivocation_unsigned_t;

#define PD_CALL_GRANDPA_NOTE_STALLED 2
typedef struct {
  pd_BlockNumber_t delay;
  pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_t;

#define PD_CALL_IMONLINE_HEARTBEAT 0
typedef struct {
  pd_Heartbeat_t heartbeat;
  pd_Signature_t _signature;
} pd_imonline_heartbeat_t;

#define PD_CALL_IMONLINE_SET_SLASHING_PARAMS 1
typedef struct {
  pd_OfflineSlashingParams_t params;
} pd_imonline_set_slashing_params_t;

#define PD_CALL_SUDO_SUDO 0
typedef struct {
  pd_Call_t call;
} pd_sudo_sudo_t;

#define PD_CALL_SUDO_SUDO_UNCHECKED_WEIGHT 1
typedef struct {
  pd_Call_t call;
  pd_Weight_t _weight;
} pd_sudo_sudo_unchecked_weight_t;

#define PD_CALL_SUDO_SET_KEY 2
typedef struct {
  pd_LookupSource_t new_;
} pd_sudo_set_key_t;

#define PD_CALL_SUDO_SUDO_AS 3
typedef struct {
  pd_LookupSource_t who;
  pd_Call_t call;
} pd_sudo_sudo_as_t;

#define PD_CALL_MULTISIG_CREATE_MULTISIG 0
typedef struct {
  pd_VecSignatory_t signers;
  pd_u64_t sigs_required;
} pd_multisig_create_multisig_t;

#define PD_CALL_MULTISIG_APPROVE_AS_IDENTITY 5
typedef struct {
  pd_AccountId_t multisig;
  pd_u64_t proposal_id;
} pd_multisig_approve_as_identity_t;

#define PD_CALL_MULTISIG_APPROVE_AS_KEY 6
typedef struct {
  pd_AccountId_t multisig;
  pd_u64_t proposal_id;
} pd_multisig_approve_as_key_t;

#define PD_CALL_MULTISIG_REJECT_AS_IDENTITY 7
typedef struct {
  pd_AccountId_t multisig;
  pd_u64_t proposal_id;
} pd_multisig_reject_as_identity_t;

#define PD_CALL_MULTISIG_REJECT_AS_KEY 8
typedef struct {
  pd_AccountId_t multisig;
  pd_u64_t proposal_id;
} pd_multisig_reject_as_key_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY 9
typedef struct {
  pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_identity_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_KEY 10
typedef struct {
  pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_key_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNER 11
typedef struct {
  pd_Signatory_t signer;
} pd_multisig_add_multisig_signer_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNER 12
typedef struct {
  pd_Signatory_t signer;
} pd_multisig_remove_multisig_signer_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNERS_VIA_CREATOR 13
typedef struct {
  pd_AccountId_t multisig;
  pd_VecSignatory_t signers;
} pd_multisig_add_multisig_signers_via_creator_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR 14
typedef struct {
  pd_AccountId_t multisig;
  pd_VecSignatory_t signers;
} pd_multisig_remove_multisig_signers_via_creator_t;

#define PD_CALL_MULTISIG_CHANGE_SIGS_REQUIRED 15
typedef struct {
  pd_u64_t sigs_required;
} pd_multisig_change_sigs_required_t;

#define PD_CALL_MULTISIG_CHANGE_ALL_SIGNERS_AND_SIGS_REQUIRED 16
typedef struct {
  pd_VecSignatory_t signers;
  pd_u64_t sigs_required;
} pd_multisig_change_all_signers_and_sigs_required_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_SIGNER 17
typedef struct {
  pd_AccountId_t multisig;
} pd_multisig_make_multisig_signer_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_PRIMARY 18
typedef struct {
  pd_AccountId_t multisig;
  pd_Optionu64_t optional_cdd_auth_id;
} pd_multisig_make_multisig_primary_t;

#define PD_CALL_CONTRACTS_UPDATE_SCHEDULE 0
typedef struct {
  pd_Schedule_t schedule;
} pd_contracts_update_schedule_t;

#define PD_CALL_CONTRACTS_PUT_CODE 1
typedef struct {
  pd_TemplateMetadata_t meta_info;
  pd_BalanceOf_t instantiation_fee;
  pd_Bytes_t code;
} pd_contracts_put_code_t;

#define PD_CALL_CONTRACTS_CALL 2
typedef struct {
  pd_LookupSource_t dest;
  pd_CompactBalanceOf_t value;
  pd_CompactGas_t gas_limit;
  pd_Bytes_t data;
} pd_contracts_call_t;

#define PD_CALL_CONTRACTS_INSTANTIATE 3
typedef struct {
  pd_CompactBalanceOf_t endowment;
  pd_CompactGas_t gas_limit;
  pd_CodeHash_t code_hash;
  pd_Bytes_t data;
  pd_BalanceOf_t max_fee;
} pd_contracts_instantiate_t;

#define PD_CALL_CONTRACTS_FREEZE_INSTANTIATION 4
typedef struct {
  pd_CodeHash_t code_hash;
} pd_contracts_freeze_instantiation_t;

#define PD_CALL_CONTRACTS_UNFREEZE_INSTANTIATION 5
typedef struct {
  pd_CodeHash_t code_hash;
} pd_contracts_unfreeze_instantiation_t;

#define PD_CALL_CONTRACTS_TRANSFER_TEMPLATE_OWNERSHIP 6
typedef struct {
  pd_CodeHash_t code_hash;
  pd_IdentityId_t new_owner;
} pd_contracts_transfer_template_ownership_t;

#define PD_CALL_CONTRACTS_CHANGE_TEMPLATE_FEES 7
typedef struct {
  pd_CodeHash_t code_hash;
  pd_OptionBalanceOf_t new_instantiation_fee;
  pd_OptionBalanceOf_t new_usage_fee;
} pd_contracts_change_template_fees_t;

#define PD_CALL_CONTRACTS_CHANGE_TEMPLATE_META_URL 8
typedef struct {
  pd_CodeHash_t code_hash;
  pd_OptionMetaUrl_t new_url;
} pd_contracts_change_template_meta_url_t;

#define PD_CALL_TREASURY_DISBURSEMENT 0
typedef struct {
  pd_VecBeneficiary_t beneficiaries;
} pd_treasury_disbursement_t;

#define PD_CALL_TREASURY_REIMBURSEMENT 1
typedef struct {
  pd_BalanceOf_t amount;
} pd_treasury_reimbursement_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_VOTE_THRESHOLD 0
typedef struct {
  pd_u32_t n;
  pd_u32_t d;
} pd_polymeshcommittee_set_vote_threshold_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_RELEASE_COORDINATOR 1
typedef struct {
  pd_IdentityId_t id;
} pd_polymeshcommittee_set_release_coordinator_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_EXPIRES_AFTER 2
typedef struct {
  pd_MaybeBlock_t expiry;
} pd_polymeshcommittee_set_expires_after_t;

#define PD_CALL_POLYMESHCOMMITTEE_CLOSE 3
typedef struct {
  pd_Hash_t proposal;
  pd_CompactProposalIndex_t index;
} pd_polymeshcommittee_close_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE 5
typedef struct {
  pd_Hash_t proposal;
  pd_ProposalIndex_t index;
  pd_bool_t approve;
} pd_polymeshcommittee_vote_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT 0
typedef struct {
  pd_MemberCount_t limit;
} pd_committeemembership_set_active_members_limit_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_DISABLE_MEMBER 1
typedef struct {
  pd_IdentityId_t who;
  pd_OptionMoment_t expiry;
  pd_OptionMoment_t at;
} pd_committeemembership_disable_member_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ADD_MEMBER 2
typedef struct {
  pd_IdentityId_t who;
} pd_committeemembership_add_member_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_REMOVE_MEMBER 3
typedef struct {
  pd_IdentityId_t who;
} pd_committeemembership_remove_member_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SWAP_MEMBER 4
typedef struct {
  pd_IdentityId_t remove;
  pd_IdentityId_t add;
} pd_committeemembership_swap_member_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_RESET_MEMBERS 5
typedef struct {
  pd_VecIdentityId_t members;
} pd_committeemembership_reset_members_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP 6
typedef struct {
} pd_committeemembership_abdicate_membership_t;

#define PD_CALL_PIPS_SET_PRUNE_HISTORICAL_PIPS 0
typedef struct {
  pd_bool_t new_value;
} pd_pips_set_prune_historical_pips_t;

#define PD_CALL_PIPS_SET_MIN_PROPOSAL_DEPOSIT 1
typedef struct {
  pd_BalanceOf_t deposit;
} pd_pips_set_min_proposal_deposit_t;

#define PD_CALL_PIPS_SET_PROPOSAL_COOL_OFF_PERIOD 2
typedef struct {
  pd_BlockNumber_t duration;
} pd_pips_set_proposal_cool_off_period_t;

#define PD_CALL_PIPS_SET_DEFAULT_ENACTMENT_PERIOD 3
typedef struct {
  pd_BlockNumber_t duration;
} pd_pips_set_default_enactment_period_t;

#define PD_CALL_PIPS_SET_PENDING_PIP_EXPIRY 4
typedef struct {
  pd_MaybeBlock_t expiry;
} pd_pips_set_pending_pip_expiry_t;

#define PD_CALL_PIPS_SET_MAX_PIP_SKIP_COUNT 5
typedef struct {
  pd_SkippedCount_t new_max;
} pd_pips_set_max_pip_skip_count_t;

#define PD_CALL_PIPS_SET_ACTIVE_PIP_LIMIT 6
typedef struct {
  pd_u32_t new_max;
} pd_pips_set_active_pip_limit_t;

#define PD_CALL_PIPS_AMEND_PROPOSAL 8
typedef struct {
  pd_PipId_t id;
  pd_OptionUrl_t url;
  pd_OptionPipDescription_t description;
} pd_pips_amend_proposal_t;

#define PD_CALL_PIPS_CANCEL_PROPOSAL 9
typedef struct {
  pd_PipId_t id;
} pd_pips_cancel_proposal_t;

#define PD_CALL_PIPS_VOTE 10
typedef struct {
  pd_PipId_t id;
  pd_bool_t aye_or_nay;
  pd_BalanceOf_t deposit;
} pd_pips_vote_t;

#define PD_CALL_PIPS_APPROVE_COMMITTEE_PROPOSAL 11
typedef struct {
  pd_PipId_t id;
} pd_pips_approve_committee_proposal_t;

#define PD_CALL_PIPS_REJECT_PROPOSAL 12
typedef struct {
  pd_PipId_t id;
} pd_pips_reject_proposal_t;

#define PD_CALL_PIPS_PRUNE_PROPOSAL 13
typedef struct {
  pd_PipId_t id;
} pd_pips_prune_proposal_t;

#define PD_CALL_PIPS_RESCHEDULE_EXECUTION 14
typedef struct {
  pd_PipId_t id;
  pd_OptionBlockNumber_t until;
} pd_pips_reschedule_execution_t;

#define PD_CALL_PIPS_CLEAR_SNAPSHOT 15
typedef struct {
} pd_pips_clear_snapshot_t;

#define PD_CALL_PIPS_SNAPSHOT 16
typedef struct {
} pd_pips_snapshot_t;

#define PD_CALL_PIPS_ENACT_SNAPSHOT_RESULTS 17
typedef struct {
  pd_VecTuplePipIdSnapshotResult_t results;
} pd_pips_enact_snapshot_results_t;

#define PD_CALL_PIPS_EXECUTE_SCHEDULED_PIP 18
typedef struct {
  pd_PipId_t id;
} pd_pips_execute_scheduled_pip_t;

#define PD_CALL_PIPS_EXPIRE_SCHEDULED_PIP 19
typedef struct {
  pd_IdentityId_t did;
  pd_PipId_t id;
} pd_pips_expire_scheduled_pip_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_VOTE_THRESHOLD 0
typedef struct {
  pd_u32_t n;
  pd_u32_t d;
} pd_technicalcommittee_set_vote_threshold_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_RELEASE_COORDINATOR 1
typedef struct {
  pd_IdentityId_t id;
} pd_technicalcommittee_set_release_coordinator_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_EXPIRES_AFTER 2
typedef struct {
  pd_MaybeBlock_t expiry;
} pd_technicalcommittee_set_expires_after_t;

#define PD_CALL_TECHNICALCOMMITTEE_CLOSE 3
typedef struct {
  pd_Hash_t proposal;
  pd_CompactProposalIndex_t index;
} pd_technicalcommittee_close_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE 5
typedef struct {
  pd_Hash_t proposal;
  pd_ProposalIndex_t index;
  pd_bool_t approve;
} pd_technicalcommittee_vote_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT 0
typedef struct {
  pd_MemberCount_t limit;
} pd_technicalcommitteemembership_set_active_members_limit_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_DISABLE_MEMBER 1
typedef struct {
  pd_IdentityId_t who;
  pd_OptionMoment_t expiry;
  pd_OptionMoment_t at;
} pd_technicalcommitteemembership_disable_member_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER 2
typedef struct {
  pd_IdentityId_t who;
} pd_technicalcommitteemembership_add_member_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER 3
typedef struct {
  pd_IdentityId_t who;
} pd_technicalcommitteemembership_remove_member_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER 4
typedef struct {
  pd_IdentityId_t remove;
  pd_IdentityId_t add;
} pd_technicalcommitteemembership_swap_member_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS 5
typedef struct {
  pd_VecIdentityId_t members;
} pd_technicalcommitteemembership_reset_members_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP 6
typedef struct {
} pd_technicalcommitteemembership_abdicate_membership_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_VOTE_THRESHOLD 0
typedef struct {
  pd_u32_t n;
  pd_u32_t d;
} pd_upgradecommittee_set_vote_threshold_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_RELEASE_COORDINATOR 1
typedef struct {
  pd_IdentityId_t id;
} pd_upgradecommittee_set_release_coordinator_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_EXPIRES_AFTER 2
typedef struct {
  pd_MaybeBlock_t expiry;
} pd_upgradecommittee_set_expires_after_t;

#define PD_CALL_UPGRADECOMMITTEE_CLOSE 3
typedef struct {
  pd_Hash_t proposal;
  pd_CompactProposalIndex_t index;
} pd_upgradecommittee_close_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE 5
typedef struct {
  pd_Hash_t proposal;
  pd_ProposalIndex_t index;
  pd_bool_t approve;
} pd_upgradecommittee_vote_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT 0
typedef struct {
  pd_MemberCount_t limit;
} pd_upgradecommitteemembership_set_active_members_limit_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_DISABLE_MEMBER 1
typedef struct {
  pd_IdentityId_t who;
  pd_OptionMoment_t expiry;
  pd_OptionMoment_t at;
} pd_upgradecommitteemembership_disable_member_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ADD_MEMBER 2
typedef struct {
  pd_IdentityId_t who;
} pd_upgradecommitteemembership_add_member_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_REMOVE_MEMBER 3
typedef struct {
  pd_IdentityId_t who;
} pd_upgradecommitteemembership_remove_member_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SWAP_MEMBER 4
typedef struct {
  pd_IdentityId_t remove;
  pd_IdentityId_t add;
} pd_upgradecommitteemembership_swap_member_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_RESET_MEMBERS 5
typedef struct {
  pd_VecIdentityId_t members;
} pd_upgradecommitteemembership_reset_members_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP 6
typedef struct {
} pd_upgradecommitteemembership_abdicate_membership_t;

#define PD_CALL_ASSET_REGISTER_TICKER 0
typedef struct {
  pd_Ticker_t ticker;
} pd_asset_register_ticker_t;

#define PD_CALL_ASSET_ACCEPT_TICKER_TRANSFER 1
typedef struct {
  pd_u64_t auth_id;
} pd_asset_accept_ticker_transfer_t;

#define PD_CALL_ASSET_ACCEPT_PRIMARY_ISSUANCE_AGENT_TRANSFER 2
typedef struct {
  pd_u64_t auth_id;
} pd_asset_accept_primary_issuance_agent_transfer_t;

#define PD_CALL_ASSET_ACCEPT_ASSET_OWNERSHIP_TRANSFER 3
typedef struct {
  pd_u64_t auth_id;
} pd_asset_accept_asset_ownership_transfer_t;

#define PD_CALL_ASSET_CREATE_ASSET 4
typedef struct {
  pd_AssetName_t name;
  pd_Ticker_t ticker;
  pd_Balance_t total_supply;
  pd_bool_t divisible;
  pd_AssetType_t asset_type;
  pd_VecAssetIdentifier_t identifiers;
  pd_OptionFundingRoundName_t funding_round;
} pd_asset_create_asset_t;

#define PD_CALL_ASSET_FREEZE 5
typedef struct {
  pd_Ticker_t ticker;
} pd_asset_freeze_t;

#define PD_CALL_ASSET_UNFREEZE 6
typedef struct {
  pd_Ticker_t ticker;
} pd_asset_unfreeze_t;

#define PD_CALL_ASSET_RENAME_ASSET 7
typedef struct {
  pd_Ticker_t ticker;
  pd_AssetName_t name;
} pd_asset_rename_asset_t;

#define PD_CALL_ASSET_ISSUE 8
typedef struct {
  pd_Ticker_t ticker;
  pd_Balance_t value;
} pd_asset_issue_t;

#define PD_CALL_ASSET_REDEEM 9
typedef struct {
  pd_Ticker_t ticker;
  pd_Balance_t value;
} pd_asset_redeem_t;

#define PD_CALL_ASSET_MAKE_DIVISIBLE 10
typedef struct {
  pd_Ticker_t ticker;
} pd_asset_make_divisible_t;

#define PD_CALL_ASSET_ADD_DOCUMENTS 11
typedef struct {
  pd_VecDocument_t docs;
  pd_Ticker_t ticker;
} pd_asset_add_documents_t;

#define PD_CALL_ASSET_REMOVE_DOCUMENTS 12
typedef struct {
  pd_VecDocumentId_t ids;
  pd_Ticker_t ticker;
} pd_asset_remove_documents_t;

#define PD_CALL_ASSET_SET_FUNDING_ROUND 13
typedef struct {
  pd_Ticker_t ticker;
  pd_FundingRoundName_t name;
} pd_asset_set_funding_round_t;

#define PD_CALL_ASSET_UPDATE_IDENTIFIERS 14
typedef struct {
  pd_Ticker_t ticker;
  pd_VecAssetIdentifier_t identifiers;
} pd_asset_update_identifiers_t;

#define PD_CALL_ASSET_ADD_EXTENSION 15
typedef struct {
  pd_Ticker_t ticker;
  pd_SmartExtension_t extension_details;
} pd_asset_add_extension_t;

#define PD_CALL_ASSET_ARCHIVE_EXTENSION 16
typedef struct {
  pd_Ticker_t ticker;
  pd_AccountId_t extension_id;
} pd_asset_archive_extension_t;

#define PD_CALL_ASSET_UNARCHIVE_EXTENSION 17
typedef struct {
  pd_Ticker_t ticker;
  pd_AccountId_t extension_id;
} pd_asset_unarchive_extension_t;

#define PD_CALL_ASSET_REMOVE_PRIMARY_ISSUANCE_AGENT 18
typedef struct {
  pd_Ticker_t ticker;
} pd_asset_remove_primary_issuance_agent_t;

#define PD_CALL_ASSET_REMOVE_SMART_EXTENSION 19
typedef struct {
  pd_Ticker_t ticker;
  pd_AccountId_t extension_id;
} pd_asset_remove_smart_extension_t;

#define PD_CALL_ASSET_CLAIM_CLASSIC_TICKER 20
typedef struct {
  pd_Ticker_t ticker;
  pd_EcdsaSignature_t ethereum_signature;
} pd_asset_claim_classic_ticker_t;

#define PD_CALL_ASSET_RESERVE_CLASSIC_TICKER 21
typedef struct {
  pd_ClassicTickerImport_t classic_ticker_import;
  pd_IdentityId_t contract_did;
  pd_TickerRegistrationConfig_t config;
} pd_asset_reserve_classic_ticker_t;

#define PD_CALL_DIVIDEND_NEW 0
typedef struct {
  pd_Balance_t amount;
  pd_Ticker_t ticker;
  pd_Moment_t matures_at;
  pd_Moment_t expires_at;
  pd_Ticker_t payout_ticker;
  pd_CheckpointId_t checkpoint_id;
} pd_dividend_new_t;

#define PD_CALL_DIVIDEND_CANCEL 1
typedef struct {
  pd_Ticker_t ticker;
  pd_u32_t dividend_id;
} pd_dividend_cancel_t;

#define PD_CALL_DIVIDEND_CLAIM 2
typedef struct {
  pd_Ticker_t ticker;
  pd_u32_t dividend_id;
} pd_dividend_claim_t;

#define PD_CALL_DIVIDEND_CLAIM_UNCLAIMED 3
typedef struct {
  pd_Ticker_t ticker;
  pd_u32_t dividend_id;
} pd_dividend_claim_unclaimed_t;

#define PD_CALL_IDENTITY_REGISTER_DID 0
typedef struct {
  pd_InvestorUid_t uid;
  pd_VecSecondaryKey_t secondary_keys;
} pd_identity_register_did_t;

#define PD_CALL_IDENTITY_CDD_REGISTER_DID 1
typedef struct {
  pd_AccountId_t target_account;
  pd_VecSecondaryKey_t secondary_keys;
} pd_identity_cdd_register_did_t;

#define PD_CALL_IDENTITY_MOCK_CDD_REGISTER_DID 2
typedef struct {
  pd_AccountId_t target_account;
} pd_identity_mock_cdd_register_did_t;

#define PD_CALL_IDENTITY_INVALIDATE_CDD_CLAIMS 3
typedef struct {
  pd_IdentityId_t cdd;
  pd_Moment_t disable_from;
  pd_OptionMoment_t expiry;
} pd_identity_invalidate_cdd_claims_t;

#define PD_CALL_IDENTITY_REMOVE_SECONDARY_KEYS 4
typedef struct {
  pd_VecSignatory_t signers_to_remove;
} pd_identity_remove_secondary_keys_t;

#define PD_CALL_IDENTITY_ACCEPT_PRIMARY_KEY 5
typedef struct {
  pd_u64_t rotation_auth_id;
  pd_Optionu64_t optional_cdd_auth_id;
} pd_identity_accept_primary_key_t;

#define PD_CALL_IDENTITY_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION 6
typedef struct {
  pd_bool_t auth_required;
} pd_identity_change_cdd_requirement_for_mk_rotation_t;

#define PD_CALL_IDENTITY_JOIN_IDENTITY_AS_KEY 7
typedef struct {
  pd_u64_t auth_id;
} pd_identity_join_identity_as_key_t;

#define PD_CALL_IDENTITY_JOIN_IDENTITY_AS_IDENTITY 8
typedef struct {
  pd_u64_t auth_id;
} pd_identity_join_identity_as_identity_t;

#define PD_CALL_IDENTITY_LEAVE_IDENTITY_AS_KEY 9
typedef struct {
} pd_identity_leave_identity_as_key_t;

#define PD_CALL_IDENTITY_LEAVE_IDENTITY_AS_IDENTITY 10
typedef struct {
  pd_IdentityId_t did;
} pd_identity_leave_identity_as_identity_t;

#define PD_CALL_IDENTITY_ADD_CLAIM 11
typedef struct {
  pd_IdentityId_t target;
  pd_Claim_t claim;
  pd_OptionMoment_t expiry;
} pd_identity_add_claim_t;

#define PD_CALL_IDENTITY_REVOKE_CLAIM 13
typedef struct {
  pd_IdentityId_t target;
  pd_Claim_t claim;
} pd_identity_revoke_claim_t;

#define PD_CALL_IDENTITY_SET_PERMISSION_TO_SIGNER 14
typedef struct {
  pd_Signatory_t signer;
  pd_Permissions_t permissions;
} pd_identity_set_permission_to_signer_t;

#define PD_CALL_IDENTITY_LEGACY_SET_PERMISSION_TO_SIGNER 15
typedef struct {
  pd_Signatory_t signer;
  pd_LegacyPermissions_t permissions;
} pd_identity_legacy_set_permission_to_signer_t;

#define PD_CALL_IDENTITY_FREEZE_SECONDARY_KEYS 16
typedef struct {
} pd_identity_freeze_secondary_keys_t;

#define PD_CALL_IDENTITY_UNFREEZE_SECONDARY_KEYS 17
typedef struct {
} pd_identity_unfreeze_secondary_keys_t;

#define PD_CALL_IDENTITY_GET_MY_DID 18
typedef struct {
} pd_identity_get_my_did_t;

#define PD_CALL_IDENTITY_GET_CDD_OF 19
typedef struct {
  pd_AccountId_t of;
} pd_identity_get_cdd_of_t;

#define PD_CALL_IDENTITY_ADD_AUTHORIZATION 20
typedef struct {
  pd_Signatory_t target;
  pd_AuthorizationData_t authorization_data;
  pd_OptionMoment_t expiry;
} pd_identity_add_authorization_t;

#define PD_CALL_IDENTITY_REMOVE_AUTHORIZATION 21
typedef struct {
  pd_Signatory_t target;
  pd_u64_t auth_id;
  pd_bool_t _auth_issuer_pays;
} pd_identity_remove_authorization_t;

#define PD_CALL_IDENTITY_ACCEPT_AUTHORIZATION 22
typedef struct {
  pd_u64_t auth_id;
} pd_identity_accept_authorization_t;

#define PD_CALL_IDENTITY_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION 23
typedef struct {
  pd_VecSecondaryKeyWithAuth_t additional_keys;
  pd_Moment_t expires_at;
} pd_identity_add_secondary_keys_with_authorization_t;

#define PD_CALL_IDENTITY_REVOKE_OFFCHAIN_AUTHORIZATION 24
typedef struct {
  pd_Signatory_t signer;
  pd_TargetIdAuthorization_t auth;
} pd_identity_revoke_offchain_authorization_t;

#define PD_CALL_IDENTITY_ADD_INVESTOR_UNIQUENESS_CLAIM 25
typedef struct {
  pd_IdentityId_t target;
  pd_Claim_t claim;
  pd_InvestorZKProofData_t proof;
  pd_OptionMoment_t expiry;
} pd_identity_add_investor_uniqueness_claim_t;

#define PD_CALL_IDENTITY_GC_ADD_CDD_CLAIM 26
typedef struct {
  pd_IdentityId_t target;
  pd_OptionMoment_t expiry;
} pd_identity_gc_add_cdd_claim_t;

#define PD_CALL_IDENTITY_GC_REVOKE_CDD_CLAIM 27
typedef struct {
  pd_IdentityId_t target;
} pd_identity_gc_revoke_cdd_claim_t;

#define PD_CALL_BRIDGE_CHANGE_CONTROLLER 0
typedef struct {
  pd_AccountId_t controller;
} pd_bridge_change_controller_t;

#define PD_CALL_BRIDGE_CHANGE_ADMIN 1
typedef struct {
  pd_AccountId_t admin;
} pd_bridge_change_admin_t;

#define PD_CALL_BRIDGE_CHANGE_TIMELOCK 2
typedef struct {
  pd_BlockNumber_t timelock;
} pd_bridge_change_timelock_t;

#define PD_CALL_BRIDGE_FREEZE 3
typedef struct {
} pd_bridge_freeze_t;

#define PD_CALL_BRIDGE_UNFREEZE 4
typedef struct {
} pd_bridge_unfreeze_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_LIMIT 5
typedef struct {
  pd_Balance_t amount;
  pd_BlockNumber_t duration;
} pd_bridge_change_bridge_limit_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_EXEMPTED 6
typedef struct {
  pd_VecTupleIdentityIdbool_t exempted;
} pd_bridge_change_bridge_exempted_t;

#define PD_CALL_BRIDGE_FORCE_HANDLE_BRIDGE_TX 7
typedef struct {
  pd_BridgeTx_t bridge_tx;
} pd_bridge_force_handle_bridge_tx_t;

#define PD_CALL_BRIDGE_BATCH_PROPOSE_BRIDGE_TX 8
typedef struct {
  pd_VecBridgeTx_t bridge_txs;
} pd_bridge_batch_propose_bridge_tx_t;

#define PD_CALL_BRIDGE_PROPOSE_BRIDGE_TX 9
typedef struct {
  pd_BridgeTx_t bridge_tx;
} pd_bridge_propose_bridge_tx_t;

#define PD_CALL_BRIDGE_HANDLE_BRIDGE_TX 10
typedef struct {
  pd_BridgeTx_t bridge_tx;
} pd_bridge_handle_bridge_tx_t;

#define PD_CALL_BRIDGE_FREEZE_TXS 11
typedef struct {
  pd_VecBridgeTx_t bridge_txs;
} pd_bridge_freeze_txs_t;

#define PD_CALL_BRIDGE_UNFREEZE_TXS 12
typedef struct {
  pd_VecBridgeTx_t bridge_txs;
} pd_bridge_unfreeze_txs_t;

#define PD_CALL_BRIDGE_HANDLE_SCHEDULED_BRIDGE_TX 13
typedef struct {
  pd_BridgeTx_t bridge_tx;
} pd_bridge_handle_scheduled_bridge_tx_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_COMPLIANCE_REQUIREMENT 0
typedef struct {
  pd_Ticker_t ticker;
  pd_VecCondition_t sender_conditions;
  pd_VecCondition_t receiver_conditions;
} pd_compliancemanager_add_compliance_requirement_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_COMPLIANCE_REQUIREMENT 1
typedef struct {
  pd_Ticker_t ticker;
  pd_u32_t id;
} pd_compliancemanager_remove_compliance_requirement_t;

#define PD_CALL_COMPLIANCEMANAGER_REPLACE_ASSET_COMPLIANCE 2
typedef struct {
  pd_Ticker_t ticker;
  pd_VecComplianceRequirement_t asset_compliance;
} pd_compliancemanager_replace_asset_compliance_t;

#define PD_CALL_COMPLIANCEMANAGER_RESET_ASSET_COMPLIANCE 3
typedef struct {
  pd_Ticker_t ticker;
} pd_compliancemanager_reset_asset_compliance_t;

#define PD_CALL_COMPLIANCEMANAGER_PAUSE_ASSET_COMPLIANCE 4
typedef struct {
  pd_Ticker_t ticker;
} pd_compliancemanager_pause_asset_compliance_t;

#define PD_CALL_COMPLIANCEMANAGER_RESUME_ASSET_COMPLIANCE 5
typedef struct {
  pd_Ticker_t ticker;
} pd_compliancemanager_resume_asset_compliance_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER 6
typedef struct {
  pd_Ticker_t ticker;
  pd_TrustedIssuer_t issuer;
} pd_compliancemanager_add_default_trusted_claim_issuer_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER 7
typedef struct {
  pd_Ticker_t ticker;
  pd_TrustedIssuer_t issuer;
} pd_compliancemanager_remove_default_trusted_claim_issuer_t;

#define PD_CALL_COMPLIANCEMANAGER_CHANGE_COMPLIANCE_REQUIREMENT 8
typedef struct {
  pd_Ticker_t ticker;
  pd_ComplianceRequirement_t new_req;
} pd_compliancemanager_change_compliance_requirement_t;

#define PD_CALL_VOTING_ADD_BALLOT 0
typedef struct {
  pd_Ticker_t ticker;
  pd_Bytes_t ballot_name;
  pd_Ballot_t ballot_details;
} pd_voting_add_ballot_t;

#define PD_CALL_VOTING_VOTE 1
typedef struct {
  pd_Ticker_t ticker;
  pd_Bytes_t ballot_name;
  pd_VecBalance_t votes;
} pd_voting_vote_t;

#define PD_CALL_VOTING_CANCEL_BALLOT 2
typedef struct {
  pd_Ticker_t ticker;
  pd_Bytes_t ballot_name;
} pd_voting_cancel_ballot_t;

#define PD_CALL_STOCAPPED_LAUNCH_STO 0
typedef struct {
  pd_Ticker_t ticker;
  pd_IdentityId_t beneficiary_did;
  pd_Balance_t cap;
  pd_u128_t rate;
  pd_Moment_t start_date;
  pd_Moment_t end_date;
} pd_stocapped_launch_sto_t;

#define PD_CALL_STOCAPPED_BUY_TOKENS 1
typedef struct {
  pd_Ticker_t ticker;
  pd_u32_t sto_id;
  pd_Balance_t value;
} pd_stocapped_buy_tokens_t;

#define PD_CALL_STOCAPPED_PAUSE_STO 2
typedef struct {
  pd_Ticker_t ticker;
  pd_u32_t sto_id;
} pd_stocapped_pause_sto_t;

#define PD_CALL_STOCAPPED_UNPAUSE_STO 3
typedef struct {
  pd_Ticker_t ticker;
  pd_u32_t sto_id;
} pd_stocapped_unpause_sto_t;

#define PD_CALL_EXEMPTION_MODIFY_EXEMPTION_LIST 0
typedef struct {
  pd_Ticker_t ticker;
  pd_u16_t _tm;
  pd_IdentityId_t asset_holder_did;
  pd_bool_t exempted;
} pd_exemption_modify_exemption_list_t;

#define PD_CALL_SETTLEMENT_CREATE_VENUE 0
typedef struct {
  pd_VenueDetails_t details;
  pd_VecAccountId_t signers;
  pd_VenueType_t venue_type;
} pd_settlement_create_venue_t;

#define PD_CALL_SETTLEMENT_UPDATE_VENUE 1
typedef struct {
  pd_u64_t venue_id;
  pd_OptionVenueDetails_t details;
  pd_OptionVenueType_t venue_type;
} pd_settlement_update_venue_t;

#define PD_CALL_SETTLEMENT_ADD_INSTRUCTION 2
typedef struct {
  pd_u64_t venue_id;
  pd_SettlementType_t settlement_type;
  pd_OptionMoment_t valid_from;
  pd_VecLeg_t legs;
} pd_settlement_add_instruction_t;

#define PD_CALL_SETTLEMENT_ADD_AND_AFFIRM_INSTRUCTION 3
typedef struct {
  pd_u64_t venue_id;
  pd_SettlementType_t settlement_type;
  pd_OptionMoment_t valid_from;
  pd_VecLeg_t legs;
  pd_VecPortfolioId_t portfolios;
} pd_settlement_add_and_affirm_instruction_t;

#define PD_CALL_SETTLEMENT_AFFIRM_INSTRUCTION 4
typedef struct {
  pd_u64_t instruction_id;
  pd_VecPortfolioId_t portfolios;
} pd_settlement_affirm_instruction_t;

#define PD_CALL_SETTLEMENT_WITHDRAW_AFFIRMATION 5
typedef struct {
  pd_u64_t instruction_id;
  pd_VecPortfolioId_t portfolios;
} pd_settlement_withdraw_affirmation_t;

#define PD_CALL_SETTLEMENT_REJECT_INSTRUCTION 6
typedef struct {
  pd_u64_t instruction_id;
  pd_VecPortfolioId_t portfolios;
} pd_settlement_reject_instruction_t;

#define PD_CALL_SETTLEMENT_AFFIRM_WITH_RECEIPTS 7
typedef struct {
  pd_u64_t instruction_id;
  pd_VecReceiptDetails_t receipt_details;
  pd_VecPortfolioId_t portfolios;
} pd_settlement_affirm_with_receipts_t;

#define PD_CALL_SETTLEMENT_CLAIM_RECEIPT 8
typedef struct {
  pd_u64_t instruction_id;
  pd_ReceiptDetails_t receipt_details;
} pd_settlement_claim_receipt_t;

#define PD_CALL_SETTLEMENT_UNCLAIM_RECEIPT 9
typedef struct {
  pd_u64_t instruction_id;
  pd_u64_t leg_id;
} pd_settlement_unclaim_receipt_t;

#define PD_CALL_SETTLEMENT_SET_VENUE_FILTERING 10
typedef struct {
  pd_Ticker_t ticker;
  pd_bool_t enabled;
} pd_settlement_set_venue_filtering_t;

#define PD_CALL_SETTLEMENT_ALLOW_VENUES 11
typedef struct {
  pd_Ticker_t ticker;
  pd_Vecu64_t venues;
} pd_settlement_allow_venues_t;

#define PD_CALL_SETTLEMENT_DISALLOW_VENUES 12
typedef struct {
  pd_Ticker_t ticker;
  pd_Vecu64_t venues;
} pd_settlement_disallow_venues_t;

#define PD_CALL_SETTLEMENT_EXECUTE_SCHEDULED_INSTRUCTION 13
typedef struct {
  pd_u64_t instruction_id;
} pd_settlement_execute_scheduled_instruction_t;

#define PD_CALL_STO_CREATE_FUNDRAISER 0
typedef struct {
  pd_PortfolioId_t offering_portfolio;
  pd_Ticker_t offering_asset;
  pd_PortfolioId_t raising_portfolio;
  pd_Ticker_t raising_asset;
  pd_VecPriceTier_t tiers;
  pd_u64_t venue_id;
  pd_OptionMoment_t start;
  pd_OptionMoment_t end;
} pd_sto_create_fundraiser_t;

#define PD_CALL_STO_INVEST 1
typedef struct {
  pd_PortfolioId_t investment_portfolio;
  pd_PortfolioId_t funding_portfolio;
  pd_Ticker_t offering_asset;
  pd_u64_t fundraiser_id;
  pd_Balance_t investment_amount;
  pd_OptionBalance_t max_price;
  pd_OptionReceiptDetails_t receipt;
} pd_sto_invest_t;

#define PD_CALL_STO_FREEZE_FUNDRAISER 2
typedef struct {
  pd_Ticker_t offering_asset;
  pd_u64_t fundraiser_id;
} pd_sto_freeze_fundraiser_t;

#define PD_CALL_STO_UNFREEZE_FUNDRAISER 3
typedef struct {
  pd_Ticker_t offering_asset;
  pd_u64_t fundraiser_id;
} pd_sto_unfreeze_fundraiser_t;

#define PD_CALL_STO_MODIFY_FUNDRAISER_WINDOW 4
typedef struct {
  pd_Ticker_t offering_asset;
  pd_u64_t fundraiser_id;
  pd_Moment_t start;
  pd_OptionMoment_t end;
} pd_sto_modify_fundraiser_window_t;

#define PD_CALL_STO_STOP 5
typedef struct {
  pd_Ticker_t offering_asset;
  pd_u64_t fundraiser_id;
} pd_sto_stop_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SET_ACTIVE_MEMBERS_LIMIT 0
typedef struct {
  pd_MemberCount_t limit;
} pd_cddserviceproviders_set_active_members_limit_t;

#define PD_CALL_CDDSERVICEPROVIDERS_DISABLE_MEMBER 1
typedef struct {
  pd_IdentityId_t who;
  pd_OptionMoment_t expiry;
  pd_OptionMoment_t at;
} pd_cddserviceproviders_disable_member_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ADD_MEMBER 2
typedef struct {
  pd_IdentityId_t who;
} pd_cddserviceproviders_add_member_t;

#define PD_CALL_CDDSERVICEPROVIDERS_REMOVE_MEMBER 3
typedef struct {
  pd_IdentityId_t who;
} pd_cddserviceproviders_remove_member_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SWAP_MEMBER 4
typedef struct {
  pd_IdentityId_t remove;
  pd_IdentityId_t add;
} pd_cddserviceproviders_swap_member_t;

#define PD_CALL_CDDSERVICEPROVIDERS_RESET_MEMBERS 5
typedef struct {
  pd_VecIdentityId_t members;
} pd_cddserviceproviders_reset_members_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ABDICATE_MEMBERSHIP 6
typedef struct {
} pd_cddserviceproviders_abdicate_membership_t;

#define PD_CALL_PROTOCOLFEE_CHANGE_COEFFICIENT 0
typedef struct {
  pd_PosRatio_t coefficient;
} pd_protocolfee_change_coefficient_t;

#define PD_CALL_PROTOCOLFEE_CHANGE_BASE_FEE 1
typedef struct {
  pd_ProtocolOp_t op;
  pd_BalanceOf_t base_fee;
} pd_protocolfee_change_base_fee_t;

#define PD_CALL_UTILITY_BATCH 0
typedef struct {
  pd_VecCall_t calls;
} pd_utility_batch_t;

#define PD_CALL_UTILITY_BATCH_ATOMIC 1
typedef struct {
  pd_VecCall_t calls;
} pd_utility_batch_atomic_t;

#define PD_CALL_UTILITY_BATCH_OPTIMISTIC 2
typedef struct {
  pd_VecCall_t calls;
} pd_utility_batch_optimistic_t;

#define PD_CALL_UTILITY_RELAY_TX 3
typedef struct {
  pd_AccountId_t target;
  pd_OffChainSignature_t signature;
  pd_UniqueCall_t call;
} pd_utility_relay_tx_t;

#define PD_CALL_PORTFOLIO_CREATE_PORTFOLIO 0
typedef struct {
  pd_PortfolioName_t name;
} pd_portfolio_create_portfolio_t;

#define PD_CALL_PORTFOLIO_DELETE_PORTFOLIO 1
typedef struct {
  pd_PortfolioNumber_t num;
} pd_portfolio_delete_portfolio_t;

#define PD_CALL_PORTFOLIO_MOVE_PORTFOLIO_FUNDS 2
typedef struct {
  pd_PortfolioId_t from;
  pd_PortfolioId_t to;
  pd_VecMovePortfolioItem_t items;
} pd_portfolio_move_portfolio_funds_t;

#define PD_CALL_PORTFOLIO_RENAME_PORTFOLIO 3
typedef struct {
  pd_PortfolioNumber_t num;
  pd_PortfolioName_t to_name;
} pd_portfolio_rename_portfolio_t;

#define PD_CALL_CONFIDENTIAL_ADD_RANGE_PROOF 0
typedef struct {
  pd_IdentityId_t target_id;
  pd_Ticker_t ticker;
  pd_u64_t secret_value;
} pd_confidential_add_range_proof_t;

#define PD_CALL_CONFIDENTIAL_ADD_VERIFY_RANGE_PROOF 1
typedef struct {
  pd_IdentityId_t target;
  pd_IdentityId_t prover;
  pd_Ticker_t ticker;
} pd_confidential_add_verify_range_proof_t;

#define PD_CALL_SCHEDULER_SCHEDULE 0
typedef struct {
  pd_BlockNumber_t when;
  pd_OptionPeriod_t maybe_periodic;
  pd_Priority_t priority;
  pd_Call_t call;
} pd_scheduler_schedule_t;

#define PD_CALL_SCHEDULER_CANCEL 1
typedef struct {
  pd_BlockNumber_t when;
  pd_u32_t index;
} pd_scheduler_cancel_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED 2
typedef struct {
  pd_Bytes_t id;
  pd_BlockNumber_t when;
  pd_OptionPeriod_t maybe_periodic;
  pd_Priority_t priority;
  pd_Call_t call;
} pd_scheduler_schedule_named_t;

#define PD_CALL_SCHEDULER_CANCEL_NAMED 3
typedef struct {
  pd_Bytes_t id;
} pd_scheduler_cancel_named_t;

#define PD_CALL_SCHEDULER_SCHEDULE_AFTER 4
typedef struct {
  pd_BlockNumber_t after;
  pd_OptionPeriod_t maybe_periodic;
  pd_Priority_t priority;
  pd_Call_t call;
} pd_scheduler_schedule_after_t;

#define PD_CALL_SCHEDULER_SCHEDULE_NAMED_AFTER 5
typedef struct {
  pd_Bytes_t id;
  pd_BlockNumber_t after;
  pd_OptionPeriod_t maybe_periodic;
  pd_Priority_t priority;
  pd_Call_t call;
} pd_scheduler_schedule_named_after_t;

#define PD_CALL_CORPORATEACTION_SET_MAX_DETAILS_LENGTH 0
typedef struct {
  pd_u32_t length;
} pd_corporateaction_set_max_details_length_t;

#define PD_CALL_CORPORATEACTION_RESET_CAA 1
typedef struct {
  pd_Ticker_t ticker;
} pd_corporateaction_reset_caa_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_TARGETS 2
typedef struct {
  pd_Ticker_t ticker;
  pd_TargetIdentities_t targets;
} pd_corporateaction_set_default_targets_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_WITHHOLDING_TAX 3
typedef struct {
  pd_Ticker_t ticker;
  pd_Tax_t tax;
} pd_corporateaction_set_default_withholding_tax_t;

#define PD_CALL_CORPORATEACTION_SET_DID_WITHHOLDING_TAX 4
typedef struct {
  pd_Ticker_t ticker;
  pd_IdentityId_t taxed_did;
  pd_OptionTax_t tax;
} pd_corporateaction_set_did_withholding_tax_t;

#define PD_CALL_CORPORATEACTION_INITIATE_CORPORATE_ACTION 5
typedef struct {
  pd_Ticker_t ticker;
  pd_CAKind_t kind;
  pd_OptionRecordDateSpec_t record_date;
  pd_CADetails_t details;
  pd_OptionTargetIdentities_t targets;
  pd_OptionTax_t default_withholding_tax;
  pd_OptionVecTupleIdentityIdTax_t withholding_tax;
} pd_corporateaction_initiate_corporate_action_t;

#define PD_CALL_CORPORATEACTION_LINK_CA_DOC 6
typedef struct {
  pd_CAId_t id;
  pd_VecDocumentId_t docs;
} pd_corporateaction_link_ca_doc_t;

#define PD_CALL_CORPORATEACTION_REMOVE_CA 7
typedef struct {
  pd_CAId_t ca_id;
} pd_corporateaction_remove_ca_t;

#define PD_CALL_CORPORATEACTION_CHANGE_RECORD_DATE 8
typedef struct {
  pd_CAId_t ca_id;
  pd_OptionRecordDateSpec_t record_date;
} pd_corporateaction_change_record_date_t;

#define PD_CALL_CORPORATEBALLOT_ATTACH_BALLOT 0
typedef struct {
  pd_CAId_t ca_id;
  pd_BallotTimeRange_t range;
  pd_BallotMeta_t meta;
  pd_bool_t rcv;
} pd_corporateballot_attach_ballot_t;

#define PD_CALL_CORPORATEBALLOT_VOTE 1
typedef struct {
  pd_CAId_t ca_id;
  pd_VecBallotVote_t votes;
} pd_corporateballot_vote_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_END 2
typedef struct {
  pd_CAId_t ca_id;
  pd_Moment_t end;
} pd_corporateballot_change_end_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_META 3
typedef struct {
  pd_CAId_t ca_id;
  pd_BallotMeta_t meta;
} pd_corporateballot_change_meta_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_RCV 4
typedef struct {
  pd_CAId_t ca_id;
  pd_bool_t rcv;
} pd_corporateballot_change_rcv_t;

#define PD_CALL_CORPORATEBALLOT_REMOVE_BALLOT 5
typedef struct {
  pd_CAId_t ca_id;
} pd_corporateballot_remove_ballot_t;

#define PD_CALL_CAPITALDISTRIBUTION_DISTRIBUTE 0
typedef struct {
  pd_CAId_t ca_id;
  pd_OptionPortfolioNumber_t portfolio;
  pd_Ticker_t currency;
  pd_Balance_t amount;
  pd_Moment_t payment_at;
  pd_OptionMoment_t expires_at;
} pd_capitaldistribution_distribute_t;

#define PD_CALL_CAPITALDISTRIBUTION_CLAIM 1
typedef struct {
  pd_CAId_t ca_id;
} pd_capitaldistribution_claim_t;

#define PD_CALL_CAPITALDISTRIBUTION_PUSH_BENEFIT 2
typedef struct {
  pd_CAId_t ca_id;
  pd_IdentityId_t holder;
} pd_capitaldistribution_push_benefit_t;

#define PD_CALL_CAPITALDISTRIBUTION_RECLAIM 3
typedef struct {
  pd_CAId_t ca_id;
} pd_capitaldistribution_reclaim_t;

#define PD_CALL_CAPITALDISTRIBUTION_REMOVE_DISTRIBUTION 4
typedef struct {
  pd_CAId_t ca_id;
} pd_capitaldistribution_remove_distribution_t;

#define PD_CALL_CHECKPOINT_CREATE_CHECKPOINT 0
typedef struct {
  pd_Ticker_t ticker;
} pd_checkpoint_create_checkpoint_t;

#define PD_CALL_CHECKPOINT_SET_SCHEDULES_MAX_COMPLEXITY 1
typedef struct {
  pd_u64_t max_complexity;
} pd_checkpoint_set_schedules_max_complexity_t;

#define PD_CALL_CHECKPOINT_CREATE_SCHEDULE 2
typedef struct {
  pd_Ticker_t ticker;
  pd_ScheduleSpec_t schedule;
} pd_checkpoint_create_schedule_t;

#define PD_CALL_CHECKPOINT_REMOVE_SCHEDULE 3
typedef struct {
  pd_Ticker_t ticker;
  pd_ScheduleId_t id;
} pd_checkpoint_remove_schedule_t;

typedef union {
  pd_system_fill_block_t system_fill_block;
  pd_system_remark_t system_remark;
  pd_system_set_heap_pages_t system_set_heap_pages;
  pd_system_set_code_t system_set_code;
  pd_system_set_code_without_checks_t system_set_code_without_checks;
  pd_system_set_changes_trie_config_t system_set_changes_trie_config;
  pd_system_set_storage_t system_set_storage;
  pd_system_kill_storage_t system_kill_storage;
  pd_system_kill_prefix_t system_kill_prefix;
  pd_system_suicide_t system_suicide;
  pd_babe_report_equivocation_t babe_report_equivocation;
  pd_babe_report_equivocation_unsigned_t babe_report_equivocation_unsigned;
  pd_timestamp_set_t timestamp_set;
  pd_indices_claim_t indices_claim;
  pd_indices_transfer_t indices_transfer;
  pd_indices_free_t indices_free;
  pd_indices_force_transfer_t indices_force_transfer;
  pd_indices_freeze_t indices_freeze;
  pd_balances_transfer_t balances_transfer;
  pd_balances_transfer_with_memo_t balances_transfer_with_memo;
  pd_balances_deposit_block_reward_reserve_balance_t
      balances_deposit_block_reward_reserve_balance;
  pd_balances_set_balance_t balances_set_balance;
  pd_balances_force_transfer_t balances_force_transfer;
  pd_balances_burn_account_balance_t balances_burn_account_balance;
  pd_authorship_set_uncles_t authorship_set_uncles;
  pd_staking_bond_t staking_bond;
  pd_staking_bond_extra_t staking_bond_extra;
  pd_staking_unbond_t staking_unbond;
  pd_staking_withdraw_unbonded_t staking_withdraw_unbonded;
  pd_staking_validate_t staking_validate;
  pd_staking_nominate_t staking_nominate;
  pd_staking_chill_t staking_chill;
  pd_staking_set_payee_t staking_set_payee;
  pd_staking_set_controller_t staking_set_controller;
  pd_staking_set_validator_count_t staking_set_validator_count;
  pd_staking_increase_validator_count_t staking_increase_validator_count;
  pd_staking_scale_validator_count_t staking_scale_validator_count;
  pd_staking_add_permissioned_validator_t staking_add_permissioned_validator;
  pd_staking_remove_permissioned_validator_t
      staking_remove_permissioned_validator;
  pd_staking_validate_cdd_expiry_nominators_t
      staking_validate_cdd_expiry_nominators;
  pd_staking_set_commission_cap_t staking_set_commission_cap;
  pd_staking_set_min_bond_threshold_t staking_set_min_bond_threshold;
  pd_staking_force_no_eras_t staking_force_no_eras;
  pd_staking_force_new_era_t staking_force_new_era;
  pd_staking_set_invulnerables_t staking_set_invulnerables;
  pd_staking_force_unstake_t staking_force_unstake;
  pd_staking_force_new_era_always_t staking_force_new_era_always;
  pd_staking_cancel_deferred_slash_t staking_cancel_deferred_slash;
  pd_staking_payout_stakers_t staking_payout_stakers;
  pd_staking_rebond_t staking_rebond;
  pd_staking_set_history_depth_t staking_set_history_depth;
  pd_staking_reap_stash_t staking_reap_stash;
  pd_staking_submit_election_solution_t staking_submit_election_solution;
  pd_staking_submit_election_solution_unsigned_t
      staking_submit_election_solution_unsigned;
  pd_staking_payout_stakers_by_system_t staking_payout_stakers_by_system;
  pd_staking_change_slashing_allowed_for_t staking_change_slashing_allowed_for;
  pd_session_set_keys_t session_set_keys;
  pd_session_purge_keys_t session_purge_keys;
  pd_finalitytracker_final_hint_t finalitytracker_final_hint;
  pd_grandpa_report_equivocation_t grandpa_report_equivocation;
  pd_grandpa_report_equivocation_unsigned_t
      grandpa_report_equivocation_unsigned;
  pd_grandpa_note_stalled_t grandpa_note_stalled;
  pd_imonline_heartbeat_t imonline_heartbeat;
  pd_imonline_set_slashing_params_t imonline_set_slashing_params;
  pd_sudo_sudo_t sudo_sudo;
  pd_sudo_sudo_unchecked_weight_t sudo_sudo_unchecked_weight;
  pd_sudo_set_key_t sudo_set_key;
  pd_sudo_sudo_as_t sudo_sudo_as;
  pd_multisig_create_multisig_t multisig_create_multisig;
  pd_multisig_approve_as_identity_t multisig_approve_as_identity;
  pd_multisig_approve_as_key_t multisig_approve_as_key;
  pd_multisig_reject_as_identity_t multisig_reject_as_identity;
  pd_multisig_reject_as_key_t multisig_reject_as_key;
  pd_multisig_accept_multisig_signer_as_identity_t
      multisig_accept_multisig_signer_as_identity;
  pd_multisig_accept_multisig_signer_as_key_t
      multisig_accept_multisig_signer_as_key;
  pd_multisig_add_multisig_signer_t multisig_add_multisig_signer;
  pd_multisig_remove_multisig_signer_t multisig_remove_multisig_signer;
  pd_multisig_add_multisig_signers_via_creator_t
      multisig_add_multisig_signers_via_creator;
  pd_multisig_remove_multisig_signers_via_creator_t
      multisig_remove_multisig_signers_via_creator;
  pd_multisig_change_sigs_required_t multisig_change_sigs_required;
  pd_multisig_change_all_signers_and_sigs_required_t
      multisig_change_all_signers_and_sigs_required;
  pd_multisig_make_multisig_signer_t multisig_make_multisig_signer;
  pd_multisig_make_multisig_primary_t multisig_make_multisig_primary;
  pd_contracts_update_schedule_t contracts_update_schedule;
  pd_contracts_put_code_t contracts_put_code;
  pd_contracts_call_t contracts_call;
  pd_contracts_instantiate_t contracts_instantiate;
  pd_contracts_freeze_instantiation_t contracts_freeze_instantiation;
  pd_contracts_unfreeze_instantiation_t contracts_unfreeze_instantiation;
  pd_contracts_transfer_template_ownership_t
      contracts_transfer_template_ownership;
  pd_contracts_change_template_fees_t contracts_change_template_fees;
  pd_contracts_change_template_meta_url_t contracts_change_template_meta_url;
  pd_treasury_disbursement_t treasury_disbursement;
  pd_treasury_reimbursement_t treasury_reimbursement;
  pd_polymeshcommittee_set_vote_threshold_t
      polymeshcommittee_set_vote_threshold;
  pd_polymeshcommittee_set_release_coordinator_t
      polymeshcommittee_set_release_coordinator;
  pd_polymeshcommittee_set_expires_after_t polymeshcommittee_set_expires_after;
  pd_polymeshcommittee_close_t polymeshcommittee_close;
  pd_polymeshcommittee_vote_t polymeshcommittee_vote;
  pd_committeemembership_set_active_members_limit_t
      committeemembership_set_active_members_limit;
  pd_committeemembership_disable_member_t committeemembership_disable_member;
  pd_committeemembership_add_member_t committeemembership_add_member;
  pd_committeemembership_remove_member_t committeemembership_remove_member;
  pd_committeemembership_swap_member_t committeemembership_swap_member;
  pd_committeemembership_reset_members_t committeemembership_reset_members;
  pd_committeemembership_abdicate_membership_t
      committeemembership_abdicate_membership;
  pd_pips_set_prune_historical_pips_t pips_set_prune_historical_pips;
  pd_pips_set_min_proposal_deposit_t pips_set_min_proposal_deposit;
  pd_pips_set_proposal_cool_off_period_t pips_set_proposal_cool_off_period;
  pd_pips_set_default_enactment_period_t pips_set_default_enactment_period;
  pd_pips_set_pending_pip_expiry_t pips_set_pending_pip_expiry;
  pd_pips_set_max_pip_skip_count_t pips_set_max_pip_skip_count;
  pd_pips_set_active_pip_limit_t pips_set_active_pip_limit;
  pd_pips_amend_proposal_t pips_amend_proposal;
  pd_pips_cancel_proposal_t pips_cancel_proposal;
  pd_pips_vote_t pips_vote;
  pd_pips_approve_committee_proposal_t pips_approve_committee_proposal;
  pd_pips_reject_proposal_t pips_reject_proposal;
  pd_pips_prune_proposal_t pips_prune_proposal;
  pd_pips_reschedule_execution_t pips_reschedule_execution;
  pd_pips_clear_snapshot_t pips_clear_snapshot;
  pd_pips_snapshot_t pips_snapshot;
  pd_pips_enact_snapshot_results_t pips_enact_snapshot_results;
  pd_pips_execute_scheduled_pip_t pips_execute_scheduled_pip;
  pd_pips_expire_scheduled_pip_t pips_expire_scheduled_pip;
  pd_technicalcommittee_set_vote_threshold_t
      technicalcommittee_set_vote_threshold;
  pd_technicalcommittee_set_release_coordinator_t
      technicalcommittee_set_release_coordinator;
  pd_technicalcommittee_set_expires_after_t
      technicalcommittee_set_expires_after;
  pd_technicalcommittee_close_t technicalcommittee_close;
  pd_technicalcommittee_vote_t technicalcommittee_vote;
  pd_technicalcommitteemembership_set_active_members_limit_t
      technicalcommitteemembership_set_active_members_limit;
  pd_technicalcommitteemembership_disable_member_t
      technicalcommitteemembership_disable_member;
  pd_technicalcommitteemembership_add_member_t
      technicalcommitteemembership_add_member;
  pd_technicalcommitteemembership_remove_member_t
      technicalcommitteemembership_remove_member;
  pd_technicalcommitteemembership_swap_member_t
      technicalcommitteemembership_swap_member;
  pd_technicalcommitteemembership_reset_members_t
      technicalcommitteemembership_reset_members;
  pd_technicalcommitteemembership_abdicate_membership_t
      technicalcommitteemembership_abdicate_membership;
  pd_upgradecommittee_set_vote_threshold_t upgradecommittee_set_vote_threshold;
  pd_upgradecommittee_set_release_coordinator_t
      upgradecommittee_set_release_coordinator;
  pd_upgradecommittee_set_expires_after_t upgradecommittee_set_expires_after;
  pd_upgradecommittee_close_t upgradecommittee_close;
  pd_upgradecommittee_vote_t upgradecommittee_vote;
  pd_upgradecommitteemembership_set_active_members_limit_t
      upgradecommitteemembership_set_active_members_limit;
  pd_upgradecommitteemembership_disable_member_t
      upgradecommitteemembership_disable_member;
  pd_upgradecommitteemembership_add_member_t
      upgradecommitteemembership_add_member;
  pd_upgradecommitteemembership_remove_member_t
      upgradecommitteemembership_remove_member;
  pd_upgradecommitteemembership_swap_member_t
      upgradecommitteemembership_swap_member;
  pd_upgradecommitteemembership_reset_members_t
      upgradecommitteemembership_reset_members;
  pd_upgradecommitteemembership_abdicate_membership_t
      upgradecommitteemembership_abdicate_membership;
  pd_asset_register_ticker_t asset_register_ticker;
  pd_asset_accept_ticker_transfer_t asset_accept_ticker_transfer;
  pd_asset_accept_primary_issuance_agent_transfer_t
      asset_accept_primary_issuance_agent_transfer;
  pd_asset_accept_asset_ownership_transfer_t
      asset_accept_asset_ownership_transfer;
  pd_asset_create_asset_t asset_create_asset;
  pd_asset_freeze_t asset_freeze;
  pd_asset_unfreeze_t asset_unfreeze;
  pd_asset_rename_asset_t asset_rename_asset;
  pd_asset_issue_t asset_issue;
  pd_asset_redeem_t asset_redeem;
  pd_asset_make_divisible_t asset_make_divisible;
  pd_asset_add_documents_t asset_add_documents;
  pd_asset_remove_documents_t asset_remove_documents;
  pd_asset_set_funding_round_t asset_set_funding_round;
  pd_asset_update_identifiers_t asset_update_identifiers;
  pd_asset_add_extension_t asset_add_extension;
  pd_asset_archive_extension_t asset_archive_extension;
  pd_asset_unarchive_extension_t asset_unarchive_extension;
  pd_asset_remove_primary_issuance_agent_t asset_remove_primary_issuance_agent;
  pd_asset_remove_smart_extension_t asset_remove_smart_extension;
  pd_asset_claim_classic_ticker_t asset_claim_classic_ticker;
  pd_asset_reserve_classic_ticker_t asset_reserve_classic_ticker;
  pd_dividend_new_t dividend_new;
  pd_dividend_cancel_t dividend_cancel;
  pd_dividend_claim_t dividend_claim;
  pd_dividend_claim_unclaimed_t dividend_claim_unclaimed;
  pd_identity_register_did_t identity_register_did;
  pd_identity_cdd_register_did_t identity_cdd_register_did;
  pd_identity_mock_cdd_register_did_t identity_mock_cdd_register_did;
  pd_identity_invalidate_cdd_claims_t identity_invalidate_cdd_claims;
  pd_identity_remove_secondary_keys_t identity_remove_secondary_keys;
  pd_identity_accept_primary_key_t identity_accept_primary_key;
  pd_identity_change_cdd_requirement_for_mk_rotation_t
      identity_change_cdd_requirement_for_mk_rotation;
  pd_identity_join_identity_as_key_t identity_join_identity_as_key;
  pd_identity_join_identity_as_identity_t identity_join_identity_as_identity;
  pd_identity_leave_identity_as_key_t identity_leave_identity_as_key;
  pd_identity_leave_identity_as_identity_t identity_leave_identity_as_identity;
  pd_identity_add_claim_t identity_add_claim;
  pd_identity_revoke_claim_t identity_revoke_claim;
  pd_identity_set_permission_to_signer_t identity_set_permission_to_signer;
  pd_identity_legacy_set_permission_to_signer_t
      identity_legacy_set_permission_to_signer;
  pd_identity_freeze_secondary_keys_t identity_freeze_secondary_keys;
  pd_identity_unfreeze_secondary_keys_t identity_unfreeze_secondary_keys;
  pd_identity_get_my_did_t identity_get_my_did;
  pd_identity_get_cdd_of_t identity_get_cdd_of;
  pd_identity_add_authorization_t identity_add_authorization;
  pd_identity_remove_authorization_t identity_remove_authorization;
  pd_identity_accept_authorization_t identity_accept_authorization;
  pd_identity_add_secondary_keys_with_authorization_t
      identity_add_secondary_keys_with_authorization;
  pd_identity_revoke_offchain_authorization_t
      identity_revoke_offchain_authorization;
  pd_identity_add_investor_uniqueness_claim_t
      identity_add_investor_uniqueness_claim;
  pd_identity_gc_add_cdd_claim_t identity_gc_add_cdd_claim;
  pd_identity_gc_revoke_cdd_claim_t identity_gc_revoke_cdd_claim;
  pd_bridge_change_controller_t bridge_change_controller;
  pd_bridge_change_admin_t bridge_change_admin;
  pd_bridge_change_timelock_t bridge_change_timelock;
  pd_bridge_freeze_t bridge_freeze;
  pd_bridge_unfreeze_t bridge_unfreeze;
  pd_bridge_change_bridge_limit_t bridge_change_bridge_limit;
  pd_bridge_change_bridge_exempted_t bridge_change_bridge_exempted;
  pd_bridge_force_handle_bridge_tx_t bridge_force_handle_bridge_tx;
  pd_bridge_batch_propose_bridge_tx_t bridge_batch_propose_bridge_tx;
  pd_bridge_propose_bridge_tx_t bridge_propose_bridge_tx;
  pd_bridge_handle_bridge_tx_t bridge_handle_bridge_tx;
  pd_bridge_freeze_txs_t bridge_freeze_txs;
  pd_bridge_unfreeze_txs_t bridge_unfreeze_txs;
  pd_bridge_handle_scheduled_bridge_tx_t bridge_handle_scheduled_bridge_tx;
  pd_compliancemanager_add_compliance_requirement_t
      compliancemanager_add_compliance_requirement;
  pd_compliancemanager_remove_compliance_requirement_t
      compliancemanager_remove_compliance_requirement;
  pd_compliancemanager_replace_asset_compliance_t
      compliancemanager_replace_asset_compliance;
  pd_compliancemanager_reset_asset_compliance_t
      compliancemanager_reset_asset_compliance;
  pd_compliancemanager_pause_asset_compliance_t
      compliancemanager_pause_asset_compliance;
  pd_compliancemanager_resume_asset_compliance_t
      compliancemanager_resume_asset_compliance;
  pd_compliancemanager_add_default_trusted_claim_issuer_t
      compliancemanager_add_default_trusted_claim_issuer;
  pd_compliancemanager_remove_default_trusted_claim_issuer_t
      compliancemanager_remove_default_trusted_claim_issuer;
  pd_compliancemanager_change_compliance_requirement_t
      compliancemanager_change_compliance_requirement;
  pd_voting_add_ballot_t voting_add_ballot;
  pd_voting_vote_t voting_vote;
  pd_voting_cancel_ballot_t voting_cancel_ballot;
  pd_stocapped_launch_sto_t stocapped_launch_sto;
  pd_stocapped_buy_tokens_t stocapped_buy_tokens;
  pd_stocapped_pause_sto_t stocapped_pause_sto;
  pd_stocapped_unpause_sto_t stocapped_unpause_sto;
  pd_exemption_modify_exemption_list_t exemption_modify_exemption_list;
  pd_settlement_create_venue_t settlement_create_venue;
  pd_settlement_update_venue_t settlement_update_venue;
  pd_settlement_add_instruction_t settlement_add_instruction;
  pd_settlement_add_and_affirm_instruction_t
      settlement_add_and_affirm_instruction;
  pd_settlement_affirm_instruction_t settlement_affirm_instruction;
  pd_settlement_withdraw_affirmation_t settlement_withdraw_affirmation;
  pd_settlement_reject_instruction_t settlement_reject_instruction;
  pd_settlement_affirm_with_receipts_t settlement_affirm_with_receipts;
  pd_settlement_claim_receipt_t settlement_claim_receipt;
  pd_settlement_unclaim_receipt_t settlement_unclaim_receipt;
  pd_settlement_set_venue_filtering_t settlement_set_venue_filtering;
  pd_settlement_allow_venues_t settlement_allow_venues;
  pd_settlement_disallow_venues_t settlement_disallow_venues;
  pd_settlement_execute_scheduled_instruction_t
      settlement_execute_scheduled_instruction;
  pd_sto_create_fundraiser_t sto_create_fundraiser;
  pd_sto_invest_t sto_invest;
  pd_sto_freeze_fundraiser_t sto_freeze_fundraiser;
  pd_sto_unfreeze_fundraiser_t sto_unfreeze_fundraiser;
  pd_sto_modify_fundraiser_window_t sto_modify_fundraiser_window;
  pd_sto_stop_t sto_stop;
  pd_cddserviceproviders_set_active_members_limit_t
      cddserviceproviders_set_active_members_limit;
  pd_cddserviceproviders_disable_member_t cddserviceproviders_disable_member;
  pd_cddserviceproviders_add_member_t cddserviceproviders_add_member;
  pd_cddserviceproviders_remove_member_t cddserviceproviders_remove_member;
  pd_cddserviceproviders_swap_member_t cddserviceproviders_swap_member;
  pd_cddserviceproviders_reset_members_t cddserviceproviders_reset_members;
  pd_cddserviceproviders_abdicate_membership_t
      cddserviceproviders_abdicate_membership;
  pd_protocolfee_change_coefficient_t protocolfee_change_coefficient;
  pd_protocolfee_change_base_fee_t protocolfee_change_base_fee;
  pd_utility_batch_t utility_batch;
  pd_utility_batch_atomic_t utility_batch_atomic;
  pd_utility_batch_optimistic_t utility_batch_optimistic;
  pd_utility_relay_tx_t utility_relay_tx;
  pd_portfolio_create_portfolio_t portfolio_create_portfolio;
  pd_portfolio_delete_portfolio_t portfolio_delete_portfolio;
  pd_portfolio_move_portfolio_funds_t portfolio_move_portfolio_funds;
  pd_portfolio_rename_portfolio_t portfolio_rename_portfolio;
  pd_confidential_add_range_proof_t confidential_add_range_proof;
  pd_confidential_add_verify_range_proof_t confidential_add_verify_range_proof;
  pd_scheduler_schedule_t scheduler_schedule;
  pd_scheduler_cancel_t scheduler_cancel;
  pd_scheduler_schedule_named_t scheduler_schedule_named;
  pd_scheduler_cancel_named_t scheduler_cancel_named;
  pd_scheduler_schedule_after_t scheduler_schedule_after;
  pd_scheduler_schedule_named_after_t scheduler_schedule_named_after;
  pd_corporateaction_set_max_details_length_t
      corporateaction_set_max_details_length;
  pd_corporateaction_reset_caa_t corporateaction_reset_caa;
  pd_corporateaction_set_default_targets_t corporateaction_set_default_targets;
  pd_corporateaction_set_default_withholding_tax_t
      corporateaction_set_default_withholding_tax;
  pd_corporateaction_set_did_withholding_tax_t
      corporateaction_set_did_withholding_tax;
  pd_corporateaction_initiate_corporate_action_t
      corporateaction_initiate_corporate_action;
  pd_corporateaction_link_ca_doc_t corporateaction_link_ca_doc;
  pd_corporateaction_remove_ca_t corporateaction_remove_ca;
  pd_corporateaction_change_record_date_t corporateaction_change_record_date;
  pd_corporateballot_attach_ballot_t corporateballot_attach_ballot;
  pd_corporateballot_vote_t corporateballot_vote;
  pd_corporateballot_change_end_t corporateballot_change_end;
  pd_corporateballot_change_meta_t corporateballot_change_meta;
  pd_corporateballot_change_rcv_t corporateballot_change_rcv;
  pd_corporateballot_remove_ballot_t corporateballot_remove_ballot;
  pd_capitaldistribution_distribute_t capitaldistribution_distribute;
  pd_capitaldistribution_claim_t capitaldistribution_claim;
  pd_capitaldistribution_push_benefit_t capitaldistribution_push_benefit;
  pd_capitaldistribution_reclaim_t capitaldistribution_reclaim;
  pd_capitaldistribution_remove_distribution_t
      capitaldistribution_remove_distribution;
  pd_checkpoint_create_checkpoint_t checkpoint_create_checkpoint;
  pd_checkpoint_set_schedules_max_complexity_t
      checkpoint_set_schedules_max_complexity;
  pd_checkpoint_create_schedule_t checkpoint_create_schedule;
  pd_checkpoint_remove_schedule_t checkpoint_remove_schedule;
} pd_MethodBasic_t;

typedef struct {
  pd_CallIndex_t callIndex;
  pd_MethodBasic_t method;
  // Track proposal buffer
  const uint8_t *_ptr;
  uint16_t _len;
} pd_Proposal_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY 1
typedef struct {
  pd_AccountId_t multisig;
  pd_Proposal_t proposal;
  pd_OptionMoment_t expiry;
  pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_identity_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_KEY 2
typedef struct {
  pd_AccountId_t multisig;
  pd_Proposal_t proposal;
  pd_OptionMoment_t expiry;
  pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_key_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_IDENTITY 3
typedef struct {
  pd_AccountId_t multisig;
  pd_Proposal_t proposal;
  pd_OptionMoment_t expiry;
  pd_bool_t auto_close;
} pd_multisig_create_proposal_as_identity_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_KEY 4
typedef struct {
  pd_AccountId_t multisig;
  pd_Proposal_t proposal;
  pd_OptionMoment_t expiry;
  pd_bool_t auto_close;
} pd_multisig_create_proposal_as_key_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_OR_PROPOSE 4
typedef struct {
  pd_bool_t approve;
  pd_Proposal_t call;
} pd_polymeshcommittee_vote_or_propose_t;

#define PD_CALL_PIPS_PROPOSE 7
typedef struct {
  pd_Proposal_t proposal;
  pd_BalanceOf_t deposit;
  pd_OptionUrl_t url;
  pd_OptionPipDescription_t description;
} pd_pips_propose_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_OR_PROPOSE 4
typedef struct {
  pd_bool_t approve;
  pd_Proposal_t call;
} pd_technicalcommittee_vote_or_propose_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_OR_PROPOSE 4
typedef struct {
  pd_bool_t approve;
  pd_Proposal_t call;
} pd_upgradecommittee_vote_or_propose_t;

#define PD_CALL_IDENTITY_FORWARDED_CALL 12
typedef struct {
  pd_IdentityId_t target_did;
  pd_Proposal_t proposal;
} pd_identity_forwarded_call_t;

typedef union {
  pd_multisig_create_or_approve_proposal_as_identity_t
      multisig_create_or_approve_proposal_as_identity;
  pd_multisig_create_or_approve_proposal_as_key_t
      multisig_create_or_approve_proposal_as_key;
  pd_multisig_create_proposal_as_identity_t
      multisig_create_proposal_as_identity;
  pd_multisig_create_proposal_as_key_t multisig_create_proposal_as_key;
  pd_polymeshcommittee_vote_or_propose_t polymeshcommittee_vote_or_propose;
  pd_pips_propose_t pips_propose;
  pd_technicalcommittee_vote_or_propose_t technicalcommittee_vote_or_propose;
  pd_upgradecommittee_vote_or_propose_t upgradecommittee_vote_or_propose;
  pd_identity_forwarded_call_t identity_forwarded_call;
} pd_MethodNested_t;

typedef union {
  pd_MethodBasic_t basic;
  pd_MethodNested_t nested;
} pd_Method_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
