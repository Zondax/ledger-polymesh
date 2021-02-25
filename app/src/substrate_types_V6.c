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
#include "substrate_dispatch_V6.h"

#include <stddef.h>
#include <stdint.h>
#include <zxmacros.h>

parser_error_t _readCompactAssignments_V6(parser_context_t* c, pd_CompactAssignments_V6_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex_V6(parser_context_t* c, pd_CompactEraIndex_V6_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactGas_V6(parser_context_t* c, pd_CompactGas_V6_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment_V6(parser_context_t* c, pd_CompactMoment_V6_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAccountId_V6(parser_context_t* c, pd_AccountId_V6_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V6(parser_context_t* c, pd_AccountIndex_V6_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readAssetIdentifier_V6(parser_context_t* c, pd_AssetIdentifier_V6_t* v)
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

parser_error_t _readAssetName_V6(parser_context_t* c, pd_AssetName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readAssetType_V6(parser_context_t* c, pd_AssetType_V6_t* v)
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

parser_error_t _readAuthorizationData_V6(parser_context_t* c, pd_AuthorizationData_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId_V6(c, &v->identityId))
        break;
    case 2:
    case 3:
    case 5:
    case 8:
    case 10:
        CHECK_INPUT();
        CHECK_ERROR(_readTicker_V6(c, &v->ticker))
        break;
    case 4:
        CHECK_INPUT();
        CHECK_ERROR(_readAccountId_V6(c, &v->accountId))
        break;
    case 6:
        CHECK_INPUT();
        CHECK_ERROR(_readPermissions_V6(c, &v->permissions))
        break;
    case 7:
        CHECK_INPUT();
        CHECK_ERROR(_readPortfolioId_V6(c, &v->portfolioId))
        break;
    case 9:
        // noData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBallotMeta_V6(parser_context_t* c, pd_BallotMeta_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBallotTitle_V6(c, &v->title))
    CHECK_ERROR(_readVecMotion_V6(c, &v->motions))
    return parser_ok;
}

parser_error_t _readBallotTimeRange_V6(parser_context_t* c, pd_BallotTimeRange_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readMoment_V6(c, &v->start))
    CHECK_ERROR(_readMoment_V6(c, &v->end))
    return parser_ok;
}

parser_error_t _readBallotTitle_V6(parser_context_t* c, pd_BallotTitle_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readBallotVote_V6(parser_context_t* c, pd_BallotVote_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->power))
    CHECK_ERROR(_readOptionu16(c, &v->fallback))
    return parser_ok;
}

parser_error_t _readBeneficiary_V6(parser_context_t* c, pd_Beneficiary_V6_t* v)
{
    CHECK_ERROR(_readIdentityId_V6(c, &v->identity))
    CHECK_ERROR(_readBalance(c, &v->balance))
    return parser_ok;
}

parser_error_t _readBridgeTx_V6(parser_context_t* c, pd_BridgeTx_V6_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt32(c, &v->nonce))
    CHECK_ERROR(_readAccountId_V6(c, &v->recipient))
    CHECK_ERROR(_readBalance(c, &v->value))
    CHECK_ERROR(_readHash(c, &v->txHash))

    return parser_ok;
}

parser_error_t _readCADetails_V6(parser_context_t* c, pd_CADetails_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readCAId_V6(parser_context_t* c, pd_CAId_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readTicker_V6(c, &v->ticker))
    CHECK_ERROR(_readLocalCAId_V6(c, &v->local_id))
    return parser_ok;
}

parser_error_t _readCAKind_V6(parser_context_t* c, pd_CAKind_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCalendarPeriod_V6(parser_context_t* c, pd_CalendarPeriod_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCalendarUnit_V6(c, &v->unit))
    CHECK_ERROR(_readUInt64(c, &v->amount))
    return parser_ok;
}

parser_error_t _readCalendarUnit_V6(parser_context_t* c, pd_CalendarUnit_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCddId_V6(parser_context_t* c, pd_CddId_V6_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChangesTrieConfiguration_V6(parser_context_t* c, pd_ChangesTrieConfiguration_V6_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCheckpointId_V6(parser_context_t* c, pd_CheckpointId_V6_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readChoiceTitle_V6(parser_context_t* c, pd_ChoiceTitle_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readClaimType_V6(parser_context_t* c, pd_ClaimType_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readClaim_V6(parser_context_t* c, pd_Claim_V6_t* v)
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
        CHECK_ERROR(_readScope_V6(c, &v->scope))
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_readCddId_V6(c, &v->cddId))
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_readTupleCountryCodeScope_V6(c, &v->jurisdiction))
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_readTupleScopeScopeIdCddId_V6(c, &v->investorUniqueness))
        break;
    case 10: // NoData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readClassicTickerImport_V6(parser_context_t* c, pd_ClassicTickerImport_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readEthereumAddress_V6(c, &v->eth_owner))
    CHECK_ERROR(_readTicker_V6(c, &v->ticker))
    CHECK_ERROR(_readBool(c, &v->is_contract))
    CHECK_ERROR(_readBool(c, &v->is_created))
    return parser_ok;
}

parser_error_t _readCodeHash_V6(parser_context_t* c, pd_CodeHash_V6_t* v)
{
    CHECK_ERROR(_readHash(c, &v->hash))
    return parser_ok;
}

parser_error_t _readCompactPerBill_V6(parser_context_t* c, pd_CompactPerBill_V6_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readComplianceRequirement_V6(parser_context_t* c, pd_ComplianceRequirement_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readVecCondition_V6(c, &v->senderConditions))
    CHECK_ERROR(_readVecCondition_V6(c, &v->receiverConditions))
    CHECK_ERROR(_readUInt32(c, &v->id))
    return parser_ok;
}

parser_error_t _readConditionType_V6(parser_context_t* c, pd_ConditionType_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readClaim_V6(c, &v->claim))
        break;
    case 2:
    case 3:
        CHECK_INPUT();
        CHECK_ERROR(_readVecClaim_V6(c, &v->vecClaim))
        break;
    case 4:
        CHECK_INPUT();
        CHECK_ERROR(_readTargetIdentity_V6(c, &v->identity))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readCondition_V6(parser_context_t* c, pd_Condition_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readConditionType_V6(c, &v->conditionType))
    CHECK_ERROR(_readVecTrustedIssuer_V6(c, &v->issuers))
    return parser_ok;
}

parser_error_t _readCounter_V6(parser_context_t* c, pd_Counter_V6_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readCountryCode_V6(parser_context_t* c, pd_CountryCode_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readDispatchableName_V6(parser_context_t* c, pd_DispatchableName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentHash_V6(parser_context_t* c, pd_DocumentHash_V6_t* v)
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

parser_error_t _readDocumentId_V6(parser_context_t* c, pd_DocumentId_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readDocumentName_V6(parser_context_t* c, pd_DocumentName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentType_V6(parser_context_t* c, pd_DocumentType_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentUri_V6(parser_context_t* c, pd_DocumentUri_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocument_V6(parser_context_t* c, pd_Document_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readDocumentUri_V6(c, &v->uri))
    CHECK_ERROR(_readDocumentHash_V6(c, &v->content_hash))
    CHECK_ERROR(_readDocumentName_V6(c, &v->name))
    CHECK_ERROR(_readOptionDocumentType_V6(c, &v->doc_type))
    CHECK_ERROR(_readOptionMoment_V6(c, &v->filing_date))
    return parser_ok;
}

parser_error_t _readEcdsaSignature_V6(parser_context_t* c, pd_EcdsaSignature_V6_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V6(parser_context_t* c, pd_ElectionScore_V6_t* v)
{
    return parser_not_supported;
}

parser_error_t _readElectionSize_V6(parser_context_t* c, pd_ElectionSize_V6_t* v)
{
    CHECK_ERROR(_readCompactInt(c, &v->validators));
    CHECK_ERROR(_readCompactInt(c, &v->nominators));
    return parser_ok;
}

parser_error_t _readEquivocationProof_V6(parser_context_t* c, pd_EquivocationProof_V6_t* v)
{
    return parser_not_supported;
}

parser_error_t _readEraIndex_V6(parser_context_t* c, pd_EraIndex_V6_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress_V6(parser_context_t* c, pd_EthereumAddress_V6_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readFundingRoundName_V6(parser_context_t* c, pd_FundingRoundName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readFundraiserName_V6(parser_context_t* c, pd_FundraiserName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readIdentityId_V6(parser_context_t* c, pd_IdentityId_V6_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readInvestorUid_V6(parser_context_t* c, pd_InvestorUid_V6_t* v) {
    GEN_DEF_READARRAY(16)
}

parser_error_t _readInvestorZKProofData_V6(parser_context_t* c, pd_InvestorZKProofData_V6_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readKeyOwnerProof_V6(parser_context_t* c, pd_KeyOwnerProof_V6_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V6(parser_context_t* c, pd_KeyValue_V6_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V6(parser_context_t* c, pd_Key_V6_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V6(parser_context_t* c, pd_Keys_V6_t* v)
{
    GEN_DEF_READARRAY(4 * 32)
    return parser_ok;
}

parser_error_t _readLeg_V6(parser_context_t* c, pd_Leg_V6_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readPortfolioId_V6(c, &v->from))
    CHECK_ERROR(_readPortfolioId_V6(c, &v->to))
    CHECK_ERROR(_readTicker_V6(c, &v->asset))
    CHECK_ERROR(_readBalance(c, &v->amount))

    return parser_ok;
}

parser_error_t _readLegacyPermissions_V6(parser_context_t* c, pd_LegacyPermissions_V6_t* v)
{
    return parser_not_supported;
}

parser_error_t _readLocalCAId_V6(parser_context_t* c, pd_LocalCAId_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readLookupSource_V6(parser_context_t* c, pd_LookupSource_V6_t* v)
{
    uint8_t len;
    CHECK_ERROR(_readUInt8(c, &len))
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readMaybeBlock_V6(parser_context_t* c, pd_MaybeBlock_V6_t* v)
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

parser_error_t _readMemberCount_V6(parser_context_t* c, pd_MemberCount_V6_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readMemo_V6(parser_context_t* c, pd_Memo_V6_t* v)
{
    v->_len = 32;
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readMetaDescription_V6(parser_context_t* c, pd_MetaDescription_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMetaUrl_V6(parser_context_t* c, pd_MetaUrl_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMetaVersion_V6(parser_context_t* c, pd_MetaVersion_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readMoment_V6(parser_context_t* c, pd_Moment_V6_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readMotionInfoLink_V6(parser_context_t* c, pd_MotionInfoLink_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotionTitle_V6(parser_context_t* c, pd_MotionTitle_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotion_V6(parser_context_t* c, pd_Motion_V6_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMotionTitle_V6(c, &v->title))
    CHECK_ERROR(_readMotionInfoLink_V6(c, &v->info_link))
    CHECK_ERROR(_readVecChoiceTitle_V6(c, &v->choices))
    return parser_ok;
}

parser_error_t _readMovePortfolioItem_V6(parser_context_t* c, pd_MovePortfolioItem_V6_t* v)
{
    CHECK_ERROR(_readTicker_V6(c, &v->ticker));
    CHECK_ERROR(_readBalance(c, &v->balance));
    return parser_ok;
}

parser_error_t _readOffChainSignature_V6(parser_context_t* c, pd_OffChainSignature_V6_t* v)
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

parser_error_t _readOfflineSlashingParams_V6(parser_context_t* c, pd_OfflineSlashingParams_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->max_offline_percent))
    CHECK_ERROR(_readUInt32(c, &v->constant))
    CHECK_ERROR(_readUInt32(c, &v->max_slash_percent))
    return parser_ok;
}

parser_error_t _readPalletName_V6(parser_context_t* c, pd_PalletName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPalletPermissions_V6(parser_context_t* c, pd_PalletPermissions_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readPalletName_V6(c, &v->palletName))
    CHECK_ERROR(_readOptionVecDispatchableName_V6(c, &v->dispatchableNames))

    return parser_ok;
}

parser_error_t _readPerbill_V6(parser_context_t* c, pd_Perbill_V6_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPercent_V6(parser_context_t* c, pd_Percent_V6_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPercentage_V6(parser_context_t* c, pd_Percentage_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPermill_V6(c, &v->value))
    return parser_ok;
}

parser_error_t _readPeriod_V6(parser_context_t* c, pd_Period_V6_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPermill_V6(parser_context_t* c, pd_Permill_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPermissions_V6(parser_context_t* c, pd_Permissions_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionVecTicker_V6(c, &v->asset))
    CHECK_ERROR(_readOptionVecPalletPermissions_V6(c, &v->extrinsic))
    CHECK_ERROR(_readOptionVecPortfolioId_V6(c, &v->portfolio))
    return parser_ok;
}

parser_error_t _readPipDescription_V6(parser_context_t* c, pd_PipDescription_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPipId_V6(parser_context_t* c, pd_PipId_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPortfolioId_V6(parser_context_t* c, pd_PortfolioId_V6_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId_V6(c, &v->did))
    CHECK_ERROR(_readPortfolioKind_V6(c, &v->kind))

    return parser_ok;
}

parser_error_t _readPortfolioKind_V6(parser_context_t* c, pd_PortfolioKind_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readPortfolioNumber_V6(c, &v->number))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readPortfolioName_V6(parser_context_t* c, pd_PortfolioName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPortfolioNumber_V6(parser_context_t* c, pd_PortfolioNumber_V6_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPosRatio_V6(parser_context_t* c, pd_PosRatio_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->numerator))
    CHECK_ERROR(_readUInt32(c, &v->denominator))
    return parser_ok;
}

parser_error_t _readPriceTier_V6(parser_context_t* c, pd_PriceTier_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->total))
    CHECK_ERROR(_readBalance(c, &v->price))
    return parser_ok;
}

parser_error_t _readPriority_V6(parser_context_t* c, pd_Priority_V6_t* v)
{
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency_V6(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readProposalIndex_V6(parser_context_t* c, pd_ProposalIndex_V6_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readProtocolOp_V6(parser_context_t* c, pd_ProtocolOp_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 16) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readReceiptDetails_V6(parser_context_t* c, pd_ReceiptDetails_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->receipt_uid))
    CHECK_ERROR(_readUInt64(c, &v->leg_id))
    CHECK_ERROR(_readAccountId_V6(c, &v->signer))
    CHECK_ERROR(_readOffChainSignature_V6(c, &v->signature))
    CHECK_ERROR(_readReceiptMetadata_V6(c, &v->metadata))
    return parser_ok;
}

parser_error_t _readReceiptMetadata_V6(parser_context_t* c, pd_ReceiptMetadata_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readRecordDateSpec_V6(parser_context_t* c, pd_RecordDateSpec_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_readMoment_V6(c, &v->scheduled))
        break;
    case 1: // ExistingSchedule
        CHECK_ERROR(_readScheduleId_V6(c, &v->existingSchedule))
        break;
    case 2: // Existing
        CHECK_ERROR(_readCheckpointId_V6(c, &v->existing))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readRewardDestination_V6(parser_context_t* c, pd_RewardDestination_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readScheduleId_V6(parser_context_t* c, pd_ScheduleId_V6_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readScheduleSpec_V6(parser_context_t* c, pd_ScheduleSpec_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionMoment_V6(c, &v->start))
    CHECK_ERROR(_readCalendarPeriod_V6(c, &v->period))
    return parser_ok;
}

parser_error_t _readSchedule_V6(parser_context_t* c, pd_Schedule_V6_t* v)
{
    return parser_not_supported;
}

parser_error_t _readScopeId_V6(parser_context_t* c, pd_ScopeId_V6_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readScope_V6(parser_context_t* c, pd_Scope_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readIdentityId_V6(c, &v->identity))
        break;
    case 1:
        CHECK_ERROR(_readTicker_V6(c, &v->ticker))
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

parser_error_t _readSecondaryKeyWithAuth_V6(parser_context_t* c, pd_SecondaryKeyWithAuth_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSecondaryKey_V6(c, &v->secondary_key))
    CHECK_ERROR(_readSignature_V6(c, &v->auth_signature))
    return parser_ok;
}

parser_error_t _readSecondaryKey_V6(parser_context_t* c, pd_SecondaryKey_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSignatory_V6(c, &v->signer))
    CHECK_ERROR(_readPermissions_V6(c, &v->permissions))
    return parser_ok;
}

parser_error_t _readSettlementType_V6(parser_context_t* c, pd_SettlementType_V6_t* v)
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

parser_error_t _readSignatory_V6(parser_context_t* c, pd_Signatory_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId_V6(c, &v->identity))
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readAccountId_V6(c, &v->account))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignature_V6(parser_context_t* c, pd_Signature_V6_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSkippedCount_V6(parser_context_t* c, pd_SkippedCount_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readSlashingSwitch_V6(parser_context_t* c, pd_SlashingSwitch_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readSmartExtensionName_V6(parser_context_t* c, pd_SmartExtensionName_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readSmartExtensionType_V6(parser_context_t* c, pd_SmartExtensionType_V6_t* v)
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

parser_error_t _readSmartExtension_V6(parser_context_t* c, pd_SmartExtension_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSmartExtensionType_V6(c, &v->extension_type))
    CHECK_ERROR(_readSmartExtensionName_V6(c, &v->extension_name))
    CHECK_ERROR(_readAccountId_V6(c, &v->extension_id))
    CHECK_ERROR(_readBool(c, &v->is_archive))
    return parser_ok;
}

parser_error_t _readSnapshotResult_V6(parser_context_t* c, pd_SnapshotResult_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readStreamDependency_V6(parser_context_t* c, pd_StreamDependency_V6_t* v)
{
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTargetIdAuthorization_V6(parser_context_t* c, pd_TargetIdAuthorization_V6_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId_V6(c, &v->targetId))
    CHECK_ERROR(_readUInt64(c, &v->nonce))
    CHECK_ERROR(_readMoment_V6(c, &v->expiresAt))

    return parser_ok;
}

parser_error_t _readTargetIdentities_V6(parser_context_t* c, pd_TargetIdentities_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readVecIdentityId_V6(c, &v->identities))
    CHECK_ERROR(_readTargetTreatment_V6(c, &v->treatment))
    return parser_ok;
}

parser_error_t _readTargetIdentity_V6(parser_context_t* c, pd_TargetIdentity_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readIdentityId_V6(c, &v->specific))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTargetTreatment_V6(parser_context_t* c, pd_TargetTreatment_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTax_V6(parser_context_t* c, pd_Tax_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPermill_V6(c, &v->value))
    return parser_ok;
}

parser_error_t _readTemplateMetadata_V6(parser_context_t* c, pd_TemplateMetadata_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionMetaUrl_V6(c, &v->url))
    CHECK_ERROR(_readSmartExtensionType_V6(c, &v->se_type))
    CHECK_ERROR(_readBalance(c, &v->usage_fee))
    CHECK_ERROR(_readMetaDescription_V6(c, &v->description))
    CHECK_ERROR(_readMetaVersion_V6(c, &v->version))
    return parser_ok;
}

parser_error_t _readTickerRegistrationConfig_V6(parser_context_t* c, pd_TickerRegistrationConfig_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->max_ticker_length))
    CHECK_ERROR(_readOptionMoment_V6(c, &v->registration_length))
    return parser_ok;
}

parser_error_t _readTicker_V6(parser_context_t* c, pd_Ticker_V6_t* v)
{
    v->_len = 12;
    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readTransferManager_V6(parser_context_t* c, pd_TransferManager_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // CountTransferManager
        CHECK_ERROR(_readCounter_V6(c, &v->countTransferManager))
        break;
    case 1: // PercentageTransferManager
        CHECK_ERROR(_readPercentage_V6(c, &v->percentageTransferManager))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedFor_V6(parser_context_t* c, pd_TrustedFor_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readVecClaimType_V6(c, &v->claims))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedIssuer_V6(parser_context_t* c, pd_TrustedIssuer_V6_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readIdentityId_V6(c, &v->issuer))
    CHECK_ERROR(_readTrustedFor_V6(c, &v->trustedFor))
    return parser_ok;
}

parser_error_t _readTupleCountryCodeScope_V6(parser_context_t* c, pd_TupleCountryCodeScope_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCountryCode_V6(c, &v->country_code))
    CHECK_ERROR(_readScope_V6(c, &v->scope))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdTax_V6(parser_context_t* c, pd_TupleIdentityIdTax_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readIdentityId_V6(c, &v->id))
    CHECK_ERROR(_readTax_V6(c, &v->tax))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdbool_V6(parser_context_t* c, pd_TupleIdentityIdbool_V6_t* v)
{
    CHECK_ERROR(_readIdentityId_V6(c, &v->identity))
    CHECK_ERROR(_readBool(c, &v->val))
    return parser_ok;
}

parser_error_t _readTuplePipIdSnapshotResult_V6(parser_context_t* c, pd_TuplePipIdSnapshotResult_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPipId_V6(c, &v->pip_id))
    CHECK_ERROR(_readSnapshotResult_V6(c, &v->snapshot_result))
    return parser_ok;
}

parser_error_t _readTupleScopeScopeIdCddId_V6(parser_context_t* c, pd_TupleScopeScopeIdCddId_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readScope_V6(c, &v->scope))
    CHECK_ERROR(_readScopeId_V6(c, &v->scopeId))
    CHECK_ERROR(_readCddId_V6(c, &v->cddId))
    return parser_ok;
}

parser_error_t _readUniqueCall_V6(parser_context_t* c, pd_UniqueCall_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->nonce))
    CHECK_ERROR(_readCall(c, &v->call))
    return parser_ok;
}

parser_error_t _readUrl_V6(parser_context_t* c, pd_Url_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readValidatorIndex_V6(parser_context_t* c, pd_ValidatorIndex_V6_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readValidatorPrefs_V6(parser_context_t* c, pd_ValidatorPrefs_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCompactPerBill_V6(c, &v->commission));
    return parser_ok;
}

parser_error_t _readVenueDetails_V6(parser_context_t* c, pd_VenueDetails_V6_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readVenueType_V6(parser_context_t* c, pd_VenueType_V6_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 3) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readWeight_V6(parser_context_t* c, pd_Weight_V6_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readVecAccountId_V6(parser_context_t* c, pd_VecAccountId_V6_t* v) {
    GEN_DEF_READVECTOR(AccountId_V6)
}

parser_error_t _readVecAssetIdentifier_V6(parser_context_t* c, pd_VecAssetIdentifier_V6_t* v) {
    GEN_DEF_READVECTOR(AssetIdentifier_V6)
}

parser_error_t _readVecBallotVote_V6(parser_context_t* c, pd_VecBallotVote_V6_t* v) {
    GEN_DEF_READVECTOR(BallotVote_V6)
}

parser_error_t _readVecBeneficiary_V6(parser_context_t* c, pd_VecBeneficiary_V6_t* v) {
    GEN_DEF_READVECTOR(Beneficiary_V6)
}

parser_error_t _readVecBridgeTx_V6(parser_context_t* c, pd_VecBridgeTx_V6_t* v) {
    GEN_DEF_READVECTOR(BridgeTx_V6)
}

parser_error_t _readVecChoiceTitle_V6(parser_context_t* c, pd_VecChoiceTitle_V6_t* v) {
    GEN_DEF_READVECTOR(ChoiceTitle_V6)
}

parser_error_t _readVecClaimType_V6(parser_context_t* c, pd_VecClaimType_V6_t* v) {
    GEN_DEF_READVECTOR(ClaimType_V6)
}

parser_error_t _readVecClaim_V6(parser_context_t* c, pd_VecClaim_V6_t* v) {
    GEN_DEF_READVECTOR(Claim_V6)
}

parser_error_t _readVecComplianceRequirement_V6(parser_context_t* c, pd_VecComplianceRequirement_V6_t* v) {
    GEN_DEF_READVECTOR(ComplianceRequirement_V6)
}

parser_error_t _readVecCondition_V6(parser_context_t* c, pd_VecCondition_V6_t* v) {
    GEN_DEF_READVECTOR(Condition_V6)
}

parser_error_t _readVecDispatchableName_V6(parser_context_t* c, pd_VecDispatchableName_V6_t* v) {
    GEN_DEF_READVECTOR(DispatchableName_V6)
}

parser_error_t _readVecDocumentId_V6(parser_context_t* c, pd_VecDocumentId_V6_t* v) {
    GEN_DEF_READVECTOR(DocumentId_V6)
}

parser_error_t _readVecDocument_V6(parser_context_t* c, pd_VecDocument_V6_t* v) {
    GEN_DEF_READVECTOR(Document_V6)
}

parser_error_t _readVecIdentityId_V6(parser_context_t* c, pd_VecIdentityId_V6_t* v) {
    GEN_DEF_READVECTOR(IdentityId_V6)
}

parser_error_t _readVecKeyValue_V6(parser_context_t* c, pd_VecKeyValue_V6_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V6)
}

parser_error_t _readVecKey_V6(parser_context_t* c, pd_VecKey_V6_t* v) {
    GEN_DEF_READVECTOR(Key_V6)
}

parser_error_t _readVecLeg_V6(parser_context_t* c, pd_VecLeg_V6_t* v) {
    GEN_DEF_READVECTOR(Leg_V6)
}

parser_error_t _readVecLookupSource_V6(parser_context_t* c, pd_VecLookupSource_V6_t* v) {
    GEN_DEF_READVECTOR(LookupSource_V6)
}

parser_error_t _readVecMotion_V6(parser_context_t* c, pd_VecMotion_V6_t* v) {
    GEN_DEF_READVECTOR(Motion_V6)
}

parser_error_t _readVecMovePortfolioItem_V6(parser_context_t* c, pd_VecMovePortfolioItem_V6_t* v) {
    GEN_DEF_READVECTOR(MovePortfolioItem_V6)
}

parser_error_t _readVecPalletPermissions_V6(parser_context_t* c, pd_VecPalletPermissions_V6_t* v) {
    GEN_DEF_READVECTOR(PalletPermissions_V6)
}

parser_error_t _readVecPortfolioId_V6(parser_context_t* c, pd_VecPortfolioId_V6_t* v) {
    GEN_DEF_READVECTOR(PortfolioId_V6)
}

parser_error_t _readVecPriceTier_V6(parser_context_t* c, pd_VecPriceTier_V6_t* v) {
    GEN_DEF_READVECTOR(PriceTier_V6)
}

parser_error_t _readVecReceiptDetails_V6(parser_context_t* c, pd_VecReceiptDetails_V6_t* v) {
    GEN_DEF_READVECTOR(ReceiptDetails_V6)
}

parser_error_t _readVecScopeId_V6(parser_context_t* c, pd_VecScopeId_V6_t* v) {
    GEN_DEF_READVECTOR(ScopeId_V6)
}

parser_error_t _readVecSecondaryKeyWithAuth_V6(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V6_t* v) {
    GEN_DEF_READVECTOR(SecondaryKeyWithAuth_V6)
}

parser_error_t _readVecSecondaryKey_V6(parser_context_t* c, pd_VecSecondaryKey_V6_t* v) {
    GEN_DEF_READVECTOR(SecondaryKey_V6)
}

parser_error_t _readVecSignatory_V6(parser_context_t* c, pd_VecSignatory_V6_t* v) {
    GEN_DEF_READVECTOR(Signatory_V6)
}

parser_error_t _readVecTicker_V6(parser_context_t* c, pd_VecTicker_V6_t* v) {
    GEN_DEF_READVECTOR(Ticker_V6)
}

parser_error_t _readVecTrustedIssuer_V6(parser_context_t* c, pd_VecTrustedIssuer_V6_t* v) {
    GEN_DEF_READVECTOR(TrustedIssuer_V6)
}

parser_error_t _readVecTupleIdentityIdTax_V6(parser_context_t* c, pd_VecTupleIdentityIdTax_V6_t* v) {
    GEN_DEF_READVECTOR(TupleIdentityIdTax_V6)
}

parser_error_t _readVecTupleIdentityIdbool_V6(parser_context_t* c, pd_VecTupleIdentityIdbool_V6_t* v) {
    GEN_DEF_READVECTOR(TupleIdentityIdbool_V6)
}

parser_error_t _readVecTuplePipIdSnapshotResult_V6(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V6_t* v) {
    GEN_DEF_READVECTOR(TuplePipIdSnapshotResult_V6)
}

parser_error_t _readVecValidatorIndex_V6(parser_context_t* c, pd_VecValidatorIndex_V6_t* v) {
    GEN_DEF_READVECTOR(ValidatorIndex_V6)
}

parser_error_t _readOptionChangesTrieConfiguration_V6(parser_context_t* c, pd_OptionChangesTrieConfiguration_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionDocumentType_V6(parser_context_t* c, pd_OptionDocumentType_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readDocumentType_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionFundingRoundName_V6(parser_context_t* c, pd_OptionFundingRoundName_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readFundingRoundName_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMemo_V6(parser_context_t* c, pd_OptionMemo_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMemo_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMetaUrl_V6(parser_context_t* c, pd_OptionMetaUrl_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMetaUrl_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMoment_V6(parser_context_t* c, pd_OptionMoment_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMoment_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod_V6(parser_context_t* c, pd_OptionPeriod_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPipDescription_V6(parser_context_t* c, pd_OptionPipDescription_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPipDescription_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPortfolioNumber_V6(parser_context_t* c, pd_OptionPortfolioNumber_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPortfolioNumber_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReceiptDetails_V6(parser_context_t* c, pd_OptionReceiptDetails_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReceiptDetails_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionRecordDateSpec_V6(parser_context_t* c, pd_OptionRecordDateSpec_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRecordDateSpec_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTargetIdentities_V6(parser_context_t* c, pd_OptionTargetIdentities_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTargetIdentities_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTax_V6(parser_context_t* c, pd_OptionTax_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTax_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionUrl_V6(parser_context_t* c, pd_OptionUrl_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readUrl_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecDispatchableName_V6(parser_context_t* c, pd_OptionVecDispatchableName_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecDispatchableName_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPalletPermissions_V6(parser_context_t* c, pd_OptionVecPalletPermissions_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPalletPermissions_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPortfolioId_V6(parser_context_t* c, pd_OptionVecPortfolioId_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPortfolioId_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTicker_V6(parser_context_t* c, pd_OptionVecTicker_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTicker_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTupleIdentityIdTax_V6(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTupleIdentityIdTax_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVenueDetails_V6(parser_context_t* c, pd_OptionVenueDetails_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVenueDetails_V6(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVenueType_V6(parser_context_t* c, pd_OptionVenueType_V6_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVenueType_V6(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactAssignments_V6(
    const pd_CompactAssignments_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactEraIndex_V6(
    const pd_CompactEraIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactGas_V6(
    const pd_CompactGas_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment_V6(
    const pd_CompactMoment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, 0, "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountId_V6(
    const pd_AccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V6(
    const pd_AccountIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetIdentifier_V6(
    const pd_AssetIdentifier_V6_t* v,
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

parser_error_t _toStringAssetName_V6(
    const pd_AssetName_V6_t* v,
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

parser_error_t _toStringAssetType_V6(
    const pd_AssetType_V6_t* v,
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

parser_error_t _toStringAuthorizationData_V6(
    const pd_AuthorizationData_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
    uint8_t _dummy;

    // Count the total pages (pageCount) first (Printing the enum name adds 1 page).
    // If pageIdx == 0, prints enum name, else prints value.

    switch (v->value) {
    case 0: // AttestPrimaryKeyRotation
        CHECK_ERROR(_toStringIdentityId_V6(&v->identityId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("AttestPrimaryKeyRotation")
        CHECK_ERROR(_toStringIdentityId_V6(&v->identityId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 1: // RotatePrimaryKey
        CHECK_ERROR(_toStringIdentityId_V6(&v->identityId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("RotatePrimaryKey")
        CHECK_ERROR(_toStringIdentityId_V6(&v->identityId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 2: // TransferTicker
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferTicker")
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 3: // TransferPrimaryIssuanceAgent
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferPrimaryIssuanceAgent")
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 5: // TransferAssetOwnership
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferAssetOwnership")
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 8: // Custom
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("Custom")
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 10: // TransferCorporateActionAgent
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferCorporateActionAgent")
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 4: // AddMultiSigSigner
        CHECK_ERROR(_toStringAccountId_V6(&v->accountId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("AddMultiSigSigner")
        CHECK_ERROR(_toStringAccountId_V6(&v->accountId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 6: // JoinIdentity
        CHECK_ERROR(_toStringPermissions_V6(&v->permissions, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("JoinIdentity")
        CHECK_ERROR(_toStringPermissions_V6(&v->permissions, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 7: // PortfolioCustody
        CHECK_ERROR(_toStringPortfolioId_V6(&v->portfolioId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("PortfolioCustody")
        CHECK_ERROR(_toStringPortfolioId_V6(&v->portfolioId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 9: // NoData
        snprintf(outValue, outValueLen, "NoData");
        *pageCount = 1;
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringBallotMeta_V6(
    const pd_BallotMeta_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBallotTitle_V6(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecMotion_V6(&v->motions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBallotTitle_V6(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecMotion_V6(&v->motions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTimeRange_V6(
    const pd_BallotTimeRange_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringMoment_V6(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMoment_V6(&v->end, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMoment_V6(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMoment_V6(&v->end, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTitle_V6(
    const pd_BallotTitle_V6_t* v,
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

parser_error_t _toStringBallotVote_V6(
    const pd_BallotVote_V6_t* v,
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

parser_error_t _toStringBeneficiary_V6(
    const pd_Beneficiary_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V6(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V6(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringBridgeTx_V6(
    const pd_BridgeTx_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringu32(&v->nonce, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAccountId_V6(&v->recipient, outValue, outValueLen, 0, &pages[1]))
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
        CHECK_ERROR(_toStringAccountId_V6(&v->recipient, outValue, outValueLen, pageIdx, &pages[1]))
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

parser_error_t _toStringCADetails_V6(
    const pd_CADetails_V6_t* v,
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

parser_error_t _toStringCAId_V6(
    const pd_CAId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringLocalCAId_V6(&v->local_id, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringLocalCAId_V6(&v->local_id, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCAKind_V6(
    const pd_CAKind_V6_t* v,
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

parser_error_t _toStringCalendarPeriod_V6(
    const pd_CalendarPeriod_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCalendarUnit_V6(&v->unit, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCalendarUnit_V6(&v->unit, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringCalendarUnit_V6(
    const pd_CalendarUnit_V6_t* v,
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

parser_error_t _toStringCddId_V6(
    const pd_CddId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChangesTrieConfiguration_V6(
    const pd_ChangesTrieConfiguration_V6_t* v,
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

parser_error_t _toStringCheckpointId_V6(
    const pd_CheckpointId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChoiceTitle_V6(
    const pd_ChoiceTitle_V6_t* v,
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

parser_error_t _toStringClaimType_V6(
    const pd_ClaimType_V6_t* v,
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

parser_error_t _toStringClaim_V6(
    const pd_Claim_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
    uint8_t _dummy;

    // Count the total pages (pageCount) first (Printing the enum name adds 1 page).
    // If pageIdx == 0, prints enum name, else prints value.

    switch (v->value) {
    case 0: // Accredited
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Accredited");
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 1: // Affiliate
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Affiliate");
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 2: // BuyLockup
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("BuyLockup");
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 3: // SellLockup
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("SellLockup");
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 5: // KnowYourCustomer
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("KnowYourCustomer");
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 7: // Exempted
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Exempted");
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 8: // Blocked
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Blocked");
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_toStringCddId_V6(&v->cddId, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("CustomerDueDiligence");
        CHECK_ERROR(_toStringCddId_V6(&v->cddId, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_toStringTupleCountryCodeScope_V6(&v->jurisdiction, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Jurisdiction");
        CHECK_ERROR(_toStringTupleCountryCodeScope_V6(&v->jurisdiction, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_toStringTupleScopeScopeIdCddId_V6(&v->investorUniqueness, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("InvestorUniqueness");
        CHECK_ERROR(_toStringTupleScopeScopeIdCddId_V6(&v->investorUniqueness, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 10: // NoData
        snprintf(outValue, outValueLen, "NoData");
        *pageCount = 1;
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringClassicTickerImport_V6(
    const pd_ClassicTickerImport_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringEthereumAddress_V6(&v->eth_owner, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_contract, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->is_created, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringEthereumAddress_V6(&v->eth_owner, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->is_contract, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringbool(&v->is_created, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCodeHash_V6(
    const pd_CodeHash_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringHash(&v->hash, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactPerBill_V6(
    const pd_CompactPerBill_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringComplianceRequirement_V6(
    const pd_ComplianceRequirement_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringVecCondition_V6(&v->senderConditions, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecCondition_V6(&v->receiverConditions, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecCondition_V6(&v->senderConditions, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecCondition_V6(&v->receiverConditions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringConditionType_V6(
    const pd_ConditionType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    switch (v->value) {
    case 0: // IsPresent
    case 1: // IsAbsent
        CHECK_ERROR(_toStringClaim_V6(&v->claim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // IsAnyOf
    case 3: // IsNoneOf
        CHECK_ERROR(_toStringVecClaim_V6(&v->vecClaim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // IsIdentity
        CHECK_ERROR(_toStringTargetIdentity_V6(&v->identity, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringCondition_V6(
    const pd_Condition_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringConditionType_V6(&v->conditionType, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecTrustedIssuer_V6(&v->issuers, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringConditionType_V6(&v->conditionType, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecTrustedIssuer_V6(&v->issuers, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCounter_V6(
    const pd_Counter_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCountryCode_V6(
    const pd_CountryCode_V6_t* v,
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

parser_error_t _toStringDispatchableName_V6(
    const pd_DispatchableName_V6_t* v,
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

parser_error_t _toStringDocumentHash_V6(
    const pd_DocumentHash_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(v->_len)
}

parser_error_t _toStringDocumentId_V6(
    const pd_DocumentId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDocumentName_V6(
    const pd_DocumentName_V6_t* v,
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

parser_error_t _toStringDocumentType_V6(
    const pd_DocumentType_V6_t* v,
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

parser_error_t _toStringDocumentUri_V6(
    const pd_DocumentUri_V6_t* v,
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

parser_error_t _toStringDocument_V6(
    const pd_Document_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringDocumentUri_V6(&v->uri, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringDocumentHash_V6(&v->content_hash, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringDocumentName_V6(&v->name, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionDocumentType_V6(&v->doc_type, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionMoment_V6(&v->filing_date, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringDocumentUri_V6(&v->uri, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringDocumentHash_V6(&v->content_hash, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringDocumentName_V6(&v->name, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionDocumentType_V6(&v->doc_type, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionMoment_V6(&v->filing_date, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEcdsaSignature_V6(
    const pd_EcdsaSignature_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V6(
    const pd_ElectionScore_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringElectionSize_V6(
    const pd_ElectionSize_V6_t* v,
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
        CHECK_ERROR(_toStringCompactInt(&v->validators, COIN_AMOUNT_DECIMAL_PLACES, 0, "", outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactInt(&v->nominators, COIN_AMOUNT_DECIMAL_PLACES, 0, "", outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEquivocationProof_V6(
    const pd_EquivocationProof_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringEraIndex_V6(
    const pd_EraIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V6(
    const pd_EthereumAddress_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringFundingRoundName_V6(
    const pd_FundingRoundName_V6_t* v,
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

parser_error_t _toStringFundraiserName_V6(
    const pd_FundraiserName_V6_t* v,
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

parser_error_t _toStringIdentityId_V6(
    const pd_IdentityId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringInvestorUid_V6(
    const pd_InvestorUid_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(16)
}

parser_error_t _toStringInvestorZKProofData_V6(
    const pd_InvestorZKProofData_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringKeyOwnerProof_V6(
    const pd_KeyOwnerProof_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V6(
    const pd_KeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V6(
    const pd_Key_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V6(
    const pd_Keys_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLeg_V6(
    const pd_Leg_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringPortfolioId_V6(&v->from, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioId_V6(&v->to, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTicker_V6(&v->asset, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringBalance(&v->amount, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPortfolioId_V6(&v->from, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioId_V6(&v->to, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTicker_V6(&v->asset, outValue, outValueLen, pageIdx, &pages[2]))
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

parser_error_t _toStringLegacyPermissions_V6(
    const pd_LegacyPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringLocalCAId_V6(
    const pd_LocalCAId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringLookupSource_V6(
    const pd_LookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMaybeBlock_V6(
    const pd_MaybeBlock_V6_t* v,
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

parser_error_t _toStringMemberCount_V6(
    const pd_MemberCount_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMemo_V6(
    const pd_Memo_V6_t* v,
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

parser_error_t _toStringMetaDescription_V6(
    const pd_MetaDescription_V6_t* v,
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

parser_error_t _toStringMetaUrl_V6(
    const pd_MetaUrl_V6_t* v,
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

parser_error_t _toStringMetaVersion_V6(
    const pd_MetaVersion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMoment_V6(
    const pd_Moment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMotionInfoLink_V6(
    const pd_MotionInfoLink_V6_t* v,
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

parser_error_t _toStringMotionTitle_V6(
    const pd_MotionTitle_V6_t* v,
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

parser_error_t _toStringMotion_V6(
    const pd_Motion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringMotionTitle_V6(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMotionInfoLink_V6(&v->info_link, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecChoiceTitle_V6(&v->choices, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMotionTitle_V6(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMotionInfoLink_V6(&v->info_link, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecChoiceTitle_V6(&v->choices, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMovePortfolioItem_V6(
    const pd_MovePortfolioItem_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringOffChainSignature_V6(
    const pd_OffChainSignature_V6_t* v,
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

parser_error_t _toStringOfflineSlashingParams_V6(
    const pd_OfflineSlashingParams_V6_t* v,
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

parser_error_t _toStringPalletName_V6(
    const pd_PalletName_V6_t* v,
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

parser_error_t _toStringPalletPermissions_V6(
    const pd_PalletPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPalletName_V6(&v->palletName, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecDispatchableName_V6(&v->dispatchableNames, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPalletName_V6(&v->palletName, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecDispatchableName_V6(&v->dispatchableNames, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPerbill_V6(
    const pd_Perbill_V6_t* v,
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

parser_error_t _toStringPercent_V6(
    const pd_Percent_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, '%', "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPercentage_V6(
    const pd_Percentage_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringPermill_V6(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringPeriod_V6(
    const pd_Period_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPermill_V6(
    const pd_Permill_V6_t* v,
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

parser_error_t _toStringPermissions_V6(
    const pd_Permissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringOptionVecTicker_V6(&v->asset, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecPalletPermissions_V6(&v->extrinsic, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionVecPortfolioId_V6(&v->portfolio, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionVecTicker_V6(&v->asset, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecPalletPermissions_V6(&v->extrinsic, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionVecPortfolioId_V6(&v->portfolio, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPipDescription_V6(
    const pd_PipDescription_V6_t* v,
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

parser_error_t _toStringPipId_V6(
    const pd_PipId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPortfolioId_V6(
    const pd_PortfolioId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V6(&v->did, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioKind_V6(&v->kind, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V6(&v->did, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioKind_V6(&v->kind, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPortfolioKind_V6(
    const pd_PortfolioKind_V6_t* v,
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
        _toStringPortfolioNumber_V6(&v->number, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringPortfolioName_V6(
    const pd_PortfolioName_V6_t* v,
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

parser_error_t _toStringPortfolioNumber_V6(
    const pd_PortfolioNumber_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPosRatio_V6(
    const pd_PosRatio_V6_t* v,
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

parser_error_t _toStringPriceTier_V6(
    const pd_PriceTier_V6_t* v,
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

parser_error_t _toStringPriority_V6(
    const pd_Priority_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency_V6(&v->dependency, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringStreamDependency_V6(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProposalIndex_V6(
    const pd_ProposalIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProtocolOp_V6(
    const pd_ProtocolOp_V6_t* v,
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

parser_error_t _toStringReceiptDetails_V6(
    const pd_ReceiptDetails_V6_t* v,
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
    CHECK_ERROR(_toStringAccountId_V6(&v->signer, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOffChainSignature_V6(&v->signature, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringReceiptMetadata_V6(&v->metadata, outValue, outValueLen, 0, &pages[4]))

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
        CHECK_ERROR(_toStringAccountId_V6(&v->signer, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOffChainSignature_V6(&v->signature, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringReceiptMetadata_V6(&v->metadata, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringReceiptMetadata_V6(
    const pd_ReceiptMetadata_V6_t* v,
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

parser_error_t _toStringRecordDateSpec_V6(
    const pd_RecordDateSpec_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_toStringMoment_V6(&v->scheduled, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1: // ExistingSchedule
        CHECK_ERROR(_toStringScheduleId_V6(&v->existingSchedule, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 2: // Existing
        CHECK_ERROR(_toStringCheckpointId_V6(&v->existing, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringRewardDestination_V6(
    const pd_RewardDestination_V6_t* v,
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

parser_error_t _toStringScheduleId_V6(
    const pd_ScheduleId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringScheduleSpec_V6(
    const pd_ScheduleSpec_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringOptionMoment_V6(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCalendarPeriod_V6(&v->period, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMoment_V6(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCalendarPeriod_V6(&v->period, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSchedule_V6(
    const pd_Schedule_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringScopeId_V6(
    const pd_ScopeId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringScope_V6(
    const pd_Scope_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId_V6(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringTicker_V6(&v->ticker, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 2:
        GEN_DEF_TOSTRING_ARRAY(v->_len)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSecondaryKeyWithAuth_V6(
    const pd_SecondaryKeyWithAuth_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSecondaryKey_V6(&v->secondary_key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSignature_V6(&v->auth_signature, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSecondaryKey_V6(&v->secondary_key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSignature_V6(&v->auth_signature, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSecondaryKey_V6(
    const pd_SecondaryKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSignatory_V6(&v->signer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPermissions_V6(&v->permissions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSignatory_V6(&v->signer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPermissions_V6(&v->permissions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSettlementType_V6(
    const pd_SettlementType_V6_t* v,
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

parser_error_t _toStringSignatory_V6(
    const pd_Signatory_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId_V6(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringAccountId_V6(&v->account, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSignature_V6(
    const pd_Signature_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSkippedCount_V6(
    const pd_SkippedCount_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    uint16_t valu16 = (uint16_t)v->value;
    return _toStringu16(&valu16, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSlashingSwitch_V6(
    const pd_SlashingSwitch_V6_t* v,
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

parser_error_t _toStringSmartExtensionName_V6(
    const pd_SmartExtensionName_V6_t* v,
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

parser_error_t _toStringSmartExtensionType_V6(
    const pd_SmartExtensionType_V6_t* v,
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

parser_error_t _toStringSmartExtension_V6(
    const pd_SmartExtension_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringSmartExtensionType_V6(&v->extension_type, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSmartExtensionName_V6(&v->extension_name, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringAccountId_V6(&v->extension_id, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->is_archive, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSmartExtensionType_V6(&v->extension_type, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSmartExtensionName_V6(&v->extension_name, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringAccountId_V6(&v->extension_id, outValue, outValueLen, pageIdx, &pages[2]))
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

parser_error_t _toStringSnapshotResult_V6(
    const pd_SnapshotResult_V6_t* v,
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

parser_error_t _toStringStreamDependency_V6(
    const pd_StreamDependency_V6_t* v,
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

parser_error_t _toStringTargetIdAuthorization_V6(
    const pd_TargetIdAuthorization_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringIdentityId_V6(&v->targetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringMoment_V6(&v->expiresAt, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V6(&v->targetId, outValue, outValueLen, pageIdx, &pages[0]))
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
        CHECK_ERROR(_toStringMoment_V6(&v->expiresAt, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdentities_V6(
    const pd_TargetIdentities_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringVecIdentityId_V6(&v->identities, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTargetTreatment_V6(&v->treatment, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecIdentityId_V6(&v->identities, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTargetTreatment_V6(&v->treatment, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdentity_V6(
    const pd_TargetIdentity_V6_t* v,
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
        _toStringIdentityId_V6(&v->specific, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTargetTreatment_V6(
    const pd_TargetTreatment_V6_t* v,
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

parser_error_t _toStringTax_V6(
    const pd_Tax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringPermill_V6(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringTemplateMetadata_V6(
    const pd_TemplateMetadata_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringOptionMetaUrl_V6(&v->url, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSmartExtensionType_V6(&v->se_type, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->usage_fee, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringMetaDescription_V6(&v->description, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringMetaVersion_V6(&v->version, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMetaUrl_V6(&v->url, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSmartExtensionType_V6(&v->se_type, outValue, outValueLen, pageIdx, &pages[1]))
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
        CHECK_ERROR(_toStringMetaDescription_V6(&v->description, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringMetaVersion_V6(&v->version, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTickerRegistrationConfig_V6(
    const pd_TickerRegistrationConfig_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->max_ticker_length, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionMoment_V6(&v->registration_length, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringOptionMoment_V6(&v->registration_length, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTicker_V6(
    const pd_Ticker_V6_t* v,
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

parser_error_t _toStringTransferManager_V6(
    const pd_TransferManager_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // CountTransferManager
        CHECK_ERROR(_toStringCounter_V6(&v->countTransferManager, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1: // PercentageTransferManager
        CHECK_ERROR(_toStringPercentage_V6(&v->percentageTransferManager, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTrustedFor_V6(
    const pd_TrustedFor_V6_t* v,
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
        _toStringVecClaimType_V6(&v->claims, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTrustedIssuer_V6(
    const pd_TrustedIssuer_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V6(&v->issuer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTrustedFor_V6(&v->trustedFor, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V6(&v->issuer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTrustedFor_V6(&v->trustedFor, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleCountryCodeScope_V6(
    const pd_TupleCountryCodeScope_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCountryCode_V6(&v->country_code, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCountryCode_V6(&v->country_code, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdTax_V6(
    const pd_TupleIdentityIdTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V6(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTax_V6(&v->tax, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V6(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTax_V6(&v->tax, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdbool_V6(
    const pd_TupleIdentityIdbool_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V6(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V6(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTuplePipIdSnapshotResult_V6(
    const pd_TuplePipIdSnapshotResult_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPipId_V6(&v->pip_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSnapshotResult_V6(&v->snapshot_result, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPipId_V6(&v->pip_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSnapshotResult_V6(&v->snapshot_result, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleScopeScopeIdCddId_V6(
    const pd_TupleScopeScopeIdCddId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScopeId_V6(&v->scopeId, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCddId_V6(&v->cddId, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringScope_V6(&v->scope, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScopeId_V6(&v->scopeId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCddId_V6(&v->cddId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUniqueCall_V6(
    const pd_UniqueCall_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCall(&v->call, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCall(&v->call, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUrl_V6(
    const pd_Url_V6_t* v,
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

parser_error_t _toStringValidatorIndex_V6(
    const pd_ValidatorIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringValidatorPrefs_V6(
    const pd_ValidatorPrefs_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return _toStringCompactPerBill_V6(&v->commission, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVenueDetails_V6(
    const pd_VenueDetails_V6_t* v,
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

parser_error_t _toStringVenueType_V6(
    const pd_VenueType_V6_t* v,
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

parser_error_t _toStringWeight_V6(
    const pd_Weight_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecAccountId_V6(
    const pd_VecAccountId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V6);
}

parser_error_t _toStringVecAssetIdentifier_V6(
    const pd_VecAssetIdentifier_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdentifier_V6);
}

parser_error_t _toStringVecBallotVote_V6(
    const pd_VecBallotVote_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BallotVote_V6);
}

parser_error_t _toStringVecBeneficiary_V6(
    const pd_VecBeneficiary_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Beneficiary_V6);
}

parser_error_t _toStringVecBridgeTx_V6(
    const pd_VecBridgeTx_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BridgeTx_V6);
}

parser_error_t _toStringVecChoiceTitle_V6(
    const pd_VecChoiceTitle_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ChoiceTitle_V6);
}

parser_error_t _toStringVecClaimType_V6(
    const pd_VecClaimType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ClaimType_V6);
}

parser_error_t _toStringVecClaim_V6(
    const pd_VecClaim_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Claim_V6);
}

parser_error_t _toStringVecComplianceRequirement_V6(
    const pd_VecComplianceRequirement_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ComplianceRequirement_V6);
}

parser_error_t _toStringVecCondition_V6(
    const pd_VecCondition_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Condition_V6);
}

parser_error_t _toStringVecDispatchableName_V6(
    const pd_VecDispatchableName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DispatchableName_V6);
}

parser_error_t _toStringVecDocumentId_V6(
    const pd_VecDocumentId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DocumentId_V6);
}

parser_error_t _toStringVecDocument_V6(
    const pd_VecDocument_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Document_V6);
}

parser_error_t _toStringVecIdentityId_V6(
    const pd_VecIdentityId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(IdentityId_V6);
}

parser_error_t _toStringVecKeyValue_V6(
    const pd_VecKeyValue_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V6);
}

parser_error_t _toStringVecKey_V6(
    const pd_VecKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V6);
}

parser_error_t _toStringVecLeg_V6(
    const pd_VecLeg_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Leg_V6);
}

parser_error_t _toStringVecLookupSource_V6(
    const pd_VecLookupSource_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupSource_V6);
}

parser_error_t _toStringVecMotion_V6(
    const pd_VecMotion_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Motion_V6);
}

parser_error_t _toStringVecMovePortfolioItem_V6(
    const pd_VecMovePortfolioItem_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MovePortfolioItem_V6);
}

parser_error_t _toStringVecPalletPermissions_V6(
    const pd_VecPalletPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PalletPermissions_V6);
}

parser_error_t _toStringVecPortfolioId_V6(
    const pd_VecPortfolioId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PortfolioId_V6);
}

parser_error_t _toStringVecPriceTier_V6(
    const pd_VecPriceTier_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PriceTier_V6);
}

parser_error_t _toStringVecReceiptDetails_V6(
    const pd_VecReceiptDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ReceiptDetails_V6);
}

parser_error_t _toStringVecScopeId_V6(
    const pd_VecScopeId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ScopeId_V6);
}

parser_error_t _toStringVecSecondaryKeyWithAuth_V6(
    const pd_VecSecondaryKeyWithAuth_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKeyWithAuth_V6);
}

parser_error_t _toStringVecSecondaryKey_V6(
    const pd_VecSecondaryKey_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKey_V6);
}

parser_error_t _toStringVecSignatory_V6(
    const pd_VecSignatory_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Signatory_V6);
}

parser_error_t _toStringVecTicker_V6(
    const pd_VecTicker_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Ticker_V6);
}

parser_error_t _toStringVecTrustedIssuer_V6(
    const pd_VecTrustedIssuer_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TrustedIssuer_V6);
}

parser_error_t _toStringVecTupleIdentityIdTax_V6(
    const pd_VecTupleIdentityIdTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdTax_V6);
}

parser_error_t _toStringVecTupleIdentityIdbool_V6(
    const pd_VecTupleIdentityIdbool_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdbool_V6);
}

parser_error_t _toStringVecTuplePipIdSnapshotResult_V6(
    const pd_VecTuplePipIdSnapshotResult_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TuplePipIdSnapshotResult_V6);
}

parser_error_t _toStringVecValidatorIndex_V6(
    const pd_VecValidatorIndex_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ValidatorIndex_V6);
}

parser_error_t _toStringOptionChangesTrieConfiguration_V6(
    const pd_OptionChangesTrieConfiguration_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionDocumentType_V6(
    const pd_OptionDocumentType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringDocumentType_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionFundingRoundName_V6(
    const pd_OptionFundingRoundName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringFundingRoundName_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMemo_V6(
    const pd_OptionMemo_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMemo_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMetaUrl_V6(
    const pd_OptionMetaUrl_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMetaUrl_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMoment_V6(
    const pd_OptionMoment_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMoment_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod_V6(
    const pd_OptionPeriod_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPipDescription_V6(
    const pd_OptionPipDescription_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPipDescription_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPortfolioNumber_V6(
    const pd_OptionPortfolioNumber_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPortfolioNumber_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReceiptDetails_V6(
    const pd_OptionReceiptDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReceiptDetails_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionRecordDateSpec_V6(
    const pd_OptionRecordDateSpec_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringRecordDateSpec_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTargetIdentities_V6(
    const pd_OptionTargetIdentities_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTargetIdentities_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTax_V6(
    const pd_OptionTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTax_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionUrl_V6(
    const pd_OptionUrl_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringUrl_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecDispatchableName_V6(
    const pd_OptionVecDispatchableName_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecDispatchableName_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPalletPermissions_V6(
    const pd_OptionVecPalletPermissions_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPalletPermissions_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPortfolioId_V6(
    const pd_OptionVecPortfolioId_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPortfolioId_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTicker_V6(
    const pd_OptionVecTicker_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTicker_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTupleIdentityIdTax_V6(
    const pd_OptionVecTupleIdentityIdTax_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTupleIdentityIdTax_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVenueDetails_V6(
    const pd_OptionVenueDetails_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVenueDetails_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVenueType_V6(
    const pd_OptionVenueType_V6_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVenueType_V6(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
