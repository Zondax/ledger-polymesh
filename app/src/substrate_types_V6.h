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
} pd_DispatchableName_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_IdentityId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Ticker_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CddId_V6_t;

typedef struct {
    uint8_t value;
} pd_ClaimType_V6_t;

typedef struct {
    uint8_t value;
} pd_CountryCode_V6_t;

typedef struct {
    uint64_t value;
} pd_PortfolioNumber_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_ScopeId_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V6_t identity;
        pd_Ticker_V6_t ticker;
        uint64_t _len;
        const uint8_t* _ptr;
    };
} pd_Scope_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDispatchableName_V6_t;

typedef struct {
    uint8_t some;
    pd_VecDispatchableName_V6_t contained;
} pd_OptionVecDispatchableName_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PalletName_V6_t;

typedef struct {
    uint8_t value;
    pd_PortfolioNumber_V6_t number;
} pd_PortfolioKind_V6_t;

typedef struct {
    pd_CountryCode_V6_t country_code;
    pd_Scope_V6_t scope;
} pd_TupleCountryCodeScope_V6_t;

typedef struct {
    pd_Scope_V6_t scope;
    pd_ScopeId_V6_t scopeId;
    pd_CddId_V6_t cddId;
} pd_TupleScopeScopeIdCddId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaimType_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_Scope_V6_t scope;
        pd_CddId_V6_t cddId;
        pd_TupleCountryCodeScope_V6_t jurisdiction;
        pd_TupleScopeScopeIdCddId_V6_t investorUniqueness;
    };
} pd_Claim_V6_t;

typedef struct {
    pd_PalletName_V6_t palletName;
    pd_OptionVecDispatchableName_V6_t dispatchableNames;
} pd_PalletPermissions_V6_t;

typedef struct {
    pd_IdentityId_V6_t did;
    pd_PortfolioKind_V6_t kind;
} pd_PortfolioId_V6_t;

typedef struct {
    uint8_t value;
    pd_VecClaimType_V6_t claims;
} pd_TrustedFor_V6_t;

typedef struct {
    uint8_t value;
    pd_IdentityId_V6_t specific;
} pd_TargetIdentity_V6_t;

typedef struct {
    pd_IdentityId_V6_t issuer;
    pd_TrustedFor_V6_t trustedFor;
} pd_TrustedIssuer_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaim_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPalletPermissions_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPortfolioId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTicker_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ChoiceTitle_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_Claim_V6_t claim;
        pd_VecClaim_V6_t vecClaim;
        pd_TargetIdentity_V6_t identity;
    };
} pd_ConditionType_V6_t;

typedef struct {
    uint8_t some;
    pd_VecPalletPermissions_V6_t contained;
} pd_OptionVecPalletPermissions_V6_t;

typedef struct {
    uint8_t some;
    pd_VecPortfolioId_V6_t contained;
} pd_OptionVecPortfolioId_V6_t;

typedef struct {
    uint8_t some;
    pd_VecTicker_V6_t contained;
} pd_OptionVecTicker_V6_t;

typedef struct {
    uint32_t value;
} pd_Permill_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTrustedIssuer_V6_t;

typedef struct {
    pd_ConditionType_V6_t conditionType;
    pd_VecTrustedIssuer_V6_t issuers;
} pd_Condition_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentType_V6_t;

typedef struct {
    pd_PalletName_V6_t palletName;
    pd_bool_t total;
    pd_VecDispatchableName_V6_t dispatchableNames;
} pd_LegacyPalletPermissions_V6_t;

typedef struct {
    uint64_t value;
} pd_Moment_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionInfoLink_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionTitle_V6_t;

typedef struct {
    pd_OptionVecTicker_V6_t asset;
    pd_OptionVecPalletPermissions_V6_t extrinsic;
    pd_OptionVecPortfolioId_V6_t portfolio;
} pd_Permissions_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V6_t identity;
        pd_AccountId_V6_t account;
    };
} pd_Signatory_V6_t;

typedef struct {
    pd_Permill_V6_t value;
} pd_Tax_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecChoiceTitle_V6_t;

typedef struct {
    uint8_t value;
} pd_CalendarUnit_V6_t;

typedef struct {
    uint64_t value;
} pd_CheckpointId_V6_t;

typedef struct {
    uint8_t value;
    uint8_t _len;
    const uint8_t* _ptr;
} pd_DocumentHash_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentName_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentUri_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MetaUrl_V6_t;

typedef struct {
    pd_MotionTitle_V6_t title;
    pd_MotionInfoLink_V6_t info_link;
    pd_VecChoiceTitle_V6_t choices;
} pd_Motion_V6_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_OffChainSignature_V6_t;

typedef struct {
    uint8_t some;
    pd_DocumentType_V6_t contained;
} pd_OptionDocumentType_V6_t;

typedef struct {
    uint8_t some;
    pd_Moment_V6_t contained;
} pd_OptionMoment_V6_t;

typedef struct {
    uint32_t value;
} pd_PipId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ReceiptMetadata_V6_t;

typedef struct {
    uint64_t value;
} pd_ScheduleId_V6_t;

typedef struct {
    pd_Signatory_V6_t signer;
    pd_Permissions_V6_t permissions;
} pd_SecondaryKey_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_V6_t;

typedef struct {
    uint8_t value;
} pd_SnapshotResult_V6_t;

typedef struct {
    uint8_t value;
} pd_TargetTreatment_V6_t;

typedef struct {
    pd_IdentityId_V6_t id;
    pd_Tax_V6_t tax;
} pd_TupleIdentityIdTax_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCondition_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecIdentityId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLegacyPalletPermissions_V6_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetIdentifier_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_BallotTitle_V6_t;

typedef struct {
    pd_Balance_t power;
    pd_Optionu16_t fallback;
} pd_BallotVote_V6_t;

typedef struct {
    pd_IdentityId_V6_t identity;
    pd_Balance_t balance;
} pd_Beneficiary_V6_t;

typedef struct {
    uint32_t nonce;
    pd_AccountId_V6_t recipient;
    pd_Balance_t value;
    pd_Hash_t txHash;
} pd_BridgeTx_V6_t;

typedef struct {
    pd_CalendarUnit_V6_t unit;
    uint64_t amount;
} pd_CalendarPeriod_V6_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V6_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V6_t;

typedef struct {
    pd_VecCondition_V6_t senderConditions;
    pd_VecCondition_V6_t receiverConditions;
    uint32_t id;
} pd_ComplianceRequirement_V6_t;

typedef struct {
    uint64_t value;
} pd_Counter_V6_t;

typedef struct {
    uint32_t value;
} pd_DocumentId_V6_t;

typedef struct {
    pd_DocumentUri_V6_t uri;
    pd_DocumentHash_V6_t content_hash;
    pd_DocumentName_V6_t name;
    pd_OptionDocumentType_V6_t doc_type;
    pd_OptionMoment_V6_t filing_date;
} pd_Document_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundingRoundName_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V6_t;

typedef struct {
    pd_PortfolioId_V6_t from;
    pd_PortfolioId_V6_t to;
    pd_Ticker_V6_t asset;
    pd_Balance_t amount;
} pd_Leg_V6_t;

typedef struct {
    uint32_t value;
} pd_LocalCAId_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_LookupSource_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Memo_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MetaDescription_V6_t;

typedef struct {
    uint32_t value;
} pd_MetaVersion_V6_t;

typedef struct {
    pd_Ticker_V6_t ticker;
    pd_Balance_t balance;
} pd_MovePortfolioItem_V6_t;

typedef struct {
    uint8_t some;
    pd_MetaUrl_V6_t contained;
} pd_OptionMetaUrl_V6_t;

typedef struct {
    uint8_t some;
    pd_VecLegacyPalletPermissions_V6_t contained;
} pd_OptionVecLegacyPalletPermissions_V6_t;

typedef struct {
    pd_Permill_V6_t value;
} pd_Percentage_V6_t;

typedef struct {
    uint64_t value;
} pd_Period_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PipDescription_V6_t;

typedef struct {
    pd_Balance_t total;
    pd_Balance_t price;
} pd_PriceTier_V6_t;

typedef struct {
    uint64_t receipt_uid;
    uint64_t leg_id;
    pd_AccountId_V6_t signer;
    pd_OffChainSignature_V6_t signature;
    pd_ReceiptMetadata_V6_t metadata;
} pd_ReceiptDetails_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_Moment_V6_t scheduled;
        pd_ScheduleId_V6_t existingSchedule;
        pd_CheckpointId_V6_t existing;
    };
} pd_RecordDateSpec_V6_t;

typedef struct {
    pd_SecondaryKey_V6_t secondary_key;
    pd_Signature_V6_t auth_signature;
} pd_SecondaryKeyWithAuth_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_SmartExtensionName_V6_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_SmartExtensionType_V6_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V6_t;

typedef struct {
    pd_VecIdentityId_V6_t identities;
    pd_TargetTreatment_V6_t treatment;
} pd_TargetIdentities_V6_t;

typedef struct {
    pd_IdentityId_V6_t identity;
    pd_bool_t val;
} pd_TupleIdentityIdbool_V6_t;

typedef struct {
    pd_PipId_V6_t pip_id;
    pd_SnapshotResult_V6_t snapshot_result;
} pd_TuplePipIdSnapshotResult_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Url_V6_t;

typedef struct {
    uint16_t value;
} pd_ValidatorIndex_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMotion_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdTax_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_VenueDetails_V6_t;

typedef struct {
    uint8_t value;
} pd_VenueType_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V6_t identityId;
        pd_AccountId_V6_t accountId;
        pd_Ticker_V6_t ticker;
        pd_Permissions_V6_t permissions;
        pd_PortfolioId_V6_t portfolioId;
    };
} pd_AuthorizationData_V6_t;

typedef struct {
    pd_BallotTitle_V6_t title;
    pd_VecMotion_V6_t motions;
} pd_BallotMeta_V6_t;

typedef struct {
    pd_Moment_V6_t start;
    pd_Moment_V6_t end;
} pd_BallotTimeRange_V6_t;

typedef struct {
    pd_Ticker_V6_t ticker;
    pd_LocalCAId_V6_t local_id;
} pd_CAId_V6_t;

typedef struct {
    pd_EthereumAddress_V6_t eth_owner;
    pd_Ticker_V6_t ticker;
    pd_bool_t is_contract;
    pd_bool_t is_created;
} pd_ClassicTickerImport_V6_t;

typedef struct {
    pd_Hash_t hash;
} pd_CodeHash_V6_t;

typedef struct {
    pd_OptionVecTicker_V6_t asset;
    pd_OptionVecLegacyPalletPermissions_V6_t extrinsic;
    pd_OptionVecPortfolioId_V6_t portfolio;
} pd_LegacyPermissions_V6_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_MaybeBlock_V6_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V6_t contained;
} pd_OptionChangesTrieConfiguration_V6_t;

typedef struct {
    uint8_t some;
    pd_ReceiptDetails_V6_t contained;
} pd_OptionReceiptDetails_V6_t;

typedef struct {
    uint8_t some;
    pd_RecordDateSpec_V6_t contained;
} pd_OptionRecordDateSpec_V6_t;

typedef struct {
    uint8_t some;
    pd_TargetIdentities_V6_t contained;
} pd_OptionTargetIdentities_V6_t;

typedef struct {
    uint8_t some;
    pd_Tax_V6_t contained;
} pd_OptionTax_V6_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V6_t dependency;
} pd_Priority_V6_t;

typedef struct {
    pd_OptionMoment_V6_t start;
    pd_CalendarPeriod_V6_t period;
} pd_ScheduleSpec_V6_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_SettlementType_V6_t;

typedef struct {
    pd_SmartExtensionType_V6_t extension_type;
    pd_SmartExtensionName_V6_t extension_name;
    pd_AccountId_V6_t extension_id;
    pd_bool_t is_archive;
} pd_SmartExtension_V6_t;

typedef struct {
    pd_IdentityId_V6_t targetId;
    uint64_t nonce;
    pd_Moment_V6_t expiresAt;
} pd_TargetIdAuthorization_V6_t;

typedef struct {
    pd_OptionMetaUrl_V6_t url;
    pd_SmartExtensionType_V6_t se_type;
    pd_Balance_t usage_fee;
    pd_MetaDescription_V6_t description;
    pd_MetaVersion_V6_t version;
} pd_TemplateMetadata_V6_t;

typedef struct {
    uint8_t max_ticker_length;
    pd_OptionMoment_V6_t registration_length;
} pd_TickerRegistrationConfig_V6_t;

typedef struct {
    uint8_t value;
    union {
        pd_Counter_V6_t countTransferManager;
        pd_Percentage_V6_t percentageTransferManager;
    };
} pd_TransferManager_V6_t;

typedef struct {
    uint64_t nonce;
    pd_Call_t call;
} pd_UniqueCall_V6_t;

typedef struct {
    pd_CompactPerBill_V6_t commission;
} pd_ValidatorPrefs_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBallotVote_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBeneficiary_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBridgeTx_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecComplianceRequirement_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocument_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLeg_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMovePortfolioItem_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPriceTier_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecReceiptDetails_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKeyWithAuth_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKey_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSignatory_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdbool_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePipIdSnapshotResult_V6_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetName_V6_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetType_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_CADetails_V6_t;

typedef struct {
    uint8_t value;
} pd_CAKind_V6_t;

typedef compactInt_t pd_CompactAssignments_V6_t;

typedef compactInt_t pd_CompactEraIndex_V6_t;

typedef compactInt_t pd_CompactGas_V6_t;

typedef compactInt_t pd_CompactMoment_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V6_t;

typedef struct {
    compactInt_t validators;
    compactInt_t nominators;
} pd_ElectionSize_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_EquivocationProof_V6_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundraiserName_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorUid_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorZKProofData_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V6_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V6_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V6_t;

typedef struct {
    uint32_t max_offline_percent;
    uint32_t constant;
    uint32_t max_slash_percent;
} pd_OfflineSlashingParams_V6_t;

typedef struct {
    uint8_t some;
    pd_FundingRoundName_V6_t contained;
} pd_OptionFundingRoundName_V6_t;

typedef struct {
    uint8_t some;
    pd_Memo_V6_t contained;
} pd_OptionMemo_V6_t;

typedef struct {
    uint8_t some;
    pd_Period_V6_t contained;
} pd_OptionPeriod_V6_t;

typedef struct {
    uint8_t some;
    pd_PipDescription_V6_t contained;
} pd_OptionPipDescription_V6_t;

typedef struct {
    uint8_t some;
    pd_PortfolioNumber_V6_t contained;
} pd_OptionPortfolioNumber_V6_t;

typedef struct {
    uint8_t some;
    pd_Url_V6_t contained;
} pd_OptionUrl_V6_t;

typedef struct {
    uint8_t some;
    pd_VecTupleIdentityIdTax_V6_t contained;
} pd_OptionVecTupleIdentityIdTax_V6_t;

typedef struct {
    uint8_t some;
    pd_VenueDetails_V6_t contained;
} pd_OptionVenueDetails_V6_t;

typedef struct {
    uint8_t some;
    pd_VenueType_V6_t contained;
} pd_OptionVenueType_V6_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V6_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PortfolioName_V6_t;

typedef struct {
    uint32_t numerator;
    uint32_t denominator;
} pd_PosRatio_V6_t;

typedef struct {
    uint32_t value;
} pd_ProposalIndex_V6_t;

typedef struct {
    uint8_t value;
} pd_ProtocolOp_V6_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V6_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Schedule_V6_t;

typedef struct {
    uint8_t value;
} pd_SkippedCount_V6_t;

typedef struct {
    uint8_t value;
} pd_SlashingSwitch_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdentifier_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocumentId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecScopeId_V6_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecValidatorIndex_V6_t;

typedef struct {
    uint64_t value;
} pd_Weight_V6_t;

#ifdef __cplusplus
}
#endif
