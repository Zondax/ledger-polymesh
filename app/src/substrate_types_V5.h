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
} pd_DispatchableName_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_IdentityId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Ticker_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CddId_V5_t;

typedef struct {
    uint8_t value;
} pd_ClaimType_V5_t;

typedef struct {
    uint8_t value;
} pd_CountryCode_V5_t;

typedef struct {
    uint64_t value;
} pd_PortfolioNumber_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_ScopeId_V5_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V5_t identity;
        pd_Ticker_V5_t ticker;
        uint64_t _len;
        const uint8_t* _ptr;
    };
} pd_Scope_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDispatchableName_V5_t;

typedef struct {
    uint8_t some;
    pd_VecDispatchableName_V5_t contained;
} pd_OptionVecDispatchableName_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PalletName_V5_t;

typedef struct {
    uint8_t value;
    pd_PortfolioNumber_V5_t number;
} pd_PortfolioKind_V5_t;

typedef struct {
    pd_CountryCode_V5_t country_code;
    pd_Scope_V5_t scope;
} pd_TupleCountryCodeScope_V5_t;

typedef struct {
    pd_Scope_V5_t scope;
    pd_ScopeId_V5_t scopeId;
    pd_CddId_V5_t cddId;
} pd_TupleScopeScopeIdCddId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaimType_V5_t;

typedef struct {
    uint8_t value;
    union {
        pd_Scope_V5_t scope;
        pd_CddId_V5_t cddId;
        pd_TupleCountryCodeScope_V5_t jurisdiction;
        pd_TupleScopeScopeIdCddId_V5_t investorUniqueness;
    };
} pd_Claim_V5_t;

typedef struct {
    pd_PalletName_V5_t palletName;
    pd_OptionVecDispatchableName_V5_t dispatchableNames;
} pd_PalletPermissions_V5_t;

typedef struct {
    pd_IdentityId_V5_t did;
    pd_PortfolioKind_V5_t kind;
} pd_PortfolioId_V5_t;

typedef struct {
    uint8_t value;
    pd_VecClaimType_V5_t claims;
} pd_TrustedFor_V5_t;

typedef struct {
    uint8_t value;
    pd_IdentityId_V5_t specific;
} pd_TargetIdentity_V5_t;

typedef struct {
    pd_IdentityId_V5_t issuer;
    pd_TrustedFor_V5_t trustedFor;
} pd_TrustedIssuer_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaim_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPalletPermissions_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPortfolioId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTicker_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ChoiceTitle_V5_t;

typedef struct {
    uint8_t value;
    union {
        pd_Claim_V5_t claim;
        pd_VecClaim_V5_t vecClaim;
        pd_TargetIdentity_V5_t identity;
    };
} pd_ConditionType_V5_t;

typedef struct {
    uint8_t some;
    pd_VecPalletPermissions_V5_t contained;
} pd_OptionVecPalletPermissions_V5_t;

typedef struct {
    uint8_t some;
    pd_VecPortfolioId_V5_t contained;
} pd_OptionVecPortfolioId_V5_t;

typedef struct {
    uint8_t some;
    pd_VecTicker_V5_t contained;
} pd_OptionVecTicker_V5_t;

typedef struct {
    uint32_t value;
} pd_Permill_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTrustedIssuer_V5_t;

typedef struct {
    pd_ConditionType_V5_t conditionType;
    pd_VecTrustedIssuer_V5_t issuers;
} pd_Condition_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentType_V5_t;

typedef struct {
    uint64_t value;
} pd_Moment_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionInfoLink_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionTitle_V5_t;

typedef struct {
    pd_OptionVecTicker_V5_t asset;
    pd_OptionVecPalletPermissions_V5_t extrinsic;
    pd_OptionVecPortfolioId_V5_t portfolio;
} pd_Permissions_V5_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V5_t identity;
        pd_AccountId_V5_t account;
    };
} pd_Signatory_V5_t;

typedef struct {
    pd_Permill_V5_t value;
} pd_Tax_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecChoiceTitle_V5_t;

typedef struct {
    uint8_t value;
} pd_CalendarUnit_V5_t;

typedef struct {
    uint64_t value;
} pd_CheckpointId_V5_t;

typedef struct {
    uint8_t value;
    uint8_t _len;
    const uint8_t* _ptr;
} pd_DocumentHash_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentName_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentUri_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MetaUrl_V5_t;

typedef struct {
    pd_MotionTitle_V5_t title;
    pd_MotionInfoLink_V5_t info_link;
    pd_VecChoiceTitle_V5_t choices;
} pd_Motion_V5_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_OffChainSignature_V5_t;

typedef struct {
    uint8_t some;
    pd_DocumentType_V5_t contained;
} pd_OptionDocumentType_V5_t;

typedef struct {
    uint8_t some;
    pd_Moment_V5_t contained;
} pd_OptionMoment_V5_t;

typedef struct {
    uint32_t value;
} pd_PipId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ReceiptMetadata_V5_t;

typedef struct {
    uint64_t value;
} pd_ScheduleId_V5_t;

typedef struct {
    pd_Signatory_V5_t signer;
    pd_Permissions_V5_t permissions;
} pd_SecondaryKey_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_V5_t;

typedef struct {
    uint8_t value;
} pd_SnapshotResult_V5_t;

typedef struct {
    uint8_t value;
} pd_TargetTreatment_V5_t;

typedef struct {
    pd_IdentityId_V5_t id;
    pd_Tax_V5_t tax;
} pd_TupleIdentityIdTax_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCondition_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecIdentityId_V5_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetIdentifier_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_BallotTitle_V5_t;

typedef struct {
    pd_Balance_t power;
    pd_Optionu16_t fallback;
} pd_BallotVote_V5_t;

typedef struct {
    pd_IdentityId_V5_t identity;
    pd_Balance_t balance;
} pd_Beneficiary_V5_t;

typedef struct {
    uint32_t nonce;
    pd_AccountId_V5_t recipient;
    pd_Balance_t value;
    pd_Hash_t txHash;
} pd_BridgeTx_V5_t;

typedef struct {
    pd_CalendarUnit_V5_t unit;
    uint64_t amount;
} pd_CalendarPeriod_V5_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V5_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V5_t;

typedef struct {
    pd_VecCondition_V5_t senderConditions;
    pd_VecCondition_V5_t receiverConditions;
    uint32_t id;
} pd_ComplianceRequirement_V5_t;

typedef struct {
    uint64_t value;
} pd_Counter_V5_t;

typedef struct {
    uint32_t value;
} pd_DocumentId_V5_t;

typedef struct {
    pd_DocumentUri_V5_t uri;
    pd_DocumentHash_V5_t content_hash;
    pd_DocumentName_V5_t name;
    pd_OptionDocumentType_V5_t doc_type;
    pd_OptionMoment_V5_t filing_date;
} pd_Document_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundingRoundName_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V5_t;

typedef struct {
    pd_PortfolioId_V5_t from;
    pd_PortfolioId_V5_t to;
    pd_Ticker_V5_t asset;
    pd_Balance_t amount;
} pd_Leg_V5_t;

typedef struct {
    uint32_t value;
} pd_LocalCAId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Memo_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MetaDescription_V5_t;

typedef struct {
    uint32_t value;
} pd_MetaVersion_V5_t;

typedef struct {
    pd_Ticker_V5_t ticker;
    pd_Balance_t balance;
} pd_MovePortfolioItem_V5_t;

typedef struct {
    uint8_t some;
    pd_MetaUrl_V5_t contained;
} pd_OptionMetaUrl_V5_t;

typedef struct {
    pd_Permill_V5_t value;
} pd_Percentage_V5_t;

typedef struct {
    uint64_t value;
} pd_Period_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PipDescription_V5_t;

typedef struct {
    pd_Balance_t total;
    pd_Balance_t price;
} pd_PriceTier_V5_t;

typedef struct {
    uint64_t receipt_uid;
    uint64_t leg_id;
    pd_AccountId_V5_t signer;
    pd_OffChainSignature_V5_t signature;
    pd_ReceiptMetadata_V5_t metadata;
} pd_ReceiptDetails_V5_t;

typedef struct {
    uint8_t value;
    union {
        pd_Moment_V5_t scheduled;
        pd_ScheduleId_V5_t existingSchedule;
        pd_CheckpointId_V5_t existing;
    };
} pd_RecordDateSpec_V5_t;

typedef struct {
    pd_SecondaryKey_V5_t secondary_key;
    pd_Signature_V5_t auth_signature;
} pd_SecondaryKeyWithAuth_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_SmartExtensionName_V5_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_SmartExtensionType_V5_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V5_t;

typedef struct {
    pd_VecIdentityId_V5_t identities;
    pd_TargetTreatment_V5_t treatment;
} pd_TargetIdentities_V5_t;

typedef struct {
    pd_IdentityId_V5_t identity;
    pd_bool_t val;
} pd_TupleIdentityIdbool_V5_t;

typedef struct {
    pd_PipId_V5_t pip_id;
    pd_SnapshotResult_V5_t snapshot_result;
} pd_TuplePipIdSnapshotResult_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Url_V5_t;

typedef struct {
    uint16_t value;
} pd_ValidatorIndex_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMotion_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdTax_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_VenueDetails_V5_t;

typedef struct {
    uint8_t value;
} pd_VenueType_V5_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V5_t identityId;
        pd_AccountId_V5_t accountId;
        pd_Ticker_V5_t ticker;
        pd_Permissions_V5_t permissions;
        pd_PortfolioId_V5_t portfolioId;
    };
} pd_AuthorizationData_V5_t;

typedef struct {
    pd_BallotTitle_V5_t title;
    pd_VecMotion_V5_t motions;
} pd_BallotMeta_V5_t;

typedef struct {
    pd_Moment_V5_t start;
    pd_Moment_V5_t end;
} pd_BallotTimeRange_V5_t;

typedef struct {
    pd_Ticker_V5_t ticker;
    pd_LocalCAId_V5_t local_id;
} pd_CAId_V5_t;

typedef struct {
    pd_EthereumAddress_V5_t eth_owner;
    pd_Ticker_V5_t ticker;
    pd_bool_t is_contract;
    pd_bool_t is_created;
} pd_ClassicTickerImport_V5_t;

typedef struct {
    pd_Hash_t hash;
} pd_CodeHash_V5_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_MaybeBlock_V5_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V5_t contained;
} pd_OptionChangesTrieConfiguration_V5_t;

typedef struct {
    uint8_t some;
    pd_ReceiptDetails_V5_t contained;
} pd_OptionReceiptDetails_V5_t;

typedef struct {
    uint8_t some;
    pd_RecordDateSpec_V5_t contained;
} pd_OptionRecordDateSpec_V5_t;

typedef struct {
    uint8_t some;
    pd_TargetIdentities_V5_t contained;
} pd_OptionTargetIdentities_V5_t;

typedef struct {
    uint8_t some;
    pd_Tax_V5_t contained;
} pd_OptionTax_V5_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V5_t dependency;
} pd_Priority_V5_t;

typedef struct {
    pd_OptionMoment_V5_t start;
    pd_CalendarPeriod_V5_t period;
} pd_ScheduleSpec_V5_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_SettlementType_V5_t;

typedef struct {
    pd_SmartExtensionType_V5_t extension_type;
    pd_SmartExtensionName_V5_t extension_name;
    pd_AccountId_V5_t extension_id;
    pd_bool_t is_archive;
} pd_SmartExtension_V5_t;

typedef struct {
    pd_IdentityId_V5_t targetId;
    uint64_t nonce;
    pd_Moment_V5_t expiresAt;
} pd_TargetIdAuthorization_V5_t;

typedef struct {
    pd_OptionMetaUrl_V5_t url;
    pd_SmartExtensionType_V5_t se_type;
    pd_Balance_t usage_fee;
    pd_MetaDescription_V5_t description;
    pd_MetaVersion_V5_t version;
} pd_TemplateMetadata_V5_t;

typedef struct {
    uint8_t max_ticker_length;
    pd_OptionMoment_V5_t registration_length;
} pd_TickerRegistrationConfig_V5_t;

typedef struct {
    uint8_t value;
    union {
        pd_Counter_V5_t countTransferManager;
        pd_Percentage_V5_t percentageTransferManager;
    };
} pd_TransferManager_V5_t;

typedef struct {
    uint64_t nonce;
    pd_Call_t call;
} pd_UniqueCall_V5_t;

typedef struct {
    pd_CompactPerBill_V5_t commission;
} pd_ValidatorPrefs_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBallotVote_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBeneficiary_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBridgeTx_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecComplianceRequirement_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocument_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLeg_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMovePortfolioItem_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPriceTier_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecReceiptDetails_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKeyWithAuth_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKey_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSignatory_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdbool_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePipIdSnapshotResult_V5_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetName_V5_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetType_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_CADetails_V5_t;

typedef struct {
    uint8_t value;
} pd_CAKind_V5_t;

typedef compactInt_t pd_CompactAssignments_V5_t;

typedef compactInt_t pd_CompactEraIndex_V5_t;

typedef compactInt_t pd_CompactGas_V5_t;

typedef compactInt_t pd_CompactMoment_V5_t;

typedef compactInt_t pd_CompactProposalIndex_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V5_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V5_t;

typedef struct {
    compactInt_t validators;
    compactInt_t nominators;
} pd_ElectionSize_V5_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_EquivocationProof_V5_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundraiserName_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorUid_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorZKProofData_V5_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V5_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V5_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LegacyPermissions_V5_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V5_t;

typedef struct {
    uint32_t max_offline_percent;
    uint32_t constant;
    uint32_t max_slash_percent;
} pd_OfflineSlashingParams_V5_t;

typedef struct {
    uint8_t some;
    pd_FundingRoundName_V5_t contained;
} pd_OptionFundingRoundName_V5_t;

typedef struct {
    uint8_t some;
    pd_Memo_V5_t contained;
} pd_OptionMemo_V5_t;

typedef struct {
    uint8_t some;
    pd_Period_V5_t contained;
} pd_OptionPeriod_V5_t;

typedef struct {
    uint8_t some;
    pd_PipDescription_V5_t contained;
} pd_OptionPipDescription_V5_t;

typedef struct {
    uint8_t some;
    pd_PortfolioNumber_V5_t contained;
} pd_OptionPortfolioNumber_V5_t;

typedef struct {
    uint8_t some;
    pd_Url_V5_t contained;
} pd_OptionUrl_V5_t;

typedef struct {
    uint8_t some;
    pd_VecTupleIdentityIdTax_V5_t contained;
} pd_OptionVecTupleIdentityIdTax_V5_t;

typedef struct {
    uint8_t some;
    pd_VenueDetails_V5_t contained;
} pd_OptionVenueDetails_V5_t;

typedef struct {
    uint8_t some;
    pd_VenueType_V5_t contained;
} pd_OptionVenueType_V5_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V5_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PortfolioName_V5_t;

typedef struct {
    uint32_t numerator;
    uint32_t denominator;
} pd_PosRatio_V5_t;

typedef struct {
    uint32_t value;
} pd_ProposalIndex_V5_t;

typedef struct {
    uint8_t value;
} pd_ProtocolOp_V5_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V5_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Schedule_V5_t;

typedef struct {
    uint8_t value;
} pd_SkippedCount_V5_t;

typedef struct {
    uint8_t value;
} pd_SlashingSwitch_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdentifier_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocumentId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecScopeId_V5_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecValidatorIndex_V5_t;

typedef struct {
    uint64_t value;
} pd_Weight_V5_t;

#ifdef __cplusplus
}
#endif
