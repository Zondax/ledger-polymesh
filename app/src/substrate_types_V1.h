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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "substrate_types.h"
#include <stddef.h>
#include <stdint.h>

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DispatchableName_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_IdentityId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Ticker_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CddId_V1_t;

typedef struct {
    uint8_t value;
} pd_ClaimType_V1_t;

typedef struct {
    uint8_t value;
} pd_CountryCode_V1_t;

typedef struct {
    uint64_t value;
} pd_PortfolioNumber_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_ScopeId_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V1_t identity;
        pd_Ticker_V1_t ticker;
        uint64_t _len;
        const uint8_t* _ptr;
    };
} pd_Scope_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDispatchableName_V1_t;

typedef struct {
    uint8_t some;
    pd_VecDispatchableName_V1_t contained;
} pd_OptionVecDispatchableName_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PalletName_V1_t;

typedef struct {
    uint8_t value;
    pd_PortfolioNumber_V1_t number;
} pd_PortfolioKind_V1_t;

typedef struct {
    pd_CountryCode_V1_t country_code;
    pd_Scope_V1_t scope;
} pd_TupleCountryCodeScope_V1_t;

typedef struct {
    pd_Scope_V1_t scope;
    pd_ScopeId_V1_t scopeId;
    pd_CddId_V1_t cddId;
} pd_TupleScopeScopeIdCddId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaimType_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Scope_V1_t scope;
        pd_CddId_V1_t cddId;
        pd_TupleCountryCodeScope_V1_t jurisdiction;
        pd_TupleScopeScopeIdCddId_V1_t investorUniqueness;
    };
} pd_Claim_V1_t;

typedef struct {
    pd_PalletName_V1_t palletName;
    pd_OptionVecDispatchableName_V1_t dispatchableNames;
} pd_PalletPermissions_V1_t;

typedef struct {
    pd_IdentityId_V1_t did;
    pd_PortfolioKind_V1_t kind;
} pd_PortfolioId_V1_t;

typedef struct {
    uint8_t value;
    pd_VecClaimType_V1_t claims;
} pd_TrustedFor_V1_t;

typedef struct {
    uint8_t value;
    pd_IdentityId_V1_t specific;
} pd_TargetIdentity_V1_t;

typedef struct {
    pd_IdentityId_V1_t issuer;
    pd_TrustedFor_V1_t trustedFor;
} pd_TrustedIssuer_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaim_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPalletPermissions_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPortfolioId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTicker_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ChoiceTitle_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Claim_V1_t claim;
        pd_VecClaim_V1_t vecClaim;
        pd_TargetIdentity_V1_t identity;
    };
} pd_ConditionType_V1_t;

typedef struct {
    uint8_t some;
    pd_VecPalletPermissions_V1_t contained;
} pd_OptionVecPalletPermissions_V1_t;

typedef struct {
    uint8_t some;
    pd_VecPortfolioId_V1_t contained;
} pd_OptionVecPortfolioId_V1_t;

typedef struct {
    uint8_t some;
    pd_VecTicker_V1_t contained;
} pd_OptionVecTicker_V1_t;

typedef struct {
    uint32_t value;
} pd_Permill_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTrustedIssuer_V1_t;

typedef struct {
    uint32_t value;
} pd_AGId_V1_t;

typedef struct {
    pd_ConditionType_V1_t conditionType;
    pd_VecTrustedIssuer_V1_t issuers;
} pd_Condition_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentType_V1_t;

typedef struct {
    pd_PalletName_V1_t palletName;
    pd_bool_t total;
    pd_VecDispatchableName_V1_t dispatchableNames;
} pd_LegacyPalletPermissions_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Memo_V1_t;

typedef struct {
    uint64_t value;
} pd_Moment_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionInfoLink_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionTitle_V1_t;

typedef struct {
    pd_OptionVecTicker_V1_t asset;
    pd_OptionVecPalletPermissions_V1_t extrinsic;
    pd_OptionVecPortfolioId_V1_t portfolio;
} pd_Permissions_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V1_t identity;
        pd_AccountId_V1_t account;
    };
} pd_Signatory_V1_t;

typedef struct {
    pd_Permill_V1_t value;
} pd_Tax_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecChoiceTitle_V1_t;

typedef struct {
    uint8_t value;
    pd_AGId_V1_t agId;

} pd_AgentGroup_V1_t;

typedef struct {
    uint8_t value;
} pd_CalendarUnit_V1_t;

typedef struct {
    uint64_t value;
} pd_CheckpointId_V1_t;

typedef struct {
    uint8_t value;
    uint8_t _len;
    const uint8_t* _ptr;
} pd_DocumentHash_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentName_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentUri_V1_t;

typedef struct {
    pd_MotionTitle_V1_t title;
    pd_MotionInfoLink_V1_t info_link;
    pd_VecChoiceTitle_V1_t choices;
} pd_Motion_V1_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_OffChainSignature_V1_t;

typedef struct {
    uint8_t some;
    pd_DocumentType_V1_t contained;
} pd_OptionDocumentType_V1_t;

typedef struct {
    uint8_t some;
    pd_Memo_V1_t contained;
} pd_OptionMemo_V1_t;

typedef struct {
    uint8_t some;
    pd_Moment_V1_t contained;
} pd_OptionMoment_V1_t;

typedef struct {
    uint32_t value;
} pd_PipId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ReceiptMetadata_V1_t;

typedef struct {
    uint64_t value;
} pd_ScheduleId_V1_t;

typedef struct {
    pd_Signatory_V1_t signer;
    pd_Permissions_V1_t permissions;
} pd_SecondaryKey_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_V1_t;

typedef struct {
    uint8_t value;
} pd_SnapshotResult_V1_t;

typedef struct {
    uint8_t value;
} pd_TargetTreatment_V1_t;

typedef struct {
    pd_IdentityId_V1_t id;
    pd_Tax_V1_t tax;
} pd_TupleIdentityIdTax_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCondition_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecIdentityId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLegacyPalletPermissions_V1_t;

typedef struct {
    pd_AccountId_V1_t accountId_1;
    pd_AccountId_V1_t accountId_2;
    pd_Balance_t balance;
} pd_AddRelayerPayingKey_V1_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetIdentifier_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_BallotTitle_V1_t;

typedef struct {
    pd_Balance_t power;
    pd_Optionu16_t fallback;
} pd_BallotVote_V1_t;

typedef struct {
    pd_Ticker_V1_t ticker;
    pd_AgentGroup_V1_t agentGroup;
} pd_BecomeAgent_V1_t;

typedef struct {
    pd_IdentityId_V1_t identity;
    pd_Balance_t balance;
} pd_Beneficiary_V1_t;

typedef struct {
    uint32_t nonce;
    pd_AccountId_V1_t recipient;
    pd_Balance_t value;
    pd_Hash_t txHash;
} pd_BridgeTx_V1_t;

typedef struct {
    pd_CalendarUnit_V1_t unit;
    uint64_t amount;
} pd_CalendarPeriod_V1_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V1_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V1_t;

typedef struct {
    pd_VecCondition_V1_t senderConditions;
    pd_VecCondition_V1_t receiverConditions;
    uint32_t id;
} pd_ComplianceRequirement_V1_t;

typedef struct {
    uint64_t value;
} pd_Counter_V1_t;

typedef struct {
    uint32_t value;
} pd_CustomAssetTypeId_V1_t;

typedef struct {
    uint32_t value;
} pd_DocumentId_V1_t;

typedef struct {
    pd_DocumentUri_V1_t uri;
    pd_DocumentHash_V1_t content_hash;
    pd_DocumentName_V1_t name;
    pd_OptionDocumentType_V1_t doc_type;
    pd_OptionMoment_V1_t filing_date;
} pd_Document_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundingRoundName_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V1_t;

typedef struct {
    pd_PortfolioId_V1_t from;
    pd_PortfolioId_V1_t to;
    pd_Ticker_V1_t asset;
    pd_Balance_t amount;
} pd_Leg_V1_t;

typedef struct {
    uint32_t value;
} pd_LocalCAId_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_LookupSource_V1_t;

typedef struct {
    pd_Ticker_V1_t ticker;
    pd_Balance_t balance;
    pd_OptionMemo_V1_t memo;
} pd_MovePortfolioItem_V1_t;

typedef struct {
    uint8_t some;
    pd_VecLegacyPalletPermissions_V1_t contained;
} pd_OptionVecLegacyPalletPermissions_V1_t;

typedef struct {
    pd_Permill_V1_t value;
} pd_Percentage_V1_t;

typedef struct {
    uint64_t value;
} pd_Period_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PipDescription_V1_t;

typedef struct {
    pd_Balance_t total;
    pd_Balance_t price;
} pd_PriceTier_V1_t;

typedef struct {
    uint64_t receipt_uid;
    uint64_t leg_id;
    pd_AccountId_V1_t signer;
    pd_OffChainSignature_V1_t signature;
    pd_ReceiptMetadata_V1_t metadata;
} pd_ReceiptDetails_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Moment_V1_t scheduled;
        pd_ScheduleId_V1_t existingSchedule;
        pd_CheckpointId_V1_t existing;
    };
} pd_RecordDateSpec_V1_t;

typedef struct {
    pd_SecondaryKey_V1_t secondary_key;
    pd_Signature_V1_t auth_signature;
} pd_SecondaryKeyWithAuth_V1_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V1_t;

typedef struct {
    pd_VecIdentityId_V1_t identities;
    pd_TargetTreatment_V1_t treatment;
} pd_TargetIdentities_V1_t;

typedef struct {
    pd_IdentityId_V1_t identity;
    pd_bool_t val;
} pd_TupleIdentityIdbool_V1_t;

typedef struct {
    pd_PipId_V1_t pip_id;
    pd_SnapshotResult_V1_t snapshot_result;
} pd_TuplePipIdSnapshotResult_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Url_V1_t;

typedef struct {
    uint16_t value;
} pd_ValidatorIndex_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMotion_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdTax_V1_t;

typedef struct {
    uint8_t value;
    pd_CustomAssetTypeId_V1_t custom;
} pd_AssetType_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V1_t identityId;
        pd_AccountId_V1_t accountId;
        pd_Ticker_V1_t ticker;
        pd_Permissions_V1_t permissions;
        pd_PortfolioId_V1_t portfolioId;
        pd_BecomeAgent_V1_t becomeAgent;
        pd_AddRelayerPayingKey_V1_t addRelayerPayingKey;
    };
} pd_AuthorizationData_V1_t;

typedef struct {
    pd_BallotTitle_V1_t title;
    pd_VecMotion_V1_t motions;
} pd_BallotMeta_V1_t;

typedef struct {
    pd_Moment_V1_t start;
    pd_Moment_V1_t end;
} pd_BallotTimeRange_V1_t;

typedef struct {
    pd_Ticker_V1_t ticker;
    pd_LocalCAId_V1_t local_id;
} pd_CAId_V1_t;

typedef struct {
    pd_EthereumAddress_V1_t eth_owner;
    pd_Ticker_V1_t ticker;
    pd_bool_t is_contract;
    pd_bool_t is_created;
} pd_ClassicTickerImport_V1_t;

typedef struct {
    pd_OptionVecTicker_V1_t asset;
    pd_OptionVecLegacyPalletPermissions_V1_t extrinsic;
    pd_OptionVecPortfolioId_V1_t portfolio;
} pd_LegacyPermissions_V1_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_MaybeBlock_V1_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V1_t contained;
} pd_OptionChangesTrieConfiguration_V1_t;

typedef struct {
    uint8_t some;
    pd_ReceiptDetails_V1_t contained;
} pd_OptionReceiptDetails_V1_t;

typedef struct {
    uint8_t some;
    pd_RecordDateSpec_V1_t contained;
} pd_OptionRecordDateSpec_V1_t;

typedef struct {
    uint8_t some;
    pd_Scope_V1_t contained;
} pd_OptionScope_V1_t;

typedef struct {
    uint8_t some;
    pd_TargetIdentities_V1_t contained;
} pd_OptionTargetIdentities_V1_t;

typedef struct {
    uint8_t some;
    pd_Tax_V1_t contained;
} pd_OptionTax_V1_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V1_t dependency;
} pd_Priority_V1_t;

typedef struct {
    pd_OptionMoment_V1_t start;
    pd_CalendarPeriod_V1_t period;
    uint32_t remaining;
} pd_ScheduleSpec_V1_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_SettlementType_V1_t;

typedef struct {
    uint8_t max_ticker_length;
    pd_OptionMoment_V1_t registration_length;
} pd_TickerRegistrationConfig_V1_t;

typedef struct {
    uint8_t value;
    union {
        pd_Counter_V1_t countTransferManager;
        pd_Percentage_V1_t percentageTransferManager;
    };
} pd_TransferManager_V1_t;

typedef struct {
    uint64_t nonce;
    pd_Call_t call;
} pd_UniqueCall_V1_t;

typedef struct {
    pd_CompactPerBill_V1_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBallotVote_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBeneficiary_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBridgeTx_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecComplianceRequirement_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocument_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLeg_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMovePortfolioItem_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPriceTier_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecReceiptDetails_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKeyWithAuth_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKey_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSignatory_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdbool_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePipIdSnapshotResult_V1_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetName_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BabeEquivocationProof_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_CADetails_V1_t;

typedef struct {
    uint8_t value;
} pd_CAKind_V1_t;

typedef compactInt_t pd_CompactAssignments_V1_t;

typedef compactInt_t pd_CompactEraIndex_V1_t;

typedef compactInt_t pd_CompactMoment_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V1_t;

typedef struct {
    compactInt_t validators;
    compactInt_t nominators;
} pd_ElectionSize_V1_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ExtrinsicPermissions_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundraiserName_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_GrandpaEquivocationProof_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorUid_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorZKProofData_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ItnRewardStatus_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V1_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V1_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V1_t;

typedef struct {
    uint8_t some;
    pd_FundingRoundName_V1_t contained;
} pd_OptionFundingRoundName_V1_t;

typedef struct {
    uint8_t some;
    pd_Period_V1_t contained;
} pd_OptionPeriod_V1_t;

typedef struct {
    uint8_t some;
    pd_PipDescription_V1_t contained;
} pd_OptionPipDescription_V1_t;

typedef struct {
    uint8_t some;
    pd_PortfolioNumber_V1_t contained;
} pd_OptionPortfolioNumber_V1_t;

typedef struct {
    uint8_t some;
    pd_Url_V1_t contained;
} pd_OptionUrl_V1_t;

typedef struct {
    uint8_t some;
    pd_VecTupleIdentityIdTax_V1_t contained;
} pd_OptionVecTupleIdentityIdTax_V1_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V1_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PortfolioName_V1_t;

typedef struct {
    uint32_t numerator;
    uint32_t denominator;
} pd_PosRatio_V1_t;

typedef struct {
    uint32_t value;
} pd_ProposalIndex_V1_t;

typedef struct {
    uint8_t value;
} pd_ProtocolOp_V1_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V1_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ScopeClaimProof_V1_t;

typedef struct {
    uint8_t value;
} pd_SkippedCount_V1_t;

typedef struct {
    uint8_t value;
} pd_SlashingSwitch_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdentifier_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocumentId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecScopeId_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecValidatorIndex_V1_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_VenueDetails_V1_t;

typedef struct {
    uint8_t value;
} pd_VenueType_V1_t;

typedef struct {
    uint64_t value;
} pd_Weight_V1_t;

#ifdef __cplusplus
}
#endif
