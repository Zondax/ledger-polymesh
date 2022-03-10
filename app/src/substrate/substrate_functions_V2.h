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
#include "substrate_methods_V2.h"
#include "substrate_types_V2.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAGId_V2(parser_context_t* c, pd_AGId_V2_t* v);
parser_error_t _readAccountId_V2(parser_context_t* c, pd_AccountId_V2_t* v);
parser_error_t _readAccountIndex_V2(parser_context_t* c, pd_AccountIndex_V2_t* v);
parser_error_t _readAddRelayerPayingKey_V2(parser_context_t* c, pd_AddRelayerPayingKey_V2_t* v);
parser_error_t _readAgentGroup_V2(parser_context_t* c, pd_AgentGroup_V2_t* v);
parser_error_t _readAssetIdentifier_V2(parser_context_t* c, pd_AssetIdentifier_V2_t* v);
parser_error_t _readAssetName_V2(parser_context_t* c, pd_AssetName_V2_t* v);
parser_error_t _readAssetPermissions_V2(parser_context_t* c, pd_AssetPermissions_V2_t* v);
parser_error_t _readAssetType_V2(parser_context_t* c, pd_AssetType_V2_t* v);
parser_error_t _readAuthorizationData_V2(parser_context_t* c, pd_AuthorizationData_V2_t* v);
parser_error_t _readBabeEquivocationProof_V2(parser_context_t* c, pd_BabeEquivocationProof_V2_t* v);
parser_error_t _readBallotMeta_V2(parser_context_t* c, pd_BallotMeta_V2_t* v);
parser_error_t _readBallotTimeRange_V2(parser_context_t* c, pd_BallotTimeRange_V2_t* v);
parser_error_t _readBallotTitle_V2(parser_context_t* c, pd_BallotTitle_V2_t* v);
parser_error_t _readBallotVote_V2(parser_context_t* c, pd_BallotVote_V2_t* v);
parser_error_t _readBecomeAgent_V2(parser_context_t* c, pd_BecomeAgent_V2_t* v);
parser_error_t _readBeneficiary_V2(parser_context_t* c, pd_Beneficiary_V2_t* v);
parser_error_t _readBridgeTx_V2(parser_context_t* c, pd_BridgeTx_V2_t* v);
parser_error_t _readCADetails_V2(parser_context_t* c, pd_CADetails_V2_t* v);
parser_error_t _readCAId_V2(parser_context_t* c, pd_CAId_V2_t* v);
parser_error_t _readCAKind_V2(parser_context_t* c, pd_CAKind_V2_t* v);
parser_error_t _readCalendarPeriod_V2(parser_context_t* c, pd_CalendarPeriod_V2_t* v);
parser_error_t _readCalendarUnit_V2(parser_context_t* c, pd_CalendarUnit_V2_t* v);
parser_error_t _readCddId_V2(parser_context_t* c, pd_CddId_V2_t* v);
parser_error_t _readChangesTrieConfiguration_V2(parser_context_t* c, pd_ChangesTrieConfiguration_V2_t* v);
parser_error_t _readCheckpointId_V2(parser_context_t* c, pd_CheckpointId_V2_t* v);
parser_error_t _readChoiceTitle_V2(parser_context_t* c, pd_ChoiceTitle_V2_t* v);
parser_error_t _readClaimType_V2(parser_context_t* c, pd_ClaimType_V2_t* v);
parser_error_t _readClaim_V2(parser_context_t* c, pd_Claim_V2_t* v);
parser_error_t _readClassicTickerImport_V2(parser_context_t* c, pd_ClassicTickerImport_V2_t* v);
parser_error_t _readCompactAccountIndex_V2(parser_context_t* c, pd_CompactAccountIndex_V2_t* v);
parser_error_t _readCompactAssignments_V2(parser_context_t* c, pd_CompactAssignments_V2_t* v);
parser_error_t _readCompactEraIndex_V2(parser_context_t* c, pd_CompactEraIndex_V2_t* v);
parser_error_t _readCompactMoment_V2(parser_context_t* c, pd_CompactMoment_V2_t* v);
parser_error_t _readCompactPerBill_V2(parser_context_t* c, pd_CompactPerBill_V2_t* v);
parser_error_t _readComplianceRequirement_V2(parser_context_t* c, pd_ComplianceRequirement_V2_t* v);
parser_error_t _readConditionType_V2(parser_context_t* c, pd_ConditionType_V2_t* v);
parser_error_t _readCondition_V2(parser_context_t* c, pd_Condition_V2_t* v);
parser_error_t _readCounter_V2(parser_context_t* c, pd_Counter_V2_t* v);
parser_error_t _readCountryCode_V2(parser_context_t* c, pd_CountryCode_V2_t* v);
parser_error_t _readCustomAssetTypeId_V2(parser_context_t* c, pd_CustomAssetTypeId_V2_t* v);
parser_error_t _readDispatchableName_V2(parser_context_t* c, pd_DispatchableName_V2_t* v);
parser_error_t _readDispatchableNames_V2(parser_context_t* c, pd_DispatchableNames_V2_t* v);
parser_error_t _readDocumentHash_V2(parser_context_t* c, pd_DocumentHash_V2_t* v);
parser_error_t _readDocumentId_V2(parser_context_t* c, pd_DocumentId_V2_t* v);
parser_error_t _readDocumentName_V2(parser_context_t* c, pd_DocumentName_V2_t* v);
parser_error_t _readDocumentType_V2(parser_context_t* c, pd_DocumentType_V2_t* v);
parser_error_t _readDocumentUri_V2(parser_context_t* c, pd_DocumentUri_V2_t* v);
parser_error_t _readDocument_V2(parser_context_t* c, pd_Document_V2_t* v);
parser_error_t _readEcdsaSignature_V2(parser_context_t* c, pd_EcdsaSignature_V2_t* v);
parser_error_t _readElectionScore_V2(parser_context_t* c, pd_ElectionScore_V2_t* v);
parser_error_t _readElectionSize_V2(parser_context_t* c, pd_ElectionSize_V2_t* v);
parser_error_t _readEraIndex_V2(parser_context_t* c, pd_EraIndex_V2_t* v);
parser_error_t _readEthereumAddress_V2(parser_context_t* c, pd_EthereumAddress_V2_t* v);
parser_error_t _readExtrinsicPermissions_V2(parser_context_t* c, pd_ExtrinsicPermissions_V2_t* v);
parser_error_t _readFundingRoundName_V2(parser_context_t* c, pd_FundingRoundName_V2_t* v);
parser_error_t _readFundraiserId_V2(parser_context_t* c, pd_FundraiserId_V2_t* v);
parser_error_t _readFundraiserName_V2(parser_context_t* c, pd_FundraiserName_V2_t* v);
parser_error_t _readGrandpaEquivocationProof_V2(parser_context_t* c, pd_GrandpaEquivocationProof_V2_t* v);
parser_error_t _readIdentityId_V2(parser_context_t* c, pd_IdentityId_V2_t* v);
parser_error_t _readInstructionId_V2(parser_context_t* c, pd_InstructionId_V2_t* v);
parser_error_t _readInvestorUid_V2(parser_context_t* c, pd_InvestorUid_V2_t* v);
parser_error_t _readInvestorZKProofData_V2(parser_context_t* c, pd_InvestorZKProofData_V2_t* v);
parser_error_t _readItnRewardStatus_V2(parser_context_t* c, pd_ItnRewardStatus_V2_t* v);
parser_error_t _readKeyOwnerProof_V2(parser_context_t* c, pd_KeyOwnerProof_V2_t* v);
parser_error_t _readKeyValue_V2(parser_context_t* c, pd_KeyValue_V2_t* v);
parser_error_t _readKey_V2(parser_context_t* c, pd_Key_V2_t* v);
parser_error_t _readKeys_V2(parser_context_t* c, pd_Keys_V2_t* v);
parser_error_t _readLegId_V2(parser_context_t* c, pd_LegId_V2_t* v);
parser_error_t _readLeg_V2(parser_context_t* c, pd_Leg_V2_t* v);
parser_error_t _readLegacyPalletPermissions_V2(parser_context_t* c, pd_LegacyPalletPermissions_V2_t* v);
parser_error_t _readLegacyPermissions_V2(parser_context_t* c, pd_LegacyPermissions_V2_t* v);
parser_error_t _readLocalCAId_V2(parser_context_t* c, pd_LocalCAId_V2_t* v);
parser_error_t _readLookupSource_V2(parser_context_t* c, pd_LookupSource_V2_t* v);
parser_error_t _readMaybeBlock_V2(parser_context_t* c, pd_MaybeBlock_V2_t* v);
parser_error_t _readMemberCount_V2(parser_context_t* c, pd_MemberCount_V2_t* v);
parser_error_t _readMemo_V2(parser_context_t* c, pd_Memo_V2_t* v);
parser_error_t _readMoment_V2(parser_context_t* c, pd_Moment_V2_t* v);
parser_error_t _readMotionInfoLink_V2(parser_context_t* c, pd_MotionInfoLink_V2_t* v);
parser_error_t _readMotionTitle_V2(parser_context_t* c, pd_MotionTitle_V2_t* v);
parser_error_t _readMotion_V2(parser_context_t* c, pd_Motion_V2_t* v);
parser_error_t _readMovePortfolioItem_V2(parser_context_t* c, pd_MovePortfolioItem_V2_t* v);
parser_error_t _readOffChainSignature_V2(parser_context_t* c, pd_OffChainSignature_V2_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V2(parser_context_t* c, pd_OptionChangesTrieConfiguration_V2_t* v);
parser_error_t _readOptionDocumentType_V2(parser_context_t* c, pd_OptionDocumentType_V2_t* v);
parser_error_t _readOptionFundingRoundName_V2(parser_context_t* c, pd_OptionFundingRoundName_V2_t* v);
parser_error_t _readOptionMemo_V2(parser_context_t* c, pd_OptionMemo_V2_t* v);
parser_error_t _readOptionMoment_V2(parser_context_t* c, pd_OptionMoment_V2_t* v);
parser_error_t _readOptionPeriod_V2(parser_context_t* c, pd_OptionPeriod_V2_t* v);
parser_error_t _readOptionPipDescription_V2(parser_context_t* c, pd_OptionPipDescription_V2_t* v);
parser_error_t _readOptionPortfolioNumber_V2(parser_context_t* c, pd_OptionPortfolioNumber_V2_t* v);
parser_error_t _readOptionReceiptDetails_V2(parser_context_t* c, pd_OptionReceiptDetails_V2_t* v);
parser_error_t _readOptionRecordDateSpec_V2(parser_context_t* c, pd_OptionRecordDateSpec_V2_t* v);
parser_error_t _readOptionScope_V2(parser_context_t* c, pd_OptionScope_V2_t* v);
parser_error_t _readOptionTargetIdentities_V2(parser_context_t* c, pd_OptionTargetIdentities_V2_t* v);
parser_error_t _readOptionTax_V2(parser_context_t* c, pd_OptionTax_V2_t* v);
parser_error_t _readOptionUrl_V2(parser_context_t* c, pd_OptionUrl_V2_t* v);
parser_error_t _readOptionVecLegacyPalletPermissions_V2(parser_context_t* c, pd_OptionVecLegacyPalletPermissions_V2_t* v);
parser_error_t _readOptionVecPortfolioId_V2(parser_context_t* c, pd_OptionVecPortfolioId_V2_t* v);
parser_error_t _readOptionVecTicker_V2(parser_context_t* c, pd_OptionVecTicker_V2_t* v);
parser_error_t _readOptionVecTupleIdentityIdTax_V2(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V2_t* v);
parser_error_t _readPalletName_V2(parser_context_t* c, pd_PalletName_V2_t* v);
parser_error_t _readPalletPermissions_V2(parser_context_t* c, pd_PalletPermissions_V2_t* v);
parser_error_t _readPerbill_V2(parser_context_t* c, pd_Perbill_V2_t* v);
parser_error_t _readPercent_V2(parser_context_t* c, pd_Percent_V2_t* v);
parser_error_t _readPercentage_V2(parser_context_t* c, pd_Percentage_V2_t* v);
parser_error_t _readPeriod_V2(parser_context_t* c, pd_Period_V2_t* v);
parser_error_t _readPermill_V2(parser_context_t* c, pd_Permill_V2_t* v);
parser_error_t _readPermissions_V2(parser_context_t* c, pd_Permissions_V2_t* v);
parser_error_t _readPipDescription_V2(parser_context_t* c, pd_PipDescription_V2_t* v);
parser_error_t _readPipId_V2(parser_context_t* c, pd_PipId_V2_t* v);
parser_error_t _readPortfolioId_V2(parser_context_t* c, pd_PortfolioId_V2_t* v);
parser_error_t _readPortfolioKind_V2(parser_context_t* c, pd_PortfolioKind_V2_t* v);
parser_error_t _readPortfolioName_V2(parser_context_t* c, pd_PortfolioName_V2_t* v);
parser_error_t _readPortfolioNumber_V2(parser_context_t* c, pd_PortfolioNumber_V2_t* v);
parser_error_t _readPortfolioPermissions_V2(parser_context_t* c, pd_PortfolioPermissions_V2_t* v);
parser_error_t _readPosRatio_V2(parser_context_t* c, pd_PosRatio_V2_t* v);
parser_error_t _readPriceTier_V2(parser_context_t* c, pd_PriceTier_V2_t* v);
parser_error_t _readPriority_V2(parser_context_t* c, pd_Priority_V2_t* v);
parser_error_t _readProposalIndex_V2(parser_context_t* c, pd_ProposalIndex_V2_t* v);
parser_error_t _readProtocolOp_V2(parser_context_t* c, pd_ProtocolOp_V2_t* v);
parser_error_t _readReceiptDetails_V2(parser_context_t* c, pd_ReceiptDetails_V2_t* v);
parser_error_t _readReceiptMetadata_V2(parser_context_t* c, pd_ReceiptMetadata_V2_t* v);
parser_error_t _readRecordDateSpec_V2(parser_context_t* c, pd_RecordDateSpec_V2_t* v);
parser_error_t _readRewardDestination_V2(parser_context_t* c, pd_RewardDestination_V2_t* v);
parser_error_t _readScheduleId_V2(parser_context_t* c, pd_ScheduleId_V2_t* v);
parser_error_t _readScheduleSpec_V2(parser_context_t* c, pd_ScheduleSpec_V2_t* v);
parser_error_t _readScopeClaimProof_V2(parser_context_t* c, pd_ScopeClaimProof_V2_t* v);
parser_error_t _readScopeId_V2(parser_context_t* c, pd_ScopeId_V2_t* v);
parser_error_t _readScope_V2(parser_context_t* c, pd_Scope_V2_t* v);
parser_error_t _readSecondaryKeyWithAuth_V2(parser_context_t* c, pd_SecondaryKeyWithAuth_V2_t* v);
parser_error_t _readSecondaryKey_V2(parser_context_t* c, pd_SecondaryKey_V2_t* v);
parser_error_t _readSettlementType_V2(parser_context_t* c, pd_SettlementType_V2_t* v);
parser_error_t _readSignatory_V2(parser_context_t* c, pd_Signatory_V2_t* v);
parser_error_t _readSignature_V2(parser_context_t* c, pd_Signature_V2_t* v);
parser_error_t _readSkippedCount_V2(parser_context_t* c, pd_SkippedCount_V2_t* v);
parser_error_t _readSlashingSwitch_V2(parser_context_t* c, pd_SlashingSwitch_V2_t* v);
parser_error_t _readSnapshotResult_V2(parser_context_t* c, pd_SnapshotResult_V2_t* v);
parser_error_t _readStreamDependency_V2(parser_context_t* c, pd_StreamDependency_V2_t* v);
parser_error_t _readTargetIdentities_V2(parser_context_t* c, pd_TargetIdentities_V2_t* v);
parser_error_t _readTargetIdentity_V2(parser_context_t* c, pd_TargetIdentity_V2_t* v);
parser_error_t _readTargetTreatment_V2(parser_context_t* c, pd_TargetTreatment_V2_t* v);
parser_error_t _readTax_V2(parser_context_t* c, pd_Tax_V2_t* v);
parser_error_t _readTickerRegistrationConfig_V2(parser_context_t* c, pd_TickerRegistrationConfig_V2_t* v);
parser_error_t _readTicker_V2(parser_context_t* c, pd_Ticker_V2_t* v);
parser_error_t _readTransferManager_V2(parser_context_t* c, pd_TransferManager_V2_t* v);
parser_error_t _readTrustedFor_V2(parser_context_t* c, pd_TrustedFor_V2_t* v);
parser_error_t _readTrustedIssuer_V2(parser_context_t* c, pd_TrustedIssuer_V2_t* v);
parser_error_t _readTupleCountryCodeScope_V2(parser_context_t* c, pd_TupleCountryCodeScope_V2_t* v);
parser_error_t _readTupleIdentityIdTax_V2(parser_context_t* c, pd_TupleIdentityIdTax_V2_t* v);
parser_error_t _readTupleIdentityIdbool_V2(parser_context_t* c, pd_TupleIdentityIdbool_V2_t* v);
parser_error_t _readTuplePipIdSnapshotResult_V2(parser_context_t* c, pd_TuplePipIdSnapshotResult_V2_t* v);
parser_error_t _readTupleScopeScopeIdCddId_V2(parser_context_t* c, pd_TupleScopeScopeIdCddId_V2_t* v);
parser_error_t _readUniqueCall_V2(parser_context_t* c, pd_UniqueCall_V2_t* v);
parser_error_t _readUrl_V2(parser_context_t* c, pd_Url_V2_t* v);
parser_error_t _readValidatorIndex_V2(parser_context_t* c, pd_ValidatorIndex_V2_t* v);
parser_error_t _readValidatorPrefs_V2(parser_context_t* c, pd_ValidatorPrefs_V2_t* v);
parser_error_t _readVecAccountId_V2(parser_context_t* c, pd_VecAccountId_V2_t* v);
parser_error_t _readVecAssetIdentifier_V2(parser_context_t* c, pd_VecAssetIdentifier_V2_t* v);
parser_error_t _readVecBallotVote_V2(parser_context_t* c, pd_VecBallotVote_V2_t* v);
parser_error_t _readVecBeneficiary_V2(parser_context_t* c, pd_VecBeneficiary_V2_t* v);
parser_error_t _readVecBridgeTx_V2(parser_context_t* c, pd_VecBridgeTx_V2_t* v);
parser_error_t _readVecChoiceTitle_V2(parser_context_t* c, pd_VecChoiceTitle_V2_t* v);
parser_error_t _readVecClaimType_V2(parser_context_t* c, pd_VecClaimType_V2_t* v);
parser_error_t _readVecClaim_V2(parser_context_t* c, pd_VecClaim_V2_t* v);
parser_error_t _readVecComplianceRequirement_V2(parser_context_t* c, pd_VecComplianceRequirement_V2_t* v);
parser_error_t _readVecCondition_V2(parser_context_t* c, pd_VecCondition_V2_t* v);
parser_error_t _readVecDispatchableName_V2(parser_context_t* c, pd_VecDispatchableName_V2_t* v);
parser_error_t _readVecDocumentId_V2(parser_context_t* c, pd_VecDocumentId_V2_t* v);
parser_error_t _readVecDocument_V2(parser_context_t* c, pd_VecDocument_V2_t* v);
parser_error_t _readVecIdentityId_V2(parser_context_t* c, pd_VecIdentityId_V2_t* v);
parser_error_t _readVecKeyValue_V2(parser_context_t* c, pd_VecKeyValue_V2_t* v);
parser_error_t _readVecKey_V2(parser_context_t* c, pd_VecKey_V2_t* v);
parser_error_t _readVecLeg_V2(parser_context_t* c, pd_VecLeg_V2_t* v);
parser_error_t _readVecLegacyPalletPermissions_V2(parser_context_t* c, pd_VecLegacyPalletPermissions_V2_t* v);
parser_error_t _readVecLookupSource_V2(parser_context_t* c, pd_VecLookupSource_V2_t* v);
parser_error_t _readVecMotion_V2(parser_context_t* c, pd_VecMotion_V2_t* v);
parser_error_t _readVecMovePortfolioItem_V2(parser_context_t* c, pd_VecMovePortfolioItem_V2_t* v);
parser_error_t _readVecPalletPermissions_V2(parser_context_t* c, pd_VecPalletPermissions_V2_t* v);
parser_error_t _readVecPortfolioId_V2(parser_context_t* c, pd_VecPortfolioId_V2_t* v);
parser_error_t _readVecPriceTier_V2(parser_context_t* c, pd_VecPriceTier_V2_t* v);
parser_error_t _readVecReceiptDetails_V2(parser_context_t* c, pd_VecReceiptDetails_V2_t* v);
parser_error_t _readVecScopeId_V2(parser_context_t* c, pd_VecScopeId_V2_t* v);
parser_error_t _readVecSecondaryKeyWithAuth_V2(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V2_t* v);
parser_error_t _readVecSecondaryKey_V2(parser_context_t* c, pd_VecSecondaryKey_V2_t* v);
parser_error_t _readVecSignatory_V2(parser_context_t* c, pd_VecSignatory_V2_t* v);
parser_error_t _readVecTicker_V2(parser_context_t* c, pd_VecTicker_V2_t* v);
parser_error_t _readVecTrustedIssuer_V2(parser_context_t* c, pd_VecTrustedIssuer_V2_t* v);
parser_error_t _readVecTupleIdentityIdTax_V2(parser_context_t* c, pd_VecTupleIdentityIdTax_V2_t* v);
parser_error_t _readVecTupleIdentityIdbool_V2(parser_context_t* c, pd_VecTupleIdentityIdbool_V2_t* v);
parser_error_t _readVecTuplePipIdSnapshotResult_V2(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V2_t* v);
parser_error_t _readVecValidatorIndex_V2(parser_context_t* c, pd_VecValidatorIndex_V2_t* v);
parser_error_t _readVecVenueId_V2(parser_context_t* c, pd_VecVenueId_V2_t* v);
parser_error_t _readVenueDetails_V2(parser_context_t* c, pd_VenueDetails_V2_t* v);
parser_error_t _readVenueId_V2(parser_context_t* c, pd_VenueId_V2_t* v);
parser_error_t _readVenueType_V2(parser_context_t* c, pd_VenueType_V2_t* v);
parser_error_t _readWeight_V2(parser_context_t* c, pd_Weight_V2_t* v);

// toString functions
parser_error_t _toStringAGId_V2(
    const pd_AGId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V2(
    const pd_AccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V2(
    const pd_AccountIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAddRelayerPayingKey_V2(
    const pd_AddRelayerPayingKey_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAgentGroup_V2(
    const pd_AgentGroup_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdentifier_V2(
    const pd_AssetIdentifier_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetName_V2(
    const pd_AssetName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetPermissions_V2(
    const pd_AssetPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V2(
    const pd_AssetType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorizationData_V2(
    const pd_AuthorizationData_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBabeEquivocationProof_V2(
    const pd_BabeEquivocationProof_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotMeta_V2(
    const pd_BallotMeta_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTimeRange_V2(
    const pd_BallotTimeRange_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTitle_V2(
    const pd_BallotTitle_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotVote_V2(
    const pd_BallotVote_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBecomeAgent_V2(
    const pd_BecomeAgent_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBeneficiary_V2(
    const pd_Beneficiary_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeTx_V2(
    const pd_BridgeTx_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCADetails_V2(
    const pd_CADetails_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAId_V2(
    const pd_CAId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAKind_V2(
    const pd_CAKind_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarPeriod_V2(
    const pd_CalendarPeriod_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarUnit_V2(
    const pd_CalendarUnit_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCddId_V2(
    const pd_CddId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V2(
    const pd_ChangesTrieConfiguration_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCheckpointId_V2(
    const pd_CheckpointId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChoiceTitle_V2(
    const pd_ChoiceTitle_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaimType_V2(
    const pd_ClaimType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaim_V2(
    const pd_Claim_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassicTickerImport_V2(
    const pd_ClassicTickerImport_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex_V2(
    const pd_CompactAccountIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V2(
    const pd_CompactAssignments_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V2(
    const pd_CompactEraIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V2(
    const pd_CompactMoment_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V2(
    const pd_CompactPerBill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringComplianceRequirement_V2(
    const pd_ComplianceRequirement_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConditionType_V2(
    const pd_ConditionType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCondition_V2(
    const pd_Condition_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCounter_V2(
    const pd_Counter_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCountryCode_V2(
    const pd_CountryCode_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCustomAssetTypeId_V2(
    const pd_CustomAssetTypeId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableName_V2(
    const pd_DispatchableName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableNames_V2(
    const pd_DispatchableNames_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentHash_V2(
    const pd_DocumentHash_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentId_V2(
    const pd_DocumentId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentName_V2(
    const pd_DocumentName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentType_V2(
    const pd_DocumentType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentUri_V2(
    const pd_DocumentUri_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocument_V2(
    const pd_Document_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V2(
    const pd_EcdsaSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V2(
    const pd_ElectionScore_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V2(
    const pd_ElectionSize_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V2(
    const pd_EraIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V2(
    const pd_EthereumAddress_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringExtrinsicPermissions_V2(
    const pd_ExtrinsicPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundingRoundName_V2(
    const pd_FundingRoundName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserId_V2(
    const pd_FundraiserId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserName_V2(
    const pd_FundraiserName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGrandpaEquivocationProof_V2(
    const pd_GrandpaEquivocationProof_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityId_V2(
    const pd_IdentityId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstructionId_V2(
    const pd_InstructionId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorUid_V2(
    const pd_InvestorUid_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorZKProofData_V2(
    const pd_InvestorZKProofData_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItnRewardStatus_V2(
    const pd_ItnRewardStatus_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V2(
    const pd_KeyOwnerProof_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V2(
    const pd_KeyValue_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V2(
    const pd_Key_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V2(
    const pd_Keys_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegId_V2(
    const pd_LegId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeg_V2(
    const pd_Leg_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPalletPermissions_V2(
    const pd_LegacyPalletPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPermissions_V2(
    const pd_LegacyPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLocalCAId_V2(
    const pd_LocalCAId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V2(
    const pd_LookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMaybeBlock_V2(
    const pd_MaybeBlock_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V2(
    const pd_MemberCount_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemo_V2(
    const pd_Memo_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment_V2(
    const pd_Moment_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionInfoLink_V2(
    const pd_MotionInfoLink_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionTitle_V2(
    const pd_MotionTitle_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotion_V2(
    const pd_Motion_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMovePortfolioItem_V2(
    const pd_MovePortfolioItem_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffChainSignature_V2(
    const pd_OffChainSignature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V2(
    const pd_OptionChangesTrieConfiguration_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionDocumentType_V2(
    const pd_OptionDocumentType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionFundingRoundName_V2(
    const pd_OptionFundingRoundName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMemo_V2(
    const pd_OptionMemo_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMoment_V2(
    const pd_OptionMoment_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V2(
    const pd_OptionPeriod_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPipDescription_V2(
    const pd_OptionPipDescription_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioNumber_V2(
    const pd_OptionPortfolioNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptDetails_V2(
    const pd_OptionReceiptDetails_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRecordDateSpec_V2(
    const pd_OptionRecordDateSpec_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionScope_V2(
    const pd_OptionScope_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTargetIdentities_V2(
    const pd_OptionTargetIdentities_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTax_V2(
    const pd_OptionTax_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionUrl_V2(
    const pd_OptionUrl_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecLegacyPalletPermissions_V2(
    const pd_OptionVecLegacyPalletPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPortfolioId_V2(
    const pd_OptionVecPortfolioId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTicker_V2(
    const pd_OptionVecTicker_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleIdentityIdTax_V2(
    const pd_OptionVecTupleIdentityIdTax_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletName_V2(
    const pd_PalletName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletPermissions_V2(
    const pd_PalletPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V2(
    const pd_Perbill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V2(
    const pd_Percent_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercentage_V2(
    const pd_Percentage_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V2(
    const pd_Period_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermill_V2(
    const pd_Permill_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermissions_V2(
    const pd_Permissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipDescription_V2(
    const pd_PipDescription_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipId_V2(
    const pd_PipId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioId_V2(
    const pd_PortfolioId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioKind_V2(
    const pd_PortfolioKind_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioName_V2(
    const pd_PortfolioName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioNumber_V2(
    const pd_PortfolioNumber_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioPermissions_V2(
    const pd_PortfolioPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPosRatio_V2(
    const pd_PosRatio_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriceTier_V2(
    const pd_PriceTier_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V2(
    const pd_Priority_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposalIndex_V2(
    const pd_ProposalIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProtocolOp_V2(
    const pd_ProtocolOp_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptDetails_V2(
    const pd_ReceiptDetails_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptMetadata_V2(
    const pd_ReceiptMetadata_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRecordDateSpec_V2(
    const pd_RecordDateSpec_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V2(
    const pd_RewardDestination_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleId_V2(
    const pd_ScheduleId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleSpec_V2(
    const pd_ScheduleSpec_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeClaimProof_V2(
    const pd_ScopeClaimProof_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeId_V2(
    const pd_ScopeId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScope_V2(
    const pd_Scope_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyWithAuth_V2(
    const pd_SecondaryKeyWithAuth_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKey_V2(
    const pd_SecondaryKey_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSettlementType_V2(
    const pd_SettlementType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignatory_V2(
    const pd_Signatory_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V2(
    const pd_Signature_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSkippedCount_V2(
    const pd_SkippedCount_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSlashingSwitch_V2(
    const pd_SlashingSwitch_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSnapshotResult_V2(
    const pd_SnapshotResult_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V2(
    const pd_StreamDependency_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentities_V2(
    const pd_TargetIdentities_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentity_V2(
    const pd_TargetIdentity_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetTreatment_V2(
    const pd_TargetTreatment_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTax_V2(
    const pd_Tax_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTickerRegistrationConfig_V2(
    const pd_TickerRegistrationConfig_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTicker_V2(
    const pd_Ticker_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTransferManager_V2(
    const pd_TransferManager_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedFor_V2(
    const pd_TrustedFor_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedIssuer_V2(
    const pd_TrustedIssuer_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCountryCodeScope_V2(
    const pd_TupleCountryCodeScope_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdTax_V2(
    const pd_TupleIdentityIdTax_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdbool_V2(
    const pd_TupleIdentityIdbool_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePipIdSnapshotResult_V2(
    const pd_TuplePipIdSnapshotResult_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleScopeScopeIdCddId_V2(
    const pd_TupleScopeScopeIdCddId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUniqueCall_V2(
    const pd_UniqueCall_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUrl_V2(
    const pd_Url_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V2(
    const pd_ValidatorIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V2(
    const pd_ValidatorPrefs_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V2(
    const pd_VecAccountId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdentifier_V2(
    const pd_VecAssetIdentifier_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBallotVote_V2(
    const pd_VecBallotVote_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBeneficiary_V2(
    const pd_VecBeneficiary_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBridgeTx_V2(
    const pd_VecBridgeTx_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecChoiceTitle_V2(
    const pd_VecChoiceTitle_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaimType_V2(
    const pd_VecClaimType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaim_V2(
    const pd_VecClaim_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecComplianceRequirement_V2(
    const pd_VecComplianceRequirement_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCondition_V2(
    const pd_VecCondition_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDispatchableName_V2(
    const pd_VecDispatchableName_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocumentId_V2(
    const pd_VecDocumentId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocument_V2(
    const pd_VecDocument_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecIdentityId_V2(
    const pd_VecIdentityId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V2(
    const pd_VecKeyValue_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V2(
    const pd_VecKey_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLeg_V2(
    const pd_VecLeg_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLegacyPalletPermissions_V2(
    const pd_VecLegacyPalletPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V2(
    const pd_VecLookupSource_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMotion_V2(
    const pd_VecMotion_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMovePortfolioItem_V2(
    const pd_VecMovePortfolioItem_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPalletPermissions_V2(
    const pd_VecPalletPermissions_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPortfolioId_V2(
    const pd_VecPortfolioId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPriceTier_V2(
    const pd_VecPriceTier_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecReceiptDetails_V2(
    const pd_VecReceiptDetails_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecScopeId_V2(
    const pd_VecScopeId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyWithAuth_V2(
    const pd_VecSecondaryKeyWithAuth_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKey_V2(
    const pd_VecSecondaryKey_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSignatory_V2(
    const pd_VecSignatory_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTicker_V2(
    const pd_VecTicker_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTrustedIssuer_V2(
    const pd_VecTrustedIssuer_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdTax_V2(
    const pd_VecTupleIdentityIdTax_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdbool_V2(
    const pd_VecTupleIdentityIdbool_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePipIdSnapshotResult_V2(
    const pd_VecTuplePipIdSnapshotResult_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V2(
    const pd_VecValidatorIndex_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVenueId_V2(
    const pd_VecVenueId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueDetails_V2(
    const pd_VenueDetails_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueId_V2(
    const pd_VenueId_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueType_V2(
    const pd_VenueType_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V2(
    const pd_Weight_V2_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
