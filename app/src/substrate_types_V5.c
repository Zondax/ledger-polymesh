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
#include "substrate_dispatch_V5.h"

#include <stddef.h>
#include <stdint.h>
#include <zxmacros.h>

parser_error_t _readCompactAssignments_V5(parser_context_t* c, pd_CompactAssignments_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex_V5(parser_context_t* c, pd_CompactEraIndex_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactGas_V5(parser_context_t* c, pd_CompactGas_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment_V5(parser_context_t* c, pd_CompactMoment_V5_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAccountId_V5(parser_context_t* c, pd_AccountId_V5_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V5(parser_context_t* c, pd_AccountIndex_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readAssetIdentifier_V5(parser_context_t* c, pd_AssetIdentifier_V5_t* v)
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

parser_error_t _readAssetName_V5(parser_context_t* c, pd_AssetName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readAssetType_V5(parser_context_t* c, pd_AssetType_V5_t* v)
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

parser_error_t _readAuthorizationData_V5(parser_context_t* c, pd_AuthorizationData_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId_V5(c, &v->identityId))
        break;
    case 2:
    case 3:
    case 5:
    case 8:
    case 10:
        CHECK_INPUT();
        CHECK_ERROR(_readTicker_V5(c, &v->ticker))
        break;
    case 4:
        CHECK_INPUT();
        CHECK_ERROR(_readAccountId_V5(c, &v->accountId))
        break;
    case 6:
        CHECK_INPUT();
        CHECK_ERROR(_readPermissions_V5(c, &v->permissions))
        break;
    case 7:
        CHECK_INPUT();
        CHECK_ERROR(_readPortfolioId_V5(c, &v->portfolioId))
        break;
    case 9:
        // noData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBallotMeta_V5(parser_context_t* c, pd_BallotMeta_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBallotTitle_V5(c, &v->title))
    CHECK_ERROR(_readVecMotion_V5(c, &v->motions))
    return parser_ok;
}

parser_error_t _readBallotTimeRange_V5(parser_context_t* c, pd_BallotTimeRange_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readMoment_V5(c, &v->start))
    CHECK_ERROR(_readMoment_V5(c, &v->end))
    return parser_ok;
}

parser_error_t _readBallotTitle_V5(parser_context_t* c, pd_BallotTitle_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readBallotVote_V5(parser_context_t* c, pd_BallotVote_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->power))
    CHECK_ERROR(_readOptionu16(c, &v->fallback))
    return parser_ok;
}

parser_error_t _readBeneficiary_V5(parser_context_t* c, pd_Beneficiary_V5_t* v)
{
    CHECK_ERROR(_readIdentityId_V5(c, &v->identity))
    CHECK_ERROR(_readBalance(c, &v->balance))
    return parser_ok;
}

parser_error_t _readBridgeTx_V5(parser_context_t* c, pd_BridgeTx_V5_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt32(c, &v->nonce))
    CHECK_ERROR(_readAccountId_V5(c, &v->recipient))
    CHECK_ERROR(_readBalance(c, &v->value))
    CHECK_ERROR(_readHash(c, &v->txHash))

    return parser_ok;
}

parser_error_t _readCADetails_V5(parser_context_t* c, pd_CADetails_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readCAId_V5(parser_context_t* c, pd_CAId_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readTicker_V5(c, &v->ticker))
    CHECK_ERROR(_readLocalCAId_V5(c, &v->local_id))
    return parser_ok;
}

parser_error_t _readCAKind_V5(parser_context_t* c, pd_CAKind_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCalendarPeriod_V5(parser_context_t* c, pd_CalendarPeriod_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCalendarUnit_V5(c, &v->unit))
    CHECK_ERROR(_readUInt64(c, &v->amount))
    return parser_ok;
}

parser_error_t _readCalendarUnit_V5(parser_context_t* c, pd_CalendarUnit_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCddId_V5(parser_context_t* c, pd_CddId_V5_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChangesTrieConfiguration_V5(parser_context_t* c, pd_ChangesTrieConfiguration_V5_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCheckpointId_V5(parser_context_t* c, pd_CheckpointId_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readChoiceTitle_V5(parser_context_t* c, pd_ChoiceTitle_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readClaimType_V5(parser_context_t* c, pd_ClaimType_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readClaim_V5(parser_context_t* c, pd_Claim_V5_t* v)
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
        CHECK_ERROR(_readScope_V5(c, &v->scope))
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_readCddId_V5(c, &v->cddId))
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_readTupleCountryCodeScope_V5(c, &v->jurisdiction))
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_readTupleScopeScopeIdCddId_V5(c, &v->investorUniqueness))
        break;
    case 10: // NoData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readClassicTickerImport_V5(parser_context_t* c, pd_ClassicTickerImport_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readEthereumAddress_V5(c, &v->eth_owner))
    CHECK_ERROR(_readTicker_V5(c, &v->ticker))
    CHECK_ERROR(_readBool(c, &v->is_contract))
    CHECK_ERROR(_readBool(c, &v->is_created))
    return parser_ok;
}

parser_error_t _readCodeHash_V5(parser_context_t* c, pd_CodeHash_V5_t* v)
{
    CHECK_ERROR(_readHash(c, &v->hash))
    return parser_ok;
}

parser_error_t _readCompactPerBill_V5(parser_context_t* c, pd_CompactPerBill_V5_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readComplianceRequirement_V5(parser_context_t* c, pd_ComplianceRequirement_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readVecCondition_V5(c, &v->senderConditions))
    CHECK_ERROR(_readVecCondition_V5(c, &v->receiverConditions))
    CHECK_ERROR(_readUInt32(c, &v->id))
    return parser_ok;
}

parser_error_t _readConditionType_V5(parser_context_t* c, pd_ConditionType_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readClaim_V5(c, &v->claim))
        break;
    case 2:
    case 3:
        CHECK_INPUT();
        CHECK_ERROR(_readVecClaim_V5(c, &v->vecClaim))
        break;
    case 4:
        CHECK_INPUT();
        CHECK_ERROR(_readTargetIdentity_V5(c, &v->identity))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readCondition_V5(parser_context_t* c, pd_Condition_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readConditionType_V5(c, &v->conditionType))
    CHECK_ERROR(_readVecTrustedIssuer_V5(c, &v->issuers))
    return parser_ok;
}

parser_error_t _readCounter_V5(parser_context_t* c, pd_Counter_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readCountryCode_V5(parser_context_t* c, pd_CountryCode_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readDispatchableName_V5(parser_context_t* c, pd_DispatchableName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentHash_V5(parser_context_t* c, pd_DocumentHash_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0: // None
        v->_len = 0;
        break;
    case 1: // H512
        v->_len = 64;
        break;
    case 2: // H384
        v->_len = 48;
        break;
    case 3: // H320
        v->_len = 40;
        break;
    case 4: // H256
        v->_len = 32;
        break;
    case 5: // H224
        v->_len = 28;
        break;
    case 6: // H192
        v->_len = 24;
        break;
    case 7: // H160
        v->_len = 20;
        break;
    case 8: // H128
        v->_len = 16;
        break;
    default:
        return parser_unexpected_value;
    }

    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readDocumentId_V5(parser_context_t* c, pd_DocumentId_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readDocumentName_V5(parser_context_t* c, pd_DocumentName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentType_V5(parser_context_t* c, pd_DocumentType_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentUri_V5(parser_context_t* c, pd_DocumentUri_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocument_V5(parser_context_t* c, pd_Document_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readDocumentUri_V5(c, &v->uri))
    CHECK_ERROR(_readDocumentHash_V5(c, &v->content_hash))
    CHECK_ERROR(_readDocumentName_V5(c, &v->name))
    CHECK_ERROR(_readOptionDocumentType_V5(c, &v->doc_type))
    CHECK_ERROR(_readOptionMoment_V5(c, &v->filing_date))
    return parser_ok;
}

parser_error_t _readEcdsaSignature_V5(parser_context_t* c, pd_EcdsaSignature_V5_t* v){
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V5(parser_context_t* c, pd_ElectionScore_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readElectionSize_V5(parser_context_t* c, pd_ElectionSize_V5_t* v)
{
    CHECK_ERROR(_readCompactInt(c, &v->validators));
    CHECK_ERROR(_readCompactInt(c, &v->nominators));
    return parser_ok;
}

parser_error_t _readEquivocationProof_V5(parser_context_t* c, pd_EquivocationProof_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V5(parser_context_t* c, pd_EraIndex_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress_V5(parser_context_t* c, pd_EthereumAddress_V5_t* v){
    GEN_DEF_READARRAY(20)
}

parser_error_t _readFundingRoundName_V5(parser_context_t* c, pd_FundingRoundName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readFundraiserName_V5(parser_context_t* c, pd_FundraiserName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readIdentityId_V5(parser_context_t* c, pd_IdentityId_V5_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readInvestorUid_V5(parser_context_t* c, pd_InvestorUid_V5_t* v){
    GEN_DEF_READARRAY(16)
}

parser_error_t _readInvestorZKProofData_V5(parser_context_t* c, pd_InvestorZKProofData_V5_t* v){
    GEN_DEF_READARRAY(64)
}

parser_error_t _readKeyOwnerProof_V5(parser_context_t* c, pd_KeyOwnerProof_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V5(parser_context_t* c, pd_KeyValue_V5_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V5(parser_context_t* c, pd_Key_V5_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V5(parser_context_t* c, pd_Keys_V5_t* v)
{
    GEN_DEF_READARRAY(4 * 32)
    return parser_ok;
}

parser_error_t _readLeg_V5(parser_context_t* c, pd_Leg_V5_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readPortfolioId_V5(c, &v->from))
    CHECK_ERROR(_readPortfolioId_V5(c, &v->to))
    CHECK_ERROR(_readTicker_V5(c, &v->asset))
    CHECK_ERROR(_readBalance(c, &v->amount))

    return parser_ok;
}

parser_error_t _readLegacyPermissions_V5(parser_context_t* c, pd_LegacyPermissions_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLocalCAId_V5(parser_context_t* c, pd_LocalCAId_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMaybeBlock_V5(parser_context_t* c, pd_MaybeBlock_V5_t* v)
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

parser_error_t _readMemberCount_V5(parser_context_t* c, pd_MemberCount_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readMemo_V5(parser_context_t* c, pd_Memo_V5_t* v)
{
    v->_len = 32;
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readMetaDescription_V5(parser_context_t* c, pd_MetaDescription_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMetaUrl_V5(parser_context_t* c, pd_MetaUrl_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMetaVersion_V5(parser_context_t* c, pd_MetaVersion_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMoment_V5(parser_context_t* c, pd_Moment_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readMotionInfoLink_V5(parser_context_t* c, pd_MotionInfoLink_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotionTitle_V5(parser_context_t* c, pd_MotionTitle_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotion_V5(parser_context_t* c, pd_Motion_V5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMotionTitle_V5(c, &v->title))
    CHECK_ERROR(_readMotionInfoLink_V5(c, &v->info_link))
    CHECK_ERROR(_readVecChoiceTitle_V5(c, &v->choices))
    return parser_ok;
}

parser_error_t _readMovePortfolioItem_V5(parser_context_t* c, pd_MovePortfolioItem_V5_t* v)
{
    CHECK_ERROR(_readTicker_V5(c, &v->ticker));
    CHECK_ERROR(_readBalance(c, &v->balance));
    return parser_ok;
}

parser_error_t _readOffChainSignature_V5(parser_context_t* c, pd_OffChainSignature_V5_t* v)
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

parser_error_t _readOfflineSlashingParams_V5(parser_context_t* c, pd_OfflineSlashingParams_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->max_offline_percent))
    CHECK_ERROR(_readUInt32(c, &v->constant))
    CHECK_ERROR(_readUInt32(c, &v->max_slash_percent))
    return parser_ok;
}

parser_error_t _readPalletName_V5(parser_context_t* c, pd_PalletName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPalletPermissions_V5(parser_context_t* c, pd_PalletPermissions_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readPalletName_V5(c, &v->palletName))
    CHECK_ERROR(_readOptionVecDispatchableName_V5(c, &v->dispatchableNames))

    return parser_ok;
}

parser_error_t _readPerbill_V5(parser_context_t* c, pd_Perbill_V5_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPercent_V5(parser_context_t* c, pd_Percent_V5_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPercentage_V5(parser_context_t* c, pd_Percentage_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPermill_V5(c, &v->value))
    return parser_ok;
}

parser_error_t _readPeriod_V5(parser_context_t* c, pd_Period_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPermill_V5(parser_context_t* c, pd_Permill_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPermissions_V5(parser_context_t* c, pd_Permissions_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionVecTicker_V5(c, &v->asset))
    CHECK_ERROR(_readOptionVecPalletPermissions_V5(c, &v->extrinsic))
    CHECK_ERROR(_readOptionVecPortfolioId_V5(c, &v->portfolio))
    return parser_ok;
}

parser_error_t _readPipDescription_V5(parser_context_t* c, pd_PipDescription_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPipId_V5(parser_context_t* c, pd_PipId_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPortfolioId_V5(parser_context_t* c, pd_PortfolioId_V5_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId_V5(c, &v->did))
    CHECK_ERROR(_readPortfolioKind_V5(c, &v->kind))

    return parser_ok;
}

parser_error_t _readPortfolioKind_V5(parser_context_t* c, pd_PortfolioKind_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readPortfolioNumber_V5(c, &v->number))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readPortfolioName_V5(parser_context_t* c, pd_PortfolioName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPortfolioNumber_V5(parser_context_t* c, pd_PortfolioNumber_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPosRatio_V5(parser_context_t* c, pd_PosRatio_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->numerator))
    CHECK_ERROR(_readUInt32(c, &v->denominator))
    return parser_ok;
}

parser_error_t _readPriceTier_V5(parser_context_t* c, pd_PriceTier_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->total))
    CHECK_ERROR(_readBalance(c, &v->price))
    return parser_ok;
}

parser_error_t _readPriority_V5(parser_context_t* c, pd_Priority_V5_t* v)
{
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency_V5(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readProposalIndex_V5(parser_context_t* c, pd_ProposalIndex_V5_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readProtocolOp_V5(parser_context_t* c, pd_ProtocolOp_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 16) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readReceiptDetails_V5(parser_context_t* c, pd_ReceiptDetails_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->receipt_uid))
    CHECK_ERROR(_readUInt64(c, &v->leg_id))
    CHECK_ERROR(_readAccountId_V5(c, &v->signer))
    CHECK_ERROR(_readOffChainSignature_V5(c, &v->signature))
    CHECK_ERROR(_readReceiptMetadata_V5(c, &v->metadata))
    return parser_ok;
}

parser_error_t _readReceiptMetadata_V5(parser_context_t* c, pd_ReceiptMetadata_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readRecordDateSpec_V5(parser_context_t* c, pd_RecordDateSpec_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_readMoment_V5(c, &v->scheduled))
        break;
    case 1: // ExistingSchedule
        CHECK_ERROR(_readScheduleId_V5(c, &v->existingSchedule))
        break;
    case 2: // Existing
        CHECK_ERROR(_readCheckpointId_V5(c, &v->existing))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readRewardDestination_V5(parser_context_t* c, pd_RewardDestination_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readScheduleId_V5(parser_context_t* c, pd_ScheduleId_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readScheduleSpec_V5(parser_context_t* c, pd_ScheduleSpec_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionMoment_V5(c, &v->start))
    CHECK_ERROR(_readCalendarPeriod_V5(c, &v->period))
    return parser_ok;
}

parser_error_t _readSchedule_V5(parser_context_t* c, pd_Schedule_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readScopeId_V5(parser_context_t* c, pd_ScopeId_V5_t* v){
    GEN_DEF_READARRAY(32)
}

parser_error_t _readScope_V5(parser_context_t* c, pd_Scope_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readIdentityId_V5(c, &v->identity))
        break;
    case 1:
        CHECK_ERROR(_readTicker_V5(c, &v->ticker))
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

parser_error_t _readSecondaryKeyWithAuth_V5(parser_context_t* c, pd_SecondaryKeyWithAuth_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSecondaryKey_V5(c, &v->secondary_key))
    CHECK_ERROR(_readSignature_V5(c, &v->auth_signature))
    return parser_ok;
}

parser_error_t _readSecondaryKey_V5(parser_context_t* c, pd_SecondaryKey_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSignatory_V5(c, &v->signer))
    CHECK_ERROR(_readPermissions_V5(c, &v->permissions))
    return parser_ok;
}

parser_error_t _readSettlementType_V5(parser_context_t* c, pd_SettlementType_V5_t* v)
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

parser_error_t _readSignatory_V5(parser_context_t* c, pd_Signatory_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId_V5(c, &v->identity))
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readAccountId_V5(c, &v->account))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignature_V5(parser_context_t* c, pd_Signature_V5_t* v){
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSkippedCount_V5(parser_context_t* c, pd_SkippedCount_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readSlashingSwitch_V5(parser_context_t* c, pd_SlashingSwitch_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readSmartExtensionName_V5(parser_context_t* c, pd_SmartExtensionName_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readSmartExtensionType_V5(parser_context_t* c, pd_SmartExtensionType_V5_t* v)
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

parser_error_t _readSmartExtension_V5(parser_context_t* c, pd_SmartExtension_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSmartExtensionType_V5(c, &v->extension_type))
    CHECK_ERROR(_readSmartExtensionName_V5(c, &v->extension_name))
    CHECK_ERROR(_readAccountId_V5(c, &v->extension_id))
    CHECK_ERROR(_readBool(c, &v->is_archive))
    return parser_ok;
}

parser_error_t _readSnapshotResult_V5(parser_context_t* c, pd_SnapshotResult_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readStreamDependency_V5(parser_context_t* c, pd_StreamDependency_V5_t* v)
{
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTargetIdAuthorization_V5(parser_context_t* c, pd_TargetIdAuthorization_V5_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId_V5(c, &v->targetId))
    CHECK_ERROR(_readUInt64(c, &v->nonce))
    CHECK_ERROR(_readMoment_V5(c, &v->expiresAt))

    return parser_ok;
}

parser_error_t _readTargetIdentities_V5(parser_context_t* c, pd_TargetIdentities_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readVecIdentityId_V5(c, &v->identities))
    CHECK_ERROR(_readTargetTreatment_V5(c, &v->treatment))
    return parser_ok;
}

parser_error_t _readTargetIdentity_V5(parser_context_t* c, pd_TargetIdentity_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId_V5(c, &v->specific))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTargetTreatment_V5(parser_context_t* c, pd_TargetTreatment_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTax_V5(parser_context_t* c, pd_Tax_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPermill_V5(c, &v->value))
    return parser_ok;
}

parser_error_t _readTemplateMetadata_V5(parser_context_t* c, pd_TemplateMetadata_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionMetaUrl_V5(c, &v->url))
    CHECK_ERROR(_readSmartExtensionType_V5(c, &v->se_type))
    CHECK_ERROR(_readBalance(c, &v->usage_fee))
    CHECK_ERROR(_readMetaDescription_V5(c, &v->description))
    CHECK_ERROR(_readMetaVersion_V5(c, &v->version))
    return parser_ok;
}

parser_error_t _readTickerRegistrationConfig_V5(parser_context_t* c, pd_TickerRegistrationConfig_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->max_ticker_length))
    CHECK_ERROR(_readOptionMoment_V5(c, &v->registration_length))
    return parser_ok;
}

parser_error_t _readTicker_V5(parser_context_t* c, pd_Ticker_V5_t* v)
{
    v->_len = 12;
    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readTransferManager_V5(parser_context_t* c, pd_TransferManager_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // CountTransferManager
        CHECK_ERROR(_readCounter_V5(c, &v->countTransferManager))
        break;
    case 1: // PercentageTransferManager
        CHECK_ERROR(_readPercentage_V5(c, &v->percentageTransferManager))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedFor_V5(parser_context_t* c, pd_TrustedFor_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readVecClaimType_V5(c, &v->claims))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedIssuer_V5(parser_context_t* c, pd_TrustedIssuer_V5_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readIdentityId_V5(c, &v->issuer))
    CHECK_ERROR(_readTrustedFor_V5(c, &v->trustedFor))
    return parser_ok;
}

parser_error_t _readTupleCountryCodeScope_V5(parser_context_t* c, pd_TupleCountryCodeScope_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCountryCode_V5(c, &v->country_code))
    CHECK_ERROR(_readScope_V5(c, &v->scope))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdTax_V5(parser_context_t* c, pd_TupleIdentityIdTax_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readIdentityId_V5(c, &v->id))
    CHECK_ERROR(_readTax_V5(c, &v->tax))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdbool_V5(parser_context_t* c, pd_TupleIdentityIdbool_V5_t* v)
{
    CHECK_ERROR(_readIdentityId_V5(c, &v->identity))
    CHECK_ERROR(_readBool(c, &v->val))
    return parser_ok;
}

parser_error_t _readTuplePipIdSnapshotResult_V5(parser_context_t* c, pd_TuplePipIdSnapshotResult_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPipId_V5(c, &v->pip_id))
    CHECK_ERROR(_readSnapshotResult_V5(c, &v->snapshot_result))
    return parser_ok;
}

parser_error_t _readTupleScopeScopeIdCddId_V5(parser_context_t* c, pd_TupleScopeScopeIdCddId_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readScope_V5(c, &v->scope))
    CHECK_ERROR(_readScopeId_V5(c, &v->scopeId))
    CHECK_ERROR(_readCddId_V5(c, &v->cddId))
    return parser_ok;
}

parser_error_t _readUniqueCall_V5(parser_context_t* c, pd_UniqueCall_V5_t* v)
{
    return parser_not_supported;
}

parser_error_t _readUrl_V5(parser_context_t* c, pd_Url_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readValidatorIndex_V5(parser_context_t* c, pd_ValidatorIndex_V5_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readValidatorPrefs_V5(parser_context_t* c, pd_ValidatorPrefs_V5_t* v)
{
    CHECK_INPUT();
    return _readCompactPerBill_V5(c, &v->commission);
}

parser_error_t _readVenueDetails_V5(parser_context_t* c, pd_VenueDetails_V5_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readVenueType_V5(parser_context_t* c, pd_VenueType_V5_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 3) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readWeight_V5(parser_context_t* c, pd_Weight_V5_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readVecAccountId_V5(parser_context_t* c, pd_VecAccountId_V5_t* v){
    GEN_DEF_READVECTOR(AccountId_V5)
}

parser_error_t _readVecAssetIdentifier_V5(parser_context_t* c, pd_VecAssetIdentifier_V5_t* v){
    GEN_DEF_READVECTOR(AssetIdentifier_V5)
}

parser_error_t _readVecBallotVote_V5(parser_context_t* c, pd_VecBallotVote_V5_t* v){
    GEN_DEF_READVECTOR(BallotVote_V5)
}

parser_error_t _readVecBeneficiary_V5(parser_context_t* c, pd_VecBeneficiary_V5_t* v){
    GEN_DEF_READVECTOR(Beneficiary_V5)
}

parser_error_t _readVecBridgeTx_V5(parser_context_t* c, pd_VecBridgeTx_V5_t* v){
    GEN_DEF_READVECTOR(BridgeTx_V5)
}

parser_error_t _readVecChoiceTitle_V5(parser_context_t* c, pd_VecChoiceTitle_V5_t* v){
    GEN_DEF_READVECTOR(ChoiceTitle_V5)
}

parser_error_t _readVecClaimType_V5(parser_context_t* c, pd_VecClaimType_V5_t* v){
    GEN_DEF_READVECTOR(ClaimType_V5)
}

parser_error_t _readVecClaim_V5(parser_context_t* c, pd_VecClaim_V5_t* v){
    GEN_DEF_READVECTOR(Claim_V5)
}

parser_error_t _readVecComplianceRequirement_V5(parser_context_t* c, pd_VecComplianceRequirement_V5_t* v){
    GEN_DEF_READVECTOR(ComplianceRequirement_V5)
}

parser_error_t _readVecCondition_V5(parser_context_t* c, pd_VecCondition_V5_t* v){
    GEN_DEF_READVECTOR(Condition_V5)
}

parser_error_t _readVecDispatchableName_V5(parser_context_t* c, pd_VecDispatchableName_V5_t* v){
    GEN_DEF_READVECTOR(DispatchableName_V5)
}

parser_error_t _readVecDocumentId_V5(parser_context_t* c, pd_VecDocumentId_V5_t* v){
    GEN_DEF_READVECTOR(DocumentId_V5)
}

parser_error_t _readVecDocument_V5(parser_context_t* c, pd_VecDocument_V5_t* v){
    GEN_DEF_READVECTOR(Document_V5)
}

parser_error_t _readVecIdentityId_V5(parser_context_t* c, pd_VecIdentityId_V5_t* v){
    GEN_DEF_READVECTOR(IdentityId_V5)
}

parser_error_t _readVecKeyValue_V5(parser_context_t* c, pd_VecKeyValue_V5_t* v){
    GEN_DEF_READVECTOR(KeyValue_V5)
}

parser_error_t _readVecKey_V5(parser_context_t* c, pd_VecKey_V5_t* v){
    GEN_DEF_READVECTOR(Key_V5)
}

parser_error_t _readVecLeg_V5(parser_context_t* c, pd_VecLeg_V5_t* v){
    GEN_DEF_READVECTOR(Leg_V5)
}

parser_error_t _readVecMotion_V5(parser_context_t* c, pd_VecMotion_V5_t* v){
    GEN_DEF_READVECTOR(Motion_V5)
}

parser_error_t _readVecMovePortfolioItem_V5(parser_context_t* c, pd_VecMovePortfolioItem_V5_t* v){
    GEN_DEF_READVECTOR(MovePortfolioItem_V5)
}

parser_error_t _readVecPalletPermissions_V5(parser_context_t* c, pd_VecPalletPermissions_V5_t* v){
    GEN_DEF_READVECTOR(PalletPermissions_V5)
}

parser_error_t _readVecPortfolioId_V5(parser_context_t* c, pd_VecPortfolioId_V5_t* v){
    GEN_DEF_READVECTOR(PortfolioId_V5)
}

parser_error_t _readVecPriceTier_V5(parser_context_t* c, pd_VecPriceTier_V5_t* v){
    GEN_DEF_READVECTOR(PriceTier_V5)
}

parser_error_t _readVecReceiptDetails_V5(parser_context_t* c, pd_VecReceiptDetails_V5_t* v){
    GEN_DEF_READVECTOR(ReceiptDetails_V5)
}

parser_error_t _readVecScopeId_V5(parser_context_t* c, pd_VecScopeId_V5_t* v){
    GEN_DEF_READVECTOR(ScopeId_V5)
}

parser_error_t _readVecSecondaryKeyWithAuth_V5(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V5_t* v){
    GEN_DEF_READVECTOR(SecondaryKeyWithAuth_V5)
}

parser_error_t _readVecSecondaryKey_V5(parser_context_t* c, pd_VecSecondaryKey_V5_t* v){
    GEN_DEF_READVECTOR(SecondaryKey_V5)
}

parser_error_t _readVecSignatory_V5(parser_context_t* c, pd_VecSignatory_V5_t* v){
    GEN_DEF_READVECTOR(Signatory_V5)
}

parser_error_t _readVecTicker_V5(parser_context_t* c, pd_VecTicker_V5_t* v){
    GEN_DEF_READVECTOR(Ticker_V5)
}

parser_error_t _readVecTrustedIssuer_V5(parser_context_t* c, pd_VecTrustedIssuer_V5_t* v){
    GEN_DEF_READVECTOR(TrustedIssuer_V5)
}

parser_error_t _readVecTupleIdentityIdTax_V5(parser_context_t* c, pd_VecTupleIdentityIdTax_V5_t* v){
    GEN_DEF_READVECTOR(TupleIdentityIdTax_V5)
}

parser_error_t _readVecTupleIdentityIdbool_V5(parser_context_t* c, pd_VecTupleIdentityIdbool_V5_t* v){
    GEN_DEF_READVECTOR(TupleIdentityIdbool_V5)
}

parser_error_t _readVecTuplePipIdSnapshotResult_V5(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V5_t* v){
    GEN_DEF_READVECTOR(TuplePipIdSnapshotResult_V5)
}

parser_error_t _readVecValidatorIndex_V5(parser_context_t* c, pd_VecValidatorIndex_V5_t* v){
    GEN_DEF_READVECTOR(ValidatorIndex_V5)
}

parser_error_t _readOptionChangesTrieConfiguration_V5(parser_context_t* c, pd_OptionChangesTrieConfiguration_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionDocumentType_V5(parser_context_t* c, pd_OptionDocumentType_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readDocumentType_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionFundingRoundName_V5(parser_context_t* c, pd_OptionFundingRoundName_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readFundingRoundName_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMemo_V5(parser_context_t* c, pd_OptionMemo_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMemo_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMetaUrl_V5(parser_context_t* c, pd_OptionMetaUrl_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMetaUrl_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMoment_V5(parser_context_t* c, pd_OptionMoment_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMoment_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod_V5(parser_context_t* c, pd_OptionPeriod_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPipDescription_V5(parser_context_t* c, pd_OptionPipDescription_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPipDescription_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPortfolioNumber_V5(parser_context_t* c, pd_OptionPortfolioNumber_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPortfolioNumber_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReceiptDetails_V5(parser_context_t* c, pd_OptionReceiptDetails_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReceiptDetails_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionRecordDateSpec_V5(parser_context_t* c, pd_OptionRecordDateSpec_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRecordDateSpec_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTargetIdentities_V5(parser_context_t* c, pd_OptionTargetIdentities_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTargetIdentities_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTax_V5(parser_context_t* c, pd_OptionTax_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTax_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionUrl_V5(parser_context_t* c, pd_OptionUrl_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readUrl_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecDispatchableName_V5(parser_context_t* c, pd_OptionVecDispatchableName_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecDispatchableName_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPalletPermissions_V5(parser_context_t* c, pd_OptionVecPalletPermissions_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPalletPermissions_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPortfolioId_V5(parser_context_t* c, pd_OptionVecPortfolioId_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPortfolioId_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTicker_V5(parser_context_t* c, pd_OptionVecTicker_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTicker_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTupleIdentityIdTax_V5(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTupleIdentityIdTax_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVenueDetails_V5(parser_context_t* c, pd_OptionVenueDetails_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVenueDetails_V5(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVenueType_V5(parser_context_t* c, pd_OptionVenueType_V5_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVenueType_V5(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactAssignments_V5(
    const pd_CompactAssignments_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactEraIndex_V5(
    const pd_CompactEraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactGas_V5(
    const pd_CompactGas_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment_V5(
    const pd_CompactMoment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId_V5(
    const pd_AccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V5(
    const pd_AccountIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdentifier_V5(
    const pd_AssetIdentifier_V5_t* v,
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

parser_error_t _toStringAssetName_V5(
    const pd_AssetName_V5_t* v,
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

parser_error_t _toStringAssetType_V5(
    const pd_AssetType_V5_t* v,
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

parser_error_t _toStringAuthorizationData_V5(
    const pd_AuthorizationData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
    case 1:
        CHECK_ERROR(_toStringIdentityId_V5(&v->identityId, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 2:
    case 3:
    case 5:
    case 8:
    case 10:
        CHECK_ERROR(_toStringTicker_V5(&v->ticker, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 4:
        CHECK_ERROR(_toStringAccountId_V5(&v->accountId, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 6:
        CHECK_ERROR(_toStringPermissions_V5(&v->permissions, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 7:
        CHECK_ERROR(_toStringPortfolioId_V5(&v->portfolioId, outValue, outValueLen, pageIdx, pageCount);)
        break;
    case 9:
        snprintf(outValue, outValueLen, "NoData");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringBallotMeta_V5(
    const pd_BallotMeta_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBallotTitle_V5(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecMotion_V5(&v->motions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBallotTitle_V5(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecMotion_V5(&v->motions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTimeRange_V5(
    const pd_BallotTimeRange_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringMoment_V5(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMoment_V5(&v->end, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMoment_V5(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMoment_V5(&v->end, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTitle_V5(
    const pd_BallotTitle_V5_t* v,
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

parser_error_t _toStringBallotVote_V5(
    const pd_BallotVote_V5_t* v,
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

parser_error_t _toStringBeneficiary_V5(
    const pd_Beneficiary_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V5(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V5(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringBridgeTx_V5(
    const pd_BridgeTx_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringu32(&v->nonce, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAccountId_V5(&v->recipient, outValue, outValueLen, 0, &pages[1]))
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
        CHECK_ERROR(_toStringAccountId_V5(&v->recipient, outValue, outValueLen, pageIdx, &pages[1]))
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

parser_error_t _toStringCADetails_V5(
    const pd_CADetails_V5_t* v,
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

parser_error_t _toStringCAId_V5(
    const pd_CAId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringTicker_V5(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringLocalCAId_V5(&v->local_id, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker_V5(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringLocalCAId_V5(&v->local_id, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCAKind_V5(
    const pd_CAKind_V5_t* v,
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

parser_error_t _toStringCalendarPeriod_V5(
    const pd_CalendarPeriod_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCalendarUnit_V5(&v->unit, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCalendarUnit_V5(&v->unit, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu64(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCalendarUnit_V5(
    const pd_CalendarUnit_V5_t* v,
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

parser_error_t _toStringCddId_V5(
    const pd_CddId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChangesTrieConfiguration_V5(
    const pd_ChangesTrieConfiguration_V5_t* v,
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

parser_error_t _toStringCheckpointId_V5(
    const pd_CheckpointId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChoiceTitle_V5(
    const pd_ChoiceTitle_V5_t* v,
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

parser_error_t _toStringClaimType_V5(
    const pd_ClaimType_V5_t* v,
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

parser_error_t _toStringClaim_V5(
    const pd_Claim_V5_t* v,
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
        CHECK_ERROR(_toStringScope_V5(&v->scope, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_toStringCddId_V5(&v->cddId, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_toStringTupleCountryCodeScope_V5(&v->jurisdiction, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_toStringTupleScopeScopeIdCddId_V5(&v->investorUniqueness, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 10: // NoData
        snprintf(outValue, outValueLen, "NoData");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringClassicTickerImport_V5(
    const pd_ClassicTickerImport_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringEthereumAddress_V5(&v->eth_owner, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTicker_V5(&v->ticker, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_contract, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->is_created, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringEthereumAddress_V5(&v->eth_owner, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTicker_V5(&v->ticker, outValue, outValueLen, 0, &pages[1]))
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

parser_error_t _toStringCodeHash_V5(
    const pd_CodeHash_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringHash(&v->hash, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill_V5(
    const pd_CompactPerBill_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringComplianceRequirement_V5(
    const pd_ComplianceRequirement_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringVecCondition_V5(&v->senderConditions, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecCondition_V5(&v->receiverConditions, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecCondition_V5(&v->senderConditions, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecCondition_V5(&v->receiverConditions, outValue, outValueLen, pageIdx, &pages[1]))
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

parser_error_t _toStringConditionType_V5(
    const pd_ConditionType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    switch (v->value) {
    case 0: // IsPresent
    case 1: // IsAbsent
        CHECK_ERROR(_toStringClaim_V5(&v->claim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // IsAnyOf
    case 3: // IsNoneOf
        CHECK_ERROR(_toStringVecClaim_V5(&v->vecClaim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // IsIdentity
        CHECK_ERROR(_toStringTargetIdentity_V5(&v->identity, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringCondition_V5(
    const pd_Condition_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringConditionType_V5(&v->conditionType, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecTrustedIssuer_V5(&v->issuers, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringConditionType_V5(&v->conditionType, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecTrustedIssuer_V5(&v->issuers, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCounter_V5(
    const pd_Counter_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCountryCode_V5(
    const pd_CountryCode_V5_t* v,
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

parser_error_t _toStringDispatchableName_V5(
    const pd_DispatchableName_V5_t* v,
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

parser_error_t _toStringDocumentHash_V5(
    const pd_DocumentHash_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(v->_len)
}

parser_error_t _toStringDocumentId_V5(
    const pd_DocumentId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDocumentName_V5(
    const pd_DocumentName_V5_t* v,
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

parser_error_t _toStringDocumentType_V5(
    const pd_DocumentType_V5_t* v,
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

parser_error_t _toStringDocumentUri_V5(
    const pd_DocumentUri_V5_t* v,
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

parser_error_t _toStringDocument_V5(
    const pd_Document_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringDocumentUri_V5(&v->uri, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringDocumentHash_V5(&v->content_hash, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringDocumentName_V5(&v->name, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionDocumentType_V5(&v->doc_type, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionMoment_V5(&v->filing_date, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringDocumentUri_V5(&v->uri, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringDocumentHash_V5(&v->content_hash, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringDocumentName_V5(&v->name, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionDocumentType_V5(&v->doc_type, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionMoment_V5(&v->filing_date, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEcdsaSignature_V5(
    const pd_EcdsaSignature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V5(
    const pd_ElectionScore_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringElectionSize_V5(
    const pd_ElectionSize_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactInt(&v->validators, COIN_AMOUNT_DECIMAL_PLACES, 0, "", outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactInt(&v->nominators, COIN_AMOUNT_DECIMAL_PLACES, 0, "", outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactInt(&v->validators, COIN_AMOUNT_DECIMAL_PLACES, 0, "", outValue, outValueLen, 0, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactInt(&v->nominators, COIN_AMOUNT_DECIMAL_PLACES, 0, "", outValue, outValueLen, 0, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEquivocationProof_V5(
    const pd_EquivocationProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V5(
    const pd_EraIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V5(
    const pd_EthereumAddress_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringFundingRoundName_V5(
    const pd_FundingRoundName_V5_t* v,
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

parser_error_t _toStringFundraiserName_V5(
    const pd_FundraiserName_V5_t* v,
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

parser_error_t _toStringIdentityId_V5(
    const pd_IdentityId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringInvestorUid_V5(
    const pd_InvestorUid_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(16)
}

parser_error_t _toStringInvestorZKProofData_V5(
    const pd_InvestorZKProofData_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringKeyOwnerProof_V5(
    const pd_KeyOwnerProof_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V5(
    const pd_KeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V5(
    const pd_Key_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V5(
    const pd_Keys_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLeg_V5(
    const pd_Leg_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringPortfolioId_V5(&v->from, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioId_V5(&v->to, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTicker_V5(&v->asset, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringBalance(&v->amount, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPortfolioId_V5(&v->from, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioId_V5(&v->to, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTicker_V5(&v->asset, outValue, outValueLen, pageIdx, &pages[2]))
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

parser_error_t _toStringLegacyPermissions_V5(
    const pd_LegacyPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLocalCAId_V5(
    const pd_LocalCAId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMaybeBlock_V5(
    const pd_MaybeBlock_V5_t* v,
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

parser_error_t _toStringMemberCount_V5(
    const pd_MemberCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMemo_V5(
    const pd_Memo_V5_t* v,
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

parser_error_t _toStringMetaDescription_V5(
    const pd_MetaDescription_V5_t* v,
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

parser_error_t _toStringMetaUrl_V5(
    const pd_MetaUrl_V5_t* v,
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

parser_error_t _toStringMetaVersion_V5(
    const pd_MetaVersion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMoment_V5(
    const pd_Moment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMotionInfoLink_V5(
    const pd_MotionInfoLink_V5_t* v,
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

parser_error_t _toStringMotionTitle_V5(
    const pd_MotionTitle_V5_t* v,
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

parser_error_t _toStringMotion_V5(
    const pd_Motion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringMotionTitle_V5(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMotionInfoLink_V5(&v->info_link, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecChoiceTitle_V5(&v->choices, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMotionTitle_V5(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMotionInfoLink_V5(&v->info_link, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecChoiceTitle_V5(&v->choices, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMovePortfolioItem_V5(
    const pd_MovePortfolioItem_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringTicker_V5(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker_V5(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringOffChainSignature_V5(
    const pd_OffChainSignature_V5_t* v,
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

parser_error_t _toStringOfflineSlashingParams_V5(
    const pd_OfflineSlashingParams_V5_t* v,
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

parser_error_t _toStringPalletName_V5(
    const pd_PalletName_V5_t* v,
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

parser_error_t _toStringPalletPermissions_V5(
    const pd_PalletPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPalletName_V5(&v->palletName, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecDispatchableName_V5(&v->dispatchableNames, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPalletName_V5(&v->palletName, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecDispatchableName_V5(&v->dispatchableNames, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPerbill_V5(
    const pd_Perbill_V5_t* v,
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

parser_error_t _toStringPercent_V5(
    const pd_Percent_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPercentage_V5(
    const pd_Percentage_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringPermill_V5(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringPeriod_V5(
    const pd_Period_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPermill_V5(
    const pd_Permill_V5_t* v,
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

parser_error_t _toStringPermissions_V5(
    const pd_Permissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringOptionVecTicker_V5(&v->asset, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecPalletPermissions_V5(&v->extrinsic, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionVecPortfolioId_V5(&v->portfolio, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionVecTicker_V5(&v->asset, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecPalletPermissions_V5(&v->extrinsic, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionVecPortfolioId_V5(&v->portfolio, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPipDescription_V5(
    const pd_PipDescription_V5_t* v,
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

parser_error_t _toStringPipId_V5(
    const pd_PipId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPortfolioId_V5(
    const pd_PortfolioId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V5(&v->did, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioKind_V5(&v->kind, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V5(&v->did, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioKind_V5(&v->kind, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPortfolioKind_V5(
    const pd_PortfolioKind_V5_t* v,
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
        _toStringPortfolioNumber_V5(&v->number, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringPortfolioName_V5(
    const pd_PortfolioName_V5_t* v,
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

parser_error_t _toStringPortfolioNumber_V5(
    const pd_PortfolioNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPosRatio_V5(
    const pd_PosRatio_V5_t* v,
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

parser_error_t _toStringPriceTier_V5(
    const pd_PriceTier_V5_t* v,
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

parser_error_t _toStringPriority_V5(
    const pd_Priority_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency_V5(&v->dependency, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringStreamDependency_V5(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProposalIndex_V5(
    const pd_ProposalIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProtocolOp_V5(
    const pd_ProtocolOp_V5_t* v,
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

parser_error_t _toStringReceiptDetails_V5(
    const pd_ReceiptDetails_V5_t* v,
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
    CHECK_ERROR(_toStringAccountId_V5(&v->signer, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOffChainSignature_V5(&v->signature, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringReceiptMetadata_V5(&v->metadata, outValue, outValueLen, 0, &pages[4]))

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
        CHECK_ERROR(_toStringAccountId_V5(&v->signer, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOffChainSignature_V5(&v->signature, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringReceiptMetadata_V5(&v->metadata, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringReceiptMetadata_V5(
    const pd_ReceiptMetadata_V5_t* v,
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

parser_error_t _toStringRecordDateSpec_V5(
    const pd_RecordDateSpec_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_toStringMoment_V5(&v->scheduled, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1: // ExistingSchedule
        CHECK_ERROR(_toStringScheduleId_V5(&v->existingSchedule, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 2: // Existing
        CHECK_ERROR(_toStringCheckpointId_V5(&v->existing, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringRewardDestination_V5(
    const pd_RewardDestination_V5_t* v,
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

parser_error_t _toStringScheduleId_V5(
    const pd_ScheduleId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringScheduleSpec_V5(
    const pd_ScheduleSpec_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringOptionMoment_V5(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCalendarPeriod_V5(&v->period, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMoment_V5(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCalendarPeriod_V5(&v->period, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSchedule_V5(
    const pd_Schedule_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringScopeId_V5(
    const pd_ScopeId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringScope_V5(
    const pd_Scope_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId_V5(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringTicker_V5(&v->ticker, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 2:
        GEN_DEF_TOSTRING_ARRAY(v->_len)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSecondaryKeyWithAuth_V5(
    const pd_SecondaryKeyWithAuth_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSecondaryKey_V5(&v->secondary_key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSignature_V5(&v->auth_signature, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSecondaryKey_V5(&v->secondary_key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSignature_V5(&v->auth_signature, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSecondaryKey_V5(
    const pd_SecondaryKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSignatory_V5(&v->signer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPermissions_V5(&v->permissions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSignatory_V5(&v->signer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPermissions_V5(&v->permissions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSettlementType_V5(
    const pd_SettlementType_V5_t* v,
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

parser_error_t _toStringSignatory_V5(
    const pd_Signatory_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId_V5(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringAccountId_V5(&v->account, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSignature_V5(
    const pd_Signature_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount){
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSkippedCount_V5(
    const pd_SkippedCount_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    uint16_t valu16 = (uint16_t)v->value;
    return _toStringu16(&valu16, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSlashingSwitch_V5(
    const pd_SlashingSwitch_V5_t* v,
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

parser_error_t _toStringSmartExtensionName_V5(
    const pd_SmartExtensionName_V5_t* v,
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

parser_error_t _toStringSmartExtensionType_V5(
    const pd_SmartExtensionType_V5_t* v,
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

parser_error_t _toStringSmartExtension_V5(
    const pd_SmartExtension_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringSmartExtensionType_V5(&v->extension_type, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSmartExtensionName_V5(&v->extension_name, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringAccountId_V5(&v->extension_id, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->is_archive, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSmartExtensionType_V5(&v->extension_type, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSmartExtensionName_V5(&v->extension_name, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringAccountId_V5(&v->extension_id, outValue, outValueLen, pageIdx, &pages[2]))
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

parser_error_t _toStringSnapshotResult_V5(
    const pd_SnapshotResult_V5_t* v,
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

parser_error_t _toStringStreamDependency_V5(
    const pd_StreamDependency_V5_t* v,
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

parser_error_t _toStringTargetIdAuthorization_V5(
    const pd_TargetIdAuthorization_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringIdentityId_V5(&v->targetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringMoment_V5(&v->expiresAt, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V5(&v->targetId, outValue, outValueLen, pageIdx, &pages[0]))
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
        CHECK_ERROR(_toStringMoment_V5(&v->expiresAt, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdentities_V5(
    const pd_TargetIdentities_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringVecIdentityId_V5(&v->identities, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTargetTreatment_V5(&v->treatment, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecIdentityId_V5(&v->identities, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTargetTreatment_V5(&v->treatment, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdentity_V5(
    const pd_TargetIdentity_V5_t* v,
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
        _toStringIdentityId_V5(&v->specific, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTargetTreatment_V5(
    const pd_TargetTreatment_V5_t* v,
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

parser_error_t _toStringTax_V5(
    const pd_Tax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringPermill_V5(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringTemplateMetadata_V5(
    const pd_TemplateMetadata_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringOptionMetaUrl_V5(&v->url, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSmartExtensionType_V5(&v->se_type, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->usage_fee, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringMetaDescription_V5(&v->description, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringMetaVersion_V5(&v->version, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMetaUrl_V5(&v->url, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSmartExtensionType_V5(&v->se_type, outValue, outValueLen, pageIdx, &pages[1]))
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
        CHECK_ERROR(_toStringMetaDescription_V5(&v->description, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringMetaVersion_V5(&v->version, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTickerRegistrationConfig_V5(
    const pd_TickerRegistrationConfig_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->max_ticker_length, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionMoment_V5(&v->registration_length, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringOptionMoment_V5(&v->registration_length, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTicker_V5(
    const pd_Ticker_V5_t* v,
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

parser_error_t _toStringTransferManager_V5(
    const pd_TransferManager_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // CountTransferManager
        CHECK_ERROR(_toStringCounter_V5(&v->countTransferManager, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1: // PercentageTransferManager
        CHECK_ERROR(_toStringPercentage_V5(&v->percentageTransferManager, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTrustedFor_V5(
    const pd_TrustedFor_V5_t* v,
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
        _toStringVecClaimType_V5(&v->claims, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTrustedIssuer_V5(
    const pd_TrustedIssuer_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V5(&v->issuer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTrustedFor_V5(&v->trustedFor, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V5(&v->issuer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTrustedFor_V5(&v->trustedFor, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleCountryCodeScope_V5(
    const pd_TupleCountryCodeScope_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCountryCode_V5(&v->country_code, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScope_V5(&v->scope, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCountryCode_V5(&v->country_code, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScope_V5(&v->scope, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdTax_V5(
    const pd_TupleIdentityIdTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V5(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTax_V5(&v->tax, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V5(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTax_V5(&v->tax, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdbool_V5(
    const pd_TupleIdentityIdbool_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V5(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V5(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTuplePipIdSnapshotResult_V5(
    const pd_TuplePipIdSnapshotResult_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPipId_V5(&v->pip_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSnapshotResult_V5(&v->snapshot_result, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPipId_V5(&v->pip_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSnapshotResult_V5(&v->snapshot_result, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleScopeScopeIdCddId_V5(
    const pd_TupleScopeScopeIdCddId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringScope_V5(&v->scope, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScopeId_V5(&v->scopeId, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCddId_V5(&v->cddId, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringScope_V5(&v->scope, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScopeId_V5(&v->scopeId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCddId_V5(&v->cddId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUniqueCall_V5(
    const pd_UniqueCall_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringUrl_V5(
    const pd_Url_V5_t* v,
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

parser_error_t _toStringValidatorIndex_V5(
    const pd_ValidatorIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringValidatorPrefs_V5(
    const pd_ValidatorPrefs_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactPerBill_V5(&v->commission, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVenueDetails_V5(
    const pd_VenueDetails_V5_t* v,
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

parser_error_t _toStringVenueType_V5(
    const pd_VenueType_V5_t* v,
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

parser_error_t _toStringWeight_V5(
    const pd_Weight_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecAccountId_V5(
    const pd_VecAccountId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V5);
}

parser_error_t _toStringVecAssetIdentifier_V5(
    const pd_VecAssetIdentifier_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdentifier_V5);
}

parser_error_t _toStringVecBallotVote_V5(
    const pd_VecBallotVote_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BallotVote_V5);
}

parser_error_t _toStringVecBeneficiary_V5(
    const pd_VecBeneficiary_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Beneficiary_V5);
}

parser_error_t _toStringVecBridgeTx_V5(
    const pd_VecBridgeTx_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BridgeTx_V5);
}

parser_error_t _toStringVecChoiceTitle_V5(
    const pd_VecChoiceTitle_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ChoiceTitle_V5);
}

parser_error_t _toStringVecClaimType_V5(
    const pd_VecClaimType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ClaimType_V5);
}

parser_error_t _toStringVecClaim_V5(
    const pd_VecClaim_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Claim_V5);
}

parser_error_t _toStringVecComplianceRequirement_V5(
    const pd_VecComplianceRequirement_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ComplianceRequirement_V5);
}

parser_error_t _toStringVecCondition_V5(
    const pd_VecCondition_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Condition_V5);
}

parser_error_t _toStringVecDispatchableName_V5(
    const pd_VecDispatchableName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DispatchableName_V5);
}

parser_error_t _toStringVecDocumentId_V5(
    const pd_VecDocumentId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DocumentId_V5);
}

parser_error_t _toStringVecDocument_V5(
    const pd_VecDocument_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Document_V5);
}

parser_error_t _toStringVecIdentityId_V5(
    const pd_VecIdentityId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(IdentityId_V5);
}

parser_error_t _toStringVecKeyValue_V5(
    const pd_VecKeyValue_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V5);
}

parser_error_t _toStringVecKey_V5(
    const pd_VecKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V5);
}

parser_error_t _toStringVecLeg_V5(
    const pd_VecLeg_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Leg_V5);
}

parser_error_t _toStringVecMotion_V5(
    const pd_VecMotion_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Motion_V5);
}

parser_error_t _toStringVecMovePortfolioItem_V5(
    const pd_VecMovePortfolioItem_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MovePortfolioItem_V5);
}

parser_error_t _toStringVecPalletPermissions_V5(
    const pd_VecPalletPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PalletPermissions_V5);
}

parser_error_t _toStringVecPortfolioId_V5(
    const pd_VecPortfolioId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PortfolioId_V5);
}

parser_error_t _toStringVecPriceTier_V5(
    const pd_VecPriceTier_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PriceTier_V5);
}

parser_error_t _toStringVecReceiptDetails_V5(
    const pd_VecReceiptDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ReceiptDetails_V5);
}

parser_error_t _toStringVecScopeId_V5(
    const pd_VecScopeId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ScopeId_V5);
}

parser_error_t _toStringVecSecondaryKeyWithAuth_V5(
    const pd_VecSecondaryKeyWithAuth_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKeyWithAuth_V5);
}

parser_error_t _toStringVecSecondaryKey_V5(
    const pd_VecSecondaryKey_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKey_V5);
}

parser_error_t _toStringVecSignatory_V5(
    const pd_VecSignatory_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Signatory_V5);
}

parser_error_t _toStringVecTicker_V5(
    const pd_VecTicker_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Ticker_V5);
}

parser_error_t _toStringVecTrustedIssuer_V5(
    const pd_VecTrustedIssuer_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TrustedIssuer_V5);
}

parser_error_t _toStringVecTupleIdentityIdTax_V5(
    const pd_VecTupleIdentityIdTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdTax_V5);
}

parser_error_t _toStringVecTupleIdentityIdbool_V5(
    const pd_VecTupleIdentityIdbool_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdbool_V5);
}

parser_error_t _toStringVecTuplePipIdSnapshotResult_V5(
    const pd_VecTuplePipIdSnapshotResult_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TuplePipIdSnapshotResult_V5);
}

parser_error_t _toStringVecValidatorIndex_V5(
    const pd_VecValidatorIndex_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ValidatorIndex_V5);
}

parser_error_t _toStringOptionChangesTrieConfiguration_V5(
    const pd_OptionChangesTrieConfiguration_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionDocumentType_V5(
    const pd_OptionDocumentType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringDocumentType_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionFundingRoundName_V5(
    const pd_OptionFundingRoundName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringFundingRoundName_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMemo_V5(
    const pd_OptionMemo_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMemo_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMetaUrl_V5(
    const pd_OptionMetaUrl_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMetaUrl_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMoment_V5(
    const pd_OptionMoment_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMoment_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod_V5(
    const pd_OptionPeriod_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPipDescription_V5(
    const pd_OptionPipDescription_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPipDescription_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPortfolioNumber_V5(
    const pd_OptionPortfolioNumber_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPortfolioNumber_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReceiptDetails_V5(
    const pd_OptionReceiptDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReceiptDetails_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionRecordDateSpec_V5(
    const pd_OptionRecordDateSpec_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringRecordDateSpec_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTargetIdentities_V5(
    const pd_OptionTargetIdentities_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTargetIdentities_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTax_V5(
    const pd_OptionTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTax_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionUrl_V5(
    const pd_OptionUrl_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringUrl_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecDispatchableName_V5(
    const pd_OptionVecDispatchableName_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecDispatchableName_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPalletPermissions_V5(
    const pd_OptionVecPalletPermissions_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPalletPermissions_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPortfolioId_V5(
    const pd_OptionVecPortfolioId_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPortfolioId_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTicker_V5(
    const pd_OptionVecTicker_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTicker_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTupleIdentityIdTax_V5(
    const pd_OptionVecTupleIdentityIdTax_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTupleIdentityIdTax_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVenueDetails_V5(
    const pd_OptionVenueDetails_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVenueDetails_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVenueType_V5(
    const pd_OptionVenueType_V5_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVenueType_V5(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
