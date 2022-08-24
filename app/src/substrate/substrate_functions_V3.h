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
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "parser_common.h"
#include "substrate_methods_V3.h"
#include "substrate_types_V3.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAGId_V3(parser_context_t* c, pd_AGId_V3_t* v);
parser_error_t _readAccountId_V3(parser_context_t* c, pd_AccountId_V3_t* v);
parser_error_t _readAccountIndex_V3(parser_context_t* c, pd_AccountIndex_V3_t* v);
parser_error_t _readAddRelayerPayingKey_V3(parser_context_t* c, pd_AddRelayerPayingKey_V3_t* v);
parser_error_t _readAgentGroup_V3(parser_context_t* c, pd_AgentGroup_V3_t* v);
parser_error_t _readAssetIdentifier_V3(parser_context_t* c, pd_AssetIdentifier_V3_t* v);
parser_error_t _readAssetMetadataKey_V3(parser_context_t* c, pd_AssetMetadataKey_V3_t* v);
parser_error_t _readAssetMetadataLockStatusMoment_V3(parser_context_t* c, pd_AssetMetadataLockStatusMoment_V3_t* v);
parser_error_t _readAssetMetadataName_V3(parser_context_t* c, pd_AssetMetadataName_V3_t* v);
parser_error_t _readAssetMetadataSpec_V3(parser_context_t* c, pd_AssetMetadataSpec_V3_t* v);
parser_error_t _readAssetMetadataValueDetailMoment_V3(parser_context_t* c, pd_AssetMetadataValueDetailMoment_V3_t* v);
parser_error_t _readAssetMetadataValue_V3(parser_context_t* c, pd_AssetMetadataValue_V3_t* v);
parser_error_t _readAssetName_V3(parser_context_t* c, pd_AssetName_V3_t* v);
parser_error_t _readAssetPermissions_V3(parser_context_t* c, pd_AssetPermissions_V3_t* v);
parser_error_t _readAssetType_V3(parser_context_t* c, pd_AssetType_V3_t* v);
parser_error_t _readAuthorizationDataAccountId_V3(parser_context_t* c, pd_AuthorizationDataAccountId_V3_t* v);
parser_error_t _readBallotMeta_V3(parser_context_t* c, pd_BallotMeta_V3_t* v);
parser_error_t _readBallotTimeRange_V3(parser_context_t* c, pd_BallotTimeRange_V3_t* v);
parser_error_t _readBallotTitle_V3(parser_context_t* c, pd_BallotTitle_V3_t* v);
parser_error_t _readBallotVote_V3(parser_context_t* c, pd_BallotVote_V3_t* v);
parser_error_t _readBecomeAgent_V3(parser_context_t* c, pd_BecomeAgent_V3_t* v);
parser_error_t _readBeneficiary_V3(parser_context_t* c, pd_Beneficiary_V3_t* v);
parser_error_t _readBridgeTxAccountId_V3(parser_context_t* c, pd_BridgeTxAccountId_V3_t* v);
parser_error_t _readCADetails_V3(parser_context_t* c, pd_CADetails_V3_t* v);
parser_error_t _readCAId_V3(parser_context_t* c, pd_CAId_V3_t* v);
parser_error_t _readCAKind_V3(parser_context_t* c, pd_CAKind_V3_t* v);
parser_error_t _readCalendarPeriod_V3(parser_context_t* c, pd_CalendarPeriod_V3_t* v);
parser_error_t _readCalendarUnit_V3(parser_context_t* c, pd_CalendarUnit_V3_t* v);
parser_error_t _readCddId_V3(parser_context_t* c, pd_CddId_V3_t* v);
parser_error_t _readCheckpointId_V3(parser_context_t* c, pd_CheckpointId_V3_t* v);
parser_error_t _readChoiceTitle_V3(parser_context_t* c, pd_ChoiceTitle_V3_t* v);
parser_error_t _readClaimType_V3(parser_context_t* c, pd_ClaimType_V3_t* v);
parser_error_t _readClaim_V3(parser_context_t* c, pd_Claim_V3_t* v);
parser_error_t _readClassicTickerImport_V3(parser_context_t* c, pd_ClassicTickerImport_V3_t* v);
parser_error_t _readCodeHash_V3(parser_context_t* c, pd_CodeHash_V3_t* v);
parser_error_t _readCompactAccountIndex_V3(parser_context_t* c, pd_CompactAccountIndex_V3_t* v);
parser_error_t _readCompactPerBill_V3(parser_context_t* c, pd_CompactPerBill_V3_t* v);
parser_error_t _readConditionType_V3(parser_context_t* c, pd_ConditionType_V3_t* v);
parser_error_t _readCondition_V3(parser_context_t* c, pd_Condition_V3_t* v);
parser_error_t _readCountryCode_V3(parser_context_t* c, pd_CountryCode_V3_t* v);
parser_error_t _readCustomAssetTypeId_V3(parser_context_t* c, pd_CustomAssetTypeId_V3_t* v);
parser_error_t _readDispatchableName_V3(parser_context_t* c, pd_DispatchableName_V3_t* v);
parser_error_t _readDispatchableNames_V3(parser_context_t* c, pd_DispatchableNames_V3_t* v);
parser_error_t _readDocumentHash_V3(parser_context_t* c, pd_DocumentHash_V3_t* v);
parser_error_t _readDocumentId_V3(parser_context_t* c, pd_DocumentId_V3_t* v);
parser_error_t _readDocumentName_V3(parser_context_t* c, pd_DocumentName_V3_t* v);
parser_error_t _readDocumentType_V3(parser_context_t* c, pd_DocumentType_V3_t* v);
parser_error_t _readDocumentUri_V3(parser_context_t* c, pd_DocumentUri_V3_t* v);
parser_error_t _readDocument_V3(parser_context_t* c, pd_Document_V3_t* v);
parser_error_t _readEcdsaSignature_V3(parser_context_t* c, pd_EcdsaSignature_V3_t* v);
parser_error_t _readEd25519Signature_V3(parser_context_t* c, pd_Ed25519Signature_V3_t* v);
parser_error_t _readEraIndex_V3(parser_context_t* c, pd_EraIndex_V3_t* v);
parser_error_t _readEthereumAddress_V3(parser_context_t* c, pd_EthereumAddress_V3_t* v);
parser_error_t _readExtrinsicPermissions_V3(parser_context_t* c, pd_ExtrinsicPermissions_V3_t* v);
parser_error_t _readFundingRoundName_V3(parser_context_t* c, pd_FundingRoundName_V3_t* v);
parser_error_t _readFundraiserId_V3(parser_context_t* c, pd_FundraiserId_V3_t* v);
parser_error_t _readFundraiserName_V3(parser_context_t* c, pd_FundraiserName_V3_t* v);
parser_error_t _readIdentityId_V3(parser_context_t* c, pd_IdentityId_V3_t* v);
parser_error_t _readInstructionId_V3(parser_context_t* c, pd_InstructionId_V3_t* v);
parser_error_t _readInvestorZKProofData_V3(parser_context_t* c, pd_InvestorZKProofData_V3_t* v);
parser_error_t _readKeys_V3(parser_context_t* c, pd_Keys_V3_t* v);
parser_error_t _readLegId_V3(parser_context_t* c, pd_LegId_V3_t* v);
parser_error_t _readLeg_V3(parser_context_t* c, pd_Leg_V3_t* v);
parser_error_t _readLocalCAId_V3(parser_context_t* c, pd_LocalCAId_V3_t* v);
parser_error_t _readLookupasStaticLookupSource_V3(parser_context_t* c, pd_LookupasStaticLookupSource_V3_t* v);
parser_error_t _readMaybeBlockBlockNumber_V3(parser_context_t* c, pd_MaybeBlockBlockNumber_V3_t* v);
parser_error_t _readMemberCount_V3(parser_context_t* c, pd_MemberCount_V3_t* v);
parser_error_t _readMemo_V3(parser_context_t* c, pd_Memo_V3_t* v);
parser_error_t _readMoment_V3(parser_context_t* c, pd_Moment_V3_t* v);
parser_error_t _readMotionInfoLink_V3(parser_context_t* c, pd_MotionInfoLink_V3_t* v);
parser_error_t _readMotionTitle_V3(parser_context_t* c, pd_MotionTitle_V3_t* v);
parser_error_t _readMotion_V3(parser_context_t* c, pd_Motion_V3_t* v);
parser_error_t _readMovePortfolioItem_V3(parser_context_t* c, pd_MovePortfolioItem_V3_t* v);
parser_error_t _readMultiSignature_V3(parser_context_t* c, pd_MultiSignature_V3_t* v);
parser_error_t _readOffChainSignature_V3(parser_context_t* c, pd_OffChainSignature_V3_t* v);
parser_error_t _readOptionAssetMetadataValueDetailMoment_V3(parser_context_t* c, pd_OptionAssetMetadataValueDetailMoment_V3_t* v);
parser_error_t _readOptionDocumentType_V3(parser_context_t* c, pd_OptionDocumentType_V3_t* v);
parser_error_t _readOptionFundingRoundName_V3(parser_context_t* c, pd_OptionFundingRoundName_V3_t* v);
parser_error_t _readOptionMemo_V3(parser_context_t* c, pd_OptionMemo_V3_t* v);
parser_error_t _readOptionMoment_V3(parser_context_t* c, pd_OptionMoment_V3_t* v);
parser_error_t _readOptionPipDescription_V3(parser_context_t* c, pd_OptionPipDescription_V3_t* v);
parser_error_t _readOptionPortfolioNumber_V3(parser_context_t* c, pd_OptionPortfolioNumber_V3_t* v);
parser_error_t _readOptionReceiptDetails_V3(parser_context_t* c, pd_OptionReceiptDetails_V3_t* v);
parser_error_t _readOptionRecordDateSpec_V3(parser_context_t* c, pd_OptionRecordDateSpec_V3_t* v);
parser_error_t _readOptionScope_V3(parser_context_t* c, pd_OptionScope_V3_t* v);
parser_error_t _readOptionTargetIdentities_V3(parser_context_t* c, pd_OptionTargetIdentities_V3_t* v);
parser_error_t _readOptionTax_V3(parser_context_t* c, pd_OptionTax_V3_t* v);
parser_error_t _readOptionUrl_V3(parser_context_t* c, pd_OptionUrl_V3_t* v);
parser_error_t _readOptionVecTupleIdentityIdTax_V3(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V3_t* v);
parser_error_t _readPalletName_V3(parser_context_t* c, pd_PalletName_V3_t* v);
parser_error_t _readPalletPermissions_V3(parser_context_t* c, pd_PalletPermissions_V3_t* v);
parser_error_t _readPerbill_V3(parser_context_t* c, pd_Perbill_V3_t* v);
parser_error_t _readPermill_V3(parser_context_t* c, pd_Permill_V3_t* v);
parser_error_t _readPermissions_V3(parser_context_t* c, pd_Permissions_V3_t* v);
parser_error_t _readPipDescription_V3(parser_context_t* c, pd_PipDescription_V3_t* v);
parser_error_t _readPipId_V3(parser_context_t* c, pd_PipId_V3_t* v);
parser_error_t _readPortfolioId_V3(parser_context_t* c, pd_PortfolioId_V3_t* v);
parser_error_t _readPortfolioKind_V3(parser_context_t* c, pd_PortfolioKind_V3_t* v);
parser_error_t _readPortfolioName_V3(parser_context_t* c, pd_PortfolioName_V3_t* v);
parser_error_t _readPortfolioNumber_V3(parser_context_t* c, pd_PortfolioNumber_V3_t* v);
parser_error_t _readPortfolioPermissions_V3(parser_context_t* c, pd_PortfolioPermissions_V3_t* v);
parser_error_t _readPosRatio_V3(parser_context_t* c, pd_PosRatio_V3_t* v);
parser_error_t _readPriceTier_V3(parser_context_t* c, pd_PriceTier_V3_t* v);
parser_error_t _readProposalIndex_V3(parser_context_t* c, pd_ProposalIndex_V3_t* v);
parser_error_t _readReceiptDetails_V3(parser_context_t* c, pd_ReceiptDetails_V3_t* v);
parser_error_t _readReceiptMetadata_V3(parser_context_t* c, pd_ReceiptMetadata_V3_t* v);
parser_error_t _readRecordDateSpec_V3(parser_context_t* c, pd_RecordDateSpec_V3_t* v);
parser_error_t _readRewardDestination_V3(parser_context_t* c, pd_RewardDestination_V3_t* v);
parser_error_t _readScheduleId_V3(parser_context_t* c, pd_ScheduleId_V3_t* v);
parser_error_t _readScheduleSpec_V3(parser_context_t* c, pd_ScheduleSpec_V3_t* v);
parser_error_t _readScopeId_V3(parser_context_t* c, pd_ScopeId_V3_t* v);
parser_error_t _readScope_V3(parser_context_t* c, pd_Scope_V3_t* v);
parser_error_t _readSecondaryKeyWithAuthAccountId_V3(parser_context_t* c, pd_SecondaryKeyWithAuthAccountId_V3_t* v);
parser_error_t _readSettlementTypeBlockNumber_V3(parser_context_t* c, pd_SettlementTypeBlockNumber_V3_t* v);
parser_error_t _readSignatoryAccountId_V3(parser_context_t* c, pd_SignatoryAccountId_V3_t* v);
parser_error_t _readSignature_V3(parser_context_t* c, pd_Signature_V3_t* v);
parser_error_t _readSkippedCount_V3(parser_context_t* c, pd_SkippedCount_V3_t* v);
parser_error_t _readSlashingSwitch_V3(parser_context_t* c, pd_SlashingSwitch_V3_t* v);
parser_error_t _readSnapshotResult_V3(parser_context_t* c, pd_SnapshotResult_V3_t* v);
parser_error_t _readSr25519Signature_V3(parser_context_t* c, pd_Sr25519Signature_V3_t* v);
parser_error_t _readTargetIdentities_V3(parser_context_t* c, pd_TargetIdentities_V3_t* v);
parser_error_t _readTargetIdentity_V3(parser_context_t* c, pd_TargetIdentity_V3_t* v);
parser_error_t _readTargetTreatment_V3(parser_context_t* c, pd_TargetTreatment_V3_t* v);
parser_error_t _readTax_V3(parser_context_t* c, pd_Tax_V3_t* v);
parser_error_t _readTickerRegistrationConfigMoment_V3(parser_context_t* c, pd_TickerRegistrationConfigMoment_V3_t* v);
parser_error_t _readTicker_V3(parser_context_t* c, pd_Ticker_V3_t* v);
parser_error_t _readTrustedFor_V3(parser_context_t* c, pd_TrustedFor_V3_t* v);
parser_error_t _readTrustedIssuer_V3(parser_context_t* c, pd_TrustedIssuer_V3_t* v);
parser_error_t _readTupleCountryCodeScope_V3(parser_context_t* c, pd_TupleCountryCodeScope_V3_t* v);
parser_error_t _readTupleIdentityIdTax_V3(parser_context_t* c, pd_TupleIdentityIdTax_V3_t* v);
parser_error_t _readTupleIdentityIdbool_V3(parser_context_t* c, pd_TupleIdentityIdbool_V3_t* v);
parser_error_t _readTuplePipIdSnapshotResult_V3(parser_context_t* c, pd_TuplePipIdSnapshotResult_V3_t* v);
parser_error_t _readTupleScopeScopeIdCddId_V3(parser_context_t* c, pd_TupleScopeScopeIdCddId_V3_t* v);
parser_error_t _readUniqueCall_V3(parser_context_t* c, pd_UniqueCall_V3_t* v);
parser_error_t _readUrl_V3(parser_context_t* c, pd_Url_V3_t* v);
parser_error_t _readValidatorPrefs_V3(parser_context_t* c, pd_ValidatorPrefs_V3_t* v);
parser_error_t _readVecAccountId_V3(parser_context_t* c, pd_VecAccountId_V3_t* v);
parser_error_t _readVecAssetIdentifier_V3(parser_context_t* c, pd_VecAssetIdentifier_V3_t* v);
parser_error_t _readVecBallotVote_V3(parser_context_t* c, pd_VecBallotVote_V3_t* v);
parser_error_t _readVecBeneficiary_V3(parser_context_t* c, pd_VecBeneficiary_V3_t* v);
parser_error_t _readVecBridgeTxAccountId_V3(parser_context_t* c, pd_VecBridgeTxAccountId_V3_t* v);
parser_error_t _readVecChoiceTitle_V3(parser_context_t* c, pd_VecChoiceTitle_V3_t* v);
parser_error_t _readVecClaimType_V3(parser_context_t* c, pd_VecClaimType_V3_t* v);
parser_error_t _readVecClaim_V3(parser_context_t* c, pd_VecClaim_V3_t* v);
parser_error_t _readVecCondition_V3(parser_context_t* c, pd_VecCondition_V3_t* v);
parser_error_t _readVecDispatchableName_V3(parser_context_t* c, pd_VecDispatchableName_V3_t* v);
parser_error_t _readVecDocumentId_V3(parser_context_t* c, pd_VecDocumentId_V3_t* v);
parser_error_t _readVecDocument_V3(parser_context_t* c, pd_VecDocument_V3_t* v);
parser_error_t _readVecIdentityId_V3(parser_context_t* c, pd_VecIdentityId_V3_t* v);
parser_error_t _readVecLeg_V3(parser_context_t* c, pd_VecLeg_V3_t* v);
parser_error_t _readVecLookupasStaticLookupSource_V3(parser_context_t* c, pd_VecLookupasStaticLookupSource_V3_t* v);
parser_error_t _readVecMotion_V3(parser_context_t* c, pd_VecMotion_V3_t* v);
parser_error_t _readVecMovePortfolioItem_V3(parser_context_t* c, pd_VecMovePortfolioItem_V3_t* v);
parser_error_t _readVecPalletPermissions_V3(parser_context_t* c, pd_VecPalletPermissions_V3_t* v);
parser_error_t _readVecPortfolioId_V3(parser_context_t* c, pd_VecPortfolioId_V3_t* v);
parser_error_t _readVecPriceTier_V3(parser_context_t* c, pd_VecPriceTier_V3_t* v);
parser_error_t _readVecReceiptDetails_V3(parser_context_t* c, pd_VecReceiptDetails_V3_t* v);
parser_error_t _readVecSecondaryKeyWithAuthAccountId_V3(parser_context_t* c, pd_VecSecondaryKeyWithAuthAccountId_V3_t* v);
parser_error_t _readVecSignatoryAccountId_V3(parser_context_t* c, pd_VecSignatoryAccountId_V3_t* v);
parser_error_t _readVecTicker_V3(parser_context_t* c, pd_VecTicker_V3_t* v);
parser_error_t _readVecTrustedIssuer_V3(parser_context_t* c, pd_VecTrustedIssuer_V3_t* v);
parser_error_t _readVecTupleIdentityIdTax_V3(parser_context_t* c, pd_VecTupleIdentityIdTax_V3_t* v);
parser_error_t _readVecTupleIdentityIdbool_V3(parser_context_t* c, pd_VecTupleIdentityIdbool_V3_t* v);
parser_error_t _readVecTuplePipIdSnapshotResult_V3(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V3_t* v);
parser_error_t _readVecVenueId_V3(parser_context_t* c, pd_VecVenueId_V3_t* v);
parser_error_t _readVenueDetails_V3(parser_context_t* c, pd_VenueDetails_V3_t* v);
parser_error_t _readVenueId_V3(parser_context_t* c, pd_VenueId_V3_t* v);
parser_error_t _readVenueType_V3(parser_context_t* c, pd_VenueType_V3_t* v);
parser_error_t _readWeight_V3(parser_context_t* c, pd_Weight_V3_t* v);

// toString functions
parser_error_t _toStringAGId_V3(
    const pd_AGId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V3(
    const pd_AccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V3(
    const pd_AccountIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAddRelayerPayingKey_V3(
    const pd_AddRelayerPayingKey_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAgentGroup_V3(
    const pd_AgentGroup_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdentifier_V3(
    const pd_AssetIdentifier_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataKey_V3(
    const pd_AssetMetadataKey_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataLockStatusMoment_V3(
    const pd_AssetMetadataLockStatusMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataName_V3(
    const pd_AssetMetadataName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataSpec_V3(
    const pd_AssetMetadataSpec_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataValueDetailMoment_V3(
    const pd_AssetMetadataValueDetailMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataValue_V3(
    const pd_AssetMetadataValue_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetName_V3(
    const pd_AssetName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetPermissions_V3(
    const pd_AssetPermissions_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V3(
    const pd_AssetType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorizationDataAccountId_V3(
    const pd_AuthorizationDataAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotMeta_V3(
    const pd_BallotMeta_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTimeRange_V3(
    const pd_BallotTimeRange_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTitle_V3(
    const pd_BallotTitle_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotVote_V3(
    const pd_BallotVote_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBecomeAgent_V3(
    const pd_BecomeAgent_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBeneficiary_V3(
    const pd_Beneficiary_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeTxAccountId_V3(
    const pd_BridgeTxAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCADetails_V3(
    const pd_CADetails_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAId_V3(
    const pd_CAId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAKind_V3(
    const pd_CAKind_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarPeriod_V3(
    const pd_CalendarPeriod_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarUnit_V3(
    const pd_CalendarUnit_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCddId_V3(
    const pd_CddId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCheckpointId_V3(
    const pd_CheckpointId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChoiceTitle_V3(
    const pd_ChoiceTitle_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaimType_V3(
    const pd_ClaimType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaim_V3(
    const pd_Claim_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassicTickerImport_V3(
    const pd_ClassicTickerImport_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash_V3(
    const pd_CodeHash_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V3(
    const pd_CompactAccountIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V3(
    const pd_CompactPerBill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConditionType_V3(
    const pd_ConditionType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCondition_V3(
    const pd_Condition_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCountryCode_V3(
    const pd_CountryCode_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCustomAssetTypeId_V3(
    const pd_CustomAssetTypeId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableName_V3(
    const pd_DispatchableName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableNames_V3(
    const pd_DispatchableNames_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentHash_V3(
    const pd_DocumentHash_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentId_V3(
    const pd_DocumentId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentName_V3(
    const pd_DocumentName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentType_V3(
    const pd_DocumentType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentUri_V3(
    const pd_DocumentUri_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocument_V3(
    const pd_Document_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V3(
    const pd_EcdsaSignature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature_V3(
    const pd_Ed25519Signature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V3(
    const pd_EraIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V3(
    const pd_EthereumAddress_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringExtrinsicPermissions_V3(
    const pd_ExtrinsicPermissions_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundingRoundName_V3(
    const pd_FundingRoundName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserId_V3(
    const pd_FundraiserId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserName_V3(
    const pd_FundraiserName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityId_V3(
    const pd_IdentityId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstructionId_V3(
    const pd_InstructionId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorZKProofData_V3(
    const pd_InvestorZKProofData_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V3(
    const pd_Keys_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegId_V3(
    const pd_LegId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeg_V3(
    const pd_Leg_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLocalCAId_V3(
    const pd_LocalCAId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource_V3(
    const pd_LookupasStaticLookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMaybeBlockBlockNumber_V3(
    const pd_MaybeBlockBlockNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V3(
    const pd_MemberCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemo_V3(
    const pd_Memo_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment_V3(
    const pd_Moment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionInfoLink_V3(
    const pd_MotionInfoLink_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionTitle_V3(
    const pd_MotionTitle_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotion_V3(
    const pd_Motion_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMovePortfolioItem_V3(
    const pd_MovePortfolioItem_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature_V3(
    const pd_MultiSignature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffChainSignature_V3(
    const pd_OffChainSignature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAssetMetadataValueDetailMoment_V3(
    const pd_OptionAssetMetadataValueDetailMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionDocumentType_V3(
    const pd_OptionDocumentType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionFundingRoundName_V3(
    const pd_OptionFundingRoundName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMemo_V3(
    const pd_OptionMemo_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMoment_V3(
    const pd_OptionMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPipDescription_V3(
    const pd_OptionPipDescription_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioNumber_V3(
    const pd_OptionPortfolioNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptDetails_V3(
    const pd_OptionReceiptDetails_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRecordDateSpec_V3(
    const pd_OptionRecordDateSpec_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionScope_V3(
    const pd_OptionScope_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTargetIdentities_V3(
    const pd_OptionTargetIdentities_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTax_V3(
    const pd_OptionTax_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionUrl_V3(
    const pd_OptionUrl_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleIdentityIdTax_V3(
    const pd_OptionVecTupleIdentityIdTax_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletName_V3(
    const pd_PalletName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletPermissions_V3(
    const pd_PalletPermissions_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V3(
    const pd_Perbill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermill_V3(
    const pd_Permill_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermissions_V3(
    const pd_Permissions_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipDescription_V3(
    const pd_PipDescription_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipId_V3(
    const pd_PipId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioId_V3(
    const pd_PortfolioId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioKind_V3(
    const pd_PortfolioKind_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioName_V3(
    const pd_PortfolioName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioNumber_V3(
    const pd_PortfolioNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioPermissions_V3(
    const pd_PortfolioPermissions_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPosRatio_V3(
    const pd_PosRatio_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriceTier_V3(
    const pd_PriceTier_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposalIndex_V3(
    const pd_ProposalIndex_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptDetails_V3(
    const pd_ReceiptDetails_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptMetadata_V3(
    const pd_ReceiptMetadata_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRecordDateSpec_V3(
    const pd_RecordDateSpec_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V3(
    const pd_RewardDestination_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleId_V3(
    const pd_ScheduleId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleSpec_V3(
    const pd_ScheduleSpec_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeId_V3(
    const pd_ScopeId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScope_V3(
    const pd_Scope_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyWithAuthAccountId_V3(
    const pd_SecondaryKeyWithAuthAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSettlementTypeBlockNumber_V3(
    const pd_SettlementTypeBlockNumber_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignatoryAccountId_V3(
    const pd_SignatoryAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V3(
    const pd_Signature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSkippedCount_V3(
    const pd_SkippedCount_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSlashingSwitch_V3(
    const pd_SlashingSwitch_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSnapshotResult_V3(
    const pd_SnapshotResult_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature_V3(
    const pd_Sr25519Signature_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentities_V3(
    const pd_TargetIdentities_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentity_V3(
    const pd_TargetIdentity_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetTreatment_V3(
    const pd_TargetTreatment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTax_V3(
    const pd_Tax_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTickerRegistrationConfigMoment_V3(
    const pd_TickerRegistrationConfigMoment_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTicker_V3(
    const pd_Ticker_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedFor_V3(
    const pd_TrustedFor_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedIssuer_V3(
    const pd_TrustedIssuer_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCountryCodeScope_V3(
    const pd_TupleCountryCodeScope_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdTax_V3(
    const pd_TupleIdentityIdTax_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdbool_V3(
    const pd_TupleIdentityIdbool_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePipIdSnapshotResult_V3(
    const pd_TuplePipIdSnapshotResult_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleScopeScopeIdCddId_V3(
    const pd_TupleScopeScopeIdCddId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUniqueCall_V3(
    const pd_UniqueCall_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUrl_V3(
    const pd_Url_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V3(
    const pd_ValidatorPrefs_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V3(
    const pd_VecAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdentifier_V3(
    const pd_VecAssetIdentifier_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBallotVote_V3(
    const pd_VecBallotVote_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBeneficiary_V3(
    const pd_VecBeneficiary_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBridgeTxAccountId_V3(
    const pd_VecBridgeTxAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecChoiceTitle_V3(
    const pd_VecChoiceTitle_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaimType_V3(
    const pd_VecClaimType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaim_V3(
    const pd_VecClaim_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCondition_V3(
    const pd_VecCondition_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDispatchableName_V3(
    const pd_VecDispatchableName_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocumentId_V3(
    const pd_VecDocumentId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocument_V3(
    const pd_VecDocument_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecIdentityId_V3(
    const pd_VecIdentityId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLeg_V3(
    const pd_VecLeg_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource_V3(
    const pd_VecLookupasStaticLookupSource_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMotion_V3(
    const pd_VecMotion_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMovePortfolioItem_V3(
    const pd_VecMovePortfolioItem_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPalletPermissions_V3(
    const pd_VecPalletPermissions_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPortfolioId_V3(
    const pd_VecPortfolioId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPriceTier_V3(
    const pd_VecPriceTier_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecReceiptDetails_V3(
    const pd_VecReceiptDetails_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyWithAuthAccountId_V3(
    const pd_VecSecondaryKeyWithAuthAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSignatoryAccountId_V3(
    const pd_VecSignatoryAccountId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTicker_V3(
    const pd_VecTicker_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTrustedIssuer_V3(
    const pd_VecTrustedIssuer_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdTax_V3(
    const pd_VecTupleIdentityIdTax_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdbool_V3(
    const pd_VecTupleIdentityIdbool_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePipIdSnapshotResult_V3(
    const pd_VecTuplePipIdSnapshotResult_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVenueId_V3(
    const pd_VecVenueId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueDetails_V3(
    const pd_VenueDetails_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueId_V3(
    const pd_VenueId_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueType_V3(
    const pd_VenueType_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V3(
    const pd_Weight_V3_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
