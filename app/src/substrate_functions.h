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
#include <stddef.h>
#include <stdint.h>

parser_error_t _readAddress(parser_context_t *c, pd_Address_t *v);

parser_error_t _readCompactBalance(parser_context_t *c, pd_CompactBalance_t *v);

parser_error_t _readHash(parser_context_t *c, pd_Hash_t *v);

parser_error_t _toStringAddress(const pd_Address_t *v, char *outValue,
                                uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringCompactBalance(const pd_CompactBalance_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringHash(const pd_Hash_t *v, char *outValue,
                             uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

// Read functions

parser_error_t _readIdentityId(parser_context_t *c, pd_IdentityId_t *v);
parser_error_t _readTicker(parser_context_t *c, pd_Ticker_t *v);
parser_error_t _readCountryCode(parser_context_t *c, pd_CountryCode_t *v);
parser_error_t _readScope(parser_context_t *c, pd_Scope_t *v);
parser_error_t _readScopeId(parser_context_t *c, pd_ScopeId_t *v);
parser_error_t _readCddId(parser_context_t *c, pd_CddId_t *v);
parser_error_t _readTupleCountryCodeScope(parser_context_t *c,
                                          pd_TupleCountryCodeScope_t *v);
parser_error_t _readTupleScopeScopeIdCddId(parser_context_t *c,
                                           pd_TupleScopeScopeIdCddId_t *v);
parser_error_t _readClaimType(parser_context_t *c, pd_ClaimType_t *v);
parser_error_t _readVecClaimType(parser_context_t *c, pd_VecClaimType_t *v);
parser_error_t _readPalletName(parser_context_t *c, pd_PalletName_t *v);
parser_error_t _readbool(parser_context_t *c, pd_bool_t *v);
parser_error_t _readDispatchableName(parser_context_t *c,
                                     pd_DispatchableName_t *v);
parser_error_t _readVecDispatchableName(parser_context_t *c,
                                        pd_VecDispatchableName_t *v);
parser_error_t _readPortfolioNumber(parser_context_t *c,
                                    pd_PortfolioNumber_t *v);
parser_error_t _readClaim(parser_context_t *c, pd_Claim_t *v);
parser_error_t _readVecClaim(parser_context_t *c, pd_VecClaim_t *v);
parser_error_t _readTargetIdentity(parser_context_t *c, pd_TargetIdentity_t *v);
parser_error_t _readTrustedFor(parser_context_t *c, pd_TrustedFor_t *v);
parser_error_t _readVecTicker(parser_context_t *c, pd_VecTicker_t *v);
parser_error_t _readOptionVecTicker(parser_context_t *c,
                                    pd_OptionVecTicker_t *v);
parser_error_t _readPalletPermissions(parser_context_t *c,
                                      pd_PalletPermissions_t *v);
parser_error_t _readVecPalletPermissions(parser_context_t *c,
                                         pd_VecPalletPermissions_t *v);
parser_error_t
_readOptionVecPalletPermissions(parser_context_t *c,
                                pd_OptionVecPalletPermissions_t *v);
parser_error_t _readVecPortfolioNumber(parser_context_t *c,
                                       pd_VecPortfolioNumber_t *v);
parser_error_t _readOptionVecPortfolioNumber(parser_context_t *c,
                                             pd_OptionVecPortfolioNumber_t *v);
parser_error_t _readPortfolioKind(parser_context_t *c, pd_PortfolioKind_t *v);
parser_error_t _readConditionType(parser_context_t *c, pd_ConditionType_t *v);
parser_error_t _readTrustedIssuer(parser_context_t *c, pd_TrustedIssuer_t *v);
parser_error_t _readVecTrustedIssuer(parser_context_t *c,
                                     pd_VecTrustedIssuer_t *v);
parser_error_t _readCompactPerBill(parser_context_t *c, pd_CompactPerBill_t *v);
parser_error_t _readAccountId(parser_context_t *c, pd_AccountId_t *v);
parser_error_t _readBalance(parser_context_t *c, pd_Balance_t *v);
parser_error_t _readBlockNumber(parser_context_t *c, pd_BlockNumber_t *v);
parser_error_t _readPermissions(parser_context_t *c, pd_Permissions_t *v);
parser_error_t _readPortfolioId(parser_context_t *c, pd_PortfolioId_t *v);
parser_error_t _readMoment(parser_context_t *c, pd_Moment_t *v);
parser_error_t _readCondition(parser_context_t *c, pd_Condition_t *v);
parser_error_t _readVecCondition(parser_context_t *c, pd_VecCondition_t *v);
parser_error_t _readMotion(parser_context_t *c, pd_Motion_t *v);
parser_error_t _readVecMotion(parser_context_t *c, pd_VecMotion_t *v);
parser_error_t _readValidatorPrefs(parser_context_t *c, pd_ValidatorPrefs_t *v);
parser_error_t _readSignatory(parser_context_t *c, pd_Signatory_t *v);
parser_error_t _readVecSignatory(parser_context_t *c, pd_VecSignatory_t *v);
parser_error_t _readCodeHash(parser_context_t *c, pd_CodeHash_t *v);
parser_error_t _readBeneficiary(parser_context_t *c, pd_Beneficiary_t *v);
parser_error_t _readVecBeneficiary(parser_context_t *c, pd_VecBeneficiary_t *v);
parser_error_t _readMaybeBlock(parser_context_t *c, pd_MaybeBlock_t *v);
parser_error_t _readAuthorizationData(parser_context_t *c,
                                      pd_AuthorizationData_t *v);
parser_error_t _readTargetIdAuthorization(parser_context_t *c,
                                          pd_TargetIdAuthorization_t *v);
parser_error_t _readBridgeTx(parser_context_t *c, pd_BridgeTx_t *v);
parser_error_t _readVecBridgeTx(parser_context_t *c, pd_VecBridgeTx_t *v);
parser_error_t _readComplianceRequirement(parser_context_t *c,
                                          pd_ComplianceRequirement_t *v);
parser_error_t _readVecComplianceRequirement(parser_context_t *c,
                                             pd_VecComplianceRequirement_t *v);
parser_error_t _readBallot(parser_context_t *c, pd_Ballot_t *v);
parser_error_t _readSettlementType(parser_context_t *c, pd_SettlementType_t *v);
parser_error_t _readLeg(parser_context_t *c, pd_Leg_t *v);
parser_error_t _readVecLeg(parser_context_t *c, pd_VecLeg_t *v);
parser_error_t _readVecPortfolioId(parser_context_t *c, pd_VecPortfolioId_t *v);
parser_error_t _readMovePortfolioItem(parser_context_t *c,
                                      pd_MovePortfolioItem_t *v);
parser_error_t _readVecMovePortfolioItem(parser_context_t *c,
                                         pd_VecMovePortfolioItem_t *v);
parser_error_t _readPerbill(parser_context_t *c, pd_Perbill_t *v);
parser_error_t _readBytes(parser_context_t *c, pd_Bytes_t *v);
parser_error_t _readu64(parser_context_t *c, pd_u64_t *v);
parser_error_t _readChangesTrieConfiguration(parser_context_t *c,
                                             pd_ChangesTrieConfiguration_t *v);
parser_error_t
_readOptionChangesTrieConfiguration(parser_context_t *c,
                                    pd_OptionChangesTrieConfiguration_t *v);
parser_error_t _readKeyValue(parser_context_t *c, pd_KeyValue_t *v);
parser_error_t _readVecKeyValue(parser_context_t *c, pd_VecKeyValue_t *v);
parser_error_t _readKey(parser_context_t *c, pd_Key_t *v);
parser_error_t _readVecKey(parser_context_t *c, pd_VecKey_t *v);
parser_error_t _readu32(parser_context_t *c, pd_u32_t *v);
parser_error_t _readEquivocationProof(parser_context_t *c,
                                      pd_EquivocationProof_t *v);
parser_error_t _readKeyOwnerProof(parser_context_t *c, pd_KeyOwnerProof_t *v);
parser_error_t _readCompactMoment(parser_context_t *c, pd_CompactMoment_t *v);
parser_error_t _readAccountIndex(parser_context_t *c, pd_AccountIndex_t *v);
parser_error_t _readLookupSource(parser_context_t *c, pd_LookupSource_t *v);
parser_error_t _readMemo(parser_context_t *c, pd_Memo_t *v);
parser_error_t _readOptionMemo(parser_context_t *c, pd_OptionMemo_t *v);
parser_error_t _readHeader(parser_context_t *c, pd_Header_t *v);
parser_error_t _readVecHeader(parser_context_t *c, pd_VecHeader_t *v);
parser_error_t _readCompactBalanceOf(parser_context_t *c,
                                     pd_CompactBalanceOf_t *v);
parser_error_t _readRewardDestination(parser_context_t *c,
                                      pd_RewardDestination_t *v);
parser_error_t _readVecLookupSource(parser_context_t *c,
                                    pd_VecLookupSource_t *v);
parser_error_t _readCompactu32(parser_context_t *c, pd_Compactu32_t *v);
parser_error_t _readPercent(parser_context_t *c, pd_Percent_t *v);
parser_error_t _readVecAccountId(parser_context_t *c, pd_VecAccountId_t *v);
parser_error_t _readBalanceOf(parser_context_t *c, pd_BalanceOf_t *v);
parser_error_t _readEraIndex(parser_context_t *c, pd_EraIndex_t *v);
parser_error_t _readVecu32(parser_context_t *c, pd_Vecu32_t *v);
parser_error_t _readCompactEraIndex(parser_context_t *c,
                                    pd_CompactEraIndex_t *v);
parser_error_t _readValidatorIndex(parser_context_t *c, pd_ValidatorIndex_t *v);
parser_error_t _readVecValidatorIndex(parser_context_t *c,
                                      pd_VecValidatorIndex_t *v);
parser_error_t _readCompactAssignments(parser_context_t *c,
                                       pd_CompactAssignments_t *v);
parser_error_t _readElectionScore(parser_context_t *c, pd_ElectionScore_t *v);
parser_error_t _readElectionSize(parser_context_t *c, pd_ElectionSize_t *v);
parser_error_t _readSlashingSwitch(parser_context_t *c, pd_SlashingSwitch_t *v);
parser_error_t _readKeys(parser_context_t *c, pd_Keys_t *v);
parser_error_t _readCompactBlockNumber(parser_context_t *c,
                                       pd_CompactBlockNumber_t *v);
parser_error_t _readHeartbeat(parser_context_t *c, pd_Heartbeat_t *v);
parser_error_t _readSignature(parser_context_t *c, pd_Signature_t *v);
parser_error_t _readOfflineSlashingParams(parser_context_t *c,
                                          pd_OfflineSlashingParams_t *v);
parser_error_t _readCall(parser_context_t *c, pd_Call_t *v);
parser_error_t _readWeight(parser_context_t *c, pd_Weight_t *v);
parser_error_t _readOptionMoment(parser_context_t *c, pd_OptionMoment_t *v);
parser_error_t _readOptionu64(parser_context_t *c, pd_Optionu64_t *v);
parser_error_t _readSchedule(parser_context_t *c, pd_Schedule_t *v);
parser_error_t _readTemplateMetadata(parser_context_t *c,
                                     pd_TemplateMetadata_t *v);
parser_error_t _readCompactGas(parser_context_t *c, pd_CompactGas_t *v);
parser_error_t _readOptionBalanceOf(parser_context_t *c,
                                    pd_OptionBalanceOf_t *v);
parser_error_t _readMetaUrl(parser_context_t *c, pd_MetaUrl_t *v);
parser_error_t _readOptionMetaUrl(parser_context_t *c, pd_OptionMetaUrl_t *v);
parser_error_t _readCompactProposalIndex(parser_context_t *c,
                                         pd_CompactProposalIndex_t *v);
parser_error_t _readProposalIndex(parser_context_t *c, pd_ProposalIndex_t *v);
parser_error_t _readMemberCount(parser_context_t *c, pd_MemberCount_t *v);
parser_error_t _readVecIdentityId(parser_context_t *c, pd_VecIdentityId_t *v);
parser_error_t _readSkippedCount(parser_context_t *c, pd_SkippedCount_t *v);
parser_error_t _readUrl(parser_context_t *c, pd_Url_t *v);
parser_error_t _readOptionUrl(parser_context_t *c, pd_OptionUrl_t *v);
parser_error_t _readPipDescription(parser_context_t *c, pd_PipDescription_t *v);
parser_error_t _readOptionPipDescription(parser_context_t *c,
                                         pd_OptionPipDescription_t *v);
parser_error_t _readPipId(parser_context_t *c, pd_PipId_t *v);
parser_error_t _readOptionBlockNumber(parser_context_t *c,
                                      pd_OptionBlockNumber_t *v);
parser_error_t _readTuplePipIdSnapshotResult(parser_context_t *c,
                                             pd_TuplePipIdSnapshotResult_t *v);
parser_error_t
_readVecTuplePipIdSnapshotResult(parser_context_t *c,
                                 pd_VecTuplePipIdSnapshotResult_t *v);
parser_error_t _readAssetName(parser_context_t *c, pd_AssetName_t *v);
parser_error_t _readAssetType(parser_context_t *c, pd_AssetType_t *v);
parser_error_t _readAssetIdentifier(parser_context_t *c,
                                    pd_AssetIdentifier_t *v);
parser_error_t _readVecAssetIdentifier(parser_context_t *c,
                                       pd_VecAssetIdentifier_t *v);
parser_error_t _readFundingRoundName(parser_context_t *c,
                                     pd_FundingRoundName_t *v);
parser_error_t _readOptionFundingRoundName(parser_context_t *c,
                                           pd_OptionFundingRoundName_t *v);
parser_error_t _readDocument(parser_context_t *c, pd_Document_t *v);
parser_error_t _readVecDocument(parser_context_t *c, pd_VecDocument_t *v);
parser_error_t _readDocumentId(parser_context_t *c, pd_DocumentId_t *v);
parser_error_t _readVecDocumentId(parser_context_t *c, pd_VecDocumentId_t *v);
parser_error_t _readSmartExtension(parser_context_t *c, pd_SmartExtension_t *v);
parser_error_t _readEcdsaSignature(parser_context_t *c, pd_EcdsaSignature_t *v);
parser_error_t _readClassicTickerImport(parser_context_t *c,
                                        pd_ClassicTickerImport_t *v);
parser_error_t _readTickerRegistrationConfig(parser_context_t *c,
                                             pd_TickerRegistrationConfig_t *v);
parser_error_t _readCheckpointId(parser_context_t *c, pd_CheckpointId_t *v);
parser_error_t _readInvestorUid(parser_context_t *c, pd_InvestorUid_t *v);
parser_error_t _readSecondaryKey(parser_context_t *c, pd_SecondaryKey_t *v);
parser_error_t _readVecSecondaryKey(parser_context_t *c,
                                    pd_VecSecondaryKey_t *v);
parser_error_t _readLegacyPermissions(parser_context_t *c,
                                      pd_LegacyPermissions_t *v);
parser_error_t _readSecondaryKeyWithAuth(parser_context_t *c,
                                         pd_SecondaryKeyWithAuth_t *v);
parser_error_t _readVecSecondaryKeyWithAuth(parser_context_t *c,
                                            pd_VecSecondaryKeyWithAuth_t *v);
parser_error_t _readInvestorZKProofData(parser_context_t *c,
                                        pd_InvestorZKProofData_t *v);
parser_error_t _readTupleIdentityIdbool(parser_context_t *c,
                                        pd_TupleIdentityIdbool_t *v);
parser_error_t _readVecTupleIdentityIdbool(parser_context_t *c,
                                           pd_VecTupleIdentityIdbool_t *v);
parser_error_t _readVecBalance(parser_context_t *c, pd_VecBalance_t *v);
parser_error_t _readu128(parser_context_t *c, pd_u128_t *v);
parser_error_t _readu16(parser_context_t *c, pd_u16_t *v);
parser_error_t _readVenueDetails(parser_context_t *c, pd_VenueDetails_t *v);
parser_error_t _readVenueType(parser_context_t *c, pd_VenueType_t *v);
parser_error_t _readOptionVenueDetails(parser_context_t *c,
                                       pd_OptionVenueDetails_t *v);
parser_error_t _readOptionVenueType(parser_context_t *c,
                                    pd_OptionVenueType_t *v);
parser_error_t _readReceiptDetails(parser_context_t *c, pd_ReceiptDetails_t *v);
parser_error_t _readVecReceiptDetails(parser_context_t *c,
                                      pd_VecReceiptDetails_t *v);
parser_error_t _readVecu64(parser_context_t *c, pd_Vecu64_t *v);
parser_error_t _readPriceTier(parser_context_t *c, pd_PriceTier_t *v);
parser_error_t _readVecPriceTier(parser_context_t *c, pd_VecPriceTier_t *v);
parser_error_t _readOptionBalance(parser_context_t *c, pd_OptionBalance_t *v);
parser_error_t _readOptionReceiptDetails(parser_context_t *c,
                                         pd_OptionReceiptDetails_t *v);
parser_error_t _readPosRatio(parser_context_t *c, pd_PosRatio_t *v);
parser_error_t _readProtocolOp(parser_context_t *c, pd_ProtocolOp_t *v);
parser_error_t _readVecCall(parser_context_t *c, pd_VecCall_t *v);
parser_error_t _readOffChainSignature(parser_context_t *c,
                                      pd_OffChainSignature_t *v);
parser_error_t _readUniqueCall(parser_context_t *c, pd_UniqueCall_t *v);
parser_error_t _readPortfolioName(parser_context_t *c, pd_PortfolioName_t *v);
parser_error_t _readPeriod(parser_context_t *c, pd_Period_t *v);
parser_error_t _readOptionPeriod(parser_context_t *c, pd_OptionPeriod_t *v);
parser_error_t _readPriority(parser_context_t *c, pd_Priority_t *v);
parser_error_t _readTargetIdentities(parser_context_t *c,
                                     pd_TargetIdentities_t *v);
parser_error_t _readTax(parser_context_t *c, pd_Tax_t *v);
parser_error_t _readOptionTax(parser_context_t *c, pd_OptionTax_t *v);
parser_error_t _readCAKind(parser_context_t *c, pd_CAKind_t *v);
parser_error_t _readRecordDateSpec(parser_context_t *c, pd_RecordDateSpec_t *v);
parser_error_t _readOptionRecordDateSpec(parser_context_t *c,
                                         pd_OptionRecordDateSpec_t *v);
parser_error_t _readCADetails(parser_context_t *c, pd_CADetails_t *v);
parser_error_t _readOptionTargetIdentities(parser_context_t *c,
                                           pd_OptionTargetIdentities_t *v);
parser_error_t _readTupleIdentityIdTax(parser_context_t *c,
                                       pd_TupleIdentityIdTax_t *v);
parser_error_t _readVecTupleIdentityIdTax(parser_context_t *c,
                                          pd_VecTupleIdentityIdTax_t *v);
parser_error_t
_readOptionVecTupleIdentityIdTax(parser_context_t *c,
                                 pd_OptionVecTupleIdentityIdTax_t *v);
parser_error_t _readCAId(parser_context_t *c, pd_CAId_t *v);
parser_error_t _readBallotTimeRange(parser_context_t *c,
                                    pd_BallotTimeRange_t *v);
parser_error_t _readBallotMeta(parser_context_t *c, pd_BallotMeta_t *v);
parser_error_t _readBallotVote(parser_context_t *c, pd_BallotVote_t *v);
parser_error_t _readVecBallotVote(parser_context_t *c, pd_VecBallotVote_t *v);
parser_error_t _readOptionPortfolioNumber(parser_context_t *c,
                                          pd_OptionPortfolioNumber_t *v);
parser_error_t _readScheduleSpec(parser_context_t *c, pd_ScheduleSpec_t *v);
parser_error_t _readScheduleId(parser_context_t *c, pd_ScheduleId_t *v);

// toString functions

parser_error_t _toStringIdentityId(const pd_IdentityId_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringTicker(const pd_Ticker_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringCountryCode(const pd_CountryCode_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringScope(const pd_Scope_t *v, char *outValue,
                              uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringScopeId(const pd_ScopeId_t *v, char *outValue,
                                uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringCddId(const pd_CddId_t *v, char *outValue,
                              uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t
_toStringTupleCountryCodeScope(const pd_TupleCountryCodeScope_t *v,
                               char *outValue, uint16_t outValueLen,
                               uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringTupleScopeScopeIdCddId(const pd_TupleScopeScopeIdCddId_t *v,
                                char *outValue, uint16_t outValueLen,
                                uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringClaimType(const pd_ClaimType_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecClaimType(const pd_VecClaimType_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringPalletName(const pd_PalletName_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringbool(const pd_bool_t *v, char *outValue,
                             uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringDispatchableName(const pd_DispatchableName_t *v,
                                         char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecDispatchableName(const pd_VecDispatchableName_t *v,
                                            char *outValue,
                                            uint16_t outValueLen,
                                            uint8_t pageIdx,
                                            uint8_t *pageCount);

parser_error_t _toStringPortfolioNumber(const pd_PortfolioNumber_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringClaim(const pd_Claim_t *v, char *outValue,
                              uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringVecClaim(const pd_VecClaim_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringTargetIdentity(const pd_TargetIdentity_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringTrustedFor(const pd_TrustedFor_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringVecTicker(const pd_VecTicker_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringOptionVecTicker(const pd_OptionVecTicker_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPalletPermissions(const pd_PalletPermissions_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecPalletPermissions(const pd_VecPalletPermissions_t *v,
                                             char *outValue,
                                             uint16_t outValueLen,
                                             uint8_t pageIdx,
                                             uint8_t *pageCount);

parser_error_t
_toStringOptionVecPalletPermissions(const pd_OptionVecPalletPermissions_t *v,
                                    char *outValue, uint16_t outValueLen,
                                    uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecPortfolioNumber(const pd_VecPortfolioNumber_t *v,
                                           char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringOptionVecPortfolioNumber(const pd_OptionVecPortfolioNumber_t *v,
                                  char *outValue, uint16_t outValueLen,
                                  uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPortfolioKind(const pd_PortfolioKind_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringConditionType(const pd_ConditionType_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringTrustedIssuer(const pd_TrustedIssuer_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecTrustedIssuer(const pd_VecTrustedIssuer_t *v,
                                         char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactPerBill(const pd_CompactPerBill_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAccountId(const pd_AccountId_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringBalance(const pd_Balance_t *v, char *outValue,
                                uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringBlockNumber(const pd_BlockNumber_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringPermissions(const pd_Permissions_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringPortfolioId(const pd_PortfolioId_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringMoment(const pd_Moment_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringCondition(const pd_Condition_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecCondition(const pd_VecCondition_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringMotion(const pd_Motion_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringVecMotion(const pd_VecMotion_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringValidatorPrefs(const pd_ValidatorPrefs_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringSignatory(const pd_Signatory_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecSignatory(const pd_VecSignatory_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringCodeHash(const pd_CodeHash_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringBeneficiary(const pd_Beneficiary_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringVecBeneficiary(const pd_VecBeneficiary_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringMaybeBlock(const pd_MaybeBlock_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringAuthorizationData(const pd_AuthorizationData_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringTargetIdAuthorization(const pd_TargetIdAuthorization_t *v,
                               char *outValue, uint16_t outValueLen,
                               uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBridgeTx(const pd_BridgeTx_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringVecBridgeTx(const pd_VecBridgeTx_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t
_toStringComplianceRequirement(const pd_ComplianceRequirement_t *v,
                               char *outValue, uint16_t outValueLen,
                               uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringVecComplianceRequirement(const pd_VecComplianceRequirement_t *v,
                                  char *outValue, uint16_t outValueLen,
                                  uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBallot(const pd_Ballot_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringSettlementType(const pd_SettlementType_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringLeg(const pd_Leg_t *v, char *outValue,
                            uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringVecLeg(const pd_VecLeg_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringVecPortfolioId(const pd_VecPortfolioId_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringMovePortfolioItem(const pd_MovePortfolioItem_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecMovePortfolioItem(const pd_VecMovePortfolioItem_t *v,
                                             char *outValue,
                                             uint16_t outValueLen,
                                             uint8_t pageIdx,
                                             uint8_t *pageCount);

parser_error_t _toStringPerbill(const pd_Perbill_t *v, char *outValue,
                                uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringBytes(const pd_Bytes_t *v, char *outValue,
                              uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringu64(const pd_u64_t *v, char *outValue,
                            uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t
_toStringChangesTrieConfiguration(const pd_ChangesTrieConfiguration_t *v,
                                  char *outValue, uint16_t outValueLen,
                                  uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionChangesTrieConfiguration(
    const pd_OptionChangesTrieConfiguration_t *v, char *outValue,
    uint16_t outValueLen, uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeyValue(const pd_KeyValue_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringVecKeyValue(const pd_VecKeyValue_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringKey(const pd_Key_t *v, char *outValue,
                            uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringVecKey(const pd_VecKey_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringu32(const pd_u32_t *v, char *outValue,
                            uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringEquivocationProof(const pd_EquivocationProof_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeyOwnerProof(const pd_KeyOwnerProof_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactMoment(const pd_CompactMoment_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAccountIndex(const pd_AccountIndex_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringLookupSource(const pd_LookupSource_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringMemo(const pd_Memo_t *v, char *outValue,
                             uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringOptionMemo(const pd_OptionMemo_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringHeader(const pd_Header_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringVecHeader(const pd_VecHeader_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringCompactBalanceOf(const pd_CompactBalanceOf_t *v,
                                         char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringRewardDestination(const pd_RewardDestination_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecLookupSource(const pd_VecLookupSource_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactu32(const pd_Compactu32_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringPercent(const pd_Percent_t *v, char *outValue,
                                uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringVecAccountId(const pd_VecAccountId_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringBalanceOf(const pd_BalanceOf_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringEraIndex(const pd_EraIndex_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringVecu32(const pd_Vecu32_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringCompactEraIndex(const pd_CompactEraIndex_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringValidatorIndex(const pd_ValidatorIndex_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecValidatorIndex(const pd_VecValidatorIndex_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactAssignments(const pd_CompactAssignments_t *v,
                                           char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringElectionScore(const pd_ElectionScore_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringElectionSize(const pd_ElectionSize_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringSlashingSwitch(const pd_SlashingSwitch_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringKeys(const pd_Keys_t *v, char *outValue,
                             uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringCompactBlockNumber(const pd_CompactBlockNumber_t *v,
                                           char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringHeartbeat(const pd_Heartbeat_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringSignature(const pd_Signature_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t
_toStringOfflineSlashingParams(const pd_OfflineSlashingParams_t *v,
                               char *outValue, uint16_t outValueLen,
                               uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCall(const pd_Call_t *v, char *outValue,
                             uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringWeight(const pd_Weight_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringOptionMoment(const pd_OptionMoment_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringOptionu64(const pd_Optionu64_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringSchedule(const pd_Schedule_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringTemplateMetadata(const pd_TemplateMetadata_t *v,
                                         char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactGas(const pd_CompactGas_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringOptionBalanceOf(const pd_OptionBalanceOf_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringMetaUrl(const pd_MetaUrl_t *v, char *outValue,
                                uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringOptionMetaUrl(const pd_OptionMetaUrl_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCompactProposalIndex(const pd_CompactProposalIndex_t *v,
                                             char *outValue,
                                             uint16_t outValueLen,
                                             uint8_t pageIdx,
                                             uint8_t *pageCount);

parser_error_t _toStringProposalIndex(const pd_ProposalIndex_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringMemberCount(const pd_MemberCount_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringVecIdentityId(const pd_VecIdentityId_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringSkippedCount(const pd_SkippedCount_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringUrl(const pd_Url_t *v, char *outValue,
                            uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringOptionUrl(const pd_OptionUrl_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringPipDescription(const pd_PipDescription_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionPipDescription(const pd_OptionPipDescription_t *v,
                                             char *outValue,
                                             uint16_t outValueLen,
                                             uint8_t pageIdx,
                                             uint8_t *pageCount);

parser_error_t _toStringPipId(const pd_PipId_t *v, char *outValue,
                              uint16_t outValueLen, uint8_t pageIdx,
                              uint8_t *pageCount);

parser_error_t _toStringOptionBlockNumber(const pd_OptionBlockNumber_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringTuplePipIdSnapshotResult(const pd_TuplePipIdSnapshotResult_t *v,
                                  char *outValue, uint16_t outValueLen,
                                  uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringVecTuplePipIdSnapshotResult(const pd_VecTuplePipIdSnapshotResult_t *v,
                                     char *outValue, uint16_t outValueLen,
                                     uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringAssetName(const pd_AssetName_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringAssetType(const pd_AssetType_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringAssetIdentifier(const pd_AssetIdentifier_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecAssetIdentifier(const pd_VecAssetIdentifier_t *v,
                                           char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringFundingRoundName(const pd_FundingRoundName_t *v,
                                         char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringOptionFundingRoundName(const pd_OptionFundingRoundName_t *v,
                                char *outValue, uint16_t outValueLen,
                                uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringDocument(const pd_Document_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringVecDocument(const pd_VecDocument_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringDocumentId(const pd_DocumentId_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringVecDocumentId(const pd_VecDocumentId_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringSmartExtension(const pd_SmartExtension_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringEcdsaSignature(const pd_EcdsaSignature_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringClassicTickerImport(const pd_ClassicTickerImport_t *v,
                                            char *outValue,
                                            uint16_t outValueLen,
                                            uint8_t pageIdx,
                                            uint8_t *pageCount);

parser_error_t
_toStringTickerRegistrationConfig(const pd_TickerRegistrationConfig_t *v,
                                  char *outValue, uint16_t outValueLen,
                                  uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCheckpointId(const pd_CheckpointId_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringInvestorUid(const pd_InvestorUid_t *v, char *outValue,
                                    uint16_t outValueLen, uint8_t pageIdx,
                                    uint8_t *pageCount);

parser_error_t _toStringSecondaryKey(const pd_SecondaryKey_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringVecSecondaryKey(const pd_VecSecondaryKey_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringLegacyPermissions(const pd_LegacyPermissions_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringSecondaryKeyWithAuth(const pd_SecondaryKeyWithAuth_t *v,
                                             char *outValue,
                                             uint16_t outValueLen,
                                             uint8_t pageIdx,
                                             uint8_t *pageCount);

parser_error_t
_toStringVecSecondaryKeyWithAuth(const pd_VecSecondaryKeyWithAuth_t *v,
                                 char *outValue, uint16_t outValueLen,
                                 uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringInvestorZKProofData(const pd_InvestorZKProofData_t *v,
                                            char *outValue,
                                            uint16_t outValueLen,
                                            uint8_t pageIdx,
                                            uint8_t *pageCount);

parser_error_t _toStringTupleIdentityIdbool(const pd_TupleIdentityIdbool_t *v,
                                            char *outValue,
                                            uint16_t outValueLen,
                                            uint8_t pageIdx,
                                            uint8_t *pageCount);

parser_error_t
_toStringVecTupleIdentityIdbool(const pd_VecTupleIdentityIdbool_t *v,
                                char *outValue, uint16_t outValueLen,
                                uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecBalance(const pd_VecBalance_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringu128(const pd_u128_t *v, char *outValue,
                             uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringu16(const pd_u16_t *v, char *outValue,
                            uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringVenueDetails(const pd_VenueDetails_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringVenueType(const pd_VenueType_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringOptionVenueDetails(const pd_OptionVenueDetails_t *v,
                                           char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionVenueType(const pd_OptionVenueType_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringReceiptDetails(const pd_ReceiptDetails_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecReceiptDetails(const pd_VecReceiptDetails_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringVecu64(const pd_Vecu64_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringPriceTier(const pd_PriceTier_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringVecPriceTier(const pd_VecPriceTier_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringOptionBalance(const pd_OptionBalance_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionReceiptDetails(const pd_OptionReceiptDetails_t *v,
                                             char *outValue,
                                             uint16_t outValueLen,
                                             uint8_t pageIdx,
                                             uint8_t *pageCount);

parser_error_t _toStringPosRatio(const pd_PosRatio_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringProtocolOp(const pd_ProtocolOp_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringVecCall(const pd_VecCall_t *v, char *outValue,
                                uint16_t outValueLen, uint8_t pageIdx,
                                uint8_t *pageCount);

parser_error_t _toStringOffChainSignature(const pd_OffChainSignature_t *v,
                                          char *outValue, uint16_t outValueLen,
                                          uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringUniqueCall(const pd_UniqueCall_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringPortfolioName(const pd_PortfolioName_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringPeriod(const pd_Period_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringOptionPeriod(const pd_OptionPeriod_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringPriority(const pd_Priority_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

parser_error_t _toStringTargetIdentities(const pd_TargetIdentities_t *v,
                                         char *outValue, uint16_t outValueLen,
                                         uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringTax(const pd_Tax_t *v, char *outValue,
                            uint16_t outValueLen, uint8_t pageIdx,
                            uint8_t *pageCount);

parser_error_t _toStringOptionTax(const pd_OptionTax_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t _toStringCAKind(const pd_CAKind_t *v, char *outValue,
                               uint16_t outValueLen, uint8_t pageIdx,
                               uint8_t *pageCount);

parser_error_t _toStringRecordDateSpec(const pd_RecordDateSpec_t *v,
                                       char *outValue, uint16_t outValueLen,
                                       uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringOptionRecordDateSpec(const pd_OptionRecordDateSpec_t *v,
                                             char *outValue,
                                             uint16_t outValueLen,
                                             uint8_t pageIdx,
                                             uint8_t *pageCount);

parser_error_t _toStringCADetails(const pd_CADetails_t *v, char *outValue,
                                  uint16_t outValueLen, uint8_t pageIdx,
                                  uint8_t *pageCount);

parser_error_t
_toStringOptionTargetIdentities(const pd_OptionTargetIdentities_t *v,
                                char *outValue, uint16_t outValueLen,
                                uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringTupleIdentityIdTax(const pd_TupleIdentityIdTax_t *v,
                                           char *outValue, uint16_t outValueLen,
                                           uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringVecTupleIdentityIdTax(const pd_VecTupleIdentityIdTax_t *v,
                               char *outValue, uint16_t outValueLen,
                               uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringOptionVecTupleIdentityIdTax(const pd_OptionVecTupleIdentityIdTax_t *v,
                                     char *outValue, uint16_t outValueLen,
                                     uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringCAId(const pd_CAId_t *v, char *outValue,
                             uint16_t outValueLen, uint8_t pageIdx,
                             uint8_t *pageCount);

parser_error_t _toStringBallotTimeRange(const pd_BallotTimeRange_t *v,
                                        char *outValue, uint16_t outValueLen,
                                        uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringBallotMeta(const pd_BallotMeta_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringBallotVote(const pd_BallotVote_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _toStringVecBallotVote(const pd_VecBallotVote_t *v,
                                      char *outValue, uint16_t outValueLen,
                                      uint8_t pageIdx, uint8_t *pageCount);

parser_error_t
_toStringOptionPortfolioNumber(const pd_OptionPortfolioNumber_t *v,
                               char *outValue, uint16_t outValueLen,
                               uint8_t pageIdx, uint8_t *pageCount);

parser_error_t _toStringScheduleSpec(const pd_ScheduleSpec_t *v, char *outValue,
                                     uint16_t outValueLen, uint8_t pageIdx,
                                     uint8_t *pageCount);

parser_error_t _toStringScheduleId(const pd_ScheduleId_t *v, char *outValue,
                                   uint16_t outValueLen, uint8_t pageIdx,
                                   uint8_t *pageCount);

parser_error_t _readProposal(parser_context_t *c, pd_Proposal_t *v);
parser_error_t _toStringProposal(const pd_Proposal_t *v, char *outValue,
                                 uint16_t outValueLen, uint8_t pageIdx,
                                 uint8_t *pageCount);

#ifdef __cplusplus
}
#endif
