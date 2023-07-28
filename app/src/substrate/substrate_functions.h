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

#include <stddef.h>
#include <stdint.h>

// Common read functions

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v);
parser_error_t _readu8(parser_context_t* c, pd_u8_t* v);
parser_error_t _readu16(parser_context_t* c, pd_u16_t* v);
parser_error_t _readu32(parser_context_t* c, pd_u32_t* v);
parser_error_t _readu64(parser_context_t* c, pd_u64_t* v);
parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v);
parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v);
parser_error_t _readCompactu64(parser_context_t* c, pd_Compactu64_t* v);
parser_error_t _readCallImpl(parser_context_t* c, pd_Call_t* v, pd_MethodNested_t* m);

parser_error_t _readIdentityId(parser_context_t* c, pd_IdentityId_t* v);
parser_error_t _readTicker(parser_context_t* c, pd_Ticker_t* v);
parser_error_t _readScope(parser_context_t* c, pd_Scope_t* v);
parser_error_t _readCddId(parser_context_t* c, pd_CddId_t* v);
parser_error_t _readClaimType(parser_context_t* c, pd_ClaimType_t* v);
parser_error_t _readCountryCode(parser_context_t* c, pd_CountryCode_t* v);
parser_error_t _readDispatchableName(parser_context_t* c, pd_DispatchableName_t* v);
parser_error_t _readOptionScope(parser_context_t* c, pd_OptionScope_t* v);
parser_error_t _readScopeId(parser_context_t* c, pd_ScopeId_t* v);
parser_error_t _readPortfolioNumber(parser_context_t* c, pd_PortfolioNumber_t* v);
parser_error_t _readTupleCountryCodeScope(parser_context_t* c, pd_TupleCountryCodeScope_t* v);
parser_error_t _readTupleScopeScopeIdCddId(parser_context_t* c, pd_TupleScopeScopeIdCddId_t* v);
parser_error_t _readTupleU32Scope(parser_context_t* c, pd_TupleU32Scope_t* v);
parser_error_t _readVecClaimType(parser_context_t* c, pd_VecClaimType_t* v);
parser_error_t _readVecDispatchableName(parser_context_t* c, pd_VecDispatchableName_t* v);
parser_error_t _readClaim(parser_context_t* c, pd_Claim_t* v);
parser_error_t _readDispatchableNames(parser_context_t* c, pd_DispatchableNames_t* v);
parser_error_t _readPalletName(parser_context_t* c, pd_PalletName_t* v);
parser_error_t _readPortfolioKind(parser_context_t* c, pd_PortfolioKind_t* v);
parser_error_t _readTrustedFor(parser_context_t* c, pd_TrustedFor_t* v);
parser_error_t _readPalletPermissions(parser_context_t* c, pd_PalletPermissions_t* v);
parser_error_t _readPermill(parser_context_t* c, pd_Permill_t* v);
parser_error_t _readPortfolioId(parser_context_t* c, pd_PortfolioId_t* v);
parser_error_t _readTargetIdentity(parser_context_t* c, pd_TargetIdentity_t* v);
parser_error_t _readTrustedIssuer(parser_context_t* c, pd_TrustedIssuer_t* v);
parser_error_t _readVecClaim(parser_context_t* c, pd_VecClaim_t* v);
parser_error_t _readChoiceTitle(parser_context_t* c, pd_ChoiceTitle_t* v);
parser_error_t _readConditionType(parser_context_t* c, pd_ConditionType_t* v);
parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v);
parser_error_t _readEd25519Signature(parser_context_t* c, pd_Ed25519Signature_t* v);
parser_error_t _readMemo(parser_context_t* c, pd_Memo_t* v);
parser_error_t _readSr25519Signature(parser_context_t* c, pd_Sr25519Signature_t* v);
parser_error_t _readTax(parser_context_t* c, pd_Tax_t* v);
parser_error_t _readVecPalletPermissions(parser_context_t* c, pd_VecPalletPermissions_t* v);
parser_error_t _readVecPortfolioId(parser_context_t* c, pd_VecPortfolioId_t* v);
parser_error_t _readVecTicker(parser_context_t* c, pd_VecTicker_t* v);
parser_error_t _readVecTrustedIssuer(parser_context_t* c, pd_VecTrustedIssuer_t* v);
parser_error_t _readAssetPermissions(parser_context_t* c, pd_AssetPermissions_t* v);
parser_error_t _readBalanceNoSymbol(parser_context_t* c, pd_BalanceNoSymbol_t* v);
parser_error_t _readCheckpointId(parser_context_t* c, pd_CheckpointId_t* v);
parser_error_t _readCondition(parser_context_t* c, pd_Condition_t* v);
parser_error_t _readDocumentType(parser_context_t* c, pd_DocumentType_t* v);
parser_error_t _readExtrinsicPermissions(parser_context_t* c, pd_ExtrinsicPermissions_t* v);
parser_error_t _readMoment(parser_context_t* c, pd_Moment_t* v);
parser_error_t _readMotionInfoLink(parser_context_t* c, pd_MotionInfoLink_t* v);
parser_error_t _readMotionTitle(parser_context_t* c, pd_MotionTitle_t* v);
parser_error_t _readMultiSignature(parser_context_t* c, pd_MultiSignature_t* v);
parser_error_t _readOptionMemo(parser_context_t* c, pd_OptionMemo_t* v);
parser_error_t _readPortfolioPermissions(parser_context_t* c, pd_PortfolioPermissions_t* v);
parser_error_t _readReceiptMetadata(parser_context_t* c, pd_ReceiptMetadata_t* v);
parser_error_t _readScheduleId(parser_context_t* c, pd_ScheduleId_t* v);
parser_error_t _readTargetTreatment(parser_context_t* c, pd_TargetTreatment_t* v);
parser_error_t _readTupleIdentityIdTax(parser_context_t* c, pd_TupleIdentityIdTax_t* v);
parser_error_t _readVecChoiceTitle(parser_context_t* c, pd_VecChoiceTitle_t* v);
parser_error_t _readVecIdentityId(parser_context_t* c, pd_VecIdentityId_t* v);
parser_error_t _readVecu64(parser_context_t* c, pd_Vecu64_t* v);
parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v);
parser_error_t _readAgentGroup(parser_context_t* c, pd_AgentGroup_t* v);
parser_error_t _readAssetMetadataKey(parser_context_t* c, pd_AssetMetadataKey_t* v);
parser_error_t _readAssetMetadataLockStatusMoment(parser_context_t* c, pd_AssetMetadataLockStatusMoment_t* v);
parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v);
parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v);
parser_error_t _readCompactAccountIndex(parser_context_t* c, pd_CompactAccountIndex_t* v);
parser_error_t _readDocumentHash(parser_context_t* c, pd_DocumentHash_t* v);
parser_error_t _readDocumentName(parser_context_t* c, pd_DocumentName_t* v);
parser_error_t _readDocumentUri(parser_context_t* c, pd_DocumentUri_t* v);
parser_error_t _readFundFungible(parser_context_t* c, pd_FundFungible_t* v);
parser_error_t _readFundNonFungible(parser_context_t* c, pd_FundNonFungible_t* v);
parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v);
parser_error_t _readLegFungible(parser_context_t* c, pd_LegFungible_t* v);
parser_error_t _readLegNonFungible(parser_context_t* c, pd_LegNonFungible_t* v);
parser_error_t _readLegOffChain(parser_context_t* c, pd_LegOffChain_t* v);
parser_error_t _readMotion(parser_context_t* c, pd_Motion_t* v);
parser_error_t _readOffChainSignature(parser_context_t* c, pd_OffChainSignature_t* v);
parser_error_t _readOptionDocumentType(parser_context_t* c, pd_OptionDocumentType_t* v);
parser_error_t _readOptionMoment(parser_context_t* c, pd_OptionMoment_t* v);
parser_error_t _readOptionReceiptMetadata(parser_context_t* c, pd_OptionReceiptMetadata_t* v);
parser_error_t _readOptionu16(parser_context_t* c, pd_Optionu16_t* v);
parser_error_t _readPermissions(parser_context_t* c, pd_Permissions_t* v);
parser_error_t _readPipId(parser_context_t* c, pd_PipId_t* v);
parser_error_t _readRecordDateSpec(parser_context_t* c, pd_RecordDateSpec_t* v);
parser_error_t _readSignature(parser_context_t* c, pd_Signature_t* v);
parser_error_t _readSnapshotResult(parser_context_t* c, pd_SnapshotResult_t* v);
parser_error_t _readTargetIdentities(parser_context_t* c, pd_TargetIdentities_t* v);
parser_error_t _readVecCondition(parser_context_t* c, pd_VecCondition_t* v);
parser_error_t _readVecTupleIdentityIdTax(parser_context_t* c, pd_VecTupleIdentityIdTax_t* v);
parser_error_t _readAddRelayerPayingKey(parser_context_t* c, pd_AddRelayerPayingKey_t* v);
parser_error_t _readAssetIdentifier(parser_context_t* c, pd_AssetIdentifier_t* v);
parser_error_t _readAssetMetadataValueDetailMoment(parser_context_t* c, pd_AssetMetadataValueDetailMoment_t* v);
parser_error_t _readBallotTitle(parser_context_t* c, pd_BallotTitle_t* v);
parser_error_t _readBallotVote(parser_context_t* c, pd_BallotVote_t* v);
parser_error_t _readBecomeAgent(parser_context_t* c, pd_BecomeAgent_t* v);
parser_error_t _readBeneficiary(parser_context_t* c, pd_Beneficiary_t* v);
parser_error_t _readBridgeTxAccountId(parser_context_t* c, pd_BridgeTxAccountId_t* v);
parser_error_t _readCAKind(parser_context_t* c, pd_CAKind_t* v);
parser_error_t _readCall(parser_context_t* c, pd_Call_t* v);
parser_error_t _readCompactBalanceOf(parser_context_t* c, pd_CompactBalanceOf_t* v);
parser_error_t _readCompactPerBill(parser_context_t* c, pd_CompactPerBill_t* v);
parser_error_t _readComplianceRequirement(parser_context_t* c, pd_ComplianceRequirement_t* v);
parser_error_t _readCreateChildIdentityWithAuthAccountId(parser_context_t* c, pd_CreateChildIdentityWithAuthAccountId_t* v);
parser_error_t _readCustomAssetTypeId(parser_context_t* c, pd_CustomAssetTypeId_t* v);
parser_error_t _readDocumentId(parser_context_t* c, pd_DocumentId_t* v);
parser_error_t _readDocument(parser_context_t* c, pd_Document_t* v);
parser_error_t _readFund(parser_context_t* c, pd_Fund_t* v);
parser_error_t _readFundingRoundName(parser_context_t* c, pd_FundingRoundName_t* v);
parser_error_t _readLeg(parser_context_t* c, pd_Leg_t* v);
parser_error_t _readLocalCAId(parser_context_t* c, pd_LocalCAId_t* v);
parser_error_t _readLookupasStaticLookupSource(parser_context_t* c, pd_LookupasStaticLookupSource_t* v);
parser_error_t _readNFTMetadataAttribute(parser_context_t* c, pd_NFTMetadataAttribute_t* v);
parser_error_t _readNonFungibleType(parser_context_t* c, pd_NonFungibleType_t* v);
parser_error_t _readOptionBytes(parser_context_t* c, pd_OptionBytes_t* v);
parser_error_t _readOptionPermill(parser_context_t* c, pd_OptionPermill_t* v);
parser_error_t _readOptionRecordDateSpec(parser_context_t* c, pd_OptionRecordDateSpec_t* v);
parser_error_t _readOptionTargetIdentities(parser_context_t* c, pd_OptionTargetIdentities_t* v);
parser_error_t _readOptionVecTupleIdentityIdTax(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_t* v);
parser_error_t _readPipDescription(parser_context_t* c, pd_PipDescription_t* v);
parser_error_t _readPriceTier(parser_context_t* c, pd_PriceTier_t* v);
parser_error_t _readReceiptDetails(parser_context_t* c, pd_ReceiptDetails_t* v);
parser_error_t _readSecondaryKeyAccountId(parser_context_t* c, pd_SecondaryKeyAccountId_t* v);
parser_error_t _readSecondaryKeyWithAuthAccountId(parser_context_t* c, pd_SecondaryKeyWithAuthAccountId_t* v);
parser_error_t _readSignatoryAccountId(parser_context_t* c, pd_SignatoryAccountId_t* v);
parser_error_t _readSystemOrigin(parser_context_t* c, pd_SystemOrigin_t* v);
parser_error_t _readTupleExtrinsicIdbool(parser_context_t* c, pd_TupleExtrinsicIdbool_t* v);
parser_error_t _readTupleIdentityIdbool(parser_context_t* c, pd_TupleIdentityIdbool_t* v);
parser_error_t _readTuplePipIdSnapshotResult(parser_context_t* c, pd_TuplePipIdSnapshotResult_t* v);
parser_error_t _readUrl(parser_context_t* c, pd_Url_t* v);
parser_error_t _readVecMotion(parser_context_t* c, pd_VecMotion_t* v);
parser_error_t _readVenueId(parser_context_t* c, pd_VenueId_t* v);
parser_error_t _readWeight(parser_context_t* c, pd_Weight_t* v);
parser_error_t _readAccountIdLookupOfT(parser_context_t* c, pd_AccountIdLookupOfT_t* v);
parser_error_t _readAssetMetadataName(parser_context_t* c, pd_AssetMetadataName_t* v);
parser_error_t _readAssetMetadataSpec(parser_context_t* c, pd_AssetMetadataSpec_t* v);
parser_error_t _readAssetMetadataValue(parser_context_t* c, pd_AssetMetadataValue_t* v);
parser_error_t _readAssetType(parser_context_t* c, pd_AssetType_t* v);
parser_error_t _readAuthorizationDataAccountId(parser_context_t* c, pd_AuthorizationDataAccountId_t* v);
parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v);
parser_error_t _readBallotMeta(parser_context_t* c, pd_BallotMeta_t* v);
parser_error_t _readBallotTimeRange(parser_context_t* c, pd_BallotTimeRange_t* v);
parser_error_t _readBoxPalletsOrigin(parser_context_t* c, pd_BoxPalletsOrigin_t* v);
parser_error_t _readCAId(parser_context_t* c, pd_CAId_t* v);
parser_error_t _readCodeHash(parser_context_t* c, pd_CodeHash_t* v);
parser_error_t _readInitiateCorporateActionArgs(parser_context_t* c, pd_InitiateCorporateActionArgs_t* v);
parser_error_t _readMaybeBlockBlockNumber(parser_context_t* c, pd_MaybeBlockBlockNumber_t* v);
parser_error_t _readOptionAssetMetadataValueDetailMoment(parser_context_t* c, pd_OptionAssetMetadataValueDetailMoment_t* v);
parser_error_t _readOptionPortfolioId(parser_context_t* c, pd_OptionPortfolioId_t* v);
parser_error_t _readOptionReceiptDetails(parser_context_t* c, pd_OptionReceiptDetails_t* v);
parser_error_t _readOptionTax(parser_context_t* c, pd_OptionTax_t* v);
parser_error_t _readOptionWeight(parser_context_t* c, pd_OptionWeight_t* v);
parser_error_t _readProposal(parser_context_t* c, pd_Proposal_t* v);
parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v);
parser_error_t _readScheduleCheckpoints(parser_context_t* c, pd_ScheduleCheckpoints_t* v);
parser_error_t _readSettlementTypeBlockNumber(parser_context_t* c, pd_SettlementTypeBlockNumber_t* v);
parser_error_t _readUniqueCall(parser_context_t* c, pd_UniqueCall_t* v);
parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v);
parser_error_t _readVecBallotVote(parser_context_t* c, pd_VecBallotVote_t* v);
parser_error_t _readVecBeneficiary(parser_context_t* c, pd_VecBeneficiary_t* v);
parser_error_t _readVecBridgeTxAccountId(parser_context_t* c, pd_VecBridgeTxAccountId_t* v);
parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v);
parser_error_t _readVecComplianceRequirement(parser_context_t* c, pd_VecComplianceRequirement_t* v);
parser_error_t _readVecCreateChildIdentityWithAuthAccountId(parser_context_t* c, pd_VecCreateChildIdentityWithAuthAccountId_t* v);
parser_error_t _readVecDocument(parser_context_t* c, pd_VecDocument_t* v);
parser_error_t _readVecFund(parser_context_t* c, pd_VecFund_t* v);
parser_error_t _readVecLeg(parser_context_t* c, pd_VecLeg_t* v);
parser_error_t _readVecLookupasStaticLookupSource(parser_context_t* c, pd_VecLookupasStaticLookupSource_t* v);
parser_error_t _readVecNFTMetadataAttribute(parser_context_t* c, pd_VecNFTMetadataAttribute_t* v);
parser_error_t _readVecPriceTier(parser_context_t* c, pd_VecPriceTier_t* v);
parser_error_t _readVecReceiptDetails(parser_context_t* c, pd_VecReceiptDetails_t* v);
parser_error_t _readVecSecondaryKeyAccountId(parser_context_t* c, pd_VecSecondaryKeyAccountId_t* v);
parser_error_t _readVecSecondaryKeyWithAuthAccountId(parser_context_t* c, pd_VecSecondaryKeyWithAuthAccountId_t* v);
parser_error_t _readVecSignatoryAccountId(parser_context_t* c, pd_VecSignatoryAccountId_t* v);
parser_error_t _readVecTupleExtrinsicIdbool(parser_context_t* c, pd_VecTupleExtrinsicIdbool_t* v);
parser_error_t _readVecTupleIdentityIdbool(parser_context_t* c, pd_VecTupleIdentityIdbool_t* v);
parser_error_t _readVecTuplePipIdSnapshotResult(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_t* v);
parser_error_t _readAGId(parser_context_t* c, pd_AGId_t* v);
parser_error_t _readAccountIndex(parser_context_t* c, pd_AccountIndex_t* v);
parser_error_t _readAssetMetadataLocalKey(parser_context_t* c, pd_AssetMetadataLocalKey_t* v);
parser_error_t _readAssetName(parser_context_t* c, pd_AssetName_t* v);
parser_error_t _readCADetails(parser_context_t* c, pd_CADetails_t* v);
parser_error_t _readDeterminism(parser_context_t* c, pd_Determinism_t* v);
parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v);
parser_error_t _readFundraiserId(parser_context_t* c, pd_FundraiserId_t* v);
parser_error_t _readFundraiserName(parser_context_t* c, pd_FundraiserName_t* v);
parser_error_t _readInstructionId(parser_context_t* c, pd_InstructionId_t* v);
parser_error_t _readKeys(parser_context_t* c, pd_Keys_t* v);
parser_error_t _readMemberCount(parser_context_t* c, pd_MemberCount_t* v);
parser_error_t _readNFTId(parser_context_t* c, pd_NFTId_t* v);
parser_error_t _readOptionBalance(parser_context_t* c, pd_OptionBalance_t* v);
parser_error_t _readOptionBlockNumber(parser_context_t* c, pd_OptionBlockNumber_t* v);
parser_error_t _readOptionCompactBalanceOf(parser_context_t* c, pd_OptionCompactBalanceOf_t* v);
parser_error_t _readOptionFundingRoundName(parser_context_t* c, pd_OptionFundingRoundName_t* v);
parser_error_t _readOptionNonFungibleType(parser_context_t* c, pd_OptionNonFungibleType_t* v);
parser_error_t _readOptionPipDescription(parser_context_t* c, pd_OptionPipDescription_t* v);
parser_error_t _readOptionPortfolioNumber(parser_context_t* c, pd_OptionPortfolioNumber_t* v);
parser_error_t _readOptionUrl(parser_context_t* c, pd_OptionUrl_t* v);
parser_error_t _readOptionu32(parser_context_t* c, pd_Optionu32_t* v);
parser_error_t _readOptionu64(parser_context_t* c, pd_Optionu64_t* v);
parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v);
parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v);
parser_error_t _readPortfolioName(parser_context_t* c, pd_PortfolioName_t* v);
parser_error_t _readPosRatio(parser_context_t* c, pd_PosRatio_t* v);
parser_error_t _readProposalIndex(parser_context_t* c, pd_ProposalIndex_t* v);
parser_error_t _readSkippedCount(parser_context_t* c, pd_SkippedCount_t* v);
parser_error_t _readSlashingSwitch(parser_context_t* c, pd_SlashingSwitch_t* v);
parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v);
parser_error_t _readVecAssetIdentifier(parser_context_t* c, pd_VecAssetIdentifier_t* v);
parser_error_t _readVecAssetMetadataKey(parser_context_t* c, pd_VecAssetMetadataKey_t* v);
parser_error_t _readVecDocumentId(parser_context_t* c, pd_VecDocumentId_t* v);
parser_error_t _readVecVenueId(parser_context_t* c, pd_VecVenueId_t* v);
parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v);
parser_error_t _readVecu8(parser_context_t* c, pd_Vecu8_t* v);
parser_error_t _readVenueDetails(parser_context_t* c, pd_VenueDetails_t* v);
parser_error_t _readVenueType(parser_context_t* c, pd_VenueType_t* v);

// Common toString functions

parser_error_t _toStringu8(
    const pd_u8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu16(
    const pd_u16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu32(
    const pd_u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringu64(
    const pd_u64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringbool(
    const pd_bool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringIdentityId(
    const pd_IdentityId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTicker(
    const pd_Ticker_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScope(
    const pd_Scope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCddId(
    const pd_CddId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaimType(
    const pd_ClaimType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCountryCode(
    const pd_CountryCode_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableName(
    const pd_DispatchableName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionScope(
    const pd_OptionScope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScopeId(
    const pd_ScopeId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioNumber(
    const pd_PortfolioNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleCountryCodeScope(
    const pd_TupleCountryCodeScope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleScopeScopeIdCddId(
    const pd_TupleScopeScopeIdCddId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleU32Scope(
    const pd_TupleU32Scope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaimType(
    const pd_VecClaimType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDispatchableName(
    const pd_VecDispatchableName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringClaim(
    const pd_Claim_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDispatchableNames(
    const pd_DispatchableNames_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletName(
    const pd_PalletName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioKind(
    const pd_PortfolioKind_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedFor(
    const pd_TrustedFor_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPalletPermissions(
    const pd_PalletPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermill(
    const pd_Permill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioId(
    const pd_PortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentity(
    const pd_TargetIdentity_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTrustedIssuer(
    const pd_TrustedIssuer_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecClaim(
    const pd_VecClaim_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringChoiceTitle(
    const pd_ChoiceTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringConditionType(
    const pd_ConditionType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEd25519Signature(
    const pd_Ed25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemo(
    const pd_Memo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSr25519Signature(
    const pd_Sr25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTax(
    const pd_Tax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPalletPermissions(
    const pd_VecPalletPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPortfolioId(
    const pd_VecPortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTicker(
    const pd_VecTicker_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTrustedIssuer(
    const pd_VecTrustedIssuer_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetPermissions(
    const pd_AssetPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceNoSymbol(
    const pd_BalanceNoSymbol_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCheckpointId(
    const pd_CheckpointId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCondition(
    const pd_Condition_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentType(
    const pd_DocumentType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringExtrinsicPermissions(
    const pd_ExtrinsicPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMoment(
    const pd_Moment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionInfoLink(
    const pd_MotionInfoLink_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotionTitle(
    const pd_MotionTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMultiSignature(
    const pd_MultiSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMemo(
    const pd_OptionMemo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioPermissions(
    const pd_PortfolioPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptMetadata(
    const pd_ReceiptMetadata_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleId(
    const pd_ScheduleId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetTreatment(
    const pd_TargetTreatment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdTax(
    const pd_TupleIdentityIdTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecChoiceTitle(
    const pd_VecChoiceTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecIdentityId(
    const pd_VecIdentityId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu64(
    const pd_Vecu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAgentGroup(
    const pd_AgentGroup_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataKey(
    const pd_AssetMetadataKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataLockStatusMoment(
    const pd_AssetMetadataLockStatusMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalance(
    const pd_Balance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBytes(
    const pd_Bytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactAccountIndex(
    const pd_CompactAccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentHash(
    const pd_DocumentHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentName(
    const pd_DocumentName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentUri(
    const pd_DocumentUri_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundFungible(
    const pd_FundFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundNonFungible(
    const pd_FundNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegFungible(
    const pd_LegFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegNonFungible(
    const pd_LegNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLegOffChain(
    const pd_LegOffChain_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMotion(
    const pd_Motion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOffChainSignature(
    const pd_OffChainSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionDocumentType(
    const pd_OptionDocumentType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionMoment(
    const pd_OptionMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptMetadata(
    const pd_OptionReceiptMetadata_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionu16(
    const pd_Optionu16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPermissions(
    const pd_Permissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipId(
    const pd_PipId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRecordDateSpec(
    const pd_RecordDateSpec_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignature(
    const pd_Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSnapshotResult(
    const pd_SnapshotResult_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTargetIdentities(
    const pd_TargetIdentities_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCondition(
    const pd_VecCondition_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdTax(
    const pd_VecTupleIdentityIdTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAddRelayerPayingKey(
    const pd_AddRelayerPayingKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetIdentifier(
    const pd_AssetIdentifier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataValueDetailMoment(
    const pd_AssetMetadataValueDetailMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTitle(
    const pd_BallotTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotVote(
    const pd_BallotVote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBecomeAgent(
    const pd_BecomeAgent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBeneficiary(
    const pd_Beneficiary_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBridgeTxAccountId(
    const pd_BridgeTxAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAKind(
    const pd_CAKind_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCall(
    const pd_Call_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactBalanceOf(
    const pd_CompactBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCompactPerBill(
    const pd_CompactPerBill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringComplianceRequirement(
    const pd_ComplianceRequirement_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCreateChildIdentityWithAuthAccountId(
    const pd_CreateChildIdentityWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCustomAssetTypeId(
    const pd_CustomAssetTypeId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocumentId(
    const pd_DocumentId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDocument(
    const pd_Document_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFund(
    const pd_Fund_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundingRoundName(
    const pd_FundingRoundName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLeg(
    const pd_Leg_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLocalCAId(
    const pd_LocalCAId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringLookupasStaticLookupSource(
    const pd_LookupasStaticLookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNFTMetadataAttribute(
    const pd_NFTMetadataAttribute_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNonFungibleType(
    const pd_NonFungibleType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBytes(
    const pd_OptionBytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPermill(
    const pd_OptionPermill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionRecordDateSpec(
    const pd_OptionRecordDateSpec_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTargetIdentities(
    const pd_OptionTargetIdentities_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionVecTupleIdentityIdTax(
    const pd_OptionVecTupleIdentityIdTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPipDescription(
    const pd_PipDescription_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPriceTier(
    const pd_PriceTier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringReceiptDetails(
    const pd_ReceiptDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyAccountId(
    const pd_SecondaryKeyAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSecondaryKeyWithAuthAccountId(
    const pd_SecondaryKeyWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSignatoryAccountId(
    const pd_SignatoryAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSystemOrigin(
    const pd_SystemOrigin_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleExtrinsicIdbool(
    const pd_TupleExtrinsicIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTupleIdentityIdbool(
    const pd_TupleIdentityIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringTuplePipIdSnapshotResult(
    const pd_TuplePipIdSnapshotResult_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUrl(
    const pd_Url_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecMotion(
    const pd_VecMotion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueId(
    const pd_VenueId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringWeight(
    const pd_Weight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIdLookupOfT(
    const pd_AccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataName(
    const pd_AssetMetadataName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataSpec(
    const pd_AssetMetadataSpec_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataValue(
    const pd_AssetMetadataValue_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetType(
    const pd_AssetType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAuthorizationDataAccountId(
    const pd_AuthorizationDataAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBalanceOf(
    const pd_BalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotMeta(
    const pd_BallotMeta_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBallotTimeRange(
    const pd_BallotTimeRange_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringBoxPalletsOrigin(
    const pd_BoxPalletsOrigin_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCAId(
    const pd_CAId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCodeHash(
    const pd_CodeHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInitiateCorporateActionArgs(
    const pd_InitiateCorporateActionArgs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMaybeBlockBlockNumber(
    const pd_MaybeBlockBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionAssetMetadataValueDetailMoment(
    const pd_OptionAssetMetadataValueDetailMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioId(
    const pd_OptionPortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionReceiptDetails(
    const pd_OptionReceiptDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionTax(
    const pd_OptionTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionWeight(
    const pd_OptionWeight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposal(
    const pd_Proposal_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringScheduleCheckpoints(
    const pd_ScheduleCheckpoints_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSettlementTypeBlockNumber(
    const pd_SettlementTypeBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringUniqueCall(
    const pd_UniqueCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBallotVote(
    const pd_VecBallotVote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBeneficiary(
    const pd_VecBeneficiary_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecBridgeTxAccountId(
    const pd_VecBridgeTxAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCall(
    const pd_VecCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecComplianceRequirement(
    const pd_VecComplianceRequirement_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecCreateChildIdentityWithAuthAccountId(
    const pd_VecCreateChildIdentityWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocument(
    const pd_VecDocument_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecFund(
    const pd_VecFund_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLeg(
    const pd_VecLeg_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecLookupasStaticLookupSource(
    const pd_VecLookupasStaticLookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecNFTMetadataAttribute(
    const pd_VecNFTMetadataAttribute_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecPriceTier(
    const pd_VecPriceTier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecReceiptDetails(
    const pd_VecReceiptDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyAccountId(
    const pd_VecSecondaryKeyAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSecondaryKeyWithAuthAccountId(
    const pd_VecSecondaryKeyWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecSignatoryAccountId(
    const pd_VecSignatoryAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleExtrinsicIdbool(
    const pd_VecTupleExtrinsicIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTupleIdentityIdbool(
    const pd_VecTupleIdentityIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecTuplePipIdSnapshotResult(
    const pd_VecTuplePipIdSnapshotResult_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAGId(
    const pd_AGId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAccountIndex(
    const pd_AccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetMetadataLocalKey(
    const pd_AssetMetadataLocalKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringAssetName(
    const pd_AssetName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringCADetails(
    const pd_CADetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringDeterminism(
    const pd_Determinism_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserId(
    const pd_FundraiserId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringFundraiserName(
    const pd_FundraiserName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringInstructionId(
    const pd_InstructionId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringKeys(
    const pd_Keys_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringMemberCount(
    const pd_MemberCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringNFTId(
    const pd_NFTId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBalance(
    const pd_OptionBalance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionBlockNumber(
    const pd_OptionBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionCompactBalanceOf(
    const pd_OptionCompactBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionFundingRoundName(
    const pd_OptionFundingRoundName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionNonFungibleType(
    const pd_OptionNonFungibleType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPipDescription(
    const pd_OptionPipDescription_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionPortfolioNumber(
    const pd_OptionPortfolioNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionUrl(
    const pd_OptionUrl_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionu32(
    const pd_Optionu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringOptionu64(
    const pd_Optionu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPerbill(
    const pd_Perbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPercent(
    const pd_Percent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPortfolioName(
    const pd_PortfolioName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringPosRatio(
    const pd_PosRatio_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringProposalIndex(
    const pd_ProposalIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSkippedCount(
    const pd_SkippedCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringSlashingSwitch(
    const pd_SlashingSwitch_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetIdentifier(
    const pd_VecAssetIdentifier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecAssetMetadataKey(
    const pd_VecAssetMetadataKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecDocumentId(
    const pd_VecDocumentId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecVenueId(
    const pd_VecVenueId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu32(
    const pd_Vecu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVecu8(
    const pd_Vecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueDetails(
    const pd_VenueDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

parser_error_t _toStringVenueType(
    const pd_VenueType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount);

#ifdef __cplusplus
}
#endif
