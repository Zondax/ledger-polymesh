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
#include "substrate_dispatch_V1.h"
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readCompactAssignments_V1(parser_context_t* c, pd_CompactAssignments_V1_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactEraIndex_V1(parser_context_t* c, pd_CompactEraIndex_V1_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readCompactMoment_V1(parser_context_t* c, pd_CompactMoment_V1_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAGId_V1(parser_context_t* c, pd_AGId_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAccountId_V1(parser_context_t* c, pd_AccountId_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIndex_V1(parser_context_t* c, pd_AccountIndex_V1_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readAgentGroup_V1(parser_context_t* c, pd_AgentGroup_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readAssetIdentifier_V1(parser_context_t* c, pd_AssetIdentifier_V1_t* v)
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

parser_error_t _readAssetName_V1(parser_context_t* c, pd_AssetName_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readAssetType_V1(parser_context_t* c, pd_AssetType_V1_t* v)
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

parser_error_t _readAuthorizationData_V1(parser_context_t* c, pd_AuthorizationData_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_ERROR(_readIdentityId_V1(c, &v->identityId))
        break;
    case 2:
    case 3:
    case 5:
    case 8:
    case 10:
        CHECK_ERROR(_readTicker_V1(c, &v->ticker))
        break;
    case 4:
        CHECK_ERROR(_readAccountId_V1(c, &v->accountId))
        break;
    case 6:
        CHECK_ERROR(_readPermissions_V1(c, &v->permissions))
        break;
    case 7:
        CHECK_ERROR(_readPortfolioId_V1(c, &v->portfolioId))
        break;
    case 9:
        // noData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBabeEquivocationProof_V1(parser_context_t* c, pd_BabeEquivocationProof_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readBallotMeta_V1(parser_context_t* c, pd_BallotMeta_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBallotTitle_V1(c, &v->title))
    CHECK_ERROR(_readVecMotion_V1(c, &v->motions))
    return parser_ok;
}

parser_error_t _readBallotTimeRange_V1(parser_context_t* c, pd_BallotTimeRange_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readMoment_V1(c, &v->start))
    CHECK_ERROR(_readMoment_V1(c, &v->end))
    return parser_ok;
}

parser_error_t _readBallotTitle_V1(parser_context_t* c, pd_BallotTitle_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readBallotVote_V1(parser_context_t* c, pd_BallotVote_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->power))
    CHECK_ERROR(_readOptionu16(c, &v->fallback))
    return parser_ok;
}

parser_error_t _readBeneficiary_V1(parser_context_t* c, pd_Beneficiary_V1_t* v)
{
    CHECK_ERROR(_readIdentityId_V1(c, &v->identity))
    CHECK_ERROR(_readBalance(c, &v->balance))
    return parser_ok;
}

parser_error_t _readBridgeTx_V1(parser_context_t* c, pd_BridgeTx_V1_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt32(c, &v->nonce))
    CHECK_ERROR(_readAccountId_V1(c, &v->recipient))
    CHECK_ERROR(_readBalance(c, &v->value))
    CHECK_ERROR(_readHash(c, &v->txHash))

    return parser_ok;
}

parser_error_t _readCADetails_V1(parser_context_t* c, pd_CADetails_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readCAId_V1(parser_context_t* c, pd_CAId_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readTicker_V1(c, &v->ticker))
    CHECK_ERROR(_readLocalCAId_V1(c, &v->local_id))
    return parser_ok;
}

parser_error_t _readCAKind_V1(parser_context_t* c, pd_CAKind_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCalendarPeriod_V1(parser_context_t* c, pd_CalendarPeriod_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCalendarUnit_V1(c, &v->unit))
    CHECK_ERROR(_readUInt64(c, &v->amount))
    return parser_ok;
}

parser_error_t _readCalendarUnit_V1(parser_context_t* c, pd_CalendarUnit_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCddId_V1(parser_context_t* c, pd_CddId_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readChangesTrieConfiguration_V1(parser_context_t* c, pd_ChangesTrieConfiguration_V1_t* v)
{
    CHECK_ERROR(_readu32(c, &v->digest_interval))
    CHECK_ERROR(_readu32(c, &v->digest_levels))
    return parser_ok;
}

parser_error_t _readCheckpointId_V1(parser_context_t* c, pd_CheckpointId_V1_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readChoiceTitle_V1(parser_context_t* c, pd_ChoiceTitle_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readClaimType_V1(parser_context_t* c, pd_ClaimType_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readClaim_V1(parser_context_t* c, pd_Claim_V1_t* v)
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
        CHECK_ERROR(_readScope_V1(c, &v->scope))
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_readCddId_V1(c, &v->cddId))
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_readTupleCountryCodeScope_V1(c, &v->jurisdiction))
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_readTupleScopeScopeIdCddId_V1(c, &v->investorUniqueness))
        break;
    case 10: // NoData
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readClassicTickerImport_V1(parser_context_t* c, pd_ClassicTickerImport_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readEthereumAddress_V1(c, &v->eth_owner))
    CHECK_ERROR(_readTicker_V1(c, &v->ticker))
    CHECK_ERROR(_readBool(c, &v->is_contract))
    CHECK_ERROR(_readBool(c, &v->is_created))
    return parser_ok;
}

parser_error_t _readCompactPerBill_V1(parser_context_t* c, pd_CompactPerBill_V1_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readComplianceRequirement_V1(parser_context_t* c, pd_ComplianceRequirement_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readVecCondition_V1(c, &v->senderConditions))
    CHECK_ERROR(_readVecCondition_V1(c, &v->receiverConditions))
    CHECK_ERROR(_readUInt32(c, &v->id))
    return parser_ok;
}

parser_error_t _readConditionType_V1(parser_context_t* c, pd_ConditionType_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_ERROR(_readClaim_V1(c, &v->claim))
        break;
    case 2:
    case 3:
        CHECK_ERROR(_readVecClaim_V1(c, &v->vecClaim))
        break;
    case 4:
        CHECK_ERROR(_readTargetIdentity_V1(c, &v->identity))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readCondition_V1(parser_context_t* c, pd_Condition_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readConditionType_V1(c, &v->conditionType))
    CHECK_ERROR(_readVecTrustedIssuer_V1(c, &v->issuers))
    return parser_ok;
}

parser_error_t _readCounter_V1(parser_context_t* c, pd_Counter_V1_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readCountryCode_V1(parser_context_t* c, pd_CountryCode_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readDispatchableName_V1(parser_context_t* c, pd_DispatchableName_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentHash_V1(parser_context_t* c, pd_DocumentHash_V1_t* v)
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

parser_error_t _readDocumentId_V1(parser_context_t* c, pd_DocumentId_V1_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readDocumentName_V1(parser_context_t* c, pd_DocumentName_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentType_V1(parser_context_t* c, pd_DocumentType_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocumentUri_V1(parser_context_t* c, pd_DocumentUri_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readDocument_V1(parser_context_t* c, pd_Document_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readDocumentUri_V1(c, &v->uri))
    CHECK_ERROR(_readDocumentHash_V1(c, &v->content_hash))
    CHECK_ERROR(_readDocumentName_V1(c, &v->name))
    CHECK_ERROR(_readOptionDocumentType_V1(c, &v->doc_type))
    CHECK_ERROR(_readOptionMoment_V1(c, &v->filing_date))
    return parser_ok;
}

parser_error_t _readEcdsaSignature_V1(parser_context_t* c, pd_EcdsaSignature_V1_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readElectionScore_V1(parser_context_t* c, pd_ElectionScore_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readElectionSize_V1(parser_context_t* c, pd_ElectionSize_V1_t* v)
{
    CHECK_ERROR(_readCompactInt(c, &v->validators));
    CHECK_ERROR(_readCompactInt(c, &v->nominators));
    return parser_ok;
}

parser_error_t _readEraIndex_V1(parser_context_t* c, pd_EraIndex_V1_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readEthereumAddress_V1(parser_context_t* c, pd_EthereumAddress_V1_t* v) {
    GEN_DEF_READARRAY(20)
}

parser_error_t _readExtrinsicPermissions_V1(parser_context_t* c, pd_ExtrinsicPermissions_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readFundingRoundName_V1(parser_context_t* c, pd_FundingRoundName_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readFundraiserName_V1(parser_context_t* c, pd_FundraiserName_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readGrandpaEquivocationProof_V1(parser_context_t* c, pd_GrandpaEquivocationProof_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readIdentityId_V1(parser_context_t* c, pd_IdentityId_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readInvestorUid_V1(parser_context_t* c, pd_InvestorUid_V1_t* v) {
    GEN_DEF_READARRAY(16)
}

parser_error_t _readInvestorZKProofData_V1(parser_context_t* c, pd_InvestorZKProofData_V1_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readItnRewardStatus_V1(parser_context_t* c, pd_ItnRewardStatus_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyOwnerProof_V1(parser_context_t* c, pd_KeyOwnerProof_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readKeyValue_V1(parser_context_t* c, pd_KeyValue_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKey_V1(parser_context_t* c, pd_Key_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readKeys_V1(parser_context_t* c, pd_Keys_V1_t* v)
{
    GEN_DEF_READARRAY(4 * 32)
    return parser_ok;
}

parser_error_t _readLeg_V1(parser_context_t* c, pd_Leg_V1_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readPortfolioId_V1(c, &v->from))
    CHECK_ERROR(_readPortfolioId_V1(c, &v->to))
    CHECK_ERROR(_readTicker_V1(c, &v->asset))
    CHECK_ERROR(_readBalance(c, &v->amount))

    return parser_ok;
}

parser_error_t _readLegacyPalletPermissions_V1(parser_context_t* c, pd_LegacyPalletPermissions_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readPalletName_V1(c, &v->palletName))
    CHECK_ERROR(_readBool(c, &v->total))
    CHECK_ERROR(_readVecDispatchableName_V1(c, &v->dispatchableNames))

    return parser_ok;
}

parser_error_t _readLegacyPermissions_V1(parser_context_t* c, pd_LegacyPermissions_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionVecTicker_V1(c, &v->asset))
    CHECK_ERROR(_readOptionVecLegacyPalletPermissions_V1(c, &v->extrinsic))
    CHECK_ERROR(_readOptionVecPortfolioId_V1(c, &v->portfolio))
    return parser_ok;
}

parser_error_t _readLocalCAId_V1(parser_context_t* c, pd_LocalCAId_V1_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readLookupSource_V1(parser_context_t* c, pd_LookupSource_V1_t* v)
{
    uint8_t len;
    CHECK_ERROR(_readUInt8(c, &len))
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readMaybeBlock_V1(parser_context_t* c, pd_MaybeBlock_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
        break;
    case 1:
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMemberCount_V1(parser_context_t* c, pd_MemberCount_V1_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readMemo_V1(parser_context_t* c, pd_Memo_V1_t* v)
{
    v->_len = 32;
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readMoment_V1(parser_context_t* c, pd_Moment_V1_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readMotionInfoLink_V1(parser_context_t* c, pd_MotionInfoLink_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotionTitle_V1(parser_context_t* c, pd_MotionTitle_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readMotion_V1(parser_context_t* c, pd_Motion_V1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMotionTitle_V1(c, &v->title))
    CHECK_ERROR(_readMotionInfoLink_V1(c, &v->info_link))
    CHECK_ERROR(_readVecChoiceTitle_V1(c, &v->choices))
    return parser_ok;
}

parser_error_t _readMovePortfolioItem_V1(parser_context_t* c, pd_MovePortfolioItem_V1_t* v)
{
    CHECK_ERROR(_readTicker_V1(c, &v->ticker));
    CHECK_ERROR(_readBalance(c, &v->balance));
    CHECK_ERROR(_readOptionMemo_V1(c, &v->memo));
    return parser_ok;
}

parser_error_t _readOffChainSignature_V1(parser_context_t* c, pd_OffChainSignature_V1_t* v)
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

parser_error_t _readPalletName_V1(parser_context_t* c, pd_PalletName_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPalletPermissions_V1(parser_context_t* c, pd_PalletPermissions_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readPalletName_V1(c, &v->palletName))
    CHECK_ERROR(_readOptionVecDispatchableName_V1(c, &v->dispatchableNames))

    return parser_ok;
}

parser_error_t _readPerbill_V1(parser_context_t* c, pd_Perbill_V1_t* v)
{
    return _readUInt32(c, &v->value);
}

parser_error_t _readPercent_V1(parser_context_t* c, pd_Percent_V1_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readPercentage_V1(parser_context_t* c, pd_Percentage_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPermill_V1(c, &v->value))
    return parser_ok;
}

parser_error_t _readPeriod_V1(parser_context_t* c, pd_Period_V1_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPermill_V1(parser_context_t* c, pd_Permill_V1_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPermissions_V1(parser_context_t* c, pd_Permissions_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionVecTicker_V1(c, &v->asset))
    CHECK_ERROR(_readOptionVecPalletPermissions_V1(c, &v->extrinsic))
    CHECK_ERROR(_readOptionVecPortfolioId_V1(c, &v->portfolio))
    return parser_ok;
}

parser_error_t _readPipDescription_V1(parser_context_t* c, pd_PipDescription_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPipId_V1(parser_context_t* c, pd_PipId_V1_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPortfolioId_V1(parser_context_t* c, pd_PortfolioId_V1_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId_V1(c, &v->did))
    CHECK_ERROR(_readPortfolioKind_V1(c, &v->kind))

    return parser_ok;
}

parser_error_t _readPortfolioKind_V1(parser_context_t* c, pd_PortfolioKind_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT();
        CHECK_ERROR(_readPortfolioNumber_V1(c, &v->number))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readPortfolioName_V1(parser_context_t* c, pd_PortfolioName_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readPortfolioNumber_V1(parser_context_t* c, pd_PortfolioNumber_V1_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readPosRatio_V1(parser_context_t* c, pd_PosRatio_V1_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->numerator))
    CHECK_ERROR(_readUInt32(c, &v->denominator))
    return parser_ok;
}

parser_error_t _readPriceTier_V1(parser_context_t* c, pd_PriceTier_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readBalance(c, &v->total))
    CHECK_ERROR(_readBalance(c, &v->price))
    return parser_ok;
}

parser_error_t _readPriority_V1(parser_context_t* c, pd_Priority_V1_t* v)
{
    CHECK_ERROR(_readu32(c, &v->stream_id))
    CHECK_ERROR(_readStreamDependency_V1(c, &v->dependency))
    return parser_ok;
}

parser_error_t _readProposalIndex_V1(parser_context_t* c, pd_ProposalIndex_V1_t* v)
{
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readProtocolOp_V1(parser_context_t* c, pd_ProtocolOp_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 16) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readReceiptDetails_V1(parser_context_t* c, pd_ReceiptDetails_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->receipt_uid))
    CHECK_ERROR(_readUInt64(c, &v->leg_id))
    CHECK_ERROR(_readAccountId_V1(c, &v->signer))
    CHECK_ERROR(_readOffChainSignature_V1(c, &v->signature))
    CHECK_ERROR(_readReceiptMetadata_V1(c, &v->metadata))
    return parser_ok;
}

parser_error_t _readReceiptMetadata_V1(parser_context_t* c, pd_ReceiptMetadata_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readRecordDateSpec_V1(parser_context_t* c, pd_RecordDateSpec_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_readMoment_V1(c, &v->scheduled))
        break;
    case 1: // ExistingSchedule
        CHECK_ERROR(_readScheduleId_V1(c, &v->existingSchedule))
        break;
    case 2: // Existing
        CHECK_ERROR(_readCheckpointId_V1(c, &v->existing))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readRewardDestination_V1(parser_context_t* c, pd_RewardDestination_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 2) {
        return parser_value_out_of_range;
    }

    return parser_ok;
}

parser_error_t _readScheduleId_V1(parser_context_t* c, pd_ScheduleId_V1_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readScheduleSpec_V1(parser_context_t* c, pd_ScheduleSpec_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readOptionMoment_V1(c, &v->start))
    CHECK_ERROR(_readCalendarPeriod_V1(c, &v->period))
    CHECK_ERROR(_readUInt32(c, &v->remaining))
    return parser_ok;
}

parser_error_t _readScopeClaimProof_V1(parser_context_t* c, pd_ScopeClaimProof_V1_t* v)
{
    return parser_not_supported;
}

parser_error_t _readScopeId_V1(parser_context_t* c, pd_ScopeId_V1_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readScope_V1(parser_context_t* c, pd_Scope_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readIdentityId_V1(c, &v->identity))
        break;
    case 1:
        CHECK_ERROR(_readTicker_V1(c, &v->ticker))
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

parser_error_t _readSecondaryKeyWithAuth_V1(parser_context_t* c, pd_SecondaryKeyWithAuth_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSecondaryKey_V1(c, &v->secondary_key))
    CHECK_ERROR(_readSignature_V1(c, &v->auth_signature))
    return parser_ok;
}

parser_error_t _readSecondaryKey_V1(parser_context_t* c, pd_SecondaryKey_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readSignatory_V1(c, &v->signer))
    CHECK_ERROR(_readPermissions_V1(c, &v->permissions))
    return parser_ok;
}

parser_error_t _readSettlementType_V1(parser_context_t* c, pd_SettlementType_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignatory_V1(parser_context_t* c, pd_Signatory_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readIdentityId_V1(c, &v->identity))
        break;
    case 1:
        CHECK_ERROR(_readAccountId_V1(c, &v->account))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignature_V1(parser_context_t* c, pd_Signature_V1_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSkippedCount_V1(parser_context_t* c, pd_SkippedCount_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readSlashingSwitch_V1(parser_context_t* c, pd_SlashingSwitch_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readSnapshotResult_V1(parser_context_t* c, pd_SnapshotResult_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readStreamDependency_V1(parser_context_t* c, pd_StreamDependency_V1_t* v)
{
    CHECK_ERROR(_readu32(c, &v->dependency_id))
    CHECK_ERROR(_readUInt8(c, &v->weight))
    CHECK_ERROR(_readbool(c, &v->is_exclusive))
    return parser_ok;
}

parser_error_t _readTargetIdentities_V1(parser_context_t* c, pd_TargetIdentities_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readVecIdentityId_V1(c, &v->identities))
    CHECK_ERROR(_readTargetTreatment_V1(c, &v->treatment))
    return parser_ok;
}

parser_error_t _readTargetIdentity_V1(parser_context_t* c, pd_TargetIdentity_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_ERROR(_readIdentityId_V1(c, &v->specific))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTargetTreatment_V1(parser_context_t* c, pd_TargetTreatment_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTax_V1(parser_context_t* c, pd_Tax_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPermill_V1(c, &v->value))
    return parser_ok;
}

parser_error_t _readTickerRegistrationConfig_V1(parser_context_t* c, pd_TickerRegistrationConfig_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->max_ticker_length))
    CHECK_ERROR(_readOptionMoment_V1(c, &v->registration_length))
    return parser_ok;
}

parser_error_t _readTicker_V1(parser_context_t* c, pd_Ticker_V1_t* v)
{
    v->_len = 12;
    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readTransferManager_V1(parser_context_t* c, pd_TransferManager_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // CountTransferManager
        CHECK_ERROR(_readCounter_V1(c, &v->countTransferManager))
        break;
    case 1: // PercentageTransferManager
        CHECK_ERROR(_readPercentage_V1(c, &v->percentageTransferManager))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedFor_V1(parser_context_t* c, pd_TrustedFor_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_ERROR(_readVecClaimType_V1(c, &v->claims))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedIssuer_V1(parser_context_t* c, pd_TrustedIssuer_V1_t* v)
{
    CHECK_INPUT();

    CHECK_ERROR(_readIdentityId_V1(c, &v->issuer))
    CHECK_ERROR(_readTrustedFor_V1(c, &v->trustedFor))
    return parser_ok;
}

parser_error_t _readTupleCountryCodeScope_V1(parser_context_t* c, pd_TupleCountryCodeScope_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCountryCode_V1(c, &v->country_code))
    CHECK_ERROR(_readScope_V1(c, &v->scope))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdTax_V1(parser_context_t* c, pd_TupleIdentityIdTax_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readIdentityId_V1(c, &v->id))
    CHECK_ERROR(_readTax_V1(c, &v->tax))
    return parser_ok;
}

parser_error_t _readTupleIdentityIdbool_V1(parser_context_t* c, pd_TupleIdentityIdbool_V1_t* v)
{
    CHECK_ERROR(_readIdentityId_V1(c, &v->identity))
    CHECK_ERROR(_readBool(c, &v->val))
    return parser_ok;
}

parser_error_t _readTuplePipIdSnapshotResult_V1(parser_context_t* c, pd_TuplePipIdSnapshotResult_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readPipId_V1(c, &v->pip_id))
    CHECK_ERROR(_readSnapshotResult_V1(c, &v->snapshot_result))
    return parser_ok;
}

parser_error_t _readTupleScopeScopeIdCddId_V1(parser_context_t* c, pd_TupleScopeScopeIdCddId_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readScope_V1(c, &v->scope))
    CHECK_ERROR(_readScopeId_V1(c, &v->scopeId))
    CHECK_ERROR(_readCddId_V1(c, &v->cddId))
    return parser_ok;
}

parser_error_t _readUniqueCall_V1(parser_context_t* c, pd_UniqueCall_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt64(c, &v->nonce))
    CHECK_ERROR(_readCall(c, &v->call))
    return parser_ok;
}

parser_error_t _readUrl_V1(parser_context_t* c, pd_Url_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readValidatorIndex_V1(parser_context_t* c, pd_ValidatorIndex_V1_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt16(c, &v->value))
    return parser_ok;
}

parser_error_t _readValidatorPrefs_V1(parser_context_t* c, pd_ValidatorPrefs_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readCompactPerBill_V1(c, &v->commission));
    CHECK_ERROR(_readBool(c, &v->blocked));
    return parser_ok;
}

parser_error_t _readVenueDetails_V1(parser_context_t* c, pd_VenueDetails_V1_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readVenueType_V1(parser_context_t* c, pd_VenueType_V1_t* v)
{
    CHECK_INPUT();
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 3) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readWeight_V1(parser_context_t* c, pd_Weight_V1_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readVecAccountId_V1(parser_context_t* c, pd_VecAccountId_V1_t* v) {
    GEN_DEF_READVECTOR(AccountId_V1)
}

parser_error_t _readVecAssetIdentifier_V1(parser_context_t* c, pd_VecAssetIdentifier_V1_t* v) {
    GEN_DEF_READVECTOR(AssetIdentifier_V1)
}

parser_error_t _readVecBallotVote_V1(parser_context_t* c, pd_VecBallotVote_V1_t* v) {
    GEN_DEF_READVECTOR(BallotVote_V1)
}

parser_error_t _readVecBeneficiary_V1(parser_context_t* c, pd_VecBeneficiary_V1_t* v) {
    GEN_DEF_READVECTOR(Beneficiary_V1)
}

parser_error_t _readVecBridgeTx_V1(parser_context_t* c, pd_VecBridgeTx_V1_t* v) {
    GEN_DEF_READVECTOR(BridgeTx_V1)
}

parser_error_t _readVecChoiceTitle_V1(parser_context_t* c, pd_VecChoiceTitle_V1_t* v) {
    GEN_DEF_READVECTOR(ChoiceTitle_V1)
}

parser_error_t _readVecClaimType_V1(parser_context_t* c, pd_VecClaimType_V1_t* v) {
    GEN_DEF_READVECTOR(ClaimType_V1)
}

parser_error_t _readVecClaim_V1(parser_context_t* c, pd_VecClaim_V1_t* v) {
    GEN_DEF_READVECTOR(Claim_V1)
}

parser_error_t _readVecComplianceRequirement_V1(parser_context_t* c, pd_VecComplianceRequirement_V1_t* v) {
    GEN_DEF_READVECTOR(ComplianceRequirement_V1)
}

parser_error_t _readVecCondition_V1(parser_context_t* c, pd_VecCondition_V1_t* v) {
    GEN_DEF_READVECTOR(Condition_V1)
}

parser_error_t _readVecDispatchableName_V1(parser_context_t* c, pd_VecDispatchableName_V1_t* v) {
    GEN_DEF_READVECTOR(DispatchableName_V1)
}

parser_error_t _readVecDocumentId_V1(parser_context_t* c, pd_VecDocumentId_V1_t* v) {
    GEN_DEF_READVECTOR(DocumentId_V1)
}

parser_error_t _readVecDocument_V1(parser_context_t* c, pd_VecDocument_V1_t* v) {
    GEN_DEF_READVECTOR(Document_V1)
}

parser_error_t _readVecIdentityId_V1(parser_context_t* c, pd_VecIdentityId_V1_t* v) {
    GEN_DEF_READVECTOR(IdentityId_V1)
}

parser_error_t _readVecKeyValue_V1(parser_context_t* c, pd_VecKeyValue_V1_t* v) {
    GEN_DEF_READVECTOR(KeyValue_V1)
}

parser_error_t _readVecKey_V1(parser_context_t* c, pd_VecKey_V1_t* v) {
    GEN_DEF_READVECTOR(Key_V1)
}

parser_error_t _readVecLeg_V1(parser_context_t* c, pd_VecLeg_V1_t* v) {
    GEN_DEF_READVECTOR(Leg_V1)
}

parser_error_t _readVecLegacyPalletPermissions_V1(parser_context_t* c, pd_VecLegacyPalletPermissions_V1_t* v) {
    GEN_DEF_READVECTOR(LegacyPalletPermissions_V1)
}

parser_error_t _readVecLookupSource_V1(parser_context_t* c, pd_VecLookupSource_V1_t* v) {
    GEN_DEF_READVECTOR(LookupSource_V1)
}

parser_error_t _readVecMotion_V1(parser_context_t* c, pd_VecMotion_V1_t* v) {
    GEN_DEF_READVECTOR(Motion_V1)
}

parser_error_t _readVecMovePortfolioItem_V1(parser_context_t* c, pd_VecMovePortfolioItem_V1_t* v) {
    GEN_DEF_READVECTOR(MovePortfolioItem_V1)
}

parser_error_t _readVecPalletPermissions_V1(parser_context_t* c, pd_VecPalletPermissions_V1_t* v) {
    GEN_DEF_READVECTOR(PalletPermissions_V1)
}

parser_error_t _readVecPortfolioId_V1(parser_context_t* c, pd_VecPortfolioId_V1_t* v) {
    GEN_DEF_READVECTOR(PortfolioId_V1)
}

parser_error_t _readVecPriceTier_V1(parser_context_t* c, pd_VecPriceTier_V1_t* v) {
    GEN_DEF_READVECTOR(PriceTier_V1)
}

parser_error_t _readVecReceiptDetails_V1(parser_context_t* c, pd_VecReceiptDetails_V1_t* v) {
    GEN_DEF_READVECTOR(ReceiptDetails_V1)
}

parser_error_t _readVecScopeId_V1(parser_context_t* c, pd_VecScopeId_V1_t* v) {
    GEN_DEF_READVECTOR(ScopeId_V1)
}

parser_error_t _readVecSecondaryKeyWithAuth_V1(parser_context_t* c, pd_VecSecondaryKeyWithAuth_V1_t* v) {
    GEN_DEF_READVECTOR(SecondaryKeyWithAuth_V1)
}

parser_error_t _readVecSecondaryKey_V1(parser_context_t* c, pd_VecSecondaryKey_V1_t* v) {
    GEN_DEF_READVECTOR(SecondaryKey_V1)
}

parser_error_t _readVecSignatory_V1(parser_context_t* c, pd_VecSignatory_V1_t* v) {
    GEN_DEF_READVECTOR(Signatory_V1)
}

parser_error_t _readVecTicker_V1(parser_context_t* c, pd_VecTicker_V1_t* v) {
    GEN_DEF_READVECTOR(Ticker_V1)
}

parser_error_t _readVecTrustedIssuer_V1(parser_context_t* c, pd_VecTrustedIssuer_V1_t* v) {
    GEN_DEF_READVECTOR(TrustedIssuer_V1)
}

parser_error_t _readVecTupleIdentityIdTax_V1(parser_context_t* c, pd_VecTupleIdentityIdTax_V1_t* v) {
    GEN_DEF_READVECTOR(TupleIdentityIdTax_V1)
}

parser_error_t _readVecTupleIdentityIdbool_V1(parser_context_t* c, pd_VecTupleIdentityIdbool_V1_t* v) {
    GEN_DEF_READVECTOR(TupleIdentityIdbool_V1)
}

parser_error_t _readVecTuplePipIdSnapshotResult_V1(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_V1_t* v) {
    GEN_DEF_READVECTOR(TuplePipIdSnapshotResult_V1)
}

parser_error_t _readVecValidatorIndex_V1(parser_context_t* c, pd_VecValidatorIndex_V1_t* v) {
    GEN_DEF_READVECTOR(ValidatorIndex_V1)
}

parser_error_t _readOptionChangesTrieConfiguration_V1(parser_context_t* c, pd_OptionChangesTrieConfiguration_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readChangesTrieConfiguration_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionDocumentType_V1(parser_context_t* c, pd_OptionDocumentType_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readDocumentType_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionFundingRoundName_V1(parser_context_t* c, pd_OptionFundingRoundName_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readFundingRoundName_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMemo_V1(parser_context_t* c, pd_OptionMemo_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMemo_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMoment_V1(parser_context_t* c, pd_OptionMoment_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMoment_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPeriod_V1(parser_context_t* c, pd_OptionPeriod_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPeriod_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPipDescription_V1(parser_context_t* c, pd_OptionPipDescription_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPipDescription_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPortfolioNumber_V1(parser_context_t* c, pd_OptionPortfolioNumber_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPortfolioNumber_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReceiptDetails_V1(parser_context_t* c, pd_OptionReceiptDetails_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReceiptDetails_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionRecordDateSpec_V1(parser_context_t* c, pd_OptionRecordDateSpec_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRecordDateSpec_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionScope_V1(parser_context_t* c, pd_OptionScope_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readScope_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTargetIdentities_V1(parser_context_t* c, pd_OptionTargetIdentities_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTargetIdentities_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTax_V1(parser_context_t* c, pd_OptionTax_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTax_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionUrl_V1(parser_context_t* c, pd_OptionUrl_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readUrl_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecDispatchableName_V1(parser_context_t* c, pd_OptionVecDispatchableName_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecDispatchableName_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecLegacyPalletPermissions_V1(parser_context_t* c, pd_OptionVecLegacyPalletPermissions_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecLegacyPalletPermissions_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPalletPermissions_V1(parser_context_t* c, pd_OptionVecPalletPermissions_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPalletPermissions_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecPortfolioId_V1(parser_context_t* c, pd_OptionVecPortfolioId_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecPortfolioId_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTicker_V1(parser_context_t* c, pd_OptionVecTicker_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTicker_V1(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTupleIdentityIdTax_V1(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_V1_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTupleIdentityIdTax_V1(c, &v->contained))
    }
    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactAssignments_V1(
    const pd_CompactAssignments_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactEraIndex_V1(
    const pd_CompactEraIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactMoment_V1(
    const pd_CompactMoment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAGId_V1(
    const pd_AGId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAccountId_V1(
    const pd_AccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAccountIndex_V1(
    const pd_AccountIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAgentGroup_V1(
    const pd_AgentGroup_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringAssetIdentifier_V1(
    const pd_AssetIdentifier_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringAssetName_V1(
    const pd_AssetName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringAssetType_V1(
    const pd_AssetType_V1_t* v,
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
        memset(bufferUI, 0, sizeof(bufferUI));
        memcpy(bufferUI, v->_ptr, v->_len);
        memset(outValue, 0, outValueLen);

        asciify(bufferUI);
        pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
        break;
    }
    }

    return parser_ok;
}

parser_error_t _toStringAuthorizationData_V1(
    const pd_AuthorizationData_V1_t* v,
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
        CHECK_ERROR(_toStringIdentityId_V1(&v->identityId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("AttestPrimaryKeyRotation")
        CHECK_ERROR(_toStringIdentityId_V1(&v->identityId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 1: // RotatePrimaryKey
        CHECK_ERROR(_toStringIdentityId_V1(&v->identityId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("RotatePrimaryKey")
        CHECK_ERROR(_toStringIdentityId_V1(&v->identityId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 2: // TransferTicker
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferTicker")
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 3: // TransferPrimaryIssuanceAgent
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferPrimaryIssuanceAgent")
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 5: // TransferAssetOwnership
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferAssetOwnership")
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 8: // Custom
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("Custom")
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 10: // TransferCorporateActionAgent
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferCorporateActionAgent")
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 4: // AddMultiSigSigner
        CHECK_ERROR(_toStringAccountId_V1(&v->accountId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("AddMultiSigSigner")
        CHECK_ERROR(_toStringAccountId_V1(&v->accountId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 6: // JoinIdentity
        CHECK_ERROR(_toStringPermissions_V1(&v->permissions, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("JoinIdentity")
        CHECK_ERROR(_toStringPermissions_V1(&v->permissions, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 7: // PortfolioCustody
        CHECK_ERROR(_toStringPortfolioId_V1(&v->portfolioId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("PortfolioCustody")
        CHECK_ERROR(_toStringPortfolioId_V1(&v->portfolioId, outValue, outValueLen, pageIdx, &_dummy);)
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

parser_error_t _toStringBabeEquivocationProof_V1(
    const pd_BabeEquivocationProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringBallotMeta_V1(
    const pd_BallotMeta_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringBallotTitle_V1(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecMotion_V1(&v->motions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBallotTitle_V1(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecMotion_V1(&v->motions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTimeRange_V1(
    const pd_BallotTimeRange_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringMoment_V1(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMoment_V1(&v->end, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMoment_V1(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMoment_V1(&v->end, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBallotTitle_V1(
    const pd_BallotTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringBallotVote_V1(
    const pd_BallotVote_V1_t* v,
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

parser_error_t _toStringBeneficiary_V1(
    const pd_Beneficiary_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V1(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V1(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringBridgeTx_V1(
    const pd_BridgeTx_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringu32(&v->nonce, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAccountId_V1(&v->recipient, outValue, outValueLen, 0, &pages[1]))
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
        CHECK_ERROR(_toStringAccountId_V1(&v->recipient, outValue, outValueLen, pageIdx, &pages[1]))
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

parser_error_t _toStringCADetails_V1(
    const pd_CADetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringCAId_V1(
    const pd_CAId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringLocalCAId_V1(&v->local_id, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringLocalCAId_V1(&v->local_id, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCAKind_V1(
    const pd_CAKind_V1_t* v,
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

parser_error_t _toStringCalendarPeriod_V1(
    const pd_CalendarPeriod_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCalendarUnit_V1(&v->unit, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->amount, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCalendarUnit_V1(&v->unit, outValue, outValueLen, pageIdx, &pages[0]))
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

parser_error_t _toStringCalendarUnit_V1(
    const pd_CalendarUnit_V1_t* v,
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

parser_error_t _toStringCddId_V1(
    const pd_CddId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringChangesTrieConfiguration_V1(
    const pd_ChangesTrieConfiguration_V1_t* v,
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

parser_error_t _toStringCheckpointId_V1(
    const pd_CheckpointId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringChoiceTitle_V1(
    const pd_ChoiceTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringClaimType_V1(
    const pd_ClaimType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
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

parser_error_t _toStringClaim_V1(
    const pd_Claim_V1_t* v,
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
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Accredited");
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 1: // Affiliate
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Affiliate");
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 2: // BuyLockup
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("BuyLockup");
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 3: // SellLockup
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("SellLockup");
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 5: // KnowYourCustomer
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("KnowYourCustomer");
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 7: // Exempted
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Exempted");
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 8: // Blocked
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Blocked");
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_toStringCddId_V1(&v->cddId, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("CustomerDueDiligence");
        CHECK_ERROR(_toStringCddId_V1(&v->cddId, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_toStringTupleCountryCodeScope_V1(&v->jurisdiction, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Jurisdiction");
        CHECK_ERROR(_toStringTupleCountryCodeScope_V1(&v->jurisdiction, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 9: // InvestorUniqueness
        CHECK_ERROR(_toStringTupleScopeScopeIdCddId_V1(&v->investorUniqueness, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("InvestorUniqueness");
        CHECK_ERROR(_toStringTupleScopeScopeIdCddId_V1(&v->investorUniqueness, outValue, outValueLen, pageIdx, &_dummy));
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

parser_error_t _toStringClassicTickerImport_V1(
    const pd_ClassicTickerImport_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringEthereumAddress_V1(&v->eth_owner, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->is_contract, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringbool(&v->is_created, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringEthereumAddress_V1(&v->eth_owner, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &pages[1]))
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

parser_error_t _toStringCompactPerBill_V1(
    const pd_CompactPerBill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringComplianceRequirement_V1(
    const pd_ComplianceRequirement_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{

    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringVecCondition_V1(&v->senderConditions, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecCondition_V1(&v->receiverConditions, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecCondition_V1(&v->senderConditions, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecCondition_V1(&v->receiverConditions, outValue, outValueLen, pageIdx, &pages[1]))
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

parser_error_t _toStringConditionType_V1(
    const pd_ConditionType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    switch (v->value) {
    case 0: // IsPresent
    case 1: // IsAbsent
        CHECK_ERROR(_toStringClaim_V1(&v->claim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // IsAnyOf
    case 3: // IsNoneOf
        CHECK_ERROR(_toStringVecClaim_V1(&v->vecClaim, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // IsIdentity
        CHECK_ERROR(_toStringTargetIdentity_V1(&v->identity, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringCondition_V1(
    const pd_Condition_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringConditionType_V1(&v->conditionType, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecTrustedIssuer_V1(&v->issuers, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringConditionType_V1(&v->conditionType, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecTrustedIssuer_V1(&v->issuers, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCounter_V1(
    const pd_Counter_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCountryCode_V1(
    const pd_CountryCode_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->value > COUNTRY_CODES_SIZE - 1) {
        return parser_value_out_of_range;
    }
    snprintf(outValue, outValueLen, "%s", STR_COUNTRY_CODES[v->value]);
    *pageCount = 1;
    return parser_ok;
}

parser_error_t _toStringDispatchableName_V1(
    const pd_DispatchableName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocumentHash_V1(
    const pd_DocumentHash_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(v->_len)
}

parser_error_t _toStringDocumentId_V1(
    const pd_DocumentId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDocumentName_V1(
    const pd_DocumentName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocumentType_V1(
    const pd_DocumentType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocumentUri_V1(
    const pd_DocumentUri_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringDocument_V1(
    const pd_Document_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[5];
    CHECK_ERROR(_toStringDocumentUri_V1(&v->uri, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringDocumentHash_V1(&v->content_hash, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringDocumentName_V1(&v->name, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionDocumentType_V1(&v->doc_type, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionMoment_V1(&v->filing_date, outValue, outValueLen, 0, &pages[4]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3] + pages[4];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringDocumentUri_V1(&v->uri, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringDocumentHash_V1(&v->content_hash, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringDocumentName_V1(&v->name, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionDocumentType_V1(&v->doc_type, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionMoment_V1(&v->filing_date, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEcdsaSignature_V1(
    const pd_EcdsaSignature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringElectionScore_V1(
    const pd_ElectionScore_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringElectionSize_V1(
    const pd_ElectionSize_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringCompactInt(&v->validators, COIN_AMOUNT_DECIMAL_PLACES, "", "", outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactInt(&v->nominators, COIN_AMOUNT_DECIMAL_PLACES, "", "", outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactInt(&v->validators, COIN_AMOUNT_DECIMAL_PLACES, "", "", outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactInt(&v->nominators, COIN_AMOUNT_DECIMAL_PLACES, "", "", outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringEraIndex_V1(
    const pd_EraIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringEthereumAddress_V1(
    const pd_EthereumAddress_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(20)
}

parser_error_t _toStringExtrinsicPermissions_V1(
    const pd_ExtrinsicPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringFundingRoundName_V1(
    const pd_FundingRoundName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringFundraiserName_V1(
    const pd_FundraiserName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringGrandpaEquivocationProof_V1(
    const pd_GrandpaEquivocationProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringIdentityId_V1(
    const pd_IdentityId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringInvestorUid_V1(
    const pd_InvestorUid_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(16)
}

parser_error_t _toStringInvestorZKProofData_V1(
    const pd_InvestorZKProofData_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringItnRewardStatus_V1(
    const pd_ItnRewardStatus_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyOwnerProof_V1(
    const pd_KeyOwnerProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringKeyValue_V1(
    const pd_KeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKey_V1(
    const pd_Key_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    return parser_print_not_supported;
}

parser_error_t _toStringKeys_V1(
    const pd_Keys_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
}

parser_error_t _toStringLeg_V1(
    const pd_Leg_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[4];
    CHECK_ERROR(_toStringPortfolioId_V1(&v->from, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioId_V1(&v->to, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTicker_V1(&v->asset, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringBalance(&v->amount, outValue, outValueLen, 0, &pages[3]))

    *pageCount = pages[0] + pages[1] + pages[2] + pages[3];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPortfolioId_V1(&v->from, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioId_V1(&v->to, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTicker_V1(&v->asset, outValue, outValueLen, pageIdx, &pages[2]))
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

parser_error_t _toStringLegacyPalletPermissions_V1(
    const pd_LegacyPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringPalletName_V1(&v->palletName, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->total, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecDispatchableName_V1(&v->dispatchableNames, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPalletName_V1(&v->palletName, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->total, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecDispatchableName_V1(&v->dispatchableNames, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringLegacyPermissions_V1(
    const pd_LegacyPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringOptionVecTicker_V1(&v->asset, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecLegacyPalletPermissions_V1(&v->extrinsic, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionVecPortfolioId_V1(&v->portfolio, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionVecTicker_V1(&v->asset, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecLegacyPalletPermissions_V1(&v->extrinsic, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionVecPortfolioId_V1(&v->portfolio, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringLocalCAId_V1(
    const pd_LocalCAId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringLookupSource_V1(
    const pd_LookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringPubkeyAsAddress(v->_ptr, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMaybeBlock_V1(
    const pd_MaybeBlock_V1_t* v,
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

parser_error_t _toStringMemberCount_V1(
    const pd_MemberCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMemo_V1(
    const pd_Memo_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    if (formatBufferData(v->_ptr, v->_len, outValue, outValueLen, pageIdx, pageCount) != zxerr_ok) {
        return parser_print_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringMoment_V1(
    const pd_Moment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringMotionInfoLink_V1(
    const pd_MotionInfoLink_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringMotionTitle_V1(
    const pd_MotionTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringMotion_V1(
    const pd_Motion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringMotionTitle_V1(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMotionInfoLink_V1(&v->info_link, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecChoiceTitle_V1(&v->choices, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMotionTitle_V1(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMotionInfoLink_V1(&v->info_link, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecChoiceTitle_V1(&v->choices, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMovePortfolioItem_V1(
    const pd_MovePortfolioItem_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionMemo_V1(&v->memo, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionMemo_V1(&v->memo, outValue, outValueLen, 0, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringOffChainSignature_V1(
    const pd_OffChainSignature_V1_t* v,
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

parser_error_t _toStringPalletName_V1(
    const pd_PalletName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringPalletPermissions_V1(
    const pd_PalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPalletName_V1(&v->palletName, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecDispatchableName_V1(&v->dispatchableNames, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPalletName_V1(&v->palletName, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecDispatchableName_V1(&v->dispatchableNames, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPerbill_V1(
    const pd_Perbill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 7) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPercent_V1(
    const pd_Percent_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPercentage_V1(
    const pd_Percentage_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringPermill_V1(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringPeriod_V1(
    const pd_Period_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPermill_V1(
    const pd_Permill_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100];
    char ratioBuffer[80];
    memset(outValue, 0, outValueLen);
    memset(ratioBuffer, 0, sizeof(ratioBuffer));
    memset(bufferUI, 0, sizeof(bufferUI));
    *pageCount = 1;

    if (fpuint64_to_str(ratioBuffer, sizeof(ratioBuffer), v->value, 4) == 0) {
        return parser_unexpected_value;
    }

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", ratioBuffer);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPermissions_V1(
    const pd_Permissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringOptionVecTicker_V1(&v->asset, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionVecPalletPermissions_V1(&v->extrinsic, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionVecPortfolioId_V1(&v->portfolio, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionVecTicker_V1(&v->asset, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionVecPalletPermissions_V1(&v->extrinsic, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionVecPortfolioId_V1(&v->portfolio, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPipDescription_V1(
    const pd_PipDescription_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringPipId_V1(
    const pd_PipId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPortfolioId_V1(
    const pd_PortfolioId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V1(&v->did, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioKind_V1(&v->kind, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V1(&v->did, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioKind_V1(&v->kind, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringPortfolioKind_V1(
    const pd_PortfolioKind_V1_t* v,
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
        _toStringPortfolioNumber_V1(&v->number, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringPortfolioName_V1(
    const pd_PortfolioName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringPortfolioNumber_V1(
    const pd_PortfolioNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPosRatio_V1(
    const pd_PosRatio_V1_t* v,
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

parser_error_t _toStringPriceTier_V1(
    const pd_PriceTier_V1_t* v,
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

parser_error_t _toStringPriority_V1(
    const pd_Priority_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringu32(&v->stream_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringStreamDependency_V1(&v->dependency, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringStreamDependency_V1(&v->dependency, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProposalIndex_V1(
    const pd_ProposalIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringProtocolOp_V1(
    const pd_ProtocolOp_V1_t* v,
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

parser_error_t _toStringReceiptDetails_V1(
    const pd_ReceiptDetails_V1_t* v,
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
    CHECK_ERROR(_toStringAccountId_V1(&v->signer, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOffChainSignature_V1(&v->signature, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringReceiptMetadata_V1(&v->metadata, outValue, outValueLen, 0, &pages[4]))

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
        CHECK_ERROR(_toStringAccountId_V1(&v->signer, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    pageIdx -= pages[2];

    //////
    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOffChainSignature_V1(&v->signature, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    pageIdx -= pages[3];

    //////
    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringReceiptMetadata_V1(&v->metadata, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringReceiptMetadata_V1(
    const pd_ReceiptMetadata_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringRecordDateSpec_V1(
    const pd_RecordDateSpec_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_toStringMoment_V1(&v->scheduled, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1: // ExistingSchedule
        CHECK_ERROR(_toStringScheduleId_V1(&v->existingSchedule, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 2: // Existing
        CHECK_ERROR(_toStringCheckpointId_V1(&v->existing, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringRewardDestination_V1(
    const pd_RewardDestination_V1_t* v,
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

parser_error_t _toStringScheduleId_V1(
    const pd_ScheduleId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringScheduleSpec_V1(
    const pd_ScheduleSpec_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringOptionMoment_V1(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCalendarPeriod_V1(&v->period, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->remaining, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMoment_V1(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCalendarPeriod_V1(&v->period, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];
    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->remaining, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringScopeClaimProof_V1(
    const pd_ScopeClaimProof_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return parser_print_not_supported;
}

parser_error_t _toStringScopeId_V1(
    const pd_ScopeId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringScope_V1(
    const pd_Scope_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId_V1(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringTicker_V1(&v->ticker, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 2:
        GEN_DEF_TOSTRING_ARRAY(v->_len)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSecondaryKeyWithAuth_V1(
    const pd_SecondaryKeyWithAuth_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSecondaryKey_V1(&v->secondary_key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSignature_V1(&v->auth_signature, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSecondaryKey_V1(&v->secondary_key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSignature_V1(&v->auth_signature, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSecondaryKey_V1(
    const pd_SecondaryKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringSignatory_V1(&v->signer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPermissions_V1(&v->permissions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSignatory_V1(&v->signer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPermissions_V1(&v->permissions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSettlementType_V1(
    const pd_SettlementType_V1_t* v,
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

parser_error_t _toStringSignatory_V1(
    const pd_Signatory_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0:
        _toStringIdentityId_V1(&v->identity, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 1:
        _toStringAccountId_V1(&v->account, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSignature_V1(
    const pd_Signature_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSkippedCount_V1(
    const pd_SkippedCount_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    uint16_t valu16 = (uint16_t)v->value;
    return _toStringu16(&valu16, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringSlashingSwitch_V1(
    const pd_SlashingSwitch_V1_t* v,
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

parser_error_t _toStringSnapshotResult_V1(
    const pd_SnapshotResult_V1_t* v,
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

parser_error_t _toStringStreamDependency_V1(
    const pd_StreamDependency_V1_t* v,
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

parser_error_t _toStringTargetIdentities_V1(
    const pd_TargetIdentities_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringVecIdentityId_V1(&v->identities, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTargetTreatment_V1(&v->treatment, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecIdentityId_V1(&v->identities, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTargetTreatment_V1(&v->treatment, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetIdentity_V1(
    const pd_TargetIdentity_V1_t* v,
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
        _toStringIdentityId_V1(&v->specific, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTargetTreatment_V1(
    const pd_TargetTreatment_V1_t* v,
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

parser_error_t _toStringTax_V1(
    const pd_Tax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringPermill_V1(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringTickerRegistrationConfig_V1(
    const pd_TickerRegistrationConfig_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringu16((const pd_u16_t*)&v->max_ticker_length, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionMoment_V1(&v->registration_length, outValue, outValueLen, 0, &pages[1]))

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
        CHECK_ERROR(_toStringOptionMoment_V1(&v->registration_length, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTicker_V1(
    const pd_Ticker_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringTransferManager_V1(
    const pd_TransferManager_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // CountTransferManager
        CHECK_ERROR(_toStringCounter_V1(&v->countTransferManager, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 1: // PercentageTransferManager
        CHECK_ERROR(_toStringPercentage_V1(&v->percentageTransferManager, outValue, outValueLen, pageIdx, pageCount));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTrustedFor_V1(
    const pd_TrustedFor_V1_t* v,
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
        _toStringVecClaimType_V1(&v->claims, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringTrustedIssuer_V1(
    const pd_TrustedIssuer_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V1(&v->issuer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTrustedFor_V1(&v->trustedFor, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V1(&v->issuer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTrustedFor_V1(&v->trustedFor, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleCountryCodeScope_V1(
    const pd_TupleCountryCodeScope_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringCountryCode_V1(&v->country_code, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCountryCode_V1(&v->country_code, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdTax_V1(
    const pd_TupleIdentityIdTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V1(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTax_V1(&v->tax, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V1(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTax_V1(&v->tax, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleIdentityIdbool_V1(
    const pd_TupleIdentityIdbool_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // Get all pages first
    uint8_t pages[2];
    CHECK_ERROR(_toStringIdentityId_V1(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId_V1(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringbool(&v->val, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTuplePipIdSnapshotResult_V1(
    const pd_TuplePipIdSnapshotResult_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringPipId_V1(&v->pip_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSnapshotResult_V1(&v->snapshot_result, outValue, outValueLen, 0, &pages[1]))

    *pageCount = pages[0] + pages[1];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPipId_V1(&v->pip_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSnapshotResult_V1(&v->snapshot_result, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleScopeScopeIdCddId_V1(
    const pd_TupleScopeScopeIdCddId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // Index + count pages
    uint8_t pages[3];
    CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScopeId_V1(&v->scopeId, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCddId_V1(&v->cddId, outValue, outValueLen, 0, &pages[2]))

    *pageCount = pages[0] + pages[1] + pages[2];
    if (pageIdx > *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringScope_V1(&v->scope, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    //////
    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScopeId_V1(&v->scopeId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    pageIdx -= pages[1];

    //////
    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCddId_V1(&v->cddId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUniqueCall_V1(
    const pd_UniqueCall_V1_t* v,
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

parser_error_t _toStringUrl_V1(
    const pd_Url_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringValidatorIndex_V1(
    const pd_ValidatorIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu16(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringValidatorPrefs_V1(
    const pd_ValidatorPrefs_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return _toStringCompactPerBill_V1(&v->commission, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVenueDetails_V1(
    const pd_VenueDetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[v->_len + 1];
    memset(bufferUI, 0, sizeof(bufferUI));
    memcpy(bufferUI, v->_ptr, v->_len);
    memset(outValue, 0, outValueLen);

    asciify(bufferUI);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);

    return parser_ok;
}

parser_error_t _toStringVenueType_V1(
    const pd_VenueType_V1_t* v,
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

parser_error_t _toStringWeight_V1(
    const pd_Weight_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecAccountId_V1(
    const pd_VecAccountId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountId_V1);
}

parser_error_t _toStringVecAssetIdentifier_V1(
    const pd_VecAssetIdentifier_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdentifier_V1);
}

parser_error_t _toStringVecBallotVote_V1(
    const pd_VecBallotVote_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BallotVote_V1);
}

parser_error_t _toStringVecBeneficiary_V1(
    const pd_VecBeneficiary_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Beneficiary_V1);
}

parser_error_t _toStringVecBridgeTx_V1(
    const pd_VecBridgeTx_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(BridgeTx_V1);
}

parser_error_t _toStringVecChoiceTitle_V1(
    const pd_VecChoiceTitle_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ChoiceTitle_V1);
}

parser_error_t _toStringVecClaimType_V1(
    const pd_VecClaimType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ClaimType_V1);
}

parser_error_t _toStringVecClaim_V1(
    const pd_VecClaim_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Claim_V1);
}

parser_error_t _toStringVecComplianceRequirement_V1(
    const pd_VecComplianceRequirement_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ComplianceRequirement_V1);
}

parser_error_t _toStringVecCondition_V1(
    const pd_VecCondition_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Condition_V1);
}

parser_error_t _toStringVecDispatchableName_V1(
    const pd_VecDispatchableName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DispatchableName_V1);
}

parser_error_t _toStringVecDocumentId_V1(
    const pd_VecDocumentId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(DocumentId_V1);
}

parser_error_t _toStringVecDocument_V1(
    const pd_VecDocument_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Document_V1);
}

parser_error_t _toStringVecIdentityId_V1(
    const pd_VecIdentityId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(IdentityId_V1);
}

parser_error_t _toStringVecKeyValue_V1(
    const pd_VecKeyValue_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(KeyValue_V1);
}

parser_error_t _toStringVecKey_V1(
    const pd_VecKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Key_V1);
}

parser_error_t _toStringVecLeg_V1(
    const pd_VecLeg_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Leg_V1);
}

parser_error_t _toStringVecLegacyPalletPermissions_V1(
    const pd_VecLegacyPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LegacyPalletPermissions_V1);
}

parser_error_t _toStringVecLookupSource_V1(
    const pd_VecLookupSource_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(LookupSource_V1);
}

parser_error_t _toStringVecMotion_V1(
    const pd_VecMotion_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Motion_V1);
}

parser_error_t _toStringVecMovePortfolioItem_V1(
    const pd_VecMovePortfolioItem_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(MovePortfolioItem_V1);
}

parser_error_t _toStringVecPalletPermissions_V1(
    const pd_VecPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PalletPermissions_V1);
}

parser_error_t _toStringVecPortfolioId_V1(
    const pd_VecPortfolioId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PortfolioId_V1);
}

parser_error_t _toStringVecPriceTier_V1(
    const pd_VecPriceTier_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(PriceTier_V1);
}

parser_error_t _toStringVecReceiptDetails_V1(
    const pd_VecReceiptDetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ReceiptDetails_V1);
}

parser_error_t _toStringVecScopeId_V1(
    const pd_VecScopeId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ScopeId_V1);
}

parser_error_t _toStringVecSecondaryKeyWithAuth_V1(
    const pd_VecSecondaryKeyWithAuth_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKeyWithAuth_V1);
}

parser_error_t _toStringVecSecondaryKey_V1(
    const pd_VecSecondaryKey_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKey_V1);
}

parser_error_t _toStringVecSignatory_V1(
    const pd_VecSignatory_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Signatory_V1);
}

parser_error_t _toStringVecTicker_V1(
    const pd_VecTicker_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Ticker_V1);
}

parser_error_t _toStringVecTrustedIssuer_V1(
    const pd_VecTrustedIssuer_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TrustedIssuer_V1);
}

parser_error_t _toStringVecTupleIdentityIdTax_V1(
    const pd_VecTupleIdentityIdTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdTax_V1);
}

parser_error_t _toStringVecTupleIdentityIdbool_V1(
    const pd_VecTupleIdentityIdbool_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleIdentityIdbool_V1);
}

parser_error_t _toStringVecTuplePipIdSnapshotResult_V1(
    const pd_VecTuplePipIdSnapshotResult_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TuplePipIdSnapshotResult_V1);
}

parser_error_t _toStringVecValidatorIndex_V1(
    const pd_VecValidatorIndex_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ValidatorIndex_V1);
}

parser_error_t _toStringOptionChangesTrieConfiguration_V1(
    const pd_OptionChangesTrieConfiguration_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringChangesTrieConfiguration_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionDocumentType_V1(
    const pd_OptionDocumentType_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringDocumentType_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionFundingRoundName_V1(
    const pd_OptionFundingRoundName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringFundingRoundName_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMemo_V1(
    const pd_OptionMemo_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMemo_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionMoment_V1(
    const pd_OptionMoment_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringMoment_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPeriod_V1(
    const pd_OptionPeriod_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPeriod_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPipDescription_V1(
    const pd_OptionPipDescription_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPipDescription_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPortfolioNumber_V1(
    const pd_OptionPortfolioNumber_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPortfolioNumber_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionReceiptDetails_V1(
    const pd_OptionReceiptDetails_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReceiptDetails_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionRecordDateSpec_V1(
    const pd_OptionRecordDateSpec_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringRecordDateSpec_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionScope_V1(
    const pd_OptionScope_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringScope_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTargetIdentities_V1(
    const pd_OptionTargetIdentities_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTargetIdentities_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionTax_V1(
    const pd_OptionTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringTax_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionUrl_V1(
    const pd_OptionUrl_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringUrl_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecDispatchableName_V1(
    const pd_OptionVecDispatchableName_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecDispatchableName_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecLegacyPalletPermissions_V1(
    const pd_OptionVecLegacyPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecLegacyPalletPermissions_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPalletPermissions_V1(
    const pd_OptionVecPalletPermissions_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPalletPermissions_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecPortfolioId_V1(
    const pd_OptionVecPortfolioId_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecPortfolioId_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTicker_V1(
    const pd_OptionVecTicker_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTicker_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionVecTupleIdentityIdTax_V1(
    const pd_OptionVecTupleIdentityIdTax_V1_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVecTupleIdentityIdTax_V1(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}
