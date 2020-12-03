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

#include <stddef.h>
#include <stdint.h>

// https://github.com/paritytech/substrate/blob/effe489951d1edab9d34846b1eefdfaf9511dab9/frame/identity/src/lib.rs
#define Data_e_NONE 0
#define Data_e_RAW_VECU8 33
#define Data_e_BLAKETWO256U8_32 34
#define Data_e_SHA256_U8_32 35
#define Data_e_KECCAK256_U8_32 36
#define Data_e_SHATHREE256_U8_32 37

typedef uint8_t pd_bool_t;
typedef uint16_t pd_u16_t;
typedef uint32_t pd_u32_t;
typedef uint64_t pd_u64_t;

typedef struct {
  uint8_t moduleIdx;
  uint8_t idx;
} pd_CallIndex_t;

typedef enum { eEraImmortal = 0, eEraMortal = 1 } pd_ExtrinsicEra_e;

// This type has a non-standard serialization
// core/sr-primitives/src/generic/era.rs
typedef struct {
  pd_ExtrinsicEra_e type;
  uint64_t period;
  uint64_t phase;
} pd_ExtrinsicEra_t;

typedef struct {
  const uint8_t *ptr;
  uint8_t len;
} compactInt_t;

////////////////////////
// Not supported types
////////////////////////

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wextern-c-compat"
// NOTE: These are large types that cannot be reviewed in the device.
// They will be marked as not supported
typedef struct {
} pd_AttestedCandidate_t;
typedef struct {
} pd_Header_t;
typedef struct {
} pd_Heartbeat_t;
#pragma clang diagnostic pop

////////////////////////
// Types that require out of order declaration
////////////////////////

typedef enum { eAddressIndex = 0, eAddressId = 1 } pd_Address_e;

typedef struct {
  pd_Address_e type;
  uint64_t idx;
  const uint8_t *idPtr;
} pd_Address_t;

typedef struct {
  compactInt_t index;
} pd_CompactIndex_t;

typedef struct {
  compactInt_t value;
} pd_CompactBalance_t;

typedef struct {
  const uint8_t *_ptr;
} pd_Hash_t;

typedef struct {
  const uint8_t *_ptr;
} pd_BalanceOf_t;

typedef struct {
  uint8_t value;
} pd_Conviction_t;

typedef struct {
  const uint8_t *_ptr;
} pd_u8_array_20_t;

typedef struct {
  uint8_t some;
  pd_u8_array_20_t contained;
} pd_Optionu8_array_20_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecTupleDataData_t;

////////////////////////
////////////////////////
////////////////////////
////////////////////////

typedef compactInt_t pd_Compactu32_t; // u32
typedef compactInt_t pd_Compactu64_t; // u64
typedef pd_CompactBalance_t pd_CompactBalanceOf_t;
typedef uint32_t pd_BlockNumber_t; // u32

// Based
// https://github.com/paritytech/substrate/blob/master/node/primitives/src/lib.rs

typedef struct {
  const uint8_t *_ptr;
} pd_IdentityId_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_Ticker_t;

typedef struct {
  uint8_t value;
} pd_CountryCode_t;

typedef struct {
  uint8_t value;
  union {
    pd_IdentityId_t identity;
    pd_Ticker_t ticker;
    uint64_t _len;
    const uint8_t *_ptr;
  };
} pd_Scope_t;

typedef struct {
  const uint8_t *_ptr;
} pd_ScopeId_t;

typedef struct {
  const uint8_t *_ptr;
} pd_CddId_t;

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
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ClaimType_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecClaimType_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_PalletName_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_DispatchableName_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecDispatchableName_t;

typedef struct {
  uint64_t value;
} pd_PortfolioNumber_t;

typedef struct {
  uint8_t value;
  union {
    pd_Scope_t scope;
    pd_CddId_t cddId;
    pd_TupleCountryCodeScope_t jurisdiction;
    pd_TupleScopeScopeIdCddId_t investorUniqueness;
  };
} pd_Claim_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecClaim_t;

typedef struct {
  uint8_t value;
  pd_IdentityId_t specific;
} pd_TargetIdentity_t;

typedef struct {
  uint8_t value;
  pd_VecClaimType_t claims;
} pd_TrustedFor_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecTicker_t;

typedef struct {
  uint8_t some;
  pd_VecTicker_t contained;
} pd_OptionVecTicker_t;

typedef struct {
  pd_PalletName_t palletName;
  pd_bool_t total;
  pd_VecDispatchableName_t dispatchableNames;
} pd_PalletPermissions_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecPalletPermissions_t;

typedef struct {
  uint8_t some;
  pd_VecPalletPermissions_t contained;
} pd_OptionVecPalletPermissions_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecPortfolioNumber_t;

typedef struct {
  uint8_t some;
  pd_VecPortfolioNumber_t contained;
} pd_OptionVecPortfolioNumber_t;

typedef struct {
  uint8_t value;
  pd_PortfolioNumber_t number;

} pd_PortfolioKind_t;

typedef struct {
  uint8_t value;
  union {
    pd_Claim_t claim;
    pd_VecClaim_t vecClaim;
    pd_TargetIdentity_t identity;
  };
} pd_ConditionType_t;

typedef struct {
  pd_IdentityId_t issuer;
  pd_TrustedFor_t trustedFor;
} pd_TrustedIssuer_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecTrustedIssuer_t;

typedef struct {
  compactInt_t value;
} pd_CompactPerBill_t;

typedef struct {
  const uint8_t *_ptr;
} pd_AccountId_t;

typedef struct {
  const uint8_t *_ptr;
} pd_Balance_t;

typedef struct {
  pd_OptionVecTicker_t asset;
  pd_OptionVecPalletPermissions_t extrinsic;
  pd_OptionVecPortfolioNumber_t portfolio;
} pd_Permissions_t;

typedef struct {
  pd_IdentityId_t did;
  pd_PortfolioKind_t kind;
} pd_PortfolioId_t;

typedef struct {
  uint64_t value;
} pd_Moment_t;

typedef struct {
  pd_ConditionType_t conditionType;
  pd_VecTrustedIssuer_t issuers;
} pd_Condition_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecCondition_t;

typedef struct {
  uint64_t value;
} pd_Motion_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecMotion_t;

typedef struct {
  pd_CompactPerBill_t commission;
} pd_ValidatorPrefs_t;

typedef struct {
  uint8_t value;
  union {
    pd_IdentityId_t identity;
    pd_AccountId_t account;
  };
} pd_Signatory_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecSignatory_t;

typedef struct {
  pd_Hash_t hash;
} pd_CodeHash_t;

typedef struct {
  pd_IdentityId_t identity;
  pd_Balance_t balance;
} pd_Beneficiary_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecBeneficiary_t;

typedef struct {
  uint8_t value;
  pd_BlockNumber_t blockNumber;
} pd_MaybeBlock_t;

typedef struct {
  uint8_t value;
  union {
    pd_IdentityId_t identityId;
    pd_AccountId_t accountId;
    pd_Ticker_t ticker;
    pd_Permissions_t permissions;
    pd_PortfolioId_t portfolioId;
  };
} pd_AuthorizationData_t;

typedef struct {
  pd_IdentityId_t targetId;
  uint64_t nonce;
  pd_Moment_t expiresAt;
} pd_TargetIdAuthorization_t;

typedef struct {
  uint32_t nonce;
  pd_AccountId_t recipient;
  pd_Balance_t value;
  pd_Hash_t txHash;
} pd_BridgeTx_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecBridgeTx_t;

typedef struct {
  pd_VecCondition_t senderConditions;
  pd_VecCondition_t receiverConditions;
  uint32_t id;
} pd_ComplianceRequirement_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecComplianceRequirement_t;

typedef struct {
  uint64_t checkpointId;
  pd_Moment_t votingStart;
  pd_Moment_t votingEnd;
  pd_VecMotion_t motions;
} pd_Ballot_t;

typedef struct {
  uint8_t value;
  pd_BlockNumber_t blockNumber;
} pd_SettlementType_t;

typedef struct {
  pd_PortfolioId_t from;
  pd_PortfolioId_t to;
  pd_Ticker_t asset;
  pd_Balance_t amount;
} pd_Leg_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecLeg_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecPortfolioId_t;

typedef struct {
  pd_Ticker_t ticker;
  pd_Balance_t balance;
} pd_MovePortfolioItem_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecMovePortfolioItem_t;

typedef struct {
  uint32_t value;
} pd_Perbill_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_Bytes_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ChangesTrieConfiguration_t;

typedef struct {
  uint8_t some;
  pd_ChangesTrieConfiguration_t contained;
} pd_OptionChangesTrieConfiguration_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecKeyValue_t;

typedef struct {
  const uint8_t *_ptr;
} pd_Key_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecKey_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_EquivocationProof_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_KeyOwnerProof_t;

typedef compactInt_t pd_CompactMoment_t;

typedef struct {
  uint32_t value;
} pd_AccountIndex_t;

typedef struct {
  const uint8_t *_ptr;
} pd_LookupSource_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_Memo_t;

typedef struct {
  uint8_t some;
  pd_Memo_t contained;
} pd_OptionMemo_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecHeader_t;

typedef struct {
  uint8_t value;
} pd_RewardDestination_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecLookupSource_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Percent_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecAccountId_t;

typedef struct {
  uint32_t value;
} pd_EraIndex_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_Vecu32_t;

typedef compactInt_t pd_CompactEraIndex_t;

typedef struct {
  uint16_t value;
} pd_ValidatorIndex_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecValidatorIndex_t;

typedef compactInt_t pd_CompactAssignments_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ElectionScore_t;

typedef struct {
  compactInt_t validators;
  compactInt_t nominators;
} pd_ElectionSize_t;

typedef struct {
  uint8_t value;
} pd_SlashingSwitch_t;

typedef compactInt_t pd_CompactBlockNumber_t;

typedef struct {
  const uint8_t *_ptr;
} pd_Signature_t;

typedef struct {
  uint32_t max_offline_percent;
  uint32_t constant;
  uint32_t max_slash_percent;
} pd_OfflineSlashingParams_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Call_t;

typedef struct {
  uint64_t value;
} pd_Weight_t;

typedef struct {
  uint8_t some;
  pd_Moment_t contained;
} pd_OptionMoment_t;

typedef struct {
  uint8_t some;
  pd_u64_t contained;
} pd_Optionu64_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Schedule_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TemplateMetadata_t;

typedef compactInt_t pd_CompactGas_t;

typedef struct {
  uint8_t some;
  pd_BalanceOf_t contained;
} pd_OptionBalanceOf_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_MetaUrl_t;

typedef struct {
  uint8_t some;
  pd_MetaUrl_t contained;
} pd_OptionMetaUrl_t;

typedef compactInt_t pd_CompactProposalIndex_t;

typedef struct {
  uint32_t value;
} pd_ProposalIndex_t;

typedef struct {
  uint32_t value;
} pd_MemberCount_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecIdentityId_t;

typedef struct {
  uint8_t value;
} pd_SkippedCount_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_Url_t;

typedef struct {
  uint8_t some;
  pd_Url_t contained;
} pd_OptionUrl_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_PipDescription_t;

typedef struct {
  uint8_t some;
  pd_PipDescription_t contained;
} pd_OptionPipDescription_t;

typedef struct {
  uint32_t value;
} pd_PipId_t;

typedef struct {
  uint8_t some;
  pd_BlockNumber_t contained;
} pd_OptionBlockNumber_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TuplePipIdSnapshotResult_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecTuplePipIdSnapshotResult_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_AssetName_t;

typedef struct {
  uint8_t value;
  uint64_t _len;
  const uint8_t *_ptr;
} pd_AssetType_t;

typedef struct {
  uint8_t value;
  uint64_t _len;
  const uint8_t *_ptr;
} pd_AssetIdentifier_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecAssetIdentifier_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_FundingRoundName_t;

typedef struct {
  uint8_t some;
  pd_FundingRoundName_t contained;
} pd_OptionFundingRoundName_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Document_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecDocument_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_DocumentId_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecDocumentId_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SmartExtension_t;

typedef struct {
  const uint8_t *_ptr;
} pd_EcdsaSignature_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ClassicTickerImport_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TickerRegistrationConfig_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CheckpointId_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_InvestorUid_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SecondaryKey_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecSecondaryKey_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_LegacyPermissions_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_SecondaryKeyWithAuth_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecSecondaryKeyWithAuth_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_InvestorZKProofData_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleIdentityIdbool_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecTupleIdentityIdbool_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecBalance_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_u128_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_VenueDetails_t;

typedef struct {
  uint8_t value;
} pd_VenueType_t;

typedef struct {
  uint8_t some;
  pd_VenueDetails_t contained;
} pd_OptionVenueDetails_t;

typedef struct {
  uint8_t some;
  pd_VenueType_t contained;
} pd_OptionVenueType_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ReceiptDetails_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecReceiptDetails_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_Vecu64_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_PriceTier_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecPriceTier_t;

typedef struct {
  uint8_t some;
  pd_Balance_t contained;
} pd_OptionBalance_t;

typedef struct {
  uint8_t some;
  pd_ReceiptDetails_t contained;
} pd_OptionReceiptDetails_t;

typedef struct {
  uint32_t numerator;
  uint32_t denominator;
} pd_PosRatio_t;

typedef struct {
  uint8_t value;
} pd_ProtocolOp_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecCall_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_OffChainSignature_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_UniqueCall_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
} pd_PortfolioName_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Period_t;

typedef struct {
  uint8_t some;
  pd_Period_t contained;
} pd_OptionPeriod_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Priority_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TargetIdentities_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_Tax_t;

typedef struct {
  uint8_t some;
  pd_Tax_t contained;
} pd_OptionTax_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CAKind_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_RecordDateSpec_t;

typedef struct {
  uint8_t some;
  pd_RecordDateSpec_t contained;
} pd_OptionRecordDateSpec_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CADetails_t;

typedef struct {
  uint8_t some;
  pd_TargetIdentities_t contained;
} pd_OptionTargetIdentities_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_TupleIdentityIdTax_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecTupleIdentityIdTax_t;

typedef struct {
  uint8_t some;
  pd_VecTupleIdentityIdTax_t contained;
} pd_OptionVecTupleIdentityIdTax_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_CAId_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BallotTimeRange_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BallotMeta_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_BallotVote_t;

typedef struct {
  uint64_t _len;
  const uint8_t *_ptr;
  uint64_t _lenBuffer;
} pd_VecBallotVote_t;

typedef struct {
  uint8_t some;
  pd_PortfolioNumber_t contained;
} pd_OptionPortfolioNumber_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ScheduleSpec_t;

typedef struct {
  // TODO: Not implemented
  uint8_t _NOT_IMPLEMENTED__DO_NOT_USE;
} pd_ScheduleId_t;

// Types with dependencies

typedef pd_VecKey_t pd_Keys_t;
typedef pd_Key_t pd_KeyValue_t;

#include "substrate_methods.h"

#ifdef __cplusplus
}
#endif
