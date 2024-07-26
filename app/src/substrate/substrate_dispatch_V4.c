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

#include "substrate_dispatch_V4.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>
#ifdef LEDGER_SPECIFIC
#include "bolos_target.h"
#endif

__Z_INLINE parser_error_t _readMethod_balances_transfer_V4(
    parser_context_t* c, pd_balances_transfer_V4_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_with_memo_V4(
    parser_context_t* c, pd_balances_transfer_with_memo_V4_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readOptionMemo(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_primary_key_V4(
    parser_context_t* c, pd_identity_accept_primary_key_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->rotation_auth_id))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_key_V4(
    parser_context_t* c, pd_identity_join_identity_as_key_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_key_V4(
    parser_context_t* c, pd_identity_leave_identity_as_key_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_claim_V4(
    parser_context_t* c, pd_identity_add_claim_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->target))
    CHECK_ERROR(_readClaim(c, &m->claim))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_claim_V4(
    parser_context_t* c, pd_identity_revoke_claim_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->target))
    CHECK_ERROR(_readClaim(c, &m->claim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_freeze_secondary_keys_V4(
    parser_context_t* c, pd_identity_freeze_secondary_keys_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_unfreeze_secondary_keys_V4(
    parser_context_t* c, pd_identity_unfreeze_secondary_keys_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_authorization_V4(
    parser_context_t* c, pd_identity_add_authorization_V4_t* m)
{
    CHECK_ERROR(_readSignatoryAccountId(c, &m->target))
    CHECK_ERROR(_readAuthorizationDataAccountId(c, &m->data))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_authorization_V4(
    parser_context_t* c, pd_identity_remove_authorization_V4_t* m)
{
    CHECK_ERROR(_readSignatoryAccountId(c, &m->target))
    CHECK_ERROR(_readu64(c, &m->auth_id))
    CHECK_ERROR(_readbool(c, &m->_auth_issuer_pays))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_secondary_keys_with_authorization_V4(
    parser_context_t* c, pd_identity_add_secondary_keys_with_authorization_V4_t* m)
{
    CHECK_ERROR(_readVecSecondaryKeyWithAuthAccountId(c, &m->additional_keys))
    CHECK_ERROR(_readMoment(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_secondary_keys_V4(
    parser_context_t* c, pd_identity_remove_secondary_keys_V4_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->keys_to_remove))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_multisig_V4(
    parser_context_t* c, pd_multisig_create_multisig_V4_t* m)
{
    CHECK_ERROR(_readVecSignatoryAccountId(c, &m->signers))
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_key_V4(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_key_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_key_V4(
    parser_context_t* c, pd_multisig_create_proposal_as_key_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_key_V4(
    parser_context_t* c, pd_multisig_approve_as_key_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_key_V4(
    parser_context_t* c, pd_multisig_reject_as_key_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_key_V4(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_key_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signer_V4(
    parser_context_t* c, pd_multisig_add_multisig_signer_V4_t* m)
{
    CHECK_ERROR(_readSignatoryAccountId(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signer_V4(
    parser_context_t* c, pd_multisig_remove_multisig_signer_V4_t* m)
{
    CHECK_ERROR(_readSignatoryAccountId(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signers_via_creator_V4(
    parser_context_t* c, pd_multisig_add_multisig_signers_via_creator_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readVecSignatoryAccountId(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signers_via_creator_V4(
    parser_context_t* c, pd_multisig_remove_multisig_signers_via_creator_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readVecSignatoryAccountId(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_change_sigs_required_V4(
    parser_context_t* c, pd_multisig_change_sigs_required_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_primary_V4(
    parser_context_t* c, pd_multisig_make_multisig_primary_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V4(
    parser_context_t* c, pd_staking_bond_V4_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->controller))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V4(
    parser_context_t* c, pd_staking_bond_extra_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V4(
    parser_context_t* c, pd_staking_unbond_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V4(
    parser_context_t* c, pd_staking_withdraw_unbonded_V4_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V4(
    parser_context_t* c, pd_staking_validate_V4_t* m)
{
    CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V4(
    parser_context_t* c, pd_staking_nominate_V4_t* m)
{
    CHECK_ERROR(_readVecAccountIdLookupOfT(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V4(
    parser_context_t* c, pd_staking_chill_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V4(
    parser_context_t* c, pd_staking_set_payee_V4_t* m)
{
    CHECK_ERROR(_readRewardDestination(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V4(
    parser_context_t* c, pd_staking_set_controller_V4_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V4(
    parser_context_t* c, pd_staking_rebond_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_propose_V4(
    parser_context_t* c, pd_pips_propose_V4_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readBalance(c, &m->deposit))
    CHECK_ERROR(_readOptionUrl(c, &m->url))
    CHECK_ERROR(_readOptionPipDescription(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_vote_V4(
    parser_context_t* c, pd_pips_vote_V4_t* m)
{
    CHECK_ERROR(_readPipId(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->aye_or_nay))
    CHECK_ERROR(_readBalance(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V4(
    parser_context_t* c, pd_utility_batch_V4_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_atomic_V4(
    parser_context_t* c, pd_utility_batch_atomic_V4_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_optimistic_V4(
    parser_context_t* c, pd_utility_batch_optimistic_V4_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
__Z_INLINE parser_error_t _readMethod_asset_add_mandatory_mediators_V4(
    parser_context_t* c, pd_asset_add_mandatory_mediators_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readBoundedBTreeSetIdentityIdMaxAssetMediators(c, &m->mediators))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_asset_remove_mandatory_mediators_V4(
    parser_context_t* c, pd_asset_remove_mandatory_mediators_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readBoundedBTreeSetIdentityIdMaxAssetMediators(c, &m->mediators))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_set_max_details_length_V4(
    parser_context_t* c, pd_corporateaction_set_max_details_length_V4_t* m)
{
    CHECK_ERROR(_readu32(c, &m->length))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_targets_V4(
    parser_context_t* c, pd_corporateaction_set_default_targets_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readTargetIdentities(c, &m->targets))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_withholding_tax_V4(
    parser_context_t* c, pd_corporateaction_set_default_withholding_tax_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readTax(c, &m->tax))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_set_did_withholding_tax_V4(
    parser_context_t* c, pd_corporateaction_set_did_withholding_tax_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readIdentityId(c, &m->taxed_did))
    CHECK_ERROR(_readOptionTax(c, &m->tax))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_initiate_corporate_action_V4(
    parser_context_t* c, pd_corporateaction_initiate_corporate_action_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readCAKind(c, &m->kind))
    CHECK_ERROR(_readMoment(c, &m->decl_date))
    CHECK_ERROR(_readOptionRecordDateSpec(c, &m->record_date))
    CHECK_ERROR(_readCADetails(c, &m->details))
    CHECK_ERROR(_readOptionTargetIdentities(c, &m->targets))
    CHECK_ERROR(_readOptionTax(c, &m->default_withholding_tax))
    CHECK_ERROR(_readOptionVecTupleIdentityIdTax(c, &m->withholding_tax))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_link_ca_doc_V4(
    parser_context_t* c, pd_corporateaction_link_ca_doc_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->id))
    CHECK_ERROR(_readVecDocumentId(c, &m->docs))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_remove_ca_V4(
    parser_context_t* c, pd_corporateaction_remove_ca_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_change_record_date_V4(
    parser_context_t* c, pd_corporateaction_change_record_date_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readOptionRecordDateSpec(c, &m->record_date))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateaction_initiate_corporate_action_and_distribute_V4(
    parser_context_t* c, pd_corporateaction_initiate_corporate_action_and_distribute_V4_t* m)
{
    CHECK_ERROR(_readInitiateCorporateActionArgs(c, &m->ca_args))
    CHECK_ERROR(_readOptionPortfolioNumber(c, &m->portfolio))
    CHECK_ERROR(_readTicker(c, &m->currency))
    CHECK_ERROR(_readBalance(c, &m->per_share))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readMoment(c, &m->payment_at))
    CHECK_ERROR(_readOptionMoment(c, &m->expires_at))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateballot_attach_ballot_V4(
    parser_context_t* c, pd_corporateballot_attach_ballot_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readBallotTimeRange(c, &m->range))
    CHECK_ERROR(_readBallotMeta(c, &m->meta))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateballot_vote_V4(
    parser_context_t* c, pd_corporateballot_vote_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readVecBallotVote(c, &m->votes))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateballot_change_end_V4(
    parser_context_t* c, pd_corporateballot_change_end_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readMoment(c, &m->end))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateballot_change_meta_V4(
    parser_context_t* c, pd_corporateballot_change_meta_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readBallotMeta(c, &m->meta))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateballot_change_rcv_V4(
    parser_context_t* c, pd_corporateballot_change_rcv_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_corporateballot_remove_ballot_V4(
    parser_context_t* c, pd_corporateballot_remove_ballot_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_pips_enact_snapshot_results_V4(
    parser_context_t* c, pd_pips_enact_snapshot_results_V4_t* m)
{
    CHECK_ERROR(_readVecTuplePipIdSnapshotResult(c, &m->results))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_portfolio_allow_identity_to_create_portfolios_V4(
    parser_context_t* c, pd_portfolio_allow_identity_to_create_portfolios_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->trusted_identity))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_portfolio_revoke_create_portfolios_permission_V4(
    parser_context_t* c, pd_portfolio_revoke_create_portfolios_permission_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->identity))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_portfolio_create_custody_portfolio_V4(
    parser_context_t* c, pd_portfolio_create_custody_portfolio_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->portfolio_owner_id))
    CHECK_ERROR(_readPortfolioName(c, &m->portfolio_name))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_affirm_with_receipts_with_count_V4(
    parser_context_t* c, pd_settlement_affirm_with_receipts_with_count_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readVecReceiptDetails(c, &m->receipt_details))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    CHECK_ERROR(_readOptionAffirmationCount(c, &m->number_of_assets))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_affirm_instruction_with_count_V4(
    parser_context_t* c, pd_settlement_affirm_instruction_with_count_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    CHECK_ERROR(_readOptionAffirmationCount(c, &m->number_of_assets))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_reject_instruction_with_count_V4(
    parser_context_t* c, pd_settlement_reject_instruction_with_count_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readPortfolioId(c, &m->portfolio))
    CHECK_ERROR(_readOptionAssetCount(c, &m->number_of_assets))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_withdraw_affirmation_with_count_V4(
    parser_context_t* c, pd_settlement_withdraw_affirmation_with_count_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    CHECK_ERROR(_readOptionAffirmationCount(c, &m->number_of_assets))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_add_instruction_with_mediators_V4(
    parser_context_t* c, pd_settlement_add_instruction_with_mediators_V4_t* m)
{
    CHECK_ERROR(_readVenueId(c, &m->venue_id))
    CHECK_ERROR(_readSettlementTypeBlockNumber(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment(c, &m->value_date))
    CHECK_ERROR(_readVecLeg(c, &m->legs))
    CHECK_ERROR(_readOptionMemo(c, &m->instruction_memo))
    CHECK_ERROR(_readBoundedBTreeSetIdentityIdMaxInstructionMediators(c, &m->mediators))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_add_and_affirm_with_mediators_V4(
    parser_context_t* c, pd_settlement_add_and_affirm_with_mediators_V4_t* m)
{
    CHECK_ERROR(_readVenueId(c, &m->venue_id))
    CHECK_ERROR(_readSettlementTypeBlockNumber(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment(c, &m->value_date))
    CHECK_ERROR(_readVecLeg(c, &m->legs))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    CHECK_ERROR(_readOptionMemo(c, &m->instruction_memo))
    CHECK_ERROR(_readBoundedBTreeSetIdentityIdMaxInstructionMediators(c, &m->mediators))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_affirm_instruction_as_mediator_V4(
    parser_context_t* c, pd_settlement_affirm_instruction_as_mediator_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->instruction_id))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_withdraw_affirmation_as_mediator_V4(
    parser_context_t* c, pd_settlement_withdraw_affirmation_as_mediator_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->instruction_id))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_settlement_reject_instruction_as_mediator_V4(
    parser_context_t* c, pd_settlement_reject_instruction_as_mediator_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->instruction_id))
    CHECK_ERROR(_readOptionAssetCount(c, &m->number_of_assets))
    return parser_ok;
}
__Z_INLINE parser_error_t _readMethod_nft_controller_transfer_V4(
    parser_context_t* c, pd_nft_controller_transfer_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readNFTs(c, &m->nfts))
    CHECK_ERROR(_readPortfolioId(c, &m->source_portfolio))
    CHECK_ERROR(_readPortfolioKind(c, &m->callers_portfolio_kind))
    return parser_ok;
}
#endif
__Z_INLINE parser_error_t _readMethod_system_remark_V4(
    parser_context_t* c, pd_system_remark_V4_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V4(
    parser_context_t* c, pd_system_set_heap_pages_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V4(
    parser_context_t* c, pd_system_set_code_V4_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V4(
    parser_context_t* c, pd_system_set_code_without_checks_V4_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_with_event_V4(
    parser_context_t* c, pd_system_remark_with_event_V4_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V4(
    parser_context_t* c, pd_timestamp_set_V4_t* m)
{
    CHECK_ERROR(_readCompactu64(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V4(
    parser_context_t* c, pd_indices_claim_V4_t* m)
{
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V4(
    parser_context_t* c, pd_indices_transfer_V4_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V4(
    parser_context_t* c, pd_indices_free_V4_t* m)
{
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V4(
    parser_context_t* c, pd_indices_force_transfer_V4_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->new_))
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V4(
    parser_context_t* c, pd_indices_freeze_V4_t* m)
{
    CHECK_ERROR(_readAccountIndex(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_deposit_block_reward_reserve_balance_V4(
    parser_context_t* c, pd_balances_deposit_block_reward_reserve_balance_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V4(
    parser_context_t* c, pd_balances_set_balance_V4_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V4(
    parser_context_t* c, pd_balances_force_transfer_V4_t* m)
{
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->source))
    CHECK_ERROR(_readLookupasStaticLookupSource(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_burn_account_balance_V4(
    parser_context_t* c, pd_balances_burn_account_balance_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cdd_register_did_V4(
    parser_context_t* c, pd_identity_cdd_register_did_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->target_account))
    CHECK_ERROR(_readVecSecondaryKeyAccountId(c, &m->secondary_keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_invalidate_cdd_claims_V4(
    parser_context_t* c, pd_identity_invalidate_cdd_claims_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->cdd))
    CHECK_ERROR(_readMoment(c, &m->disable_from))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_change_cdd_requirement_for_mk_rotation_V4(
    parser_context_t* c, pd_identity_change_cdd_requirement_for_mk_rotation_V4_t* m)
{
    CHECK_ERROR(_readbool(c, &m->auth_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_add_cdd_claim_V4(
    parser_context_t* c, pd_identity_gc_add_cdd_claim_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_revoke_cdd_claim_V4(
    parser_context_t* c, pd_identity_gc_revoke_cdd_claim_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_claim_by_index_V4(
    parser_context_t* c, pd_identity_revoke_claim_by_index_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->target))
    CHECK_ERROR(_readClaimType(c, &m->claim_type))
    CHECK_ERROR(_readOptionScope(c, &m->scope))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rotate_primary_key_to_secondary_V4(
    parser_context_t* c, pd_identity_rotate_primary_key_to_secondary_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_secondary_key_permissions_V4(
    parser_context_t* c, pd_identity_set_secondary_key_permissions_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->key))
    CHECK_ERROR(_readPermissions(c, &m->perms))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_register_custom_claim_type_V4(
    parser_context_t* c, pd_identity_register_custom_claim_type_V4_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->ty))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cdd_register_did_with_cdd_V4(
    parser_context_t* c, pd_identity_cdd_register_did_with_cdd_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->target_account))
    CHECK_ERROR(_readVecSecondaryKeyAccountId(c, &m->secondary_keys))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_create_child_identity_V4(
    parser_context_t* c, pd_identity_create_child_identity_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->secondary_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_create_child_identities_V4(
    parser_context_t* c, pd_identity_create_child_identities_V4_t* m)
{
    CHECK_ERROR(_readVecCreateChildIdentityWithAuthAccountId(c, &m->child_keys))
    CHECK_ERROR(_readMoment(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_unlink_child_identity_V4(
    parser_context_t* c, pd_identity_unlink_child_identity_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->child_did))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_set_active_members_limit_V4(
    parser_context_t* c, pd_cddserviceproviders_set_active_members_limit_V4_t* m)
{
    CHECK_ERROR(_readMemberCount(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_disable_member_V4(
    parser_context_t* c, pd_cddserviceproviders_disable_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_add_member_V4(
    parser_context_t* c, pd_cddserviceproviders_add_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_remove_member_V4(
    parser_context_t* c, pd_cddserviceproviders_remove_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_swap_member_V4(
    parser_context_t* c, pd_cddserviceproviders_swap_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->remove))
    CHECK_ERROR(_readIdentityId(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_reset_members_V4(
    parser_context_t* c, pd_cddserviceproviders_reset_members_V4_t* m)
{
    CHECK_ERROR(_readVecIdentityId(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_abdicate_membership_V4(
    parser_context_t* c, pd_cddserviceproviders_abdicate_membership_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_vote_threshold_V4(
    parser_context_t* c, pd_polymeshcommittee_set_vote_threshold_V4_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_release_coordinator_V4(
    parser_context_t* c, pd_polymeshcommittee_set_release_coordinator_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_expires_after_V4(
    parser_context_t* c, pd_polymeshcommittee_set_expires_after_V4_t* m)
{
    CHECK_ERROR(_readMaybeBlockBlockNumber(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_or_propose_V4(
    parser_context_t* c, pd_polymeshcommittee_vote_or_propose_V4_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_V4(
    parser_context_t* c, pd_polymeshcommittee_vote_V4_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_set_active_members_limit_V4(
    parser_context_t* c, pd_committeemembership_set_active_members_limit_V4_t* m)
{
    CHECK_ERROR(_readMemberCount(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_disable_member_V4(
    parser_context_t* c, pd_committeemembership_disable_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_add_member_V4(
    parser_context_t* c, pd_committeemembership_add_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_remove_member_V4(
    parser_context_t* c, pd_committeemembership_remove_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_swap_member_V4(
    parser_context_t* c, pd_committeemembership_swap_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->remove))
    CHECK_ERROR(_readIdentityId(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_reset_members_V4(
    parser_context_t* c, pd_committeemembership_reset_members_V4_t* m)
{
    CHECK_ERROR(_readVecIdentityId(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_abdicate_membership_V4(
    parser_context_t* c, pd_committeemembership_abdicate_membership_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_vote_threshold_V4(
    parser_context_t* c, pd_technicalcommittee_set_vote_threshold_V4_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_release_coordinator_V4(
    parser_context_t* c, pd_technicalcommittee_set_release_coordinator_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_expires_after_V4(
    parser_context_t* c, pd_technicalcommittee_set_expires_after_V4_t* m)
{
    CHECK_ERROR(_readMaybeBlockBlockNumber(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_or_propose_V4(
    parser_context_t* c, pd_technicalcommittee_vote_or_propose_V4_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V4(
    parser_context_t* c, pd_technicalcommittee_vote_V4_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_set_active_members_limit_V4(
    parser_context_t* c, pd_technicalcommitteemembership_set_active_members_limit_V4_t* m)
{
    CHECK_ERROR(_readMemberCount(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_disable_member_V4(
    parser_context_t* c, pd_technicalcommitteemembership_disable_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_add_member_V4(
    parser_context_t* c, pd_technicalcommitteemembership_add_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_remove_member_V4(
    parser_context_t* c, pd_technicalcommitteemembership_remove_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_swap_member_V4(
    parser_context_t* c, pd_technicalcommitteemembership_swap_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->remove))
    CHECK_ERROR(_readIdentityId(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_reset_members_V4(
    parser_context_t* c, pd_technicalcommitteemembership_reset_members_V4_t* m)
{
    CHECK_ERROR(_readVecIdentityId(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_abdicate_membership_V4(
    parser_context_t* c, pd_technicalcommitteemembership_abdicate_membership_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_vote_threshold_V4(
    parser_context_t* c, pd_upgradecommittee_set_vote_threshold_V4_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_release_coordinator_V4(
    parser_context_t* c, pd_upgradecommittee_set_release_coordinator_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_expires_after_V4(
    parser_context_t* c, pd_upgradecommittee_set_expires_after_V4_t* m)
{
    CHECK_ERROR(_readMaybeBlockBlockNumber(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_or_propose_V4(
    parser_context_t* c, pd_upgradecommittee_vote_or_propose_V4_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readProposal(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_V4(
    parser_context_t* c, pd_upgradecommittee_vote_V4_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_set_active_members_limit_V4(
    parser_context_t* c, pd_upgradecommitteemembership_set_active_members_limit_V4_t* m)
{
    CHECK_ERROR(_readMemberCount(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_disable_member_V4(
    parser_context_t* c, pd_upgradecommitteemembership_disable_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_add_member_V4(
    parser_context_t* c, pd_upgradecommitteemembership_add_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_remove_member_V4(
    parser_context_t* c, pd_upgradecommitteemembership_remove_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_swap_member_V4(
    parser_context_t* c, pd_upgradecommitteemembership_swap_member_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->remove))
    CHECK_ERROR(_readIdentityId(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_reset_members_V4(
    parser_context_t* c, pd_upgradecommitteemembership_reset_members_V4_t* m)
{
    CHECK_ERROR(_readVecIdentityId(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_abdicate_membership_V4(
    parser_context_t* c, pd_upgradecommitteemembership_abdicate_membership_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_identity_V4(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_identity_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_identity_V4(
    parser_context_t* c, pd_multisig_create_proposal_as_identity_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_identity_V4(
    parser_context_t* c, pd_multisig_approve_as_identity_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_identity_V4(
    parser_context_t* c, pd_multisig_reject_as_identity_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_identity_V4(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_identity_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_secondary_V4(
    parser_context_t* c, pd_multisig_make_multisig_secondary_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_execute_scheduled_proposal_V4(
    parser_context_t* c, pd_multisig_execute_scheduled_proposal_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    CHECK_ERROR(_readIdentityId(c, &m->multisig_did))
    CHECK_ERROR(_readWeight(c, &m->_proposal_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_change_sigs_required_via_creator_V4(
    parser_context_t* c, pd_multisig_change_sigs_required_via_creator_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig_account))
    CHECK_ERROR(_readu64(c, &m->signatures_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_creator_controls_V4(
    parser_context_t* c, pd_multisig_remove_creator_controls_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->multisig_account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_controller_V4(
    parser_context_t* c, pd_bridge_change_controller_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_admin_V4(
    parser_context_t* c, pd_bridge_change_admin_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_timelock_V4(
    parser_context_t* c, pd_bridge_change_timelock_V4_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->timelock))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_V4(
    parser_context_t* c, pd_bridge_freeze_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_V4(
    parser_context_t* c, pd_bridge_unfreeze_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_limit_V4(
    parser_context_t* c, pd_bridge_change_bridge_limit_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_exempted_V4(
    parser_context_t* c, pd_bridge_change_bridge_exempted_V4_t* m)
{
    CHECK_ERROR(_readVecTupleIdentityIdbool(c, &m->exempted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_force_handle_bridge_tx_V4(
    parser_context_t* c, pd_bridge_force_handle_bridge_tx_V4_t* m)
{
    CHECK_ERROR(_readBridgeTxAccountId(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_batch_propose_bridge_tx_V4(
    parser_context_t* c, pd_bridge_batch_propose_bridge_tx_V4_t* m)
{
    CHECK_ERROR(_readVecBridgeTxAccountId(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_propose_bridge_tx_V4(
    parser_context_t* c, pd_bridge_propose_bridge_tx_V4_t* m)
{
    CHECK_ERROR(_readBridgeTxAccountId(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_bridge_tx_V4(
    parser_context_t* c, pd_bridge_handle_bridge_tx_V4_t* m)
{
    CHECK_ERROR(_readBridgeTxAccountId(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_txs_V4(
    parser_context_t* c, pd_bridge_freeze_txs_V4_t* m)
{
    CHECK_ERROR(_readVecBridgeTxAccountId(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_txs_V4(
    parser_context_t* c, pd_bridge_unfreeze_txs_V4_t* m)
{
    CHECK_ERROR(_readVecBridgeTxAccountId(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_scheduled_bridge_tx_V4(
    parser_context_t* c, pd_bridge_handle_scheduled_bridge_tx_V4_t* m)
{
    CHECK_ERROR(_readBridgeTxAccountId(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_add_freeze_admin_V4(
    parser_context_t* c, pd_bridge_add_freeze_admin_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->freeze_admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_remove_freeze_admin_V4(
    parser_context_t* c, pd_bridge_remove_freeze_admin_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->freeze_admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_remove_txs_V4(
    parser_context_t* c, pd_bridge_remove_txs_V4_t* m)
{
    CHECK_ERROR(_readVecBridgeTxAccountId(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V4(
    parser_context_t* c, pd_staking_set_validator_count_V4_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V4(
    parser_context_t* c, pd_staking_increase_validator_count_V4_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V4(
    parser_context_t* c, pd_staking_scale_validator_count_V4_t* m)
{
    CHECK_ERROR(_readPercent(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_add_permissioned_validator_V4(
    parser_context_t* c, pd_staking_add_permissioned_validator_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->identity))
    CHECK_ERROR(_readOptionu32(c, &m->intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_remove_permissioned_validator_V4(
    parser_context_t* c, pd_staking_remove_permissioned_validator_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->identity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_cdd_expiry_nominators_V4(
    parser_context_t* c, pd_staking_validate_cdd_expiry_nominators_V4_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_commission_cap_V4(
    parser_context_t* c, pd_staking_set_commission_cap_V4_t* m)
{
    CHECK_ERROR(_readPerbill(c, &m->new_cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_bond_threshold_V4(
    parser_context_t* c, pd_staking_set_min_bond_threshold_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->new_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V4(
    parser_context_t* c, pd_staking_force_no_eras_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V4(
    parser_context_t* c, pd_staking_force_new_era_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V4(
    parser_context_t* c, pd_staking_set_invulnerables_V4_t* m)
{
    CHECK_ERROR(_readVecAccountId(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V4(
    parser_context_t* c, pd_staking_force_unstake_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V4(
    parser_context_t* c, pd_staking_force_new_era_always_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V4(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V4_t* m)
{
    CHECK_ERROR(_readEraIndex(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V4(
    parser_context_t* c, pd_staking_payout_stakers_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V4(
    parser_context_t* c, pd_staking_set_history_depth_V4_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V4(
    parser_context_t* c, pd_staking_reap_stash_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_system_V4(
    parser_context_t* c, pd_staking_payout_stakers_by_system_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_change_slashing_allowed_for_V4(
    parser_context_t* c, pd_staking_change_slashing_allowed_for_V4_t* m)
{
    CHECK_ERROR(_readSlashingSwitch(c, &m->slashing_switch))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_update_permissioned_validator_intended_count_V4(
    parser_context_t* c, pd_staking_update_permissioned_validator_intended_count_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->identity))
    CHECK_ERROR(_readu32(c, &m->new_intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_from_governance_V4(
    parser_context_t* c, pd_staking_chill_from_governance_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->identity))
    CHECK_ERROR(_readVecAccountId(c, &m->stash_keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V4(
    parser_context_t* c, pd_session_set_keys_V4_t* m)
{
    CHECK_ERROR(_readKeys(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V4(
    parser_context_t* c, pd_session_purge_keys_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_ticker_V4(
    parser_context_t* c, pd_asset_register_ticker_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_ticker_transfer_V4(
    parser_context_t* c, pd_asset_accept_ticker_transfer_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_asset_ownership_transfer_V4(
    parser_context_t* c, pd_asset_accept_asset_ownership_transfer_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_create_asset_V4(
    parser_context_t* c, pd_asset_create_asset_V4_t* m)
{
    CHECK_ERROR(_readAssetName(c, &m->name))
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readbool(c, &m->divisible))
    CHECK_ERROR(_readAssetType(c, &m->asset_type))
    CHECK_ERROR(_readVecAssetIdentifier(c, &m->identifiers))
    CHECK_ERROR(_readOptionFundingRoundName(c, &m->funding_round))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_freeze_V4(
    parser_context_t* c, pd_asset_freeze_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unfreeze_V4(
    parser_context_t* c, pd_asset_unfreeze_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_rename_asset_V4(
    parser_context_t* c, pd_asset_rename_asset_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetName(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_issue_V4(
    parser_context_t* c, pd_asset_issue_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->amount))
    CHECK_ERROR(_readPortfolioKind(c, &m->portfolio_kind))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_redeem_V4(
    parser_context_t* c, pd_asset_redeem_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_make_divisible_V4(
    parser_context_t* c, pd_asset_make_divisible_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_documents_V4(
    parser_context_t* c, pd_asset_add_documents_V4_t* m)
{
    CHECK_ERROR(_readVecDocument(c, &m->docs))
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_documents_V4(
    parser_context_t* c, pd_asset_remove_documents_V4_t* m)
{
    CHECK_ERROR(_readVecDocumentId(c, &m->ids))
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_set_funding_round_V4(
    parser_context_t* c, pd_asset_set_funding_round_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readFundingRoundName(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_update_identifiers_V4(
    parser_context_t* c, pd_asset_update_identifiers_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readVecAssetIdentifier(c, &m->asset_identifiers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_controller_transfer_V4(
    parser_context_t* c, pd_asset_controller_transfer_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->amount))
    CHECK_ERROR(_readPortfolioId(c, &m->from_portfolio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_custom_asset_type_V4(
    parser_context_t* c, pd_asset_register_custom_asset_type_V4_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->ty))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_create_asset_with_custom_type_V4(
    parser_context_t* c, pd_asset_create_asset_with_custom_type_V4_t* m)
{
    CHECK_ERROR(_readAssetName(c, &m->name))
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readbool(c, &m->divisible))
    CHECK_ERROR(_readVecu8(c, &m->custom_asset_type))
    CHECK_ERROR(_readVecAssetIdentifier(c, &m->identifiers))
    CHECK_ERROR(_readOptionFundingRoundName(c, &m->funding_round))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_set_asset_metadata_V4(
    parser_context_t* c, pd_asset_set_asset_metadata_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetMetadataKey(c, &m->key))
    CHECK_ERROR(_readAssetMetadataValue(c, &m->value))
    CHECK_ERROR(_readOptionAssetMetadataValueDetailMoment(c, &m->detail))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_set_asset_metadata_details_V4(
    parser_context_t* c, pd_asset_set_asset_metadata_details_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetMetadataKey(c, &m->key))
    CHECK_ERROR(_readAssetMetadataValueDetailMoment(c, &m->detail))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_and_set_local_asset_metadata_V4(
    parser_context_t* c, pd_asset_register_and_set_local_asset_metadata_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetMetadataName(c, &m->name))
    CHECK_ERROR(_readAssetMetadataSpec(c, &m->spec))
    CHECK_ERROR(_readAssetMetadataValue(c, &m->value))
    CHECK_ERROR(_readOptionAssetMetadataValueDetailMoment(c, &m->detail))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_asset_metadata_local_type_V4(
    parser_context_t* c, pd_asset_register_asset_metadata_local_type_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetMetadataName(c, &m->name))
    CHECK_ERROR(_readAssetMetadataSpec(c, &m->spec))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_asset_metadata_global_type_V4(
    parser_context_t* c, pd_asset_register_asset_metadata_global_type_V4_t* m)
{
    CHECK_ERROR(_readAssetMetadataName(c, &m->name))
    CHECK_ERROR(_readAssetMetadataSpec(c, &m->spec))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_redeem_from_portfolio_V4(
    parser_context_t* c, pd_asset_redeem_from_portfolio_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->amount))
    CHECK_ERROR(_readPortfolioKind(c, &m->portfolio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_update_asset_type_V4(
    parser_context_t* c, pd_asset_update_asset_type_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetType(c, &m->asset_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_local_metadata_key_V4(
    parser_context_t* c, pd_asset_remove_local_metadata_key_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetMetadataLocalKey(c, &m->local_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_metadata_value_V4(
    parser_context_t* c, pd_asset_remove_metadata_value_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAssetMetadataKey(c, &m->metadata_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_exempt_ticker_affirmation_V4(
    parser_context_t* c, pd_asset_exempt_ticker_affirmation_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_ticker_affirmation_exemption_V4(
    parser_context_t* c, pd_asset_remove_ticker_affirmation_exemption_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_pre_approve_ticker_V4(
    parser_context_t* c, pd_asset_pre_approve_ticker_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_ticker_pre_approval_V4(
    parser_context_t* c, pd_asset_remove_ticker_pre_approval_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_distribute_V4(
    parser_context_t* c, pd_capitaldistribution_distribute_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readOptionPortfolioNumber(c, &m->portfolio))
    CHECK_ERROR(_readTicker(c, &m->currency))
    CHECK_ERROR(_readBalance(c, &m->per_share))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readMoment(c, &m->payment_at))
    CHECK_ERROR(_readOptionMoment(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_claim_V4(
    parser_context_t* c, pd_capitaldistribution_claim_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_push_benefit_V4(
    parser_context_t* c, pd_capitaldistribution_push_benefit_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    CHECK_ERROR(_readIdentityId(c, &m->holder))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_reclaim_V4(
    parser_context_t* c, pd_capitaldistribution_reclaim_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_remove_distribution_V4(
    parser_context_t* c, pd_capitaldistribution_remove_distribution_V4_t* m)
{
    CHECK_ERROR(_readCAId(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_checkpoint_V4(
    parser_context_t* c, pd_checkpoint_create_checkpoint_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_set_schedules_max_complexity_V4(
    parser_context_t* c, pd_checkpoint_set_schedules_max_complexity_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->max_complexity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_schedule_V4(
    parser_context_t* c, pd_checkpoint_create_schedule_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readScheduleCheckpoints(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_remove_schedule_V4(
    parser_context_t* c, pd_checkpoint_remove_schedule_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readScheduleId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_compliance_requirement_V4(
    parser_context_t* c, pd_compliancemanager_add_compliance_requirement_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readVecCondition(c, &m->sender_conditions))
    CHECK_ERROR(_readVecCondition(c, &m->receiver_conditions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_compliance_requirement_V4(
    parser_context_t* c, pd_compliancemanager_remove_compliance_requirement_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_replace_asset_compliance_V4(
    parser_context_t* c, pd_compliancemanager_replace_asset_compliance_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readVecComplianceRequirement(c, &m->asset_compliance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_reset_asset_compliance_V4(
    parser_context_t* c, pd_compliancemanager_reset_asset_compliance_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_pause_asset_compliance_V4(
    parser_context_t* c, pd_compliancemanager_pause_asset_compliance_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_resume_asset_compliance_V4(
    parser_context_t* c, pd_compliancemanager_resume_asset_compliance_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_default_trusted_claim_issuer_V4(
    parser_context_t* c, pd_compliancemanager_add_default_trusted_claim_issuer_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readTrustedIssuer(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_default_trusted_claim_issuer_V4(
    parser_context_t* c, pd_compliancemanager_remove_default_trusted_claim_issuer_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readIdentityId(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_change_compliance_requirement_V4(
    parser_context_t* c, pd_compliancemanager_change_compliance_requirement_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readComplianceRequirement(c, &m->new_req))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_prune_historical_pips_V4(
    parser_context_t* c, pd_pips_set_prune_historical_pips_V4_t* m)
{
    CHECK_ERROR(_readbool(c, &m->prune))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_min_proposal_deposit_V4(
    parser_context_t* c, pd_pips_set_min_proposal_deposit_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_default_enactment_period_V4(
    parser_context_t* c, pd_pips_set_default_enactment_period_V4_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_pending_pip_expiry_V4(
    parser_context_t* c, pd_pips_set_pending_pip_expiry_V4_t* m)
{
    CHECK_ERROR(_readMaybeBlockBlockNumber(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_max_pip_skip_count_V4(
    parser_context_t* c, pd_pips_set_max_pip_skip_count_V4_t* m)
{
    CHECK_ERROR(_readSkippedCount(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_active_pip_limit_V4(
    parser_context_t* c, pd_pips_set_active_pip_limit_V4_t* m)
{
    CHECK_ERROR(_readu32(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_approve_committee_proposal_V4(
    parser_context_t* c, pd_pips_approve_committee_proposal_V4_t* m)
{
    CHECK_ERROR(_readPipId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reject_proposal_V4(
    parser_context_t* c, pd_pips_reject_proposal_V4_t* m)
{
    CHECK_ERROR(_readPipId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_prune_proposal_V4(
    parser_context_t* c, pd_pips_prune_proposal_V4_t* m)
{
    CHECK_ERROR(_readPipId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reschedule_execution_V4(
    parser_context_t* c, pd_pips_reschedule_execution_V4_t* m)
{
    CHECK_ERROR(_readPipId(c, &m->id))
    CHECK_ERROR(_readOptionBlockNumber(c, &m->until))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_clear_snapshot_V4(
    parser_context_t* c, pd_pips_clear_snapshot_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_snapshot_V4(
    parser_context_t* c, pd_pips_snapshot_V4_t* m)
{
    UNUSED(c);
    UNUSED(m);
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_execute_scheduled_pip_V4(
    parser_context_t* c, pd_pips_execute_scheduled_pip_V4_t* m)
{
    CHECK_ERROR(_readPipId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_expire_scheduled_pip_V4(
    parser_context_t* c, pd_pips_expire_scheduled_pip_V4_t* m)
{
    CHECK_ERROR(_readIdentityId(c, &m->did))
    CHECK_ERROR(_readPipId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_create_portfolio_V4(
    parser_context_t* c, pd_portfolio_create_portfolio_V4_t* m)
{
    CHECK_ERROR(_readPortfolioName(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_delete_portfolio_V4(
    parser_context_t* c, pd_portfolio_delete_portfolio_V4_t* m)
{
    CHECK_ERROR(_readPortfolioNumber(c, &m->num))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_rename_portfolio_V4(
    parser_context_t* c, pd_portfolio_rename_portfolio_V4_t* m)
{
    CHECK_ERROR(_readPortfolioNumber(c, &m->num))
    CHECK_ERROR(_readPortfolioName(c, &m->to_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_quit_portfolio_custody_V4(
    parser_context_t* c, pd_portfolio_quit_portfolio_custody_V4_t* m)
{
    CHECK_ERROR(_readPortfolioId(c, &m->pid))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_accept_portfolio_custody_V4(
    parser_context_t* c, pd_portfolio_accept_portfolio_custody_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_move_portfolio_funds_V4(
    parser_context_t* c, pd_portfolio_move_portfolio_funds_V4_t* m)
{
    CHECK_ERROR(_readPortfolioId(c, &m->from))
    CHECK_ERROR(_readPortfolioId(c, &m->to))
    CHECK_ERROR(_readVecFund(c, &m->funds))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_pre_approve_portfolio_V4(
    parser_context_t* c, pd_portfolio_pre_approve_portfolio_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readPortfolioId(c, &m->portfolio_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_remove_portfolio_pre_approval_V4(
    parser_context_t* c, pd_portfolio_remove_portfolio_pre_approval_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readPortfolioId(c, &m->portfolio_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_coefficient_V4(
    parser_context_t* c, pd_protocolfee_change_coefficient_V4_t* m)
{
    CHECK_ERROR(_readPosRatio(c, &m->coefficient))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_create_venue_V4(
    parser_context_t* c, pd_settlement_create_venue_V4_t* m)
{
    CHECK_ERROR(_readVenueDetails(c, &m->details))
    CHECK_ERROR(_readVecAccountId(c, &m->signers))
    CHECK_ERROR(_readVenueType(c, &m->typ))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue_details_V4(
    parser_context_t* c, pd_settlement_update_venue_details_V4_t* m)
{
    CHECK_ERROR(_readVenueId(c, &m->id))
    CHECK_ERROR(_readVenueDetails(c, &m->details))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue_type_V4(
    parser_context_t* c, pd_settlement_update_venue_type_V4_t* m)
{
    CHECK_ERROR(_readVenueId(c, &m->id))
    CHECK_ERROR(_readVenueType(c, &m->typ))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_with_receipts_V4(
    parser_context_t* c, pd_settlement_affirm_with_receipts_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readVecReceiptDetails(c, &m->receipt_details))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_set_venue_filtering_V4(
    parser_context_t* c, pd_settlement_set_venue_filtering_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readbool(c, &m->enabled))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_allow_venues_V4(
    parser_context_t* c, pd_settlement_allow_venues_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readVecVenueId(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_disallow_venues_V4(
    parser_context_t* c, pd_settlement_disallow_venues_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readVecVenueId(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue_signers_V4(
    parser_context_t* c, pd_settlement_update_venue_signers_V4_t* m)
{
    CHECK_ERROR(_readVenueId(c, &m->id))
    CHECK_ERROR(_readVecAccountId(c, &m->signers))
    CHECK_ERROR(_readbool(c, &m->add_signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_execute_manual_instruction_V4(
    parser_context_t* c, pd_settlement_execute_manual_instruction_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readOptionPortfolioId(c, &m->portfolio))
    CHECK_ERROR(_readu32(c, &m->fungible_transfers))
    CHECK_ERROR(_readu32(c, &m->nfts_transfers))
    CHECK_ERROR(_readu32(c, &m->offchain_transfers))
    CHECK_ERROR(_readOptionWeight(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_instruction_V4(
    parser_context_t* c, pd_settlement_add_instruction_V4_t* m)
{
    CHECK_ERROR(_readVenueId(c, &m->venue_id))
    CHECK_ERROR(_readSettlementTypeBlockNumber(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment(c, &m->value_date))
    CHECK_ERROR(_readVecLeg(c, &m->legs))
    CHECK_ERROR(_readOptionMemo(c, &m->instruction_memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_and_affirm_instruction_V4(
    parser_context_t* c, pd_settlement_add_and_affirm_instruction_V4_t* m)
{
    CHECK_ERROR(_readVenueId(c, &m->venue_id))
    CHECK_ERROR(_readSettlementTypeBlockNumber(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment(c, &m->value_date))
    CHECK_ERROR(_readVecLeg(c, &m->legs))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    CHECK_ERROR(_readOptionMemo(c, &m->instruction_memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_instruction_V4(
    parser_context_t* c, pd_settlement_affirm_instruction_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_withdraw_affirmation_V4(
    parser_context_t* c, pd_settlement_withdraw_affirmation_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_reject_instruction_V4(
    parser_context_t* c, pd_settlement_reject_instruction_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readPortfolioId(c, &m->portfolio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_execute_scheduled_instruction_V4(
    parser_context_t* c, pd_settlement_execute_scheduled_instruction_V4_t* m)
{
    CHECK_ERROR(_readInstructionId(c, &m->id))
    CHECK_ERROR(_readWeight(c, &m->weight_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_create_fundraiser_V4(
    parser_context_t* c, pd_sto_create_fundraiser_V4_t* m)
{
    CHECK_ERROR(_readPortfolioId(c, &m->offering_portfolio))
    CHECK_ERROR(_readTicker(c, &m->offering_asset))
    CHECK_ERROR(_readPortfolioId(c, &m->raising_portfolio))
    CHECK_ERROR(_readTicker(c, &m->raising_asset))
    CHECK_ERROR(_readVecPriceTier(c, &m->tiers))
    CHECK_ERROR(_readVenueId(c, &m->venue_id))
    CHECK_ERROR(_readOptionMoment(c, &m->start))
    CHECK_ERROR(_readOptionMoment(c, &m->end))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->minimum_investment))
    CHECK_ERROR(_readFundraiserName(c, &m->fundraiser_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_invest_V4(
    parser_context_t* c, pd_sto_invest_V4_t* m)
{
    CHECK_ERROR(_readPortfolioId(c, &m->investment_portfolio))
    CHECK_ERROR(_readPortfolioId(c, &m->funding_portfolio))
    CHECK_ERROR(_readTicker(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId(c, &m->id))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->purchase_amount))
    CHECK_ERROR(_readOptionBalance(c, &m->max_price))
    CHECK_ERROR(_readOptionReceiptDetails(c, &m->receipt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_freeze_fundraiser_V4(
    parser_context_t* c, pd_sto_freeze_fundraiser_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_unfreeze_fundraiser_V4(
    parser_context_t* c, pd_sto_unfreeze_fundraiser_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_modify_fundraiser_window_V4(
    parser_context_t* c, pd_sto_modify_fundraiser_window_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId(c, &m->id))
    CHECK_ERROR(_readMoment(c, &m->start))
    CHECK_ERROR(_readOptionMoment(c, &m->end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_stop_V4(
    parser_context_t* c, pd_sto_stop_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_disbursement_V4(
    parser_context_t* c, pd_treasury_disbursement_V4_t* m)
{
    CHECK_ERROR(_readVecBeneficiary(c, &m->beneficiaries))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reimbursement_V4(
    parser_context_t* c, pd_treasury_reimbursement_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_relay_tx_V4(
    parser_context_t* c, pd_utility_relay_tx_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->target))
    CHECK_ERROR(_readOffChainSignature(c, &m->signature))
    CHECK_ERROR(_readUniqueCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_all_V4(
    parser_context_t* c, pd_utility_batch_all_V4_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_dispatch_as_V4(
    parser_context_t* c, pd_utility_dispatch_as_V4_t* m)
{
    CHECK_ERROR(_readBoxPalletsOrigin(c, &m->as_origin))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_force_batch_V4(
    parser_context_t* c, pd_utility_force_batch_V4_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_with_weight_V4(
    parser_context_t* c, pd_utility_with_weight_V4_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight(c, &m->weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_old_V4(
    parser_context_t* c, pd_utility_batch_old_V4_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_as_derivative_V4(
    parser_context_t* c, pd_utility_as_derivative_V4_t* m)
{
    CHECK_ERROR(_readu16(c, &m->index))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_create_group_V4(
    parser_context_t* c, pd_externalagents_create_group_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readExtrinsicPermissions(c, &m->perms))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_set_group_permissions_V4(
    parser_context_t* c, pd_externalagents_set_group_permissions_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readAGId(c, &m->id))
    CHECK_ERROR(_readExtrinsicPermissions(c, &m->perms))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_remove_agent_V4(
    parser_context_t* c, pd_externalagents_remove_agent_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readIdentityId(c, &m->agent))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_abdicate_V4(
    parser_context_t* c, pd_externalagents_abdicate_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_change_group_V4(
    parser_context_t* c, pd_externalagents_change_group_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readIdentityId(c, &m->agent))
    CHECK_ERROR(_readAgentGroup(c, &m->group))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_accept_become_agent_V4(
    parser_context_t* c, pd_externalagents_accept_become_agent_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_create_group_and_add_auth_V4(
    parser_context_t* c, pd_externalagents_create_group_and_add_auth_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readExtrinsicPermissions(c, &m->perms))
    CHECK_ERROR(_readIdentityId(c, &m->target))
    CHECK_ERROR(_readOptionMoment(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_create_and_change_custom_group_V4(
    parser_context_t* c, pd_externalagents_create_and_change_custom_group_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readExtrinsicPermissions(c, &m->perms))
    CHECK_ERROR(_readIdentityId(c, &m->agent))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_set_paying_key_V4(
    parser_context_t* c, pd_relayer_set_paying_key_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->polyx_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_accept_paying_key_V4(
    parser_context_t* c, pd_relayer_accept_paying_key_V4_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_remove_paying_key_V4(
    parser_context_t* c, pd_relayer_remove_paying_key_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->user_key))
    CHECK_ERROR(_readAccountId(c, &m->paying_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_update_polyx_limit_V4(
    parser_context_t* c, pd_relayer_update_polyx_limit_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->polyx_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_increase_polyx_limit_V4(
    parser_context_t* c, pd_relayer_increase_polyx_limit_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_decrease_polyx_limit_V4(
    parser_context_t* c, pd_relayer_decrease_polyx_limit_V4_t* m)
{
    CHECK_ERROR(_readAccountId(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_old_weight_V4(
    parser_context_t* c, pd_contracts_call_old_weight_V4_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readBytes(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_with_code_old_weight_V4(
    parser_context_t* c, pd_contracts_instantiate_with_code_old_weight_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readBytes(c, &m->code))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_old_weight_V4(
    parser_context_t* c, pd_contracts_instantiate_old_weight_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readCompactu64(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_upload_code_V4(
    parser_context_t* c, pd_contracts_upload_code_V4_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readDeterminism(c, &m->determinism))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_remove_code_V4(
    parser_context_t* c, pd_contracts_remove_code_V4_t* m)
{
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_set_code_V4(
    parser_context_t* c, pd_contracts_set_code_V4_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_V4(
    parser_context_t* c, pd_contracts_call_V4_t* m)
{
    CHECK_ERROR(_readAccountIdLookupOfT(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readBytes(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_with_code_V4(
    parser_context_t* c, pd_contracts_instantiate_with_code_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readBytes(c, &m->code))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_V4(
    parser_context_t* c, pd_contracts_instantiate_V4_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionCompactBalanceOf(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBytes(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcontracts_instantiate_with_code_perms_V4(
    parser_context_t* c, pd_polymeshcontracts_instantiate_with_code_perms_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->endowment))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionBalance(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    CHECK_ERROR(_readPermissions(c, &m->perms))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcontracts_instantiate_with_hash_perms_V4(
    parser_context_t* c, pd_polymeshcontracts_instantiate_with_hash_perms_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->endowment))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionBalance(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    CHECK_ERROR(_readPermissions(c, &m->perms))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcontracts_update_call_runtime_whitelist_V4(
    parser_context_t* c, pd_polymeshcontracts_update_call_runtime_whitelist_V4_t* m)
{
    CHECK_ERROR(_readVecTupleExtrinsicIdbool(c, &m->updates))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcontracts_instantiate_with_code_as_primary_key_V4(
    parser_context_t* c, pd_polymeshcontracts_instantiate_with_code_as_primary_key_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->endowment))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionBalance(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readVecu8(c, &m->code))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcontracts_instantiate_with_hash_as_primary_key_V4(
    parser_context_t* c, pd_polymeshcontracts_instantiate_with_hash_as_primary_key_V4_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->endowment))
    CHECK_ERROR(_readWeight(c, &m->gas_limit))
    CHECK_ERROR(_readOptionBalance(c, &m->storage_deposit_limit))
    CHECK_ERROR(_readCodeHash(c, &m->code_hash))
    CHECK_ERROR(_readVecu8(c, &m->data))
    CHECK_ERROR(_readVecu8(c, &m->salt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcontracts_upgrade_api_V4(
    parser_context_t* c, pd_polymeshcontracts_upgrade_api_V4_t* m)
{
    CHECK_ERROR(_readApi(c, &m->api))
    CHECK_ERROR(_readNextUpgradeT(c, &m->next_upgrade))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_note_preimage_V4(
    parser_context_t* c, pd_preimage_note_preimage_V4_t* m)
{
    CHECK_ERROR(_readVecu8(c, &m->bytes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unnote_preimage_V4(
    parser_context_t* c, pd_preimage_unnote_preimage_V4_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_request_preimage_V4(
    parser_context_t* c, pd_preimage_request_preimage_V4_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_preimage_unrequest_preimage_V4(
    parser_context_t* c, pd_preimage_unrequest_preimage_V4_t* m)
{
    CHECK_ERROR(_readHash(c, &m->hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nft_create_nft_collection_V4(
    parser_context_t* c, pd_nft_create_nft_collection_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readOptionNonFungibleType(c, &m->nft_type))
    CHECK_ERROR(_readVecAssetMetadataKey(c, &m->collection_keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nft_issue_nft_V4(
    parser_context_t* c, pd_nft_issue_nft_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readVecNFTMetadataAttribute(c, &m->nft_metadata_attributes))
    CHECK_ERROR(_readPortfolioKind(c, &m->portfolio_kind))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_nft_redeem_nft_V4(
    parser_context_t* c, pd_nft_redeem_nft_V4_t* m)
{
    CHECK_ERROR(_readTicker(c, &m->ticker))
    CHECK_ERROR(_readNFTId(c, &m->nft_id))
    CHECK_ERROR(_readPortfolioKind(c, &m->portfolio_kind))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V4(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V4_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V4(c, &method->nested.balances_transfer_V4))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_transfer_with_memo_V4(c, &method->nested.balances_transfer_with_memo_V4))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_identity_accept_primary_key_V4(c, &method->nested.identity_accept_primary_key_V4))
        break;
    case 1796: /* module 7 call 4 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_key_V4(c, &method->nested.identity_join_identity_as_key_V4))
        break;
    case 1797: /* module 7 call 5 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_key_V4(c, &method->nested.identity_leave_identity_as_key_V4))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_identity_add_claim_V4(c, &method->nested.identity_add_claim_V4))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_identity_revoke_claim_V4(c, &method->nested.identity_revoke_claim_V4))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_identity_freeze_secondary_keys_V4(c, &method->nested.identity_freeze_secondary_keys_V4))
        break;
    case 1801: /* module 7 call 9 */
        CHECK_ERROR(_readMethod_identity_unfreeze_secondary_keys_V4(c, &method->nested.identity_unfreeze_secondary_keys_V4))
        break;
    case 1802: /* module 7 call 10 */
        CHECK_ERROR(_readMethod_identity_add_authorization_V4(c, &method->nested.identity_add_authorization_V4))
        break;
    case 1803: /* module 7 call 11 */
        CHECK_ERROR(_readMethod_identity_remove_authorization_V4(c, &method->nested.identity_remove_authorization_V4))
        break;
    case 1808: /* module 7 call 16 */
        CHECK_ERROR(_readMethod_identity_add_secondary_keys_with_authorization_V4(c, &method->nested.identity_add_secondary_keys_with_authorization_V4))
        break;
    case 1810: /* module 7 call 18 */
        CHECK_ERROR(_readMethod_identity_remove_secondary_keys_V4(c, &method->nested.identity_remove_secondary_keys_V4))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_multisig_create_multisig_V4(c, &method->nested.multisig_create_multisig_V4))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_key_V4(c, &method->nested.multisig_create_or_approve_proposal_as_key_V4))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_key_V4(c, &method->nested.multisig_create_proposal_as_key_V4))
        break;
    case 3846: /* module 15 call 6 */
        CHECK_ERROR(_readMethod_multisig_approve_as_key_V4(c, &method->nested.multisig_approve_as_key_V4))
        break;
    case 3848: /* module 15 call 8 */
        CHECK_ERROR(_readMethod_multisig_reject_as_key_V4(c, &method->nested.multisig_reject_as_key_V4))
        break;
    case 3850: /* module 15 call 10 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_key_V4(c, &method->nested.multisig_accept_multisig_signer_as_key_V4))
        break;
    case 3851: /* module 15 call 11 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signer_V4(c, &method->nested.multisig_add_multisig_signer_V4))
        break;
    case 3852: /* module 15 call 12 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signer_V4(c, &method->nested.multisig_remove_multisig_signer_V4))
        break;
    case 3853: /* module 15 call 13 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signers_via_creator_V4(c, &method->nested.multisig_add_multisig_signers_via_creator_V4))
        break;
    case 3854: /* module 15 call 14 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signers_via_creator_V4(c, &method->nested.multisig_remove_multisig_signers_via_creator_V4))
        break;
    case 3855: /* module 15 call 15 */
        CHECK_ERROR(_readMethod_multisig_change_sigs_required_V4(c, &method->nested.multisig_change_sigs_required_V4))
        break;
    case 3857: /* module 15 call 17 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_primary_V4(c, &method->nested.multisig_make_multisig_primary_V4))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V4(c, &method->nested.staking_bond_V4))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V4(c, &method->nested.staking_bond_extra_V4))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V4(c, &method->nested.staking_unbond_V4))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V4(c, &method->nested.staking_withdraw_unbonded_V4))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V4(c, &method->nested.staking_validate_V4))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V4(c, &method->nested.staking_nominate_V4))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V4(c, &method->nested.staking_chill_V4))
        break;
    case 4359: /* module 17 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V4(c, &method->nested.staking_set_payee_V4))
        break;
    case 4360: /* module 17 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V4(c, &method->nested.staking_set_controller_V4))
        break;
    case 4376: /* module 17 call 24 */
        CHECK_ERROR(_readMethod_staking_rebond_V4(c, &method->nested.staking_rebond_V4))
        break;
    case 8454: /* module 33 call 6 */
        CHECK_ERROR(_readMethod_pips_propose_V4(c, &method->nested.pips_propose_V4))
        break;
    case 8455: /* module 33 call 7 */
        CHECK_ERROR(_readMethod_pips_vote_V4(c, &method->nested.pips_vote_V4))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V4(c, &method->nested.utility_batch_V4))
        break;
    case 10503: /* module 41 call 7 */
        CHECK_ERROR(_readMethod_utility_batch_atomic_V4(c, &method->nested.utility_batch_atomic_V4))
        break;
    case 10504: /* module 41 call 8 */
        CHECK_ERROR(_readMethod_utility_batch_optimistic_V4(c, &method->nested.utility_batch_optimistic_V4))
        break;

#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 6686: /* module 26 call 30 */
        CHECK_ERROR(_readMethod_asset_add_mandatory_mediators_V4(c, &method->basic.asset_add_mandatory_mediators_V4))
        break;
    case 6687: /* module 26 call 31 */
        CHECK_ERROR(_readMethod_asset_remove_mandatory_mediators_V4(c, &method->basic.asset_remove_mandatory_mediators_V4))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_corporateaction_set_max_details_length_V4(c, &method->nested.corporateaction_set_max_details_length_V4))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_targets_V4(c, &method->nested.corporateaction_set_default_targets_V4))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_withholding_tax_V4(c, &method->nested.corporateaction_set_default_withholding_tax_V4))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_corporateaction_set_did_withholding_tax_V4(c, &method->nested.corporateaction_set_did_withholding_tax_V4))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action_V4(c, &method->nested.corporateaction_initiate_corporate_action_V4))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_corporateaction_link_ca_doc_V4(c, &method->nested.corporateaction_link_ca_doc_V4))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_corporateaction_remove_ca_V4(c, &method->nested.corporateaction_remove_ca_V4))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_corporateaction_change_record_date_V4(c, &method->nested.corporateaction_change_record_date_V4))
        break;
    case 7688: /* module 30 call 8 */
        CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action_and_distribute_V4(c, &method->nested.corporateaction_initiate_corporate_action_and_distribute_V4))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_corporateballot_attach_ballot_V4(c, &method->nested.corporateballot_attach_ballot_V4))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_corporateballot_vote_V4(c, &method->nested.corporateballot_vote_V4))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_corporateballot_change_end_V4(c, &method->nested.corporateballot_change_end_V4))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_corporateballot_change_meta_V4(c, &method->nested.corporateballot_change_meta_V4))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_corporateballot_change_rcv_V4(c, &method->nested.corporateballot_change_rcv_V4))
        break;
    case 7941: /* module 31 call 5 */
        CHECK_ERROR(_readMethod_corporateballot_remove_ballot_V4(c, &method->nested.corporateballot_remove_ballot_V4))
        break;
    case 8462: /* module 33 call 14 */
        CHECK_ERROR(_readMethod_pips_enact_snapshot_results_V4(c, &method->nested.pips_enact_snapshot_results_V4))
        break;
    case 8712: /* module 34 call 8 */
        CHECK_ERROR(_readMethod_portfolio_allow_identity_to_create_portfolios_V4(c, &method->basic.portfolio_allow_identity_to_create_portfolios_V4))
        break;
    case 8713: /* module 34 call 9 */
        CHECK_ERROR(_readMethod_portfolio_revoke_create_portfolios_permission_V4(c, &method->basic.portfolio_revoke_create_portfolios_permission_V4))
        break;
    case 8714: /* module 34 call 10 */
        CHECK_ERROR(_readMethod_portfolio_create_custody_portfolio_V4(c, &method->basic.portfolio_create_custody_portfolio_V4))
        break;
    case 9487: /* module 37 call 15 */
        CHECK_ERROR(_readMethod_settlement_affirm_with_receipts_with_count_V4(c, &method->basic.settlement_affirm_with_receipts_with_count_V4))
        break;
    case 9488: /* module 37 call 16 */
        CHECK_ERROR(_readMethod_settlement_affirm_instruction_with_count_V4(c, &method->basic.settlement_affirm_instruction_with_count_V4))
        break;
    case 9489: /* module 37 call 17 */
        CHECK_ERROR(_readMethod_settlement_reject_instruction_with_count_V4(c, &method->basic.settlement_reject_instruction_with_count_V4))
        break;
    case 9490: /* module 37 call 18 */
        CHECK_ERROR(_readMethod_settlement_withdraw_affirmation_with_count_V4(c, &method->basic.settlement_withdraw_affirmation_with_count_V4))
        break;
    case 9491: /* module 37 call 19 */
        CHECK_ERROR(_readMethod_settlement_add_instruction_with_mediators_V4(c, &method->basic.settlement_add_instruction_with_mediators_V4))
        break;
    case 9492: /* module 37 call 20 */
        CHECK_ERROR(_readMethod_settlement_add_and_affirm_with_mediators_V4(c, &method->basic.settlement_add_and_affirm_with_mediators_V4))
        break;
    case 9493: /* module 37 call 21 */
        CHECK_ERROR(_readMethod_settlement_affirm_instruction_as_mediator_V4(c, &method->basic.settlement_affirm_instruction_as_mediator_V4))
        break;
    case 9494: /* module 37 call 22 */
        CHECK_ERROR(_readMethod_settlement_withdraw_affirmation_as_mediator_V4(c, &method->basic.settlement_withdraw_affirmation_as_mediator_V4))
        break;
    case 9495: /* module 37 call 23 */
        CHECK_ERROR(_readMethod_settlement_reject_instruction_as_mediator_V4(c, &method->basic.settlement_reject_instruction_as_mediator_V4))
        break;
    case 12547: /* module 49 call 3 */
        CHECK_ERROR(_readMethod_nft_controller_transfer_V4(c, &method->basic.nft_controller_transfer_V4))
        break;
#endif
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_remark_V4(c, &method->nested.system_remark_V4))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V4(c, &method->nested.system_set_heap_pages_V4))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_code_V4(c, &method->nested.system_set_code_V4))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V4(c, &method->nested.system_set_code_without_checks_V4))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_remark_with_event_V4(c, &method->nested.system_remark_with_event_V4))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V4(c, &method->nested.timestamp_set_V4))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V4(c, &method->nested.indices_claim_V4))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V4(c, &method->nested.indices_transfer_V4))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V4(c, &method->nested.indices_free_V4))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V4(c, &method->nested.indices_force_transfer_V4))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V4(c, &method->nested.indices_freeze_V4))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_deposit_block_reward_reserve_balance_V4(c, &method->nested.balances_deposit_block_reward_reserve_balance_V4))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_set_balance_V4(c, &method->nested.balances_set_balance_V4))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V4(c, &method->nested.balances_force_transfer_V4))
        break;
    case 1285: /* module 5 call 5 */
        CHECK_ERROR(_readMethod_balances_burn_account_balance_V4(c, &method->nested.balances_burn_account_balance_V4))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_identity_cdd_register_did_V4(c, &method->nested.identity_cdd_register_did_V4))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_identity_invalidate_cdd_claims_V4(c, &method->nested.identity_invalidate_cdd_claims_V4))
        break;
    case 1795: /* module 7 call 3 */
        CHECK_ERROR(_readMethod_identity_change_cdd_requirement_for_mk_rotation_V4(c, &method->nested.identity_change_cdd_requirement_for_mk_rotation_V4))
        break;
    case 1804: /* module 7 call 12 */
        CHECK_ERROR(_readMethod_identity_gc_add_cdd_claim_V4(c, &method->nested.identity_gc_add_cdd_claim_V4))
        break;
    case 1805: /* module 7 call 13 */
        CHECK_ERROR(_readMethod_identity_gc_revoke_cdd_claim_V4(c, &method->nested.identity_gc_revoke_cdd_claim_V4))
        break;
    case 1806: /* module 7 call 14 */
        CHECK_ERROR(_readMethod_identity_revoke_claim_by_index_V4(c, &method->nested.identity_revoke_claim_by_index_V4))
        break;
    case 1807: /* module 7 call 15 */
        CHECK_ERROR(_readMethod_identity_rotate_primary_key_to_secondary_V4(c, &method->nested.identity_rotate_primary_key_to_secondary_V4))
        break;
    case 1809: /* module 7 call 17 */
        CHECK_ERROR(_readMethod_identity_set_secondary_key_permissions_V4(c, &method->nested.identity_set_secondary_key_permissions_V4))
        break;
    case 1811: /* module 7 call 19 */
        CHECK_ERROR(_readMethod_identity_register_custom_claim_type_V4(c, &method->nested.identity_register_custom_claim_type_V4))
        break;
    case 1812: /* module 7 call 20 */
        CHECK_ERROR(_readMethod_identity_cdd_register_did_with_cdd_V4(c, &method->nested.identity_cdd_register_did_with_cdd_V4))
        break;
    case 1813: /* module 7 call 21 */
        CHECK_ERROR(_readMethod_identity_create_child_identity_V4(c, &method->nested.identity_create_child_identity_V4))
        break;
    case 1814: /* module 7 call 22 */
        CHECK_ERROR(_readMethod_identity_create_child_identities_V4(c, &method->nested.identity_create_child_identities_V4))
        break;
    case 1815: /* module 7 call 23 */
        CHECK_ERROR(_readMethod_identity_unlink_child_identity_V4(c, &method->nested.identity_unlink_child_identity_V4))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_cddserviceproviders_set_active_members_limit_V4(c, &method->nested.cddserviceproviders_set_active_members_limit_V4))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_cddserviceproviders_disable_member_V4(c, &method->nested.cddserviceproviders_disable_member_V4))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_cddserviceproviders_add_member_V4(c, &method->nested.cddserviceproviders_add_member_V4))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_cddserviceproviders_remove_member_V4(c, &method->nested.cddserviceproviders_remove_member_V4))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_cddserviceproviders_swap_member_V4(c, &method->nested.cddserviceproviders_swap_member_V4))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_cddserviceproviders_reset_members_V4(c, &method->nested.cddserviceproviders_reset_members_V4))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_cddserviceproviders_abdicate_membership_V4(c, &method->nested.cddserviceproviders_abdicate_membership_V4))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_vote_threshold_V4(c, &method->nested.polymeshcommittee_set_vote_threshold_V4))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_release_coordinator_V4(c, &method->nested.polymeshcommittee_set_release_coordinator_V4))
        break;
    case 2306: /* module 9 call 2 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_expires_after_V4(c, &method->nested.polymeshcommittee_set_expires_after_V4))
        break;
    case 2307: /* module 9 call 3 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_or_propose_V4(c, &method->nested.polymeshcommittee_vote_or_propose_V4))
        break;
    case 2308: /* module 9 call 4 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_V4(c, &method->nested.polymeshcommittee_vote_V4))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_committeemembership_set_active_members_limit_V4(c, &method->nested.committeemembership_set_active_members_limit_V4))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_committeemembership_disable_member_V4(c, &method->nested.committeemembership_disable_member_V4))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_committeemembership_add_member_V4(c, &method->nested.committeemembership_add_member_V4))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_committeemembership_remove_member_V4(c, &method->nested.committeemembership_remove_member_V4))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_committeemembership_swap_member_V4(c, &method->nested.committeemembership_swap_member_V4))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_committeemembership_reset_members_V4(c, &method->nested.committeemembership_reset_members_V4))
        break;
    case 2566: /* module 10 call 6 */
        CHECK_ERROR(_readMethod_committeemembership_abdicate_membership_V4(c, &method->nested.committeemembership_abdicate_membership_V4))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_vote_threshold_V4(c, &method->nested.technicalcommittee_set_vote_threshold_V4))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_release_coordinator_V4(c, &method->nested.technicalcommittee_set_release_coordinator_V4))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_expires_after_V4(c, &method->nested.technicalcommittee_set_expires_after_V4))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_or_propose_V4(c, &method->nested.technicalcommittee_vote_or_propose_V4))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V4(c, &method->nested.technicalcommittee_vote_V4))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_set_active_members_limit_V4(c, &method->nested.technicalcommitteemembership_set_active_members_limit_V4))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_disable_member_V4(c, &method->nested.technicalcommitteemembership_disable_member_V4))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member_V4(c, &method->nested.technicalcommitteemembership_add_member_V4))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member_V4(c, &method->nested.technicalcommitteemembership_remove_member_V4))
        break;
    case 3076: /* module 12 call 4 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member_V4(c, &method->nested.technicalcommitteemembership_swap_member_V4))
        break;
    case 3077: /* module 12 call 5 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members_V4(c, &method->nested.technicalcommitteemembership_reset_members_V4))
        break;
    case 3078: /* module 12 call 6 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_abdicate_membership_V4(c, &method->nested.technicalcommitteemembership_abdicate_membership_V4))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_vote_threshold_V4(c, &method->nested.upgradecommittee_set_vote_threshold_V4))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_release_coordinator_V4(c, &method->nested.upgradecommittee_set_release_coordinator_V4))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_expires_after_V4(c, &method->nested.upgradecommittee_set_expires_after_V4))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_or_propose_V4(c, &method->nested.upgradecommittee_vote_or_propose_V4))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_V4(c, &method->nested.upgradecommittee_vote_V4))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_set_active_members_limit_V4(c, &method->nested.upgradecommitteemembership_set_active_members_limit_V4))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_disable_member_V4(c, &method->nested.upgradecommitteemembership_disable_member_V4))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_add_member_V4(c, &method->nested.upgradecommitteemembership_add_member_V4))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_remove_member_V4(c, &method->nested.upgradecommitteemembership_remove_member_V4))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_swap_member_V4(c, &method->nested.upgradecommitteemembership_swap_member_V4))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_reset_members_V4(c, &method->nested.upgradecommitteemembership_reset_members_V4))
        break;
    case 3590: /* module 14 call 6 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_abdicate_membership_V4(c, &method->nested.upgradecommitteemembership_abdicate_membership_V4))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_identity_V4(c, &method->nested.multisig_create_or_approve_proposal_as_identity_V4))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_identity_V4(c, &method->nested.multisig_create_proposal_as_identity_V4))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_multisig_approve_as_identity_V4(c, &method->nested.multisig_approve_as_identity_V4))
        break;
    case 3847: /* module 15 call 7 */
        CHECK_ERROR(_readMethod_multisig_reject_as_identity_V4(c, &method->nested.multisig_reject_as_identity_V4))
        break;
    case 3849: /* module 15 call 9 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_identity_V4(c, &method->nested.multisig_accept_multisig_signer_as_identity_V4))
        break;
    case 3856: /* module 15 call 16 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_secondary_V4(c, &method->nested.multisig_make_multisig_secondary_V4))
        break;
    case 3858: /* module 15 call 18 */
        CHECK_ERROR(_readMethod_multisig_execute_scheduled_proposal_V4(c, &method->nested.multisig_execute_scheduled_proposal_V4))
        break;
    case 3859: /* module 15 call 19 */
        CHECK_ERROR(_readMethod_multisig_change_sigs_required_via_creator_V4(c, &method->nested.multisig_change_sigs_required_via_creator_V4))
        break;
    case 3860: /* module 15 call 20 */
        CHECK_ERROR(_readMethod_multisig_remove_creator_controls_V4(c, &method->nested.multisig_remove_creator_controls_V4))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_bridge_change_controller_V4(c, &method->nested.bridge_change_controller_V4))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_bridge_change_admin_V4(c, &method->nested.bridge_change_admin_V4))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_bridge_change_timelock_V4(c, &method->nested.bridge_change_timelock_V4))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_bridge_freeze_V4(c, &method->nested.bridge_freeze_V4))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_V4(c, &method->nested.bridge_unfreeze_V4))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_limit_V4(c, &method->nested.bridge_change_bridge_limit_V4))
        break;
    case 4102: /* module 16 call 6 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_exempted_V4(c, &method->nested.bridge_change_bridge_exempted_V4))
        break;
    case 4103: /* module 16 call 7 */
        CHECK_ERROR(_readMethod_bridge_force_handle_bridge_tx_V4(c, &method->nested.bridge_force_handle_bridge_tx_V4))
        break;
    case 4104: /* module 16 call 8 */
        CHECK_ERROR(_readMethod_bridge_batch_propose_bridge_tx_V4(c, &method->basic.bridge_batch_propose_bridge_tx_V4))
        break;
    case 4105: /* module 16 call 9 */
        CHECK_ERROR(_readMethod_bridge_propose_bridge_tx_V4(c, &method->basic.bridge_propose_bridge_tx_V4))
        break;
    case 4106: /* module 16 call 10 */
        CHECK_ERROR(_readMethod_bridge_handle_bridge_tx_V4(c, &method->basic.bridge_handle_bridge_tx_V4))
        break;
    case 4107: /* module 16 call 11 */
        CHECK_ERROR(_readMethod_bridge_freeze_txs_V4(c, &method->basic.bridge_freeze_txs_V4))
        break;
    case 4108: /* module 16 call 12 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_txs_V4(c, &method->basic.bridge_unfreeze_txs_V4))
        break;
    case 4109: /* module 16 call 13 */
        CHECK_ERROR(_readMethod_bridge_handle_scheduled_bridge_tx_V4(c, &method->basic.bridge_handle_scheduled_bridge_tx_V4))
        break;
    case 4110: /* module 16 call 14 */
        CHECK_ERROR(_readMethod_bridge_add_freeze_admin_V4(c, &method->basic.bridge_add_freeze_admin_V4))
        break;
    case 4111: /* module 16 call 15 */
        CHECK_ERROR(_readMethod_bridge_remove_freeze_admin_V4(c, &method->basic.bridge_remove_freeze_admin_V4))
        break;
    case 4112: /* module 16 call 16 */
        CHECK_ERROR(_readMethod_bridge_remove_txs_V4(c, &method->basic.bridge_remove_txs_V4))
        break;
    case 4361: /* module 17 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V4(c, &method->nested.staking_set_validator_count_V4))
        break;
    case 4362: /* module 17 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V4(c, &method->nested.staking_increase_validator_count_V4))
        break;
    case 4363: /* module 17 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V4(c, &method->nested.staking_scale_validator_count_V4))
        break;
    case 4364: /* module 17 call 12 */
        CHECK_ERROR(_readMethod_staking_add_permissioned_validator_V4(c, &method->nested.staking_add_permissioned_validator_V4))
        break;
    case 4365: /* module 17 call 13 */
        CHECK_ERROR(_readMethod_staking_remove_permissioned_validator_V4(c, &method->nested.staking_remove_permissioned_validator_V4))
        break;
    case 4366: /* module 17 call 14 */
        CHECK_ERROR(_readMethod_staking_validate_cdd_expiry_nominators_V4(c, &method->nested.staking_validate_cdd_expiry_nominators_V4))
        break;
    case 4367: /* module 17 call 15 */
        CHECK_ERROR(_readMethod_staking_set_commission_cap_V4(c, &method->nested.staking_set_commission_cap_V4))
        break;
    case 4368: /* module 17 call 16 */
        CHECK_ERROR(_readMethod_staking_set_min_bond_threshold_V4(c, &method->nested.staking_set_min_bond_threshold_V4))
        break;
    case 4369: /* module 17 call 17 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V4(c, &method->nested.staking_force_no_eras_V4))
        break;
    case 4370: /* module 17 call 18 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V4(c, &method->nested.staking_force_new_era_V4))
        break;
    case 4371: /* module 17 call 19 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V4(c, &method->nested.staking_set_invulnerables_V4))
        break;
    case 4372: /* module 17 call 20 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V4(c, &method->nested.staking_force_unstake_V4))
        break;
    case 4373: /* module 17 call 21 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V4(c, &method->nested.staking_force_new_era_always_V4))
        break;
    case 4374: /* module 17 call 22 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V4(c, &method->nested.staking_cancel_deferred_slash_V4))
        break;
    case 4375: /* module 17 call 23 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V4(c, &method->nested.staking_payout_stakers_V4))
        break;
    case 4377: /* module 17 call 25 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V4(c, &method->nested.staking_set_history_depth_V4))
        break;
    case 4378: /* module 17 call 26 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V4(c, &method->nested.staking_reap_stash_V4))
        break;
    case 4381: /* module 17 call 29 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_by_system_V4(c, &method->nested.staking_payout_stakers_by_system_V4))
        break;
    case 4382: /* module 17 call 30 */
        CHECK_ERROR(_readMethod_staking_change_slashing_allowed_for_V4(c, &method->nested.staking_change_slashing_allowed_for_V4))
        break;
    case 4383: /* module 17 call 31 */
        CHECK_ERROR(_readMethod_staking_update_permissioned_validator_intended_count_V4(c, &method->nested.staking_update_permissioned_validator_intended_count_V4))
        break;
    case 4384: /* module 17 call 32 */
        CHECK_ERROR(_readMethod_staking_chill_from_governance_V4(c, &method->nested.staking_chill_from_governance_V4))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V4(c, &method->nested.session_set_keys_V4))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V4(c, &method->nested.session_purge_keys_V4))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_asset_register_ticker_V4(c, &method->nested.asset_register_ticker_V4))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_asset_accept_ticker_transfer_V4(c, &method->nested.asset_accept_ticker_transfer_V4))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_asset_accept_asset_ownership_transfer_V4(c, &method->nested.asset_accept_asset_ownership_transfer_V4))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_asset_create_asset_V4(c, &method->nested.asset_create_asset_V4))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_asset_freeze_V4(c, &method->nested.asset_freeze_V4))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_asset_unfreeze_V4(c, &method->nested.asset_unfreeze_V4))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_asset_rename_asset_V4(c, &method->nested.asset_rename_asset_V4))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_asset_issue_V4(c, &method->nested.asset_issue_V4))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_asset_redeem_V4(c, &method->nested.asset_redeem_V4))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_asset_make_divisible_V4(c, &method->nested.asset_make_divisible_V4))
        break;
    case 6666: /* module 26 call 10 */
        CHECK_ERROR(_readMethod_asset_add_documents_V4(c, &method->nested.asset_add_documents_V4))
        break;
    case 6667: /* module 26 call 11 */
        CHECK_ERROR(_readMethod_asset_remove_documents_V4(c, &method->nested.asset_remove_documents_V4))
        break;
    case 6668: /* module 26 call 12 */
        CHECK_ERROR(_readMethod_asset_set_funding_round_V4(c, &method->nested.asset_set_funding_round_V4))
        break;
    case 6669: /* module 26 call 13 */
        CHECK_ERROR(_readMethod_asset_update_identifiers_V4(c, &method->nested.asset_update_identifiers_V4))
        break;
    case 6670: /* module 26 call 14 */
        CHECK_ERROR(_readMethod_asset_controller_transfer_V4(c, &method->basic.asset_controller_transfer_V4))
        break;
    case 6671: /* module 26 call 15 */
        CHECK_ERROR(_readMethod_asset_register_custom_asset_type_V4(c, &method->basic.asset_register_custom_asset_type_V4))
        break;
    case 6672: /* module 26 call 16 */
        CHECK_ERROR(_readMethod_asset_create_asset_with_custom_type_V4(c, &method->basic.asset_create_asset_with_custom_type_V4))
        break;
    case 6673: /* module 26 call 17 */
        CHECK_ERROR(_readMethod_asset_set_asset_metadata_V4(c, &method->basic.asset_set_asset_metadata_V4))
        break;
    case 6674: /* module 26 call 18 */
        CHECK_ERROR(_readMethod_asset_set_asset_metadata_details_V4(c, &method->basic.asset_set_asset_metadata_details_V4))
        break;
    case 6675: /* module 26 call 19 */
        CHECK_ERROR(_readMethod_asset_register_and_set_local_asset_metadata_V4(c, &method->basic.asset_register_and_set_local_asset_metadata_V4))
        break;
    case 6676: /* module 26 call 20 */
        CHECK_ERROR(_readMethod_asset_register_asset_metadata_local_type_V4(c, &method->basic.asset_register_asset_metadata_local_type_V4))
        break;
    case 6677: /* module 26 call 21 */
        CHECK_ERROR(_readMethod_asset_register_asset_metadata_global_type_V4(c, &method->basic.asset_register_asset_metadata_global_type_V4))
        break;
    case 6678: /* module 26 call 22 */
        CHECK_ERROR(_readMethod_asset_redeem_from_portfolio_V4(c, &method->basic.asset_redeem_from_portfolio_V4))
        break;
    case 6679: /* module 26 call 23 */
        CHECK_ERROR(_readMethod_asset_update_asset_type_V4(c, &method->basic.asset_update_asset_type_V4))
        break;
    case 6680: /* module 26 call 24 */
        CHECK_ERROR(_readMethod_asset_remove_local_metadata_key_V4(c, &method->basic.asset_remove_local_metadata_key_V4))
        break;
    case 6681: /* module 26 call 25 */
        CHECK_ERROR(_readMethod_asset_remove_metadata_value_V4(c, &method->basic.asset_remove_metadata_value_V4))
        break;
    case 6682: /* module 26 call 26 */
        CHECK_ERROR(_readMethod_asset_exempt_ticker_affirmation_V4(c, &method->basic.asset_exempt_ticker_affirmation_V4))
        break;
    case 6683: /* module 26 call 27 */
        CHECK_ERROR(_readMethod_asset_remove_ticker_affirmation_exemption_V4(c, &method->basic.asset_remove_ticker_affirmation_exemption_V4))
        break;
    case 6684: /* module 26 call 28 */
        CHECK_ERROR(_readMethod_asset_pre_approve_ticker_V4(c, &method->basic.asset_pre_approve_ticker_V4))
        break;
    case 6685: /* module 26 call 29 */
        CHECK_ERROR(_readMethod_asset_remove_ticker_pre_approval_V4(c, &method->basic.asset_remove_ticker_pre_approval_V4))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_capitaldistribution_distribute_V4(c, &method->nested.capitaldistribution_distribute_V4))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_capitaldistribution_claim_V4(c, &method->nested.capitaldistribution_claim_V4))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_capitaldistribution_push_benefit_V4(c, &method->nested.capitaldistribution_push_benefit_V4))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_capitaldistribution_reclaim_V4(c, &method->nested.capitaldistribution_reclaim_V4))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_capitaldistribution_remove_distribution_V4(c, &method->nested.capitaldistribution_remove_distribution_V4))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_checkpoint_create_checkpoint_V4(c, &method->nested.checkpoint_create_checkpoint_V4))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_checkpoint_set_schedules_max_complexity_V4(c, &method->nested.checkpoint_set_schedules_max_complexity_V4))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_checkpoint_create_schedule_V4(c, &method->nested.checkpoint_create_schedule_V4))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_checkpoint_remove_schedule_V4(c, &method->nested.checkpoint_remove_schedule_V4))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_compliancemanager_add_compliance_requirement_V4(c, &method->nested.compliancemanager_add_compliance_requirement_V4))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_compliance_requirement_V4(c, &method->nested.compliancemanager_remove_compliance_requirement_V4))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_compliancemanager_replace_asset_compliance_V4(c, &method->nested.compliancemanager_replace_asset_compliance_V4))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_compliancemanager_reset_asset_compliance_V4(c, &method->nested.compliancemanager_reset_asset_compliance_V4))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_compliancemanager_pause_asset_compliance_V4(c, &method->nested.compliancemanager_pause_asset_compliance_V4))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_compliancemanager_resume_asset_compliance_V4(c, &method->nested.compliancemanager_resume_asset_compliance_V4))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_compliancemanager_add_default_trusted_claim_issuer_V4(c, &method->nested.compliancemanager_add_default_trusted_claim_issuer_V4))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_default_trusted_claim_issuer_V4(c, &method->nested.compliancemanager_remove_default_trusted_claim_issuer_V4))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_compliancemanager_change_compliance_requirement_V4(c, &method->nested.compliancemanager_change_compliance_requirement_V4))
        break;
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_pips_set_prune_historical_pips_V4(c, &method->nested.pips_set_prune_historical_pips_V4))
        break;
    case 8449: /* module 33 call 1 */
        CHECK_ERROR(_readMethod_pips_set_min_proposal_deposit_V4(c, &method->nested.pips_set_min_proposal_deposit_V4))
        break;
    case 8450: /* module 33 call 2 */
        CHECK_ERROR(_readMethod_pips_set_default_enactment_period_V4(c, &method->nested.pips_set_default_enactment_period_V4))
        break;
    case 8451: /* module 33 call 3 */
        CHECK_ERROR(_readMethod_pips_set_pending_pip_expiry_V4(c, &method->nested.pips_set_pending_pip_expiry_V4))
        break;
    case 8452: /* module 33 call 4 */
        CHECK_ERROR(_readMethod_pips_set_max_pip_skip_count_V4(c, &method->nested.pips_set_max_pip_skip_count_V4))
        break;
    case 8453: /* module 33 call 5 */
        CHECK_ERROR(_readMethod_pips_set_active_pip_limit_V4(c, &method->nested.pips_set_active_pip_limit_V4))
        break;
    case 8456: /* module 33 call 8 */
        CHECK_ERROR(_readMethod_pips_approve_committee_proposal_V4(c, &method->nested.pips_approve_committee_proposal_V4))
        break;
    case 8457: /* module 33 call 9 */
        CHECK_ERROR(_readMethod_pips_reject_proposal_V4(c, &method->nested.pips_reject_proposal_V4))
        break;
    case 8458: /* module 33 call 10 */
        CHECK_ERROR(_readMethod_pips_prune_proposal_V4(c, &method->nested.pips_prune_proposal_V4))
        break;
    case 8459: /* module 33 call 11 */
        CHECK_ERROR(_readMethod_pips_reschedule_execution_V4(c, &method->nested.pips_reschedule_execution_V4))
        break;
    case 8460: /* module 33 call 12 */
        CHECK_ERROR(_readMethod_pips_clear_snapshot_V4(c, &method->nested.pips_clear_snapshot_V4))
        break;
    case 8461: /* module 33 call 13 */
        CHECK_ERROR(_readMethod_pips_snapshot_V4(c, &method->nested.pips_snapshot_V4))
        break;
    case 8463: /* module 33 call 15 */
        CHECK_ERROR(_readMethod_pips_execute_scheduled_pip_V4(c, &method->nested.pips_execute_scheduled_pip_V4))
        break;
    case 8464: /* module 33 call 16 */
        CHECK_ERROR(_readMethod_pips_expire_scheduled_pip_V4(c, &method->nested.pips_expire_scheduled_pip_V4))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_portfolio_create_portfolio_V4(c, &method->nested.portfolio_create_portfolio_V4))
        break;
    case 8705: /* module 34 call 1 */
        CHECK_ERROR(_readMethod_portfolio_delete_portfolio_V4(c, &method->nested.portfolio_delete_portfolio_V4))
        break;
    case 8706: /* module 34 call 2 */
        CHECK_ERROR(_readMethod_portfolio_rename_portfolio_V4(c, &method->nested.portfolio_rename_portfolio_V4))
        break;
    case 8707: /* module 34 call 3 */
        CHECK_ERROR(_readMethod_portfolio_quit_portfolio_custody_V4(c, &method->basic.portfolio_quit_portfolio_custody_V4))
        break;
    case 8708: /* module 34 call 4 */
        CHECK_ERROR(_readMethod_portfolio_accept_portfolio_custody_V4(c, &method->basic.portfolio_accept_portfolio_custody_V4))
        break;
    case 8709: /* module 34 call 5 */
        CHECK_ERROR(_readMethod_portfolio_move_portfolio_funds_V4(c, &method->nested.portfolio_move_portfolio_funds_V4))
        break;
    case 8710: /* module 34 call 6 */
        CHECK_ERROR(_readMethod_portfolio_pre_approve_portfolio_V4(c, &method->basic.portfolio_pre_approve_portfolio_V4))
        break;
    case 8711: /* module 34 call 7 */
        CHECK_ERROR(_readMethod_portfolio_remove_portfolio_pre_approval_V4(c, &method->basic.portfolio_remove_portfolio_pre_approval_V4))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_protocolfee_change_coefficient_V4(c, &method->nested.protocolfee_change_coefficient_V4))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_settlement_create_venue_V4(c, &method->nested.settlement_create_venue_V4))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_settlement_update_venue_details_V4(c, &method->basic.settlement_update_venue_details_V4))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_settlement_update_venue_type_V4(c, &method->basic.settlement_update_venue_type_V4))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_settlement_affirm_with_receipts_V4(c, &method->nested.settlement_affirm_with_receipts_V4))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_settlement_set_venue_filtering_V4(c, &method->nested.settlement_set_venue_filtering_V4))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_settlement_allow_venues_V4(c, &method->nested.settlement_allow_venues_V4))
        break;
    case 9478: /* module 37 call 6 */
        CHECK_ERROR(_readMethod_settlement_disallow_venues_V4(c, &method->nested.settlement_disallow_venues_V4))
        break;
    case 9479: /* module 37 call 7 */
        CHECK_ERROR(_readMethod_settlement_update_venue_signers_V4(c, &method->basic.settlement_update_venue_signers_V4))
        break;
    case 9480: /* module 37 call 8 */
        CHECK_ERROR(_readMethod_settlement_execute_manual_instruction_V4(c, &method->basic.settlement_execute_manual_instruction_V4))
        break;
    case 9481: /* module 37 call 9 */
        CHECK_ERROR(_readMethod_settlement_add_instruction_V4(c, &method->nested.settlement_add_instruction_V4))
        break;
    case 9482: /* module 37 call 10 */
        CHECK_ERROR(_readMethod_settlement_add_and_affirm_instruction_V4(c, &method->nested.settlement_add_and_affirm_instruction_V4))
        break;
    case 9483: /* module 37 call 11 */
        CHECK_ERROR(_readMethod_settlement_affirm_instruction_V4(c, &method->nested.settlement_affirm_instruction_V4))
        break;
    case 9484: /* module 37 call 12 */
        CHECK_ERROR(_readMethod_settlement_withdraw_affirmation_V4(c, &method->nested.settlement_withdraw_affirmation_V4))
        break;
    case 9485: /* module 37 call 13 */
        CHECK_ERROR(_readMethod_settlement_reject_instruction_V4(c, &method->nested.settlement_reject_instruction_V4))
        break;
    case 9486: /* module 37 call 14 */
        CHECK_ERROR(_readMethod_settlement_execute_scheduled_instruction_V4(c, &method->nested.settlement_execute_scheduled_instruction_V4))
        break;
    case 9984: /* module 39 call 0 */
        CHECK_ERROR(_readMethod_sto_create_fundraiser_V4(c, &method->basic.sto_create_fundraiser_V4))
        break;
    case 9985: /* module 39 call 1 */
        CHECK_ERROR(_readMethod_sto_invest_V4(c, &method->basic.sto_invest_V4))
        break;
    case 9986: /* module 39 call 2 */
        CHECK_ERROR(_readMethod_sto_freeze_fundraiser_V4(c, &method->basic.sto_freeze_fundraiser_V4))
        break;
    case 9987: /* module 39 call 3 */
        CHECK_ERROR(_readMethod_sto_unfreeze_fundraiser_V4(c, &method->basic.sto_unfreeze_fundraiser_V4))
        break;
    case 9988: /* module 39 call 4 */
        CHECK_ERROR(_readMethod_sto_modify_fundraiser_window_V4(c, &method->basic.sto_modify_fundraiser_window_V4))
        break;
    case 9989: /* module 39 call 5 */
        CHECK_ERROR(_readMethod_sto_stop_V4(c, &method->basic.sto_stop_V4))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_treasury_disbursement_V4(c, &method->nested.treasury_disbursement_V4))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_treasury_reimbursement_V4(c, &method->nested.treasury_reimbursement_V4))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_utility_relay_tx_V4(c, &method->nested.utility_relay_tx_V4))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_all_V4(c, &method->basic.utility_batch_all_V4))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_utility_dispatch_as_V4(c, &method->basic.utility_dispatch_as_V4))
        break;
    case 10500: /* module 41 call 4 */
        CHECK_ERROR(_readMethod_utility_force_batch_V4(c, &method->basic.utility_force_batch_V4))
        break;
    case 10501: /* module 41 call 5 */
        CHECK_ERROR(_readMethod_utility_with_weight_V4(c, &method->basic.utility_with_weight_V4))
        break;
    case 10502: /* module 41 call 6 */
        CHECK_ERROR(_readMethod_utility_batch_old_V4(c, &method->basic.utility_batch_old_V4))
        break;
    case 10505: /* module 41 call 9 */
        CHECK_ERROR(_readMethod_utility_as_derivative_V4(c, &method->basic.utility_as_derivative_V4))
        break;
    case 11008: /* module 43 call 0 */
        CHECK_ERROR(_readMethod_externalagents_create_group_V4(c, &method->basic.externalagents_create_group_V4))
        break;
    case 11009: /* module 43 call 1 */
        CHECK_ERROR(_readMethod_externalagents_set_group_permissions_V4(c, &method->basic.externalagents_set_group_permissions_V4))
        break;
    case 11010: /* module 43 call 2 */
        CHECK_ERROR(_readMethod_externalagents_remove_agent_V4(c, &method->basic.externalagents_remove_agent_V4))
        break;
    case 11011: /* module 43 call 3 */
        CHECK_ERROR(_readMethod_externalagents_abdicate_V4(c, &method->basic.externalagents_abdicate_V4))
        break;
    case 11012: /* module 43 call 4 */
        CHECK_ERROR(_readMethod_externalagents_change_group_V4(c, &method->basic.externalagents_change_group_V4))
        break;
    case 11013: /* module 43 call 5 */
        CHECK_ERROR(_readMethod_externalagents_accept_become_agent_V4(c, &method->basic.externalagents_accept_become_agent_V4))
        break;
    case 11014: /* module 43 call 6 */
        CHECK_ERROR(_readMethod_externalagents_create_group_and_add_auth_V4(c, &method->basic.externalagents_create_group_and_add_auth_V4))
        break;
    case 11015: /* module 43 call 7 */
        CHECK_ERROR(_readMethod_externalagents_create_and_change_custom_group_V4(c, &method->basic.externalagents_create_and_change_custom_group_V4))
        break;
    case 11264: /* module 44 call 0 */
        CHECK_ERROR(_readMethod_relayer_set_paying_key_V4(c, &method->basic.relayer_set_paying_key_V4))
        break;
    case 11265: /* module 44 call 1 */
        CHECK_ERROR(_readMethod_relayer_accept_paying_key_V4(c, &method->basic.relayer_accept_paying_key_V4))
        break;
    case 11266: /* module 44 call 2 */
        CHECK_ERROR(_readMethod_relayer_remove_paying_key_V4(c, &method->basic.relayer_remove_paying_key_V4))
        break;
    case 11267: /* module 44 call 3 */
        CHECK_ERROR(_readMethod_relayer_update_polyx_limit_V4(c, &method->basic.relayer_update_polyx_limit_V4))
        break;
    case 11268: /* module 44 call 4 */
        CHECK_ERROR(_readMethod_relayer_increase_polyx_limit_V4(c, &method->basic.relayer_increase_polyx_limit_V4))
        break;
    case 11269: /* module 44 call 5 */
        CHECK_ERROR(_readMethod_relayer_decrease_polyx_limit_V4(c, &method->basic.relayer_decrease_polyx_limit_V4))
        break;
    case 11776: /* module 46 call 0 */
        CHECK_ERROR(_readMethod_contracts_call_old_weight_V4(c, &method->basic.contracts_call_old_weight_V4))
        break;
    case 11777: /* module 46 call 1 */
        CHECK_ERROR(_readMethod_contracts_instantiate_with_code_old_weight_V4(c, &method->basic.contracts_instantiate_with_code_old_weight_V4))
        break;
    case 11778: /* module 46 call 2 */
        CHECK_ERROR(_readMethod_contracts_instantiate_old_weight_V4(c, &method->basic.contracts_instantiate_old_weight_V4))
        break;
    case 11779: /* module 46 call 3 */
        CHECK_ERROR(_readMethod_contracts_upload_code_V4(c, &method->basic.contracts_upload_code_V4))
        break;
    case 11780: /* module 46 call 4 */
        CHECK_ERROR(_readMethod_contracts_remove_code_V4(c, &method->basic.contracts_remove_code_V4))
        break;
    case 11781: /* module 46 call 5 */
        CHECK_ERROR(_readMethod_contracts_set_code_V4(c, &method->basic.contracts_set_code_V4))
        break;
    case 11782: /* module 46 call 6 */
        CHECK_ERROR(_readMethod_contracts_call_V4(c, &method->nested.contracts_call_V4))
        break;
    case 11783: /* module 46 call 7 */
        CHECK_ERROR(_readMethod_contracts_instantiate_with_code_V4(c, &method->basic.contracts_instantiate_with_code_V4))
        break;
    case 11784: /* module 46 call 8 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V4(c, &method->nested.contracts_instantiate_V4))
        break;
    case 12032: /* module 47 call 0 */
        CHECK_ERROR(_readMethod_polymeshcontracts_instantiate_with_code_perms_V4(c, &method->basic.polymeshcontracts_instantiate_with_code_perms_V4))
        break;
    case 12033: /* module 47 call 1 */
        CHECK_ERROR(_readMethod_polymeshcontracts_instantiate_with_hash_perms_V4(c, &method->basic.polymeshcontracts_instantiate_with_hash_perms_V4))
        break;
    case 12034: /* module 47 call 2 */
        CHECK_ERROR(_readMethod_polymeshcontracts_update_call_runtime_whitelist_V4(c, &method->basic.polymeshcontracts_update_call_runtime_whitelist_V4))
        break;
    case 12035: /* module 47 call 3 */
        CHECK_ERROR(_readMethod_polymeshcontracts_instantiate_with_code_as_primary_key_V4(c, &method->basic.polymeshcontracts_instantiate_with_code_as_primary_key_V4))
        break;
    case 12036: /* module 47 call 4 */
        CHECK_ERROR(_readMethod_polymeshcontracts_instantiate_with_hash_as_primary_key_V4(c, &method->basic.polymeshcontracts_instantiate_with_hash_as_primary_key_V4))
        break;
    case 12037: /* module 47 call 5 */
        CHECK_ERROR(_readMethod_polymeshcontracts_upgrade_api_V4(c, &method->basic.polymeshcontracts_upgrade_api_V4))
        break;
    case 12288: /* module 48 call 0 */
        CHECK_ERROR(_readMethod_preimage_note_preimage_V4(c, &method->basic.preimage_note_preimage_V4))
        break;
    case 12289: /* module 48 call 1 */
        CHECK_ERROR(_readMethod_preimage_unnote_preimage_V4(c, &method->basic.preimage_unnote_preimage_V4))
        break;
    case 12290: /* module 48 call 2 */
        CHECK_ERROR(_readMethod_preimage_request_preimage_V4(c, &method->basic.preimage_request_preimage_V4))
        break;
    case 12291: /* module 48 call 3 */
        CHECK_ERROR(_readMethod_preimage_unrequest_preimage_V4(c, &method->basic.preimage_unrequest_preimage_V4))
        break;
    case 12544: /* module 49 call 0 */
        CHECK_ERROR(_readMethod_nft_create_nft_collection_V4(c, &method->basic.nft_create_nft_collection_V4))
        break;
    case 12545: /* module 49 call 1 */
        CHECK_ERROR(_readMethod_nft_issue_nft_V4(c, &method->basic.nft_issue_nft_V4))
        break;
    case 12546: /* module 49 call 2 */
        CHECK_ERROR(_readMethod_nft_redeem_nft_V4(c, &method->basic.nft_redeem_nft_V4))
        break;
#endif
    default:
        return parser_unexpected_callIndex;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V4(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 5:
        return STR_MO_BALANCES;
    case 7:
        return STR_MO_IDENTITY;
    case 15:
        return STR_MO_MULTISIG;
    case 17:
        return STR_MO_STAKING;
    case 33:
        return STR_MO_PIPS;
    case 41:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 30:
        return STR_MO_CORPORATEACTION;
    case 31:
        return STR_MO_CORPORATEBALLOT;
#endif
    case 0:
        return STR_MO_SYSTEM;
    case 2:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_INDICES;
    case 8:
        return STR_MO_CDDSERVICEPROVIDERS;
    case 9:
        return STR_MO_POLYMESHCOMMITTEE;
    case 10:
        return STR_MO_COMMITTEEMEMBERSHIP;
    case 11:
        return STR_MO_TECHNICALCOMMITTEE;
    case 12:
        return STR_MO_TECHNICALCOMMITTEEMEMBERSHIP;
    case 13:
        return STR_MO_UPGRADECOMMITTEE;
    case 14:
        return STR_MO_UPGRADECOMMITTEEMEMBERSHIP;
    case 16:
        return STR_MO_BRIDGE;
    case 19:
        return STR_MO_SESSION;
    case 26:
        return STR_MO_ASSET;
    case 27:
        return STR_MO_CAPITALDISTRIBUTION;
    case 28:
        return STR_MO_CHECKPOINT;
    case 29:
        return STR_MO_COMPLIANCEMANAGER;
    case 34:
        return STR_MO_PORTFOLIO;
    case 35:
        return STR_MO_PROTOCOLFEE;
    case 37:
        return STR_MO_SETTLEMENT;
    case 39:
        return STR_MO_STO;
    case 40:
        return STR_MO_TREASURY;
    case 43:
        return STR_MO_EXTERNALAGENTS;
    case 44:
        return STR_MO_RELAYER;
    case 46:
        return STR_MO_CONTRACTS;
    case 47:
        return STR_MO_POLYMESHCONTRACTS;
    case 48:
        return STR_MO_PREIMAGE;
    case 49:
        return STR_MO_NFT;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V4(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return STR_ME_TRANSFER;
    case 1281: /* module 5 call 1 */
        return STR_ME_TRANSFER_WITH_MEMO;
    case 1794: /* module 7 call 2 */
        return STR_ME_ACCEPT_PRIMARY_KEY;
    case 1796: /* module 7 call 4 */
        return STR_ME_JOIN_IDENTITY_AS_KEY;
    case 1797: /* module 7 call 5 */
        return STR_ME_LEAVE_IDENTITY_AS_KEY;
    case 1798: /* module 7 call 6 */
        return STR_ME_ADD_CLAIM;
    case 1799: /* module 7 call 7 */
        return STR_ME_REVOKE_CLAIM;
    case 1800: /* module 7 call 8 */
        return STR_ME_FREEZE_SECONDARY_KEYS;
    case 1801: /* module 7 call 9 */
        return STR_ME_UNFREEZE_SECONDARY_KEYS;
    case 1802: /* module 7 call 10 */
        return STR_ME_ADD_AUTHORIZATION;
    case 1803: /* module 7 call 11 */
        return STR_ME_REMOVE_AUTHORIZATION;
    case 1808: /* module 7 call 16 */
        return STR_ME_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION;
    case 1810: /* module 7 call 18 */
        return STR_ME_REMOVE_SECONDARY_KEYS;
    case 3840: /* module 15 call 0 */
        return STR_ME_CREATE_MULTISIG;
    case 3842: /* module 15 call 2 */
        return STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_KEY;
    case 3844: /* module 15 call 4 */
        return STR_ME_CREATE_PROPOSAL_AS_KEY;
    case 3846: /* module 15 call 6 */
        return STR_ME_APPROVE_AS_KEY;
    case 3848: /* module 15 call 8 */
        return STR_ME_REJECT_AS_KEY;
    case 3850: /* module 15 call 10 */
        return STR_ME_ACCEPT_MULTISIG_SIGNER_AS_KEY;
    case 3851: /* module 15 call 11 */
        return STR_ME_ADD_MULTISIG_SIGNER;
    case 3852: /* module 15 call 12 */
        return STR_ME_REMOVE_MULTISIG_SIGNER;
    case 3853: /* module 15 call 13 */
        return STR_ME_ADD_MULTISIG_SIGNERS_VIA_CREATOR;
    case 3854: /* module 15 call 14 */
        return STR_ME_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR;
    case 3855: /* module 15 call 15 */
        return STR_ME_CHANGE_SIGS_REQUIRED;
    case 3857: /* module 15 call 17 */
        return STR_ME_MAKE_MULTISIG_PRIMARY;
    case 4352: /* module 17 call 0 */
        return STR_ME_BOND;
    case 4353: /* module 17 call 1 */
        return STR_ME_BOND_EXTRA;
    case 4354: /* module 17 call 2 */
        return STR_ME_UNBOND;
    case 4355: /* module 17 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 4356: /* module 17 call 4 */
        return STR_ME_VALIDATE;
    case 4357: /* module 17 call 5 */
        return STR_ME_NOMINATE;
    case 4358: /* module 17 call 6 */
        return STR_ME_CHILL;
    case 4359: /* module 17 call 7 */
        return STR_ME_SET_PAYEE;
    case 4360: /* module 17 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 4376: /* module 17 call 24 */
        return STR_ME_REBOND;
    case 8454: /* module 33 call 6 */
        return STR_ME_PROPOSE;
    case 8455: /* module 33 call 7 */
        return STR_ME_VOTE;
    case 10496: /* module 41 call 0 */
        return STR_ME_BATCH;
    case 10503: /* module 41 call 7 */
        return STR_ME_BATCH_ATOMIC;
    case 10504: /* module 41 call 8 */
        return STR_ME_BATCH_OPTIMISTIC;
    default:
        return _getMethod_Name_V4_ParserFull(callPrivIdx);
    }

    return NULL;
}

const char* _getMethod_Name_V4_ParserFull(uint16_t callPrivIdx)
{
    switch (callPrivIdx) {
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 6686: /* module 26 call 30 */
        return STR_ME_ADD_MANDATORY_MEDIATORS;
    case 6687: /* module 26 call 31 */
        return STR_ME_REMOVE_MANDATORY_MEDIATORS;
    case 7680: /* module 30 call 0 */
        return STR_ME_SET_MAX_DETAILS_LENGTH;
    case 7681: /* module 30 call 1 */
        return STR_ME_SET_DEFAULT_TARGETS;
    case 7682: /* module 30 call 2 */
        return STR_ME_SET_DEFAULT_WITHHOLDING_TAX;
    case 7683: /* module 30 call 3 */
        return STR_ME_SET_DID_WITHHOLDING_TAX;
    case 7684: /* module 30 call 4 */
        return STR_ME_INITIATE_CORPORATE_ACTION;
    case 7685: /* module 30 call 5 */
        return STR_ME_LINK_CA_DOC;
    case 7686: /* module 30 call 6 */
        return STR_ME_REMOVE_CA;
    case 7687: /* module 30 call 7 */
        return STR_ME_CHANGE_RECORD_DATE;
    case 7688: /* module 30 call 8 */
        return STR_ME_INITIATE_CORPORATE_ACTION_AND_DISTRIBUTE;
    case 7936: /* module 31 call 0 */
        return STR_ME_ATTACH_BALLOT;
    case 7937: /* module 31 call 1 */
        return STR_ME_VOTE;
    case 7938: /* module 31 call 2 */
        return STR_ME_CHANGE_END;
    case 7939: /* module 31 call 3 */
        return STR_ME_CHANGE_META;
    case 7940: /* module 31 call 4 */
        return STR_ME_CHANGE_RCV;
    case 7941: /* module 31 call 5 */
        return STR_ME_REMOVE_BALLOT;
    case 8462: /* module 33 call 14 */
        return STR_ME_ENACT_SNAPSHOT_RESULTS;
    case 8712: /* module 34 call 8 */
        return STR_ME_ALLOW_IDENTITY_TO_CREATE_PORTFOLIOS;
    case 8713: /* module 34 call 9 */
        return STR_ME_REVOKE_CREATE_PORTFOLIOS_PERMISSION;
    case 8714: /* module 34 call 10 */
        return STR_ME_CREATE_CUSTODY_PORTFOLIO;
    case 9487: /* module 37 call 15 */
        return STR_ME_AFFIRM_WITH_RECEIPTS_WITH_COUNT;
    case 9488: /* module 37 call 16 */
        return STR_ME_AFFIRM_INSTRUCTION_WITH_COUNT;
    case 9489: /* module 37 call 17 */
        return STR_ME_REJECT_INSTRUCTION_WITH_COUNT;
    case 9490: /* module 37 call 18 */
        return STR_ME_WITHDRAW_AFFIRMATION_WITH_COUNT;
    case 9491: /* module 37 call 19 */
        return STR_ME_ADD_INSTRUCTION_WITH_MEDIATORS;
    case 9492: /* module 37 call 20 */
        return STR_ME_ADD_AND_AFFIRM_WITH_MEDIATORS;
    case 9493: /* module 37 call 21 */
        return STR_ME_AFFIRM_INSTRUCTION_AS_MEDIATOR;
    case 9494: /* module 37 call 22 */
        return STR_ME_WITHDRAW_AFFIRMATION_AS_MEDIATOR;
    case 9495: /* module 37 call 23 */
        return STR_ME_REJECT_INSTRUCTION_AS_MEDIATOR;
    case 12547: /* module 49 call 3 */
        return STR_ME_CONTROLLER_TRANSFER;
#endif
    case 0: /* module 0 call 0 */
        return STR_ME_REMARK;
    case 1: /* module 0 call 1 */
        return STR_ME_SET_HEAP_PAGES;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_CODE;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 7: /* module 0 call 7 */
        return STR_ME_REMARK_WITH_EVENT;
    case 512: /* module 2 call 0 */
        return STR_ME_SET;
    case 768: /* module 3 call 0 */
        return STR_ME_CLAIM;
    case 769: /* module 3 call 1 */
        return STR_ME_TRANSFER;
    case 770: /* module 3 call 2 */
        return STR_ME_FREE;
    case 771: /* module 3 call 3 */
        return STR_ME_FORCE_TRANSFER;
    case 772: /* module 3 call 4 */
        return STR_ME_FREEZE;
    case 1282: /* module 5 call 2 */
        return STR_ME_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE;
    case 1283: /* module 5 call 3 */
        return STR_ME_SET_BALANCE;
    case 1284: /* module 5 call 4 */
        return STR_ME_FORCE_TRANSFER;
    case 1285: /* module 5 call 5 */
        return STR_ME_BURN_ACCOUNT_BALANCE;
    case 1792: /* module 7 call 0 */
        return STR_ME_CDD_REGISTER_DID;
    case 1793: /* module 7 call 1 */
        return STR_ME_INVALIDATE_CDD_CLAIMS;
    case 1795: /* module 7 call 3 */
        return STR_ME_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION;
    case 1804: /* module 7 call 12 */
        return STR_ME_GC_ADD_CDD_CLAIM;
    case 1805: /* module 7 call 13 */
        return STR_ME_GC_REVOKE_CDD_CLAIM;
    case 1806: /* module 7 call 14 */
        return STR_ME_REVOKE_CLAIM_BY_INDEX;
    case 1807: /* module 7 call 15 */
        return STR_ME_ROTATE_PRIMARY_KEY_TO_SECONDARY;
    case 1809: /* module 7 call 17 */
        return STR_ME_SET_SECONDARY_KEY_PERMISSIONS;
    case 1811: /* module 7 call 19 */
        return STR_ME_REGISTER_CUSTOM_CLAIM_TYPE;
    case 1812: /* module 7 call 20 */
        return STR_ME_CDD_REGISTER_DID_WITH_CDD;
    case 1813: /* module 7 call 21 */
        return STR_ME_CREATE_CHILD_IDENTITY;
    case 1814: /* module 7 call 22 */
        return STR_ME_CREATE_CHILD_IDENTITIES;
    case 1815: /* module 7 call 23 */
        return STR_ME_UNLINK_CHILD_IDENTITY;
    case 2048: /* module 8 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 2049: /* module 8 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 2050: /* module 8 call 2 */
        return STR_ME_ADD_MEMBER;
    case 2051: /* module 8 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 2052: /* module 8 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 2053: /* module 8 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 2054: /* module 8 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 2304: /* module 9 call 0 */
        return STR_ME_SET_VOTE_THRESHOLD;
    case 2305: /* module 9 call 1 */
        return STR_ME_SET_RELEASE_COORDINATOR;
    case 2306: /* module 9 call 2 */
        return STR_ME_SET_EXPIRES_AFTER;
    case 2307: /* module 9 call 3 */
        return STR_ME_VOTE_OR_PROPOSE;
    case 2308: /* module 9 call 4 */
        return STR_ME_VOTE;
    case 2560: /* module 10 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 2561: /* module 10 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 2562: /* module 10 call 2 */
        return STR_ME_ADD_MEMBER;
    case 2563: /* module 10 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 2564: /* module 10 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 2565: /* module 10 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 2566: /* module 10 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 2816: /* module 11 call 0 */
        return STR_ME_SET_VOTE_THRESHOLD;
    case 2817: /* module 11 call 1 */
        return STR_ME_SET_RELEASE_COORDINATOR;
    case 2818: /* module 11 call 2 */
        return STR_ME_SET_EXPIRES_AFTER;
    case 2819: /* module 11 call 3 */
        return STR_ME_VOTE_OR_PROPOSE;
    case 2820: /* module 11 call 4 */
        return STR_ME_VOTE;
    case 3072: /* module 12 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 3073: /* module 12 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 3074: /* module 12 call 2 */
        return STR_ME_ADD_MEMBER;
    case 3075: /* module 12 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 3076: /* module 12 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 3077: /* module 12 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 3078: /* module 12 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 3328: /* module 13 call 0 */
        return STR_ME_SET_VOTE_THRESHOLD;
    case 3329: /* module 13 call 1 */
        return STR_ME_SET_RELEASE_COORDINATOR;
    case 3330: /* module 13 call 2 */
        return STR_ME_SET_EXPIRES_AFTER;
    case 3331: /* module 13 call 3 */
        return STR_ME_VOTE_OR_PROPOSE;
    case 3332: /* module 13 call 4 */
        return STR_ME_VOTE;
    case 3584: /* module 14 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 3585: /* module 14 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 3586: /* module 14 call 2 */
        return STR_ME_ADD_MEMBER;
    case 3587: /* module 14 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 3588: /* module 14 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 3589: /* module 14 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 3590: /* module 14 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 3841: /* module 15 call 1 */
        return STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY;
    case 3843: /* module 15 call 3 */
        return STR_ME_CREATE_PROPOSAL_AS_IDENTITY;
    case 3845: /* module 15 call 5 */
        return STR_ME_APPROVE_AS_IDENTITY;
    case 3847: /* module 15 call 7 */
        return STR_ME_REJECT_AS_IDENTITY;
    case 3849: /* module 15 call 9 */
        return STR_ME_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY;
    case 3856: /* module 15 call 16 */
        return STR_ME_MAKE_MULTISIG_SECONDARY;
    case 3858: /* module 15 call 18 */
        return STR_ME_EXECUTE_SCHEDULED_PROPOSAL;
    case 3859: /* module 15 call 19 */
        return STR_ME_CHANGE_SIGS_REQUIRED_VIA_CREATOR;
    case 3860: /* module 15 call 20 */
        return STR_ME_REMOVE_CREATOR_CONTROLS;
    case 4096: /* module 16 call 0 */
        return STR_ME_CHANGE_CONTROLLER;
    case 4097: /* module 16 call 1 */
        return STR_ME_CHANGE_ADMIN;
    case 4098: /* module 16 call 2 */
        return STR_ME_CHANGE_TIMELOCK;
    case 4099: /* module 16 call 3 */
        return STR_ME_FREEZE;
    case 4100: /* module 16 call 4 */
        return STR_ME_UNFREEZE;
    case 4101: /* module 16 call 5 */
        return STR_ME_CHANGE_BRIDGE_LIMIT;
    case 4102: /* module 16 call 6 */
        return STR_ME_CHANGE_BRIDGE_EXEMPTED;
    case 4103: /* module 16 call 7 */
        return STR_ME_FORCE_HANDLE_BRIDGE_TX;
    case 4104: /* module 16 call 8 */
        return STR_ME_BATCH_PROPOSE_BRIDGE_TX;
    case 4105: /* module 16 call 9 */
        return STR_ME_PROPOSE_BRIDGE_TX;
    case 4106: /* module 16 call 10 */
        return STR_ME_HANDLE_BRIDGE_TX;
    case 4107: /* module 16 call 11 */
        return STR_ME_FREEZE_TXS;
    case 4108: /* module 16 call 12 */
        return STR_ME_UNFREEZE_TXS;
    case 4109: /* module 16 call 13 */
        return STR_ME_HANDLE_SCHEDULED_BRIDGE_TX;
    case 4110: /* module 16 call 14 */
        return STR_ME_ADD_FREEZE_ADMIN;
    case 4111: /* module 16 call 15 */
        return STR_ME_REMOVE_FREEZE_ADMIN;
    case 4112: /* module 16 call 16 */
        return STR_ME_REMOVE_TXS;
    case 4361: /* module 17 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 4362: /* module 17 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 4363: /* module 17 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 4364: /* module 17 call 12 */
        return STR_ME_ADD_PERMISSIONED_VALIDATOR;
    case 4365: /* module 17 call 13 */
        return STR_ME_REMOVE_PERMISSIONED_VALIDATOR;
    case 4366: /* module 17 call 14 */
        return STR_ME_VALIDATE_CDD_EXPIRY_NOMINATORS;
    case 4367: /* module 17 call 15 */
        return STR_ME_SET_COMMISSION_CAP;
    case 4368: /* module 17 call 16 */
        return STR_ME_SET_MIN_BOND_THRESHOLD;
    case 4369: /* module 17 call 17 */
        return STR_ME_FORCE_NO_ERAS;
    case 4370: /* module 17 call 18 */
        return STR_ME_FORCE_NEW_ERA;
    case 4371: /* module 17 call 19 */
        return STR_ME_SET_INVULNERABLES;
    case 4372: /* module 17 call 20 */
        return STR_ME_FORCE_UNSTAKE;
    case 4373: /* module 17 call 21 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 4374: /* module 17 call 22 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 4375: /* module 17 call 23 */
        return STR_ME_PAYOUT_STAKERS;
    case 4377: /* module 17 call 25 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 4378: /* module 17 call 26 */
        return STR_ME_REAP_STASH;
    case 4381: /* module 17 call 29 */
        return STR_ME_PAYOUT_STAKERS_BY_SYSTEM;
    case 4382: /* module 17 call 30 */
        return STR_ME_CHANGE_SLASHING_ALLOWED_FOR;
    case 4383: /* module 17 call 31 */
        return STR_ME_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT;
    case 4384: /* module 17 call 32 */
        return STR_ME_CHILL_FROM_GOVERNANCE;
    case 4864: /* module 19 call 0 */
        return STR_ME_SET_KEYS;
    case 4865: /* module 19 call 1 */
        return STR_ME_PURGE_KEYS;
    case 6656: /* module 26 call 0 */
        return STR_ME_REGISTER_TICKER;
    case 6657: /* module 26 call 1 */
        return STR_ME_ACCEPT_TICKER_TRANSFER;
    case 6658: /* module 26 call 2 */
        return STR_ME_ACCEPT_ASSET_OWNERSHIP_TRANSFER;
    case 6659: /* module 26 call 3 */
        return STR_ME_CREATE_ASSET;
    case 6660: /* module 26 call 4 */
        return STR_ME_FREEZE;
    case 6661: /* module 26 call 5 */
        return STR_ME_UNFREEZE;
    case 6662: /* module 26 call 6 */
        return STR_ME_RENAME_ASSET;
    case 6663: /* module 26 call 7 */
        return STR_ME_ISSUE;
    case 6664: /* module 26 call 8 */
        return STR_ME_REDEEM;
    case 6665: /* module 26 call 9 */
        return STR_ME_MAKE_DIVISIBLE;
    case 6666: /* module 26 call 10 */
        return STR_ME_ADD_DOCUMENTS;
    case 6667: /* module 26 call 11 */
        return STR_ME_REMOVE_DOCUMENTS;
    case 6668: /* module 26 call 12 */
        return STR_ME_SET_FUNDING_ROUND;
    case 6669: /* module 26 call 13 */
        return STR_ME_UPDATE_IDENTIFIERS;
    case 6670: /* module 26 call 14 */
        return STR_ME_CONTROLLER_TRANSFER;
    case 6671: /* module 26 call 15 */
        return STR_ME_REGISTER_CUSTOM_ASSET_TYPE;
    case 6672: /* module 26 call 16 */
        return STR_ME_CREATE_ASSET_WITH_CUSTOM_TYPE;
    case 6673: /* module 26 call 17 */
        return STR_ME_SET_ASSET_METADATA;
    case 6674: /* module 26 call 18 */
        return STR_ME_SET_ASSET_METADATA_DETAILS;
    case 6675: /* module 26 call 19 */
        return STR_ME_REGISTER_AND_SET_LOCAL_ASSET_METADATA;
    case 6676: /* module 26 call 20 */
        return STR_ME_REGISTER_ASSET_METADATA_LOCAL_TYPE;
    case 6677: /* module 26 call 21 */
        return STR_ME_REGISTER_ASSET_METADATA_GLOBAL_TYPE;
    case 6678: /* module 26 call 22 */
        return STR_ME_REDEEM_FROM_PORTFOLIO;
    case 6679: /* module 26 call 23 */
        return STR_ME_UPDATE_ASSET_TYPE;
    case 6680: /* module 26 call 24 */
        return STR_ME_REMOVE_LOCAL_METADATA_KEY;
    case 6681: /* module 26 call 25 */
        return STR_ME_REMOVE_METADATA_VALUE;
    case 6682: /* module 26 call 26 */
        return STR_ME_EXEMPT_TICKER_AFFIRMATION;
    case 6683: /* module 26 call 27 */
        return STR_ME_REMOVE_TICKER_AFFIRMATION_EXEMPTION;
    case 6684: /* module 26 call 28 */
        return STR_ME_PRE_APPROVE_TICKER;
    case 6685: /* module 26 call 29 */
        return STR_ME_REMOVE_TICKER_PRE_APPROVAL;
    case 6912: /* module 27 call 0 */
        return STR_ME_DISTRIBUTE;
    case 6913: /* module 27 call 1 */
        return STR_ME_CLAIM;
    case 6914: /* module 27 call 2 */
        return STR_ME_PUSH_BENEFIT;
    case 6915: /* module 27 call 3 */
        return STR_ME_RECLAIM;
    case 6916: /* module 27 call 4 */
        return STR_ME_REMOVE_DISTRIBUTION;
    case 7168: /* module 28 call 0 */
        return STR_ME_CREATE_CHECKPOINT;
    case 7169: /* module 28 call 1 */
        return STR_ME_SET_SCHEDULES_MAX_COMPLEXITY;
    case 7170: /* module 28 call 2 */
        return STR_ME_CREATE_SCHEDULE;
    case 7171: /* module 28 call 3 */
        return STR_ME_REMOVE_SCHEDULE;
    case 7424: /* module 29 call 0 */
        return STR_ME_ADD_COMPLIANCE_REQUIREMENT;
    case 7425: /* module 29 call 1 */
        return STR_ME_REMOVE_COMPLIANCE_REQUIREMENT;
    case 7426: /* module 29 call 2 */
        return STR_ME_REPLACE_ASSET_COMPLIANCE;
    case 7427: /* module 29 call 3 */
        return STR_ME_RESET_ASSET_COMPLIANCE;
    case 7428: /* module 29 call 4 */
        return STR_ME_PAUSE_ASSET_COMPLIANCE;
    case 7429: /* module 29 call 5 */
        return STR_ME_RESUME_ASSET_COMPLIANCE;
    case 7430: /* module 29 call 6 */
        return STR_ME_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER;
    case 7431: /* module 29 call 7 */
        return STR_ME_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER;
    case 7432: /* module 29 call 8 */
        return STR_ME_CHANGE_COMPLIANCE_REQUIREMENT;
    case 8448: /* module 33 call 0 */
        return STR_ME_SET_PRUNE_HISTORICAL_PIPS;
    case 8449: /* module 33 call 1 */
        return STR_ME_SET_MIN_PROPOSAL_DEPOSIT;
    case 8450: /* module 33 call 2 */
        return STR_ME_SET_DEFAULT_ENACTMENT_PERIOD;
    case 8451: /* module 33 call 3 */
        return STR_ME_SET_PENDING_PIP_EXPIRY;
    case 8452: /* module 33 call 4 */
        return STR_ME_SET_MAX_PIP_SKIP_COUNT;
    case 8453: /* module 33 call 5 */
        return STR_ME_SET_ACTIVE_PIP_LIMIT;
    case 8456: /* module 33 call 8 */
        return STR_ME_APPROVE_COMMITTEE_PROPOSAL;
    case 8457: /* module 33 call 9 */
        return STR_ME_REJECT_PROPOSAL;
    case 8458: /* module 33 call 10 */
        return STR_ME_PRUNE_PROPOSAL;
    case 8459: /* module 33 call 11 */
        return STR_ME_RESCHEDULE_EXECUTION;
    case 8460: /* module 33 call 12 */
        return STR_ME_CLEAR_SNAPSHOT;
    case 8461: /* module 33 call 13 */
        return STR_ME_SNAPSHOT;
    case 8463: /* module 33 call 15 */
        return STR_ME_EXECUTE_SCHEDULED_PIP;
    case 8464: /* module 33 call 16 */
        return STR_ME_EXPIRE_SCHEDULED_PIP;
    case 8704: /* module 34 call 0 */
        return STR_ME_CREATE_PORTFOLIO;
    case 8705: /* module 34 call 1 */
        return STR_ME_DELETE_PORTFOLIO;
    case 8706: /* module 34 call 2 */
        return STR_ME_RENAME_PORTFOLIO;
    case 8707: /* module 34 call 3 */
        return STR_ME_QUIT_PORTFOLIO_CUSTODY;
    case 8708: /* module 34 call 4 */
        return STR_ME_ACCEPT_PORTFOLIO_CUSTODY;
    case 8709: /* module 34 call 5 */
        return STR_ME_MOVE_PORTFOLIO_FUNDS;
    case 8710: /* module 34 call 6 */
        return STR_ME_PRE_APPROVE_PORTFOLIO;
    case 8711: /* module 34 call 7 */
        return STR_ME_REMOVE_PORTFOLIO_PRE_APPROVAL;
    case 8960: /* module 35 call 0 */
        return STR_ME_CHANGE_COEFFICIENT;
    case 9472: /* module 37 call 0 */
        return STR_ME_CREATE_VENUE;
    case 9473: /* module 37 call 1 */
        return STR_ME_UPDATE_VENUE_DETAILS;
    case 9474: /* module 37 call 2 */
        return STR_ME_UPDATE_VENUE_TYPE;
    case 9475: /* module 37 call 3 */
        return STR_ME_AFFIRM_WITH_RECEIPTS;
    case 9476: /* module 37 call 4 */
        return STR_ME_SET_VENUE_FILTERING;
    case 9477: /* module 37 call 5 */
        return STR_ME_ALLOW_VENUES;
    case 9478: /* module 37 call 6 */
        return STR_ME_DISALLOW_VENUES;
    case 9479: /* module 37 call 7 */
        return STR_ME_UPDATE_VENUE_SIGNERS;
    case 9480: /* module 37 call 8 */
        return STR_ME_EXECUTE_MANUAL_INSTRUCTION;
    case 9481: /* module 37 call 9 */
        return STR_ME_ADD_INSTRUCTION;
    case 9482: /* module 37 call 10 */
        return STR_ME_ADD_AND_AFFIRM_INSTRUCTION;
    case 9483: /* module 37 call 11 */
        return STR_ME_AFFIRM_INSTRUCTION;
    case 9484: /* module 37 call 12 */
        return STR_ME_WITHDRAW_AFFIRMATION;
    case 9485: /* module 37 call 13 */
        return STR_ME_REJECT_INSTRUCTION;
    case 9486: /* module 37 call 14 */
        return STR_ME_EXECUTE_SCHEDULED_INSTRUCTION;
    case 9984: /* module 39 call 0 */
        return STR_ME_CREATE_FUNDRAISER;
    case 9985: /* module 39 call 1 */
        return STR_ME_INVEST;
    case 9986: /* module 39 call 2 */
        return STR_ME_FREEZE_FUNDRAISER;
    case 9987: /* module 39 call 3 */
        return STR_ME_UNFREEZE_FUNDRAISER;
    case 9988: /* module 39 call 4 */
        return STR_ME_MODIFY_FUNDRAISER_WINDOW;
    case 9989: /* module 39 call 5 */
        return STR_ME_STOP;
    case 10240: /* module 40 call 0 */
        return STR_ME_DISBURSEMENT;
    case 10241: /* module 40 call 1 */
        return STR_ME_REIMBURSEMENT;
    case 10497: /* module 41 call 1 */
        return STR_ME_RELAY_TX;
    case 10498: /* module 41 call 2 */
        return STR_ME_BATCH_ALL;
    case 10499: /* module 41 call 3 */
        return STR_ME_DISPATCH_AS;
    case 10500: /* module 41 call 4 */
        return STR_ME_FORCE_BATCH;
    case 10501: /* module 41 call 5 */
        return STR_ME_WITH_WEIGHT;
    case 10502: /* module 41 call 6 */
        return STR_ME_BATCH_OLD;
    case 10505: /* module 41 call 9 */
        return STR_ME_AS_DERIVATIVE;
    case 11008: /* module 43 call 0 */
        return STR_ME_CREATE_GROUP;
    case 11009: /* module 43 call 1 */
        return STR_ME_SET_GROUP_PERMISSIONS;
    case 11010: /* module 43 call 2 */
        return STR_ME_REMOVE_AGENT;
    case 11011: /* module 43 call 3 */
        return STR_ME_ABDICATE;
    case 11012: /* module 43 call 4 */
        return STR_ME_CHANGE_GROUP;
    case 11013: /* module 43 call 5 */
        return STR_ME_ACCEPT_BECOME_AGENT;
    case 11014: /* module 43 call 6 */
        return STR_ME_CREATE_GROUP_AND_ADD_AUTH;
    case 11015: /* module 43 call 7 */
        return STR_ME_CREATE_AND_CHANGE_CUSTOM_GROUP;
    case 11264: /* module 44 call 0 */
        return STR_ME_SET_PAYING_KEY;
    case 11265: /* module 44 call 1 */
        return STR_ME_ACCEPT_PAYING_KEY;
    case 11266: /* module 44 call 2 */
        return STR_ME_REMOVE_PAYING_KEY;
    case 11267: /* module 44 call 3 */
        return STR_ME_UPDATE_POLYX_LIMIT;
    case 11268: /* module 44 call 4 */
        return STR_ME_INCREASE_POLYX_LIMIT;
    case 11269: /* module 44 call 5 */
        return STR_ME_DECREASE_POLYX_LIMIT;
    case 11776: /* module 46 call 0 */
        return STR_ME_CALL_OLD_WEIGHT;
    case 11777: /* module 46 call 1 */
        return STR_ME_INSTANTIATE_WITH_CODE_OLD_WEIGHT;
    case 11778: /* module 46 call 2 */
        return STR_ME_INSTANTIATE_OLD_WEIGHT;
    case 11779: /* module 46 call 3 */
        return STR_ME_UPLOAD_CODE;
    case 11780: /* module 46 call 4 */
        return STR_ME_REMOVE_CODE;
    case 11781: /* module 46 call 5 */
        return STR_ME_SET_CODE;
    case 11782: /* module 46 call 6 */
        return STR_ME_CALL;
    case 11783: /* module 46 call 7 */
        return STR_ME_INSTANTIATE_WITH_CODE;
    case 11784: /* module 46 call 8 */
        return STR_ME_INSTANTIATE;
    case 12032: /* module 47 call 0 */
        return STR_ME_INSTANTIATE_WITH_CODE_PERMS;
    case 12033: /* module 47 call 1 */
        return STR_ME_INSTANTIATE_WITH_HASH_PERMS;
    case 12034: /* module 47 call 2 */
        return STR_ME_UPDATE_CALL_RUNTIME_WHITELIST;
    case 12035: /* module 47 call 3 */
        return STR_ME_INSTANTIATE_WITH_CODE_AS_PRIMARY_KEY;
    case 12036: /* module 47 call 4 */
        return STR_ME_INSTANTIATE_WITH_HASH_AS_PRIMARY_KEY;
    case 12037: /* module 47 call 5 */
        return STR_ME_UPGRADE_API;
    case 12288: /* module 48 call 0 */
        return STR_ME_NOTE_PREIMAGE;
    case 12289: /* module 48 call 1 */
        return STR_ME_UNNOTE_PREIMAGE;
    case 12290: /* module 48 call 2 */
        return STR_ME_REQUEST_PREIMAGE;
    case 12291: /* module 48 call 3 */
        return STR_ME_UNREQUEST_PREIMAGE;
    case 12544: /* module 49 call 0 */
        return STR_ME_CREATE_NFT_COLLECTION;
    case 12545: /* module 49 call 1 */
        return STR_ME_ISSUE_NFT;
    case 12546: /* module 49 call 2 */
        return STR_ME_REDEEM_NFT;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V4(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return 2;
    case 1281: /* module 5 call 1 */
        return 3;
    case 1794: /* module 7 call 2 */
        return 2;
    case 1796: /* module 7 call 4 */
        return 1;
    case 1797: /* module 7 call 5 */
        return 0;
    case 1798: /* module 7 call 6 */
        return 3;
    case 1799: /* module 7 call 7 */
        return 2;
    case 1800: /* module 7 call 8 */
        return 0;
    case 1801: /* module 7 call 9 */
        return 0;
    case 1802: /* module 7 call 10 */
        return 3;
    case 1803: /* module 7 call 11 */
        return 3;
    case 1808: /* module 7 call 16 */
        return 2;
    case 1810: /* module 7 call 18 */
        return 1;
    case 3840: /* module 15 call 0 */
        return 2;
    case 3842: /* module 15 call 2 */
        return 4;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3846: /* module 15 call 6 */
        return 2;
    case 3848: /* module 15 call 8 */
        return 2;
    case 3850: /* module 15 call 10 */
        return 1;
    case 3851: /* module 15 call 11 */
        return 1;
    case 3852: /* module 15 call 12 */
        return 1;
    case 3853: /* module 15 call 13 */
        return 2;
    case 3854: /* module 15 call 14 */
        return 2;
    case 3855: /* module 15 call 15 */
        return 1;
    case 3857: /* module 15 call 17 */
        return 2;
    case 4352: /* module 17 call 0 */
        return 3;
    case 4353: /* module 17 call 1 */
        return 1;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 1;
    case 4356: /* module 17 call 4 */
        return 1;
    case 4357: /* module 17 call 5 */
        return 1;
    case 4358: /* module 17 call 6 */
        return 0;
    case 4359: /* module 17 call 7 */
        return 1;
    case 4360: /* module 17 call 8 */
        return 1;
    case 4376: /* module 17 call 24 */
        return 1;
    case 8454: /* module 33 call 6 */
        return 4;
    case 8455: /* module 33 call 7 */
        return 3;
    case 10496: /* module 41 call 0 */
        return 1;
    case 10503: /* module 41 call 7 */
        return 1;
    case 10504: /* module 41 call 8 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 6686: /* module 26 call 30 */
        return 2;
    case 6687: /* module 26 call 31 */
        return 2;
    case 7680: /* module 30 call 0 */
        return 1;
    case 7681: /* module 30 call 1 */
        return 2;
    case 7682: /* module 30 call 2 */
        return 2;
    case 7683: /* module 30 call 3 */
        return 3;
    case 7684: /* module 30 call 4 */
        return 8;
    case 7685: /* module 30 call 5 */
        return 2;
    case 7686: /* module 30 call 6 */
        return 1;
    case 7687: /* module 30 call 7 */
        return 2;
    case 7688: /* module 30 call 8 */
        return 7;
    case 7936: /* module 31 call 0 */
        return 4;
    case 7937: /* module 31 call 1 */
        return 2;
    case 7938: /* module 31 call 2 */
        return 2;
    case 7939: /* module 31 call 3 */
        return 2;
    case 7940: /* module 31 call 4 */
        return 2;
    case 7941: /* module 31 call 5 */
        return 1;
    case 8462: /* module 33 call 14 */
        return 1;
    case 8712: /* module 34 call 8 */
        return 1;
    case 8713: /* module 34 call 9 */
        return 1;
    case 8714: /* module 34 call 10 */
        return 2;
    case 9487: /* module 37 call 15 */
        return 4;
    case 9488: /* module 37 call 16 */
        return 3;
    case 9489: /* module 37 call 17 */
        return 3;
    case 9490: /* module 37 call 18 */
        return 3;
    case 9491: /* module 37 call 19 */
        return 7;
    case 9492: /* module 37 call 20 */
        return 8;
    case 9493: /* module 37 call 21 */
        return 2;
    case 9494: /* module 37 call 22 */
        return 1;
    case 9495: /* module 37 call 23 */
        return 2;
    case 12547: /* module 49 call 3 */
        return 4;
#endif
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 512: /* module 2 call 0 */
        return 1;
    case 768: /* module 3 call 0 */
        return 1;
    case 769: /* module 3 call 1 */
        return 2;
    case 770: /* module 3 call 2 */
        return 1;
    case 771: /* module 3 call 3 */
        return 3;
    case 772: /* module 3 call 4 */
        return 1;
    case 1282: /* module 5 call 2 */
        return 1;
    case 1283: /* module 5 call 3 */
        return 3;
    case 1284: /* module 5 call 4 */
        return 3;
    case 1285: /* module 5 call 5 */
        return 1;
    case 1792: /* module 7 call 0 */
        return 2;
    case 1793: /* module 7 call 1 */
        return 3;
    case 1795: /* module 7 call 3 */
        return 1;
    case 1804: /* module 7 call 12 */
        return 1;
    case 1805: /* module 7 call 13 */
        return 1;
    case 1806: /* module 7 call 14 */
        return 3;
    case 1807: /* module 7 call 15 */
        return 2;
    case 1809: /* module 7 call 17 */
        return 2;
    case 1811: /* module 7 call 19 */
        return 1;
    case 1812: /* module 7 call 20 */
        return 3;
    case 1813: /* module 7 call 21 */
        return 1;
    case 1814: /* module 7 call 22 */
        return 2;
    case 1815: /* module 7 call 23 */
        return 1;
    case 2048: /* module 8 call 0 */
        return 1;
    case 2049: /* module 8 call 1 */
        return 3;
    case 2050: /* module 8 call 2 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 2;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 0;
    case 2304: /* module 9 call 0 */
        return 2;
    case 2305: /* module 9 call 1 */
        return 1;
    case 2306: /* module 9 call 2 */
        return 1;
    case 2307: /* module 9 call 3 */
        return 2;
    case 2308: /* module 9 call 4 */
        return 3;
    case 2560: /* module 10 call 0 */
        return 1;
    case 2561: /* module 10 call 1 */
        return 3;
    case 2562: /* module 10 call 2 */
        return 1;
    case 2563: /* module 10 call 3 */
        return 1;
    case 2564: /* module 10 call 4 */
        return 2;
    case 2565: /* module 10 call 5 */
        return 1;
    case 2566: /* module 10 call 6 */
        return 0;
    case 2816: /* module 11 call 0 */
        return 2;
    case 2817: /* module 11 call 1 */
        return 1;
    case 2818: /* module 11 call 2 */
        return 1;
    case 2819: /* module 11 call 3 */
        return 2;
    case 2820: /* module 11 call 4 */
        return 3;
    case 3072: /* module 12 call 0 */
        return 1;
    case 3073: /* module 12 call 1 */
        return 3;
    case 3074: /* module 12 call 2 */
        return 1;
    case 3075: /* module 12 call 3 */
        return 1;
    case 3076: /* module 12 call 4 */
        return 2;
    case 3077: /* module 12 call 5 */
        return 1;
    case 3078: /* module 12 call 6 */
        return 0;
    case 3328: /* module 13 call 0 */
        return 2;
    case 3329: /* module 13 call 1 */
        return 1;
    case 3330: /* module 13 call 2 */
        return 1;
    case 3331: /* module 13 call 3 */
        return 2;
    case 3332: /* module 13 call 4 */
        return 3;
    case 3584: /* module 14 call 0 */
        return 1;
    case 3585: /* module 14 call 1 */
        return 3;
    case 3586: /* module 14 call 2 */
        return 1;
    case 3587: /* module 14 call 3 */
        return 1;
    case 3588: /* module 14 call 4 */
        return 2;
    case 3589: /* module 14 call 5 */
        return 1;
    case 3590: /* module 14 call 6 */
        return 0;
    case 3841: /* module 15 call 1 */
        return 4;
    case 3843: /* module 15 call 3 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 2;
    case 3847: /* module 15 call 7 */
        return 2;
    case 3849: /* module 15 call 9 */
        return 1;
    case 3856: /* module 15 call 16 */
        return 1;
    case 3858: /* module 15 call 18 */
        return 4;
    case 3859: /* module 15 call 19 */
        return 2;
    case 3860: /* module 15 call 20 */
        return 1;
    case 4096: /* module 16 call 0 */
        return 1;
    case 4097: /* module 16 call 1 */
        return 1;
    case 4098: /* module 16 call 2 */
        return 1;
    case 4099: /* module 16 call 3 */
        return 0;
    case 4100: /* module 16 call 4 */
        return 0;
    case 4101: /* module 16 call 5 */
        return 2;
    case 4102: /* module 16 call 6 */
        return 1;
    case 4103: /* module 16 call 7 */
        return 1;
    case 4104: /* module 16 call 8 */
        return 1;
    case 4105: /* module 16 call 9 */
        return 1;
    case 4106: /* module 16 call 10 */
        return 1;
    case 4107: /* module 16 call 11 */
        return 1;
    case 4108: /* module 16 call 12 */
        return 1;
    case 4109: /* module 16 call 13 */
        return 1;
    case 4110: /* module 16 call 14 */
        return 1;
    case 4111: /* module 16 call 15 */
        return 1;
    case 4112: /* module 16 call 16 */
        return 1;
    case 4361: /* module 17 call 9 */
        return 1;
    case 4362: /* module 17 call 10 */
        return 1;
    case 4363: /* module 17 call 11 */
        return 1;
    case 4364: /* module 17 call 12 */
        return 2;
    case 4365: /* module 17 call 13 */
        return 1;
    case 4366: /* module 17 call 14 */
        return 1;
    case 4367: /* module 17 call 15 */
        return 1;
    case 4368: /* module 17 call 16 */
        return 1;
    case 4369: /* module 17 call 17 */
        return 0;
    case 4370: /* module 17 call 18 */
        return 0;
    case 4371: /* module 17 call 19 */
        return 1;
    case 4372: /* module 17 call 20 */
        return 2;
    case 4373: /* module 17 call 21 */
        return 0;
    case 4374: /* module 17 call 22 */
        return 2;
    case 4375: /* module 17 call 23 */
        return 2;
    case 4377: /* module 17 call 25 */
        return 2;
    case 4378: /* module 17 call 26 */
        return 2;
    case 4381: /* module 17 call 29 */
        return 2;
    case 4382: /* module 17 call 30 */
        return 1;
    case 4383: /* module 17 call 31 */
        return 2;
    case 4384: /* module 17 call 32 */
        return 2;
    case 4864: /* module 19 call 0 */
        return 2;
    case 4865: /* module 19 call 1 */
        return 0;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 1;
    case 6659: /* module 26 call 3 */
        return 6;
    case 6660: /* module 26 call 4 */
        return 1;
    case 6661: /* module 26 call 5 */
        return 1;
    case 6662: /* module 26 call 6 */
        return 2;
    case 6663: /* module 26 call 7 */
        return 3;
    case 6664: /* module 26 call 8 */
        return 2;
    case 6665: /* module 26 call 9 */
        return 1;
    case 6666: /* module 26 call 10 */
        return 2;
    case 6667: /* module 26 call 11 */
        return 2;
    case 6668: /* module 26 call 12 */
        return 2;
    case 6669: /* module 26 call 13 */
        return 2;
    case 6670: /* module 26 call 14 */
        return 3;
    case 6671: /* module 26 call 15 */
        return 1;
    case 6672: /* module 26 call 16 */
        return 6;
    case 6673: /* module 26 call 17 */
        return 4;
    case 6674: /* module 26 call 18 */
        return 3;
    case 6675: /* module 26 call 19 */
        return 5;
    case 6676: /* module 26 call 20 */
        return 3;
    case 6677: /* module 26 call 21 */
        return 2;
    case 6678: /* module 26 call 22 */
        return 3;
    case 6679: /* module 26 call 23 */
        return 2;
    case 6680: /* module 26 call 24 */
        return 2;
    case 6681: /* module 26 call 25 */
        return 2;
    case 6682: /* module 26 call 26 */
        return 1;
    case 6683: /* module 26 call 27 */
        return 1;
    case 6684: /* module 26 call 28 */
        return 1;
    case 6685: /* module 26 call 29 */
        return 1;
    case 6912: /* module 27 call 0 */
        return 7;
    case 6913: /* module 27 call 1 */
        return 1;
    case 6914: /* module 27 call 2 */
        return 2;
    case 6915: /* module 27 call 3 */
        return 1;
    case 6916: /* module 27 call 4 */
        return 1;
    case 7168: /* module 28 call 0 */
        return 1;
    case 7169: /* module 28 call 1 */
        return 1;
    case 7170: /* module 28 call 2 */
        return 2;
    case 7171: /* module 28 call 3 */
        return 2;
    case 7424: /* module 29 call 0 */
        return 3;
    case 7425: /* module 29 call 1 */
        return 2;
    case 7426: /* module 29 call 2 */
        return 2;
    case 7427: /* module 29 call 3 */
        return 1;
    case 7428: /* module 29 call 4 */
        return 1;
    case 7429: /* module 29 call 5 */
        return 1;
    case 7430: /* module 29 call 6 */
        return 2;
    case 7431: /* module 29 call 7 */
        return 2;
    case 7432: /* module 29 call 8 */
        return 2;
    case 8448: /* module 33 call 0 */
        return 1;
    case 8449: /* module 33 call 1 */
        return 1;
    case 8450: /* module 33 call 2 */
        return 1;
    case 8451: /* module 33 call 3 */
        return 1;
    case 8452: /* module 33 call 4 */
        return 1;
    case 8453: /* module 33 call 5 */
        return 1;
    case 8456: /* module 33 call 8 */
        return 1;
    case 8457: /* module 33 call 9 */
        return 1;
    case 8458: /* module 33 call 10 */
        return 1;
    case 8459: /* module 33 call 11 */
        return 2;
    case 8460: /* module 33 call 12 */
        return 0;
    case 8461: /* module 33 call 13 */
        return 0;
    case 8463: /* module 33 call 15 */
        return 1;
    case 8464: /* module 33 call 16 */
        return 2;
    case 8704: /* module 34 call 0 */
        return 1;
    case 8705: /* module 34 call 1 */
        return 1;
    case 8706: /* module 34 call 2 */
        return 2;
    case 8707: /* module 34 call 3 */
        return 1;
    case 8708: /* module 34 call 4 */
        return 1;
    case 8709: /* module 34 call 5 */
        return 3;
    case 8710: /* module 34 call 6 */
        return 2;
    case 8711: /* module 34 call 7 */
        return 2;
    case 8960: /* module 35 call 0 */
        return 1;
    case 9472: /* module 37 call 0 */
        return 3;
    case 9473: /* module 37 call 1 */
        return 2;
    case 9474: /* module 37 call 2 */
        return 2;
    case 9475: /* module 37 call 3 */
        return 3;
    case 9476: /* module 37 call 4 */
        return 2;
    case 9477: /* module 37 call 5 */
        return 2;
    case 9478: /* module 37 call 6 */
        return 2;
    case 9479: /* module 37 call 7 */
        return 3;
    case 9480: /* module 37 call 8 */
        return 6;
    case 9481: /* module 37 call 9 */
        return 6;
    case 9482: /* module 37 call 10 */
        return 7;
    case 9483: /* module 37 call 11 */
        return 2;
    case 9484: /* module 37 call 12 */
        return 2;
    case 9485: /* module 37 call 13 */
        return 2;
    case 9486: /* module 37 call 14 */
        return 2;
    case 9984: /* module 39 call 0 */
        return 10;
    case 9985: /* module 39 call 1 */
        return 7;
    case 9986: /* module 39 call 2 */
        return 2;
    case 9987: /* module 39 call 3 */
        return 2;
    case 9988: /* module 39 call 4 */
        return 4;
    case 9989: /* module 39 call 5 */
        return 2;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10241: /* module 40 call 1 */
        return 1;
    case 10497: /* module 41 call 1 */
        return 3;
    case 10498: /* module 41 call 2 */
        return 1;
    case 10499: /* module 41 call 3 */
        return 2;
    case 10500: /* module 41 call 4 */
        return 1;
    case 10501: /* module 41 call 5 */
        return 2;
    case 10502: /* module 41 call 6 */
        return 1;
    case 10505: /* module 41 call 9 */
        return 2;
    case 11008: /* module 43 call 0 */
        return 2;
    case 11009: /* module 43 call 1 */
        return 3;
    case 11010: /* module 43 call 2 */
        return 2;
    case 11011: /* module 43 call 3 */
        return 1;
    case 11012: /* module 43 call 4 */
        return 3;
    case 11013: /* module 43 call 5 */
        return 1;
    case 11014: /* module 43 call 6 */
        return 4;
    case 11015: /* module 43 call 7 */
        return 3;
    case 11264: /* module 44 call 0 */
        return 2;
    case 11265: /* module 44 call 1 */
        return 1;
    case 11266: /* module 44 call 2 */
        return 2;
    case 11267: /* module 44 call 3 */
        return 2;
    case 11268: /* module 44 call 4 */
        return 2;
    case 11269: /* module 44 call 5 */
        return 2;
    case 11776: /* module 46 call 0 */
        return 5;
    case 11777: /* module 46 call 1 */
        return 6;
    case 11778: /* module 46 call 2 */
        return 6;
    case 11779: /* module 46 call 3 */
        return 3;
    case 11780: /* module 46 call 4 */
        return 1;
    case 11781: /* module 46 call 5 */
        return 2;
    case 11782: /* module 46 call 6 */
        return 5;
    case 11783: /* module 46 call 7 */
        return 6;
    case 11784: /* module 46 call 8 */
        return 6;
    case 12032: /* module 47 call 0 */
        return 7;
    case 12033: /* module 47 call 1 */
        return 7;
    case 12034: /* module 47 call 2 */
        return 1;
    case 12035: /* module 47 call 3 */
        return 6;
    case 12036: /* module 47 call 4 */
        return 6;
    case 12037: /* module 47 call 5 */
        return 2;
    case 12288: /* module 48 call 0 */
        return 1;
    case 12289: /* module 48 call 1 */
        return 1;
    case 12290: /* module 48 call 2 */
        return 1;
    case 12291: /* module 48 call 3 */
        return 1;
    case 12544: /* module 49 call 0 */
        return 3;
    case 12545: /* module 49 call 1 */
        return 3;
    case 12546: /* module 49 call 2 */
        return 3;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V4(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_memo;
        default:
            return NULL;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rotation_auth_id;
        case 1:
            return STR_IT_optional_cdd_auth_id;
        default:
            return NULL;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_claim;
        case 2:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_claim;
        default:
            return NULL;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_data;
        case 2:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_auth_id;
        case 2:
            return STR_IT__auth_issuer_pays;
        default:
            return NULL;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional_keys;
        case 1:
            return STR_IT_expires_at;
        default:
            return NULL;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys_to_remove;
        default:
            return NULL;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signers;
        case 1:
            return STR_IT_sigs_required;
        default:
            return NULL;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_expiry;
        case 3:
            return STR_IT_auto_close;
        default:
            return NULL;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_expiry;
        case 3:
            return STR_IT_auto_close;
        default:
            return NULL;
        }
    case 3846: /* module 15 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3848: /* module 15 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3850: /* module 15 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 3851: /* module 15 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        default:
            return NULL;
        }
    case 3852: /* module 15 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        default:
            return NULL;
        }
    case 3853: /* module 15 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_signers;
        default:
            return NULL;
        }
    case 3854: /* module 15 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_signers;
        default:
            return NULL;
        }
    case 3855: /* module 15 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sigs_required;
        default:
            return NULL;
        }
    case 3857: /* module 15 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_optional_cdd_auth_id;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4359: /* module 17 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 4360: /* module 17 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 4376: /* module 17 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 8454: /* module 33 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_deposit;
        case 2:
            return STR_IT_url;
        case 3:
            return STR_IT_description;
        default:
            return NULL;
        }
    case 8455: /* module 33 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_aye_or_nay;
        case 2:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10503: /* module 41 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10504: /* module 41 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 6686: /* module 26 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_mediators;
        default:
            return NULL;
        }
    case 6687: /* module 26 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_mediators;
        default:
            return NULL;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_length;
        default:
            return NULL;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_tax;
        default:
            return NULL;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_taxed_did;
        case 2:
            return STR_IT_tax;
        default:
            return NULL;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_kind;
        case 2:
            return STR_IT_decl_date;
        case 3:
            return STR_IT_record_date;
        case 4:
            return STR_IT_details;
        case 5:
            return STR_IT_targets;
        case 6:
            return STR_IT_default_withholding_tax;
        case 7:
            return STR_IT_withholding_tax;
        default:
            return NULL;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_docs;
        default:
            return NULL;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_record_date;
        default:
            return NULL;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_args;
        case 1:
            return STR_IT_portfolio;
        case 2:
            return STR_IT_currency;
        case 3:
            return STR_IT_per_share;
        case 4:
            return STR_IT_amount;
        case 5:
            return STR_IT_payment_at;
        case 6:
            return STR_IT_expires_at;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_range;
        case 2:
            return STR_IT_meta;
        case 3:
            return STR_IT_rcv;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_votes;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_end;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_meta;
        default:
            return NULL;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_rcv;
        default:
            return NULL;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 8462: /* module 33 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_results;
        default:
            return NULL;
        }
    case 8712: /* module 34 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_trusted_identity;
        default:
            return NULL;
        }
    case 8713: /* module 34 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        default:
            return NULL;
        }
    case 8714: /* module 34 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_portfolio_owner_id;
        case 1:
            return STR_IT_portfolio_name;
        default:
            return NULL;
        }
    case 9487: /* module 37 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_receipt_details;
        case 2:
            return STR_IT_portfolios;
        case 3:
            return STR_IT_number_of_assets;
        default:
            return NULL;
        }
    case 9488: /* module 37 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolios;
        case 2:
            return STR_IT_number_of_assets;
        default:
            return NULL;
        }
    case 9489: /* module 37 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolio;
        case 2:
            return STR_IT_number_of_assets;
        default:
            return NULL;
        }
    case 9490: /* module 37 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolios;
        case 2:
            return STR_IT_number_of_assets;
        default:
            return NULL;
        }
    case 9491: /* module 37 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_venue_id;
        case 1:
            return STR_IT_settlement_type;
        case 2:
            return STR_IT_trade_date;
        case 3:
            return STR_IT_value_date;
        case 4:
            return STR_IT_legs;
        case 5:
            return STR_IT_instruction_memo;
        case 6:
            return STR_IT_mediators;
        default:
            return NULL;
        }
    case 9492: /* module 37 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_venue_id;
        case 1:
            return STR_IT_settlement_type;
        case 2:
            return STR_IT_trade_date;
        case 3:
            return STR_IT_value_date;
        case 4:
            return STR_IT_legs;
        case 5:
            return STR_IT_portfolios;
        case 6:
            return STR_IT_instruction_memo;
        case 7:
            return STR_IT_mediators;
        default:
            return NULL;
        }
    case 9493: /* module 37 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 9494: /* module 37 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        default:
            return NULL;
        }
    case 9495: /* module 37 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_number_of_assets;
        default:
            return NULL;
        }
    case 12547: /* module 49 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_nfts;
        case 2:
            return STR_IT_source_portfolio;
        case 3:
            return STR_IT_callers_portfolio_kind;
        default:
            return NULL;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remark;
        default:
            return NULL;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_now;
        default:
            return NULL;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_freeze;
        default:
            return NULL;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_new_free;
        case 2:
            return STR_IT_new_reserved;
        default:
            return NULL;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target_account;
        case 1:
            return STR_IT_secondary_keys;
        default:
            return NULL;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_cdd;
        case 1:
            return STR_IT_disable_from;
        case 2:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_required;
        default:
            return NULL;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 1805: /* module 7 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 1806: /* module 7 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_claim_type;
        case 2:
            return STR_IT_scope;
        default:
            return NULL;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        case 1:
            return STR_IT_optional_cdd_auth_id;
        default:
            return NULL;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_key;
        case 1:
            return STR_IT_perms;
        default:
            return NULL;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ty;
        default:
            return NULL;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target_account;
        case 1:
            return STR_IT_secondary_keys;
        case 2:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_secondary_key;
        default:
            return NULL;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_child_keys;
        case 1:
            return STR_IT_expires_at;
        default:
            return NULL;
        }
    case 1815: /* module 7 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_child_did;
        default:
            return NULL;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_expiry;
        case 2:
            return STR_IT_at;
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_n;
        case 1:
            return STR_IT_d;
        default:
            return NULL;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_expiry;
        case 2:
            return STR_IT_at;
        default:
            return NULL;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_n;
        case 1:
            return STR_IT_d;
        default:
            return NULL;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_expiry;
        case 2:
            return STR_IT_at;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 3078: /* module 12 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_n;
        case 1:
            return STR_IT_d;
        default:
            return NULL;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_proposal;
        case 1:
            return STR_IT_index;
        case 2:
            return STR_IT_approve;
        default:
            return NULL;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_expiry;
        case 2:
            return STR_IT_at;
        default:
            return NULL;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_expiry;
        case 3:
            return STR_IT_auto_close;
        default:
            return NULL;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal;
        case 2:
            return STR_IT_expiry;
        case 3:
            return STR_IT_auto_close;
        default:
            return NULL;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3847: /* module 15 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 3849: /* module 15 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT__auth_id;
        default:
            return NULL;
        }
    case 3856: /* module 15 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        default:
            return NULL;
        }
    case 3858: /* module 15 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        case 2:
            return STR_IT_multisig_did;
        case 3:
            return STR_IT__proposal_weight;
        default:
            return NULL;
        }
    case 3859: /* module 15 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig_account;
        case 1:
            return STR_IT_signatures_required;
        default:
            return NULL;
        }
    case 3860: /* module 15 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig_account;
        default:
            return NULL;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_admin;
        default:
            return NULL;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_timelock;
        default:
            return NULL;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_exempted;
        default:
            return NULL;
        }
    case 4103: /* module 16 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 4104: /* module 16 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_txs;
        default:
            return NULL;
        }
    case 4105: /* module 16 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 4106: /* module 16 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 4107: /* module 16 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_txs;
        default:
            return NULL;
        }
    case 4108: /* module 16 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_txs;
        default:
            return NULL;
        }
    case 4109: /* module 16 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 4110: /* module 16 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_freeze_admin;
        default:
            return NULL;
        }
    case 4111: /* module 16 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_freeze_admin;
        default:
            return NULL;
        }
    case 4112: /* module 16 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_txs;
        default:
            return NULL;
        }
    case 4361: /* module 17 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4362: /* module 17 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 4363: /* module 17 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 4364: /* module 17 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        case 1:
            return STR_IT_intended_count;
        default:
            return NULL;
        }
    case 4365: /* module 17 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        default:
            return NULL;
        }
    case 4366: /* module 17 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 4367: /* module 17 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_cap;
        default:
            return NULL;
        }
    case 4368: /* module 17 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_value;
        default:
            return NULL;
        }
    case 4369: /* module 17 call 17 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4370: /* module 17 call 18 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4371: /* module 17 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_invulnerables;
        default:
            return NULL;
        }
    case 4372: /* module 17 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4373: /* module 17 call 21 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 4374: /* module 17 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 4375: /* module 17 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 4377: /* module 17 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT_era_items_deleted;
        default:
            return NULL;
        }
    case 4378: /* module 17 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 4381: /* module 17 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 4382: /* module 17 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_slashing_switch;
        default:
            return NULL;
        }
    case 4383: /* module 17 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        case 1:
            return STR_IT_new_intended_count;
        default:
            return NULL;
        }
    case 4384: /* module 17 call 32 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        case 1:
            return STR_IT_stash_keys;
        default:
            return NULL;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_name;
        case 1:
            return STR_IT_ticker;
        case 2:
            return STR_IT_divisible;
        case 3:
            return STR_IT_asset_type;
        case 4:
            return STR_IT_identifiers;
        case 5:
            return STR_IT_funding_round;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_portfolio_kind;
        default:
            return NULL;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6666: /* module 26 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_docs;
        case 1:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ids;
        case 1:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6668: /* module 26 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 6669: /* module 26 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_asset_identifiers;
        default:
            return NULL;
        }
    case 6670: /* module 26 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_from_portfolio;
        default:
            return NULL;
        }
    case 6671: /* module 26 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ty;
        default:
            return NULL;
        }
    case 6672: /* module 26 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_name;
        case 1:
            return STR_IT_ticker;
        case 2:
            return STR_IT_divisible;
        case 3:
            return STR_IT_custom_asset_type;
        case 4:
            return STR_IT_identifiers;
        case 5:
            return STR_IT_funding_round;
        default:
            return NULL;
        }
    case 6673: /* module 26 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_key;
        case 2:
            return STR_IT_value;
        case 3:
            return STR_IT_detail;
        default:
            return NULL;
        }
    case 6674: /* module 26 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_key;
        case 2:
            return STR_IT_detail;
        default:
            return NULL;
        }
    case 6675: /* module 26 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_spec;
        case 3:
            return STR_IT_value;
        case 4:
            return STR_IT_detail;
        default:
            return NULL;
        }
    case 6676: /* module 26 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_name;
        case 2:
            return STR_IT_spec;
        default:
            return NULL;
        }
    case 6677: /* module 26 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_name;
        case 1:
            return STR_IT_spec;
        default:
            return NULL;
        }
    case 6678: /* module 26 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_portfolio;
        default:
            return NULL;
        }
    case 6679: /* module 26 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_asset_type;
        default:
            return NULL;
        }
    case 6680: /* module 26 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_local_key;
        default:
            return NULL;
        }
    case 6681: /* module 26 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_metadata_key;
        default:
            return NULL;
        }
    case 6682: /* module 26 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6683: /* module 26 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6684: /* module 26 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6685: /* module 26 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_portfolio;
        case 2:
            return STR_IT_currency;
        case 3:
            return STR_IT_per_share;
        case 4:
            return STR_IT_amount;
        case 5:
            return STR_IT_payment_at;
        case 6:
            return STR_IT_expires_at;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_holder;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_complexity;
        default:
            return NULL;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_sender_conditions;
        case 2:
            return STR_IT_receiver_conditions;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_asset_compliance;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_issuer;
        default:
            return NULL;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_issuer;
        default:
            return NULL;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_new_req;
        default:
            return NULL;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prune;
        default:
            return NULL;
        }
    case 8449: /* module 33 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 8450: /* module 33 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 8451: /* module 33 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 8452: /* module 33 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 8453: /* module 33 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 8456: /* module 33 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8457: /* module 33 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8458: /* module 33 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8459: /* module 33 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_until;
        default:
            return NULL;
        }
    case 8460: /* module 33 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8461: /* module 33 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 8463: /* module 33 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8464: /* module 33 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_did;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num;
        default:
            return NULL;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num;
        case 1:
            return STR_IT_to_name;
        default:
            return NULL;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pid;
        default:
            return NULL;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_from;
        case 1:
            return STR_IT_to;
        case 2:
            return STR_IT_funds;
        default:
            return NULL;
        }
    case 8710: /* module 34 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_portfolio_id;
        default:
            return NULL;
        }
    case 8711: /* module 34 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_portfolio_id;
        default:
            return NULL;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_coefficient;
        default:
            return NULL;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_details;
        case 1:
            return STR_IT_signers;
        case 2:
            return STR_IT_typ;
        default:
            return NULL;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_details;
        default:
            return NULL;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_typ;
        default:
            return NULL;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_receipt_details;
        case 2:
            return STR_IT_portfolios;
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_enabled;
        default:
            return NULL;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_venues;
        default:
            return NULL;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_venues;
        default:
            return NULL;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_signers;
        case 2:
            return STR_IT_add_signers;
        default:
            return NULL;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolio;
        case 2:
            return STR_IT_fungible_transfers;
        case 3:
            return STR_IT_nfts_transfers;
        case 4:
            return STR_IT_offchain_transfers;
        case 5:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 9481: /* module 37 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_venue_id;
        case 1:
            return STR_IT_settlement_type;
        case 2:
            return STR_IT_trade_date;
        case 3:
            return STR_IT_value_date;
        case 4:
            return STR_IT_legs;
        case 5:
            return STR_IT_instruction_memo;
        default:
            return NULL;
        }
    case 9482: /* module 37 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_venue_id;
        case 1:
            return STR_IT_settlement_type;
        case 2:
            return STR_IT_trade_date;
        case 3:
            return STR_IT_value_date;
        case 4:
            return STR_IT_legs;
        case 5:
            return STR_IT_portfolios;
        case 6:
            return STR_IT_instruction_memo;
        default:
            return NULL;
        }
    case 9483: /* module 37 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolios;
        default:
            return NULL;
        }
    case 9484: /* module 37 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolios;
        default:
            return NULL;
        }
    case 9485: /* module 37 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolio;
        default:
            return NULL;
        }
    case 9486: /* module 37 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_weight_limit;
        default:
            return NULL;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_portfolio;
        case 1:
            return STR_IT_offering_asset;
        case 2:
            return STR_IT_raising_portfolio;
        case 3:
            return STR_IT_raising_asset;
        case 4:
            return STR_IT_tiers;
        case 5:
            return STR_IT_venue_id;
        case 6:
            return STR_IT_start;
        case 7:
            return STR_IT_end;
        case 8:
            return STR_IT_minimum_investment;
        case 9:
            return STR_IT_fundraiser_name;
        default:
            return NULL;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_investment_portfolio;
        case 1:
            return STR_IT_funding_portfolio;
        case 2:
            return STR_IT_offering_asset;
        case 3:
            return STR_IT_id;
        case 4:
            return STR_IT_purchase_amount;
        case 5:
            return STR_IT_max_price;
        case 6:
            return STR_IT_receipt;
        default:
            return NULL;
        }
    case 9986: /* module 39 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9987: /* module 39 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9988: /* module 39 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_id;
        case 2:
            return STR_IT_start;
        case 3:
            return STR_IT_end;
        default:
            return NULL;
        }
    case 9989: /* module 39 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_beneficiaries;
        default:
            return NULL;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_signature;
        case 2:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_as_origin;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT_weight;
        default:
            return NULL;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
        default:
            return NULL;
        }
    case 10505: /* module 41 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_index;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_perms;
        default:
            return NULL;
        }
    case 11009: /* module 43 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_id;
        case 2:
            return STR_IT_perms;
        default:
            return NULL;
        }
    case 11010: /* module 43 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_agent;
        default:
            return NULL;
        }
    case 11011: /* module 43 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 11012: /* module 43 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_agent;
        case 2:
            return STR_IT_group;
        default:
            return NULL;
        }
    case 11013: /* module 43 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 11014: /* module 43 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_perms;
        case 2:
            return STR_IT_target;
        case 3:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 11015: /* module 43 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_perms;
        case 2:
            return STR_IT_agent;
        default:
            return NULL;
        }
    case 11264: /* module 44 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_user_key;
        case 1:
            return STR_IT_polyx_limit;
        default:
            return NULL;
        }
    case 11265: /* module 44 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 11266: /* module 44 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_user_key;
        case 1:
            return STR_IT_paying_key;
        default:
            return NULL;
        }
    case 11267: /* module 44 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_user_key;
        case 1:
            return STR_IT_polyx_limit;
        default:
            return NULL;
        }
    case 11268: /* module 44 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_user_key;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 11269: /* module 44 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_user_key;
        case 1:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_storage_deposit_limit;
        case 4:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
        case 1:
            return STR_IT_storage_deposit_limit;
        case 2:
            return STR_IT_determinism;
        default:
            return NULL;
        }
    case 11780: /* module 46 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 11781: /* module 46 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 11782: /* module 46 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_amount;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_storage_deposit_limit;
        case 4:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 11783: /* module 46 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 11784: /* module 46 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 12032: /* module 47 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        case 6:
            return STR_IT_perms;
        default:
            return NULL;
        }
    case 12033: /* module 47 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        case 6:
            return STR_IT_perms;
        default:
            return NULL;
        }
    case 12034: /* module 47 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_updates;
        default:
            return NULL;
        }
    case 12035: /* module 47 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 12036: /* module 47 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_storage_deposit_limit;
        case 3:
            return STR_IT_code_hash;
        case 4:
            return STR_IT_data;
        case 5:
            return STR_IT_salt;
        default:
            return NULL;
        }
    case 12037: /* module 47 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_api;
        case 1:
            return STR_IT_next_upgrade;
        default:
            return NULL;
        }
    case 12288: /* module 48 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bytes;
        default:
            return NULL;
        }
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hash;
        default:
            return NULL;
        }
    case 12544: /* module 49 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_nft_type;
        case 2:
            return STR_IT_collection_keys;
        default:
            return NULL;
        }
    case 12545: /* module 49 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_nft_metadata_attributes;
        case 2:
            return STR_IT_portfolio_kind;
        default:
            return NULL;
        }
    case 12546: /* module 49 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_nft_id;
        case 2:
            return STR_IT_portfolio_kind;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V4(
    pd_Method_V4_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V4 - dest */;
            return _toStringLookupasStaticLookupSource(
                &m->nested.balances_transfer_V4.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_transfer_with_memo_V4 - dest */;
            return _toStringLookupasStaticLookupSource(
                &m->nested.balances_transfer_with_memo_V4.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_with_memo_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_with_memo_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_transfer_with_memo_V4 - memo */;
            return _toStringOptionMemo(
                &m->nested.balances_transfer_with_memo_V4.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0: /* identity_accept_primary_key_V4 - rotation_auth_id */;
            return _toStringu64(
                &m->nested.identity_accept_primary_key_V4.rotation_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_accept_primary_key_V4 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->nested.identity_accept_primary_key_V4.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0: /* identity_join_identity_as_key_V4 - auth_id */;
            return _toStringu64(
                &m->nested.identity_join_identity_as_key_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        case 0: /* identity_add_claim_V4 - target */;
            return _toStringIdentityId(
                &m->nested.identity_add_claim_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_claim_V4 - claim */;
            return _toStringClaim(
                &m->nested.identity_add_claim_V4.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_claim_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.identity_add_claim_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0: /* identity_revoke_claim_V4 - target */;
            return _toStringIdentityId(
                &m->nested.identity_revoke_claim_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_claim_V4 - claim */;
            return _toStringClaim(
                &m->nested.identity_revoke_claim_V4.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1802: /* module 7 call 10 */
        switch (itemIdx) {
        case 0: /* identity_add_authorization_V4 - target */;
            return _toStringSignatoryAccountId(
                &m->nested.identity_add_authorization_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_authorization_V4 - data */;
            return _toStringAuthorizationDataAccountId(
                &m->nested.identity_add_authorization_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_authorization_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.identity_add_authorization_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        case 0: /* identity_remove_authorization_V4 - target */;
            return _toStringSignatoryAccountId(
                &m->nested.identity_remove_authorization_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_remove_authorization_V4 - auth_id */;
            return _toStringu64(
                &m->nested.identity_remove_authorization_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_remove_authorization_V4 - _auth_issuer_pays */;
            return _toStringbool(
                &m->nested.identity_remove_authorization_V4._auth_issuer_pays,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        case 0: /* identity_add_secondary_keys_with_authorization_V4 - additional_keys */;
            return _toStringVecSecondaryKeyWithAuthAccountId(
                &m->nested.identity_add_secondary_keys_with_authorization_V4.additional_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_secondary_keys_with_authorization_V4 - expires_at */;
            return _toStringMoment(
                &m->nested.identity_add_secondary_keys_with_authorization_V4.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0: /* identity_remove_secondary_keys_V4 - keys_to_remove */;
            return _toStringVecAccountId(
                &m->nested.identity_remove_secondary_keys_V4.keys_to_remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_create_multisig_V4 - signers */;
            return _toStringVecSignatoryAccountId(
                &m->nested.multisig_create_multisig_V4.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_multisig_V4 - sigs_required */;
            return _toStringu64(
                &m->nested.multisig_create_multisig_V4.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_key_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_create_or_approve_proposal_as_key_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_key_V4 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_key_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_key_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.multisig_create_or_approve_proposal_as_key_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_key_V4 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_key_V4.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_key_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_create_proposal_as_key_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_key_V4 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_key_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_key_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.multisig_create_proposal_as_key_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_key_V4 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_key_V4.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3846: /* module 15 call 6 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_key_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_approve_as_key_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_key_V4 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_approve_as_key_V4.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3848: /* module 15 call 8 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_key_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_reject_as_key_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_key_V4 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_reject_as_key_V4.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3850: /* module 15 call 10 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_key_V4 - auth_id */;
            return _toStringu64(
                &m->nested.multisig_accept_multisig_signer_as_key_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3851: /* module 15 call 11 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signer_V4 - signer */;
            return _toStringSignatoryAccountId(
                &m->nested.multisig_add_multisig_signer_V4.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3852: /* module 15 call 12 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signer_V4 - signer */;
            return _toStringSignatoryAccountId(
                &m->nested.multisig_remove_multisig_signer_V4.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3853: /* module 15 call 13 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signers_via_creator_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_add_multisig_signers_via_creator_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_add_multisig_signers_via_creator_V4 - signers */;
            return _toStringVecSignatoryAccountId(
                &m->nested.multisig_add_multisig_signers_via_creator_V4.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3854: /* module 15 call 14 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signers_via_creator_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_remove_multisig_signers_via_creator_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_remove_multisig_signers_via_creator_V4 - signers */;
            return _toStringVecSignatoryAccountId(
                &m->nested.multisig_remove_multisig_signers_via_creator_V4.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3855: /* module 15 call 15 */
        switch (itemIdx) {
        case 0: /* multisig_change_sigs_required_V4 - sigs_required */;
            return _toStringu64(
                &m->nested.multisig_change_sigs_required_V4.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3857: /* module 15 call 17 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_primary_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_make_multisig_primary_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_make_multisig_primary_V4 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->nested.multisig_make_multisig_primary_V4.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V4 - controller */;
            return _toStringAccountIdLookupOfT(
                &m->nested.staking_bond_V4.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V4 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_bond_V4.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_bond_extra_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_unbond_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V4 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_withdraw_unbonded_V4.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V4 - prefs */;
            return _toStringValidatorPrefs(
                &m->nested.staking_validate_V4.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V4 - targets */;
            return _toStringVecAccountIdLookupOfT(
                &m->nested.staking_nominate_V4.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4358: /* module 17 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4359: /* module 17 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V4 - payee */;
            return _toStringRewardDestination(
                &m->nested.staking_set_payee_V4.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4360: /* module 17 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V4 - controller */;
            return _toStringAccountIdLookupOfT(
                &m->nested.staking_set_controller_V4.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4376: /* module 17 call 24 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.staking_rebond_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8454: /* module 33 call 6 */
        switch (itemIdx) {
        case 0: /* pips_propose_V4 - proposal */;
            return _toStringProposal(
                &m->nested.pips_propose_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_propose_V4 - deposit */;
            return _toStringBalance(
                &m->nested.pips_propose_V4.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_propose_V4 - url */;
            return _toStringOptionUrl(
                &m->nested.pips_propose_V4.url,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* pips_propose_V4 - description */;
            return _toStringOptionPipDescription(
                &m->nested.pips_propose_V4.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8455: /* module 33 call 7 */
        switch (itemIdx) {
        case 0: /* pips_vote_V4 - id */;
            return _toStringPipId(
                &m->nested.pips_vote_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_vote_V4 - aye_or_nay */;
            return _toStringbool(
                &m->nested.pips_vote_V4.aye_or_nay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_vote_V4 - deposit */;
            return _toStringBalance(
                &m->nested.pips_vote_V4.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V4 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_V4.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10503: /* module 41 call 7 */
        switch (itemIdx) {
        case 0: /* utility_batch_atomic_V4 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_atomic_V4.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10504: /* module 41 call 8 */
        switch (itemIdx) {
        case 0: /* utility_batch_optimistic_V4 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_optimistic_V4.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
#ifndef TARGET_NANOS
    case 6686: /* module 26 call 30 */
        switch (itemIdx) {
        case 0: /* asset_add_mandatory_mediators_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_add_mandatory_mediators_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_add_mandatory_mediators_V4 - mediators */;
            return _toStringBoundedBTreeSetIdentityIdMaxAssetMediators(
                &m->basic.asset_add_mandatory_mediators_V4.mediators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6687: /* module 26 call 31 */
        switch (itemIdx) {
        case 0: /* asset_remove_mandatory_mediators_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_remove_mandatory_mediators_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_mandatory_mediators_V4 - mediators */;
            return _toStringBoundedBTreeSetIdentityIdMaxAssetMediators(
                &m->basic.asset_remove_mandatory_mediators_V4.mediators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_max_details_length_V4 - length */;
            return _toStringu32(
                &m->nested.corporateaction_set_max_details_length_V4.length,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_targets_V4 - ticker */;
            return _toStringTicker(
                &m->nested.corporateaction_set_default_targets_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_targets_V4 - targets */;
            return _toStringTargetIdentities(
                &m->nested.corporateaction_set_default_targets_V4.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_withholding_tax_V4 - ticker */;
            return _toStringTicker(
                &m->nested.corporateaction_set_default_withholding_tax_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_withholding_tax_V4 - tax */;
            return _toStringTax(
                &m->nested.corporateaction_set_default_withholding_tax_V4.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_did_withholding_tax_V4 - ticker */;
            return _toStringTicker(
                &m->nested.corporateaction_set_did_withholding_tax_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_did_withholding_tax_V4 - taxed_did */;
            return _toStringIdentityId(
                &m->nested.corporateaction_set_did_withholding_tax_V4.taxed_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_set_did_withholding_tax_V4 - tax */;
            return _toStringOptionTax(
                &m->nested.corporateaction_set_did_withholding_tax_V4.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* corporateaction_initiate_corporate_action_V4 - ticker */;
            return _toStringTicker(
                &m->nested.corporateaction_initiate_corporate_action_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_initiate_corporate_action_V4 - kind */;
            return _toStringCAKind(
                &m->nested.corporateaction_initiate_corporate_action_V4.kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_initiate_corporate_action_V4 - decl_date */;
            return _toStringMoment(
                &m->nested.corporateaction_initiate_corporate_action_V4.decl_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateaction_initiate_corporate_action_V4 - record_date */;
            return _toStringOptionRecordDateSpec(
                &m->nested.corporateaction_initiate_corporate_action_V4.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* corporateaction_initiate_corporate_action_V4 - details */;
            return _toStringCADetails(
                &m->nested.corporateaction_initiate_corporate_action_V4.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* corporateaction_initiate_corporate_action_V4 - targets */;
            return _toStringOptionTargetIdentities(
                &m->nested.corporateaction_initiate_corporate_action_V4.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* corporateaction_initiate_corporate_action_V4 - default_withholding_tax */;
            return _toStringOptionTax(
                &m->nested.corporateaction_initiate_corporate_action_V4.default_withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* corporateaction_initiate_corporate_action_V4 - withholding_tax */;
            return _toStringOptionVecTupleIdentityIdTax(
                &m->nested.corporateaction_initiate_corporate_action_V4.withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* corporateaction_link_ca_doc_V4 - id */;
            return _toStringCAId(
                &m->nested.corporateaction_link_ca_doc_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_link_ca_doc_V4 - docs */;
            return _toStringVecDocumentId(
                &m->nested.corporateaction_link_ca_doc_V4.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* corporateaction_remove_ca_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateaction_remove_ca_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0: /* corporateaction_change_record_date_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateaction_change_record_date_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_change_record_date_V4 - record_date */;
            return _toStringOptionRecordDateSpec(
                &m->nested.corporateaction_change_record_date_V4.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7688: /* module 30 call 8 */
        switch (itemIdx) {
        case 0: /* corporateaction_initiate_corporate_action_and_distribute_V4 - ca_args */;
            return _toStringInitiateCorporateActionArgs(
                &m->nested.corporateaction_initiate_corporate_action_and_distribute_V4.ca_args,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_initiate_corporate_action_and_distribute_V4 - portfolio */;
            return _toStringOptionPortfolioNumber(
                &m->nested.corporateaction_initiate_corporate_action_and_distribute_V4.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_initiate_corporate_action_and_distribute_V4 - currency */;
            return _toStringTicker(
                &m->nested.corporateaction_initiate_corporate_action_and_distribute_V4.currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateaction_initiate_corporate_action_and_distribute_V4 - per_share */;
            return _toStringBalance(
                &m->nested.corporateaction_initiate_corporate_action_and_distribute_V4.per_share,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* corporateaction_initiate_corporate_action_and_distribute_V4 - amount */;
            return _toStringBalance(
                &m->nested.corporateaction_initiate_corporate_action_and_distribute_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* corporateaction_initiate_corporate_action_and_distribute_V4 - payment_at */;
            return _toStringMoment(
                &m->nested.corporateaction_initiate_corporate_action_and_distribute_V4.payment_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* corporateaction_initiate_corporate_action_and_distribute_V4 - expires_at */;
            return _toStringOptionMoment(
                &m->nested.corporateaction_initiate_corporate_action_and_distribute_V4.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* corporateballot_attach_ballot_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateballot_attach_ballot_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_attach_ballot_V4 - range */;
            return _toStringBallotTimeRange(
                &m->nested.corporateballot_attach_ballot_V4.range,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateballot_attach_ballot_V4 - meta */;
            return _toStringBallotMeta(
                &m->nested.corporateballot_attach_ballot_V4.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateballot_attach_ballot_V4 - rcv */;
            return _toStringbool(
                &m->nested.corporateballot_attach_ballot_V4.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* corporateballot_vote_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateballot_vote_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_vote_V4 - votes */;
            return _toStringVecBallotVote(
                &m->nested.corporateballot_vote_V4.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_end_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateballot_change_end_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_end_V4 - end */;
            return _toStringMoment(
                &m->nested.corporateballot_change_end_V4.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_meta_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateballot_change_meta_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_meta_V4 - meta */;
            return _toStringBallotMeta(
                &m->nested.corporateballot_change_meta_V4.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_rcv_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateballot_change_rcv_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_rcv_V4 - rcv */;
            return _toStringbool(
                &m->nested.corporateballot_change_rcv_V4.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0: /* corporateballot_remove_ballot_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.corporateballot_remove_ballot_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8462: /* module 33 call 14 */
        switch (itemIdx) {
        case 0: /* pips_enact_snapshot_results_V4 - results */;
            return _toStringVecTuplePipIdSnapshotResult(
                &m->nested.pips_enact_snapshot_results_V4.results,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8712: /* module 34 call 8 */
        switch (itemIdx) {
        case 0: /* portfolio_allow_identity_to_create_portfolios_V4 - trusted_identity */;
            return _toStringIdentityId(
                &m->basic.portfolio_allow_identity_to_create_portfolios_V4.trusted_identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8713: /* module 34 call 9 */
        switch (itemIdx) {
        case 0: /* portfolio_revoke_create_portfolios_permission_V4 - identity */;
            return _toStringIdentityId(
                &m->basic.portfolio_revoke_create_portfolios_permission_V4.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8714: /* module 34 call 10 */
        switch (itemIdx) {
        case 0: /* portfolio_create_custody_portfolio_V4 - portfolio_owner_id */;
            return _toStringIdentityId(
                &m->basic.portfolio_create_custody_portfolio_V4.portfolio_owner_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_create_custody_portfolio_V4 - portfolio_name */;
            return _toStringPortfolioName(
                &m->basic.portfolio_create_custody_portfolio_V4.portfolio_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9487: /* module 37 call 15 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_with_receipts_with_count_V4 - id */;
            return _toStringInstructionId(
                &m->basic.settlement_affirm_with_receipts_with_count_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_with_receipts_with_count_V4 - receipt_details */;
            return _toStringVecReceiptDetails(
                &m->basic.settlement_affirm_with_receipts_with_count_V4.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_with_receipts_with_count_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->basic.settlement_affirm_with_receipts_with_count_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_affirm_with_receipts_with_count_V4 - number_of_assets */;
            return _toStringOptionAffirmationCount(
                &m->basic.settlement_affirm_with_receipts_with_count_V4.number_of_assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9488: /* module 37 call 16 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_instruction_with_count_V4 - id */;
            return _toStringInstructionId(
                &m->basic.settlement_affirm_instruction_with_count_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_instruction_with_count_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->basic.settlement_affirm_instruction_with_count_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_instruction_with_count_V4 - number_of_assets */;
            return _toStringOptionAffirmationCount(
                &m->basic.settlement_affirm_instruction_with_count_V4.number_of_assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9489: /* module 37 call 17 */
        switch (itemIdx) {
        case 0: /* settlement_reject_instruction_with_count_V4 - id */;
            return _toStringInstructionId(
                &m->basic.settlement_reject_instruction_with_count_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_reject_instruction_with_count_V4 - portfolio */;
            return _toStringPortfolioId(
                &m->basic.settlement_reject_instruction_with_count_V4.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_reject_instruction_with_count_V4 - number_of_assets */;
            return _toStringOptionAssetCount(
                &m->basic.settlement_reject_instruction_with_count_V4.number_of_assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9490: /* module 37 call 18 */
        switch (itemIdx) {
        case 0: /* settlement_withdraw_affirmation_with_count_V4 - id */;
            return _toStringInstructionId(
                &m->basic.settlement_withdraw_affirmation_with_count_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_withdraw_affirmation_with_count_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->basic.settlement_withdraw_affirmation_with_count_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_withdraw_affirmation_with_count_V4 - number_of_assets */;
            return _toStringOptionAffirmationCount(
                &m->basic.settlement_withdraw_affirmation_with_count_V4.number_of_assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9491: /* module 37 call 19 */
        switch (itemIdx) {
        case 0: /* settlement_add_instruction_with_mediators_V4 - venue_id */;
            return _toStringVenueId(
                &m->basic.settlement_add_instruction_with_mediators_V4.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_instruction_with_mediators_V4 - settlement_type */;
            return _toStringSettlementTypeBlockNumber(
                &m->basic.settlement_add_instruction_with_mediators_V4.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_instruction_with_mediators_V4 - trade_date */;
            return _toStringOptionMoment(
                &m->basic.settlement_add_instruction_with_mediators_V4.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_instruction_with_mediators_V4 - value_date */;
            return _toStringOptionMoment(
                &m->basic.settlement_add_instruction_with_mediators_V4.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_instruction_with_mediators_V4 - legs */;
            return _toStringVecLeg(
                &m->basic.settlement_add_instruction_with_mediators_V4.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_add_instruction_with_mediators_V4 - instruction_memo */;
            return _toStringOptionMemo(
                &m->basic.settlement_add_instruction_with_mediators_V4.instruction_memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* settlement_add_instruction_with_mediators_V4 - mediators */;
            return _toStringBoundedBTreeSetIdentityIdMaxInstructionMediators(
                &m->basic.settlement_add_instruction_with_mediators_V4.mediators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9492: /* module 37 call 20 */
        switch (itemIdx) {
        case 0: /* settlement_add_and_affirm_with_mediators_V4 - venue_id */;
            return _toStringVenueId(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_and_affirm_with_mediators_V4 - settlement_type */;
            return _toStringSettlementTypeBlockNumber(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_and_affirm_with_mediators_V4 - trade_date */;
            return _toStringOptionMoment(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_and_affirm_with_mediators_V4 - value_date */;
            return _toStringOptionMoment(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_and_affirm_with_mediators_V4 - legs */;
            return _toStringVecLeg(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_add_and_affirm_with_mediators_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* settlement_add_and_affirm_with_mediators_V4 - instruction_memo */;
            return _toStringOptionMemo(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.instruction_memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* settlement_add_and_affirm_with_mediators_V4 - mediators */;
            return _toStringBoundedBTreeSetIdentityIdMaxInstructionMediators(
                &m->basic.settlement_add_and_affirm_with_mediators_V4.mediators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9493: /* module 37 call 21 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_instruction_as_mediator_V4 - instruction_id */;
            return _toStringInstructionId(
                &m->basic.settlement_affirm_instruction_as_mediator_V4.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_instruction_as_mediator_V4 - expiry */;
            return _toStringOptionMoment(
                &m->basic.settlement_affirm_instruction_as_mediator_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9494: /* module 37 call 22 */
        switch (itemIdx) {
        case 0: /* settlement_withdraw_affirmation_as_mediator_V4 - instruction_id */;
            return _toStringInstructionId(
                &m->basic.settlement_withdraw_affirmation_as_mediator_V4.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9495: /* module 37 call 23 */
        switch (itemIdx) {
        case 0: /* settlement_reject_instruction_as_mediator_V4 - instruction_id */;
            return _toStringInstructionId(
                &m->basic.settlement_reject_instruction_as_mediator_V4.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_reject_instruction_as_mediator_V4 - number_of_assets */;
            return _toStringOptionAssetCount(
                &m->basic.settlement_reject_instruction_as_mediator_V4.number_of_assets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12547: /* module 49 call 3 */
        switch (itemIdx) {
        case 0: /* nft_controller_transfer_V4 - ticker */;
            return _toStringTicker(
                &m->basic.nft_controller_transfer_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nft_controller_transfer_V4 - nfts */;
            return _toStringNFTs(
                &m->basic.nft_controller_transfer_V4.nfts,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nft_controller_transfer_V4 - source_portfolio */;
            return _toStringPortfolioId(
                &m->basic.nft_controller_transfer_V4.source_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* nft_controller_transfer_V4 - callers_portfolio_kind */;
            return _toStringPortfolioKind(
                &m->basic.nft_controller_transfer_V4.callers_portfolio_kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_remark_V4 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_V4.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V4 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V4.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_code_V4 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V4.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V4 - code */;
            return _toStringVecu8(
                &m->nested.system_set_code_without_checks_V4.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_remark_with_event_V4 - remark */;
            return _toStringBytes(
                &m->nested.system_remark_with_event_V4.remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V4 - now */;
            return _toStringCompactu64(
                &m->nested.timestamp_set_V4.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V4 - index */;
            return _toStringAccountIndex(
                &m->nested.indices_claim_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V4 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->nested.indices_transfer_V4.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V4 - index */;
            return _toStringAccountIndex(
                &m->nested.indices_transfer_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V4 - index */;
            return _toStringAccountIndex(
                &m->nested.indices_free_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V4 - new_ */;
            return _toStringAccountIdLookupOfT(
                &m->nested.indices_force_transfer_V4.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V4 - index */;
            return _toStringAccountIndex(
                &m->nested.indices_force_transfer_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V4 - freeze */;
            return _toStringbool(
                &m->nested.indices_force_transfer_V4.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V4 - index */;
            return _toStringAccountIndex(
                &m->nested.indices_freeze_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_deposit_block_reward_reserve_balance_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_deposit_block_reward_reserve_balance_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V4 - who */;
            return _toStringLookupasStaticLookupSource(
                &m->nested.balances_set_balance_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V4 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V4.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V4 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V4.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V4 - source */;
            return _toStringLookupasStaticLookupSource(
                &m->nested.balances_force_transfer_V4.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V4 - dest */;
            return _toStringLookupasStaticLookupSource(
                &m->nested.balances_force_transfer_V4.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0: /* balances_burn_account_balance_V4 - amount */;
            return _toStringBalance(
                &m->nested.balances_burn_account_balance_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* identity_cdd_register_did_V4 - target_account */;
            return _toStringAccountId(
                &m->nested.identity_cdd_register_did_V4.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_cdd_register_did_V4 - secondary_keys */;
            return _toStringVecSecondaryKeyAccountId(
                &m->nested.identity_cdd_register_did_V4.secondary_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0: /* identity_invalidate_cdd_claims_V4 - cdd */;
            return _toStringIdentityId(
                &m->nested.identity_invalidate_cdd_claims_V4.cdd,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_invalidate_cdd_claims_V4 - disable_from */;
            return _toStringMoment(
                &m->nested.identity_invalidate_cdd_claims_V4.disable_from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_invalidate_cdd_claims_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.identity_invalidate_cdd_claims_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0: /* identity_change_cdd_requirement_for_mk_rotation_V4 - auth_required */;
            return _toStringbool(
                &m->nested.identity_change_cdd_requirement_for_mk_rotation_V4.auth_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        case 0: /* identity_gc_add_cdd_claim_V4 - target */;
            return _toStringIdentityId(
                &m->nested.identity_gc_add_cdd_claim_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1805: /* module 7 call 13 */
        switch (itemIdx) {
        case 0: /* identity_gc_revoke_cdd_claim_V4 - target */;
            return _toStringIdentityId(
                &m->nested.identity_gc_revoke_cdd_claim_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1806: /* module 7 call 14 */
        switch (itemIdx) {
        case 0: /* identity_revoke_claim_by_index_V4 - target */;
            return _toStringIdentityId(
                &m->nested.identity_revoke_claim_by_index_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_claim_by_index_V4 - claim_type */;
            return _toStringClaimType(
                &m->nested.identity_revoke_claim_by_index_V4.claim_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_revoke_claim_by_index_V4 - scope */;
            return _toStringOptionScope(
                &m->nested.identity_revoke_claim_by_index_V4.scope,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0: /* identity_rotate_primary_key_to_secondary_V4 - auth_id */;
            return _toStringu64(
                &m->nested.identity_rotate_primary_key_to_secondary_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rotate_primary_key_to_secondary_V4 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->nested.identity_rotate_primary_key_to_secondary_V4.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0: /* identity_set_secondary_key_permissions_V4 - key */;
            return _toStringAccountId(
                &m->nested.identity_set_secondary_key_permissions_V4.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_secondary_key_permissions_V4 - perms */;
            return _toStringPermissions(
                &m->nested.identity_set_secondary_key_permissions_V4.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1811: /* module 7 call 19 */
        switch (itemIdx) {
        case 0: /* identity_register_custom_claim_type_V4 - ty */;
            return _toStringVecu8(
                &m->nested.identity_register_custom_claim_type_V4.ty,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0: /* identity_cdd_register_did_with_cdd_V4 - target_account */;
            return _toStringAccountId(
                &m->nested.identity_cdd_register_did_with_cdd_V4.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_cdd_register_did_with_cdd_V4 - secondary_keys */;
            return _toStringVecSecondaryKeyAccountId(
                &m->nested.identity_cdd_register_did_with_cdd_V4.secondary_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_cdd_register_did_with_cdd_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.identity_cdd_register_did_with_cdd_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0: /* identity_create_child_identity_V4 - secondary_key */;
            return _toStringAccountId(
                &m->nested.identity_create_child_identity_V4.secondary_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1814: /* module 7 call 22 */
        switch (itemIdx) {
        case 0: /* identity_create_child_identities_V4 - child_keys */;
            return _toStringVecCreateChildIdentityWithAuthAccountId(
                &m->nested.identity_create_child_identities_V4.child_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_create_child_identities_V4 - expires_at */;
            return _toStringMoment(
                &m->nested.identity_create_child_identities_V4.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1815: /* module 7 call 23 */
        switch (itemIdx) {
        case 0: /* identity_unlink_child_identity_V4 - child_did */;
            return _toStringIdentityId(
                &m->nested.identity_unlink_child_identity_V4.child_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_set_active_members_limit_V4 - limit */;
            return _toStringMemberCount(
                &m->nested.cddserviceproviders_set_active_members_limit_V4.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_disable_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.cddserviceproviders_disable_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_disable_member_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.cddserviceproviders_disable_member_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* cddserviceproviders_disable_member_V4 - at */;
            return _toStringOptionMoment(
                &m->nested.cddserviceproviders_disable_member_V4.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_add_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.cddserviceproviders_add_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_remove_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.cddserviceproviders_remove_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_swap_member_V4 - remove */;
            return _toStringIdentityId(
                &m->nested.cddserviceproviders_swap_member_V4.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_swap_member_V4 - add */;
            return _toStringIdentityId(
                &m->nested.cddserviceproviders_swap_member_V4.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_reset_members_V4 - members */;
            return _toStringVecIdentityId(
                &m->nested.cddserviceproviders_reset_members_V4.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2304: /* module 9 call 0 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_vote_threshold_V4 - n */;
            return _toStringu32(
                &m->nested.polymeshcommittee_set_vote_threshold_V4.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_set_vote_threshold_V4 - d */;
            return _toStringu32(
                &m->nested.polymeshcommittee_set_vote_threshold_V4.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_release_coordinator_V4 - id */;
            return _toStringIdentityId(
                &m->nested.polymeshcommittee_set_release_coordinator_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_expires_after_V4 - expiry */;
            return _toStringMaybeBlockBlockNumber(
                &m->nested.polymeshcommittee_set_expires_after_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_or_propose_V4 - approve */;
            return _toStringbool(
                &m->nested.polymeshcommittee_vote_or_propose_V4.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_or_propose_V4 - call */;
            return _toStringProposal(
                &m->nested.polymeshcommittee_vote_or_propose_V4.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_V4 - proposal */;
            return _toStringHash(
                &m->nested.polymeshcommittee_vote_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_V4 - index */;
            return _toStringProposalIndex(
                &m->nested.polymeshcommittee_vote_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcommittee_vote_V4 - approve */;
            return _toStringbool(
                &m->nested.polymeshcommittee_vote_V4.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* committeemembership_set_active_members_limit_V4 - limit */;
            return _toStringMemberCount(
                &m->nested.committeemembership_set_active_members_limit_V4.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* committeemembership_disable_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.committeemembership_disable_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_disable_member_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.committeemembership_disable_member_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* committeemembership_disable_member_V4 - at */;
            return _toStringOptionMoment(
                &m->nested.committeemembership_disable_member_V4.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* committeemembership_add_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.committeemembership_add_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* committeemembership_remove_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.committeemembership_remove_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* committeemembership_swap_member_V4 - remove */;
            return _toStringIdentityId(
                &m->nested.committeemembership_swap_member_V4.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_swap_member_V4 - add */;
            return _toStringIdentityId(
                &m->nested.committeemembership_swap_member_V4.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* committeemembership_reset_members_V4 - members */;
            return _toStringVecIdentityId(
                &m->nested.committeemembership_reset_members_V4.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2566: /* module 10 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_vote_threshold_V4 - n */;
            return _toStringu32(
                &m->nested.technicalcommittee_set_vote_threshold_V4.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_vote_threshold_V4 - d */;
            return _toStringu32(
                &m->nested.technicalcommittee_set_vote_threshold_V4.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_release_coordinator_V4 - id */;
            return _toStringIdentityId(
                &m->nested.technicalcommittee_set_release_coordinator_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_expires_after_V4 - expiry */;
            return _toStringMaybeBlockBlockNumber(
                &m->nested.technicalcommittee_set_expires_after_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_or_propose_V4 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_or_propose_V4.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_or_propose_V4 - call */;
            return _toStringProposal(
                &m->nested.technicalcommittee_vote_or_propose_V4.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V4 - proposal */;
            return _toStringHash(
                &m->nested.technicalcommittee_vote_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V4 - index */;
            return _toStringProposalIndex(
                &m->nested.technicalcommittee_vote_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V4 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_V4.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_set_active_members_limit_V4 - limit */;
            return _toStringMemberCount(
                &m->nested.technicalcommitteemembership_set_active_members_limit_V4.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_disable_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.technicalcommitteemembership_disable_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_disable_member_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.technicalcommitteemembership_disable_member_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommitteemembership_disable_member_V4 - at */;
            return _toStringOptionMoment(
                &m->nested.technicalcommitteemembership_disable_member_V4.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_add_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.technicalcommitteemembership_add_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_remove_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.technicalcommitteemembership_remove_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_swap_member_V4 - remove */;
            return _toStringIdentityId(
                &m->nested.technicalcommitteemembership_swap_member_V4.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_swap_member_V4 - add */;
            return _toStringIdentityId(
                &m->nested.technicalcommitteemembership_swap_member_V4.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_reset_members_V4 - members */;
            return _toStringVecIdentityId(
                &m->nested.technicalcommitteemembership_reset_members_V4.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3078: /* module 12 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_vote_threshold_V4 - n */;
            return _toStringu32(
                &m->nested.upgradecommittee_set_vote_threshold_V4.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_set_vote_threshold_V4 - d */;
            return _toStringu32(
                &m->nested.upgradecommittee_set_vote_threshold_V4.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_release_coordinator_V4 - id */;
            return _toStringIdentityId(
                &m->nested.upgradecommittee_set_release_coordinator_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_expires_after_V4 - expiry */;
            return _toStringMaybeBlockBlockNumber(
                &m->nested.upgradecommittee_set_expires_after_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_or_propose_V4 - approve */;
            return _toStringbool(
                &m->nested.upgradecommittee_vote_or_propose_V4.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_or_propose_V4 - call */;
            return _toStringProposal(
                &m->nested.upgradecommittee_vote_or_propose_V4.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_V4 - proposal */;
            return _toStringHash(
                &m->nested.upgradecommittee_vote_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_V4 - index */;
            return _toStringProposalIndex(
                &m->nested.upgradecommittee_vote_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommittee_vote_V4 - approve */;
            return _toStringbool(
                &m->nested.upgradecommittee_vote_V4.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_set_active_members_limit_V4 - limit */;
            return _toStringMemberCount(
                &m->nested.upgradecommitteemembership_set_active_members_limit_V4.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_disable_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.upgradecommitteemembership_disable_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_disable_member_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.upgradecommitteemembership_disable_member_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommitteemembership_disable_member_V4 - at */;
            return _toStringOptionMoment(
                &m->nested.upgradecommitteemembership_disable_member_V4.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_add_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.upgradecommitteemembership_add_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_remove_member_V4 - who */;
            return _toStringIdentityId(
                &m->nested.upgradecommitteemembership_remove_member_V4.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_swap_member_V4 - remove */;
            return _toStringIdentityId(
                &m->nested.upgradecommitteemembership_swap_member_V4.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_swap_member_V4 - add */;
            return _toStringIdentityId(
                &m->nested.upgradecommitteemembership_swap_member_V4.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_reset_members_V4 - members */;
            return _toStringVecIdentityId(
                &m->nested.upgradecommitteemembership_reset_members_V4.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3590: /* module 14 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_identity_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_identity_V4 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_identity_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_identity_V4 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V4.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_identity_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_create_proposal_as_identity_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_identity_V4 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_identity_V4.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_identity_V4 - expiry */;
            return _toStringOptionMoment(
                &m->nested.multisig_create_proposal_as_identity_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_identity_V4 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_identity_V4.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_identity_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_approve_as_identity_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_identity_V4 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_approve_as_identity_V4.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3847: /* module 15 call 7 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_identity_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_reject_as_identity_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_identity_V4 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_reject_as_identity_V4.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3849: /* module 15 call 9 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_identity_V4 - _auth_id */;
            return _toStringu64(
                &m->nested.multisig_accept_multisig_signer_as_identity_V4._auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3856: /* module 15 call 16 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_secondary_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_make_multisig_secondary_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3858: /* module 15 call 18 */
        switch (itemIdx) {
        case 0: /* multisig_execute_scheduled_proposal_V4 - multisig */;
            return _toStringAccountId(
                &m->nested.multisig_execute_scheduled_proposal_V4.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_execute_scheduled_proposal_V4 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_execute_scheduled_proposal_V4.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_execute_scheduled_proposal_V4 - multisig_did */;
            return _toStringIdentityId(
                &m->nested.multisig_execute_scheduled_proposal_V4.multisig_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_execute_scheduled_proposal_V4 - _proposal_weight */;
            return _toStringWeight(
                &m->nested.multisig_execute_scheduled_proposal_V4._proposal_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3859: /* module 15 call 19 */
        switch (itemIdx) {
        case 0: /* multisig_change_sigs_required_via_creator_V4 - multisig_account */;
            return _toStringAccountId(
                &m->nested.multisig_change_sigs_required_via_creator_V4.multisig_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_change_sigs_required_via_creator_V4 - signatures_required */;
            return _toStringu64(
                &m->nested.multisig_change_sigs_required_via_creator_V4.signatures_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3860: /* module 15 call 20 */
        switch (itemIdx) {
        case 0: /* multisig_remove_creator_controls_V4 - multisig_account */;
            return _toStringAccountId(
                &m->nested.multisig_remove_creator_controls_V4.multisig_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* bridge_change_controller_V4 - controller */;
            return _toStringAccountId(
                &m->nested.bridge_change_controller_V4.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* bridge_change_admin_V4 - admin */;
            return _toStringAccountId(
                &m->nested.bridge_change_admin_V4.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* bridge_change_timelock_V4 - timelock */;
            return _toStringBlockNumber(
                &m->nested.bridge_change_timelock_V4.timelock,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4099: /* module 16 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4100: /* module 16 call 4 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4101: /* module 16 call 5 */
        switch (itemIdx) {
        case 0: /* bridge_change_bridge_limit_V4 - amount */;
            return _toStringBalance(
                &m->nested.bridge_change_bridge_limit_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_change_bridge_limit_V4 - duration */;
            return _toStringBlockNumber(
                &m->nested.bridge_change_bridge_limit_V4.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        case 0: /* bridge_change_bridge_exempted_V4 - exempted */;
            return _toStringVecTupleIdentityIdbool(
                &m->nested.bridge_change_bridge_exempted_V4.exempted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4103: /* module 16 call 7 */
        switch (itemIdx) {
        case 0: /* bridge_force_handle_bridge_tx_V4 - bridge_tx */;
            return _toStringBridgeTxAccountId(
                &m->nested.bridge_force_handle_bridge_tx_V4.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4104: /* module 16 call 8 */
        switch (itemIdx) {
        case 0: /* bridge_batch_propose_bridge_tx_V4 - bridge_txs */;
            return _toStringVecBridgeTxAccountId(
                &m->basic.bridge_batch_propose_bridge_tx_V4.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4105: /* module 16 call 9 */
        switch (itemIdx) {
        case 0: /* bridge_propose_bridge_tx_V4 - bridge_tx */;
            return _toStringBridgeTxAccountId(
                &m->basic.bridge_propose_bridge_tx_V4.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4106: /* module 16 call 10 */
        switch (itemIdx) {
        case 0: /* bridge_handle_bridge_tx_V4 - bridge_tx */;
            return _toStringBridgeTxAccountId(
                &m->basic.bridge_handle_bridge_tx_V4.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4107: /* module 16 call 11 */
        switch (itemIdx) {
        case 0: /* bridge_freeze_txs_V4 - bridge_txs */;
            return _toStringVecBridgeTxAccountId(
                &m->basic.bridge_freeze_txs_V4.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4108: /* module 16 call 12 */
        switch (itemIdx) {
        case 0: /* bridge_unfreeze_txs_V4 - bridge_txs */;
            return _toStringVecBridgeTxAccountId(
                &m->basic.bridge_unfreeze_txs_V4.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4109: /* module 16 call 13 */
        switch (itemIdx) {
        case 0: /* bridge_handle_scheduled_bridge_tx_V4 - bridge_tx */;
            return _toStringBridgeTxAccountId(
                &m->basic.bridge_handle_scheduled_bridge_tx_V4.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4110: /* module 16 call 14 */
        switch (itemIdx) {
        case 0: /* bridge_add_freeze_admin_V4 - freeze_admin */;
            return _toStringAccountId(
                &m->basic.bridge_add_freeze_admin_V4.freeze_admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4111: /* module 16 call 15 */
        switch (itemIdx) {
        case 0: /* bridge_remove_freeze_admin_V4 - freeze_admin */;
            return _toStringAccountId(
                &m->basic.bridge_remove_freeze_admin_V4.freeze_admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4112: /* module 16 call 16 */
        switch (itemIdx) {
        case 0: /* bridge_remove_txs_V4 - bridge_txs */;
            return _toStringVecBridgeTxAccountId(
                &m->basic.bridge_remove_txs_V4.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4361: /* module 17 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V4 - new_ */;
            return _toStringCompactu32(
                &m->nested.staking_set_validator_count_V4.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4362: /* module 17 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V4 - additional */;
            return _toStringCompactu32(
                &m->nested.staking_increase_validator_count_V4.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4363: /* module 17 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V4 - factor */;
            return _toStringPercent(
                &m->nested.staking_scale_validator_count_V4.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4364: /* module 17 call 12 */
        switch (itemIdx) {
        case 0: /* staking_add_permissioned_validator_V4 - identity */;
            return _toStringIdentityId(
                &m->nested.staking_add_permissioned_validator_V4.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_add_permissioned_validator_V4 - intended_count */;
            return _toStringOptionu32(
                &m->nested.staking_add_permissioned_validator_V4.intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4365: /* module 17 call 13 */
        switch (itemIdx) {
        case 0: /* staking_remove_permissioned_validator_V4 - identity */;
            return _toStringIdentityId(
                &m->nested.staking_remove_permissioned_validator_V4.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4366: /* module 17 call 14 */
        switch (itemIdx) {
        case 0: /* staking_validate_cdd_expiry_nominators_V4 - targets */;
            return _toStringVecAccountId(
                &m->nested.staking_validate_cdd_expiry_nominators_V4.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4367: /* module 17 call 15 */
        switch (itemIdx) {
        case 0: /* staking_set_commission_cap_V4 - new_cap */;
            return _toStringPerbill(
                &m->nested.staking_set_commission_cap_V4.new_cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4368: /* module 17 call 16 */
        switch (itemIdx) {
        case 0: /* staking_set_min_bond_threshold_V4 - new_value */;
            return _toStringBalance(
                &m->nested.staking_set_min_bond_threshold_V4.new_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4369: /* module 17 call 17 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4370: /* module 17 call 18 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4371: /* module 17 call 19 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V4 - invulnerables */;
            return _toStringVecAccountId(
                &m->nested.staking_set_invulnerables_V4.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4372: /* module 17 call 20 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V4 - stash */;
            return _toStringAccountId(
                &m->nested.staking_force_unstake_V4.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V4 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_force_unstake_V4.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4373: /* module 17 call 21 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 4374: /* module 17 call 22 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V4 - era */;
            return _toStringEraIndex(
                &m->nested.staking_cancel_deferred_slash_V4.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V4 - slash_indices */;
            return _toStringVecu32(
                &m->nested.staking_cancel_deferred_slash_V4.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4375: /* module 17 call 23 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V4 - validator_stash */;
            return _toStringAccountId(
                &m->nested.staking_payout_stakers_V4.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V4 - era */;
            return _toStringEraIndex(
                &m->nested.staking_payout_stakers_V4.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4377: /* module 17 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V4 - new_history_depth */;
            return _toStringCompactu32(
                &m->nested.staking_set_history_depth_V4.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V4 - era_items_deleted */;
            return _toStringCompactu32(
                &m->nested.staking_set_history_depth_V4.era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4378: /* module 17 call 26 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V4 - stash */;
            return _toStringAccountId(
                &m->nested.staking_reap_stash_V4.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V4 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_reap_stash_V4.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4381: /* module 17 call 29 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_by_system_V4 - validator_stash */;
            return _toStringAccountId(
                &m->nested.staking_payout_stakers_by_system_V4.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_by_system_V4 - era */;
            return _toStringEraIndex(
                &m->nested.staking_payout_stakers_by_system_V4.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4382: /* module 17 call 30 */
        switch (itemIdx) {
        case 0: /* staking_change_slashing_allowed_for_V4 - slashing_switch */;
            return _toStringSlashingSwitch(
                &m->nested.staking_change_slashing_allowed_for_V4.slashing_switch,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4383: /* module 17 call 31 */
        switch (itemIdx) {
        case 0: /* staking_update_permissioned_validator_intended_count_V4 - identity */;
            return _toStringIdentityId(
                &m->nested.staking_update_permissioned_validator_intended_count_V4.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_update_permissioned_validator_intended_count_V4 - new_intended_count */;
            return _toStringu32(
                &m->nested.staking_update_permissioned_validator_intended_count_V4.new_intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4384: /* module 17 call 32 */
        switch (itemIdx) {
        case 0: /* staking_chill_from_governance_V4 - identity */;
            return _toStringIdentityId(
                &m->nested.staking_chill_from_governance_V4.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_chill_from_governance_V4 - stash_keys */;
            return _toStringVecAccountId(
                &m->nested.staking_chill_from_governance_V4.stash_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V4 - keys */;
            return _toStringKeys(
                &m->nested.session_set_keys_V4.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V4 - proof */;
            return _toStringBytes(
                &m->nested.session_set_keys_V4.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4865: /* module 19 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* asset_register_ticker_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_register_ticker_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* asset_accept_ticker_transfer_V4 - auth_id */;
            return _toStringu64(
                &m->nested.asset_accept_ticker_transfer_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* asset_accept_asset_ownership_transfer_V4 - auth_id */;
            return _toStringu64(
                &m->nested.asset_accept_asset_ownership_transfer_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* asset_create_asset_V4 - name */;
            return _toStringAssetName(
                &m->nested.asset_create_asset_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_create_asset_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_create_asset_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_create_asset_V4 - divisible */;
            return _toStringbool(
                &m->nested.asset_create_asset_V4.divisible,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* asset_create_asset_V4 - asset_type */;
            return _toStringAssetType(
                &m->nested.asset_create_asset_V4.asset_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* asset_create_asset_V4 - identifiers */;
            return _toStringVecAssetIdentifier(
                &m->nested.asset_create_asset_V4.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* asset_create_asset_V4 - funding_round */;
            return _toStringOptionFundingRoundName(
                &m->nested.asset_create_asset_V4.funding_round,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* asset_freeze_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_freeze_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* asset_unfreeze_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_unfreeze_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        case 0: /* asset_rename_asset_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_rename_asset_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_rename_asset_V4 - name */;
            return _toStringAssetName(
                &m->nested.asset_rename_asset_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0: /* asset_issue_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_issue_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_issue_V4 - amount */;
            return _toStringBalanceNoSymbol(
                &m->nested.asset_issue_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_issue_V4 - portfolio_kind */;
            return _toStringPortfolioKind(
                &m->nested.asset_issue_V4.portfolio_kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        case 0: /* asset_redeem_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_redeem_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_redeem_V4 - amount */;
            return _toStringBalanceNoSymbol(
                &m->nested.asset_redeem_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0: /* asset_make_divisible_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_make_divisible_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6666: /* module 26 call 10 */
        switch (itemIdx) {
        case 0: /* asset_add_documents_V4 - docs */;
            return _toStringVecDocument(
                &m->nested.asset_add_documents_V4.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_add_documents_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_add_documents_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0: /* asset_remove_documents_V4 - ids */;
            return _toStringVecDocumentId(
                &m->nested.asset_remove_documents_V4.ids,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_documents_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_remove_documents_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6668: /* module 26 call 12 */
        switch (itemIdx) {
        case 0: /* asset_set_funding_round_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_set_funding_round_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_set_funding_round_V4 - name */;
            return _toStringFundingRoundName(
                &m->nested.asset_set_funding_round_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6669: /* module 26 call 13 */
        switch (itemIdx) {
        case 0: /* asset_update_identifiers_V4 - ticker */;
            return _toStringTicker(
                &m->nested.asset_update_identifiers_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_update_identifiers_V4 - asset_identifiers */;
            return _toStringVecAssetIdentifier(
                &m->nested.asset_update_identifiers_V4.asset_identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6670: /* module 26 call 14 */
        switch (itemIdx) {
        case 0: /* asset_controller_transfer_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_controller_transfer_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_controller_transfer_V4 - amount */;
            return _toStringBalanceNoSymbol(
                &m->basic.asset_controller_transfer_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_controller_transfer_V4 - from_portfolio */;
            return _toStringPortfolioId(
                &m->basic.asset_controller_transfer_V4.from_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6671: /* module 26 call 15 */
        switch (itemIdx) {
        case 0: /* asset_register_custom_asset_type_V4 - ty */;
            return _toStringVecu8(
                &m->basic.asset_register_custom_asset_type_V4.ty,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6672: /* module 26 call 16 */
        switch (itemIdx) {
        case 0: /* asset_create_asset_with_custom_type_V4 - name */;
            return _toStringAssetName(
                &m->basic.asset_create_asset_with_custom_type_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_create_asset_with_custom_type_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_create_asset_with_custom_type_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_create_asset_with_custom_type_V4 - divisible */;
            return _toStringbool(
                &m->basic.asset_create_asset_with_custom_type_V4.divisible,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* asset_create_asset_with_custom_type_V4 - custom_asset_type */;
            return _toStringVecu8(
                &m->basic.asset_create_asset_with_custom_type_V4.custom_asset_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* asset_create_asset_with_custom_type_V4 - identifiers */;
            return _toStringVecAssetIdentifier(
                &m->basic.asset_create_asset_with_custom_type_V4.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* asset_create_asset_with_custom_type_V4 - funding_round */;
            return _toStringOptionFundingRoundName(
                &m->basic.asset_create_asset_with_custom_type_V4.funding_round,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6673: /* module 26 call 17 */
        switch (itemIdx) {
        case 0: /* asset_set_asset_metadata_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_set_asset_metadata_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_set_asset_metadata_V4 - key */;
            return _toStringAssetMetadataKey(
                &m->basic.asset_set_asset_metadata_V4.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_set_asset_metadata_V4 - value */;
            return _toStringAssetMetadataValue(
                &m->basic.asset_set_asset_metadata_V4.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* asset_set_asset_metadata_V4 - detail */;
            return _toStringOptionAssetMetadataValueDetailMoment(
                &m->basic.asset_set_asset_metadata_V4.detail,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6674: /* module 26 call 18 */
        switch (itemIdx) {
        case 0: /* asset_set_asset_metadata_details_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_set_asset_metadata_details_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_set_asset_metadata_details_V4 - key */;
            return _toStringAssetMetadataKey(
                &m->basic.asset_set_asset_metadata_details_V4.key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_set_asset_metadata_details_V4 - detail */;
            return _toStringAssetMetadataValueDetailMoment(
                &m->basic.asset_set_asset_metadata_details_V4.detail,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6675: /* module 26 call 19 */
        switch (itemIdx) {
        case 0: /* asset_register_and_set_local_asset_metadata_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_register_and_set_local_asset_metadata_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_register_and_set_local_asset_metadata_V4 - name */;
            return _toStringAssetMetadataName(
                &m->basic.asset_register_and_set_local_asset_metadata_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_register_and_set_local_asset_metadata_V4 - spec */;
            return _toStringAssetMetadataSpec(
                &m->basic.asset_register_and_set_local_asset_metadata_V4.spec,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* asset_register_and_set_local_asset_metadata_V4 - value */;
            return _toStringAssetMetadataValue(
                &m->basic.asset_register_and_set_local_asset_metadata_V4.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* asset_register_and_set_local_asset_metadata_V4 - detail */;
            return _toStringOptionAssetMetadataValueDetailMoment(
                &m->basic.asset_register_and_set_local_asset_metadata_V4.detail,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6676: /* module 26 call 20 */
        switch (itemIdx) {
        case 0: /* asset_register_asset_metadata_local_type_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_register_asset_metadata_local_type_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_register_asset_metadata_local_type_V4 - name */;
            return _toStringAssetMetadataName(
                &m->basic.asset_register_asset_metadata_local_type_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_register_asset_metadata_local_type_V4 - spec */;
            return _toStringAssetMetadataSpec(
                &m->basic.asset_register_asset_metadata_local_type_V4.spec,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6677: /* module 26 call 21 */
        switch (itemIdx) {
        case 0: /* asset_register_asset_metadata_global_type_V4 - name */;
            return _toStringAssetMetadataName(
                &m->basic.asset_register_asset_metadata_global_type_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_register_asset_metadata_global_type_V4 - spec */;
            return _toStringAssetMetadataSpec(
                &m->basic.asset_register_asset_metadata_global_type_V4.spec,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6678: /* module 26 call 22 */
        switch (itemIdx) {
        case 0: /* asset_redeem_from_portfolio_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_redeem_from_portfolio_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_redeem_from_portfolio_V4 - amount */;
            return _toStringBalanceNoSymbol(
                &m->basic.asset_redeem_from_portfolio_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_redeem_from_portfolio_V4 - portfolio */;
            return _toStringPortfolioKind(
                &m->basic.asset_redeem_from_portfolio_V4.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6679: /* module 26 call 23 */
        switch (itemIdx) {
        case 0: /* asset_update_asset_type_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_update_asset_type_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_update_asset_type_V4 - asset_type */;
            return _toStringAssetType(
                &m->basic.asset_update_asset_type_V4.asset_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6680: /* module 26 call 24 */
        switch (itemIdx) {
        case 0: /* asset_remove_local_metadata_key_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_remove_local_metadata_key_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_local_metadata_key_V4 - local_key */;
            return _toStringAssetMetadataLocalKey(
                &m->basic.asset_remove_local_metadata_key_V4.local_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6681: /* module 26 call 25 */
        switch (itemIdx) {
        case 0: /* asset_remove_metadata_value_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_remove_metadata_value_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_metadata_value_V4 - metadata_key */;
            return _toStringAssetMetadataKey(
                &m->basic.asset_remove_metadata_value_V4.metadata_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6682: /* module 26 call 26 */
        switch (itemIdx) {
        case 0: /* asset_exempt_ticker_affirmation_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_exempt_ticker_affirmation_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6683: /* module 26 call 27 */
        switch (itemIdx) {
        case 0: /* asset_remove_ticker_affirmation_exemption_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_remove_ticker_affirmation_exemption_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6684: /* module 26 call 28 */
        switch (itemIdx) {
        case 0: /* asset_pre_approve_ticker_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_pre_approve_ticker_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6685: /* module 26 call 29 */
        switch (itemIdx) {
        case 0: /* asset_remove_ticker_pre_approval_V4 - ticker */;
            return _toStringTicker(
                &m->basic.asset_remove_ticker_pre_approval_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_distribute_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.capitaldistribution_distribute_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_distribute_V4 - portfolio */;
            return _toStringOptionPortfolioNumber(
                &m->nested.capitaldistribution_distribute_V4.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* capitaldistribution_distribute_V4 - currency */;
            return _toStringTicker(
                &m->nested.capitaldistribution_distribute_V4.currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* capitaldistribution_distribute_V4 - per_share */;
            return _toStringBalance(
                &m->nested.capitaldistribution_distribute_V4.per_share,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* capitaldistribution_distribute_V4 - amount */;
            return _toStringBalance(
                &m->nested.capitaldistribution_distribute_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* capitaldistribution_distribute_V4 - payment_at */;
            return _toStringMoment(
                &m->nested.capitaldistribution_distribute_V4.payment_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* capitaldistribution_distribute_V4 - expires_at */;
            return _toStringOptionMoment(
                &m->nested.capitaldistribution_distribute_V4.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_claim_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.capitaldistribution_claim_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_push_benefit_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.capitaldistribution_push_benefit_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_push_benefit_V4 - holder */;
            return _toStringIdentityId(
                &m->nested.capitaldistribution_push_benefit_V4.holder,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_reclaim_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.capitaldistribution_reclaim_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_remove_distribution_V4 - ca_id */;
            return _toStringCAId(
                &m->nested.capitaldistribution_remove_distribution_V4.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_checkpoint_V4 - ticker */;
            return _toStringTicker(
                &m->nested.checkpoint_create_checkpoint_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* checkpoint_set_schedules_max_complexity_V4 - max_complexity */;
            return _toStringu64(
                &m->nested.checkpoint_set_schedules_max_complexity_V4.max_complexity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_schedule_V4 - ticker */;
            return _toStringTicker(
                &m->nested.checkpoint_create_schedule_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_create_schedule_V4 - schedule */;
            return _toStringScheduleCheckpoints(
                &m->nested.checkpoint_create_schedule_V4.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* checkpoint_remove_schedule_V4 - ticker */;
            return _toStringTicker(
                &m->nested.checkpoint_remove_schedule_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_remove_schedule_V4 - id */;
            return _toStringScheduleId(
                &m->nested.checkpoint_remove_schedule_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_compliance_requirement_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_add_compliance_requirement_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_compliance_requirement_V4 - sender_conditions */;
            return _toStringVecCondition(
                &m->nested.compliancemanager_add_compliance_requirement_V4.sender_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* compliancemanager_add_compliance_requirement_V4 - receiver_conditions */;
            return _toStringVecCondition(
                &m->nested.compliancemanager_add_compliance_requirement_V4.receiver_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_compliance_requirement_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_remove_compliance_requirement_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_compliance_requirement_V4 - id */;
            return _toStringu32(
                &m->nested.compliancemanager_remove_compliance_requirement_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* compliancemanager_replace_asset_compliance_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_replace_asset_compliance_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_replace_asset_compliance_V4 - asset_compliance */;
            return _toStringVecComplianceRequirement(
                &m->nested.compliancemanager_replace_asset_compliance_V4.asset_compliance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* compliancemanager_reset_asset_compliance_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_reset_asset_compliance_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* compliancemanager_pause_asset_compliance_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_pause_asset_compliance_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* compliancemanager_resume_asset_compliance_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_resume_asset_compliance_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_default_trusted_claim_issuer_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_add_default_trusted_claim_issuer_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_default_trusted_claim_issuer_V4 - issuer */;
            return _toStringTrustedIssuer(
                &m->nested.compliancemanager_add_default_trusted_claim_issuer_V4.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_default_trusted_claim_issuer_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_remove_default_trusted_claim_issuer_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_default_trusted_claim_issuer_V4 - issuer */;
            return _toStringIdentityId(
                &m->nested.compliancemanager_remove_default_trusted_claim_issuer_V4.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0: /* compliancemanager_change_compliance_requirement_V4 - ticker */;
            return _toStringTicker(
                &m->nested.compliancemanager_change_compliance_requirement_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_change_compliance_requirement_V4 - new_req */;
            return _toStringComplianceRequirement(
                &m->nested.compliancemanager_change_compliance_requirement_V4.new_req,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0: /* pips_set_prune_historical_pips_V4 - prune */;
            return _toStringbool(
                &m->nested.pips_set_prune_historical_pips_V4.prune,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8449: /* module 33 call 1 */
        switch (itemIdx) {
        case 0: /* pips_set_min_proposal_deposit_V4 - deposit */;
            return _toStringBalance(
                &m->nested.pips_set_min_proposal_deposit_V4.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8450: /* module 33 call 2 */
        switch (itemIdx) {
        case 0: /* pips_set_default_enactment_period_V4 - duration */;
            return _toStringBlockNumber(
                &m->nested.pips_set_default_enactment_period_V4.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8451: /* module 33 call 3 */
        switch (itemIdx) {
        case 0: /* pips_set_pending_pip_expiry_V4 - expiry */;
            return _toStringMaybeBlockBlockNumber(
                &m->nested.pips_set_pending_pip_expiry_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8452: /* module 33 call 4 */
        switch (itemIdx) {
        case 0: /* pips_set_max_pip_skip_count_V4 - max */;
            return _toStringSkippedCount(
                &m->nested.pips_set_max_pip_skip_count_V4.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8453: /* module 33 call 5 */
        switch (itemIdx) {
        case 0: /* pips_set_active_pip_limit_V4 - limit */;
            return _toStringu32(
                &m->nested.pips_set_active_pip_limit_V4.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8456: /* module 33 call 8 */
        switch (itemIdx) {
        case 0: /* pips_approve_committee_proposal_V4 - id */;
            return _toStringPipId(
                &m->nested.pips_approve_committee_proposal_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8457: /* module 33 call 9 */
        switch (itemIdx) {
        case 0: /* pips_reject_proposal_V4 - id */;
            return _toStringPipId(
                &m->nested.pips_reject_proposal_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8458: /* module 33 call 10 */
        switch (itemIdx) {
        case 0: /* pips_prune_proposal_V4 - id */;
            return _toStringPipId(
                &m->nested.pips_prune_proposal_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8459: /* module 33 call 11 */
        switch (itemIdx) {
        case 0: /* pips_reschedule_execution_V4 - id */;
            return _toStringPipId(
                &m->nested.pips_reschedule_execution_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_reschedule_execution_V4 - until */;
            return _toStringOptionBlockNumber(
                &m->nested.pips_reschedule_execution_V4.until,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8460: /* module 33 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8461: /* module 33 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 8463: /* module 33 call 15 */
        switch (itemIdx) {
        case 0: /* pips_execute_scheduled_pip_V4 - id */;
            return _toStringPipId(
                &m->nested.pips_execute_scheduled_pip_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8464: /* module 33 call 16 */
        switch (itemIdx) {
        case 0: /* pips_expire_scheduled_pip_V4 - did */;
            return _toStringIdentityId(
                &m->nested.pips_expire_scheduled_pip_V4.did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_expire_scheduled_pip_V4 - id */;
            return _toStringPipId(
                &m->nested.pips_expire_scheduled_pip_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* portfolio_create_portfolio_V4 - name */;
            return _toStringPortfolioName(
                &m->nested.portfolio_create_portfolio_V4.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0: /* portfolio_delete_portfolio_V4 - num */;
            return _toStringPortfolioNumber(
                &m->nested.portfolio_delete_portfolio_V4.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0: /* portfolio_rename_portfolio_V4 - num */;
            return _toStringPortfolioNumber(
                &m->nested.portfolio_rename_portfolio_V4.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_rename_portfolio_V4 - to_name */;
            return _toStringPortfolioName(
                &m->nested.portfolio_rename_portfolio_V4.to_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0: /* portfolio_quit_portfolio_custody_V4 - pid */;
            return _toStringPortfolioId(
                &m->basic.portfolio_quit_portfolio_custody_V4.pid,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0: /* portfolio_accept_portfolio_custody_V4 - auth_id */;
            return _toStringu64(
                &m->basic.portfolio_accept_portfolio_custody_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        case 0: /* portfolio_move_portfolio_funds_V4 - from */;
            return _toStringPortfolioId(
                &m->nested.portfolio_move_portfolio_funds_V4.from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_move_portfolio_funds_V4 - to */;
            return _toStringPortfolioId(
                &m->nested.portfolio_move_portfolio_funds_V4.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* portfolio_move_portfolio_funds_V4 - funds */;
            return _toStringVecFund(
                &m->nested.portfolio_move_portfolio_funds_V4.funds,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8710: /* module 34 call 6 */
        switch (itemIdx) {
        case 0: /* portfolio_pre_approve_portfolio_V4 - ticker */;
            return _toStringTicker(
                &m->basic.portfolio_pre_approve_portfolio_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_pre_approve_portfolio_V4 - portfolio_id */;
            return _toStringPortfolioId(
                &m->basic.portfolio_pre_approve_portfolio_V4.portfolio_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8711: /* module 34 call 7 */
        switch (itemIdx) {
        case 0: /* portfolio_remove_portfolio_pre_approval_V4 - ticker */;
            return _toStringTicker(
                &m->basic.portfolio_remove_portfolio_pre_approval_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_remove_portfolio_pre_approval_V4 - portfolio_id */;
            return _toStringPortfolioId(
                &m->basic.portfolio_remove_portfolio_pre_approval_V4.portfolio_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* protocolfee_change_coefficient_V4 - coefficient */;
            return _toStringPosRatio(
                &m->nested.protocolfee_change_coefficient_V4.coefficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* settlement_create_venue_V4 - details */;
            return _toStringVenueDetails(
                &m->nested.settlement_create_venue_V4.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_create_venue_V4 - signers */;
            return _toStringVecAccountId(
                &m->nested.settlement_create_venue_V4.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_create_venue_V4 - typ */;
            return _toStringVenueType(
                &m->nested.settlement_create_venue_V4.typ,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* settlement_update_venue_details_V4 - id */;
            return _toStringVenueId(
                &m->basic.settlement_update_venue_details_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_update_venue_details_V4 - details */;
            return _toStringVenueDetails(
                &m->basic.settlement_update_venue_details_V4.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0: /* settlement_update_venue_type_V4 - id */;
            return _toStringVenueId(
                &m->basic.settlement_update_venue_type_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_update_venue_type_V4 - typ */;
            return _toStringVenueType(
                &m->basic.settlement_update_venue_type_V4.typ,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_with_receipts_V4 - id */;
            return _toStringInstructionId(
                &m->nested.settlement_affirm_with_receipts_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_with_receipts_V4 - receipt_details */;
            return _toStringVecReceiptDetails(
                &m->nested.settlement_affirm_with_receipts_V4.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_with_receipts_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->nested.settlement_affirm_with_receipts_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* settlement_set_venue_filtering_V4 - ticker */;
            return _toStringTicker(
                &m->nested.settlement_set_venue_filtering_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_set_venue_filtering_V4 - enabled */;
            return _toStringbool(
                &m->nested.settlement_set_venue_filtering_V4.enabled,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0: /* settlement_allow_venues_V4 - ticker */;
            return _toStringTicker(
                &m->nested.settlement_allow_venues_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_allow_venues_V4 - venues */;
            return _toStringVecVenueId(
                &m->nested.settlement_allow_venues_V4.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0: /* settlement_disallow_venues_V4 - ticker */;
            return _toStringTicker(
                &m->nested.settlement_disallow_venues_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_disallow_venues_V4 - venues */;
            return _toStringVecVenueId(
                &m->nested.settlement_disallow_venues_V4.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0: /* settlement_update_venue_signers_V4 - id */;
            return _toStringVenueId(
                &m->basic.settlement_update_venue_signers_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_update_venue_signers_V4 - signers */;
            return _toStringVecAccountId(
                &m->basic.settlement_update_venue_signers_V4.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_update_venue_signers_V4 - add_signers */;
            return _toStringbool(
                &m->basic.settlement_update_venue_signers_V4.add_signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0: /* settlement_execute_manual_instruction_V4 - id */;
            return _toStringInstructionId(
                &m->basic.settlement_execute_manual_instruction_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_execute_manual_instruction_V4 - portfolio */;
            return _toStringOptionPortfolioId(
                &m->basic.settlement_execute_manual_instruction_V4.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_execute_manual_instruction_V4 - fungible_transfers */;
            return _toStringu32(
                &m->basic.settlement_execute_manual_instruction_V4.fungible_transfers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_execute_manual_instruction_V4 - nfts_transfers */;
            return _toStringu32(
                &m->basic.settlement_execute_manual_instruction_V4.nfts_transfers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_execute_manual_instruction_V4 - offchain_transfers */;
            return _toStringu32(
                &m->basic.settlement_execute_manual_instruction_V4.offchain_transfers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_execute_manual_instruction_V4 - weight_limit */;
            return _toStringOptionWeight(
                &m->basic.settlement_execute_manual_instruction_V4.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9481: /* module 37 call 9 */
        switch (itemIdx) {
        case 0: /* settlement_add_instruction_V4 - venue_id */;
            return _toStringVenueId(
                &m->nested.settlement_add_instruction_V4.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_instruction_V4 - settlement_type */;
            return _toStringSettlementTypeBlockNumber(
                &m->nested.settlement_add_instruction_V4.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_instruction_V4 - trade_date */;
            return _toStringOptionMoment(
                &m->nested.settlement_add_instruction_V4.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_instruction_V4 - value_date */;
            return _toStringOptionMoment(
                &m->nested.settlement_add_instruction_V4.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_instruction_V4 - legs */;
            return _toStringVecLeg(
                &m->nested.settlement_add_instruction_V4.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_add_instruction_V4 - instruction_memo */;
            return _toStringOptionMemo(
                &m->nested.settlement_add_instruction_V4.instruction_memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9482: /* module 37 call 10 */
        switch (itemIdx) {
        case 0: /* settlement_add_and_affirm_instruction_V4 - venue_id */;
            return _toStringVenueId(
                &m->nested.settlement_add_and_affirm_instruction_V4.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_and_affirm_instruction_V4 - settlement_type */;
            return _toStringSettlementTypeBlockNumber(
                &m->nested.settlement_add_and_affirm_instruction_V4.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_and_affirm_instruction_V4 - trade_date */;
            return _toStringOptionMoment(
                &m->nested.settlement_add_and_affirm_instruction_V4.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_and_affirm_instruction_V4 - value_date */;
            return _toStringOptionMoment(
                &m->nested.settlement_add_and_affirm_instruction_V4.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_and_affirm_instruction_V4 - legs */;
            return _toStringVecLeg(
                &m->nested.settlement_add_and_affirm_instruction_V4.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_add_and_affirm_instruction_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->nested.settlement_add_and_affirm_instruction_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* settlement_add_and_affirm_instruction_V4 - instruction_memo */;
            return _toStringOptionMemo(
                &m->nested.settlement_add_and_affirm_instruction_V4.instruction_memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9483: /* module 37 call 11 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_instruction_V4 - id */;
            return _toStringInstructionId(
                &m->nested.settlement_affirm_instruction_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_instruction_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->nested.settlement_affirm_instruction_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9484: /* module 37 call 12 */
        switch (itemIdx) {
        case 0: /* settlement_withdraw_affirmation_V4 - id */;
            return _toStringInstructionId(
                &m->nested.settlement_withdraw_affirmation_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_withdraw_affirmation_V4 - portfolios */;
            return _toStringVecPortfolioId(
                &m->nested.settlement_withdraw_affirmation_V4.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9485: /* module 37 call 13 */
        switch (itemIdx) {
        case 0: /* settlement_reject_instruction_V4 - id */;
            return _toStringInstructionId(
                &m->nested.settlement_reject_instruction_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_reject_instruction_V4 - portfolio */;
            return _toStringPortfolioId(
                &m->nested.settlement_reject_instruction_V4.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9486: /* module 37 call 14 */
        switch (itemIdx) {
        case 0: /* settlement_execute_scheduled_instruction_V4 - id */;
            return _toStringInstructionId(
                &m->nested.settlement_execute_scheduled_instruction_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_execute_scheduled_instruction_V4 - weight_limit */;
            return _toStringWeight(
                &m->nested.settlement_execute_scheduled_instruction_V4.weight_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0: /* sto_create_fundraiser_V4 - offering_portfolio */;
            return _toStringPortfolioId(
                &m->basic.sto_create_fundraiser_V4.offering_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_create_fundraiser_V4 - offering_asset */;
            return _toStringTicker(
                &m->basic.sto_create_fundraiser_V4.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_create_fundraiser_V4 - raising_portfolio */;
            return _toStringPortfolioId(
                &m->basic.sto_create_fundraiser_V4.raising_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_create_fundraiser_V4 - raising_asset */;
            return _toStringTicker(
                &m->basic.sto_create_fundraiser_V4.raising_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_create_fundraiser_V4 - tiers */;
            return _toStringVecPriceTier(
                &m->basic.sto_create_fundraiser_V4.tiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_create_fundraiser_V4 - venue_id */;
            return _toStringVenueId(
                &m->basic.sto_create_fundraiser_V4.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_create_fundraiser_V4 - start */;
            return _toStringOptionMoment(
                &m->basic.sto_create_fundraiser_V4.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* sto_create_fundraiser_V4 - end */;
            return _toStringOptionMoment(
                &m->basic.sto_create_fundraiser_V4.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 8: /* sto_create_fundraiser_V4 - minimum_investment */;
            return _toStringBalanceNoSymbol(
                &m->basic.sto_create_fundraiser_V4.minimum_investment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 9: /* sto_create_fundraiser_V4 - fundraiser_name */;
            return _toStringFundraiserName(
                &m->basic.sto_create_fundraiser_V4.fundraiser_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0: /* sto_invest_V4 - investment_portfolio */;
            return _toStringPortfolioId(
                &m->basic.sto_invest_V4.investment_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_invest_V4 - funding_portfolio */;
            return _toStringPortfolioId(
                &m->basic.sto_invest_V4.funding_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_invest_V4 - offering_asset */;
            return _toStringTicker(
                &m->basic.sto_invest_V4.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_invest_V4 - id */;
            return _toStringFundraiserId(
                &m->basic.sto_invest_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_invest_V4 - purchase_amount */;
            return _toStringBalanceNoSymbol(
                &m->basic.sto_invest_V4.purchase_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_invest_V4 - max_price */;
            return _toStringOptionBalance(
                &m->basic.sto_invest_V4.max_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_invest_V4 - receipt */;
            return _toStringOptionReceiptDetails(
                &m->basic.sto_invest_V4.receipt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9986: /* module 39 call 2 */
        switch (itemIdx) {
        case 0: /* sto_freeze_fundraiser_V4 - offering_asset */;
            return _toStringTicker(
                &m->basic.sto_freeze_fundraiser_V4.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_freeze_fundraiser_V4 - id */;
            return _toStringFundraiserId(
                &m->basic.sto_freeze_fundraiser_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9987: /* module 39 call 3 */
        switch (itemIdx) {
        case 0: /* sto_unfreeze_fundraiser_V4 - offering_asset */;
            return _toStringTicker(
                &m->basic.sto_unfreeze_fundraiser_V4.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_unfreeze_fundraiser_V4 - id */;
            return _toStringFundraiserId(
                &m->basic.sto_unfreeze_fundraiser_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9988: /* module 39 call 4 */
        switch (itemIdx) {
        case 0: /* sto_modify_fundraiser_window_V4 - offering_asset */;
            return _toStringTicker(
                &m->basic.sto_modify_fundraiser_window_V4.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_modify_fundraiser_window_V4 - id */;
            return _toStringFundraiserId(
                &m->basic.sto_modify_fundraiser_window_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_modify_fundraiser_window_V4 - start */;
            return _toStringMoment(
                &m->basic.sto_modify_fundraiser_window_V4.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_modify_fundraiser_window_V4 - end */;
            return _toStringOptionMoment(
                &m->basic.sto_modify_fundraiser_window_V4.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9989: /* module 39 call 5 */
        switch (itemIdx) {
        case 0: /* sto_stop_V4 - offering_asset */;
            return _toStringTicker(
                &m->basic.sto_stop_V4.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_stop_V4 - id */;
            return _toStringFundraiserId(
                &m->basic.sto_stop_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_disbursement_V4 - beneficiaries */;
            return _toStringVecBeneficiary(
                &m->nested.treasury_disbursement_V4.beneficiaries,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reimbursement_V4 - amount */;
            return _toStringBalance(
                &m->nested.treasury_reimbursement_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* utility_relay_tx_V4 - target */;
            return _toStringAccountId(
                &m->nested.utility_relay_tx_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_relay_tx_V4 - signature */;
            return _toStringOffChainSignature(
                &m->nested.utility_relay_tx_V4.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* utility_relay_tx_V4 - call */;
            return _toStringUniqueCall(
                &m->nested.utility_relay_tx_V4.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_all_V4 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_all_V4.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* utility_dispatch_as_V4 - as_origin */;
            return _toStringBoxPalletsOrigin(
                &m->basic.utility_dispatch_as_V4.as_origin,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_dispatch_as_V4 - call */;
            return _toStringCall(
                &m->basic.utility_dispatch_as_V4.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10500: /* module 41 call 4 */
        switch (itemIdx) {
        case 0: /* utility_force_batch_V4 - calls */;
            return _toStringVecCall(
                &m->basic.utility_force_batch_V4.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10501: /* module 41 call 5 */
        switch (itemIdx) {
        case 0: /* utility_with_weight_V4 - call */;
            return _toStringCall(
                &m->basic.utility_with_weight_V4.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_with_weight_V4 - weight */;
            return _toStringWeight(
                &m->basic.utility_with_weight_V4.weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10502: /* module 41 call 6 */
        switch (itemIdx) {
        case 0: /* utility_batch_old_V4 - calls */;
            return _toStringVecCall(
                &m->basic.utility_batch_old_V4.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10505: /* module 41 call 9 */
        switch (itemIdx) {
        case 0: /* utility_as_derivative_V4 - index */;
            return _toStringu16(
                &m->basic.utility_as_derivative_V4.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_as_derivative_V4 - call */;
            return _toStringCall(
                &m->basic.utility_as_derivative_V4.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11008: /* module 43 call 0 */
        switch (itemIdx) {
        case 0: /* externalagents_create_group_V4 - ticker */;
            return _toStringTicker(
                &m->basic.externalagents_create_group_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* externalagents_create_group_V4 - perms */;
            return _toStringExtrinsicPermissions(
                &m->basic.externalagents_create_group_V4.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11009: /* module 43 call 1 */
        switch (itemIdx) {
        case 0: /* externalagents_set_group_permissions_V4 - ticker */;
            return _toStringTicker(
                &m->basic.externalagents_set_group_permissions_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* externalagents_set_group_permissions_V4 - id */;
            return _toStringAGId(
                &m->basic.externalagents_set_group_permissions_V4.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* externalagents_set_group_permissions_V4 - perms */;
            return _toStringExtrinsicPermissions(
                &m->basic.externalagents_set_group_permissions_V4.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11010: /* module 43 call 2 */
        switch (itemIdx) {
        case 0: /* externalagents_remove_agent_V4 - ticker */;
            return _toStringTicker(
                &m->basic.externalagents_remove_agent_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* externalagents_remove_agent_V4 - agent */;
            return _toStringIdentityId(
                &m->basic.externalagents_remove_agent_V4.agent,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11011: /* module 43 call 3 */
        switch (itemIdx) {
        case 0: /* externalagents_abdicate_V4 - ticker */;
            return _toStringTicker(
                &m->basic.externalagents_abdicate_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11012: /* module 43 call 4 */
        switch (itemIdx) {
        case 0: /* externalagents_change_group_V4 - ticker */;
            return _toStringTicker(
                &m->basic.externalagents_change_group_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* externalagents_change_group_V4 - agent */;
            return _toStringIdentityId(
                &m->basic.externalagents_change_group_V4.agent,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* externalagents_change_group_V4 - group */;
            return _toStringAgentGroup(
                &m->basic.externalagents_change_group_V4.group,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11013: /* module 43 call 5 */
        switch (itemIdx) {
        case 0: /* externalagents_accept_become_agent_V4 - auth_id */;
            return _toStringu64(
                &m->basic.externalagents_accept_become_agent_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11014: /* module 43 call 6 */
        switch (itemIdx) {
        case 0: /* externalagents_create_group_and_add_auth_V4 - ticker */;
            return _toStringTicker(
                &m->basic.externalagents_create_group_and_add_auth_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* externalagents_create_group_and_add_auth_V4 - perms */;
            return _toStringExtrinsicPermissions(
                &m->basic.externalagents_create_group_and_add_auth_V4.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* externalagents_create_group_and_add_auth_V4 - target */;
            return _toStringIdentityId(
                &m->basic.externalagents_create_group_and_add_auth_V4.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* externalagents_create_group_and_add_auth_V4 - expiry */;
            return _toStringOptionMoment(
                &m->basic.externalagents_create_group_and_add_auth_V4.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11015: /* module 43 call 7 */
        switch (itemIdx) {
        case 0: /* externalagents_create_and_change_custom_group_V4 - ticker */;
            return _toStringTicker(
                &m->basic.externalagents_create_and_change_custom_group_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* externalagents_create_and_change_custom_group_V4 - perms */;
            return _toStringExtrinsicPermissions(
                &m->basic.externalagents_create_and_change_custom_group_V4.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* externalagents_create_and_change_custom_group_V4 - agent */;
            return _toStringIdentityId(
                &m->basic.externalagents_create_and_change_custom_group_V4.agent,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11264: /* module 44 call 0 */
        switch (itemIdx) {
        case 0: /* relayer_set_paying_key_V4 - user_key */;
            return _toStringAccountId(
                &m->basic.relayer_set_paying_key_V4.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_set_paying_key_V4 - polyx_limit */;
            return _toStringBalance(
                &m->basic.relayer_set_paying_key_V4.polyx_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11265: /* module 44 call 1 */
        switch (itemIdx) {
        case 0: /* relayer_accept_paying_key_V4 - auth_id */;
            return _toStringu64(
                &m->basic.relayer_accept_paying_key_V4.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11266: /* module 44 call 2 */
        switch (itemIdx) {
        case 0: /* relayer_remove_paying_key_V4 - user_key */;
            return _toStringAccountId(
                &m->basic.relayer_remove_paying_key_V4.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_remove_paying_key_V4 - paying_key */;
            return _toStringAccountId(
                &m->basic.relayer_remove_paying_key_V4.paying_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11267: /* module 44 call 3 */
        switch (itemIdx) {
        case 0: /* relayer_update_polyx_limit_V4 - user_key */;
            return _toStringAccountId(
                &m->basic.relayer_update_polyx_limit_V4.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_update_polyx_limit_V4 - polyx_limit */;
            return _toStringBalance(
                &m->basic.relayer_update_polyx_limit_V4.polyx_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11268: /* module 44 call 4 */
        switch (itemIdx) {
        case 0: /* relayer_increase_polyx_limit_V4 - user_key */;
            return _toStringAccountId(
                &m->basic.relayer_increase_polyx_limit_V4.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_increase_polyx_limit_V4 - amount */;
            return _toStringBalance(
                &m->basic.relayer_increase_polyx_limit_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11269: /* module 44 call 5 */
        switch (itemIdx) {
        case 0: /* relayer_decrease_polyx_limit_V4 - user_key */;
            return _toStringAccountId(
                &m->basic.relayer_decrease_polyx_limit_V4.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_decrease_polyx_limit_V4 - amount */;
            return _toStringBalance(
                &m->basic.relayer_decrease_polyx_limit_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0: /* contracts_call_old_weight_V4 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.contracts_call_old_weight_V4.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_old_weight_V4 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_call_old_weight_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_old_weight_V4 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.contracts_call_old_weight_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_old_weight_V4 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_call_old_weight_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_call_old_weight_V4 - data */;
            return _toStringBytes(
                &m->basic.contracts_call_old_weight_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_with_code_old_weight_V4 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_instantiate_with_code_old_weight_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_with_code_old_weight_V4 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.contracts_instantiate_with_code_old_weight_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_with_code_old_weight_V4 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_instantiate_with_code_old_weight_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_with_code_old_weight_V4 - code */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_old_weight_V4.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_with_code_old_weight_V4 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_old_weight_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_with_code_old_weight_V4 - salt */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_old_weight_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_old_weight_V4 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_instantiate_old_weight_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_old_weight_V4 - gas_limit */;
            return _toStringCompactu64(
                &m->basic.contracts_instantiate_old_weight_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_old_weight_V4 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_instantiate_old_weight_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_old_weight_V4 - code_hash */;
            return _toStringCodeHash(
                &m->basic.contracts_instantiate_old_weight_V4.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_old_weight_V4 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_old_weight_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_old_weight_V4 - salt */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_old_weight_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0: /* contracts_upload_code_V4 - code */;
            return _toStringBytes(
                &m->basic.contracts_upload_code_V4.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_upload_code_V4 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_upload_code_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_upload_code_V4 - determinism */;
            return _toStringDeterminism(
                &m->basic.contracts_upload_code_V4.determinism,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11780: /* module 46 call 4 */
        switch (itemIdx) {
        case 0: /* contracts_remove_code_V4 - code_hash */;
            return _toStringCodeHash(
                &m->basic.contracts_remove_code_V4.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11781: /* module 46 call 5 */
        switch (itemIdx) {
        case 0: /* contracts_set_code_V4 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->basic.contracts_set_code_V4.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_set_code_V4 - code_hash */;
            return _toStringCodeHash(
                &m->basic.contracts_set_code_V4.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11782: /* module 46 call 6 */
        switch (itemIdx) {
        case 0: /* contracts_call_V4 - dest */;
            return _toStringAccountIdLookupOfT(
                &m->nested.contracts_call_V4.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_call_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_V4 - gas_limit */;
            return _toStringWeight(
                &m->nested.contracts_call_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_V4 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_call_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_call_V4 - data */;
            return _toStringBytes(
                &m->nested.contracts_call_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11783: /* module 46 call 7 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_with_code_V4 - amount */;
            return _toStringCompactBalance(
                &m->basic.contracts_instantiate_with_code_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_with_code_V4 - gas_limit */;
            return _toStringWeight(
                &m->basic.contracts_instantiate_with_code_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_with_code_V4 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->basic.contracts_instantiate_with_code_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_with_code_V4 - code */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_V4.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_with_code_V4 - data */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_with_code_V4 - salt */;
            return _toStringBytes(
                &m->basic.contracts_instantiate_with_code_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11784: /* module 46 call 8 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_V4 - amount */;
            return _toStringCompactBalance(
                &m->nested.contracts_instantiate_V4.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_V4 - gas_limit */;
            return _toStringWeight(
                &m->nested.contracts_instantiate_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_V4 - storage_deposit_limit */;
            return _toStringOptionCompactBalanceOf(
                &m->nested.contracts_instantiate_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_V4 - code_hash */;
            return _toStringCodeHash(
                &m->nested.contracts_instantiate_V4.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_V4 - data */;
            return _toStringBytes(
                &m->nested.contracts_instantiate_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* contracts_instantiate_V4 - salt */;
            return _toStringBytes(
                &m->nested.contracts_instantiate_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12032: /* module 47 call 0 */
        switch (itemIdx) {
        case 0: /* polymeshcontracts_instantiate_with_code_perms_V4 - endowment */;
            return _toStringBalance(
                &m->basic.polymeshcontracts_instantiate_with_code_perms_V4.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcontracts_instantiate_with_code_perms_V4 - gas_limit */;
            return _toStringWeight(
                &m->basic.polymeshcontracts_instantiate_with_code_perms_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcontracts_instantiate_with_code_perms_V4 - storage_deposit_limit */;
            return _toStringOptionBalance(
                &m->basic.polymeshcontracts_instantiate_with_code_perms_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polymeshcontracts_instantiate_with_code_perms_V4 - code */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_code_perms_V4.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polymeshcontracts_instantiate_with_code_perms_V4 - data */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_code_perms_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* polymeshcontracts_instantiate_with_code_perms_V4 - salt */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_code_perms_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* polymeshcontracts_instantiate_with_code_perms_V4 - perms */;
            return _toStringPermissions(
                &m->basic.polymeshcontracts_instantiate_with_code_perms_V4.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12033: /* module 47 call 1 */
        switch (itemIdx) {
        case 0: /* polymeshcontracts_instantiate_with_hash_perms_V4 - endowment */;
            return _toStringBalance(
                &m->basic.polymeshcontracts_instantiate_with_hash_perms_V4.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcontracts_instantiate_with_hash_perms_V4 - gas_limit */;
            return _toStringWeight(
                &m->basic.polymeshcontracts_instantiate_with_hash_perms_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcontracts_instantiate_with_hash_perms_V4 - storage_deposit_limit */;
            return _toStringOptionBalance(
                &m->basic.polymeshcontracts_instantiate_with_hash_perms_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polymeshcontracts_instantiate_with_hash_perms_V4 - code_hash */;
            return _toStringCodeHash(
                &m->basic.polymeshcontracts_instantiate_with_hash_perms_V4.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polymeshcontracts_instantiate_with_hash_perms_V4 - data */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_hash_perms_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* polymeshcontracts_instantiate_with_hash_perms_V4 - salt */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_hash_perms_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* polymeshcontracts_instantiate_with_hash_perms_V4 - perms */;
            return _toStringPermissions(
                &m->basic.polymeshcontracts_instantiate_with_hash_perms_V4.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12034: /* module 47 call 2 */
        switch (itemIdx) {
        case 0: /* polymeshcontracts_update_call_runtime_whitelist_V4 - updates */;
            return _toStringVecTupleExtrinsicIdbool(
                &m->basic.polymeshcontracts_update_call_runtime_whitelist_V4.updates,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12035: /* module 47 call 3 */
        switch (itemIdx) {
        case 0: /* polymeshcontracts_instantiate_with_code_as_primary_key_V4 - endowment */;
            return _toStringBalance(
                &m->basic.polymeshcontracts_instantiate_with_code_as_primary_key_V4.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcontracts_instantiate_with_code_as_primary_key_V4 - gas_limit */;
            return _toStringWeight(
                &m->basic.polymeshcontracts_instantiate_with_code_as_primary_key_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcontracts_instantiate_with_code_as_primary_key_V4 - storage_deposit_limit */;
            return _toStringOptionBalance(
                &m->basic.polymeshcontracts_instantiate_with_code_as_primary_key_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polymeshcontracts_instantiate_with_code_as_primary_key_V4 - code */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_code_as_primary_key_V4.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polymeshcontracts_instantiate_with_code_as_primary_key_V4 - data */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_code_as_primary_key_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* polymeshcontracts_instantiate_with_code_as_primary_key_V4 - salt */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_code_as_primary_key_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12036: /* module 47 call 4 */
        switch (itemIdx) {
        case 0: /* polymeshcontracts_instantiate_with_hash_as_primary_key_V4 - endowment */;
            return _toStringBalance(
                &m->basic.polymeshcontracts_instantiate_with_hash_as_primary_key_V4.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcontracts_instantiate_with_hash_as_primary_key_V4 - gas_limit */;
            return _toStringWeight(
                &m->basic.polymeshcontracts_instantiate_with_hash_as_primary_key_V4.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcontracts_instantiate_with_hash_as_primary_key_V4 - storage_deposit_limit */;
            return _toStringOptionBalance(
                &m->basic.polymeshcontracts_instantiate_with_hash_as_primary_key_V4.storage_deposit_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* polymeshcontracts_instantiate_with_hash_as_primary_key_V4 - code_hash */;
            return _toStringCodeHash(
                &m->basic.polymeshcontracts_instantiate_with_hash_as_primary_key_V4.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* polymeshcontracts_instantiate_with_hash_as_primary_key_V4 - data */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_hash_as_primary_key_V4.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* polymeshcontracts_instantiate_with_hash_as_primary_key_V4 - salt */;
            return _toStringVecu8(
                &m->basic.polymeshcontracts_instantiate_with_hash_as_primary_key_V4.salt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12037: /* module 47 call 5 */
        switch (itemIdx) {
        case 0: /* polymeshcontracts_upgrade_api_V4 - api */;
            return _toStringApi(
                &m->basic.polymeshcontracts_upgrade_api_V4.api,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcontracts_upgrade_api_V4 - next_upgrade */;
            return _toStringNextUpgradeT(
                &m->basic.polymeshcontracts_upgrade_api_V4.next_upgrade,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12288: /* module 48 call 0 */
        switch (itemIdx) {
        case 0: /* preimage_note_preimage_V4 - bytes */;
            return _toStringVecu8(
                &m->basic.preimage_note_preimage_V4.bytes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0: /* preimage_unnote_preimage_V4 - hash */;
            return _toStringHash(
                &m->basic.preimage_unnote_preimage_V4.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0: /* preimage_request_preimage_V4 - hash */;
            return _toStringHash(
                &m->basic.preimage_request_preimage_V4.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0: /* preimage_unrequest_preimage_V4 - hash */;
            return _toStringHash(
                &m->basic.preimage_unrequest_preimage_V4.hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12544: /* module 49 call 0 */
        switch (itemIdx) {
        case 0: /* nft_create_nft_collection_V4 - ticker */;
            return _toStringTicker(
                &m->basic.nft_create_nft_collection_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nft_create_nft_collection_V4 - nft_type */;
            return _toStringOptionNonFungibleType(
                &m->basic.nft_create_nft_collection_V4.nft_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nft_create_nft_collection_V4 - collection_keys */;
            return _toStringVecAssetMetadataKey(
                &m->basic.nft_create_nft_collection_V4.collection_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12545: /* module 49 call 1 */
        switch (itemIdx) {
        case 0: /* nft_issue_nft_V4 - ticker */;
            return _toStringTicker(
                &m->basic.nft_issue_nft_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nft_issue_nft_V4 - nft_metadata_attributes */;
            return _toStringVecNFTMetadataAttribute(
                &m->basic.nft_issue_nft_V4.nft_metadata_attributes,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nft_issue_nft_V4 - portfolio_kind */;
            return _toStringPortfolioKind(
                &m->basic.nft_issue_nft_V4.portfolio_kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12546: /* module 49 call 2 */
        switch (itemIdx) {
        case 0: /* nft_redeem_nft_V4 - ticker */;
            return _toStringTicker(
                &m->basic.nft_redeem_nft_V4.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* nft_redeem_nft_V4 - nft_id */;
            return _toStringNFTId(
                &m->basic.nft_redeem_nft_V4.nft_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* nft_redeem_nft_V4 - portfolio_kind */;
            return _toStringPortfolioKind(
                &m->basic.nft_redeem_nft_V4.portfolio_kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#endif
    default:
        return parser_ok;
    }

    return parser_ok;
}

bool _getMethod_ItemIsExpert_V4(uint8_t moduleIdx, uint8_t callIdx, __Z_UNUSED uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 4355: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 4372: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 4378: // Staking:Reap stash
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }

    default:
        return false;
    }
}

bool _getMethod_IsNestingSupported_V4(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 4104: // Bridge:Batch propose bridge tx
    case 4105: // Bridge:Propose bridge tx
    case 4106: // Bridge:Handle bridge tx
    case 4107: // Bridge:Freeze txs
    case 4108: // Bridge:Unfreeze txs
    case 4109: // Bridge:Handle scheduled bridge tx
    case 4110: // Bridge:Add freeze admin
    case 4111: // Bridge:Remove freeze admin
    case 4112: // Bridge:Remove txs
    case 6670: // Asset:Controller transfer
    case 6671: // Asset:Register custom asset type
    case 6672: // Asset:Create asset with custom type
    case 6673: // Asset:Set asset metadata
    case 6674: // Asset:Set asset metadata details
    case 6675: // Asset:Register and set local asset metadata
    case 6676: // Asset:Register asset metadata local type
    case 6677: // Asset:Register asset metadata global type
    case 6678: // Asset:Redeem from portfolio
    case 6679: // Asset:Update asset type
    case 6680: // Asset:Remove local metadata key
    case 6681: // Asset:Remove metadata value
    case 6682: // Asset:Exempt ticker affirmation
    case 6683: // Asset:Remove ticker affirmation exemption
    case 6684: // Asset:Pre approve ticker
    case 6685: // Asset:Remove ticker pre approval
    case 6686: // Asset:Add mandatory mediators
    case 6687: // Asset:Remove mandatory mediators
    case 8707: // Portfolio:Quit portfolio custody
    case 8708: // Portfolio:Accept portfolio custody
    case 8710: // Portfolio:Pre approve portfolio
    case 8711: // Portfolio:Remove portfolio pre approval
    case 8712: // Portfolio:Allow identity to create portfolios
    case 8713: // Portfolio:Revoke create portfolios permission
    case 8714: // Portfolio:Create custody portfolio
    case 9473: // Settlement:Update venue details
    case 9474: // Settlement:Update venue type
    case 9479: // Settlement:Update venue signers
    case 9480: // Settlement:Execute manual instruction
    case 9487: // Settlement:Affirm with receipts with count
    case 9488: // Settlement:Affirm instruction with count
    case 9489: // Settlement:Reject instruction with count
    case 9490: // Settlement:Withdraw affirmation with count
    case 9491: // Settlement:Add instruction with mediators
    case 9492: // Settlement:Add and affirm with mediators
    case 9493: // Settlement:Affirm instruction as mediator
    case 9494: // Settlement:Withdraw affirmation as mediator
    case 9495: // Settlement:Reject instruction as mediator
    case 9984: // Sto:Create fundraiser
    case 9985: // Sto:Invest
    case 9986: // Sto:Freeze fundraiser
    case 9987: // Sto:Unfreeze fundraiser
    case 9988: // Sto:Modify fundraiser window
    case 9989: // Sto:Stop
    case 10498: // Utility:Batch all
    case 10499: // Utility:Dispatch as
    case 10500: // Utility:Force batch
    case 10501: // Utility:With weight
    case 10502: // Utility:Batch old
    case 10505: // Utility:As derivative
    case 11008: // ExternalAgents:Create group
    case 11009: // ExternalAgents:Set group permissions
    case 11010: // ExternalAgents:Remove agent
    case 11011: // ExternalAgents:Abdicate
    case 11012: // ExternalAgents:Change group
    case 11013: // ExternalAgents:Accept become agent
    case 11014: // ExternalAgents:Create group and add auth
    case 11015: // ExternalAgents:Create and change custom group
    case 11264: // Relayer:Set paying key
    case 11265: // Relayer:Accept paying key
    case 11266: // Relayer:Remove paying key
    case 11267: // Relayer:Update polyx limit
    case 11268: // Relayer:Increase polyx limit
    case 11269: // Relayer:Decrease polyx limit
    case 11776: // Contracts:Call old weight
    case 11777: // Contracts:Instantiate with code old weight
    case 11778: // Contracts:Instantiate old weight
    case 11779: // Contracts:Upload code
    case 11780: // Contracts:Remove code
    case 11781: // Contracts:Set code
    case 11783: // Contracts:Instantiate with code
    case 12032: // PolymeshContracts:Instantiate with code perms
    case 12033: // PolymeshContracts:Instantiate with hash perms
    case 12034: // PolymeshContracts:Update call runtime whitelist
    case 12035: // PolymeshContracts:Instantiate with code as primary key
    case 12036: // PolymeshContracts:Instantiate with hash as primary key
    case 12037: // PolymeshContracts:Upgrade api
    case 12288: // Preimage:Note preimage
    case 12289: // Preimage:Unnote preimage
    case 12290: // Preimage:Request preimage
    case 12291: // Preimage:Unrequest preimage
    case 12544: // Nft:Create nft collection
    case 12545: // Nft:Issue nft
    case 12546: // Nft:Redeem nft
    case 12547: // Nft:Controller transfer
        return false;
    default:
        return true;
    }
}
