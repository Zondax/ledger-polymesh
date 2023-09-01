/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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
#pragma once

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"

extern "C" {
#endif

#include "substrate_types.h"
#include "substrate_types_V4.h"
#include <stddef.h>
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

#define PD_CALL_SYSTEM_V4 0
#define PD_CALL_TIMESTAMP_V4 2
#define PD_CALL_INDICES_V4 3
#define PD_CALL_BALANCES_V4 5
#define PD_CALL_IDENTITY_V4 7
#define PD_CALL_CDDSERVICEPROVIDERS_V4 8
#define PD_CALL_POLYMESHCOMMITTEE_V4 9
#define PD_CALL_COMMITTEEMEMBERSHIP_V4 10
#define PD_CALL_TECHNICALCOMMITTEE_V4 11
#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_V4 12
#define PD_CALL_UPGRADECOMMITTEE_V4 13
#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_V4 14
#define PD_CALL_MULTISIG_V4 15
#define PD_CALL_BRIDGE_V4 16
#define PD_CALL_STAKING_V4 17
#define PD_CALL_SESSION_V4 19
#define PD_CALL_ASSET_V4 26
#define PD_CALL_CAPITALDISTRIBUTION_V4 27
#define PD_CALL_CHECKPOINT_V4 28
#define PD_CALL_COMPLIANCEMANAGER_V4 29
#define PD_CALL_CORPORATEACTION_V4 30
#define PD_CALL_CORPORATEBALLOT_V4 31
#define PD_CALL_PIPS_V4 33
#define PD_CALL_PORTFOLIO_V4 34
#define PD_CALL_PROTOCOLFEE_V4 35
#define PD_CALL_SETTLEMENT_V4 37
#define PD_CALL_STO_V4 39
#define PD_CALL_TREASURY_V4 40
#define PD_CALL_UTILITY_V4 41
#define PD_CALL_EXTERNALAGENTS_V4 43
#define PD_CALL_RELAYER_V4 44
#define PD_CALL_REWARDS_V4 45
#define PD_CALL_CONTRACTS_V4 46
#define PD_CALL_POLYMESHCONTRACTS_V4 47
#define PD_CALL_PREIMAGE_V4 48
#define PD_CALL_NFT_V4 49

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif

#define PD_CALL_BRIDGE_BATCH_PROPOSE_BRIDGE_TX_V4 8
typedef struct {
    pd_VecBridgeTxAccountId_t bridge_txs;
} pd_bridge_batch_propose_bridge_tx_V4_t;

#define PD_CALL_BRIDGE_PROPOSE_BRIDGE_TX_V4 9
typedef struct {
    pd_BridgeTxAccountId_t bridge_tx;
} pd_bridge_propose_bridge_tx_V4_t;

#define PD_CALL_BRIDGE_HANDLE_BRIDGE_TX_V4 10
typedef struct {
    pd_BridgeTxAccountId_t bridge_tx;
} pd_bridge_handle_bridge_tx_V4_t;

#define PD_CALL_BRIDGE_FREEZE_TXS_V4 11
typedef struct {
    pd_VecBridgeTxAccountId_t bridge_txs;
} pd_bridge_freeze_txs_V4_t;

#define PD_CALL_BRIDGE_UNFREEZE_TXS_V4 12
typedef struct {
    pd_VecBridgeTxAccountId_t bridge_txs;
} pd_bridge_unfreeze_txs_V4_t;

#define PD_CALL_BRIDGE_HANDLE_SCHEDULED_BRIDGE_TX_V4 13
typedef struct {
    pd_BridgeTxAccountId_t bridge_tx;
} pd_bridge_handle_scheduled_bridge_tx_V4_t;

#define PD_CALL_BRIDGE_ADD_FREEZE_ADMIN_V4 14
typedef struct {
    pd_AccountId_t freeze_admin;
} pd_bridge_add_freeze_admin_V4_t;

#define PD_CALL_BRIDGE_REMOVE_FREEZE_ADMIN_V4 15
typedef struct {
    pd_AccountId_t freeze_admin;
} pd_bridge_remove_freeze_admin_V4_t;

#define PD_CALL_BRIDGE_REMOVE_TXS_V4 16
typedef struct {
    pd_VecBridgeTxAccountId_t bridge_txs;
} pd_bridge_remove_txs_V4_t;

#define PD_CALL_ASSET_CONTROLLER_TRANSFER_V4 14
typedef struct {
    pd_Ticker_t ticker;
    pd_BalanceNoSymbol_t amount;
    pd_PortfolioId_t from_portfolio;
} pd_asset_controller_transfer_V4_t;

#define PD_CALL_ASSET_REGISTER_CUSTOM_ASSET_TYPE_V4 15
typedef struct {
    pd_Vecu8_t ty;
} pd_asset_register_custom_asset_type_V4_t;

#define PD_CALL_ASSET_CREATE_ASSET_WITH_CUSTOM_TYPE_V4 16
typedef struct {
    pd_AssetName_t name;
    pd_Ticker_t ticker;
    pd_bool_t divisible;
    pd_Vecu8_t custom_asset_type;
    pd_VecAssetIdentifier_t identifiers;
    pd_OptionFundingRoundName_t funding_round;
} pd_asset_create_asset_with_custom_type_V4_t;

#define PD_CALL_ASSET_SET_ASSET_METADATA_V4 17
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetMetadataKey_t key;
    pd_AssetMetadataValue_t value;
    pd_OptionAssetMetadataValueDetailMoment_t detail;
} pd_asset_set_asset_metadata_V4_t;

#define PD_CALL_ASSET_SET_ASSET_METADATA_DETAILS_V4 18
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetMetadataKey_t key;
    pd_AssetMetadataValueDetailMoment_t detail;
} pd_asset_set_asset_metadata_details_V4_t;

#define PD_CALL_ASSET_REGISTER_AND_SET_LOCAL_ASSET_METADATA_V4 19
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetMetadataName_t name;
    pd_AssetMetadataSpec_t spec;
    pd_AssetMetadataValue_t value;
    pd_OptionAssetMetadataValueDetailMoment_t detail;
} pd_asset_register_and_set_local_asset_metadata_V4_t;

#define PD_CALL_ASSET_REGISTER_ASSET_METADATA_LOCAL_TYPE_V4 20
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetMetadataName_t name;
    pd_AssetMetadataSpec_t spec;
} pd_asset_register_asset_metadata_local_type_V4_t;

#define PD_CALL_ASSET_REGISTER_ASSET_METADATA_GLOBAL_TYPE_V4 21
typedef struct {
    pd_AssetMetadataName_t name;
    pd_AssetMetadataSpec_t spec;
} pd_asset_register_asset_metadata_global_type_V4_t;

#define PD_CALL_ASSET_REDEEM_FROM_PORTFOLIO_V4 22
typedef struct {
    pd_Ticker_t ticker;
    pd_BalanceNoSymbol_t amount;
    pd_PortfolioKind_t portfolio;
} pd_asset_redeem_from_portfolio_V4_t;

#define PD_CALL_ASSET_UPDATE_ASSET_TYPE_V4 23
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetType_t asset_type;
} pd_asset_update_asset_type_V4_t;

#define PD_CALL_ASSET_REMOVE_LOCAL_METADATA_KEY_V4 24
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetMetadataLocalKey_t local_key;
} pd_asset_remove_local_metadata_key_V4_t;

#define PD_CALL_ASSET_REMOVE_METADATA_VALUE_V4 25
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetMetadataKey_t metadata_key;
} pd_asset_remove_metadata_value_V4_t;

#define PD_CALL_ASSET_EXEMPT_TICKER_AFFIRMATION_V4 26
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_exempt_ticker_affirmation_V4_t;

#define PD_CALL_ASSET_REMOVE_TICKER_AFFIRMATION_EXEMPTION_V4 27
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_remove_ticker_affirmation_exemption_V4_t;

#define PD_CALL_ASSET_PRE_APPROVE_TICKER_V4 28
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_pre_approve_ticker_V4_t;

#define PD_CALL_ASSET_REMOVE_TICKER_PRE_APPROVAL_V4 29
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_remove_ticker_pre_approval_V4_t;

#define PD_CALL_PORTFOLIO_QUIT_PORTFOLIO_CUSTODY_V4 3
typedef struct {
    pd_PortfolioId_t pid;
} pd_portfolio_quit_portfolio_custody_V4_t;

#define PD_CALL_PORTFOLIO_ACCEPT_PORTFOLIO_CUSTODY_V4 4
typedef struct {
    pd_u64_t auth_id;
} pd_portfolio_accept_portfolio_custody_V4_t;

#define PD_CALL_PORTFOLIO_PRE_APPROVE_PORTFOLIO_V4 6
typedef struct {
    pd_Ticker_t ticker;
    pd_PortfolioId_t portfolio_id;
} pd_portfolio_pre_approve_portfolio_V4_t;

#define PD_CALL_PORTFOLIO_REMOVE_PORTFOLIO_PRE_APPROVAL_V4 7
typedef struct {
    pd_Ticker_t ticker;
    pd_PortfolioId_t portfolio_id;
} pd_portfolio_remove_portfolio_pre_approval_V4_t;

#define PD_CALL_SETTLEMENT_UPDATE_VENUE_DETAILS_V4 1
typedef struct {
    pd_VenueId_t id;
    pd_VenueDetails_t details;
} pd_settlement_update_venue_details_V4_t;

#define PD_CALL_SETTLEMENT_UPDATE_VENUE_TYPE_V4 2
typedef struct {
    pd_VenueId_t id;
    pd_VenueType_t typ;
} pd_settlement_update_venue_type_V4_t;

#define PD_CALL_SETTLEMENT_UPDATE_VENUE_SIGNERS_V4 7
typedef struct {
    pd_VenueId_t id;
    pd_VecAccountId_t signers;
    pd_bool_t add_signers;
} pd_settlement_update_venue_signers_V4_t;

#define PD_CALL_SETTLEMENT_EXECUTE_MANUAL_INSTRUCTION_V4 8
typedef struct {
    pd_InstructionId_t id;
    pd_OptionPortfolioId_t portfolio;
    pd_u32_t fungible_transfers;
    pd_u32_t nfts_transfers;
    pd_u32_t offchain_transfers;
    pd_OptionWeight_t weight_limit;
} pd_settlement_execute_manual_instruction_V4_t;

#define PD_CALL_STO_CREATE_FUNDRAISER_V4 0
typedef struct {
    pd_PortfolioId_t offering_portfolio;
    pd_Ticker_t offering_asset;
    pd_PortfolioId_t raising_portfolio;
    pd_Ticker_t raising_asset;
    pd_VecPriceTier_t tiers;
    pd_VenueId_t venue_id;
    pd_OptionMoment_t start;
    pd_OptionMoment_t end;
    pd_BalanceNoSymbol_t minimum_investment;
    pd_FundraiserName_t fundraiser_name;
} pd_sto_create_fundraiser_V4_t;

#define PD_CALL_STO_INVEST_V4 1
typedef struct {
    pd_PortfolioId_t investment_portfolio;
    pd_PortfolioId_t funding_portfolio;
    pd_Ticker_t offering_asset;
    pd_FundraiserId_t id;
    pd_BalanceNoSymbol_t purchase_amount;
    pd_OptionBalance_t max_price;
    pd_OptionReceiptDetails_t receipt;
} pd_sto_invest_V4_t;

#define PD_CALL_STO_FREEZE_FUNDRAISER_V4 2
typedef struct {
    pd_Ticker_t offering_asset;
    pd_FundraiserId_t id;
} pd_sto_freeze_fundraiser_V4_t;

#define PD_CALL_STO_UNFREEZE_FUNDRAISER_V4 3
typedef struct {
    pd_Ticker_t offering_asset;
    pd_FundraiserId_t id;
} pd_sto_unfreeze_fundraiser_V4_t;

#define PD_CALL_STO_MODIFY_FUNDRAISER_WINDOW_V4 4
typedef struct {
    pd_Ticker_t offering_asset;
    pd_FundraiserId_t id;
    pd_Moment_t start;
    pd_OptionMoment_t end;
} pd_sto_modify_fundraiser_window_V4_t;

#define PD_CALL_STO_STOP_V4 5
typedef struct {
    pd_Ticker_t offering_asset;
    pd_FundraiserId_t id;
} pd_sto_stop_V4_t;

#define PD_CALL_UTILITY_BATCH_ALL_V4 2
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_all_V4_t;

#define PD_CALL_UTILITY_DISPATCH_AS_V4 3
typedef struct {
    pd_BoxPalletsOrigin_t as_origin;
    pd_Call_t call;
} pd_utility_dispatch_as_V4_t;

#define PD_CALL_UTILITY_FORCE_BATCH_V4 4
typedef struct {
    pd_VecCall_t calls;
} pd_utility_force_batch_V4_t;

#define PD_CALL_UTILITY_WITH_WEIGHT_V4 5
typedef struct {
    pd_Call_t call;
    pd_Weight_t weight;
} pd_utility_with_weight_V4_t;

#define PD_CALL_UTILITY_BATCH_OLD_V4 6
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_old_V4_t;

#define PD_CALL_EXTERNALAGENTS_CREATE_GROUP_V4 0
typedef struct {
    pd_Ticker_t ticker;
    pd_ExtrinsicPermissions_t perms;
} pd_externalagents_create_group_V4_t;

#define PD_CALL_EXTERNALAGENTS_SET_GROUP_PERMISSIONS_V4 1
typedef struct {
    pd_Ticker_t ticker;
    pd_AGId_t id;
    pd_ExtrinsicPermissions_t perms;
} pd_externalagents_set_group_permissions_V4_t;

#define PD_CALL_EXTERNALAGENTS_REMOVE_AGENT_V4 2
typedef struct {
    pd_Ticker_t ticker;
    pd_IdentityId_t agent;
} pd_externalagents_remove_agent_V4_t;

#define PD_CALL_EXTERNALAGENTS_ABDICATE_V4 3
typedef struct {
    pd_Ticker_t ticker;
} pd_externalagents_abdicate_V4_t;

#define PD_CALL_EXTERNALAGENTS_CHANGE_GROUP_V4 4
typedef struct {
    pd_Ticker_t ticker;
    pd_IdentityId_t agent;
    pd_AgentGroup_t group;
} pd_externalagents_change_group_V4_t;

#define PD_CALL_EXTERNALAGENTS_ACCEPT_BECOME_AGENT_V4 5
typedef struct {
    pd_u64_t auth_id;
} pd_externalagents_accept_become_agent_V4_t;

#define PD_CALL_EXTERNALAGENTS_CREATE_GROUP_AND_ADD_AUTH_V4 6
typedef struct {
    pd_Ticker_t ticker;
    pd_ExtrinsicPermissions_t perms;
    pd_IdentityId_t target;
    pd_OptionMoment_t expiry;
} pd_externalagents_create_group_and_add_auth_V4_t;

#define PD_CALL_EXTERNALAGENTS_CREATE_AND_CHANGE_CUSTOM_GROUP_V4 7
typedef struct {
    pd_Ticker_t ticker;
    pd_ExtrinsicPermissions_t perms;
    pd_IdentityId_t agent;
} pd_externalagents_create_and_change_custom_group_V4_t;

#define PD_CALL_RELAYER_SET_PAYING_KEY_V4 0
typedef struct {
    pd_AccountId_t user_key;
    pd_Balance_t polyx_limit;
} pd_relayer_set_paying_key_V4_t;

#define PD_CALL_RELAYER_ACCEPT_PAYING_KEY_V4 1
typedef struct {
    pd_u64_t auth_id;
} pd_relayer_accept_paying_key_V4_t;

#define PD_CALL_RELAYER_REMOVE_PAYING_KEY_V4 2
typedef struct {
    pd_AccountId_t user_key;
    pd_AccountId_t paying_key;
} pd_relayer_remove_paying_key_V4_t;

#define PD_CALL_RELAYER_UPDATE_POLYX_LIMIT_V4 3
typedef struct {
    pd_AccountId_t user_key;
    pd_Balance_t polyx_limit;
} pd_relayer_update_polyx_limit_V4_t;

#define PD_CALL_RELAYER_INCREASE_POLYX_LIMIT_V4 4
typedef struct {
    pd_AccountId_t user_key;
    pd_Balance_t amount;
} pd_relayer_increase_polyx_limit_V4_t;

#define PD_CALL_RELAYER_DECREASE_POLYX_LIMIT_V4 5
typedef struct {
    pd_AccountId_t user_key;
    pd_Balance_t amount;
} pd_relayer_decrease_polyx_limit_V4_t;

#define PD_CALL_REWARDS_CLAIM_ITN_REWARD_V4 0
typedef struct {
    pd_AccountId_t _reward_address;
    pd_AccountId_t _itn_address;
    pd_OffChainSignature_t _signature;
} pd_rewards_claim_itn_reward_V4_t;

#define PD_CALL_CONTRACTS_CALL_OLD_WEIGHT_V4 0
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_old_weight_V4_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_OLD_WEIGHT_V4 1
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_old_weight_V4_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_OLD_WEIGHT_V4 2
typedef struct {
    pd_CompactBalance_t amount;
    pd_Compactu64_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_old_weight_V4_t;

#define PD_CALL_CONTRACTS_UPLOAD_CODE_V4 3
typedef struct {
    pd_Vecu8_t code;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Determinism_t determinism;
} pd_contracts_upload_code_V4_t;

#define PD_CALL_CONTRACTS_REMOVE_CODE_V4 4
typedef struct {
    pd_CodeHash_t code_hash;
} pd_contracts_remove_code_V4_t;

#define PD_CALL_CONTRACTS_SET_CODE_V4 5
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CodeHash_t code_hash;
} pd_contracts_set_code_V4_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_WITH_CODE_V4 7
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
} pd_contracts_instantiate_with_code_V4_t;

#define PD_CALL_POLYMESHCONTRACTS_INSTANTIATE_WITH_CODE_PERMS_V4 0
typedef struct {
    pd_Balance_t endowment;
    pd_Weight_t gas_limit;
    pd_OptionBalance_t storage_deposit_limit;
    pd_Vecu8_t code;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
    pd_Permissions_t perms;
} pd_polymeshcontracts_instantiate_with_code_perms_V4_t;

#define PD_CALL_POLYMESHCONTRACTS_INSTANTIATE_WITH_HASH_PERMS_V4 1
typedef struct {
    pd_Balance_t endowment;
    pd_Weight_t gas_limit;
    pd_OptionBalance_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Vecu8_t data;
    pd_Vecu8_t salt;
    pd_Permissions_t perms;
} pd_polymeshcontracts_instantiate_with_hash_perms_V4_t;

#define PD_CALL_POLYMESHCONTRACTS_UPDATE_CALL_RUNTIME_WHITELIST_V4 2
typedef struct {
    pd_VecTupleExtrinsicIdbool_t updates;
} pd_polymeshcontracts_update_call_runtime_whitelist_V4_t;

#define PD_CALL_PREIMAGE_NOTE_PREIMAGE_V4 0
typedef struct {
    pd_Vecu8_t bytes;
} pd_preimage_note_preimage_V4_t;

#define PD_CALL_PREIMAGE_UNNOTE_PREIMAGE_V4 1
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unnote_preimage_V4_t;

#define PD_CALL_PREIMAGE_REQUEST_PREIMAGE_V4 2
typedef struct {
    pd_Hash_t hash;
} pd_preimage_request_preimage_V4_t;

#define PD_CALL_PREIMAGE_UNREQUEST_PREIMAGE_V4 3
typedef struct {
    pd_Hash_t hash;
} pd_preimage_unrequest_preimage_V4_t;

#define PD_CALL_NFT_CREATE_NFT_COLLECTION_V4 0
typedef struct {
    pd_Ticker_t ticker;
    pd_OptionNonFungibleType_t nft_type;
    pd_VecAssetMetadataKey_t collection_keys;
} pd_nft_create_nft_collection_V4_t;

#define PD_CALL_NFT_ISSUE_NFT_V4 1
typedef struct {
    pd_Ticker_t ticker;
    pd_VecNFTMetadataAttribute_t nft_metadata_attributes;
    pd_PortfolioKind_t portfolio_kind;
} pd_nft_issue_nft_V4_t;

#define PD_CALL_NFT_REDEEM_NFT_V4 2
typedef struct {
    pd_Ticker_t ticker;
    pd_NFTId_t nft_id;
    pd_PortfolioKind_t portfolio_kind;
} pd_nft_redeem_nft_V4_t;

#endif

typedef union {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#endif
    pd_bridge_batch_propose_bridge_tx_V4_t bridge_batch_propose_bridge_tx_V4;
    pd_bridge_propose_bridge_tx_V4_t bridge_propose_bridge_tx_V4;
    pd_bridge_handle_bridge_tx_V4_t bridge_handle_bridge_tx_V4;
    pd_bridge_freeze_txs_V4_t bridge_freeze_txs_V4;
    pd_bridge_unfreeze_txs_V4_t bridge_unfreeze_txs_V4;
    pd_bridge_handle_scheduled_bridge_tx_V4_t bridge_handle_scheduled_bridge_tx_V4;
    pd_bridge_add_freeze_admin_V4_t bridge_add_freeze_admin_V4;
    pd_bridge_remove_freeze_admin_V4_t bridge_remove_freeze_admin_V4;
    pd_bridge_remove_txs_V4_t bridge_remove_txs_V4;
    pd_asset_controller_transfer_V4_t asset_controller_transfer_V4;
    pd_asset_register_custom_asset_type_V4_t asset_register_custom_asset_type_V4;
    pd_asset_create_asset_with_custom_type_V4_t asset_create_asset_with_custom_type_V4;
    pd_asset_set_asset_metadata_V4_t asset_set_asset_metadata_V4;
    pd_asset_set_asset_metadata_details_V4_t asset_set_asset_metadata_details_V4;
    pd_asset_register_and_set_local_asset_metadata_V4_t asset_register_and_set_local_asset_metadata_V4;
    pd_asset_register_asset_metadata_local_type_V4_t asset_register_asset_metadata_local_type_V4;
    pd_asset_register_asset_metadata_global_type_V4_t asset_register_asset_metadata_global_type_V4;
    pd_asset_redeem_from_portfolio_V4_t asset_redeem_from_portfolio_V4;
    pd_asset_update_asset_type_V4_t asset_update_asset_type_V4;
    pd_asset_remove_local_metadata_key_V4_t asset_remove_local_metadata_key_V4;
    pd_asset_remove_metadata_value_V4_t asset_remove_metadata_value_V4;
    pd_asset_exempt_ticker_affirmation_V4_t asset_exempt_ticker_affirmation_V4;
    pd_asset_remove_ticker_affirmation_exemption_V4_t asset_remove_ticker_affirmation_exemption_V4;
    pd_asset_pre_approve_ticker_V4_t asset_pre_approve_ticker_V4;
    pd_asset_remove_ticker_pre_approval_V4_t asset_remove_ticker_pre_approval_V4;
    pd_portfolio_quit_portfolio_custody_V4_t portfolio_quit_portfolio_custody_V4;
    pd_portfolio_accept_portfolio_custody_V4_t portfolio_accept_portfolio_custody_V4;
    pd_portfolio_pre_approve_portfolio_V4_t portfolio_pre_approve_portfolio_V4;
    pd_portfolio_remove_portfolio_pre_approval_V4_t portfolio_remove_portfolio_pre_approval_V4;
    pd_settlement_update_venue_details_V4_t settlement_update_venue_details_V4;
    pd_settlement_update_venue_type_V4_t settlement_update_venue_type_V4;
    pd_settlement_update_venue_signers_V4_t settlement_update_venue_signers_V4;
    pd_settlement_execute_manual_instruction_V4_t settlement_execute_manual_instruction_V4;
    pd_sto_create_fundraiser_V4_t sto_create_fundraiser_V4;
    pd_sto_invest_V4_t sto_invest_V4;
    pd_sto_freeze_fundraiser_V4_t sto_freeze_fundraiser_V4;
    pd_sto_unfreeze_fundraiser_V4_t sto_unfreeze_fundraiser_V4;
    pd_sto_modify_fundraiser_window_V4_t sto_modify_fundraiser_window_V4;
    pd_sto_stop_V4_t sto_stop_V4;
    pd_utility_batch_all_V4_t utility_batch_all_V4;
    pd_utility_dispatch_as_V4_t utility_dispatch_as_V4;
    pd_utility_force_batch_V4_t utility_force_batch_V4;
    pd_utility_with_weight_V4_t utility_with_weight_V4;
    pd_utility_batch_old_V4_t utility_batch_old_V4;
    pd_externalagents_create_group_V4_t externalagents_create_group_V4;
    pd_externalagents_set_group_permissions_V4_t externalagents_set_group_permissions_V4;
    pd_externalagents_remove_agent_V4_t externalagents_remove_agent_V4;
    pd_externalagents_abdicate_V4_t externalagents_abdicate_V4;
    pd_externalagents_change_group_V4_t externalagents_change_group_V4;
    pd_externalagents_accept_become_agent_V4_t externalagents_accept_become_agent_V4;
    pd_externalagents_create_group_and_add_auth_V4_t externalagents_create_group_and_add_auth_V4;
    pd_externalagents_create_and_change_custom_group_V4_t externalagents_create_and_change_custom_group_V4;
    pd_relayer_set_paying_key_V4_t relayer_set_paying_key_V4;
    pd_relayer_accept_paying_key_V4_t relayer_accept_paying_key_V4;
    pd_relayer_remove_paying_key_V4_t relayer_remove_paying_key_V4;
    pd_relayer_update_polyx_limit_V4_t relayer_update_polyx_limit_V4;
    pd_relayer_increase_polyx_limit_V4_t relayer_increase_polyx_limit_V4;
    pd_relayer_decrease_polyx_limit_V4_t relayer_decrease_polyx_limit_V4;
    pd_rewards_claim_itn_reward_V4_t rewards_claim_itn_reward_V4;
    pd_contracts_call_old_weight_V4_t contracts_call_old_weight_V4;
    pd_contracts_instantiate_with_code_old_weight_V4_t contracts_instantiate_with_code_old_weight_V4;
    pd_contracts_instantiate_old_weight_V4_t contracts_instantiate_old_weight_V4;
    pd_contracts_upload_code_V4_t contracts_upload_code_V4;
    pd_contracts_remove_code_V4_t contracts_remove_code_V4;
    pd_contracts_set_code_V4_t contracts_set_code_V4;
    pd_contracts_instantiate_with_code_V4_t contracts_instantiate_with_code_V4;
    pd_polymeshcontracts_instantiate_with_code_perms_V4_t polymeshcontracts_instantiate_with_code_perms_V4;
    pd_polymeshcontracts_instantiate_with_hash_perms_V4_t polymeshcontracts_instantiate_with_hash_perms_V4;
    pd_polymeshcontracts_update_call_runtime_whitelist_V4_t polymeshcontracts_update_call_runtime_whitelist_V4;
    pd_preimage_note_preimage_V4_t preimage_note_preimage_V4;
    pd_preimage_unnote_preimage_V4_t preimage_unnote_preimage_V4;
    pd_preimage_request_preimage_V4_t preimage_request_preimage_V4;
    pd_preimage_unrequest_preimage_V4_t preimage_unrequest_preimage_V4;
    pd_nft_create_nft_collection_V4_t nft_create_nft_collection_V4;
    pd_nft_issue_nft_V4_t nft_issue_nft_V4;
    pd_nft_redeem_nft_V4_t nft_redeem_nft_V4;
#endif
} pd_MethodBasic_V4_t;

#define PD_CALL_BALANCES_TRANSFER_V4 0
typedef struct {
    pd_LookupasStaticLookupSource_t dest;
    pd_CompactBalance_t amount;
} pd_balances_transfer_V4_t;

#define PD_CALL_BALANCES_TRANSFER_WITH_MEMO_V4 1
typedef struct {
    pd_LookupasStaticLookupSource_t dest;
    pd_CompactBalance_t amount;
    pd_OptionMemo_t memo;
} pd_balances_transfer_with_memo_V4_t;

#define PD_CALL_IDENTITY_ACCEPT_PRIMARY_KEY_V4 2
typedef struct {
    pd_u64_t rotation_auth_id;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_identity_accept_primary_key_V4_t;

#define PD_CALL_IDENTITY_JOIN_IDENTITY_AS_KEY_V4 4
typedef struct {
    pd_u64_t auth_id;
} pd_identity_join_identity_as_key_V4_t;

#define PD_CALL_IDENTITY_LEAVE_IDENTITY_AS_KEY_V4 5
typedef struct {
} pd_identity_leave_identity_as_key_V4_t;

#define PD_CALL_IDENTITY_ADD_CLAIM_V4 6
typedef struct {
    pd_IdentityId_t target;
    pd_Claim_t claim;
    pd_OptionMoment_t expiry;
} pd_identity_add_claim_V4_t;

#define PD_CALL_IDENTITY_REVOKE_CLAIM_V4 7
typedef struct {
    pd_IdentityId_t target;
    pd_Claim_t claim;
} pd_identity_revoke_claim_V4_t;

#define PD_CALL_IDENTITY_FREEZE_SECONDARY_KEYS_V4 8
typedef struct {
} pd_identity_freeze_secondary_keys_V4_t;

#define PD_CALL_IDENTITY_UNFREEZE_SECONDARY_KEYS_V4 9
typedef struct {
} pd_identity_unfreeze_secondary_keys_V4_t;

#define PD_CALL_IDENTITY_ADD_AUTHORIZATION_V4 10
typedef struct {
    pd_SignatoryAccountId_t target;
    pd_AuthorizationDataAccountId_t data;
    pd_OptionMoment_t expiry;
} pd_identity_add_authorization_V4_t;

#define PD_CALL_IDENTITY_REMOVE_AUTHORIZATION_V4 11
typedef struct {
    pd_SignatoryAccountId_t target;
    pd_u64_t auth_id;
    pd_bool_t _auth_issuer_pays;
} pd_identity_remove_authorization_V4_t;

#define PD_CALL_IDENTITY_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION_V4 16
typedef struct {
    pd_VecSecondaryKeyWithAuthAccountId_t additional_keys;
    pd_Moment_t expires_at;
} pd_identity_add_secondary_keys_with_authorization_V4_t;

#define PD_CALL_IDENTITY_REMOVE_SECONDARY_KEYS_V4 18
typedef struct {
    pd_VecAccountId_t keys_to_remove;
} pd_identity_remove_secondary_keys_V4_t;

#define PD_CALL_MULTISIG_CREATE_MULTISIG_V4 0
typedef struct {
    pd_VecSignatoryAccountId_t signers;
    pd_u64_t sigs_required;
} pd_multisig_create_multisig_V4_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY_V4 1
typedef struct {
    pd_AccountId_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_identity_V4_t;

#define PD_CALL_MULTISIG_CREATE_OR_APPROVE_PROPOSAL_AS_KEY_V4 2
typedef struct {
    pd_AccountId_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_or_approve_proposal_as_key_V4_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_IDENTITY_V4 3
typedef struct {
    pd_AccountId_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_identity_V4_t;

#define PD_CALL_MULTISIG_CREATE_PROPOSAL_AS_KEY_V4 4
typedef struct {
    pd_AccountId_t multisig;
    pd_Proposal_t proposal;
    pd_OptionMoment_t expiry;
    pd_bool_t auto_close;
} pd_multisig_create_proposal_as_key_V4_t;

#define PD_CALL_MULTISIG_APPROVE_AS_IDENTITY_V4 5
typedef struct {
    pd_AccountId_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_identity_V4_t;

#define PD_CALL_MULTISIG_APPROVE_AS_KEY_V4 6
typedef struct {
    pd_AccountId_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_approve_as_key_V4_t;

#define PD_CALL_MULTISIG_REJECT_AS_IDENTITY_V4 7
typedef struct {
    pd_AccountId_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_identity_V4_t;

#define PD_CALL_MULTISIG_REJECT_AS_KEY_V4 8
typedef struct {
    pd_AccountId_t multisig;
    pd_u64_t proposal_id;
} pd_multisig_reject_as_key_V4_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY_V4 9
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_identity_V4_t;

#define PD_CALL_MULTISIG_ACCEPT_MULTISIG_SIGNER_AS_KEY_V4 10
typedef struct {
    pd_u64_t auth_id;
} pd_multisig_accept_multisig_signer_as_key_V4_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNER_V4 11
typedef struct {
    pd_SignatoryAccountId_t signer;
} pd_multisig_add_multisig_signer_V4_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNER_V4 12
typedef struct {
    pd_SignatoryAccountId_t signer;
} pd_multisig_remove_multisig_signer_V4_t;

#define PD_CALL_MULTISIG_ADD_MULTISIG_SIGNERS_VIA_CREATOR_V4 13
typedef struct {
    pd_AccountId_t multisig;
    pd_VecSignatoryAccountId_t signers;
} pd_multisig_add_multisig_signers_via_creator_V4_t;

#define PD_CALL_MULTISIG_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR_V4 14
typedef struct {
    pd_AccountId_t multisig;
    pd_VecSignatoryAccountId_t signers;
} pd_multisig_remove_multisig_signers_via_creator_V4_t;

#define PD_CALL_MULTISIG_CHANGE_SIGS_REQUIRED_V4 15
typedef struct {
    pd_u64_t sigs_required;
} pd_multisig_change_sigs_required_V4_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_PRIMARY_V4 17
typedef struct {
    pd_AccountId_t multisig;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_multisig_make_multisig_primary_V4_t;

#define PD_CALL_MULTISIG_EXECUTE_SCHEDULED_PROPOSAL_V4 18
typedef struct {
    pd_AccountId_t multisig;
    pd_u64_t proposal_id;
    pd_IdentityId_t multisig_did;
    pd_Weight_t _proposal_weight;
} pd_multisig_execute_scheduled_proposal_V4_t;

#define PD_CALL_STAKING_BOND_V4 0
typedef struct {
    pd_LookupasStaticLookupSource_t controller;
    pd_CompactBalance_t amount;
    pd_RewardDestination_t payee;
} pd_staking_bond_V4_t;

#define PD_CALL_STAKING_BOND_EXTRA_V4 1
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_bond_extra_V4_t;

#define PD_CALL_STAKING_UNBOND_V4 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_unbond_V4_t;

#define PD_CALL_STAKING_WITHDRAW_UNBONDED_V4 3
typedef struct {
    pd_u32_t num_slashing_spans;
} pd_staking_withdraw_unbonded_V4_t;

#define PD_CALL_STAKING_VALIDATE_V4 4
typedef struct {
    pd_ValidatorPrefs_t prefs;
} pd_staking_validate_V4_t;

#define PD_CALL_STAKING_NOMINATE_V4 5
typedef struct {
    pd_VecLookupasStaticLookupSource_t targets;
} pd_staking_nominate_V4_t;

#define PD_CALL_STAKING_CHILL_V4 6
typedef struct {
} pd_staking_chill_V4_t;

#define PD_CALL_STAKING_SET_PAYEE_V4 7
typedef struct {
    pd_RewardDestination_t payee;
} pd_staking_set_payee_V4_t;

#define PD_CALL_STAKING_SET_CONTROLLER_V4 8
typedef struct {
    pd_LookupasStaticLookupSource_t controller;
} pd_staking_set_controller_V4_t;

#define PD_CALL_STAKING_REBOND_V4 24
typedef struct {
    pd_CompactBalance_t amount;
} pd_staking_rebond_V4_t;

#define PD_CALL_PIPS_PROPOSE_V4 6
typedef struct {
    pd_Proposal_t proposal;
    pd_Balance_t deposit;
    pd_OptionUrl_t url;
    pd_OptionPipDescription_t description;
} pd_pips_propose_V4_t;

#define PD_CALL_PIPS_VOTE_V4 7
typedef struct {
    pd_PipId_t id;
    pd_bool_t aye_or_nay;
    pd_Balance_t deposit;
} pd_pips_vote_V4_t;

#define PD_CALL_UTILITY_BATCH_V4 0
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_V4_t;

#define PD_CALL_UTILITY_BATCH_ATOMIC_V4 7
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_atomic_V4_t;

#define PD_CALL_UTILITY_BATCH_OPTIMISTIC_V4 8
typedef struct {
    pd_VecCall_t calls;
} pd_utility_batch_optimistic_V4_t;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
#define PD_CALL_CORPORATEACTION_SET_MAX_DETAILS_LENGTH_V4 0
typedef struct {
    pd_u32_t length;
} pd_corporateaction_set_max_details_length_V4_t;
#define PD_CALL_CORPORATEACTION_SET_DEFAULT_TARGETS_V4 1
typedef struct {
    pd_Ticker_t ticker;
    pd_TargetIdentities_t targets;
} pd_corporateaction_set_default_targets_V4_t;
#define PD_CALL_CORPORATEACTION_SET_DEFAULT_WITHHOLDING_TAX_V4 2
typedef struct {
    pd_Ticker_t ticker;
    pd_Tax_t tax;
} pd_corporateaction_set_default_withholding_tax_V4_t;
#define PD_CALL_CORPORATEACTION_SET_DID_WITHHOLDING_TAX_V4 3
typedef struct {
    pd_Ticker_t ticker;
    pd_IdentityId_t taxed_did;
    pd_OptionTax_t tax;
} pd_corporateaction_set_did_withholding_tax_V4_t;
#define PD_CALL_CORPORATEACTION_INITIATE_CORPORATE_ACTION_V4 4
typedef struct {
    pd_Ticker_t ticker;
    pd_CAKind_t kind;
    pd_Moment_t decl_date;
    pd_OptionRecordDateSpec_t record_date;
    pd_CADetails_t details;
    pd_OptionTargetIdentities_t targets;
    pd_OptionTax_t default_withholding_tax;
    pd_OptionVecTupleIdentityIdTax_t withholding_tax;
} pd_corporateaction_initiate_corporate_action_V4_t;
#define PD_CALL_CORPORATEACTION_LINK_CA_DOC_V4 5
typedef struct {
    pd_CAId_t id;
    pd_VecDocumentId_t docs;
} pd_corporateaction_link_ca_doc_V4_t;
#define PD_CALL_CORPORATEACTION_REMOVE_CA_V4 6
typedef struct {
    pd_CAId_t ca_id;
} pd_corporateaction_remove_ca_V4_t;
#define PD_CALL_CORPORATEACTION_CHANGE_RECORD_DATE_V4 7
typedef struct {
    pd_CAId_t ca_id;
    pd_OptionRecordDateSpec_t record_date;
} pd_corporateaction_change_record_date_V4_t;
#define PD_CALL_CORPORATEACTION_INITIATE_CORPORATE_ACTION_AND_DISTRIBUTE_V4 8
typedef struct {
    pd_InitiateCorporateActionArgs_t ca_args;
    pd_OptionPortfolioNumber_t portfolio;
    pd_Ticker_t currency;
    pd_Balance_t per_share;
    pd_Balance_t amount;
    pd_Moment_t payment_at;
    pd_OptionMoment_t expires_at;
} pd_corporateaction_initiate_corporate_action_and_distribute_V4_t;
#define PD_CALL_CORPORATEBALLOT_ATTACH_BALLOT_V4 0
typedef struct {
    pd_CAId_t ca_id;
    pd_BallotTimeRange_t range;
    pd_BallotMeta_t meta;
    pd_bool_t rcv;
} pd_corporateballot_attach_ballot_V4_t;
#define PD_CALL_CORPORATEBALLOT_VOTE_V4 1
typedef struct {
    pd_CAId_t ca_id;
    pd_VecBallotVote_t votes;
} pd_corporateballot_vote_V4_t;
#define PD_CALL_CORPORATEBALLOT_CHANGE_END_V4 2
typedef struct {
    pd_CAId_t ca_id;
    pd_Moment_t end;
} pd_corporateballot_change_end_V4_t;
#define PD_CALL_CORPORATEBALLOT_CHANGE_META_V4 3
typedef struct {
    pd_CAId_t ca_id;
    pd_BallotMeta_t meta;
} pd_corporateballot_change_meta_V4_t;
#define PD_CALL_CORPORATEBALLOT_CHANGE_RCV_V4 4
typedef struct {
    pd_CAId_t ca_id;
    pd_bool_t rcv;
} pd_corporateballot_change_rcv_V4_t;
#define PD_CALL_CORPORATEBALLOT_REMOVE_BALLOT_V4 5
typedef struct {
    pd_CAId_t ca_id;
} pd_corporateballot_remove_ballot_V4_t;
#endif
#define PD_CALL_SYSTEM_REMARK_V4 0
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_V4_t;

#define PD_CALL_SYSTEM_SET_HEAP_PAGES_V4 1
typedef struct {
    pd_u64_t pages;
} pd_system_set_heap_pages_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_V4 2
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_V4_t;

#define PD_CALL_SYSTEM_SET_CODE_WITHOUT_CHECKS_V4 3
typedef struct {
    pd_Vecu8_t code;
} pd_system_set_code_without_checks_V4_t;

#define PD_CALL_SYSTEM_REMARK_WITH_EVENT_V4 7
typedef struct {
    pd_Bytes_t remark;
} pd_system_remark_with_event_V4_t;

#define PD_CALL_TIMESTAMP_SET_V4 0
typedef struct {
    pd_Compactu64_t now;
} pd_timestamp_set_V4_t;

#define PD_CALL_INDICES_CLAIM_V4 0
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_claim_V4_t;

#define PD_CALL_INDICES_TRANSFER_V4 1
typedef struct {
    pd_AccountIdLookupOfT_t new_;
    pd_AccountIndex_t index;
} pd_indices_transfer_V4_t;

#define PD_CALL_INDICES_FREE_V4 2
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_free_V4_t;

#define PD_CALL_INDICES_FORCE_TRANSFER_V4 3
typedef struct {
    pd_AccountIdLookupOfT_t new_;
    pd_AccountIndex_t index;
    pd_bool_t freeze;
} pd_indices_force_transfer_V4_t;

#define PD_CALL_INDICES_FREEZE_V4 4
typedef struct {
    pd_AccountIndex_t index;
} pd_indices_freeze_V4_t;

#define PD_CALL_BALANCES_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE_V4 2
typedef struct {
    pd_CompactBalance_t amount;
} pd_balances_deposit_block_reward_reserve_balance_V4_t;

#define PD_CALL_BALANCES_SET_BALANCE_V4 3
typedef struct {
    pd_LookupasStaticLookupSource_t who;
    pd_CompactBalance_t new_free;
    pd_CompactBalance_t new_reserved;
} pd_balances_set_balance_V4_t;

#define PD_CALL_BALANCES_FORCE_TRANSFER_V4 4
typedef struct {
    pd_LookupasStaticLookupSource_t source;
    pd_LookupasStaticLookupSource_t dest;
    pd_CompactBalance_t amount;
} pd_balances_force_transfer_V4_t;

#define PD_CALL_BALANCES_BURN_ACCOUNT_BALANCE_V4 5
typedef struct {
    pd_Balance_t amount;
} pd_balances_burn_account_balance_V4_t;

#define PD_CALL_IDENTITY_CDD_REGISTER_DID_V4 0
typedef struct {
    pd_AccountId_t target_account;
    pd_VecSecondaryKeyAccountId_t secondary_keys;
} pd_identity_cdd_register_did_V4_t;

#define PD_CALL_IDENTITY_INVALIDATE_CDD_CLAIMS_V4 1
typedef struct {
    pd_IdentityId_t cdd;
    pd_Moment_t disable_from;
    pd_OptionMoment_t expiry;
} pd_identity_invalidate_cdd_claims_V4_t;

#define PD_CALL_IDENTITY_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION_V4 3
typedef struct {
    pd_bool_t auth_required;
} pd_identity_change_cdd_requirement_for_mk_rotation_V4_t;

#define PD_CALL_IDENTITY_GC_ADD_CDD_CLAIM_V4 12
typedef struct {
    pd_IdentityId_t target;
} pd_identity_gc_add_cdd_claim_V4_t;

#define PD_CALL_IDENTITY_GC_REVOKE_CDD_CLAIM_V4 13
typedef struct {
    pd_IdentityId_t target;
} pd_identity_gc_revoke_cdd_claim_V4_t;

#define PD_CALL_IDENTITY_REVOKE_CLAIM_BY_INDEX_V4 14
typedef struct {
    pd_IdentityId_t target;
    pd_ClaimType_t claim_type;
    pd_OptionScope_t scope;
} pd_identity_revoke_claim_by_index_V4_t;

#define PD_CALL_IDENTITY_ROTATE_PRIMARY_KEY_TO_SECONDARY_V4 15
typedef struct {
    pd_u64_t auth_id;
    pd_Optionu64_t optional_cdd_auth_id;
} pd_identity_rotate_primary_key_to_secondary_V4_t;

#define PD_CALL_IDENTITY_SET_SECONDARY_KEY_PERMISSIONS_V4 17
typedef struct {
    pd_AccountId_t key;
    pd_Permissions_t perms;
} pd_identity_set_secondary_key_permissions_V4_t;

#define PD_CALL_IDENTITY_REGISTER_CUSTOM_CLAIM_TYPE_V4 19
typedef struct {
    pd_Vecu8_t ty;
} pd_identity_register_custom_claim_type_V4_t;

#define PD_CALL_IDENTITY_CDD_REGISTER_DID_WITH_CDD_V4 20
typedef struct {
    pd_AccountId_t target_account;
    pd_VecSecondaryKeyAccountId_t secondary_keys;
    pd_OptionMoment_t expiry;
} pd_identity_cdd_register_did_with_cdd_V4_t;

#define PD_CALL_IDENTITY_CREATE_CHILD_IDENTITY_V4 21
typedef struct {
    pd_AccountId_t secondary_key;
} pd_identity_create_child_identity_V4_t;

#define PD_CALL_IDENTITY_CREATE_CHILD_IDENTITIES_V4 22
typedef struct {
    pd_VecCreateChildIdentityWithAuthAccountId_t child_keys;
    pd_Moment_t expires_at;
} pd_identity_create_child_identities_V4_t;

#define PD_CALL_IDENTITY_UNLINK_CHILD_IDENTITY_V4 23
typedef struct {
    pd_IdentityId_t child_did;
} pd_identity_unlink_child_identity_V4_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SET_ACTIVE_MEMBERS_LIMIT_V4 0
typedef struct {
    pd_MemberCount_t limit;
} pd_cddserviceproviders_set_active_members_limit_V4_t;

#define PD_CALL_CDDSERVICEPROVIDERS_DISABLE_MEMBER_V4 1
typedef struct {
    pd_IdentityId_t who;
    pd_OptionMoment_t expiry;
    pd_OptionMoment_t at;
} pd_cddserviceproviders_disable_member_V4_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ADD_MEMBER_V4 2
typedef struct {
    pd_IdentityId_t who;
} pd_cddserviceproviders_add_member_V4_t;

#define PD_CALL_CDDSERVICEPROVIDERS_REMOVE_MEMBER_V4 3
typedef struct {
    pd_IdentityId_t who;
} pd_cddserviceproviders_remove_member_V4_t;

#define PD_CALL_CDDSERVICEPROVIDERS_SWAP_MEMBER_V4 4
typedef struct {
    pd_IdentityId_t remove;
    pd_IdentityId_t add;
} pd_cddserviceproviders_swap_member_V4_t;

#define PD_CALL_CDDSERVICEPROVIDERS_RESET_MEMBERS_V4 5
typedef struct {
    pd_VecIdentityId_t members;
} pd_cddserviceproviders_reset_members_V4_t;

#define PD_CALL_CDDSERVICEPROVIDERS_ABDICATE_MEMBERSHIP_V4 6
typedef struct {
} pd_cddserviceproviders_abdicate_membership_V4_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_VOTE_THRESHOLD_V4 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_polymeshcommittee_set_vote_threshold_V4_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_RELEASE_COORDINATOR_V4 1
typedef struct {
    pd_IdentityId_t id;
} pd_polymeshcommittee_set_release_coordinator_V4_t;

#define PD_CALL_POLYMESHCOMMITTEE_SET_EXPIRES_AFTER_V4 2
typedef struct {
    pd_MaybeBlockBlockNumber_t expiry;
} pd_polymeshcommittee_set_expires_after_V4_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_OR_PROPOSE_V4 3
typedef struct {
    pd_bool_t approve;
    pd_Proposal_t call;
} pd_polymeshcommittee_vote_or_propose_V4_t;

#define PD_CALL_POLYMESHCOMMITTEE_VOTE_V4 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_t index;
    pd_bool_t approve;
} pd_polymeshcommittee_vote_V4_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V4 0
typedef struct {
    pd_MemberCount_t limit;
} pd_committeemembership_set_active_members_limit_V4_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_DISABLE_MEMBER_V4 1
typedef struct {
    pd_IdentityId_t who;
    pd_OptionMoment_t expiry;
    pd_OptionMoment_t at;
} pd_committeemembership_disable_member_V4_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ADD_MEMBER_V4 2
typedef struct {
    pd_IdentityId_t who;
} pd_committeemembership_add_member_V4_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_REMOVE_MEMBER_V4 3
typedef struct {
    pd_IdentityId_t who;
} pd_committeemembership_remove_member_V4_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_SWAP_MEMBER_V4 4
typedef struct {
    pd_IdentityId_t remove;
    pd_IdentityId_t add;
} pd_committeemembership_swap_member_V4_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_RESET_MEMBERS_V4 5
typedef struct {
    pd_VecIdentityId_t members;
} pd_committeemembership_reset_members_V4_t;

#define PD_CALL_COMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V4 6
typedef struct {
} pd_committeemembership_abdicate_membership_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_VOTE_THRESHOLD_V4 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_technicalcommittee_set_vote_threshold_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_RELEASE_COORDINATOR_V4 1
typedef struct {
    pd_IdentityId_t id;
} pd_technicalcommittee_set_release_coordinator_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_SET_EXPIRES_AFTER_V4 2
typedef struct {
    pd_MaybeBlockBlockNumber_t expiry;
} pd_technicalcommittee_set_expires_after_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_OR_PROPOSE_V4 3
typedef struct {
    pd_bool_t approve;
    pd_Proposal_t call;
} pd_technicalcommittee_vote_or_propose_V4_t;

#define PD_CALL_TECHNICALCOMMITTEE_VOTE_V4 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_t index;
    pd_bool_t approve;
} pd_technicalcommittee_vote_V4_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V4 0
typedef struct {
    pd_MemberCount_t limit;
} pd_technicalcommitteemembership_set_active_members_limit_V4_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V4 1
typedef struct {
    pd_IdentityId_t who;
    pd_OptionMoment_t expiry;
    pd_OptionMoment_t at;
} pd_technicalcommitteemembership_disable_member_V4_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ADD_MEMBER_V4 2
typedef struct {
    pd_IdentityId_t who;
} pd_technicalcommitteemembership_add_member_V4_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V4 3
typedef struct {
    pd_IdentityId_t who;
} pd_technicalcommitteemembership_remove_member_V4_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_SWAP_MEMBER_V4 4
typedef struct {
    pd_IdentityId_t remove;
    pd_IdentityId_t add;
} pd_technicalcommitteemembership_swap_member_V4_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_RESET_MEMBERS_V4 5
typedef struct {
    pd_VecIdentityId_t members;
} pd_technicalcommitteemembership_reset_members_V4_t;

#define PD_CALL_TECHNICALCOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V4 6
typedef struct {
} pd_technicalcommitteemembership_abdicate_membership_V4_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_VOTE_THRESHOLD_V4 0
typedef struct {
    pd_u32_t n;
    pd_u32_t d;
} pd_upgradecommittee_set_vote_threshold_V4_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_RELEASE_COORDINATOR_V4 1
typedef struct {
    pd_IdentityId_t id;
} pd_upgradecommittee_set_release_coordinator_V4_t;

#define PD_CALL_UPGRADECOMMITTEE_SET_EXPIRES_AFTER_V4 2
typedef struct {
    pd_MaybeBlockBlockNumber_t expiry;
} pd_upgradecommittee_set_expires_after_V4_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_OR_PROPOSE_V4 3
typedef struct {
    pd_bool_t approve;
    pd_Proposal_t call;
} pd_upgradecommittee_vote_or_propose_V4_t;

#define PD_CALL_UPGRADECOMMITTEE_VOTE_V4 4
typedef struct {
    pd_Hash_t proposal;
    pd_ProposalIndex_t index;
    pd_bool_t approve;
} pd_upgradecommittee_vote_V4_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SET_ACTIVE_MEMBERS_LIMIT_V4 0
typedef struct {
    pd_MemberCount_t limit;
} pd_upgradecommitteemembership_set_active_members_limit_V4_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_DISABLE_MEMBER_V4 1
typedef struct {
    pd_IdentityId_t who;
    pd_OptionMoment_t expiry;
    pd_OptionMoment_t at;
} pd_upgradecommitteemembership_disable_member_V4_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ADD_MEMBER_V4 2
typedef struct {
    pd_IdentityId_t who;
} pd_upgradecommitteemembership_add_member_V4_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_REMOVE_MEMBER_V4 3
typedef struct {
    pd_IdentityId_t who;
} pd_upgradecommitteemembership_remove_member_V4_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_SWAP_MEMBER_V4 4
typedef struct {
    pd_IdentityId_t remove;
    pd_IdentityId_t add;
} pd_upgradecommitteemembership_swap_member_V4_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_RESET_MEMBERS_V4 5
typedef struct {
    pd_VecIdentityId_t members;
} pd_upgradecommitteemembership_reset_members_V4_t;

#define PD_CALL_UPGRADECOMMITTEEMEMBERSHIP_ABDICATE_MEMBERSHIP_V4 6
typedef struct {
} pd_upgradecommitteemembership_abdicate_membership_V4_t;

#define PD_CALL_MULTISIG_MAKE_MULTISIG_SECONDARY_V4 16
typedef struct {
    pd_AccountId_t multisig;
} pd_multisig_make_multisig_secondary_V4_t;

#define PD_CALL_MULTISIG_CHANGE_SIGS_REQUIRED_VIA_CREATOR_V4 19
typedef struct {
    pd_AccountId_t multisig_account;
    pd_u64_t signatures_required;
} pd_multisig_change_sigs_required_via_creator_V4_t;

#define PD_CALL_MULTISIG_REMOVE_CREATOR_CONTROLS_V4 20
typedef struct {
    pd_AccountId_t multisig_account;
} pd_multisig_remove_creator_controls_V4_t;

#define PD_CALL_BRIDGE_CHANGE_CONTROLLER_V4 0
typedef struct {
    pd_AccountId_t controller;
} pd_bridge_change_controller_V4_t;

#define PD_CALL_BRIDGE_CHANGE_ADMIN_V4 1
typedef struct {
    pd_AccountId_t admin;
} pd_bridge_change_admin_V4_t;

#define PD_CALL_BRIDGE_CHANGE_TIMELOCK_V4 2
typedef struct {
    pd_BlockNumber_t timelock;
} pd_bridge_change_timelock_V4_t;

#define PD_CALL_BRIDGE_FREEZE_V4 3
typedef struct {
} pd_bridge_freeze_V4_t;

#define PD_CALL_BRIDGE_UNFREEZE_V4 4
typedef struct {
} pd_bridge_unfreeze_V4_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_LIMIT_V4 5
typedef struct {
    pd_Balance_t amount;
    pd_BlockNumber_t duration;
} pd_bridge_change_bridge_limit_V4_t;

#define PD_CALL_BRIDGE_CHANGE_BRIDGE_EXEMPTED_V4 6
typedef struct {
    pd_VecTupleIdentityIdbool_t exempted;
} pd_bridge_change_bridge_exempted_V4_t;

#define PD_CALL_BRIDGE_FORCE_HANDLE_BRIDGE_TX_V4 7
typedef struct {
    pd_BridgeTxAccountId_t bridge_tx;
} pd_bridge_force_handle_bridge_tx_V4_t;

#define PD_CALL_STAKING_SET_VALIDATOR_COUNT_V4 9
typedef struct {
    pd_Compactu32_t new_;
} pd_staking_set_validator_count_V4_t;

#define PD_CALL_STAKING_INCREASE_VALIDATOR_COUNT_V4 10
typedef struct {
    pd_Compactu32_t additional;
} pd_staking_increase_validator_count_V4_t;

#define PD_CALL_STAKING_SCALE_VALIDATOR_COUNT_V4 11
typedef struct {
    pd_Percent_t factor;
} pd_staking_scale_validator_count_V4_t;

#define PD_CALL_STAKING_ADD_PERMISSIONED_VALIDATOR_V4 12
typedef struct {
    pd_IdentityId_t identity;
    pd_Optionu32_t intended_count;
} pd_staking_add_permissioned_validator_V4_t;

#define PD_CALL_STAKING_REMOVE_PERMISSIONED_VALIDATOR_V4 13
typedef struct {
    pd_IdentityId_t identity;
} pd_staking_remove_permissioned_validator_V4_t;

#define PD_CALL_STAKING_VALIDATE_CDD_EXPIRY_NOMINATORS_V4 14
typedef struct {
    pd_VecAccountId_t targets;
} pd_staking_validate_cdd_expiry_nominators_V4_t;

#define PD_CALL_STAKING_SET_COMMISSION_CAP_V4 15
typedef struct {
    pd_Perbill_t new_cap;
} pd_staking_set_commission_cap_V4_t;

#define PD_CALL_STAKING_SET_MIN_BOND_THRESHOLD_V4 16
typedef struct {
    pd_Balance_t new_value;
} pd_staking_set_min_bond_threshold_V4_t;

#define PD_CALL_STAKING_FORCE_NO_ERAS_V4 17
typedef struct {
} pd_staking_force_no_eras_V4_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_V4 18
typedef struct {
} pd_staking_force_new_era_V4_t;

#define PD_CALL_STAKING_SET_INVULNERABLES_V4 19
typedef struct {
    pd_VecAccountId_t invulnerables;
} pd_staking_set_invulnerables_V4_t;

#define PD_CALL_STAKING_FORCE_UNSTAKE_V4 20
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_force_unstake_V4_t;

#define PD_CALL_STAKING_FORCE_NEW_ERA_ALWAYS_V4 21
typedef struct {
} pd_staking_force_new_era_always_V4_t;

#define PD_CALL_STAKING_CANCEL_DEFERRED_SLASH_V4 22
typedef struct {
    pd_EraIndex_t era;
    pd_Vecu32_t slash_indices;
} pd_staking_cancel_deferred_slash_V4_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_V4 23
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_V4_t;

#define PD_CALL_STAKING_SET_HISTORY_DEPTH_V4 25
typedef struct {
    pd_Compactu32_t new_history_depth;
    pd_Compactu32_t _era_items_deleted;
} pd_staking_set_history_depth_V4_t;

#define PD_CALL_STAKING_REAP_STASH_V4 26
typedef struct {
    pd_AccountId_t stash;
    pd_u32_t num_slashing_spans;
} pd_staking_reap_stash_V4_t;

#define PD_CALL_STAKING_PAYOUT_STAKERS_BY_SYSTEM_V4 29
typedef struct {
    pd_AccountId_t validator_stash;
    pd_EraIndex_t era;
} pd_staking_payout_stakers_by_system_V4_t;

#define PD_CALL_STAKING_CHANGE_SLASHING_ALLOWED_FOR_V4 30
typedef struct {
    pd_SlashingSwitch_t slashing_switch;
} pd_staking_change_slashing_allowed_for_V4_t;

#define PD_CALL_STAKING_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT_V4 31
typedef struct {
    pd_IdentityId_t identity;
    pd_u32_t new_intended_count;
} pd_staking_update_permissioned_validator_intended_count_V4_t;

#define PD_CALL_STAKING_CHILL_FROM_GOVERNANCE_V4 32
typedef struct {
    pd_IdentityId_t identity;
    pd_VecAccountId_t stash_keys;
} pd_staking_chill_from_governance_V4_t;

#define PD_CALL_SESSION_SET_KEYS_V4 0
typedef struct {
    pd_Keys_t keys;
    pd_Bytes_t proof;
} pd_session_set_keys_V4_t;

#define PD_CALL_SESSION_PURGE_KEYS_V4 1
typedef struct {
} pd_session_purge_keys_V4_t;

#define PD_CALL_ASSET_REGISTER_TICKER_V4 0
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_register_ticker_V4_t;

#define PD_CALL_ASSET_ACCEPT_TICKER_TRANSFER_V4 1
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_ticker_transfer_V4_t;

#define PD_CALL_ASSET_ACCEPT_ASSET_OWNERSHIP_TRANSFER_V4 2
typedef struct {
    pd_u64_t auth_id;
} pd_asset_accept_asset_ownership_transfer_V4_t;

#define PD_CALL_ASSET_CREATE_ASSET_V4 3
typedef struct {
    pd_AssetName_t name;
    pd_Ticker_t ticker;
    pd_bool_t divisible;
    pd_AssetType_t asset_type;
    pd_VecAssetIdentifier_t identifiers;
    pd_OptionFundingRoundName_t funding_round;
} pd_asset_create_asset_V4_t;

#define PD_CALL_ASSET_FREEZE_V4 4
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_freeze_V4_t;

#define PD_CALL_ASSET_UNFREEZE_V4 5
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_unfreeze_V4_t;

#define PD_CALL_ASSET_RENAME_ASSET_V4 6
typedef struct {
    pd_Ticker_t ticker;
    pd_AssetName_t name;
} pd_asset_rename_asset_V4_t;

#define PD_CALL_ASSET_ISSUE_V4 7
typedef struct {
    pd_Ticker_t ticker;
    pd_BalanceNoSymbol_t amount;
    pd_PortfolioKind_t portfolio_kind;
} pd_asset_issue_V4_t;

#define PD_CALL_ASSET_REDEEM_V4 8
typedef struct {
    pd_Ticker_t ticker;
    pd_BalanceNoSymbol_t amount;
} pd_asset_redeem_V4_t;

#define PD_CALL_ASSET_MAKE_DIVISIBLE_V4 9
typedef struct {
    pd_Ticker_t ticker;
} pd_asset_make_divisible_V4_t;

#define PD_CALL_ASSET_ADD_DOCUMENTS_V4 10
typedef struct {
    pd_VecDocument_t docs;
    pd_Ticker_t ticker;
} pd_asset_add_documents_V4_t;

#define PD_CALL_ASSET_REMOVE_DOCUMENTS_V4 11
typedef struct {
    pd_VecDocumentId_t ids;
    pd_Ticker_t ticker;
} pd_asset_remove_documents_V4_t;

#define PD_CALL_ASSET_SET_FUNDING_ROUND_V4 12
typedef struct {
    pd_Ticker_t ticker;
    pd_FundingRoundName_t name;
} pd_asset_set_funding_round_V4_t;

#define PD_CALL_ASSET_UPDATE_IDENTIFIERS_V4 13
typedef struct {
    pd_Ticker_t ticker;
    pd_VecAssetIdentifier_t identifiers;
} pd_asset_update_identifiers_V4_t;

#define PD_CALL_CAPITALDISTRIBUTION_DISTRIBUTE_V4 0
typedef struct {
    pd_CAId_t ca_id;
    pd_OptionPortfolioNumber_t portfolio;
    pd_Ticker_t currency;
    pd_Balance_t per_share;
    pd_Balance_t amount;
    pd_Moment_t payment_at;
    pd_OptionMoment_t expires_at;
} pd_capitaldistribution_distribute_V4_t;

#define PD_CALL_CAPITALDISTRIBUTION_CLAIM_V4 1
typedef struct {
    pd_CAId_t ca_id;
} pd_capitaldistribution_claim_V4_t;

#define PD_CALL_CAPITALDISTRIBUTION_PUSH_BENEFIT_V4 2
typedef struct {
    pd_CAId_t ca_id;
    pd_IdentityId_t holder;
} pd_capitaldistribution_push_benefit_V4_t;

#define PD_CALL_CAPITALDISTRIBUTION_RECLAIM_V4 3
typedef struct {
    pd_CAId_t ca_id;
} pd_capitaldistribution_reclaim_V4_t;

#define PD_CALL_CAPITALDISTRIBUTION_REMOVE_DISTRIBUTION_V4 4
typedef struct {
    pd_CAId_t ca_id;
} pd_capitaldistribution_remove_distribution_V4_t;

#define PD_CALL_CHECKPOINT_CREATE_CHECKPOINT_V4 0
typedef struct {
    pd_Ticker_t ticker;
} pd_checkpoint_create_checkpoint_V4_t;

#define PD_CALL_CHECKPOINT_SET_SCHEDULES_MAX_COMPLEXITY_V4 1
typedef struct {
    pd_u64_t max_complexity;
} pd_checkpoint_set_schedules_max_complexity_V4_t;

#define PD_CALL_CHECKPOINT_CREATE_SCHEDULE_V4 2
typedef struct {
    pd_Ticker_t ticker;
    pd_ScheduleCheckpoints_t schedule;
} pd_checkpoint_create_schedule_V4_t;

#define PD_CALL_CHECKPOINT_REMOVE_SCHEDULE_V4 3
typedef struct {
    pd_Ticker_t ticker;
    pd_ScheduleId_t id;
} pd_checkpoint_remove_schedule_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_COMPLIANCE_REQUIREMENT_V4 0
typedef struct {
    pd_Ticker_t ticker;
    pd_VecCondition_t sender_conditions;
    pd_VecCondition_t receiver_conditions;
} pd_compliancemanager_add_compliance_requirement_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_COMPLIANCE_REQUIREMENT_V4 1
typedef struct {
    pd_Ticker_t ticker;
    pd_u32_t id;
} pd_compliancemanager_remove_compliance_requirement_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_REPLACE_ASSET_COMPLIANCE_V4 2
typedef struct {
    pd_Ticker_t ticker;
    pd_VecComplianceRequirement_t asset_compliance;
} pd_compliancemanager_replace_asset_compliance_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_RESET_ASSET_COMPLIANCE_V4 3
typedef struct {
    pd_Ticker_t ticker;
} pd_compliancemanager_reset_asset_compliance_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_PAUSE_ASSET_COMPLIANCE_V4 4
typedef struct {
    pd_Ticker_t ticker;
} pd_compliancemanager_pause_asset_compliance_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_RESUME_ASSET_COMPLIANCE_V4 5
typedef struct {
    pd_Ticker_t ticker;
} pd_compliancemanager_resume_asset_compliance_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER_V4 6
typedef struct {
    pd_Ticker_t ticker;
    pd_TrustedIssuer_t issuer;
} pd_compliancemanager_add_default_trusted_claim_issuer_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER_V4 7
typedef struct {
    pd_Ticker_t ticker;
    pd_IdentityId_t issuer;
} pd_compliancemanager_remove_default_trusted_claim_issuer_V4_t;

#define PD_CALL_COMPLIANCEMANAGER_CHANGE_COMPLIANCE_REQUIREMENT_V4 8
typedef struct {
    pd_Ticker_t ticker;
    pd_ComplianceRequirement_t new_req;
} pd_compliancemanager_change_compliance_requirement_V4_t;

#define PD_CALL_PIPS_SET_PRUNE_HISTORICAL_PIPS_V4 0
typedef struct {
    pd_bool_t prune;
} pd_pips_set_prune_historical_pips_V4_t;

#define PD_CALL_PIPS_SET_MIN_PROPOSAL_DEPOSIT_V4 1
typedef struct {
    pd_Balance_t deposit;
} pd_pips_set_min_proposal_deposit_V4_t;

#define PD_CALL_PIPS_SET_DEFAULT_ENACTMENT_PERIOD_V4 2
typedef struct {
    pd_BlockNumber_t duration;
} pd_pips_set_default_enactment_period_V4_t;

#define PD_CALL_PIPS_SET_PENDING_PIP_EXPIRY_V4 3
typedef struct {
    pd_MaybeBlockBlockNumber_t expiry;
} pd_pips_set_pending_pip_expiry_V4_t;

#define PD_CALL_PIPS_SET_MAX_PIP_SKIP_COUNT_V4 4
typedef struct {
    pd_SkippedCount_t max;
} pd_pips_set_max_pip_skip_count_V4_t;

#define PD_CALL_PIPS_SET_ACTIVE_PIP_LIMIT_V4 5
typedef struct {
    pd_u32_t limit;
} pd_pips_set_active_pip_limit_V4_t;

#define PD_CALL_PIPS_APPROVE_COMMITTEE_PROPOSAL_V4 8
typedef struct {
    pd_PipId_t id;
} pd_pips_approve_committee_proposal_V4_t;

#define PD_CALL_PIPS_REJECT_PROPOSAL_V4 9
typedef struct {
    pd_PipId_t id;
} pd_pips_reject_proposal_V4_t;

#define PD_CALL_PIPS_PRUNE_PROPOSAL_V4 10
typedef struct {
    pd_PipId_t id;
} pd_pips_prune_proposal_V4_t;

#define PD_CALL_PIPS_RESCHEDULE_EXECUTION_V4 11
typedef struct {
    pd_PipId_t id;
    pd_OptionBlockNumber_t until;
} pd_pips_reschedule_execution_V4_t;

#define PD_CALL_PIPS_CLEAR_SNAPSHOT_V4 12
typedef struct {
} pd_pips_clear_snapshot_V4_t;

#define PD_CALL_PIPS_SNAPSHOT_V4 13
typedef struct {
} pd_pips_snapshot_V4_t;

#define PD_CALL_PIPS_ENACT_SNAPSHOT_RESULTS_V4 14
typedef struct {
    pd_VecTuplePipIdSnapshotResult_t results;
} pd_pips_enact_snapshot_results_V4_t;

#define PD_CALL_PIPS_EXECUTE_SCHEDULED_PIP_V4 15
typedef struct {
    pd_PipId_t id;
} pd_pips_execute_scheduled_pip_V4_t;

#define PD_CALL_PIPS_EXPIRE_SCHEDULED_PIP_V4 16
typedef struct {
    pd_IdentityId_t did;
    pd_PipId_t id;
} pd_pips_expire_scheduled_pip_V4_t;

#define PD_CALL_PORTFOLIO_CREATE_PORTFOLIO_V4 0
typedef struct {
    pd_PortfolioName_t name;
} pd_portfolio_create_portfolio_V4_t;

#define PD_CALL_PORTFOLIO_DELETE_PORTFOLIO_V4 1
typedef struct {
    pd_PortfolioNumber_t num;
} pd_portfolio_delete_portfolio_V4_t;

#define PD_CALL_PORTFOLIO_RENAME_PORTFOLIO_V4 2
typedef struct {
    pd_PortfolioNumber_t num;
    pd_PortfolioName_t to_name;
} pd_portfolio_rename_portfolio_V4_t;

#define PD_CALL_PORTFOLIO_MOVE_PORTFOLIO_FUNDS_V4 5
typedef struct {
    pd_PortfolioId_t from;
    pd_PortfolioId_t to;
    pd_VecFund_t funds;
} pd_portfolio_move_portfolio_funds_V4_t;

#define PD_CALL_PROTOCOLFEE_CHANGE_COEFFICIENT_V4 0
typedef struct {
    pd_PosRatio_t coefficient;
} pd_protocolfee_change_coefficient_V4_t;

#define PD_CALL_SETTLEMENT_CREATE_VENUE_V4 0
typedef struct {
    pd_VenueDetails_t details;
    pd_VecAccountId_t signers;
    pd_VenueType_t typ;
} pd_settlement_create_venue_V4_t;

#define PD_CALL_SETTLEMENT_AFFIRM_WITH_RECEIPTS_V4 3
typedef struct {
    pd_InstructionId_t id;
    pd_VecReceiptDetails_t receipt_details;
    pd_VecPortfolioId_t portfolios;
} pd_settlement_affirm_with_receipts_V4_t;

#define PD_CALL_SETTLEMENT_SET_VENUE_FILTERING_V4 4
typedef struct {
    pd_Ticker_t ticker;
    pd_bool_t enabled;
} pd_settlement_set_venue_filtering_V4_t;

#define PD_CALL_SETTLEMENT_ALLOW_VENUES_V4 5
typedef struct {
    pd_Ticker_t ticker;
    pd_VecVenueId_t venues;
} pd_settlement_allow_venues_V4_t;

#define PD_CALL_SETTLEMENT_DISALLOW_VENUES_V4 6
typedef struct {
    pd_Ticker_t ticker;
    pd_VecVenueId_t venues;
} pd_settlement_disallow_venues_V4_t;

#define PD_CALL_SETTLEMENT_ADD_INSTRUCTION_V4 9
typedef struct {
    pd_VenueId_t venue_id;
    pd_SettlementTypeBlockNumber_t settlement_type;
    pd_OptionMoment_t trade_date;
    pd_OptionMoment_t value_date;
    pd_VecLeg_t legs;
    pd_OptionMemo_t instruction_memo;
} pd_settlement_add_instruction_V4_t;

#define PD_CALL_SETTLEMENT_ADD_AND_AFFIRM_INSTRUCTION_V4 10
typedef struct {
    pd_VenueId_t venue_id;
    pd_SettlementTypeBlockNumber_t settlement_type;
    pd_OptionMoment_t trade_date;
    pd_OptionMoment_t value_date;
    pd_VecLeg_t legs;
    pd_VecPortfolioId_t portfolios;
    pd_OptionMemo_t instruction_memo;
} pd_settlement_add_and_affirm_instruction_V4_t;

#define PD_CALL_SETTLEMENT_AFFIRM_INSTRUCTION_V4 11
typedef struct {
    pd_InstructionId_t id;
    pd_VecPortfolioId_t portfolios;
} pd_settlement_affirm_instruction_V4_t;

#define PD_CALL_SETTLEMENT_WITHDRAW_AFFIRMATION_V4 12
typedef struct {
    pd_InstructionId_t id;
    pd_VecPortfolioId_t portfolios;
} pd_settlement_withdraw_affirmation_V4_t;

#define PD_CALL_SETTLEMENT_REJECT_INSTRUCTION_V4 13
typedef struct {
    pd_InstructionId_t id;
    pd_PortfolioId_t portfolio;
} pd_settlement_reject_instruction_V4_t;

#define PD_CALL_SETTLEMENT_EXECUTE_SCHEDULED_INSTRUCTION_V4 14
typedef struct {
    pd_InstructionId_t id;
    pd_Weight_t weight_limit;
} pd_settlement_execute_scheduled_instruction_V4_t;

#define PD_CALL_TREASURY_DISBURSEMENT_V4 0
typedef struct {
    pd_VecBeneficiary_t beneficiaries;
} pd_treasury_disbursement_V4_t;

#define PD_CALL_TREASURY_REIMBURSEMENT_V4 1
typedef struct {
    pd_Balance_t amount;
} pd_treasury_reimbursement_V4_t;

#define PD_CALL_UTILITY_RELAY_TX_V4 1
typedef struct {
    pd_AccountId_t target;
    pd_OffChainSignature_t signature;
    pd_UniqueCall_t call;
} pd_utility_relay_tx_V4_t;

#define PD_CALL_CONTRACTS_CALL_V4 6
typedef struct {
    pd_AccountIdLookupOfT_t dest;
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_Vecu8_t data;
} pd_contracts_call_V4_t;

#define PD_CALL_CONTRACTS_INSTANTIATE_V4 8
typedef struct {
    pd_CompactBalance_t amount;
    pd_Weight_t gas_limit;
    pd_OptionCompactBalanceOf_t storage_deposit_limit;
    pd_CodeHash_t code_hash;
    pd_Bytes_t data;
    pd_Bytes_t salt;
} pd_contracts_instantiate_V4_t;

#endif

typedef union {
    pd_balances_transfer_V4_t balances_transfer_V4;
    pd_balances_transfer_with_memo_V4_t balances_transfer_with_memo_V4;
    pd_identity_accept_primary_key_V4_t identity_accept_primary_key_V4;
    pd_identity_join_identity_as_key_V4_t identity_join_identity_as_key_V4;
    pd_identity_leave_identity_as_key_V4_t identity_leave_identity_as_key_V4;
    pd_identity_add_claim_V4_t identity_add_claim_V4;
    pd_identity_revoke_claim_V4_t identity_revoke_claim_V4;
    pd_identity_freeze_secondary_keys_V4_t identity_freeze_secondary_keys_V4;
    pd_identity_unfreeze_secondary_keys_V4_t identity_unfreeze_secondary_keys_V4;
    pd_identity_add_authorization_V4_t identity_add_authorization_V4;
    pd_identity_remove_authorization_V4_t identity_remove_authorization_V4;
    pd_identity_add_secondary_keys_with_authorization_V4_t identity_add_secondary_keys_with_authorization_V4;
    pd_identity_remove_secondary_keys_V4_t identity_remove_secondary_keys_V4;
    pd_multisig_create_multisig_V4_t multisig_create_multisig_V4;
    pd_multisig_create_or_approve_proposal_as_identity_V4_t multisig_create_or_approve_proposal_as_identity_V4;
    pd_multisig_create_or_approve_proposal_as_key_V4_t multisig_create_or_approve_proposal_as_key_V4;
    pd_multisig_create_proposal_as_identity_V4_t multisig_create_proposal_as_identity_V4;
    pd_multisig_create_proposal_as_key_V4_t multisig_create_proposal_as_key_V4;
    pd_multisig_approve_as_identity_V4_t multisig_approve_as_identity_V4;
    pd_multisig_approve_as_key_V4_t multisig_approve_as_key_V4;
    pd_multisig_reject_as_identity_V4_t multisig_reject_as_identity_V4;
    pd_multisig_reject_as_key_V4_t multisig_reject_as_key_V4;
    pd_multisig_accept_multisig_signer_as_identity_V4_t multisig_accept_multisig_signer_as_identity_V4;
    pd_multisig_accept_multisig_signer_as_key_V4_t multisig_accept_multisig_signer_as_key_V4;
    pd_multisig_add_multisig_signer_V4_t multisig_add_multisig_signer_V4;
    pd_multisig_remove_multisig_signer_V4_t multisig_remove_multisig_signer_V4;
    pd_multisig_add_multisig_signers_via_creator_V4_t multisig_add_multisig_signers_via_creator_V4;
    pd_multisig_remove_multisig_signers_via_creator_V4_t multisig_remove_multisig_signers_via_creator_V4;
    pd_multisig_change_sigs_required_V4_t multisig_change_sigs_required_V4;
    pd_multisig_make_multisig_primary_V4_t multisig_make_multisig_primary_V4;
    pd_multisig_execute_scheduled_proposal_V4_t multisig_execute_scheduled_proposal_V4;
    pd_staking_bond_V4_t staking_bond_V4;
    pd_staking_bond_extra_V4_t staking_bond_extra_V4;
    pd_staking_unbond_V4_t staking_unbond_V4;
    pd_staking_withdraw_unbonded_V4_t staking_withdraw_unbonded_V4;
    pd_staking_validate_V4_t staking_validate_V4;
    pd_staking_nominate_V4_t staking_nominate_V4;
    pd_staking_chill_V4_t staking_chill_V4;
    pd_staking_set_payee_V4_t staking_set_payee_V4;
    pd_staking_set_controller_V4_t staking_set_controller_V4;
    pd_staking_rebond_V4_t staking_rebond_V4;
    pd_pips_propose_V4_t pips_propose_V4;
    pd_pips_vote_V4_t pips_vote_V4;
    pd_utility_batch_V4_t utility_batch_V4;
    pd_utility_batch_atomic_V4_t utility_batch_atomic_V4;
    pd_utility_batch_optimistic_V4_t utility_batch_optimistic_V4;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    pd_corporateaction_set_max_details_length_V4_t corporateaction_set_max_details_length_V4;
    pd_corporateaction_set_default_targets_V4_t corporateaction_set_default_targets_V4;
    pd_corporateaction_set_default_withholding_tax_V4_t corporateaction_set_default_withholding_tax_V4;
    pd_corporateaction_set_did_withholding_tax_V4_t corporateaction_set_did_withholding_tax_V4;
    pd_corporateaction_initiate_corporate_action_V4_t corporateaction_initiate_corporate_action_V4;
    pd_corporateaction_link_ca_doc_V4_t corporateaction_link_ca_doc_V4;
    pd_corporateaction_remove_ca_V4_t corporateaction_remove_ca_V4;
    pd_corporateaction_change_record_date_V4_t corporateaction_change_record_date_V4;
    pd_corporateaction_initiate_corporate_action_and_distribute_V4_t corporateaction_initiate_corporate_action_and_distribute_V4;
    pd_corporateballot_attach_ballot_V4_t corporateballot_attach_ballot_V4;
    pd_corporateballot_vote_V4_t corporateballot_vote_V4;
    pd_corporateballot_change_end_V4_t corporateballot_change_end_V4;
    pd_corporateballot_change_meta_V4_t corporateballot_change_meta_V4;
    pd_corporateballot_change_rcv_V4_t corporateballot_change_rcv_V4;
    pd_corporateballot_remove_ballot_V4_t corporateballot_remove_ballot_V4;
#endif
    pd_system_remark_V4_t system_remark_V4;
    pd_system_set_heap_pages_V4_t system_set_heap_pages_V4;
    pd_system_set_code_V4_t system_set_code_V4;
    pd_system_set_code_without_checks_V4_t system_set_code_without_checks_V4;
    pd_system_remark_with_event_V4_t system_remark_with_event_V4;
    pd_timestamp_set_V4_t timestamp_set_V4;
    pd_indices_claim_V4_t indices_claim_V4;
    pd_indices_transfer_V4_t indices_transfer_V4;
    pd_indices_free_V4_t indices_free_V4;
    pd_indices_force_transfer_V4_t indices_force_transfer_V4;
    pd_indices_freeze_V4_t indices_freeze_V4;
    pd_balances_deposit_block_reward_reserve_balance_V4_t balances_deposit_block_reward_reserve_balance_V4;
    pd_balances_set_balance_V4_t balances_set_balance_V4;
    pd_balances_force_transfer_V4_t balances_force_transfer_V4;
    pd_balances_burn_account_balance_V4_t balances_burn_account_balance_V4;
    pd_identity_cdd_register_did_V4_t identity_cdd_register_did_V4;
    pd_identity_invalidate_cdd_claims_V4_t identity_invalidate_cdd_claims_V4;
    pd_identity_change_cdd_requirement_for_mk_rotation_V4_t identity_change_cdd_requirement_for_mk_rotation_V4;
    pd_identity_gc_add_cdd_claim_V4_t identity_gc_add_cdd_claim_V4;
    pd_identity_gc_revoke_cdd_claim_V4_t identity_gc_revoke_cdd_claim_V4;
    pd_identity_revoke_claim_by_index_V4_t identity_revoke_claim_by_index_V4;
    pd_identity_rotate_primary_key_to_secondary_V4_t identity_rotate_primary_key_to_secondary_V4;
    pd_identity_set_secondary_key_permissions_V4_t identity_set_secondary_key_permissions_V4;
    pd_identity_register_custom_claim_type_V4_t identity_register_custom_claim_type_V4;
    pd_identity_cdd_register_did_with_cdd_V4_t identity_cdd_register_did_with_cdd_V4;
    pd_identity_create_child_identity_V4_t identity_create_child_identity_V4;
    pd_identity_create_child_identities_V4_t identity_create_child_identities_V4;
    pd_identity_unlink_child_identity_V4_t identity_unlink_child_identity_V4;
    pd_cddserviceproviders_set_active_members_limit_V4_t cddserviceproviders_set_active_members_limit_V4;
    pd_cddserviceproviders_disable_member_V4_t cddserviceproviders_disable_member_V4;
    pd_cddserviceproviders_add_member_V4_t cddserviceproviders_add_member_V4;
    pd_cddserviceproviders_remove_member_V4_t cddserviceproviders_remove_member_V4;
    pd_cddserviceproviders_swap_member_V4_t cddserviceproviders_swap_member_V4;
    pd_cddserviceproviders_reset_members_V4_t cddserviceproviders_reset_members_V4;
    pd_cddserviceproviders_abdicate_membership_V4_t cddserviceproviders_abdicate_membership_V4;
    pd_polymeshcommittee_set_vote_threshold_V4_t polymeshcommittee_set_vote_threshold_V4;
    pd_polymeshcommittee_set_release_coordinator_V4_t polymeshcommittee_set_release_coordinator_V4;
    pd_polymeshcommittee_set_expires_after_V4_t polymeshcommittee_set_expires_after_V4;
    pd_polymeshcommittee_vote_or_propose_V4_t polymeshcommittee_vote_or_propose_V4;
    pd_polymeshcommittee_vote_V4_t polymeshcommittee_vote_V4;
    pd_committeemembership_set_active_members_limit_V4_t committeemembership_set_active_members_limit_V4;
    pd_committeemembership_disable_member_V4_t committeemembership_disable_member_V4;
    pd_committeemembership_add_member_V4_t committeemembership_add_member_V4;
    pd_committeemembership_remove_member_V4_t committeemembership_remove_member_V4;
    pd_committeemembership_swap_member_V4_t committeemembership_swap_member_V4;
    pd_committeemembership_reset_members_V4_t committeemembership_reset_members_V4;
    pd_committeemembership_abdicate_membership_V4_t committeemembership_abdicate_membership_V4;
    pd_technicalcommittee_set_vote_threshold_V4_t technicalcommittee_set_vote_threshold_V4;
    pd_technicalcommittee_set_release_coordinator_V4_t technicalcommittee_set_release_coordinator_V4;
    pd_technicalcommittee_set_expires_after_V4_t technicalcommittee_set_expires_after_V4;
    pd_technicalcommittee_vote_or_propose_V4_t technicalcommittee_vote_or_propose_V4;
    pd_technicalcommittee_vote_V4_t technicalcommittee_vote_V4;
    pd_technicalcommitteemembership_set_active_members_limit_V4_t technicalcommitteemembership_set_active_members_limit_V4;
    pd_technicalcommitteemembership_disable_member_V4_t technicalcommitteemembership_disable_member_V4;
    pd_technicalcommitteemembership_add_member_V4_t technicalcommitteemembership_add_member_V4;
    pd_technicalcommitteemembership_remove_member_V4_t technicalcommitteemembership_remove_member_V4;
    pd_technicalcommitteemembership_swap_member_V4_t technicalcommitteemembership_swap_member_V4;
    pd_technicalcommitteemembership_reset_members_V4_t technicalcommitteemembership_reset_members_V4;
    pd_technicalcommitteemembership_abdicate_membership_V4_t technicalcommitteemembership_abdicate_membership_V4;
    pd_upgradecommittee_set_vote_threshold_V4_t upgradecommittee_set_vote_threshold_V4;
    pd_upgradecommittee_set_release_coordinator_V4_t upgradecommittee_set_release_coordinator_V4;
    pd_upgradecommittee_set_expires_after_V4_t upgradecommittee_set_expires_after_V4;
    pd_upgradecommittee_vote_or_propose_V4_t upgradecommittee_vote_or_propose_V4;
    pd_upgradecommittee_vote_V4_t upgradecommittee_vote_V4;
    pd_upgradecommitteemembership_set_active_members_limit_V4_t upgradecommitteemembership_set_active_members_limit_V4;
    pd_upgradecommitteemembership_disable_member_V4_t upgradecommitteemembership_disable_member_V4;
    pd_upgradecommitteemembership_add_member_V4_t upgradecommitteemembership_add_member_V4;
    pd_upgradecommitteemembership_remove_member_V4_t upgradecommitteemembership_remove_member_V4;
    pd_upgradecommitteemembership_swap_member_V4_t upgradecommitteemembership_swap_member_V4;
    pd_upgradecommitteemembership_reset_members_V4_t upgradecommitteemembership_reset_members_V4;
    pd_upgradecommitteemembership_abdicate_membership_V4_t upgradecommitteemembership_abdicate_membership_V4;
    pd_multisig_make_multisig_secondary_V4_t multisig_make_multisig_secondary_V4;
    pd_multisig_change_sigs_required_via_creator_V4_t multisig_change_sigs_required_via_creator_V4;
    pd_multisig_remove_creator_controls_V4_t multisig_remove_creator_controls_V4;
    pd_bridge_change_controller_V4_t bridge_change_controller_V4;
    pd_bridge_change_admin_V4_t bridge_change_admin_V4;
    pd_bridge_change_timelock_V4_t bridge_change_timelock_V4;
    pd_bridge_freeze_V4_t bridge_freeze_V4;
    pd_bridge_unfreeze_V4_t bridge_unfreeze_V4;
    pd_bridge_change_bridge_limit_V4_t bridge_change_bridge_limit_V4;
    pd_bridge_change_bridge_exempted_V4_t bridge_change_bridge_exempted_V4;
    pd_bridge_force_handle_bridge_tx_V4_t bridge_force_handle_bridge_tx_V4;
    pd_staking_set_validator_count_V4_t staking_set_validator_count_V4;
    pd_staking_increase_validator_count_V4_t staking_increase_validator_count_V4;
    pd_staking_scale_validator_count_V4_t staking_scale_validator_count_V4;
    pd_staking_add_permissioned_validator_V4_t staking_add_permissioned_validator_V4;
    pd_staking_remove_permissioned_validator_V4_t staking_remove_permissioned_validator_V4;
    pd_staking_validate_cdd_expiry_nominators_V4_t staking_validate_cdd_expiry_nominators_V4;
    pd_staking_set_commission_cap_V4_t staking_set_commission_cap_V4;
    pd_staking_set_min_bond_threshold_V4_t staking_set_min_bond_threshold_V4;
    pd_staking_force_no_eras_V4_t staking_force_no_eras_V4;
    pd_staking_force_new_era_V4_t staking_force_new_era_V4;
    pd_staking_set_invulnerables_V4_t staking_set_invulnerables_V4;
    pd_staking_force_unstake_V4_t staking_force_unstake_V4;
    pd_staking_force_new_era_always_V4_t staking_force_new_era_always_V4;
    pd_staking_cancel_deferred_slash_V4_t staking_cancel_deferred_slash_V4;
    pd_staking_payout_stakers_V4_t staking_payout_stakers_V4;
    pd_staking_set_history_depth_V4_t staking_set_history_depth_V4;
    pd_staking_reap_stash_V4_t staking_reap_stash_V4;
    pd_staking_payout_stakers_by_system_V4_t staking_payout_stakers_by_system_V4;
    pd_staking_change_slashing_allowed_for_V4_t staking_change_slashing_allowed_for_V4;
    pd_staking_update_permissioned_validator_intended_count_V4_t staking_update_permissioned_validator_intended_count_V4;
    pd_staking_chill_from_governance_V4_t staking_chill_from_governance_V4;
    pd_session_set_keys_V4_t session_set_keys_V4;
    pd_session_purge_keys_V4_t session_purge_keys_V4;
    pd_asset_register_ticker_V4_t asset_register_ticker_V4;
    pd_asset_accept_ticker_transfer_V4_t asset_accept_ticker_transfer_V4;
    pd_asset_accept_asset_ownership_transfer_V4_t asset_accept_asset_ownership_transfer_V4;
    pd_asset_create_asset_V4_t asset_create_asset_V4;
    pd_asset_freeze_V4_t asset_freeze_V4;
    pd_asset_unfreeze_V4_t asset_unfreeze_V4;
    pd_asset_rename_asset_V4_t asset_rename_asset_V4;
    pd_asset_issue_V4_t asset_issue_V4;
    pd_asset_redeem_V4_t asset_redeem_V4;
    pd_asset_make_divisible_V4_t asset_make_divisible_V4;
    pd_asset_add_documents_V4_t asset_add_documents_V4;
    pd_asset_remove_documents_V4_t asset_remove_documents_V4;
    pd_asset_set_funding_round_V4_t asset_set_funding_round_V4;
    pd_asset_update_identifiers_V4_t asset_update_identifiers_V4;
    pd_capitaldistribution_distribute_V4_t capitaldistribution_distribute_V4;
    pd_capitaldistribution_claim_V4_t capitaldistribution_claim_V4;
    pd_capitaldistribution_push_benefit_V4_t capitaldistribution_push_benefit_V4;
    pd_capitaldistribution_reclaim_V4_t capitaldistribution_reclaim_V4;
    pd_capitaldistribution_remove_distribution_V4_t capitaldistribution_remove_distribution_V4;
    pd_checkpoint_create_checkpoint_V4_t checkpoint_create_checkpoint_V4;
    pd_checkpoint_set_schedules_max_complexity_V4_t checkpoint_set_schedules_max_complexity_V4;
    pd_checkpoint_create_schedule_V4_t checkpoint_create_schedule_V4;
    pd_checkpoint_remove_schedule_V4_t checkpoint_remove_schedule_V4;
    pd_compliancemanager_add_compliance_requirement_V4_t compliancemanager_add_compliance_requirement_V4;
    pd_compliancemanager_remove_compliance_requirement_V4_t compliancemanager_remove_compliance_requirement_V4;
    pd_compliancemanager_replace_asset_compliance_V4_t compliancemanager_replace_asset_compliance_V4;
    pd_compliancemanager_reset_asset_compliance_V4_t compliancemanager_reset_asset_compliance_V4;
    pd_compliancemanager_pause_asset_compliance_V4_t compliancemanager_pause_asset_compliance_V4;
    pd_compliancemanager_resume_asset_compliance_V4_t compliancemanager_resume_asset_compliance_V4;
    pd_compliancemanager_add_default_trusted_claim_issuer_V4_t compliancemanager_add_default_trusted_claim_issuer_V4;
    pd_compliancemanager_remove_default_trusted_claim_issuer_V4_t compliancemanager_remove_default_trusted_claim_issuer_V4;
    pd_compliancemanager_change_compliance_requirement_V4_t compliancemanager_change_compliance_requirement_V4;
    pd_pips_set_prune_historical_pips_V4_t pips_set_prune_historical_pips_V4;
    pd_pips_set_min_proposal_deposit_V4_t pips_set_min_proposal_deposit_V4;
    pd_pips_set_default_enactment_period_V4_t pips_set_default_enactment_period_V4;
    pd_pips_set_pending_pip_expiry_V4_t pips_set_pending_pip_expiry_V4;
    pd_pips_set_max_pip_skip_count_V4_t pips_set_max_pip_skip_count_V4;
    pd_pips_set_active_pip_limit_V4_t pips_set_active_pip_limit_V4;
    pd_pips_approve_committee_proposal_V4_t pips_approve_committee_proposal_V4;
    pd_pips_reject_proposal_V4_t pips_reject_proposal_V4;
    pd_pips_prune_proposal_V4_t pips_prune_proposal_V4;
    pd_pips_reschedule_execution_V4_t pips_reschedule_execution_V4;
    pd_pips_clear_snapshot_V4_t pips_clear_snapshot_V4;
    pd_pips_snapshot_V4_t pips_snapshot_V4;
    pd_pips_enact_snapshot_results_V4_t pips_enact_snapshot_results_V4;
    pd_pips_execute_scheduled_pip_V4_t pips_execute_scheduled_pip_V4;
    pd_pips_expire_scheduled_pip_V4_t pips_expire_scheduled_pip_V4;
    pd_portfolio_create_portfolio_V4_t portfolio_create_portfolio_V4;
    pd_portfolio_delete_portfolio_V4_t portfolio_delete_portfolio_V4;
    pd_portfolio_rename_portfolio_V4_t portfolio_rename_portfolio_V4;
    pd_portfolio_move_portfolio_funds_V4_t portfolio_move_portfolio_funds_V4;
    pd_protocolfee_change_coefficient_V4_t protocolfee_change_coefficient_V4;
    pd_settlement_create_venue_V4_t settlement_create_venue_V4;
    pd_settlement_affirm_with_receipts_V4_t settlement_affirm_with_receipts_V4;
    pd_settlement_set_venue_filtering_V4_t settlement_set_venue_filtering_V4;
    pd_settlement_allow_venues_V4_t settlement_allow_venues_V4;
    pd_settlement_disallow_venues_V4_t settlement_disallow_venues_V4;
    pd_settlement_add_instruction_V4_t settlement_add_instruction_V4;
    pd_settlement_add_and_affirm_instruction_V4_t settlement_add_and_affirm_instruction_V4;
    pd_settlement_affirm_instruction_V4_t settlement_affirm_instruction_V4;
    pd_settlement_withdraw_affirmation_V4_t settlement_withdraw_affirmation_V4;
    pd_settlement_reject_instruction_V4_t settlement_reject_instruction_V4;
    pd_settlement_execute_scheduled_instruction_V4_t settlement_execute_scheduled_instruction_V4;
    pd_treasury_disbursement_V4_t treasury_disbursement_V4;
    pd_treasury_reimbursement_V4_t treasury_reimbursement_V4;
    pd_utility_relay_tx_V4_t utility_relay_tx_V4;
    pd_contracts_call_V4_t contracts_call_V4;
    pd_contracts_instantiate_V4_t contracts_instantiate_V4;
#endif
} pd_MethodNested_V4_t;

typedef union {
    pd_MethodBasic_V4_t basic;
    pd_MethodNested_V4_t nested;
} pd_Method_V4_t;

#ifdef __cplusplus
}
#pragma clang diagnostic pop
#endif
