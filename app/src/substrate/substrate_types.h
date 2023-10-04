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
extern "C" {
#endif

#include "stdbool.h"
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
#pragma clang diagnostic pop
#endif

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define Data_e_NONE 0
#define Data_e_RAW_VECU8 33
#define Data_e_BLAKETWO256U8_32 34
#define Data_e_SHA256_U8_32 35
#define Data_e_KECCAK256_U8_32 36
#define Data_e_SHATHREE256_U8_32 37

typedef uint8_t pd_bool_t;
typedef uint8_t pd_u8_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;
typedef uint32_t pd_BlockNumber_t;

#define CHECK_ERROR(FUNC_CALL)          \
    {                                   \
        parser_error_t err = FUNC_CALL; \
        if (err != parser_ok)           \
            return err;                 \
    }

typedef struct {
    uint8_t moduleIdx;
    uint8_t idx;
} pd_CallIndex_t;

typedef enum {
    eEraImmortal = 0,
    eEraMortal = 1
} pd_ExtrinsicEra_e;

// This type has a non-standard serialization
// core/sr-primitives/src/generic/era.rs
typedef struct {
    pd_ExtrinsicEra_e type;
    uint64_t period;
    uint64_t phase;
} pd_ExtrinsicEra_t;

typedef struct {
    const uint8_t* ptr;
    uint8_t len;
} compactInt_t;

typedef struct {
    uint32_t _lenBuffer;
    const uint8_t* _ptr; // Pointer to actual
    const uint8_t* _nextPtr; // Pointer to next Call
    uint8_t slotIdx; // Count of nested calls
    bool isTail;
} pd_NestCallIdx_t;

////////////////////////
// Common types
////////////////////////

typedef compactInt_t pd_Compactu32_t; // u32
typedef compactInt_t pd_Compactu64_t; // u64
typedef compactInt_t pd_CompactAssignments_t;
typedef compactInt_t pd_CompactBountyIndex_t;
typedef compactInt_t pd_CompactEraIndex_t;
typedef compactInt_t pd_CompactMemberCount_t;
typedef compactInt_t pd_CompactMoment_t;
typedef compactInt_t pd_CompactPropIndex_t;
typedef compactInt_t pd_CompactProposalIndex_t;
typedef compactInt_t pd_CompactReferendumIndex_t;
typedef compactInt_t pd_CompactRegistrarIndex_t;
typedef compactInt_t pd_CompactWeight_t;

typedef enum {
    eAddressIndex = 0,
    eAddressId = 1
} pd_Address_e;

typedef struct {
    pd_Address_e type;
    uint64_t idx;
    const uint8_t* idPtr;
} pd_Address_t;

typedef struct {
    compactInt_t index;
} pd_CompactIndex_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalance_t;

typedef struct {
    const uint8_t* _ptr;
} pd_IdentityId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Ticker_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_t identity;
        pd_Ticker_t ticker;
        uint64_t _len;
        const uint8_t* _ptr;
    };
} pd_Scope_t;

typedef struct {
    const uint8_t* _ptr;
} pd_CddId_t;

typedef struct {
    uint8_t value;
} pd_ClaimType_t;

typedef struct {
    uint8_t value;
} pd_CountryCode_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DispatchableName_t;

typedef struct {
    uint8_t some;
    pd_Scope_t contained;
} pd_OptionScope_t;

typedef struct {
    const uint8_t* _ptr;
} pd_ScopeId_t;

typedef struct {
    uint64_t value;
} pd_PortfolioNumber_t;

typedef struct {
    pd_CountryCode_t country_code;
    pd_Scope_t scope;
} pd_TupleCountryCodeScope_t;

typedef struct {
    pd_Scope_t scope;
    pd_ScopeId_t scopeId;
    pd_CddId_t cddId;
} pd_TupleScopeScopeIdCddId_t;

typedef struct {
    uint32_t u32;
    pd_OptionScope_t scope;
} pd_TupleU32Scope_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaimType_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDispatchableName_t;

typedef struct {
    uint8_t value;
    union {
        pd_Scope_t scope;
        pd_CddId_t cddId;
        pd_TupleCountryCodeScope_t jurisdiction;
        pd_TupleScopeScopeIdCddId_t investorUniqueness;
        pd_TupleU32Scope_t custom;
    };
} pd_Claim_t;

typedef struct {
    uint8_t value;
    pd_VecDispatchableName_t contained;
} pd_DispatchableNames_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PalletName_t;

typedef struct {
    uint8_t value;
    pd_PortfolioNumber_t number;
} pd_PortfolioKind_t;

typedef struct {
    uint8_t value;
    pd_VecClaimType_t claims;
} pd_TrustedFor_t;

typedef struct {
    pd_PalletName_t palletName;
    pd_DispatchableNames_t dispatchableNames;
} pd_PalletPermissions_t;

typedef struct {
    uint32_t value;
} pd_Permill_t;

typedef struct {
    pd_IdentityId_t did;
    pd_PortfolioKind_t kind;
} pd_PortfolioId_t;

typedef struct {
    uint8_t value;
    pd_IdentityId_t specific;
} pd_TargetIdentity_t;

typedef struct {
    pd_IdentityId_t issuer;
    pd_TrustedFor_t trustedFor;
} pd_TrustedIssuer_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecClaim_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_ChoiceTitle_t;

typedef struct {
    uint8_t value;
    union {
        pd_Claim_t claim;
        pd_VecClaim_t vecClaim;
        pd_TargetIdentity_t identity;
    };
} pd_ConditionType_t;

typedef struct {
    const uint8_t* _ptr;
} pd_EcdsaSignature_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Ed25519Signature_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Memo_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Sr25519Signature_t;

typedef struct {
    pd_Permill_t value;
} pd_Tax_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPalletPermissions_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPortfolioId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTicker_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTrustedIssuer_t;

typedef struct {
    uint8_t value;
    pd_VecTicker_t contained;
} pd_AssetPermissions_t;

typedef struct {
    const uint8_t* _ptr;
} pd_BalanceNoSymbol_t;

typedef struct {
    uint64_t value;
} pd_CheckpointId_t;

typedef struct {
    pd_ConditionType_t conditionType;
    pd_VecTrustedIssuer_t issuers;
} pd_Condition_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentType_t;

typedef struct {
    uint8_t value;
    pd_VecPalletPermissions_t contained;
} pd_ExtrinsicPermissions_t;

typedef struct {
    uint64_t value;
} pd_Moment_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionInfoLink_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_MotionTitle_t;

typedef struct {
    uint8_t value;
    union {
        pd_Ed25519Signature_t ed25519;
        pd_Sr25519Signature_t sr25519;
        pd_EcdsaSignature_t ecdsa;
    };
} pd_MultiSignature_t;

typedef struct {
    uint8_t some;
    pd_Memo_t contained;
} pd_OptionMemo_t;

typedef struct {
    uint8_t value;
    pd_VecPortfolioId_t contained;
} pd_PortfolioPermissions_t;

typedef struct {
    const uint8_t* _ptr;
} pd_ReceiptMetadata_t;

typedef struct {
    uint64_t value;
} pd_ScheduleId_t;

typedef struct {
    uint8_t value;
} pd_TargetTreatment_t;

typedef struct {
    pd_IdentityId_t id;
    pd_Tax_t tax;
} pd_TupleIdentityIdTax_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecChoiceTitle_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecIdentityId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu64_t;

typedef struct {
    const uint8_t* _ptr;
} pd_AccountId_t;

typedef struct {
    uint8_t value;
    uint32_t custom;
} pd_AgentGroup_t;

typedef struct {
    uint8_t value;
    uint64_t key;
} pd_AssetMetadataKey_t;

typedef struct {
    uint8_t value;
    pd_Moment_t moment;
} pd_AssetMetadataLockStatusMoment_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Balance_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Bytes_t;

typedef struct {
    compactInt_t value;
} pd_CompactAccountIndex_t;

typedef struct {
    uint8_t value;
    uint8_t _len;
    const uint8_t* _ptr;
} pd_DocumentHash_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentName_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_DocumentUri_t;

typedef struct {
    pd_Ticker_t ticker;
    pd_BalanceNoSymbol_t amount;
    pd_OptionMemo_t memo;
} pd_FundFungible_t;

typedef struct {
    pd_Ticker_t ticker;
    pd_Vecu64_t ids;
    pd_OptionMemo_t memo;
} pd_FundNonFungible_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Hash_t;

typedef struct {
    pd_PortfolioId_t sender;
    pd_PortfolioId_t receiver;
    pd_Ticker_t ticker;
    pd_BalanceNoSymbol_t amount;
} pd_LegFungible_t;

typedef struct {
    pd_PortfolioId_t sender;
    pd_PortfolioId_t receiver;
    pd_Ticker_t ticker;
    pd_Vecu64_t ids;
} pd_LegNonFungible_t;

typedef struct {
    pd_IdentityId_t sender;
    pd_IdentityId_t receiver;
    pd_Ticker_t ticker;
    pd_BalanceNoSymbol_t amount;
} pd_LegOffChain_t;

typedef struct {
    pd_MotionTitle_t title;
    pd_MotionInfoLink_t info_link;
    pd_VecChoiceTitle_t choices;
} pd_Motion_t;

typedef struct {
    pd_MultiSignature_t value;
} pd_OffChainSignature_t;

typedef struct {
    uint8_t some;
    pd_DocumentType_t contained;
} pd_OptionDocumentType_t;

typedef struct {
    uint8_t some;
    pd_Moment_t contained;
} pd_OptionMoment_t;

typedef struct {
    uint8_t some;
    pd_ReceiptMetadata_t contained;
} pd_OptionReceiptMetadata_t;

typedef struct {
    uint8_t some;
    pd_u16_t contained;
} pd_Optionu16_t;

typedef struct {
    pd_AssetPermissions_t asset;
    pd_ExtrinsicPermissions_t extrinsic;
    pd_PortfolioPermissions_t portfolio;
} pd_Permissions_t;

typedef struct {
    uint32_t value;
} pd_PipId_t;

typedef struct {
    uint8_t value;
    union {
        pd_Moment_t scheduled;
        pd_ScheduleId_t existingSchedule;
        pd_CheckpointId_t existing;
    };
} pd_RecordDateSpec_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Signature_t;

typedef struct {
    uint8_t value;
} pd_SnapshotResult_t;

typedef struct {
    pd_VecIdentityId_t identities;
    pd_TargetTreatment_t treatment;
} pd_TargetIdentities_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCondition_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdTax_t;

typedef struct {
    pd_AccountId_t accountId_1;
    pd_AccountId_t accountId_2;
    pd_Balance_t balance;
} pd_AddRelayerPayingKey_t;

typedef struct {
    uint8_t value;
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetIdentifier_t;

typedef struct {
    pd_OptionMoment_t expire;
    pd_AssetMetadataLockStatusMoment_t lockStatus;
} pd_AssetMetadataValueDetailMoment_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_BallotTitle_t;

typedef struct {
    pd_Balance_t power;
    pd_Optionu16_t fallback;
} pd_BallotVote_t;

typedef struct {
    pd_Ticker_t ticker;
    pd_AgentGroup_t agentGroup;
} pd_BecomeAgent_t;

typedef struct {
    pd_IdentityId_t identity;
    pd_Balance_t balance;
} pd_Beneficiary_t;

typedef struct {
    uint32_t nonce;
    pd_AccountId_t recipient;
    pd_Balance_t value;
    pd_Hash_t txHash;
} pd_BridgeTxAccountId_t;

typedef struct {
    uint8_t value;
} pd_CAKind_t;

typedef struct {
    pd_CallIndex_t callIndex;
    const uint32_t* _txVerPtr;
    pd_NestCallIdx_t nestCallIdx;
} pd_Call_t;

typedef struct {
    compactInt_t value;
} pd_CompactBalanceOf_t;

typedef struct {
    compactInt_t value;
} pd_CompactPerBill_t;

typedef struct {
    pd_VecCondition_t senderConditions;
    pd_VecCondition_t receiverConditions;
    uint32_t id;
} pd_ComplianceRequirement_t;

typedef struct {
    pd_AccountId_t key;
    pd_Signature_t authSignature;
} pd_CreateChildIdentityWithAuthAccountId_t;

typedef struct {
    uint32_t value;
} pd_CustomAssetTypeId_t;

typedef struct {
    uint32_t value;
} pd_DocumentId_t;

typedef struct {
    pd_DocumentUri_t uri;
    pd_DocumentHash_t content_hash;
    pd_DocumentName_t name;
    pd_OptionDocumentType_t doc_type;
    pd_OptionMoment_t filing_date;
} pd_Document_t;

typedef struct {
    uint8_t value;
    union {
        pd_FundFungible_t fungible;
        pd_FundNonFungible_t nonFungible;
    };
} pd_Fund_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundingRoundName_t;

typedef struct {
    uint8_t value;
    union {
        pd_LegFungible_t fungible;
        pd_LegNonFungible_t nonFungible;
        pd_LegOffChain_t offChain;
    };
} pd_Leg_t;

typedef struct {
    uint32_t value;
} pd_LocalCAId_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_t id;
        pd_CompactAccountIndex_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_LookupasStaticLookupSource_t;

typedef struct {
    pd_AssetMetadataKey_t key;
    pd_Bytes_t value;
} pd_NFTMetadataAttribute_t;

typedef struct {
    uint8_t value;
    uint32_t custom;
} pd_NonFungibleType_t;

typedef struct {
    uint8_t some;
    pd_Bytes_t contained;
} pd_OptionBytes_t;

typedef struct {
    uint8_t some;
    pd_Permill_t contained;
} pd_OptionPermill_t;

typedef struct {
    uint8_t some;
    pd_RecordDateSpec_t contained;
} pd_OptionRecordDateSpec_t;

typedef struct {
    uint8_t some;
    pd_TargetIdentities_t contained;
} pd_OptionTargetIdentities_t;

typedef struct {
    uint8_t some;
    pd_VecTupleIdentityIdTax_t contained;
} pd_OptionVecTupleIdentityIdTax_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PipDescription_t;

typedef struct {
    pd_Balance_t total;
    pd_Balance_t price;
} pd_PriceTier_t;

typedef struct {
    uint64_t uid;
    uint64_t instructionId;
    uint64_t legId;
    pd_AccountId_t signer;
    pd_OffChainSignature_t signature;
    pd_OptionReceiptMetadata_t metadata;
} pd_ReceiptDetails_t;

typedef struct {
    pd_AccountId_t key;
    pd_Permissions_t permissions;
} pd_SecondaryKeyAccountId_t;

typedef struct {
    pd_AccountId_t key;
    pd_Permissions_t permissions;
    pd_Signature_t auth_signature;
} pd_SecondaryKeyWithAuthAccountId_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_t identity;
        pd_AccountId_t account;
    };
} pd_SignatoryAccountId_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t _signed;
} pd_SystemOrigin_t;

typedef struct {
    uint8_t extrinsicId1;
    uint8_t extrinsicId2;
    pd_bool_t _bool;
} pd_TupleExtrinsicIdbool_t;

typedef struct {
    pd_IdentityId_t identity;
    pd_bool_t val;
} pd_TupleIdentityIdbool_t;

typedef struct {
    pd_PipId_t pip_id;
    pd_SnapshotResult_t snapshot_result;
} pd_TuplePipIdSnapshotResult_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_Url_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecMotion_t;

typedef struct {
    uint64_t value;
} pd_VenueId_t;

typedef struct {
    pd_Compactu64_t refTime;
    pd_Compactu64_t proofSize;
} pd_Weight_t;

typedef struct {
    uint8_t value;
    union {
        pd_AccountId_t id;
        pd_CompactAccountIndex_t index;
        pd_Bytes_t raw;
        const uint8_t* _ptr;
    };
} pd_AccountIdLookupOfT_t;

typedef struct {
    pd_Bytes_t value;
} pd_AssetMetadataName_t;

typedef struct {
    pd_OptionBytes_t url;
    pd_OptionBytes_t description;
    pd_OptionBytes_t typeDef;
} pd_AssetMetadataSpec_t;

typedef struct {
    pd_Bytes_t value;
} pd_AssetMetadataValue_t;

typedef struct {
    uint8_t value;
    pd_CustomAssetTypeId_t custom;
} pd_AssetType_t;

typedef struct {
    uint8_t value;
    union {
        pd_IdentityId_t identityId;
        pd_AccountId_t accountId;
        pd_Ticker_t ticker;
        pd_Permissions_t permissions;
        pd_PortfolioId_t portfolioId;
        pd_BecomeAgent_t becomeAgent;
        pd_AddRelayerPayingKey_t addRelayerPayingKey;
    };
} pd_AuthorizationDataAccountId_t;

typedef struct {
    pd_Balance_t value;
} pd_BalanceOf_t;

typedef struct {
    pd_BallotTitle_t title;
    pd_VecMotion_t motions;
} pd_BallotMeta_t;

typedef struct {
    pd_Moment_t start;
    pd_Moment_t end;
} pd_BallotTimeRange_t;

typedef struct {
    uint8_t value;
    union {
        pd_SystemOrigin_t system;
        uint8_t committee;
    };
} pd_BoxPalletsOrigin_t;

typedef struct {
    pd_Ticker_t ticker;
    pd_LocalCAId_t local_id;
} pd_CAId_t;

typedef struct {
    pd_Hash_t hash;
} pd_CodeHash_t;

typedef struct {
    pd_Ticker_t ticker;
    pd_CAKind_t kind;
    uint64_t declDate;
    pd_OptionRecordDateSpec_t recordDate;
    pd_Bytes_t details;
    pd_OptionTargetIdentities_t targets;
    pd_OptionPermill_t defaultWithholdingTax;
    pd_OptionVecTupleIdentityIdTax_t withholdingTax;
} pd_InitiateCorporateActionArgs_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_MaybeBlockBlockNumber_t;

typedef struct {
    uint8_t some;
    pd_AssetMetadataValueDetailMoment_t contained;
} pd_OptionAssetMetadataValueDetailMoment_t;

typedef struct {
    uint8_t some;
    pd_PortfolioId_t contained;
} pd_OptionPortfolioId_t;

typedef struct {
    uint8_t some;
    pd_ReceiptDetails_t contained;
} pd_OptionReceiptDetails_t;

typedef struct {
    uint8_t some;
    pd_Tax_t contained;
} pd_OptionTax_t;

typedef struct {
    uint8_t some;
    pd_Weight_t contained;
} pd_OptionWeight_t;

typedef struct {
    pd_Call_t call;
} pd_Proposal_t;

typedef struct {
    uint8_t value;
    pd_AccountId_t accountId;
} pd_RewardDestination_t;

typedef struct {
    pd_Vecu64_t pending;
} pd_ScheduleCheckpoints_t;

typedef struct {
    uint8_t value;
    pd_BlockNumber_t blockNumber;
} pd_SettlementTypeBlockNumber_t;

typedef struct {
    uint64_t nonce;
    pd_Call_t call;
} pd_UniqueCall_t;

typedef struct {
    pd_CompactPerBill_t commission;
    pd_bool_t blocked;
} pd_ValidatorPrefs_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBallotVote_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBeneficiary_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecBridgeTxAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
    uint32_t callTxVersion;
} pd_VecCall_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecComplianceRequirement_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecCreateChildIdentityWithAuthAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocument_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecFund_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLeg_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecLookupasStaticLookupSource_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecNFTMetadataAttribute_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecPriceTier_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecReceiptDetails_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKeyAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSecondaryKeyWithAuthAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecSignatoryAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleExtrinsicIdbool_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTupleIdentityIdbool_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecTuplePipIdSnapshotResult_t;

typedef struct {
    uint32_t value;
} pd_AGId_t;

typedef struct {
    uint32_t value;
} pd_AccountIndex_t;

typedef struct {
    uint64_t value;
} pd_AssetMetadataLocalKey_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_AssetName_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_CADetails_t;

typedef struct {
    uint8_t value;
} pd_Determinism_t;

typedef struct {
    uint32_t value;
} pd_EraIndex_t;

typedef struct {
    uint64_t value;
} pd_FundraiserId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_FundraiserName_t;

typedef struct {
    uint64_t value;
} pd_InstructionId_t;

typedef struct {
    const uint8_t* _ptr;
} pd_Keys_t;

typedef struct {
    uint32_t value;
} pd_MemberCount_t;

typedef struct {
    uint64_t value;
} pd_NFTId_t;

typedef struct {
    uint8_t some;
    pd_Balance_t contained;
} pd_OptionBalance_t;

typedef struct {
    uint8_t some;
    pd_BlockNumber_t contained;
} pd_OptionBlockNumber_t;

typedef struct {
    uint8_t some;
    pd_CompactBalanceOf_t contained;
} pd_OptionCompactBalanceOf_t;

typedef struct {
    uint8_t some;
    pd_FundingRoundName_t contained;
} pd_OptionFundingRoundName_t;

typedef struct {
    uint8_t some;
    pd_NonFungibleType_t contained;
} pd_OptionNonFungibleType_t;

typedef struct {
    uint8_t some;
    pd_PipDescription_t contained;
} pd_OptionPipDescription_t;

typedef struct {
    uint8_t some;
    pd_PortfolioNumber_t contained;
} pd_OptionPortfolioNumber_t;

typedef struct {
    uint8_t some;
    pd_Url_t contained;
} pd_OptionUrl_t;

typedef struct {
    uint8_t some;
    pd_u32_t contained;
} pd_Optionu32_t;

typedef struct {
    uint8_t some;
    pd_u64_t contained;
} pd_Optionu64_t;

typedef struct {
    uint32_t value;
} pd_Perbill_t;

typedef struct {
    uint8_t value;
} pd_Percent_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_PortfolioName_t;

typedef struct {
    uint32_t numerator;
    uint32_t denominator;
} pd_PosRatio_t;

typedef struct {
    uint32_t value;
} pd_ProposalIndex_t;

typedef struct {
    uint8_t value;
} pd_SkippedCount_t;

typedef struct {
    uint8_t value;
} pd_SlashingSwitch_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetIdentifier_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecAssetMetadataKey_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecDocumentId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_VecVenueId_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu32_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
    uint64_t _lenBuffer;
} pd_Vecu8_t;

typedef struct {
    uint64_t _len;
    const uint8_t* _ptr;
} pd_VenueDetails_t;

typedef struct {
    uint8_t value;
} pd_VenueType_t;

#ifdef __cplusplus
}
#endif
