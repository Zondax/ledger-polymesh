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
#include "substrate_methods_V1.h"
#include "substrate_types_V1.h"
#include <stddef.h>
#include <stdint.h>

// Read functions
parser_error_t _readAGId_V1(parser_context_t* c, pd_AGId_V1_t* v);
parser_error_t _readAccountId_V1(parser_context_t* c, pd_AccountId_V1_t* v);
parser_error_t _readAccountIndex_V1(parser_context_t* c, pd_AccountIndex_V1_t* v);
parser_error_t _readAddRelayerPayingKey_V1(parser_context_t* c, pd_AddRelayerPayingKey_V1_t* v);
parser_error_t _readAgentGroup_V1(parser_context_t* c, pd_AgentGroup_V1_t* v);
parser_error_t _readAssetIdentifier_V1(parser_context_t* c, pd_AssetIdentifier_V1_t* v);
parser_error_t _readAssetName_V1(parser_context_t* c, pd_AssetName_V1_t* v);
parser_error_t _readAssetType_V1(parser_context_t* c, pd_AssetType_V1_t* v);
parser_error_t _readAuthorizationData_V1(parser_context_t* c, pd_AuthorizationData_V1_t* v);
parser_error_t _readBabeEquivocationProof_V1(parser_context_t* c, pd_BabeEquivocationProof_V1_t* v);
parser_error_t _readBallotMeta_V1(parser_context_t* c, pd_BallotMeta_V1_t* v);
parser_error_t _readBallotTimeRange_V1(parser_context_t* c, pd_BallotTimeRange_V1_t* v);
parser_error_t _readBallotTitle_V1(parser_context_t* c, pd_BallotTitle_V1_t* v);
parser_error_t _readBallotVote_V1(parser_context_t* c, pd_BallotVote_V1_t* v);
parser_error_t _readBecomeAgent_V1(parser_context_t* c, pd_BecomeAgent_V1_t* v);
parser_error_t _readBeneficiary_V1(parser_context_t* c, pd_Beneficiary_V1_t* v);
parser_error_t _readBridgeTx_V1(parser_context_t* c, pd_BridgeTx_V1_t* v);
parser_error_t _readCADetails_V1(parser_context_t* c, pd_CADetails_V1_t* v);
parser_error_t _readCAId_V1(parser_context_t* c, pd_CAId_V1_t* v);
parser_error_t _readCAKind_V1(parser_context_t* c, pd_CAKind_V1_t* v);
parser_error_t _readCalendarPeriod_V1(parser_context_t* c, pd_CalendarPeriod_V1_t* v);
parser_error_t _readCalendarUnit_V1(parser_context_t* c, pd_CalendarUnit_V1_t* v);
parser_error_t _readCddId_V1(parser_context_t* c, pd_CddId_V1_t* v);
parser_error_t _readChangesTrieConfiguration_V1(parser_context_t* c, pd_ChangesTrieConfiguration_V1_t* v);
parser_error_t _readCheckpointId_V1(parser_context_t* c, pd_CheckpointId_V1_t* v);
parser_error_t _readChoiceTitle_V1(parser_context_t* c, pd_ChoiceTitle_V1_t* v);
parser_error_t _readClaimType_V1(parser_context_t* c, pd_ClaimType_V1_t* v);
parser_error_t _readClaim_V1(parser_context_t* c, pd_Claim_V1_t* v);
parser_error_t _readClassicTickerImport_V1(parser_context_t* c, pd_ClassicTickerImport_V1_t* v);
parser_error_t _readCompactAssignments_V1(parser_context_t* c, pd_CompactAssignments_V1_t* v);
parser_error_t _readCompactEraIndex_V1(parser_context_t* c, pd_CompactEraIndex_V1_t* v);
parser_error_t _readCompactMoment_V1(parser_context_t* c, pd_CompactMoment_V1_t* v);
parser_error_t _readCompactPerBill_V1(parser_context_t* c, pd_CompactPerBill_V1_t* v);
parser_error_t _readComplianceRequirement_V1(parser_context_t* c, pd_ComplianceRequirement_V1_t* v);
parser_error_t _readConditionType_V1(parser_context_t* c, pd_ConditionType_V1_t* v);
parser_error_t _readCondition_V1(parser_context_t* c, pd_Condition_V1_t* v);
parser_error_t _readCounter_V1(parser_context_t* c, pd_Counter_V1_t* v);
parser_error_t _readCountryCode_V1(parser_context_t* c, pd_CountryCode_V1_t* v);
parser_error_t _readCustomAssetTypeId_V1(parser_context_t* c, pd_CustomAssetTypeId_V1_t* v);
parser_error_t _readDispatchableName_V1(parser_context_t* c, pd_DispatchableName_V1_t* v);
parser_error_t _readDocumentHash_V1(parser_context_t* c, pd_DocumentHash_V1_t* v);
parser_error_t _readDocumentId_V1(parser_context_t* c, pd_DocumentId_V1_t* v);
parser_error_t _readDocumentName_V1(parser_context_t* c, pd_DocumentName_V1_t* v);
parser_error_t _readDocumentType_V1(parser_context_t* c, pd_DocumentType_V1_t* v);
parser_error_t _readDocumentUri_V1(parser_context_t* c, pd_DocumentUri_V1_t* v);
parser_error_t _readDocument_V1(parser_context_t* c, pd_Document_V1_t* v);
parser_error_t _readEcdsaSignature_V1(parser_context_t* c, pd_EcdsaSignature_V1_t* v);
parser_error_t _readElectionScore_V1(parser_context_t* c, pd_ElectionScore_V1_t* v);
parser_error_t _readElectionSize_V1(parser_context_t* c, pd_ElectionSize_V1_t* v);
parser_error_t _readEraIndex_V1(parser_context_t* c, pd_EraIndex_V1_t* v);
parser_error_t _readEthereumAddress_V1(parser_context_t* c, pd_EthereumAddress_V1_t* v);
parser_error_t _readDispatchableNames_V1(parser_context_t* c, pd_DispatchableNames_V1_t* v);
parser_error_t _readAssetPermissions_V1(parser_context_t* c, pd_AssetPermissions_V1_t* v);
parser_error_t _readExtrinsicPermissions_V1(parser_context_t* c, pd_ExtrinsicPermissions_V1_t* v);
parser_error_t _readPortfolioPermissions_V1(parser_context_t* c, pd_PortfolioPermissions_V1_t* v);
parser_error_t _readFundingRoundName_V1(parser_context_t* c, pd_FundingRoundName_V1_t* v);
parser_error_t _readFundraiserName_V1(parser_context_t* c, pd_FundraiserName_V1_t* v);
parser_error_t _readGrandpaEquivocationProof_V1(parser_context_t* c, pd_GrandpaEquivocationProof_V1_t* v);
parser_error_t _readIdentityId_V1(parser_context_t* c, pd_IdentityId_V1_t* v);
parser_error_t _readInvestorUid_V1(parser_context_t* c, pd_InvestorUid_V1_t* v);
parser_error_t _readInvestorZKProofData_V1(parser_context_t* c, pd_InvestorZKProofData_V1_t* v);
parser_error_t _readItnRewardStatus_V1(parser_context_t* c, pd_ItnRewardStatus_V1_t* v);
parser_error_t _readKeyOwnerProof_V1(parser_context_t* c, pd_KeyOwnerProof_V1_t* v);
parser_error_t _readKeyValue_V1(parser_context_t* c, pd_KeyValue_V1_t* v);
parser_error_t _readKey_V1(parser_context_t* c, pd_Key_V1_t* v);
parser_error_t _readKeys_V1(parser_context_t* c, pd_Keys_V1_t* v);
parser_error_t _readLeg_V1(parser_context_t* c, pd_Leg_V1_t* v);
parser_error_t _readLegacyPalletPermissions_V1(parser_context_t* c, pd_LegacyPalletPermissions_V1_t* v);
parser_error_t _readLegacyPermissions_V1(parser_context_t* c, pd_LegacyPermissions_V1_t* v);
parser_error_t _readLocalCAId_V1(parser_context_t* c, pd_LocalCAId_V1_t* v);
parser_error_t _readLookupSource_V1(parser_context_t* c, pd_LookupSource_V1_t* v);
parser_error_t _readMaybeBlock_V1(parser_context_t* c, pd_MaybeBlock_V1_t* v);
parser_error_t _readMemberCount_V1(parser_context_t* c, pd_MemberCount_V1_t* v);
parser_error_t _readMemo_V1(parser_context_t* c, pd_Memo_V1_t* v);
parser_error_t _readMoment_V1(parser_context_t* c, pd_Moment_V1_t* v);
parser_error_t _readMotionInfoLink_V1(parser_context_t* c, pd_MotionInfoLink_V1_t* v);
parser_error_t _readMotionTitle_V1(parser_context_t* c, pd_MotionTitle_V1_t* v);
parser_error_t _readMotion_V1(parser_context_t* c, pd_Motion_V1_t* v);
parser_error_t _readMovePortfolioItem_V1(parser_context_t* c, pd_MovePortfolioItem_V1_t* v);
parser_error_t _readOffChainSignature_V1(parser_context_t* c, pd_OffChainSignature_V1_t* v);
parser_error_t _readOptionChangesTrieConfiguration_V1(parser_context_t* c, pd_OptionChangesTrieConfiguration_V1_t* v);
parser_error_t _readOptionDocumentType_V1(parser_context_t* c, pd_OptionDocumentType_V1_t* v);
parser_error_t _readOptionFundingRoundName_V1(parser_context_t* c, pd_OptionFundingRoundName_V1_t* v);
parser_error_t _readOptionMemo_V1(parser_context_t* c, pd_OptionMemo_V1_t* v);
parser_error_t _readOptionMoment_V1(parser_context_t* c, pd_OptionMoment_V1_t* v);
parser_error_t _readOptionPeriod_V1(parser_context_t* c, pd_OptionPeriod_V1_t* v);
parser_error_t _readOptionPipDescription_V1(parser_context_t* c, pd_OptionPipDescription_V1_t* v);
parser_error_t _readOptionPortfolioNumber_V1(parser_context_t* c, pd_OptionPortfolioNumber_V1_t* v);
parser_error_t _readOptionReceiptDetails_V1(parser_context_t* c, pd_OptionReceiptDetails_V1_t* v);
parser_error_t _readOptionRecordDateSpec_V1(parser_context_t* c, pd_OptionRecordDateSpec_V1_t* v);
parser_error_t _readOptionScope_V1(parser_context_t* c, pd_OptionScope_V1_t* v);
parser_error_t _readOptionTargetIdentities_V1(parser_context_t* c, pd_OptionTargetIdentities_V1_t* v);
parser_error_t _readOptionTax_V1(parser_context_t* c, pd_OptionTax_V1_t* v);
parser_error_t _readOptionUrl_V1(parser_context_t* c, pd_OptionUrl_V1_t* v);
parser_error_t _readOptionVecDispatchableName_V1(parser_context_t* c, pd_OptionVecDispatchableName_V1_t* v);
parser_error_t _readOptionVecLegacyPalletPermissions_V1(parser_context_t* c, pd_OptionVecLegacyPalletPermissions_V1_t* v);
parser_error_t _readOptionVecPalletPermissions_V1(parser_context_t* c, pd_OptionVecPalletPermissions_V1_t* v);
parser_error_t _readOptionVecPortfolioId_V1(parser_context_t* c, pd_OptionVecPortfolioId_V1_t* v);
parser_error_t _readOptionVecTicker_V1(parser_context_t* c, pd_OptionVecTicker_V1_t* v);
parser_error_t _readOptionVecTupleIdentityIdTax_V1(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V1_t* v);
parser_error_t _readPalletName_V1(parser_context_t* c, pd_PalletName_V1_t* v);
parser_error_t _readPalletPermissions_V1(parser_context_t* c, pd_PalletPermissions_V1_t* v);
parser_error_t _readPerbill_V1(parser_context_t* c, pd_Perbill_V1_t* v);
parser_error_t _readPercent_V1(parser_context_t* c, pd_Percent_V1_t* v);
parser_error_t _readPercentage_V1(parser_context_t* c, pd_Percentage_V1_t* v);
parser_error_t _readPeriod_V1(parser_context_t* c, pd_Period_V1_t* v);
parser_error_t _readPermill_V1(parser_context_t* c, pd_Permill_V1_t* v);
parser_error_t _readPermissions_V1(parser_context_t* c, pd_Permissions_V1_t* v);
parser_error_t _readPipDescription_V1(parser_context_t* c, pd_PipDescription_V1_t* v);
parser_error_t _readPipId_V1(parser_context_t* c, pd_PipId_V1_t* v);
parser_error_t _readPortfolioId_V1(parser_context_t* c, pd_PortfolioId_V1_t* v);
parser_error_t _readPortfolioKind_V1(parser_context_t* c, pd_PortfolioKind_V1_t* v);
parser_error_t _readPortfolioName_V1(parser_context_t* c, pd_PortfolioName_V1_t* v);
parser_error_t _readPortfolioNumber_V1(parser_context_t* c, pd_PortfolioNumber_V1_t* v);
parser_error_t _readPosRatio_V1(parser_context_t* c, pd_PosRatio_V1_t* v);
parser_error_t _readPriceTier_V1(parser_context_t* c, pd_PriceTier_V1_t* v);
parser_error_t _readPriority_V1(parser_context_t* c, pd_Priority_V1_t* v);
parser_error_t _readProposalIndex_V1(parser_context_t* c, pd_ProposalIndex_V1_t* v);
parser_error_t _readProtocolOp_V1(parser_context_t* c, pd_ProtocolOp_V1_t* v);
parser_error_t _readReceiptDetails_V1(parser_context_t* c, pd_ReceiptDetails_V1_t* v);
parser_error_t _readReceiptMetadata_V1(parser_context_t* c, pd_ReceiptMetadata_V1_t* v);
parser_error_t _readRecordDateSpec_V1(parser_context_t* c, pd_RecordDateSpec_V1_t* v);
parser_error_t _readRewardDestination_V1(parser_context_t* c, pd_RewardDestination_V1_t* v);
parser_error_t _readScheduleId_V1(parser_context_t* c, pd_ScheduleId_V1_t* v);
parser_error_t _readScheduleSpec_V1(parser_context_t* c, pd_ScheduleSpec_V1_t* v);
parser_error_t _readScopeClaimProof_V1(parser_context_t* c, pd_ScopeClaimProof_V1_t* v);
parser_error_t _readScopeId_V1(parser_context_t* c, pd_ScopeId_V1_t* v);
parser_error_t _readScope_V1(parser_context_t* c, pd_Scope_V1_t* v);
parser_error_t _readSecondaryKeyWithAuth_V1(parser_context_t* c, pd_SecondaryKeyWithAuth_V1_t* v);
parser_error_t _readSecondaryKey_V1(parser_context_t* c, pd_SecondaryKey_V1_t* v);
parser_error_t _readSettlementType_V1(parser_context_t* c, pd_SettlementType_V1_t* v);
parser_error_t _readSignatory_V1(parser_context_t* c, pd_Signatory_V1_t* v);
parser_error_t _readSignature_V1(parser_context_t* c, pd_Signature_V1_t* v);
parser_error_t _readSkippedCount_V1(parser_context_t* c, pd_SkippedCount_V1_t* v);
parser_error_t _readSlashingSwitch_V1(parser_context_t* c, pd_SlashingSwitch_V1_t* v);
parser_error_t _readSnapshotResult_V1(parser_context_t* c, pd_SnapshotResult_V1_t* v);
parser_error_t _readStreamDependency_V1(parser_context_t* c, pd_StreamDependency_V1_t* v);
parser_error_t _readTargetIdentities_V1(parser_context_t* c, pd_TargetIdentities_V1_t* v);
parser_error_t _readTargetIdentity_V1(parser_context_t* c, pd_TargetIdentity_V1_t* v);
parser_error_t _readTargetTreatment_V1(parser_context_t* c, pd_TargetTreatment_V1_t* v);
parser_error_t _readTax_V1(parser_context_t* c, pd_Tax_V1_t* v);
parser_error_t _readTickerRegistrationConfig_V1(parser_context_t* c, pd_TickerRegistrationConfig_V1_t* v);
parser_error_t _readTicker_V1(parser_context_t* c, pd_Ticker_V1_t* v);
parser_error_t _readTransferManager_V1(parser_context_t* c, pd_TransferManager_V1_t* v);
parser_error_t _readTrustedFor_V1(parser_context_t* c, pd_TrustedFor_V1_t* v);
parser_error_t _readTrustedIssuer_V1(parser_context_t* c, pd_TrustedIssuer_V1_t* v);
parser_error_t _readTupleCountryCodeScope_V1(parser_context_t* c, pd_TupleCountryCodeScope_V1_t* v);
parser_error_t _readTupleIdentityIdTax_V1(parser_context_t* c, pd_TupleIdentityIdTax_V1_t* v);
parser_error_t _readTupleIdentityIdbool_V1(parser_context_t* c, pd_TupleIdentityIdbool_V1_t* v);
parser_error_t _readTuplePipIdSnapshotResult_V1(parser_context_t* c, pd_TuplePipIdSnapshotResult_V1_t* v);
parser_error_t _readTupleScopeScopeIdCddId_V1(parser_context_t* c, pd_TupleScopeScopeIdCddId_V1_t* v);
parser_error_t _readUniqueCall_V1(parser_context_t* c, pd_UniqueCall_V1_t* v);
parser_error_t _readUrl_V1(parser_context_t* c, pd_Url_V1_t* v);
parser_error_t _readValidatorIndex_V1(parser_context_t* c, pd_ValidatorIndex_V1_t* v);
parser_error_t _readValidatorPrefs_V1(parser_context_t* c, pd_ValidatorPrefs_V1_t* v);
parser_error_t _readVecAccountId_V1(parser_context_t* c, pd_VecAccountId_V1_t* v);
parser_error_t _readVecAssetIdentifier_V1(parser_context_t* c, pd_VecAssetIdentifier_V1_t* v);
parser_error_t _readVecBallotVote_V1(parser_context_t* c, pd_VecBallotVote_V1_t* v);
parser_error_t _readVecBeneficiary_V1(parser_context_t* c, pd_VecBeneficiary_V1_t* v);
parser_error_t _readVecBridgeTx_V1(parser_context_t* c, pd_VecBridgeTx_V1_t* v);
parser_error_t _readVecChoiceTitle_V1(parser_context_t* c, pd_VecChoiceTitle_V1_t* v);
parser_error_t _readVecClaimType_V1(parser_context_t* c, pd_VecClaimType_V1_t* v);
parser_error_t _readVecClaim_V1(parser_context_t* c, pd_VecClaim_V1_t* v);
parser_error_t _readVecComplianceRequirement_V1(parser_context_t* c, pd_VecComplianceRequirement_V1_t* v);
parser_error_t _readVecCondition_V1(parser_context_t* c, pd_VecCondition_V1_t* v);
parser_error_t _readVecDispatchableName_V1(parser_context_t* c, pd_VecDispatchableName_V1_t* v);
parser_error_t _readVecDocumentId_V1(parser_context_t* c, pd_VecDocumentId_V1_t* v);
parser_error_t _readVecDocument_V1(parser_context_t* c, pd_VecDocument_V1_t* v);
parser_error_t _readVecIdentityId_V1(parser_context_t* c, pd_VecIdentityId_V1_t* v);
parser_error_t _readVecKeyValue_V1(parser_context_t* c, pd_VecKeyValue_V1_t* v);
parser_error_t _readVecKey_V1(parser_context_t* c, pd_VecKey_V1_t* v);
parser_error_t _readVecLeg_V1(parser_context_t* c, pd_VecLeg_V1_t* v);
parser_error_t _readVecLegacyPalletPermissions_V1(parser_context_t* c, pd_VecLegacyPalletPermissions_V1_t* v);
parser_error_t _readVecLookupSource_V1(parser_context_t* c, pd_VecLookupSource_V1_t* v);
parser_error_t _readVecMotion_V1(parser_context_t* c, pd_VecMotion_V1_t* v);
parser_error_t _readVecMovePortfolioItem_V1(parser_context_t* c, pd_VecMovePortfolioItem_V1_t* v);
parser_error_t _readVecPalletPermissions_V1(parser_context_t* c, pd_VecPalletPermissions_V1_t* v);
parser_error_t _readVecPortfolioId_V1(parser_context_t* c, pd_VecPortfolioId_V1_t* v);
parser_error_t _readVecPriceTier_V1(parser_context_t* c, pd_VecPriceTier_V1_t* v);
parser_error_t _readVecReceiptDetails_V1(parser_context_t* c, pd_VecReceiptDetails_V1_t* v);
parser_error_t _readVecScopeId_V1(parser_context_t* c, pd_VecScopeId_V1_t* v);
parser_error_t _readVecSecondaryKeyWithAuth_V1(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V1_t* v);
parser_error_t _readVecSecondaryKey_V1(parser_context_t* c, pd_VecSecondaryKey_V1_t* v);
parser_error_t _readVecSignatory_V1(parser_context_t* c, pd_VecSignatory_V1_t* v);
parser_error_t _readVecTicker_V1(parser_context_t* c, pd_VecTicker_V1_t* v);
parser_error_t _readVecTrustedIssuer_V1(parser_context_t* c, pd_VecTrustedIssuer_V1_t* v);
parser_error_t _readVecTupleIdentityIdTax_V1(parser_context_t* c, pd_VecTupleIdentityIdTax_V1_t* v);
parser_error_t _readVecTupleIdentityIdbool_V1(parser_context_t* c, pd_VecTupleIdentityIdbool_V1_t* v);
parser_error_t _readVecTuplePipIdSnapshotResult_V1(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V1_t* v);
parser_error_t _readVecValidatorIndex_V1(parser_context_t* c, pd_VecValidatorIndex_V1_t* v);
parser_error_t _readVenueDetails_V1(parser_context_t* c, pd_VenueDetails_V1_t* v);
parser_error_t _readVenueType_V1(parser_context_t* c, pd_VenueType_V1_t* v);
parser_error_t _readWeight_V1(parser_context_t* c, pd_Weight_V1_t* v);

// toString functions
parser_error_t _toStringAGId_V1(
    const pd_AGId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId_V1(
    const pd_AccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex_V1(
    const pd_AccountIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAddRelayerPayingKey_V1(
    const pd_AddRelayerPayingKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAgentGroup_V1(
    const pd_AgentGroup_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdentifier_V1(
    const pd_AssetIdentifier_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetName_V1(
    const pd_AssetName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType_V1(
    const pd_AssetType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorizationData_V1(
    const pd_AuthorizationData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBabeEquivocationProof_V1(
    const pd_BabeEquivocationProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotMeta_V1(
    const pd_BallotMeta_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTimeRange_V1(
    const pd_BallotTimeRange_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTitle_V1(
    const pd_BallotTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotVote_V1(
    const pd_BallotVote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBecomeAgent_V1(
    const pd_BecomeAgent_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBeneficiary_V1(
    const pd_Beneficiary_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeTx_V1(
    const pd_BridgeTx_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCADetails_V1(
    const pd_CADetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAId_V1(
    const pd_CAId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAKind_V1(
    const pd_CAKind_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarPeriod_V1(
    const pd_CalendarPeriod_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCalendarUnit_V1(
    const pd_CalendarUnit_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCddId_V1(
    const pd_CddId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChangesTrieConfiguration_V1(
    const pd_ChangesTrieConfiguration_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCheckpointId_V1(
    const pd_CheckpointId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChoiceTitle_V1(
    const pd_ChoiceTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaimType_V1(
    const pd_ClaimType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaim_V1(
    const pd_Claim_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClassicTickerImport_V1(
    const pd_ClassicTickerImport_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAssignments_V1(
    const pd_CompactAssignments_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactEraIndex_V1(
    const pd_CompactEraIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactMoment_V1(
    const pd_CompactMoment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill_V1(
    const pd_CompactPerBill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringComplianceRequirement_V1(
    const pd_ComplianceRequirement_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConditionType_V1(
    const pd_ConditionType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCondition_V1(
    const pd_Condition_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCounter_V1(
    const pd_Counter_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCountryCode_V1(
    const pd_CountryCode_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCustomAssetTypeId_V1(
    const pd_CustomAssetTypeId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableName_V1(
    const pd_DispatchableName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentHash_V1(
    const pd_DocumentHash_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentId_V1(
    const pd_DocumentId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentName_V1(
    const pd_DocumentName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentType_V1(
    const pd_DocumentType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentUri_V1(
    const pd_DocumentUri_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocument_V1(
    const pd_Document_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature_V1(
    const pd_EcdsaSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionScore_V1(
    const pd_ElectionScore_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringElectionSize_V1(
    const pd_ElectionSize_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex_V1(
    const pd_EraIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEthereumAddress_V1(
    const pd_EthereumAddress_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableNames_V1(
    const pd_DispatchableNames_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetPermissions_V1(
    const pd_AssetPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringExtrinsicPermissions_V1(
    const pd_ExtrinsicPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioPermissions_V1(
    const pd_PortfolioPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundingRoundName_V1(
    const pd_FundingRoundName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserName_V1(
    const pd_FundraiserName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringGrandpaEquivocationProof_V1(
    const pd_GrandpaEquivocationProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityId_V1(
    const pd_IdentityId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorUid_V1(
    const pd_InvestorUid_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInvestorZKProofData_V1(
    const pd_InvestorZKProofData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringItnRewardStatus_V1(
    const pd_ItnRewardStatus_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyOwnerProof_V1(
    const pd_KeyOwnerProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeyValue_V1(
    const pd_KeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKey_V1(
    const pd_Key_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys_V1(
    const pd_Keys_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeg_V1(
    const pd_Leg_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPalletPermissions_V1(
    const pd_LegacyPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegacyPermissions_V1(
    const pd_LegacyPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLocalCAId_V1(
    const pd_LocalCAId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupSource_V1(
    const pd_LookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMaybeBlock_V1(
    const pd_MaybeBlock_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount_V1(
    const pd_MemberCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemo_V1(
    const pd_Memo_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment_V1(
    const pd_Moment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionInfoLink_V1(
    const pd_MotionInfoLink_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionTitle_V1(
    const pd_MotionTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotion_V1(
    const pd_Motion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMovePortfolioItem_V1(
    const pd_MovePortfolioItem_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffChainSignature_V1(
    const pd_OffChainSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration_V1(
    const pd_OptionChangesTrieConfiguration_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionDocumentType_V1(
    const pd_OptionDocumentType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionFundingRoundName_V1(
    const pd_OptionFundingRoundName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMemo_V1(
    const pd_OptionMemo_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMoment_V1(
    const pd_OptionMoment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPeriod_V1(
    const pd_OptionPeriod_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPipDescription_V1(
    const pd_OptionPipDescription_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioNumber_V1(
    const pd_OptionPortfolioNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptDetails_V1(
    const pd_OptionReceiptDetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRecordDateSpec_V1(
    const pd_OptionRecordDateSpec_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionScope_V1(
    const pd_OptionScope_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTargetIdentities_V1(
    const pd_OptionTargetIdentities_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTax_V1(
    const pd_OptionTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionUrl_V1(
    const pd_OptionUrl_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecDispatchableName_V1(
    const pd_OptionVecDispatchableName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecLegacyPalletPermissions_V1(
    const pd_OptionVecLegacyPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPalletPermissions_V1(
    const pd_OptionVecPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecPortfolioId_V1(
    const pd_OptionVecPortfolioId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTicker_V1(
    const pd_OptionVecTicker_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleIdentityIdTax_V1(
    const pd_OptionVecTupleIdentityIdTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletName_V1(
    const pd_PalletName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletPermissions_V1(
    const pd_PalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill_V1(
    const pd_Perbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent_V1(
    const pd_Percent_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercentage_V1(
    const pd_Percentage_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPeriod_V1(
    const pd_Period_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermill_V1(
    const pd_Permill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermissions_V1(
    const pd_Permissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipDescription_V1(
    const pd_PipDescription_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipId_V1(
    const pd_PipId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioId_V1(
    const pd_PortfolioId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioKind_V1(
    const pd_PortfolioKind_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioName_V1(
    const pd_PortfolioName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioNumber_V1(
    const pd_PortfolioNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPosRatio_V1(
    const pd_PosRatio_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriceTier_V1(
    const pd_PriceTier_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriority_V1(
    const pd_Priority_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposalIndex_V1(
    const pd_ProposalIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProtocolOp_V1(
    const pd_ProtocolOp_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptDetails_V1(
    const pd_ReceiptDetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptMetadata_V1(
    const pd_ReceiptMetadata_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRecordDateSpec_V1(
    const pd_RecordDateSpec_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination_V1(
    const pd_RewardDestination_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleId_V1(
    const pd_ScheduleId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleSpec_V1(
    const pd_ScheduleSpec_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeClaimProof_V1(
    const pd_ScopeClaimProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeId_V1(
    const pd_ScopeId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScope_V1(
    const pd_Scope_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyWithAuth_V1(
    const pd_SecondaryKeyWithAuth_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKey_V1(
    const pd_SecondaryKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSettlementType_V1(
    const pd_SettlementType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignatory_V1(
    const pd_Signatory_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature_V1(
    const pd_Signature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSkippedCount_V1(
    const pd_SkippedCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSlashingSwitch_V1(
    const pd_SlashingSwitch_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSnapshotResult_V1(
    const pd_SnapshotResult_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringStreamDependency_V1(
    const pd_StreamDependency_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentities_V1(
    const pd_TargetIdentities_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentity_V1(
    const pd_TargetIdentity_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetTreatment_V1(
    const pd_TargetTreatment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTax_V1(
    const pd_Tax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTickerRegistrationConfig_V1(
    const pd_TickerRegistrationConfig_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTicker_V1(
    const pd_Ticker_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTransferManager_V1(
    const pd_TransferManager_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedFor_V1(
    const pd_TrustedFor_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedIssuer_V1(
    const pd_TrustedIssuer_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCountryCodeScope_V1(
    const pd_TupleCountryCodeScope_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdTax_V1(
    const pd_TupleIdentityIdTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdbool_V1(
    const pd_TupleIdentityIdbool_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePipIdSnapshotResult_V1(
    const pd_TuplePipIdSnapshotResult_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleScopeScopeIdCddId_V1(
    const pd_TupleScopeScopeIdCddId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUniqueCall_V1(
    const pd_UniqueCall_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUrl_V1(
    const pd_Url_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorIndex_V1(
    const pd_ValidatorIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs_V1(
    const pd_ValidatorPrefs_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId_V1(
    const pd_VecAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdentifier_V1(
    const pd_VecAssetIdentifier_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBallotVote_V1(
    const pd_VecBallotVote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBeneficiary_V1(
    const pd_VecBeneficiary_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBridgeTx_V1(
    const pd_VecBridgeTx_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecChoiceTitle_V1(
    const pd_VecChoiceTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaimType_V1(
    const pd_VecClaimType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaim_V1(
    const pd_VecClaim_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecComplianceRequirement_V1(
    const pd_VecComplianceRequirement_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCondition_V1(
    const pd_VecCondition_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDispatchableName_V1(
    const pd_VecDispatchableName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocumentId_V1(
    const pd_VecDocumentId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocument_V1(
    const pd_VecDocument_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecIdentityId_V1(
    const pd_VecIdentityId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKeyValue_V1(
    const pd_VecKeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecKey_V1(
    const pd_VecKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLeg_V1(
    const pd_VecLeg_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLegacyPalletPermissions_V1(
    const pd_VecLegacyPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupSource_V1(
    const pd_VecLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMotion_V1(
    const pd_VecMotion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMovePortfolioItem_V1(
    const pd_VecMovePortfolioItem_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPalletPermissions_V1(
    const pd_VecPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPortfolioId_V1(
    const pd_VecPortfolioId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPriceTier_V1(
    const pd_VecPriceTier_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecReceiptDetails_V1(
    const pd_VecReceiptDetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecScopeId_V1(
    const pd_VecScopeId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyWithAuth_V1(
    const pd_VecSecondaryKeyWithAuth_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKey_V1(
    const pd_VecSecondaryKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSignatory_V1(
    const pd_VecSignatory_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTicker_V1(
    const pd_VecTicker_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTrustedIssuer_V1(
    const pd_VecTrustedIssuer_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdTax_V1(
    const pd_VecTupleIdentityIdTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdbool_V1(
    const pd_VecTupleIdentityIdbool_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePipIdSnapshotResult_V1(
    const pd_VecTuplePipIdSnapshotResult_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecValidatorIndex_V1(
    const pd_VecValidatorIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueDetails_V1(
    const pd_VenueDetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueType_V1(
    const pd_VenueType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight_V1(
    const pd_Weight_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
