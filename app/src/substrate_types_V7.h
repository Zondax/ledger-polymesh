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
} pd_DispatchableName_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_IdentityId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Ticker_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CddId_V7_t;

typedef struct {
    uint8_t value;
} pd_ClaimType_V7_t;

typedef struct {
    uint8_t value;
} pd_CountryCode_V7_t;

typedef struct {
    uint64_t value;
} pd_PortfolioNumber_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_ScopeId_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V7_t identity;
        pd_Ticker_V7_t ticker;
        uint64_t _len;
        const uint8_t* _ptr;
    };
} pd_Scope_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDispatchableName_V7_t;

typedef struct {
    uint8_t some;
    pd_VecDispatchableName_V7_t contained;
} pd_OptionVecDispatchableName_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PalletName_V7_t;

typedef struct {
    uint8_t value;
    pd_PortfolioNumber_V7_t number;
} pd_PortfolioKind_V7_t;

typedef struct {
    pd_CountryCode_V7_t country_code;
    pd_Scope_V7_t scope;
} pd_TupleCountryCodeScope_V7_t;

typedef struct {
    pd_Scope_V7_t scope;
    pd_ScopeId_V7_t scopeId;
    pd_CddId_V7_t cddId;
} pd_TupleScopeScopeIdCddId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaimType_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_Scope_V7_t scope;
        pd_CddId_V7_t cddId;
        pd_TupleCountryCodeScope_V7_t jurisdiction;
        pd_TupleScopeScopeIdCddId_V7_t investorUniqueness;
    };
} pd_Claim_V7_t;

typedef struct {
    pd_PalletName_V7_t palletName;
    pd_OptionVecDispatchableName_V7_t dispatchableNames;
} pd_PalletPermissions_V7_t;

typedef struct {
    pd_IdentityId_V7_t did;
    pd_PortfolioKind_V7_t kind;
} pd_PortfolioId_V7_t;

typedef struct {
    uint8_t value;
    pd_VecClaimType_V7_t claims;
} pd_TrustedFor_V7_t;

typedef struct {
    uint8_t value;
    pd_IdentityId_V7_t specific;
} pd_TargetIdentity_V7_t;

typedef struct {
    pd_IdentityId_V7_t issuer;
    pd_TrustedFor_V7_t trustedFor;
} pd_TrustedIssuer_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaim_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPalletPermissions_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPortfolioId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTicker_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ChoiceTitle_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_Claim_V7_t claim;
        pd_VecClaim_V7_t vecClaim;
        pd_TargetIdentity_V7_t identity;
    };
} pd_ConditionType_V7_t;

typedef struct {
    uint8_t some;
    pd_VecPalletPermissions_V7_t contained;
} pd_OptionVecPalletPermissions_V7_t;

typedef struct {
    uint8_t some;
    pd_VecPortfolioId_V7_t contained;
} pd_OptionVecPortfolioId_V7_t;

typedef struct {
    uint8_t some;
    pd_VecTicker_V7_t contained;
} pd_OptionVecTicker_V7_t;

typedef struct {
    uint32_t value;
} pd_Permill_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTrustedIssuer_V7_t;

typedef struct {
    pd_ConditionType_V7_t conditionType;
    pd_VecTrustedIssuer_V7_t issuers;
} pd_Condition_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentType_V7_t;

typedef struct {
    pd_PalletName_V7_t palletName;
    pd_bool_t total;
    pd_VecDispatchableName_V7_t dispatchableNames;
} pd_LegacyPalletPermissions_V7_t;

typedef struct {
    uint64_t value;
} pd_Moment_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionInfoLink_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionTitle_V7_t;

typedef struct {
    pd_OptionVecTicker_V7_t asset;
    pd_OptionVecPalletPermissions_V7_t extrinsic;
    pd_OptionVecPortfolioId_V7_t portfolio;
} pd_Permissions_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V7_t identity;
        pd_AccountId_V7_t account;
    };
} pd_Signatory_V7_t;

typedef struct {
    pd_Permill_V7_t value;
} pd_Tax_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecChoiceTitle_V7_t;

typedef struct {
    uint8_t value;
} pd_CalendarUnit_V7_t;

typedef struct {
    uint64_t value;
} pd_CheckpointId_V7_t;

typedef struct {
    uint8_t value;
    uint8_t _len;
    const uint8_t* _ptr;
} pd_DocumentHash_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentName_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentUri_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MetaUrl_V7_t;

typedef struct {
    pd_MotionTitle_V7_t title;
    pd_MotionInfoLink_V7_t info_link;
    pd_VecChoiceTitle_V7_t choices;
} pd_Motion_V7_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_OffChainSignature_V7_t;

typedef struct {
    uint8_t some;
    pd_DocumentType_V7_t contained;
} pd_OptionDocumentType_V7_t;

typedef struct {
    uint8_t some;
    pd_Moment_V7_t contained;
} pd_OptionMoment_V7_t;

typedef struct {
    uint32_t value;
} pd_PipId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ReceiptMetadata_V7_t;

typedef struct {
    uint64_t value;
} pd_ScheduleId_V7_t;

typedef struct {
    pd_Signatory_V7_t signer;
    pd_Permissions_V7_t permissions;
} pd_SecondaryKey_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_V7_t;

typedef struct {
    uint8_t value;
} pd_SnapshotResult_V7_t;

typedef struct {
    uint8_t value;
} pd_TargetTreatment_V7_t;

typedef struct {
    pd_IdentityId_V7_t id;
    pd_Tax_V7_t tax;
} pd_TupleIdentityIdTax_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCondition_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecIdentityId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLegacyPalletPermissions_V7_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetIdentifier_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_BallotTitle_V7_t;

typedef struct {
    pd_Balance_t power;
    pd_Optionu16_t fallback;
} pd_BallotVote_V7_t;

typedef struct {
    pd_IdentityId_V7_t identity;
    pd_Balance_t balance;
} pd_Beneficiary_V7_t;

typedef struct {
    uint32_t nonce;
    pd_AccountId_V7_t recipient;
    pd_Balance_t value;
    pd_Hash_t txHash;
} pd_BridgeTx_V7_t;

typedef struct {
    pd_CalendarUnit_V7_t unit;
    uint64_t amount;
} pd_CalendarPeriod_V7_t;

typedef struct {
    pd_u32_t digest_interval;
    pd_u32_t digest_levels;
} pd_ChangesTrieConfiguration_V7_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V7_t;

typedef struct {
    pd_VecCondition_V7_t senderConditions;
    pd_VecCondition_V7_t receiverConditions;
    uint32_t id;
} pd_ComplianceRequirement_V7_t;

typedef struct {
    uint64_t value;
} pd_Counter_V7_t;

typedef struct {
    uint32_t value;
} pd_DocumentId_V7_t;

typedef struct {
    pd_DocumentUri_V7_t uri;
    pd_DocumentHash_V7_t content_hash;
    pd_DocumentName_V7_t name;
    pd_OptionDocumentType_V7_t doc_type;
    pd_OptionMoment_V7_t filing_date;
} pd_Document_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundingRoundName_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_KeyValue_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Key_V7_t;

typedef struct {
    pd_PortfolioId_V7_t from;
    pd_PortfolioId_V7_t to;
    pd_Ticker_V7_t asset;
    pd_Balance_t amount;
} pd_Leg_V7_t;

typedef struct {
    uint32_t value;
} pd_LocalCAId_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_LookupSource_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Memo_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MetaDescription_V7_t;

typedef struct {
    uint32_t value;
} pd_MetaVersion_V7_t;

typedef struct {
    pd_Ticker_V7_t ticker;
    pd_Balance_t balance;
} pd_MovePortfolioItem_V7_t;

typedef struct {
    uint8_t some;
    pd_MetaUrl_V7_t contained;
} pd_OptionMetaUrl_V7_t;

typedef struct {
    uint8_t some;
    pd_VecLegacyPalletPermissions_V7_t contained;
} pd_OptionVecLegacyPalletPermissions_V7_t;

typedef struct {
    pd_Permill_V7_t value;
} pd_Percentage_V7_t;

typedef struct {
    uint64_t value;
} pd_Period_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PipDescription_V7_t;

typedef struct {
    pd_Balance_t total;
    pd_Balance_t price;
} pd_PriceTier_V7_t;

typedef struct {
    uint64_t receipt_uid;
    uint64_t leg_id;
    pd_AccountId_V7_t signer;
    pd_OffChainSignature_V7_t signature;
    pd_ReceiptMetadata_V7_t metadata;
} pd_ReceiptDetails_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_Moment_V7_t scheduled;
        pd_ScheduleId_V7_t existingSchedule;
        pd_CheckpointId_V7_t existing;
    };
} pd_RecordDateSpec_V7_t;

typedef struct {
    pd_SecondaryKey_V7_t secondary_key;
    pd_Signature_V7_t auth_signature;
} pd_SecondaryKeyWithAuth_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_SmartExtensionName_V7_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_SmartExtensionType_V7_t;

typedef struct {
    pd_u32_t dependency_id;
    uint8_t weight;
    pd_bool_t is_exclusive;
} pd_StreamDependency_V7_t;

typedef struct {
    pd_VecIdentityId_V7_t identities;
    pd_TargetTreatment_V7_t treatment;
} pd_TargetIdentities_V7_t;

typedef struct {
    pd_IdentityId_V7_t identity;
    pd_bool_t val;
} pd_TupleIdentityIdbool_V7_t;

typedef struct {
    pd_PipId_V7_t pip_id;
    pd_SnapshotResult_V7_t snapshot_result;
} pd_TuplePipIdSnapshotResult_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Url_V7_t;

typedef struct {
    uint16_t value;
} pd_ValidatorIndex_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMotion_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdTax_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_VenueDetails_V7_t;

typedef struct {
    uint8_t value;
} pd_VenueType_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V7_t identityId;
        pd_AccountId_V7_t accountId;
        pd_Ticker_V7_t ticker;
        pd_Permissions_V7_t permissions;
        pd_PortfolioId_V7_t portfolioId;
    };
} pd_AuthorizationData_V7_t;

typedef struct {
    pd_BallotTitle_V7_t title;
    pd_VecMotion_V7_t motions;
} pd_BallotMeta_V7_t;

typedef struct {
    pd_Moment_V7_t start;
    pd_Moment_V7_t end;
} pd_BallotTimeRange_V7_t;

typedef struct {
    pd_Ticker_V7_t ticker;
    pd_LocalCAId_V7_t local_id;
} pd_CAId_V7_t;

typedef struct {
    pd_EthereumAddress_V7_t eth_owner;
    pd_Ticker_V7_t ticker;
    pd_bool_t is_contract;
    pd_bool_t is_created;
} pd_ClassicTickerImport_V7_t;

typedef struct {
    pd_Hash_t hash;
} pd_CodeHash_V7_t;

typedef struct {
    pd_OptionVecTicker_V7_t asset;
    pd_OptionVecLegacyPalletPermissions_V7_t extrinsic;
    pd_OptionVecPortfolioId_V7_t portfolio;
} pd_LegacyPermissions_V7_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_MaybeBlock_V7_t;

typedef struct {
    uint8_t some;
    pd_ChangesTrieConfiguration_V7_t contained;
} pd_OptionChangesTrieConfiguration_V7_t;

typedef struct {
    uint8_t some;
    pd_ReceiptDetails_V7_t contained;
} pd_OptionReceiptDetails_V7_t;

typedef struct {
    uint8_t some;
    pd_RecordDateSpec_V7_t contained;
} pd_OptionRecordDateSpec_V7_t;

typedef struct {
    uint8_t some;
    pd_Scope_V7_t contained;
} pd_OptionScope_V7_t;

typedef struct {
    uint8_t some;
    pd_TargetIdentities_V7_t contained;
} pd_OptionTargetIdentities_V7_t;

typedef struct {
    uint8_t some;
    pd_Tax_V7_t contained;
} pd_OptionTax_V7_t;

typedef struct {
    uint32_t stream_id;
    pd_StreamDependency_V7_t dependency;
} pd_Priority_V7_t;

typedef struct {
    pd_OptionMoment_V7_t start;
    pd_CalendarPeriod_V7_t period;
} pd_ScheduleSpec_V7_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_SettlementType_V7_t;

typedef struct {
    pd_SmartExtensionType_V7_t extension_type;
    pd_SmartExtensionName_V7_t extension_name;
    pd_AccountId_V7_t extension_id;
    pd_bool_t is_archive;
} pd_SmartExtension_V7_t;

typedef struct {
    pd_IdentityId_V7_t targetId;
    uint64_t nonce;
    pd_Moment_V7_t expiresAt;
} pd_TargetIdAuthorization_V7_t;

typedef struct {
    pd_OptionMetaUrl_V7_t url;
    pd_SmartExtensionType_V7_t se_type;
    pd_Balance_t usage_fee;
    pd_MetaDescription_V7_t description;
    pd_MetaVersion_V7_t version;
} pd_TemplateMetadata_V7_t;

typedef struct {
    uint8_t max_ticker_length;
    pd_OptionMoment_V7_t registration_length;
} pd_TickerRegistrationConfig_V7_t;

typedef struct {
    uint8_t value;
    union {
        pd_Counter_V7_t countTransferManager;
        pd_Percentage_V7_t percentageTransferManager;
    };
} pd_TransferManager_V7_t;

typedef struct {
    uint64_t nonce;
    pd_Call_t call;
} pd_UniqueCall_V7_t;

typedef struct {
    pd_CompactPerBill_V7_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBallotVote_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBeneficiary_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBridgeTx_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecComplianceRequirement_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocument_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLeg_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMovePortfolioItem_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPriceTier_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecReceiptDetails_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKeyWithAuth_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKey_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSignatory_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdbool_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePipIdSnapshotResult_V7_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetName_V7_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetType_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BabeEquivocationProof_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_CADetails_V7_t;

typedef struct {
    uint8_t value;
} pd_CAKind_V7_t;

typedef compactInt_t pd_CompactAssignments_V7_t;

typedef compactInt_t pd_CompactEraIndex_V7_t;

typedef compactInt_t pd_CompactGas_V7_t;

typedef compactInt_t pd_CompactMoment_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_V7_t;

typedef struct {
    compactInt_t validators;
    compactInt_t nominators;
} pd_ElectionSize_V7_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundraiserName_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_GrandpaEquivocationProof_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorZKProofData_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_V7_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V7_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V7_t;

typedef struct {
    uint8_t some;
    pd_FundingRoundName_V7_t contained;
} pd_OptionFundingRoundName_V7_t;

typedef struct {
    uint8_t some;
    pd_Memo_V7_t contained;
} pd_OptionMemo_V7_t;

typedef struct {
    uint8_t some;
    pd_Period_V7_t contained;
} pd_OptionPeriod_V7_t;

typedef struct {
    uint8_t some;
    pd_PipDescription_V7_t contained;
} pd_OptionPipDescription_V7_t;

typedef struct {
    uint8_t some;
    pd_PortfolioNumber_V7_t contained;
} pd_OptionPortfolioNumber_V7_t;

typedef struct {
    uint8_t some;
    pd_Url_V7_t contained;
} pd_OptionUrl_V7_t;

typedef struct {
    uint8_t some;
    pd_VecTupleIdentityIdTax_V7_t contained;
} pd_OptionVecTupleIdentityIdTax_V7_t;

typedef struct {
    uint8_t some;
    pd_VenueDetails_V7_t contained;
} pd_OptionVenueDetails_V7_t;

typedef struct {
    uint8_t some;
    pd_VenueType_V7_t contained;
} pd_OptionVenueType_V7_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V7_t;

typedef struct {
    compactInt_t value;
} pd_Percent_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PortfolioName_V7_t;

typedef struct {
    uint32_t numerator;
    uint32_t denominator;
} pd_PosRatio_V7_t;

typedef struct {
    uint32_t value;
} pd_ProposalIndex_V7_t;

typedef struct {
    uint8_t value;
} pd_ProtocolOp_V7_t;

typedef struct {
    uint8_t value;
} pd_RewardDestination_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Schedule_V7_t;

typedef struct {
    // TODO: Not implemented
    uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ScopeClaimProof_V7_t;

typedef struct {
    uint8_t value;
} pd_SkippedCount_V7_t;

typedef struct {
    uint8_t value;
} pd_SlashingSwitch_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdentifier_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocumentId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKeyValue_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecKey_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupSource_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecScopeId_V7_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecValidatorIndex_V7_t;

typedef struct {
    uint64_t value;
} pd_Weight_V7_t;

#ifdef __cplusplus
}
#endif
