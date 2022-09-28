/*******************************************************************************
 *  (c) 2019 - 2022 Zondax AG
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
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

#define PD_CALL_SYSTEM_V3 0
#define PD_CALL_TIMESTAMP_V3 2
#define PD_CALL_INDICES_V3 3
#define PD_CALL_BALANCES_V3 5
#define PD_CALL_IDENTITY_V3 7
#define PD_CALL_CDDSERVICEPROVIDERS_V3 8
#define PD_CALL_POLYMESHCOMMITTEE_V3 9
#define PD_CALL_COMMITTEEMEMBERSHIP_V3 10
#define PD_CALL_TECHNICALCOMMITTEE_V3 11
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_V3 12
#define PD_CALL_UPGRADECOMMITTEE_V3 13
#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_V3 14
#define PD_CALL_MULTISIG_V3 15
#define PD_CALL_BRIDGE_V3 16
#define PD_CALL_STAKING_V3 17
#define PD_CALL_SESSION_V3 19
#define PD_CALL_GRANDPA_V3 21
#define PD_CALL_SUDO_V3 25
#define PD_CALL_ASSET_V3 26
#define PD_CALL_CAPITALDISTRIBUTION_V3 27
#define PD_CALL_CHECKPOINT_V3 28
#define PD_CALL_COMPLIANCEMANAGER_V3 29
#define PD_CALL_CORPORATEACTION_V3 30
#define PD_CALL_CORPORATEBALLOT_V3 31
#define PD_CALL_PIPS_V3 33
#define PD_CALL_PORTFOLIO_V3 34
#define PD_CALL_PROTOCOLFEE_V3 35
#define PD_CALL_SETTLEMENT_V3 37
#define PD_CALL_STO_V3 39
#define PD_CALL_TREASURY_V3 40
#define PD_CALL_UTILITY_V3 41
#define PD_CALL_EXTERNALAGENTS_V3 43
#define PD_CALL_RELAYER_V3 44
#define PD_CALL_REWARDS_V3 45
#define PD_CALL_CONTRACTS_V3 46
#define PD_CALL_POLYMESHCONTRACTS_V3 47
#define PD_CALL_PREIMAGE_V3 48

#ifdef SUBSTRATE_PARSER_FULL

#define PD_CALL_IDENTITY_PLACEHOLDER_LEGACY_SET_PERMISSION_TO_SIGNER_V3 10
typedef struct {
} pd_identity_placeholder_legacy_set_permission_to_signer_V3_t;

#define PD_CALL_IDENTITY_REVOKE_CLAIM_BY_INDEX_V3 20
typedef struct {
    pd_IdentityId_V3_t target;
    pd_ClaimType_V3_t claim_type;
    pd_OptionScope_V3_t scope;
} pd_identity_revoke_claim_by_index_V3_t;

#define PD_CALL_IDENTITY_ROTATE_PRIMARY_KEY_TO_SECONDARY_V3 21
typedef struct {
    pd_u64_t auth_id;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_identity_rotate_primary_key_to_secondary_V3_t;

#define PD_CALL_IDENTITY_SET_SECONDARY_KEY_PERMISSIONS_V3 23
typedef struct {
    pd_AccountId_V3_t key;
    pd_Permissions_V3_t perms;
} pd_identity_set_secondary_key_permissions_V3_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_SECONDARY_V3 16
typedef struct {
    pd_AccountId_V3_t multisig;
} pd_multisig_make_multisig_secondary_V3_t;

#define PD_CALL_BRIDGE_FORCE_HANDLE_BRIDGE_TX_V3 7
typedef struct {
    pd_BridgeTxAccountId_V3_t bridge_tx;
} pd_bridge_force_handle_bridge_tx_V3_t;

#define PD_CALL_BRIDGE_BATCH_PROPOSE_BRIDGE_TX_V3 8
typedef struct {
    pd_VecBridgeTxAccountId_V3_t bridge_txs;
} pd_bridge_batch_propose_bridge_tx_V3_t;

#define PD_CALL_BRIDGE_PROPOSE_BRIDGE_TX_V3 9
typedef struct {
    pd_BridgeTxAccountId_V3_t bridge_tx;
} pd_bridge_propose_bridge_tx_V3_t;

#define PD_CALL_BRIDGE_HANDLE_BRIDGE_TX_V3 10
typedef struct {
    pd_BridgeTxAccountId_V3_t bridge_tx;
} pd_bridge_handle_bridge_tx_V3_t;

#define PD_CALL_BRIDGE_FREEZE_TXS_V3 11
typedef struct {
    pd_VecBridgeTxAccountId_V3_t bridge_txs;
} pd_bridge_freeze_txs_V3_t;

#define PD_CALL_BRIDGE_UNFREEZE_TXS_V3 12
typedef struct {
    pd_VecBridgeTxAccountId_V3_t bridge_txs;
} pd_bridge_unfreeze_txs_V3_t;

#define PD_CALL_BRIDGE_HANDLE_SCHEDULED_BRIDGE_TX_V3 13
typedef struct {
    pd_BridgeTxAccountId_V3_t bridge_tx;
} pd_bridge_handle_scheduled_bridge_tx_V3_t;

#define PD_CALL_BRIDGE_ADD_FREEZE_ADMIN_V3 14
typedef struct {
    pd_AccountId_V3_t freeze_admin;
} pd_bridge_add_freeze_admin_V3_t;

#define PD_CALL_BRIDGE_REMOVE_FREEZE_ADMIN_V3 15
typedef struct {
    pd_AccountId_V3_t freeze_admin;
} pd_bridge_remove_freeze_admin_V3_t;

#define PD_CALL_BRIDGE_REMOVE_TXS_V3 16
typedef struct {
    pd_VecBridgeTxAccountId_V3_t bridge_txs;
} pd_bridge_remove_txs_V3_t;

#define PD_CALL_ASSET_CONTROLLER_TRANSFER_V3 16
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_BalanceNoSymbol_t amount;
    pd_PortfolioId_V3_t from_portfolio;
} pd_asset_controller_transfer_V3_t;

#define PD_CALL_ASSET_REGISTER_CUSTOM_ASSET_TYPE_V3 17
typedef struct {
    pd_Vecu8_t ty;
} pd_asset_register_custom_asset_type_V3_t;

#define PD_CALL_ASSET_CREATE_ASSET_WITH_CUSTOM_TYPE_V3 18
typedef struct {
    pd_AssetName_V3_t name;
    pd_Ticker_V3_t ticker;
    pd_bool_t divisible;
    pd_Vecu8_t custom_asset_type;
    pd_VecAssetIdentifier_V3_t identifiers;
    pd_OptionFundingRoundName_V3_t funding_round;
    pd_bool_t disable_iu;
} pd_asset_create_asset_with_custom_type_V3_t;

#define PD_CALL_ASSET_SET_ASSET_METADATA_V3 19
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_AssetMetadataKey_V3_t key;
    pd_AssetMetadataValue_V3_t value;
    pd_OptionAssetMetadataValueDetailMoment_V3_t detail;
} pd_asset_set_asset_metadata_V3_t;

#define PD_CALL_ASSET_SET_ASSET_METADATA_DETAILS_V3 20
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_AssetMetadataKey_V3_t key;
    pd_AssetMetadataValueDetailMoment_V3_t detail;
} pd_asset_set_asset_metadata_details_V3_t;

#define PD_CALL_ASSET_REGISTER_AND_SET_LOCAL_ASSET_METADATA_V3 21
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_AssetMetadataName_V3_t name;
    pd_AssetMetadataSpec_V3_t spec;
    pd_AssetMetadataValue_V3_t value;
    pd_OptionAssetMetadataValueDetailMoment_V3_t detail;
} pd_asset_register_and_set_local_asset_metadata_V3_t;

#define PD_CALL_ASSET_REGISTER_ASSET_METADATA_LOCAL_TYPE_V3 22
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_AssetMetadataName_V3_t name;
    pd_AssetMetadataSpec_V3_t spec;
} pd_asset_register_asset_metadata_local_type_V3_t;

#define PD_CALL_ASSET_REGISTER_ASSET_METADATA_GLOBAL_TYPE_V3 23
typedef struct {
    pd_AssetMetadataName_V3_t name;
    pd_AssetMetadataSpec_V3_t spec;
} pd_asset_register_asset_metadata_global_type_V3_t;

#define PD_CALL_PORTFOLIO_QUIT_PORTFOLIO_CUSTODY_V3 4
typedef struct {
    pd_PortfolioId_V3_t pid;
} pd_portfolio_quit_portfolio_custody_V3_t;

#define PD_CALL_PORTFOLIO_ACCEPT_PORTFOLIO_CUSTODY_V3 5
typedef struct {
    pd_u64_t auth_id;
} pd_portfolio_accept_portfolio_custody_V3_t;

#define PD_CALL_SETTLEMENT_UPDATE_VENUE_DETAILS_V3 1
typedef struct {
    pd_VenueId_V3_t id;
    pd_VenueDetails_V3_t details;
} pd_settlement_update_venue_details_V3_t;

#define PD_CALL_SETTLEMENT_UPDATE_VENUE_TYPE_V3 2
typedef struct {
    pd_VenueId_V3_t id;
    pd_VenueType_V3_t typ;
} pd_settlement_update_venue_type_V3_t;

#define PD_CALL_SETTLEMENT_CHANGE_RECEIPT_VALIDITY_V3 14
typedef struct {
    pd_u64_t receipt_uid;
    pd_bool_t validity;
} pd_settlement_change_receipt_validity_V3_t;

#define PD_CALL_SETTLEMENT_RESCHEDULE_INSTRUCTION_V3 16
typedef struct {
    pd_InstructionId_V3_t id;
} pd_settlement_reschedule_instruction_V3_t;

#define PD_CALL_STO_CREATE_FUNDRAISER_V3 0
typedef struct {
    pd_PortfolioId_V3_t offering_portfolio;
    pd_Ticker_V3_t offering_asset;
    pd_PortfolioId_V3_t raising_portfolio;
    pd_Ticker_V3_t raising_asset;
    pd_VecPriceTier_V3_t tiers;
    pd_VenueId_V3_t venue_id;
    pd_OptionMoment_V3_t start;
    pd_OptionMoment_V3_t end;
    pd_BalanceNoSymbol_t minimum_investment;
    pd_FundraiserName_V3_t fundraiser_name;
} pd_sto_create_fundraiser_V3_t;

#define PD_CALL_STO_INVEST_V3 1
typedef struct {
    pd_PortfolioId_V3_t investment_portfolio;
    pd_PortfolioId_V3_t funding_portfolio;
    pd_Ticker_V3_t offering_asset;
    pd_FundraiserId_V3_t id;
    pd_BalanceNoSymbol_t purchase_amount;
    pd_OptionBalance_t max_price;
    pd_OptionReceiptDetails_V3_t receipt;
} pd_sto_invest_V3_t;

#define PD_CALL_STO_FREEZE_FUNDRAISER_V3 2
typedef struct {
    pd_Ticker_V3_t offering_asset;
    pd_FundraiserId_V3_t id;
} pd_sto_freeze_fundraiser_V3_t;

#define PD_CALL_STO_UNFREEZE_FUNDRAISER_V3 3
typedef struct {
    pd_Ticker_V3_t offering_asset;
    pd_FundraiserId_V3_t id;
} pd_sto_unfreeze_fundraiser_V3_t;

#define PD_CALL_STO_MODIFY_FUNDRAISER_WINDOW_V3 4
typedef struct {
    pd_Ticker_V3_t offering_asset;
    pd_FundraiserId_V3_t id;
    pd_Moment_V3_t start;
    pd_OptionMoment_V3_t end;
} pd_sto_modify_fundraiser_window_V3_t;

#define PD_CALL_STO_STOP_V3 5
typedef struct {
    pd_Ticker_V3_t offering_asset;
    pd_FundraiserId_V3_t id;
} pd_sto_stop_V3_t;

#define PD_CALL_EXTERNALAGENTS_REMOVE_AGENT_V3 2
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_IdentityId_V3_t agent;
} pd_externalagents_remove_agent_V3_t;

#define PD_CALL_EXTERNALAGENTS_ABDICATE_V3 3
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_externalagents_abdicate_V3_t;

#define PD_CALL_EXTERNALAGENTS_ACCEPT_BECOME_AGENT_V3 5
typedef struct {
    pd_u64_t auth_id;
} pd_externalagents_accept_become_agent_V3_t;

#define PD_CALL_EXTERNALAGENTS_CREATE_GROUP_AND_ADD_AUTH_V3 6
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_ExtrinsicPermissions_V3_t perms;
    pd_IdentityId_V3_t target;
    pd_OptionMoment_V3_t expiry;
} pd_externalagents_create_group_and_add_auth_V3_t;

#define PD_CALL_EXTERNALAGENTS_CREATE_AND_CHANGE_CUSTOM_GROUP_V3 7
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_ExtrinsicPermissions_V3_t perms;
    pd_IdentityId_V3_t agent;
} pd_externalagents_create_and_change_custom_group_V3_t;

#define PD_CALL_RELAYER_SET_PAYING_KEY_V3 0
typedef struct {
    pd_AccountId_V3_t user_key;
    pd_Balance_t polyx_limit;
} pd_relayer_set_paying_key_V3_t;

#define PD_CALL_RELAYER_ACCEPT_PAYING_KEY_V3 1
typedef struct {
    pd_u64_t auth_id;
} pd_relayer_accept_paying_key_V3_t;

#define PD_CALL_RELAYER_REMOVE_PAYING_KEY_V3 2
typedef struct {
    pd_AccountId_V3_t user_key;
    pd_AccountId_V3_t paying_key;
} pd_relayer_remove_paying_key_V3_t;

#define PD_CALL_RELAYER_UPDATE_POLYX_LIMIT_V3 3
typedef struct {
    pd_AccountId_V3_t user_key;
    pd_Balance_t polyx_limit;
} pd_relayer_update_polyx_limit_V3_t;

#define PD_CALL_RELAYER_INCREASE_POLYX_LIMIT_V3 4
typedef struct {
    pd_AccountId_V3_t user_key;
    pd_Balance_t amount;
} pd_relayer_increase_polyx_limit_V3_t;

#define PD_CALL_RELAYER_DECREASE_POLYX_LIMIT_V3 5
typedef struct {
    pd_AccountId_V3_t user_key;
    pd_Balance_t amount;
} pd_relayer_decrease_polyx_limit_V3_t;

#define PD_CALL_REWARDS_CLAIM_ITN_REWARD_V3 0
typedef struct {
    pd_AccountId_V3_t reward_address;
    pd_AccountId_V3_t itn_address;
    pd_OffChainSignature_V3_t signature;
} pd_rewards_claim_itn_reward_V3_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_V3 1
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_V3_t;

#define PD_CALL_CONTRACTS_UPLOAD_CODE_V3 3
typedef struct {
    pd_Vecu8_t code;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
} pd_contracts_upload_code_V3_t;

#define PD_CALL_CONTRACTS_REMOVE_CODE_V3 4
typedef struct {
    pd_CodeHash_V3_t code_hash;
} pd_contracts_remove_code_V3_t;

#define PD_CALL_POLYMESHCONTRACTS_INSTANTIATE_WITH_CODE_PERMS_V3 0
typedef struct {
    pd_Balance_t endowment;
    pd_Weight_V3_t gas_limit;
    pd_OptionBalance_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
    pd_Permissions_V3_t perms;
} pd_polymeshcontracts_instantiate_with_code_perms_V3_t;

#define PD_CALL_POLYMESHCONTRACTS_INSTANTIATE_WITH_HASH_PERMS_V3 1
typedef struct {
    pd_Balance_t endowment;
    pd_Weight_V3_t gas_limit;
    pd_OptionBalance_t storage_deposit_limit;
    pd_CodeHash_V3_t code_hash;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
    pd_Permissions_V3_t perms;
} pd_polymeshcontracts_instantiate_with_hash_perms_V3_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V3 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V3_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V3 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V3_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V3 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V3_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V3 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V3_t;

#endif

typedef union {
#ifdef SUBSTRATE_PARSER_FULL
    pd_identity_placeholder_legacy_set_permission_to_signer_V3_t identity_placeholder_legacy_set_permission_to_signer_V3;
    pd_identity_revoke_claim_by_index_V3_t identity_revoke_claim_by_index_V3;
    pd_identity_rotate_primary_key_to_secondary_V3_t identity_rotate_primary_key_to_secondary_V3;
    pd_identity_set_secondary_key_permissions_V3_t identity_set_secondary_key_permissions_V3;
    pd_multisig_make_multisig_secondary_V3_t multisig_make_multisig_secondary_V3;
    pd_bridge_force_handle_bridge_tx_V3_t bridge_force_handle_bridge_tx_V3;
    pd_bridge_batch_propose_bridge_tx_V3_t bridge_batch_propose_bridge_tx_V3;
    pd_bridge_propose_bridge_tx_V3_t bridge_propose_bridge_tx_V3;
    pd_bridge_handle_bridge_tx_V3_t bridge_handle_bridge_tx_V3;
    pd_bridge_freeze_txs_V3_t bridge_freeze_txs_V3;
    pd_bridge_unfreeze_txs_V3_t bridge_unfreeze_txs_V3;
    pd_bridge_handle_scheduled_bridge_tx_V3_t bridge_handle_scheduled_bridge_tx_V3;
    pd_bridge_add_freeze_admin_V3_t bridge_add_freeze_admin_V3;
    pd_bridge_remove_freeze_admin_V3_t bridge_remove_freeze_admin_V3;
    pd_bridge_remove_txs_V3_t bridge_remove_txs_V3;
    pd_asset_controller_transfer_V3_t asset_controller_transfer_V3;
    pd_asset_register_custom_asset_type_V3_t asset_register_custom_asset_type_V3;
    pd_asset_create_asset_with_custom_type_V3_t asset_create_asset_with_custom_type_V3;
    pd_asset_set_asset_metadata_V3_t asset_set_asset_metadata_V3;
    pd_asset_set_asset_metadata_details_V3_t asset_set_asset_metadata_details_V3;
    pd_asset_register_and_set_local_asset_metadata_V3_t asset_register_and_set_local_asset_metadata_V3;
    pd_asset_register_asset_metadata_local_type_V3_t asset_register_asset_metadata_local_type_V3;
    pd_asset_register_asset_metadata_global_type_V3_t asset_register_asset_metadata_global_type_V3;
    pd_portfolio_quit_portfolio_custody_V3_t portfolio_quit_portfolio_custody_V3;
    pd_portfolio_accept_portfolio_custody_V3_t portfolio_accept_portfolio_custody_V3;
    pd_settlement_update_venue_details_V3_t settlement_update_venue_details_V3;
    pd_settlement_update_venue_type_V3_t settlement_update_venue_type_V3;
    pd_settlement_change_receipt_validity_V3_t settlement_change_receipt_validity_V3;
    pd_settlement_reschedule_instruction_V3_t settlement_reschedule_instruction_V3;
    pd_sto_create_fundraiser_V3_t sto_create_fundraiser_V3;
    pd_sto_invest_V3_t sto_invest_V3;
    pd_sto_freeze_fundraiser_V3_t sto_freeze_fundraiser_V3;
    pd_sto_unfreeze_fundraiser_V3_t sto_unfreeze_fundraiser_V3;
    pd_sto_modify_fundraiser_window_V3_t sto_modify_fundraiser_window_V3;
    pd_sto_stop_V3_t sto_stop_V3;
    pd_externalagents_remove_agent_V3_t externalagents_remove_agent_V3;
    pd_externalagents_abdicate_V3_t externalagents_abdicate_V3;
    pd_externalagents_accept_become_agent_V3_t externalagents_accept_become_agent_V3;
    pd_externalagents_create_group_and_add_auth_V3_t externalagents_create_group_and_add_auth_V3;
    pd_externalagents_create_and_change_custom_group_V3_t externalagents_create_and_change_custom_group_V3;
    pd_relayer_set_paying_key_V3_t relayer_set_paying_key_V3;
    pd_relayer_accept_paying_key_V3_t relayer_accept_paying_key_V3;
    pd_relayer_remove_paying_key_V3_t relayer_remove_paying_key_V3;
    pd_relayer_update_polyx_limit_V3_t relayer_update_polyx_limit_V3;
    pd_relayer_increase_polyx_limit_V3_t relayer_increase_polyx_limit_V3;
    pd_relayer_decrease_polyx_limit_V3_t relayer_decrease_polyx_limit_V3;
    pd_rewards_claim_itn_reward_V3_t rewards_claim_itn_reward_V3;
    pd_contracts_instantiate_with_code_V3_t contracts_instantiate_with_code_V3;
    pd_contracts_upload_code_V3_t contracts_upload_code_V3;
    pd_contracts_remove_code_V3_t contracts_remove_code_V3;
    pd_polymeshcontracts_instantiate_with_code_perms_V3_t polymeshcontracts_instantiate_with_code_perms_V3;
    pd_polymeshcontracts_instantiate_with_hash_perms_V3_t polymeshcontracts_instantiate_with_hash_perms_V3;
    pd_preimage_note_preimage_V3_t preimage_note_preimage_V3;
    pd_preimage_unnote_preimage_V3_t preimage_unnote_preimage_V3;
    pd_preimage_request_preimage_V3_t preimage_request_preimage_V3;
    pd_preimage_unrequest_preimage_V3_t preimage_unrequest_preimage_V3;
#endif
} pd_MethodBasic_V3_t;

#define PD_CALL_BALANCES_TRANSFER_V3 0
typedef struct {
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V3_t;

#define PD_CALL_BALANCES_TRANSFER_WITH_MEMO_V3 1
typedef struct {
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t amount;
    pd_OptionMemo_V3_t memo;
} pd_balances_transfer_with_memo_V3_t;

#define PD_CALL_IDENTITY_ACCEPT_PRIMARY_KEY_V3 3
typedef struct {
    pd_u64_t rotation_auth_id;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_identity_accept_primary_key_V3_t;

#define PD_CALL_IDENTITY_JOIN_IDENTITY_AS_KEY_V3 5
typedef struct {
    pd_u64_t auth_id;
} pd_identity_join_identity_as_key_V3_t;

#define PD_CALL_IDENTITY_LEAVE_IDENTITY_AS_KEY_V3 6
typedef struct {
} pd_identity_leave_identity_as_key_V3_t;

#define PD_CALL_IDENTITY_ADD_CLAIM_V3 7
typedef struct {
    pd_IdentityId_V3_t target;
    pd_Claim_V3_t claim;
    pd_OptionMoment_V3_t expiry;
} pd_identity_add_claim_V3_t;

#define PD_CALL_IDENTITY_REVOKE_CLAIM_V3 8
typedef struct {
    pd_IdentityId_V3_t target;
    pd_Claim_V3_t claim;
} pd_identity_revoke_claim_V3_t;

#define PD_CALL_IDENTITY_SET_PERMISSION_TO_SIGNER_V3 9
typedef struct {
    pd_SignatoryAccountId_V3_t key;
    pd_Permissions_V3_t perms;
} pd_identity_set_permission_to_signer_V3_t;

#define PD_CALL_IDENTITY_FREEZE_SECONDARY_KEYS_V3 11
typedef struct {
} pd_identity_freeze_secondary_keys_V3_t;

#define PD_CALL_IDENTITY_UNFREEZE_SECONDARY_KEYS_V3 12
typedef struct {
} pd_identity_unfreeze_secondary_keys_V3_t;

#define PD_CALL_IDENTITY_ADD_AUTHORIZATION_V3 13
typedef struct {
    pd_SignatoryAccountId_V3_t target;
    pd_AuthorizationDataAccountId_V3_t data;
    pd_OptionMoment_V3_t expiry;
} pd_identity_add_authorization_V3_t;

#define PD_CALL_IDENTITY_REMOVE_AUTHORIZATION_V3 14
typedef struct {
    pd_SignatoryAccountId_V3_t target;
    pd_u64_t auth_id;
    pd_bool_t _auth_issuer_pays;
} pd_identity_remove_authorization_V3_t;

#define PD_CALL_IDENTITY_ADD_INVESTOR_UNIQUENESS_CLAIM_V3 16
typedef struct {
    pd_IdentityId_V3_t target;
    pd_Claim_V3_t claim;
    pd_InvestorZKProofData_V3_t proof;
    pd_OptionMoment_V3_t expiry;
} pd_identity_add_investor_uniqueness_claim_V3_t;

#define PD_CALL_IDENTITY_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION_V3 22
typedef struct {
    pd_VecSecondaryKeyWithAuthAccountId_V3_t additional_keys;
    pd_Moment_V3_t expires_at;
} pd_identity_add_secondary_keys_with_authorization_V3_t;

#define PD_CALL_IDENTITY_REMOVE_SECONDARY_KEYS_V3 24
typedef struct {
    pd_VecAccountId_V3_t keys_to_remove;
} pd_identity_remove_secondary_keys_V3_t;

#define PD_CALL_MULTISIG_CREATE_MULTISIG_V3 0
typedef struct {
    pd_VecSignatoryAccountId_V3_t signers;
    pd_u64_t sigs_required;
} pd_multisig_create_multisig_V3_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY_V3 1
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V3_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_identity_V3_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_KEY_V3 2
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V3_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_key_V3_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_IDENTITY_V3 3
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V3_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_identity_V3_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_KEY_V3 4
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_V3_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_key_V3_t;

#define PD_CALL_MULTISIG_APPROVE_AS_IDENTITY_V3 5
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_identity_V3_t;

#define PD_CALL_MULTISIG_APPROVE_AS_KEY_V3 6
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_key_V3_t;

#define PD_CALL_MULTISIG_REJECT_AS_IDENTITY_V3 7
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_identity_V3_t;

#define PD_CALL_MULTISIG_REJECT_AS_KEY_V3 8
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_key_V3_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY_V3 9
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_identity_V3_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_KEY_V3 10
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_key_V3_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNER_V3 11
typedef struct {
    pd_SignatoryAccountId_V3_t signer;
} pd_multisig_add_multisig_signer_V3_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNER_V3 12
typedef struct {
    pd_SignatoryAccountId_V3_t signer;
} pd_multisig_remove_multisig_signer_V3_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNERS_VIA_CREATOR_V3 13
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_VecSignatoryAccountId_V3_t signers;
} pd_multisig_add_multisig_signers_via_creator_V3_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR_V3 14
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_VecSignatoryAccountId_V3_t signers;
} pd_multisig_remove_multisig_signers_via_creator_V3_t;

#define PD_CALL_MULTISIG_CHANGE_SIGS_REQUIRED_V3 15
typedef struct {
    pd_u64_t sigs_required;
} pd_multisig_change_sigs_required_V3_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_PRIMARY_V3 17
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_multisig_make_multisig_primary_V3_t;

#define PD_CALL_MULTISIG_EXECUTE_SCHEDULED_PROPOSAL_V3 18
typedef struct {
    pd_AccountId_V3_t multisig;
    pd_u64_t proposal_id;
    pd_IdentityId_V3_t multisig_did;
    pd_Weight_V3_t _proposal_weight;
} pd_multisig_execute_scheduled_proposal_V3_t;

#define PD_CALL_STAKING_BOND_V3 0
typedef struct {
    pd_LookupasStaticLookupSource_V3_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_V3_t payee;
} pd_staking_bond_V3_t;

#define PD_CALL_STAKING_BOND_EXTRA_V3 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V3_t;

#define PD_CALL_STAKING_UNBOND_V3 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V3_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V3 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V3_t;

#define PD_CALL_STAKING_VALIDATE_V3 4
typedef struct {
    pd_ValidatorPrefs_V3_t prefs;
} pd_staking_validate_V3_t;

#define PD_CALL_STAKING_NOMINATE_V3 5
typedef struct {
    pd_VecLookupasStaticLookupSource_V3_t targets;
} pd_staking_nominate_V3_t;

#define PD_CALL_STAKING_CHILL_V3 6
typedef struct {
} pd_staking_chill_V3_t;

#define PD_CALL_STAKING_SET_PAYEE_V3 7
typedef struct {
    pd_RewardDestination_V3_t payee;
} pd_staking_set_payee_V3_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V3 8
typedef struct {
    pd_LookupasStaticLookupSource_V3_t controller;
} pd_staking_set_controller_V3_t;

#define PD_CALL_STAKING_REBOND_V3 24
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V3_t;

#define PD_CALL_PIPS_PROPOSE_V3 6
typedef struct {
    pd_Proposal_t proposal;
    pd_Balance_t deposit;
    pd_OptionUrl_V3_t url;
    pd_OptionPipDescription_V3_t description;
} pd_pips_propose_V3_t;

#define PD_CALL_PIPS_VOTE_V3 7
typedef struct {
    pd_PipId_V3_t id;
    pd_bool_t aye_or_nay;
    pd_Balance_t deposit;
} pd_pips_vote_V3_t;

#define PD_CALL_UTILITY_BATCH_V3 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V3_t;

#define PD_CALL_UTILITY_BATCH_ATOMIC_V3 1
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_atomic_V3_t;

#define PD_CALL_UTILITY_BATCH_OPTIMISTIC_V3 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_optimistic_V3_t;

#ifdef SUBSTRATE_PARSER_FULL
#define PD_CALL_SYSTEM_FILL_BLOCK_V3 0
typedef struct {
    pd_Perbill_V3_t ratio;
} pd_system_fill_block_V3_t;

#define PD_CALL_SYSTEM_REMARK_V3 1
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_V3_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V3 2
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_V3 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V3_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V3 4
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V3_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V3 8
typedef struct {
    pd_Vecu8_t remark;
} pd_system_remark_with_event_V3_t;

#define PD_CALL_TIMESTAMP_SET_V3 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V3_t;

#define PD_CALL_INDICES_CLAIM_V3 0
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_claim_V3_t;

#define PD_CALL_INDICES_TRANSFER_V3 1
typedef struct {
    pd_AccountId_V3_t new_;
    pd_AccountIndex_V3_t index;
} pd_indices_transfer_V3_t;

#define PD_CALL_INDICES_FREE_V3 2
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_free_V3_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V3 3
typedef struct {
    pd_AccountId_V3_t new_;
    pd_AccountIndex_V3_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V3_t;

#define PD_CALL_INDICES_FREEZE_V3 4
typedef struct {
    pd_AccountIndex_V3_t index;
} pd_indices_freeze_V3_t;

#define PD_CALL_BALANCES_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE_V3 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_balances_deposit_block_reward_reserve_balance_V3_t;

#define PD_CALL_BALANCES_SET_BALANCE_V3 3
typedef struct {
    pd_LookupasStaticLookupSource_V3_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V3_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V3 4
typedef struct {
    pd_LookupasStaticLookupSource_V3_t source;
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V3_t;

#define PD_CALL_BALANCES_BURN_ACCOUNT_BALANCE_V3 5
typedef struct {
    pd_Balance_t amount;
} pd_balances_burn_account_balance_V3_t;

#define PD_CALL_IDENTITY_INVALIDATE_CDD_CLAIMS_V3 1
typedef struct {
    pd_IdentityId_V3_t cdd;
    pd_Moment_V3_t disable_from;
    pd_OptionMoment_V3_t expiry;
} pd_identity_invalidate_cdd_claims_V3_t;

#define PD_CALL_IDENTITY_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION_V3 4
typedef struct {
    pd_bool_t auth_required;
} pd_identity_change_cdd_requirement_for_mk_rotation_V3_t;

#define PD_CALL_IDENTITY_GC_ADD_CDD_CLAIM_V3 17
typedef struct {
    pd_IdentityId_V3_t target;
} pd_identity_gc_add_cdd_claim_V3_t;

#define PD_CALL_IDENTITY_GC_REVOKE_CDD_CLAIM_V3 18
typedef struct {
    pd_IdentityId_V3_t target;
} pd_identity_gc_revoke_cdd_claim_V3_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SET_ACTIVE_MEMBERS_LIMIT_V3 0
typedef struct {
    pd_MemberCount_V3_t limit;
} pd_cddserviceproviders_set_active_members_limit_V3_t;

#define PD_CALL_CDDSERVICEPROVIDERS_DISABLE_MEMBER_V3 1
typedef struct {
    pd_IdentityId_V3_t who;
    pd_OptionMoment_V3_t expiry;
    pd_OptionMoment_V3_t at;
} pd_cddserviceproviders_disable_member_V3_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ADD_MEMBER_V3 2
typedef struct {
    pd_IdentityId_V3_t who;
} pd_cddserviceproviders_add_member_V3_t;

#define PD_CALL_CDDSERVICEPROVIDERS_REMOVE_MEMBER_V3 3
typedef struct {
    pd_IdentityId_V3_t who;
} pd_cddserviceproviders_remove_member_V3_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SWAP_MEMBER_V3 4
typedef struct {
    pd_IdentityId_V3_t remove;
    pd_IdentityId_V3_t add;
} pd_cddserviceproviders_swap_member_V3_t;

#define PD_CALL_CDDSERVICEPROVIDERS_RESET_MEMBERS_V3 5
typedef struct {
    pd_VecIdentityId_V3_t members;
} pd_cddserviceproviders_reset_members_V3_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ABDICATE_MEMBERSHIP_V3 6
typedef struct {
} pd_cddserviceproviders_abdicate_membership_V3_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_VOTE_THRESHOLD_V3 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_polymeshcommittee_set_vote_threshold_V3_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_RELEASE_COORDINATOR_V3 1
typedef struct {
    pd_IdentityId_V3_t id;
} pd_polymeshcommittee_set_release_coordinator_V3_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_EXPIRES_AFTER_V3 2
typedef struct {
    pd_MaybeBlockBlockNumber_V3_t expiry;
} pd_polymeshcommittee_set_expires_after_V3_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_OR_PROPOSE_V3 3
typedef struct {
    pd_bool_t approve;
    pd_Call_t call;
} pd_polymeshcommittee_vote_or_propose_V3_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_V3 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_polymeshcommittee_vote_V3_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V3 0
typedef struct {
    pd_MemberCount_V3_t limit;
} pd_committeemembership_set_active_members_limit_V3_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_DISABLE_MEMBER_V3 1
typedef struct {
    pd_IdentityId_V3_t who;
    pd_OptionMoment_V3_t expiry;
    pd_OptionMoment_V3_t at;
} pd_committeemembership_disable_member_V3_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ADD_MEMBER_V3 2
typedef struct {
    pd_IdentityId_V3_t who;
} pd_committeemembership_add_member_V3_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_REMOVE_MEMBER_V3 3
typedef struct {
    pd_IdentityId_V3_t who;
} pd_committeemembership_remove_member_V3_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SWAP_MEMBER_V3 4
typedef struct {
    pd_IdentityId_V3_t remove;
    pd_IdentityId_V3_t add;
} pd_committeemembership_swap_member_V3_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_RESET_MEMBERS_V3 5
typedef struct {
    pd_VecIdentityId_V3_t members;
} pd_committeemembership_reset_members_V3_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V3 6
typedef struct {
} pd_committeemembership_abdicate_membership_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_VOTE_THRESHOLD_V3 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_technicalcommittee_set_vote_threshold_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_RELEASE_COORDINATOR_V3 1
typedef struct {
    pd_IdentityId_V3_t id;
} pd_technicalcommittee_set_release_coordinator_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_EXPIRES_AFTER_V3 2
typedef struct {
    pd_MaybeBlockBlockNumber_V3_t expiry;
} pd_technicalcommittee_set_expires_after_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_OR_PROPOSE_V3 3
typedef struct {
    pd_bool_t approve;
    pd_Call_t call;
} pd_technicalcommittee_vote_or_propose_V3_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V3 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V3_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V3 0
typedef struct {
    pd_MemberCount_V3_t limit;
} pd_technicalcommitteemembership_set_active_members_limit_V3_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V3 1
typedef struct {
    pd_IdentityId_V3_t who;
    pd_OptionMoment_V3_t expiry;
    pd_OptionMoment_V3_t at;
} pd_technicalcommitteemembership_disable_member_V3_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER_V3 2
typedef struct {
    pd_IdentityId_V3_t who;
} pd_technicalcommitteemembership_add_member_V3_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V3 3
typedef struct {
    pd_IdentityId_V3_t who;
} pd_technicalcommitteemembership_remove_member_V3_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER_V3 4
typedef struct {
    pd_IdentityId_V3_t remove;
    pd_IdentityId_V3_t add;
} pd_technicalcommitteemembership_swap_member_V3_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS_V3 5
typedef struct {
    pd_VecIdentityId_V3_t members;
} pd_technicalcommitteemembership_reset_members_V3_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V3 6
typedef struct {
} pd_technicalcommitteemembership_abdicate_membership_V3_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_VOTE_THRESHOLD_V3 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_upgradecommittee_set_vote_threshold_V3_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_RELEASE_COORDINATOR_V3 1
typedef struct {
    pd_IdentityId_V3_t id;
} pd_upgradecommittee_set_release_coordinator_V3_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_EXPIRES_AFTER_V3 2
typedef struct {
    pd_MaybeBlockBlockNumber_V3_t expiry;
} pd_upgradecommittee_set_expires_after_V3_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_OR_PROPOSE_V3 3
typedef struct {
    pd_bool_t approve;
    pd_Call_t call;
} pd_upgradecommittee_vote_or_propose_V3_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_V3 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_V3_t index;
    pd_bool_t approve;
} pd_upgradecommittee_vote_V3_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V3 0
typedef struct {
    pd_MemberCount_V3_t limit;
} pd_upgradecommitteemembership_set_active_members_limit_V3_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V3 1
typedef struct {
    pd_IdentityId_V3_t who;
    pd_OptionMoment_V3_t expiry;
    pd_OptionMoment_V3_t at;
} pd_upgradecommitteemembership_disable_member_V3_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ADD_MEMBER_V3 2
typedef struct {
    pd_IdentityId_V3_t who;
} pd_upgradecommitteemembership_add_member_V3_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V3 3
typedef struct {
    pd_IdentityId_V3_t who;
} pd_upgradecommitteemembership_remove_member_V3_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SWAP_MEMBER_V3 4
typedef struct {
    pd_IdentityId_V3_t remove;
    pd_IdentityId_V3_t add;
} pd_upgradecommitteemembership_swap_member_V3_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_RESET_MEMBERS_V3 5
typedef struct {
    pd_VecIdentityId_V3_t members;
} pd_upgradecommitteemembership_reset_members_V3_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V3 6
typedef struct {
} pd_upgradecommitteemembership_abdicate_membership_V3_t;

#define PD_CALL_BRIDGE_CHANGE_CONTROLLER_V3 0
typedef struct {
    pd_AccountId_V3_t controller;
} pd_bridge_change_controller_V3_t;

#define PD_CALL_BRIDGE_CHANGE_ADMIN_V3 1
typedef struct {
    pd_AccountId_V3_t admin;
} pd_bridge_change_admin_V3_t;

#define PD_CALL_BRIDGE_CHANGE_TIMELOCK_V3 2
typedef struct {
    pd_BlockNumber_t timelock;
} pd_bridge_change_timelock_V3_t;

#define PD_CALL_BRIDGE_FREEZE_V3 3
typedef struct {
} pd_bridge_freeze_V3_t;

#define PD_CALL_BRIDGE_UNFREEZE_V3 4
typedef struct {
} pd_bridge_unfreeze_V3_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_LIMIT_V3 5
typedef struct {
    pd_Balance_t amount;
    pd_BlockNumber_t duration;
} pd_bridge_change_bridge_limit_V3_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_EXEMPTED_V3 6
typedef struct {
    pd_VecTupleIdentityIdbool_V3_t exempted;
} pd_bridge_change_bridge_exempted_V3_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V3 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V3_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V3 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V3_t;

#define PD_CALL_STAKING_ADD_PERMISSIONED_VALIDATOR_V3 12
typedef struct {
    pd_IdentityId_V3_t identity;
    pd_Optionu32_t intended_count;
} pd_staking_add_permissioned_validator_V3_t;

#define PD_CALL_STAKING_REMOVE_PERMISSIONED_VALIDATOR_V3 13
typedef struct {
    pd_IdentityId_V3_t identity;
} pd_staking_remove_permissioned_validator_V3_t;

#define PD_CALL_STAKING_VALIDATE_CDD_EXPIRY_NOMINATORS_V3 14
typedef struct {
    pd_VecAccountId_V3_t targets;
} pd_staking_validate_cdd_expiry_nominators_V3_t;

#define PD_CALL_STAKING_SET_COMMISSION_CAP_V3 15
typedef struct {
    pd_Perbill_V3_t new_cap;
} pd_staking_set_commission_cap_V3_t;

#define PD_CALL_STAKING_SET_MIN_BOND_THRESHOLD_V3 16
typedef struct {
    pd_Balance_t new_value;
} pd_staking_set_min_bond_threshold_V3_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V3 17
typedef struct {
} pd_staking_force_no_eras_V3_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V3 18
typedef struct {
} pd_staking_force_new_era_V3_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V3 19
typedef struct {
    pd_VecAccountId_V3_t invulnerables;
} pd_staking_set_invulnerables_V3_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V3 20
typedef struct {
    pd_AccountId_V3_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V3_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V3 21
typedef struct {
} pd_staking_force_new_era_always_V3_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V3 22
typedef struct {
    pd_EraIndex_V3_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V3_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V3 23
typedef struct {
    pd_AccountId_V3_t validator_stash;
    pd_EraIndex_V3_t era;
} pd_staking_payout_stakers_V3_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V3 25
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V3_t;

#define PD_CALL_STAKING_REAP_STASH_V3 26
typedef struct {
    pd_AccountId_V3_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V3_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_SYSTEM_V3 29
typedef struct {
    pd_AccountId_V3_t validator_stash;
    pd_EraIndex_V3_t era;
} pd_staking_payout_stakers_by_system_V3_t;

#define PD_CALL_STAKING_CHANGE_SLASHING_ALLOWED_FOR_V3 30
typedef struct {
    pd_SlashingSwitch_V3_t slashing_switch;
} pd_staking_change_slashing_allowed_for_V3_t;

#define PD_CALL_STAKING_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT_V3 31
typedef struct {
    pd_IdentityId_V3_t identity;
    pd_u32_t new_intended_count;
} pd_staking_update_permissioned_validator_intended_count_V3_t;

#define PD_CALL_SESSION_SET_KEYS_V3 0
typedef struct {
    pd_Keys_V3_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V3_t;

#define PD_CALL_SESSION_PURGE_KEYS_V3 1
typedef struct {
} pd_session_purge_keys_V3_t;

#define PD_CALL_GRANDPA_NOTE_STALLED_V3 2
typedef struct {
    pd_BlockNumber_t delay;
    pd_BlockNumber_t best_finalized_block_number;
} pd_grandpa_note_stalled_V3_t;

#define PD_CALL_SUDO_SUDO_AS_V3 3
typedef struct {
    pd_LookupasStaticLookupSource_V3_t who;
    pd_Call_t call;
} pd_sudo_sudo_as_V3_t;

#define PD_CALL_ASSET_REGISTER_TICKER_V3 0
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_asset_register_ticker_V3_t;

#define PD_CALL_ASSET_ACCEPT_TICKER_TRANSFER_V3 1
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_ticker_transfer_V3_t;

#define PD_CALL_ASSET_ACCEPT_ASSET_OWNERSHIP_TRANSFER_V3 2
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_asset_ownership_transfer_V3_t;

#define PD_CALL_ASSET_CREATE_ASSET_V3 3
typedef struct {
    pd_AssetName_V3_t name;
    pd_Ticker_V3_t ticker;
    pd_bool_t divisible;
    pd_AssetType_V3_t asset_type;
    pd_VecAssetIdentifier_V3_t identifiers;
    pd_OptionFundingRoundName_V3_t funding_round;
    pd_bool_t disable_iu;
} pd_asset_create_asset_V3_t;

#define PD_CALL_ASSET_FREEZE_V3 4
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_asset_freeze_V3_t;

#define PD_CALL_ASSET_UNFREEZE_V3 5
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_asset_unfreeze_V3_t;

#define PD_CALL_ASSET_RENAME_ASSET_V3 6
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_AssetName_V3_t name;
} pd_asset_rename_asset_V3_t;

#define PD_CALL_ASSET_ISSUE_V3 7
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_BalanceNoSymbol_t amount;
} pd_asset_issue_V3_t;

#define PD_CALL_ASSET_REDEEM_V3 8
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_BalanceNoSymbol_t amount;
} pd_asset_redeem_V3_t;

#define PD_CALL_ASSET_MAKE_DIVISIBLE_V3 9
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_asset_make_divisible_V3_t;

#define PD_CALL_ASSET_ADD_DOCUMENTS_V3 10
typedef struct {
    pd_VecDocument_V3_t docs;
    pd_Ticker_V3_t ticker;
} pd_asset_add_documents_V3_t;

#define PD_CALL_ASSET_REMOVE_DOCUMENTS_V3 11
typedef struct {
    pd_VecDocumentId_V3_t ids;
    pd_Ticker_V3_t ticker;
} pd_asset_remove_documents_V3_t;

#define PD_CALL_ASSET_SET_FUNDING_ROUND_V3 12
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_FundingRoundName_V3_t name;
} pd_asset_set_funding_round_V3_t;

#define PD_CALL_ASSET_UPDATE_IDENTIFIERS_V3 13
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_VecAssetIdentifier_V3_t identifiers;
} pd_asset_update_identifiers_V3_t;

#define PD_CALL_ASSET_CLAIM_CLASSIC_TICKER_V3 14
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_EcdsaSignature_V3_t ethereum_signature;
} pd_asset_claim_classic_ticker_V3_t;

#define PD_CALL_ASSET_RESERVE_CLASSIC_TICKER_V3 15
typedef struct {
    pd_ClassicTickerImport_V3_t classic_ticker_import;
    pd_IdentityId_V3_t contract_did;
    pd_TickerRegistrationConfigMoment_V3_t config;
} pd_asset_reserve_classic_ticker_V3_t;

#define PD_CALL_CAPITALDISTRIBUTION_DISTRIBUTE_V3 0
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_OptionPortfolioNumber_V3_t portfolio;
    pd_Ticker_V3_t currency;
    pd_Balance_t per_share;
    pd_Balance_t amount;
    pd_Moment_V3_t payment_at;
    pd_OptionMoment_V3_t expires_at;
} pd_capitaldistribution_distribute_V3_t;

#define PD_CALL_CAPITALDISTRIBUTION_CLAIM_V3 1
typedef struct {
    pd_CAId_V3_t ca_id;
} pd_capitaldistribution_claim_V3_t;

#define PD_CALL_CAPITALDISTRIBUTION_PUSH_BENEFIT_V3 2
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_IdentityId_V3_t holder;
} pd_capitaldistribution_push_benefit_V3_t;

#define PD_CALL_CAPITALDISTRIBUTION_RECLAIM_V3 3
typedef struct {
    pd_CAId_V3_t ca_id;
} pd_capitaldistribution_reclaim_V3_t;

#define PD_CALL_CAPITALDISTRIBUTION_REMOVE_DISTRIBUTION_V3 4
typedef struct {
    pd_CAId_V3_t ca_id;
} pd_capitaldistribution_remove_distribution_V3_t;

#define PD_CALL_CHECKPOINT_CREATE_CHECKPOINT_V3 0
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_checkpoint_create_checkpoint_V3_t;

#define PD_CALL_CHECKPOINT_SET_SCHEDULES_MAX_COMPLEXITY_V3 1
typedef struct {
    pd_u64_t max_complexity;
} pd_checkpoint_set_schedules_max_complexity_V3_t;

#define PD_CALL_CHECKPOINT_CREATE_SCHEDULE_V3 2
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_ScheduleSpec_V3_t schedule;
} pd_checkpoint_create_schedule_V3_t;

#define PD_CALL_CHECKPOINT_REMOVE_SCHEDULE_V3 3
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_ScheduleId_V3_t id;
} pd_checkpoint_remove_schedule_V3_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_COMPLIANCE_REQUIREMENT_V3 0
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_VecCondition_V3_t sender_conditions;
    pd_VecCondition_V3_t receiver_conditions;
} pd_compliancemanager_add_compliance_requirement_V3_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_COMPLIANCE_REQUIREMENT_V3 1
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_u32_t id;
} pd_compliancemanager_remove_compliance_requirement_V3_t;

#define PD_CALL_COMPLIANCEMANAGER_RESET_ASSET_COMPLIANCE_V3 3
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_compliancemanager_reset_asset_compliance_V3_t;

#define PD_CALL_COMPLIANCEMANAGER_PAUSE_ASSET_COMPLIANCE_V3 4
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_compliancemanager_pause_asset_compliance_V3_t;

#define PD_CALL_COMPLIANCEMANAGER_RESUME_ASSET_COMPLIANCE_V3 5
typedef struct {
    pd_Ticker_V3_t ticker;
} pd_compliancemanager_resume_asset_compliance_V3_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER_V3 6
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_TrustedIssuer_V3_t issuer;
} pd_compliancemanager_add_default_trusted_claim_issuer_V3_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER_V3 7
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_IdentityId_V3_t issuer;
} pd_compliancemanager_remove_default_trusted_claim_issuer_V3_t;

#define PD_CALL_CORPORATEACTION_SET_MAX_DETAILS_LENGTH_V3 0
typedef struct {
    pd_u32_t length;
} pd_corporateaction_set_max_details_length_V3_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_TARGETS_V3 1
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_TargetIdentities_V3_t targets;
} pd_corporateaction_set_default_targets_V3_t;

#define PD_CALL_CORPORATEACTION_SET_DEFAULT_WITHHOLDING_TAX_V3 2
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_Tax_V3_t tax;
} pd_corporateaction_set_default_withholding_tax_V3_t;

#define PD_CALL_CORPORATEACTION_SET_DID_WITHHOLDING_TAX_V3 3
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_IdentityId_V3_t taxed_did;
    pd_OptionTax_V3_t tax;
} pd_corporateaction_set_did_withholding_tax_V3_t;

#define PD_CALL_CORPORATEACTION_INITIATE_CORPORATE_ACTION_V3 4
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_CAKind_V3_t kind;
    pd_Moment_V3_t decl_date;
    pd_OptionRecordDateSpec_V3_t record_date;
    pd_CADetails_V3_t details;
    pd_OptionTargetIdentities_V3_t targets;
    pd_OptionTax_V3_t default_withholding_tax;
    pd_OptionVecTupleIdentityIdTax_V3_t withholding_tax;
} pd_corporateaction_initiate_corporate_action_V3_t;

#define PD_CALL_CORPORATEACTION_LINK_CA_DOC_V3 5
typedef struct {
    pd_CAId_V3_t id;
    pd_VecDocumentId_V3_t docs;
} pd_corporateaction_link_ca_doc_V3_t;

#define PD_CALL_CORPORATEACTION_REMOVE_CA_V3 6
typedef struct {
    pd_CAId_V3_t ca_id;
} pd_corporateaction_remove_ca_V3_t;

#define PD_CALL_CORPORATEACTION_CHANGE_RECORD_DATE_V3 7
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_OptionRecordDateSpec_V3_t record_date;
} pd_corporateaction_change_record_date_V3_t;

#define PD_CALL_CORPORATEBALLOT_ATTACH_BALLOT_V3 0
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_BallotTimeRange_V3_t range;
    pd_BallotMeta_V3_t meta;
    pd_bool_t rcv;
} pd_corporateballot_attach_ballot_V3_t;

#define PD_CALL_CORPORATEBALLOT_VOTE_V3 1
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_VecBallotVote_V3_t votes;
} pd_corporateballot_vote_V3_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_END_V3 2
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_Moment_V3_t end;
} pd_corporateballot_change_end_V3_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_META_V3 3
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_BallotMeta_V3_t meta;
} pd_corporateballot_change_meta_V3_t;

#define PD_CALL_CORPORATEBALLOT_CHANGE_RCV_V3 4
typedef struct {
    pd_CAId_V3_t ca_id;
    pd_bool_t rcv;
} pd_corporateballot_change_rcv_V3_t;

#define PD_CALL_CORPORATEBALLOT_REMOVE_BALLOT_V3 5
typedef struct {
    pd_CAId_V3_t ca_id;
} pd_corporateballot_remove_ballot_V3_t;

#define PD_CALL_PIPS_SET_PRUNE_HISTORICAL_PIPS_V3 0
typedef struct {
    pd_bool_t prune;
} pd_pips_set_prune_historical_pips_V3_t;

#define PD_CALL_PIPS_SET_MIN_PROPOSAL_DEPOSIT_V3 1
typedef struct {
    pd_Balance_t deposit;
} pd_pips_set_min_proposal_deposit_V3_t;

#define PD_CALL_PIPS_SET_DEFAULT_ENACTMENT_PERIOD_V3 2
typedef struct {
    pd_BlockNumber_t duration;
} pd_pips_set_default_enactment_period_V3_t;

#define PD_CALL_PIPS_SET_PENDING_PIP_EXPIRY_V3 3
typedef struct {
    pd_MaybeBlockBlockNumber_V3_t expiry;
} pd_pips_set_pending_pip_expiry_V3_t;

#define PD_CALL_PIPS_SET_MAX_PIP_SKIP_COUNT_V3 4
typedef struct {
    pd_SkippedCount_V3_t max;
} pd_pips_set_max_pip_skip_count_V3_t;

#define PD_CALL_PIPS_SET_ACTIVE_PIP_LIMIT_V3 5
typedef struct {
    pd_u32_t limit;
} pd_pips_set_active_pip_limit_V3_t;

#define PD_CALL_PIPS_APPROVE_COMMITTEE_PROPOSAL_V3 8
typedef struct {
    pd_PipId_V3_t id;
} pd_pips_approve_committee_proposal_V3_t;

#define PD_CALL_PIPS_REJECT_PROPOSAL_V3 9
typedef struct {
    pd_PipId_V3_t id;
} pd_pips_reject_proposal_V3_t;

#define PD_CALL_PIPS_PRUNE_PROPOSAL_V3 10
typedef struct {
    pd_PipId_V3_t id;
} pd_pips_prune_proposal_V3_t;

#define PD_CALL_PIPS_RESCHEDULE_EXECUTION_V3 11
typedef struct {
    pd_PipId_V3_t id;
    pd_OptionBlockNumber_t until;
} pd_pips_reschedule_execution_V3_t;

#define PD_CALL_PIPS_CLEAR_SNAPSHOT_V3 12
typedef struct {
} pd_pips_clear_snapshot_V3_t;

#define PD_CALL_PIPS_SNAPSHOT_V3 13
typedef struct {
} pd_pips_snapshot_V3_t;

#define PD_CALL_PIPS_ENACT_SNAPSHOT_RESULTS_V3 14
typedef struct {
    pd_VecTuplePipIdSnapshotResult_V3_t results;
} pd_pips_enact_snapshot_results_V3_t;

#define PD_CALL_PIPS_EXECUTE_SCHEDULED_PIP_V3 15
typedef struct {
    pd_PipId_V3_t id;
} pd_pips_execute_scheduled_pip_V3_t;

#define PD_CALL_PIPS_EXPIRE_SCHEDULED_PIP_V3 16
typedef struct {
    pd_IdentityId_V3_t did;
    pd_PipId_V3_t id;
} pd_pips_expire_scheduled_pip_V3_t;

#define PD_CALL_PORTFOLIO_CREATE_PORTFOLIO_V3 0
typedef struct {
    pd_PortfolioName_V3_t name;
} pd_portfolio_create_portfolio_V3_t;

#define PD_CALL_PORTFOLIO_DELETE_PORTFOLIO_V3 1
typedef struct {
    pd_PortfolioNumber_V3_t num;
} pd_portfolio_delete_portfolio_V3_t;

#define PD_CALL_PORTFOLIO_MOVE_PORTFOLIO_FUNDS_V3 2
typedef struct {
    pd_PortfolioId_V3_t from;
    pd_PortfolioId_V3_t to;
    pd_VecMovePortfolioItem_V3_t items;
} pd_portfolio_move_portfolio_funds_V3_t;

#define PD_CALL_PORTFOLIO_RENAME_PORTFOLIO_V3 3
typedef struct {
    pd_PortfolioNumber_V3_t num;
    pd_PortfolioName_V3_t to_name;
} pd_portfolio_rename_portfolio_V3_t;

#define PD_CALL_PROTOCOLFEE_CHANGE_COEFFICIENT_V3 0
typedef struct {
    pd_PosRatio_V3_t coefficient;
} pd_protocolfee_change_coefficient_V3_t;

#define PD_CALL_SETTLEMENT_CREATE_VENUE_V3 0
typedef struct {
    pd_VenueDetails_V3_t details;
    pd_VecAccountId_V3_t signers;
    pd_VenueType_V3_t typ;
} pd_settlement_create_venue_V3_t;

#define PD_CALL_SETTLEMENT_ADD_INSTRUCTION_V3 3
typedef struct {
    pd_VenueId_V3_t venue_id;
    pd_SettlementTypeBlockNumber_V3_t settlement_type;
    pd_OptionMoment_V3_t trade_date;
    pd_OptionMoment_V3_t value_date;
    pd_VecLeg_V3_t legs;
} pd_settlement_add_instruction_V3_t;

#define PD_CALL_SETTLEMENT_ADD_AND_AFFIRM_INSTRUCTION_V3 4
typedef struct {
    pd_VenueId_V3_t venue_id;
    pd_SettlementTypeBlockNumber_V3_t settlement_type;
    pd_OptionMoment_V3_t trade_date;
    pd_OptionMoment_V3_t value_date;
    pd_VecLeg_V3_t legs;
    pd_VecPortfolioId_V3_t portfolios;
} pd_settlement_add_and_affirm_instruction_V3_t;

#define PD_CALL_SETTLEMENT_AFFIRM_INSTRUCTION_V3 5
typedef struct {
    pd_InstructionId_V3_t id;
    pd_VecPortfolioId_V3_t portfolios;
    pd_u32_t max_legs_count;
} pd_settlement_affirm_instruction_V3_t;

#define PD_CALL_SETTLEMENT_WITHDRAW_AFFIRMATION_V3 6
typedef struct {
    pd_InstructionId_V3_t id;
    pd_VecPortfolioId_V3_t portfolios;
    pd_u32_t max_legs_count;
} pd_settlement_withdraw_affirmation_V3_t;

#define PD_CALL_SETTLEMENT_REJECT_INSTRUCTION_V3 7
typedef struct {
    pd_InstructionId_V3_t id;
    pd_PortfolioId_V3_t portfolio;
    pd_u32_t num_of_legs;
} pd_settlement_reject_instruction_V3_t;

#define PD_CALL_SETTLEMENT_AFFIRM_WITH_RECEIPTS_V3 8
typedef struct {
    pd_InstructionId_V3_t id;
    pd_VecReceiptDetails_V3_t receipt_details;
    pd_VecPortfolioId_V3_t portfolios;
    pd_u32_t max_legs_count;
} pd_settlement_affirm_with_receipts_V3_t;

#define PD_CALL_SETTLEMENT_CLAIM_RECEIPT_V3 9
typedef struct {
    pd_InstructionId_V3_t id;
    pd_ReceiptDetails_V3_t receipt_details;
} pd_settlement_claim_receipt_V3_t;

#define PD_CALL_SETTLEMENT_UNCLAIM_RECEIPT_V3 10
typedef struct {
    pd_InstructionId_V3_t instruction_id;
    pd_LegId_V3_t leg_id;
} pd_settlement_unclaim_receipt_V3_t;

#define PD_CALL_SETTLEMENT_SET_VENUE_FILTERING_V3 11
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_bool_t enabled;
} pd_settlement_set_venue_filtering_V3_t;

#define PD_CALL_SETTLEMENT_ALLOW_VENUES_V3 12
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_VecVenueId_V3_t venues;
} pd_settlement_allow_venues_V3_t;

#define PD_CALL_SETTLEMENT_DISALLOW_VENUES_V3 13
typedef struct {
    pd_Ticker_V3_t ticker;
    pd_VecVenueId_V3_t venues;
} pd_settlement_disallow_venues_V3_t;

#define PD_CALL_SETTLEMENT_EXECUTE_SCHEDULED_INSTRUCTION_V3 15
typedef struct {
    pd_InstructionId_V3_t id;
    pd_u32_t _legs_count;
} pd_settlement_execute_scheduled_instruction_V3_t;

#define PD_CALL_TREASURY_DISBURSEMENT_V3 0
typedef struct {
    pd_VecBeneficiary_V3_t beneficiaries;
} pd_treasury_disbursement_V3_t;

#define PD_CALL_TREASURY_REIMBURSEMENT_V3 1
typedef struct {
    pd_Balance_t amount;
} pd_treasury_reimbursement_V3_t;

#define PD_CALL_UTILITY_RELAY_TX_V3 3
typedef struct {
    pd_AccountId_V3_t target;
    pd_OffChainSignature_V3_t signature;
    pd_UniqueCall_V3_t call;
} pd_utility_relay_tx_V3_t;

#define PD_CALL_CONTRACTS_CALL_V3 0
typedef struct {
    pd_LookupasStaticLookupSource_V3_t dest;
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_V3_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V3 2
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_V3_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V3_t;

#endif

typedef union {
    pd_balances_transfer_V3_t balances_transfer_V3;
    pd_balances_transfer_with_memo_V3_t balances_transfer_with_memo_V3;
    pd_identity_accept_primary_key_V3_t identity_accept_primary_key_V3;
    pd_identity_join_identity_as_key_V3_t identity_join_identity_as_key_V3;
    pd_identity_leave_identity_as_key_V3_t identity_leave_identity_as_key_V3;
    pd_identity_add_claim_V3_t identity_add_claim_V3;
    pd_identity_revoke_claim_V3_t identity_revoke_claim_V3;
    pd_identity_set_permission_to_signer_V3_t identity_set_permission_to_signer_V3;
    pd_identity_freeze_secondary_keys_V3_t identity_freeze_secondary_keys_V3;
    pd_identity_unfreeze_secondary_keys_V3_t identity_unfreeze_secondary_keys_V3;
    pd_identity_add_authorization_V3_t identity_add_authorization_V3;
    pd_identity_remove_authorization_V3_t identity_remove_authorization_V3;
    pd_identity_add_investor_uniqueness_claim_V3_t identity_add_investor_uniqueness_claim_V3;
    pd_identity_add_secondary_keys_with_authorization_V3_t identity_add_secondary_keys_with_authorization_V3;
    pd_identity_remove_secondary_keys_V3_t identity_remove_secondary_keys_V3;
    pd_multisig_create_multisig_V3_t multisig_create_multisig_V3;
    pd_multisig_create_or_approve_proposal_as_identity_V3_t multisig_create_or_approve_proposal_as_identity_V3;
    pd_multisig_create_or_approve_proposal_as_key_V3_t multisig_create_or_approve_proposal_as_key_V3;
    pd_multisig_create_proposal_as_identity_V3_t multisig_create_proposal_as_identity_V3;
    pd_multisig_create_proposal_as_key_V3_t multisig_create_proposal_as_key_V3;
    pd_multisig_approve_as_identity_V3_t multisig_approve_as_identity_V3;
    pd_multisig_approve_as_key_V3_t multisig_approve_as_key_V3;
    pd_multisig_reject_as_identity_V3_t multisig_reject_as_identity_V3;
    pd_multisig_reject_as_key_V3_t multisig_reject_as_key_V3;
    pd_multisig_accept_multisig_signer_as_identity_V3_t multisig_accept_multisig_signer_as_identity_V3;
    pd_multisig_accept_multisig_signer_as_key_V3_t multisig_accept_multisig_signer_as_key_V3;
    pd_multisig_add_multisig_signer_V3_t multisig_add_multisig_signer_V3;
    pd_multisig_remove_multisig_signer_V3_t multisig_remove_multisig_signer_V3;
    pd_multisig_add_multisig_signers_via_creator_V3_t multisig_add_multisig_signers_via_creator_V3;
    pd_multisig_remove_multisig_signers_via_creator_V3_t multisig_remove_multisig_signers_via_creator_V3;
    pd_multisig_change_sigs_required_V3_t multisig_change_sigs_required_V3;
    pd_multisig_make_multisig_primary_V3_t multisig_make_multisig_primary_V3;
    pd_multisig_execute_scheduled_proposal_V3_t multisig_execute_scheduled_proposal_V3;
    pd_staking_bond_V3_t staking_bond_V3;
    pd_staking_bond_extra_V3_t staking_bond_extra_V3;
    pd_staking_unbond_V3_t staking_unbond_V3;
    pd_staking_withdraw_unbonded_V3_t staking_withdraw_unbonded_V3;
    pd_staking_validate_V3_t staking_validate_V3;
    pd_staking_nominate_V3_t staking_nominate_V3;
    pd_staking_chill_V3_t staking_chill_V3;
    pd_staking_set_payee_V3_t staking_set_payee_V3;
    pd_staking_set_controller_V3_t staking_set_controller_V3;
    pd_staking_rebond_V3_t staking_rebond_V3;
    pd_pips_propose_V3_t pips_propose_V3;
    pd_pips_vote_V3_t pips_vote_V3;
    pd_utility_batch_V3_t utility_batch_V3;
    pd_utility_batch_atomic_V3_t utility_batch_atomic_V3;
    pd_utility_batch_optimistic_V3_t utility_batch_optimistic_V3;
#ifdef SUBSTRATE_PARSER_FULL
    pd_system_fill_block_V3_t system_fill_block_V3;
    pd_system_remark_V3_t system_remark_V3;
    pd_system_set_heap_pages_V3_t system_set_heap_pages_V3;
    pd_system_set_code_V3_t system_set_code_V3;
    pd_system_set_code_without_checks_V3_t system_set_code_without_checks_V3;
    pd_system_remark_with_event_V3_t system_remark_with_event_V3;
    pd_timestamp_set_V3_t timestamp_set_V3;
    pd_indices_claim_V3_t indices_claim_V3;
    pd_indices_transfer_V3_t indices_transfer_V3;
    pd_indices_free_V3_t indices_free_V3;
    pd_indices_force_transfer_V3_t indices_force_transfer_V3;
    pd_indices_freeze_V3_t indices_freeze_V3;
    pd_balances_deposit_block_reward_reserve_balance_V3_t balances_deposit_block_reward_reserve_balance_V3;
    pd_balances_set_balance_V3_t balances_set_balance_V3;
    pd_balances_force_transfer_V3_t balances_force_transfer_V3;
    pd_balances_burn_account_balance_V3_t balances_burn_account_balance_V3;
    pd_identity_invalidate_cdd_claims_V3_t identity_invalidate_cdd_claims_V3;
    pd_identity_change_cdd_requirement_for_mk_rotation_V3_t identity_change_cdd_requirement_for_mk_rotation_V3;
    pd_identity_gc_add_cdd_claim_V3_t identity_gc_add_cdd_claim_V3;
    pd_identity_gc_revoke_cdd_claim_V3_t identity_gc_revoke_cdd_claim_V3;
    pd_cddserviceproviders_set_active_members_limit_V3_t cddserviceproviders_set_active_members_limit_V3;
    pd_cddserviceproviders_disable_member_V3_t cddserviceproviders_disable_member_V3;
    pd_cddserviceproviders_add_member_V3_t cddserviceproviders_add_member_V3;
    pd_cddserviceproviders_remove_member_V3_t cddserviceproviders_remove_member_V3;
    pd_cddserviceproviders_swap_member_V3_t cddserviceproviders_swap_member_V3;
    pd_cddserviceproviders_reset_members_V3_t cddserviceproviders_reset_members_V3;
    pd_cddserviceproviders_abdicate_membership_V3_t cddserviceproviders_abdicate_membership_V3;
    pd_polymeshcommittee_set_vote_threshold_V3_t polymeshcommittee_set_vote_threshold_V3;
    pd_polymeshcommittee_set_release_coordinator_V3_t polymeshcommittee_set_release_coordinator_V3;
    pd_polymeshcommittee_set_expires_after_V3_t polymeshcommittee_set_expires_after_V3;
    pd_polymeshcommittee_vote_or_propose_V3_t polymeshcommittee_vote_or_propose_V3;
    pd_polymeshcommittee_vote_V3_t polymeshcommittee_vote_V3;
    pd_committeemembership_set_active_members_limit_V3_t committeemembership_set_active_members_limit_V3;
    pd_committeemembership_disable_member_V3_t committeemembership_disable_member_V3;
    pd_committeemembership_add_member_V3_t committeemembership_add_member_V3;
    pd_committeemembership_remove_member_V3_t committeemembership_remove_member_V3;
    pd_committeemembership_swap_member_V3_t committeemembership_swap_member_V3;
    pd_committeemembership_reset_members_V3_t committeemembership_reset_members_V3;
    pd_committeemembership_abdicate_membership_V3_t committeemembership_abdicate_membership_V3;
    pd_technicalcommittee_set_vote_threshold_V3_t technicalcommittee_set_vote_threshold_V3;
    pd_technicalcommittee_set_release_coordinator_V3_t technicalcommittee_set_release_coordinator_V3;
    pd_technicalcommittee_set_expires_after_V3_t technicalcommittee_set_expires_after_V3;
    pd_technicalcommittee_vote_or_propose_V3_t technicalcommittee_vote_or_propose_V3;
    pd_technicalcommittee_vote_V3_t technicalcommittee_vote_V3;
    pd_technicalcommitteemembership_set_active_members_limit_V3_t technicalcommitteemembership_set_active_members_limit_V3;
    pd_technicalcommitteemembership_disable_member_V3_t technicalcommitteemembership_disable_member_V3;
    pd_technicalcommitteemembership_add_member_V3_t technicalcommitteemembership_add_member_V3;
    pd_technicalcommitteemembership_remove_member_V3_t technicalcommitteemembership_remove_member_V3;
    pd_technicalcommitteemembership_swap_member_V3_t technicalcommitteemembership_swap_member_V3;
    pd_technicalcommitteemembership_reset_members_V3_t technicalcommitteemembership_reset_members_V3;
    pd_technicalcommitteemembership_abdicate_membership_V3_t technicalcommitteemembership_abdicate_membership_V3;
    pd_upgradecommittee_set_vote_threshold_V3_t upgradecommittee_set_vote_threshold_V3;
    pd_upgradecommittee_set_release_coordinator_V3_t upgradecommittee_set_release_coordinator_V3;
    pd_upgradecommittee_set_expires_after_V3_t upgradecommittee_set_expires_after_V3;
    pd_upgradecommittee_vote_or_propose_V3_t upgradecommittee_vote_or_propose_V3;
    pd_upgradecommittee_vote_V3_t upgradecommittee_vote_V3;
    pd_upgradecommitteemembership_set_active_members_limit_V3_t upgradecommitteemembership_set_active_members_limit_V3;
    pd_upgradecommitteemembership_disable_member_V3_t upgradecommitteemembership_disable_member_V3;
    pd_upgradecommitteemembership_add_member_V3_t upgradecommitteemembership_add_member_V3;
    pd_upgradecommitteemembership_remove_member_V3_t upgradecommitteemembership_remove_member_V3;
    pd_upgradecommitteemembership_swap_member_V3_t upgradecommitteemembership_swap_member_V3;
    pd_upgradecommitteemembership_reset_members_V3_t upgradecommitteemembership_reset_members_V3;
    pd_upgradecommitteemembership_abdicate_membership_V3_t upgradecommitteemembership_abdicate_membership_V3;
    pd_bridge_change_controller_V3_t bridge_change_controller_V3;
    pd_bridge_change_admin_V3_t bridge_change_admin_V3;
    pd_bridge_change_timelock_V3_t bridge_change_timelock_V3;
    pd_bridge_freeze_V3_t bridge_freeze_V3;
    pd_bridge_unfreeze_V3_t bridge_unfreeze_V3;
    pd_bridge_change_bridge_limit_V3_t bridge_change_bridge_limit_V3;
    pd_bridge_change_bridge_exempted_V3_t bridge_change_bridge_exempted_V3;
    pd_staking_set_validator_count_V3_t staking_set_validator_count_V3;
    pd_staking_increase_validator_count_V3_t staking_increase_validator_count_V3;
    pd_staking_add_permissioned_validator_V3_t staking_add_permissioned_validator_V3;
    pd_staking_remove_permissioned_validator_V3_t staking_remove_permissioned_validator_V3;
    pd_staking_validate_cdd_expiry_nominators_V3_t staking_validate_cdd_expiry_nominators_V3;
    pd_staking_set_commission_cap_V3_t staking_set_commission_cap_V3;
    pd_staking_set_min_bond_threshold_V3_t staking_set_min_bond_threshold_V3;
    pd_staking_force_no_eras_V3_t staking_force_no_eras_V3;
    pd_staking_force_new_era_V3_t staking_force_new_era_V3;
    pd_staking_set_invulnerables_V3_t staking_set_invulnerables_V3;
    pd_staking_force_unstake_V3_t staking_force_unstake_V3;
    pd_staking_force_new_era_always_V3_t staking_force_new_era_always_V3;
    pd_staking_cancel_deferred_slash_V3_t staking_cancel_deferred_slash_V3;
    pd_staking_payout_stakers_V3_t staking_payout_stakers_V3;
    pd_staking_set_history_depth_V3_t staking_set_history_depth_V3;
    pd_staking_reap_stash_V3_t staking_reap_stash_V3;
    pd_staking_payout_stakers_by_system_V3_t staking_payout_stakers_by_system_V3;
    pd_staking_change_slashing_allowed_for_V3_t staking_change_slashing_allowed_for_V3;
    pd_staking_update_permissioned_validator_intended_count_V3_t staking_update_permissioned_validator_intended_count_V3;
    pd_session_set_keys_V3_t session_set_keys_V3;
    pd_session_purge_keys_V3_t session_purge_keys_V3;
    pd_grandpa_note_stalled_V3_t grandpa_note_stalled_V3;
    pd_sudo_sudo_as_V3_t sudo_sudo_as_V3;
    pd_asset_register_ticker_V3_t asset_register_ticker_V3;
    pd_asset_accept_ticker_transfer_V3_t asset_accept_ticker_transfer_V3;
    pd_asset_accept_asset_ownership_transfer_V3_t asset_accept_asset_ownership_transfer_V3;
    pd_asset_create_asset_V3_t asset_create_asset_V3;
    pd_asset_freeze_V3_t asset_freeze_V3;
    pd_asset_unfreeze_V3_t asset_unfreeze_V3;
    pd_asset_rename_asset_V3_t asset_rename_asset_V3;
    pd_asset_issue_V3_t asset_issue_V3;
    pd_asset_redeem_V3_t asset_redeem_V3;
    pd_asset_make_divisible_V3_t asset_make_divisible_V3;
    pd_asset_add_documents_V3_t asset_add_documents_V3;
    pd_asset_remove_documents_V3_t asset_remove_documents_V3;
    pd_asset_set_funding_round_V3_t asset_set_funding_round_V3;
    pd_asset_update_identifiers_V3_t asset_update_identifiers_V3;
    pd_asset_claim_classic_ticker_V3_t asset_claim_classic_ticker_V3;
    pd_asset_reserve_classic_ticker_V3_t asset_reserve_classic_ticker_V3;
    pd_capitaldistribution_distribute_V3_t capitaldistribution_distribute_V3;
    pd_capitaldistribution_claim_V3_t capitaldistribution_claim_V3;
    pd_capitaldistribution_push_benefit_V3_t capitaldistribution_push_benefit_V3;
    pd_capitaldistribution_reclaim_V3_t capitaldistribution_reclaim_V3;
    pd_capitaldistribution_remove_distribution_V3_t capitaldistribution_remove_distribution_V3;
    pd_checkpoint_create_checkpoint_V3_t checkpoint_create_checkpoint_V3;
    pd_checkpoint_set_schedules_max_complexity_V3_t checkpoint_set_schedules_max_complexity_V3;
    pd_checkpoint_create_schedule_V3_t checkpoint_create_schedule_V3;
    pd_checkpoint_remove_schedule_V3_t checkpoint_remove_schedule_V3;
    pd_compliancemanager_add_compliance_requirement_V3_t compliancemanager_add_compliance_requirement_V3;
    pd_compliancemanager_remove_compliance_requirement_V3_t compliancemanager_remove_compliance_requirement_V3;
    pd_compliancemanager_reset_asset_compliance_V3_t compliancemanager_reset_asset_compliance_V3;
    pd_compliancemanager_pause_asset_compliance_V3_t compliancemanager_pause_asset_compliance_V3;
    pd_compliancemanager_resume_asset_compliance_V3_t compliancemanager_resume_asset_compliance_V3;
    pd_compliancemanager_add_default_trusted_claim_issuer_V3_t compliancemanager_add_default_trusted_claim_issuer_V3;
    pd_compliancemanager_remove_default_trusted_claim_issuer_V3_t compliancemanager_remove_default_trusted_claim_issuer_V3;
    pd_corporateaction_set_max_details_length_V3_t corporateaction_set_max_details_length_V3;
    pd_corporateaction_set_default_targets_V3_t corporateaction_set_default_targets_V3;
    pd_corporateaction_set_default_withholding_tax_V3_t corporateaction_set_default_withholding_tax_V3;
    pd_corporateaction_set_did_withholding_tax_V3_t corporateaction_set_did_withholding_tax_V3;
    pd_corporateaction_initiate_corporate_action_V3_t corporateaction_initiate_corporate_action_V3;
    pd_corporateaction_link_ca_doc_V3_t corporateaction_link_ca_doc_V3;
    pd_corporateaction_remove_ca_V3_t corporateaction_remove_ca_V3;
    pd_corporateaction_change_record_date_V3_t corporateaction_change_record_date_V3;
    pd_corporateballot_attach_ballot_V3_t corporateballot_attach_ballot_V3;
    pd_corporateballot_vote_V3_t corporateballot_vote_V3;
    pd_corporateballot_change_end_V3_t corporateballot_change_end_V3;
    pd_corporateballot_change_meta_V3_t corporateballot_change_meta_V3;
    pd_corporateballot_change_rcv_V3_t corporateballot_change_rcv_V3;
    pd_corporateballot_remove_ballot_V3_t corporateballot_remove_ballot_V3;
    pd_pips_set_prune_historical_pips_V3_t pips_set_prune_historical_pips_V3;
    pd_pips_set_min_proposal_deposit_V3_t pips_set_min_proposal_deposit_V3;
    pd_pips_set_default_enactment_period_V3_t pips_set_default_enactment_period_V3;
    pd_pips_set_pending_pip_expiry_V3_t pips_set_pending_pip_expiry_V3;
    pd_pips_set_max_pip_skip_count_V3_t pips_set_max_pip_skip_count_V3;
    pd_pips_set_active_pip_limit_V3_t pips_set_active_pip_limit_V3;
    pd_pips_approve_committee_proposal_V3_t pips_approve_committee_proposal_V3;
    pd_pips_reject_proposal_V3_t pips_reject_proposal_V3;
    pd_pips_prune_proposal_V3_t pips_prune_proposal_V3;
    pd_pips_reschedule_execution_V3_t pips_reschedule_execution_V3;
    pd_pips_clear_snapshot_V3_t pips_clear_snapshot_V3;
    pd_pips_snapshot_V3_t pips_snapshot_V3;
    pd_pips_enact_snapshot_results_V3_t pips_enact_snapshot_results_V3;
    pd_pips_execute_scheduled_pip_V3_t pips_execute_scheduled_pip_V3;
    pd_pips_expire_scheduled_pip_V3_t pips_expire_scheduled_pip_V3;
    pd_portfolio_create_portfolio_V3_t portfolio_create_portfolio_V3;
    pd_portfolio_delete_portfolio_V3_t portfolio_delete_portfolio_V3;
    pd_portfolio_move_portfolio_funds_V3_t portfolio_move_portfolio_funds_V3;
    pd_portfolio_rename_portfolio_V3_t portfolio_rename_portfolio_V3;
    pd_protocolfee_change_coefficient_V3_t protocolfee_change_coefficient_V3;
    pd_settlement_create_venue_V3_t settlement_create_venue_V3;
    pd_settlement_add_instruction_V3_t settlement_add_instruction_V3;
    pd_settlement_add_and_affirm_instruction_V3_t settlement_add_and_affirm_instruction_V3;
    pd_settlement_affirm_instruction_V3_t settlement_affirm_instruction_V3;
    pd_settlement_withdraw_affirmation_V3_t settlement_withdraw_affirmation_V3;
    pd_settlement_reject_instruction_V3_t settlement_reject_instruction_V3;
    pd_settlement_affirm_with_receipts_V3_t settlement_affirm_with_receipts_V3;
    pd_settlement_claim_receipt_V3_t settlement_claim_receipt_V3;
    pd_settlement_unclaim_receipt_V3_t settlement_unclaim_receipt_V3;
    pd_settlement_set_venue_filtering_V3_t settlement_set_venue_filtering_V3;
    pd_settlement_allow_venues_V3_t settlement_allow_venues_V3;
    pd_settlement_disallow_venues_V3_t settlement_disallow_venues_V3;
    pd_settlement_execute_scheduled_instruction_V3_t settlement_execute_scheduled_instruction_V3;
    pd_treasury_disbursement_V3_t treasury_disbursement_V3;
    pd_treasury_reimbursement_V3_t treasury_reimbursement_V3;
    pd_utility_relay_tx_V3_t utility_relay_tx_V3;
    pd_contracts_call_V3_t contracts_call_V3;
    pd_contracts_instantiate_V3_t contracts_instantiate_V3;
#endif
} pd_MethodNested_V3_t;

typedef union {
    pd_MethodBasic_V3_t basic;
    pd_MethodNested_V3_t nested;
} pd_Method_V3_t;

#ifdef __cplusplus
}
#endif

#pragma clang diagnostic pop
