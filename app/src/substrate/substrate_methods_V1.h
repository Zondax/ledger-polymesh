/*******************************************************************************
 *  (c) 2019 - 2022 Zondax GmbH
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

#include "substrate_types.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V1 0
#define PD_CALL_TIMESTAMP_V1 2
#define PD_CALL_INDICES_V1 3
#define PD_CALL_BALANCES_V1 5
#define PD_CALL_IDENTITY_V1 7
#define PD_CALL_CDDSERVICEPROVIDERS_V1 8
#define PD_CALL_POLYMESHCOMMITTEE_V1 9
#define PD_CALL_COMMITTEEMEMBERSHIP_V1 10
#define PD_CALL_TECHNICALCOMMITTEE_V1 11
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_V1 12
#define PD_CALL_UPGRADECOMMITTEE_V1 13
#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_V1 14
#define PD_CALL_MULTISIG_V1 15
#define PD_CALL_BRIDGE_V1 16
#define PD_CALL_STAKING_V1 17
#define PD_CALL_SESSION_V1 19
#define PD_CALL_GRANDPA_V1 21
#define PD_CALL_SUDO_V1 25
#define PD_CALL_ASSET_V1 26
#define PD_CALL_CAPITALDISTRIBUTION_V1 27
#define PD_CALL_CHECKPOINT_V1 28
#define PD_CALL_COMPLIANCEMANAGER_V1 29
#define PD_CALL_CORPORATEACTION_V1 30
#define PD_CALL_CORPORATEBALLOT_V1 31
#define PD_CALL_PIPS_V1 33
#define PD_CALL_PORTFOLIO_V1 34
#define PD_CALL_PROTOCOLFEE_V1 35
#define PD_CALL_SETTLEMENT_V1 37
#define PD_CALL_STATISTICS_V1 38
#define PD_CALL_TREASURY_V1 40
#define PD_CALL_UTILITY_V1 41
#define PD_CALL_EXTERNALAGENTS_V1 43
#define PD_CALL_RELAYER_V1 44
#define PD_CALL_REWARDS_V1 45

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_IDENTITY_REVOKE_CLAIM_BY_INDEX_V1 20
typedef struct {
    pd_IdentityId_V1_t target;
    pd_ClaimType_V1_t claim_type;
    pd_OptionScope_V1_t scope;
} pd_identity_revoke_claim_by_index_V1_t;

#define PD_CALL_BRIDGE_FORCE_HANDLE_BRIDGE_TX_V1 7
typedef struct {
    pd_BridgeTx_V1_t bridge_tx;
} pd_bridge_force_handle_bridge_tx_V1_t;

#define PD_CALL_BRIDGE_BATCH_PROPOSE_BRIDGE_TX_V1 8
typedef struct {
    pd_VecBridgeTx_V1_t bridge_txs;
} pd_bridge_batch_propose_bridge_tx_V1_t;

#define PD_CALL_BRIDGE_PROPOSE_BRIDGE_TX_V1 9
typedef struct {
    pd_BridgeTx_V1_t bridge_tx;
} pd_bridge_propose_bridge_tx_V1_t;

#define PD_CALL_BRIDGE_HANDLE_BRIDGE_TX_V1 10
typedef struct {
    pd_BridgeTx_V1_t bridge_tx;
} pd_bridge_handle_bridge_tx_V1_t;

#define PD_CALL_BRIDGE_FREEZE_TXS_V1 11
typedef struct {
    pd_VecBridgeTx_V1_t bridge_txs;
} pd_bridge_freeze_txs_V1_t;

#define PD_CALL_BRIDGE_UNFREEZE_TXS_V1 12
typedef struct {
    pd_VecBridgeTx_V1_t bridge_txs;
} pd_bridge_unfreeze_txs_V1_t;

#define PD_CALL_BRIDGE_HANDLE_SCHEDULED_BRIDGE_TX_V1 13
typedef struct {
    pd_BridgeTx_V1_t bridge_tx;
} pd_bridge_handle_scheduled_bridge_tx_V1_t;

#define PD_CALL_BRIDGE_ADD_FREEZE_ADMIN_V1 14
typedef struct {
    pd_AccountId_V1_t freeze_admin;
} pd_bridge_add_freeze_admin_V1_t;

#define PD_CALL_BRIDGE_REMOVE_FREEZE_ADMIN_V1 15
typedef struct {
    pd_AccountId_V1_t freeze_admin;
} pd_bridge_remove_freeze_admin_V1_t;

#define PD_CALL_ASSET_CONTROLLER_TRANSFER_V1 16
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_BalanceNoSymbol_t amount;
    pd_PortfolioId_V1_t from_portfolio;
} pd_asset_controller_transfer_V1_t;

#define PD_CALL_ASSET_REGISTER_CUSTOM_ASSET_TYPE_V1 17
typedef struct {
    pd_Bytes_t ty;
} pd_asset_register_custom_asset_type_V1_t;

#define PD_CALL_PORTFOLIO_QUIT_PORTFOLIO_CUSTODY_V1 4
typedef struct {
    pd_PortfolioId_V1_t pid;
} pd_portfolio_quit_portfolio_custody_V1_t;

#define PD_CALL_PORTFOLIO_ACCEPT_PORTFOLIO_CUSTODY_V1 5
typedef struct {
    pd_u64_t auth_id;
} pd_portfolio_accept_portfolio_custody_V1_t;

#define PD_CALL_SETTLEMENT_CHANGE_RECEIPT_VALIDITY_V1 14
typedef struct {
    pd_u64_t receipt_uid;
    pd_bool_t validity;
} pd_settlement_change_receipt_validity_V1_t;

#define PD_CALL_EXTERNALAGENTS_REMOVE_AGENT_V1 2
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_IdentityId_V1_t agent;
} pd_externalagents_remove_agent_V1_t;

#define PD_CALL_EXTERNALAGENTS_ABDICATE_V1 3
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_externalagents_abdicate_V1_t;

#define PD_CALL_EXTERNALAGENTS_ACCEPT_BECOME_AGENT_V1 5
typedef struct {
    pd_u64_t auth_id;
} pd_externalagents_accept_become_agent_V1_t;

#define PD_CALL_RELAYER_SET_PAYING_KEY_V1 0
typedef struct {
    pd_AccountId_V1_t user_key;
    pd_Balance_t polyx_limit;
} pd_relayer_set_paying_key_V1_t;

#define PD_CALL_RELAYER_ACCEPT_PAYING_KEY_V1 1
typedef struct {
    pd_u64_t auth_id;
} pd_relayer_accept_paying_key_V1_t;

#define PD_CALL_RELAYER_REMOVE_PAYING_KEY_V1 2
typedef struct {
    pd_AccountId_V1_t user_key;
    pd_AccountId_V1_t paying_key;
} pd_relayer_remove_paying_key_V1_t;

#define PD_CALL_RELAYER_UPDATE_POLYX_LIMIT_V1 3
typedef struct {
    pd_AccountId_V1_t user_key;
    pd_Balance_t polyx_limit;
} pd_relayer_update_polyx_limit_V1_t;

#define PD_CALL_RELAYER_INCREASE_POLYX_LIMIT_V1 4
typedef struct {
    pd_AccountId_V1_t user_key;
    pd_Balance_t amount;
} pd_relayer_increase_polyx_limit_V1_t;

#define PD_CALL_RELAYER_DECREASE_POLYX_LIMIT_V1 5
typedef struct {
    pd_AccountId_V1_t user_key;
    pd_Balance_t amount;
} pd_relayer_decrease_polyx_limit_V1_t;

#define PD_CALL_REWARDS_CLAIM_ITN_REWARD_V1 0
typedef struct {
    pd_AccountId_V1_t reward_address;
    pd_AccountId_V1_t itn_address;
    pd_OffChainSignature_V1_t signature;
} pd_rewards_claim_itn_reward_V1_t;

#endif

typedef union {
#ifdef SUBSTRATE_PARSER_FULL
    pd_identity_revoke_claim_by_index_V1_t identity_revoke_claim_by_index_V1;
    pd_bridge_force_handle_bridge_tx_V1_t bridge_force_handle_bridge_tx_V1;
    pd_bridge_batch_propose_bridge_tx_V1_t bridge_batch_propose_bridge_tx_V1;
    pd_bridge_propose_bridge_tx_V1_t bridge_propose_bridge_tx_V1;
    pd_bridge_handle_bridge_tx_V1_t bridge_handle_bridge_tx_V1;
    pd_bridge_freeze_txs_V1_t bridge_freeze_txs_V1;
    pd_bridge_unfreeze_txs_V1_t bridge_unfreeze_txs_V1;
    pd_bridge_handle_scheduled_bridge_tx_V1_t bridge_handle_scheduled_bridge_tx_V1;
    pd_bridge_add_freeze_admin_V1_t bridge_add_freeze_admin_V1;
    pd_bridge_remove_freeze_admin_V1_t bridge_remove_freeze_admin_V1;
    pd_asset_controller_transfer_V1_t asset_controller_transfer_V1;
    pd_asset_register_custom_asset_type_V1_t asset_register_custom_asset_type_V1;
    pd_portfolio_quit_portfolio_custody_V1_t portfolio_quit_portfolio_custody_V1;
    pd_portfolio_accept_portfolio_custody_V1_t portfolio_accept_portfolio_custody_V1;
    pd_settlement_change_receipt_validity_V1_t settlement_change_receipt_validity_V1;
    pd_externalagents_remove_agent_V1_t externalagents_remove_agent_V1;
    pd_externalagents_abdicate_V1_t externalagents_abdicate_V1;
    pd_externalagents_accept_become_agent_V1_t externalagents_accept_become_agent_V1;
    pd_relayer_set_paying_key_V1_t relayer_set_paying_key_V1;
    pd_relayer_accept_paying_key_V1_t relayer_accept_paying_key_V1;
    pd_relayer_remove_paying_key_V1_t relayer_remove_paying_key_V1;
    pd_relayer_update_polyx_limit_V1_t relayer_update_polyx_limit_V1;
    pd_relayer_increase_polyx_limit_V1_t relayer_increase_polyx_limit_V1;
    pd_relayer_decrease_polyx_limit_V1_t relayer_decrease_polyx_limit_V1;
    pd_rewards_claim_itn_reward_V1_t rewards_claim_itn_reward_V1;
#endif
} pd_MethodBasic_V1_t;

#define PD_CALL_BALANCES_TRANSFER_V1 0
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V1_t;

#define PD_CALL_IDENTITY_REMOVE_SECONDARY_KEYS_V1 2
typedef struct {
    pd_VecSignatory_V1_t signers_to_remove;
} pd_identity_remove_secondary_keys_V1_t;

#define PD_CALL_IDENTITY_ACCEPT_PRIMARY_KEY_V1 3
typedef struct {
    pd_u64_t rotation_auth_id;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_identity_accept_primary_key_V1_t;

#define PD_CALL_IDENTITY_JOIN_IDENTITY_AS_KEY_V1 5
typedef struct {
    pd_u64_t auth_id;
} pd_identity_join_identity_as_key_V1_t;

#define PD_CALL_IDENTITY_LEAVE_IDENTITY_AS_KEY_V1 6
typedef struct {
} pd_identity_leave_identity_as_key_V1_t;

#define PD_CALL_IDENTITY_ADD_CLAIM_V1 7
typedef struct {
    pd_IdentityId_V1_t target;
    pd_Claim_V1_t claim;
    pd_OptionMoment_V1_t expiry;
} pd_identity_add_claim_V1_t;

#define PD_CALL_IDENTITY_REVOKE_CLAIM_V1 8
typedef struct {
    pd_IdentityId_V1_t target;
    pd_Claim_V1_t claim;
} pd_identity_revoke_claim_V1_t;

#define PD_CALL_IDENTITY_SET_PERMISSION_TO_SIGNER_V1 9
typedef struct {
    pd_Signatory_V1_t signer;
    pd_Permissions_V1_t permissions;
} pd_identity_set_permission_to_signer_V1_t;

#define PD_CALL_IDENTITY_FREEZE_SECONDARY_KEYS_V1 11
typedef struct {
} pd_identity_freeze_secondary_keys_V1_t;

#define PD_CALL_IDENTITY_UNFREEZE_SECONDARY_KEYS_V1 12
typedef struct {
} pd_identity_unfreeze_secondary_keys_V1_t;

#define PD_CALL_IDENTITY_ADD_AUTHORIZATION_V1 13
typedef struct {
    pd_Signatory_V1_t target;
    pd_AuthorizationData_V1_t authorization_data;
    pd_OptionMoment_V1_t expiry;
} pd_identity_add_authorization_V1_t;

#define PD_CALL_IDENTITY_REMOVE_AUTHORIZATION_V1 14
typedef struct {
    pd_Signatory_V1_t target;
    pd_u64_t auth_id;
    pd_bool_t _auth_issuer_pays;
} pd_identity_remove_authorization_V1_t;

#define PD_CALL_IDENTITY_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION_V1 15
typedef struct {
    pd_VecSecondaryKeyWithAuth_V1_t additional_keys;
    pd_Moment_V1_t expires_at;
} pd_identity_add_secondary_keys_with_authorization_V1_t;

#define PD_CALL_IDENTITY_ADD_INVESTOR_UNIQUENESS_CLAIM_V1 16
typedef struct {
    pd_IdentityId_V1_t target;
    pd_Claim_V1_t claim;
    pd_InvestorZKProofData_V1_t proof;
    pd_OptionMoment_V1_t expiry;
} pd_identity_add_investor_uniqueness_claim_V1_t;

#define PD_CALL_MULTISIG_CREATE_MULTISIG_V1 0
typedef struct {
    pd_VecSignatory_V1_t signers;
    pd_u64_t sigs_required;
} pd_multisig_create_multisig_V1_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY_V1 1
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V1_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_identity_V1_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_KEY_V1 2
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V1_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_key_V1_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_IDENTITY_V1 3
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V1_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_identity_V1_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_KEY_V1 4
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V1_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_key_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_IDENTITY_V1 5
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_identity_V1_t;

#define PD_CALL_MULTISIG_APPROVE_AS_KEY_V1 6
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_key_V1_t;

#define PD_CALL_MULTISIG_REJECT_AS_IDENTITY_V1 7
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_identity_V1_t;

#define PD_CALL_MULTISIG_REJECT_AS_KEY_V1 8
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_key_V1_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY_V1 9
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_identity_V1_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_KEY_V1 10
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_key_V1_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNER_V1 11
typedef struct {
    pd_Signatory_V1_t signer;
} pd_multisig_add_multisig_signer_V1_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNER_V1 12
typedef struct {
    pd_Signatory_V1_t signer;
} pd_multisig_remove_multisig_signer_V1_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNERS_VIA_CREATOR_V1 13
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_VecSignatory_V1_t signers;
} pd_multisig_add_multisig_signers_via_creator_V1_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR_V1 14
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_VecSignatory_V1_t signers;
} pd_multisig_remove_multisig_signers_via_creator_V1_t;

#define PD_CALL_MULTISIG_CHANGE_SIGS_REQUIRED_V1 15
typedef struct {
    pd_u64_t sigs_required;
} pd_multisig_change_sigs_required_V1_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_SIGNER_V1 16
typedef struct {
    pd_AccountId_V1_t multisig;
} pd_multisig_make_multisig_signer_V1_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_PRIMARY_V1 17
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_multisig_make_multisig_primary_V1_t;

#define PD_CALL_MULTISIG_EXECUTE_SCHEDULED_PROPOSAL_V1 18
typedef struct {
    pd_AccountId_V1_t multisig;
    pd_u64_t proposal_id;
    pd_IdentityId_V1_t multisig_did;
    pd_Weight_V1_t _proposal_weight;
} pd_multisig_execute_scheduled_proposal_V1_t;

#define PD_CALL_STAKING_BOND_V1 0
typedef struct {
    pd_LookupSource_V1_t controller;
    pd_CompactBalanceOf_t amount;
    pd_RewardDestination_V1_t payee;
} pd_staking_bond_V1_t;

#define PD_CALL_STAKING_BOND_EXTRA_V1 1
typedef struct {
    pd_CompactBalanceOf_t amount;
} pd_staking_bond_extra_V1_t;

#define PD_CALL_STAKING_UNBOND_V1 2
typedef struct {
    pd_CompactBalanceOf_t amount;
} pd_staking_unbond_V1_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V1 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V1_t;

#define PD_CALL_STAKING_VALIDATE_V1 4
typedef struct {
    pd_ValidatorPrefs_V1_t prefs;
} pd_staking_validate_V1_t;

#define PD_CALL_STAKING_NOMINATE_V1 5
typedef struct {
    pd_VecLookupSource_V1_t targets;
} pd_staking_nominate_V1_t;

#define PD_CALL_STAKING_CHILL_V1 6
typedef struct {
} pd_staking_chill_V1_t;

#define PD_CALL_STAKING_SET_PAYEE_V1 7
typedef struct {
    pd_RewardDestination_V1_t payee;
} pd_staking_set_payee_V1_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V1 8
typedef struct {
    pd_LookupSource_V1_t controller;
} pd_staking_set_controller_V1_t;

#define PD_CALL_STAKING_REBOND_V1 24
typedef struct {
    pd_CompactBalanceOf_t amount;
} pd_staking_rebond_V1_t;

#define PD_CALL_PIPS_PROPOSE_V1 6
typedef struct {
    pd_Proposal_t proposal;
    pd_Balance_t deposit;
    pd_OptionUrl_V1_t url;
    pd_OptionPipDescription_V1_t description;
} pd_pips_propose_V1_t;

#define PD_CALL_PIPS_VOTE_V1 7
typedef struct {
    pd_PipId_V1_t id;
    pd_bool_t aye_or_nay;
    pd_Balance_t deposit;
} pd_pips_vote_V1_t;

#define PD_CALL_UTILITY_BATCH_V1 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V1_t;

#define PD_CALL_UTILITY_BATCH_ATOMIC_V1 1
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_atomic_V1_t;

#define PD_CALL_UTILITY_BATCH_OPTIMISTIC_V1 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_optimistic_V1_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V1 0
typedef struct {
    pd_Perbill_V1_t _ratio;
} pd_system_fill_block_V1_t;

#define PD_CALL_SYSTEM_REMARK_V1 1
typedef struct {
    pd_Bytes_t _remark;
} pd_system_remark_V1_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V1 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_V1 3
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_V1_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V1 4
typedef struct {
    pd_Bytes_t code;
} pd_system_set_code_without_checks_V1_t;

#define PD_CALL_TIMESTAMP_SET_V1 0
typedef struct {
    pd_CompactMoment_V1_t now;
} pd_timestamp_set_V1_t;

#define PD_CALL_INDICES_CLAIM_V1 0
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_claim_V1_t;

#define PD_CALL_INDICES_TRANSFER_V1 1
typedef struct {
    pd_AccountId_V1_t new_;
    pd_AccountIndex_V1_t index;
} pd_indices_transfer_V1_t;

#define PD_CALL_INDICES_FREE_V1 2
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_free_V1_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V1 3
typedef struct {
    pd_AccountId_V1_t new_;
    pd_AccountIndex_V1_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V1_t;

#define PD_CALL_INDICES_FREEZE_V1 4
typedef struct {
    pd_AccountIndex_V1_t index;
} pd_indices_freeze_V1_t;

#define PD_CALL_BALANCES_TRANSFER_WITH_MEMO_V1 1
typedef struct {
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t amount;
    pd_OptionMemo_V1_t memo;
} pd_balances_transfer_with_memo_V1_t;

#define PD_CALL_BALANCES_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE_V1 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_balances_deposit_block_reward_reserve_balance_V1_t;

#define PD_CALL_BALANCES_SET_BALANCE_V1 3
typedef struct {
    pd_LookupSource_V1_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V1_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V1 4
typedef struct {
    pd_LookupSource_V1_t source;
    pd_LookupSource_V1_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V1_t;

#define PD_CALL_BALANCES_BURN_ACCOUNT_BALANCE_V1 5
typedef struct {
    pd_Balance_t amount;
} pd_balances_burn_account_balance_V1_t;

#define PD_CALL_IDENTITY_INVALIDATE_CDD_CLAIMS_V1 1
typedef struct {
    pd_IdentityId_V1_t cdd;
    pd_Moment_V1_t disable_from;
    pd_OptionMoment_V1_t expiry;
} pd_identity_invalidate_cdd_claims_V1_t;

#define PD_CALL_IDENTITY_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION_V1 4
typedef struct {
    pd_bool_t auth_required;
} pd_identity_change_cdd_requirement_for_mk_rotation_V1_t;

#define PD_CALL_IDENTITY_GC_ADD_CDD_CLAIM_V1 17
typedef struct {
    pd_IdentityId_V1_t target;
} pd_identity_gc_add_cdd_claim_V1_t;

#define PD_CALL_IDENTITY_GC_REVOKE_CDD_CLAIM_V1 18
typedef struct {
    pd_IdentityId_V1_t target;
} pd_identity_gc_revoke_cdd_claim_V1_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SET_ACTIVE_MEMBERS_LIMIT_V1 0
typedef struct {
    pd_MemberCount_V1_t limit;
} pd_cddserviceproviders_set_active_members_limit_V1_t;

#define PD_CALL_CDDSERVICEPROVIDERS_DISABLE_MEMBER_V1 1
typedef struct {
    pd_IdentityId_V1_t who;
    pd_OptionMoment_V1_t expiry;
    pd_OptionMoment_V1_t at;
} pd_cddserviceproviders_disable_member_V1_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ADD_MEMBER_V1 2
typedef struct {
    pd_IdentityId_V1_t who;
} pd_cddserviceproviders_add_member_V1_t;

#define PD_CALL_CDDSERVICEPROVIDERS_REMOVE_MEMBER_V1 3
typedef struct {
    pd_IdentityId_V1_t who;
} pd_cddserviceproviders_remove_member_V1_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SWAP_MEMBER_V1 4
typedef struct {
    pd_IdentityId_V1_t remove;
    pd_IdentityId_V1_t add;
} pd_cddserviceproviders_swap_member_V1_t;

#define PD_CALL_CDDSERVICEPROVIDERS_RESET_MEMBERS_V1 5
typedef struct {
    pd_VecIdentityId_V1_t members;
} pd_cddserviceproviders_reset_members_V1_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ABDICATE_MEMBERSHIP_V1 6
typedef struct {
} pd_cddserviceproviders_abdicate_membership_V1_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_VOTE_THRESHOLD_V1 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_polymeshcommittee_set_vote_threshold_V1_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_RELEASE_COORDINATOR_V1 1
typedef struct {
    pd_IdentityId_V1_t id;
} pd_polymeshcommittee_set_release_coordinator_V1_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_EXPIRES_AFTER_V1 2
typedef struct {
    pd_MaybeBlock_V1_t expiry;
} pd_polymeshcommittee_set_expires_after_V1_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_OR_PROPOSE_V1 3
typedef struct {
    pd_bool_t approve;
    pd_Call_t call;
} pd_polymeshcommittee_vote_or_propose_V1_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_V1 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V1_t index;
    pd_bool_t approve;
} pd_polymeshcommittee_vote_V1_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V1 0
typedef struct {
    pd_MemberCount_V1_t limit;
} pd_committeemembership_set_active_members_limit_V1_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_DISABLE_MEMBER_V1 1
typedef struct {
    pd_IdentityId_V1_t who;
    pd_OptionMoment_V1_t expiry;
    pd_OptionMoment_V1_t at;
} pd_committeemembership_disable_member_V1_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ADD_MEMBER_V1 2
typedef struct {
    pd_IdentityId_V1_t who;
} pd_committeemembership_add_member_V1_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_REMOVE_MEMBER_V1 3
typedef struct {
    pd_IdentityId_V1_t who;
} pd_committeemembership_remove_member_V1_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SWAP_MEMBER_V1 4
typedef struct {
    pd_IdentityId_V1_t remove;
    pd_IdentityId_V1_t add;
} pd_committeemembership_swap_member_V1_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_RESET_MEMBERS_V1 5
typedef struct {
    pd_VecIdentityId_V1_t members;
} pd_committeemembership_reset_members_V1_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V1 6
typedef struct {
} pd_committeemembership_abdicate_membership_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_VOTE_THRESHOLD_V1 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_technicalcommittee_set_vote_threshold_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_RELEASE_COORDINATOR_V1 1
typedef struct {
    pd_IdentityId_V1_t id;
} pd_technicalcommittee_set_release_coordinator_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_EXPIRES_AFTER_V1 2
typedef struct {
    pd_MaybeBlock_V1_t expiry;
} pd_technicalcommittee_set_expires_after_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_OR_PROPOSE_V1 3
typedef struct {
    pd_bool_t approve;
    pd_Call_t call;
} pd_technicalcommittee_vote_or_propose_V1_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V1 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V1_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V1_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V1 0
typedef struct {
    pd_MemberCount_V1_t limit;
} pd_technicalcommitteemembership_set_active_members_limit_V1_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V1 1
typedef struct {
    pd_IdentityId_V1_t who;
    pd_OptionMoment_V1_t expiry;
    pd_OptionMoment_V1_t at;
} pd_technicalcommitteemembership_disable_member_V1_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER_V1 2
typedef struct {
    pd_IdentityId_V1_t who;
} pd_technicalcommitteemembership_add_member_V1_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V1 3
typedef struct {
    pd_IdentityId_V1_t who;
} pd_technicalcommitteemembership_remove_member_V1_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER_V1 4
typedef struct {
    pd_IdentityId_V1_t remove;
    pd_IdentityId_V1_t add;
} pd_technicalcommitteemembership_swap_member_V1_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS_V1 5
typedef struct {
    pd_VecIdentityId_V1_t members;
} pd_technicalcommitteemembership_reset_members_V1_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V1 6
typedef struct {
} pd_technicalcommitteemembership_abdicate_membership_V1_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_VOTE_THRESHOLD_V1 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_upgradecommittee_set_vote_threshold_V1_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_RELEASE_COORDINATOR_V1 1
typedef struct {
    pd_IdentityId_V1_t id;
} pd_upgradecommittee_set_release_coordinator_V1_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_EXPIRES_AFTER_V1 2
typedef struct {
    pd_MaybeBlock_V1_t expiry;
} pd_upgradecommittee_set_expires_after_V1_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_OR_PROPOSE_V1 3
typedef struct {
    pd_bool_t approve;
    pd_Call_t call;
} pd_upgradecommittee_vote_or_propose_V1_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_V1 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V1_t index;
    pd_bool_t approve;
} pd_upgradecommittee_vote_V1_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V1 0
typedef struct {
    pd_MemberCount_V1_t limit;
} pd_upgradecommitteemembership_set_active_members_limit_V1_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V1 1
typedef struct {
    pd_IdentityId_V1_t who;
    pd_OptionMoment_V1_t expiry;
    pd_OptionMoment_V1_t at;
} pd_upgradecommitteemembership_disable_member_V1_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ADD_MEMBER_V1 2
typedef struct {
    pd_IdentityId_V1_t who;
} pd_upgradecommitteemembership_add_member_V1_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V1 3
typedef struct {
    pd_IdentityId_V1_t who;
} pd_upgradecommitteemembership_remove_member_V1_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SWAP_MEMBER_V1 4
typedef struct {
    pd_IdentityId_V1_t remove;
    pd_IdentityId_V1_t add;
} pd_upgradecommitteemembership_swap_member_V1_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_RESET_MEMBERS_V1 5
typedef struct {
    pd_VecIdentityId_V1_t members;
} pd_upgradecommitteemembership_reset_members_V1_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V1 6
typedef struct {
} pd_upgradecommitteemembership_abdicate_membership_V1_t;

#define PD_CALL_BRIDGE_CHANGE_CONTROLLER_V1 0
typedef struct {
    pd_AccountId_V1_t controller;
} pd_bridge_change_controller_V1_t;

#define PD_CALL_BRIDGE_CHANGE_ADMIN_V1 1
typedef struct {
    pd_AccountId_V1_t admin;
} pd_bridge_change_admin_V1_t;

#define PD_CALL_BRIDGE_CHANGE_TIMELOCK_V1 2
typedef struct {
    pd_BlockNumber_t timelock;
} pd_bridge_change_timelock_V1_t;

#define PD_CALL_BRIDGE_FREEZE_V1 3
typedef struct {
} pd_bridge_freeze_V1_t;

#define PD_CALL_BRIDGE_UNFREEZE_V1 4
typedef struct {
} pd_bridge_unfreeze_V1_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_LIMIT_V1 5
typedef struct {
    pd_Balance_t amount;
    pd_BlockNumber_t duration;
} pd_bridge_change_bridge_limit_V1_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_EXEMPTED_V1 6
typedef struct {
    pd_VecTupleIdentityIdbool_V1_t exempted;
} pd_bridge_change_bridge_exempted_V1_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V1 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V1_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V1 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V1_t;

#define PD_CALL_STAKING_ADD_PERMISSIONED_VALIDATOR_V1 12
typedef struct {
    pd_IdentityId_V1_t identity;
    pd_Optionu32_t intended_count;
} pd_staking_add_permissioned_validator_V1_t;

#define PD_CALL_STAKING_REMOVE_PERMISSIONED_VALIDATOR_V1 13
typedef struct {
    pd_IdentityId_V1_t identity;
} pd_staking_remove_permissioned_validator_V1_t;

#define PD_CALL_STAKING_VALIDATE_CDD_EXPIRY_NOMINATORS_V1 14
typedef struct {
    pd_VecAccountId_V1_t targets;
} pd_staking_validate_cdd_expiry_nominators_V1_t;

#define PD_CALL_STAKING_SET_COMMISSION_CAP_V1 15
typedef struct {
    pd_Perbill_V1_t new_cap;
} pd_staking_set_commission_cap_V1_t;

#define PD_CALL_STAKING_SET_MIN_BOND_THRESHOLD_V1 16
typedef struct {
    pd_BalanceOf_t new_value;
} pd_staking_set_min_bond_threshold_V1_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V1 17
typedef struct {
} pd_staking_force_no_eras_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V1 18
typedef struct {
} pd_staking_force_new_era_V1_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V1 19
typedef struct {
    pd_VecAccountId_V1_t invulnerables;
} pd_staking_set_invulnerables_V1_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V1 20
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V1_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V1 21
typedef struct {
} pd_staking_force_new_era_always_V1_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V1 22
typedef struct {
    pd_EraIndex_V1_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V1 23
typedef struct {
    pd_AccountId_V1_t validator_stash;
    pd_EraIndex_V1_t era;
} pd_staking_payout_stakers_V1_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V1 25
typedef struct {
    pd_CompactEraIndex_V1_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V1_t;

#define PD_CALL_STAKING_REAP_STASH_V1 26
typedef struct {
    pd_AccountId_V1_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V1_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_SYSTEM_V1 29
typedef struct {
    pd_AccountId_V1_t validator_stash;
    pd_EraIndex_V1_t era;
} pd_staking_payout_stakers_by_system_V1_t;

#define PD_CALL_STAKING_CHANGE_SLASHING_ALLOWED_FOR_V1 30
typedef struct {
    pd_SlashingSwitch_V1_t slashing_switch;
} pd_staking_change_slashing_allowed_for_V1_t;

#define PD_CALL_STAKING_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT_V1 31
typedef struct {
    pd_IdentityId_V1_t identity;
    pd_u32_t new_intended_count;
} pd_staking_update_permissioned_validator_intended_count_V1_t;

#define PD_CALL_SESSION_SET_KEYS_V1 0
typedef struct {
    pd_Keys_V1_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V1_t;

#define PD_CALL_SESSION_PURGE_KEYS_V1 1
typedef struct {
} pd_session_purge_keys_V1_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V1 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V1_t;

#define PD_CALL_SUDO_SUDO_AS_V1 3
typedef struct {
    pd_LookupSource_V1_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V1_t;

#define PD_CALL_ASSET_REGISTER_TICKER_V1 0
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_asset_register_ticker_V1_t;

#define PD_CALL_ASSET_ACCEPT_TICKER_TRANSFER_V1 1
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_ticker_transfer_V1_t;

#define PD_CALL_ASSET_ACCEPT_ASSET_OWNERSHIP_TRANSFER_V1 2
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_asset_ownership_transfer_V1_t;

#define PD_CALL_ASSET_CREATE_ASSET_V1 3
typedef struct {
    pd_AssetName_V1_t name;
    pd_Ticker_V1_t ticker;
    pd_bool_t divisible;
    pd_AssetType_V1_t asset_type;
    pd_VecAssetIdentifier_V1_t identifiers;
    pd_OptionFundingRoundName_V1_t funding_round;
    pd_bool_t disable_iu;
} pd_asset_create_asset_V1_t;

#define PD_CALL_ASSET_FREEZE_V1 4
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_asset_freeze_V1_t;

#define PD_CALL_ASSET_UNFREEZE_V1 5
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_asset_unfreeze_V1_t;

#define PD_CALL_ASSET_RENAME_ASSET_V1 6
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_AssetName_V1_t name;
} pd_asset_rename_asset_V1_t;

#define PD_CALL_ASSET_ISSUE_V1 7
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_BalanceNoSymbol_t amount;
} pd_asset_issue_V1_t;

#define PD_CALL_ASSET_REDEEM_V1 8
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_BalanceNoSymbol_t amount;
} pd_asset_redeem_V1_t;

#define PD_CALL_ASSET_MAKE_DIVISIBLE_V1 9
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_asset_make_divisible_V1_t;

#define PD_CALL_ASSET_ADD_DOCUMENTS_V1 10
typedef struct {
    pd_VecDocument_V1_t docs;
    pd_Ticker_V1_t ticker;
} pd_asset_add_documents_V1_t;

#define PD_CALL_ASSET_REMOVE_DOCUMENTS_V1 11
typedef struct {
    pd_VecDocumentId_V1_t ids;
    pd_Ticker_V1_t ticker;
} pd_asset_remove_documents_V1_t;

#define PD_CALL_ASSET_SET_FUNDING_ROUND_V1 12
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_FundingRoundName_V1_t name;
} pd_asset_set_funding_round_V1_t;

#define PD_CALL_ASSET_UPDATE_IDENTIFIERS_V1 13
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_VecAssetIdentifier_V1_t identifiers;
} pd_asset_update_identifiers_V1_t;

#define PD_CALL_ASSET_CLAIM_CLASSIC_TICKER_V1 14
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_EcdsaSignature_V1_t ethereum_signature;
} pd_asset_claim_classic_ticker_V1_t;

#define PD_CALL_ASSET_RESERVE_CLASSIC_TICKER_V1 15
typedef struct {
    pd_ClassicTickerImport_V1_t classic_ticker_import;
    pd_IdentityId_V1_t contract_did;
    pd_TickerRegistrationConfig_V1_t config;
} pd_asset_reserve_classic_ticker_V1_t;

#define PD_CALL_CAPITALDISTRIBUTION_DISTRIBUTE_V1 0
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_OptionPortfolioNumber_V1_t portfolio;
    pd_Ticker_V1_t currency;
    pd_Balance_t per_share;
    pd_Balance_t amount;
    pd_Moment_V1_t payment_at;
    pd_OptionMoment_V1_t expires_at;
} pd_capitaldistribution_distribute_V1_t;

#define PD_CALL_CAPITALDISTRIBUTION_CLAIM_V1 1
typedef struct {
    pd_CAId_V1_t ca_id;
} pd_capitaldistribution_claim_V1_t;

#define PD_CALL_CAPITALDISTRIBUTION_PUSH_BENEFIT_V1 2
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_IdentityId_V1_t holder;
} pd_capitaldistribution_push_benefit_V1_t;

#define PD_CALL_CAPITALDISTRIBUTION_RECLAIM_V1 3
typedef struct {
    pd_CAId_V1_t ca_id;
} pd_capitaldistribution_reclaim_V1_t;

#define PD_CALL_CAPITALDISTRIBUTION_REMOVE_DISTRIBUTION_V1 4
typedef struct {
    pd_CAId_V1_t ca_id;
} pd_capitaldistribution_remove_distribution_V1_t;

#define PD_CALL_CHECKPOINT_CREATE_CHECKPOINT_V1 0
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_checkpoint_create_checkpoint_V1_t;

#define PD_CALL_CHECKPOINT_SET_SCHEDULES_MAX_COMPLEXITY_V1 1
typedef struct {
    pd_u64_t max_complexity;
} pd_checkpoint_set_schedules_max_complexity_V1_t;

#define PD_CALL_CHECKPOINT_CREATE_SCHEDULE_V1 2
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_ScheduleSpec_V1_t schedule;
} pd_checkpoint_create_schedule_V1_t;

#define PD_CALL_CHECKPOINT_REMOVE_SCHEDULE_V1 3
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_ScheduleId_V1_t id;
} pd_checkpoint_remove_schedule_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_COMPLIANCE_REQUIREMENT_V1 0
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_VecCondition_V1_t sender_conditions;
    pd_VecCondition_V1_t receiver_conditions;
} pd_compliancemanager_add_compliance_requirement_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_COMPLIANCE_REQUIREMENT_V1 1
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_u32_t id;
} pd_compliancemanager_remove_compliance_requirement_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_REPLACE_ASSET_COMPLIANCE_V1 2
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_VecComplianceRequirement_V1_t asset_compliance;
} pd_compliancemanager_replace_asset_compliance_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_RESET_ASSET_COMPLIANCE_V1 3
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_compliancemanager_reset_asset_compliance_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_PAUSE_ASSET_COMPLIANCE_V1 4
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_compliancemanager_pause_asset_compliance_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_RESUME_ASSET_COMPLIANCE_V1 5
typedef struct {
    pd_Ticker_V1_t ticker;
} pd_compliancemanager_resume_asset_compliance_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER_V1 6
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_TrustedIssuer_V1_t issuer;
} pd_compliancemanager_add_default_trusted_claim_issuer_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER_V1 7
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_IdentityId_V1_t issuer;
} pd_compliancemanager_remove_default_trusted_claim_issuer_V1_t;

#define PD_CALL_COMPLIANCEMANAGER_CHANGE_COMPLIANCE_REQUIREMENT_V1 8
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_ComplianceRequirement_V1_t new_req;
} pd_compliancemanager_change_compliance_requirement_V1_t;

#define PD_CALL_CORPORATEACTION_SET_MAX_DETAILS_LENGTH_V1 0
typedef struct {
    pd_u32_t length;
} pd_corporateaction_set_max_details_length_V1_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_TARGETS_V1 1
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_TargetIdentities_V1_t targets;
} pd_corporateaction_set_default_targets_V1_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_WITHHOLDING_TAX_V1 2
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_Tax_V1_t tax;
} pd_corporateaction_set_default_withholding_tax_V1_t;

#define PD_CALL_CORPORATEACTION_SET_DID_WITHHOLDING_TAX_V1 3
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_IdentityId_V1_t taxed_did;
    pd_OptionTax_V1_t tax;
} pd_corporateaction_set_did_withholding_tax_V1_t;

#define PD_CALL_CORPORATEACTION_INITIATE_CORPORATE_ACTION_V1 4
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_CAKind_V1_t kind;
    pd_Moment_V1_t decl_date;
    pd_OptionRecordDateSpec_V1_t record_date;
    pd_CADetails_V1_t details;
    pd_OptionTargetIdentities_V1_t targets;
    pd_OptionTax_V1_t default_withholding_tax;
    pd_OptionVecTupleIdentityIdTax_V1_t withholding_tax;
} pd_corporateaction_initiate_corporate_action_V1_t;

#define PD_CALL_CORPORATEACTION_LINK_CA_DOC_V1 5
typedef struct {
    pd_CAId_V1_t id;
    pd_VecDocumentId_V1_t docs;
} pd_corporateaction_link_ca_doc_V1_t;

#define PD_CALL_CORPORATEACTION_REMOVE_CA_V1 6
typedef struct {
    pd_CAId_V1_t ca_id;
} pd_corporateaction_remove_ca_V1_t;

#define PD_CALL_CORPORATEACTION_CHANGE_RECORD_DATE_V1 7
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_OptionRecordDateSpec_V1_t record_date;
} pd_corporateaction_change_record_date_V1_t;

#define PD_CALL_CORPORATEBALLOT_ATTACH_BALLOT_V1 0
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_BallotTimeRange_V1_t range;
    pd_BallotMeta_V1_t meta;
    pd_bool_t rcv;
} pd_corporateballot_attach_ballot_V1_t;

#define PD_CALL_CORPORATEBALLOT_VOTE_V1 1
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_VecBallotVote_V1_t votes;
} pd_corporateballot_vote_V1_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_END_V1 2
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_Moment_V1_t end;
} pd_corporateballot_change_end_V1_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_META_V1 3
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_BallotMeta_V1_t meta;
} pd_corporateballot_change_meta_V1_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_RCV_V1 4
typedef struct {
    pd_CAId_V1_t ca_id;
    pd_bool_t rcv;
} pd_corporateballot_change_rcv_V1_t;

#define PD_CALL_CORPORATEBALLOT_REMOVE_BALLOT_V1 5
typedef struct {
    pd_CAId_V1_t ca_id;
} pd_corporateballot_remove_ballot_V1_t;

#define PD_CALL_PIPS_SET_PRUNE_HISTORICAL_PIPS_V1 0
typedef struct {
    pd_bool_t prune;
} pd_pips_set_prune_historical_pips_V1_t;

#define PD_CALL_PIPS_SET_MIN_PROPOSAL_DEPOSIT_V1 1
typedef struct {
    pd_Balance_t deposit;
} pd_pips_set_min_proposal_deposit_V1_t;

#define PD_CALL_PIPS_SET_DEFAULT_ENACTMENT_PERIOD_V1 2
typedef struct {
    pd_BlockNumber_t duration;
} pd_pips_set_default_enactment_period_V1_t;

#define PD_CALL_PIPS_SET_PENDING_PIP_EXPIRY_V1 3
typedef struct {
    pd_MaybeBlock_V1_t expiry;
} pd_pips_set_pending_pip_expiry_V1_t;

#define PD_CALL_PIPS_SET_MAX_PIP_SKIP_COUNT_V1 4
typedef struct {
    pd_SkippedCount_V1_t max;
} pd_pips_set_max_pip_skip_count_V1_t;

#define PD_CALL_PIPS_SET_ACTIVE_PIP_LIMIT_V1 5
typedef struct {
    pd_u32_t limit;
} pd_pips_set_active_pip_limit_V1_t;

#define PD_CALL_PIPS_APPROVE_COMMITTEE_PROPOSAL_V1 8
typedef struct {
    pd_PipId_V1_t id;
} pd_pips_approve_committee_proposal_V1_t;

#define PD_CALL_PIPS_REJECT_PROPOSAL_V1 9
typedef struct {
    pd_PipId_V1_t id;
} pd_pips_reject_proposal_V1_t;

#define PD_CALL_PIPS_PRUNE_PROPOSAL_V1 10
typedef struct {
    pd_PipId_V1_t id;
} pd_pips_prune_proposal_V1_t;

#define PD_CALL_PIPS_RESCHEDULE_EXECUTION_V1 11
typedef struct {
    pd_PipId_V1_t id;
    pd_OptionBlockNumber_t until;
} pd_pips_reschedule_execution_V1_t;

#define PD_CALL_PIPS_CLEAR_SNAPSHOT_V1 12
typedef struct {
} pd_pips_clear_snapshot_V1_t;

#define PD_CALL_PIPS_SNAPSHOT_V1 13
typedef struct {
} pd_pips_snapshot_V1_t;

#define PD_CALL_PIPS_ENACT_SNAPSHOT_RESULTS_V1 14
typedef struct {
    pd_VecTuplePipIdSnapshotResult_V1_t results;
} pd_pips_enact_snapshot_results_V1_t;

#define PD_CALL_PIPS_EXECUTE_SCHEDULED_PIP_V1 15
typedef struct {
    pd_PipId_V1_t id;
} pd_pips_execute_scheduled_pip_V1_t;

#define PD_CALL_PIPS_EXPIRE_SCHEDULED_PIP_V1 16
typedef struct {
    pd_IdentityId_V1_t did;
    pd_PipId_V1_t id;
} pd_pips_expire_scheduled_pip_V1_t;

#define PD_CALL_PORTFOLIO_CREATE_PORTFOLIO_V1 0
typedef struct {
    pd_PortfolioName_V1_t name;
} pd_portfolio_create_portfolio_V1_t;

#define PD_CALL_PORTFOLIO_DELETE_PORTFOLIO_V1 1
typedef struct {
    pd_PortfolioNumber_V1_t num;
} pd_portfolio_delete_portfolio_V1_t;

#define PD_CALL_PORTFOLIO_MOVE_PORTFOLIO_FUNDS_V1 2
typedef struct {
    pd_PortfolioId_V1_t from;
    pd_PortfolioId_V1_t to;
    pd_VecMovePortfolioItem_V1_t items;
} pd_portfolio_move_portfolio_funds_V1_t;

#define PD_CALL_PORTFOLIO_RENAME_PORTFOLIO_V1 3
typedef struct {
    pd_PortfolioNumber_V1_t num;
    pd_PortfolioName_V1_t to_name;
} pd_portfolio_rename_portfolio_V1_t;

#define PD_CALL_PROTOCOLFEE_CHANGE_COEFFICIENT_V1 0
typedef struct {
    pd_PosRatio_V1_t coefficient;
} pd_protocolfee_change_coefficient_V1_t;

#define PD_CALL_SETTLEMENT_CREATE_VENUE_V1 0
typedef struct {
    pd_VenueDetails_V1_t details;
    pd_VecAccountId_V1_t signers;
    pd_VenueType_V1_t typ;
} pd_settlement_create_venue_V1_t;

#define PD_CALL_SETTLEMENT_SET_VENUE_FILTERING_V1 11
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_bool_t enabled;
} pd_settlement_set_venue_filtering_V1_t;

#define PD_CALL_STATISTICS_ADD_TRANSFER_MANAGER_V1 0
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_TransferManager_V1_t new_transfer_manager;
} pd_statistics_add_transfer_manager_V1_t;

#define PD_CALL_STATISTICS_REMOVE_TRANSFER_MANAGER_V1 1
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_TransferManager_V1_t transfer_manager;
} pd_statistics_remove_transfer_manager_V1_t;

#define PD_CALL_STATISTICS_ADD_EXEMPTED_ENTITIES_V1 2
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_TransferManager_V1_t transfer_manager;
    pd_VecScopeId_V1_t exempted_entities;
} pd_statistics_add_exempted_entities_V1_t;

#define PD_CALL_STATISTICS_REMOVE_EXEMPTED_ENTITIES_V1 3
typedef struct {
    pd_Ticker_V1_t ticker;
    pd_TransferManager_V1_t transfer_manager;
    pd_VecScopeId_V1_t entities;
} pd_statistics_remove_exempted_entities_V1_t;

#define PD_CALL_TREASURY_DISBURSEMENT_V1 0
typedef struct {
    pd_VecBeneficiary_V1_t beneficiaries;
} pd_treasury_disbursement_V1_t;

#define PD_CALL_TREASURY_REIMBURSEMENT_V1 1
typedef struct {
    pd_BalanceOf_t amount;
} pd_treasury_reimbursement_V1_t;

#define PD_CALL_UTILITY_RELAY_TX_V1 3
typedef struct {
    pd_AccountId_V1_t target;
    pd_OffChainSignature_V1_t signature;
    pd_UniqueCall_V1_t call;
} pd_utility_relay_tx_V1_t;

#endif

typedef union {
    pd_balances_transfer_V1_t balances_transfer_V1;
    pd_identity_remove_secondary_keys_V1_t identity_remove_secondary_keys_V1;
    pd_identity_accept_primary_key_V1_t identity_accept_primary_key_V1;
    pd_identity_join_identity_as_key_V1_t identity_join_identity_as_key_V1;
    pd_identity_leave_identity_as_key_V1_t identity_leave_identity_as_key_V1;
    pd_identity_add_claim_V1_t identity_add_claim_V1;
    pd_identity_revoke_claim_V1_t identity_revoke_claim_V1;
    pd_identity_set_permission_to_signer_V1_t identity_set_permission_to_signer_V1;
    pd_identity_freeze_secondary_keys_V1_t identity_freeze_secondary_keys_V1;
    pd_identity_unfreeze_secondary_keys_V1_t identity_unfreeze_secondary_keys_V1;
    pd_identity_add_authorization_V1_t identity_add_authorization_V1;
    pd_identity_remove_authorization_V1_t identity_remove_authorization_V1;
    pd_identity_add_secondary_keys_with_authorization_V1_t identity_add_secondary_keys_with_authorization_V1;
    pd_identity_add_investor_uniqueness_claim_V1_t identity_add_investor_uniqueness_claim_V1;
    pd_multisig_create_multisig_V1_t multisig_create_multisig_V1;
    pd_multisig_create_or_approve_proposal_as_identity_V1_t multisig_create_or_approve_proposal_as_identity_V1;
    pd_multisig_create_or_approve_proposal_as_key_V1_t multisig_create_or_approve_proposal_as_key_V1;
    pd_multisig_create_proposal_as_identity_V1_t multisig_create_proposal_as_identity_V1;
    pd_multisig_create_proposal_as_key_V1_t multisig_create_proposal_as_key_V1;
    pd_multisig_approve_as_identity_V1_t multisig_approve_as_identity_V1;
    pd_multisig_approve_as_key_V1_t multisig_approve_as_key_V1;
    pd_multisig_reject_as_identity_V1_t multisig_reject_as_identity_V1;
    pd_multisig_reject_as_key_V1_t multisig_reject_as_key_V1;
    pd_multisig_accept_multisig_signer_as_identity_V1_t multisig_accept_multisig_signer_as_identity_V1;
    pd_multisig_accept_multisig_signer_as_key_V1_t multisig_accept_multisig_signer_as_key_V1;
    pd_multisig_add_multisig_signer_V1_t multisig_add_multisig_signer_V1;
    pd_multisig_remove_multisig_signer_V1_t multisig_remove_multisig_signer_V1;
    pd_multisig_add_multisig_signers_via_creator_V1_t multisig_add_multisig_signers_via_creator_V1;
    pd_multisig_remove_multisig_signers_via_creator_V1_t multisig_remove_multisig_signers_via_creator_V1;
    pd_multisig_change_sigs_required_V1_t multisig_change_sigs_required_V1;
    pd_multisig_make_multisig_signer_V1_t multisig_make_multisig_signer_V1;
    pd_multisig_make_multisig_primary_V1_t multisig_make_multisig_primary_V1;
    pd_multisig_execute_scheduled_proposal_V1_t multisig_execute_scheduled_proposal_V1;
    pd_staking_bond_V1_t staking_bond_V1;
    pd_staking_bond_extra_V1_t staking_bond_extra_V1;
    pd_staking_unbond_V1_t staking_unbond_V1;
    pd_staking_withdraw_unbonded_V1_t staking_withdraw_unbonded_V1;
    pd_staking_validate_V1_t staking_validate_V1;
    pd_staking_nominate_V1_t staking_nominate_V1;
    pd_staking_chill_V1_t staking_chill_V1;
    pd_staking_set_payee_V1_t staking_set_payee_V1;
    pd_staking_set_controller_V1_t staking_set_controller_V1;
    pd_staking_rebond_V1_t staking_rebond_V1;
    pd_pips_propose_V1_t pips_propose_V1;
    pd_pips_vote_V1_t pips_vote_V1;
    pd_utility_batch_V1_t utility_batch_V1;
    pd_utility_batch_atomic_V1_t utility_batch_atomic_V1;
    pd_utility_batch_optimistic_V1_t utility_batch_optimistic_V1;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V1_t system_fill_block_V1;
    pd_system_remark_V1_t system_remark_V1;
    pd_system_set_heap_pages_V1_t system_set_heap_pages_V1;
    pd_system_set_code_V1_t system_set_code_V1;
    pd_system_set_code_without_checks_V1_t system_set_code_without_checks_V1;
    pd_timestamp_set_V1_t timestamp_set_V1;
    pd_indices_claim_V1_t indices_claim_V1;
    pd_indices_transfer_V1_t indices_transfer_V1;
    pd_indices_free_V1_t indices_free_V1;
    pd_indices_force_transfer_V1_t indices_force_transfer_V1;
    pd_indices_freeze_V1_t indices_freeze_V1;
    pd_balances_transfer_with_memo_V1_t balances_transfer_with_memo_V1;
    pd_balances_deposit_block_reward_reserve_balance_V1_t balances_deposit_block_reward_reserve_balance_V1;
    pd_balances_set_balance_V1_t balances_set_balance_V1;
    pd_balances_force_transfer_V1_t balances_force_transfer_V1;
    pd_balances_burn_account_balance_V1_t balances_burn_account_balance_V1;
    pd_identity_invalidate_cdd_claims_V1_t identity_invalidate_cdd_claims_V1;
    pd_identity_change_cdd_requirement_for_mk_rotation_V1_t identity_change_cdd_requirement_for_mk_rotation_V1;
    pd_identity_gc_add_cdd_claim_V1_t identity_gc_add_cdd_claim_V1;
    pd_identity_gc_revoke_cdd_claim_V1_t identity_gc_revoke_cdd_claim_V1;
    pd_cddserviceproviders_set_active_members_limit_V1_t cddserviceproviders_set_active_members_limit_V1;
    pd_cddserviceproviders_disable_member_V1_t cddserviceproviders_disable_member_V1;
    pd_cddserviceproviders_add_member_V1_t cddserviceproviders_add_member_V1;
    pd_cddserviceproviders_remove_member_V1_t cddserviceproviders_remove_member_V1;
    pd_cddserviceproviders_swap_member_V1_t cddserviceproviders_swap_member_V1;
    pd_cddserviceproviders_reset_members_V1_t cddserviceproviders_reset_members_V1;
    pd_cddserviceproviders_abdicate_membership_V1_t cddserviceproviders_abdicate_membership_V1;
    pd_polymeshcommittee_set_vote_threshold_V1_t polymeshcommittee_set_vote_threshold_V1;
    pd_polymeshcommittee_set_release_coordinator_V1_t polymeshcommittee_set_release_coordinator_V1;
    pd_polymeshcommittee_set_expires_after_V1_t polymeshcommittee_set_expires_after_V1;
    pd_polymeshcommittee_vote_or_propose_V1_t polymeshcommittee_vote_or_propose_V1;
    pd_polymeshcommittee_vote_V1_t polymeshcommittee_vote_V1;
    pd_committeemembership_set_active_members_limit_V1_t committeemembership_set_active_members_limit_V1;
    pd_committeemembership_disable_member_V1_t committeemembership_disable_member_V1;
    pd_committeemembership_add_member_V1_t committeemembership_add_member_V1;
    pd_committeemembership_remove_member_V1_t committeemembership_remove_member_V1;
    pd_committeemembership_swap_member_V1_t committeemembership_swap_member_V1;
    pd_committeemembership_reset_members_V1_t committeemembership_reset_members_V1;
    pd_committeemembership_abdicate_membership_V1_t committeemembership_abdicate_membership_V1;
    pd_technicalcommittee_set_vote_threshold_V1_t technicalcommittee_set_vote_threshold_V1;
    pd_technicalcommittee_set_release_coordinator_V1_t technicalcommittee_set_release_coordinator_V1;
    pd_technicalcommittee_set_expires_after_V1_t technicalcommittee_set_expires_after_V1;
    pd_technicalcommittee_vote_or_propose_V1_t technicalcommittee_vote_or_propose_V1;
    pd_technicalcommittee_vote_V1_t technicalcommittee_vote_V1;
    pd_technicalcommitteemembership_set_active_members_limit_V1_t technicalcommitteemembership_set_active_members_limit_V1;
    pd_technicalcommitteemembership_disable_member_V1_t technicalcommitteemembership_disable_member_V1;
    pd_technicalcommitteemembership_add_member_V1_t technicalcommitteemembership_add_member_V1;
    pd_technicalcommitteemembership_remove_member_V1_t technicalcommitteemembership_remove_member_V1;
    pd_technicalcommitteemembership_swap_member_V1_t technicalcommitteemembership_swap_member_V1;
    pd_technicalcommitteemembership_reset_members_V1_t technicalcommitteemembership_reset_members_V1;
    pd_technicalcommitteemembership_abdicate_membership_V1_t technicalcommitteemembership_abdicate_membership_V1;
    pd_upgradecommittee_set_vote_threshold_V1_t upgradecommittee_set_vote_threshold_V1;
    pd_upgradecommittee_set_release_coordinator_V1_t upgradecommittee_set_release_coordinator_V1;
    pd_upgradecommittee_set_expires_after_V1_t upgradecommittee_set_expires_after_V1;
    pd_upgradecommittee_vote_or_propose_V1_t upgradecommittee_vote_or_propose_V1;
    pd_upgradecommittee_vote_V1_t upgradecommittee_vote_V1;
    pd_upgradecommitteemembership_set_active_members_limit_V1_t upgradecommitteemembership_set_active_members_limit_V1;
    pd_upgradecommitteemembership_disable_member_V1_t upgradecommitteemembership_disable_member_V1;
    pd_upgradecommitteemembership_add_member_V1_t upgradecommitteemembership_add_member_V1;
    pd_upgradecommitteemembership_remove_member_V1_t upgradecommitteemembership_remove_member_V1;
    pd_upgradecommitteemembership_swap_member_V1_t upgradecommitteemembership_swap_member_V1;
    pd_upgradecommitteemembership_reset_members_V1_t upgradecommitteemembership_reset_members_V1;
    pd_upgradecommitteemembership_abdicate_membership_V1_t upgradecommitteemembership_abdicate_membership_V1;
    pd_bridge_change_controller_V1_t bridge_change_controller_V1;
    pd_bridge_change_admin_V1_t bridge_change_admin_V1;
    pd_bridge_change_timelock_V1_t bridge_change_timelock_V1;
    pd_bridge_freeze_V1_t bridge_freeze_V1;
    pd_bridge_unfreeze_V1_t bridge_unfreeze_V1;
    pd_bridge_change_bridge_limit_V1_t bridge_change_bridge_limit_V1;
    pd_bridge_change_bridge_exempted_V1_t bridge_change_bridge_exempted_V1;
    pd_staking_set_validator_count_V1_t staking_set_validator_count_V1;
    pd_staking_increase_validator_count_V1_t staking_increase_validator_count_V1;
    pd_staking_add_permissioned_validator_V1_t staking_add_permissioned_validator_V1;
    pd_staking_remove_permissioned_validator_V1_t staking_remove_permissioned_validator_V1;
    pd_staking_validate_cdd_expiry_nominators_V1_t staking_validate_cdd_expiry_nominators_V1;
    pd_staking_set_commission_cap_V1_t staking_set_commission_cap_V1;
    pd_staking_set_min_bond_threshold_V1_t staking_set_min_bond_threshold_V1;
    pd_staking_force_no_eras_V1_t staking_force_no_eras_V1;
    pd_staking_force_new_era_V1_t staking_force_new_era_V1;
    pd_staking_set_invulnerables_V1_t staking_set_invulnerables_V1;
    pd_staking_force_unstake_V1_t staking_force_unstake_V1;
    pd_staking_force_new_era_always_V1_t staking_force_new_era_always_V1;
    pd_staking_cancel_deferred_slash_V1_t staking_cancel_deferred_slash_V1;
    pd_staking_payout_stakers_V1_t staking_payout_stakers_V1;
    pd_staking_set_history_depth_V1_t staking_set_history_depth_V1;
    pd_staking_reap_stash_V1_t staking_reap_stash_V1;
    pd_staking_payout_stakers_by_system_V1_t staking_payout_stakers_by_system_V1;
    pd_staking_change_slashing_allowed_for_V1_t staking_change_slashing_allowed_for_V1;
    pd_staking_update_permissioned_validator_intended_count_V1_t staking_update_permissioned_validator_intended_count_V1;
    pd_session_set_keys_V1_t session_set_keys_V1;
    pd_session_purge_keys_V1_t session_purge_keys_V1;
    pd_grandpa_note_stalled_V1_t grandpa_note_stalled_V1;
    pd_sudo_sudo_as_V1_t sudo_sudo_as_V1;
    pd_asset_register_ticker_V1_t asset_register_ticker_V1;
    pd_asset_accept_ticker_transfer_V1_t asset_accept_ticker_transfer_V1;
    pd_asset_accept_asset_ownership_transfer_V1_t asset_accept_asset_ownership_transfer_V1;
    pd_asset_create_asset_V1_t asset_create_asset_V1;
    pd_asset_freeze_V1_t asset_freeze_V1;
    pd_asset_unfreeze_V1_t asset_unfreeze_V1;
    pd_asset_rename_asset_V1_t asset_rename_asset_V1;
    pd_asset_issue_V1_t asset_issue_V1;
    pd_asset_redeem_V1_t asset_redeem_V1;
    pd_asset_make_divisible_V1_t asset_make_divisible_V1;
    pd_asset_add_documents_V1_t asset_add_documents_V1;
    pd_asset_remove_documents_V1_t asset_remove_documents_V1;
    pd_asset_set_funding_round_V1_t asset_set_funding_round_V1;
    pd_asset_update_identifiers_V1_t asset_update_identifiers_V1;
    pd_asset_claim_classic_ticker_V1_t asset_claim_classic_ticker_V1;
    pd_asset_reserve_classic_ticker_V1_t asset_reserve_classic_ticker_V1;
    pd_capitaldistribution_distribute_V1_t capitaldistribution_distribute_V1;
    pd_capitaldistribution_claim_V1_t capitaldistribution_claim_V1;
    pd_capitaldistribution_push_benefit_V1_t capitaldistribution_push_benefit_V1;
    pd_capitaldistribution_reclaim_V1_t capitaldistribution_reclaim_V1;
    pd_capitaldistribution_remove_distribution_V1_t capitaldistribution_remove_distribution_V1;
    pd_checkpoint_create_checkpoint_V1_t checkpoint_create_checkpoint_V1;
    pd_checkpoint_set_schedules_max_complexity_V1_t checkpoint_set_schedules_max_complexity_V1;
    pd_checkpoint_create_schedule_V1_t checkpoint_create_schedule_V1;
    pd_checkpoint_remove_schedule_V1_t checkpoint_remove_schedule_V1;
    pd_compliancemanager_add_compliance_requirement_V1_t compliancemanager_add_compliance_requirement_V1;
    pd_compliancemanager_remove_compliance_requirement_V1_t compliancemanager_remove_compliance_requirement_V1;
    pd_compliancemanager_replace_asset_compliance_V1_t compliancemanager_replace_asset_compliance_V1;
    pd_compliancemanager_reset_asset_compliance_V1_t compliancemanager_reset_asset_compliance_V1;
    pd_compliancemanager_pause_asset_compliance_V1_t compliancemanager_pause_asset_compliance_V1;
    pd_compliancemanager_resume_asset_compliance_V1_t compliancemanager_resume_asset_compliance_V1;
    pd_compliancemanager_add_default_trusted_claim_issuer_V1_t compliancemanager_add_default_trusted_claim_issuer_V1;
    pd_compliancemanager_remove_default_trusted_claim_issuer_V1_t compliancemanager_remove_default_trusted_claim_issuer_V1;
    pd_compliancemanager_change_compliance_requirement_V1_t compliancemanager_change_compliance_requirement_V1;
    pd_corporateaction_set_max_details_length_V1_t corporateaction_set_max_details_length_V1;
    pd_corporateaction_set_default_targets_V1_t corporateaction_set_default_targets_V1;
    pd_corporateaction_set_default_withholding_tax_V1_t corporateaction_set_default_withholding_tax_V1;
    pd_corporateaction_set_did_withholding_tax_V1_t corporateaction_set_did_withholding_tax_V1;
    pd_corporateaction_initiate_corporate_action_V1_t corporateaction_initiate_corporate_action_V1;
    pd_corporateaction_link_ca_doc_V1_t corporateaction_link_ca_doc_V1;
    pd_corporateaction_remove_ca_V1_t corporateaction_remove_ca_V1;
    pd_corporateaction_change_record_date_V1_t corporateaction_change_record_date_V1;
    pd_corporateballot_attach_ballot_V1_t corporateballot_attach_ballot_V1;
    pd_corporateballot_vote_V1_t corporateballot_vote_V1;
    pd_corporateballot_change_end_V1_t corporateballot_change_end_V1;
    pd_corporateballot_change_meta_V1_t corporateballot_change_meta_V1;
    pd_corporateballot_change_rcv_V1_t corporateballot_change_rcv_V1;
    pd_corporateballot_remove_ballot_V1_t corporateballot_remove_ballot_V1;
    pd_pips_set_prune_historical_pips_V1_t pips_set_prune_historical_pips_V1;
    pd_pips_set_min_proposal_deposit_V1_t pips_set_min_proposal_deposit_V1;
    pd_pips_set_default_enactment_period_V1_t pips_set_default_enactment_period_V1;
    pd_pips_set_pending_pip_expiry_V1_t pips_set_pending_pip_expiry_V1;
    pd_pips_set_max_pip_skip_count_V1_t pips_set_max_pip_skip_count_V1;
    pd_pips_set_active_pip_limit_V1_t pips_set_active_pip_limit_V1;
    pd_pips_approve_committee_proposal_V1_t pips_approve_committee_proposal_V1;
    pd_pips_reject_proposal_V1_t pips_reject_proposal_V1;
    pd_pips_prune_proposal_V1_t pips_prune_proposal_V1;
    pd_pips_reschedule_execution_V1_t pips_reschedule_execution_V1;
    pd_pips_clear_snapshot_V1_t pips_clear_snapshot_V1;
    pd_pips_snapshot_V1_t pips_snapshot_V1;
    pd_pips_enact_snapshot_results_V1_t pips_enact_snapshot_results_V1;
    pd_pips_execute_scheduled_pip_V1_t pips_execute_scheduled_pip_V1;
    pd_pips_expire_scheduled_pip_V1_t pips_expire_scheduled_pip_V1;
    pd_portfolio_create_portfolio_V1_t portfolio_create_portfolio_V1;
    pd_portfolio_delete_portfolio_V1_t portfolio_delete_portfolio_V1;
    pd_portfolio_move_portfolio_funds_V1_t portfolio_move_portfolio_funds_V1;
    pd_portfolio_rename_portfolio_V1_t portfolio_rename_portfolio_V1;
    pd_protocolfee_change_coefficient_V1_t protocolfee_change_coefficient_V1;
    pd_settlement_create_venue_V1_t settlement_create_venue_V1;
    pd_settlement_set_venue_filtering_V1_t settlement_set_venue_filtering_V1;
    pd_statistics_add_transfer_manager_V1_t statistics_add_transfer_manager_V1;
    pd_statistics_remove_transfer_manager_V1_t statistics_remove_transfer_manager_V1;
    pd_statistics_add_exempted_entities_V1_t statistics_add_exempted_entities_V1;
    pd_statistics_remove_exempted_entities_V1_t statistics_remove_exempted_entities_V1;
    pd_treasury_disbursement_V1_t treasury_disbursement_V1;
    pd_treasury_reimbursement_V1_t treasury_reimbursement_V1;
    pd_utility_relay_tx_V1_t utility_relay_tx_V1;
#endif
} pd_MethodNested_V1_t;

typedef union {
    pd_MethodBasic_V1_t basic;
    pd_MethodNested_V1_t nested;
} pd_Method_V1_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
