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
#include "bignum.h"
#include "coin.h"
#include "parser_impl.h"
#include "substrate_dispatch.h"

#include <stddef.h>
#include <stdint.h>
#include <zxmacros.h>

parser_error_t _readCompactAssignments(parser_context_t* c, pd_CompactAssignments_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactBlockNumber(parser_context_t* c, pd_CompactBlockNumber_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex(parser_context_t* c, pd_CompactEraIndex_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactGas(parser_context_t* c, pd_CompactGas_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment(parser_context_t* c, pd_CompactMoment_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactProposalIndex(parser_context_t* c, pd_CompactProposalIndex_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex(parser_context_t* c, pd_AccountIndex_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readAssetIdentifier(parser_context_t* c, pd_AssetIdentifier_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
    case 1:
        v->_len = 9;
        break;
    case 2:
        v->_len = 12;
        break;
    case 3:
        v->_len = 20;
        break;
    default:
        return parser_unexpected_value;
    }

    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readAssetName(parser_context_t* c, pd_AssetName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readAssetType(parser_context_t* c, pd_AssetType_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 9) {
        return parser_unexpected_value;
    }

    if (v->value == 9) {
        // Custom type
        compactInt_t clen;
        CHECK_ERROR(_readCompactInt(c, &clen))
        CHECK_ERROR(_getValue(&clen, &v->_len))
        v->_ptr = c->buffer + c->offset;
        CTX_CHECK_AND_ADVANCE(c, v->_len);
    }

    return parser_ok;
}

parser_error_t _readAuthorizationData(parser_context_t* c, pd_AuthorizationData_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId(c, &v->identityId))
        break;
    case 2:
    case 3:
    case 5:
    case 8:
    case 10:
        CHECK_INPUT();
        CHECK_ERROR(_readTicker(c, &v->ticker))
        break;
    case 4:
        CHECK_INPUT();
        CHECK_ERROR(_readAccountId(c, &v->accountId))
        break;
    case 6:
        CHECK_INPUT();
        CHECK_ERROR(_readPermissions(c, &v->permissions))
        break;
    case 7:
        CHECK_INPUT();
        CHECK_ERROR(_readPortfolioId(c, &v->portfolioId))
        break;
    case 9:
        // noData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v){
    GEN_DEF_READARRAY(16)
}

parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v){
    GEN_DEF_READARRAY(16)
}

parser_error_t _readBallotMeta(parser_context_t* c, pd_BallotMeta_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBallotTitle(c, &v->title))
    CHECK_ERROR(_readVecMotion(c, &v->motions))
    return parser_ok;
}

parser_error_t _readBallotTimeRange(parser_context_t* c, pd_BallotTimeRange_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readMoment(c, &v->start))
    CHECK_ERROR(_readMoment(c, &v->end))
    return parser_ok;
}

parser_error_t _readBallotTitle(parser_context_t* c, pd_BallotTitle_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readBallotVote(parser_context_t* c, pd_BallotVote_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->power))
    CHECK_ERROR(_readOptionu16(c, &v->fallback))
    return parser_ok;
}

parser_error_t _readBallot(parser_context_t* c, pd_Ballot_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readu64(c, &v->checkpointId))
    CHECK_ERROR(_readMoment(c, &v->votingStart))
    CHECK_ERROR(_readMoment(c, &v->votingEnd))
    CHECK_ERROR(_readVecMotion(c, &v->motions))
    return parser_ok;
}

parser_error_t _readBeneficiary(parser_context_t* c, pd_Beneficiary_t* v)
{
    CHECK_ERROR(_readIdentityId(c, &v->identity))
    CHECK_ERROR(_readBalance(c, &v->balance))
    return parser_ok;
}

parser_error_t _readBridgeTx(parser_context_t* c, pd_BridgeTx_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt32(c, &v->nonce))
    CHECK_ERROR(_readAccountId(c, &v->recipient))
    CHECK_ERROR(_readBalance(c, &v->value))
    CHECK_ERROR(_readHash(c, &v->txHash))

    return parser_ok;
}

parser_error_t _readBytes(parser_context_t* c, pd_Bytes_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);
    return parser_ok;
}

parser_error_t _readCADetails(parser_context_t* c, pd_CADetails_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readCAId(parser_context_t* c, pd_CAId_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readTicker(c, &v->ticker))
    CHECK_ERROR(_readLocalCAId(c, &v->local_id))
    return parser_ok;
}

parser_error_t _readCAKind(parser_context_t* c, pd_CAKind_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCalendarPeriod(parser_context_t* c, pd_CalendarPeriod_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCalendarUnit(c, &v->unit))
    CHECK_ERROR(_readOptionNonZeroU64(c, &v->amount))
    return parser_ok;
}

parser_error_t _readCalendarUnit(parser_context_t* c, pd_CalendarUnit_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCall(parser_context_t* c, pd_Call_t* v)
{
    return parser_not_supported;
}

parser_error_t _readCddId(parser_context_t* c, pd_CddId_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChangesTrieConfiguration(parser_context_t* c, pd_ChangesTrieConfiguration_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCheckpointId(parser_context_t* c, pd_CheckpointId_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readChoiceTitle(parser_context_t* c, pd_ChoiceTitle_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readClaimType(parser_context_t* c, pd_ClaimType_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readClaim(parser_context_t* c, pd_Claim_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Accredited
    case 1: // Affiliate
    case 2: // BuyLockup
    case 3: // SellLockup
    case 5: // KnowYourCustomer
    case 7: // Exempted
    case 8: // Blocked
        CHECK_ERROR(_readScope(c, &v->scope))
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_readCddId(c, &v->cddId))
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_readTupleCountryCodeScope(c, &v->jurisdiction))
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_readTupleScopeScopeIdCddId(c, &v->investorUniqueness))
        break;
    case 10: // NoData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readClassicTickerImport(parser_context_t* c, pd_ClassicTickerImport_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readEthereumAddress(c, &v->eth_owner))
    CHECK_ERROR(_readTicker(c, &v->ticker))
    CHECK_ERROR(_readBool(c, &v->is_contract))
    CHECK_ERROR(_readBool(c, &v->is_created))
    return parser_ok;
}

parser_error_t _readCodeHash(parser_context_t* c, pd_CodeHash_t* v)
{
    CHECK_ERROR(_readHash(c, &v->hash))
    return parser_ok;
}

parser_error_t _readCompactBalanceOf(parser_context_t* c, pd_CompactBalanceOf_t* v)
{
    return _readCompactBalance(c, v);
}

parser_error_t _readCompactPerBill(parser_context_t* c, pd_CompactPerBill_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readComplianceRequirement(parser_context_t* c, pd_ComplianceRequirement_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readVecCondition(c, &v->senderConditions))
    CHECK_ERROR(_readVecCondition(c, &v->receiverConditions))
    CHECK_ERROR(_readUInt32(c, &v->id))
    return parser_ok;
}

parser_error_t _readConditionType(parser_context_t* c, pd_ConditionType_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readClaim(c, &v->claim))
        break;
    case 2:
    case 3:
        CHECK_INPUT();
        CHECK_ERROR(_readVecClaim(c, &v->vecClaim))
        break;
    case 4:
        CHECK_INPUT();
        CHECK_ERROR(_readTargetIdentity(c, &v->identity))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readCondition(parser_context_t* c, pd_Condition_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readConditionType(c, &v->conditionType))
    CHECK_ERROR(_readVecTrustedIssuer(c, &v->issuers))
    return parser_ok;
}

parser_error_t _readCountryCode(parser_context_t* c, pd_CountryCode_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readDispatchableName(parser_context_t* c, pd_DispatchableName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentHash(parser_context_t* c, pd_DocumentHash_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentId(parser_context_t* c, pd_DocumentId_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readDocumentName(parser_context_t* c, pd_DocumentName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentType(parser_context_t* c, pd_DocumentType_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentUri(parser_context_t* c, pd_DocumentUri_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocument(parser_context_t* c, pd_Document_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readDocumentUri(c, &v->uri))
    CHECK_ERROR(_readDocumentHash(c, &v->content_hash))
    CHECK_ERROR(_readDocumentName(c, &v->name))
    CHECK_ERROR(_readOptionDocumentType(c, &v->doc_type))
    CHECK_ERROR(_readOptionMoment(c, &v->filing_date))
    return parser_ok;
}

parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v){
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore(parser_context_t* c, pd_ElectionScore_t* v)
{
    return parser_not_supported;
}

parser_error_t _readElectionSize(parser_context_t* c, pd_ElectionSize_t* v)
{
    CHECK_ERROR(_readCompactInt(c, &v->validators));
    CHECK_ERROR(_readCompactInt(c, &v->nominators));
    return parser_ok;
}

parser_error_t _readEquivocationProof(parser_context_t* c, pd_EquivocationProof_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress(parser_context_t* c, pd_EthereumAddress_t* v){
    GEN_DEF_READARRAY(20)
}

parser_error_t _readFundingRoundName(parser_context_t* c, pd_FundingRoundName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readHeader(parser_context_t* c, pd_Header_t* v)
{
    return parser_not_supported;
}

parser_error_t _readHeartbeat(parser_context_t* c, pd_Heartbeat_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityId(parser_context_t* c, pd_IdentityId_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readInvestorUid(parser_context_t* c, pd_InvestorUid_t* v){
    GEN_DEF_READARRAY(16)
}

parser_error_t _readInvestorZKProofData(parser_context_t* c, pd_InvestorZKProofData_t* v){
    GEN_DEF_READARRAY(64)
}

parser_error_t _readKeyOwnerProof(parser_context_t* c, pd_KeyOwnerProof_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue(parser_context_t* c, pd_KeyValue_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKey(parser_context_t* c, pd_Key_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys(parser_context_t* c, pd_Keys_t* v)
{
    GEN_DEF_READARRAY(4 * 32)
    return parser_ok;
}

parser_error_t _readLeg(parser_context_t* c, pd_Leg_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readPortfolioId(c, &v->from))
    CHECK_ERROR(_readPortfolioId(c, &v->to))
    CHECK_ERROR(_readTicker(c, &v->asset))
    CHECK_ERROR(_readBalance(c, &v->amount))

    return parser_ok;
}

parser_error_t _readLegacyPermissions(parser_context_t* c, pd_LegacyPermissions_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLocalCAId(parser_context_t* c, pd_LocalCAId_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readLookupSource(parser_context_t* c, pd_LookupSource_t* v)
{
    uint8_t len;
    CHECK_ERROR(_readUInt8(c, &len))
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readMaybeBlock(parser_context_t* c, pd_MaybeBlock_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_INPUT();
        CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
        break;
    case 1:
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMemberCount(parser_context_t* c, pd_MemberCount_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readMemo(parser_context_t* c, pd_Memo_t* v)
{
    v->_len = 32;
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readMetaDescription(parser_context_t* c, pd_MetaDescription_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMetaUrl(parser_context_t* c, pd_MetaUrl_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMetaVersion(parser_context_t* c, pd_MetaVersion_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMoment(parser_context_t* c, pd_Moment_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readMotionInfoLink(parser_context_t* c, pd_MotionInfoLink_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotionTitle(parser_context_t* c, pd_MotionTitle_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotion(parser_context_t* c, pd_Motion_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMotionTitle(c, &v->title))
    CHECK_ERROR(_readMotionInfoLink(c, &v->info_link))
    CHECK_ERROR(_readVecChoiceTitle(c, &v->choices))
    return parser_ok;
}

parser_error_t _readMovePortfolioItem(parser_context_t* c, pd_MovePortfolioItem_t* v)
{
    CHECK_ERROR(_readTicker(c, &v->ticker));
    CHECK_ERROR(_readBalance(c, &v->balance));
    return parser_ok;
}

parser_error_t _readNonZeroU64(parser_context_t* c, pd_NonZeroU64_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readOffChainSignature(parser_context_t* c, pd_OffChainSignature_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Ed25519
    case 1: // Sr25519
    case 2: // Ecdsa
        GEN_DEF_READARRAY(64)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readOfflineSlashingParams(parser_context_t* c, pd_OfflineSlashingParams_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->max_offline_percent))
    CHECK_ERROR(_readUInt32(c, &v->constant))
    CHECK_ERROR(_readUInt32(c, &v->max_slash_percent))
    return parser_ok;
}

parser_error_t _readPalletName(parser_context_t* c, pd_PalletName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPalletPermissions(parser_context_t* c, pd_PalletPermissions_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readPalletName(c, &v->palletName))
    CHECK_ERROR(_readOptionVecDispatchableName(c, &v->dispatchableNames))

    return parser_ok;
}

parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPeriod(parser_context_t* c, pd_Period_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPermill(parser_context_t* c, pd_Permill_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPermissions(parser_context_t* c, pd_Permissions_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionVecTicker(c, &v->asset))
    CHECK_ERROR(_readOptionVecPalletPermissions(c, &v->extrinsic))
    CHECK_ERROR(_readOptionVecPortfolioId(c, &v->portfolio))
    return parser_ok;
}

parser_error_t _readPipDescription(parser_context_t* c, pd_PipDescription_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPipId(parser_context_t* c, pd_PipId_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPortfolioId(parser_context_t* c, pd_PortfolioId_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId(c, &v->did))
    CHECK_ERROR(_readPortfolioKind(c, &v->kind))

    return parser_ok;
}

parser_error_t _readPortfolioKind(parser_context_t* c, pd_PortfolioKind_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readPortfolioNumber(c, &v->number))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readPortfolioName(parser_context_t* c, pd_PortfolioName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPortfolioNumber(parser_context_t* c, pd_PortfolioNumber_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPosRatio(parser_context_t* c, pd_PosRatio_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->numerator))
    CHECK_ERROR(_readUInt32(c, &v->denominator))
    return parser_ok;
}

parser_error_t _readPriceTier(parser_context_t* c, pd_PriceTier_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->total))
    CHECK_ERROR(_readBalance(c, &v->price))
    return parser_ok;
}

parser_error_t _readPriority(parser_context_t* c, pd_Priority_t* v)
{
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readProposalIndex(parser_context_t* c, pd_ProposalIndex_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readProtocolOp(parser_context_t* c, pd_ProtocolOp_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 16) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readReceiptDetails(parser_context_t* c, pd_ReceiptDetails_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readu64(c, &v->receipt_uid))
    CHECK_ERROR(_readu64(c, &v->leg_id))
    CHECK_ERROR(_readAccountId(c, &v->signer))
    CHECK_ERROR(_readOffChainSignature(c, &v->signature))
    CHECK_ERROR(_readReceiptMetadata(c, &v->metadata))
    return parser_ok;
}

parser_error_t _readReceiptMetadata(parser_context_t* c, pd_ReceiptMetadata_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readRecordDateSpec(parser_context_t* c, pd_RecordDateSpec_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_readMoment(c, &v->scheduled))
        break;
    case 1: // Existing
        CHECK_ERROR(_readCheckpointId(c, &v->existing))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readScheduleId(parser_context_t* c, pd_ScheduleId_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readScheduleSpec(parser_context_t* c, pd_ScheduleSpec_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionMoment(c, &v->start))
    CHECK_ERROR(_readCalendarPeriod(c, &v->period))
    return parser_ok;
}

parser_error_t _readSchedule(parser_context_t* c, pd_Schedule_t* v)
{
    return parser_not_supported;
}

parser_error_t _readScopeId(parser_context_t* c, pd_ScopeId_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readScope(parser_context_t* c, pd_Scope_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readIdentityId(c, &v->identity))
        break;
    case 1:
        CHECK_ERROR(_readTicker(c, &v->ticker))
        break;
    case 2: {
        compactInt_t clen;
        CHECK_ERROR(_readCompactInt(c, &clen))
        CHECK_ERROR(_getValue(&clen, &v->_len))
        GEN_DEF_READARRAY(v->_len)
        break;
    }
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSecondaryKeyWithAuth(parser_context_t* c, pd_SecondaryKeyWithAuth_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSecondaryKey(c, &v->secondary_key))
    CHECK_ERROR(_readSignature(c, &v->auth_signature))
    return parser_ok;
}

parser_error_t _readSecondaryKey(parser_context_t* c, pd_SecondaryKey_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSignatory(c, &v->signer))
    CHECK_ERROR(_readPermissions(c, &v->permissions))
    return parser_ok;
}

parser_error_t _readSettlementType(parser_context_t* c, pd_SettlementType_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignatory(parser_context_t* c, pd_Signatory_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId(c, &v->identity))
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readAccountId(c, &v->account))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignature(parser_context_t* c, pd_Signature_t* v){
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSkippedCount(parser_context_t* c, pd_SkippedCount_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readSlashingSwitch(parser_context_t* c, pd_SlashingSwitch_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readSmartExtensionName(parser_context_t* c, pd_SmartExtensionName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readSmartExtensionType(parser_context_t* c, pd_SmartExtensionType_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0: // TransferManager
    case 1: // Offerings
    case 2: // SmartWallet
        break;
    case 3: // Custom
    {
        compactInt_t clen;
        CHECK_ERROR(_readCompactInt(c, &clen))
        CHECK_ERROR(_getValue(&clen, &v->_len))
        GEN_DEF_READARRAY(v->_len)
        break;
    }
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSmartExtension(parser_context_t* c, pd_SmartExtension_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSmartExtensionType(c, &v->extension_type))
    CHECK_ERROR(_readSmartExtensionName(c, &v->extension_name))
    CHECK_ERROR(_readAccountId(c, &v->extension_id))
    CHECK_ERROR(_readBool(c, &v->is_archive))
    return parser_ok;
}

parser_error_t _readSnapshotResult(parser_context_t* c, pd_SnapshotResult_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readStreamDependency(parser_context_t* c, pd_StreamDependency_t* v)
{
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTargetIdAuthorization(parser_context_t* c, pd_TargetIdAuthorization_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId(c, &v->targetId))
    CHECK_ERROR(_readUInt64(c, &v->nonce))
    CHECK_ERROR(_readMoment(c, &v->expiresAt))

    return parser_ok;
}

parser_error_t _readTargetIdentities(parser_context_t* c, pd_TargetIdentities_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readVecIdentityId(c, &v->identities))
    CHECK_ERROR(_readTargetTreatment(c, &v->treatment))
    return parser_ok;
}

parser_error_t _readTargetIdentity(parser_context_t* c, pd_TargetIdentity_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId(c, &v->specific))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTargetTreatment(parser_context_t* c, pd_TargetTreatment_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTax(parser_context_t* c, pd_Tax_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPermill(c, &v->value))
    return parser_ok;
}

parser_error_t _readTemplateMetadata(parser_context_t* c, pd_TemplateMetadata_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionMetaUrl(c, &v->url))
    CHECK_ERROR(_readSmartExtensionType(c, &v->se_type))
    CHECK_ERROR(_readBalance(c, &v->usage_fee))
    CHECK_ERROR(_readMetaDescription(c, &v->description))
    CHECK_ERROR(_readMetaVersion(c, &v->version))
    return parser_ok;
}

parser_error_t _readTickerRegistrationConfig(parser_context_t* c, pd_TickerRegistrationConfig_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->max_ticker_length))
    CHECK_ERROR(_readOptionMoment(c, &v->registration_length))
    return parser_ok;
}

parser_error_t _readTicker(parser_context_t* c, pd_Ticker_t* v)
{
    v->_len = 12;
    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readTrustedFor(parser_context_t* c, pd_TrustedFor_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readVecClaimType(c, &v->claims))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedIssuer(parser_context_t* c, pd_TrustedIssuer_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readIdentityId(c, &v->issuer))
    CHECK_ERROR(_readTrustedFor(c, &v->trustedFor))
    return parser_ok;
}

parser_error_t _readTupleCountryCodeScope(parser_context_t* c, pd_TupleCountryCodeScope_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCountryCode(c, &v->country_code))
    CHECK_ERROR(_readScope(c, &v->scope))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdTax(parser_context_t* c, pd_TupleIdentityIdTax_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readIdentityId(c, &v->id))
    CHECK_ERROR(_readTax(c, &v->tax))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdbool(parser_context_t* c, pd_TupleIdentityIdbool_t* v)
{
    CHECK_ERROR(_readIdentityId(c, &v->identity))
    CHECK_ERROR(_readBool(c, &v->val))
    return parser_ok;
}

parser_error_t _readTuplePipIdSnapshotResult(parser_context_t* c, pd_TuplePipIdSnapshotResult_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPipId(c, &v->pip_id))
    CHECK_ERROR(_readSnapshotResult(c, &v->snapshot_result))
    return parser_ok;
}

parser_error_t _readTupleScopeScopeIdCddId(parser_context_t* c, pd_TupleScopeScopeIdCddId_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readScope(c, &v->scope))
    CHECK_ERROR(_readScopeId(c, &v->scopeId))
    CHECK_ERROR(_readCddId(c, &v->cddId))
    return parser_ok;
}

parser_error_t _readUniqueCall(parser_context_t* c, pd_UniqueCall_t* v)
{
    return parser_not_supported;
}

parser_error_t _readUrl(parser_context_t* c, pd_Url_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readValidatorIndex(parser_context_t* c, pd_ValidatorIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v)
{
    CHECK_INPUT();
    return _readCompactPerBill(c, &v->commission);
}

parser_error_t _readVenueDetails(parser_context_t* c, pd_VenueDetails_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readVenueType(parser_context_t* c, pd_VenueType_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 3) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readWeight(parser_context_t* c, pd_Weight_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readu128(parser_context_t* c, pd_u128_t* v){
    GEN_DEF_READARRAY(16)
}

parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v){
    GEN_DEF_READVECTOR(AccountId)
}

parser_error_t _readVecAssetIdentifier(parser_context_t* c, pd_VecAssetIdentifier_t* v){
    GEN_DEF_READVECTOR(AssetIdentifier)
}

parser_error_t _readVecBalance(parser_context_t* c, pd_VecBalance_t* v){
    GEN_DEF_READVECTOR(Balance)
}

parser_error_t _readVecBallotVote(parser_context_t* c, pd_VecBallotVote_t* v){
    GEN_DEF_READVECTOR(BallotVote)
}

parser_error_t _readVecBeneficiary(parser_context_t* c, pd_VecBeneficiary_t* v){
    GEN_DEF_READVECTOR(Beneficiary)
}

parser_error_t _readVecBridgeTx(parser_context_t* c, pd_VecBridgeTx_t* v){
    GEN_DEF_READVECTOR(BridgeTx)
}

parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v){
    GEN_DEF_READVECTOR(Call)
}

parser_error_t _readVecChoiceTitle(parser_context_t* c, pd_VecChoiceTitle_t* v){
    GEN_DEF_READVECTOR(ChoiceTitle)
}

parser_error_t _readVecClaimType(parser_context_t* c, pd_VecClaimType_t* v){
    GEN_DEF_READVECTOR(ClaimType)
}

parser_error_t _readVecClaim(parser_context_t* c, pd_VecClaim_t* v){
    GEN_DEF_READVECTOR(Claim)
}

parser_error_t _readVecComplianceRequirement(parser_context_t* c, pd_VecComplianceRequirement_t* v){
    GEN_DEF_READVECTOR(ComplianceRequirement)
}

parser_error_t _readVecCondition(parser_context_t* c, pd_VecCondition_t* v){
    GEN_DEF_READVECTOR(Condition)
}

parser_error_t _readVecDispatchableName(parser_context_t* c, pd_VecDispatchableName_t* v){
    GEN_DEF_READVECTOR(DispatchableName)
}

parser_error_t _readVecDocumentId(parser_context_t* c, pd_VecDocumentId_t* v){
    GEN_DEF_READVECTOR(DocumentId)
}

parser_error_t _readVecDocument(parser_context_t* c, pd_VecDocument_t* v){
    GEN_DEF_READVECTOR(Document)
}

parser_error_t _readVecHeader(parser_context_t* c, pd_VecHeader_t* v){
    GEN_DEF_READVECTOR(Header)
}

parser_error_t _readVecIdentityId(parser_context_t* c, pd_VecIdentityId_t* v){
    GEN_DEF_READVECTOR(IdentityId)
}

parser_error_t _readVecKeyValue(parser_context_t* c, pd_VecKeyValue_t* v){
    GEN_DEF_READVECTOR(KeyValue)
}

parser_error_t _readVecKey(parser_context_t* c, pd_VecKey_t* v){
    GEN_DEF_READVECTOR(Key)
}

parser_error_t _readVecLeg(parser_context_t* c, pd_VecLeg_t* v){
    GEN_DEF_READVECTOR(Leg)
}

parser_error_t _readVecLookupSource(parser_context_t* c, pd_VecLookupSource_t* v){
    GEN_DEF_READVECTOR(LookupSource)
}

parser_error_t _readVecMotion(parser_context_t* c, pd_VecMotion_t* v){
    GEN_DEF_READVECTOR(Motion)
}

parser_error_t _readVecMovePortfolioItem(parser_context_t* c, pd_VecMovePortfolioItem_t* v){
    GEN_DEF_READVECTOR(MovePortfolioItem)
}

parser_error_t _readVecPalletPermissions(parser_context_t* c, pd_VecPalletPermissions_t* v){
    GEN_DEF_READVECTOR(PalletPermissions)
}

parser_error_t _readVecPortfolioId(parser_context_t* c, pd_VecPortfolioId_t* v){
    GEN_DEF_READVECTOR(PortfolioId)
}

parser_error_t _readVecPriceTier(parser_context_t* c, pd_VecPriceTier_t* v){
    GEN_DEF_READVECTOR(PriceTier)
}

parser_error_t _readVecReceiptDetails(parser_context_t* c, pd_VecReceiptDetails_t* v){
    GEN_DEF_READVECTOR(ReceiptDetails)
}

parser_error_t _readVecSecondaryKeyWithAuth(parser_context_t* c, pd_VecSecondaryKeyWithAuth_t* v){
    GEN_DEF_READVECTOR(SecondaryKeyWithAuth)
}

parser_error_t _readVecSecondaryKey(parser_context_t* c, pd_VecSecondaryKey_t* v){
    GEN_DEF_READVECTOR(SecondaryKey)
}

parser_error_t _readVecSignatory(parser_context_t* c, pd_VecSignatory_t* v){
    GEN_DEF_READVECTOR(Signatory)
}

parser_error_t _readVecTicker(parser_context_t* c, pd_VecTicker_t* v){
    GEN_DEF_READVECTOR(Ticker)
}

parser_error_t _readVecTrustedIssuer(parser_context_t* c, pd_VecTrustedIssuer_t* v){
    GEN_DEF_READVECTOR(TrustedIssuer)
}

parser_error_t _readVecTupleIdentityIdTax(parser_context_t* c, pd_VecTupleIdentityIdTax_t* v){
    GEN_DEF_READVECTOR(TupleIdentityIdTax)
}

parser_error_t _readVecTupleIdentityIdbool(parser_context_t* c, pd_VecTupleIdentityIdbool_t* v){
    GEN_DEF_READVECTOR(TupleIdentityIdbool)
}

parser_error_t _readVecTuplePipIdSnapshotResult(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_t* v){
    GEN_DEF_READVECTOR(TuplePipIdSnapshotResult)
}

parser_error_t _readVecValidatorIndex(parser_context_t* c, pd_VecValidatorIndex_t* v){
    GEN_DEF_READVECTOR(ValidatorIndex)
}

parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v){
    GEN_DEF_READVECTOR(u32)
}

parser_error_t _readVecu64(parser_context_t* c, pd_Vecu64_t* v){
    GEN_DEF_READVECTOR(u64)
}

parser_error_t _readOptionBalanceOf(parser_context_t* c, pd_OptionBalanceOf_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBalanceOf(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBalance(parser_context_t* c, pd_OptionBalance_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBalance(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBlockNumber(parser_context_t* c, pd_OptionBlockNumber_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBlockNumber(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionChangesTrieConfiguration(parser_context_t* c, pd_OptionChangesTrieConfiguration_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionDocumentType(parser_context_t* c, pd_OptionDocumentType_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readDocumentType(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionFundingRoundName(parser_context_t* c, pd_OptionFundingRoundName_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readFundingRoundName(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMemo(parser_context_t* c, pd_OptionMemo_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMemo(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMetaUrl(parser_context_t* c, pd_OptionMetaUrl_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMetaUrl(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMoment(parser_context_t* c, pd_OptionMoment_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMoment(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionNonZeroU64(parser_context_t* c, pd_OptionNonZeroU64_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readNonZeroU64(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod(parser_context_t* c, pd_OptionPeriod_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPipDescription(parser_context_t* c, pd_OptionPipDescription_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPipDescription(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPortfolioNumber(parser_context_t* c, pd_OptionPortfolioNumber_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPortfolioNumber(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReceiptDetails(parser_context_t* c, pd_OptionReceiptDetails_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReceiptDetails(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionRecordDateSpec(parser_context_t* c, pd_OptionRecordDateSpec_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRecordDateSpec(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTargetIdentities(parser_context_t* c, pd_OptionTargetIdentities_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTargetIdentities(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTax(parser_context_t* c, pd_OptionTax_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTax(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionUrl(parser_context_t* c, pd_OptionUrl_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readUrl(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecDispatchableName(parser_context_t* c, pd_OptionVecDispatchableName_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecDispatchableName(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPalletPermissions(parser_context_t* c, pd_OptionVecPalletPermissions_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPalletPermissions(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPortfolioId(parser_context_t* c, pd_OptionVecPortfolioId_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPortfolioId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTicker(parser_context_t* c, pd_OptionVecTicker_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTicker(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTupleIdentityIdTax(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTupleIdentityIdTax(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVenueDetails(parser_context_t* c, pd_OptionVenueDetails_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVenueDetails(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVenueType(parser_context_t* c, pd_OptionVenueType_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVenueType(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu16(parser_context_t* c, pd_Optionu16_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu16(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu64(parser_context_t* c, pd_Optionu64_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu64(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactAssignments(
    const pd_CompactAssignments_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactBlockNumber(
    const pd_CompactBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactEraIndex(
    const pd_CompactEraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactGas(
    const pd_CompactGas_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment(
    const pd_CompactMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactProposalIndex(
    const pd_CompactProposalIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId(
    const pd_AccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex(
    const pd_AccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdentifier(
    const pd_AssetIdentifier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringAssetName(
    const pd_AssetName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringAssetType(
    const pd_AssetType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "EquityCommon");
        break;
    case 1:
        snprintf(outValue, outValueLen, "EquityPreferred");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Commodity");
        break;
    case 3:
        snprintf(outValue, outValueLen, "FixedIncome");
        break;
    case 4:
        snprintf(outValue, outValueLen, "REIT");
        break;
    case 5:
        snprintf(outValue, outValueLen, "Fund");
        break;
    case 6:
        snprintf(outValue, outValueLen, "RevenueShareAgreement");
        break;
    case 7:
        snprintf(outValue, outValueLen, "StructuredProduct");
        break;
    case 8:
        snprintf(outValue, outValueLen, "Derivative");
        break;
    case 9: {
        char bufferUI[v->_len + 1];
        MEMSET(bufferUI, 0, sizeof(bufferUI));
        MEMCPY(bufferUI, v->_ptr, v->_len);
        MEMSET(outValue, 0, outValueLen);

        asciify(bufferUI);
        pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
        break;
    }
    }

    return parser_ok;
}

parser_error_t _toStringAuthorizationData(
    const pd_AuthorizationData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
    case 1:
        CHECK_ERROR(_toStringIdentityId(&v->identityId, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 2:
    case 3:
    case 5:
    case 8:
    case 10:
        CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 4:
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 6:
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 7:
        CHECK_ERROR(_toStringPortfolioId(&v->portfolioId, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 9:
        snprintf(outValue, outValueLen, "NoData");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringBalanceOf(
    const pd_BalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    char bufferUI[200];
    MEMSET(outValue, 0, outValueLen);
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[100];
    const uint16_t bcdOutLen = sizeof(bcdOut);

    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen)) {
        return parser_unexpected_buffer_end;
    }

    // Format number
    if (intstr_to_fpstr_inplace(bufferUI, sizeof(bufferUI), COIN_AMOUNT_DECIMAL_PLACES) == 0) {
        return parser_unexpected_value;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringBalance(
    const pd_Balance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    char bufferUI[200];
    MEMSET(outValue, 0, outValueLen);
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[100];
    const uint16_t bcdOutLen = sizeof(bcdOut);

    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen)) {
        return parser_unexpected_buffer_end;
    }

    // Format number
    if (intstr_to_fpstr_inplace(bufferUI, sizeof(bufferUI), COIN_AMOUNT_DECIMAL_PLACES) == 0) {
        return parser_unexpected_value;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringBallotMeta(
    const pd_BallotMeta_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBallotTitle(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecMotion(&v->motions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBallotTitle(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecMotion(&v->motions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTimeRange(
    const pd_BallotTimeRange_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringMoment(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMoment(&v->end, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMoment(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMoment(&v->end, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTitle(
    const pd_BallotTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringBallotVote(
    const pd_BallotVote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBalance(&v->power, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionu16(&v->fallback, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalance(&v->power, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionu16(&v->fallback, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallot(
    const pd_Ballot_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringu64(&v->checkpointId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMoment(&v->votingStart, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringMoment(&v->votingEnd, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringVecMotion(&v->motions, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu64(&v->checkpointId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMoment(&v->votingStart, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringMoment(&v->votingEnd, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringVecMotion(&v->motions, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBeneficiary(
    const pd_Beneficiary_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBridgeTx(
    const pd_BridgeTx_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringu32(&v->nonce, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAccountId(&v->recipient, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->value, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringHash(&v->txHash, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->nonce, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAccountId(&v->recipient, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalance(&v->value, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringHash(&v->txHash, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBytes(
    const pd_Bytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(v->_len);
}

parser_error_t _toStringCADetails(
    const pd_CADetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringCAId(
    const pd_CAId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringLocalCAId(&v->local_id, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringLocalCAId(&v->local_id, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCAKind(
    const pd_CAKind_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "PredictableBenefit");
        break;
    case 1:
        snprintf(outValue, outValueLen, "UnpredictableBenfit");
        break;
    case 2:
        snprintf(outValue, outValueLen, "IssuerNotice");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Reorganization");
        break;
    case 4:
        snprintf(outValue, outValueLen, "Other");
        break;
    default:
        return parser_unexpected_value;
    }
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringCalendarPeriod(
    const pd_CalendarPeriod_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCalendarUnit(&v->unit, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionNonZeroU64(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCalendarUnit(&v->unit, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionNonZeroU64(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCalendarUnit(
    const pd_CalendarUnit_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Second");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Minute");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Hour");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Day");
        break;
    case 4:
        snprintf(outValue, outValueLen, "Week");
        break;
    case 5:
        snprintf(outValue, outValueLen, "Month");
        break;
    case 6:
        snprintf(outValue, outValueLen, "Year");
        break;
    default:
        return parser_unexpected_value;
    }
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringCall(
    const pd_Call_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringCddId(
    const pd_CddId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChangesTrieConfiguration(
    const pd_ChangesTrieConfiguration_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->digest_interval, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->digest_levels, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCheckpointId(
    const pd_CheckpointId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChoiceTitle(
    const pd_ChoiceTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringClaimType(
    const pd_ClaimType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Accredited
        snprintf(outValue, outValueLen, "Accredited");
        break;
    case 1: // Affiliate
        snprintf(outValue, outValueLen, "Affiliate");
        break;
    case 2: // BuyLockup
        snprintf(outValue, outValueLen, "BuyLockup");
        break;
    case 3: // SellLockup
        snprintf(outValue, outValueLen, "SellLockup");
        break;
    case 5: // KnowYourCustomer
        snprintf(outValue, outValueLen, "KnowYourCustomer");
        break;
    case 7: // Exempted
        snprintf(outValue, outValueLen, "Exempted");
        break;
    case 8: // Blocked
        snprintf(outValue, outValueLen, "Blocked");
        break;
    case 4: // CustomerDueDiligence
        snprintf(outValue, outValueLen, "CustomerDueDiligence");
        break;
    case 6: // Jurisdiction
        snprintf(outValue, outValueLen, "Jurisdiction");
        break;
    case 9: // InvestorUniqueness
        snprintf(outValue, outValueLen, "InvestorUniqueness");
        break;
    case 10: // NoData
        snprintf(outValue, outValueLen, "NoData");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringClaim(
    const pd_Claim_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Accredited
    case 1: // Affiliate
    case 2: // BuyLockup
    case 3: // SellLockup
    case 5: // KnowYourCustomer
    case 7: // Exempted
    case 8: // Blocked
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_toStringCddId(&v->cddId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_toStringTupleCountryCodeScope(&v->jurisdiction, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_toStringTupleScopeScopeIdCddId(&v->investorUniqueness, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 10: // NoData
        snprintf(outValue, outValueLen, "NoData");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringClassicTickerImport(
    const pd_ClassicTickerImport_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringEthereumAddress(&v->eth_owner, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_contract, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->is_created, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringEthereumAddress(&v->eth_owner, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, 0, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->is_contract, outValue, outValueLen, 0, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringbool(&v->is_created, outValue, outValueLen, 0, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCodeHash(
    const pd_CodeHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringHash(&v->hash, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactBalanceOf(
    const pd_CompactBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactBalance(v, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill(
    const pd_CompactPerBill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringComplianceRequirement(
    const pd_ComplianceRequirement_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringVecCondition(&v->senderConditions, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecCondition(&v->receiverConditions, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecCondition(&v->senderConditions, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecCondition(&v->receiverConditions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, 0, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringConditionType(
    const pd_ConditionType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    switch (v->value) {
    case 0: // IsPresent
    case 1: // IsAbsent
        CHECK_ERROR(_toStringClaim(&v->claim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // IsAnyOf
    case 3: // IsNoneOf
        CHECK_ERROR(_toStringVecClaim(&v->vecClaim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // IsIdentity
        CHECK_ERROR(_toStringTargetIdentity(&v->identity, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringCondition(
    const pd_Condition_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringConditionType(&v->conditionType, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecTrustedIssuer(&v->issuers, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringConditionType(&v->conditionType, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecTrustedIssuer(&v->issuers, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCountryCode(
    const pd_CountryCode_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    //TODO complete
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "AF");
        break;
    case 1:
        snprintf(outValue, outValueLen, "AX");
        break;
    case 2:
        snprintf(outValue, outValueLen, "AL");
        break;
    case 3:
        snprintf(outValue, outValueLen, "DZ");
        break;
    default:
        return parser_not_supported;
    }

    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringDispatchableName(
    const pd_DispatchableName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocumentHash(
    const pd_DocumentHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocumentId(
    const pd_DocumentId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDocumentName(
    const pd_DocumentName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocumentType(
    const pd_DocumentType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocumentUri(
    const pd_DocumentUri_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocument(
    const pd_Document_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringDocumentUri(&v->uri, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringDocumentHash(&v->content_hash, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringDocumentName(&v->name, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionDocumentType(&v->doc_type, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionMoment(&v->filing_date, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringDocumentUri(&v->uri, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringDocumentHash(&v->content_hash, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringDocumentName(&v->name, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionDocumentType(&v->doc_type, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionMoment(&v->filing_date, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore(
    const pd_ElectionScore_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringElectionSize(
    const pd_ElectionSize_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactInt(&v->validators, COIN_AMOUNT_DECIMAL_PLACES, 0, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactInt(&v->nominators, COIN_AMOUNT_DECIMAL_PLACES, 0, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactInt(&v->validators, COIN_AMOUNT_DECIMAL_PLACES, 0, outValue, outValueLen, 0, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactInt(&v->nominators, COIN_AMOUNT_DECIMAL_PLACES, 0, outValue, outValueLen, 0, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEquivocationProof(
    const pd_EquivocationProof_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex(
    const pd_EraIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress(
    const pd_EthereumAddress_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringFundingRoundName(
    const pd_FundingRoundName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringHeader(
    const pd_Header_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringHeartbeat(
    const pd_Heartbeat_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringIdentityId(
    const pd_IdentityId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringInvestorUid(
    const pd_InvestorUid_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(16)
}

parser_error_t _toStringInvestorZKProofData(
    const pd_InvestorZKProofData_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringKeyOwnerProof(
    const pd_KeyOwnerProof_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue(
    const pd_KeyValue_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey(
    const pd_Key_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys(
    const pd_Keys_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLeg(
    const pd_Leg_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringPortfolioId(&v->from, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioId(&v->to, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTicker(&v->asset, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringBalance(&v->amount, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPortfolioId(&v->from, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioId(&v->to, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTicker(&v->asset, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringBalance(&v->amount, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringLegacyPermissions(
    const pd_LegacyPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringLocalCAId(
    const pd_LocalCAId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringLookupSource(
    const pd_LookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMaybeBlock(
    const pd_MaybeBlock_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringBlockNumber(&v->blockNumber, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringMemberCount(
    const pd_MemberCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMemo(
    const pd_Memo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringMetaDescription(
    const pd_MetaDescription_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringMetaUrl(
    const pd_MetaUrl_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringMetaVersion(
    const pd_MetaVersion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMoment(
    const pd_Moment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMotionInfoLink(
    const pd_MotionInfoLink_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringMotionTitle(
    const pd_MotionTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringMotion(
    const pd_Motion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringMotionTitle(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMotionInfoLink(&v->info_link, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecChoiceTitle(&v->choices, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMotionTitle(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMotionInfoLink(&v->info_link, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecChoiceTitle(&v->choices, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMovePortfolioItem(
    const pd_MovePortfolioItem_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNonZeroU64(
    const pd_NonZeroU64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringOffChainSignature(
    const pd_OffChainSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Ed25519
    case 1: // Sr25519
    case 2: // Ecdsa
        GEN_DEF_TOSTRING_ARRAY(64)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringOfflineSlashingParams(
    const pd_OfflineSlashingParams_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringu32(&v->max_offline_percent, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->constant, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->max_slash_percent, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->max_offline_percent, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->constant, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->max_slash_percent, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPalletName(
    const pd_PalletName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringPalletPermissions(
    const pd_PalletPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPalletName(&v->palletName, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecDispatchableName(&v->dispatchableNames, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPalletName(&v->palletName, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecDispatchableName(&v->dispatchableNames, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPerbill(
    const pd_Perbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    MEMSET(outValue, 0, outValueLen);
    MEMSET(ratioBuffer, 0, sizeof(ratioBuffer));
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPercent(
    const pd_Percent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPeriod(
    const pd_Period_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPermill(
    const pd_Permill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    MEMSET(outValue, 0, outValueLen);
    MEMSET(ratioBuffer, 0, sizeof(ratioBuffer));
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 4) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPermissions(
    const pd_Permissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringOptionVecTicker(&v->asset, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecPalletPermissions(&v->extrinsic, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionVecPortfolioId(&v->portfolio, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionVecTicker(&v->asset, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecPalletPermissions(&v->extrinsic, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionVecPortfolioId(&v->portfolio, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPipDescription(
    const pd_PipDescription_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringPipId(
    const pd_PipId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPortfolioId(
    const pd_PortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId(&v->did, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioKind(&v->kind, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->did, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioKind(&v->kind, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPortfolioKind(
    const pd_PortfolioKind_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Default");
        break;
    case 1:
        _toStringPortfolioNumber(&v->number, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringPortfolioName(
    const pd_PortfolioName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringPortfolioNumber(
    const pd_PortfolioNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPosRatio(
    const pd_PosRatio_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->numerator, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->denominator, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->numerator, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->denominator, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPriceTier(
    const pd_PriceTier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBalance(&v->total, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->price, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalance(&v->total, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->price, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPriority(
    const pd_Priority_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency(&v->dependency, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringStreamDependency(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProposalIndex(
    const pd_ProposalIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProtocolOp(
    const pd_ProtocolOp_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "AssetRegisterTicker");
        break;
    case 1:
        snprintf(outValue, outValueLen, "AssetIssue");
        break;
    case 2:
        snprintf(outValue, outValueLen, "AssetAddDocument");
        break;
    case 3:
        snprintf(outValue, outValueLen, "AssetCreateAsset");
        break;
    case 4:
        snprintf(outValue, outValueLen, "AssetCreateCheckpointSchedule");
        break;
    case 5:
        snprintf(outValue, outValueLen, "DividendNew");
        break;
    case 6:
        snprintf(outValue, outValueLen, "ComplianceManagerAddComplianceRequirement");
        break;
    case 7:
        snprintf(outValue, outValueLen, "IdentityRegisterDid");
        break;
    case 8:
        snprintf(outValue, outValueLen, "IdentityCddRegisterDid");
        break;
    case 9:
        snprintf(outValue, outValueLen, "IdentityAddClaim");
        break;
    case 10:
        snprintf(outValue, outValueLen, "IdentitySetPrimaryKey");
        break;
    case 11:
        snprintf(outValue, outValueLen, "IdentityAddSecondaryKeysWithAuthorization");
        break;
    case 12:
        snprintf(outValue, outValueLen, "PipsPropose");
        break;
    case 13:
        snprintf(outValue, outValueLen, "VotingAddBallot");
        break;
    case 14:
        snprintf(outValue, outValueLen, "ContractsPutCode");
        break;
    case 15:
        snprintf(outValue, outValueLen, "BallotAttachBallot");
        break;
    case 16:
        snprintf(outValue, outValueLen, "DistributionDistribute");
        break;
    }

    return parser_ok;
}

parser_error_t _toStringReceiptDetails(
    const pd_ReceiptDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringu64(&v->receipt_uid, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->leg_id, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringAccountId(&v->signer, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOffChainSignature(&v->signature, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringReceiptMetadata(&v->metadata, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu64(&v->receipt_uid, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu64(&v->leg_id, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringAccountId(&v->signer, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOffChainSignature(&v->signature, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringReceiptMetadata(&v->metadata, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringReceiptMetadata(
    const pd_ReceiptMetadata_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringRecordDateSpec(
    const pd_RecordDateSpec_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_toStringMoment(&v->scheduled, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1: // Existing
        CHECK_ERROR(_toStringCheckpointId(&v->existing, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Staked");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Stash");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Controller");
        break;
    default:
        return parser_print_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringScheduleId(
    const pd_ScheduleId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringScheduleSpec(
    const pd_ScheduleSpec_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringOptionMoment(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCalendarPeriod(&v->period, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMoment(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCalendarPeriod(&v->period, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSchedule(
    const pd_Schedule_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringScopeId(
    const pd_ScopeId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringScope(
    const pd_Scope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringTicker(&v->ticker, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 2:
        GEN_DEF_TOSTRING_ARRAY(v->_len)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSecondaryKeyWithAuth(
    const pd_SecondaryKeyWithAuth_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSecondaryKey(&v->secondary_key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSignature(&v->auth_signature, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSecondaryKey(&v->secondary_key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSignature(&v->auth_signature, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSecondaryKey(
    const pd_SecondaryKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSignatory(&v->signer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSignatory(&v->signer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSettlementType(
    const pd_SettlementType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "SettleOnAffirmation");
        *pageCount = 1;
        break;
    case 1:
        _toStringBlockNumber(&v->blockNumber, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSignatory(
    const pd_Signatory_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringAccountId(&v->account, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSignature(
    const pd_Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSkippedCount(
    const pd_SkippedCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    uint16_t valu16 = (uint16_t)v->value;
    return _toStringu16(&valu16, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSlashingSwitch(
    const pd_SlashingSwitch_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Validator");
        break;
    case 1:
        snprintf(outValue, outValueLen, "ValidatorAndNominator");
        break;
    case 2:
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_unexpected_value;
    }
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringSmartExtensionName(
    const pd_SmartExtensionName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringSmartExtensionType(
    const pd_SmartExtensionType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "TransferManager");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Offerings");
        break;
    case 2:
        snprintf(outValue, outValueLen, "SmartWallet");
        break;
    case 3:
        GEN_DEF_TOSTRING_ARRAY(v->_len)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSmartExtension(
    const pd_SmartExtension_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringSmartExtensionType(&v->extension_type, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSmartExtensionName(&v->extension_name, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringAccountId(&v->extension_id, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->is_archive, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSmartExtensionType(&v->extension_type, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSmartExtensionName(&v->extension_name, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringAccountId(&v->extension_id, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringbool(&v->is_archive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSnapshotResult(
    const pd_SnapshotResult_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Approve");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Reject");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Skip");
        break;
    default:
        return parser_unexpected_value;
    }

    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringStreamDependency(
    const pd_StreamDependency_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->dependency_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->weight, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->is_exclusive, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdAuthorization(
    const pd_TargetIdAuthorization_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringIdentityId(&v->targetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringMoment(&v->expiresAt, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->targetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringMoment(&v->expiresAt, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdentities(
    const pd_TargetIdentities_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTargetTreatment(&v->treatment, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTargetTreatment(&v->treatment, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdentity(
    const pd_TargetIdentity_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "PrimaryIssuanceAgent");
        break;
    case 1:
        _toStringIdentityId(&v->specific, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTargetTreatment(
    const pd_TargetTreatment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Include");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Exclude");
        break;
    default:
        return parser_unexpected_value;
    }
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringTax(
    const pd_Tax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringPermill(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringTemplateMetadata(
    const pd_TemplateMetadata_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringOptionMetaUrl(&v->url, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSmartExtensionType(&v->se_type, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->usage_fee, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringMetaDescription(&v->description, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringMetaVersion(&v->version, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMetaUrl(&v->url, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSmartExtensionType(&v->se_type, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalance(&v->usage_fee, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringMetaDescription(&v->description, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringMetaVersion(&v->version, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTickerRegistrationConfig(
    const pd_TickerRegistrationConfig_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->max_ticker_length, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionMoment(&v->registration_length, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->max_ticker_length, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionMoment(&v->registration_length, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTicker(
    const pd_Ticker_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringTrustedFor(
    const pd_TrustedFor_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Any
        snprintf(outValue, outValueLen, "Any");
        *pageCount = 1;
        break;
    case 1: // Specific
        _toStringVecClaimType(&v->claims, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTrustedIssuer(
    const pd_TrustedIssuer_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId(&v->issuer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTrustedFor(&v->trustedFor, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->issuer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTrustedFor(&v->trustedFor, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleCountryCodeScope(
    const pd_TupleCountryCodeScope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCountryCode(&v->country_code, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCountryCode(&v->country_code, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdTax(
    const pd_TupleIdentityIdTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTax(&v->tax, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTax(&v->tax, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdbool(
    const pd_TupleIdentityIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTuplePipIdSnapshotResult(
    const pd_TuplePipIdSnapshotResult_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPipId(&v->pip_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSnapshotResult(&v->snapshot_result, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPipId(&v->pip_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSnapshotResult(&v->snapshot_result, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleScopeScopeIdCddId(
    const pd_TupleScopeScopeIdCddId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScopeId(&v->scopeId, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCddId(&v->cddId, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScopeId(&v->scopeId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCddId(&v->cddId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUniqueCall(
    const pd_UniqueCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringUrl(
    const pd_Url_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringValidatorIndex(
    const pd_ValidatorIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactPerBill(&v->commission, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVenueDetails(
    const pd_VenueDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    MEMSET(bufferUI, 0, sizeof(bufferUI));
    MEMCPY(bufferUI, v->_ptr, v->_len);
    MEMSET(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringVenueType(
    const pd_VenueType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Other");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Distribution");
        break;
    case 2:
        snprintf(outValue, outValueLen, "Sto");
        break;
    case 3:
        snprintf(outValue, outValueLen, "Exchange");
        break;
    }
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringWeight(
    const pd_Weight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringu128(
    const pd_u128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    char bufferUI[200];
    MEMZERO(outValue, outValueLen);
    MEMZERO(bufferUI, sizeof(bufferUI));
    *pageCount = 1;

    uint8_t bcdOut[100];
    const uint16_t bcdOutLen = sizeof(bcdOut);
    bignumLittleEndian_to_bcd(bcdOut, bcdOutLen, v->_ptr, 16);
    if (!bignumLittleEndian_bcdprint(bufferUI, sizeof(bufferUI), bcdOut, bcdOutLen))
        return parser_unexpected_buffer_end;

    // Format number
    if (intstr_to_fpstr_inplace(bufferUI, sizeof(bufferUI), 0) == 0) {
        return parser_unexpected_value;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringVecAccountId(
    const pd_VecAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId);
}

parser_error_t _toStringVecAssetIdentifier(
    const pd_VecAssetIdentifier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdentifier);
}

parser_error_t _toStringVecBalance(
    const pd_VecBalance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Balance);
}

parser_error_t _toStringVecBallotVote(
    const pd_VecBallotVote_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BallotVote);
}

parser_error_t _toStringVecBeneficiary(
    const pd_VecBeneficiary_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Beneficiary);
}

parser_error_t _toStringVecBridgeTx(
    const pd_VecBridgeTx_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BridgeTx);
}

parser_error_t _toStringVecCall(
    const pd_VecCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Call);
}

parser_error_t _toStringVecChoiceTitle(
    const pd_VecChoiceTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ChoiceTitle);
}

parser_error_t _toStringVecClaimType(
    const pd_VecClaimType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ClaimType);
}

parser_error_t _toStringVecClaim(
    const pd_VecClaim_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Claim);
}

parser_error_t _toStringVecComplianceRequirement(
    const pd_VecComplianceRequirement_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ComplianceRequirement);
}

parser_error_t _toStringVecCondition(
    const pd_VecCondition_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Condition);
}

parser_error_t _toStringVecDispatchableName(
    const pd_VecDispatchableName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DispatchableName);
}

parser_error_t _toStringVecDocumentId(
    const pd_VecDocumentId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DocumentId);
}

parser_error_t _toStringVecDocument(
    const pd_VecDocument_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Document);
}

parser_error_t _toStringVecHeader(
    const pd_VecHeader_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Header);
}

parser_error_t _toStringVecIdentityId(
    const pd_VecIdentityId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(IdentityId);
}

parser_error_t _toStringVecKeyValue(
    const pd_VecKeyValue_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue);
}

parser_error_t _toStringVecKey(
    const pd_VecKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key);
}

parser_error_t _toStringVecLeg(
    const pd_VecLeg_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Leg);
}

parser_error_t _toStringVecLookupSource(
    const pd_VecLookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupSource);
}

parser_error_t _toStringVecMotion(
    const pd_VecMotion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Motion);
}

parser_error_t _toStringVecMovePortfolioItem(
    const pd_VecMovePortfolioItem_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MovePortfolioItem);
}

parser_error_t _toStringVecPalletPermissions(
    const pd_VecPalletPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PalletPermissions);
}

parser_error_t _toStringVecPortfolioId(
    const pd_VecPortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PortfolioId);
}

parser_error_t _toStringVecPriceTier(
    const pd_VecPriceTier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PriceTier);
}

parser_error_t _toStringVecReceiptDetails(
    const pd_VecReceiptDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ReceiptDetails);
}

parser_error_t _toStringVecSecondaryKeyWithAuth(
    const pd_VecSecondaryKeyWithAuth_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKeyWithAuth);
}

parser_error_t _toStringVecSecondaryKey(
    const pd_VecSecondaryKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKey);
}

parser_error_t _toStringVecSignatory(
    const pd_VecSignatory_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Signatory);
}

parser_error_t _toStringVecTicker(
    const pd_VecTicker_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Ticker);
}

parser_error_t _toStringVecTrustedIssuer(
    const pd_VecTrustedIssuer_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TrustedIssuer);
}

parser_error_t _toStringVecTupleIdentityIdTax(
    const pd_VecTupleIdentityIdTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdTax);
}

parser_error_t _toStringVecTupleIdentityIdbool(
    const pd_VecTupleIdentityIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdbool);
}

parser_error_t _toStringVecTuplePipIdSnapshotResult(
    const pd_VecTuplePipIdSnapshotResult_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TuplePipIdSnapshotResult);
}

parser_error_t _toStringVecValidatorIndex(
    const pd_VecValidatorIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ValidatorIndex);
}

parser_error_t _toStringVecu32(
    const pd_Vecu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u32);
}

parser_error_t _toStringVecu64(
    const pd_Vecu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u64);
}

parser_error_t _toStringOptionBalanceOf(
    const pd_OptionBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBalanceOf(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionBalance(
    const pd_OptionBalance_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBalance(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionBlockNumber(
    const pd_OptionBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBlockNumber(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionChangesTrieConfiguration(
    const pd_OptionChangesTrieConfiguration_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionDocumentType(
    const pd_OptionDocumentType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringDocumentType(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionFundingRoundName(
    const pd_OptionFundingRoundName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringFundingRoundName(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMemo(
    const pd_OptionMemo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMemo(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMetaUrl(
    const pd_OptionMetaUrl_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMetaUrl(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMoment(
    const pd_OptionMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMoment(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionNonZeroU64(
    const pd_OptionNonZeroU64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringNonZeroU64(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod(
    const pd_OptionPeriod_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPipDescription(
    const pd_OptionPipDescription_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPipDescription(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPortfolioNumber(
    const pd_OptionPortfolioNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPortfolioNumber(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReceiptDetails(
    const pd_OptionReceiptDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReceiptDetails(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionRecordDateSpec(
    const pd_OptionRecordDateSpec_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringRecordDateSpec(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTargetIdentities(
    const pd_OptionTargetIdentities_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTargetIdentities(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTax(
    const pd_OptionTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTax(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionUrl(
    const pd_OptionUrl_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringUrl(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecDispatchableName(
    const pd_OptionVecDispatchableName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecDispatchableName(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPalletPermissions(
    const pd_OptionVecPalletPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPalletPermissions(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPortfolioId(
    const pd_OptionVecPortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPortfolioId(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTicker(
    const pd_OptionVecTicker_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTicker(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTupleIdentityIdTax(
    const pd_OptionVecTupleIdentityIdTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTupleIdentityIdTax(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVenueDetails(
    const pd_OptionVenueDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVenueDetails(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVenueType(
    const pd_OptionVenueType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVenueType(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu16(
    const pd_Optionu16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu16(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu64(
    const pd_Optionu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu64(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v)
{
    return _readUInt8(c, v);
}

parser_error_t _readu16(parser_context_t* c, pd_u16_t* v)
{
    return _readUInt16(c, v);
}

parser_error_t _readu32(parser_context_t* c, pd_u32_t* v)
{
    return _readUInt32(c, v);
}

parser_error_t _readu64(parser_context_t* c, pd_u64_t* v)
{
    return _readUInt64(c, v);
}

parser_error_t _readBlockNumber(parser_context_t* c, pd_BlockNumber_t* v)
{
    return _readUInt32(c, v);
}

parser_error_t _readCompactu32(parser_context_t* c, pd_Compactu32_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactu64(parser_context_t* c, pd_Compactu64_t* v)
{
    return _readCompactInt(c, v);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringbool(
    const pd_bool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    switch (*v) {
    case 0:
        snprintf(outValue, outValueLen, "False");
        return parser_ok;
    case 1:
        snprintf(outValue, outValueLen, "True");
        return parser_ok;
    }

    return parser_not_supported;
}

parser_error_t _toStringu16(
    const pd_u16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[50];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu32(
    const pd_u32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringu64(
    const pd_u64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    char bufferUI[100];

    uint64_to_str(bufferUI, sizeof(bufferUI), *v);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringBlockNumber(
    const pd_BlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(v, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu32(
    const pd_Compactu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, outValue, outValueLen, pageIdx, pageCount);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _readProposal(parser_context_t* c, pd_Proposal_t* v)
{
    CHECK_INPUT();
    uint16_t startOffset = c->offset;
    CHECK_ERROR(_readCallIndex(c, &v->callIndex))
    CHECK_ERROR(_readMethodBasic(c, v->callIndex.moduleIdx, v->callIndex.idx, &v->method))
    v->_ptr = c->buffer + startOffset;
    v->_len = c->offset - startOffset;
    return parser_ok;
}

parser_error_t _toStringProposal(
    const pd_Proposal_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_ARRAY(v->_len);
}
