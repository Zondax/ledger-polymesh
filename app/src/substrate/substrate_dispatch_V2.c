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

#include "substrate_dispatch_V2.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

#ifndef DISABLE_CURRENT

__Z_INLINE parser_error_t _readMethod_balances_transfer_V2(
    parser_context_t* c, pd_balances_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_secondary_keys_V2(
    parser_context_t* c, pd_identity_remove_secondary_keys_V2_t* m)
{
    CHECK_ERROR(_readVecSignatory_V2(c, &m->signers_to_remove))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_primary_key_V2(
    parser_context_t* c, pd_identity_accept_primary_key_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->rotation_auth_id))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_key_V2(
    parser_context_t* c, pd_identity_join_identity_as_key_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_key_V2(
    parser_context_t* c, pd_identity_leave_identity_as_key_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_claim_V2(
    parser_context_t* c, pd_identity_add_claim_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->target))
    CHECK_ERROR(_readClaim_V2(c, &m->claim))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_claim_V2(
    parser_context_t* c, pd_identity_revoke_claim_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->target))
    CHECK_ERROR(_readClaim_V2(c, &m->claim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_permission_to_signer_V2(
    parser_context_t* c, pd_identity_set_permission_to_signer_V2_t* m)
{
    CHECK_ERROR(_readSignatory_V2(c, &m->signer))
    CHECK_ERROR(_readPermissions_V2(c, &m->perms))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_freeze_secondary_keys_V2(
    parser_context_t* c, pd_identity_freeze_secondary_keys_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_unfreeze_secondary_keys_V2(
    parser_context_t* c, pd_identity_unfreeze_secondary_keys_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_authorization_V2(
    parser_context_t* c, pd_identity_add_authorization_V2_t* m)
{
    CHECK_ERROR(_readSignatory_V2(c, &m->target))
    CHECK_ERROR(_readAuthorizationData_V2(c, &m->data))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_authorization_V2(
    parser_context_t* c, pd_identity_remove_authorization_V2_t* m)
{
    CHECK_ERROR(_readSignatory_V2(c, &m->target))
    CHECK_ERROR(_readu64(c, &m->auth_id))
    CHECK_ERROR(_readbool(c, &m->_auth_issuer_pays))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_secondary_keys_with_authorization_V2(
    parser_context_t* c, pd_identity_add_secondary_keys_with_authorization_V2_t* m)
{
    CHECK_ERROR(_readVecSecondaryKeyWithAuth_V2(c, &m->additional_keys))
    CHECK_ERROR(_readMoment_V2(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_investor_uniqueness_claim_V2(
    parser_context_t* c, pd_identity_add_investor_uniqueness_claim_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->target))
    CHECK_ERROR(_readClaim_V2(c, &m->claim))
    CHECK_ERROR(_readInvestorZKProofData_V2(c, &m->proof))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_multisig_V2(
    parser_context_t* c, pd_multisig_create_multisig_V2_t* m)
{
    CHECK_ERROR(_readVecSignatory_V2(c, &m->signers))
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_identity_V2(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_identity_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_key_V2(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_key_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_identity_V2(
    parser_context_t* c, pd_multisig_create_proposal_as_identity_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_key_V2(
    parser_context_t* c, pd_multisig_create_proposal_as_key_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_identity_V2(
    parser_context_t* c, pd_multisig_approve_as_identity_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_key_V2(
    parser_context_t* c, pd_multisig_approve_as_key_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_identity_V2(
    parser_context_t* c, pd_multisig_reject_as_identity_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_key_V2(
    parser_context_t* c, pd_multisig_reject_as_key_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_identity_V2(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_identity_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_key_V2(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_key_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signer_V2(
    parser_context_t* c, pd_multisig_add_multisig_signer_V2_t* m)
{
    CHECK_ERROR(_readSignatory_V2(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signer_V2(
    parser_context_t* c, pd_multisig_remove_multisig_signer_V2_t* m)
{
    CHECK_ERROR(_readSignatory_V2(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signers_via_creator_V2(
    parser_context_t* c, pd_multisig_add_multisig_signers_via_creator_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readVecSignatory_V2(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signers_via_creator_V2(
    parser_context_t* c, pd_multisig_remove_multisig_signers_via_creator_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readVecSignatory_V2(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_change_sigs_required_V2(
    parser_context_t* c, pd_multisig_change_sigs_required_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_signer_V2(
    parser_context_t* c, pd_multisig_make_multisig_signer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_primary_V2(
    parser_context_t* c, pd_multisig_make_multisig_primary_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_execute_scheduled_proposal_V2(
    parser_context_t* c, pd_multisig_execute_scheduled_proposal_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    CHECK_ERROR(_readIdentityId_V2(c, &m->multisig_did))
    CHECK_ERROR(_readWeight_V2(c, &m->_proposal_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V2(
    parser_context_t* c, pd_staking_bond_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V2(
    parser_context_t* c, pd_staking_bond_extra_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V2(
    parser_context_t* c, pd_staking_unbond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V2(
    parser_context_t* c, pd_staking_withdraw_unbonded_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V2(
    parser_context_t* c, pd_staking_validate_V2_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V2(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V2(
    parser_context_t* c, pd_staking_nominate_V2_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V2(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V2(
    parser_context_t* c, pd_staking_chill_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V2(
    parser_context_t* c, pd_staking_set_payee_V2_t* m)
{
    CHECK_ERROR(_readRewardDestination_V2(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V2(
    parser_context_t* c, pd_staking_set_controller_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V2(
    parser_context_t* c, pd_staking_rebond_V2_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_propose_V2(
    parser_context_t* c, pd_pips_propose_V2_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readBalance(c, &m->deposit))
    CHECK_ERROR(_readOptionUrl_V2(c, &m->url))
    CHECK_ERROR(_readOptionPipDescription_V2(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_vote_V2(
    parser_context_t* c, pd_pips_vote_V2_t* m)
{
    CHECK_ERROR(_readPipId_V2(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->aye_or_nay))
    CHECK_ERROR(_readBalance(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V2(
    parser_context_t* c, pd_utility_batch_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_atomic_V2(
    parser_context_t* c, pd_utility_batch_atomic_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_optimistic_V2(
    parser_context_t* c, pd_utility_batch_optimistic_V2_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V2(
    parser_context_t* c, pd_system_fill_block_V2_t* m)
{
    CHECK_ERROR(_readPerbill_V2(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V2(
    parser_context_t* c, pd_system_remark_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V2(
    parser_context_t* c, pd_system_set_heap_pages_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V2(
    parser_context_t* c, pd_system_set_code_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V2(
    parser_context_t* c, pd_system_set_code_without_checks_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V2(
    parser_context_t* c, pd_timestamp_set_V2_t* m)
{
    CHECK_ERROR(_readCompactMoment_V2(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V2(
    parser_context_t* c, pd_indices_claim_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V2(
    parser_context_t* c, pd_indices_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V2(
    parser_context_t* c, pd_indices_free_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V2(
    parser_context_t* c, pd_indices_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V2(
    parser_context_t* c, pd_indices_freeze_V2_t* m)
{
    CHECK_ERROR(_readAccountIndex_V2(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_with_memo_V2(
    parser_context_t* c, pd_balances_transfer_with_memo_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    CHECK_ERROR(_readOptionMemo_V2(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_deposit_block_reward_reserve_balance_V2(
    parser_context_t* c, pd_balances_deposit_block_reward_reserve_balance_V2_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V2(
    parser_context_t* c, pd_balances_set_balance_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V2(
    parser_context_t* c, pd_balances_force_transfer_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->source))
    CHECK_ERROR(_readLookupSource_V2(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_burn_account_balance_V2(
    parser_context_t* c, pd_balances_burn_account_balance_V2_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_invalidate_cdd_claims_V2(
    parser_context_t* c, pd_identity_invalidate_cdd_claims_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->cdd))
    CHECK_ERROR(_readMoment_V2(c, &m->disable_from))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_change_cdd_requirement_for_mk_rotation_V2(
    parser_context_t* c, pd_identity_change_cdd_requirement_for_mk_rotation_V2_t* m)
{
    CHECK_ERROR(_readbool(c, &m->auth_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_add_cdd_claim_V2(
    parser_context_t* c, pd_identity_gc_add_cdd_claim_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_revoke_cdd_claim_V2(
    parser_context_t* c, pd_identity_gc_revoke_cdd_claim_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_claim_by_index_V2(
    parser_context_t* c, pd_identity_revoke_claim_by_index_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->target))
    CHECK_ERROR(_readClaimType_V2(c, &m->claim_type))
    CHECK_ERROR(_readOptionScope_V2(c, &m->scope))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_rotate_primary_key_to_secondary_V2(
    parser_context_t* c, pd_identity_rotate_primary_key_to_secondary_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_set_active_members_limit_V2(
    parser_context_t* c, pd_cddserviceproviders_set_active_members_limit_V2_t* m)
{
    CHECK_ERROR(_readMemberCount_V2(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_disable_member_V2(
    parser_context_t* c, pd_cddserviceproviders_disable_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_add_member_V2(
    parser_context_t* c, pd_cddserviceproviders_add_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_remove_member_V2(
    parser_context_t* c, pd_cddserviceproviders_remove_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_swap_member_V2(
    parser_context_t* c, pd_cddserviceproviders_swap_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V2(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_reset_members_V2(
    parser_context_t* c, pd_cddserviceproviders_reset_members_V2_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V2(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_abdicate_membership_V2(
    parser_context_t* c, pd_cddserviceproviders_abdicate_membership_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_vote_threshold_V2(
    parser_context_t* c, pd_polymeshcommittee_set_vote_threshold_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_release_coordinator_V2(
    parser_context_t* c, pd_polymeshcommittee_set_release_coordinator_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_expires_after_V2(
    parser_context_t* c, pd_polymeshcommittee_set_expires_after_V2_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_or_propose_V2(
    parser_context_t* c, pd_polymeshcommittee_vote_or_propose_V2_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_V2(
    parser_context_t* c, pd_polymeshcommittee_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_set_active_members_limit_V2(
    parser_context_t* c, pd_committeemembership_set_active_members_limit_V2_t* m)
{
    CHECK_ERROR(_readMemberCount_V2(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_disable_member_V2(
    parser_context_t* c, pd_committeemembership_disable_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_add_member_V2(
    parser_context_t* c, pd_committeemembership_add_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_remove_member_V2(
    parser_context_t* c, pd_committeemembership_remove_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_swap_member_V2(
    parser_context_t* c, pd_committeemembership_swap_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V2(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_reset_members_V2(
    parser_context_t* c, pd_committeemembership_reset_members_V2_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V2(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_abdicate_membership_V2(
    parser_context_t* c, pd_committeemembership_abdicate_membership_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_vote_threshold_V2(
    parser_context_t* c, pd_technicalcommittee_set_vote_threshold_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_release_coordinator_V2(
    parser_context_t* c, pd_technicalcommittee_set_release_coordinator_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_expires_after_V2(
    parser_context_t* c, pd_technicalcommittee_set_expires_after_V2_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_or_propose_V2(
    parser_context_t* c, pd_technicalcommittee_vote_or_propose_V2_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V2(
    parser_context_t* c, pd_technicalcommittee_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_set_active_members_limit_V2(
    parser_context_t* c, pd_technicalcommitteemembership_set_active_members_limit_V2_t* m)
{
    CHECK_ERROR(_readMemberCount_V2(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_disable_member_V2(
    parser_context_t* c, pd_technicalcommitteemembership_disable_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_add_member_V2(
    parser_context_t* c, pd_technicalcommitteemembership_add_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_remove_member_V2(
    parser_context_t* c, pd_technicalcommitteemembership_remove_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_swap_member_V2(
    parser_context_t* c, pd_technicalcommitteemembership_swap_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V2(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_reset_members_V2(
    parser_context_t* c, pd_technicalcommitteemembership_reset_members_V2_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V2(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_abdicate_membership_V2(
    parser_context_t* c, pd_technicalcommitteemembership_abdicate_membership_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_vote_threshold_V2(
    parser_context_t* c, pd_upgradecommittee_set_vote_threshold_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_release_coordinator_V2(
    parser_context_t* c, pd_upgradecommittee_set_release_coordinator_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_expires_after_V2(
    parser_context_t* c, pd_upgradecommittee_set_expires_after_V2_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_or_propose_V2(
    parser_context_t* c, pd_upgradecommittee_vote_or_propose_V2_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_V2(
    parser_context_t* c, pd_upgradecommittee_vote_V2_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V2(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_set_active_members_limit_V2(
    parser_context_t* c, pd_upgradecommitteemembership_set_active_members_limit_V2_t* m)
{
    CHECK_ERROR(_readMemberCount_V2(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_disable_member_V2(
    parser_context_t* c, pd_upgradecommitteemembership_disable_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_add_member_V2(
    parser_context_t* c, pd_upgradecommitteemembership_add_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_remove_member_V2(
    parser_context_t* c, pd_upgradecommitteemembership_remove_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_swap_member_V2(
    parser_context_t* c, pd_upgradecommitteemembership_swap_member_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V2(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_reset_members_V2(
    parser_context_t* c, pd_upgradecommitteemembership_reset_members_V2_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V2(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_abdicate_membership_V2(
    parser_context_t* c, pd_upgradecommitteemembership_abdicate_membership_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_controller_V2(
    parser_context_t* c, pd_bridge_change_controller_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_admin_V2(
    parser_context_t* c, pd_bridge_change_admin_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_timelock_V2(
    parser_context_t* c, pd_bridge_change_timelock_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->timelock))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_V2(
    parser_context_t* c, pd_bridge_freeze_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_V2(
    parser_context_t* c, pd_bridge_unfreeze_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_limit_V2(
    parser_context_t* c, pd_bridge_change_bridge_limit_V2_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_exempted_V2(
    parser_context_t* c, pd_bridge_change_bridge_exempted_V2_t* m)
{
    CHECK_ERROR(_readVecTupleIdentityIdbool_V2(c, &m->exempted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_force_handle_bridge_tx_V2(
    parser_context_t* c, pd_bridge_force_handle_bridge_tx_V2_t* m)
{
    CHECK_ERROR(_readBridgeTx_V2(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_batch_propose_bridge_tx_V2(
    parser_context_t* c, pd_bridge_batch_propose_bridge_tx_V2_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V2(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_propose_bridge_tx_V2(
    parser_context_t* c, pd_bridge_propose_bridge_tx_V2_t* m)
{
    CHECK_ERROR(_readBridgeTx_V2(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_bridge_tx_V2(
    parser_context_t* c, pd_bridge_handle_bridge_tx_V2_t* m)
{
    CHECK_ERROR(_readBridgeTx_V2(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_txs_V2(
    parser_context_t* c, pd_bridge_freeze_txs_V2_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V2(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_txs_V2(
    parser_context_t* c, pd_bridge_unfreeze_txs_V2_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V2(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_scheduled_bridge_tx_V2(
    parser_context_t* c, pd_bridge_handle_scheduled_bridge_tx_V2_t* m)
{
    CHECK_ERROR(_readBridgeTx_V2(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_add_freeze_admin_V2(
    parser_context_t* c, pd_bridge_add_freeze_admin_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->freeze_admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_remove_freeze_admin_V2(
    parser_context_t* c, pd_bridge_remove_freeze_admin_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->freeze_admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_remove_txs_V2(
    parser_context_t* c, pd_bridge_remove_txs_V2_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V2(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V2(
    parser_context_t* c, pd_staking_set_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V2(
    parser_context_t* c, pd_staking_increase_validator_count_V2_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_add_permissioned_validator_V2(
    parser_context_t* c, pd_staking_add_permissioned_validator_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->identity))
    CHECK_ERROR(_readOptionu32(c, &m->intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_remove_permissioned_validator_V2(
    parser_context_t* c, pd_staking_remove_permissioned_validator_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->identity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_cdd_expiry_nominators_V2(
    parser_context_t* c, pd_staking_validate_cdd_expiry_nominators_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_commission_cap_V2(
    parser_context_t* c, pd_staking_set_commission_cap_V2_t* m)
{
    CHECK_ERROR(_readPerbill_V2(c, &m->new_cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_bond_threshold_V2(
    parser_context_t* c, pd_staking_set_min_bond_threshold_V2_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->new_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V2(
    parser_context_t* c, pd_staking_force_no_eras_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V2(
    parser_context_t* c, pd_staking_force_new_era_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V2(
    parser_context_t* c, pd_staking_set_invulnerables_V2_t* m)
{
    CHECK_ERROR(_readVecAccountId_V2(c, &m->invulnerables))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V2(
    parser_context_t* c, pd_staking_force_unstake_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V2(
    parser_context_t* c, pd_staking_force_new_era_always_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V2(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V2_t* m)
{
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V2(
    parser_context_t* c, pd_staking_payout_stakers_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V2(
    parser_context_t* c, pd_staking_set_history_depth_V2_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V2(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V2(
    parser_context_t* c, pd_staking_reap_stash_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_system_V2(
    parser_context_t* c, pd_staking_payout_stakers_by_system_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V2(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_change_slashing_allowed_for_V2(
    parser_context_t* c, pd_staking_change_slashing_allowed_for_V2_t* m)
{
    CHECK_ERROR(_readSlashingSwitch_V2(c, &m->slashing_switch))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_update_permissioned_validator_intended_count_V2(
    parser_context_t* c, pd_staking_update_permissioned_validator_intended_count_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->identity))
    CHECK_ERROR(_readu32(c, &m->new_intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V2(
    parser_context_t* c, pd_session_set_keys_V2_t* m)
{
    CHECK_ERROR(_readKeys_V2(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V2(
    parser_context_t* c, pd_session_purge_keys_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V2(
    parser_context_t* c, pd_grandpa_note_stalled_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V2(
    parser_context_t* c, pd_sudo_sudo_as_V2_t* m)
{
    CHECK_ERROR(_readLookupSource_V2(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_ticker_V2(
    parser_context_t* c, pd_asset_register_ticker_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_ticker_transfer_V2(
    parser_context_t* c, pd_asset_accept_ticker_transfer_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_asset_ownership_transfer_V2(
    parser_context_t* c, pd_asset_accept_asset_ownership_transfer_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_create_asset_V2(
    parser_context_t* c, pd_asset_create_asset_V2_t* m)
{
    CHECK_ERROR(_readAssetName_V2(c, &m->name))
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readbool(c, &m->divisible))
    CHECK_ERROR(_readAssetType_V2(c, &m->asset_type))
    CHECK_ERROR(_readVecAssetIdentifier_V2(c, &m->identifiers))
    CHECK_ERROR(_readOptionFundingRoundName_V2(c, &m->funding_round))
    CHECK_ERROR(_readbool(c, &m->disable_iu))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_freeze_V2(
    parser_context_t* c, pd_asset_freeze_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unfreeze_V2(
    parser_context_t* c, pd_asset_unfreeze_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_rename_asset_V2(
    parser_context_t* c, pd_asset_rename_asset_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readAssetName_V2(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_issue_V2(
    parser_context_t* c, pd_asset_issue_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_redeem_V2(
    parser_context_t* c, pd_asset_redeem_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_make_divisible_V2(
    parser_context_t* c, pd_asset_make_divisible_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_documents_V2(
    parser_context_t* c, pd_asset_add_documents_V2_t* m)
{
    CHECK_ERROR(_readVecDocument_V2(c, &m->docs))
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_documents_V2(
    parser_context_t* c, pd_asset_remove_documents_V2_t* m)
{
    CHECK_ERROR(_readVecDocumentId_V2(c, &m->ids))
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_set_funding_round_V2(
    parser_context_t* c, pd_asset_set_funding_round_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readFundingRoundName_V2(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_update_identifiers_V2(
    parser_context_t* c, pd_asset_update_identifiers_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readVecAssetIdentifier_V2(c, &m->identifiers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_claim_classic_ticker_V2(
    parser_context_t* c, pd_asset_claim_classic_ticker_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readEcdsaSignature_V2(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_reserve_classic_ticker_V2(
    parser_context_t* c, pd_asset_reserve_classic_ticker_V2_t* m)
{
    CHECK_ERROR(_readClassicTickerImport_V2(c, &m->classic_ticker_import))
    CHECK_ERROR(_readIdentityId_V2(c, &m->contract_did))
    CHECK_ERROR(_readTickerRegistrationConfig_V2(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_controller_transfer_V2(
    parser_context_t* c, pd_asset_controller_transfer_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->amount))
    CHECK_ERROR(_readPortfolioId_V2(c, &m->from_portfolio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_custom_asset_type_V2(
    parser_context_t* c, pd_asset_register_custom_asset_type_V2_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->ty))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_distribute_V2(
    parser_context_t* c, pd_capitaldistribution_distribute_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readOptionPortfolioNumber_V2(c, &m->portfolio))
    CHECK_ERROR(_readTicker_V2(c, &m->currency))
    CHECK_ERROR(_readBalance(c, &m->per_share))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readMoment_V2(c, &m->payment_at))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_claim_V2(
    parser_context_t* c, pd_capitaldistribution_claim_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_push_benefit_V2(
    parser_context_t* c, pd_capitaldistribution_push_benefit_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readIdentityId_V2(c, &m->holder))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_reclaim_V2(
    parser_context_t* c, pd_capitaldistribution_reclaim_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_remove_distribution_V2(
    parser_context_t* c, pd_capitaldistribution_remove_distribution_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_checkpoint_V2(
    parser_context_t* c, pd_checkpoint_create_checkpoint_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_set_schedules_max_complexity_V2(
    parser_context_t* c, pd_checkpoint_set_schedules_max_complexity_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->max_complexity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_schedule_V2(
    parser_context_t* c, pd_checkpoint_create_schedule_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readScheduleSpec_V2(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_remove_schedule_V2(
    parser_context_t* c, pd_checkpoint_remove_schedule_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readScheduleId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_compliance_requirement_V2(
    parser_context_t* c, pd_compliancemanager_add_compliance_requirement_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readVecCondition_V2(c, &m->sender_conditions))
    CHECK_ERROR(_readVecCondition_V2(c, &m->receiver_conditions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_compliance_requirement_V2(
    parser_context_t* c, pd_compliancemanager_remove_compliance_requirement_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_replace_asset_compliance_V2(
    parser_context_t* c, pd_compliancemanager_replace_asset_compliance_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readVecComplianceRequirement_V2(c, &m->asset_compliance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_reset_asset_compliance_V2(
    parser_context_t* c, pd_compliancemanager_reset_asset_compliance_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_pause_asset_compliance_V2(
    parser_context_t* c, pd_compliancemanager_pause_asset_compliance_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_resume_asset_compliance_V2(
    parser_context_t* c, pd_compliancemanager_resume_asset_compliance_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_default_trusted_claim_issuer_V2(
    parser_context_t* c, pd_compliancemanager_add_default_trusted_claim_issuer_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readTrustedIssuer_V2(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_default_trusted_claim_issuer_V2(
    parser_context_t* c, pd_compliancemanager_remove_default_trusted_claim_issuer_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readIdentityId_V2(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_change_compliance_requirement_V2(
    parser_context_t* c, pd_compliancemanager_change_compliance_requirement_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readComplianceRequirement_V2(c, &m->new_req))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_max_details_length_V2(
    parser_context_t* c, pd_corporateaction_set_max_details_length_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->length))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_targets_V2(
    parser_context_t* c, pd_corporateaction_set_default_targets_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readTargetIdentities_V2(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_withholding_tax_V2(
    parser_context_t* c, pd_corporateaction_set_default_withholding_tax_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readTax_V2(c, &m->tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_did_withholding_tax_V2(
    parser_context_t* c, pd_corporateaction_set_did_withholding_tax_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readIdentityId_V2(c, &m->taxed_did))
    CHECK_ERROR(_readOptionTax_V2(c, &m->tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_initiate_corporate_action_V2(
    parser_context_t* c, pd_corporateaction_initiate_corporate_action_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readCAKind_V2(c, &m->kind))
    CHECK_ERROR(_readMoment_V2(c, &m->decl_date))
    CHECK_ERROR(_readOptionRecordDateSpec_V2(c, &m->record_date))
    CHECK_ERROR(_readCADetails_V2(c, &m->details))
    CHECK_ERROR(_readOptionTargetIdentities_V2(c, &m->targets))
    CHECK_ERROR(_readOptionTax_V2(c, &m->default_withholding_tax))
    CHECK_ERROR(_readOptionVecTupleIdentityIdTax_V2(c, &m->withholding_tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_link_ca_doc_V2(
    parser_context_t* c, pd_corporateaction_link_ca_doc_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->id))
    CHECK_ERROR(_readVecDocumentId_V2(c, &m->docs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_remove_ca_V2(
    parser_context_t* c, pd_corporateaction_remove_ca_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_change_record_date_V2(
    parser_context_t* c, pd_corporateaction_change_record_date_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readOptionRecordDateSpec_V2(c, &m->record_date))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_attach_ballot_V2(
    parser_context_t* c, pd_corporateballot_attach_ballot_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readBallotTimeRange_V2(c, &m->range))
    CHECK_ERROR(_readBallotMeta_V2(c, &m->meta))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_vote_V2(
    parser_context_t* c, pd_corporateballot_vote_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readVecBallotVote_V2(c, &m->votes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_end_V2(
    parser_context_t* c, pd_corporateballot_change_end_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readMoment_V2(c, &m->end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_meta_V2(
    parser_context_t* c, pd_corporateballot_change_meta_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readBallotMeta_V2(c, &m->meta))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_rcv_V2(
    parser_context_t* c, pd_corporateballot_change_rcv_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_remove_ballot_V2(
    parser_context_t* c, pd_corporateballot_remove_ballot_V2_t* m)
{
    CHECK_ERROR(_readCAId_V2(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_prune_historical_pips_V2(
    parser_context_t* c, pd_pips_set_prune_historical_pips_V2_t* m)
{
    CHECK_ERROR(_readbool(c, &m->prune))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_min_proposal_deposit_V2(
    parser_context_t* c, pd_pips_set_min_proposal_deposit_V2_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_default_enactment_period_V2(
    parser_context_t* c, pd_pips_set_default_enactment_period_V2_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_pending_pip_expiry_V2(
    parser_context_t* c, pd_pips_set_pending_pip_expiry_V2_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V2(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_max_pip_skip_count_V2(
    parser_context_t* c, pd_pips_set_max_pip_skip_count_V2_t* m)
{
    CHECK_ERROR(_readSkippedCount_V2(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_active_pip_limit_V2(
    parser_context_t* c, pd_pips_set_active_pip_limit_V2_t* m)
{
    CHECK_ERROR(_readu32(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_approve_committee_proposal_V2(
    parser_context_t* c, pd_pips_approve_committee_proposal_V2_t* m)
{
    CHECK_ERROR(_readPipId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reject_proposal_V2(
    parser_context_t* c, pd_pips_reject_proposal_V2_t* m)
{
    CHECK_ERROR(_readPipId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_prune_proposal_V2(
    parser_context_t* c, pd_pips_prune_proposal_V2_t* m)
{
    CHECK_ERROR(_readPipId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reschedule_execution_V2(
    parser_context_t* c, pd_pips_reschedule_execution_V2_t* m)
{
    CHECK_ERROR(_readPipId_V2(c, &m->id))
    CHECK_ERROR(_readOptionBlockNumber(c, &m->until))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_clear_snapshot_V2(
    parser_context_t* c, pd_pips_clear_snapshot_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_snapshot_V2(
    parser_context_t* c, pd_pips_snapshot_V2_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_enact_snapshot_results_V2(
    parser_context_t* c, pd_pips_enact_snapshot_results_V2_t* m)
{
    CHECK_ERROR(_readVecTuplePipIdSnapshotResult_V2(c, &m->results))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_execute_scheduled_pip_V2(
    parser_context_t* c, pd_pips_execute_scheduled_pip_V2_t* m)
{
    CHECK_ERROR(_readPipId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_expire_scheduled_pip_V2(
    parser_context_t* c, pd_pips_expire_scheduled_pip_V2_t* m)
{
    CHECK_ERROR(_readIdentityId_V2(c, &m->did))
    CHECK_ERROR(_readPipId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_create_portfolio_V2(
    parser_context_t* c, pd_portfolio_create_portfolio_V2_t* m)
{
    CHECK_ERROR(_readPortfolioName_V2(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_delete_portfolio_V2(
    parser_context_t* c, pd_portfolio_delete_portfolio_V2_t* m)
{
    CHECK_ERROR(_readPortfolioNumber_V2(c, &m->num))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_move_portfolio_funds_V2(
    parser_context_t* c, pd_portfolio_move_portfolio_funds_V2_t* m)
{
    CHECK_ERROR(_readPortfolioId_V2(c, &m->from))
    CHECK_ERROR(_readPortfolioId_V2(c, &m->to))
    CHECK_ERROR(_readVecMovePortfolioItem_V2(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_rename_portfolio_V2(
    parser_context_t* c, pd_portfolio_rename_portfolio_V2_t* m)
{
    CHECK_ERROR(_readPortfolioNumber_V2(c, &m->num))
    CHECK_ERROR(_readPortfolioName_V2(c, &m->to_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_quit_portfolio_custody_V2(
    parser_context_t* c, pd_portfolio_quit_portfolio_custody_V2_t* m)
{
    CHECK_ERROR(_readPortfolioId_V2(c, &m->pid))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_accept_portfolio_custody_V2(
    parser_context_t* c, pd_portfolio_accept_portfolio_custody_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_coefficient_V2(
    parser_context_t* c, pd_protocolfee_change_coefficient_V2_t* m)
{
    CHECK_ERROR(_readPosRatio_V2(c, &m->coefficient))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_create_venue_V2(
    parser_context_t* c, pd_settlement_create_venue_V2_t* m)
{
    CHECK_ERROR(_readVenueDetails_V2(c, &m->details))
    CHECK_ERROR(_readVecAccountId_V2(c, &m->signers))
    CHECK_ERROR(_readVenueType_V2(c, &m->typ))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue_details_V2(
    parser_context_t* c, pd_settlement_update_venue_details_V2_t* m)
{
    CHECK_ERROR(_readVenueId_V2(c, &m->id))
    CHECK_ERROR(_readVenueDetails_V2(c, &m->details))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue_type_V2(
    parser_context_t* c, pd_settlement_update_venue_type_V2_t* m)
{
    CHECK_ERROR(_readVenueId_V2(c, &m->id))
    CHECK_ERROR(_readVenueType_V2(c, &m->typ))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_instruction_V2(
    parser_context_t* c, pd_settlement_add_instruction_V2_t* m)
{
    CHECK_ERROR(_readVenueId_V2(c, &m->venue_id))
    CHECK_ERROR(_readSettlementType_V2(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->value_date))
    CHECK_ERROR(_readVecLeg_V2(c, &m->legs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_and_affirm_instruction_V2(
    parser_context_t* c, pd_settlement_add_and_affirm_instruction_V2_t* m)
{
    CHECK_ERROR(_readVenueId_V2(c, &m->venue_id))
    CHECK_ERROR(_readSettlementType_V2(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->value_date))
    CHECK_ERROR(_readVecLeg_V2(c, &m->legs))
    CHECK_ERROR(_readVecPortfolioId_V2(c, &m->portfolios))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_instruction_V2(
    parser_context_t* c, pd_settlement_affirm_instruction_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->id))
    CHECK_ERROR(_readVecPortfolioId_V2(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_withdraw_affirmation_V2(
    parser_context_t* c, pd_settlement_withdraw_affirmation_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->id))
    CHECK_ERROR(_readVecPortfolioId_V2(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_reject_instruction_V2(
    parser_context_t* c, pd_settlement_reject_instruction_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->id))
    CHECK_ERROR(_readPortfolioId_V2(c, &m->portfolio))
    CHECK_ERROR(_readu32(c, &m->num_of_legs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_with_receipts_V2(
    parser_context_t* c, pd_settlement_affirm_with_receipts_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->id))
    CHECK_ERROR(_readVecReceiptDetails_V2(c, &m->receipt_details))
    CHECK_ERROR(_readVecPortfolioId_V2(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_claim_receipt_V2(
    parser_context_t* c, pd_settlement_claim_receipt_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->id))
    CHECK_ERROR(_readReceiptDetails_V2(c, &m->receipt_details))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_unclaim_receipt_V2(
    parser_context_t* c, pd_settlement_unclaim_receipt_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->instruction_id))
    CHECK_ERROR(_readLegId_V2(c, &m->leg_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_set_venue_filtering_V2(
    parser_context_t* c, pd_settlement_set_venue_filtering_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readbool(c, &m->enabled))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_allow_venues_V2(
    parser_context_t* c, pd_settlement_allow_venues_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readVecVenueId_V2(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_disallow_venues_V2(
    parser_context_t* c, pd_settlement_disallow_venues_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readVecVenueId_V2(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_change_receipt_validity_V2(
    parser_context_t* c, pd_settlement_change_receipt_validity_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->receipt_uid))
    CHECK_ERROR(_readbool(c, &m->validity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_execute_scheduled_instruction_V2(
    parser_context_t* c, pd_settlement_execute_scheduled_instruction_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->id))
    CHECK_ERROR(_readu32(c, &m->_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_reschedule_instruction_V2(
    parser_context_t* c, pd_settlement_reschedule_instruction_V2_t* m)
{
    CHECK_ERROR(_readInstructionId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_add_transfer_manager_V2(
    parser_context_t* c, pd_statistics_add_transfer_manager_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V2(c, &m->new_transfer_manager))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_remove_transfer_manager_V2(
    parser_context_t* c, pd_statistics_remove_transfer_manager_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V2(c, &m->transfer_manager))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_add_exempted_entities_V2(
    parser_context_t* c, pd_statistics_add_exempted_entities_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V2(c, &m->transfer_manager))
    CHECK_ERROR(_readVecScopeId_V2(c, &m->exempted_entities))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_remove_exempted_entities_V2(
    parser_context_t* c, pd_statistics_remove_exempted_entities_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V2(c, &m->transfer_manager))
    CHECK_ERROR(_readVecScopeId_V2(c, &m->entities))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_create_fundraiser_V2(
    parser_context_t* c, pd_sto_create_fundraiser_V2_t* m)
{
    CHECK_ERROR(_readPortfolioId_V2(c, &m->offering_portfolio))
    CHECK_ERROR(_readTicker_V2(c, &m->offering_asset))
    CHECK_ERROR(_readPortfolioId_V2(c, &m->raising_portfolio))
    CHECK_ERROR(_readTicker_V2(c, &m->raising_asset))
    CHECK_ERROR(_readVecPriceTier_V2(c, &m->tiers))
    CHECK_ERROR(_readVenueId_V2(c, &m->venue_id))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->start))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->end))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->minimum_investment))
    CHECK_ERROR(_readFundraiserName_V2(c, &m->fundraiser_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_invest_V2(
    parser_context_t* c, pd_sto_invest_V2_t* m)
{
    CHECK_ERROR(_readPortfolioId_V2(c, &m->investment_portfolio))
    CHECK_ERROR(_readPortfolioId_V2(c, &m->funding_portfolio))
    CHECK_ERROR(_readTicker_V2(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId_V2(c, &m->id))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->purchase_amount))
    CHECK_ERROR(_readOptionBalance(c, &m->max_price))
    CHECK_ERROR(_readOptionReceiptDetails_V2(c, &m->receipt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_freeze_fundraiser_V2(
    parser_context_t* c, pd_sto_freeze_fundraiser_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_unfreeze_fundraiser_V2(
    parser_context_t* c, pd_sto_unfreeze_fundraiser_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_modify_fundraiser_window_V2(
    parser_context_t* c, pd_sto_modify_fundraiser_window_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId_V2(c, &m->id))
    CHECK_ERROR(_readMoment_V2(c, &m->start))
    CHECK_ERROR(_readOptionMoment_V2(c, &m->end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_stop_V2(
    parser_context_t* c, pd_sto_stop_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->offering_asset))
    CHECK_ERROR(_readFundraiserId_V2(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_disbursement_V2(
    parser_context_t* c, pd_treasury_disbursement_V2_t* m)
{
    CHECK_ERROR(_readVecBeneficiary_V2(c, &m->beneficiaries))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reimbursement_V2(
    parser_context_t* c, pd_treasury_reimbursement_V2_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_relay_tx_V2(
    parser_context_t* c, pd_utility_relay_tx_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->target))
    CHECK_ERROR(_readOffChainSignature_V2(c, &m->signature))
    CHECK_ERROR(_readUniqueCall_V2(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_remove_agent_V2(
    parser_context_t* c, pd_externalagents_remove_agent_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    CHECK_ERROR(_readIdentityId_V2(c, &m->agent))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_abdicate_V2(
    parser_context_t* c, pd_externalagents_abdicate_V2_t* m)
{
    CHECK_ERROR(_readTicker_V2(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_externalagents_accept_become_agent_V2(
    parser_context_t* c, pd_externalagents_accept_become_agent_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_set_paying_key_V2(
    parser_context_t* c, pd_relayer_set_paying_key_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->polyx_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_accept_paying_key_V2(
    parser_context_t* c, pd_relayer_accept_paying_key_V2_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_remove_paying_key_V2(
    parser_context_t* c, pd_relayer_remove_paying_key_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->user_key))
    CHECK_ERROR(_readAccountId_V2(c, &m->paying_key))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_update_polyx_limit_V2(
    parser_context_t* c, pd_relayer_update_polyx_limit_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->polyx_limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_increase_polyx_limit_V2(
    parser_context_t* c, pd_relayer_increase_polyx_limit_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_relayer_decrease_polyx_limit_V2(
    parser_context_t* c, pd_relayer_decrease_polyx_limit_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->user_key))
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_rewards_claim_itn_reward_V2(
    parser_context_t* c, pd_rewards_claim_itn_reward_V2_t* m)
{
    CHECK_ERROR(_readAccountId_V2(c, &m->reward_address))
    CHECK_ERROR(_readAccountId_V2(c, &m->itn_address))
    CHECK_ERROR(_readOffChainSignature_V2(c, &m->signature))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V2(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V2_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1280: /* module 5 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V2(c, &method->nested.balances_transfer_V2))
        break;
    case 1794: /* module 7 call 2 */
        CHECK_ERROR(_readMethod_identity_remove_secondary_keys_V2(c, &method->nested.identity_remove_secondary_keys_V2))
        break;
    case 1795: /* module 7 call 3 */
        CHECK_ERROR(_readMethod_identity_accept_primary_key_V2(c, &method->nested.identity_accept_primary_key_V2))
        break;
    case 1797: /* module 7 call 5 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_key_V2(c, &method->nested.identity_join_identity_as_key_V2))
        break;
    case 1798: /* module 7 call 6 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_key_V2(c, &method->nested.identity_leave_identity_as_key_V2))
        break;
    case 1799: /* module 7 call 7 */
        CHECK_ERROR(_readMethod_identity_add_claim_V2(c, &method->nested.identity_add_claim_V2))
        break;
    case 1800: /* module 7 call 8 */
        CHECK_ERROR(_readMethod_identity_revoke_claim_V2(c, &method->nested.identity_revoke_claim_V2))
        break;
    case 1801: /* module 7 call 9 */
        CHECK_ERROR(_readMethod_identity_set_permission_to_signer_V2(c, &method->nested.identity_set_permission_to_signer_V2))
        break;
    case 1803: /* module 7 call 11 */
        CHECK_ERROR(_readMethod_identity_freeze_secondary_keys_V2(c, &method->nested.identity_freeze_secondary_keys_V2))
        break;
    case 1804: /* module 7 call 12 */
        CHECK_ERROR(_readMethod_identity_unfreeze_secondary_keys_V2(c, &method->nested.identity_unfreeze_secondary_keys_V2))
        break;
    case 1805: /* module 7 call 13 */
        CHECK_ERROR(_readMethod_identity_add_authorization_V2(c, &method->nested.identity_add_authorization_V2))
        break;
    case 1806: /* module 7 call 14 */
        CHECK_ERROR(_readMethod_identity_remove_authorization_V2(c, &method->nested.identity_remove_authorization_V2))
        break;
    case 1807: /* module 7 call 15 */
        CHECK_ERROR(_readMethod_identity_add_secondary_keys_with_authorization_V2(c, &method->nested.identity_add_secondary_keys_with_authorization_V2))
        break;
    case 1808: /* module 7 call 16 */
        CHECK_ERROR(_readMethod_identity_add_investor_uniqueness_claim_V2(c, &method->nested.identity_add_investor_uniqueness_claim_V2))
        break;
    case 3840: /* module 15 call 0 */
        CHECK_ERROR(_readMethod_multisig_create_multisig_V2(c, &method->nested.multisig_create_multisig_V2))
        break;
    case 3841: /* module 15 call 1 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_identity_V2(c, &method->nested.multisig_create_or_approve_proposal_as_identity_V2))
        break;
    case 3842: /* module 15 call 2 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_key_V2(c, &method->nested.multisig_create_or_approve_proposal_as_key_V2))
        break;
    case 3843: /* module 15 call 3 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_identity_V2(c, &method->nested.multisig_create_proposal_as_identity_V2))
        break;
    case 3844: /* module 15 call 4 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_key_V2(c, &method->nested.multisig_create_proposal_as_key_V2))
        break;
    case 3845: /* module 15 call 5 */
        CHECK_ERROR(_readMethod_multisig_approve_as_identity_V2(c, &method->nested.multisig_approve_as_identity_V2))
        break;
    case 3846: /* module 15 call 6 */
        CHECK_ERROR(_readMethod_multisig_approve_as_key_V2(c, &method->nested.multisig_approve_as_key_V2))
        break;
    case 3847: /* module 15 call 7 */
        CHECK_ERROR(_readMethod_multisig_reject_as_identity_V2(c, &method->nested.multisig_reject_as_identity_V2))
        break;
    case 3848: /* module 15 call 8 */
        CHECK_ERROR(_readMethod_multisig_reject_as_key_V2(c, &method->nested.multisig_reject_as_key_V2))
        break;
    case 3849: /* module 15 call 9 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_identity_V2(c, &method->nested.multisig_accept_multisig_signer_as_identity_V2))
        break;
    case 3850: /* module 15 call 10 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_key_V2(c, &method->nested.multisig_accept_multisig_signer_as_key_V2))
        break;
    case 3851: /* module 15 call 11 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signer_V2(c, &method->nested.multisig_add_multisig_signer_V2))
        break;
    case 3852: /* module 15 call 12 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signer_V2(c, &method->nested.multisig_remove_multisig_signer_V2))
        break;
    case 3853: /* module 15 call 13 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signers_via_creator_V2(c, &method->nested.multisig_add_multisig_signers_via_creator_V2))
        break;
    case 3854: /* module 15 call 14 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signers_via_creator_V2(c, &method->nested.multisig_remove_multisig_signers_via_creator_V2))
        break;
    case 3855: /* module 15 call 15 */
        CHECK_ERROR(_readMethod_multisig_change_sigs_required_V2(c, &method->nested.multisig_change_sigs_required_V2))
        break;
    case 3856: /* module 15 call 16 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_signer_V2(c, &method->nested.multisig_make_multisig_signer_V2))
        break;
    case 3857: /* module 15 call 17 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_primary_V2(c, &method->nested.multisig_make_multisig_primary_V2))
        break;
    case 3858: /* module 15 call 18 */
        CHECK_ERROR(_readMethod_multisig_execute_scheduled_proposal_V2(c, &method->nested.multisig_execute_scheduled_proposal_V2))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V2(c, &method->nested.staking_bond_V2))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V2(c, &method->nested.staking_bond_extra_V2))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V2(c, &method->nested.staking_unbond_V2))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V2(c, &method->nested.staking_withdraw_unbonded_V2))
        break;
    case 4356: /* module 17 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V2(c, &method->nested.staking_validate_V2))
        break;
    case 4357: /* module 17 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V2(c, &method->nested.staking_nominate_V2))
        break;
    case 4358: /* module 17 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V2(c, &method->nested.staking_chill_V2))
        break;
    case 4359: /* module 17 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V2(c, &method->nested.staking_set_payee_V2))
        break;
    case 4360: /* module 17 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V2(c, &method->nested.staking_set_controller_V2))
        break;
    case 4376: /* module 17 call 24 */
        CHECK_ERROR(_readMethod_staking_rebond_V2(c, &method->nested.staking_rebond_V2))
        break;
    case 8454: /* module 33 call 6 */
        CHECK_ERROR(_readMethod_pips_propose_V2(c, &method->nested.pips_propose_V2))
        break;
    case 8455: /* module 33 call 7 */
        CHECK_ERROR(_readMethod_pips_vote_V2(c, &method->nested.pips_vote_V2))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V2(c, &method->nested.utility_batch_V2))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_utility_batch_atomic_V2(c, &method->nested.utility_batch_atomic_V2))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_optimistic_V2(c, &method->nested.utility_batch_optimistic_V2))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V2(c, &method->nested.system_fill_block_V2))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V2(c, &method->nested.system_remark_V2))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V2(c, &method->nested.system_set_heap_pages_V2))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V2(c, &method->nested.system_set_code_V2))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V2(c, &method->nested.system_set_code_without_checks_V2))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V2(c, &method->nested.timestamp_set_V2))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V2(c, &method->nested.indices_claim_V2))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V2(c, &method->nested.indices_transfer_V2))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V2(c, &method->nested.indices_free_V2))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V2(c, &method->nested.indices_force_transfer_V2))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V2(c, &method->nested.indices_freeze_V2))
        break;
    case 1281: /* module 5 call 1 */
        CHECK_ERROR(_readMethod_balances_transfer_with_memo_V2(c, &method->nested.balances_transfer_with_memo_V2))
        break;
    case 1282: /* module 5 call 2 */
        CHECK_ERROR(_readMethod_balances_deposit_block_reward_reserve_balance_V2(c, &method->nested.balances_deposit_block_reward_reserve_balance_V2))
        break;
    case 1283: /* module 5 call 3 */
        CHECK_ERROR(_readMethod_balances_set_balance_V2(c, &method->nested.balances_set_balance_V2))
        break;
    case 1284: /* module 5 call 4 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V2(c, &method->nested.balances_force_transfer_V2))
        break;
    case 1285: /* module 5 call 5 */
        CHECK_ERROR(_readMethod_balances_burn_account_balance_V2(c, &method->nested.balances_burn_account_balance_V2))
        break;
    case 1793: /* module 7 call 1 */
        CHECK_ERROR(_readMethod_identity_invalidate_cdd_claims_V2(c, &method->nested.identity_invalidate_cdd_claims_V2))
        break;
    case 1796: /* module 7 call 4 */
        CHECK_ERROR(_readMethod_identity_change_cdd_requirement_for_mk_rotation_V2(c, &method->nested.identity_change_cdd_requirement_for_mk_rotation_V2))
        break;
    case 1809: /* module 7 call 17 */
        CHECK_ERROR(_readMethod_identity_gc_add_cdd_claim_V2(c, &method->nested.identity_gc_add_cdd_claim_V2))
        break;
    case 1810: /* module 7 call 18 */
        CHECK_ERROR(_readMethod_identity_gc_revoke_cdd_claim_V2(c, &method->nested.identity_gc_revoke_cdd_claim_V2))
        break;
    case 1812: /* module 7 call 20 */
        CHECK_ERROR(_readMethod_identity_revoke_claim_by_index_V2(c, &method->basic.identity_revoke_claim_by_index_V2))
        break;
    case 1813: /* module 7 call 21 */
        CHECK_ERROR(_readMethod_identity_rotate_primary_key_to_secondary_V2(c, &method->basic.identity_rotate_primary_key_to_secondary_V2))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_cddserviceproviders_set_active_members_limit_V2(c, &method->nested.cddserviceproviders_set_active_members_limit_V2))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_cddserviceproviders_disable_member_V2(c, &method->nested.cddserviceproviders_disable_member_V2))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_cddserviceproviders_add_member_V2(c, &method->nested.cddserviceproviders_add_member_V2))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_cddserviceproviders_remove_member_V2(c, &method->nested.cddserviceproviders_remove_member_V2))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_cddserviceproviders_swap_member_V2(c, &method->nested.cddserviceproviders_swap_member_V2))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_cddserviceproviders_reset_members_V2(c, &method->nested.cddserviceproviders_reset_members_V2))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_cddserviceproviders_abdicate_membership_V2(c, &method->nested.cddserviceproviders_abdicate_membership_V2))
        break;
    case 2304: /* module 9 call 0 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_vote_threshold_V2(c, &method->nested.polymeshcommittee_set_vote_threshold_V2))
        break;
    case 2305: /* module 9 call 1 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_release_coordinator_V2(c, &method->nested.polymeshcommittee_set_release_coordinator_V2))
        break;
    case 2306: /* module 9 call 2 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_expires_after_V2(c, &method->nested.polymeshcommittee_set_expires_after_V2))
        break;
    case 2307: /* module 9 call 3 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_or_propose_V2(c, &method->nested.polymeshcommittee_vote_or_propose_V2))
        break;
    case 2308: /* module 9 call 4 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_V2(c, &method->nested.polymeshcommittee_vote_V2))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_committeemembership_set_active_members_limit_V2(c, &method->nested.committeemembership_set_active_members_limit_V2))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_committeemembership_disable_member_V2(c, &method->nested.committeemembership_disable_member_V2))
        break;
    case 2562: /* module 10 call 2 */
        CHECK_ERROR(_readMethod_committeemembership_add_member_V2(c, &method->nested.committeemembership_add_member_V2))
        break;
    case 2563: /* module 10 call 3 */
        CHECK_ERROR(_readMethod_committeemembership_remove_member_V2(c, &method->nested.committeemembership_remove_member_V2))
        break;
    case 2564: /* module 10 call 4 */
        CHECK_ERROR(_readMethod_committeemembership_swap_member_V2(c, &method->nested.committeemembership_swap_member_V2))
        break;
    case 2565: /* module 10 call 5 */
        CHECK_ERROR(_readMethod_committeemembership_reset_members_V2(c, &method->nested.committeemembership_reset_members_V2))
        break;
    case 2566: /* module 10 call 6 */
        CHECK_ERROR(_readMethod_committeemembership_abdicate_membership_V2(c, &method->nested.committeemembership_abdicate_membership_V2))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_vote_threshold_V2(c, &method->nested.technicalcommittee_set_vote_threshold_V2))
        break;
    case 2817: /* module 11 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_release_coordinator_V2(c, &method->nested.technicalcommittee_set_release_coordinator_V2))
        break;
    case 2818: /* module 11 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_expires_after_V2(c, &method->nested.technicalcommittee_set_expires_after_V2))
        break;
    case 2819: /* module 11 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_or_propose_V2(c, &method->nested.technicalcommittee_vote_or_propose_V2))
        break;
    case 2820: /* module 11 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V2(c, &method->nested.technicalcommittee_vote_V2))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_set_active_members_limit_V2(c, &method->nested.technicalcommitteemembership_set_active_members_limit_V2))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_disable_member_V2(c, &method->nested.technicalcommitteemembership_disable_member_V2))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member_V2(c, &method->nested.technicalcommitteemembership_add_member_V2))
        break;
    case 3075: /* module 12 call 3 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member_V2(c, &method->nested.technicalcommitteemembership_remove_member_V2))
        break;
    case 3076: /* module 12 call 4 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member_V2(c, &method->nested.technicalcommitteemembership_swap_member_V2))
        break;
    case 3077: /* module 12 call 5 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members_V2(c, &method->nested.technicalcommitteemembership_reset_members_V2))
        break;
    case 3078: /* module 12 call 6 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_abdicate_membership_V2(c, &method->nested.technicalcommitteemembership_abdicate_membership_V2))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_vote_threshold_V2(c, &method->nested.upgradecommittee_set_vote_threshold_V2))
        break;
    case 3329: /* module 13 call 1 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_release_coordinator_V2(c, &method->nested.upgradecommittee_set_release_coordinator_V2))
        break;
    case 3330: /* module 13 call 2 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_expires_after_V2(c, &method->nested.upgradecommittee_set_expires_after_V2))
        break;
    case 3331: /* module 13 call 3 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_or_propose_V2(c, &method->nested.upgradecommittee_vote_or_propose_V2))
        break;
    case 3332: /* module 13 call 4 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_V2(c, &method->nested.upgradecommittee_vote_V2))
        break;
    case 3584: /* module 14 call 0 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_set_active_members_limit_V2(c, &method->nested.upgradecommitteemembership_set_active_members_limit_V2))
        break;
    case 3585: /* module 14 call 1 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_disable_member_V2(c, &method->nested.upgradecommitteemembership_disable_member_V2))
        break;
    case 3586: /* module 14 call 2 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_add_member_V2(c, &method->nested.upgradecommitteemembership_add_member_V2))
        break;
    case 3587: /* module 14 call 3 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_remove_member_V2(c, &method->nested.upgradecommitteemembership_remove_member_V2))
        break;
    case 3588: /* module 14 call 4 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_swap_member_V2(c, &method->nested.upgradecommitteemembership_swap_member_V2))
        break;
    case 3589: /* module 14 call 5 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_reset_members_V2(c, &method->nested.upgradecommitteemembership_reset_members_V2))
        break;
    case 3590: /* module 14 call 6 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_abdicate_membership_V2(c, &method->nested.upgradecommitteemembership_abdicate_membership_V2))
        break;
    case 4096: /* module 16 call 0 */
        CHECK_ERROR(_readMethod_bridge_change_controller_V2(c, &method->nested.bridge_change_controller_V2))
        break;
    case 4097: /* module 16 call 1 */
        CHECK_ERROR(_readMethod_bridge_change_admin_V2(c, &method->nested.bridge_change_admin_V2))
        break;
    case 4098: /* module 16 call 2 */
        CHECK_ERROR(_readMethod_bridge_change_timelock_V2(c, &method->nested.bridge_change_timelock_V2))
        break;
    case 4099: /* module 16 call 3 */
        CHECK_ERROR(_readMethod_bridge_freeze_V2(c, &method->nested.bridge_freeze_V2))
        break;
    case 4100: /* module 16 call 4 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_V2(c, &method->nested.bridge_unfreeze_V2))
        break;
    case 4101: /* module 16 call 5 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_limit_V2(c, &method->nested.bridge_change_bridge_limit_V2))
        break;
    case 4102: /* module 16 call 6 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_exempted_V2(c, &method->nested.bridge_change_bridge_exempted_V2))
        break;
    case 4103: /* module 16 call 7 */
        CHECK_ERROR(_readMethod_bridge_force_handle_bridge_tx_V2(c, &method->basic.bridge_force_handle_bridge_tx_V2))
        break;
    case 4104: /* module 16 call 8 */
        CHECK_ERROR(_readMethod_bridge_batch_propose_bridge_tx_V2(c, &method->basic.bridge_batch_propose_bridge_tx_V2))
        break;
    case 4105: /* module 16 call 9 */
        CHECK_ERROR(_readMethod_bridge_propose_bridge_tx_V2(c, &method->basic.bridge_propose_bridge_tx_V2))
        break;
    case 4106: /* module 16 call 10 */
        CHECK_ERROR(_readMethod_bridge_handle_bridge_tx_V2(c, &method->basic.bridge_handle_bridge_tx_V2))
        break;
    case 4107: /* module 16 call 11 */
        CHECK_ERROR(_readMethod_bridge_freeze_txs_V2(c, &method->basic.bridge_freeze_txs_V2))
        break;
    case 4108: /* module 16 call 12 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_txs_V2(c, &method->basic.bridge_unfreeze_txs_V2))
        break;
    case 4109: /* module 16 call 13 */
        CHECK_ERROR(_readMethod_bridge_handle_scheduled_bridge_tx_V2(c, &method->basic.bridge_handle_scheduled_bridge_tx_V2))
        break;
    case 4110: /* module 16 call 14 */
        CHECK_ERROR(_readMethod_bridge_add_freeze_admin_V2(c, &method->basic.bridge_add_freeze_admin_V2))
        break;
    case 4111: /* module 16 call 15 */
        CHECK_ERROR(_readMethod_bridge_remove_freeze_admin_V2(c, &method->basic.bridge_remove_freeze_admin_V2))
        break;
    case 4112: /* module 16 call 16 */
        CHECK_ERROR(_readMethod_bridge_remove_txs_V2(c, &method->basic.bridge_remove_txs_V2))
        break;
    case 4361: /* module 17 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V2(c, &method->nested.staking_set_validator_count_V2))
        break;
    case 4362: /* module 17 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V2(c, &method->nested.staking_increase_validator_count_V2))
        break;
    case 4364: /* module 17 call 12 */
        CHECK_ERROR(_readMethod_staking_add_permissioned_validator_V2(c, &method->nested.staking_add_permissioned_validator_V2))
        break;
    case 4365: /* module 17 call 13 */
        CHECK_ERROR(_readMethod_staking_remove_permissioned_validator_V2(c, &method->nested.staking_remove_permissioned_validator_V2))
        break;
    case 4366: /* module 17 call 14 */
        CHECK_ERROR(_readMethod_staking_validate_cdd_expiry_nominators_V2(c, &method->nested.staking_validate_cdd_expiry_nominators_V2))
        break;
    case 4367: /* module 17 call 15 */
        CHECK_ERROR(_readMethod_staking_set_commission_cap_V2(c, &method->nested.staking_set_commission_cap_V2))
        break;
    case 4368: /* module 17 call 16 */
        CHECK_ERROR(_readMethod_staking_set_min_bond_threshold_V2(c, &method->nested.staking_set_min_bond_threshold_V2))
        break;
    case 4369: /* module 17 call 17 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V2(c, &method->nested.staking_force_no_eras_V2))
        break;
    case 4370: /* module 17 call 18 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V2(c, &method->nested.staking_force_new_era_V2))
        break;
    case 4371: /* module 17 call 19 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V2(c, &method->nested.staking_set_invulnerables_V2))
        break;
    case 4372: /* module 17 call 20 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V2(c, &method->nested.staking_force_unstake_V2))
        break;
    case 4373: /* module 17 call 21 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V2(c, &method->nested.staking_force_new_era_always_V2))
        break;
    case 4374: /* module 17 call 22 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V2(c, &method->nested.staking_cancel_deferred_slash_V2))
        break;
    case 4375: /* module 17 call 23 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V2(c, &method->nested.staking_payout_stakers_V2))
        break;
    case 4377: /* module 17 call 25 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V2(c, &method->nested.staking_set_history_depth_V2))
        break;
    case 4378: /* module 17 call 26 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V2(c, &method->nested.staking_reap_stash_V2))
        break;
    case 4381: /* module 17 call 29 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_by_system_V2(c, &method->nested.staking_payout_stakers_by_system_V2))
        break;
    case 4382: /* module 17 call 30 */
        CHECK_ERROR(_readMethod_staking_change_slashing_allowed_for_V2(c, &method->nested.staking_change_slashing_allowed_for_V2))
        break;
    case 4383: /* module 17 call 31 */
        CHECK_ERROR(_readMethod_staking_update_permissioned_validator_intended_count_V2(c, &method->nested.staking_update_permissioned_validator_intended_count_V2))
        break;
    case 4864: /* module 19 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V2(c, &method->nested.session_set_keys_V2))
        break;
    case 4865: /* module 19 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V2(c, &method->nested.session_purge_keys_V2))
        break;
    case 5378: /* module 21 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V2(c, &method->nested.grandpa_note_stalled_V2))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V2(c, &method->nested.sudo_sudo_as_V2))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_asset_register_ticker_V2(c, &method->nested.asset_register_ticker_V2))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_asset_accept_ticker_transfer_V2(c, &method->nested.asset_accept_ticker_transfer_V2))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_asset_accept_asset_ownership_transfer_V2(c, &method->nested.asset_accept_asset_ownership_transfer_V2))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_asset_create_asset_V2(c, &method->nested.asset_create_asset_V2))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_asset_freeze_V2(c, &method->nested.asset_freeze_V2))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_asset_unfreeze_V2(c, &method->nested.asset_unfreeze_V2))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_asset_rename_asset_V2(c, &method->nested.asset_rename_asset_V2))
        break;
    case 6663: /* module 26 call 7 */
        CHECK_ERROR(_readMethod_asset_issue_V2(c, &method->nested.asset_issue_V2))
        break;
    case 6664: /* module 26 call 8 */
        CHECK_ERROR(_readMethod_asset_redeem_V2(c, &method->nested.asset_redeem_V2))
        break;
    case 6665: /* module 26 call 9 */
        CHECK_ERROR(_readMethod_asset_make_divisible_V2(c, &method->nested.asset_make_divisible_V2))
        break;
    case 6666: /* module 26 call 10 */
        CHECK_ERROR(_readMethod_asset_add_documents_V2(c, &method->nested.asset_add_documents_V2))
        break;
    case 6667: /* module 26 call 11 */
        CHECK_ERROR(_readMethod_asset_remove_documents_V2(c, &method->nested.asset_remove_documents_V2))
        break;
    case 6668: /* module 26 call 12 */
        CHECK_ERROR(_readMethod_asset_set_funding_round_V2(c, &method->nested.asset_set_funding_round_V2))
        break;
    case 6669: /* module 26 call 13 */
        CHECK_ERROR(_readMethod_asset_update_identifiers_V2(c, &method->nested.asset_update_identifiers_V2))
        break;
    case 6670: /* module 26 call 14 */
        CHECK_ERROR(_readMethod_asset_claim_classic_ticker_V2(c, &method->nested.asset_claim_classic_ticker_V2))
        break;
    case 6671: /* module 26 call 15 */
        CHECK_ERROR(_readMethod_asset_reserve_classic_ticker_V2(c, &method->nested.asset_reserve_classic_ticker_V2))
        break;
    case 6672: /* module 26 call 16 */
        CHECK_ERROR(_readMethod_asset_controller_transfer_V2(c, &method->basic.asset_controller_transfer_V2))
        break;
    case 6673: /* module 26 call 17 */
        CHECK_ERROR(_readMethod_asset_register_custom_asset_type_V2(c, &method->basic.asset_register_custom_asset_type_V2))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_capitaldistribution_distribute_V2(c, &method->nested.capitaldistribution_distribute_V2))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_capitaldistribution_claim_V2(c, &method->nested.capitaldistribution_claim_V2))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_capitaldistribution_push_benefit_V2(c, &method->nested.capitaldistribution_push_benefit_V2))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_capitaldistribution_reclaim_V2(c, &method->nested.capitaldistribution_reclaim_V2))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_capitaldistribution_remove_distribution_V2(c, &method->nested.capitaldistribution_remove_distribution_V2))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_checkpoint_create_checkpoint_V2(c, &method->nested.checkpoint_create_checkpoint_V2))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_checkpoint_set_schedules_max_complexity_V2(c, &method->nested.checkpoint_set_schedules_max_complexity_V2))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_checkpoint_create_schedule_V2(c, &method->nested.checkpoint_create_schedule_V2))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_checkpoint_remove_schedule_V2(c, &method->nested.checkpoint_remove_schedule_V2))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_compliancemanager_add_compliance_requirement_V2(c, &method->nested.compliancemanager_add_compliance_requirement_V2))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_compliance_requirement_V2(c, &method->nested.compliancemanager_remove_compliance_requirement_V2))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_compliancemanager_replace_asset_compliance_V2(c, &method->nested.compliancemanager_replace_asset_compliance_V2))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_compliancemanager_reset_asset_compliance_V2(c, &method->nested.compliancemanager_reset_asset_compliance_V2))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_compliancemanager_pause_asset_compliance_V2(c, &method->nested.compliancemanager_pause_asset_compliance_V2))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_compliancemanager_resume_asset_compliance_V2(c, &method->nested.compliancemanager_resume_asset_compliance_V2))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_compliancemanager_add_default_trusted_claim_issuer_V2(c, &method->nested.compliancemanager_add_default_trusted_claim_issuer_V2))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_default_trusted_claim_issuer_V2(c, &method->nested.compliancemanager_remove_default_trusted_claim_issuer_V2))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_compliancemanager_change_compliance_requirement_V2(c, &method->nested.compliancemanager_change_compliance_requirement_V2))
        break;
    case 7680: /* module 30 call 0 */
        CHECK_ERROR(_readMethod_corporateaction_set_max_details_length_V2(c, &method->nested.corporateaction_set_max_details_length_V2))
        break;
    case 7681: /* module 30 call 1 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_targets_V2(c, &method->nested.corporateaction_set_default_targets_V2))
        break;
    case 7682: /* module 30 call 2 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_withholding_tax_V2(c, &method->nested.corporateaction_set_default_withholding_tax_V2))
        break;
    case 7683: /* module 30 call 3 */
        CHECK_ERROR(_readMethod_corporateaction_set_did_withholding_tax_V2(c, &method->nested.corporateaction_set_did_withholding_tax_V2))
        break;
    case 7684: /* module 30 call 4 */
        CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action_V2(c, &method->nested.corporateaction_initiate_corporate_action_V2))
        break;
    case 7685: /* module 30 call 5 */
        CHECK_ERROR(_readMethod_corporateaction_link_ca_doc_V2(c, &method->nested.corporateaction_link_ca_doc_V2))
        break;
    case 7686: /* module 30 call 6 */
        CHECK_ERROR(_readMethod_corporateaction_remove_ca_V2(c, &method->nested.corporateaction_remove_ca_V2))
        break;
    case 7687: /* module 30 call 7 */
        CHECK_ERROR(_readMethod_corporateaction_change_record_date_V2(c, &method->nested.corporateaction_change_record_date_V2))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_corporateballot_attach_ballot_V2(c, &method->nested.corporateballot_attach_ballot_V2))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_corporateballot_vote_V2(c, &method->nested.corporateballot_vote_V2))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_corporateballot_change_end_V2(c, &method->nested.corporateballot_change_end_V2))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_corporateballot_change_meta_V2(c, &method->nested.corporateballot_change_meta_V2))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_corporateballot_change_rcv_V2(c, &method->nested.corporateballot_change_rcv_V2))
        break;
    case 7941: /* module 31 call 5 */
        CHECK_ERROR(_readMethod_corporateballot_remove_ballot_V2(c, &method->nested.corporateballot_remove_ballot_V2))
        break;
    case 8448: /* module 33 call 0 */
        CHECK_ERROR(_readMethod_pips_set_prune_historical_pips_V2(c, &method->nested.pips_set_prune_historical_pips_V2))
        break;
    case 8449: /* module 33 call 1 */
        CHECK_ERROR(_readMethod_pips_set_min_proposal_deposit_V2(c, &method->nested.pips_set_min_proposal_deposit_V2))
        break;
    case 8450: /* module 33 call 2 */
        CHECK_ERROR(_readMethod_pips_set_default_enactment_period_V2(c, &method->nested.pips_set_default_enactment_period_V2))
        break;
    case 8451: /* module 33 call 3 */
        CHECK_ERROR(_readMethod_pips_set_pending_pip_expiry_V2(c, &method->nested.pips_set_pending_pip_expiry_V2))
        break;
    case 8452: /* module 33 call 4 */
        CHECK_ERROR(_readMethod_pips_set_max_pip_skip_count_V2(c, &method->nested.pips_set_max_pip_skip_count_V2))
        break;
    case 8453: /* module 33 call 5 */
        CHECK_ERROR(_readMethod_pips_set_active_pip_limit_V2(c, &method->nested.pips_set_active_pip_limit_V2))
        break;
    case 8456: /* module 33 call 8 */
        CHECK_ERROR(_readMethod_pips_approve_committee_proposal_V2(c, &method->nested.pips_approve_committee_proposal_V2))
        break;
    case 8457: /* module 33 call 9 */
        CHECK_ERROR(_readMethod_pips_reject_proposal_V2(c, &method->nested.pips_reject_proposal_V2))
        break;
    case 8458: /* module 33 call 10 */
        CHECK_ERROR(_readMethod_pips_prune_proposal_V2(c, &method->nested.pips_prune_proposal_V2))
        break;
    case 8459: /* module 33 call 11 */
        CHECK_ERROR(_readMethod_pips_reschedule_execution_V2(c, &method->nested.pips_reschedule_execution_V2))
        break;
    case 8460: /* module 33 call 12 */
        CHECK_ERROR(_readMethod_pips_clear_snapshot_V2(c, &method->nested.pips_clear_snapshot_V2))
        break;
    case 8461: /* module 33 call 13 */
        CHECK_ERROR(_readMethod_pips_snapshot_V2(c, &method->nested.pips_snapshot_V2))
        break;
    case 8462: /* module 33 call 14 */
        CHECK_ERROR(_readMethod_pips_enact_snapshot_results_V2(c, &method->nested.pips_enact_snapshot_results_V2))
        break;
    case 8463: /* module 33 call 15 */
        CHECK_ERROR(_readMethod_pips_execute_scheduled_pip_V2(c, &method->nested.pips_execute_scheduled_pip_V2))
        break;
    case 8464: /* module 33 call 16 */
        CHECK_ERROR(_readMethod_pips_expire_scheduled_pip_V2(c, &method->nested.pips_expire_scheduled_pip_V2))
        break;
    case 8704: /* module 34 call 0 */
        CHECK_ERROR(_readMethod_portfolio_create_portfolio_V2(c, &method->nested.portfolio_create_portfolio_V2))
        break;
    case 8705: /* module 34 call 1 */
        CHECK_ERROR(_readMethod_portfolio_delete_portfolio_V2(c, &method->nested.portfolio_delete_portfolio_V2))
        break;
    case 8706: /* module 34 call 2 */
        CHECK_ERROR(_readMethod_portfolio_move_portfolio_funds_V2(c, &method->nested.portfolio_move_portfolio_funds_V2))
        break;
    case 8707: /* module 34 call 3 */
        CHECK_ERROR(_readMethod_portfolio_rename_portfolio_V2(c, &method->nested.portfolio_rename_portfolio_V2))
        break;
    case 8708: /* module 34 call 4 */
        CHECK_ERROR(_readMethod_portfolio_quit_portfolio_custody_V2(c, &method->basic.portfolio_quit_portfolio_custody_V2))
        break;
    case 8709: /* module 34 call 5 */
        CHECK_ERROR(_readMethod_portfolio_accept_portfolio_custody_V2(c, &method->basic.portfolio_accept_portfolio_custody_V2))
        break;
    case 8960: /* module 35 call 0 */
        CHECK_ERROR(_readMethod_protocolfee_change_coefficient_V2(c, &method->nested.protocolfee_change_coefficient_V2))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_settlement_create_venue_V2(c, &method->nested.settlement_create_venue_V2))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_settlement_update_venue_details_V2(c, &method->basic.settlement_update_venue_details_V2))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_settlement_update_venue_type_V2(c, &method->basic.settlement_update_venue_type_V2))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_settlement_add_instruction_V2(c, &method->nested.settlement_add_instruction_V2))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_settlement_add_and_affirm_instruction_V2(c, &method->nested.settlement_add_and_affirm_instruction_V2))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_settlement_affirm_instruction_V2(c, &method->nested.settlement_affirm_instruction_V2))
        break;
    case 9478: /* module 37 call 6 */
        CHECK_ERROR(_readMethod_settlement_withdraw_affirmation_V2(c, &method->nested.settlement_withdraw_affirmation_V2))
        break;
    case 9479: /* module 37 call 7 */
        CHECK_ERROR(_readMethod_settlement_reject_instruction_V2(c, &method->nested.settlement_reject_instruction_V2))
        break;
    case 9480: /* module 37 call 8 */
        CHECK_ERROR(_readMethod_settlement_affirm_with_receipts_V2(c, &method->nested.settlement_affirm_with_receipts_V2))
        break;
    case 9481: /* module 37 call 9 */
        CHECK_ERROR(_readMethod_settlement_claim_receipt_V2(c, &method->nested.settlement_claim_receipt_V2))
        break;
    case 9482: /* module 37 call 10 */
        CHECK_ERROR(_readMethod_settlement_unclaim_receipt_V2(c, &method->nested.settlement_unclaim_receipt_V2))
        break;
    case 9483: /* module 37 call 11 */
        CHECK_ERROR(_readMethod_settlement_set_venue_filtering_V2(c, &method->nested.settlement_set_venue_filtering_V2))
        break;
    case 9484: /* module 37 call 12 */
        CHECK_ERROR(_readMethod_settlement_allow_venues_V2(c, &method->nested.settlement_allow_venues_V2))
        break;
    case 9485: /* module 37 call 13 */
        CHECK_ERROR(_readMethod_settlement_disallow_venues_V2(c, &method->nested.settlement_disallow_venues_V2))
        break;
    case 9486: /* module 37 call 14 */
        CHECK_ERROR(_readMethod_settlement_change_receipt_validity_V2(c, &method->basic.settlement_change_receipt_validity_V2))
        break;
    case 9487: /* module 37 call 15 */
        CHECK_ERROR(_readMethod_settlement_execute_scheduled_instruction_V2(c, &method->nested.settlement_execute_scheduled_instruction_V2))
        break;
    case 9488: /* module 37 call 16 */
        CHECK_ERROR(_readMethod_settlement_reschedule_instruction_V2(c, &method->basic.settlement_reschedule_instruction_V2))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_statistics_add_transfer_manager_V2(c, &method->nested.statistics_add_transfer_manager_V2))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_statistics_remove_transfer_manager_V2(c, &method->nested.statistics_remove_transfer_manager_V2))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_statistics_add_exempted_entities_V2(c, &method->nested.statistics_add_exempted_entities_V2))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_statistics_remove_exempted_entities_V2(c, &method->nested.statistics_remove_exempted_entities_V2))
        break;
    case 9984: /* module 39 call 0 */
        CHECK_ERROR(_readMethod_sto_create_fundraiser_V2(c, &method->basic.sto_create_fundraiser_V2))
        break;
    case 9985: /* module 39 call 1 */
        CHECK_ERROR(_readMethod_sto_invest_V2(c, &method->basic.sto_invest_V2))
        break;
    case 9986: /* module 39 call 2 */
        CHECK_ERROR(_readMethod_sto_freeze_fundraiser_V2(c, &method->basic.sto_freeze_fundraiser_V2))
        break;
    case 9987: /* module 39 call 3 */
        CHECK_ERROR(_readMethod_sto_unfreeze_fundraiser_V2(c, &method->basic.sto_unfreeze_fundraiser_V2))
        break;
    case 9988: /* module 39 call 4 */
        CHECK_ERROR(_readMethod_sto_modify_fundraiser_window_V2(c, &method->basic.sto_modify_fundraiser_window_V2))
        break;
    case 9989: /* module 39 call 5 */
        CHECK_ERROR(_readMethod_sto_stop_V2(c, &method->basic.sto_stop_V2))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_treasury_disbursement_V2(c, &method->nested.treasury_disbursement_V2))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_treasury_reimbursement_V2(c, &method->nested.treasury_reimbursement_V2))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_utility_relay_tx_V2(c, &method->nested.utility_relay_tx_V2))
        break;
    case 11010: /* module 43 call 2 */
        CHECK_ERROR(_readMethod_externalagents_remove_agent_V2(c, &method->basic.externalagents_remove_agent_V2))
        break;
    case 11011: /* module 43 call 3 */
        CHECK_ERROR(_readMethod_externalagents_abdicate_V2(c, &method->basic.externalagents_abdicate_V2))
        break;
    case 11013: /* module 43 call 5 */
        CHECK_ERROR(_readMethod_externalagents_accept_become_agent_V2(c, &method->basic.externalagents_accept_become_agent_V2))
        break;
    case 11264: /* module 44 call 0 */
        CHECK_ERROR(_readMethod_relayer_set_paying_key_V2(c, &method->basic.relayer_set_paying_key_V2))
        break;
    case 11265: /* module 44 call 1 */
        CHECK_ERROR(_readMethod_relayer_accept_paying_key_V2(c, &method->basic.relayer_accept_paying_key_V2))
        break;
    case 11266: /* module 44 call 2 */
        CHECK_ERROR(_readMethod_relayer_remove_paying_key_V2(c, &method->basic.relayer_remove_paying_key_V2))
        break;
    case 11267: /* module 44 call 3 */
        CHECK_ERROR(_readMethod_relayer_update_polyx_limit_V2(c, &method->basic.relayer_update_polyx_limit_V2))
        break;
    case 11268: /* module 44 call 4 */
        CHECK_ERROR(_readMethod_relayer_increase_polyx_limit_V2(c, &method->basic.relayer_increase_polyx_limit_V2))
        break;
    case 11269: /* module 44 call 5 */
        CHECK_ERROR(_readMethod_relayer_decrease_polyx_limit_V2(c, &method->basic.relayer_decrease_polyx_limit_V2))
        break;
    case 11520: /* module 45 call 0 */
        CHECK_ERROR(_readMethod_rewards_claim_itn_reward_V2(c, &method->basic.rewards_claim_itn_reward_V2))
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

const char* _getMethod_ModuleName_V2(uint8_t moduleIdx)
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
    case 21:
        return STR_MO_GRANDPA;
    case 25:
        return STR_MO_SUDO;
    case 26:
        return STR_MO_ASSET;
    case 27:
        return STR_MO_CAPITALDISTRIBUTION;
    case 28:
        return STR_MO_CHECKPOINT;
    case 29:
        return STR_MO_COMPLIANCEMANAGER;
    case 30:
        return STR_MO_CORPORATEACTION;
    case 31:
        return STR_MO_CORPORATEBALLOT;
    case 34:
        return STR_MO_PORTFOLIO;
    case 35:
        return STR_MO_PROTOCOLFEE;
    case 37:
        return STR_MO_SETTLEMENT;
    case 38:
        return STR_MO_STATISTICS;
    case 39:
        return STR_MO_STO;
    case 40:
        return STR_MO_TREASURY;
    case 43:
        return STR_MO_EXTERNALAGENTS;
    case 44:
        return STR_MO_RELAYER;
    case 45:
        return STR_MO_REWARDS;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return STR_ME_TRANSFER;
    case 1794: /* module 7 call 2 */
        return STR_ME_REMOVE_SECONDARY_KEYS;
    case 1795: /* module 7 call 3 */
        return STR_ME_ACCEPT_PRIMARY_KEY;
    case 1797: /* module 7 call 5 */
        return STR_ME_JOIN_IDENTITY_AS_KEY;
    case 1798: /* module 7 call 6 */
        return STR_ME_LEAVE_IDENTITY_AS_KEY;
    case 1799: /* module 7 call 7 */
        return STR_ME_ADD_CLAIM;
    case 1800: /* module 7 call 8 */
        return STR_ME_REVOKE_CLAIM;
    case 1801: /* module 7 call 9 */
        return STR_ME_SET_PERMISSION_TO_SIGNER;
    case 1803: /* module 7 call 11 */
        return STR_ME_FREEZE_SECONDARY_KEYS;
    case 1804: /* module 7 call 12 */
        return STR_ME_UNFREEZE_SECONDARY_KEYS;
    case 1805: /* module 7 call 13 */
        return STR_ME_ADD_AUTHORIZATION;
    case 1806: /* module 7 call 14 */
        return STR_ME_REMOVE_AUTHORIZATION;
    case 1807: /* module 7 call 15 */
        return STR_ME_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION;
    case 1808: /* module 7 call 16 */
        return STR_ME_ADD_INVESTOR_UNIQUENESS_CLAIM;
    case 3840: /* module 15 call 0 */
        return STR_ME_CREATE_MULTISIG;
    case 3841: /* module 15 call 1 */
        return STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY;
    case 3842: /* module 15 call 2 */
        return STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_KEY;
    case 3843: /* module 15 call 3 */
        return STR_ME_CREATE_PROPOSAL_AS_IDENTITY;
    case 3844: /* module 15 call 4 */
        return STR_ME_CREATE_PROPOSAL_AS_KEY;
    case 3845: /* module 15 call 5 */
        return STR_ME_APPROVE_AS_IDENTITY;
    case 3846: /* module 15 call 6 */
        return STR_ME_APPROVE_AS_KEY;
    case 3847: /* module 15 call 7 */
        return STR_ME_REJECT_AS_IDENTITY;
    case 3848: /* module 15 call 8 */
        return STR_ME_REJECT_AS_KEY;
    case 3849: /* module 15 call 9 */
        return STR_ME_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY;
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
    case 3856: /* module 15 call 16 */
        return STR_ME_MAKE_MULTISIG_SIGNER;
    case 3857: /* module 15 call 17 */
        return STR_ME_MAKE_MULTISIG_PRIMARY;
    case 3858: /* module 15 call 18 */
        return STR_ME_EXECUTE_SCHEDULED_PROPOSAL;
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
    case 10497: /* module 41 call 1 */
        return STR_ME_BATCH_ATOMIC;
    case 10498: /* module 41 call 2 */
        return STR_ME_BATCH_OPTIMISTIC;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return STR_ME_FILL_BLOCK;
    case 1: /* module 0 call 1 */
        return STR_ME_REMARK;
    case 2: /* module 0 call 2 */
        return STR_ME_SET_HEAP_PAGES;
    case 3: /* module 0 call 3 */
        return STR_ME_SET_CODE;
    case 4: /* module 0 call 4 */
        return STR_ME_SET_CODE_WITHOUT_CHECKS;
    case 5: /* module 0 call 5 */
        return STR_ME_SET_CHANGES_TRIE_CONFIG;
    case 6: /* module 0 call 6 */
        return STR_ME_SET_STORAGE;
    case 7: /* module 0 call 7 */
        return STR_ME_KILL_STORAGE;
    case 8: /* module 0 call 8 */
        return STR_ME_KILL_PREFIX;
    case 256: /* module 1 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 257: /* module 1 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
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
    case 1024: /* module 4 call 0 */
        return STR_ME_SET_UNCLES;
    case 1281: /* module 5 call 1 */
        return STR_ME_TRANSFER_WITH_MEMO;
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
    case 1796: /* module 7 call 4 */
        return STR_ME_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION;
    case 1809: /* module 7 call 17 */
        return STR_ME_GC_ADD_CDD_CLAIM;
    case 1810: /* module 7 call 18 */
        return STR_ME_GC_REVOKE_CDD_CLAIM;
    case 1811: /* module 7 call 19 */
        return STR_ME_ADD_INVESTOR_UNIQUENESS_CLAIM_V2;
    case 1812: /* module 7 call 20 */
        return STR_ME_REVOKE_CLAIM_BY_INDEX;
    case 1813: /* module 7 call 21 */
        return STR_ME_ROTATE_PRIMARY_KEY_TO_SECONDARY;
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
    case 4379: /* module 17 call 27 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION;
    case 4380: /* module 17 call 28 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION_UNSIGNED;
    case 4381: /* module 17 call 29 */
        return STR_ME_PAYOUT_STAKERS_BY_SYSTEM;
    case 4382: /* module 17 call 30 */
        return STR_ME_CHANGE_SLASHING_ALLOWED_FOR;
    case 4383: /* module 17 call 31 */
        return STR_ME_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT;
    case 4864: /* module 19 call 0 */
        return STR_ME_SET_KEYS;
    case 4865: /* module 19 call 1 */
        return STR_ME_PURGE_KEYS;
    case 5376: /* module 21 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 5377: /* module 21 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 5378: /* module 21 call 2 */
        return STR_ME_NOTE_STALLED;
    case 5888: /* module 23 call 0 */
        return STR_ME_HEARTBEAT;
    case 6400: /* module 25 call 0 */
        return STR_ME_SUDO;
    case 6401: /* module 25 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 6402: /* module 25 call 2 */
        return STR_ME_SET_KEY;
    case 6403: /* module 25 call 3 */
        return STR_ME_SUDO_AS;
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
        return STR_ME_CLAIM_CLASSIC_TICKER;
    case 6671: /* module 26 call 15 */
        return STR_ME_RESERVE_CLASSIC_TICKER;
    case 6672: /* module 26 call 16 */
        return STR_ME_CONTROLLER_TRANSFER;
    case 6673: /* module 26 call 17 */
        return STR_ME_REGISTER_CUSTOM_ASSET_TYPE;
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
    case 8462: /* module 33 call 14 */
        return STR_ME_ENACT_SNAPSHOT_RESULTS;
    case 8463: /* module 33 call 15 */
        return STR_ME_EXECUTE_SCHEDULED_PIP;
    case 8464: /* module 33 call 16 */
        return STR_ME_EXPIRE_SCHEDULED_PIP;
    case 8704: /* module 34 call 0 */
        return STR_ME_CREATE_PORTFOLIO;
    case 8705: /* module 34 call 1 */
        return STR_ME_DELETE_PORTFOLIO;
    case 8706: /* module 34 call 2 */
        return STR_ME_MOVE_PORTFOLIO_FUNDS;
    case 8707: /* module 34 call 3 */
        return STR_ME_RENAME_PORTFOLIO;
    case 8708: /* module 34 call 4 */
        return STR_ME_QUIT_PORTFOLIO_CUSTODY;
    case 8709: /* module 34 call 5 */
        return STR_ME_ACCEPT_PORTFOLIO_CUSTODY;
    case 8960: /* module 35 call 0 */
        return STR_ME_CHANGE_COEFFICIENT;
    case 8961: /* module 35 call 1 */
        return STR_ME_CHANGE_BASE_FEE;
    case 9216: /* module 36 call 0 */
        return STR_ME_SCHEDULE;
    case 9217: /* module 36 call 1 */
        return STR_ME_CANCEL;
    case 9218: /* module 36 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 9219: /* module 36 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 9220: /* module 36 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 9221: /* module 36 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 9472: /* module 37 call 0 */
        return STR_ME_CREATE_VENUE;
    case 9473: /* module 37 call 1 */
        return STR_ME_UPDATE_VENUE_DETAILS;
    case 9474: /* module 37 call 2 */
        return STR_ME_UPDATE_VENUE_TYPE;
    case 9475: /* module 37 call 3 */
        return STR_ME_ADD_INSTRUCTION;
    case 9476: /* module 37 call 4 */
        return STR_ME_ADD_AND_AFFIRM_INSTRUCTION;
    case 9477: /* module 37 call 5 */
        return STR_ME_AFFIRM_INSTRUCTION;
    case 9478: /* module 37 call 6 */
        return STR_ME_WITHDRAW_AFFIRMATION;
    case 9479: /* module 37 call 7 */
        return STR_ME_REJECT_INSTRUCTION;
    case 9480: /* module 37 call 8 */
        return STR_ME_AFFIRM_WITH_RECEIPTS;
    case 9481: /* module 37 call 9 */
        return STR_ME_CLAIM_RECEIPT;
    case 9482: /* module 37 call 10 */
        return STR_ME_UNCLAIM_RECEIPT;
    case 9483: /* module 37 call 11 */
        return STR_ME_SET_VENUE_FILTERING;
    case 9484: /* module 37 call 12 */
        return STR_ME_ALLOW_VENUES;
    case 9485: /* module 37 call 13 */
        return STR_ME_DISALLOW_VENUES;
    case 9486: /* module 37 call 14 */
        return STR_ME_CHANGE_RECEIPT_VALIDITY;
    case 9487: /* module 37 call 15 */
        return STR_ME_EXECUTE_SCHEDULED_INSTRUCTION;
    case 9488: /* module 37 call 16 */
        return STR_ME_RESCHEDULE_INSTRUCTION;
    case 9728: /* module 38 call 0 */
        return STR_ME_ADD_TRANSFER_MANAGER;
    case 9729: /* module 38 call 1 */
        return STR_ME_REMOVE_TRANSFER_MANAGER;
    case 9730: /* module 38 call 2 */
        return STR_ME_ADD_EXEMPTED_ENTITIES;
    case 9731: /* module 38 call 3 */
        return STR_ME_REMOVE_EXEMPTED_ENTITIES;
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
    case 10499: /* module 41 call 3 */
        return STR_ME_RELAY_TX;
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
    case 11520: /* module 45 call 0 */
        return STR_ME_CLAIM_ITN_REWARD;
    case 11521: /* module 45 call 1 */
        return STR_ME_SET_ITN_REWARD_STATUS;
    case 12800: /* module 50 call 0 */
        return STR_ME_REGISTER_DID;
    case 12801: /* module 50 call 1 */
        return STR_ME_MOCK_CDD_REGISTER_DID;
    case 12802: /* module 50 call 2 */
        return STR_ME_GET_MY_DID;
    case 12803: /* module 50 call 3 */
        return STR_ME_GET_CDD_OF;
#endif
    default:
        return NULL;
    }

    return NULL;
}

uint8_t _getMethod_NumItems_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        return 2;
    case 1794: /* module 7 call 2 */
        return 1;
    case 1795: /* module 7 call 3 */
        return 2;
    case 1797: /* module 7 call 5 */
        return 1;
    case 1798: /* module 7 call 6 */
        return 0;
    case 1799: /* module 7 call 7 */
        return 3;
    case 1800: /* module 7 call 8 */
        return 2;
    case 1801: /* module 7 call 9 */
        return 2;
    case 1803: /* module 7 call 11 */
        return 0;
    case 1804: /* module 7 call 12 */
        return 0;
    case 1805: /* module 7 call 13 */
        return 3;
    case 1806: /* module 7 call 14 */
        return 3;
    case 1807: /* module 7 call 15 */
        return 2;
    case 1808: /* module 7 call 16 */
        return 4;
    case 3840: /* module 15 call 0 */
        return 2;
    case 3841: /* module 15 call 1 */
        return 4;
    case 3842: /* module 15 call 2 */
        return 4;
    case 3843: /* module 15 call 3 */
        return 4;
    case 3844: /* module 15 call 4 */
        return 4;
    case 3845: /* module 15 call 5 */
        return 2;
    case 3846: /* module 15 call 6 */
        return 2;
    case 3847: /* module 15 call 7 */
        return 2;
    case 3848: /* module 15 call 8 */
        return 2;
    case 3849: /* module 15 call 9 */
        return 1;
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
    case 3856: /* module 15 call 16 */
        return 1;
    case 3857: /* module 15 call 17 */
        return 2;
    case 3858: /* module 15 call 18 */
        return 4;
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
    case 10497: /* module 41 call 1 */
        return 1;
    case 10498: /* module 41 call 2 */
        return 1;
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        return 1;
    case 1: /* module 0 call 1 */
        return 1;
    case 2: /* module 0 call 2 */
        return 1;
    case 3: /* module 0 call 3 */
        return 1;
    case 4: /* module 0 call 4 */
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
    case 1281: /* module 5 call 1 */
        return 3;
    case 1282: /* module 5 call 2 */
        return 1;
    case 1283: /* module 5 call 3 */
        return 3;
    case 1284: /* module 5 call 4 */
        return 3;
    case 1285: /* module 5 call 5 */
        return 1;
    case 1793: /* module 7 call 1 */
        return 3;
    case 1796: /* module 7 call 4 */
        return 1;
    case 1809: /* module 7 call 17 */
        return 1;
    case 1810: /* module 7 call 18 */
        return 1;
    case 1812: /* module 7 call 20 */
        return 3;
    case 1813: /* module 7 call 21 */
        return 2;
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
    case 4864: /* module 19 call 0 */
        return 2;
    case 4865: /* module 19 call 1 */
        return 0;
    case 5378: /* module 21 call 2 */
        return 2;
    case 6403: /* module 25 call 3 */
        return 2;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 1;
    case 6658: /* module 26 call 2 */
        return 1;
    case 6659: /* module 26 call 3 */
        return 7;
    case 6660: /* module 26 call 4 */
        return 1;
    case 6661: /* module 26 call 5 */
        return 1;
    case 6662: /* module 26 call 6 */
        return 2;
    case 6663: /* module 26 call 7 */
        return 2;
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
        return 2;
    case 6671: /* module 26 call 15 */
        return 3;
    case 6672: /* module 26 call 16 */
        return 3;
    case 6673: /* module 26 call 17 */
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
    case 8462: /* module 33 call 14 */
        return 1;
    case 8463: /* module 33 call 15 */
        return 1;
    case 8464: /* module 33 call 16 */
        return 2;
    case 8704: /* module 34 call 0 */
        return 1;
    case 8705: /* module 34 call 1 */
        return 1;
    case 8706: /* module 34 call 2 */
        return 3;
    case 8707: /* module 34 call 3 */
        return 2;
    case 8708: /* module 34 call 4 */
        return 1;
    case 8709: /* module 34 call 5 */
        return 1;
    case 8960: /* module 35 call 0 */
        return 1;
    case 9472: /* module 37 call 0 */
        return 3;
    case 9473: /* module 37 call 1 */
        return 2;
    case 9474: /* module 37 call 2 */
        return 2;
    case 9475: /* module 37 call 3 */
        return 5;
    case 9476: /* module 37 call 4 */
        return 6;
    case 9477: /* module 37 call 5 */
        return 3;
    case 9478: /* module 37 call 6 */
        return 3;
    case 9479: /* module 37 call 7 */
        return 3;
    case 9480: /* module 37 call 8 */
        return 4;
    case 9481: /* module 37 call 9 */
        return 2;
    case 9482: /* module 37 call 10 */
        return 2;
    case 9483: /* module 37 call 11 */
        return 2;
    case 9484: /* module 37 call 12 */
        return 2;
    case 9485: /* module 37 call 13 */
        return 2;
    case 9486: /* module 37 call 14 */
        return 2;
    case 9487: /* module 37 call 15 */
        return 2;
    case 9488: /* module 37 call 16 */
        return 1;
    case 9728: /* module 38 call 0 */
        return 2;
    case 9729: /* module 38 call 1 */
        return 2;
    case 9730: /* module 38 call 2 */
        return 3;
    case 9731: /* module 38 call 3 */
        return 3;
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
    case 10499: /* module 41 call 3 */
        return 3;
    case 11010: /* module 43 call 2 */
        return 2;
    case 11011: /* module 43 call 3 */
        return 1;
    case 11013: /* module 43 call 5 */
        return 1;
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
    case 11520: /* module 45 call 0 */
        return 3;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
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
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signers_to_remove;
        default:
            return NULL;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rotation_auth_id;
        case 1:
            return STR_IT_optional_cdd_auth_id;
        default:
            return NULL;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1799: /* module 7 call 7 */
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
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_claim;
        default:
            return NULL;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        case 1:
            return STR_IT_perms;
        default:
            return NULL;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1805: /* module 7 call 13 */
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
    case 1806: /* module 7 call 14 */
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
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional_keys;
        case 1:
            return STR_IT_expires_at;
        default:
            return NULL;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_claim;
        case 2:
            return STR_IT_proof;
        case 3:
            return STR_IT_expiry;
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
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
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
    case 3847: /* module 15 call 7 */
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
    case 3849: /* module 15 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
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
    case 3856: /* module 15 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
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
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_calls;
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
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT__ratio;
        default:
            return NULL;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT__remark;
        default:
            return NULL;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pages;
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
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code;
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
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_required;
        default:
            return NULL;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 1812: /* module 7 call 20 */
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
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        case 1:
            return STR_IT_optional_cdd_auth_id;
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
            return STR_IT__era_items_deleted;
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
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_call;
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
        case 6:
            return STR_IT_disable_iu;
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
            return STR_IT_identifiers;
        default:
            return NULL;
        }
    case 6670: /* module 26 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 6671: /* module 26 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_classic_ticker_import;
        case 1:
            return STR_IT_contract_did;
        case 2:
            return STR_IT_config;
        default:
            return NULL;
        }
    case 6672: /* module 26 call 16 */
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
    case 6673: /* module 26 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ty;
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
    case 8462: /* module 33 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_results;
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
            return STR_IT_from;
        case 1:
            return STR_IT_to;
        case 2:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num;
        case 1:
            return STR_IT_to_name;
        default:
            return NULL;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_pid;
        default:
            return NULL;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
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
            return STR_IT_venue_id;
        case 1:
            return STR_IT_settlement_type;
        case 2:
            return STR_IT_trade_date;
        case 3:
            return STR_IT_value_date;
        case 4:
            return STR_IT_legs;
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
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
        default:
            return NULL;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolios;
        case 2:
            return STR_IT_max_legs_count;
        default:
            return NULL;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolios;
        case 2:
            return STR_IT_max_legs_count;
        default:
            return NULL;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_portfolio;
        case 2:
            return STR_IT_num_of_legs;
        default:
            return NULL;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_receipt_details;
        case 2:
            return STR_IT_portfolios;
        case 3:
            return STR_IT_max_legs_count;
        default:
            return NULL;
        }
    case 9481: /* module 37 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_receipt_details;
        default:
            return NULL;
        }
    case 9482: /* module 37 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_leg_id;
        default:
            return NULL;
        }
    case 9483: /* module 37 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_enabled;
        default:
            return NULL;
        }
    case 9484: /* module 37 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_venues;
        default:
            return NULL;
        }
    case 9485: /* module 37 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_venues;
        default:
            return NULL;
        }
    case 9486: /* module 37 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_receipt_uid;
        case 1:
            return STR_IT_validity;
        default:
            return NULL;
        }
    case 9487: /* module 37 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT__legs_count;
        default:
            return NULL;
        }
    case 9488: /* module 37 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_new_transfer_manager;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_transfer_manager;
        default:
            return NULL;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_transfer_manager;
        case 2:
            return STR_IT_exempted_entities;
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_transfer_manager;
        case 2:
            return STR_IT_entities;
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
    case 10499: /* module 41 call 3 */
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
    case 11013: /* module 43 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
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
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_reward_address;
        case 1:
            return STR_IT_itn_address;
        case 2:
            return STR_IT_signature;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V2(
    pd_Method_V2_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1280: /* module 5 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V2 - dest */;
            return _toStringLookupSource_V2(
                &m->nested.balances_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1794: /* module 7 call 2 */
        switch (itemIdx) {
        case 0: /* identity_remove_secondary_keys_V2 - signers_to_remove */;
            return _toStringVecSignatory_V2(
                &m->nested.identity_remove_secondary_keys_V2.signers_to_remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1795: /* module 7 call 3 */
        switch (itemIdx) {
        case 0: /* identity_accept_primary_key_V2 - rotation_auth_id */;
            return _toStringu64(
                &m->nested.identity_accept_primary_key_V2.rotation_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_accept_primary_key_V2 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->nested.identity_accept_primary_key_V2.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1797: /* module 7 call 5 */
        switch (itemIdx) {
        case 0: /* identity_join_identity_as_key_V2 - auth_id */;
            return _toStringu64(
                &m->nested.identity_join_identity_as_key_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1798: /* module 7 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1799: /* module 7 call 7 */
        switch (itemIdx) {
        case 0: /* identity_add_claim_V2 - target */;
            return _toStringIdentityId_V2(
                &m->nested.identity_add_claim_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_claim_V2 - claim */;
            return _toStringClaim_V2(
                &m->nested.identity_add_claim_V2.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_claim_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.identity_add_claim_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1800: /* module 7 call 8 */
        switch (itemIdx) {
        case 0: /* identity_revoke_claim_V2 - target */;
            return _toStringIdentityId_V2(
                &m->nested.identity_revoke_claim_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_claim_V2 - claim */;
            return _toStringClaim_V2(
                &m->nested.identity_revoke_claim_V2.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1801: /* module 7 call 9 */
        switch (itemIdx) {
        case 0: /* identity_set_permission_to_signer_V2 - signer */;
            return _toStringSignatory_V2(
                &m->nested.identity_set_permission_to_signer_V2.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_permission_to_signer_V2 - perms */;
            return _toStringPermissions_V2(
                &m->nested.identity_set_permission_to_signer_V2.perms,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1803: /* module 7 call 11 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1804: /* module 7 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1805: /* module 7 call 13 */
        switch (itemIdx) {
        case 0: /* identity_add_authorization_V2 - target */;
            return _toStringSignatory_V2(
                &m->nested.identity_add_authorization_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_authorization_V2 - data */;
            return _toStringAuthorizationData_V2(
                &m->nested.identity_add_authorization_V2.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_authorization_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.identity_add_authorization_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1806: /* module 7 call 14 */
        switch (itemIdx) {
        case 0: /* identity_remove_authorization_V2 - target */;
            return _toStringSignatory_V2(
                &m->nested.identity_remove_authorization_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_remove_authorization_V2 - auth_id */;
            return _toStringu64(
                &m->nested.identity_remove_authorization_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_remove_authorization_V2 - _auth_issuer_pays */;
            return _toStringbool(
                &m->nested.identity_remove_authorization_V2._auth_issuer_pays,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1807: /* module 7 call 15 */
        switch (itemIdx) {
        case 0: /* identity_add_secondary_keys_with_authorization_V2 - additional_keys */;
            return _toStringVecSecondaryKeyWithAuth_V2(
                &m->nested.identity_add_secondary_keys_with_authorization_V2.additional_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_secondary_keys_with_authorization_V2 - expires_at */;
            return _toStringMoment_V2(
                &m->nested.identity_add_secondary_keys_with_authorization_V2.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1808: /* module 7 call 16 */
        switch (itemIdx) {
        case 0: /* identity_add_investor_uniqueness_claim_V2 - target */;
            return _toStringIdentityId_V2(
                &m->nested.identity_add_investor_uniqueness_claim_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_investor_uniqueness_claim_V2 - claim */;
            return _toStringClaim_V2(
                &m->nested.identity_add_investor_uniqueness_claim_V2.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_investor_uniqueness_claim_V2 - proof */;
            return _toStringInvestorZKProofData_V2(
                &m->nested.identity_add_investor_uniqueness_claim_V2.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* identity_add_investor_uniqueness_claim_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.identity_add_investor_uniqueness_claim_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3840: /* module 15 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_create_multisig_V2 - signers */;
            return _toStringVecSignatory_V2(
                &m->nested.multisig_create_multisig_V2.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_multisig_V2 - sigs_required */;
            return _toStringu64(
                &m->nested.multisig_create_multisig_V2.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3841: /* module 15 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_identity_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_identity_V2 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_identity_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_identity_V2 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V2.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3842: /* module 15 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_key_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_create_or_approve_proposal_as_key_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_key_V2 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_key_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_key_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.multisig_create_or_approve_proposal_as_key_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_key_V2 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_key_V2.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3843: /* module 15 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_identity_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_create_proposal_as_identity_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_identity_V2 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_identity_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_identity_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.multisig_create_proposal_as_identity_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_identity_V2 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_identity_V2.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3844: /* module 15 call 4 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_key_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_create_proposal_as_key_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_key_V2 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_key_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_key_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.multisig_create_proposal_as_key_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_key_V2 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_key_V2.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3845: /* module 15 call 5 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_identity_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_approve_as_identity_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_identity_V2 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_approve_as_identity_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3846: /* module 15 call 6 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_key_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_approve_as_key_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_key_V2 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_approve_as_key_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3847: /* module 15 call 7 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_identity_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_reject_as_identity_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_identity_V2 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_reject_as_identity_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3848: /* module 15 call 8 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_key_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_reject_as_key_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_key_V2 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_reject_as_key_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3849: /* module 15 call 9 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_identity_V2 - auth_id */;
            return _toStringu64(
                &m->nested.multisig_accept_multisig_signer_as_identity_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3850: /* module 15 call 10 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_key_V2 - auth_id */;
            return _toStringu64(
                &m->nested.multisig_accept_multisig_signer_as_key_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3851: /* module 15 call 11 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signer_V2 - signer */;
            return _toStringSignatory_V2(
                &m->nested.multisig_add_multisig_signer_V2.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3852: /* module 15 call 12 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signer_V2 - signer */;
            return _toStringSignatory_V2(
                &m->nested.multisig_remove_multisig_signer_V2.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3853: /* module 15 call 13 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signers_via_creator_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_add_multisig_signers_via_creator_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_add_multisig_signers_via_creator_V2 - signers */;
            return _toStringVecSignatory_V2(
                &m->nested.multisig_add_multisig_signers_via_creator_V2.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3854: /* module 15 call 14 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signers_via_creator_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_remove_multisig_signers_via_creator_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_remove_multisig_signers_via_creator_V2 - signers */;
            return _toStringVecSignatory_V2(
                &m->nested.multisig_remove_multisig_signers_via_creator_V2.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3855: /* module 15 call 15 */
        switch (itemIdx) {
        case 0: /* multisig_change_sigs_required_V2 - sigs_required */;
            return _toStringu64(
                &m->nested.multisig_change_sigs_required_V2.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3856: /* module 15 call 16 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_signer_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_make_multisig_signer_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3857: /* module 15 call 17 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_primary_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_make_multisig_primary_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_make_multisig_primary_V2 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->nested.multisig_make_multisig_primary_V2.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3858: /* module 15 call 18 */
        switch (itemIdx) {
        case 0: /* multisig_execute_scheduled_proposal_V2 - multisig */;
            return _toStringAccountId_V2(
                &m->nested.multisig_execute_scheduled_proposal_V2.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_execute_scheduled_proposal_V2 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_execute_scheduled_proposal_V2.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_execute_scheduled_proposal_V2 - multisig_did */;
            return _toStringIdentityId_V2(
                &m->nested.multisig_execute_scheduled_proposal_V2.multisig_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_execute_scheduled_proposal_V2 - _proposal_weight */;
            return _toStringWeight_V2(
                &m->nested.multisig_execute_scheduled_proposal_V2._proposal_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V2 - controller */;
            return _toStringLookupSource_V2(
                &m->nested.staking_bond_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V2 - amount */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_bond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->nested.staking_bond_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V2 - amount */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_bond_extra_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V2 - amount */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_unbond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_withdraw_unbonded_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4356: /* module 17 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V2 - prefs */;
            return _toStringValidatorPrefs_V2(
                &m->nested.staking_validate_V2.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4357: /* module 17 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V2 - targets */;
            return _toStringVecLookupSource_V2(
                &m->nested.staking_nominate_V2.targets,
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
        case 0: /* staking_set_payee_V2 - payee */;
            return _toStringRewardDestination_V2(
                &m->nested.staking_set_payee_V2.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4360: /* module 17 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V2 - controller */;
            return _toStringLookupSource_V2(
                &m->nested.staking_set_controller_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4376: /* module 17 call 24 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V2 - amount */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_rebond_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8454: /* module 33 call 6 */
        switch (itemIdx) {
        case 0: /* pips_propose_V2 - proposal */;
            return _toStringProposal(
                &m->nested.pips_propose_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_propose_V2 - deposit */;
            return _toStringBalance(
                &m->nested.pips_propose_V2.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_propose_V2 - url */;
            return _toStringOptionUrl_V2(
                &m->nested.pips_propose_V2.url,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* pips_propose_V2 - description */;
            return _toStringOptionPipDescription_V2(
                &m->nested.pips_propose_V2.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8455: /* module 33 call 7 */
        switch (itemIdx) {
        case 0: /* pips_vote_V2 - id */;
            return _toStringPipId_V2(
                &m->nested.pips_vote_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_vote_V2 - aye_or_nay */;
            return _toStringbool(
                &m->nested.pips_vote_V2.aye_or_nay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_vote_V2 - deposit */;
            return _toStringBalance(
                &m->nested.pips_vote_V2.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V2 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* utility_batch_atomic_V2 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_atomic_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_optimistic_V2 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_optimistic_V2.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V2 - _ratio */;
            return _toStringPerbill_V2(
                &m->nested.system_fill_block_V2._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V2 - _remark */;
            return _toStringBytes(
                &m->nested.system_remark_V2._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V2 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V2.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V2 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V2 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V2.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V2 - now */;
            return _toStringCompactMoment_V2(
                &m->nested.timestamp_set_V2.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->nested.indices_claim_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->nested.indices_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->nested.indices_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->nested.indices_free_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V2 - new_ */;
            return _toStringAccountId_V2(
                &m->nested.indices_force_transfer_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->nested.indices_force_transfer_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V2 - freeze */;
            return _toStringbool(
                &m->nested.indices_force_transfer_V2.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V2 - index */;
            return _toStringAccountIndex_V2(
                &m->nested.indices_freeze_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1281: /* module 5 call 1 */
        switch (itemIdx) {
        case 0: /* balances_transfer_with_memo_V2 - dest */;
            return _toStringLookupSource_V2(
                &m->nested.balances_transfer_with_memo_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_with_memo_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_with_memo_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_transfer_with_memo_V2 - memo */;
            return _toStringOptionMemo_V2(
                &m->nested.balances_transfer_with_memo_V2.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1282: /* module 5 call 2 */
        switch (itemIdx) {
        case 0: /* balances_deposit_block_reward_reserve_balance_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_deposit_block_reward_reserve_balance_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1283: /* module 5 call 3 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V2 - who */;
            return _toStringLookupSource_V2(
                &m->nested.balances_set_balance_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V2 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V2 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V2.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1284: /* module 5 call 4 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V2 - source */;
            return _toStringLookupSource_V2(
                &m->nested.balances_force_transfer_V2.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V2 - dest */;
            return _toStringLookupSource_V2(
                &m->nested.balances_force_transfer_V2.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V2 - amount */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1285: /* module 5 call 5 */
        switch (itemIdx) {
        case 0: /* balances_burn_account_balance_V2 - amount */;
            return _toStringBalance(
                &m->nested.balances_burn_account_balance_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1793: /* module 7 call 1 */
        switch (itemIdx) {
        case 0: /* identity_invalidate_cdd_claims_V2 - cdd */;
            return _toStringIdentityId_V2(
                &m->nested.identity_invalidate_cdd_claims_V2.cdd,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_invalidate_cdd_claims_V2 - disable_from */;
            return _toStringMoment_V2(
                &m->nested.identity_invalidate_cdd_claims_V2.disable_from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_invalidate_cdd_claims_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.identity_invalidate_cdd_claims_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1796: /* module 7 call 4 */
        switch (itemIdx) {
        case 0: /* identity_change_cdd_requirement_for_mk_rotation_V2 - auth_required */;
            return _toStringbool(
                &m->nested.identity_change_cdd_requirement_for_mk_rotation_V2.auth_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1809: /* module 7 call 17 */
        switch (itemIdx) {
        case 0: /* identity_gc_add_cdd_claim_V2 - target */;
            return _toStringIdentityId_V2(
                &m->nested.identity_gc_add_cdd_claim_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1810: /* module 7 call 18 */
        switch (itemIdx) {
        case 0: /* identity_gc_revoke_cdd_claim_V2 - target */;
            return _toStringIdentityId_V2(
                &m->nested.identity_gc_revoke_cdd_claim_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1812: /* module 7 call 20 */
        switch (itemIdx) {
        case 0: /* identity_revoke_claim_by_index_V2 - target */;
            return _toStringIdentityId_V2(
                &m->basic.identity_revoke_claim_by_index_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_claim_by_index_V2 - claim_type */;
            return _toStringClaimType_V2(
                &m->basic.identity_revoke_claim_by_index_V2.claim_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_revoke_claim_by_index_V2 - scope */;
            return _toStringOptionScope_V2(
                &m->basic.identity_revoke_claim_by_index_V2.scope,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1813: /* module 7 call 21 */
        switch (itemIdx) {
        case 0: /* identity_rotate_primary_key_to_secondary_V2 - auth_id */;
            return _toStringu64(
                &m->basic.identity_rotate_primary_key_to_secondary_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_rotate_primary_key_to_secondary_V2 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->basic.identity_rotate_primary_key_to_secondary_V2.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_set_active_members_limit_V2 - limit */;
            return _toStringMemberCount_V2(
                &m->nested.cddserviceproviders_set_active_members_limit_V2.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_disable_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.cddserviceproviders_disable_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_disable_member_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.cddserviceproviders_disable_member_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* cddserviceproviders_disable_member_V2 - at */;
            return _toStringOptionMoment_V2(
                &m->nested.cddserviceproviders_disable_member_V2.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_add_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.cddserviceproviders_add_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_remove_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.cddserviceproviders_remove_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_swap_member_V2 - remove */;
            return _toStringIdentityId_V2(
                &m->nested.cddserviceproviders_swap_member_V2.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_swap_member_V2 - add */;
            return _toStringIdentityId_V2(
                &m->nested.cddserviceproviders_swap_member_V2.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_reset_members_V2 - members */;
            return _toStringVecIdentityId_V2(
                &m->nested.cddserviceproviders_reset_members_V2.members,
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
        case 0: /* polymeshcommittee_set_vote_threshold_V2 - n */;
            return _toStringu32(
                &m->nested.polymeshcommittee_set_vote_threshold_V2.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_set_vote_threshold_V2 - d */;
            return _toStringu32(
                &m->nested.polymeshcommittee_set_vote_threshold_V2.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2305: /* module 9 call 1 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_release_coordinator_V2 - id */;
            return _toStringIdentityId_V2(
                &m->nested.polymeshcommittee_set_release_coordinator_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2306: /* module 9 call 2 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_expires_after_V2 - expiry */;
            return _toStringMaybeBlock_V2(
                &m->nested.polymeshcommittee_set_expires_after_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2307: /* module 9 call 3 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_or_propose_V2 - approve */;
            return _toStringbool(
                &m->nested.polymeshcommittee_vote_or_propose_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_or_propose_V2 - call */;
            return _toStringCall(
                &m->nested.polymeshcommittee_vote_or_propose_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2308: /* module 9 call 4 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_V2 - proposal */;
            return _toStringHash(
                &m->nested.polymeshcommittee_vote_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_V2 - index */;
            return _toStringProposalIndex_V2(
                &m->nested.polymeshcommittee_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcommittee_vote_V2 - approve */;
            return _toStringbool(
                &m->nested.polymeshcommittee_vote_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* committeemembership_set_active_members_limit_V2 - limit */;
            return _toStringMemberCount_V2(
                &m->nested.committeemembership_set_active_members_limit_V2.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        case 0: /* committeemembership_disable_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.committeemembership_disable_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_disable_member_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.committeemembership_disable_member_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* committeemembership_disable_member_V2 - at */;
            return _toStringOptionMoment_V2(
                &m->nested.committeemembership_disable_member_V2.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2562: /* module 10 call 2 */
        switch (itemIdx) {
        case 0: /* committeemembership_add_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.committeemembership_add_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2563: /* module 10 call 3 */
        switch (itemIdx) {
        case 0: /* committeemembership_remove_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.committeemembership_remove_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2564: /* module 10 call 4 */
        switch (itemIdx) {
        case 0: /* committeemembership_swap_member_V2 - remove */;
            return _toStringIdentityId_V2(
                &m->nested.committeemembership_swap_member_V2.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_swap_member_V2 - add */;
            return _toStringIdentityId_V2(
                &m->nested.committeemembership_swap_member_V2.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2565: /* module 10 call 5 */
        switch (itemIdx) {
        case 0: /* committeemembership_reset_members_V2 - members */;
            return _toStringVecIdentityId_V2(
                &m->nested.committeemembership_reset_members_V2.members,
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
        case 0: /* technicalcommittee_set_vote_threshold_V2 - n */;
            return _toStringu32(
                &m->nested.technicalcommittee_set_vote_threshold_V2.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_vote_threshold_V2 - d */;
            return _toStringu32(
                &m->nested.technicalcommittee_set_vote_threshold_V2.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2817: /* module 11 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_release_coordinator_V2 - id */;
            return _toStringIdentityId_V2(
                &m->nested.technicalcommittee_set_release_coordinator_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2818: /* module 11 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_expires_after_V2 - expiry */;
            return _toStringMaybeBlock_V2(
                &m->nested.technicalcommittee_set_expires_after_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2819: /* module 11 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_or_propose_V2 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_or_propose_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_or_propose_V2 - call */;
            return _toStringCall(
                &m->nested.technicalcommittee_vote_or_propose_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2820: /* module 11 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V2 - proposal */;
            return _toStringHash(
                &m->nested.technicalcommittee_vote_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V2 - index */;
            return _toStringProposalIndex_V2(
                &m->nested.technicalcommittee_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V2 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_set_active_members_limit_V2 - limit */;
            return _toStringMemberCount_V2(
                &m->nested.technicalcommitteemembership_set_active_members_limit_V2.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_disable_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.technicalcommitteemembership_disable_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_disable_member_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.technicalcommitteemembership_disable_member_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommitteemembership_disable_member_V2 - at */;
            return _toStringOptionMoment_V2(
                &m->nested.technicalcommitteemembership_disable_member_V2.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_add_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.technicalcommitteemembership_add_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3075: /* module 12 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_remove_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.technicalcommitteemembership_remove_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3076: /* module 12 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_swap_member_V2 - remove */;
            return _toStringIdentityId_V2(
                &m->nested.technicalcommitteemembership_swap_member_V2.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_swap_member_V2 - add */;
            return _toStringIdentityId_V2(
                &m->nested.technicalcommitteemembership_swap_member_V2.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3077: /* module 12 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_reset_members_V2 - members */;
            return _toStringVecIdentityId_V2(
                &m->nested.technicalcommitteemembership_reset_members_V2.members,
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
        case 0: /* upgradecommittee_set_vote_threshold_V2 - n */;
            return _toStringu32(
                &m->nested.upgradecommittee_set_vote_threshold_V2.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_set_vote_threshold_V2 - d */;
            return _toStringu32(
                &m->nested.upgradecommittee_set_vote_threshold_V2.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3329: /* module 13 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_release_coordinator_V2 - id */;
            return _toStringIdentityId_V2(
                &m->nested.upgradecommittee_set_release_coordinator_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3330: /* module 13 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_expires_after_V2 - expiry */;
            return _toStringMaybeBlock_V2(
                &m->nested.upgradecommittee_set_expires_after_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3331: /* module 13 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_or_propose_V2 - approve */;
            return _toStringbool(
                &m->nested.upgradecommittee_vote_or_propose_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_or_propose_V2 - call */;
            return _toStringCall(
                &m->nested.upgradecommittee_vote_or_propose_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3332: /* module 13 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_V2 - proposal */;
            return _toStringHash(
                &m->nested.upgradecommittee_vote_V2.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_V2 - index */;
            return _toStringProposalIndex_V2(
                &m->nested.upgradecommittee_vote_V2.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommittee_vote_V2 - approve */;
            return _toStringbool(
                &m->nested.upgradecommittee_vote_V2.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3584: /* module 14 call 0 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_set_active_members_limit_V2 - limit */;
            return _toStringMemberCount_V2(
                &m->nested.upgradecommitteemembership_set_active_members_limit_V2.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3585: /* module 14 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_disable_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.upgradecommitteemembership_disable_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_disable_member_V2 - expiry */;
            return _toStringOptionMoment_V2(
                &m->nested.upgradecommitteemembership_disable_member_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommitteemembership_disable_member_V2 - at */;
            return _toStringOptionMoment_V2(
                &m->nested.upgradecommitteemembership_disable_member_V2.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3586: /* module 14 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_add_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.upgradecommitteemembership_add_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3587: /* module 14 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_remove_member_V2 - who */;
            return _toStringIdentityId_V2(
                &m->nested.upgradecommitteemembership_remove_member_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3588: /* module 14 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_swap_member_V2 - remove */;
            return _toStringIdentityId_V2(
                &m->nested.upgradecommitteemembership_swap_member_V2.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_swap_member_V2 - add */;
            return _toStringIdentityId_V2(
                &m->nested.upgradecommitteemembership_swap_member_V2.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3589: /* module 14 call 5 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_reset_members_V2 - members */;
            return _toStringVecIdentityId_V2(
                &m->nested.upgradecommitteemembership_reset_members_V2.members,
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
    case 4096: /* module 16 call 0 */
        switch (itemIdx) {
        case 0: /* bridge_change_controller_V2 - controller */;
            return _toStringAccountId_V2(
                &m->nested.bridge_change_controller_V2.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4097: /* module 16 call 1 */
        switch (itemIdx) {
        case 0: /* bridge_change_admin_V2 - admin */;
            return _toStringAccountId_V2(
                &m->nested.bridge_change_admin_V2.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4098: /* module 16 call 2 */
        switch (itemIdx) {
        case 0: /* bridge_change_timelock_V2 - timelock */;
            return _toStringBlockNumber(
                &m->nested.bridge_change_timelock_V2.timelock,
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
        case 0: /* bridge_change_bridge_limit_V2 - amount */;
            return _toStringBalance(
                &m->nested.bridge_change_bridge_limit_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_change_bridge_limit_V2 - duration */;
            return _toStringBlockNumber(
                &m->nested.bridge_change_bridge_limit_V2.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4102: /* module 16 call 6 */
        switch (itemIdx) {
        case 0: /* bridge_change_bridge_exempted_V2 - exempted */;
            return _toStringVecTupleIdentityIdbool_V2(
                &m->nested.bridge_change_bridge_exempted_V2.exempted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4103: /* module 16 call 7 */
        switch (itemIdx) {
        case 0: /* bridge_force_handle_bridge_tx_V2 - bridge_tx */;
            return _toStringBridgeTx_V2(
                &m->basic.bridge_force_handle_bridge_tx_V2.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4104: /* module 16 call 8 */
        switch (itemIdx) {
        case 0: /* bridge_batch_propose_bridge_tx_V2 - bridge_txs */;
            return _toStringVecBridgeTx_V2(
                &m->basic.bridge_batch_propose_bridge_tx_V2.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4105: /* module 16 call 9 */
        switch (itemIdx) {
        case 0: /* bridge_propose_bridge_tx_V2 - bridge_tx */;
            return _toStringBridgeTx_V2(
                &m->basic.bridge_propose_bridge_tx_V2.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4106: /* module 16 call 10 */
        switch (itemIdx) {
        case 0: /* bridge_handle_bridge_tx_V2 - bridge_tx */;
            return _toStringBridgeTx_V2(
                &m->basic.bridge_handle_bridge_tx_V2.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4107: /* module 16 call 11 */
        switch (itemIdx) {
        case 0: /* bridge_freeze_txs_V2 - bridge_txs */;
            return _toStringVecBridgeTx_V2(
                &m->basic.bridge_freeze_txs_V2.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4108: /* module 16 call 12 */
        switch (itemIdx) {
        case 0: /* bridge_unfreeze_txs_V2 - bridge_txs */;
            return _toStringVecBridgeTx_V2(
                &m->basic.bridge_unfreeze_txs_V2.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4109: /* module 16 call 13 */
        switch (itemIdx) {
        case 0: /* bridge_handle_scheduled_bridge_tx_V2 - bridge_tx */;
            return _toStringBridgeTx_V2(
                &m->basic.bridge_handle_scheduled_bridge_tx_V2.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4110: /* module 16 call 14 */
        switch (itemIdx) {
        case 0: /* bridge_add_freeze_admin_V2 - freeze_admin */;
            return _toStringAccountId_V2(
                &m->basic.bridge_add_freeze_admin_V2.freeze_admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4111: /* module 16 call 15 */
        switch (itemIdx) {
        case 0: /* bridge_remove_freeze_admin_V2 - freeze_admin */;
            return _toStringAccountId_V2(
                &m->basic.bridge_remove_freeze_admin_V2.freeze_admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4112: /* module 16 call 16 */
        switch (itemIdx) {
        case 0: /* bridge_remove_txs_V2 - bridge_txs */;
            return _toStringVecBridgeTx_V2(
                &m->basic.bridge_remove_txs_V2.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4361: /* module 17 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V2 - new_ */;
            return _toStringCompactu32(
                &m->nested.staking_set_validator_count_V2.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4362: /* module 17 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V2 - additional */;
            return _toStringCompactu32(
                &m->nested.staking_increase_validator_count_V2.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4364: /* module 17 call 12 */
        switch (itemIdx) {
        case 0: /* staking_add_permissioned_validator_V2 - identity */;
            return _toStringIdentityId_V2(
                &m->nested.staking_add_permissioned_validator_V2.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_add_permissioned_validator_V2 - intended_count */;
            return _toStringOptionu32(
                &m->nested.staking_add_permissioned_validator_V2.intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4365: /* module 17 call 13 */
        switch (itemIdx) {
        case 0: /* staking_remove_permissioned_validator_V2 - identity */;
            return _toStringIdentityId_V2(
                &m->nested.staking_remove_permissioned_validator_V2.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4366: /* module 17 call 14 */
        switch (itemIdx) {
        case 0: /* staking_validate_cdd_expiry_nominators_V2 - targets */;
            return _toStringVecAccountId_V2(
                &m->nested.staking_validate_cdd_expiry_nominators_V2.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4367: /* module 17 call 15 */
        switch (itemIdx) {
        case 0: /* staking_set_commission_cap_V2 - new_cap */;
            return _toStringPerbill_V2(
                &m->nested.staking_set_commission_cap_V2.new_cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4368: /* module 17 call 16 */
        switch (itemIdx) {
        case 0: /* staking_set_min_bond_threshold_V2 - new_value */;
            return _toStringBalanceOf(
                &m->nested.staking_set_min_bond_threshold_V2.new_value,
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
        case 0: /* staking_set_invulnerables_V2 - invulnerables */;
            return _toStringVecAccountId_V2(
                &m->nested.staking_set_invulnerables_V2.invulnerables,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4372: /* module 17 call 20 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V2 - stash */;
            return _toStringAccountId_V2(
                &m->nested.staking_force_unstake_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_force_unstake_V2.num_slashing_spans,
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
        case 0: /* staking_cancel_deferred_slash_V2 - era */;
            return _toStringEraIndex_V2(
                &m->nested.staking_cancel_deferred_slash_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V2 - slash_indices */;
            return _toStringVecu32(
                &m->nested.staking_cancel_deferred_slash_V2.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4375: /* module 17 call 23 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V2 - validator_stash */;
            return _toStringAccountId_V2(
                &m->nested.staking_payout_stakers_V2.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V2 - era */;
            return _toStringEraIndex_V2(
                &m->nested.staking_payout_stakers_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4377: /* module 17 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V2 - new_history_depth */;
            return _toStringCompactEraIndex_V2(
                &m->nested.staking_set_history_depth_V2.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V2 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->nested.staking_set_history_depth_V2._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4378: /* module 17 call 26 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V2 - stash */;
            return _toStringAccountId_V2(
                &m->nested.staking_reap_stash_V2.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V2 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_reap_stash_V2.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4381: /* module 17 call 29 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_by_system_V2 - validator_stash */;
            return _toStringAccountId_V2(
                &m->nested.staking_payout_stakers_by_system_V2.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_by_system_V2 - era */;
            return _toStringEraIndex_V2(
                &m->nested.staking_payout_stakers_by_system_V2.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4382: /* module 17 call 30 */
        switch (itemIdx) {
        case 0: /* staking_change_slashing_allowed_for_V2 - slashing_switch */;
            return _toStringSlashingSwitch_V2(
                &m->nested.staking_change_slashing_allowed_for_V2.slashing_switch,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4383: /* module 17 call 31 */
        switch (itemIdx) {
        case 0: /* staking_update_permissioned_validator_intended_count_V2 - identity */;
            return _toStringIdentityId_V2(
                &m->nested.staking_update_permissioned_validator_intended_count_V2.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_update_permissioned_validator_intended_count_V2 - new_intended_count */;
            return _toStringu32(
                &m->nested.staking_update_permissioned_validator_intended_count_V2.new_intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4864: /* module 19 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V2 - keys */;
            return _toStringKeys_V2(
                &m->nested.session_set_keys_V2.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V2 - proof */;
            return _toStringBytes(
                &m->nested.session_set_keys_V2.proof,
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
    case 5378: /* module 21 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V2 - delay */;
            return _toStringBlockNumber(
                &m->nested.grandpa_note_stalled_V2.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V2 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->nested.grandpa_note_stalled_V2.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V2 - who */;
            return _toStringLookupSource_V2(
                &m->nested.sudo_sudo_as_V2.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V2 - call */;
            return _toStringCall(
                &m->nested.sudo_sudo_as_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* asset_register_ticker_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_register_ticker_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* asset_accept_ticker_transfer_V2 - auth_id */;
            return _toStringu64(
                &m->nested.asset_accept_ticker_transfer_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* asset_accept_asset_ownership_transfer_V2 - auth_id */;
            return _toStringu64(
                &m->nested.asset_accept_asset_ownership_transfer_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* asset_create_asset_V2 - name */;
            return _toStringAssetName_V2(
                &m->nested.asset_create_asset_V2.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_create_asset_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_create_asset_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_create_asset_V2 - divisible */;
            return _toStringbool(
                &m->nested.asset_create_asset_V2.divisible,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* asset_create_asset_V2 - asset_type */;
            return _toStringAssetType_V2(
                &m->nested.asset_create_asset_V2.asset_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* asset_create_asset_V2 - identifiers */;
            return _toStringVecAssetIdentifier_V2(
                &m->nested.asset_create_asset_V2.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* asset_create_asset_V2 - funding_round */;
            return _toStringOptionFundingRoundName_V2(
                &m->nested.asset_create_asset_V2.funding_round,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* asset_create_asset_V2 - disable_iu */;
            return _toStringbool(
                &m->nested.asset_create_asset_V2.disable_iu,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* asset_freeze_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_freeze_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* asset_unfreeze_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_unfreeze_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        case 0: /* asset_rename_asset_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_rename_asset_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_rename_asset_V2 - name */;
            return _toStringAssetName_V2(
                &m->nested.asset_rename_asset_V2.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6663: /* module 26 call 7 */
        switch (itemIdx) {
        case 0: /* asset_issue_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_issue_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_issue_V2 - amount */;
            return _toStringBalanceNoSymbol(
                &m->nested.asset_issue_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6664: /* module 26 call 8 */
        switch (itemIdx) {
        case 0: /* asset_redeem_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_redeem_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_redeem_V2 - amount */;
            return _toStringBalanceNoSymbol(
                &m->nested.asset_redeem_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6665: /* module 26 call 9 */
        switch (itemIdx) {
        case 0: /* asset_make_divisible_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_make_divisible_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6666: /* module 26 call 10 */
        switch (itemIdx) {
        case 0: /* asset_add_documents_V2 - docs */;
            return _toStringVecDocument_V2(
                &m->nested.asset_add_documents_V2.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_add_documents_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_add_documents_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6667: /* module 26 call 11 */
        switch (itemIdx) {
        case 0: /* asset_remove_documents_V2 - ids */;
            return _toStringVecDocumentId_V2(
                &m->nested.asset_remove_documents_V2.ids,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_documents_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_remove_documents_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6668: /* module 26 call 12 */
        switch (itemIdx) {
        case 0: /* asset_set_funding_round_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_set_funding_round_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_set_funding_round_V2 - name */;
            return _toStringFundingRoundName_V2(
                &m->nested.asset_set_funding_round_V2.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6669: /* module 26 call 13 */
        switch (itemIdx) {
        case 0: /* asset_update_identifiers_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_update_identifiers_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_update_identifiers_V2 - identifiers */;
            return _toStringVecAssetIdentifier_V2(
                &m->nested.asset_update_identifiers_V2.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6670: /* module 26 call 14 */
        switch (itemIdx) {
        case 0: /* asset_claim_classic_ticker_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.asset_claim_classic_ticker_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_claim_classic_ticker_V2 - ethereum_signature */;
            return _toStringEcdsaSignature_V2(
                &m->nested.asset_claim_classic_ticker_V2.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6671: /* module 26 call 15 */
        switch (itemIdx) {
        case 0: /* asset_reserve_classic_ticker_V2 - classic_ticker_import */;
            return _toStringClassicTickerImport_V2(
                &m->nested.asset_reserve_classic_ticker_V2.classic_ticker_import,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_reserve_classic_ticker_V2 - contract_did */;
            return _toStringIdentityId_V2(
                &m->nested.asset_reserve_classic_ticker_V2.contract_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_reserve_classic_ticker_V2 - config */;
            return _toStringTickerRegistrationConfig_V2(
                &m->nested.asset_reserve_classic_ticker_V2.config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6672: /* module 26 call 16 */
        switch (itemIdx) {
        case 0: /* asset_controller_transfer_V2 - ticker */;
            return _toStringTicker_V2(
                &m->basic.asset_controller_transfer_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_controller_transfer_V2 - amount */;
            return _toStringBalanceNoSymbol(
                &m->basic.asset_controller_transfer_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_controller_transfer_V2 - from_portfolio */;
            return _toStringPortfolioId_V2(
                &m->basic.asset_controller_transfer_V2.from_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6673: /* module 26 call 17 */
        switch (itemIdx) {
        case 0: /* asset_register_custom_asset_type_V2 - ty */;
            return _toStringBytes(
                &m->basic.asset_register_custom_asset_type_V2.ty,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_distribute_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.capitaldistribution_distribute_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_distribute_V2 - portfolio */;
            return _toStringOptionPortfolioNumber_V2(
                &m->nested.capitaldistribution_distribute_V2.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* capitaldistribution_distribute_V2 - currency */;
            return _toStringTicker_V2(
                &m->nested.capitaldistribution_distribute_V2.currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* capitaldistribution_distribute_V2 - per_share */;
            return _toStringBalance(
                &m->nested.capitaldistribution_distribute_V2.per_share,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* capitaldistribution_distribute_V2 - amount */;
            return _toStringBalance(
                &m->nested.capitaldistribution_distribute_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* capitaldistribution_distribute_V2 - payment_at */;
            return _toStringMoment_V2(
                &m->nested.capitaldistribution_distribute_V2.payment_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* capitaldistribution_distribute_V2 - expires_at */;
            return _toStringOptionMoment_V2(
                &m->nested.capitaldistribution_distribute_V2.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_claim_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.capitaldistribution_claim_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_push_benefit_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.capitaldistribution_push_benefit_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_push_benefit_V2 - holder */;
            return _toStringIdentityId_V2(
                &m->nested.capitaldistribution_push_benefit_V2.holder,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_reclaim_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.capitaldistribution_reclaim_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_remove_distribution_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.capitaldistribution_remove_distribution_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_checkpoint_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.checkpoint_create_checkpoint_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* checkpoint_set_schedules_max_complexity_V2 - max_complexity */;
            return _toStringu64(
                &m->nested.checkpoint_set_schedules_max_complexity_V2.max_complexity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_schedule_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.checkpoint_create_schedule_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_create_schedule_V2 - schedule */;
            return _toStringScheduleSpec_V2(
                &m->nested.checkpoint_create_schedule_V2.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* checkpoint_remove_schedule_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.checkpoint_remove_schedule_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_remove_schedule_V2 - id */;
            return _toStringScheduleId_V2(
                &m->nested.checkpoint_remove_schedule_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_compliance_requirement_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_add_compliance_requirement_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_compliance_requirement_V2 - sender_conditions */;
            return _toStringVecCondition_V2(
                &m->nested.compliancemanager_add_compliance_requirement_V2.sender_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* compliancemanager_add_compliance_requirement_V2 - receiver_conditions */;
            return _toStringVecCondition_V2(
                &m->nested.compliancemanager_add_compliance_requirement_V2.receiver_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_compliance_requirement_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_remove_compliance_requirement_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_compliance_requirement_V2 - id */;
            return _toStringu32(
                &m->nested.compliancemanager_remove_compliance_requirement_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* compliancemanager_replace_asset_compliance_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_replace_asset_compliance_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_replace_asset_compliance_V2 - asset_compliance */;
            return _toStringVecComplianceRequirement_V2(
                &m->nested.compliancemanager_replace_asset_compliance_V2.asset_compliance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* compliancemanager_reset_asset_compliance_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_reset_asset_compliance_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* compliancemanager_pause_asset_compliance_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_pause_asset_compliance_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* compliancemanager_resume_asset_compliance_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_resume_asset_compliance_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_default_trusted_claim_issuer_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_add_default_trusted_claim_issuer_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_default_trusted_claim_issuer_V2 - issuer */;
            return _toStringTrustedIssuer_V2(
                &m->nested.compliancemanager_add_default_trusted_claim_issuer_V2.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_default_trusted_claim_issuer_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_remove_default_trusted_claim_issuer_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_default_trusted_claim_issuer_V2 - issuer */;
            return _toStringIdentityId_V2(
                &m->nested.compliancemanager_remove_default_trusted_claim_issuer_V2.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0: /* compliancemanager_change_compliance_requirement_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.compliancemanager_change_compliance_requirement_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_change_compliance_requirement_V2 - new_req */;
            return _toStringComplianceRequirement_V2(
                &m->nested.compliancemanager_change_compliance_requirement_V2.new_req,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7680: /* module 30 call 0 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_max_details_length_V2 - length */;
            return _toStringu32(
                &m->nested.corporateaction_set_max_details_length_V2.length,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7681: /* module 30 call 1 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_targets_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.corporateaction_set_default_targets_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_targets_V2 - targets */;
            return _toStringTargetIdentities_V2(
                &m->nested.corporateaction_set_default_targets_V2.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7682: /* module 30 call 2 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_withholding_tax_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.corporateaction_set_default_withholding_tax_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_withholding_tax_V2 - tax */;
            return _toStringTax_V2(
                &m->nested.corporateaction_set_default_withholding_tax_V2.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7683: /* module 30 call 3 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_did_withholding_tax_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.corporateaction_set_did_withholding_tax_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_did_withholding_tax_V2 - taxed_did */;
            return _toStringIdentityId_V2(
                &m->nested.corporateaction_set_did_withholding_tax_V2.taxed_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_set_did_withholding_tax_V2 - tax */;
            return _toStringOptionTax_V2(
                &m->nested.corporateaction_set_did_withholding_tax_V2.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7684: /* module 30 call 4 */
        switch (itemIdx) {
        case 0: /* corporateaction_initiate_corporate_action_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_initiate_corporate_action_V2 - kind */;
            return _toStringCAKind_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_initiate_corporate_action_V2 - decl_date */;
            return _toStringMoment_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.decl_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateaction_initiate_corporate_action_V2 - record_date */;
            return _toStringOptionRecordDateSpec_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* corporateaction_initiate_corporate_action_V2 - details */;
            return _toStringCADetails_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* corporateaction_initiate_corporate_action_V2 - targets */;
            return _toStringOptionTargetIdentities_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* corporateaction_initiate_corporate_action_V2 - default_withholding_tax */;
            return _toStringOptionTax_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.default_withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* corporateaction_initiate_corporate_action_V2 - withholding_tax */;
            return _toStringOptionVecTupleIdentityIdTax_V2(
                &m->nested.corporateaction_initiate_corporate_action_V2.withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7685: /* module 30 call 5 */
        switch (itemIdx) {
        case 0: /* corporateaction_link_ca_doc_V2 - id */;
            return _toStringCAId_V2(
                &m->nested.corporateaction_link_ca_doc_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_link_ca_doc_V2 - docs */;
            return _toStringVecDocumentId_V2(
                &m->nested.corporateaction_link_ca_doc_V2.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7686: /* module 30 call 6 */
        switch (itemIdx) {
        case 0: /* corporateaction_remove_ca_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateaction_remove_ca_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7687: /* module 30 call 7 */
        switch (itemIdx) {
        case 0: /* corporateaction_change_record_date_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateaction_change_record_date_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_change_record_date_V2 - record_date */;
            return _toStringOptionRecordDateSpec_V2(
                &m->nested.corporateaction_change_record_date_V2.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* corporateballot_attach_ballot_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateballot_attach_ballot_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_attach_ballot_V2 - range */;
            return _toStringBallotTimeRange_V2(
                &m->nested.corporateballot_attach_ballot_V2.range,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateballot_attach_ballot_V2 - meta */;
            return _toStringBallotMeta_V2(
                &m->nested.corporateballot_attach_ballot_V2.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateballot_attach_ballot_V2 - rcv */;
            return _toStringbool(
                &m->nested.corporateballot_attach_ballot_V2.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* corporateballot_vote_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateballot_vote_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_vote_V2 - votes */;
            return _toStringVecBallotVote_V2(
                &m->nested.corporateballot_vote_V2.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_end_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateballot_change_end_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_end_V2 - end */;
            return _toStringMoment_V2(
                &m->nested.corporateballot_change_end_V2.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_meta_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateballot_change_meta_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_meta_V2 - meta */;
            return _toStringBallotMeta_V2(
                &m->nested.corporateballot_change_meta_V2.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_rcv_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateballot_change_rcv_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_rcv_V2 - rcv */;
            return _toStringbool(
                &m->nested.corporateballot_change_rcv_V2.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0: /* corporateballot_remove_ballot_V2 - ca_id */;
            return _toStringCAId_V2(
                &m->nested.corporateballot_remove_ballot_V2.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8448: /* module 33 call 0 */
        switch (itemIdx) {
        case 0: /* pips_set_prune_historical_pips_V2 - prune */;
            return _toStringbool(
                &m->nested.pips_set_prune_historical_pips_V2.prune,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8449: /* module 33 call 1 */
        switch (itemIdx) {
        case 0: /* pips_set_min_proposal_deposit_V2 - deposit */;
            return _toStringBalance(
                &m->nested.pips_set_min_proposal_deposit_V2.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8450: /* module 33 call 2 */
        switch (itemIdx) {
        case 0: /* pips_set_default_enactment_period_V2 - duration */;
            return _toStringBlockNumber(
                &m->nested.pips_set_default_enactment_period_V2.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8451: /* module 33 call 3 */
        switch (itemIdx) {
        case 0: /* pips_set_pending_pip_expiry_V2 - expiry */;
            return _toStringMaybeBlock_V2(
                &m->nested.pips_set_pending_pip_expiry_V2.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8452: /* module 33 call 4 */
        switch (itemIdx) {
        case 0: /* pips_set_max_pip_skip_count_V2 - max */;
            return _toStringSkippedCount_V2(
                &m->nested.pips_set_max_pip_skip_count_V2.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8453: /* module 33 call 5 */
        switch (itemIdx) {
        case 0: /* pips_set_active_pip_limit_V2 - limit */;
            return _toStringu32(
                &m->nested.pips_set_active_pip_limit_V2.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8456: /* module 33 call 8 */
        switch (itemIdx) {
        case 0: /* pips_approve_committee_proposal_V2 - id */;
            return _toStringPipId_V2(
                &m->nested.pips_approve_committee_proposal_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8457: /* module 33 call 9 */
        switch (itemIdx) {
        case 0: /* pips_reject_proposal_V2 - id */;
            return _toStringPipId_V2(
                &m->nested.pips_reject_proposal_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8458: /* module 33 call 10 */
        switch (itemIdx) {
        case 0: /* pips_prune_proposal_V2 - id */;
            return _toStringPipId_V2(
                &m->nested.pips_prune_proposal_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8459: /* module 33 call 11 */
        switch (itemIdx) {
        case 0: /* pips_reschedule_execution_V2 - id */;
            return _toStringPipId_V2(
                &m->nested.pips_reschedule_execution_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_reschedule_execution_V2 - until */;
            return _toStringOptionBlockNumber(
                &m->nested.pips_reschedule_execution_V2.until,
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
    case 8462: /* module 33 call 14 */
        switch (itemIdx) {
        case 0: /* pips_enact_snapshot_results_V2 - results */;
            return _toStringVecTuplePipIdSnapshotResult_V2(
                &m->nested.pips_enact_snapshot_results_V2.results,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8463: /* module 33 call 15 */
        switch (itemIdx) {
        case 0: /* pips_execute_scheduled_pip_V2 - id */;
            return _toStringPipId_V2(
                &m->nested.pips_execute_scheduled_pip_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8464: /* module 33 call 16 */
        switch (itemIdx) {
        case 0: /* pips_expire_scheduled_pip_V2 - did */;
            return _toStringIdentityId_V2(
                &m->nested.pips_expire_scheduled_pip_V2.did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_expire_scheduled_pip_V2 - id */;
            return _toStringPipId_V2(
                &m->nested.pips_expire_scheduled_pip_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8704: /* module 34 call 0 */
        switch (itemIdx) {
        case 0: /* portfolio_create_portfolio_V2 - name */;
            return _toStringPortfolioName_V2(
                &m->nested.portfolio_create_portfolio_V2.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8705: /* module 34 call 1 */
        switch (itemIdx) {
        case 0: /* portfolio_delete_portfolio_V2 - num */;
            return _toStringPortfolioNumber_V2(
                &m->nested.portfolio_delete_portfolio_V2.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8706: /* module 34 call 2 */
        switch (itemIdx) {
        case 0: /* portfolio_move_portfolio_funds_V2 - from */;
            return _toStringPortfolioId_V2(
                &m->nested.portfolio_move_portfolio_funds_V2.from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_move_portfolio_funds_V2 - to */;
            return _toStringPortfolioId_V2(
                &m->nested.portfolio_move_portfolio_funds_V2.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* portfolio_move_portfolio_funds_V2 - items */;
            return _toStringVecMovePortfolioItem_V2(
                &m->nested.portfolio_move_portfolio_funds_V2.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8707: /* module 34 call 3 */
        switch (itemIdx) {
        case 0: /* portfolio_rename_portfolio_V2 - num */;
            return _toStringPortfolioNumber_V2(
                &m->nested.portfolio_rename_portfolio_V2.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_rename_portfolio_V2 - to_name */;
            return _toStringPortfolioName_V2(
                &m->nested.portfolio_rename_portfolio_V2.to_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8708: /* module 34 call 4 */
        switch (itemIdx) {
        case 0: /* portfolio_quit_portfolio_custody_V2 - pid */;
            return _toStringPortfolioId_V2(
                &m->basic.portfolio_quit_portfolio_custody_V2.pid,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8709: /* module 34 call 5 */
        switch (itemIdx) {
        case 0: /* portfolio_accept_portfolio_custody_V2 - auth_id */;
            return _toStringu64(
                &m->basic.portfolio_accept_portfolio_custody_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8960: /* module 35 call 0 */
        switch (itemIdx) {
        case 0: /* protocolfee_change_coefficient_V2 - coefficient */;
            return _toStringPosRatio_V2(
                &m->nested.protocolfee_change_coefficient_V2.coefficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* settlement_create_venue_V2 - details */;
            return _toStringVenueDetails_V2(
                &m->nested.settlement_create_venue_V2.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_create_venue_V2 - signers */;
            return _toStringVecAccountId_V2(
                &m->nested.settlement_create_venue_V2.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_create_venue_V2 - typ */;
            return _toStringVenueType_V2(
                &m->nested.settlement_create_venue_V2.typ,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* settlement_update_venue_details_V2 - id */;
            return _toStringVenueId_V2(
                &m->basic.settlement_update_venue_details_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_update_venue_details_V2 - details */;
            return _toStringVenueDetails_V2(
                &m->basic.settlement_update_venue_details_V2.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0: /* settlement_update_venue_type_V2 - id */;
            return _toStringVenueId_V2(
                &m->basic.settlement_update_venue_type_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_update_venue_type_V2 - typ */;
            return _toStringVenueType_V2(
                &m->basic.settlement_update_venue_type_V2.typ,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* settlement_add_instruction_V2 - venue_id */;
            return _toStringVenueId_V2(
                &m->nested.settlement_add_instruction_V2.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_instruction_V2 - settlement_type */;
            return _toStringSettlementType_V2(
                &m->nested.settlement_add_instruction_V2.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_instruction_V2 - trade_date */;
            return _toStringOptionMoment_V2(
                &m->nested.settlement_add_instruction_V2.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_instruction_V2 - value_date */;
            return _toStringOptionMoment_V2(
                &m->nested.settlement_add_instruction_V2.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_instruction_V2 - legs */;
            return _toStringVecLeg_V2(
                &m->nested.settlement_add_instruction_V2.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* settlement_add_and_affirm_instruction_V2 - venue_id */;
            return _toStringVenueId_V2(
                &m->nested.settlement_add_and_affirm_instruction_V2.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_and_affirm_instruction_V2 - settlement_type */;
            return _toStringSettlementType_V2(
                &m->nested.settlement_add_and_affirm_instruction_V2.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_and_affirm_instruction_V2 - trade_date */;
            return _toStringOptionMoment_V2(
                &m->nested.settlement_add_and_affirm_instruction_V2.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_and_affirm_instruction_V2 - value_date */;
            return _toStringOptionMoment_V2(
                &m->nested.settlement_add_and_affirm_instruction_V2.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_and_affirm_instruction_V2 - legs */;
            return _toStringVecLeg_V2(
                &m->nested.settlement_add_and_affirm_instruction_V2.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_add_and_affirm_instruction_V2 - portfolios */;
            return _toStringVecPortfolioId_V2(
                &m->nested.settlement_add_and_affirm_instruction_V2.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_instruction_V2 - id */;
            return _toStringInstructionId_V2(
                &m->nested.settlement_affirm_instruction_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_instruction_V2 - portfolios */;
            return _toStringVecPortfolioId_V2(
                &m->nested.settlement_affirm_instruction_V2.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_instruction_V2 - max_legs_count */;
            return _toStringu32(
                &m->nested.settlement_affirm_instruction_V2.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9478: /* module 37 call 6 */
        switch (itemIdx) {
        case 0: /* settlement_withdraw_affirmation_V2 - id */;
            return _toStringInstructionId_V2(
                &m->nested.settlement_withdraw_affirmation_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_withdraw_affirmation_V2 - portfolios */;
            return _toStringVecPortfolioId_V2(
                &m->nested.settlement_withdraw_affirmation_V2.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_withdraw_affirmation_V2 - max_legs_count */;
            return _toStringu32(
                &m->nested.settlement_withdraw_affirmation_V2.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9479: /* module 37 call 7 */
        switch (itemIdx) {
        case 0: /* settlement_reject_instruction_V2 - id */;
            return _toStringInstructionId_V2(
                &m->nested.settlement_reject_instruction_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_reject_instruction_V2 - portfolio */;
            return _toStringPortfolioId_V2(
                &m->nested.settlement_reject_instruction_V2.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_reject_instruction_V2 - num_of_legs */;
            return _toStringu32(
                &m->nested.settlement_reject_instruction_V2.num_of_legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9480: /* module 37 call 8 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_with_receipts_V2 - id */;
            return _toStringInstructionId_V2(
                &m->nested.settlement_affirm_with_receipts_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_with_receipts_V2 - receipt_details */;
            return _toStringVecReceiptDetails_V2(
                &m->nested.settlement_affirm_with_receipts_V2.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_with_receipts_V2 - portfolios */;
            return _toStringVecPortfolioId_V2(
                &m->nested.settlement_affirm_with_receipts_V2.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_affirm_with_receipts_V2 - max_legs_count */;
            return _toStringu32(
                &m->nested.settlement_affirm_with_receipts_V2.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9481: /* module 37 call 9 */
        switch (itemIdx) {
        case 0: /* settlement_claim_receipt_V2 - id */;
            return _toStringInstructionId_V2(
                &m->nested.settlement_claim_receipt_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_claim_receipt_V2 - receipt_details */;
            return _toStringReceiptDetails_V2(
                &m->nested.settlement_claim_receipt_V2.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9482: /* module 37 call 10 */
        switch (itemIdx) {
        case 0: /* settlement_unclaim_receipt_V2 - instruction_id */;
            return _toStringInstructionId_V2(
                &m->nested.settlement_unclaim_receipt_V2.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_unclaim_receipt_V2 - leg_id */;
            return _toStringLegId_V2(
                &m->nested.settlement_unclaim_receipt_V2.leg_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9483: /* module 37 call 11 */
        switch (itemIdx) {
        case 0: /* settlement_set_venue_filtering_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.settlement_set_venue_filtering_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_set_venue_filtering_V2 - enabled */;
            return _toStringbool(
                &m->nested.settlement_set_venue_filtering_V2.enabled,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9484: /* module 37 call 12 */
        switch (itemIdx) {
        case 0: /* settlement_allow_venues_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.settlement_allow_venues_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_allow_venues_V2 - venues */;
            return _toStringVecVenueId_V2(
                &m->nested.settlement_allow_venues_V2.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9485: /* module 37 call 13 */
        switch (itemIdx) {
        case 0: /* settlement_disallow_venues_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.settlement_disallow_venues_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_disallow_venues_V2 - venues */;
            return _toStringVecVenueId_V2(
                &m->nested.settlement_disallow_venues_V2.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9486: /* module 37 call 14 */
        switch (itemIdx) {
        case 0: /* settlement_change_receipt_validity_V2 - receipt_uid */;
            return _toStringu64(
                &m->basic.settlement_change_receipt_validity_V2.receipt_uid,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_change_receipt_validity_V2 - validity */;
            return _toStringbool(
                &m->basic.settlement_change_receipt_validity_V2.validity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9487: /* module 37 call 15 */
        switch (itemIdx) {
        case 0: /* settlement_execute_scheduled_instruction_V2 - id */;
            return _toStringInstructionId_V2(
                &m->nested.settlement_execute_scheduled_instruction_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_execute_scheduled_instruction_V2 - _legs_count */;
            return _toStringu32(
                &m->nested.settlement_execute_scheduled_instruction_V2._legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9488: /* module 37 call 16 */
        switch (itemIdx) {
        case 0: /* settlement_reschedule_instruction_V2 - id */;
            return _toStringInstructionId_V2(
                &m->basic.settlement_reschedule_instruction_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* statistics_add_transfer_manager_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.statistics_add_transfer_manager_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_add_transfer_manager_V2 - new_transfer_manager */;
            return _toStringTransferManager_V2(
                &m->nested.statistics_add_transfer_manager_V2.new_transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* statistics_remove_transfer_manager_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.statistics_remove_transfer_manager_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_remove_transfer_manager_V2 - transfer_manager */;
            return _toStringTransferManager_V2(
                &m->nested.statistics_remove_transfer_manager_V2.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0: /* statistics_add_exempted_entities_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.statistics_add_exempted_entities_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_add_exempted_entities_V2 - transfer_manager */;
            return _toStringTransferManager_V2(
                &m->nested.statistics_add_exempted_entities_V2.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* statistics_add_exempted_entities_V2 - exempted_entities */;
            return _toStringVecScopeId_V2(
                &m->nested.statistics_add_exempted_entities_V2.exempted_entities,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* statistics_remove_exempted_entities_V2 - ticker */;
            return _toStringTicker_V2(
                &m->nested.statistics_remove_exempted_entities_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_remove_exempted_entities_V2 - transfer_manager */;
            return _toStringTransferManager_V2(
                &m->nested.statistics_remove_exempted_entities_V2.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* statistics_remove_exempted_entities_V2 - entities */;
            return _toStringVecScopeId_V2(
                &m->nested.statistics_remove_exempted_entities_V2.entities,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0: /* sto_create_fundraiser_V2 - offering_portfolio */;
            return _toStringPortfolioId_V2(
                &m->basic.sto_create_fundraiser_V2.offering_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_create_fundraiser_V2 - offering_asset */;
            return _toStringTicker_V2(
                &m->basic.sto_create_fundraiser_V2.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_create_fundraiser_V2 - raising_portfolio */;
            return _toStringPortfolioId_V2(
                &m->basic.sto_create_fundraiser_V2.raising_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_create_fundraiser_V2 - raising_asset */;
            return _toStringTicker_V2(
                &m->basic.sto_create_fundraiser_V2.raising_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_create_fundraiser_V2 - tiers */;
            return _toStringVecPriceTier_V2(
                &m->basic.sto_create_fundraiser_V2.tiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_create_fundraiser_V2 - venue_id */;
            return _toStringVenueId_V2(
                &m->basic.sto_create_fundraiser_V2.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_create_fundraiser_V2 - start */;
            return _toStringOptionMoment_V2(
                &m->basic.sto_create_fundraiser_V2.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* sto_create_fundraiser_V2 - end */;
            return _toStringOptionMoment_V2(
                &m->basic.sto_create_fundraiser_V2.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 8: /* sto_create_fundraiser_V2 - minimum_investment */;
            return _toStringBalanceNoSymbol(
                &m->basic.sto_create_fundraiser_V2.minimum_investment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 9: /* sto_create_fundraiser_V2 - fundraiser_name */;
            return _toStringFundraiserName_V2(
                &m->basic.sto_create_fundraiser_V2.fundraiser_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0: /* sto_invest_V2 - investment_portfolio */;
            return _toStringPortfolioId_V2(
                &m->basic.sto_invest_V2.investment_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_invest_V2 - funding_portfolio */;
            return _toStringPortfolioId_V2(
                &m->basic.sto_invest_V2.funding_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_invest_V2 - offering_asset */;
            return _toStringTicker_V2(
                &m->basic.sto_invest_V2.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_invest_V2 - id */;
            return _toStringFundraiserId_V2(
                &m->basic.sto_invest_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_invest_V2 - purchase_amount */;
            return _toStringBalanceNoSymbol(
                &m->basic.sto_invest_V2.purchase_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_invest_V2 - max_price */;
            return _toStringOptionBalance(
                &m->basic.sto_invest_V2.max_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_invest_V2 - receipt */;
            return _toStringOptionReceiptDetails_V2(
                &m->basic.sto_invest_V2.receipt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9986: /* module 39 call 2 */
        switch (itemIdx) {
        case 0: /* sto_freeze_fundraiser_V2 - offering_asset */;
            return _toStringTicker_V2(
                &m->basic.sto_freeze_fundraiser_V2.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_freeze_fundraiser_V2 - id */;
            return _toStringFundraiserId_V2(
                &m->basic.sto_freeze_fundraiser_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9987: /* module 39 call 3 */
        switch (itemIdx) {
        case 0: /* sto_unfreeze_fundraiser_V2 - offering_asset */;
            return _toStringTicker_V2(
                &m->basic.sto_unfreeze_fundraiser_V2.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_unfreeze_fundraiser_V2 - id */;
            return _toStringFundraiserId_V2(
                &m->basic.sto_unfreeze_fundraiser_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9988: /* module 39 call 4 */
        switch (itemIdx) {
        case 0: /* sto_modify_fundraiser_window_V2 - offering_asset */;
            return _toStringTicker_V2(
                &m->basic.sto_modify_fundraiser_window_V2.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_modify_fundraiser_window_V2 - id */;
            return _toStringFundraiserId_V2(
                &m->basic.sto_modify_fundraiser_window_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_modify_fundraiser_window_V2 - start */;
            return _toStringMoment_V2(
                &m->basic.sto_modify_fundraiser_window_V2.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_modify_fundraiser_window_V2 - end */;
            return _toStringOptionMoment_V2(
                &m->basic.sto_modify_fundraiser_window_V2.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9989: /* module 39 call 5 */
        switch (itemIdx) {
        case 0: /* sto_stop_V2 - offering_asset */;
            return _toStringTicker_V2(
                &m->basic.sto_stop_V2.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_stop_V2 - id */;
            return _toStringFundraiserId_V2(
                &m->basic.sto_stop_V2.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_disbursement_V2 - beneficiaries */;
            return _toStringVecBeneficiary_V2(
                &m->nested.treasury_disbursement_V2.beneficiaries,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reimbursement_V2 - amount */;
            return _toStringBalanceOf(
                &m->nested.treasury_reimbursement_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* utility_relay_tx_V2 - target */;
            return _toStringAccountId_V2(
                &m->nested.utility_relay_tx_V2.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_relay_tx_V2 - signature */;
            return _toStringOffChainSignature_V2(
                &m->nested.utility_relay_tx_V2.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* utility_relay_tx_V2 - call */;
            return _toStringUniqueCall_V2(
                &m->nested.utility_relay_tx_V2.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11010: /* module 43 call 2 */
        switch (itemIdx) {
        case 0: /* externalagents_remove_agent_V2 - ticker */;
            return _toStringTicker_V2(
                &m->basic.externalagents_remove_agent_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* externalagents_remove_agent_V2 - agent */;
            return _toStringIdentityId_V2(
                &m->basic.externalagents_remove_agent_V2.agent,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11011: /* module 43 call 3 */
        switch (itemIdx) {
        case 0: /* externalagents_abdicate_V2 - ticker */;
            return _toStringTicker_V2(
                &m->basic.externalagents_abdicate_V2.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11013: /* module 43 call 5 */
        switch (itemIdx) {
        case 0: /* externalagents_accept_become_agent_V2 - auth_id */;
            return _toStringu64(
                &m->basic.externalagents_accept_become_agent_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11264: /* module 44 call 0 */
        switch (itemIdx) {
        case 0: /* relayer_set_paying_key_V2 - user_key */;
            return _toStringAccountId_V2(
                &m->basic.relayer_set_paying_key_V2.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_set_paying_key_V2 - polyx_limit */;
            return _toStringBalance(
                &m->basic.relayer_set_paying_key_V2.polyx_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11265: /* module 44 call 1 */
        switch (itemIdx) {
        case 0: /* relayer_accept_paying_key_V2 - auth_id */;
            return _toStringu64(
                &m->basic.relayer_accept_paying_key_V2.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11266: /* module 44 call 2 */
        switch (itemIdx) {
        case 0: /* relayer_remove_paying_key_V2 - user_key */;
            return _toStringAccountId_V2(
                &m->basic.relayer_remove_paying_key_V2.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_remove_paying_key_V2 - paying_key */;
            return _toStringAccountId_V2(
                &m->basic.relayer_remove_paying_key_V2.paying_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11267: /* module 44 call 3 */
        switch (itemIdx) {
        case 0: /* relayer_update_polyx_limit_V2 - user_key */;
            return _toStringAccountId_V2(
                &m->basic.relayer_update_polyx_limit_V2.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_update_polyx_limit_V2 - polyx_limit */;
            return _toStringBalance(
                &m->basic.relayer_update_polyx_limit_V2.polyx_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11268: /* module 44 call 4 */
        switch (itemIdx) {
        case 0: /* relayer_increase_polyx_limit_V2 - user_key */;
            return _toStringAccountId_V2(
                &m->basic.relayer_increase_polyx_limit_V2.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_increase_polyx_limit_V2 - amount */;
            return _toStringBalance(
                &m->basic.relayer_increase_polyx_limit_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11269: /* module 44 call 5 */
        switch (itemIdx) {
        case 0: /* relayer_decrease_polyx_limit_V2 - user_key */;
            return _toStringAccountId_V2(
                &m->basic.relayer_decrease_polyx_limit_V2.user_key,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* relayer_decrease_polyx_limit_V2 - amount */;
            return _toStringBalance(
                &m->basic.relayer_decrease_polyx_limit_V2.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0: /* rewards_claim_itn_reward_V2 - reward_address */;
            return _toStringAccountId_V2(
                &m->basic.rewards_claim_itn_reward_V2.reward_address,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* rewards_claim_itn_reward_V2 - itn_address */;
            return _toStringAccountId_V2(
                &m->basic.rewards_claim_itn_reward_V2.itn_address,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* rewards_claim_itn_reward_V2 - signature */;
            return _toStringOffChainSignature_V2(
                &m->basic.rewards_claim_itn_reward_V2.signature,
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

bool _getMethod_ItemIsExpert_V2(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
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

bool _getMethod_IsNestingSupported_V2(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1812: // Identity:Revoke claim by index
    case 1813: // Identity:Rotate primary key to secondary
    case 4103: // Bridge:Force handle bridge tx
    case 4104: // Bridge:Batch propose bridge tx
    case 4105: // Bridge:Propose bridge tx
    case 4106: // Bridge:Handle bridge tx
    case 4107: // Bridge:Freeze txs
    case 4108: // Bridge:Unfreeze txs
    case 4109: // Bridge:Handle scheduled bridge tx
    case 4110: // Bridge:Add freeze admin
    case 4111: // Bridge:Remove freeze admin
    case 4112: // Bridge:Remove txs
    case 6672: // Asset:Controller transfer
    case 6673: // Asset:Register custom asset type
    case 8708: // Portfolio:Quit portfolio custody
    case 8709: // Portfolio:Accept portfolio custody
    case 9473: // Settlement:Update venue details
    case 9474: // Settlement:Update venue type
    case 9486: // Settlement:Change receipt validity
    case 9488: // Settlement:Reschedule instruction
    case 9984: // Sto:Create fundraiser
    case 9985: // Sto:Invest
    case 9986: // Sto:Freeze fundraiser
    case 9987: // Sto:Unfreeze fundraiser
    case 9988: // Sto:Modify fundraiser window
    case 9989: // Sto:Stop
    case 11010: // ExternalAgents:Remove agent
    case 11011: // ExternalAgents:Abdicate
    case 11013: // ExternalAgents:Accept become agent
    case 11264: // Relayer:Set paying key
    case 11265: // Relayer:Accept paying key
    case 11266: // Relayer:Remove paying key
    case 11267: // Relayer:Update polyx limit
    case 11268: // Relayer:Increase polyx limit
    case 11269: // Relayer:Decrease polyx limit
    case 11520: // Rewards:Claim itn reward
        return false;
    default:
        return true;
    }
}
#endif
