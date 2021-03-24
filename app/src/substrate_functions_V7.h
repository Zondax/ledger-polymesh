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
#include "substrate_methods_V7.h"
#include "substrate_types_V7.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAccountId_V7(parser_context_t* c, pd_AccountId_V7_t* v);
parser_error_t _readAccountIndex_V7(parser_context_t* c, pd_AccountIndex_V7_t* v);
parser_error_t _readAssetIdentifier_V7(parser_context_t* c, pd_AssetIdentifier_V7_t* v);
parser_error_t _readAssetName_V7(parser_context_t* c, pd_AssetName_V7_t* v);
parser_error_t _readAssetType_V7(parser_context_t* c, pd_AssetType_V7_t* v);
parser_error_t _readAuthorizationData_V7(parser_context_t* c, pd_AuthorizationData_V7_t* v);
parser_error_t _readBabeEquivocationProof_V7(parser_context_t* c, pd_BabeEquivocationProof_V7_t* v);
parser_error_t _readBallotMeta_V7(parser_context_t* c, pd_BallotMeta_V7_t* v);
parser_error_t _readBallotTimeRange_V7(parser_context_t* c, pd_BallotTimeRange_V7_t* v);
parser_error_t _readBallotTitle_V7(parser_context_t* c, pd_BallotTitle_V7_t* v);
parser_error_t _readBallotVote_V7(parser_context_t* c, pd_BallotVote_V7_t* v);
parser_error_t _readBeneficiary_V7(parser_context_t* c, pd_Beneficiary_V7_t* v);
parser_error_t _readBridgeTx_V7(parser_context_t* c, pd_BridgeTx_V7_t* v);
parser_error_t _readCADetails_V7(parser_context_t* c, pd_CADetails_V7_t* v);
parser_error_t _readCAId_V7(parser_context_t* c, pd_CAId_V7_t* v);
parser_error_t _readCAKind_V7(parser_context_t* c, pd_CAKind_V7_t* v);
parser_error_t _readCalendarPeriod_V7(parser_context_t* c, pd_CalendarPeriod_V7_t* v);
parser_error_t _readCalendarUnit_V7(parser_context_t* c, pd_CalendarUnit_V7_t* v);
parser_error_t _readCddId_V7(parser_context_t* c, pd_CddId_V7_t* v);
parser_error_t _readChangesTrieConfiguration_V7(parser_context_t* c, pd_ChangesTrieConfiguration_V7_t* v);
parser_error_t _readCheckpointId_V7(parser_context_t* c, pd_CheckpointId_V7_t* v);
parser_error_t _readChoiceTitle_V7(parser_context_t* c, pd_ChoiceTitle_V7_t* v);
parser_error_t _readClaimType_V7(parser_context_t* c, pd_ClaimType_V7_t* v);
parser_error_t _readClaim_V7(parser_context_t* c, pd_Claim_V7_t* v);
parser_error_t _readClassicTickerImport_V7(parser_context_t* c, pd_ClassicTickerImport_V7_t* v);
parser_error_t _readCodeHash_V7(parser_context_t* c, pd_CodeHash_V7_t* v);
parser_error_t _readCompactAssignments_V7(parser_context_t* c, pd_CompactAssignments_V7_t* v);
parser_error_t _readCompactEraIndex_V7(parser_context_t* c, pd_CompactEraIndex_V7_t* v);
parser_error_t _readCompactGas_V7(parser_context_t* c, pd_CompactGas_V7_t* v);
parser_error_t _readCompactMoment_V7(parser_context_t* c, pd_CompactMoment_V7_t* v);
parser_error_t _readCompactPerBill_V7(parser_context_t* c, pd_CompactPerBill_V7_t* v);
parser_error_t _readComplianceRequirement_V7(parser_context_t* c, pd_ComplianceRequirement_V7_t* v);
parser_error_t _readConditionType_V7(parser_context_t* c, pd_ConditionType_V7_t* v);
parser_error_t _readCondition_V7(parser_context_t* c, pd_Condition_V7_t* v);
parser_error_t _readCounter_V7(parser_context_t* c, pd_Counter_V7_t* v);
parser_error_t _readCountryCode_V7(parser_context_t* c, pd_CountryCode_V7_t* v);
parser_error_t _readDispatchableName_V7(parser_context_t* c, pd_DispatchableName_V7_t* v);
parser_error_t _readDocumentHash_V7(parser_context_t* c, pd_DocumentHash_V7_t* v);
parser_error_t _readDocumentId_V7(parser_context_t* c, pd_DocumentId_V7_t* v);
parser_error_t _readDocumentName_V7(parser_context_t* c, pd_DocumentName_V7_t* v);
parser_error_t _readDocumentType_V7(parser_context_t* c, pd_DocumentType_V7_t* v);
parser_error_t _readDocumentUri_V7(parser_context_t* c, pd_DocumentUri_V7_t* v);
parser_error_t _readDocument_V7(parser_context_t* c, pd_Document_V7_t* v);
parser_error_t _readEcdsaSignature_V7(parser_context_t* c, pd_EcdsaSignature_V7_t* v);
parser_error_t _readElectionScore_V7(parser_context_t* c, pd_ElectionScore_V7_t* v);
parser_error_t _readElectionSize_V7(parser_context_t* c, pd_ElectionSize_V7_t* v);
parser_error_t _readEraIndex_V7(parser_context_t* c, pd_EraIndex_V7_t* v);
parser_error_t _readEthereumAddress_V7(parser_context_t* c, pd_EthereumAddress_V7_t* v);
parser_error_t _readFundingRoundName_V7(parser_context_t* c, pd_FundingRoundName_V7_t* v);
parser_error_t _readFundraiserName_V7(parser_context_t* c, pd_FundraiserName_V7_t* v);
parser_error_t _readGrandpaEquivocationProof_V7(parser_context_t* c, pd_GrandpaEquivocationProof_V7_t* v);
parser_error_t _readIdentityId_V7(parser_context_t* c, pd_IdentityId_V7_t* v);
parser_error_t _readInvestorUid_V7(parser_context_t* c, pd_InvestorUid_V7_t* v);
parser_error_t _readInvestorZKProofData_V7(parser_context_t* c, pd_InvestorZKProofData_V7_t* v);
parser_error_t _readKeyOwnerProof_V7(parser_context_t* c, pd_KeyOwnerProof_V7_t* v);
parser_error_t _readKeyValue_V7(parser_context_t* c, pd_KeyValue_V7_t* v);
parser_error_t _readKey_V7(parser_context_t* c, pd_Key_V7_t* v);
parser_error_t _readKeys_V7(parser_context_t* c, pd_Keys_V7_t* v);
parser_error_t _readLeg_V7(parser_context_t* c, pd_Leg_V7_t* v);
parser_error_t _readLegacyPalletPermissions_V7(parser_context_t* c, pd_LegacyPalletPermissions_V7_t* v);
parser_error_t _readLegacyPermissions_V7(parser_context_t* c, pd_LegacyPermissions_V7_t* v);
parser_error_t _readLocalCAId_V7(parser_context_t* c, pd_LocalCAId_V7_t* v);
parser_error_t _readLookupSource_V7(parser_context_t* c, pd_LookupSource_V7_t* v);
parser_error_t _readMaybeBlock_V7(parser_context_t* c, pd_MaybeBlock_V7_t* v);
parser_error_t _readMemberCount_V7(parser_context_t* c, pd_MemberCount_V7_t* v);
parser_error_t _readMemo_V7(parser_context_t* c, pd_Memo_V7_t* v);
parser_error_t _readMetaDescription_V7(parser_context_t* c, pd_MetaDescription_V7_t* v);
parser_error_t _readMetaUrl_V7(parser_context_t* c, pd_MetaUrl_V7_t* v);
parser_error_t _readMetaVersion_V7(parser_context_t* c, pd_MetaVersion_V7_t* v);
parser_error_t _readMoment_V7(parser_context_t* c, pd_Moment_V7_t* v);
parser_error_t _readMotionInfoLink_V7(parser_context_t* c, pd_MotionInfoLink_V7_t* v);
parser_error_t _readMotionTitle_V7(parser_context_t* c, pd_MotionTitle_V7_t* v);
parser_error_t _readMotion_V7(parser_context_t* c, pd_Motion_V7_t* v);
parser_error_t _readMovePortfolioItem_V7(parser_context_t* c, pd_MovePortfolioItem_V7_t* v);
parser_error_t _readOffChainSignature_V7(parser_context_t* c, pd_OffChainSignature_V7_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V7(parser_context_t* c, pd_OptionChangesTrieConfiguration_V7_t* v);
parser_error_t _readOptionDocumentType_V7(parser_context_t* c, pd_OptionDocumentType_V7_t* v);
parser_error_t _readOptionFundingRoundName_V7(parser_context_t* c, pd_OptionFundingRoundName_V7_t* v);
parser_error_t _readOptionMemo_V7(parser_context_t* c, pd_OptionMemo_V7_t* v);
parser_error_t _readOptionMetaUrl_V7(parser_context_t* c, pd_OptionMetaUrl_V7_t* v);
parser_error_t _readOptionMoment_V7(parser_context_t* c, pd_OptionMoment_V7_t* v);
parser_error_t _readOptionPeriod_V7(parser_context_t* c, pd_OptionPeriod_V7_t* v);
parser_error_t _readOptionPipDescription_V7(parser_context_t* c, pd_OptionPipDescription_V7_t* v);
parser_error_t _readOptionPortfolioNumber_V7(parser_context_t* c, pd_OptionPortfolioNumber_V7_t* v);
parser_error_t _readOptionReceiptDetails_V7(parser_context_t* c, pd_OptionReceiptDetails_V7_t* v);
parser_error_t _readOptionRecordDateSpec_V7(parser_context_t* c, pd_OptionRecordDateSpec_V7_t* v);
parser_error_t _readOptionTargetIdentities_V7(parser_context_t* c, pd_OptionTargetIdentities_V7_t* v);
parser_error_t _readOptionTax_V7(parser_context_t* c, pd_OptionTax_V7_t* v);
parser_error_t _readOptionUrl_V7(parser_context_t* c, pd_OptionUrl_V7_t* v);
parser_error_t _readOptionVecDispatchableName_V7(parser_context_t* c, pd_OptionVecDispatchableName_V7_t* v);
parser_error_t _readOptionVecLegacyPalletPermissions_V7(parser_context_t* c, pd_OptionVecLegacyPalletPermissions_V7_t* v);
parser_error_t _readOptionVecPalletPermissions_V7(parser_context_t* c, pd_OptionVecPalletPermissions_V7_t* v);
parser_error_t _readOptionVecPortfolioId_V7(parser_context_t* c, pd_OptionVecPortfolioId_V7_t* v);
parser_error_t _readOptionVecTicker_V7(parser_context_t* c, pd_OptionVecTicker_V7_t* v);
parser_error_t _readOptionVecTupleIdentityIdTax_V7(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V7_t* v);
parser_error_t _readOptionVenueDetails_V7(parser_context_t* c, pd_OptionVenueDetails_V7_t* v);
parser_error_t _readOptionVenueType_V7(parser_context_t* c, pd_OptionVenueType_V7_t* v);
parser_error_t _readPalletName_V7(parser_context_t* c, pd_PalletName_V7_t* v);
parser_error_t _readPalletPermissions_V7(parser_context_t* c, pd_PalletPermissions_V7_t* v);
parser_error_t _readPerbill_V7(parser_context_t* c, pd_Perbill_V7_t* v);
parser_error_t _readPercent_V7(parser_context_t* c, pd_Percent_V7_t* v);
parser_error_t _readPercentage_V7(parser_context_t* c, pd_Percentage_V7_t* v);
parser_error_t _readPeriod_V7(parser_context_t* c, pd_Period_V7_t* v);
parser_error_t _readPermill_V7(parser_context_t* c, pd_Permill_V7_t* v);
parser_error_t _readPermissions_V7(parser_context_t* c, pd_Permissions_V7_t* v);
parser_error_t _readPipDescription_V7(parser_context_t* c, pd_PipDescription_V7_t* v);
parser_error_t _readPipId_V7(parser_context_t* c, pd_PipId_V7_t* v);
parser_error_t _readPortfolioId_V7(parser_context_t* c, pd_PortfolioId_V7_t* v);
parser_error_t _readPortfolioKind_V7(parser_context_t* c, pd_PortfolioKind_V7_t* v);
parser_error_t _readPortfolioName_V7(parser_context_t* c, pd_PortfolioName_V7_t* v);
parser_error_t _readPortfolioNumber_V7(parser_context_t* c, pd_PortfolioNumber_V7_t* v);
parser_error_t _readPosRatio_V7(parser_context_t* c, pd_PosRatio_V7_t* v);
parser_error_t _readPriceTier_V7(parser_context_t* c, pd_PriceTier_V7_t* v);
parser_error_t _readPriority_V7(parser_context_t* c, pd_Priority_V7_t* v);
parser_error_t _readProposalIndex_V7(parser_context_t* c, pd_ProposalIndex_V7_t* v);
parser_error_t _readProtocolOp_V7(parser_context_t* c, pd_ProtocolOp_V7_t* v);
parser_error_t _readReceiptDetails_V7(parser_context_t* c, pd_ReceiptDetails_V7_t* v);
parser_error_t _readReceiptMetadata_V7(parser_context_t* c, pd_ReceiptMetadata_V7_t* v);
parser_error_t _readRecordDateSpec_V7(parser_context_t* c, pd_RecordDateSpec_V7_t* v);
parser_error_t _readRewardDestination_V7(parser_context_t* c, pd_RewardDestination_V7_t* v);
parser_error_t _readScheduleId_V7(parser_context_t* c, pd_ScheduleId_V7_t* v);
parser_error_t _readScheduleSpec_V7(parser_context_t* c, pd_ScheduleSpec_V7_t* v);
parser_error_t _readSchedule_V7(parser_context_t* c, pd_Schedule_V7_t* v);
parser_error_t _readScopeClaimProof_V7(parser_context_t* c, pd_ScopeClaimProof_V7_t* v);
parser_error_t _readScopeId_V7(parser_context_t* c, pd_ScopeId_V7_t* v);
parser_error_t _readScope_V7(parser_context_t* c, pd_Scope_V7_t* v);
parser_error_t _readSecondaryKeyWithAuth_V7(parser_context_t* c, pd_SecondaryKeyWithAuth_V7_t* v);
parser_error_t _readSecondaryKey_V7(parser_context_t* c, pd_SecondaryKey_V7_t* v);
parser_error_t _readSettlementType_V7(parser_context_t* c, pd_SettlementType_V7_t* v);
parser_error_t _readSignatory_V7(parser_context_t* c, pd_Signatory_V7_t* v);
parser_error_t _readSignature_V7(parser_context_t* c, pd_Signature_V7_t* v);
parser_error_t _readSkippedCount_V7(parser_context_t* c, pd_SkippedCount_V7_t* v);
parser_error_t _readSlashingSwitch_V7(parser_context_t* c, pd_SlashingSwitch_V7_t* v);
parser_error_t _readSmartExtensionName_V7(parser_context_t* c, pd_SmartExtensionName_V7_t* v);
parser_error_t _readSmartExtensionType_V7(parser_context_t* c, pd_SmartExtensionType_V7_t* v);
parser_error_t _readSmartExtension_V7(parser_context_t* c, pd_SmartExtension_V7_t* v);
parser_error_t _readSnapshotResult_V7(parser_context_t* c, pd_SnapshotResult_V7_t* v);
parser_error_t _readStreamDependency_V7(parser_context_t* c, pd_StreamDependency_V7_t* v);
parser_error_t _readTargetIdAuthorization_V7(parser_context_t* c, pd_TargetIdAuthorization_V7_t* v);
parser_error_t _readTargetIdentities_V7(parser_context_t* c, pd_TargetIdentities_V7_t* v);
parser_error_t _readTargetIdentity_V7(parser_context_t* c, pd_TargetIdentity_V7_t* v);
parser_error_t _readTargetTreatment_V7(parser_context_t* c, pd_TargetTreatment_V7_t* v);
parser_error_t _readTax_V7(parser_context_t* c, pd_Tax_V7_t* v);
parser_error_t _readTemplateMetadata_V7(parser_context_t* c, pd_TemplateMetadata_V7_t* v);
parser_error_t _readTickerRegistrationConfig_V7(parser_context_t* c, pd_TickerRegistrationConfig_V7_t* v);
parser_error_t _readTicker_V7(parser_context_t* c, pd_Ticker_V7_t* v);
parser_error_t _readTransferManager_V7(parser_context_t* c, pd_TransferManager_V7_t* v);
parser_error_t _readTrustedFor_V7(parser_context_t* c, pd_TrustedFor_V7_t* v);
parser_error_t _readTrustedIssuer_V7(parser_context_t* c, pd_TrustedIssuer_V7_t* v);
parser_error_t _readTupleCountryCodeScope_V7(parser_context_t* c, pd_TupleCountryCodeScope_V7_t* v);
parser_error_t _readTupleIdentityIdTax_V7(parser_context_t* c, pd_TupleIdentityIdTax_V7_t* v);
parser_error_t _readTupleIdentityIdbool_V7(parser_context_t* c, pd_TupleIdentityIdbool_V7_t* v);
parser_error_t _readTuplePipIdSnapshotResult_V7(parser_context_t* c, pd_TuplePipIdSnapshotResult_V7_t* v);
parser_error_t _readTupleScopeScopeIdCddId_V7(parser_context_t* c, pd_TupleScopeScopeIdCddId_V7_t* v);
parser_error_t _readUniqueCall_V7(parser_context_t* c, pd_UniqueCall_V7_t* v);
parser_error_t _readUrl_V7(parser_context_t* c, pd_Url_V7_t* v);
parser_error_t _readValidatorIndex_V7(parser_context_t* c, pd_ValidatorIndex_V7_t* v);
parser_error_t _readValidatorPrefs_V7(parser_context_t* c, pd_ValidatorPrefs_V7_t* v);
parser_error_t _readVecAccountId_V7(parser_context_t* c, pd_VecAccountId_V7_t* v);
parser_error_t _readVecAssetIdentifier_V7(parser_context_t* c, pd_VecAssetIdentifier_V7_t* v);
parser_error_t _readVecBallotVote_V7(parser_context_t* c, pd_VecBallotVote_V7_t* v);
parser_error_t _readVecBeneficiary_V7(parser_context_t* c, pd_VecBeneficiary_V7_t* v);
parser_error_t _readVecBridgeTx_V7(parser_context_t* c, pd_VecBridgeTx_V7_t* v);
parser_error_t _readVecChoiceTitle_V7(parser_context_t* c, pd_VecChoiceTitle_V7_t* v);
parser_error_t _readVecClaimType_V7(parser_context_t* c, pd_VecClaimType_V7_t* v);
parser_error_t _readVecClaim_V7(parser_context_t* c, pd_VecClaim_V7_t* v);
parser_error_t _readVecComplianceRequirement_V7(parser_context_t* c, pd_VecComplianceRequirement_V7_t* v);
parser_error_t _readVecCondition_V7(parser_context_t* c, pd_VecCondition_V7_t* v);
parser_error_t _readVecDispatchableName_V7(parser_context_t* c, pd_VecDispatchableName_V7_t* v);
parser_error_t _readVecDocumentId_V7(parser_context_t* c, pd_VecDocumentId_V7_t* v);
parser_error_t _readVecDocument_V7(parser_context_t* c, pd_VecDocument_V7_t* v);
parser_error_t _readVecIdentityId_V7(parser_context_t* c, pd_VecIdentityId_V7_t* v);
parser_error_t _readVecKeyValue_V7(parser_context_t* c, pd_VecKeyValue_V7_t* v);
parser_error_t _readVecKey_V7(parser_context_t* c, pd_VecKey_V7_t* v);
parser_error_t _readVecLeg_V7(parser_context_t* c, pd_VecLeg_V7_t* v);
parser_error_t _readVecLegacyPalletPermissions_V7(parser_context_t* c, pd_VecLegacyPalletPermissions_V7_t* v);
parser_error_t _readVecLookupSource_V7(parser_context_t* c, pd_VecLookupSource_V7_t* v);
parser_error_t _readVecMotion_V7(parser_context_t* c, pd_VecMotion_V7_t* v);
parser_error_t _readVecMovePortfolioItem_V7(parser_context_t* c, pd_VecMovePortfolioItem_V7_t* v);
parser_error_t _readVecPalletPermissions_V7(parser_context_t* c, pd_VecPalletPermissions_V7_t* v);
parser_error_t _readVecPortfolioId_V7(parser_context_t* c, pd_VecPortfolioId_V7_t* v);
parser_error_t _readVecPriceTier_V7(parser_context_t* c, pd_VecPriceTier_V7_t* v);
parser_error_t _readVecReceiptDetails_V7(parser_context_t* c, pd_VecReceiptDetails_V7_t* v);
parser_error_t _readVecScopeId_V7(parser_context_t* c, pd_VecScopeId_V7_t* v);
parser_error_t _readVecSecondaryKeyWithAuth_V7(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V7_t* v);
parser_error_t _readVecSecondaryKey_V7(parser_context_t* c, pd_VecSecondaryKey_V7_t* v);
parser_error_t _readVecSignatory_V7(parser_context_t* c, pd_VecSignatory_V7_t* v);
parser_error_t _readVecTicker_V7(parser_context_t* c, pd_VecTicker_V7_t* v);
parser_error_t _readVecTrustedIssuer_V7(parser_context_t* c, pd_VecTrustedIssuer_V7_t* v);
parser_error_t _readVecTupleIdentityIdTax_V7(parser_context_t* c, pd_VecTupleIdentityIdTax_V7_t* v);
parser_error_t _readVecTupleIdentityIdbool_V7(parser_context_t* c, pd_VecTupleIdentityIdbool_V7_t* v);
parser_error_t _readVecTuplePipIdSnapshotResult_V7(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V7_t* v);
parser_error_t _readVecValidatorIndex_V7(parser_context_t* c, pd_VecValidatorIndex_V7_t* v);
parser_error_t _readVenueDetails_V7(parser_context_t* c, pd_VenueDetails_V7_t* v);
parser_error_t _readVenueType_V7(parser_context_t* c, pd_VenueType_V7_t* v);
parser_error_t _readWeight_V7(parser_context_t* c, pd_Weight_V7_t* v);

// toString functions
parser_error_t _toStringAccountId_V7(
    const pd_AccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V7(
    const pd_AccountIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdentifier_V7(
    const pd_AssetIdentifier_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetName_V7(
    const pd_AssetName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V7(
    const pd_AssetType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorizationData_V7(
    const pd_AuthorizationData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBabeEquivocationProof_V7(
    const pd_BabeEquivocationProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotMeta_V7(
    const pd_BallotMeta_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTimeRange_V7(
    const pd_BallotTimeRange_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTitle_V7(
    const pd_BallotTitle_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotVote_V7(
    const pd_BallotVote_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBeneficiary_V7(
    const pd_Beneficiary_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeTx_V7(
    const pd_BridgeTx_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCADetails_V7(
    const pd_CADetails_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAId_V7(
    const pd_CAId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAKind_V7(
    const pd_CAKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarPeriod_V7(
    const pd_CalendarPeriod_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarUnit_V7(
    const pd_CalendarUnit_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCddId_V7(
    const pd_CddId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V7(
    const pd_ChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCheckpointId_V7(
    const pd_CheckpointId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChoiceTitle_V7(
    const pd_ChoiceTitle_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaimType_V7(
    const pd_ClaimType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaim_V7(
    const pd_Claim_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassicTickerImport_V7(
    const pd_ClassicTickerImport_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash_V7(
    const pd_CodeHash_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V7(
    const pd_CompactAssignments_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V7(
    const pd_CompactEraIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactGas_V7(
    const pd_CompactGas_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V7(
    const pd_CompactMoment_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V7(
    const pd_CompactPerBill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringComplianceRequirement_V7(
    const pd_ComplianceRequirement_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConditionType_V7(
    const pd_ConditionType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCondition_V7(
    const pd_Condition_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCounter_V7(
    const pd_Counter_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCountryCode_V7(
    const pd_CountryCode_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableName_V7(
    const pd_DispatchableName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentHash_V7(
    const pd_DocumentHash_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentId_V7(
    const pd_DocumentId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentName_V7(
    const pd_DocumentName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentType_V7(
    const pd_DocumentType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentUri_V7(
    const pd_DocumentUri_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocument_V7(
    const pd_Document_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V7(
    const pd_EcdsaSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V7(
    const pd_ElectionScore_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V7(
    const pd_ElectionSize_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V7(
    const pd_EraIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V7(
    const pd_EthereumAddress_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundingRoundName_V7(
    const pd_FundingRoundName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserName_V7(
    const pd_FundraiserName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGrandpaEquivocationProof_V7(
    const pd_GrandpaEquivocationProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityId_V7(
    const pd_IdentityId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorUid_V7(
    const pd_InvestorUid_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorZKProofData_V7(
    const pd_InvestorZKProofData_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V7(
    const pd_KeyOwnerProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V7(
    const pd_KeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V7(
    const pd_Key_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V7(
    const pd_Keys_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeg_V7(
    const pd_Leg_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPalletPermissions_V7(
    const pd_LegacyPalletPermissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPermissions_V7(
    const pd_LegacyPermissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLocalCAId_V7(
    const pd_LocalCAId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V7(
    const pd_LookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMaybeBlock_V7(
    const pd_MaybeBlock_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V7(
    const pd_MemberCount_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemo_V7(
    const pd_Memo_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaDescription_V7(
    const pd_MetaDescription_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaUrl_V7(
    const pd_MetaUrl_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMetaVersion_V7(
    const pd_MetaVersion_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment_V7(
    const pd_Moment_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionInfoLink_V7(
    const pd_MotionInfoLink_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionTitle_V7(
    const pd_MotionTitle_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotion_V7(
    const pd_Motion_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMovePortfolioItem_V7(
    const pd_MovePortfolioItem_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffChainSignature_V7(
    const pd_OffChainSignature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V7(
    const pd_OptionChangesTrieConfiguration_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionDocumentType_V7(
    const pd_OptionDocumentType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionFundingRoundName_V7(
    const pd_OptionFundingRoundName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMemo_V7(
    const pd_OptionMemo_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMetaUrl_V7(
    const pd_OptionMetaUrl_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMoment_V7(
    const pd_OptionMoment_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V7(
    const pd_OptionPeriod_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPipDescription_V7(
    const pd_OptionPipDescription_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioNumber_V7(
    const pd_OptionPortfolioNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptDetails_V7(
    const pd_OptionReceiptDetails_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRecordDateSpec_V7(
    const pd_OptionRecordDateSpec_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTargetIdentities_V7(
    const pd_OptionTargetIdentities_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTax_V7(
    const pd_OptionTax_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionUrl_V7(
    const pd_OptionUrl_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecDispatchableName_V7(
    const pd_OptionVecDispatchableName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecLegacyPalletPermissions_V7(
    const pd_OptionVecLegacyPalletPermissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPalletPermissions_V7(
    const pd_OptionVecPalletPermissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPortfolioId_V7(
    const pd_OptionVecPortfolioId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTicker_V7(
    const pd_OptionVecTicker_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleIdentityIdTax_V7(
    const pd_OptionVecTupleIdentityIdTax_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVenueDetails_V7(
    const pd_OptionVenueDetails_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVenueType_V7(
    const pd_OptionVenueType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletName_V7(
    const pd_PalletName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletPermissions_V7(
    const pd_PalletPermissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V7(
    const pd_Perbill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V7(
    const pd_Percent_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercentage_V7(
    const pd_Percentage_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V7(
    const pd_Period_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermill_V7(
    const pd_Permill_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermissions_V7(
    const pd_Permissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipDescription_V7(
    const pd_PipDescription_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipId_V7(
    const pd_PipId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioId_V7(
    const pd_PortfolioId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioKind_V7(
    const pd_PortfolioKind_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioName_V7(
    const pd_PortfolioName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioNumber_V7(
    const pd_PortfolioNumber_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPosRatio_V7(
    const pd_PosRatio_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriceTier_V7(
    const pd_PriceTier_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V7(
    const pd_Priority_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposalIndex_V7(
    const pd_ProposalIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProtocolOp_V7(
    const pd_ProtocolOp_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptDetails_V7(
    const pd_ReceiptDetails_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptMetadata_V7(
    const pd_ReceiptMetadata_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRecordDateSpec_V7(
    const pd_RecordDateSpec_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V7(
    const pd_RewardDestination_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleId_V7(
    const pd_ScheduleId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleSpec_V7(
    const pd_ScheduleSpec_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSchedule_V7(
    const pd_Schedule_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeClaimProof_V7(
    const pd_ScopeClaimProof_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeId_V7(
    const pd_ScopeId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScope_V7(
    const pd_Scope_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyWithAuth_V7(
    const pd_SecondaryKeyWithAuth_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKey_V7(
    const pd_SecondaryKey_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSettlementType_V7(
    const pd_SettlementType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignatory_V7(
    const pd_Signatory_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V7(
    const pd_Signature_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSkippedCount_V7(
    const pd_SkippedCount_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSlashingSwitch_V7(
    const pd_SlashingSwitch_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtensionName_V7(
    const pd_SmartExtensionName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtensionType_V7(
    const pd_SmartExtensionType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSmartExtension_V7(
    const pd_SmartExtension_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSnapshotResult_V7(
    const pd_SnapshotResult_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V7(
    const pd_StreamDependency_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdAuthorization_V7(
    const pd_TargetIdAuthorization_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentities_V7(
    const pd_TargetIdentities_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentity_V7(
    const pd_TargetIdentity_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetTreatment_V7(
    const pd_TargetTreatment_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTax_V7(
    const pd_Tax_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTemplateMetadata_V7(
    const pd_TemplateMetadata_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTickerRegistrationConfig_V7(
    const pd_TickerRegistrationConfig_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTicker_V7(
    const pd_Ticker_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTransferManager_V7(
    const pd_TransferManager_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedFor_V7(
    const pd_TrustedFor_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedIssuer_V7(
    const pd_TrustedIssuer_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCountryCodeScope_V7(
    const pd_TupleCountryCodeScope_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdTax_V7(
    const pd_TupleIdentityIdTax_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdbool_V7(
    const pd_TupleIdentityIdbool_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePipIdSnapshotResult_V7(
    const pd_TuplePipIdSnapshotResult_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleScopeScopeIdCddId_V7(
    const pd_TupleScopeScopeIdCddId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUniqueCall_V7(
    const pd_UniqueCall_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUrl_V7(
    const pd_Url_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V7(
    const pd_ValidatorIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V7(
    const pd_ValidatorPrefs_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V7(
    const pd_VecAccountId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdentifier_V7(
    const pd_VecAssetIdentifier_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBallotVote_V7(
    const pd_VecBallotVote_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBeneficiary_V7(
    const pd_VecBeneficiary_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBridgeTx_V7(
    const pd_VecBridgeTx_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecChoiceTitle_V7(
    const pd_VecChoiceTitle_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaimType_V7(
    const pd_VecClaimType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaim_V7(
    const pd_VecClaim_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecComplianceRequirement_V7(
    const pd_VecComplianceRequirement_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCondition_V7(
    const pd_VecCondition_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDispatchableName_V7(
    const pd_VecDispatchableName_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocumentId_V7(
    const pd_VecDocumentId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocument_V7(
    const pd_VecDocument_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecIdentityId_V7(
    const pd_VecIdentityId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V7(
    const pd_VecKeyValue_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V7(
    const pd_VecKey_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLeg_V7(
    const pd_VecLeg_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLegacyPalletPermissions_V7(
    const pd_VecLegacyPalletPermissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V7(
    const pd_VecLookupSource_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMotion_V7(
    const pd_VecMotion_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMovePortfolioItem_V7(
    const pd_VecMovePortfolioItem_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPalletPermissions_V7(
    const pd_VecPalletPermissions_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPortfolioId_V7(
    const pd_VecPortfolioId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPriceTier_V7(
    const pd_VecPriceTier_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecReceiptDetails_V7(
    const pd_VecReceiptDetails_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecScopeId_V7(
    const pd_VecScopeId_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyWithAuth_V7(
    const pd_VecSecondaryKeyWithAuth_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKey_V7(
    const pd_VecSecondaryKey_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSignatory_V7(
    const pd_VecSignatory_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTicker_V7(
    const pd_VecTicker_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTrustedIssuer_V7(
    const pd_VecTrustedIssuer_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdTax_V7(
    const pd_VecTupleIdentityIdTax_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdbool_V7(
    const pd_VecTupleIdentityIdbool_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePipIdSnapshotResult_V7(
    const pd_VecTuplePipIdSnapshotResult_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V7(
    const pd_VecValidatorIndex_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueDetails_V7(
    const pd_VenueDetails_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueType_V7(
    const pd_VenueType_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V7(
    const pd_Weight_V7_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
