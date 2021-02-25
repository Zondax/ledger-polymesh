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
#include "substrate_methods_V6.h"
#include "substrate_types_V6.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V6(parser_context_t* c, pd_AccountId_V6_t* v);
parser_error_t _readAccountIndex_V6(parser_context_t* c, pd_AccountIndex_V6_t* v);
parser_error_t _readAssetIdentifier_V6(parser_context_t* c, pd_AssetIdentifier_V6_t* v);
parser_error_t _readAssetName_V6(parser_context_t* c, pd_AssetName_V6_t* v);
parser_error_t _readAssetType_V6(parser_context_t* c, pd_AssetType_V6_t* v);
parser_error_t _readAuthorizationData_V6(parser_context_t* c, pd_AuthorizationData_V6_t* v);
parser_error_t _readBallotMeta_V6(parser_context_t* c, pd_BallotMeta_V6_t* v);
parser_error_t _readBallotTimeRange_V6(parser_context_t* c, pd_BallotTimeRange_V6_t* v);
parser_error_t _readBallotTitle_V6(parser_context_t* c, pd_BallotTitle_V6_t* v);
parser_error_t _readBallotVote_V6(parser_context_t* c, pd_BallotVote_V6_t* v);
parser_error_t _readBeneficiary_V6(parser_context_t* c, pd_Beneficiary_V6_t* v);
parser_error_t _readBridgeTx_V6(parser_context_t* c, pd_BridgeTx_V6_t* v);
parser_error_t _readCADetails_V6(parser_context_t* c, pd_CADetails_V6_t* v);
parser_error_t _readCAId_V6(parser_context_t* c, pd_CAId_V6_t* v);
parser_error_t _readCAKind_V6(parser_context_t* c, pd_CAKind_V6_t* v);
parser_error_t _readCalendarPeriod_V6(parser_context_t* c, pd_CalendarPeriod_V6_t* v);
parser_error_t _readCalendarUnit_V6(parser_context_t* c, pd_CalendarUnit_V6_t* v);
parser_error_t _readCddId_V6(parser_context_t* c, pd_CddId_V6_t* v);
parser_error_t _readChangesTrieConfiguration_V6(parser_context_t* c, pd_ChangesTrieConfiguration_V6_t* v);
parser_error_t _readCheckpointId_V6(parser_context_t* c, pd_CheckpointId_V6_t* v);
parser_error_t _readChoiceTitle_V6(parser_context_t* c, pd_ChoiceTitle_V6_t* v);
parser_error_t _readClaimType_V6(parser_context_t* c, pd_ClaimType_V6_t* v);
parser_error_t _readClaim_V6(parser_context_t* c, pd_Claim_V6_t* v);
parser_error_t _readClassicTickerImport_V6(parser_context_t* c, pd_ClassicTickerImport_V6_t* v);
parser_error_t _readCodeHash_V6(parser_context_t* c, pd_CodeHash_V6_t* v);
parser_error_t _readCompactAssignments_V6(parser_context_t* c, pd_CompactAssignments_V6_t* v);
parser_error_t _readCompactEraIndex_V6(parser_context_t* c, pd_CompactEraIndex_V6_t* v);
parser_error_t _readCompactGas_V6(parser_context_t* c, pd_CompactGas_V6_t* v);
parser_error_t _readCompactMoment_V6(parser_context_t* c, pd_CompactMoment_V6_t* v);
parser_error_t _readCompactPerBill_V6(parser_context_t* c, pd_CompactPerBill_V6_t* v);
parser_error_t _readComplianceRequirement_V6(parser_context_t* c, pd_ComplianceRequirement_V6_t* v);
parser_error_t _readConditionType_V6(parser_context_t* c, pd_ConditionType_V6_t* v);
parser_error_t _readCondition_V6(parser_context_t* c, pd_Condition_V6_t* v);
parser_error_t _readCounter_V6(parser_context_t* c, pd_Counter_V6_t* v);
parser_error_t _readCountryCode_V6(parser_context_t* c, pd_CountryCode_V6_t* v);
parser_error_t _readDispatchableName_V6(parser_context_t* c, pd_DispatchableName_V6_t* v);
parser_error_t _readDocumentHash_V6(parser_context_t* c, pd_DocumentHash_V6_t* v);
parser_error_t _readDocumentId_V6(parser_context_t* c, pd_DocumentId_V6_t* v);
parser_error_t _readDocumentName_V6(parser_context_t* c, pd_DocumentName_V6_t* v);
parser_error_t _readDocumentType_V6(parser_context_t* c, pd_DocumentType_V6_t* v);
parser_error_t _readDocumentUri_V6(parser_context_t* c, pd_DocumentUri_V6_t* v);
parser_error_t _readDocument_V6(parser_context_t* c, pd_Document_V6_t* v);
parser_error_t _readEcdsaSignature_V6(parser_context_t* c, pd_EcdsaSignature_V6_t* v);
parser_error_t _readElectionScore_V6(parser_context_t* c, pd_ElectionScore_V6_t* v);
parser_error_t _readElectionSize_V6(parser_context_t* c, pd_ElectionSize_V6_t* v);
parser_error_t _readEquivocationProof_V6(parser_context_t* c, pd_EquivocationProof_V6_t* v);
parser_error_t _readEraIndex_V6(parser_context_t* c, pd_EraIndex_V6_t* v);
parser_error_t _readEthereumAddress_V6(parser_context_t* c, pd_EthereumAddress_V6_t* v);
parser_error_t _readFundingRoundName_V6(parser_context_t* c, pd_FundingRoundName_V6_t* v);
parser_error_t _readFundraiserName_V6(parser_context_t* c, pd_FundraiserName_V6_t* v);
parser_error_t _readIdentityId_V6(parser_context_t* c, pd_IdentityId_V6_t* v);
parser_error_t _readInvestorUid_V6(parser_context_t* c, pd_InvestorUid_V6_t* v);
parser_error_t _readInvestorZKProofData_V6(parser_context_t* c, pd_InvestorZKProofData_V6_t* v);
parser_error_t _readKeyOwnerProof_V6(parser_context_t* c, pd_KeyOwnerProof_V6_t* v);
parser_error_t _readKeyValue_V6(parser_context_t* c, pd_KeyValue_V6_t* v);
parser_error_t _readKey_V6(parser_context_t* c, pd_Key_V6_t* v);
parser_error_t _readKeys_V6(parser_context_t* c, pd_Keys_V6_t* v);
parser_error_t _readLeg_V6(parser_context_t* c, pd_Leg_V6_t* v);
parser_error_t _readLegacyPermissions_V6(parser_context_t* c, pd_LegacyPermissions_V6_t* v);
parser_error_t _readLocalCAId_V6(parser_context_t* c, pd_LocalCAId_V6_t* v);
parser_error_t _readLookupSource_V6(parser_context_t* c, pd_LookupSource_V6_t* v);
parser_error_t _readMaybeBlock_V6(parser_context_t* c, pd_MaybeBlock_V6_t* v);
parser_error_t _readMemberCount_V6(parser_context_t* c, pd_MemberCount_V6_t* v);
parser_error_t _readMemo_V6(parser_context_t* c, pd_Memo_V6_t* v);
parser_error_t _readMetaDescription_V6(parser_context_t* c, pd_MetaDescription_V6_t* v);
parser_error_t _readMetaUrl_V6(parser_context_t* c, pd_MetaUrl_V6_t* v);
parser_error_t _readMetaVersion_V6(parser_context_t* c, pd_MetaVersion_V6_t* v);
parser_error_t _readMoment_V6(parser_context_t* c, pd_Moment_V6_t* v);
parser_error_t _readMotionInfoLink_V6(parser_context_t* c, pd_MotionInfoLink_V6_t* v);
parser_error_t _readMotionTitle_V6(parser_context_t* c, pd_MotionTitle_V6_t* v);
parser_error_t _readMotion_V6(parser_context_t* c, pd_Motion_V6_t* v);
parser_error_t _readMovePortfolioItem_V6(parser_context_t* c, pd_MovePortfolioItem_V6_t* v);
parser_error_t _readOffChainSignature_V6(parser_context_t* c, pd_OffChainSignature_V6_t* v);
parser_error_t _readOfflineSlashingParams_V6(parser_context_t* c, pd_OfflineSlashingParams_V6_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V6(parser_context_t* c, pd_OptionChangesTrieConfiguration_V6_t* v);
parser_error_t _readOptionDocumentType_V6(parser_context_t* c, pd_OptionDocumentType_V6_t* v);
parser_error_t _readOptionFundingRoundName_V6(parser_context_t* c, pd_OptionFundingRoundName_V6_t* v);
parser_error_t _readOptionMemo_V6(parser_context_t* c, pd_OptionMemo_V6_t* v);
parser_error_t _readOptionMetaUrl_V6(parser_context_t* c, pd_OptionMetaUrl_V6_t* v);
parser_error_t _readOptionMoment_V6(parser_context_t* c, pd_OptionMoment_V6_t* v);
parser_error_t _readOptionPeriod_V6(parser_context_t* c, pd_OptionPeriod_V6_t* v);
parser_error_t _readOptionPipDescription_V6(parser_context_t* c, pd_OptionPipDescription_V6_t* v);
parser_error_t _readOptionPortfolioNumber_V6(parser_context_t* c, pd_OptionPortfolioNumber_V6_t* v);
parser_error_t _readOptionReceiptDetails_V6(parser_context_t* c, pd_OptionReceiptDetails_V6_t* v);
parser_error_t _readOptionRecordDateSpec_V6(parser_context_t* c, pd_OptionRecordDateSpec_V6_t* v);
parser_error_t _readOptionTargetIdentities_V6(parser_context_t* c, pd_OptionTargetIdentities_V6_t* v);
parser_error_t _readOptionTax_V6(parser_context_t* c, pd_OptionTax_V6_t* v);
parser_error_t _readOptionUrl_V6(parser_context_t* c, pd_OptionUrl_V6_t* v);
parser_error_t _readOptionVecDispatchableName_V6(parser_context_t* c, pd_OptionVecDispatchableName_V6_t* v);
parser_error_t _readOptionVecPalletPermissions_V6(parser_context_t* c, pd_OptionVecPalletPermissions_V6_t* v);
parser_error_t _readOptionVecPortfolioId_V6(parser_context_t* c, pd_OptionVecPortfolioId_V6_t* v);
parser_error_t _readOptionVecTicker_V6(parser_context_t* c, pd_OptionVecTicker_V6_t* v);
parser_error_t _readOptionVecTupleIdentityIdTax_V6(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V6_t* v);
parser_error_t _readOptionVenueDetails_V6(parser_context_t* c, pd_OptionVenueDetails_V6_t* v);
parser_error_t _readOptionVenueType_V6(parser_context_t* c, pd_OptionVenueType_V6_t* v);
parser_error_t _readPalletName_V6(parser_context_t* c, pd_PalletName_V6_t* v);
parser_error_t _readPalletPermissions_V6(parser_context_t* c, pd_PalletPermissions_V6_t* v);
parser_error_t _readPerbill_V6(parser_context_t* c, pd_Perbill_V6_t* v);
parser_error_t _readPercent_V6(parser_context_t* c, pd_Percent_V6_t* v);
parser_error_t _readPercentage_V6(parser_context_t* c, pd_Percentage_V6_t* v);
parser_error_t _readPeriod_V6(parser_context_t* c, pd_Period_V6_t* v);
parser_error_t _readPermill_V6(parser_context_t* c, pd_Permill_V6_t* v);
parser_error_t _readPermissions_V6(parser_context_t* c, pd_Permissions_V6_t* v);
parser_error_t _readPipDescription_V6(parser_context_t* c, pd_PipDescription_V6_t* v);
parser_error_t _readPipId_V6(parser_context_t* c, pd_PipId_V6_t* v);
parser_error_t _readPortfolioId_V6(parser_context_t* c, pd_PortfolioId_V6_t* v);
parser_error_t _readPortfolioKind_V6(parser_context_t* c, pd_PortfolioKind_V6_t* v);
parser_error_t _readPortfolioName_V6(parser_context_t* c, pd_PortfolioName_V6_t* v);
parser_error_t _readPortfolioNumber_V6(parser_context_t* c, pd_PortfolioNumber_V6_t* v);
parser_error_t _readPosRatio_V6(parser_context_t* c, pd_PosRatio_V6_t* v);
parser_error_t _readPriceTier_V6(parser_context_t* c, pd_PriceTier_V6_t* v);
parser_error_t _readPriority_V6(parser_context_t* c, pd_Priority_V6_t* v);
parser_error_t _readProposalIndex_V6(parser_context_t* c, pd_ProposalIndex_V6_t* v);
parser_error_t _readProtocolOp_V6(parser_context_t* c, pd_ProtocolOp_V6_t* v);
parser_error_t _readReceiptDetails_V6(parser_context_t* c, pd_ReceiptDetails_V6_t* v);
parser_error_t _readReceiptMetadata_V6(parser_context_t* c, pd_ReceiptMetadata_V6_t* v);
parser_error_t _readRecordDateSpec_V6(parser_context_t* c, pd_RecordDateSpec_V6_t* v);
parser_error_t _readRewardDestination_V6(parser_context_t* c, pd_RewardDestination_V6_t* v);
parser_error_t _readScheduleId_V6(parser_context_t* c, pd_ScheduleId_V6_t* v);
parser_error_t _readScheduleSpec_V6(parser_context_t* c, pd_ScheduleSpec_V6_t* v);
parser_error_t _readSchedule_V6(parser_context_t* c, pd_Schedule_V6_t* v);
parser_error_t _readScopeId_V6(parser_context_t* c, pd_ScopeId_V6_t* v);
parser_error_t _readScope_V6(parser_context_t* c, pd_Scope_V6_t* v);
parser_error_t _readSecondaryKeyWithAuth_V6(parser_context_t* c, pd_SecondaryKeyWithAuth_V6_t* v);
parser_error_t _readSecondaryKey_V6(parser_context_t* c, pd_SecondaryKey_V6_t* v);
parser_error_t _readSettlementType_V6(parser_context_t* c, pd_SettlementType_V6_t* v);
parser_error_t _readSignatory_V6(parser_context_t* c, pd_Signatory_V6_t* v);
parser_error_t _readSignature_V6(parser_context_t* c, pd_Signature_V6_t* v);
parser_error_t _readSkippedCount_V6(parser_context_t* c, pd_SkippedCount_V6_t* v);
parser_error_t _readSlashingSwitch_V6(parser_context_t* c, pd_SlashingSwitch_V6_t* v);
parser_error_t _readSmartExtensionName_V6(parser_context_t* c, pd_SmartExtensionName_V6_t* v);
parser_error_t _readSmartExtensionType_V6(parser_context_t* c, pd_SmartExtensionType_V6_t* v);
parser_error_t _readSmartExtension_V6(parser_context_t* c, pd_SmartExtension_V6_t* v);
parser_error_t _readSnapshotResult_V6(parser_context_t* c, pd_SnapshotResult_V6_t* v);
parser_error_t _readStreamDependency_V6(parser_context_t* c, pd_StreamDependency_V6_t* v);
parser_error_t _readTargetIdAuthorization_V6(parser_context_t* c, pd_TargetIdAuthorization_V6_t* v);
parser_error_t _readTargetIdentities_V6(parser_context_t* c, pd_TargetIdentities_V6_t* v);
parser_error_t _readTargetIdentity_V6(parser_context_t* c, pd_TargetIdentity_V6_t* v);
parser_error_t _readTargetTreatment_V6(parser_context_t* c, pd_TargetTreatment_V6_t* v);
parser_error_t _readTax_V6(parser_context_t* c, pd_Tax_V6_t* v);
parser_error_t _readTemplateMetadata_V6(parser_context_t* c, pd_TemplateMetadata_V6_t* v);
parser_error_t _readTickerRegistrationConfig_V6(parser_context_t* c, pd_TickerRegistrationConfig_V6_t* v);
parser_error_t _readTicker_V6(parser_context_t* c, pd_Ticker_V6_t* v);
parser_error_t _readTransferManager_V6(parser_context_t* c, pd_TransferManager_V6_t* v);
parser_error_t _readTrustedFor_V6(parser_context_t* c, pd_TrustedFor_V6_t* v);
parser_error_t _readTrustedIssuer_V6(parser_context_t* c, pd_TrustedIssuer_V6_t* v);
parser_error_t _readTupleCountryCodeScope_V6(parser_context_t* c, pd_TupleCountryCodeScope_V6_t* v);
parser_error_t _readTupleIdentityIdTax_V6(parser_context_t* c, pd_TupleIdentityIdTax_V6_t* v);
parser_error_t _readTupleIdentityIdbool_V6(parser_context_t* c, pd_TupleIdentityIdbool_V6_t* v);
parser_error_t _readTuplePipIdSnapshotResult_V6(parser_context_t* c, pd_TuplePipIdSnapshotResult_V6_t* v);
parser_error_t _readTupleScopeScopeIdCddId_V6(parser_context_t* c, pd_TupleScopeScopeIdCddId_V6_t* v);
parser_error_t _readUniqueCall_V6(parser_context_t* c, pd_UniqueCall_V6_t* v);
parser_error_t _readUrl_V6(parser_context_t* c, pd_Url_V6_t* v);
parser_error_t _readValidatorIndex_V6(parser_context_t* c, pd_ValidatorIndex_V6_t* v);
parser_error_t _readValidatorPrefs_V6(parser_context_t* c, pd_ValidatorPrefs_V6_t* v);
parser_error_t _readVecAccountId_V6(parser_context_t* c, pd_VecAccountId_V6_t* v);
parser_error_t _readVecAssetIdentifier_V6(parser_context_t* c, pd_VecAssetIdentifier_V6_t* v);
parser_error_t _readVecBallotVote_V6(parser_context_t* c, pd_VecBallotVote_V6_t* v);
parser_error_t _readVecBeneficiary_V6(parser_context_t* c, pd_VecBeneficiary_V6_t* v);
parser_error_t _readVecBridgeTx_V6(parser_context_t* c, pd_VecBridgeTx_V6_t* v);
parser_error_t _readVecChoiceTitle_V6(parser_context_t* c, pd_VecChoiceTitle_V6_t* v);
parser_error_t _readVecClaimType_V6(parser_context_t* c, pd_VecClaimType_V6_t* v);
parser_error_t _readVecClaim_V6(parser_context_t* c, pd_VecClaim_V6_t* v);
parser_error_t _readVecComplianceRequirement_V6(parser_context_t* c, pd_VecComplianceRequirement_V6_t* v);
parser_error_t _readVecCondition_V6(parser_context_t* c, pd_VecCondition_V6_t* v);
parser_error_t _readVecDispatchableName_V6(parser_context_t* c, pd_VecDispatchableName_V6_t* v);
parser_error_t _readVecDocumentId_V6(parser_context_t* c, pd_VecDocumentId_V6_t* v);
parser_error_t _readVecDocument_V6(parser_context_t* c, pd_VecDocument_V6_t* v);
parser_error_t _readVecIdentityId_V6(parser_context_t* c, pd_VecIdentityId_V6_t* v);
parser_error_t _readVecKeyValue_V6(parser_context_t* c, pd_VecKeyValue_V6_t* v);
parser_error_t _readVecKey_V6(parser_context_t* c, pd_VecKey_V6_t* v);
parser_error_t _readVecLeg_V6(parser_context_t* c, pd_VecLeg_V6_t* v);
parser_error_t _readVecLookupSource_V6(parser_context_t* c, pd_VecLookupSource_V6_t* v);
parser_error_t _readVecMotion_V6(parser_context_t* c, pd_VecMotion_V6_t* v);
parser_error_t _readVecMovePortfolioItem_V6(parser_context_t* c, pd_VecMovePortfolioItem_V6_t* v);
parser_error_t _readVecPalletPermissions_V6(parser_context_t* c, pd_VecPalletPermissions_V6_t* v);
parser_error_t _readVecPortfolioId_V6(parser_context_t* c, pd_VecPortfolioId_V6_t* v);
parser_error_t _readVecPriceTier_V6(parser_context_t* c, pd_VecPriceTier_V6_t* v);
parser_error_t _readVecReceiptDetails_V6(parser_context_t* c, pd_VecReceiptDetails_V6_t* v);
parser_error_t _readVecScopeId_V6(parser_context_t* c, pd_VecScopeId_V6_t* v);
parser_error_t _readVecSecondaryKeyWithAuth_V6(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V6_t* v);
parser_error_t _readVecSecondaryKey_V6(parser_context_t* c, pd_VecSecondaryKey_V6_t* v);
parser_error_t _readVecSignatory_V6(parser_context_t* c, pd_VecSignatory_V6_t* v);
parser_error_t _readVecTicker_V6(parser_context_t* c, pd_VecTicker_V6_t* v);
parser_error_t _readVecTrustedIssuer_V6(parser_context_t* c, pd_VecTrustedIssuer_V6_t* v);
parser_error_t _readVecTupleIdentityIdTax_V6(parser_context_t* c, pd_VecTupleIdentityIdTax_V6_t* v);
parser_error_t _readVecTupleIdentityIdbool_V6(parser_context_t* c, pd_VecTupleIdentityIdbool_V6_t* v);
parser_error_t _readVecTuplePipIdSnapshotResult_V6(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V6_t* v);
parser_error_t _readVecValidatorIndex_V6(parser_context_t* c, pd_VecValidatorIndex_V6_t* v);
parser_error_t _readVenueDetails_V6(parser_context_t* c, pd_VenueDetails_V6_t* v);
parser_error_t _readVenueType_V6(parser_context_t* c, pd_VenueType_V6_t* v);
parser_error_t _readWeight_V6(parser_context_t* c, pd_Weight_V6_t* v);

// toString functions
parser_error_t _toStringAccountId_V6(
    const pd_AccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V6(
    const pd_AccountIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdentifier_V6(
    const pd_AssetIdentifier_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetName_V6(
    const pd_AssetName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V6(
    const pd_AssetType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorizationData_V6(
    const pd_AuthorizationData_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotMeta_V6(
    const pd_BallotMeta_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTimeRange_V6(
    const pd_BallotTimeRange_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTitle_V6(
    const pd_BallotTitle_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotVote_V6(
    const pd_BallotVote_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBeneficiary_V6(
    const pd_Beneficiary_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeTx_V6(
    const pd_BridgeTx_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCADetails_V6(
    const pd_CADetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAId_V6(
    const pd_CAId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAKind_V6(
    const pd_CAKind_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarPeriod_V6(
    const pd_CalendarPeriod_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarUnit_V6(
    const pd_CalendarUnit_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCddId_V6(
    const pd_CddId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V6(
    const pd_ChangesTrieConfiguration_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCheckpointId_V6(
    const pd_CheckpointId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChoiceTitle_V6(
    const pd_ChoiceTitle_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaimType_V6(
    const pd_ClaimType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaim_V6(
    const pd_Claim_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassicTickerImport_V6(
    const pd_ClassicTickerImport_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash_V6(
    const pd_CodeHash_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V6(
    const pd_CompactAssignments_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V6(
    const pd_CompactEraIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactGas_V6(
    const pd_CompactGas_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V6(
    const pd_CompactMoment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V6(
    const pd_CompactPerBill_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringComplianceRequirement_V6(
    const pd_ComplianceRequirement_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConditionType_V6(
    const pd_ConditionType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCondition_V6(
    const pd_Condition_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCounter_V6(
    const pd_Counter_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCountryCode_V6(
    const pd_CountryCode_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableName_V6(
    const pd_DispatchableName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentHash_V6(
    const pd_DocumentHash_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentId_V6(
    const pd_DocumentId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentName_V6(
    const pd_DocumentName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentType_V6(
    const pd_DocumentType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentUri_V6(
    const pd_DocumentUri_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocument_V6(
    const pd_Document_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V6(
    const pd_EcdsaSignature_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V6(
    const pd_ElectionScore_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V6(
    const pd_ElectionSize_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEquivocationProof_V6(
    const pd_EquivocationProof_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V6(
    const pd_EraIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V6(
    const pd_EthereumAddress_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundingRoundName_V6(
    const pd_FundingRoundName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserName_V6(
    const pd_FundraiserName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityId_V6(
    const pd_IdentityId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorUid_V6(
    const pd_InvestorUid_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorZKProofData_V6(
    const pd_InvestorZKProofData_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V6(
    const pd_KeyOwnerProof_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V6(
    const pd_KeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V6(
    const pd_Key_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V6(
    const pd_Keys_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeg_V6(
    const pd_Leg_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPermissions_V6(
    const pd_LegacyPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLocalCAId_V6(
    const pd_LocalCAId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V6(
    const pd_LookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMaybeBlock_V6(
    const pd_MaybeBlock_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V6(
    const pd_MemberCount_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemo_V6(
    const pd_Memo_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaDescription_V6(
    const pd_MetaDescription_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaUrl_V6(
    const pd_MetaUrl_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaVersion_V6(
    const pd_MetaVersion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment_V6(
    const pd_Moment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionInfoLink_V6(
    const pd_MotionInfoLink_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionTitle_V6(
    const pd_MotionTitle_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotion_V6(
    const pd_Motion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMovePortfolioItem_V6(
    const pd_MovePortfolioItem_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffChainSignature_V6(
    const pd_OffChainSignature_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOfflineSlashingParams_V6(
    const pd_OfflineSlashingParams_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V6(
    const pd_OptionChangesTrieConfiguration_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionDocumentType_V6(
    const pd_OptionDocumentType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionFundingRoundName_V6(
    const pd_OptionFundingRoundName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMemo_V6(
    const pd_OptionMemo_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMetaUrl_V6(
    const pd_OptionMetaUrl_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMoment_V6(
    const pd_OptionMoment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V6(
    const pd_OptionPeriod_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPipDescription_V6(
    const pd_OptionPipDescription_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioNumber_V6(
    const pd_OptionPortfolioNumber_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptDetails_V6(
    const pd_OptionReceiptDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRecordDateSpec_V6(
    const pd_OptionRecordDateSpec_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTargetIdentities_V6(
    const pd_OptionTargetIdentities_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTax_V6(
    const pd_OptionTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionUrl_V6(
    const pd_OptionUrl_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecDispatchableName_V6(
    const pd_OptionVecDispatchableName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPalletPermissions_V6(
    const pd_OptionVecPalletPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPortfolioId_V6(
    const pd_OptionVecPortfolioId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTicker_V6(
    const pd_OptionVecTicker_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleIdentityIdTax_V6(
    const pd_OptionVecTupleIdentityIdTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVenueDetails_V6(
    const pd_OptionVenueDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVenueType_V6(
    const pd_OptionVenueType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletName_V6(
    const pd_PalletName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletPermissions_V6(
    const pd_PalletPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V6(
    const pd_Perbill_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V6(
    const pd_Percent_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercentage_V6(
    const pd_Percentage_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V6(
    const pd_Period_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermill_V6(
    const pd_Permill_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermissions_V6(
    const pd_Permissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipDescription_V6(
    const pd_PipDescription_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipId_V6(
    const pd_PipId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioId_V6(
    const pd_PortfolioId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioKind_V6(
    const pd_PortfolioKind_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioName_V6(
    const pd_PortfolioName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioNumber_V6(
    const pd_PortfolioNumber_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPosRatio_V6(
    const pd_PosRatio_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriceTier_V6(
    const pd_PriceTier_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V6(
    const pd_Priority_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposalIndex_V6(
    const pd_ProposalIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProtocolOp_V6(
    const pd_ProtocolOp_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptDetails_V6(
    const pd_ReceiptDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptMetadata_V6(
    const pd_ReceiptMetadata_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRecordDateSpec_V6(
    const pd_RecordDateSpec_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V6(
    const pd_RewardDestination_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleId_V6(
    const pd_ScheduleId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleSpec_V6(
    const pd_ScheduleSpec_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSchedule_V6(
    const pd_Schedule_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeId_V6(
    const pd_ScopeId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScope_V6(
    const pd_Scope_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyWithAuth_V6(
    const pd_SecondaryKeyWithAuth_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKey_V6(
    const pd_SecondaryKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSettlementType_V6(
    const pd_SettlementType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignatory_V6(
    const pd_Signatory_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V6(
    const pd_Signature_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSkippedCount_V6(
    const pd_SkippedCount_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSlashingSwitch_V6(
    const pd_SlashingSwitch_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtensionName_V6(
    const pd_SmartExtensionName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtensionType_V6(
    const pd_SmartExtensionType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtension_V6(
    const pd_SmartExtension_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSnapshotResult_V6(
    const pd_SnapshotResult_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V6(
    const pd_StreamDependency_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdAuthorization_V6(
    const pd_TargetIdAuthorization_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentities_V6(
    const pd_TargetIdentities_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentity_V6(
    const pd_TargetIdentity_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetTreatment_V6(
    const pd_TargetTreatment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTax_V6(
    const pd_Tax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTemplateMetadata_V6(
    const pd_TemplateMetadata_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTickerRegistrationConfig_V6(
    const pd_TickerRegistrationConfig_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTicker_V6(
    const pd_Ticker_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTransferManager_V6(
    const pd_TransferManager_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedFor_V6(
    const pd_TrustedFor_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedIssuer_V6(
    const pd_TrustedIssuer_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCountryCodeScope_V6(
    const pd_TupleCountryCodeScope_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdTax_V6(
    const pd_TupleIdentityIdTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdbool_V6(
    const pd_TupleIdentityIdbool_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePipIdSnapshotResult_V6(
    const pd_TuplePipIdSnapshotResult_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleScopeScopeIdCddId_V6(
    const pd_TupleScopeScopeIdCddId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUniqueCall_V6(
    const pd_UniqueCall_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUrl_V6(
    const pd_Url_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V6(
    const pd_ValidatorIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V6(
    const pd_ValidatorPrefs_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V6(
    const pd_VecAccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdentifier_V6(
    const pd_VecAssetIdentifier_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBallotVote_V6(
    const pd_VecBallotVote_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBeneficiary_V6(
    const pd_VecBeneficiary_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBridgeTx_V6(
    const pd_VecBridgeTx_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecChoiceTitle_V6(
    const pd_VecChoiceTitle_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaimType_V6(
    const pd_VecClaimType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaim_V6(
    const pd_VecClaim_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecComplianceRequirement_V6(
    const pd_VecComplianceRequirement_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCondition_V6(
    const pd_VecCondition_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDispatchableName_V6(
    const pd_VecDispatchableName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocumentId_V6(
    const pd_VecDocumentId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocument_V6(
    const pd_VecDocument_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecIdentityId_V6(
    const pd_VecIdentityId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V6(
    const pd_VecKeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V6(
    const pd_VecKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLeg_V6(
    const pd_VecLeg_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V6(
    const pd_VecLookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMotion_V6(
    const pd_VecMotion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMovePortfolioItem_V6(
    const pd_VecMovePortfolioItem_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPalletPermissions_V6(
    const pd_VecPalletPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPortfolioId_V6(
    const pd_VecPortfolioId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPriceTier_V6(
    const pd_VecPriceTier_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecReceiptDetails_V6(
    const pd_VecReceiptDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecScopeId_V6(
    const pd_VecScopeId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyWithAuth_V6(
    const pd_VecSecondaryKeyWithAuth_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKey_V6(
    const pd_VecSecondaryKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSignatory_V6(
    const pd_VecSignatory_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTicker_V6(
    const pd_VecTicker_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTrustedIssuer_V6(
    const pd_VecTrustedIssuer_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdTax_V6(
    const pd_VecTupleIdentityIdTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdbool_V6(
    const pd_VecTupleIdentityIdbool_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePipIdSnapshotResult_V6(
    const pd_VecTuplePipIdSnapshotResult_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V6(
    const pd_VecValidatorIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueDetails_V6(
    const pd_VenueDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueType_V6(
    const pd_VenueType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V6(
    const pd_Weight_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
