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

#include "parser_common.h"
#include "substrate_methods_V5.h"
#include "substrate_types_V5.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V5(parser_context_t* c, pd_AccountId_V5_t* v);
parser_error_t _readAccountIndex_V5(parser_context_t* c, pd_AccountIndex_V5_t* v);
parser_error_t _readAssetIdentifier_V5(parser_context_t* c, pd_AssetIdentifier_V5_t* v);
parser_error_t _readAssetName_V5(parser_context_t* c, pd_AssetName_V5_t* v);
parser_error_t _readAssetType_V5(parser_context_t* c, pd_AssetType_V5_t* v);
parser_error_t _readAuthorizationData_V5(parser_context_t* c, pd_AuthorizationData_V5_t* v);
parser_error_t _readBallotMeta_V5(parser_context_t* c, pd_BallotMeta_V5_t* v);
parser_error_t _readBallotTimeRange_V5(parser_context_t* c, pd_BallotTimeRange_V5_t* v);
parser_error_t _readBallotTitle_V5(parser_context_t* c, pd_BallotTitle_V5_t* v);
parser_error_t _readBallotVote_V5(parser_context_t* c, pd_BallotVote_V5_t* v);
parser_error_t _readBeneficiary_V5(parser_context_t* c, pd_Beneficiary_V5_t* v);
parser_error_t _readBridgeTx_V5(parser_context_t* c, pd_BridgeTx_V5_t* v);
parser_error_t _readCADetails_V5(parser_context_t* c, pd_CADetails_V5_t* v);
parser_error_t _readCAId_V5(parser_context_t* c, pd_CAId_V5_t* v);
parser_error_t _readCAKind_V5(parser_context_t* c, pd_CAKind_V5_t* v);
parser_error_t _readCalendarPeriod_V5(parser_context_t* c, pd_CalendarPeriod_V5_t* v);
parser_error_t _readCalendarUnit_V5(parser_context_t* c, pd_CalendarUnit_V5_t* v);
parser_error_t _readCddId_V5(parser_context_t* c, pd_CddId_V5_t* v);
parser_error_t _readChangesTrieConfiguration_V5(parser_context_t* c, pd_ChangesTrieConfiguration_V5_t* v);
parser_error_t _readCheckpointId_V5(parser_context_t* c, pd_CheckpointId_V5_t* v);
parser_error_t _readChoiceTitle_V5(parser_context_t* c, pd_ChoiceTitle_V5_t* v);
parser_error_t _readClaimType_V5(parser_context_t* c, pd_ClaimType_V5_t* v);
parser_error_t _readClaim_V5(parser_context_t* c, pd_Claim_V5_t* v);
parser_error_t _readClassicTickerImport_V5(parser_context_t* c, pd_ClassicTickerImport_V5_t* v);
parser_error_t _readCodeHash_V5(parser_context_t* c, pd_CodeHash_V5_t* v);
parser_error_t _readCompactAssignments_V5(parser_context_t* c, pd_CompactAssignments_V5_t* v);
parser_error_t _readCompactEraIndex_V5(parser_context_t* c, pd_CompactEraIndex_V5_t* v);
parser_error_t _readCompactGas_V5(parser_context_t* c, pd_CompactGas_V5_t* v);
parser_error_t _readCompactMoment_V5(parser_context_t* c, pd_CompactMoment_V5_t* v);
parser_error_t _readCompactPerBill_V5(parser_context_t* c, pd_CompactPerBill_V5_t* v);
parser_error_t _readComplianceRequirement_V5(parser_context_t* c, pd_ComplianceRequirement_V5_t* v);
parser_error_t _readConditionType_V5(parser_context_t* c, pd_ConditionType_V5_t* v);
parser_error_t _readCondition_V5(parser_context_t* c, pd_Condition_V5_t* v);
parser_error_t _readCounter_V5(parser_context_t* c, pd_Counter_V5_t* v);
parser_error_t _readCountryCode_V5(parser_context_t* c, pd_CountryCode_V5_t* v);
parser_error_t _readDispatchableName_V5(parser_context_t* c, pd_DispatchableName_V5_t* v);
parser_error_t _readDocumentHash_V5(parser_context_t* c, pd_DocumentHash_V5_t* v);
parser_error_t _readDocumentId_V5(parser_context_t* c, pd_DocumentId_V5_t* v);
parser_error_t _readDocumentName_V5(parser_context_t* c, pd_DocumentName_V5_t* v);
parser_error_t _readDocumentType_V5(parser_context_t* c, pd_DocumentType_V5_t* v);
parser_error_t _readDocumentUri_V5(parser_context_t* c, pd_DocumentUri_V5_t* v);
parser_error_t _readDocument_V5(parser_context_t* c, pd_Document_V5_t* v);
parser_error_t _readEcdsaSignature_V5(parser_context_t* c, pd_EcdsaSignature_V5_t* v);
parser_error_t _readElectionScore_V5(parser_context_t* c, pd_ElectionScore_V5_t* v);
parser_error_t _readElectionSize_V5(parser_context_t* c, pd_ElectionSize_V5_t* v);
parser_error_t _readEquivocationProof_V5(parser_context_t* c, pd_EquivocationProof_V5_t* v);
parser_error_t _readEraIndex_V5(parser_context_t* c, pd_EraIndex_V5_t* v);
parser_error_t _readEthereumAddress_V5(parser_context_t* c, pd_EthereumAddress_V5_t* v);
parser_error_t _readFundingRoundName_V5(parser_context_t* c, pd_FundingRoundName_V5_t* v);
parser_error_t _readFundraiserName_V5(parser_context_t* c, pd_FundraiserName_V5_t* v);
parser_error_t _readIdentityId_V5(parser_context_t* c, pd_IdentityId_V5_t* v);
parser_error_t _readInvestorUid_V5(parser_context_t* c, pd_InvestorUid_V5_t* v);
parser_error_t _readInvestorZKProofData_V5(parser_context_t* c, pd_InvestorZKProofData_V5_t* v);
parser_error_t _readKeyOwnerProof_V5(parser_context_t* c, pd_KeyOwnerProof_V5_t* v);
parser_error_t _readKeyValue_V5(parser_context_t* c, pd_KeyValue_V5_t* v);
parser_error_t _readKey_V5(parser_context_t* c, pd_Key_V5_t* v);
parser_error_t _readKeys_V5(parser_context_t* c, pd_Keys_V5_t* v);
parser_error_t _readLeg_V5(parser_context_t* c, pd_Leg_V5_t* v);
parser_error_t _readLegacyPermissions_V5(parser_context_t* c, pd_LegacyPermissions_V5_t* v);
parser_error_t _readLocalCAId_V5(parser_context_t* c, pd_LocalCAId_V5_t* v);
parser_error_t _readMaybeBlock_V5(parser_context_t* c, pd_MaybeBlock_V5_t* v);
parser_error_t _readMemberCount_V5(parser_context_t* c, pd_MemberCount_V5_t* v);
parser_error_t _readMemo_V5(parser_context_t* c, pd_Memo_V5_t* v);
parser_error_t _readMetaDescription_V5(parser_context_t* c, pd_MetaDescription_V5_t* v);
parser_error_t _readMetaUrl_V5(parser_context_t* c, pd_MetaUrl_V5_t* v);
parser_error_t _readMetaVersion_V5(parser_context_t* c, pd_MetaVersion_V5_t* v);
parser_error_t _readMoment_V5(parser_context_t* c, pd_Moment_V5_t* v);
parser_error_t _readMotionInfoLink_V5(parser_context_t* c, pd_MotionInfoLink_V5_t* v);
parser_error_t _readMotionTitle_V5(parser_context_t* c, pd_MotionTitle_V5_t* v);
parser_error_t _readMotion_V5(parser_context_t* c, pd_Motion_V5_t* v);
parser_error_t _readMovePortfolioItem_V5(parser_context_t* c, pd_MovePortfolioItem_V5_t* v);
parser_error_t _readOffChainSignature_V5(parser_context_t* c, pd_OffChainSignature_V5_t* v);
parser_error_t _readOfflineSlashingParams_V5(parser_context_t* c, pd_OfflineSlashingParams_V5_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V5(parser_context_t* c, pd_OptionChangesTrieConfiguration_V5_t* v);
parser_error_t _readOptionDocumentType_V5(parser_context_t* c, pd_OptionDocumentType_V5_t* v);
parser_error_t _readOptionFundingRoundName_V5(parser_context_t* c, pd_OptionFundingRoundName_V5_t* v);
parser_error_t _readOptionMemo_V5(parser_context_t* c, pd_OptionMemo_V5_t* v);
parser_error_t _readOptionMetaUrl_V5(parser_context_t* c, pd_OptionMetaUrl_V5_t* v);
parser_error_t _readOptionMoment_V5(parser_context_t* c, pd_OptionMoment_V5_t* v);
parser_error_t _readOptionPeriod_V5(parser_context_t* c, pd_OptionPeriod_V5_t* v);
parser_error_t _readOptionPipDescription_V5(parser_context_t* c, pd_OptionPipDescription_V5_t* v);
parser_error_t _readOptionPortfolioNumber_V5(parser_context_t* c, pd_OptionPortfolioNumber_V5_t* v);
parser_error_t _readOptionReceiptDetails_V5(parser_context_t* c, pd_OptionReceiptDetails_V5_t* v);
parser_error_t _readOptionRecordDateSpec_V5(parser_context_t* c, pd_OptionRecordDateSpec_V5_t* v);
parser_error_t _readOptionTargetIdentities_V5(parser_context_t* c, pd_OptionTargetIdentities_V5_t* v);
parser_error_t _readOptionTax_V5(parser_context_t* c, pd_OptionTax_V5_t* v);
parser_error_t _readOptionUrl_V5(parser_context_t* c, pd_OptionUrl_V5_t* v);
parser_error_t _readOptionVecDispatchableName_V5(parser_context_t* c, pd_OptionVecDispatchableName_V5_t* v);
parser_error_t _readOptionVecPalletPermissions_V5(parser_context_t* c, pd_OptionVecPalletPermissions_V5_t* v);
parser_error_t _readOptionVecPortfolioId_V5(parser_context_t* c, pd_OptionVecPortfolioId_V5_t* v);
parser_error_t _readOptionVecTicker_V5(parser_context_t* c, pd_OptionVecTicker_V5_t* v);
parser_error_t _readOptionVecTupleIdentityIdTax_V5(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V5_t* v);
parser_error_t _readOptionVenueDetails_V5(parser_context_t* c, pd_OptionVenueDetails_V5_t* v);
parser_error_t _readOptionVenueType_V5(parser_context_t* c, pd_OptionVenueType_V5_t* v);
parser_error_t _readPalletName_V5(parser_context_t* c, pd_PalletName_V5_t* v);
parser_error_t _readPalletPermissions_V5(parser_context_t* c, pd_PalletPermissions_V5_t* v);
parser_error_t _readPerbill_V5(parser_context_t* c, pd_Perbill_V5_t* v);
parser_error_t _readPercent_V5(parser_context_t* c, pd_Percent_V5_t* v);
parser_error_t _readPercentage_V5(parser_context_t* c, pd_Percentage_V5_t* v);
parser_error_t _readPeriod_V5(parser_context_t* c, pd_Period_V5_t* v);
parser_error_t _readPermill_V5(parser_context_t* c, pd_Permill_V5_t* v);
parser_error_t _readPermissions_V5(parser_context_t* c, pd_Permissions_V5_t* v);
parser_error_t _readPipDescription_V5(parser_context_t* c, pd_PipDescription_V5_t* v);
parser_error_t _readPipId_V5(parser_context_t* c, pd_PipId_V5_t* v);
parser_error_t _readPortfolioId_V5(parser_context_t* c, pd_PortfolioId_V5_t* v);
parser_error_t _readPortfolioKind_V5(parser_context_t* c, pd_PortfolioKind_V5_t* v);
parser_error_t _readPortfolioName_V5(parser_context_t* c, pd_PortfolioName_V5_t* v);
parser_error_t _readPortfolioNumber_V5(parser_context_t* c, pd_PortfolioNumber_V5_t* v);
parser_error_t _readPosRatio_V5(parser_context_t* c, pd_PosRatio_V5_t* v);
parser_error_t _readPriceTier_V5(parser_context_t* c, pd_PriceTier_V5_t* v);
parser_error_t _readPriority_V5(parser_context_t* c, pd_Priority_V5_t* v);
parser_error_t _readProposalIndex_V5(parser_context_t* c, pd_ProposalIndex_V5_t* v);
parser_error_t _readProtocolOp_V5(parser_context_t* c, pd_ProtocolOp_V5_t* v);
parser_error_t _readReceiptDetails_V5(parser_context_t* c, pd_ReceiptDetails_V5_t* v);
parser_error_t _readReceiptMetadata_V5(parser_context_t* c, pd_ReceiptMetadata_V5_t* v);
parser_error_t _readRecordDateSpec_V5(parser_context_t* c, pd_RecordDateSpec_V5_t* v);
parser_error_t _readRewardDestination_V5(parser_context_t* c, pd_RewardDestination_V5_t* v);
parser_error_t _readScheduleId_V5(parser_context_t* c, pd_ScheduleId_V5_t* v);
parser_error_t _readScheduleSpec_V5(parser_context_t* c, pd_ScheduleSpec_V5_t* v);
parser_error_t _readSchedule_V5(parser_context_t* c, pd_Schedule_V5_t* v);
parser_error_t _readScopeId_V5(parser_context_t* c, pd_ScopeId_V5_t* v);
parser_error_t _readScope_V5(parser_context_t* c, pd_Scope_V5_t* v);
parser_error_t _readSecondaryKeyWithAuth_V5(parser_context_t* c, pd_SecondaryKeyWithAuth_V5_t* v);
parser_error_t _readSecondaryKey_V5(parser_context_t* c, pd_SecondaryKey_V5_t* v);
parser_error_t _readSettlementType_V5(parser_context_t* c, pd_SettlementType_V5_t* v);
parser_error_t _readSignatory_V5(parser_context_t* c, pd_Signatory_V5_t* v);
parser_error_t _readSignature_V5(parser_context_t* c, pd_Signature_V5_t* v);
parser_error_t _readSkippedCount_V5(parser_context_t* c, pd_SkippedCount_V5_t* v);
parser_error_t _readSlashingSwitch_V5(parser_context_t* c, pd_SlashingSwitch_V5_t* v);
parser_error_t _readSmartExtensionName_V5(parser_context_t* c, pd_SmartExtensionName_V5_t* v);
parser_error_t _readSmartExtensionType_V5(parser_context_t* c, pd_SmartExtensionType_V5_t* v);
parser_error_t _readSmartExtension_V5(parser_context_t* c, pd_SmartExtension_V5_t* v);
parser_error_t _readSnapshotResult_V5(parser_context_t* c, pd_SnapshotResult_V5_t* v);
parser_error_t _readStreamDependency_V5(parser_context_t* c, pd_StreamDependency_V5_t* v);
parser_error_t _readTargetIdAuthorization_V5(parser_context_t* c, pd_TargetIdAuthorization_V5_t* v);
parser_error_t _readTargetIdentities_V5(parser_context_t* c, pd_TargetIdentities_V5_t* v);
parser_error_t _readTargetIdentity_V5(parser_context_t* c, pd_TargetIdentity_V5_t* v);
parser_error_t _readTargetTreatment_V5(parser_context_t* c, pd_TargetTreatment_V5_t* v);
parser_error_t _readTax_V5(parser_context_t* c, pd_Tax_V5_t* v);
parser_error_t _readTemplateMetadata_V5(parser_context_t* c, pd_TemplateMetadata_V5_t* v);
parser_error_t _readTickerRegistrationConfig_V5(parser_context_t* c, pd_TickerRegistrationConfig_V5_t* v);
parser_error_t _readTicker_V5(parser_context_t* c, pd_Ticker_V5_t* v);
parser_error_t _readTransferManager_V5(parser_context_t* c, pd_TransferManager_V5_t* v);
parser_error_t _readTrustedFor_V5(parser_context_t* c, pd_TrustedFor_V5_t* v);
parser_error_t _readTrustedIssuer_V5(parser_context_t* c, pd_TrustedIssuer_V5_t* v);
parser_error_t _readTupleCountryCodeScope_V5(parser_context_t* c, pd_TupleCountryCodeScope_V5_t* v);
parser_error_t _readTupleIdentityIdTax_V5(parser_context_t* c, pd_TupleIdentityIdTax_V5_t* v);
parser_error_t _readTupleIdentityIdbool_V5(parser_context_t* c, pd_TupleIdentityIdbool_V5_t* v);
parser_error_t _readTuplePipIdSnapshotResult_V5(parser_context_t* c, pd_TuplePipIdSnapshotResult_V5_t* v);
parser_error_t _readTupleScopeScopeIdCddId_V5(parser_context_t* c, pd_TupleScopeScopeIdCddId_V5_t* v);
parser_error_t _readUniqueCall_V5(parser_context_t* c, pd_UniqueCall_V5_t* v);
parser_error_t _readUrl_V5(parser_context_t* c, pd_Url_V5_t* v);
parser_error_t _readValidatorIndex_V5(parser_context_t* c, pd_ValidatorIndex_V5_t* v);
parser_error_t _readValidatorPrefs_V5(parser_context_t* c, pd_ValidatorPrefs_V5_t* v);
parser_error_t _readVecAccountId_V5(parser_context_t* c, pd_VecAccountId_V5_t* v);
parser_error_t _readVecAssetIdentifier_V5(parser_context_t* c, pd_VecAssetIdentifier_V5_t* v);
parser_error_t _readVecBallotVote_V5(parser_context_t* c, pd_VecBallotVote_V5_t* v);
parser_error_t _readVecBeneficiary_V5(parser_context_t* c, pd_VecBeneficiary_V5_t* v);
parser_error_t _readVecBridgeTx_V5(parser_context_t* c, pd_VecBridgeTx_V5_t* v);
parser_error_t _readVecChoiceTitle_V5(parser_context_t* c, pd_VecChoiceTitle_V5_t* v);
parser_error_t _readVecClaimType_V5(parser_context_t* c, pd_VecClaimType_V5_t* v);
parser_error_t _readVecClaim_V5(parser_context_t* c, pd_VecClaim_V5_t* v);
parser_error_t _readVecComplianceRequirement_V5(parser_context_t* c, pd_VecComplianceRequirement_V5_t* v);
parser_error_t _readVecCondition_V5(parser_context_t* c, pd_VecCondition_V5_t* v);
parser_error_t _readVecDispatchableName_V5(parser_context_t* c, pd_VecDispatchableName_V5_t* v);
parser_error_t _readVecDocumentId_V5(parser_context_t* c, pd_VecDocumentId_V5_t* v);
parser_error_t _readVecDocument_V5(parser_context_t* c, pd_VecDocument_V5_t* v);
parser_error_t _readVecIdentityId_V5(parser_context_t* c, pd_VecIdentityId_V5_t* v);
parser_error_t _readVecKeyValue_V5(parser_context_t* c, pd_VecKeyValue_V5_t* v);
parser_error_t _readVecKey_V5(parser_context_t* c, pd_VecKey_V5_t* v);
parser_error_t _readVecLeg_V5(parser_context_t* c, pd_VecLeg_V5_t* v);
parser_error_t _readVecMotion_V5(parser_context_t* c, pd_VecMotion_V5_t* v);
parser_error_t _readVecMovePortfolioItem_V5(parser_context_t* c, pd_VecMovePortfolioItem_V5_t* v);
parser_error_t _readVecPalletPermissions_V5(parser_context_t* c, pd_VecPalletPermissions_V5_t* v);
parser_error_t _readVecPortfolioId_V5(parser_context_t* c, pd_VecPortfolioId_V5_t* v);
parser_error_t _readVecPriceTier_V5(parser_context_t* c, pd_VecPriceTier_V5_t* v);
parser_error_t _readVecReceiptDetails_V5(parser_context_t* c, pd_VecReceiptDetails_V5_t* v);
parser_error_t _readVecScopeId_V5(parser_context_t* c, pd_VecScopeId_V5_t* v);
parser_error_t _readVecSecondaryKeyWithAuth_V5(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V5_t* v);
parser_error_t _readVecSecondaryKey_V5(parser_context_t* c, pd_VecSecondaryKey_V5_t* v);
parser_error_t _readVecSignatory_V5(parser_context_t* c, pd_VecSignatory_V5_t* v);
parser_error_t _readVecTicker_V5(parser_context_t* c, pd_VecTicker_V5_t* v);
parser_error_t _readVecTrustedIssuer_V5(parser_context_t* c, pd_VecTrustedIssuer_V5_t* v);
parser_error_t _readVecTupleIdentityIdTax_V5(parser_context_t* c, pd_VecTupleIdentityIdTax_V5_t* v);
parser_error_t _readVecTupleIdentityIdbool_V5(parser_context_t* c, pd_VecTupleIdentityIdbool_V5_t* v);
parser_error_t _readVecTuplePipIdSnapshotResult_V5(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V5_t* v);
parser_error_t _readVecValidatorIndex_V5(parser_context_t* c, pd_VecValidatorIndex_V5_t* v);
parser_error_t _readVenueDetails_V5(parser_context_t* c, pd_VenueDetails_V5_t* v);
parser_error_t _readVenueType_V5(parser_context_t* c, pd_VenueType_V5_t* v);
parser_error_t _readWeight_V5(parser_context_t* c, pd_Weight_V5_t* v);

// toString functions
parser_error_t _toStringAccountId_V5(
    const pd_AccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V5(
    const pd_AccountIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdentifier_V5(
    const pd_AssetIdentifier_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetName_V5(
    const pd_AssetName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V5(
    const pd_AssetType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorizationData_V5(
    const pd_AuthorizationData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotMeta_V5(
    const pd_BallotMeta_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTimeRange_V5(
    const pd_BallotTimeRange_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTitle_V5(
    const pd_BallotTitle_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotVote_V5(
    const pd_BallotVote_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBeneficiary_V5(
    const pd_Beneficiary_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeTx_V5(
    const pd_BridgeTx_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCADetails_V5(
    const pd_CADetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAId_V5(
    const pd_CAId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAKind_V5(
    const pd_CAKind_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarPeriod_V5(
    const pd_CalendarPeriod_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarUnit_V5(
    const pd_CalendarUnit_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCddId_V5(
    const pd_CddId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V5(
    const pd_ChangesTrieConfiguration_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCheckpointId_V5(
    const pd_CheckpointId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChoiceTitle_V5(
    const pd_ChoiceTitle_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaimType_V5(
    const pd_ClaimType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaim_V5(
    const pd_Claim_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassicTickerImport_V5(
    const pd_ClassicTickerImport_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash_V5(
    const pd_CodeHash_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V5(
    const pd_CompactAssignments_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V5(
    const pd_CompactEraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactGas_V5(
    const pd_CompactGas_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V5(
    const pd_CompactMoment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V5(
    const pd_CompactPerBill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringComplianceRequirement_V5(
    const pd_ComplianceRequirement_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConditionType_V5(
    const pd_ConditionType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCondition_V5(
    const pd_Condition_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCounter_V5(
    const pd_Counter_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCountryCode_V5(
    const pd_CountryCode_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableName_V5(
    const pd_DispatchableName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentHash_V5(
    const pd_DocumentHash_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentId_V5(
    const pd_DocumentId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentName_V5(
    const pd_DocumentName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentType_V5(
    const pd_DocumentType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentUri_V5(
    const pd_DocumentUri_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocument_V5(
    const pd_Document_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V5(
    const pd_EcdsaSignature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V5(
    const pd_ElectionScore_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V5(
    const pd_ElectionSize_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEquivocationProof_V5(
    const pd_EquivocationProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V5(
    const pd_EraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V5(
    const pd_EthereumAddress_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundingRoundName_V5(
    const pd_FundingRoundName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserName_V5(
    const pd_FundraiserName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityId_V5(
    const pd_IdentityId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorUid_V5(
    const pd_InvestorUid_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorZKProofData_V5(
    const pd_InvestorZKProofData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V5(
    const pd_KeyOwnerProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V5(
    const pd_KeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V5(
    const pd_Key_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V5(
    const pd_Keys_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeg_V5(
    const pd_Leg_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPermissions_V5(
    const pd_LegacyPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLocalCAId_V5(
    const pd_LocalCAId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMaybeBlock_V5(
    const pd_MaybeBlock_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V5(
    const pd_MemberCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemo_V5(
    const pd_Memo_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaDescription_V5(
    const pd_MetaDescription_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaUrl_V5(
    const pd_MetaUrl_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaVersion_V5(
    const pd_MetaVersion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment_V5(
    const pd_Moment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionInfoLink_V5(
    const pd_MotionInfoLink_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionTitle_V5(
    const pd_MotionTitle_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotion_V5(
    const pd_Motion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMovePortfolioItem_V5(
    const pd_MovePortfolioItem_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffChainSignature_V5(
    const pd_OffChainSignature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOfflineSlashingParams_V5(
    const pd_OfflineSlashingParams_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V5(
    const pd_OptionChangesTrieConfiguration_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionDocumentType_V5(
    const pd_OptionDocumentType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionFundingRoundName_V5(
    const pd_OptionFundingRoundName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMemo_V5(
    const pd_OptionMemo_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMetaUrl_V5(
    const pd_OptionMetaUrl_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMoment_V5(
    const pd_OptionMoment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V5(
    const pd_OptionPeriod_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPipDescription_V5(
    const pd_OptionPipDescription_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioNumber_V5(
    const pd_OptionPortfolioNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptDetails_V5(
    const pd_OptionReceiptDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRecordDateSpec_V5(
    const pd_OptionRecordDateSpec_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTargetIdentities_V5(
    const pd_OptionTargetIdentities_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTax_V5(
    const pd_OptionTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionUrl_V5(
    const pd_OptionUrl_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecDispatchableName_V5(
    const pd_OptionVecDispatchableName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPalletPermissions_V5(
    const pd_OptionVecPalletPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPortfolioId_V5(
    const pd_OptionVecPortfolioId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTicker_V5(
    const pd_OptionVecTicker_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleIdentityIdTax_V5(
    const pd_OptionVecTupleIdentityIdTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVenueDetails_V5(
    const pd_OptionVenueDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVenueType_V5(
    const pd_OptionVenueType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletName_V5(
    const pd_PalletName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletPermissions_V5(
    const pd_PalletPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V5(
    const pd_Perbill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V5(
    const pd_Percent_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercentage_V5(
    const pd_Percentage_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V5(
    const pd_Period_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermill_V5(
    const pd_Permill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermissions_V5(
    const pd_Permissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipDescription_V5(
    const pd_PipDescription_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipId_V5(
    const pd_PipId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioId_V5(
    const pd_PortfolioId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioKind_V5(
    const pd_PortfolioKind_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioName_V5(
    const pd_PortfolioName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioNumber_V5(
    const pd_PortfolioNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPosRatio_V5(
    const pd_PosRatio_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriceTier_V5(
    const pd_PriceTier_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V5(
    const pd_Priority_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposalIndex_V5(
    const pd_ProposalIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProtocolOp_V5(
    const pd_ProtocolOp_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptDetails_V5(
    const pd_ReceiptDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptMetadata_V5(
    const pd_ReceiptMetadata_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRecordDateSpec_V5(
    const pd_RecordDateSpec_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V5(
    const pd_RewardDestination_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleId_V5(
    const pd_ScheduleId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleSpec_V5(
    const pd_ScheduleSpec_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSchedule_V5(
    const pd_Schedule_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeId_V5(
    const pd_ScopeId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScope_V5(
    const pd_Scope_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyWithAuth_V5(
    const pd_SecondaryKeyWithAuth_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKey_V5(
    const pd_SecondaryKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSettlementType_V5(
    const pd_SettlementType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignatory_V5(
    const pd_Signatory_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V5(
    const pd_Signature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSkippedCount_V5(
    const pd_SkippedCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSlashingSwitch_V5(
    const pd_SlashingSwitch_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtensionName_V5(
    const pd_SmartExtensionName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtensionType_V5(
    const pd_SmartExtensionType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtension_V5(
    const pd_SmartExtension_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSnapshotResult_V5(
    const pd_SnapshotResult_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V5(
    const pd_StreamDependency_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdAuthorization_V5(
    const pd_TargetIdAuthorization_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentities_V5(
    const pd_TargetIdentities_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentity_V5(
    const pd_TargetIdentity_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetTreatment_V5(
    const pd_TargetTreatment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTax_V5(
    const pd_Tax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTemplateMetadata_V5(
    const pd_TemplateMetadata_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTickerRegistrationConfig_V5(
    const pd_TickerRegistrationConfig_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTicker_V5(
    const pd_Ticker_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTransferManager_V5(
    const pd_TransferManager_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedFor_V5(
    const pd_TrustedFor_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedIssuer_V5(
    const pd_TrustedIssuer_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCountryCodeScope_V5(
    const pd_TupleCountryCodeScope_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdTax_V5(
    const pd_TupleIdentityIdTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdbool_V5(
    const pd_TupleIdentityIdbool_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePipIdSnapshotResult_V5(
    const pd_TuplePipIdSnapshotResult_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleScopeScopeIdCddId_V5(
    const pd_TupleScopeScopeIdCddId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUniqueCall_V5(
    const pd_UniqueCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUrl_V5(
    const pd_Url_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V5(
    const pd_ValidatorIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V5(
    const pd_ValidatorPrefs_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V5(
    const pd_VecAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdentifier_V5(
    const pd_VecAssetIdentifier_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBallotVote_V5(
    const pd_VecBallotVote_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBeneficiary_V5(
    const pd_VecBeneficiary_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBridgeTx_V5(
    const pd_VecBridgeTx_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecChoiceTitle_V5(
    const pd_VecChoiceTitle_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaimType_V5(
    const pd_VecClaimType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaim_V5(
    const pd_VecClaim_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecComplianceRequirement_V5(
    const pd_VecComplianceRequirement_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCondition_V5(
    const pd_VecCondition_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDispatchableName_V5(
    const pd_VecDispatchableName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocumentId_V5(
    const pd_VecDocumentId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocument_V5(
    const pd_VecDocument_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecIdentityId_V5(
    const pd_VecIdentityId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V5(
    const pd_VecKeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V5(
    const pd_VecKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLeg_V5(
    const pd_VecLeg_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMotion_V5(
    const pd_VecMotion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMovePortfolioItem_V5(
    const pd_VecMovePortfolioItem_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPalletPermissions_V5(
    const pd_VecPalletPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPortfolioId_V5(
    const pd_VecPortfolioId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPriceTier_V5(
    const pd_VecPriceTier_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecReceiptDetails_V5(
    const pd_VecReceiptDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecScopeId_V5(
    const pd_VecScopeId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyWithAuth_V5(
    const pd_VecSecondaryKeyWithAuth_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKey_V5(
    const pd_VecSecondaryKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSignatory_V5(
    const pd_VecSignatory_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTicker_V5(
    const pd_VecTicker_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTrustedIssuer_V5(
    const pd_VecTrustedIssuer_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdTax_V5(
    const pd_VecTupleIdentityIdTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdbool_V5(
    const pd_VecTupleIdentityIdbool_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePipIdSnapshotResult_V5(
    const pd_VecTuplePipIdSnapshotResult_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V5(
    const pd_VecValidatorIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueDetails_V5(
    const pd_VenueDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueType_V5(
    const pd_VenueType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V5(
    const pd_Weight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
