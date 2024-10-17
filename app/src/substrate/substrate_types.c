/*******************************************************************************
 *  (c) 2019 - 2024 Zondax AG
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
#include "substrate_strings.h"

#include <stddef.h>
#include <stdint.h>
#include <zxformat.h>
#include <zxmacros.h>

parser_error_t _readbool(parser_context_t* c, pd_bool_t* v)
{
    return _readUInt8(c, v);
}

parser_error_t _readu8(parser_context_t* c, pd_u8_t* v)
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

parser_error_t _readCallImpl(parser_context_t* c, pd_Call_t* v, pd_MethodNested_t* m)
{
    // If it's the first Call, store a pointer to it
    if (c->tx_obj->nestCallIdx._ptr == NULL) {
        c->tx_obj->nestCallIdx._ptr = c->buffer + c->offset;
        c->tx_obj->nestCallIdx._lenBuffer = c->bufferLen - c->offset;
    } else {
        // If _ptr is not null, and landed here, means we're inside a nested call.
        // We stored the pointer to the first Call and now we store
        // the pointer to the 'next' Call.
        if (c->tx_obj->nestCallIdx._nextPtr == NULL) {
            c->tx_obj->nestCallIdx._nextPtr = c->buffer + c->offset;
        }
    }

    // To keep track on how many nested Calls we have
    c->tx_obj->nestCallIdx.slotIdx++;
    if (c->tx_obj->nestCallIdx.slotIdx > MAX_CALL_NESTING_SIZE) {
        return parser_tx_nesting_limit_reached;
    }

    CHECK_ERROR(_readCallIndex(c, &v->callIndex));

    if (!_getMethod_IsNestingSupported(c->tx_obj->transactionVersion, v->callIndex.moduleIdx, v->callIndex.idx)) {
        return parser_tx_nesting_not_supported;
    }

    // Read and check the contained method on this Call
    CHECK_ERROR(_readMethod(c, v->callIndex.moduleIdx, v->callIndex.idx, (pd_Method_t*)m))

    // The instance of 'v' corresponding to the upper call on the stack (persisted variable)
    // will end up having the pointer to the first Call and to the 'next' one if exists.
    v->_txVerPtr = &c->tx_obj->transactionVersion;
    v->nestCallIdx._lenBuffer = c->tx_obj->nestCallIdx._lenBuffer;
    v->nestCallIdx._ptr = c->tx_obj->nestCallIdx._ptr;
    v->nestCallIdx._nextPtr = c->tx_obj->nestCallIdx._nextPtr;

    return parser_ok;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
parser_error_t _readCompactu16(parser_context_t* c, pd_Compactu16_t* v)
{
    return _readCompactInt(c, v);
}

parser_error_t _readAssetId(parser_context_t* c, pd_AssetId_t* v)
{
    v->_len = 16;
    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readIdentityId(parser_context_t* c, pd_IdentityId_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readScope(parser_context_t* c, pd_Scope_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        CHECK_ERROR(_readIdentityId(c, &v->identity))
        break;
    case 1:
        CHECK_ERROR(_readAssetId(c, &v->assetId))
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

parser_error_t _readCddId(parser_context_t* c, pd_CddId_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readClaimType(parser_context_t* c, pd_ClaimType_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
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

parser_error_t _readScopeId(parser_context_t* c, pd_ScopeId_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readPortfolioNumber(parser_context_t* c, pd_PortfolioNumber_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readTupleCountryCodeScope(parser_context_t* c, pd_TupleCountryCodeScope_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCountryCode(c, &v->country_code))
    CHECK_ERROR(_readScope(c, &v->scope))
    return parser_ok;
}

parser_error_t _readTupleScopeScopeIdCddId(parser_context_t* c, pd_TupleScopeScopeIdCddId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readScope(c, &v->scope))
    CHECK_ERROR(_readScopeId(c, &v->scopeId))
    CHECK_ERROR(_readCddId(c, &v->cddId))
    return parser_ok;
}

parser_error_t _readTupleU32Scope(parser_context_t* c, pd_TupleU32Scope_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->u32))
    CHECK_ERROR(_readOptionScope(c, &v->scope))
    return parser_ok;
}

parser_error_t _readAccountId(parser_context_t* c, pd_AccountId_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readBalanceNoSymbol(parser_context_t* c, pd_BalanceNoSymbol_t* v) {
    GEN_DEF_READARRAY(16)
}

parser_error_t _readClaim(parser_context_t* c, pd_Claim_t* v)
{
    CHECK_INPUT()
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
    case 11: // InvestorUniquenessV2
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

parser_error_t _readDispatchableNames(parser_context_t* c, pd_DispatchableNames_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Whole
        break;
    case 1: // These
    case 2: // Except
        CHECK_ERROR(_readVecDispatchableName(c, &v->contained))
        break;
    default:
        return parser_unexpected_value;
    }
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

parser_error_t _readPortfolioKind(parser_context_t* c, pd_PortfolioKind_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_INPUT()
        CHECK_ERROR(_readPortfolioNumber(c, &v->number))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedFor(parser_context_t* c, pd_TrustedFor_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_ERROR(_readVecClaimType(c, &v->claims))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readPalletPermissions(parser_context_t* c, pd_PalletPermissions_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readPalletName(c, &v->palletName))
    CHECK_ERROR(_readDispatchableNames(c, &v->dispatchableNames))

    return parser_ok;
}

parser_error_t _readPermill(parser_context_t* c, pd_Permill_t* v)
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

parser_error_t _readTargetIdentity(parser_context_t* c, pd_TargetIdentity_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0:
        break;
    case 1:
        CHECK_ERROR(_readIdentityId(c, &v->specific))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readTrustedIssuer(parser_context_t* c, pd_TrustedIssuer_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readIdentityId(c, &v->issuer))
    CHECK_ERROR(_readTrustedFor(c, &v->trustedFor))
    return parser_ok;
}

parser_error_t _readTupleAccountId32u128(parser_context_t* c, pd_TupleAccountId32u128_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->accountId))
    CHECK_ERROR(_readBalanceNoSymbol(c, &v->value))
    return parser_ok;
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

parser_error_t _readConditionType(parser_context_t* c, pd_ConditionType_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
    case 1:
        CHECK_ERROR(_readClaim(c, &v->claim))
        break;
    case 2:
    case 3:
        CHECK_ERROR(_readVecClaim(c, &v->vecClaim))
        break;
    case 4:
        CHECK_ERROR(_readTargetIdentity(c, &v->identity))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readEcdsaSignature(parser_context_t* c, pd_EcdsaSignature_t* v) {
    GEN_DEF_READARRAY(65)
}

parser_error_t _readEd25519Signature(parser_context_t* c, pd_Ed25519Signature_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readMemo(parser_context_t* c, pd_Memo_t* v)
{
    v->_len = 32;
    GEN_DEF_READARRAY(32)
    return parser_ok;
}

parser_error_t _readSr25519Signature(parser_context_t* c, pd_Sr25519Signature_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readTax(parser_context_t* c, pd_Tax_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readPermill(c, &v->value))
    return parser_ok;
}

parser_error_t _readTupleCompactu16Compactu16(parser_context_t* c, pd_TupleCompactu16Compactu16_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu16(c, &v->firstElemInTuple))
    CHECK_ERROR(_readCompactu16(c, &v->secondElemInTuple))
    return parser_ok;
}

parser_error_t _readAssetPermissions(parser_context_t* c, pd_AssetPermissions_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Whole
        break;
    case 1: // These
    case 2: // Except
        CHECK_ERROR(_readVecAssetId(c, &v->contained))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readCheckpointId(parser_context_t* c, pd_CheckpointId_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readCondition(parser_context_t* c, pd_Condition_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readConditionType(c, &v->conditionType))
    CHECK_ERROR(_readVecTrustedIssuer(c, &v->issuers))
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

parser_error_t _readExtrinsicPermissions(parser_context_t* c, pd_ExtrinsicPermissions_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Whole
        break;
    case 1: // These
    case 2: // Except
        CHECK_ERROR(_readVecPalletPermissions(c, &v->contained))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readMoment(parser_context_t* c, pd_Moment_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
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

parser_error_t _readMultiSignature(parser_context_t* c, pd_MultiSignature_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_readEd25519Signature(c, &v->ed25519))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_readSr25519Signature(c, &v->sr25519))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_readEcdsaSignature(c, &v->ecdsa))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readPortfolioPermissions(parser_context_t* c, pd_PortfolioPermissions_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Whole
        break;
    case 1: // These
    case 2: // Except
        CHECK_ERROR(_readVecPortfolioId(c, &v->contained))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readReceiptMetadata(parser_context_t* c, pd_ReceiptMetadata_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readScheduleId(parser_context_t* c, pd_ScheduleId_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readSpNposElectionsSupport(parser_context_t* c, pd_SpNposElectionsSupport_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBalanceNoSymbol(c, &v->total))
    CHECK_ERROR(_readVecTupleAccountId32u128(c, &v->voters))
    return parser_ok;
}

parser_error_t _readTargetTreatment(parser_context_t* c, pd_TargetTreatment_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTicker(parser_context_t* c, pd_Ticker_t* v)
{
    v->_len = 12;
    GEN_DEF_READARRAY(v->_len)
}

parser_error_t _readTupleIdentityIdTax(parser_context_t* c, pd_TupleIdentityIdTax_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readIdentityId(c, &v->id))
    CHECK_ERROR(_readTax(c, &v->tax))
    return parser_ok;
}

parser_error_t _readVoteEight(parser_context_t* c, pd_VoteEight_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readCompactu16(c, &v->ninthElem))
    return parser_ok;
}

parser_error_t _readVoteEleven(parser_context_t* c, pd_VoteEleven_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->tenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eleventhElem))
    CHECK_ERROR(_readCompactu16(c, &v->twelfthElem))
    return parser_ok;
}

parser_error_t _readVoteFifteen(parser_context_t* c, pd_VoteFifteen_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->tenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eleventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->twelfthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirteenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourteenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifteenthElem))
    CHECK_ERROR(_readCompactu16(c, &v->sixteenthElem))
    return parser_ok;
}

parser_error_t _readVoteFive(parser_context_t* c, pd_VoteFive_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readCompactu16(c, &v->sixthElem))
    return parser_ok;
}

parser_error_t _readVoteFour(parser_context_t* c, pd_VoteFour_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readCompactu16(c, &v->fifthElem))
    return parser_ok;
}

parser_error_t _readVoteFourteen(parser_context_t* c, pd_VoteFourteen_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->tenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eleventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->twelfthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirteenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourteenthElem))
    CHECK_ERROR(_readCompactu16(c, &v->fifteenthElem))
    return parser_ok;
}

parser_error_t _readVoteNine(parser_context_t* c, pd_VoteNine_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readCompactu16(c, &v->tenthElem))
    return parser_ok;
}

parser_error_t _readVoteOne(parser_context_t* c, pd_VoteOne_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readCompactu16(c, &v->secondElem))
    return parser_ok;
}

parser_error_t _readVoteSeven(parser_context_t* c, pd_VoteSeven_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readCompactu16(c, &v->eighthElem))
    return parser_ok;
}

parser_error_t _readVoteSix(parser_context_t* c, pd_VoteSix_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readCompactu16(c, &v->seventhElem))
    return parser_ok;
}

parser_error_t _readVoteSixteen(parser_context_t* c, pd_VoteSixteen_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->tenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eleventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->twelfthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirteenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourteenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifteenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixteenthElem))
    CHECK_ERROR(_readCompactu16(c, &v->seventeenthElem))
    return parser_ok;
}

parser_error_t _readVoteTen(parser_context_t* c, pd_VoteTen_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->tenthElem))
    CHECK_ERROR(_readCompactu16(c, &v->eleventhElem))
    return parser_ok;
}

parser_error_t _readVoteThirteen(parser_context_t* c, pd_VoteThirteen_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->tenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eleventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->twelfthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirteenthElem))
    CHECK_ERROR(_readCompactu16(c, &v->fourteenthElem))
    return parser_ok;
}

parser_error_t _readVoteThree(parser_context_t* c, pd_VoteThree_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readCompactu16(c, &v->fourthElem))
    return parser_ok;
}

parser_error_t _readVoteTwelve(parser_context_t* c, pd_VoteTwelve_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->thirdElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fourthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->fifthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->sixthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->seventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eighthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->ninthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->tenthElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->eleventhElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->twelfthElem))
    CHECK_ERROR(_readCompactu16(c, &v->thirteenthElem))
    return parser_ok;
}

parser_error_t _readVoteTwo(parser_context_t* c, pd_VoteTwo_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->firstElem))
    CHECK_ERROR(_readTupleCompactu16Compactu16(c, &v->secondElem))
    CHECK_ERROR(_readCompactu16(c, &v->thirdElem))
    return parser_ok;
}

parser_error_t _readAgentGroup(parser_context_t* c, pd_AgentGroup_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Full
    case 2: // ExceptMeta
    case 3: // PolymeshV1CAA
    case 4: // PolymeshV1PIA
        break;
    case 1: // Custom
        CHECK_ERROR(_readUInt32(c, &v->custom))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readAssetCount(parser_context_t* c, pd_AssetCount_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->fungible))
    CHECK_ERROR(_readUInt32(c, &v->nonFungible))
    CHECK_ERROR(_readUInt32(c, &v->offChain))
    return parser_ok;
}

parser_error_t _readAssetMetadataKey(parser_context_t* c, pd_AssetMetadataKey_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value < 2) {
        CHECK_ERROR(_readUInt64(c, &v->key))
        return parser_ok;
    }
    return parser_unexpected_value;
}

parser_error_t _readAssetMetadataLockStatusMoment(parser_context_t* c, pd_AssetMetadataLockStatusMoment_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value == 2) {
        CHECK_ERROR(_readMoment(c, &v->moment))
    }
    if (v->value > 2) {
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBalance(parser_context_t* c, pd_Balance_t* v) {
    GEN_DEF_READARRAY(16)
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

parser_error_t _readCompactAccountIndex(parser_context_t* c, pd_CompactAccountIndex_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readDocumentHash(parser_context_t* c, pd_DocumentHash_t* v)
{
    CHECK_INPUT()
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

parser_error_t _readFundFungible(parser_context_t* c, pd_FundFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId(c, &v->assetId))
    CHECK_ERROR(_readBalanceNoSymbol(c, &v->amount))
    CHECK_ERROR(_readOptionMemo(c, &v->memo))
    return parser_ok;
}

parser_error_t _readFundNonFungible(parser_context_t* c, pd_FundNonFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId(c, &v->assetId))
    CHECK_ERROR(_readVecu64(c, &v->ids))
    CHECK_ERROR(_readOptionMemo(c, &v->memo))
    return parser_ok;
}

parser_error_t _readLegFungible(parser_context_t* c, pd_LegFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readPortfolioId(c, &v->sender))
    CHECK_ERROR(_readPortfolioId(c, &v->receiver))
    CHECK_ERROR(_readAssetId(c, &v->assetId))
    CHECK_ERROR(_readBalanceNoSymbol(c, &v->amount))
    return parser_ok;
}

parser_error_t _readLegNonFungible(parser_context_t* c, pd_LegNonFungible_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readPortfolioId(c, &v->sender))
    CHECK_ERROR(_readPortfolioId(c, &v->receiver))
    CHECK_ERROR(_readAssetId(c, &v->assetId))
    CHECK_ERROR(_readVecu64(c, &v->ids))
    return parser_ok;
}

parser_error_t _readLegOffChain(parser_context_t* c, pd_LegOffChain_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readIdentityId(c, &v->sender))
    CHECK_ERROR(_readIdentityId(c, &v->receiver))
    CHECK_ERROR(_readTicker(c, &v->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &v->amount))
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

parser_error_t _readNFTId(parser_context_t* c, pd_NFTId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
}

parser_error_t _readOffChainSignature(parser_context_t* c, pd_OffChainSignature_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMultiSignature(c, &v->value))
    return parser_ok;
}

parser_error_t _readPermissions(parser_context_t* c, pd_Permissions_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetPermissions(c, &v->asset))
    CHECK_ERROR(_readExtrinsicPermissions(c, &v->extrinsic))
    CHECK_ERROR(_readPortfolioPermissions(c, &v->portfolio))
    return parser_ok;
}

parser_error_t _readPipId(parser_context_t* c, pd_PipId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readRecordDateSpec(parser_context_t* c, pd_RecordDateSpec_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Scheduled
        CHECK_ERROR(_readMoment(c, &v->scheduled))
        break;
    case 1: // ExistingSchedule
        CHECK_ERROR(_readScheduleId(c, &v->existingSchedule))
        break;
    case 2: // Existing
        CHECK_ERROR(_readCheckpointId(c, &v->existing))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignature(parser_context_t* c, pd_Signature_t* v) {
    GEN_DEF_READARRAY(64)
}

parser_error_t _readSnapshotResult(parser_context_t* c, pd_SnapshotResult_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readTargetIdentities(parser_context_t* c, pd_TargetIdentities_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecIdentityId(c, &v->identities))
    CHECK_ERROR(_readTargetTreatment(c, &v->treatment))
    return parser_ok;
}

parser_error_t _readTupleAccountId32SpNposElectionsSupport(parser_context_t* c, pd_TupleAccountId32SpNposElectionsSupport_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->accountId))
    CHECK_ERROR(_readSpNposElectionsSupport(c, &v->support))
    return parser_ok;
}

parser_error_t _readu8_array_32(parser_context_t* c, pd_u8_array_32_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readAccountIdLookupOfT(parser_context_t* c, pd_AccountIdLookupOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readAddRelayerPayingKey(parser_context_t* c, pd_AddRelayerPayingKey_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->accountId_1));
    CHECK_ERROR(_readAccountId(c, &v->accountId_2));
    CHECK_ERROR(_readBalance(c, &v->balance));
    return parser_ok;
}

parser_error_t _readAffirmationCount(parser_context_t* c, pd_AffirmationCount_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetCount(c, &v->senderAssetCount))
    CHECK_ERROR(_readAssetCount(c, &v->receiverAssetCount))
    CHECK_ERROR(_readUInt32(c, &v->offChainCount))
    return parser_ok;
}

parser_error_t _readApiCodeHash(parser_context_t* c, pd_ApiCodeHash_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu8_array_32(c, &v->hash))
    return parser_ok;
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

parser_error_t _readAssetMetadataValueDetailMoment(parser_context_t* c, pd_AssetMetadataValueDetailMoment_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionMoment(c, &v->expire))
    CHECK_ERROR(_readAssetMetadataLockStatusMoment(c, &v->lockStatus))
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
    CHECK_INPUT()
    CHECK_ERROR(_readBalance(c, &v->power))
    CHECK_ERROR(_readOptionu16(c, &v->fallback))
    return parser_ok;
}

parser_error_t _readBecomeAgent(parser_context_t* c, pd_BecomeAgent_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId(c, &v->assetId));
    CHECK_ERROR(_readAgentGroup(c, &v->agentGroup));
    return parser_ok;
}

parser_error_t _readBeneficiary(parser_context_t* c, pd_Beneficiary_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readIdentityId(c, &v->identity))
    CHECK_ERROR(_readBalance(c, &v->balance))
    return parser_ok;
}

parser_error_t _readCAKind(parser_context_t* c, pd_CAKind_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
}

parser_error_t _readCall(parser_context_t* c, pd_Call_t* v)
{
    pd_MethodNested_t _method;
    if (c->tx_obj->nestCallIdx.isTail) {
        c->tx_obj->nestCallIdx.isTail = false;
        v->nestCallIdx.isTail = true;
    } else {
        v->nestCallIdx.isTail = false;
    }

    CHECK_ERROR(_readCallImpl(c, v, &_method))
    if (c->tx_obj->nestCallIdx._ptr != NULL && c->tx_obj->nestCallIdx._nextPtr != NULL) {
        v->nestCallIdx._ptr = c->tx_obj->nestCallIdx._ptr;
        v->nestCallIdx._nextPtr = c->tx_obj->nestCallIdx._nextPtr;
    }
    v->nestCallIdx.slotIdx = c->tx_obj->nestCallIdx.slotIdx;
    return parser_ok;
}

parser_error_t _readChainVersion(parser_context_t* c, pd_ChainVersion_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->specVersion))
    CHECK_ERROR(_readUInt32(c, &v->txVersion))
    return parser_ok;
}

parser_error_t _readCompactBalanceOf(parser_context_t* c, pd_CompactBalanceOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactInt(c, &v->value));
    return parser_ok;
}

parser_error_t _readCompactPerBill(parser_context_t* c, pd_CompactPerBill_t* v)
{
    return _readCompactInt(c, &v->value);
}

parser_error_t _readComplianceRequirement(parser_context_t* c, pd_ComplianceRequirement_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readVecCondition(c, &v->senderConditions))
    CHECK_ERROR(_readVecCondition(c, &v->receiverConditions))
    CHECK_ERROR(_readUInt32(c, &v->id))
    return parser_ok;
}

parser_error_t _readCreateChildIdentityWithAuthAccountId(parser_context_t* c, pd_CreateChildIdentityWithAuthAccountId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->key))
    CHECK_ERROR(_readSignature(c, &v->authSignature))
    return parser_ok;
}

parser_error_t _readCustomAssetTypeId(parser_context_t* c, pd_CustomAssetTypeId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readDocumentId(parser_context_t* c, pd_DocumentId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readDocument(parser_context_t* c, pd_Document_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readDocumentUri(c, &v->uri))
    CHECK_ERROR(_readDocumentHash(c, &v->content_hash))
    CHECK_ERROR(_readDocumentName(c, &v->name))
    CHECK_ERROR(_readOptionDocumentType(c, &v->doc_type))
    CHECK_ERROR(_readOptionMoment(c, &v->filing_date))
    return parser_ok;
}

parser_error_t _readElectionScore(parser_context_t* c, pd_ElectionScore_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBalance(c, &v->minimalStake))
    CHECK_ERROR(_readBalance(c, &v->sumStake))
    CHECK_ERROR(_readBalance(c, &v->sumStakeSquared))
    return parser_ok;
}

parser_error_t _readFund(parser_context_t* c, pd_Fund_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Fungible
        CHECK_ERROR(_readFundFungible(c, &v->fungible))
        break;
    case 1: // NonFungible
        CHECK_ERROR(_readFundNonFungible(c, &v->nonFungible))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
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

parser_error_t _readHash(parser_context_t* c, pd_Hash_t* v) {
    GEN_DEF_READARRAY(32)
}

parser_error_t _readLeg(parser_context_t* c, pd_Leg_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Fungible
        CHECK_ERROR(_readLegFungible(c, &v->fungible))
        break;
    case 1: // NonFungible
        CHECK_ERROR(_readLegNonFungible(c, &v->nonFungible))
        break;
    case 2: // OffChain
        CHECK_ERROR(_readLegOffChain(c, &v->offChain))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readLocalCAId(parser_context_t* c, pd_LocalCAId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readNFTMetadataAttribute(parser_context_t* c, pd_NFTMetadataAttribute_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetMetadataKey(c, &v->key))
    CHECK_ERROR(_readBytes(c, &v->value))
    return parser_ok;
}

parser_error_t _readNonFungibleType(parser_context_t* c, pd_NonFungibleType_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Derivative
    case 1: // FixedIncome
    case 2: // Invoice
        break;
    case 3: // Custom
        CHECK_ERROR(_readUInt32(c, &v->custom))
        break;
    }
    return parser_ok;
}

parser_error_t _readPerbill(parser_context_t* c, pd_Perbill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readPercent(parser_context_t* c, pd_Percent_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
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

parser_error_t _readPriceTier(parser_context_t* c, pd_PriceTier_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBalance(c, &v->total))
    CHECK_ERROR(_readBalance(c, &v->price))
    return parser_ok;
}

parser_error_t _readReceiptDetails(parser_context_t* c, pd_ReceiptDetails_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->uid))
    CHECK_ERROR(_readUInt64(c, &v->instructionId))
    CHECK_ERROR(_readUInt64(c, &v->legId))
    CHECK_ERROR(_readAccountId(c, &v->signer))
    CHECK_ERROR(_readOffChainSignature(c, &v->signature))
    CHECK_ERROR(_readOptionReceiptMetadata(c, &v->metadata))
    return parser_ok;
}

parser_error_t _readSecondaryKeyAccountId(parser_context_t* c, pd_SecondaryKeyAccountId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->key))
    CHECK_ERROR(_readPermissions(c, &v->permissions))
    return parser_ok;
}

parser_error_t _readSecondaryKeyWithAuthAccountId(parser_context_t* c, pd_SecondaryKeyWithAuthAccountId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAccountId(c, &v->key))
    CHECK_ERROR(_readPermissions(c, &v->permissions))
    CHECK_ERROR(_readSignature(c, &v->auth_signature))
    return parser_ok;
}

parser_error_t _readSolution(parser_context_t* c, pd_Solution_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecVoteOne(c, &v->voteOne))
    CHECK_ERROR(_readVecVoteTwo(c, &v->voteTwo))
    CHECK_ERROR(_readVecVoteThree(c, &v->voteThree))
    CHECK_ERROR(_readVecVoteFour(c, &v->voteFour))
    CHECK_ERROR(_readVecVoteFive(c, &v->voteFive))
    CHECK_ERROR(_readVecVoteSix(c, &v->voteSix))
    CHECK_ERROR(_readVecVoteSeven(c, &v->voteSeven))
    CHECK_ERROR(_readVecVoteEight(c, &v->voteEight))
    CHECK_ERROR(_readVecVoteNine(c, &v->voteNine))
    CHECK_ERROR(_readVecVoteTen(c, &v->voteTen))
    CHECK_ERROR(_readVecVoteEleven(c, &v->voteEleven))
    CHECK_ERROR(_readVecVoteTwelve(c, &v->voteTwelve))
    CHECK_ERROR(_readVecVoteThirteen(c, &v->voteThirteen))
    CHECK_ERROR(_readVecVoteFourteen(c, &v->voteFourteen))
    CHECK_ERROR(_readVecVoteFifteen(c, &v->voteFifteen))
    CHECK_ERROR(_readVecVoteSixteen(c, &v->voteSixteen))
    return parser_ok;
}

parser_error_t _readSystemOrigin(parser_context_t* c, pd_SystemOrigin_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Root
    case 2: // None
        break;
    case 1: // Signed
        CHECK_ERROR(_readAccountId(c, &v->_signed))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readTupleExtrinsicIdbool(parser_context_t* c, pd_TupleExtrinsicIdbool_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->extrinsicId1))
    CHECK_ERROR(_readUInt8(c, &v->extrinsicId2))
    CHECK_ERROR(_readbool(c, &v->_bool))
    return parser_ok;
}

parser_error_t _readTuplePipIdSnapshotResult(parser_context_t* c, pd_TuplePipIdSnapshotResult_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readPipId(c, &v->pip_id))
    CHECK_ERROR(_readSnapshotResult(c, &v->snapshot_result))
    return parser_ok;
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

parser_error_t _readVenueId(parser_context_t* c, pd_VenueId_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readWeight(parser_context_t* c, pd_Weight_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu64(c, &v->refTime))
    CHECK_ERROR(_readCompactu64(c, &v->proofSize))
    return parser_ok;
}

parser_error_t _readu8_array_4(parser_context_t* c, pd_u8_array_4_t* v) {
    GEN_DEF_READARRAY(4)
}

parser_error_t _readApi(parser_context_t* c, pd_Api_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readu8_array_4(c, &v->desc))
    CHECK_ERROR(_readUInt32(c, &v->major))
    return parser_ok;
}

parser_error_t _readAssetMetadataName(parser_context_t* c, pd_AssetMetadataName_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBytes(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetMetadataSpec(parser_context_t* c, pd_AssetMetadataSpec_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readOptionBytes(c, &v->url))
    CHECK_ERROR(_readOptionBytes(c, &v->description))
    CHECK_ERROR(_readOptionBytes(c, &v->typeDef))
    return parser_ok;
}

parser_error_t _readAssetMetadataValue(parser_context_t* c, pd_AssetMetadataValue_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBytes(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetType(parser_context_t* c, pd_AssetType_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 10) {
        return parser_unexpected_value;
    }

    if (v->value == 9) {
        // Custom type
        CHECK_ERROR(_readCustomAssetTypeId(c, &v->custom))
    }

    return parser_ok;
}

parser_error_t _readAuthorizationDataAccountId(parser_context_t* c, pd_AuthorizationDataAccountId_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0: // AttestPrimaryKeyRotation
        CHECK_ERROR(_readIdentityId(c, &v->identityId))
        break;
    case 1: // RotatePrimaryKey
        break;
    case 2: // TransferTicker
        CHECK_ERROR(_readTicker(c, &v->ticker))
        break;
    case 3: // AddMultiSigSigner
        CHECK_ERROR(_readAccountId(c, &v->accountId))
        break;
    case 4: // TransferAssetOwnership
        CHECK_ERROR(_readAssetId(c, &v->assetId))
        break;
    case 5: // JoinIdentity
        CHECK_ERROR(_readPermissions(c, &v->permissions))
        break;
    case 6: // PortfolioCustody
        CHECK_ERROR(_readPortfolioId(c, &v->portfolioId))
        break;
    case 7: // BecomeAgent
        CHECK_ERROR(_readBecomeAgent(c, &v->becomeAgent))
        break;
    case 8: // AddRelayerPayingKey
        CHECK_ERROR(_readAddRelayerPayingKey(c, &v->addRelayerPayingKey))
        break;
    case 9: // RotatePrimaryKeyToSecondary
        CHECK_ERROR(_readPermissions(c, &v->permissions))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readBalanceOf(parser_context_t* c, pd_BalanceOf_t* v)
{
    return _readBalance(c, &v->value);
}

parser_error_t _readBallotMeta(parser_context_t* c, pd_BallotMeta_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readBallotTitle(c, &v->title))
    CHECK_ERROR(_readVecMotion(c, &v->motions))
    return parser_ok;
}

parser_error_t _readBallotTimeRange(parser_context_t* c, pd_BallotTimeRange_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readMoment(c, &v->start))
    CHECK_ERROR(_readMoment(c, &v->end))
    return parser_ok;
}

parser_error_t _readBoundedBTreeSetIdentityIdMaxAssetMediators(parser_context_t* c, pd_BoundedBTreeSetIdentityIdMaxAssetMediators_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecIdentityId(c, &v->identities))
    return parser_ok;
}

parser_error_t _readBoundedBTreeSetIdentityIdMaxInstructionMediators(parser_context_t* c, pd_BoundedBTreeSetIdentityIdMaxInstructionMediators_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecIdentityId(c, &v->identities))
    return parser_ok;
}

parser_error_t _readBoundedVecAccountIdMaxSigners(parser_context_t* c, pd_BoundedVecAccountIdMaxSigners_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecAccountId(c, &v->contained))
    return parser_ok;
}

parser_error_t _readBoxPalletsOrigin(parser_context_t* c, pd_BoxPalletsOrigin_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // System
        CHECK_ERROR(_readSystemOrigin(c, &v->system))
        break;
    case 4: // Void
        break;
    case 9: // PolymeshCommittee
    case 11: // TechnicalCommittee
    case 13: // UpgradeCommittee
        CHECK_ERROR(_readUInt8(c, &v->committee))
        if (v->committee != 0) {
            return parser_unexpected_value;
        }
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readBoxRawSolutionSolutionOfMinerConfig(parser_context_t* c, pd_BoxRawSolutionSolutionOfMinerConfig_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readSolution(c, &v->solution))
    CHECK_ERROR(_readElectionScore(c, &v->score))
    CHECK_ERROR(_readUInt32(c, &v->round))
    return parser_ok;
}

parser_error_t _readBoxTasConfigProposal(parser_context_t* c, pd_BoxTasConfigProposal_t* v)
{
    return _readCall(c, &v->call);
}

parser_error_t _readCAId(parser_context_t* c, pd_CAId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId(c, &v->assetId))
    CHECK_ERROR(_readLocalCAId(c, &v->local_id))
    return parser_ok;
}

parser_error_t _readCodeHash(parser_context_t* c, pd_CodeHash_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readHash(c, &v->hash))
    return parser_ok;
}

parser_error_t _readConfigOpBalanceOfT(parser_context_t* c, pd_ConfigOpBalanceOfT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readBalance(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConfigOpPerbill(parser_context_t* c, pd_ConfigOpPerbill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readPerbill(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readConfigOpPercent(parser_context_t* c, pd_ConfigOpPercent_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readPercent(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readInitiateCorporateActionArgs(parser_context_t* c, pd_InitiateCorporateActionArgs_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId(c, &v->assetId))
    CHECK_ERROR(_readCAKind(c, &v->kind))
    CHECK_ERROR(_readUInt64(c, &v->declDate))
    CHECK_ERROR(_readOptionRecordDateSpec(c, &v->recordDate))
    CHECK_ERROR(_readBytes(c, &v->details))
    CHECK_ERROR(_readOptionTargetIdentities(c, &v->targets))
    CHECK_ERROR(_readOptionPermill(c, &v->defaultWithholdingTax))
    CHECK_ERROR(_readOptionVecTupleIdentityIdTax(c, &v->withholdingTax))
    return parser_ok;
}

parser_error_t _readLookupasStaticLookupSource(parser_context_t* c, pd_LookupasStaticLookupSource_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_readAccountId(c, &v->id))
        break;
    case 1: // Index
        CHECK_ERROR(_readCompactAccountIndex(c, &v->index))
        break;
    case 2: // Raw
        CHECK_ERROR(_readBytes(c, &v->raw))
        break;
    case 3: // Address32
        GEN_DEF_READARRAY(32)
        break;
    case 4: // Address20
        GEN_DEF_READARRAY(20)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readMaybeBlockBlockNumber(parser_context_t* c, pd_MaybeBlockBlockNumber_t* v)
{
    CHECK_INPUT()
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

parser_error_t _readNFTs(parser_context_t* c, pd_NFTs_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readAssetId(c, &v->assetId))
    CHECK_ERROR(_readVecNFTId(c, &v->ids))
    return parser_ok;
}

parser_error_t _readNextUpgradeT(parser_context_t* c, pd_NextUpgradeT_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readChainVersion(c, &v->chainVersion))
    CHECK_ERROR(_readApiCodeHash(c, &v->apiHash))
    return parser_ok;
}

parser_error_t _readProposal(parser_context_t* c, pd_Proposal_t* v)
{
    return _readCall(c, &v->call);
}

parser_error_t _readRewardDestination(parser_context_t* c, pd_RewardDestination_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Staked
        break;
    case 1: // Stash
        break;
    case 2: // Controller
        break;
    case 3: // Account
        CHECK_ERROR(_readAccountId(c, &v->accountId))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readScheduleCheckpoints(parser_context_t* c, pd_ScheduleCheckpoints_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecu64(c, &v->pending))
    return parser_ok;
}

parser_error_t _readSettlementTypeBlockNumber(parser_context_t* c, pd_SettlementTypeBlockNumber_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0: // SettleOnAffirmation
        break;
    case 1: // SettleOnBlock
    case 2: // SettleManual
        CHECK_ERROR(_readBlockNumber(c, &v->blockNumber))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSignatoryAccountId(parser_context_t* c, pd_SignatoryAccountId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    switch (v->value) {
    case 0:
        CHECK_ERROR(_readIdentityId(c, &v->identity))
        break;
    case 1:
        CHECK_ERROR(_readAccountId(c, &v->account))
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readSolutionOrSnapshotSize(parser_context_t* c, pd_SolutionOrSnapshotSize_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactu32(c, &v->voters))
    CHECK_ERROR(_readCompactu32(c, &v->targets))
    return parser_ok;
}

parser_error_t _readSupportsAccountId(parser_context_t* c, pd_SupportsAccountId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readVecTupleAccountId32SpNposElectionsSupport(c, &v->tupleAccSupport))
    return parser_ok;
}

parser_error_t _readUniqueCall(parser_context_t* c, pd_UniqueCall_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->nonce))
    CHECK_ERROR(_readCall(c, &v->call))
    return parser_ok;
}

parser_error_t _readValidatorPrefs(parser_context_t* c, pd_ValidatorPrefs_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readCompactPerBill(c, &v->commission));
    CHECK_ERROR(_readBool(c, &v->blocked));
    return parser_ok;
}

parser_error_t _readVecCall(parser_context_t* c, pd_VecCall_t* v)
{
    compactInt_t clen;
    pd_Call_t dummy;
    CHECK_PARSER_ERR(_readCompactInt(c, &clen));
    CHECK_PARSER_ERR(_getValue(&clen, &v->_len));

    if (v->_len > MAX_CALL_VEC_SIZE) {
        return parser_tx_call_vec_too_large;
    }

    v->_ptr = c->buffer + c->offset;
    v->_lenBuffer = c->offset;
    if (v->_len == 0) {
        return parser_unexpected_buffer_end;
    }

    for (uint64_t i = 0; i < v->_len; i++) {
        c->tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCall(c, &dummy))
    }
    v->_lenBuffer = c->offset - v->_lenBuffer;
    v->callTxVersion = c->tx_obj->transactionVersion;

    return parser_ok;
}

parser_error_t _readAGId(parser_context_t* c, pd_AGId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAccountIndex(parser_context_t* c, pd_AccountIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readAssetMetadataLocalKey(parser_context_t* c, pd_AssetMetadataLocalKey_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt64(c, &v->value))
    return parser_ok;
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

parser_error_t _readConfigOpu32(parser_context_t* c, pd_ConfigOpu32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    switch (v->value) {
    case 0: // Noop
    case 2: // Remove
        break;
    case 1:
        CHECK_ERROR(_readUInt32(c, &v->set))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _readDeterminism(parser_context_t* c, pd_Determinism_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    if (v->value > 1) {
        return parser_value_out_of_range;
    }
    return parser_ok;
}

parser_error_t _readEraIndex(parser_context_t* c, pd_EraIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readFundraiserId(parser_context_t* c, pd_FundraiserId_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readFundraiserName(parser_context_t* c, pd_FundraiserName_t* v)
{
    CHECK_INPUT()

    compactInt_t clen;
    CHECK_ERROR(_readCompactInt(c, &clen))
    CHECK_ERROR(_getValue(&clen, &v->_len))

    v->_ptr = c->buffer + c->offset;
    CTX_CHECK_AND_ADVANCE(c, v->_len);

    return parser_ok;
}

parser_error_t _readInstructionId(parser_context_t* c, pd_InstructionId_t* v)
{
    return _readUInt64(c, &v->value);
}

parser_error_t _readKeys(parser_context_t* c, pd_Keys_t* v)
{
    GEN_DEF_READARRAY(4 * 32)
    return parser_ok;
}

parser_error_t _readMemberCount(parser_context_t* c, pd_MemberCount_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readOptionAssetId(parser_context_t* c, pd_OptionAssetId_t* v)
{
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAssetId(c, &v->assetId))
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

parser_error_t _readPosRatio(parser_context_t* c, pd_PosRatio_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->numerator))
    CHECK_ERROR(_readUInt32(c, &v->denominator))
    return parser_ok;
}

parser_error_t _readProposalIndex(parser_context_t* c, pd_ProposalIndex_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt32(c, &v->value))
    return parser_ok;
}

parser_error_t _readSkippedCount(parser_context_t* c, pd_SkippedCount_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))
    return parser_ok;
}

parser_error_t _readSlashingSwitch(parser_context_t* c, pd_SlashingSwitch_t* v)
{
    CHECK_INPUT()

    CHECK_ERROR(_readUInt8(c, &v->value));
    return parser_ok;
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
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->value))

    if (v->value > 3) {
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _readVecClaimType(parser_context_t* c, pd_VecClaimType_t* v) {
    GEN_DEF_READVECTOR(ClaimType)
}

parser_error_t _readVecDispatchableName(parser_context_t* c, pd_VecDispatchableName_t* v) {
    GEN_DEF_READVECTOR(DispatchableName)
}

parser_error_t _readVecClaim(parser_context_t* c, pd_VecClaim_t* v) {
    GEN_DEF_READVECTOR(Claim)
}

parser_error_t _readVecAssetId(parser_context_t* c, pd_VecAssetID_t* v) {
    GEN_DEF_READVECTOR(AssetId)
}

parser_error_t _readVecPalletPermissions(parser_context_t* c, pd_VecPalletPermissions_t* v) {
    GEN_DEF_READVECTOR(PalletPermissions)
}

parser_error_t _readVecPortfolioId(parser_context_t* c, pd_VecPortfolioId_t* v) {
    GEN_DEF_READVECTOR(PortfolioId)
}

parser_error_t _readVecTrustedIssuer(parser_context_t* c, pd_VecTrustedIssuer_t* v) {
    GEN_DEF_READVECTOR(TrustedIssuer)
}

parser_error_t _readVecTupleAccountId32u128(parser_context_t* c, pd_VecTupleAccountId32u128_t* v) {
    GEN_DEF_READVECTOR(TupleAccountId32u128)
}

parser_error_t _readVecChoiceTitle(parser_context_t* c, pd_VecChoiceTitle_t* v) {
    GEN_DEF_READVECTOR(ChoiceTitle)
}

parser_error_t _readVecIdentityId(parser_context_t* c, pd_VecIdentityId_t* v) {
    GEN_DEF_READVECTOR(IdentityId)
}

parser_error_t _readVecu64(parser_context_t* c, pd_Vecu64_t* v) {
    GEN_DEF_READVECTOR(u64)
}

parser_error_t _readVecCondition(parser_context_t* c, pd_VecCondition_t* v) {
    GEN_DEF_READVECTOR(Condition)
}

parser_error_t _readVecTupleIdentityIdTax(parser_context_t* c, pd_VecTupleIdentityIdTax_t* v) {
    GEN_DEF_READVECTOR(TupleIdentityIdTax)
}

parser_error_t _readVecVoteEight(parser_context_t* c, pd_VecVoteEight_t* v) {
    GEN_DEF_READVECTOR(VoteEight)
}

parser_error_t _readVecVoteEleven(parser_context_t* c, pd_VecVoteEleven_t* v) {
    GEN_DEF_READVECTOR(VoteEleven)
}

parser_error_t _readVecVoteFifteen(parser_context_t* c, pd_VecVoteFifteen_t* v) {
    GEN_DEF_READVECTOR(VoteFifteen)
}

parser_error_t _readVecVoteFive(parser_context_t* c, pd_VecVoteFive_t* v) {
    GEN_DEF_READVECTOR(VoteFive)
}

parser_error_t _readVecVoteFour(parser_context_t* c, pd_VecVoteFour_t* v) {
    GEN_DEF_READVECTOR(VoteFour)
}

parser_error_t _readVecVoteFourteen(parser_context_t* c, pd_VecVoteFourteen_t* v) {
    GEN_DEF_READVECTOR(VoteFourteen)
}

parser_error_t _readVecVoteNine(parser_context_t* c, pd_VecVoteNine_t* v) {
    GEN_DEF_READVECTOR(VoteNine)
}

parser_error_t _readVecVoteOne(parser_context_t* c, pd_VecVoteOne_t* v) {
    GEN_DEF_READVECTOR(VoteOne)
}

parser_error_t _readVecVoteSeven(parser_context_t* c, pd_VecVoteSeven_t* v) {
    GEN_DEF_READVECTOR(VoteSeven)
}

parser_error_t _readVecVoteSix(parser_context_t* c, pd_VecVoteSix_t* v) {
    GEN_DEF_READVECTOR(VoteSix)
}

parser_error_t _readVecVoteSixteen(parser_context_t* c, pd_VecVoteSixteen_t* v) {
    GEN_DEF_READVECTOR(VoteSixteen)
}

parser_error_t _readVecVoteTen(parser_context_t* c, pd_VecVoteTen_t* v) {
    GEN_DEF_READVECTOR(VoteTen)
}

parser_error_t _readVecVoteThirteen(parser_context_t* c, pd_VecVoteThirteen_t* v) {
    GEN_DEF_READVECTOR(VoteThirteen)
}

parser_error_t _readVecVoteThree(parser_context_t* c, pd_VecVoteThree_t* v) {
    GEN_DEF_READVECTOR(VoteThree)
}

parser_error_t _readVecVoteTwelve(parser_context_t* c, pd_VecVoteTwelve_t* v) {
    GEN_DEF_READVECTOR(VoteTwelve)
}

parser_error_t _readVecVoteTwo(parser_context_t* c, pd_VecVoteTwo_t* v) {
    GEN_DEF_READVECTOR(VoteTwo)
}

parser_error_t _readVecAccountId(parser_context_t* c, pd_VecAccountId_t* v) {
    GEN_DEF_READVECTOR(AccountId)
}

parser_error_t _readVecMotion(parser_context_t* c, pd_VecMotion_t* v) {
    GEN_DEF_READVECTOR(Motion)
}

parser_error_t _readVecNFTId(parser_context_t* c, pd_VecNFTId_t* v) {
    GEN_DEF_READVECTOR(NFTId)
}

parser_error_t _readVecTupleAccountId32SpNposElectionsSupport(parser_context_t* c, pd_VecTupleAccountId32SpNposElectionsSupport_t* v) {
    GEN_DEF_READVECTOR(TupleAccountId32SpNposElectionsSupport)
}

parser_error_t _readVecAccountIdLookupOfT(parser_context_t* c, pd_VecAccountIdLookupOfT_t* v) {
    GEN_DEF_READVECTOR(AccountIdLookupOfT)
}

parser_error_t _readVecBallotVote(parser_context_t* c, pd_VecBallotVote_t* v) {
    GEN_DEF_READVECTOR(BallotVote)
}

parser_error_t _readVecBeneficiary(parser_context_t* c, pd_VecBeneficiary_t* v) {
    GEN_DEF_READVECTOR(Beneficiary)
}

parser_error_t _readVecComplianceRequirement(parser_context_t* c, pd_VecComplianceRequirement_t* v) {
    GEN_DEF_READVECTOR(ComplianceRequirement)
}

parser_error_t _readVecCreateChildIdentityWithAuthAccountId(parser_context_t* c, pd_VecCreateChildIdentityWithAuthAccountId_t* v) {
    GEN_DEF_READVECTOR(CreateChildIdentityWithAuthAccountId)
}

parser_error_t _readVecDocument(parser_context_t* c, pd_VecDocument_t* v) {
    GEN_DEF_READVECTOR(Document)
}

parser_error_t _readVecFund(parser_context_t* c, pd_VecFund_t* v) {
    GEN_DEF_READVECTOR(Fund)
}

parser_error_t _readVecLeg(parser_context_t* c, pd_VecLeg_t* v) {
    GEN_DEF_READVECTOR(Leg)
}

parser_error_t _readVecNFTMetadataAttribute(parser_context_t* c, pd_VecNFTMetadataAttribute_t* v) {
    GEN_DEF_READVECTOR(NFTMetadataAttribute)
}

parser_error_t _readVecPriceTier(parser_context_t* c, pd_VecPriceTier_t* v) {
    GEN_DEF_READVECTOR(PriceTier)
}

parser_error_t _readVecReceiptDetails(parser_context_t* c, pd_VecReceiptDetails_t* v) {
    GEN_DEF_READVECTOR(ReceiptDetails)
}

parser_error_t _readVecSecondaryKeyAccountId(parser_context_t* c, pd_VecSecondaryKeyAccountId_t* v) {
    GEN_DEF_READVECTOR(SecondaryKeyAccountId)
}

parser_error_t _readVecSecondaryKeyWithAuthAccountId(parser_context_t* c, pd_VecSecondaryKeyWithAuthAccountId_t* v) {
    GEN_DEF_READVECTOR(SecondaryKeyWithAuthAccountId)
}

parser_error_t _readVecTupleExtrinsicIdbool(parser_context_t* c, pd_VecTupleExtrinsicIdbool_t* v) {
    GEN_DEF_READVECTOR(TupleExtrinsicIdbool)
}

parser_error_t _readVecTuplePipIdSnapshotResult(parser_context_t* c, pd_VecTuplePipIdSnapshotResult_t* v) {
    GEN_DEF_READVECTOR(TuplePipIdSnapshotResult)
}

parser_error_t _readVecAssetIdentifier(parser_context_t* c, pd_VecAssetIdentifier_t* v) {
    GEN_DEF_READVECTOR(AssetIdentifier)
}

parser_error_t _readVecAssetMetadataKey(parser_context_t* c, pd_VecAssetMetadataKey_t* v) {
    GEN_DEF_READVECTOR(AssetMetadataKey)
}

parser_error_t _readVecDocumentId(parser_context_t* c, pd_VecDocumentId_t* v) {
    GEN_DEF_READVECTOR(DocumentId)
}

parser_error_t _readVecVenueId(parser_context_t* c, pd_VecVenueId_t* v) {
    GEN_DEF_READVECTOR(VenueId)
}

parser_error_t _readVecu32(parser_context_t* c, pd_Vecu32_t* v) {
    GEN_DEF_READVECTOR(u32)
}

parser_error_t _readVecu8(parser_context_t* c, pd_Vecu8_t* v) {
    GEN_DEF_READVECTOR(u8)
}

parser_error_t _readOptionScope(parser_context_t* c, pd_OptionScope_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readScope(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMemo(parser_context_t* c, pd_OptionMemo_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMemo(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionDocumentType(parser_context_t* c, pd_OptionDocumentType_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readDocumentType(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionMoment(parser_context_t* c, pd_OptionMoment_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readMoment(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReceiptMetadata(parser_context_t* c, pd_OptionReceiptMetadata_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReceiptMetadata(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu16(parser_context_t* c, pd_Optionu16_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu16(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBytes(parser_context_t* c, pd_OptionBytes_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBytes(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPermill(parser_context_t* c, pd_OptionPermill_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPermill(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionRecordDateSpec(parser_context_t* c, pd_OptionRecordDateSpec_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readRecordDateSpec(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTargetIdentities(parser_context_t* c, pd_OptionTargetIdentities_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTargetIdentities(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVecTupleIdentityIdTax(parser_context_t* c, pd_OptionVecTupleIdentityIdTax_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVecTupleIdentityIdTax(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionAffirmationCount(parser_context_t* c, pd_OptionAffirmationCount_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAffirmationCount(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionAssetMetadataValueDetailMoment(parser_context_t* c, pd_OptionAssetMetadataValueDetailMoment_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAssetMetadataValueDetailMoment(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionElectionScore(parser_context_t* c, pd_OptionElectionScore_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readElectionScore(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPermissions(parser_context_t* c, pd_OptionPermissions_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPermissions(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPortfolioId(parser_context_t* c, pd_OptionPortfolioId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPortfolioId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionReceiptDetails(parser_context_t* c, pd_OptionReceiptDetails_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readReceiptDetails(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionTax(parser_context_t* c, pd_OptionTax_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readTax(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionWeight(parser_context_t* c, pd_OptionWeight_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readWeight(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionAssetCount(parser_context_t* c, pd_OptionAssetCount_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readAssetCount(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBalance(parser_context_t* c, pd_OptionBalance_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBalance(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionBlockNumber(parser_context_t* c, pd_OptionBlockNumber_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readBlockNumber(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionCompactBalanceOf(parser_context_t* c, pd_OptionCompactBalanceOf_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readCompactBalanceOf(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionFundingRoundName(parser_context_t* c, pd_OptionFundingRoundName_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readFundingRoundName(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionNonFungibleType(parser_context_t* c, pd_OptionNonFungibleType_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readNonFungibleType(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPipDescription(parser_context_t* c, pd_OptionPipDescription_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPipDescription(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionPortfolioNumber(parser_context_t* c, pd_OptionPortfolioNumber_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readPortfolioNumber(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionUrl(parser_context_t* c, pd_OptionUrl_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readUrl(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionVenueId(parser_context_t* c, pd_OptionVenueId_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readVenueId(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu32(parser_context_t* c, pd_Optionu32_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu32(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu64(parser_context_t* c, pd_Optionu64_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu64(c, &v->contained))
    }
    return parser_ok;
}

parser_error_t _readOptionu8(parser_context_t* c, pd_Optionu8_t* v)
{
    CHECK_INPUT()
    CHECK_ERROR(_readUInt8(c, &v->some))
    if (v->some > 0) {
        CHECK_ERROR(_readu8(c, &v->contained))
    }
    return parser_ok;
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
    UNUSED(pageIdx);

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

parser_error_t _toStringu8(
    const pd_u8_t* v,
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
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCompactu64(
    const pd_Compactu64_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

parser_error_t _toStringCompactu16(
    const pd_Compactu16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(v, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetId(
    const pd_AssetId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }

    return parser_ok;
}

parser_error_t _toStringIdentityId(
    const pd_IdentityId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
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
        _toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, pageCount);
        break;
    case 2:
        GEN_DEF_TOSTRING_ARRAY(v->_len)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringCddId(
    const pd_CddId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringClaimType(
    const pd_ClaimType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);
    *pageCount = 1;
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
    case 4: // CustomerDueDiligence
        snprintf(outValue, outValueLen, "CustomerDueDiligence");
        break;
    case 5: // KnowYourCustomer
        snprintf(outValue, outValueLen, "KnowYourCustomer");
        break;
    case 6: // Jurisdiction
        snprintf(outValue, outValueLen, "Jurisdiction");
        break;
    case 7: // Exempted
        snprintf(outValue, outValueLen, "Exempted");
        break;
    case 8: // Blocked
        snprintf(outValue, outValueLen, "Blocked");
        break;
    case 9: // InvestorUniqueness
        snprintf(outValue, outValueLen, "InvestorUniqueness");
        break;
    case 10: // NoData
        snprintf(outValue, outValueLen, "NoData");
        break;
    case 11: // InvestorUniquenessV2
        snprintf(outValue, outValueLen, "InvestorUniquenessV2");
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringCountryCode(
    const pd_CountryCode_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);
    if (v->value > COUNTRY_CODES_SIZE - 1) {
        return parser_value_out_of_range;
    }
    snprintf(outValue, outValueLen, "%s", (char*)PIC(STR_COUNTRY_CODES[v->value]));
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
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringScopeId(
    const pd_ScopeId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
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

parser_error_t _toStringTupleCountryCodeScope(
    const pd_TupleCountryCodeScope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCountryCode(&v->country_code, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCountryCode(&v->country_code, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &pages[1]))
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

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringScopeId(&v->scopeId, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCddId(&v->cddId, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringScopeId(&v->scopeId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCddId(&v->cddId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleU32Scope(
    const pd_TupleU32Scope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu32(&v->u32, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionScope(&v->scope, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->u32, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionScope(&v->scope, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
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

parser_error_t _toStringBalanceNoSymbol(
    const pd_BalanceNoSymbol_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    char bufferUI[200];
    memset(outValue, 0, outValueLen);
    memset(bufferUI, 0, sizeof(bufferUI));
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

    number_inplace_trimming(bufferUI, 1);

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
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
    *pageCount = 0;
    uint8_t _dummy;

    // Count the total pages (pageCount) first (Printing the enum name adds 1 page).
    // If pageIdx == 0, prints enum name, else prints value.

    switch (v->value) {
    case 0: // Accredited
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Accredited");
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 1: // Affiliate
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Affiliate");
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 2: // BuyLockup
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("BuyLockup");
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 3: // SellLockup
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("SellLockup");
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 4: // CustomerDueDiligence
        CHECK_ERROR(_toStringCddId(&v->cddId, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("CustomerDueDiligence");
        CHECK_ERROR(_toStringCddId(&v->cddId, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 5: // KnowYourCustomer
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("KnowYourCustomer");
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 6: // Jurisdiction
        CHECK_ERROR(_toStringTupleCountryCodeScope(&v->jurisdiction, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Jurisdiction");
        CHECK_ERROR(_toStringTupleCountryCodeScope(&v->jurisdiction, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 7: // Exempted
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Exempted");
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 8: // Blocked
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Blocked");
        CHECK_ERROR(_toStringScope(&v->scope, outValue, outValueLen, pageIdx, &_dummy));
        break;
    case 9: // Custom
        CHECK_ERROR(_toStringTupleU32Scope(&v->custom, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Custom");
        CHECK_ERROR(_toStringTupleU32Scope(&v->custom, outValue, outValueLen, pageIdx, &_dummy));
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringDispatchableNames(
    const pd_DispatchableNames_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
    uint8_t _dummy;

    switch (v->value) {
    case 0: // Whole
        GEN_DEF_TOSTRING_ENUM("Whole")
        break;
    case 1: // These
        CHECK_ERROR(_toStringVecDispatchableName(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("These")
        CHECK_ERROR(_toStringVecDispatchableName(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 2: // Except
        CHECK_ERROR(_toStringVecDispatchableName(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("Except")
        CHECK_ERROR(_toStringVecDispatchableName(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringPalletName(
    const pd_PalletName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringPortfolioKind(
    const pd_PortfolioKind_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
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

parser_error_t _toStringPalletPermissions(
    const pd_PalletPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringPalletName(&v->palletName, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringDispatchableNames(&v->dispatchableNames, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPalletName(&v->palletName, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringDispatchableNames(&v->dispatchableNames, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
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

parser_error_t _toStringPortfolioId(
    const pd_PortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringIdentityId(&v->did, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioKind(&v->kind, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->did, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioKind(&v->kind, outValue, outValueLen, pageIdx, &pages[1]))
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
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "ExternalAgent");
        break;
    case 1:
        _toStringIdentityId(&v->specific, outValue, outValueLen, pageIdx, pageCount);
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

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringIdentityId(&v->issuer, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTrustedFor(&v->trustedFor, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->issuer, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTrustedFor(&v->trustedFor, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleAccountId32u128(
    const pd_TupleAccountId32u128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceNoSymbol(&v->value, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceNoSymbol(&v->value, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringChoiceTitle(
    const pd_ChoiceTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
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

parser_error_t _toStringEcdsaSignature(
    const pd_EcdsaSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(65)
}

parser_error_t _toStringEd25519Signature(
    const pd_Ed25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringMemo(
    const pd_Memo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (formatBufferData(v->_ptr, v->_len, outValue, outValueLen, pageIdx, pageCount) != zxerr_ok) {
        return parser_print_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringSr25519Signature(
    const pd_Sr25519Signature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
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

parser_error_t _toStringTupleCompactu16Compactu16(
    const pd_TupleCompactu16Compactu16_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu16(&v->firstElemInTuple, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu16(&v->secondElemInTuple, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu16(&v->firstElemInTuple, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu16(&v->secondElemInTuple, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetPermissions(
    const pd_AssetPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
    uint8_t _dummy;

    switch (v->value) {
    case 0: // Whole
        GEN_DEF_TOSTRING_ENUM("Whole")
        break;
    case 1: // These
        CHECK_ERROR(_toStringVecAssetId(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("These")
        CHECK_ERROR(_toStringVecAssetId(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 2: // Except
        CHECK_ERROR(_toStringVecAssetId(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("Except")
        CHECK_ERROR(_toStringVecAssetId(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
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

parser_error_t _toStringCondition(
    const pd_Condition_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2];
    CHECK_ERROR(_toStringConditionType(&v->conditionType, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecTrustedIssuer(&v->issuers, outValue, outValueLen, 0, &pages[1]))

    if (v->issuers._len == 0) {
        pages[1] = 0;
    }

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringConditionType(&v->conditionType, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecTrustedIssuer(&v->issuers, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringDocumentType(
    const pd_DocumentType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringExtrinsicPermissions(
    const pd_ExtrinsicPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
    uint8_t _dummy;

    switch (v->value) {
    case 0: // Whole
        GEN_DEF_TOSTRING_ENUM("Whole")
        break;
    case 1: // These
        CHECK_ERROR(_toStringVecPalletPermissions(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("These")
        CHECK_ERROR(_toStringVecPalletPermissions(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 2: // Except
        CHECK_ERROR(_toStringVecPalletPermissions(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("Except")
        CHECK_ERROR(_toStringVecPalletPermissions(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
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
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringMotionTitle(
    const pd_MotionTitle_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringMultiSignature(
    const pd_MultiSignature_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Ed25519
        CHECK_ERROR(_toStringEd25519Signature(&v->ed25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Sr25519
        CHECK_ERROR(_toStringSr25519Signature(&v->sr25519, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Ecdsa
        CHECK_ERROR(_toStringEcdsaSignature(&v->ecdsa, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringPortfolioPermissions(
    const pd_PortfolioPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
    uint8_t _dummy;

    switch (v->value) {
    case 0: // Whole
        GEN_DEF_TOSTRING_ENUM("Whole")
        break;
    case 1: // These
        CHECK_ERROR(_toStringVecPortfolioId(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("These")
        CHECK_ERROR(_toStringVecPortfolioId(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 2: // Except
        CHECK_ERROR(_toStringVecPortfolioId(&v->contained, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("Except")
        CHECK_ERROR(_toStringVecPortfolioId(&v->contained, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringReceiptMetadata(
    const pd_ReceiptMetadata_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
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

parser_error_t _toStringSpNposElectionsSupport(
    const pd_SpNposElectionsSupport_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBalanceNoSymbol(&v->total, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecTupleAccountId32u128(&v->voters, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalanceNoSymbol(&v->total, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecTupleAccountId32u128(&v->voters, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTargetTreatment(
    const pd_TargetTreatment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);
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

parser_error_t _toStringTicker(
    const pd_Ticker_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringTupleIdentityIdTax(
    const pd_TupleIdentityIdTax_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringIdentityId(&v->id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTax(&v->tax, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTax(&v->tax, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteEight(
    const pd_VoteEight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[9] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringCompactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringCompactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteEleven(
    const pd_VoteEleven_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[12] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, 0, &pages[10]))
    CHECK_ERROR(_toStringCompactu16(&v->twelfthElem, outValue, outValueLen, 0, &pages[11]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }
    pageIdx -= pages[10];

    if (pageIdx < pages[11]) {
        CHECK_ERROR(_toStringCompactu16(&v->twelfthElem, outValue, outValueLen, pageIdx, &pages[11]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteFifteen(
    const pd_VoteFifteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[16] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, 0, &pages[10]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, 0, &pages[11]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, 0, &pages[12]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourteenthElem, outValue, outValueLen, 0, &pages[13]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifteenthElem, outValue, outValueLen, 0, &pages[14]))
    CHECK_ERROR(_toStringCompactu16(&v->sixteenthElem, outValue, outValueLen, 0, &pages[15]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }
    pageIdx -= pages[10];

    if (pageIdx < pages[11]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, pageIdx, &pages[11]))
        return parser_ok;
    }
    pageIdx -= pages[11];

    if (pageIdx < pages[12]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, pageIdx, &pages[12]))
        return parser_ok;
    }
    pageIdx -= pages[12];

    if (pageIdx < pages[13]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourteenthElem, outValue, outValueLen, pageIdx, &pages[13]))
        return parser_ok;
    }
    pageIdx -= pages[13];

    if (pageIdx < pages[14]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifteenthElem, outValue, outValueLen, pageIdx, &pages[14]))
        return parser_ok;
    }
    pageIdx -= pages[14];

    if (pageIdx < pages[15]) {
        CHECK_ERROR(_toStringCompactu16(&v->sixteenthElem, outValue, outValueLen, pageIdx, &pages[15]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteFive(
    const pd_VoteFive_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringCompactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringCompactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteFour(
    const pd_VoteFour_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringCompactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringCompactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteFourteen(
    const pd_VoteFourteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[15] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, 0, &pages[10]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, 0, &pages[11]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, 0, &pages[12]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourteenthElem, outValue, outValueLen, 0, &pages[13]))
    CHECK_ERROR(_toStringCompactu16(&v->fifteenthElem, outValue, outValueLen, 0, &pages[14]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }
    pageIdx -= pages[10];

    if (pageIdx < pages[11]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, pageIdx, &pages[11]))
        return parser_ok;
    }
    pageIdx -= pages[11];

    if (pageIdx < pages[12]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, pageIdx, &pages[12]))
        return parser_ok;
    }
    pageIdx -= pages[12];

    if (pageIdx < pages[13]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourteenthElem, outValue, outValueLen, pageIdx, &pages[13]))
        return parser_ok;
    }
    pageIdx -= pages[13];

    if (pageIdx < pages[14]) {
        CHECK_ERROR(_toStringCompactu16(&v->fifteenthElem, outValue, outValueLen, pageIdx, &pages[14]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteNine(
    const pd_VoteNine_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[10] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringCompactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringCompactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteOne(
    const pd_VoteOne_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteSeven(
    const pd_VoteSeven_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringCompactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringCompactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteSix(
    const pd_VoteSix_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[7] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringCompactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringCompactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteSixteen(
    const pd_VoteSixteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[17] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, 0, &pages[10]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, 0, &pages[11]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, 0, &pages[12]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourteenthElem, outValue, outValueLen, 0, &pages[13]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifteenthElem, outValue, outValueLen, 0, &pages[14]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixteenthElem, outValue, outValueLen, 0, &pages[15]))
    CHECK_ERROR(_toStringCompactu16(&v->seventeenthElem, outValue, outValueLen, 0, &pages[16]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }
    pageIdx -= pages[10];

    if (pageIdx < pages[11]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, pageIdx, &pages[11]))
        return parser_ok;
    }
    pageIdx -= pages[11];

    if (pageIdx < pages[12]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, pageIdx, &pages[12]))
        return parser_ok;
    }
    pageIdx -= pages[12];

    if (pageIdx < pages[13]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourteenthElem, outValue, outValueLen, pageIdx, &pages[13]))
        return parser_ok;
    }
    pageIdx -= pages[13];

    if (pageIdx < pages[14]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifteenthElem, outValue, outValueLen, pageIdx, &pages[14]))
        return parser_ok;
    }
    pageIdx -= pages[14];

    if (pageIdx < pages[15]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixteenthElem, outValue, outValueLen, pageIdx, &pages[15]))
        return parser_ok;
    }
    pageIdx -= pages[15];

    if (pageIdx < pages[16]) {
        CHECK_ERROR(_toStringCompactu16(&v->seventeenthElem, outValue, outValueLen, pageIdx, &pages[16]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteTen(
    const pd_VoteTen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[11] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringCompactu16(&v->eleventhElem, outValue, outValueLen, 0, &pages[10]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringCompactu16(&v->eleventhElem, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteThirteen(
    const pd_VoteThirteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[14] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, 0, &pages[10]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, 0, &pages[11]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, 0, &pages[12]))
    CHECK_ERROR(_toStringCompactu16(&v->fourteenthElem, outValue, outValueLen, 0, &pages[13]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }
    pageIdx -= pages[10];

    if (pageIdx < pages[11]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, pageIdx, &pages[11]))
        return parser_ok;
    }
    pageIdx -= pages[11];

    if (pageIdx < pages[12]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirteenthElem, outValue, outValueLen, pageIdx, &pages[12]))
        return parser_ok;
    }
    pageIdx -= pages[12];

    if (pageIdx < pages[13]) {
        CHECK_ERROR(_toStringCompactu16(&v->fourteenthElem, outValue, outValueLen, pageIdx, &pages[13]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteThree(
    const pd_VoteThree_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringCompactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringCompactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteTwelve(
    const pd_VoteTwelve_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[13] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, 0, &pages[10]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, 0, &pages[11]))
    CHECK_ERROR(_toStringCompactu16(&v->thirteenthElem, outValue, outValueLen, 0, &pages[12]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fourthElem, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->fifthElem, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->sixthElem, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->seventhElem, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eighthElem, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->ninthElem, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->tenthElem, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->eleventhElem, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }
    pageIdx -= pages[10];

    if (pageIdx < pages[11]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->twelfthElem, outValue, outValueLen, pageIdx, &pages[11]))
        return parser_ok;
    }
    pageIdx -= pages[11];

    if (pageIdx < pages[12]) {
        CHECK_ERROR(_toStringCompactu16(&v->thirteenthElem, outValue, outValueLen, pageIdx, &pages[12]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringVoteTwo(
    const pd_VoteTwo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringCompactu16(&v->thirdElem, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->firstElem, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTupleCompactu16Compactu16(&v->secondElem, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringCompactu16(&v->thirdElem, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAgentGroup(
    const pd_AgentGroup_t* v,
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
    case 0: // Full
        GEN_DEF_TOSTRING_ENUM("Full")
        break;
    case 1: // Custom
        CHECK_ERROR(_toStringu32(&v->custom, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("Custom")
        CHECK_ERROR(_toStringu32(&v->custom, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 2: // ExceptMeta
        GEN_DEF_TOSTRING_ENUM("ExceptMeta")
        break;
    case 3: // PolymeshV1CAA
        GEN_DEF_TOSTRING_ENUM("PolymeshV1CAA")
        break;
    case 4: // PolymeshV1PIA
        GEN_DEF_TOSTRING_ENUM("PolymeshV1PIA")
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringAssetCount(
    const pd_AssetCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringu32(&v->fungible, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->nonFungible, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->offChain, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->fungible, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->nonFungible, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->offChain, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetMetadataKey(
    const pd_AssetMetadataKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->value < 2) {
        CHECK_ERROR(_toStringu64(&v->key, outValue, outValueLen, pageIdx, pageCount))
        return parser_ok;
    }
    return parser_unexpected_value;
}

parser_error_t _toStringAssetMetadataLockStatusMoment(
    const pd_AssetMetadataLockStatusMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Unlocked");
        break;
    case 1:
        snprintf(outValue, outValueLen, "Locked");
        break;
    case 2:
        CHECK_ERROR(_toStringMoment(&v->moment, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
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
    memset(outValue, 0, outValueLen);
    memset(bufferUI, 0, sizeof(bufferUI));
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

    number_inplace_trimming(bufferUI, 1);
    number_inplace_trimming(bufferUI, 1);
    if (z_str3join(bufferUI, sizeof(bufferUI), COIN_TICKER, "") != zxerr_ok) {
        return parser_print_not_supported;
    }

    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
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

parser_error_t _toStringCompactAccountIndex(
    const pd_CompactAccountIndex_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCompactInt(&v->value, 0, false, "", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringDocumentHash(
    const pd_DocumentHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(v->_len)
}

parser_error_t _toStringDocumentName(
    const pd_DocumentName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringDocumentUri(
    const pd_DocumentUri_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringFundFungible(
    const pd_FundFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalanceNoSymbol(&v->amount, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionMemo(&v->memo, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalanceNoSymbol(&v->amount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionMemo(&v->memo, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringFundNonFungible(
    const pd_FundNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecu64(&v->ids, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionMemo(&v->memo, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecu64(&v->ids, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionMemo(&v->memo, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringLegFungible(
    const pd_LegFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringPortfolioId(&v->sender, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioId(&v->receiver, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringBalanceNoSymbol(&v->amount, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPortfolioId(&v->sender, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioId(&v->receiver, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringBalanceNoSymbol(&v->amount, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringLegNonFungible(
    const pd_LegNonFungible_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringPortfolioId(&v->sender, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPortfolioId(&v->receiver, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringVecu64(&v->ids, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPortfolioId(&v->sender, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPortfolioId(&v->receiver, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringVecu64(&v->ids, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringLegOffChain(
    const pd_LegOffChain_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[4] = { 0 };
    CHECK_ERROR(_toStringIdentityId(&v->sender, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringIdentityId(&v->receiver, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringBalanceNoSymbol(&v->amount, outValue, outValueLen, 0, &pages[3]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->sender, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringIdentityId(&v->receiver, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringBalanceNoSymbol(&v->amount, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringMotion(
    const pd_Motion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringMotionTitle(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMotionInfoLink(&v->info_link, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecChoiceTitle(&v->choices, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMotionTitle(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMotionInfoLink(&v->info_link, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecChoiceTitle(&v->choices, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNFTId(
    const pd_NFTId_t* v,
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
    CHECK_ERROR(_toStringMultiSignature(&v->value, outValue, outValueLen, pageIdx, pageCount));
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

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringAssetPermissions(&v->asset, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringExtrinsicPermissions(&v->extrinsic, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringPortfolioPermissions(&v->portfolio, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetPermissions(&v->asset, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringExtrinsicPermissions(&v->extrinsic, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringPortfolioPermissions(&v->portfolio, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
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
    case 1: // ExistingSchedule
        CHECK_ERROR(_toStringScheduleId(&v->existingSchedule, outValue, outValueLen, pageIdx, pageCount));
        break;
    case 2: // Existing
        CHECK_ERROR(_toStringCheckpointId(&v->existing, outValue, outValueLen, pageIdx, pageCount));
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
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(64)
}

parser_error_t _toStringSnapshotResult(
    const pd_SnapshotResult_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);
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

parser_error_t _toStringTargetIdentities(
    const pd_TargetIdentities_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringTargetTreatment(&v->treatment, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringTargetTreatment(&v->treatment, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringTupleAccountId32SpNposElectionsSupport(
    const pd_TupleAccountId32SpNposElectionsSupport_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSpNposElectionsSupport(&v->support, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSpNposElectionsSupport(&v->support, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringu8_array_32(
    const pd_u8_array_32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringAccountIdLookupOfT(
    const pd_AccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringAddRelayerPayingKey(
    const pd_AddRelayerPayingKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->accountId_1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAccountId(&v->accountId_2, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->accountId_1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAccountId(&v->accountId_2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAffirmationCount(
    const pd_AffirmationCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringAssetCount(&v->senderAssetCount, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetCount(&v->receiverAssetCount, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->offChainCount, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetCount(&v->senderAssetCount, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetCount(&v->receiverAssetCount, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->offChainCount, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringApiCodeHash(
    const pd_ApiCodeHash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringu8_array_32(&v->hash, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8_array_32(&v->hash, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetIdentifier(
    const pd_AssetIdentifier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringAssetMetadataValueDetailMoment(
    const pd_AssetMetadataValueDetailMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringOptionMoment(&v->expire, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAssetMetadataLockStatusMoment(&v->lockStatus, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionMoment(&v->expire, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAssetMetadataLockStatusMoment(&v->lockStatus, outValue, outValueLen, pageIdx, &pages[1]))
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
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
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

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBalance(&v->power, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionu16(&v->fallback, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalance(&v->power, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionu16(&v->fallback, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBecomeAgent(
    const pd_BecomeAgent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringAgentGroup(&v->agentGroup, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringAgentGroup(&v->agentGroup, outValue, outValueLen, pageIdx, &pages[1]))
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

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringIdentityId(&v->identity, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringIdentityId(&v->identity, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->balance, outValue, outValueLen, pageIdx, &pages[1]))
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
    UNUSED(pageIdx);
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

parser_error_t _toStringCall(
    const pd_Call_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;

    parser_context_t ctx;

    const uint8_t* buffer;
    if (v->nestCallIdx.isTail) {
        buffer = v->nestCallIdx._ptr;
    } else {
        buffer = v->nestCallIdx._nextPtr;
    }

    parser_init(&ctx, buffer, v->nestCallIdx._lenBuffer);
    parser_tx_t _txObj;

    pd_Call_t _call;
    _call.nestCallIdx.isTail = false;

    ctx.tx_obj = &_txObj;
    _txObj.transactionVersion = *v->_txVerPtr;

    ctx.tx_obj->nestCallIdx._ptr = NULL;
    ctx.tx_obj->nestCallIdx._nextPtr = NULL;
    ctx.tx_obj->nestCallIdx._lenBuffer = 0;
    ctx.tx_obj->nestCallIdx.slotIdx = 0;
    ctx.tx_obj->nestCallIdx.isTail = false;

    // Read the Call, so we get the contained Method
    parser_error_t err = _readCallImpl(&ctx, &_call, (pd_MethodNested_t*)&_txObj.method);
    if (err != parser_ok) {
        return err;
    }

    // Get num items of this current Call
    uint8_t callNumItems = _getMethod_NumItems(*v->_txVerPtr, v->callIndex.moduleIdx, v->callIndex.idx);

    // Count how many pages this call has (including nested ones if they exists)
    for (uint8_t i = 0; i < callNumItems; i++) {
        uint8_t itemPages = 0;
        _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, _call.callIndex.moduleIdx, _call.callIndex.idx, i,
            outValue, outValueLen, 0, &itemPages);
        (*pageCount) += itemPages;
    }

    if (pageIdx == 0) {
        snprintf(outValue, outValueLen, "%s", _getMethod_Name(*v->_txVerPtr, v->callIndex.moduleIdx, v->callIndex.idx));
        return parser_ok;
    }

    pageIdx--;

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    for (uint8_t i = 0; i < callNumItems; i++) {
        uint8_t itemPages = 0;
        _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, v->callIndex.moduleIdx, v->callIndex.idx, i,
            outValue, outValueLen, 0, &itemPages);

        if (pageIdx < itemPages) {
            uint8_t tmp;
            _getMethod_ItemValue(*v->_txVerPtr, &_txObj.method, v->callIndex.moduleIdx, v->callIndex.idx, i,
                outValue, outValueLen, pageIdx, &tmp);
            return parser_ok;
        }

        pageIdx -= itemPages;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringChainVersion(
    const pd_ChainVersion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu32(&v->specVersion, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->txVersion, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->specVersion, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->txVersion, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCompactBalanceOf(
    const pd_CompactBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CHECK_ERROR(_toStringCompactInt(&v->value, COIN_AMOUNT_DECIMAL_PLACES, true, "", COIN_TICKER, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringCompactPerBill(
    const pd_CompactPerBill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    // 9 but shift 2 to show as percentage
    return _toStringCompactInt(&v->value, 7, false, "%", "", outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringComplianceRequirement(
    const pd_ComplianceRequirement_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringVecCondition(&v->senderConditions, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecCondition(&v->receiverConditions, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecCondition(&v->senderConditions, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecCondition(&v->receiverConditions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->id, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCreateChildIdentityWithAuthAccountId(
    const pd_CreateChildIdentityWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSignature(&v->authSignature, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSignature(&v->authSignature, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringCustomAssetTypeId(
    const pd_CustomAssetTypeId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
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

parser_error_t _toStringDocument(
    const pd_Document_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[5] = { 0 };
    CHECK_ERROR(_toStringDocumentUri(&v->uri, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringDocumentHash(&v->content_hash, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringDocumentName(&v->name, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionDocumentType(&v->doc_type, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOptionMoment(&v->filing_date, outValue, outValueLen, 0, &pages[4]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringDocumentUri(&v->uri, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringDocumentHash(&v->content_hash, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringDocumentName(&v->name, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionDocumentType(&v->doc_type, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOptionMoment(&v->filing_date, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringElectionScore(
    const pd_ElectionScore_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringBalance(&v->minimalStake, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->sumStake, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringBalance(&v->sumStakeSquared, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalance(&v->minimalStake, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->sumStake, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringBalance(&v->sumStakeSquared, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringFund(
    const pd_Fund_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Fungible
        CHECK_ERROR(_toStringFundFungible(&v->fungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // NonFungible
        CHECK_ERROR(_toStringFundNonFungible(&v->nonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringFundingRoundName(
    const pd_FundingRoundName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringHash(
    const pd_Hash_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(32)
}

parser_error_t _toStringLeg(
    const pd_Leg_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Fungible
        CHECK_ERROR(_toStringLegFungible(&v->fungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // NonFungible
        CHECK_ERROR(_toStringLegNonFungible(&v->nonFungible, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // OffChain
        CHECK_ERROR(_toStringLegOffChain(&v->offChain, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
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

parser_error_t _toStringNFTMetadataAttribute(
    const pd_NFTMetadataAttribute_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetMetadataKey(&v->key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetMetadataKey(&v->key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNonFungibleType(
    const pd_NonFungibleType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Derivative
        snprintf(outValue, outValueLen, "Derivative");
        break;
    case 1: // FixedIncome
        snprintf(outValue, outValueLen, "FixedIncome");
        break;
    case 2: // Invoice
        snprintf(outValue, outValueLen, "Invoice");
        break;
    case 3: { // Custom
        uint8_t _dummy;
        CHECK_ERROR(_toStringu32(&v->custom, outValue, outValueLen, 0, pageCount))
        GEN_DEF_TOSTRING_ENUM("Custom")
        CHECK_ERROR(_toStringu32(&v->custom, outValue, outValueLen, 0, &_dummy))
        break;
    }
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringPerbill(
    const pd_Perbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    char bufferUI[100] = { 0 };
    char ratioBuffer[80] = { 0 };
    memset(outValue, 0, outValueLen);
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
    char bufferUI[50];
    char bufferRatio[50];

    uint64_to_str(bufferRatio, sizeof(bufferRatio), v->value);

    snprintf(bufferUI, sizeof(bufferUI), "%s%%", bufferRatio);
    pageString(outValue, outValueLen, bufferUI, pageIdx, pageCount);
    return parser_ok;
}

parser_error_t _toStringPipDescription(
    const pd_PipDescription_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringPriceTier(
    const pd_PriceTier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBalance(&v->total, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringBalance(&v->price, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBalance(&v->total, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringBalance(&v->price, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringReceiptDetails(
    const pd_ReceiptDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[6] = { 0 };
    CHECK_ERROR(_toStringu64(&v->uid, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu64(&v->instructionId, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu64(&v->legId, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringAccountId(&v->signer, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringOffChainSignature(&v->signature, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringOptionReceiptMetadata(&v->metadata, outValue, outValueLen, 0, &pages[5]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu64(&v->uid, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu64(&v->instructionId, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu64(&v->legId, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringAccountId(&v->signer, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringOffChainSignature(&v->signature, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringOptionReceiptMetadata(&v->metadata, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSecondaryKeyAccountId(
    const pd_SecondaryKeyAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSecondaryKeyWithAuthAccountId(
    const pd_SecondaryKeyWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringAccountId(&v->key, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringSignature(&v->auth_signature, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAccountId(&v->key, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringSignature(&v->auth_signature, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSolution(
    const pd_Solution_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[16] = { 0 };
    CHECK_ERROR(_toStringVecVoteOne(&v->voteOne, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecVoteTwo(&v->voteTwo, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringVecVoteThree(&v->voteThree, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringVecVoteFour(&v->voteFour, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringVecVoteFive(&v->voteFive, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringVecVoteSix(&v->voteSix, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringVecVoteSeven(&v->voteSeven, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringVecVoteEight(&v->voteEight, outValue, outValueLen, 0, &pages[7]))
    CHECK_ERROR(_toStringVecVoteNine(&v->voteNine, outValue, outValueLen, 0, &pages[8]))
    CHECK_ERROR(_toStringVecVoteTen(&v->voteTen, outValue, outValueLen, 0, &pages[9]))
    CHECK_ERROR(_toStringVecVoteEleven(&v->voteEleven, outValue, outValueLen, 0, &pages[10]))
    CHECK_ERROR(_toStringVecVoteTwelve(&v->voteTwelve, outValue, outValueLen, 0, &pages[11]))
    CHECK_ERROR(_toStringVecVoteThirteen(&v->voteThirteen, outValue, outValueLen, 0, &pages[12]))
    CHECK_ERROR(_toStringVecVoteFourteen(&v->voteFourteen, outValue, outValueLen, 0, &pages[13]))
    CHECK_ERROR(_toStringVecVoteFifteen(&v->voteFifteen, outValue, outValueLen, 0, &pages[14]))
    CHECK_ERROR(_toStringVecVoteSixteen(&v->voteSixteen, outValue, outValueLen, 0, &pages[15]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecVoteOne(&v->voteOne, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecVoteTwo(&v->voteTwo, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringVecVoteThree(&v->voteThree, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringVecVoteFour(&v->voteFour, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringVecVoteFive(&v->voteFive, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringVecVoteSix(&v->voteSix, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringVecVoteSeven(&v->voteSeven, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringVecVoteEight(&v->voteEight, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }
    pageIdx -= pages[7];

    if (pageIdx < pages[8]) {
        CHECK_ERROR(_toStringVecVoteNine(&v->voteNine, outValue, outValueLen, pageIdx, &pages[8]))
        return parser_ok;
    }
    pageIdx -= pages[8];

    if (pageIdx < pages[9]) {
        CHECK_ERROR(_toStringVecVoteTen(&v->voteTen, outValue, outValueLen, pageIdx, &pages[9]))
        return parser_ok;
    }
    pageIdx -= pages[9];

    if (pageIdx < pages[10]) {
        CHECK_ERROR(_toStringVecVoteEleven(&v->voteEleven, outValue, outValueLen, pageIdx, &pages[10]))
        return parser_ok;
    }
    pageIdx -= pages[10];

    if (pageIdx < pages[11]) {
        CHECK_ERROR(_toStringVecVoteTwelve(&v->voteTwelve, outValue, outValueLen, pageIdx, &pages[11]))
        return parser_ok;
    }
    pageIdx -= pages[11];

    if (pageIdx < pages[12]) {
        CHECK_ERROR(_toStringVecVoteThirteen(&v->voteThirteen, outValue, outValueLen, pageIdx, &pages[12]))
        return parser_ok;
    }
    pageIdx -= pages[12];

    if (pageIdx < pages[13]) {
        CHECK_ERROR(_toStringVecVoteFourteen(&v->voteFourteen, outValue, outValueLen, pageIdx, &pages[13]))
        return parser_ok;
    }
    pageIdx -= pages[13];

    if (pageIdx < pages[14]) {
        CHECK_ERROR(_toStringVecVoteFifteen(&v->voteFifteen, outValue, outValueLen, pageIdx, &pages[14]))
        return parser_ok;
    }
    pageIdx -= pages[14];

    if (pageIdx < pages[15]) {
        CHECK_ERROR(_toStringVecVoteSixteen(&v->voteSixteen, outValue, outValueLen, pageIdx, &pages[15]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSystemOrigin(
    const pd_SystemOrigin_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // Root
        snprintf(outValue, outValueLen, "Root");
        break;
    case 1: // Signed
        CHECK_ERROR(_toStringAccountId(&v->_signed, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // None
        snprintf(outValue, outValueLen, "None");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringTupleExtrinsicIdbool(
    const pd_TupleExtrinsicIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringu8(&v->extrinsicId1, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8(&v->extrinsicId2, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringbool(&v->_bool, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu8(&v->extrinsicId1, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8(&v->extrinsicId2, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringbool(&v->_bool, outValue, outValueLen, pageIdx, &pages[2]))
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

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringPipId(&v->pip_id, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringSnapshotResult(&v->snapshot_result, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringPipId(&v->pip_id, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringSnapshotResult(&v->snapshot_result, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringUrl(
    const pd_Url_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringVenueId(
    const pd_VenueId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringWeight(
    const pd_Weight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu64(&v->refTime, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu64(&v->proofSize, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringu8_array_4(
    const pd_u8_array_4_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4)
}

parser_error_t _toStringApi(
    const pd_Api_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu32(&v->major, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu8_array_4(&v->desc, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->major, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu8_array_4(&v->desc, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetMetadataName(
    const pd_AssetMetadataName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringAssetMetadataSpec(
    const pd_AssetMetadataSpec_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringOptionBytes(&v->url, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringOptionBytes(&v->description, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringOptionBytes(&v->typeDef, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringOptionBytes(&v->url, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringOptionBytes(&v->description, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringOptionBytes(&v->typeDef, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringAssetMetadataValue(
    const pd_AssetMetadataValue_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringBytes(&v->value, outValue, outValueLen, pageIdx, pageCount))
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
    *pageCount = 0;
    uint8_t _dummy;
    switch (v->value) {
    case 0:
        GEN_DEF_TOSTRING_ENUM("EquityCommon");
        break;
    case 1:
        GEN_DEF_TOSTRING_ENUM("EquityPreferred");
        break;
    case 2:
        GEN_DEF_TOSTRING_ENUM("Commodity");
        break;
    case 3:
        GEN_DEF_TOSTRING_ENUM("FixedIncome");
        break;
    case 4:
        GEN_DEF_TOSTRING_ENUM("REIT");
        break;
    case 5:
        GEN_DEF_TOSTRING_ENUM("Fund");
        break;
    case 6:
        GEN_DEF_TOSTRING_ENUM("RevenueShareAgreement");
        break;
    case 7:
        GEN_DEF_TOSTRING_ENUM("StructuredProduct");
        break;
    case 8:
        GEN_DEF_TOSTRING_ENUM("Derivative");
        break;
    case 9:
        CHECK_ERROR(_toStringCustomAssetTypeId(&v->custom, outValue, outValueLen, 0, pageCount));
        GEN_DEF_TOSTRING_ENUM("Custom")
        CHECK_ERROR(_toStringCustomAssetTypeId(&v->custom, outValue, outValueLen, pageIdx, &_dummy))
        break;
    case 10:
        GEN_DEF_TOSTRING_ENUM("StableCoin");
        break;
    }

    return parser_ok;
}

parser_error_t _toStringAuthorizationDataAccountId(
    const pd_AuthorizationDataAccountId_t* v,
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
        CHECK_ERROR(_toStringIdentityId(&v->identityId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("AttestPrimaryKeyRotation")
        CHECK_ERROR(_toStringIdentityId(&v->identityId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 1: // RotatePrimaryKey
        GEN_DEF_TOSTRING_ENUM("RotatePrimaryKey")
        break;
    case 2: // TransferTicker
        CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferTicker")
        CHECK_ERROR(_toStringTicker(&v->ticker, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 3: // AddMultiSigSigner
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("AddMultiSigSigner")
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 4: // TransferAssetOwnership
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("TransferAssetOwnership")
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 5: // JoinIdentity
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("JoinIdentity")
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 6: // PortfolioCustody
        CHECK_ERROR(_toStringPortfolioId(&v->portfolioId, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("PortfolioCustody")
        CHECK_ERROR(_toStringPortfolioId(&v->portfolioId, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 7: // BecomeAgent
        CHECK_ERROR(_toStringBecomeAgent(&v->becomeAgent, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("BecomeAgent")
        CHECK_ERROR(_toStringBecomeAgent(&v->becomeAgent, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 8: // AddRelayerPayingKey
        CHECK_ERROR(_toStringAddRelayerPayingKey(&v->addRelayerPayingKey, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("AddRelayerPayingKey")
        CHECK_ERROR(_toStringAddRelayerPayingKey(&v->addRelayerPayingKey, outValue, outValueLen, pageIdx, &_dummy);)
        break;
    case 9: // RotatePrimaryKeyToSecondary
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, 0, pageCount);)
        GEN_DEF_TOSTRING_ENUM("RotatePrimaryKeyToSecondary")
        CHECK_ERROR(_toStringPermissions(&v->permissions, outValue, outValueLen, pageIdx, &_dummy);)
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
    return _toStringBalance(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringBallotMeta(
    const pd_BallotMeta_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringBallotTitle(&v->title, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecMotion(&v->motions, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringBallotTitle(&v->title, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

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

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringMoment(&v->start, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringMoment(&v->end, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringMoment(&v->start, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringMoment(&v->end, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBoundedBTreeSetIdentityIdMaxAssetMediators(
    const pd_BoundedBTreeSetIdentityIdMaxAssetMediators_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBoundedBTreeSetIdentityIdMaxInstructionMediators(
    const pd_BoundedBTreeSetIdentityIdMaxInstructionMediators_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecIdentityId(&v->identities, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBoundedVecAccountIdMaxSigners(
    const pd_BoundedVecAccountIdMaxSigners_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringVecAccountId(&v->contained, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecAccountId(&v->contained, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBoxPalletsOrigin(
    const pd_BoxPalletsOrigin_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0: // System
        CHECK_ERROR(_toStringSystemOrigin(&v->system, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 4: // Void
        snprintf(outValue, outValueLen, "Void");
        break;
    case 9: // PolymeshCommittee
        if (v->committee != 0)
            return parser_unexpected_value;
        GEN_DEF_TOSTRING_ENUM("PolymeshCommittee")
        snprintf(outValue, outValueLen, "Endorsed");
        break;
    case 11: // TechnicalCommittee
        if (v->committee != 0)
            return parser_unexpected_value;
        GEN_DEF_TOSTRING_ENUM("TechnicalCommittee")
        snprintf(outValue, outValueLen, "Endorsed");
        break;
    case 13: // UpgradeCommittee
        if (v->committee != 0)
            return parser_unexpected_value;
        GEN_DEF_TOSTRING_ENUM("UpgradeCommittee")
        snprintf(outValue, outValueLen, "Endorsed");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringBoxRawSolutionSolutionOfMinerConfig(
    const pd_BoxRawSolutionSolutionOfMinerConfig_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[3] = { 0 };
    CHECK_ERROR(_toStringSolution(&v->solution, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringElectionScore(&v->score, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu32(&v->round, outValue, outValueLen, 0, &pages[2]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringSolution(&v->solution, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringElectionScore(&v->score, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu32(&v->round, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringBoxTasConfigProposal(
    const pd_BoxTasConfigProposal_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringCAId(
    const pd_CAId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringLocalCAId(&v->local_id, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringLocalCAId(&v->local_id, outValue, outValueLen, pageIdx, &pages[1]))
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

parser_error_t _toStringConfigOpBalanceOfT(
    const pd_ConfigOpBalanceOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringBalance(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpPerbill(
    const pd_ConfigOpPerbill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringPerbill(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpPercent(
    const pd_ConfigOpPercent_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringPercent(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringInitiateCorporateActionArgs(
    const pd_InitiateCorporateActionArgs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[8] = { 0 };
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCAKind(&v->kind, outValue, outValueLen, 0, &pages[1]))
    CHECK_ERROR(_toStringu64(&v->declDate, outValue, outValueLen, 0, &pages[2]))
    CHECK_ERROR(_toStringOptionRecordDateSpec(&v->recordDate, outValue, outValueLen, 0, &pages[3]))
    CHECK_ERROR(_toStringBytes(&v->details, outValue, outValueLen, 0, &pages[4]))
    CHECK_ERROR(_toStringOptionTargetIdentities(&v->targets, outValue, outValueLen, 0, &pages[5]))
    CHECK_ERROR(_toStringOptionPermill(&v->defaultWithholdingTax, outValue, outValueLen, 0, &pages[6]))
    CHECK_ERROR(_toStringOptionVecTupleIdentityIdTax(&v->withholdingTax, outValue, outValueLen, 0, &pages[7]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCAKind(&v->kind, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }
    pageIdx -= pages[1];

    if (pageIdx < pages[2]) {
        CHECK_ERROR(_toStringu64(&v->declDate, outValue, outValueLen, pageIdx, &pages[2]))
        return parser_ok;
    }
    pageIdx -= pages[2];

    if (pageIdx < pages[3]) {
        CHECK_ERROR(_toStringOptionRecordDateSpec(&v->recordDate, outValue, outValueLen, pageIdx, &pages[3]))
        return parser_ok;
    }
    pageIdx -= pages[3];

    if (pageIdx < pages[4]) {
        CHECK_ERROR(_toStringBytes(&v->details, outValue, outValueLen, pageIdx, &pages[4]))
        return parser_ok;
    }
    pageIdx -= pages[4];

    if (pageIdx < pages[5]) {
        CHECK_ERROR(_toStringOptionTargetIdentities(&v->targets, outValue, outValueLen, pageIdx, &pages[5]))
        return parser_ok;
    }
    pageIdx -= pages[5];

    if (pageIdx < pages[6]) {
        CHECK_ERROR(_toStringOptionPermill(&v->defaultWithholdingTax, outValue, outValueLen, pageIdx, &pages[6]))
        return parser_ok;
    }
    pageIdx -= pages[6];

    if (pageIdx < pages[7]) {
        CHECK_ERROR(_toStringOptionVecTupleIdentityIdTax(&v->withholdingTax, outValue, outValueLen, pageIdx, &pages[7]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringLookupasStaticLookupSource(
    const pd_LookupasStaticLookupSource_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // Id
        CHECK_ERROR(_toStringAccountId(&v->id, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 1: // Index
        CHECK_ERROR(_toStringCompactAccountIndex(&v->index, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2: // Raw
        CHECK_ERROR(_toStringBytes(&v->raw, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 3: // Address32
    {
        GEN_DEF_TOSTRING_ARRAY(32)
    }
    case 4: // Address20
    {
        GEN_DEF_TOSTRING_ARRAY(20)
    }
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

parser_error_t _toStringMaybeBlockBlockNumber(
    const pd_MaybeBlockBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
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

parser_error_t _toStringNFTs(
    const pd_NFTs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringVecNFTId(&v->ids, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringVecNFTId(&v->ids, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringNextUpgradeT(
    const pd_NextUpgradeT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringChainVersion(&v->chainVersion, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringApiCodeHash(&v->apiHash, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringChainVersion(&v->chainVersion, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringApiCodeHash(&v->apiHash, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringProposal(
    const pd_Proposal_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringCall(&v->call, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringRewardDestination(
    const pd_RewardDestination_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 0;
    switch (v->value) {
    case 0:
        GEN_DEF_TOSTRING_ENUM("Staked")
        break;
    case 1:
        GEN_DEF_TOSTRING_ENUM("Stash")
        break;
    case 2:
        GEN_DEF_TOSTRING_ENUM("Controller")
        break;
    case 3:
        CHECK_ERROR(_toStringAccountId(&v->accountId, outValue, outValueLen, pageIdx, pageCount))
        break;
    default:
        return parser_print_not_supported;
    }
    return parser_ok;
}

parser_error_t _toStringScheduleCheckpoints(
    const pd_ScheduleCheckpoints_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    CHECK_ERROR(_toStringVecu64(&v->pending, outValue, outValueLen, pageIdx, pageCount))
    return parser_ok;
}

parser_error_t _toStringSettlementTypeBlockNumber(
    const pd_SettlementTypeBlockNumber_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    switch (v->value) {
    case 0: // SettleOnAffirmation
        snprintf(outValue, outValueLen, "SettleOnAffirmation");
        *pageCount = 1;
        break;
    case 1: // SettleOnBlock
    case 2: // SettleManual
        _toStringBlockNumber(&v->blockNumber, outValue, outValueLen, pageIdx, pageCount);
        break;
    default:
        return parser_unexpected_value;
    }

    return parser_ok;
}

parser_error_t _toStringSignatoryAccountId(
    const pd_SignatoryAccountId_t* v,
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

parser_error_t _toStringSolutionOrSnapshotSize(
    const pd_SolutionOrSnapshotSize_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringCompactu32(&v->voters, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCompactu32(&v->targets, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringCompactu32(&v->voters, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCompactu32(&v->targets, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringSupportsAccountId(
    const pd_SupportsAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[1] = { 0 };
    CHECK_ERROR(_toStringVecTupleAccountId32SpNposElectionsSupport(&v->tupleAccSupport, outValue, outValueLen, 0, &pages[0]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringVecTupleAccountId32SpNposElectionsSupport(&v->tupleAccSupport, outValue, outValueLen, pageIdx, &pages[0]))
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

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringCall(&v->call, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu64(&v->nonce, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringCall(&v->call, outValue, outValueLen, pageIdx, &pages[1]))
        return parser_ok;
    }

    return parser_display_idx_out_of_range;
}

parser_error_t _toStringValidatorPrefs(
    const pd_ValidatorPrefs_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    return _toStringCompactPerBill(&v->commission, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringVecCall(
    const pd_VecCall_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    /* count number of pages, then output specific */
    *pageCount = 0;
    uint8_t chunkPageCount;
    uint16_t currentPage, currentTotalPage = 0;
    /* We need to do it twice because there is no memory to keep intermediate results*/
    /* First count*/
    parser_context_t ctx;
    parser_init(&ctx, v->_ptr, v->_lenBuffer);
    parser_tx_t _txObj;
    pd_Call_t _call;
    ctx.tx_obj = &_txObj;
    _txObj.transactionVersion = v->callTxVersion;
    _call._txVerPtr = &v->callTxVersion;
    _call.nestCallIdx.isTail = true;

    ctx.tx_obj->nestCallIdx.slotIdx = 0;
    ctx.tx_obj->nestCallIdx._lenBuffer = 0;
    ctx.tx_obj->nestCallIdx._ptr = NULL;
    ctx.tx_obj->nestCallIdx._nextPtr = NULL;
    ctx.tx_obj->nestCallIdx.isTail = true;

    for (uint64_t i = 0; i < v->_len; i++) {
        ctx.tx_obj->nestCallIdx._ptr = NULL;
        ctx.tx_obj->nestCallIdx._nextPtr = NULL;
        ctx.tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCallImpl(&ctx, &_call, (pd_MethodNested_t*)&_txObj.method));
        CHECK_ERROR(_toStringCall(&_call, outValue, outValueLen, 0, &chunkPageCount));
        (*pageCount) += chunkPageCount;
    }

    /* Then iterate until we can print the corresponding chunk*/
    parser_init(&ctx, v->_ptr, v->_lenBuffer);
    for (uint64_t i = 0; i < v->_len; i++) {
        ctx.tx_obj->nestCallIdx._ptr = NULL;
        ctx.tx_obj->nestCallIdx._nextPtr = NULL;
        ctx.tx_obj->nestCallIdx.slotIdx = 0;
        CHECK_ERROR(_readCallImpl(&ctx, &_call, (pd_MethodNested_t*)&_txObj.method));
        chunkPageCount = 1;
        currentPage = 0;
        while (currentPage < chunkPageCount) {
            CHECK_ERROR(_toStringCall(&_call, outValue, outValueLen, currentPage, &chunkPageCount));
            if (currentTotalPage == pageIdx) {
                return parser_ok;
            }
            currentPage++;
            currentTotalPage++;
        }
    }

    return parser_print_not_supported;
}

parser_error_t _toStringAGId(
    const pd_AGId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu32(&v->value, outValue, outValueLen, pageIdx, pageCount);
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

parser_error_t _toStringAssetMetadataLocalKey(
    const pd_AssetMetadataLocalKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringAssetName(
    const pd_AssetName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringCADetails(
    const pd_CADetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringConfigOpu32(
    const pd_ConfigOpu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    *pageCount = 1;
    switch (v->value) {
    case 0:
        snprintf(outValue, outValueLen, "Noop");
        break;
    case 1:
        CHECK_ERROR(_toStringu32(&v->set, outValue, outValueLen, pageIdx, pageCount))
        break;
    case 2:
        snprintf(outValue, outValueLen, "Remove");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
}

parser_error_t _toStringDeterminism(
    const pd_Determinism_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    UNUSED(pageIdx);
    switch (v->value) {
    case 0: // Deterministic
        snprintf(outValue, outValueLen, "Deterministic");
        break;
    case 1: // AllowIndeterminism
        snprintf(outValue, outValueLen, "AllowIndeterminism");
        break;
    default:
        return parser_unexpected_value;
    }
    return parser_ok;
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

parser_error_t _toStringFundraiserId(
    const pd_FundraiserId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringFundraiserName(
    const pd_FundraiserName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringInstructionId(
    const pd_InstructionId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    return _toStringu64(&v->value, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringKeys(
    const pd_Keys_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount) {
    GEN_DEF_TOSTRING_ARRAY(4 * 32)
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

parser_error_t _toStringOptionAssetId(
    const pd_OptionAssetId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    if (v->some == 0) {
        snprintf(outValue, outValueLen, "None");
        return parser_ok;
    }
    return _toStringAssetId(&v->assetId, outValue, outValueLen, pageIdx, pageCount);
}

parser_error_t _toStringPortfolioName(
    const pd_PortfolioName_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
    return parser_ok;
}

parser_error_t _toStringPosRatio(
    const pd_PosRatio_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    // First measure number of pages
    uint8_t pages[2] = { 0 };
    CHECK_ERROR(_toStringu32(&v->numerator, outValue, outValueLen, 0, &pages[0]))
    CHECK_ERROR(_toStringu32(&v->denominator, outValue, outValueLen, 0, &pages[1]))

    *pageCount = 0;
    for (uint8_t i = 0; i < (uint8_t)sizeof(pages); i++) {
        *pageCount += pages[i];
    }

    if (pageIdx >= *pageCount) {
        return parser_display_idx_out_of_range;
    }

    if (pageIdx < pages[0]) {
        CHECK_ERROR(_toStringu32(&v->numerator, outValue, outValueLen, pageIdx, &pages[0]))
        return parser_ok;
    }
    pageIdx -= pages[0];

    if (pageIdx < pages[1]) {
        CHECK_ERROR(_toStringu32(&v->denominator, outValue, outValueLen, pageIdx, &pages[1]))
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
    UNUSED(pageIdx);
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

parser_error_t _toStringVenueDetails(
    const pd_VenueDetails_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()
    if (v->_len > UINT16_MAX) {
        return parser_value_out_of_range;
    }
    const uint16_t strLen = (uint16_t)v->_len;
    bool allPrintable = true;
    for (uint16_t i = 0; i < strLen; i++) {
        allPrintable &= IS_PRINTABLE(v->_ptr[i]);
    }
    if (allPrintable) {
        pageStringExt(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    } else {
        pageStringHex(outValue, outValueLen, (const char*)v->_ptr, strLen, pageIdx, pageCount);
    }
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
    UNUSED(pageIdx);
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

parser_error_t _toStringVecClaimType(
    const pd_VecClaimType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ClaimType);
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

parser_error_t _toStringVecClaim(
    const pd_VecClaim_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Claim);
}

parser_error_t _toStringVecAssetId(
    const pd_VecAssetID_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetId);
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

parser_error_t _toStringVecTrustedIssuer(
    const pd_VecTrustedIssuer_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TrustedIssuer);
}

parser_error_t _toStringVecTupleAccountId32u128(
    const pd_VecTupleAccountId32u128_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountId32u128);
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

parser_error_t _toStringVecIdentityId(
    const pd_VecIdentityId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(IdentityId);
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

parser_error_t _toStringVecCondition(
    const pd_VecCondition_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Condition);
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

parser_error_t _toStringVecVoteEight(
    const pd_VecVoteEight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteEight);
}

parser_error_t _toStringVecVoteEleven(
    const pd_VecVoteEleven_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteEleven);
}

parser_error_t _toStringVecVoteFifteen(
    const pd_VecVoteFifteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteFifteen);
}

parser_error_t _toStringVecVoteFive(
    const pd_VecVoteFive_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteFive);
}

parser_error_t _toStringVecVoteFour(
    const pd_VecVoteFour_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteFour);
}

parser_error_t _toStringVecVoteFourteen(
    const pd_VecVoteFourteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteFourteen);
}

parser_error_t _toStringVecVoteNine(
    const pd_VecVoteNine_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteNine);
}

parser_error_t _toStringVecVoteOne(
    const pd_VecVoteOne_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteOne);
}

parser_error_t _toStringVecVoteSeven(
    const pd_VecVoteSeven_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteSeven);
}

parser_error_t _toStringVecVoteSix(
    const pd_VecVoteSix_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteSix);
}

parser_error_t _toStringVecVoteSixteen(
    const pd_VecVoteSixteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteSixteen);
}

parser_error_t _toStringVecVoteTen(
    const pd_VecVoteTen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteTen);
}

parser_error_t _toStringVecVoteThirteen(
    const pd_VecVoteThirteen_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteThirteen);
}

parser_error_t _toStringVecVoteThree(
    const pd_VecVoteThree_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteThree);
}

parser_error_t _toStringVecVoteTwelve(
    const pd_VecVoteTwelve_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteTwelve);
}

parser_error_t _toStringVecVoteTwo(
    const pd_VecVoteTwo_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VoteTwo);
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

parser_error_t _toStringVecMotion(
    const pd_VecMotion_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Motion);
}

parser_error_t _toStringVecNFTId(
    const pd_VecNFTId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(NFTId);
}

parser_error_t _toStringVecTupleAccountId32SpNposElectionsSupport(
    const pd_VecTupleAccountId32SpNposElectionsSupport_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleAccountId32SpNposElectionsSupport);
}

parser_error_t _toStringVecAccountIdLookupOfT(
    const pd_VecAccountIdLookupOfT_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AccountIdLookupOfT);
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

parser_error_t _toStringVecComplianceRequirement(
    const pd_VecComplianceRequirement_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(ComplianceRequirement);
}

parser_error_t _toStringVecCreateChildIdentityWithAuthAccountId(
    const pd_VecCreateChildIdentityWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(CreateChildIdentityWithAuthAccountId);
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

parser_error_t _toStringVecFund(
    const pd_VecFund_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(Fund);
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

parser_error_t _toStringVecNFTMetadataAttribute(
    const pd_VecNFTMetadataAttribute_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(NFTMetadataAttribute);
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

parser_error_t _toStringVecSecondaryKeyAccountId(
    const pd_VecSecondaryKeyAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKeyAccountId);
}

parser_error_t _toStringVecSecondaryKeyWithAuthAccountId(
    const pd_VecSecondaryKeyWithAuthAccountId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(SecondaryKeyWithAuthAccountId);
}

parser_error_t _toStringVecTupleExtrinsicIdbool(
    const pd_VecTupleExtrinsicIdbool_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(TupleExtrinsicIdbool);
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

parser_error_t _toStringVecAssetIdentifier(
    const pd_VecAssetIdentifier_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetIdentifier);
}

parser_error_t _toStringVecAssetMetadataKey(
    const pd_VecAssetMetadataKey_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(AssetMetadataKey);
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

parser_error_t _toStringVecVenueId(
    const pd_VecVenueId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(VenueId);
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

parser_error_t _toStringVecu8(
    const pd_Vecu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    GEN_DEF_TOSTRING_VECTOR(u8);
}

parser_error_t _toStringOptionScope(
    const pd_OptionScope_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringScope(
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

parser_error_t _toStringOptionReceiptMetadata(
    const pd_OptionReceiptMetadata_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringReceiptMetadata(
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

parser_error_t _toStringOptionBytes(
    const pd_OptionBytes_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringBytes(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPermill(
    const pd_OptionPermill_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPermill(
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

parser_error_t _toStringOptionAffirmationCount(
    const pd_OptionAffirmationCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAffirmationCount(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionAssetMetadataValueDetailMoment(
    const pd_OptionAssetMetadataValueDetailMoment_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAssetMetadataValueDetailMoment(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionElectionScore(
    const pd_OptionElectionScore_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringElectionScore(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPermissions(
    const pd_OptionPermissions_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPermissions(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionPortfolioId(
    const pd_OptionPortfolioId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringPortfolioId(
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

parser_error_t _toStringOptionWeight(
    const pd_OptionWeight_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringWeight(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionAssetCount(
    const pd_OptionAssetCount_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringAssetCount(
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

parser_error_t _toStringOptionCompactBalanceOf(
    const pd_OptionCompactBalanceOf_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringCompactBalanceOf(
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

parser_error_t _toStringOptionNonFungibleType(
    const pd_OptionNonFungibleType_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringNonFungibleType(
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

parser_error_t _toStringOptionVenueId(
    const pd_OptionVenueId_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringVenueId(
            &v->contained,
            outValue, outValueLen,
            pageIdx, pageCount));
    } else {
        snprintf(outValue, outValueLen, "None");
    }
    return parser_ok;
}

parser_error_t _toStringOptionu32(
    const pd_Optionu32_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu32(
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

parser_error_t _toStringOptionu8(
    const pd_Optionu8_t* v,
    char* outValue,
    uint16_t outValueLen,
    uint8_t pageIdx,
    uint8_t* pageCount)
{
    CLEAN_AND_CHECK()

    *pageCount = 1;
    if (v->some > 0) {
        CHECK_ERROR(_toStringu8(
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
