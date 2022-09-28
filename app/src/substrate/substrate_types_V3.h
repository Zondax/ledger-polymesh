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
} pd_DispatchableName_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_IdentityId_V3_t;

typedef struct {
    uint64_t value;
} pd_PortfolioNumber_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Ticker_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDispatchableName_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CddId_V3_t;

typedef struct {
    uint8_t value;
} pd_ClaimType_V3_t;

typedef struct {
    uint8_t value;
} pd_CountryCode_V3_t;

typedef struct {
    uint8_t value;
    pd_VecDispatchableName_V3_t contained;
} pd_DispatchableNames_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PalletName_V3_t;

typedef struct {
    uint8_t value;
    pd_PortfolioNumber_V3_t number;
} pd_PortfolioKind_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_ScopeId_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V3_t identity;
        pd_Ticker_V3_t ticker;
        uint64_t _len;
        const uint8_t* _ptr;
    };
} pd_Scope_V3_t;

typedef struct {
    pd_PalletName_V3_t palletName;
    pd_DispatchableNames_V3_t dispatchableNames;
} pd_PalletPermissions_V3_t;

typedef struct {
    pd_IdentityId_V3_t did;
    pd_PortfolioKind_V3_t kind;
} pd_PortfolioId_V3_t;

typedef struct {
    pd_CountryCode_V3_t country_code;
    pd_Scope_V3_t scope;
} pd_TupleCountryCodeScope_V3_t;

typedef struct {
    pd_Scope_V3_t scope;
    pd_ScopeId_V3_t scopeId;
    pd_CddId_V3_t cddId;
} pd_TupleScopeScopeIdCddId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaimType_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ChoiceTitle_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Scope_V3_t scope;
        pd_CddId_V3_t cddId;
        pd_TupleCountryCodeScope_V3_t jurisdiction;
        pd_TupleScopeScopeIdCddId_V3_t investorUniqueness;
    };
} pd_Claim_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Signature_V3_t;

typedef struct {
    uint32_t value;
} pd_Permill_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Signature_V3_t;

typedef struct {
    uint8_t value;
    pd_VecClaimType_V3_t claims;
} pd_TrustedFor_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPalletPermissions_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPortfolioId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTicker_V3_t;

typedef struct {
    uint32_t value;
} pd_AGId_V3_t;

typedef struct {
    uint8_t value;
    pd_VecTicker_V3_t contained;
} pd_AssetPermissions_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentType_V3_t;

typedef struct {
    uint8_t value;
    pd_VecPalletPermissions_V3_t contained;
} pd_ExtrinsicPermissions_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Memo_V3_t;

typedef struct {
    uint64_t value;
} pd_Moment_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionInfoLink_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionTitle_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Signature_V3_t ed25519;
        pd_Sr25519Signature_V3_t sr25519;
        pd_EcdsaSignature_V3_t ecdsa;
    };
} pd_MultiSignature_V3_t;

typedef struct {
    uint8_t value;
    pd_VecPortfolioId_V3_t contained;
} pd_PortfolioPermissions_V3_t;

typedef struct {
    uint8_t value;
    pd_IdentityId_V3_t specific;
} pd_TargetIdentity_V3_t;

typedef struct {
    pd_Permill_V3_t value;
} pd_Tax_V3_t;

typedef struct {
    pd_IdentityId_V3_t issuer;
    pd_TrustedFor_V3_t trustedFor;
} pd_TrustedIssuer_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecChoiceTitle_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaim_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_V3_t;

typedef struct {
    uint8_t value;
    pd_AGId_V3_t agId;

} pd_AgentGroup_V3_t;

typedef struct {
    uint8_t value;
    pd_Moment_V3_t moment;
} pd_AssetMetadataLockStatusMoment_V3_t;

typedef struct {
    uint8_t value;
} pd_CalendarUnit_V3_t;

typedef struct {
    uint64_t value;
} pd_CheckpointId_V3_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Claim_V3_t claim;
        pd_VecClaim_V3_t vecClaim;
        pd_TargetIdentity_V3_t identity;
    };
} pd_ConditionType_V3_t;

typedef struct {
    uint8_t value;
    uint8_t _len;
    const uint8_t* _ptr;
} pd_DocumentHash_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentName_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentUri_V3_t;

typedef struct {
    pd_MotionTitle_V3_t title;
    pd_MotionInfoLink_V3_t info_link;
    pd_VecChoiceTitle_V3_t choices;
} pd_Motion_V3_t;

typedef struct {
    pd_MultiSignature_V3_t value;
} pd_OffChainSignature_V3_t;

typedef struct {
    uint8_t some;
    pd_DocumentType_V3_t contained;
} pd_OptionDocumentType_V3_t;

typedef struct {
    uint8_t some;
    pd_Memo_V3_t contained;
} pd_OptionMemo_V3_t;

typedef struct {
    uint8_t some;
    pd_Moment_V3_t contained;
} pd_OptionMoment_V3_t;

typedef struct {
    pd_AssetPermissions_V3_t asset;
    pd_ExtrinsicPermissions_V3_t extrinsic;
    pd_PortfolioPermissions_V3_t portfolio;
} pd_Permissions_V3_t;

typedef struct {
    uint32_t value;
} pd_PipId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ReceiptMetadata_V3_t;

typedef struct {
    uint64_t value;
} pd_ScheduleId_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_V3_t;

typedef struct {
    uint8_t value;
} pd_SnapshotResult_V3_t;

typedef struct {
    uint8_t value;
} pd_TargetTreatment_V3_t;

typedef struct {
    pd_IdentityId_V3_t id;
    pd_Tax_V3_t tax;
} pd_TupleIdentityIdTax_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecIdentityId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTrustedIssuer_V3_t;

typedef struct {
    pd_AccountId_V3_t accountId_1;
    pd_AccountId_V3_t accountId_2;
    pd_Balance_t balance;
} pd_AddRelayerPayingKey_V3_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetIdentifier_V3_t;

typedef struct {
    pd_OptionMoment_V3_t expire;
    pd_AssetMetadataLockStatusMoment_V3_t lockStatus;
} pd_AssetMetadataValueDetailMoment_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_BallotTitle_V3_t;

typedef struct {
    pd_Balance_t power;
    pd_Optionu16_t fallback;
} pd_BallotVote_V3_t;

typedef struct {
    pd_Ticker_V3_t ticker;
    pd_AgentGroup_V3_t agentGroup;
} pd_BecomeAgent_V3_t;

typedef struct {
    pd_IdentityId_V3_t identity;
    pd_Balance_t balance;
} pd_Beneficiary_V3_t;

typedef struct {
    uint32_t nonce;
    pd_AccountId_V3_t recipient;
    pd_Balance_t value;
    pd_Hash_t txHash;
} pd_BridgeTxAccountId_V3_t;

typedef struct {
    pd_CalendarUnit_V3_t unit;
    uint64_t amount;
} pd_CalendarPeriod_V3_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_V3_t;

typedef struct {
    pd_ConditionType_V3_t conditionType;
    pd_VecTrustedIssuer_V3_t issuers;
} pd_Condition_V3_t;

typedef struct {
    uint32_t value;
} pd_CustomAssetTypeId_V3_t;

typedef struct {
    uint32_t value;
} pd_DocumentId_V3_t;

typedef struct {
    pd_DocumentUri_V3_t uri;
    pd_DocumentHash_V3_t content_hash;
    pd_DocumentName_V3_t name;
    pd_OptionDocumentType_V3_t doc_type;
    pd_OptionMoment_V3_t filing_date;
} pd_Document_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EthereumAddress_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundingRoundName_V3_t;

typedef struct {
    pd_PortfolioId_V3_t from;
    pd_PortfolioId_V3_t to;
    pd_Ticker_V3_t asset;
    pd_Balance_t amount;
} pd_Leg_V3_t;

typedef struct {
    uint32_t value;
} pd_LocalCAId_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_V3_t id;
        pd_CompactAccountIndex_V3_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_V3_t;

typedef struct {
    pd_Ticker_V3_t ticker;
    pd_Balance_t balance;
    pd_OptionMemo_V3_t memo;
} pd_MovePortfolioItem_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PipDescription_V3_t;

typedef struct {
    pd_Balance_t total;
    pd_Balance_t price;
} pd_PriceTier_V3_t;

typedef struct {
    uint64_t receipt_uid;
    uint64_t leg_id;
    pd_AccountId_V3_t signer;
    pd_OffChainSignature_V3_t signature;
    pd_ReceiptMetadata_V3_t metadata;
} pd_ReceiptDetails_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_Moment_V3_t scheduled;
        pd_ScheduleId_V3_t existingSchedule;
        pd_CheckpointId_V3_t existing;
    };
} pd_RecordDateSpec_V3_t;

typedef struct {
    pd_AccountId_V3_t key;
    pd_Permissions_V3_t permissions;
    pd_Signature_V3_t auth_signature;
} pd_SecondaryKeyWithAuthAccountId_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V3_t identity;
        pd_AccountId_V3_t account;
    };
} pd_SignatoryAccountId_V3_t;

typedef struct {
    pd_VecIdentityId_V3_t identities;
    pd_TargetTreatment_V3_t treatment;
} pd_TargetIdentities_V3_t;

typedef struct {
    pd_IdentityId_V3_t identity;
    pd_bool_t val;
} pd_TupleIdentityIdbool_V3_t;

typedef struct {
    pd_PipId_V3_t pip_id;
    pd_SnapshotResult_V3_t snapshot_result;
} pd_TuplePipIdSnapshotResult_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Url_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMotion_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdTax_V3_t;

typedef struct {
    uint64_t value;
} pd_VenueId_V3_t;

typedef struct {
    pd_Bytes_t value;
} pd_AssetMetadataName_V3_t;

typedef struct {
    pd_OptionBytes_t url;
    pd_OptionBytes_t description;
    pd_OptionBytes_t typeDef;
} pd_AssetMetadataSpec_V3_t;

typedef struct {
    pd_Bytes_t value;
} pd_AssetMetadataValue_V3_t;

typedef struct {
    uint8_t value;
    pd_CustomAssetTypeId_V3_t custom;
} pd_AssetType_V3_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_V3_t identityId;
        pd_AccountId_V3_t accountId;
        pd_Ticker_V3_t ticker;
        pd_Permissions_V3_t permissions;
        pd_PortfolioId_V3_t portfolioId;
        pd_BecomeAgent_V3_t becomeAgent;
        pd_AddRelayerPayingKey_V3_t addRelayerPayingKey;
    };
} pd_AuthorizationDataAccountId_V3_t;

typedef struct {
    pd_BallotTitle_V3_t title;
    pd_VecMotion_V3_t motions;
} pd_BallotMeta_V3_t;

typedef struct {
    pd_Moment_V3_t start;
    pd_Moment_V3_t end;
} pd_BallotTimeRange_V3_t;

typedef struct {
    pd_Ticker_V3_t ticker;
    pd_LocalCAId_V3_t local_id;
} pd_CAId_V3_t;

typedef struct {
    pd_EthereumAddress_V3_t eth_owner;
    pd_Ticker_V3_t ticker;
    pd_bool_t is_contract;
    pd_bool_t is_created;
} pd_ClassicTickerImport_V3_t;

typedef struct {
    pd_Hash_t hash;
} pd_CodeHash_V3_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_MaybeBlockBlockNumber_V3_t;

typedef struct {
    uint8_t some;
    pd_AssetMetadataValueDetailMoment_V3_t contained;
} pd_OptionAssetMetadataValueDetailMoment_V3_t;

typedef struct {
    uint8_t some;
    pd_ReceiptDetails_V3_t contained;
} pd_OptionReceiptDetails_V3_t;

typedef struct {
    uint8_t some;
    pd_RecordDateSpec_V3_t contained;
} pd_OptionRecordDateSpec_V3_t;

typedef struct {
    uint8_t some;
    pd_Scope_V3_t contained;
} pd_OptionScope_V3_t;

typedef struct {
    uint8_t some;
    pd_TargetIdentities_V3_t contained;
} pd_OptionTargetIdentities_V3_t;

typedef struct {
    uint8_t some;
    pd_Tax_V3_t contained;
} pd_OptionTax_V3_t;

typedef struct {
    uint8_t value;
    pd_AccountId_V3_t accountId;
} pd_RewardDestination_V3_t;

typedef struct {
    pd_OptionMoment_V3_t start;
    pd_CalendarPeriod_V3_t period;
    uint32_t remaining;
} pd_ScheduleSpec_V3_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_SettlementTypeBlockNumber_V3_t;

typedef struct {
    uint8_t max_ticker_length;
    pd_OptionMoment_V3_t registration_length;
} pd_TickerRegistrationConfigMoment_V3_t;

typedef struct {
    uint64_t nonce;
    pd_Call_t call;
} pd_UniqueCall_V3_t;

typedef struct {
    pd_CompactPerBill_V3_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBallotVote_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBeneficiary_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBridgeTxAccountId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCondition_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocument_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLeg_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMovePortfolioItem_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPriceTier_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecReceiptDetails_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKeyWithAuthAccountId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSignatoryAccountId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdbool_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePipIdSnapshotResult_V3_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_V3_t;

typedef struct {
    uint8_t value;
    uint64_t key;
} pd_AssetMetadataKey_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetName_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_CADetails_V3_t;

typedef struct {
    uint8_t value;
} pd_CAKind_V3_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_V3_t;

typedef struct {
    uint64_t value;
} pd_FundraiserId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundraiserName_V3_t;

typedef struct {
    uint64_t value;
} pd_InstructionId_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_InvestorZKProofData_V3_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_V3_t;

typedef struct {
    uint64_t value;
} pd_LegId_V3_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_V3_t;

typedef struct {
    uint8_t some;
    pd_FundingRoundName_V3_t contained;
} pd_OptionFundingRoundName_V3_t;

typedef struct {
    uint8_t some;
    pd_PipDescription_V3_t contained;
} pd_OptionPipDescription_V3_t;

typedef struct {
    uint8_t some;
    pd_PortfolioNumber_V3_t contained;
} pd_OptionPortfolioNumber_V3_t;

typedef struct {
    uint8_t some;
    pd_Url_V3_t contained;
} pd_OptionUrl_V3_t;

typedef struct {
    uint8_t some;
    pd_VecTupleIdentityIdTax_V3_t contained;
} pd_OptionVecTupleIdentityIdTax_V3_t;

typedef struct {
    uint32_t value;
} pd_Perbill_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PortfolioName_V3_t;

typedef struct {
    uint32_t numerator;
    uint32_t denominator;
} pd_PosRatio_V3_t;

typedef struct {
    uint32_t value;
} pd_ProposalIndex_V3_t;

typedef struct {
    uint8_t value;
} pd_SkippedCount_V3_t;

typedef struct {
    uint8_t value;
} pd_SlashingSwitch_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdentifier_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocumentId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVenueId_V3_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_VenueDetails_V3_t;

typedef struct {
    uint8_t value;
} pd_VenueType_V3_t;

typedef struct {
    uint64_t value;
} pd_Weight_V3_t;

#ifdef __cplusplus
}
#endif
