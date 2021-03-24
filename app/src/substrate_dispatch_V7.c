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

#include "substrate_dispatch_V7.h"
#include "substrate_strings.h"
#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t _readMethod_balances_transfer_V7(
    parser_context_t* c, pd_balances_transfer_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_with_memo_V7(
    parser_context_t* c, pd_balances_transfer_with_memo_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    CHECK_ERROR(_readOptionMemo_V7(c, &m->memo))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_secondary_keys_V7(
    parser_context_t* c, pd_identity_remove_secondary_keys_V7_t* m)
{
    CHECK_ERROR(_readVecSignatory_V7(c, &m->signers_to_remove))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_primary_key_V7(
    parser_context_t* c, pd_identity_accept_primary_key_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->rotation_auth_id))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_key_V7(
    parser_context_t* c, pd_identity_join_identity_as_key_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_identity_V7(
    parser_context_t* c, pd_identity_join_identity_as_identity_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_key_V7(
    parser_context_t* c, pd_identity_leave_identity_as_key_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_identity_V7(
    parser_context_t* c, pd_identity_leave_identity_as_identity_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->did))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_claim_V7(
    parser_context_t* c, pd_identity_add_claim_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->target))
    CHECK_ERROR(_readClaim_V7(c, &m->claim))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_claim_V7(
    parser_context_t* c, pd_identity_revoke_claim_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->target))
    CHECK_ERROR(_readClaim_V7(c, &m->claim))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_permission_to_signer_V7(
    parser_context_t* c, pd_identity_set_permission_to_signer_V7_t* m)
{
    CHECK_ERROR(_readSignatory_V7(c, &m->signer))
    CHECK_ERROR(_readPermissions_V7(c, &m->permissions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_legacy_set_permission_to_signer_V7(
    parser_context_t* c, pd_identity_legacy_set_permission_to_signer_V7_t* m)
{
    CHECK_ERROR(_readSignatory_V7(c, &m->signer))
    CHECK_ERROR(_readLegacyPermissions_V7(c, &m->permissions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_freeze_secondary_keys_V7(
    parser_context_t* c, pd_identity_freeze_secondary_keys_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_unfreeze_secondary_keys_V7(
    parser_context_t* c, pd_identity_unfreeze_secondary_keys_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_authorization_V7(
    parser_context_t* c, pd_identity_add_authorization_V7_t* m)
{
    CHECK_ERROR(_readSignatory_V7(c, &m->target))
    CHECK_ERROR(_readAuthorizationData_V7(c, &m->authorization_data))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_authorization_V7(
    parser_context_t* c, pd_identity_remove_authorization_V7_t* m)
{
    CHECK_ERROR(_readSignatory_V7(c, &m->target))
    CHECK_ERROR(_readu64(c, &m->auth_id))
    CHECK_ERROR(_readbool(c, &m->_auth_issuer_pays))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_authorization_V7(
    parser_context_t* c, pd_identity_accept_authorization_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_secondary_keys_with_authorization_V7(
    parser_context_t* c, pd_identity_add_secondary_keys_with_authorization_V7_t* m)
{
    CHECK_ERROR(_readVecSecondaryKeyWithAuth_V7(c, &m->additional_keys))
    CHECK_ERROR(_readMoment_V7(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_investor_uniqueness_claim_V7(
    parser_context_t* c, pd_identity_add_investor_uniqueness_claim_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->target))
    CHECK_ERROR(_readClaim_V7(c, &m->claim))
    CHECK_ERROR(_readInvestorZKProofData_V7(c, &m->proof))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_V7(
    parser_context_t* c, pd_staking_bond_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->controller))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readRewardDestination_V7(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra_V7(
    parser_context_t* c, pd_staking_bond_extra_V7_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond_V7(
    parser_context_t* c, pd_staking_unbond_V7_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded_V7(
    parser_context_t* c, pd_staking_withdraw_unbonded_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_V7(
    parser_context_t* c, pd_staking_validate_V7_t* m)
{
    CHECK_ERROR(_readValidatorPrefs_V7(c, &m->prefs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_nominate_V7(
    parser_context_t* c, pd_staking_nominate_V7_t* m)
{
    CHECK_ERROR(_readVecLookupSource_V7(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill_V7(
    parser_context_t* c, pd_staking_chill_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_payee_V7(
    parser_context_t* c, pd_staking_set_payee_V7_t* m)
{
    CHECK_ERROR(_readRewardDestination_V7(c, &m->payee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller_V7(
    parser_context_t* c, pd_staking_set_controller_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond_V7(
    parser_context_t* c, pd_staking_rebond_V7_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_multisig_V7(
    parser_context_t* c, pd_multisig_create_multisig_V7_t* m)
{
    CHECK_ERROR(_readVecSignatory_V7(c, &m->signers))
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_identity_V7(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_identity_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_or_approve_proposal_as_key_V7(
    parser_context_t* c, pd_multisig_create_or_approve_proposal_as_key_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_identity_V7(
    parser_context_t* c, pd_multisig_create_proposal_as_identity_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_key_V7(
    parser_context_t* c, pd_multisig_create_proposal_as_key_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readbool(c, &m->auto_close))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_identity_V7(
    parser_context_t* c, pd_multisig_approve_as_identity_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_key_V7(
    parser_context_t* c, pd_multisig_approve_as_key_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_identity_V7(
    parser_context_t* c, pd_multisig_reject_as_identity_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_key_V7(
    parser_context_t* c, pd_multisig_reject_as_key_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_identity_V7(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_identity_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_key_V7(
    parser_context_t* c, pd_multisig_accept_multisig_signer_as_key_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signer_V7(
    parser_context_t* c, pd_multisig_add_multisig_signer_V7_t* m)
{
    CHECK_ERROR(_readSignatory_V7(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signer_V7(
    parser_context_t* c, pd_multisig_remove_multisig_signer_V7_t* m)
{
    CHECK_ERROR(_readSignatory_V7(c, &m->signer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signers_via_creator_V7(
    parser_context_t* c, pd_multisig_add_multisig_signers_via_creator_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readVecSignatory_V7(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signers_via_creator_V7(
    parser_context_t* c, pd_multisig_remove_multisig_signers_via_creator_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readVecSignatory_V7(c, &m->signers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_change_sigs_required_V7(
    parser_context_t* c, pd_multisig_change_sigs_required_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->sigs_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_signer_V7(
    parser_context_t* c, pd_multisig_make_multisig_signer_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_primary_V7(
    parser_context_t* c, pd_multisig_make_multisig_primary_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_execute_scheduled_proposal_V7(
    parser_context_t* c, pd_multisig_execute_scheduled_proposal_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->multisig))
    CHECK_ERROR(_readu64(c, &m->proposal_id))
    CHECK_ERROR(_readIdentityId_V7(c, &m->multisig_did))
    CHECK_ERROR(_readWeight_V7(c, &m->proposal_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_propose_V7(
    parser_context_t* c, pd_pips_propose_V7_t* m)
{
    CHECK_ERROR(_readProposal(c, &m->proposal))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    CHECK_ERROR(_readOptionUrl_V7(c, &m->url))
    CHECK_ERROR(_readOptionPipDescription_V7(c, &m->description))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_vote_V7(
    parser_context_t* c, pd_pips_vote_V7_t* m)
{
    CHECK_ERROR(_readPipId_V7(c, &m->id))
    CHECK_ERROR(_readbool(c, &m->aye_or_nay))
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_V7(
    parser_context_t* c, pd_utility_batch_V7_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_atomic_V7(
    parser_context_t* c, pd_utility_batch_atomic_V7_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_optimistic_V7(
    parser_context_t* c, pd_utility_batch_optimistic_V7_t* m)
{
    CHECK_ERROR(_readVecCall(c, &m->calls))
    return parser_ok;
}

#ifdef SUBSTRATE_PARSER_FULL
__Z_INLINE parser_error_t _readMethod_system_fill_block_V7(
    parser_context_t* c, pd_system_fill_block_V7_t* m)
{
    CHECK_ERROR(_readPerbill_V7(c, &m->_ratio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark_V7(
    parser_context_t* c, pd_system_remark_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->_remark))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages_V7(
    parser_context_t* c, pd_system_set_heap_pages_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->pages))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_V7(
    parser_context_t* c, pd_system_set_code_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks_V7(
    parser_context_t* c, pd_system_set_code_without_checks_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config_V7(
    parser_context_t* c, pd_system_set_changes_trie_config_V7_t* m)
{
    CHECK_ERROR(_readOptionChangesTrieConfiguration_V7(c, &m->changes_trie_config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage_V7(
    parser_context_t* c, pd_system_set_storage_V7_t* m)
{
    CHECK_ERROR(_readVecKeyValue_V7(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage_V7(
    parser_context_t* c, pd_system_kill_storage_V7_t* m)
{
    CHECK_ERROR(_readVecKey_V7(c, &m->keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix_V7(
    parser_context_t* c, pd_system_kill_prefix_V7_t* m)
{
    CHECK_ERROR(_readKey_V7(c, &m->prefix))
    CHECK_ERROR(_readu32(c, &m->_subkeys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide_V7(
    parser_context_t* c, pd_system_suicide_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_V7(
    parser_context_t* c, pd_babe_report_equivocation_V7_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V7(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V7(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned_V7(
    parser_context_t* c, pd_babe_report_equivocation_unsigned_V7_t* m)
{
    CHECK_ERROR(_readBabeEquivocationProof_V7(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V7(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set_V7(
    parser_context_t* c, pd_timestamp_set_V7_t* m)
{
    CHECK_ERROR(_readCompactMoment_V7(c, &m->now))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim_V7(
    parser_context_t* c, pd_indices_claim_V7_t* m)
{
    CHECK_ERROR(_readAccountIndex_V7(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_transfer_V7(
    parser_context_t* c, pd_indices_transfer_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V7(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free_V7(
    parser_context_t* c, pd_indices_free_V7_t* m)
{
    CHECK_ERROR(_readAccountIndex_V7(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer_V7(
    parser_context_t* c, pd_indices_force_transfer_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->new_))
    CHECK_ERROR(_readAccountIndex_V7(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->freeze))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze_V7(
    parser_context_t* c, pd_indices_freeze_V7_t* m)
{
    CHECK_ERROR(_readAccountIndex_V7(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_deposit_block_reward_reserve_balance_V7(
    parser_context_t* c, pd_balances_deposit_block_reward_reserve_balance_V7_t* m)
{
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance_V7(
    parser_context_t* c, pd_balances_set_balance_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->who))
    CHECK_ERROR(_readCompactBalance(c, &m->new_free))
    CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer_V7(
    parser_context_t* c, pd_balances_force_transfer_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->source))
    CHECK_ERROR(_readLookupSource_V7(c, &m->dest))
    CHECK_ERROR(_readCompactBalance(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_burn_account_balance_V7(
    parser_context_t* c, pd_balances_burn_account_balance_V7_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cdd_register_did_V7(
    parser_context_t* c, pd_identity_cdd_register_did_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->target_account))
    CHECK_ERROR(_readVecSecondaryKey_V7(c, &m->secondary_keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_invalidate_cdd_claims_V7(
    parser_context_t* c, pd_identity_invalidate_cdd_claims_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->cdd))
    CHECK_ERROR(_readMoment_V7(c, &m->disable_from))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_change_cdd_requirement_for_mk_rotation_V7(
    parser_context_t* c, pd_identity_change_cdd_requirement_for_mk_rotation_V7_t* m)
{
    CHECK_ERROR(_readbool(c, &m->auth_required))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_forwarded_call_V7(
    parser_context_t* c, pd_identity_forwarded_call_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->target_did))
    CHECK_ERROR(_readProposal(c, &m->proposal))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_offchain_authorization_V7(
    parser_context_t* c, pd_identity_revoke_offchain_authorization_V7_t* m)
{
    CHECK_ERROR(_readSignatory_V7(c, &m->signer))
    CHECK_ERROR(_readTargetIdAuthorization_V7(c, &m->auth))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_add_cdd_claim_V7(
    parser_context_t* c, pd_identity_gc_add_cdd_claim_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->target))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_revoke_cdd_claim_V7(
    parser_context_t* c, pd_identity_gc_revoke_cdd_claim_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->target))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_investor_uniqueness_claim_v2_V7(
    parser_context_t* c, pd_identity_add_investor_uniqueness_claim_v2_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->target))
    CHECK_ERROR(_readClaim_V7(c, &m->claim))
    CHECK_ERROR(_readScopeClaimProof_V7(c, &m->proof))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles_V7(
    parser_context_t* c, pd_authorship_set_uncles_V7_t* m)
{
    CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_set_active_members_limit_V7(
    parser_context_t* c, pd_cddserviceproviders_set_active_members_limit_V7_t* m)
{
    CHECK_ERROR(_readMemberCount_V7(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_disable_member_V7(
    parser_context_t* c, pd_cddserviceproviders_disable_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_add_member_V7(
    parser_context_t* c, pd_cddserviceproviders_add_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_remove_member_V7(
    parser_context_t* c, pd_cddserviceproviders_remove_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_swap_member_V7(
    parser_context_t* c, pd_cddserviceproviders_swap_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V7(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_reset_members_V7(
    parser_context_t* c, pd_cddserviceproviders_reset_members_V7_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V7(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_abdicate_membership_V7(
    parser_context_t* c, pd_cddserviceproviders_abdicate_membership_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count_V7(
    parser_context_t* c, pd_staking_set_validator_count_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count_V7(
    parser_context_t* c, pd_staking_increase_validator_count_V7_t* m)
{
    CHECK_ERROR(_readCompactu32(c, &m->additional))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count_V7(
    parser_context_t* c, pd_staking_scale_validator_count_V7_t* m)
{
    CHECK_ERROR(_readPercent_V7(c, &m->factor))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_add_permissioned_validator_V7(
    parser_context_t* c, pd_staking_add_permissioned_validator_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->identity))
    CHECK_ERROR(_readOptionu32(c, &m->intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_remove_permissioned_validator_V7(
    parser_context_t* c, pd_staking_remove_permissioned_validator_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->identity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_cdd_expiry_nominators_V7(
    parser_context_t* c, pd_staking_validate_cdd_expiry_nominators_V7_t* m)
{
    CHECK_ERROR(_readVecAccountId_V7(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_commission_cap_V7(
    parser_context_t* c, pd_staking_set_commission_cap_V7_t* m)
{
    CHECK_ERROR(_readPerbill_V7(c, &m->new_cap))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_bond_threshold_V7(
    parser_context_t* c, pd_staking_set_min_bond_threshold_V7_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->new_value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras_V7(
    parser_context_t* c, pd_staking_force_no_eras_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_V7(
    parser_context_t* c, pd_staking_force_new_era_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables_V7(
    parser_context_t* c, pd_staking_set_invulnerables_V7_t* m)
{
    CHECK_ERROR(_readVecAccountId_V7(c, &m->validators))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake_V7(
    parser_context_t* c, pd_staking_force_unstake_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always_V7(
    parser_context_t* c, pd_staking_force_new_era_always_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash_V7(
    parser_context_t* c, pd_staking_cancel_deferred_slash_V7_t* m)
{
    CHECK_ERROR(_readEraIndex_V7(c, &m->era))
    CHECK_ERROR(_readVecu32(c, &m->slash_indices))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_V7(
    parser_context_t* c, pd_staking_payout_stakers_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V7(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth_V7(
    parser_context_t* c, pd_staking_set_history_depth_V7_t* m)
{
    CHECK_ERROR(_readCompactEraIndex_V7(c, &m->new_history_depth))
    CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash_V7(
    parser_context_t* c, pd_staking_reap_stash_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->stash))
    CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_V7(
    parser_context_t* c, pd_staking_submit_election_solution_V7_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V7(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V7(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V7(c, &m->score))
    CHECK_ERROR(_readEraIndex_V7(c, &m->era))
    CHECK_ERROR(_readElectionSize_V7(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned_V7(
    parser_context_t* c, pd_staking_submit_election_solution_unsigned_V7_t* m)
{
    CHECK_ERROR(_readVecValidatorIndex_V7(c, &m->winners))
    CHECK_ERROR(_readCompactAssignments_V7(c, &m->compact))
    CHECK_ERROR(_readElectionScore_V7(c, &m->score))
    CHECK_ERROR(_readEraIndex_V7(c, &m->era))
    CHECK_ERROR(_readElectionSize_V7(c, &m->size))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_system_V7(
    parser_context_t* c, pd_staking_payout_stakers_by_system_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->validator_stash))
    CHECK_ERROR(_readEraIndex_V7(c, &m->era))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_change_slashing_allowed_for_V7(
    parser_context_t* c, pd_staking_change_slashing_allowed_for_V7_t* m)
{
    CHECK_ERROR(_readSlashingSwitch_V7(c, &m->slashing_switch))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_update_permissioned_validator_intended_count_V7(
    parser_context_t* c, pd_staking_update_permissioned_validator_intended_count_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->identity))
    CHECK_ERROR(_readu32(c, &m->new_intended_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_set_keys_V7(
    parser_context_t* c, pd_session_set_keys_V7_t* m)
{
    CHECK_ERROR(_readKeys_V7(c, &m->keys))
    CHECK_ERROR(_readBytes(c, &m->proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys_V7(
    parser_context_t* c, pd_session_purge_keys_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_finalitytracker_final_hint_V7(
    parser_context_t* c, pd_finalitytracker_final_hint_V7_t* m)
{
    CHECK_ERROR(_readCompactBlockNumber(c, &m->hint))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_V7(
    parser_context_t* c, pd_grandpa_report_equivocation_V7_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V7(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V7(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned_V7(
    parser_context_t* c, pd_grandpa_report_equivocation_unsigned_V7_t* m)
{
    CHECK_ERROR(_readGrandpaEquivocationProof_V7(c, &m->equivocation_proof))
    CHECK_ERROR(_readKeyOwnerProof_V7(c, &m->key_owner_proof))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled_V7(
    parser_context_t* c, pd_grandpa_note_stalled_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->delay))
    CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat_V7(
    parser_context_t* c, pd_imonline_heartbeat_V7_t* m)
{
    CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
    CHECK_ERROR(_readSignature_V7(c, &m->_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_V7(
    parser_context_t* c, pd_sudo_sudo_V7_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight_V7(
    parser_context_t* c, pd_sudo_sudo_unchecked_weight_V7_t* m)
{
    CHECK_ERROR(_readCall(c, &m->call))
    CHECK_ERROR(_readWeight_V7(c, &m->_weight))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key_V7(
    parser_context_t* c, pd_sudo_set_key_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->new_))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as_V7(
    parser_context_t* c, pd_sudo_sudo_as_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->who))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_update_schedule_V7(
    parser_context_t* c, pd_contracts_update_schedule_V7_t* m)
{
    CHECK_ERROR(_readSchedule_V7(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_set_put_code_flag_V7(
    parser_context_t* c, pd_contracts_set_put_code_flag_V7_t* m)
{
    CHECK_ERROR(_readbool(c, &m->is_enabled))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_put_code_V7(
    parser_context_t* c, pd_contracts_put_code_V7_t* m)
{
    CHECK_ERROR(_readTemplateMetadata_V7(c, &m->meta_info))
    CHECK_ERROR(_readBalanceOf(c, &m->instantiation_fee))
    CHECK_ERROR(_readBytes(c, &m->code))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call_V7(
    parser_context_t* c, pd_contracts_call_V7_t* m)
{
    CHECK_ERROR(_readLookupSource_V7(c, &m->dest))
    CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
    CHECK_ERROR(_readCompactGas_V7(c, &m->gas_limit))
    CHECK_ERROR(_readBytes(c, &m->data))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate_V7(
    parser_context_t* c, pd_contracts_instantiate_V7_t* m)
{
    CHECK_ERROR(_readCompactBalanceOf(c, &m->endowment))
    CHECK_ERROR(_readCompactGas_V7(c, &m->gas_limit))
    CHECK_ERROR(_readCodeHash_V7(c, &m->code_hash))
    CHECK_ERROR(_readBytes(c, &m->data))
    CHECK_ERROR(_readBalanceOf(c, &m->max_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_freeze_instantiation_V7(
    parser_context_t* c, pd_contracts_freeze_instantiation_V7_t* m)
{
    CHECK_ERROR(_readCodeHash_V7(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_unfreeze_instantiation_V7(
    parser_context_t* c, pd_contracts_unfreeze_instantiation_V7_t* m)
{
    CHECK_ERROR(_readCodeHash_V7(c, &m->code_hash))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_transfer_template_ownership_V7(
    parser_context_t* c, pd_contracts_transfer_template_ownership_V7_t* m)
{
    CHECK_ERROR(_readCodeHash_V7(c, &m->code_hash))
    CHECK_ERROR(_readIdentityId_V7(c, &m->new_owner))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_change_template_fees_V7(
    parser_context_t* c, pd_contracts_change_template_fees_V7_t* m)
{
    CHECK_ERROR(_readCodeHash_V7(c, &m->code_hash))
    CHECK_ERROR(_readOptionBalanceOf(c, &m->new_instantiation_fee))
    CHECK_ERROR(_readOptionBalanceOf(c, &m->new_usage_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_change_template_meta_url_V7(
    parser_context_t* c, pd_contracts_change_template_meta_url_V7_t* m)
{
    CHECK_ERROR(_readCodeHash_V7(c, &m->code_hash))
    CHECK_ERROR(_readOptionMetaUrl_V7(c, &m->new_url))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_disbursement_V7(
    parser_context_t* c, pd_treasury_disbursement_V7_t* m)
{
    CHECK_ERROR(_readVecBeneficiary_V7(c, &m->beneficiaries))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reimbursement_V7(
    parser_context_t* c, pd_treasury_reimbursement_V7_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->amount))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_vote_threshold_V7(
    parser_context_t* c, pd_polymeshcommittee_set_vote_threshold_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_release_coordinator_V7(
    parser_context_t* c, pd_polymeshcommittee_set_release_coordinator_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_expires_after_V7(
    parser_context_t* c, pd_polymeshcommittee_set_expires_after_V7_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_or_propose_V7(
    parser_context_t* c, pd_polymeshcommittee_vote_or_propose_V7_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_V7(
    parser_context_t* c, pd_polymeshcommittee_vote_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V7(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_set_active_members_limit_V7(
    parser_context_t* c, pd_committeemembership_set_active_members_limit_V7_t* m)
{
    CHECK_ERROR(_readMemberCount_V7(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_disable_member_V7(
    parser_context_t* c, pd_committeemembership_disable_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_add_member_V7(
    parser_context_t* c, pd_committeemembership_add_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_remove_member_V7(
    parser_context_t* c, pd_committeemembership_remove_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_swap_member_V7(
    parser_context_t* c, pd_committeemembership_swap_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V7(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_reset_members_V7(
    parser_context_t* c, pd_committeemembership_reset_members_V7_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V7(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_abdicate_membership_V7(
    parser_context_t* c, pd_committeemembership_abdicate_membership_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_prune_historical_pips_V7(
    parser_context_t* c, pd_pips_set_prune_historical_pips_V7_t* m)
{
    CHECK_ERROR(_readbool(c, &m->prune))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_min_proposal_deposit_V7(
    parser_context_t* c, pd_pips_set_min_proposal_deposit_V7_t* m)
{
    CHECK_ERROR(_readBalanceOf(c, &m->deposit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_default_enactment_period_V7(
    parser_context_t* c, pd_pips_set_default_enactment_period_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_pending_pip_expiry_V7(
    parser_context_t* c, pd_pips_set_pending_pip_expiry_V7_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_max_pip_skip_count_V7(
    parser_context_t* c, pd_pips_set_max_pip_skip_count_V7_t* m)
{
    CHECK_ERROR(_readSkippedCount_V7(c, &m->max))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_active_pip_limit_V7(
    parser_context_t* c, pd_pips_set_active_pip_limit_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_approve_committee_proposal_V7(
    parser_context_t* c, pd_pips_approve_committee_proposal_V7_t* m)
{
    CHECK_ERROR(_readPipId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reject_proposal_V7(
    parser_context_t* c, pd_pips_reject_proposal_V7_t* m)
{
    CHECK_ERROR(_readPipId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_prune_proposal_V7(
    parser_context_t* c, pd_pips_prune_proposal_V7_t* m)
{
    CHECK_ERROR(_readPipId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reschedule_execution_V7(
    parser_context_t* c, pd_pips_reschedule_execution_V7_t* m)
{
    CHECK_ERROR(_readPipId_V7(c, &m->id))
    CHECK_ERROR(_readOptionBlockNumber(c, &m->until))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_clear_snapshot_V7(
    parser_context_t* c, pd_pips_clear_snapshot_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_snapshot_V7(
    parser_context_t* c, pd_pips_snapshot_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_enact_snapshot_results_V7(
    parser_context_t* c, pd_pips_enact_snapshot_results_V7_t* m)
{
    CHECK_ERROR(_readVecTuplePipIdSnapshotResult_V7(c, &m->results))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_execute_scheduled_pip_V7(
    parser_context_t* c, pd_pips_execute_scheduled_pip_V7_t* m)
{
    CHECK_ERROR(_readPipId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_expire_scheduled_pip_V7(
    parser_context_t* c, pd_pips_expire_scheduled_pip_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->did))
    CHECK_ERROR(_readPipId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_vote_threshold_V7(
    parser_context_t* c, pd_technicalcommittee_set_vote_threshold_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_release_coordinator_V7(
    parser_context_t* c, pd_technicalcommittee_set_release_coordinator_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_expires_after_V7(
    parser_context_t* c, pd_technicalcommittee_set_expires_after_V7_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_or_propose_V7(
    parser_context_t* c, pd_technicalcommittee_vote_or_propose_V7_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_V7(
    parser_context_t* c, pd_technicalcommittee_vote_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V7(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_set_active_members_limit_V7(
    parser_context_t* c, pd_technicalcommitteemembership_set_active_members_limit_V7_t* m)
{
    CHECK_ERROR(_readMemberCount_V7(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_disable_member_V7(
    parser_context_t* c, pd_technicalcommitteemembership_disable_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_add_member_V7(
    parser_context_t* c, pd_technicalcommitteemembership_add_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_remove_member_V7(
    parser_context_t* c, pd_technicalcommitteemembership_remove_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_swap_member_V7(
    parser_context_t* c, pd_technicalcommitteemembership_swap_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V7(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_reset_members_V7(
    parser_context_t* c, pd_technicalcommitteemembership_reset_members_V7_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V7(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_abdicate_membership_V7(
    parser_context_t* c, pd_technicalcommitteemembership_abdicate_membership_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_vote_threshold_V7(
    parser_context_t* c, pd_upgradecommittee_set_vote_threshold_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->n))
    CHECK_ERROR(_readu32(c, &m->d))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_release_coordinator_V7(
    parser_context_t* c, pd_upgradecommittee_set_release_coordinator_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_expires_after_V7(
    parser_context_t* c, pd_upgradecommittee_set_expires_after_V7_t* m)
{
    CHECK_ERROR(_readMaybeBlock_V7(c, &m->expiry))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_or_propose_V7(
    parser_context_t* c, pd_upgradecommittee_vote_or_propose_V7_t* m)
{
    CHECK_ERROR(_readbool(c, &m->approve))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_V7(
    parser_context_t* c, pd_upgradecommittee_vote_V7_t* m)
{
    CHECK_ERROR(_readHash(c, &m->proposal))
    CHECK_ERROR(_readProposalIndex_V7(c, &m->index))
    CHECK_ERROR(_readbool(c, &m->approve))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_set_active_members_limit_V7(
    parser_context_t* c, pd_upgradecommitteemembership_set_active_members_limit_V7_t* m)
{
    CHECK_ERROR(_readMemberCount_V7(c, &m->limit))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_disable_member_V7(
    parser_context_t* c, pd_upgradecommitteemembership_disable_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expiry))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_add_member_V7(
    parser_context_t* c, pd_upgradecommitteemembership_add_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_remove_member_V7(
    parser_context_t* c, pd_upgradecommitteemembership_remove_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->who))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_swap_member_V7(
    parser_context_t* c, pd_upgradecommitteemembership_swap_member_V7_t* m)
{
    CHECK_ERROR(_readIdentityId_V7(c, &m->remove))
    CHECK_ERROR(_readIdentityId_V7(c, &m->add))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_reset_members_V7(
    parser_context_t* c, pd_upgradecommitteemembership_reset_members_V7_t* m)
{
    CHECK_ERROR(_readVecIdentityId_V7(c, &m->members))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_abdicate_membership_V7(
    parser_context_t* c, pd_upgradecommitteemembership_abdicate_membership_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_ticker_V7(
    parser_context_t* c, pd_asset_register_ticker_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_ticker_transfer_V7(
    parser_context_t* c, pd_asset_accept_ticker_transfer_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_primary_issuance_agent_transfer_V7(
    parser_context_t* c, pd_asset_accept_primary_issuance_agent_transfer_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_asset_ownership_transfer_V7(
    parser_context_t* c, pd_asset_accept_asset_ownership_transfer_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->auth_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_create_asset_V7(
    parser_context_t* c, pd_asset_create_asset_V7_t* m)
{
    CHECK_ERROR(_readAssetName_V7(c, &m->name))
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->total_supply))
    CHECK_ERROR(_readbool(c, &m->divisible))
    CHECK_ERROR(_readAssetType_V7(c, &m->asset_type))
    CHECK_ERROR(_readVecAssetIdentifier_V7(c, &m->identifiers))
    CHECK_ERROR(_readOptionFundingRoundName_V7(c, &m->funding_round))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_freeze_V7(
    parser_context_t* c, pd_asset_freeze_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unfreeze_V7(
    parser_context_t* c, pd_asset_unfreeze_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_rename_asset_V7(
    parser_context_t* c, pd_asset_rename_asset_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readAssetName_V7(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_issue_V7(
    parser_context_t* c, pd_asset_issue_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_redeem_V7(
    parser_context_t* c, pd_asset_redeem_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->value))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_make_divisible_V7(
    parser_context_t* c, pd_asset_make_divisible_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_documents_V7(
    parser_context_t* c, pd_asset_add_documents_V7_t* m)
{
    CHECK_ERROR(_readVecDocument_V7(c, &m->docs))
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_documents_V7(
    parser_context_t* c, pd_asset_remove_documents_V7_t* m)
{
    CHECK_ERROR(_readVecDocumentId_V7(c, &m->ids))
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_set_funding_round_V7(
    parser_context_t* c, pd_asset_set_funding_round_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readFundingRoundName_V7(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_update_identifiers_V7(
    parser_context_t* c, pd_asset_update_identifiers_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readVecAssetIdentifier_V7(c, &m->identifiers))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_extension_V7(
    parser_context_t* c, pd_asset_add_extension_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readSmartExtension_V7(c, &m->extension_details))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_smart_extension_V7(
    parser_context_t* c, pd_asset_remove_smart_extension_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readAccountId_V7(c, &m->extension_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_archive_extension_V7(
    parser_context_t* c, pd_asset_archive_extension_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readAccountId_V7(c, &m->extension_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unarchive_extension_V7(
    parser_context_t* c, pd_asset_unarchive_extension_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readAccountId_V7(c, &m->extension_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_primary_issuance_agent_V7(
    parser_context_t* c, pd_asset_remove_primary_issuance_agent_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_claim_classic_ticker_V7(
    parser_context_t* c, pd_asset_claim_classic_ticker_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readEcdsaSignature_V7(c, &m->ethereum_signature))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_reserve_classic_ticker_V7(
    parser_context_t* c, pd_asset_reserve_classic_ticker_V7_t* m)
{
    CHECK_ERROR(_readClassicTickerImport_V7(c, &m->classic_ticker_import))
    CHECK_ERROR(_readIdentityId_V7(c, &m->contract_did))
    CHECK_ERROR(_readTickerRegistrationConfig_V7(c, &m->config))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_controller_transfer_V7(
    parser_context_t* c, pd_asset_controller_transfer_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->value))
    CHECK_ERROR(_readPortfolioId_V7(c, &m->from_portfolio))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_controller_V7(
    parser_context_t* c, pd_bridge_change_controller_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->controller))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_admin_V7(
    parser_context_t* c, pd_bridge_change_admin_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->admin))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_timelock_V7(
    parser_context_t* c, pd_bridge_change_timelock_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->timelock))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_V7(
    parser_context_t* c, pd_bridge_freeze_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_V7(
    parser_context_t* c, pd_bridge_unfreeze_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_limit_V7(
    parser_context_t* c, pd_bridge_change_bridge_limit_V7_t* m)
{
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readBlockNumber(c, &m->duration))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_exempted_V7(
    parser_context_t* c, pd_bridge_change_bridge_exempted_V7_t* m)
{
    CHECK_ERROR(_readVecTupleIdentityIdbool_V7(c, &m->exempted))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_force_handle_bridge_tx_V7(
    parser_context_t* c, pd_bridge_force_handle_bridge_tx_V7_t* m)
{
    CHECK_ERROR(_readBridgeTx_V7(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_batch_propose_bridge_tx_V7(
    parser_context_t* c, pd_bridge_batch_propose_bridge_tx_V7_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V7(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_propose_bridge_tx_V7(
    parser_context_t* c, pd_bridge_propose_bridge_tx_V7_t* m)
{
    CHECK_ERROR(_readBridgeTx_V7(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_bridge_tx_V7(
    parser_context_t* c, pd_bridge_handle_bridge_tx_V7_t* m)
{
    CHECK_ERROR(_readBridgeTx_V7(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze_txs_V7(
    parser_context_t* c, pd_bridge_freeze_txs_V7_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V7(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_txs_V7(
    parser_context_t* c, pd_bridge_unfreeze_txs_V7_t* m)
{
    CHECK_ERROR(_readVecBridgeTx_V7(c, &m->bridge_txs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_scheduled_bridge_tx_V7(
    parser_context_t* c, pd_bridge_handle_scheduled_bridge_tx_V7_t* m)
{
    CHECK_ERROR(_readBridgeTx_V7(c, &m->bridge_tx))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_compliance_requirement_V7(
    parser_context_t* c, pd_compliancemanager_add_compliance_requirement_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readVecCondition_V7(c, &m->sender_conditions))
    CHECK_ERROR(_readVecCondition_V7(c, &m->receiver_conditions))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_compliance_requirement_V7(
    parser_context_t* c, pd_compliancemanager_remove_compliance_requirement_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readu32(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_replace_asset_compliance_V7(
    parser_context_t* c, pd_compliancemanager_replace_asset_compliance_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readVecComplianceRequirement_V7(c, &m->asset_compliance))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_reset_asset_compliance_V7(
    parser_context_t* c, pd_compliancemanager_reset_asset_compliance_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_pause_asset_compliance_V7(
    parser_context_t* c, pd_compliancemanager_pause_asset_compliance_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_resume_asset_compliance_V7(
    parser_context_t* c, pd_compliancemanager_resume_asset_compliance_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_add_default_trusted_claim_issuer_V7(
    parser_context_t* c, pd_compliancemanager_add_default_trusted_claim_issuer_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readTrustedIssuer_V7(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_remove_default_trusted_claim_issuer_V7(
    parser_context_t* c, pd_compliancemanager_remove_default_trusted_claim_issuer_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readIdentityId_V7(c, &m->issuer))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_change_compliance_requirement_V7(
    parser_context_t* c, pd_compliancemanager_change_compliance_requirement_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readComplianceRequirement_V7(c, &m->new_req))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_create_venue_V7(
    parser_context_t* c, pd_settlement_create_venue_V7_t* m)
{
    CHECK_ERROR(_readVenueDetails_V7(c, &m->details))
    CHECK_ERROR(_readVecAccountId_V7(c, &m->signers))
    CHECK_ERROR(_readVenueType_V7(c, &m->venue_type))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue_V7(
    parser_context_t* c, pd_settlement_update_venue_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readOptionVenueDetails_V7(c, &m->details))
    CHECK_ERROR(_readOptionVenueType_V7(c, &m->typ))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_instruction_V7(
    parser_context_t* c, pd_settlement_add_instruction_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readSettlementType_V7(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->value_date))
    CHECK_ERROR(_readVecLeg_V7(c, &m->legs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_and_affirm_instruction_V7(
    parser_context_t* c, pd_settlement_add_and_affirm_instruction_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readSettlementType_V7(c, &m->settlement_type))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->trade_date))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->value_date))
    CHECK_ERROR(_readVecLeg_V7(c, &m->legs))
    CHECK_ERROR(_readVecPortfolioId_V7(c, &m->portfolios))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_instruction_V7(
    parser_context_t* c, pd_settlement_affirm_instruction_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecPortfolioId_V7(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_withdraw_affirmation_V7(
    parser_context_t* c, pd_settlement_withdraw_affirmation_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecPortfolioId_V7(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_reject_instruction_V7(
    parser_context_t* c, pd_settlement_reject_instruction_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecPortfolioId_V7(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_with_receipts_V7(
    parser_context_t* c, pd_settlement_affirm_with_receipts_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readVecReceiptDetails_V7(c, &m->receipt_details))
    CHECK_ERROR(_readVecPortfolioId_V7(c, &m->portfolios))
    CHECK_ERROR(_readu32(c, &m->max_legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_claim_receipt_V7(
    parser_context_t* c, pd_settlement_claim_receipt_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readReceiptDetails_V7(c, &m->receipt_details))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_unclaim_receipt_V7(
    parser_context_t* c, pd_settlement_unclaim_receipt_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readu64(c, &m->leg_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_set_venue_filtering_V7(
    parser_context_t* c, pd_settlement_set_venue_filtering_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readbool(c, &m->enabled))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_allow_venues_V7(
    parser_context_t* c, pd_settlement_allow_venues_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readVecu64(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_disallow_venues_V7(
    parser_context_t* c, pd_settlement_disallow_venues_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readVecu64(c, &m->venues))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_change_receipt_validity_V7(
    parser_context_t* c, pd_settlement_change_receipt_validity_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->receipt_uid))
    CHECK_ERROR(_readbool(c, &m->validity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_execute_scheduled_instruction_V7(
    parser_context_t* c, pd_settlement_execute_scheduled_instruction_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->instruction_id))
    CHECK_ERROR(_readu32(c, &m->legs_count))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_create_fundraiser_V7(
    parser_context_t* c, pd_sto_create_fundraiser_V7_t* m)
{
    CHECK_ERROR(_readPortfolioId_V7(c, &m->offering_portfolio))
    CHECK_ERROR(_readTicker_V7(c, &m->offering_asset))
    CHECK_ERROR(_readPortfolioId_V7(c, &m->raising_portfolio))
    CHECK_ERROR(_readTicker_V7(c, &m->raising_asset))
    CHECK_ERROR(_readVecPriceTier_V7(c, &m->tiers))
    CHECK_ERROR(_readu64(c, &m->venue_id))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->start))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->end))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->minimum_investment))
    CHECK_ERROR(_readFundraiserName_V7(c, &m->fundraiser_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_invest_V7(
    parser_context_t* c, pd_sto_invest_V7_t* m)
{
    CHECK_ERROR(_readPortfolioId_V7(c, &m->investment_portfolio))
    CHECK_ERROR(_readPortfolioId_V7(c, &m->funding_portfolio))
    CHECK_ERROR(_readTicker_V7(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    CHECK_ERROR(_readBalanceNoSymbol(c, &m->purchase_amount))
    CHECK_ERROR(_readOptionBalance(c, &m->max_price))
    CHECK_ERROR(_readOptionReceiptDetails_V7(c, &m->receipt))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_freeze_fundraiser_V7(
    parser_context_t* c, pd_sto_freeze_fundraiser_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_unfreeze_fundraiser_V7(
    parser_context_t* c, pd_sto_unfreeze_fundraiser_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_modify_fundraiser_window_V7(
    parser_context_t* c, pd_sto_modify_fundraiser_window_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    CHECK_ERROR(_readMoment_V7(c, &m->start))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_stop_V7(
    parser_context_t* c, pd_sto_stop_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->offering_asset))
    CHECK_ERROR(_readu64(c, &m->fundraiser_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_add_transfer_manager_V7(
    parser_context_t* c, pd_statistics_add_transfer_manager_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V7(c, &m->new_transfer_manager))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_remove_transfer_manager_V7(
    parser_context_t* c, pd_statistics_remove_transfer_manager_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V7(c, &m->transfer_manager))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_add_exempted_entities_V7(
    parser_context_t* c, pd_statistics_add_exempted_entities_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V7(c, &m->transfer_manager))
    CHECK_ERROR(_readVecScopeId_V7(c, &m->exempted_entities))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_statistics_remove_exempted_entities_V7(
    parser_context_t* c, pd_statistics_remove_exempted_entities_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readTransferManager_V7(c, &m->transfer_manager))
    CHECK_ERROR(_readVecScopeId_V7(c, &m->entities))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_coefficient_V7(
    parser_context_t* c, pd_protocolfee_change_coefficient_V7_t* m)
{
    CHECK_ERROR(_readPosRatio_V7(c, &m->coefficient))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_base_fee_V7(
    parser_context_t* c, pd_protocolfee_change_base_fee_V7_t* m)
{
    CHECK_ERROR(_readProtocolOp_V7(c, &m->op))
    CHECK_ERROR(_readBalanceOf(c, &m->base_fee))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_relay_tx_V7(
    parser_context_t* c, pd_utility_relay_tx_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->target))
    CHECK_ERROR(_readOffChainSignature_V7(c, &m->signature))
    CHECK_ERROR(_readUniqueCall_V7(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_create_portfolio_V7(
    parser_context_t* c, pd_portfolio_create_portfolio_V7_t* m)
{
    CHECK_ERROR(_readPortfolioName_V7(c, &m->name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_delete_portfolio_V7(
    parser_context_t* c, pd_portfolio_delete_portfolio_V7_t* m)
{
    CHECK_ERROR(_readPortfolioNumber_V7(c, &m->num))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_move_portfolio_funds_V7(
    parser_context_t* c, pd_portfolio_move_portfolio_funds_V7_t* m)
{
    CHECK_ERROR(_readPortfolioId_V7(c, &m->from))
    CHECK_ERROR(_readPortfolioId_V7(c, &m->to))
    CHECK_ERROR(_readVecMovePortfolioItem_V7(c, &m->items))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_rename_portfolio_V7(
    parser_context_t* c, pd_portfolio_rename_portfolio_V7_t* m)
{
    CHECK_ERROR(_readPortfolioNumber_V7(c, &m->num))
    CHECK_ERROR(_readPortfolioName_V7(c, &m->to_name))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_V7(
    parser_context_t* c, pd_scheduler_schedule_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V7(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V7(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_V7(
    parser_context_t* c, pd_scheduler_cancel_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readu32(c, &m->index))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_V7(
    parser_context_t* c, pd_scheduler_schedule_named_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->when))
    CHECK_ERROR(_readOptionPeriod_V7(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V7(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named_V7(
    parser_context_t* c, pd_scheduler_cancel_named_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after_V7(
    parser_context_t* c, pd_scheduler_schedule_after_V7_t* m)
{
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V7(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V7(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after_V7(
    parser_context_t* c, pd_scheduler_schedule_named_after_V7_t* m)
{
    CHECK_ERROR(_readBytes(c, &m->id))
    CHECK_ERROR(_readBlockNumber(c, &m->after))
    CHECK_ERROR(_readOptionPeriod_V7(c, &m->maybe_periodic))
    CHECK_ERROR(_readPriority_V7(c, &m->priority))
    CHECK_ERROR(_readCall(c, &m->call))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_max_details_length_V7(
    parser_context_t* c, pd_corporateaction_set_max_details_length_V7_t* m)
{
    CHECK_ERROR(_readu32(c, &m->length))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_reset_caa_V7(
    parser_context_t* c, pd_corporateaction_reset_caa_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_targets_V7(
    parser_context_t* c, pd_corporateaction_set_default_targets_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readTargetIdentities_V7(c, &m->targets))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_withholding_tax_V7(
    parser_context_t* c, pd_corporateaction_set_default_withholding_tax_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readTax_V7(c, &m->tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_did_withholding_tax_V7(
    parser_context_t* c, pd_corporateaction_set_did_withholding_tax_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readIdentityId_V7(c, &m->taxed_did))
    CHECK_ERROR(_readOptionTax_V7(c, &m->tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_initiate_corporate_action_V7(
    parser_context_t* c, pd_corporateaction_initiate_corporate_action_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readCAKind_V7(c, &m->kind))
    CHECK_ERROR(_readMoment_V7(c, &m->decl_date))
    CHECK_ERROR(_readOptionRecordDateSpec_V7(c, &m->record_date))
    CHECK_ERROR(_readCADetails_V7(c, &m->details))
    CHECK_ERROR(_readOptionTargetIdentities_V7(c, &m->targets))
    CHECK_ERROR(_readOptionTax_V7(c, &m->default_withholding_tax))
    CHECK_ERROR(_readOptionVecTupleIdentityIdTax_V7(c, &m->withholding_tax))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_link_ca_doc_V7(
    parser_context_t* c, pd_corporateaction_link_ca_doc_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->id))
    CHECK_ERROR(_readVecDocumentId_V7(c, &m->docs))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_remove_ca_V7(
    parser_context_t* c, pd_corporateaction_remove_ca_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_change_record_date_V7(
    parser_context_t* c, pd_corporateaction_change_record_date_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readOptionRecordDateSpec_V7(c, &m->record_date))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_attach_ballot_V7(
    parser_context_t* c, pd_corporateballot_attach_ballot_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readBallotTimeRange_V7(c, &m->range))
    CHECK_ERROR(_readBallotMeta_V7(c, &m->meta))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_vote_V7(
    parser_context_t* c, pd_corporateballot_vote_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readVecBallotVote_V7(c, &m->votes))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_end_V7(
    parser_context_t* c, pd_corporateballot_change_end_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readMoment_V7(c, &m->end))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_meta_V7(
    parser_context_t* c, pd_corporateballot_change_meta_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readBallotMeta_V7(c, &m->meta))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_rcv_V7(
    parser_context_t* c, pd_corporateballot_change_rcv_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readbool(c, &m->rcv))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_remove_ballot_V7(
    parser_context_t* c, pd_corporateballot_remove_ballot_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_distribute_V7(
    parser_context_t* c, pd_capitaldistribution_distribute_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readOptionPortfolioNumber_V7(c, &m->portfolio))
    CHECK_ERROR(_readTicker_V7(c, &m->currency))
    CHECK_ERROR(_readBalance(c, &m->per_share))
    CHECK_ERROR(_readBalance(c, &m->amount))
    CHECK_ERROR(_readMoment_V7(c, &m->payment_at))
    CHECK_ERROR(_readOptionMoment_V7(c, &m->expires_at))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_claim_V7(
    parser_context_t* c, pd_capitaldistribution_claim_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_push_benefit_V7(
    parser_context_t* c, pd_capitaldistribution_push_benefit_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    CHECK_ERROR(_readIdentityId_V7(c, &m->holder))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_reclaim_V7(
    parser_context_t* c, pd_capitaldistribution_reclaim_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_remove_distribution_V7(
    parser_context_t* c, pd_capitaldistribution_remove_distribution_V7_t* m)
{
    CHECK_ERROR(_readCAId_V7(c, &m->ca_id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_checkpoint_V7(
    parser_context_t* c, pd_checkpoint_create_checkpoint_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_set_schedules_max_complexity_V7(
    parser_context_t* c, pd_checkpoint_set_schedules_max_complexity_V7_t* m)
{
    CHECK_ERROR(_readu64(c, &m->max_complexity))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_schedule_V7(
    parser_context_t* c, pd_checkpoint_create_schedule_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readScheduleSpec_V7(c, &m->schedule))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_remove_schedule_V7(
    parser_context_t* c, pd_checkpoint_remove_schedule_V7_t* m)
{
    CHECK_ERROR(_readTicker_V7(c, &m->ticker))
    CHECK_ERROR(_readScheduleId_V7(c, &m->id))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_testutils_register_did_V7(
    parser_context_t* c, pd_testutils_register_did_V7_t* m)
{
    CHECK_ERROR(_readInvestorUid_V7(c, &m->uid))
    CHECK_ERROR(_readVecSecondaryKey_V7(c, &m->secondary_keys))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_testutils_mock_cdd_register_did_V7(
    parser_context_t* c, pd_testutils_mock_cdd_register_did_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->target_account))
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_testutils_get_my_did_V7(
    parser_context_t* c, pd_testutils_get_my_did_V7_t* m)
{
    return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_testutils_get_cdd_of_V7(
    parser_context_t* c, pd_testutils_get_cdd_of_V7_t* m)
{
    CHECK_ERROR(_readAccountId_V7(c, &m->of))
    return parser_ok;
}

#endif

parser_error_t _readMethod_V7(
    parser_context_t* c,
    uint8_t moduleIdx,
    uint8_t callIdx,
    pd_Method_V7_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {

    case 1024: /* module 4 call 0 */
        CHECK_ERROR(_readMethod_balances_transfer_V7(c, &method->nested.balances_transfer_V7))
        break;
    case 1025: /* module 4 call 1 */
        CHECK_ERROR(_readMethod_balances_transfer_with_memo_V7(c, &method->nested.balances_transfer_with_memo_V7))
        break;
    case 1538: /* module 6 call 2 */
        CHECK_ERROR(_readMethod_identity_remove_secondary_keys_V7(c, &method->nested.identity_remove_secondary_keys_V7))
        break;
    case 1539: /* module 6 call 3 */
        CHECK_ERROR(_readMethod_identity_accept_primary_key_V7(c, &method->nested.identity_accept_primary_key_V7))
        break;
    case 1541: /* module 6 call 5 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_key_V7(c, &method->nested.identity_join_identity_as_key_V7))
        break;
    case 1542: /* module 6 call 6 */
        CHECK_ERROR(_readMethod_identity_join_identity_as_identity_V7(c, &method->nested.identity_join_identity_as_identity_V7))
        break;
    case 1543: /* module 6 call 7 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_key_V7(c, &method->nested.identity_leave_identity_as_key_V7))
        break;
    case 1544: /* module 6 call 8 */
        CHECK_ERROR(_readMethod_identity_leave_identity_as_identity_V7(c, &method->nested.identity_leave_identity_as_identity_V7))
        break;
    case 1545: /* module 6 call 9 */
        CHECK_ERROR(_readMethod_identity_add_claim_V7(c, &method->nested.identity_add_claim_V7))
        break;
    case 1547: /* module 6 call 11 */
        CHECK_ERROR(_readMethod_identity_revoke_claim_V7(c, &method->nested.identity_revoke_claim_V7))
        break;
    case 1548: /* module 6 call 12 */
        CHECK_ERROR(_readMethod_identity_set_permission_to_signer_V7(c, &method->nested.identity_set_permission_to_signer_V7))
        break;
    case 1549: /* module 6 call 13 */
        CHECK_ERROR(_readMethod_identity_legacy_set_permission_to_signer_V7(c, &method->nested.identity_legacy_set_permission_to_signer_V7))
        break;
    case 1550: /* module 6 call 14 */
        CHECK_ERROR(_readMethod_identity_freeze_secondary_keys_V7(c, &method->nested.identity_freeze_secondary_keys_V7))
        break;
    case 1551: /* module 6 call 15 */
        CHECK_ERROR(_readMethod_identity_unfreeze_secondary_keys_V7(c, &method->nested.identity_unfreeze_secondary_keys_V7))
        break;
    case 1552: /* module 6 call 16 */
        CHECK_ERROR(_readMethod_identity_add_authorization_V7(c, &method->nested.identity_add_authorization_V7))
        break;
    case 1553: /* module 6 call 17 */
        CHECK_ERROR(_readMethod_identity_remove_authorization_V7(c, &method->nested.identity_remove_authorization_V7))
        break;
    case 1554: /* module 6 call 18 */
        CHECK_ERROR(_readMethod_identity_accept_authorization_V7(c, &method->nested.identity_accept_authorization_V7))
        break;
    case 1555: /* module 6 call 19 */
        CHECK_ERROR(_readMethod_identity_add_secondary_keys_with_authorization_V7(c, &method->nested.identity_add_secondary_keys_with_authorization_V7))
        break;
    case 1557: /* module 6 call 21 */
        CHECK_ERROR(_readMethod_identity_add_investor_uniqueness_claim_V7(c, &method->nested.identity_add_investor_uniqueness_claim_V7))
        break;
    case 2048: /* module 8 call 0 */
        CHECK_ERROR(_readMethod_staking_bond_V7(c, &method->nested.staking_bond_V7))
        break;
    case 2049: /* module 8 call 1 */
        CHECK_ERROR(_readMethod_staking_bond_extra_V7(c, &method->nested.staking_bond_extra_V7))
        break;
    case 2050: /* module 8 call 2 */
        CHECK_ERROR(_readMethod_staking_unbond_V7(c, &method->nested.staking_unbond_V7))
        break;
    case 2051: /* module 8 call 3 */
        CHECK_ERROR(_readMethod_staking_withdraw_unbonded_V7(c, &method->nested.staking_withdraw_unbonded_V7))
        break;
    case 2052: /* module 8 call 4 */
        CHECK_ERROR(_readMethod_staking_validate_V7(c, &method->nested.staking_validate_V7))
        break;
    case 2053: /* module 8 call 5 */
        CHECK_ERROR(_readMethod_staking_nominate_V7(c, &method->nested.staking_nominate_V7))
        break;
    case 2054: /* module 8 call 6 */
        CHECK_ERROR(_readMethod_staking_chill_V7(c, &method->nested.staking_chill_V7))
        break;
    case 2055: /* module 8 call 7 */
        CHECK_ERROR(_readMethod_staking_set_payee_V7(c, &method->nested.staking_set_payee_V7))
        break;
    case 2056: /* module 8 call 8 */
        CHECK_ERROR(_readMethod_staking_set_controller_V7(c, &method->nested.staking_set_controller_V7))
        break;
    case 2072: /* module 8 call 24 */
        CHECK_ERROR(_readMethod_staking_rebond_V7(c, &method->nested.staking_rebond_V7))
        break;
    case 4608: /* module 18 call 0 */
        CHECK_ERROR(_readMethod_multisig_create_multisig_V7(c, &method->nested.multisig_create_multisig_V7))
        break;
    case 4609: /* module 18 call 1 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_identity_V7(c, &method->nested.multisig_create_or_approve_proposal_as_identity_V7))
        break;
    case 4610: /* module 18 call 2 */
        CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_key_V7(c, &method->nested.multisig_create_or_approve_proposal_as_key_V7))
        break;
    case 4611: /* module 18 call 3 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_identity_V7(c, &method->nested.multisig_create_proposal_as_identity_V7))
        break;
    case 4612: /* module 18 call 4 */
        CHECK_ERROR(_readMethod_multisig_create_proposal_as_key_V7(c, &method->nested.multisig_create_proposal_as_key_V7))
        break;
    case 4613: /* module 18 call 5 */
        CHECK_ERROR(_readMethod_multisig_approve_as_identity_V7(c, &method->nested.multisig_approve_as_identity_V7))
        break;
    case 4614: /* module 18 call 6 */
        CHECK_ERROR(_readMethod_multisig_approve_as_key_V7(c, &method->nested.multisig_approve_as_key_V7))
        break;
    case 4615: /* module 18 call 7 */
        CHECK_ERROR(_readMethod_multisig_reject_as_identity_V7(c, &method->nested.multisig_reject_as_identity_V7))
        break;
    case 4616: /* module 18 call 8 */
        CHECK_ERROR(_readMethod_multisig_reject_as_key_V7(c, &method->nested.multisig_reject_as_key_V7))
        break;
    case 4617: /* module 18 call 9 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_identity_V7(c, &method->nested.multisig_accept_multisig_signer_as_identity_V7))
        break;
    case 4618: /* module 18 call 10 */
        CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_key_V7(c, &method->nested.multisig_accept_multisig_signer_as_key_V7))
        break;
    case 4619: /* module 18 call 11 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signer_V7(c, &method->nested.multisig_add_multisig_signer_V7))
        break;
    case 4620: /* module 18 call 12 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signer_V7(c, &method->nested.multisig_remove_multisig_signer_V7))
        break;
    case 4621: /* module 18 call 13 */
        CHECK_ERROR(_readMethod_multisig_add_multisig_signers_via_creator_V7(c, &method->nested.multisig_add_multisig_signers_via_creator_V7))
        break;
    case 4622: /* module 18 call 14 */
        CHECK_ERROR(_readMethod_multisig_remove_multisig_signers_via_creator_V7(c, &method->nested.multisig_remove_multisig_signers_via_creator_V7))
        break;
    case 4623: /* module 18 call 15 */
        CHECK_ERROR(_readMethod_multisig_change_sigs_required_V7(c, &method->nested.multisig_change_sigs_required_V7))
        break;
    case 4624: /* module 18 call 16 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_signer_V7(c, &method->nested.multisig_make_multisig_signer_V7))
        break;
    case 4625: /* module 18 call 17 */
        CHECK_ERROR(_readMethod_multisig_make_multisig_primary_V7(c, &method->nested.multisig_make_multisig_primary_V7))
        break;
    case 4626: /* module 18 call 18 */
        CHECK_ERROR(_readMethod_multisig_execute_scheduled_proposal_V7(c, &method->nested.multisig_execute_scheduled_proposal_V7))
        break;
    case 6150: /* module 24 call 6 */
        CHECK_ERROR(_readMethod_pips_propose_V7(c, &method->nested.pips_propose_V7))
        break;
    case 6151: /* module 24 call 7 */
        CHECK_ERROR(_readMethod_pips_vote_V7(c, &method->nested.pips_vote_V7))
        break;
    case 10496: /* module 41 call 0 */
        CHECK_ERROR(_readMethod_utility_batch_V7(c, &method->nested.utility_batch_V7))
        break;
    case 10497: /* module 41 call 1 */
        CHECK_ERROR(_readMethod_utility_batch_atomic_V7(c, &method->nested.utility_batch_atomic_V7))
        break;
    case 10498: /* module 41 call 2 */
        CHECK_ERROR(_readMethod_utility_batch_optimistic_V7(c, &method->nested.utility_batch_optimistic_V7))
        break;

#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        CHECK_ERROR(_readMethod_system_fill_block_V7(c, &method->nested.system_fill_block_V7))
        break;
    case 1: /* module 0 call 1 */
        CHECK_ERROR(_readMethod_system_remark_V7(c, &method->nested.system_remark_V7))
        break;
    case 2: /* module 0 call 2 */
        CHECK_ERROR(_readMethod_system_set_heap_pages_V7(c, &method->nested.system_set_heap_pages_V7))
        break;
    case 3: /* module 0 call 3 */
        CHECK_ERROR(_readMethod_system_set_code_V7(c, &method->nested.system_set_code_V7))
        break;
    case 4: /* module 0 call 4 */
        CHECK_ERROR(_readMethod_system_set_code_without_checks_V7(c, &method->nested.system_set_code_without_checks_V7))
        break;
    case 5: /* module 0 call 5 */
        CHECK_ERROR(_readMethod_system_set_changes_trie_config_V7(c, &method->nested.system_set_changes_trie_config_V7))
        break;
    case 6: /* module 0 call 6 */
        CHECK_ERROR(_readMethod_system_set_storage_V7(c, &method->nested.system_set_storage_V7))
        break;
    case 7: /* module 0 call 7 */
        CHECK_ERROR(_readMethod_system_kill_storage_V7(c, &method->nested.system_kill_storage_V7))
        break;
    case 8: /* module 0 call 8 */
        CHECK_ERROR(_readMethod_system_kill_prefix_V7(c, &method->nested.system_kill_prefix_V7))
        break;
    case 9: /* module 0 call 9 */
        CHECK_ERROR(_readMethod_system_suicide_V7(c, &method->nested.system_suicide_V7))
        break;
    case 256: /* module 1 call 0 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_V7(c, &method->nested.babe_report_equivocation_V7))
        break;
    case 257: /* module 1 call 1 */
        CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned_V7(c, &method->nested.babe_report_equivocation_unsigned_V7))
        break;
    case 512: /* module 2 call 0 */
        CHECK_ERROR(_readMethod_timestamp_set_V7(c, &method->nested.timestamp_set_V7))
        break;
    case 768: /* module 3 call 0 */
        CHECK_ERROR(_readMethod_indices_claim_V7(c, &method->nested.indices_claim_V7))
        break;
    case 769: /* module 3 call 1 */
        CHECK_ERROR(_readMethod_indices_transfer_V7(c, &method->nested.indices_transfer_V7))
        break;
    case 770: /* module 3 call 2 */
        CHECK_ERROR(_readMethod_indices_free_V7(c, &method->nested.indices_free_V7))
        break;
    case 771: /* module 3 call 3 */
        CHECK_ERROR(_readMethod_indices_force_transfer_V7(c, &method->nested.indices_force_transfer_V7))
        break;
    case 772: /* module 3 call 4 */
        CHECK_ERROR(_readMethod_indices_freeze_V7(c, &method->nested.indices_freeze_V7))
        break;
    case 1026: /* module 4 call 2 */
        CHECK_ERROR(_readMethod_balances_deposit_block_reward_reserve_balance_V7(c, &method->nested.balances_deposit_block_reward_reserve_balance_V7))
        break;
    case 1027: /* module 4 call 3 */
        CHECK_ERROR(_readMethod_balances_set_balance_V7(c, &method->nested.balances_set_balance_V7))
        break;
    case 1028: /* module 4 call 4 */
        CHECK_ERROR(_readMethod_balances_force_transfer_V7(c, &method->nested.balances_force_transfer_V7))
        break;
    case 1029: /* module 4 call 5 */
        CHECK_ERROR(_readMethod_balances_burn_account_balance_V7(c, &method->nested.balances_burn_account_balance_V7))
        break;
    case 1536: /* module 6 call 0 */
        CHECK_ERROR(_readMethod_identity_cdd_register_did_V7(c, &method->nested.identity_cdd_register_did_V7))
        break;
    case 1537: /* module 6 call 1 */
        CHECK_ERROR(_readMethod_identity_invalidate_cdd_claims_V7(c, &method->nested.identity_invalidate_cdd_claims_V7))
        break;
    case 1540: /* module 6 call 4 */
        CHECK_ERROR(_readMethod_identity_change_cdd_requirement_for_mk_rotation_V7(c, &method->nested.identity_change_cdd_requirement_for_mk_rotation_V7))
        break;
    case 1546: /* module 6 call 10 */
        CHECK_ERROR(_readMethod_identity_forwarded_call_V7(c, &method->nested.identity_forwarded_call_V7))
        break;
    case 1556: /* module 6 call 20 */
        CHECK_ERROR(_readMethod_identity_revoke_offchain_authorization_V7(c, &method->nested.identity_revoke_offchain_authorization_V7))
        break;
    case 1558: /* module 6 call 22 */
        CHECK_ERROR(_readMethod_identity_gc_add_cdd_claim_V7(c, &method->nested.identity_gc_add_cdd_claim_V7))
        break;
    case 1559: /* module 6 call 23 */
        CHECK_ERROR(_readMethod_identity_gc_revoke_cdd_claim_V7(c, &method->nested.identity_gc_revoke_cdd_claim_V7))
        break;
    case 1560: /* module 6 call 24 */
        CHECK_ERROR(_readMethod_identity_add_investor_uniqueness_claim_v2_V7(c, &method->basic.identity_add_investor_uniqueness_claim_v2_V7))
        break;
    case 1792: /* module 7 call 0 */
        CHECK_ERROR(_readMethod_authorship_set_uncles_V7(c, &method->nested.authorship_set_uncles_V7))
        break;
    case 9728: /* module 38 call 0 */
        CHECK_ERROR(_readMethod_cddserviceproviders_set_active_members_limit_V7(c, &method->nested.cddserviceproviders_set_active_members_limit_V7))
        break;
    case 9729: /* module 38 call 1 */
        CHECK_ERROR(_readMethod_cddserviceproviders_disable_member_V7(c, &method->nested.cddserviceproviders_disable_member_V7))
        break;
    case 9730: /* module 38 call 2 */
        CHECK_ERROR(_readMethod_cddserviceproviders_add_member_V7(c, &method->nested.cddserviceproviders_add_member_V7))
        break;
    case 9731: /* module 38 call 3 */
        CHECK_ERROR(_readMethod_cddserviceproviders_remove_member_V7(c, &method->nested.cddserviceproviders_remove_member_V7))
        break;
    case 9732: /* module 38 call 4 */
        CHECK_ERROR(_readMethod_cddserviceproviders_swap_member_V7(c, &method->nested.cddserviceproviders_swap_member_V7))
        break;
    case 9733: /* module 38 call 5 */
        CHECK_ERROR(_readMethod_cddserviceproviders_reset_members_V7(c, &method->nested.cddserviceproviders_reset_members_V7))
        break;
    case 9734: /* module 38 call 6 */
        CHECK_ERROR(_readMethod_cddserviceproviders_abdicate_membership_V7(c, &method->nested.cddserviceproviders_abdicate_membership_V7))
        break;
    case 2057: /* module 8 call 9 */
        CHECK_ERROR(_readMethod_staking_set_validator_count_V7(c, &method->nested.staking_set_validator_count_V7))
        break;
    case 2058: /* module 8 call 10 */
        CHECK_ERROR(_readMethod_staking_increase_validator_count_V7(c, &method->nested.staking_increase_validator_count_V7))
        break;
    case 2059: /* module 8 call 11 */
        CHECK_ERROR(_readMethod_staking_scale_validator_count_V7(c, &method->nested.staking_scale_validator_count_V7))
        break;
    case 2060: /* module 8 call 12 */
        CHECK_ERROR(_readMethod_staking_add_permissioned_validator_V7(c, &method->nested.staking_add_permissioned_validator_V7))
        break;
    case 2061: /* module 8 call 13 */
        CHECK_ERROR(_readMethod_staking_remove_permissioned_validator_V7(c, &method->nested.staking_remove_permissioned_validator_V7))
        break;
    case 2062: /* module 8 call 14 */
        CHECK_ERROR(_readMethod_staking_validate_cdd_expiry_nominators_V7(c, &method->nested.staking_validate_cdd_expiry_nominators_V7))
        break;
    case 2063: /* module 8 call 15 */
        CHECK_ERROR(_readMethod_staking_set_commission_cap_V7(c, &method->nested.staking_set_commission_cap_V7))
        break;
    case 2064: /* module 8 call 16 */
        CHECK_ERROR(_readMethod_staking_set_min_bond_threshold_V7(c, &method->nested.staking_set_min_bond_threshold_V7))
        break;
    case 2065: /* module 8 call 17 */
        CHECK_ERROR(_readMethod_staking_force_no_eras_V7(c, &method->nested.staking_force_no_eras_V7))
        break;
    case 2066: /* module 8 call 18 */
        CHECK_ERROR(_readMethod_staking_force_new_era_V7(c, &method->nested.staking_force_new_era_V7))
        break;
    case 2067: /* module 8 call 19 */
        CHECK_ERROR(_readMethod_staking_set_invulnerables_V7(c, &method->nested.staking_set_invulnerables_V7))
        break;
    case 2068: /* module 8 call 20 */
        CHECK_ERROR(_readMethod_staking_force_unstake_V7(c, &method->nested.staking_force_unstake_V7))
        break;
    case 2069: /* module 8 call 21 */
        CHECK_ERROR(_readMethod_staking_force_new_era_always_V7(c, &method->nested.staking_force_new_era_always_V7))
        break;
    case 2070: /* module 8 call 22 */
        CHECK_ERROR(_readMethod_staking_cancel_deferred_slash_V7(c, &method->nested.staking_cancel_deferred_slash_V7))
        break;
    case 2071: /* module 8 call 23 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_V7(c, &method->nested.staking_payout_stakers_V7))
        break;
    case 2073: /* module 8 call 25 */
        CHECK_ERROR(_readMethod_staking_set_history_depth_V7(c, &method->nested.staking_set_history_depth_V7))
        break;
    case 2074: /* module 8 call 26 */
        CHECK_ERROR(_readMethod_staking_reap_stash_V7(c, &method->nested.staking_reap_stash_V7))
        break;
    case 2075: /* module 8 call 27 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_V7(c, &method->nested.staking_submit_election_solution_V7))
        break;
    case 2076: /* module 8 call 28 */
        CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned_V7(c, &method->nested.staking_submit_election_solution_unsigned_V7))
        break;
    case 2077: /* module 8 call 29 */
        CHECK_ERROR(_readMethod_staking_payout_stakers_by_system_V7(c, &method->nested.staking_payout_stakers_by_system_V7))
        break;
    case 2078: /* module 8 call 30 */
        CHECK_ERROR(_readMethod_staking_change_slashing_allowed_for_V7(c, &method->nested.staking_change_slashing_allowed_for_V7))
        break;
    case 2079: /* module 8 call 31 */
        CHECK_ERROR(_readMethod_staking_update_permissioned_validator_intended_count_V7(c, &method->nested.staking_update_permissioned_validator_intended_count_V7))
        break;
    case 2560: /* module 10 call 0 */
        CHECK_ERROR(_readMethod_session_set_keys_V7(c, &method->nested.session_set_keys_V7))
        break;
    case 2561: /* module 10 call 1 */
        CHECK_ERROR(_readMethod_session_purge_keys_V7(c, &method->nested.session_purge_keys_V7))
        break;
    case 2816: /* module 11 call 0 */
        CHECK_ERROR(_readMethod_finalitytracker_final_hint_V7(c, &method->nested.finalitytracker_final_hint_V7))
        break;
    case 3072: /* module 12 call 0 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_V7(c, &method->nested.grandpa_report_equivocation_V7))
        break;
    case 3073: /* module 12 call 1 */
        CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned_V7(c, &method->nested.grandpa_report_equivocation_unsigned_V7))
        break;
    case 3074: /* module 12 call 2 */
        CHECK_ERROR(_readMethod_grandpa_note_stalled_V7(c, &method->nested.grandpa_note_stalled_V7))
        break;
    case 3328: /* module 13 call 0 */
        CHECK_ERROR(_readMethod_imonline_heartbeat_V7(c, &method->nested.imonline_heartbeat_V7))
        break;
    case 4352: /* module 17 call 0 */
        CHECK_ERROR(_readMethod_sudo_sudo_V7(c, &method->nested.sudo_sudo_V7))
        break;
    case 4353: /* module 17 call 1 */
        CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight_V7(c, &method->nested.sudo_sudo_unchecked_weight_V7))
        break;
    case 4354: /* module 17 call 2 */
        CHECK_ERROR(_readMethod_sudo_set_key_V7(c, &method->nested.sudo_set_key_V7))
        break;
    case 4355: /* module 17 call 3 */
        CHECK_ERROR(_readMethod_sudo_sudo_as_V7(c, &method->nested.sudo_sudo_as_V7))
        break;
    case 5120: /* module 20 call 0 */
        CHECK_ERROR(_readMethod_contracts_update_schedule_V7(c, &method->nested.contracts_update_schedule_V7))
        break;
    case 5121: /* module 20 call 1 */
        CHECK_ERROR(_readMethod_contracts_set_put_code_flag_V7(c, &method->basic.contracts_set_put_code_flag_V7))
        break;
    case 5122: /* module 20 call 2 */
        CHECK_ERROR(_readMethod_contracts_put_code_V7(c, &method->nested.contracts_put_code_V7))
        break;
    case 5123: /* module 20 call 3 */
        CHECK_ERROR(_readMethod_contracts_call_V7(c, &method->nested.contracts_call_V7))
        break;
    case 5124: /* module 20 call 4 */
        CHECK_ERROR(_readMethod_contracts_instantiate_V7(c, &method->nested.contracts_instantiate_V7))
        break;
    case 5125: /* module 20 call 5 */
        CHECK_ERROR(_readMethod_contracts_freeze_instantiation_V7(c, &method->nested.contracts_freeze_instantiation_V7))
        break;
    case 5126: /* module 20 call 6 */
        CHECK_ERROR(_readMethod_contracts_unfreeze_instantiation_V7(c, &method->nested.contracts_unfreeze_instantiation_V7))
        break;
    case 5127: /* module 20 call 7 */
        CHECK_ERROR(_readMethod_contracts_transfer_template_ownership_V7(c, &method->nested.contracts_transfer_template_ownership_V7))
        break;
    case 5128: /* module 20 call 8 */
        CHECK_ERROR(_readMethod_contracts_change_template_fees_V7(c, &method->nested.contracts_change_template_fees_V7))
        break;
    case 5129: /* module 20 call 9 */
        CHECK_ERROR(_readMethod_contracts_change_template_meta_url_V7(c, &method->nested.contracts_change_template_meta_url_V7))
        break;
    case 5376: /* module 21 call 0 */
        CHECK_ERROR(_readMethod_treasury_disbursement_V7(c, &method->nested.treasury_disbursement_V7))
        break;
    case 5377: /* module 21 call 1 */
        CHECK_ERROR(_readMethod_treasury_reimbursement_V7(c, &method->nested.treasury_reimbursement_V7))
        break;
    case 5632: /* module 22 call 0 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_vote_threshold_V7(c, &method->nested.polymeshcommittee_set_vote_threshold_V7))
        break;
    case 5633: /* module 22 call 1 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_release_coordinator_V7(c, &method->nested.polymeshcommittee_set_release_coordinator_V7))
        break;
    case 5634: /* module 22 call 2 */
        CHECK_ERROR(_readMethod_polymeshcommittee_set_expires_after_V7(c, &method->nested.polymeshcommittee_set_expires_after_V7))
        break;
    case 5635: /* module 22 call 3 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_or_propose_V7(c, &method->nested.polymeshcommittee_vote_or_propose_V7))
        break;
    case 5636: /* module 22 call 4 */
        CHECK_ERROR(_readMethod_polymeshcommittee_vote_V7(c, &method->nested.polymeshcommittee_vote_V7))
        break;
    case 5888: /* module 23 call 0 */
        CHECK_ERROR(_readMethod_committeemembership_set_active_members_limit_V7(c, &method->nested.committeemembership_set_active_members_limit_V7))
        break;
    case 5889: /* module 23 call 1 */
        CHECK_ERROR(_readMethod_committeemembership_disable_member_V7(c, &method->nested.committeemembership_disable_member_V7))
        break;
    case 5890: /* module 23 call 2 */
        CHECK_ERROR(_readMethod_committeemembership_add_member_V7(c, &method->nested.committeemembership_add_member_V7))
        break;
    case 5891: /* module 23 call 3 */
        CHECK_ERROR(_readMethod_committeemembership_remove_member_V7(c, &method->nested.committeemembership_remove_member_V7))
        break;
    case 5892: /* module 23 call 4 */
        CHECK_ERROR(_readMethod_committeemembership_swap_member_V7(c, &method->nested.committeemembership_swap_member_V7))
        break;
    case 5893: /* module 23 call 5 */
        CHECK_ERROR(_readMethod_committeemembership_reset_members_V7(c, &method->nested.committeemembership_reset_members_V7))
        break;
    case 5894: /* module 23 call 6 */
        CHECK_ERROR(_readMethod_committeemembership_abdicate_membership_V7(c, &method->nested.committeemembership_abdicate_membership_V7))
        break;
    case 6144: /* module 24 call 0 */
        CHECK_ERROR(_readMethod_pips_set_prune_historical_pips_V7(c, &method->nested.pips_set_prune_historical_pips_V7))
        break;
    case 6145: /* module 24 call 1 */
        CHECK_ERROR(_readMethod_pips_set_min_proposal_deposit_V7(c, &method->nested.pips_set_min_proposal_deposit_V7))
        break;
    case 6146: /* module 24 call 2 */
        CHECK_ERROR(_readMethod_pips_set_default_enactment_period_V7(c, &method->nested.pips_set_default_enactment_period_V7))
        break;
    case 6147: /* module 24 call 3 */
        CHECK_ERROR(_readMethod_pips_set_pending_pip_expiry_V7(c, &method->nested.pips_set_pending_pip_expiry_V7))
        break;
    case 6148: /* module 24 call 4 */
        CHECK_ERROR(_readMethod_pips_set_max_pip_skip_count_V7(c, &method->nested.pips_set_max_pip_skip_count_V7))
        break;
    case 6149: /* module 24 call 5 */
        CHECK_ERROR(_readMethod_pips_set_active_pip_limit_V7(c, &method->nested.pips_set_active_pip_limit_V7))
        break;
    case 6152: /* module 24 call 8 */
        CHECK_ERROR(_readMethod_pips_approve_committee_proposal_V7(c, &method->nested.pips_approve_committee_proposal_V7))
        break;
    case 6153: /* module 24 call 9 */
        CHECK_ERROR(_readMethod_pips_reject_proposal_V7(c, &method->nested.pips_reject_proposal_V7))
        break;
    case 6154: /* module 24 call 10 */
        CHECK_ERROR(_readMethod_pips_prune_proposal_V7(c, &method->nested.pips_prune_proposal_V7))
        break;
    case 6155: /* module 24 call 11 */
        CHECK_ERROR(_readMethod_pips_reschedule_execution_V7(c, &method->nested.pips_reschedule_execution_V7))
        break;
    case 6156: /* module 24 call 12 */
        CHECK_ERROR(_readMethod_pips_clear_snapshot_V7(c, &method->nested.pips_clear_snapshot_V7))
        break;
    case 6157: /* module 24 call 13 */
        CHECK_ERROR(_readMethod_pips_snapshot_V7(c, &method->nested.pips_snapshot_V7))
        break;
    case 6158: /* module 24 call 14 */
        CHECK_ERROR(_readMethod_pips_enact_snapshot_results_V7(c, &method->nested.pips_enact_snapshot_results_V7))
        break;
    case 6159: /* module 24 call 15 */
        CHECK_ERROR(_readMethod_pips_execute_scheduled_pip_V7(c, &method->nested.pips_execute_scheduled_pip_V7))
        break;
    case 6160: /* module 24 call 16 */
        CHECK_ERROR(_readMethod_pips_expire_scheduled_pip_V7(c, &method->nested.pips_expire_scheduled_pip_V7))
        break;
    case 6400: /* module 25 call 0 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_vote_threshold_V7(c, &method->nested.technicalcommittee_set_vote_threshold_V7))
        break;
    case 6401: /* module 25 call 1 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_release_coordinator_V7(c, &method->nested.technicalcommittee_set_release_coordinator_V7))
        break;
    case 6402: /* module 25 call 2 */
        CHECK_ERROR(_readMethod_technicalcommittee_set_expires_after_V7(c, &method->nested.technicalcommittee_set_expires_after_V7))
        break;
    case 6403: /* module 25 call 3 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_or_propose_V7(c, &method->nested.technicalcommittee_vote_or_propose_V7))
        break;
    case 6404: /* module 25 call 4 */
        CHECK_ERROR(_readMethod_technicalcommittee_vote_V7(c, &method->nested.technicalcommittee_vote_V7))
        break;
    case 6656: /* module 26 call 0 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_set_active_members_limit_V7(c, &method->nested.technicalcommitteemembership_set_active_members_limit_V7))
        break;
    case 6657: /* module 26 call 1 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_disable_member_V7(c, &method->nested.technicalcommitteemembership_disable_member_V7))
        break;
    case 6658: /* module 26 call 2 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member_V7(c, &method->nested.technicalcommitteemembership_add_member_V7))
        break;
    case 6659: /* module 26 call 3 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member_V7(c, &method->nested.technicalcommitteemembership_remove_member_V7))
        break;
    case 6660: /* module 26 call 4 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member_V7(c, &method->nested.technicalcommitteemembership_swap_member_V7))
        break;
    case 6661: /* module 26 call 5 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members_V7(c, &method->nested.technicalcommitteemembership_reset_members_V7))
        break;
    case 6662: /* module 26 call 6 */
        CHECK_ERROR(_readMethod_technicalcommitteemembership_abdicate_membership_V7(c, &method->nested.technicalcommitteemembership_abdicate_membership_V7))
        break;
    case 6912: /* module 27 call 0 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_vote_threshold_V7(c, &method->nested.upgradecommittee_set_vote_threshold_V7))
        break;
    case 6913: /* module 27 call 1 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_release_coordinator_V7(c, &method->nested.upgradecommittee_set_release_coordinator_V7))
        break;
    case 6914: /* module 27 call 2 */
        CHECK_ERROR(_readMethod_upgradecommittee_set_expires_after_V7(c, &method->nested.upgradecommittee_set_expires_after_V7))
        break;
    case 6915: /* module 27 call 3 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_or_propose_V7(c, &method->nested.upgradecommittee_vote_or_propose_V7))
        break;
    case 6916: /* module 27 call 4 */
        CHECK_ERROR(_readMethod_upgradecommittee_vote_V7(c, &method->nested.upgradecommittee_vote_V7))
        break;
    case 7168: /* module 28 call 0 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_set_active_members_limit_V7(c, &method->nested.upgradecommitteemembership_set_active_members_limit_V7))
        break;
    case 7169: /* module 28 call 1 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_disable_member_V7(c, &method->nested.upgradecommitteemembership_disable_member_V7))
        break;
    case 7170: /* module 28 call 2 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_add_member_V7(c, &method->nested.upgradecommitteemembership_add_member_V7))
        break;
    case 7171: /* module 28 call 3 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_remove_member_V7(c, &method->nested.upgradecommitteemembership_remove_member_V7))
        break;
    case 7172: /* module 28 call 4 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_swap_member_V7(c, &method->nested.upgradecommitteemembership_swap_member_V7))
        break;
    case 7173: /* module 28 call 5 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_reset_members_V7(c, &method->nested.upgradecommitteemembership_reset_members_V7))
        break;
    case 7174: /* module 28 call 6 */
        CHECK_ERROR(_readMethod_upgradecommitteemembership_abdicate_membership_V7(c, &method->nested.upgradecommitteemembership_abdicate_membership_V7))
        break;
    case 7424: /* module 29 call 0 */
        CHECK_ERROR(_readMethod_asset_register_ticker_V7(c, &method->nested.asset_register_ticker_V7))
        break;
    case 7425: /* module 29 call 1 */
        CHECK_ERROR(_readMethod_asset_accept_ticker_transfer_V7(c, &method->nested.asset_accept_ticker_transfer_V7))
        break;
    case 7426: /* module 29 call 2 */
        CHECK_ERROR(_readMethod_asset_accept_primary_issuance_agent_transfer_V7(c, &method->nested.asset_accept_primary_issuance_agent_transfer_V7))
        break;
    case 7427: /* module 29 call 3 */
        CHECK_ERROR(_readMethod_asset_accept_asset_ownership_transfer_V7(c, &method->nested.asset_accept_asset_ownership_transfer_V7))
        break;
    case 7428: /* module 29 call 4 */
        CHECK_ERROR(_readMethod_asset_create_asset_V7(c, &method->nested.asset_create_asset_V7))
        break;
    case 7429: /* module 29 call 5 */
        CHECK_ERROR(_readMethod_asset_freeze_V7(c, &method->nested.asset_freeze_V7))
        break;
    case 7430: /* module 29 call 6 */
        CHECK_ERROR(_readMethod_asset_unfreeze_V7(c, &method->nested.asset_unfreeze_V7))
        break;
    case 7431: /* module 29 call 7 */
        CHECK_ERROR(_readMethod_asset_rename_asset_V7(c, &method->nested.asset_rename_asset_V7))
        break;
    case 7432: /* module 29 call 8 */
        CHECK_ERROR(_readMethod_asset_issue_V7(c, &method->nested.asset_issue_V7))
        break;
    case 7433: /* module 29 call 9 */
        CHECK_ERROR(_readMethod_asset_redeem_V7(c, &method->nested.asset_redeem_V7))
        break;
    case 7434: /* module 29 call 10 */
        CHECK_ERROR(_readMethod_asset_make_divisible_V7(c, &method->nested.asset_make_divisible_V7))
        break;
    case 7435: /* module 29 call 11 */
        CHECK_ERROR(_readMethod_asset_add_documents_V7(c, &method->nested.asset_add_documents_V7))
        break;
    case 7436: /* module 29 call 12 */
        CHECK_ERROR(_readMethod_asset_remove_documents_V7(c, &method->nested.asset_remove_documents_V7))
        break;
    case 7437: /* module 29 call 13 */
        CHECK_ERROR(_readMethod_asset_set_funding_round_V7(c, &method->nested.asset_set_funding_round_V7))
        break;
    case 7438: /* module 29 call 14 */
        CHECK_ERROR(_readMethod_asset_update_identifiers_V7(c, &method->nested.asset_update_identifiers_V7))
        break;
    case 7439: /* module 29 call 15 */
        CHECK_ERROR(_readMethod_asset_add_extension_V7(c, &method->nested.asset_add_extension_V7))
        break;
    case 7440: /* module 29 call 16 */
        CHECK_ERROR(_readMethod_asset_remove_smart_extension_V7(c, &method->nested.asset_remove_smart_extension_V7))
        break;
    case 7441: /* module 29 call 17 */
        CHECK_ERROR(_readMethod_asset_archive_extension_V7(c, &method->nested.asset_archive_extension_V7))
        break;
    case 7442: /* module 29 call 18 */
        CHECK_ERROR(_readMethod_asset_unarchive_extension_V7(c, &method->nested.asset_unarchive_extension_V7))
        break;
    case 7443: /* module 29 call 19 */
        CHECK_ERROR(_readMethod_asset_remove_primary_issuance_agent_V7(c, &method->nested.asset_remove_primary_issuance_agent_V7))
        break;
    case 7444: /* module 29 call 20 */
        CHECK_ERROR(_readMethod_asset_claim_classic_ticker_V7(c, &method->nested.asset_claim_classic_ticker_V7))
        break;
    case 7445: /* module 29 call 21 */
        CHECK_ERROR(_readMethod_asset_reserve_classic_ticker_V7(c, &method->nested.asset_reserve_classic_ticker_V7))
        break;
    case 7446: /* module 29 call 22 */
        CHECK_ERROR(_readMethod_asset_controller_transfer_V7(c, &method->basic.asset_controller_transfer_V7))
        break;
    case 7936: /* module 31 call 0 */
        CHECK_ERROR(_readMethod_bridge_change_controller_V7(c, &method->nested.bridge_change_controller_V7))
        break;
    case 7937: /* module 31 call 1 */
        CHECK_ERROR(_readMethod_bridge_change_admin_V7(c, &method->nested.bridge_change_admin_V7))
        break;
    case 7938: /* module 31 call 2 */
        CHECK_ERROR(_readMethod_bridge_change_timelock_V7(c, &method->nested.bridge_change_timelock_V7))
        break;
    case 7939: /* module 31 call 3 */
        CHECK_ERROR(_readMethod_bridge_freeze_V7(c, &method->nested.bridge_freeze_V7))
        break;
    case 7940: /* module 31 call 4 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_V7(c, &method->nested.bridge_unfreeze_V7))
        break;
    case 7941: /* module 31 call 5 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_limit_V7(c, &method->nested.bridge_change_bridge_limit_V7))
        break;
    case 7942: /* module 31 call 6 */
        CHECK_ERROR(_readMethod_bridge_change_bridge_exempted_V7(c, &method->nested.bridge_change_bridge_exempted_V7))
        break;
    case 7943: /* module 31 call 7 */
        CHECK_ERROR(_readMethod_bridge_force_handle_bridge_tx_V7(c, &method->nested.bridge_force_handle_bridge_tx_V7))
        break;
    case 7944: /* module 31 call 8 */
        CHECK_ERROR(_readMethod_bridge_batch_propose_bridge_tx_V7(c, &method->nested.bridge_batch_propose_bridge_tx_V7))
        break;
    case 7945: /* module 31 call 9 */
        CHECK_ERROR(_readMethod_bridge_propose_bridge_tx_V7(c, &method->nested.bridge_propose_bridge_tx_V7))
        break;
    case 7946: /* module 31 call 10 */
        CHECK_ERROR(_readMethod_bridge_handle_bridge_tx_V7(c, &method->nested.bridge_handle_bridge_tx_V7))
        break;
    case 7947: /* module 31 call 11 */
        CHECK_ERROR(_readMethod_bridge_freeze_txs_V7(c, &method->nested.bridge_freeze_txs_V7))
        break;
    case 7948: /* module 31 call 12 */
        CHECK_ERROR(_readMethod_bridge_unfreeze_txs_V7(c, &method->nested.bridge_unfreeze_txs_V7))
        break;
    case 7949: /* module 31 call 13 */
        CHECK_ERROR(_readMethod_bridge_handle_scheduled_bridge_tx_V7(c, &method->nested.bridge_handle_scheduled_bridge_tx_V7))
        break;
    case 8192: /* module 32 call 0 */
        CHECK_ERROR(_readMethod_compliancemanager_add_compliance_requirement_V7(c, &method->nested.compliancemanager_add_compliance_requirement_V7))
        break;
    case 8193: /* module 32 call 1 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_compliance_requirement_V7(c, &method->nested.compliancemanager_remove_compliance_requirement_V7))
        break;
    case 8194: /* module 32 call 2 */
        CHECK_ERROR(_readMethod_compliancemanager_replace_asset_compliance_V7(c, &method->nested.compliancemanager_replace_asset_compliance_V7))
        break;
    case 8195: /* module 32 call 3 */
        CHECK_ERROR(_readMethod_compliancemanager_reset_asset_compliance_V7(c, &method->nested.compliancemanager_reset_asset_compliance_V7))
        break;
    case 8196: /* module 32 call 4 */
        CHECK_ERROR(_readMethod_compliancemanager_pause_asset_compliance_V7(c, &method->nested.compliancemanager_pause_asset_compliance_V7))
        break;
    case 8197: /* module 32 call 5 */
        CHECK_ERROR(_readMethod_compliancemanager_resume_asset_compliance_V7(c, &method->nested.compliancemanager_resume_asset_compliance_V7))
        break;
    case 8198: /* module 32 call 6 */
        CHECK_ERROR(_readMethod_compliancemanager_add_default_trusted_claim_issuer_V7(c, &method->nested.compliancemanager_add_default_trusted_claim_issuer_V7))
        break;
    case 8199: /* module 32 call 7 */
        CHECK_ERROR(_readMethod_compliancemanager_remove_default_trusted_claim_issuer_V7(c, &method->nested.compliancemanager_remove_default_trusted_claim_issuer_V7))
        break;
    case 8200: /* module 32 call 8 */
        CHECK_ERROR(_readMethod_compliancemanager_change_compliance_requirement_V7(c, &method->nested.compliancemanager_change_compliance_requirement_V7))
        break;
    case 9216: /* module 36 call 0 */
        CHECK_ERROR(_readMethod_settlement_create_venue_V7(c, &method->nested.settlement_create_venue_V7))
        break;
    case 9217: /* module 36 call 1 */
        CHECK_ERROR(_readMethod_settlement_update_venue_V7(c, &method->nested.settlement_update_venue_V7))
        break;
    case 9218: /* module 36 call 2 */
        CHECK_ERROR(_readMethod_settlement_add_instruction_V7(c, &method->nested.settlement_add_instruction_V7))
        break;
    case 9219: /* module 36 call 3 */
        CHECK_ERROR(_readMethod_settlement_add_and_affirm_instruction_V7(c, &method->nested.settlement_add_and_affirm_instruction_V7))
        break;
    case 9220: /* module 36 call 4 */
        CHECK_ERROR(_readMethod_settlement_affirm_instruction_V7(c, &method->nested.settlement_affirm_instruction_V7))
        break;
    case 9221: /* module 36 call 5 */
        CHECK_ERROR(_readMethod_settlement_withdraw_affirmation_V7(c, &method->nested.settlement_withdraw_affirmation_V7))
        break;
    case 9222: /* module 36 call 6 */
        CHECK_ERROR(_readMethod_settlement_reject_instruction_V7(c, &method->nested.settlement_reject_instruction_V7))
        break;
    case 9223: /* module 36 call 7 */
        CHECK_ERROR(_readMethod_settlement_affirm_with_receipts_V7(c, &method->nested.settlement_affirm_with_receipts_V7))
        break;
    case 9224: /* module 36 call 8 */
        CHECK_ERROR(_readMethod_settlement_claim_receipt_V7(c, &method->nested.settlement_claim_receipt_V7))
        break;
    case 9225: /* module 36 call 9 */
        CHECK_ERROR(_readMethod_settlement_unclaim_receipt_V7(c, &method->nested.settlement_unclaim_receipt_V7))
        break;
    case 9226: /* module 36 call 10 */
        CHECK_ERROR(_readMethod_settlement_set_venue_filtering_V7(c, &method->nested.settlement_set_venue_filtering_V7))
        break;
    case 9227: /* module 36 call 11 */
        CHECK_ERROR(_readMethod_settlement_allow_venues_V7(c, &method->nested.settlement_allow_venues_V7))
        break;
    case 9228: /* module 36 call 12 */
        CHECK_ERROR(_readMethod_settlement_disallow_venues_V7(c, &method->nested.settlement_disallow_venues_V7))
        break;
    case 9229: /* module 36 call 13 */
        CHECK_ERROR(_readMethod_settlement_change_receipt_validity_V7(c, &method->basic.settlement_change_receipt_validity_V7))
        break;
    case 9230: /* module 36 call 14 */
        CHECK_ERROR(_readMethod_settlement_execute_scheduled_instruction_V7(c, &method->nested.settlement_execute_scheduled_instruction_V7))
        break;
    case 9472: /* module 37 call 0 */
        CHECK_ERROR(_readMethod_sto_create_fundraiser_V7(c, &method->basic.sto_create_fundraiser_V7))
        break;
    case 9473: /* module 37 call 1 */
        CHECK_ERROR(_readMethod_sto_invest_V7(c, &method->basic.sto_invest_V7))
        break;
    case 9474: /* module 37 call 2 */
        CHECK_ERROR(_readMethod_sto_freeze_fundraiser_V7(c, &method->basic.sto_freeze_fundraiser_V7))
        break;
    case 9475: /* module 37 call 3 */
        CHECK_ERROR(_readMethod_sto_unfreeze_fundraiser_V7(c, &method->basic.sto_unfreeze_fundraiser_V7))
        break;
    case 9476: /* module 37 call 4 */
        CHECK_ERROR(_readMethod_sto_modify_fundraiser_window_V7(c, &method->basic.sto_modify_fundraiser_window_V7))
        break;
    case 9477: /* module 37 call 5 */
        CHECK_ERROR(_readMethod_sto_stop_V7(c, &method->basic.sto_stop_V7))
        break;
    case 9984: /* module 39 call 0 */
        CHECK_ERROR(_readMethod_statistics_add_transfer_manager_V7(c, &method->nested.statistics_add_transfer_manager_V7))
        break;
    case 9985: /* module 39 call 1 */
        CHECK_ERROR(_readMethod_statistics_remove_transfer_manager_V7(c, &method->nested.statistics_remove_transfer_manager_V7))
        break;
    case 9986: /* module 39 call 2 */
        CHECK_ERROR(_readMethod_statistics_add_exempted_entities_V7(c, &method->nested.statistics_add_exempted_entities_V7))
        break;
    case 9987: /* module 39 call 3 */
        CHECK_ERROR(_readMethod_statistics_remove_exempted_entities_V7(c, &method->nested.statistics_remove_exempted_entities_V7))
        break;
    case 10240: /* module 40 call 0 */
        CHECK_ERROR(_readMethod_protocolfee_change_coefficient_V7(c, &method->nested.protocolfee_change_coefficient_V7))
        break;
    case 10241: /* module 40 call 1 */
        CHECK_ERROR(_readMethod_protocolfee_change_base_fee_V7(c, &method->nested.protocolfee_change_base_fee_V7))
        break;
    case 10499: /* module 41 call 3 */
        CHECK_ERROR(_readMethod_utility_relay_tx_V7(c, &method->nested.utility_relay_tx_V7))
        break;
    case 10752: /* module 42 call 0 */
        CHECK_ERROR(_readMethod_portfolio_create_portfolio_V7(c, &method->nested.portfolio_create_portfolio_V7))
        break;
    case 10753: /* module 42 call 1 */
        CHECK_ERROR(_readMethod_portfolio_delete_portfolio_V7(c, &method->nested.portfolio_delete_portfolio_V7))
        break;
    case 10754: /* module 42 call 2 */
        CHECK_ERROR(_readMethod_portfolio_move_portfolio_funds_V7(c, &method->nested.portfolio_move_portfolio_funds_V7))
        break;
    case 10755: /* module 42 call 3 */
        CHECK_ERROR(_readMethod_portfolio_rename_portfolio_V7(c, &method->nested.portfolio_rename_portfolio_V7))
        break;
    case 11520: /* module 45 call 0 */
        CHECK_ERROR(_readMethod_scheduler_schedule_V7(c, &method->nested.scheduler_schedule_V7))
        break;
    case 11521: /* module 45 call 1 */
        CHECK_ERROR(_readMethod_scheduler_cancel_V7(c, &method->nested.scheduler_cancel_V7))
        break;
    case 11522: /* module 45 call 2 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_V7(c, &method->nested.scheduler_schedule_named_V7))
        break;
    case 11523: /* module 45 call 3 */
        CHECK_ERROR(_readMethod_scheduler_cancel_named_V7(c, &method->nested.scheduler_cancel_named_V7))
        break;
    case 11524: /* module 45 call 4 */
        CHECK_ERROR(_readMethod_scheduler_schedule_after_V7(c, &method->nested.scheduler_schedule_after_V7))
        break;
    case 11525: /* module 45 call 5 */
        CHECK_ERROR(_readMethod_scheduler_schedule_named_after_V7(c, &method->nested.scheduler_schedule_named_after_V7))
        break;
    case 11776: /* module 46 call 0 */
        CHECK_ERROR(_readMethod_corporateaction_set_max_details_length_V7(c, &method->nested.corporateaction_set_max_details_length_V7))
        break;
    case 11777: /* module 46 call 1 */
        CHECK_ERROR(_readMethod_corporateaction_reset_caa_V7(c, &method->nested.corporateaction_reset_caa_V7))
        break;
    case 11778: /* module 46 call 2 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_targets_V7(c, &method->nested.corporateaction_set_default_targets_V7))
        break;
    case 11779: /* module 46 call 3 */
        CHECK_ERROR(_readMethod_corporateaction_set_default_withholding_tax_V7(c, &method->nested.corporateaction_set_default_withholding_tax_V7))
        break;
    case 11780: /* module 46 call 4 */
        CHECK_ERROR(_readMethod_corporateaction_set_did_withholding_tax_V7(c, &method->nested.corporateaction_set_did_withholding_tax_V7))
        break;
    case 11781: /* module 46 call 5 */
        CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action_V7(c, &method->nested.corporateaction_initiate_corporate_action_V7))
        break;
    case 11782: /* module 46 call 6 */
        CHECK_ERROR(_readMethod_corporateaction_link_ca_doc_V7(c, &method->nested.corporateaction_link_ca_doc_V7))
        break;
    case 11783: /* module 46 call 7 */
        CHECK_ERROR(_readMethod_corporateaction_remove_ca_V7(c, &method->nested.corporateaction_remove_ca_V7))
        break;
    case 11784: /* module 46 call 8 */
        CHECK_ERROR(_readMethod_corporateaction_change_record_date_V7(c, &method->nested.corporateaction_change_record_date_V7))
        break;
    case 12032: /* module 47 call 0 */
        CHECK_ERROR(_readMethod_corporateballot_attach_ballot_V7(c, &method->nested.corporateballot_attach_ballot_V7))
        break;
    case 12033: /* module 47 call 1 */
        CHECK_ERROR(_readMethod_corporateballot_vote_V7(c, &method->nested.corporateballot_vote_V7))
        break;
    case 12034: /* module 47 call 2 */
        CHECK_ERROR(_readMethod_corporateballot_change_end_V7(c, &method->nested.corporateballot_change_end_V7))
        break;
    case 12035: /* module 47 call 3 */
        CHECK_ERROR(_readMethod_corporateballot_change_meta_V7(c, &method->nested.corporateballot_change_meta_V7))
        break;
    case 12036: /* module 47 call 4 */
        CHECK_ERROR(_readMethod_corporateballot_change_rcv_V7(c, &method->nested.corporateballot_change_rcv_V7))
        break;
    case 12037: /* module 47 call 5 */
        CHECK_ERROR(_readMethod_corporateballot_remove_ballot_V7(c, &method->nested.corporateballot_remove_ballot_V7))
        break;
    case 12288: /* module 48 call 0 */
        CHECK_ERROR(_readMethod_capitaldistribution_distribute_V7(c, &method->nested.capitaldistribution_distribute_V7))
        break;
    case 12289: /* module 48 call 1 */
        CHECK_ERROR(_readMethod_capitaldistribution_claim_V7(c, &method->nested.capitaldistribution_claim_V7))
        break;
    case 12290: /* module 48 call 2 */
        CHECK_ERROR(_readMethod_capitaldistribution_push_benefit_V7(c, &method->nested.capitaldistribution_push_benefit_V7))
        break;
    case 12291: /* module 48 call 3 */
        CHECK_ERROR(_readMethod_capitaldistribution_reclaim_V7(c, &method->nested.capitaldistribution_reclaim_V7))
        break;
    case 12292: /* module 48 call 4 */
        CHECK_ERROR(_readMethod_capitaldistribution_remove_distribution_V7(c, &method->nested.capitaldistribution_remove_distribution_V7))
        break;
    case 12544: /* module 49 call 0 */
        CHECK_ERROR(_readMethod_checkpoint_create_checkpoint_V7(c, &method->nested.checkpoint_create_checkpoint_V7))
        break;
    case 12545: /* module 49 call 1 */
        CHECK_ERROR(_readMethod_checkpoint_set_schedules_max_complexity_V7(c, &method->nested.checkpoint_set_schedules_max_complexity_V7))
        break;
    case 12546: /* module 49 call 2 */
        CHECK_ERROR(_readMethod_checkpoint_create_schedule_V7(c, &method->nested.checkpoint_create_schedule_V7))
        break;
    case 12547: /* module 49 call 3 */
        CHECK_ERROR(_readMethod_checkpoint_remove_schedule_V7(c, &method->nested.checkpoint_remove_schedule_V7))
        break;
    case 12800: /* module 50 call 0 */
        CHECK_ERROR(_readMethod_testutils_register_did_V7(c, &method->basic.testutils_register_did_V7))
        break;
    case 12801: /* module 50 call 1 */
        CHECK_ERROR(_readMethod_testutils_mock_cdd_register_did_V7(c, &method->basic.testutils_mock_cdd_register_did_V7))
        break;
    case 12802: /* module 50 call 2 */
        CHECK_ERROR(_readMethod_testutils_get_my_did_V7(c, &method->basic.testutils_get_my_did_V7))
        break;
    case 12803: /* module 50 call 3 */
        CHECK_ERROR(_readMethod_testutils_get_cdd_of_V7(c, &method->basic.testutils_get_cdd_of_V7))
        break;
#endif
    default:
        return parser_not_supported;
    }

    return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char* _getMethod_ModuleName_V7(uint8_t moduleIdx)
{
    switch (moduleIdx) {
    case 4:
        return STR_MO_BALANCES;
    case 6:
        return STR_MO_IDENTITY;
    case 8:
        return STR_MO_STAKING;
    case 18:
        return STR_MO_MULTISIG;
    case 24:
        return STR_MO_PIPS;
    case 41:
        return STR_MO_UTILITY;
#ifdef SUBSTRATE_PARSER_FULL
    case 0:
        return STR_MO_SYSTEM;
    case 1:
        return STR_MO_BABE;
    case 2:
        return STR_MO_TIMESTAMP;
    case 3:
        return STR_MO_INDICES;
    case 7:
        return STR_MO_AUTHORSHIP;
    case 38:
        return STR_MO_CDDSERVICEPROVIDERS;
    case 9:
        return STR_MO_OFFENCES;
    case 10:
        return STR_MO_SESSION;
    case 11:
        return STR_MO_FINALITYTRACKER;
    case 12:
        return STR_MO_GRANDPA;
    case 13:
        return STR_MO_IMONLINE;
    case 14:
        return STR_MO_AUTHORITYDISCOVERY;
    case 15:
        return STR_MO_RANDOMNESSCOLLECTIVEFLIP;
    case 17:
        return STR_MO_SUDO;
    case 20:
        return STR_MO_CONTRACTS;
    case 21:
        return STR_MO_TREASURY;
    case 22:
        return STR_MO_POLYMESHCOMMITTEE;
    case 23:
        return STR_MO_COMMITTEEMEMBERSHIP;
    case 25:
        return STR_MO_TECHNICALCOMMITTEE;
    case 26:
        return STR_MO_TECHNICALCOMMITTEEMEMBERSHIP;
    case 27:
        return STR_MO_UPGRADECOMMITTEE;
    case 28:
        return STR_MO_UPGRADECOMMITTEEMEMBERSHIP;
    case 29:
        return STR_MO_ASSET;
    case 31:
        return STR_MO_BRIDGE;
    case 32:
        return STR_MO_COMPLIANCEMANAGER;
    case 36:
        return STR_MO_SETTLEMENT;
    case 37:
        return STR_MO_STO;
    case 39:
        return STR_MO_STATISTICS;
    case 40:
        return STR_MO_PROTOCOLFEE;
    case 42:
        return STR_MO_PORTFOLIO;
    case 45:
        return STR_MO_SCHEDULER;
    case 46:
        return STR_MO_CORPORATEACTION;
    case 47:
        return STR_MO_CORPORATEBALLOT;
    case 48:
        return STR_MO_CAPITALDISTRIBUTION;
    case 49:
        return STR_MO_CHECKPOINT;
    case 50:
        return STR_MO_TESTUTILS;
    case 51:
        return STR_MO_BASE;
#endif
    default:
        return NULL;
    }

    return NULL;
}

const char* _getMethod_Name_V7(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return STR_ME_TRANSFER;
    case 1025: /* module 4 call 1 */
        return STR_ME_TRANSFER_WITH_MEMO;
    case 1538: /* module 6 call 2 */
        return STR_ME_REMOVE_SECONDARY_KEYS;
    case 1539: /* module 6 call 3 */
        return STR_ME_ACCEPT_PRIMARY_KEY;
    case 1541: /* module 6 call 5 */
        return STR_ME_JOIN_IDENTITY_AS_KEY;
    case 1542: /* module 6 call 6 */
        return STR_ME_JOIN_IDENTITY_AS_IDENTITY;
    case 1543: /* module 6 call 7 */
        return STR_ME_LEAVE_IDENTITY_AS_KEY;
    case 1544: /* module 6 call 8 */
        return STR_ME_LEAVE_IDENTITY_AS_IDENTITY;
    case 1545: /* module 6 call 9 */
        return STR_ME_ADD_CLAIM;
    case 1547: /* module 6 call 11 */
        return STR_ME_REVOKE_CLAIM;
    case 1548: /* module 6 call 12 */
        return STR_ME_SET_PERMISSION_TO_SIGNER;
    case 1549: /* module 6 call 13 */
        return STR_ME_LEGACY_SET_PERMISSION_TO_SIGNER;
    case 1550: /* module 6 call 14 */
        return STR_ME_FREEZE_SECONDARY_KEYS;
    case 1551: /* module 6 call 15 */
        return STR_ME_UNFREEZE_SECONDARY_KEYS;
    case 1552: /* module 6 call 16 */
        return STR_ME_ADD_AUTHORIZATION;
    case 1553: /* module 6 call 17 */
        return STR_ME_REMOVE_AUTHORIZATION;
    case 1554: /* module 6 call 18 */
        return STR_ME_ACCEPT_AUTHORIZATION;
    case 1555: /* module 6 call 19 */
        return STR_ME_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION;
    case 1557: /* module 6 call 21 */
        return STR_ME_ADD_INVESTOR_UNIQUENESS_CLAIM;
    case 2048: /* module 8 call 0 */
        return STR_ME_BOND;
    case 2049: /* module 8 call 1 */
        return STR_ME_BOND_EXTRA;
    case 2050: /* module 8 call 2 */
        return STR_ME_UNBOND;
    case 2051: /* module 8 call 3 */
        return STR_ME_WITHDRAW_UNBONDED;
    case 2052: /* module 8 call 4 */
        return STR_ME_VALIDATE;
    case 2053: /* module 8 call 5 */
        return STR_ME_NOMINATE;
    case 2054: /* module 8 call 6 */
        return STR_ME_CHILL;
    case 2055: /* module 8 call 7 */
        return STR_ME_SET_PAYEE;
    case 2056: /* module 8 call 8 */
        return STR_ME_SET_CONTROLLER;
    case 2072: /* module 8 call 24 */
        return STR_ME_REBOND;
    case 4608: /* module 18 call 0 */
        return STR_ME_CREATE_MULTISIG;
    case 4609: /* module 18 call 1 */
        return STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY;
    case 4610: /* module 18 call 2 */
        return STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_KEY;
    case 4611: /* module 18 call 3 */
        return STR_ME_CREATE_PROPOSAL_AS_IDENTITY;
    case 4612: /* module 18 call 4 */
        return STR_ME_CREATE_PROPOSAL_AS_KEY;
    case 4613: /* module 18 call 5 */
        return STR_ME_APPROVE_AS_IDENTITY;
    case 4614: /* module 18 call 6 */
        return STR_ME_APPROVE_AS_KEY;
    case 4615: /* module 18 call 7 */
        return STR_ME_REJECT_AS_IDENTITY;
    case 4616: /* module 18 call 8 */
        return STR_ME_REJECT_AS_KEY;
    case 4617: /* module 18 call 9 */
        return STR_ME_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY;
    case 4618: /* module 18 call 10 */
        return STR_ME_ACCEPT_MULTISIG_SIGNER_AS_KEY;
    case 4619: /* module 18 call 11 */
        return STR_ME_ADD_MULTISIG_SIGNER;
    case 4620: /* module 18 call 12 */
        return STR_ME_REMOVE_MULTISIG_SIGNER;
    case 4621: /* module 18 call 13 */
        return STR_ME_ADD_MULTISIG_SIGNERS_VIA_CREATOR;
    case 4622: /* module 18 call 14 */
        return STR_ME_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR;
    case 4623: /* module 18 call 15 */
        return STR_ME_CHANGE_SIGS_REQUIRED;
    case 4624: /* module 18 call 16 */
        return STR_ME_MAKE_MULTISIG_SIGNER;
    case 4625: /* module 18 call 17 */
        return STR_ME_MAKE_MULTISIG_PRIMARY;
    case 4626: /* module 18 call 18 */
        return STR_ME_EXECUTE_SCHEDULED_PROPOSAL;
    case 6150: /* module 24 call 6 */
        return STR_ME_PROPOSE;
    case 6151: /* module 24 call 7 */
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
    case 9: /* module 0 call 9 */
        return STR_ME_SUICIDE;
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
    case 1026: /* module 4 call 2 */
        return STR_ME_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE;
    case 1027: /* module 4 call 3 */
        return STR_ME_SET_BALANCE;
    case 1028: /* module 4 call 4 */
        return STR_ME_FORCE_TRANSFER;
    case 1029: /* module 4 call 5 */
        return STR_ME_BURN_ACCOUNT_BALANCE;
    case 1536: /* module 6 call 0 */
        return STR_ME_CDD_REGISTER_DID;
    case 1537: /* module 6 call 1 */
        return STR_ME_INVALIDATE_CDD_CLAIMS;
    case 1540: /* module 6 call 4 */
        return STR_ME_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION;
    case 1546: /* module 6 call 10 */
        return STR_ME_FORWARDED_CALL;
    case 1556: /* module 6 call 20 */
        return STR_ME_REVOKE_OFFCHAIN_AUTHORIZATION;
    case 1558: /* module 6 call 22 */
        return STR_ME_GC_ADD_CDD_CLAIM;
    case 1559: /* module 6 call 23 */
        return STR_ME_GC_REVOKE_CDD_CLAIM;
    case 1560: /* module 6 call 24 */
        return STR_ME_ADD_INVESTOR_UNIQUENESS_CLAIM_V2;
    case 1792: /* module 7 call 0 */
        return STR_ME_SET_UNCLES;
    case 9728: /* module 38 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 9729: /* module 38 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 9730: /* module 38 call 2 */
        return STR_ME_ADD_MEMBER;
    case 9731: /* module 38 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 9732: /* module 38 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 9733: /* module 38 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 9734: /* module 38 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 2057: /* module 8 call 9 */
        return STR_ME_SET_VALIDATOR_COUNT;
    case 2058: /* module 8 call 10 */
        return STR_ME_INCREASE_VALIDATOR_COUNT;
    case 2059: /* module 8 call 11 */
        return STR_ME_SCALE_VALIDATOR_COUNT;
    case 2060: /* module 8 call 12 */
        return STR_ME_ADD_PERMISSIONED_VALIDATOR;
    case 2061: /* module 8 call 13 */
        return STR_ME_REMOVE_PERMISSIONED_VALIDATOR;
    case 2062: /* module 8 call 14 */
        return STR_ME_VALIDATE_CDD_EXPIRY_NOMINATORS;
    case 2063: /* module 8 call 15 */
        return STR_ME_SET_COMMISSION_CAP;
    case 2064: /* module 8 call 16 */
        return STR_ME_SET_MIN_BOND_THRESHOLD;
    case 2065: /* module 8 call 17 */
        return STR_ME_FORCE_NO_ERAS;
    case 2066: /* module 8 call 18 */
        return STR_ME_FORCE_NEW_ERA;
    case 2067: /* module 8 call 19 */
        return STR_ME_SET_INVULNERABLES;
    case 2068: /* module 8 call 20 */
        return STR_ME_FORCE_UNSTAKE;
    case 2069: /* module 8 call 21 */
        return STR_ME_FORCE_NEW_ERA_ALWAYS;
    case 2070: /* module 8 call 22 */
        return STR_ME_CANCEL_DEFERRED_SLASH;
    case 2071: /* module 8 call 23 */
        return STR_ME_PAYOUT_STAKERS;
    case 2073: /* module 8 call 25 */
        return STR_ME_SET_HISTORY_DEPTH;
    case 2074: /* module 8 call 26 */
        return STR_ME_REAP_STASH;
    case 2075: /* module 8 call 27 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION;
    case 2076: /* module 8 call 28 */
        return STR_ME_SUBMIT_ELECTION_SOLUTION_UNSIGNED;
    case 2077: /* module 8 call 29 */
        return STR_ME_PAYOUT_STAKERS_BY_SYSTEM;
    case 2078: /* module 8 call 30 */
        return STR_ME_CHANGE_SLASHING_ALLOWED_FOR;
    case 2079: /* module 8 call 31 */
        return STR_ME_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT;
    case 2560: /* module 10 call 0 */
        return STR_ME_SET_KEYS;
    case 2561: /* module 10 call 1 */
        return STR_ME_PURGE_KEYS;
    case 2816: /* module 11 call 0 */
        return STR_ME_FINAL_HINT;
    case 3072: /* module 12 call 0 */
        return STR_ME_REPORT_EQUIVOCATION;
    case 3073: /* module 12 call 1 */
        return STR_ME_REPORT_EQUIVOCATION_UNSIGNED;
    case 3074: /* module 12 call 2 */
        return STR_ME_NOTE_STALLED;
    case 3328: /* module 13 call 0 */
        return STR_ME_HEARTBEAT;
    case 4352: /* module 17 call 0 */
        return STR_ME_SUDO;
    case 4353: /* module 17 call 1 */
        return STR_ME_SUDO_UNCHECKED_WEIGHT;
    case 4354: /* module 17 call 2 */
        return STR_ME_SET_KEY;
    case 4355: /* module 17 call 3 */
        return STR_ME_SUDO_AS;
    case 5120: /* module 20 call 0 */
        return STR_ME_UPDATE_SCHEDULE;
    case 5121: /* module 20 call 1 */
        return STR_ME_SET_PUT_CODE_FLAG;
    case 5122: /* module 20 call 2 */
        return STR_ME_PUT_CODE;
    case 5123: /* module 20 call 3 */
        return STR_ME_CALL;
    case 5124: /* module 20 call 4 */
        return STR_ME_INSTANTIATE;
    case 5125: /* module 20 call 5 */
        return STR_ME_FREEZE_INSTANTIATION;
    case 5126: /* module 20 call 6 */
        return STR_ME_UNFREEZE_INSTANTIATION;
    case 5127: /* module 20 call 7 */
        return STR_ME_TRANSFER_TEMPLATE_OWNERSHIP;
    case 5128: /* module 20 call 8 */
        return STR_ME_CHANGE_TEMPLATE_FEES;
    case 5129: /* module 20 call 9 */
        return STR_ME_CHANGE_TEMPLATE_META_URL;
    case 5376: /* module 21 call 0 */
        return STR_ME_DISBURSEMENT;
    case 5377: /* module 21 call 1 */
        return STR_ME_REIMBURSEMENT;
    case 5632: /* module 22 call 0 */
        return STR_ME_SET_VOTE_THRESHOLD;
    case 5633: /* module 22 call 1 */
        return STR_ME_SET_RELEASE_COORDINATOR;
    case 5634: /* module 22 call 2 */
        return STR_ME_SET_EXPIRES_AFTER;
    case 5635: /* module 22 call 3 */
        return STR_ME_VOTE_OR_PROPOSE;
    case 5636: /* module 22 call 4 */
        return STR_ME_VOTE;
    case 5888: /* module 23 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 5889: /* module 23 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 5890: /* module 23 call 2 */
        return STR_ME_ADD_MEMBER;
    case 5891: /* module 23 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 5892: /* module 23 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 5893: /* module 23 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 5894: /* module 23 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 6144: /* module 24 call 0 */
        return STR_ME_SET_PRUNE_HISTORICAL_PIPS;
    case 6145: /* module 24 call 1 */
        return STR_ME_SET_MIN_PROPOSAL_DEPOSIT;
    case 6146: /* module 24 call 2 */
        return STR_ME_SET_DEFAULT_ENACTMENT_PERIOD;
    case 6147: /* module 24 call 3 */
        return STR_ME_SET_PENDING_PIP_EXPIRY;
    case 6148: /* module 24 call 4 */
        return STR_ME_SET_MAX_PIP_SKIP_COUNT;
    case 6149: /* module 24 call 5 */
        return STR_ME_SET_ACTIVE_PIP_LIMIT;
    case 6152: /* module 24 call 8 */
        return STR_ME_APPROVE_COMMITTEE_PROPOSAL;
    case 6153: /* module 24 call 9 */
        return STR_ME_REJECT_PROPOSAL;
    case 6154: /* module 24 call 10 */
        return STR_ME_PRUNE_PROPOSAL;
    case 6155: /* module 24 call 11 */
        return STR_ME_RESCHEDULE_EXECUTION;
    case 6156: /* module 24 call 12 */
        return STR_ME_CLEAR_SNAPSHOT;
    case 6157: /* module 24 call 13 */
        return STR_ME_SNAPSHOT;
    case 6158: /* module 24 call 14 */
        return STR_ME_ENACT_SNAPSHOT_RESULTS;
    case 6159: /* module 24 call 15 */
        return STR_ME_EXECUTE_SCHEDULED_PIP;
    case 6160: /* module 24 call 16 */
        return STR_ME_EXPIRE_SCHEDULED_PIP;
    case 6400: /* module 25 call 0 */
        return STR_ME_SET_VOTE_THRESHOLD;
    case 6401: /* module 25 call 1 */
        return STR_ME_SET_RELEASE_COORDINATOR;
    case 6402: /* module 25 call 2 */
        return STR_ME_SET_EXPIRES_AFTER;
    case 6403: /* module 25 call 3 */
        return STR_ME_VOTE_OR_PROPOSE;
    case 6404: /* module 25 call 4 */
        return STR_ME_VOTE;
    case 6656: /* module 26 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 6657: /* module 26 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 6658: /* module 26 call 2 */
        return STR_ME_ADD_MEMBER;
    case 6659: /* module 26 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 6660: /* module 26 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 6661: /* module 26 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 6662: /* module 26 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 6912: /* module 27 call 0 */
        return STR_ME_SET_VOTE_THRESHOLD;
    case 6913: /* module 27 call 1 */
        return STR_ME_SET_RELEASE_COORDINATOR;
    case 6914: /* module 27 call 2 */
        return STR_ME_SET_EXPIRES_AFTER;
    case 6915: /* module 27 call 3 */
        return STR_ME_VOTE_OR_PROPOSE;
    case 6916: /* module 27 call 4 */
        return STR_ME_VOTE;
    case 7168: /* module 28 call 0 */
        return STR_ME_SET_ACTIVE_MEMBERS_LIMIT;
    case 7169: /* module 28 call 1 */
        return STR_ME_DISABLE_MEMBER;
    case 7170: /* module 28 call 2 */
        return STR_ME_ADD_MEMBER;
    case 7171: /* module 28 call 3 */
        return STR_ME_REMOVE_MEMBER;
    case 7172: /* module 28 call 4 */
        return STR_ME_SWAP_MEMBER;
    case 7173: /* module 28 call 5 */
        return STR_ME_RESET_MEMBERS;
    case 7174: /* module 28 call 6 */
        return STR_ME_ABDICATE_MEMBERSHIP;
    case 7424: /* module 29 call 0 */
        return STR_ME_REGISTER_TICKER;
    case 7425: /* module 29 call 1 */
        return STR_ME_ACCEPT_TICKER_TRANSFER;
    case 7426: /* module 29 call 2 */
        return STR_ME_ACCEPT_PRIMARY_ISSUANCE_AGENT_TRANSFER;
    case 7427: /* module 29 call 3 */
        return STR_ME_ACCEPT_ASSET_OWNERSHIP_TRANSFER;
    case 7428: /* module 29 call 4 */
        return STR_ME_CREATE_ASSET;
    case 7429: /* module 29 call 5 */
        return STR_ME_FREEZE;
    case 7430: /* module 29 call 6 */
        return STR_ME_UNFREEZE;
    case 7431: /* module 29 call 7 */
        return STR_ME_RENAME_ASSET;
    case 7432: /* module 29 call 8 */
        return STR_ME_ISSUE;
    case 7433: /* module 29 call 9 */
        return STR_ME_REDEEM;
    case 7434: /* module 29 call 10 */
        return STR_ME_MAKE_DIVISIBLE;
    case 7435: /* module 29 call 11 */
        return STR_ME_ADD_DOCUMENTS;
    case 7436: /* module 29 call 12 */
        return STR_ME_REMOVE_DOCUMENTS;
    case 7437: /* module 29 call 13 */
        return STR_ME_SET_FUNDING_ROUND;
    case 7438: /* module 29 call 14 */
        return STR_ME_UPDATE_IDENTIFIERS;
    case 7439: /* module 29 call 15 */
        return STR_ME_ADD_EXTENSION;
    case 7440: /* module 29 call 16 */
        return STR_ME_REMOVE_SMART_EXTENSION;
    case 7441: /* module 29 call 17 */
        return STR_ME_ARCHIVE_EXTENSION;
    case 7442: /* module 29 call 18 */
        return STR_ME_UNARCHIVE_EXTENSION;
    case 7443: /* module 29 call 19 */
        return STR_ME_REMOVE_PRIMARY_ISSUANCE_AGENT;
    case 7444: /* module 29 call 20 */
        return STR_ME_CLAIM_CLASSIC_TICKER;
    case 7445: /* module 29 call 21 */
        return STR_ME_RESERVE_CLASSIC_TICKER;
    case 7446: /* module 29 call 22 */
        return STR_ME_CONTROLLER_TRANSFER;
    case 7936: /* module 31 call 0 */
        return STR_ME_CHANGE_CONTROLLER;
    case 7937: /* module 31 call 1 */
        return STR_ME_CHANGE_ADMIN;
    case 7938: /* module 31 call 2 */
        return STR_ME_CHANGE_TIMELOCK;
    case 7939: /* module 31 call 3 */
        return STR_ME_FREEZE;
    case 7940: /* module 31 call 4 */
        return STR_ME_UNFREEZE;
    case 7941: /* module 31 call 5 */
        return STR_ME_CHANGE_BRIDGE_LIMIT;
    case 7942: /* module 31 call 6 */
        return STR_ME_CHANGE_BRIDGE_EXEMPTED;
    case 7943: /* module 31 call 7 */
        return STR_ME_FORCE_HANDLE_BRIDGE_TX;
    case 7944: /* module 31 call 8 */
        return STR_ME_BATCH_PROPOSE_BRIDGE_TX;
    case 7945: /* module 31 call 9 */
        return STR_ME_PROPOSE_BRIDGE_TX;
    case 7946: /* module 31 call 10 */
        return STR_ME_HANDLE_BRIDGE_TX;
    case 7947: /* module 31 call 11 */
        return STR_ME_FREEZE_TXS;
    case 7948: /* module 31 call 12 */
        return STR_ME_UNFREEZE_TXS;
    case 7949: /* module 31 call 13 */
        return STR_ME_HANDLE_SCHEDULED_BRIDGE_TX;
    case 8192: /* module 32 call 0 */
        return STR_ME_ADD_COMPLIANCE_REQUIREMENT;
    case 8193: /* module 32 call 1 */
        return STR_ME_REMOVE_COMPLIANCE_REQUIREMENT;
    case 8194: /* module 32 call 2 */
        return STR_ME_REPLACE_ASSET_COMPLIANCE;
    case 8195: /* module 32 call 3 */
        return STR_ME_RESET_ASSET_COMPLIANCE;
    case 8196: /* module 32 call 4 */
        return STR_ME_PAUSE_ASSET_COMPLIANCE;
    case 8197: /* module 32 call 5 */
        return STR_ME_RESUME_ASSET_COMPLIANCE;
    case 8198: /* module 32 call 6 */
        return STR_ME_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER;
    case 8199: /* module 32 call 7 */
        return STR_ME_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER;
    case 8200: /* module 32 call 8 */
        return STR_ME_CHANGE_COMPLIANCE_REQUIREMENT;
    case 9216: /* module 36 call 0 */
        return STR_ME_CREATE_VENUE;
    case 9217: /* module 36 call 1 */
        return STR_ME_UPDATE_VENUE;
    case 9218: /* module 36 call 2 */
        return STR_ME_ADD_INSTRUCTION;
    case 9219: /* module 36 call 3 */
        return STR_ME_ADD_AND_AFFIRM_INSTRUCTION;
    case 9220: /* module 36 call 4 */
        return STR_ME_AFFIRM_INSTRUCTION;
    case 9221: /* module 36 call 5 */
        return STR_ME_WITHDRAW_AFFIRMATION;
    case 9222: /* module 36 call 6 */
        return STR_ME_REJECT_INSTRUCTION;
    case 9223: /* module 36 call 7 */
        return STR_ME_AFFIRM_WITH_RECEIPTS;
    case 9224: /* module 36 call 8 */
        return STR_ME_CLAIM_RECEIPT;
    case 9225: /* module 36 call 9 */
        return STR_ME_UNCLAIM_RECEIPT;
    case 9226: /* module 36 call 10 */
        return STR_ME_SET_VENUE_FILTERING;
    case 9227: /* module 36 call 11 */
        return STR_ME_ALLOW_VENUES;
    case 9228: /* module 36 call 12 */
        return STR_ME_DISALLOW_VENUES;
    case 9229: /* module 36 call 13 */
        return STR_ME_CHANGE_RECEIPT_VALIDITY;
    case 9230: /* module 36 call 14 */
        return STR_ME_EXECUTE_SCHEDULED_INSTRUCTION;
    case 9472: /* module 37 call 0 */
        return STR_ME_CREATE_FUNDRAISER;
    case 9473: /* module 37 call 1 */
        return STR_ME_INVEST;
    case 9474: /* module 37 call 2 */
        return STR_ME_FREEZE_FUNDRAISER;
    case 9475: /* module 37 call 3 */
        return STR_ME_UNFREEZE_FUNDRAISER;
    case 9476: /* module 37 call 4 */
        return STR_ME_MODIFY_FUNDRAISER_WINDOW;
    case 9477: /* module 37 call 5 */
        return STR_ME_STOP;
    case 9984: /* module 39 call 0 */
        return STR_ME_ADD_TRANSFER_MANAGER;
    case 9985: /* module 39 call 1 */
        return STR_ME_REMOVE_TRANSFER_MANAGER;
    case 9986: /* module 39 call 2 */
        return STR_ME_ADD_EXEMPTED_ENTITIES;
    case 9987: /* module 39 call 3 */
        return STR_ME_REMOVE_EXEMPTED_ENTITIES;
    case 10240: /* module 40 call 0 */
        return STR_ME_CHANGE_COEFFICIENT;
    case 10241: /* module 40 call 1 */
        return STR_ME_CHANGE_BASE_FEE;
    case 10499: /* module 41 call 3 */
        return STR_ME_RELAY_TX;
    case 10752: /* module 42 call 0 */
        return STR_ME_CREATE_PORTFOLIO;
    case 10753: /* module 42 call 1 */
        return STR_ME_DELETE_PORTFOLIO;
    case 10754: /* module 42 call 2 */
        return STR_ME_MOVE_PORTFOLIO_FUNDS;
    case 10755: /* module 42 call 3 */
        return STR_ME_RENAME_PORTFOLIO;
    case 11520: /* module 45 call 0 */
        return STR_ME_SCHEDULE;
    case 11521: /* module 45 call 1 */
        return STR_ME_CANCEL;
    case 11522: /* module 45 call 2 */
        return STR_ME_SCHEDULE_NAMED;
    case 11523: /* module 45 call 3 */
        return STR_ME_CANCEL_NAMED;
    case 11524: /* module 45 call 4 */
        return STR_ME_SCHEDULE_AFTER;
    case 11525: /* module 45 call 5 */
        return STR_ME_SCHEDULE_NAMED_AFTER;
    case 11776: /* module 46 call 0 */
        return STR_ME_SET_MAX_DETAILS_LENGTH;
    case 11777: /* module 46 call 1 */
        return STR_ME_RESET_CAA;
    case 11778: /* module 46 call 2 */
        return STR_ME_SET_DEFAULT_TARGETS;
    case 11779: /* module 46 call 3 */
        return STR_ME_SET_DEFAULT_WITHHOLDING_TAX;
    case 11780: /* module 46 call 4 */
        return STR_ME_SET_DID_WITHHOLDING_TAX;
    case 11781: /* module 46 call 5 */
        return STR_ME_INITIATE_CORPORATE_ACTION;
    case 11782: /* module 46 call 6 */
        return STR_ME_LINK_CA_DOC;
    case 11783: /* module 46 call 7 */
        return STR_ME_REMOVE_CA;
    case 11784: /* module 46 call 8 */
        return STR_ME_CHANGE_RECORD_DATE;
    case 12032: /* module 47 call 0 */
        return STR_ME_ATTACH_BALLOT;
    case 12033: /* module 47 call 1 */
        return STR_ME_VOTE;
    case 12034: /* module 47 call 2 */
        return STR_ME_CHANGE_END;
    case 12035: /* module 47 call 3 */
        return STR_ME_CHANGE_META;
    case 12036: /* module 47 call 4 */
        return STR_ME_CHANGE_RCV;
    case 12037: /* module 47 call 5 */
        return STR_ME_REMOVE_BALLOT;
    case 12288: /* module 48 call 0 */
        return STR_ME_DISTRIBUTE;
    case 12289: /* module 48 call 1 */
        return STR_ME_CLAIM;
    case 12290: /* module 48 call 2 */
        return STR_ME_PUSH_BENEFIT;
    case 12291: /* module 48 call 3 */
        return STR_ME_RECLAIM;
    case 12292: /* module 48 call 4 */
        return STR_ME_REMOVE_DISTRIBUTION;
    case 12544: /* module 49 call 0 */
        return STR_ME_CREATE_CHECKPOINT;
    case 12545: /* module 49 call 1 */
        return STR_ME_SET_SCHEDULES_MAX_COMPLEXITY;
    case 12546: /* module 49 call 2 */
        return STR_ME_CREATE_SCHEDULE;
    case 12547: /* module 49 call 3 */
        return STR_ME_REMOVE_SCHEDULE;
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

uint8_t _getMethod_NumItems_V7(uint8_t moduleIdx, uint8_t callIdx, pd_Method_V7_t* method)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        return 2;
    case 1025: /* module 4 call 1 */
        return 3;
    case 1538: /* module 6 call 2 */
        return 1;
    case 1539: /* module 6 call 3 */
        return 2;
    case 1541: /* module 6 call 5 */
        return 1;
    case 1542: /* module 6 call 6 */
        return 1;
    case 1543: /* module 6 call 7 */
        return 0;
    case 1544: /* module 6 call 8 */
        return 1;
    case 1545: /* module 6 call 9 */
        return 3;
    case 1547: /* module 6 call 11 */
        return 2;
    case 1548: /* module 6 call 12 */
        return 2;
    case 1549: /* module 6 call 13 */
        return 2;
    case 1550: /* module 6 call 14 */
        return 0;
    case 1551: /* module 6 call 15 */
        return 0;
    case 1552: /* module 6 call 16 */
        return 3;
    case 1553: /* module 6 call 17 */
        return 3;
    case 1554: /* module 6 call 18 */
        return 1;
    case 1555: /* module 6 call 19 */
        return 2;
    case 1557: /* module 6 call 21 */
        return 4;
    case 2048: /* module 8 call 0 */
        return 3;
    case 2049: /* module 8 call 1 */
        return 1;
    case 2050: /* module 8 call 2 */
        return 1;
    case 2051: /* module 8 call 3 */
        return 1;
    case 2052: /* module 8 call 4 */
        return 1;
    case 2053: /* module 8 call 5 */
        return 1;
    case 2054: /* module 8 call 6 */
        return 0;
    case 2055: /* module 8 call 7 */
        return 1;
    case 2056: /* module 8 call 8 */
        return 1;
    case 2072: /* module 8 call 24 */
        return 1;
    case 4608: /* module 18 call 0 */
        return 2;
    case 4609: /* module 18 call 1 */
        return 4;
    case 4610: /* module 18 call 2 */
        return 4;
    case 4611: /* module 18 call 3 */
        return 4;
    case 4612: /* module 18 call 4 */
        return 4;
    case 4613: /* module 18 call 5 */
        return 2;
    case 4614: /* module 18 call 6 */
        return 2;
    case 4615: /* module 18 call 7 */
        return 2;
    case 4616: /* module 18 call 8 */
        return 2;
    case 4617: /* module 18 call 9 */
        return 1;
    case 4618: /* module 18 call 10 */
        return 1;
    case 4619: /* module 18 call 11 */
        return 1;
    case 4620: /* module 18 call 12 */
        return 1;
    case 4621: /* module 18 call 13 */
        return 2;
    case 4622: /* module 18 call 14 */
        return 2;
    case 4623: /* module 18 call 15 */
        return 1;
    case 4624: /* module 18 call 16 */
        return 1;
    case 4625: /* module 18 call 17 */
        return 2;
    case 4626: /* module 18 call 18 */
        return 4;
    case 6150: /* module 24 call 6 */
        return 4;
    case 6151: /* module 24 call 7 */
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
    case 5: /* module 0 call 5 */
        return 1;
    case 6: /* module 0 call 6 */
        return 1;
    case 7: /* module 0 call 7 */
        return 1;
    case 8: /* module 0 call 8 */
        return 2;
    case 9: /* module 0 call 9 */
        return 0;
    case 256: /* module 1 call 0 */
        return 2;
    case 257: /* module 1 call 1 */
        return 2;
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
    case 1026: /* module 4 call 2 */
        return 1;
    case 1027: /* module 4 call 3 */
        return 3;
    case 1028: /* module 4 call 4 */
        return 3;
    case 1029: /* module 4 call 5 */
        return 1;
    case 1536: /* module 6 call 0 */
        return 2;
    case 1537: /* module 6 call 1 */
        return 3;
    case 1540: /* module 6 call 4 */
        return 1;
    case 1546: /* module 6 call 10 */
        return 2;
    case 1556: /* module 6 call 20 */
        return 2;
    case 1558: /* module 6 call 22 */
        return 2;
    case 1559: /* module 6 call 23 */
        return 1;
    case 1560: /* module 6 call 24 */
        return 4;
    case 1792: /* module 7 call 0 */
        return 1;
    case 9728: /* module 38 call 0 */
        return 1;
    case 9729: /* module 38 call 1 */
        return 3;
    case 9730: /* module 38 call 2 */
        return 1;
    case 9731: /* module 38 call 3 */
        return 1;
    case 9732: /* module 38 call 4 */
        return 2;
    case 9733: /* module 38 call 5 */
        return 1;
    case 9734: /* module 38 call 6 */
        return 0;
    case 2057: /* module 8 call 9 */
        return 1;
    case 2058: /* module 8 call 10 */
        return 1;
    case 2059: /* module 8 call 11 */
        return 1;
    case 2060: /* module 8 call 12 */
        return 2;
    case 2061: /* module 8 call 13 */
        return 1;
    case 2062: /* module 8 call 14 */
        return 1;
    case 2063: /* module 8 call 15 */
        return 1;
    case 2064: /* module 8 call 16 */
        return 1;
    case 2065: /* module 8 call 17 */
        return 0;
    case 2066: /* module 8 call 18 */
        return 0;
    case 2067: /* module 8 call 19 */
        return 1;
    case 2068: /* module 8 call 20 */
        return 2;
    case 2069: /* module 8 call 21 */
        return 0;
    case 2070: /* module 8 call 22 */
        return 2;
    case 2071: /* module 8 call 23 */
        return 2;
    case 2073: /* module 8 call 25 */
        return 2;
    case 2074: /* module 8 call 26 */
        return 2;
    case 2075: /* module 8 call 27 */
        return 5;
    case 2076: /* module 8 call 28 */
        return 5;
    case 2077: /* module 8 call 29 */
        return 2;
    case 2078: /* module 8 call 30 */
        return 1;
    case 2079: /* module 8 call 31 */
        return 2;
    case 2560: /* module 10 call 0 */
        return 2;
    case 2561: /* module 10 call 1 */
        return 0;
    case 2816: /* module 11 call 0 */
        return 1;
    case 3072: /* module 12 call 0 */
        return 2;
    case 3073: /* module 12 call 1 */
        return 2;
    case 3074: /* module 12 call 2 */
        return 2;
    case 3328: /* module 13 call 0 */
        return 2;
    case 4352: /* module 17 call 0 */
        return 1;
    case 4353: /* module 17 call 1 */
        return 2;
    case 4354: /* module 17 call 2 */
        return 1;
    case 4355: /* module 17 call 3 */
        return 2;
    case 5120: /* module 20 call 0 */
        return 1;
    case 5121: /* module 20 call 1 */
        return 1;
    case 5122: /* module 20 call 2 */
        return 3;
    case 5123: /* module 20 call 3 */
        return 4;
    case 5124: /* module 20 call 4 */
        return 5;
    case 5125: /* module 20 call 5 */
        return 1;
    case 5126: /* module 20 call 6 */
        return 1;
    case 5127: /* module 20 call 7 */
        return 2;
    case 5128: /* module 20 call 8 */
        return 3;
    case 5129: /* module 20 call 9 */
        return 2;
    case 5376: /* module 21 call 0 */
        return 1;
    case 5377: /* module 21 call 1 */
        return 1;
    case 5632: /* module 22 call 0 */
        return 2;
    case 5633: /* module 22 call 1 */
        return 1;
    case 5634: /* module 22 call 2 */
        return 1;
    case 5635: /* module 22 call 3 */
        return 2;
    case 5636: /* module 22 call 4 */
        return 3;
    case 5888: /* module 23 call 0 */
        return 1;
    case 5889: /* module 23 call 1 */
        return 3;
    case 5890: /* module 23 call 2 */
        return 1;
    case 5891: /* module 23 call 3 */
        return 1;
    case 5892: /* module 23 call 4 */
        return 2;
    case 5893: /* module 23 call 5 */
        return 1;
    case 5894: /* module 23 call 6 */
        return 0;
    case 6144: /* module 24 call 0 */
        return 1;
    case 6145: /* module 24 call 1 */
        return 1;
    case 6146: /* module 24 call 2 */
        return 1;
    case 6147: /* module 24 call 3 */
        return 1;
    case 6148: /* module 24 call 4 */
        return 1;
    case 6149: /* module 24 call 5 */
        return 1;
    case 6152: /* module 24 call 8 */
        return 1;
    case 6153: /* module 24 call 9 */
        return 1;
    case 6154: /* module 24 call 10 */
        return 1;
    case 6155: /* module 24 call 11 */
        return 2;
    case 6156: /* module 24 call 12 */
        return 0;
    case 6157: /* module 24 call 13 */
        return 0;
    case 6158: /* module 24 call 14 */
        return 1;
    case 6159: /* module 24 call 15 */
        return 1;
    case 6160: /* module 24 call 16 */
        return 2;
    case 6400: /* module 25 call 0 */
        return 2;
    case 6401: /* module 25 call 1 */
        return 1;
    case 6402: /* module 25 call 2 */
        return 1;
    case 6403: /* module 25 call 3 */
        return 2;
    case 6404: /* module 25 call 4 */
        return 3;
    case 6656: /* module 26 call 0 */
        return 1;
    case 6657: /* module 26 call 1 */
        return 3;
    case 6658: /* module 26 call 2 */
        return 1;
    case 6659: /* module 26 call 3 */
        return 1;
    case 6660: /* module 26 call 4 */
        return 2;
    case 6661: /* module 26 call 5 */
        return 1;
    case 6662: /* module 26 call 6 */
        return 0;
    case 6912: /* module 27 call 0 */
        return 2;
    case 6913: /* module 27 call 1 */
        return 1;
    case 6914: /* module 27 call 2 */
        return 1;
    case 6915: /* module 27 call 3 */
        return 2;
    case 6916: /* module 27 call 4 */
        return 3;
    case 7168: /* module 28 call 0 */
        return 1;
    case 7169: /* module 28 call 1 */
        return 3;
    case 7170: /* module 28 call 2 */
        return 1;
    case 7171: /* module 28 call 3 */
        return 1;
    case 7172: /* module 28 call 4 */
        return 2;
    case 7173: /* module 28 call 5 */
        return 1;
    case 7174: /* module 28 call 6 */
        return 0;
    case 7424: /* module 29 call 0 */
        return 1;
    case 7425: /* module 29 call 1 */
        return 1;
    case 7426: /* module 29 call 2 */
        return 1;
    case 7427: /* module 29 call 3 */
        return 1;
    case 7428: /* module 29 call 4 */
        return 7;
    case 7429: /* module 29 call 5 */
        return 1;
    case 7430: /* module 29 call 6 */
        return 1;
    case 7431: /* module 29 call 7 */
        return 2;
    case 7432: /* module 29 call 8 */
        return 2;
    case 7433: /* module 29 call 9 */
        return 2;
    case 7434: /* module 29 call 10 */
        return 1;
    case 7435: /* module 29 call 11 */
        return 2;
    case 7436: /* module 29 call 12 */
        return 2;
    case 7437: /* module 29 call 13 */
        return 2;
    case 7438: /* module 29 call 14 */
        return 2;
    case 7439: /* module 29 call 15 */
        return 2;
    case 7440: /* module 29 call 16 */
        return 2;
    case 7441: /* module 29 call 17 */
        return 2;
    case 7442: /* module 29 call 18 */
        return 2;
    case 7443: /* module 29 call 19 */
        return 1;
    case 7444: /* module 29 call 20 */
        return 2;
    case 7445: /* module 29 call 21 */
        return 3;
    case 7446: /* module 29 call 22 */
        return 3;
    case 7936: /* module 31 call 0 */
        return 1;
    case 7937: /* module 31 call 1 */
        return 1;
    case 7938: /* module 31 call 2 */
        return 1;
    case 7939: /* module 31 call 3 */
        return 0;
    case 7940: /* module 31 call 4 */
        return 0;
    case 7941: /* module 31 call 5 */
        return 2;
    case 7942: /* module 31 call 6 */
        return 1;
    case 7943: /* module 31 call 7 */
        return 1;
    case 7944: /* module 31 call 8 */
        return 1;
    case 7945: /* module 31 call 9 */
        return 1;
    case 7946: /* module 31 call 10 */
        return 1;
    case 7947: /* module 31 call 11 */
        return 1;
    case 7948: /* module 31 call 12 */
        return 1;
    case 7949: /* module 31 call 13 */
        return 1;
    case 8192: /* module 32 call 0 */
        return 3;
    case 8193: /* module 32 call 1 */
        return 2;
    case 8194: /* module 32 call 2 */
        return 2;
    case 8195: /* module 32 call 3 */
        return 1;
    case 8196: /* module 32 call 4 */
        return 1;
    case 8197: /* module 32 call 5 */
        return 1;
    case 8198: /* module 32 call 6 */
        return 2;
    case 8199: /* module 32 call 7 */
        return 2;
    case 8200: /* module 32 call 8 */
        return 2;
    case 9216: /* module 36 call 0 */
        return 3;
    case 9217: /* module 36 call 1 */
        return 3;
    case 9218: /* module 36 call 2 */
        return 5;
    case 9219: /* module 36 call 3 */
        return 6;
    case 9220: /* module 36 call 4 */
        return 3;
    case 9221: /* module 36 call 5 */
        return 3;
    case 9222: /* module 36 call 6 */
        return 3;
    case 9223: /* module 36 call 7 */
        return 4;
    case 9224: /* module 36 call 8 */
        return 2;
    case 9225: /* module 36 call 9 */
        return 2;
    case 9226: /* module 36 call 10 */
        return 2;
    case 9227: /* module 36 call 11 */
        return 2;
    case 9228: /* module 36 call 12 */
        return 2;
    case 9229: /* module 36 call 13 */
        return 2;
    case 9230: /* module 36 call 14 */
        return 2;
    case 9472: /* module 37 call 0 */
        return 10;
    case 9473: /* module 37 call 1 */
        return 7;
    case 9474: /* module 37 call 2 */
        return 2;
    case 9475: /* module 37 call 3 */
        return 2;
    case 9476: /* module 37 call 4 */
        return 4;
    case 9477: /* module 37 call 5 */
        return 2;
    case 9984: /* module 39 call 0 */
        return 2;
    case 9985: /* module 39 call 1 */
        return 2;
    case 9986: /* module 39 call 2 */
        return 3;
    case 9987: /* module 39 call 3 */
        return 3;
    case 10240: /* module 40 call 0 */
        return 1;
    case 10241: /* module 40 call 1 */
        return 2;
    case 10499: /* module 41 call 3 */
        return 3;
    case 10752: /* module 42 call 0 */
        return 1;
    case 10753: /* module 42 call 1 */
        return 1;
    case 10754: /* module 42 call 2 */
        return 3;
    case 10755: /* module 42 call 3 */
        return 2;
    case 11520: /* module 45 call 0 */
        return 4;
    case 11521: /* module 45 call 1 */
        return 2;
    case 11522: /* module 45 call 2 */
        return 5;
    case 11523: /* module 45 call 3 */
        return 1;
    case 11524: /* module 45 call 4 */
        return 4;
    case 11525: /* module 45 call 5 */
        return 5;
    case 11776: /* module 46 call 0 */
        return 1;
    case 11777: /* module 46 call 1 */
        return 1;
    case 11778: /* module 46 call 2 */
        return 2;
    case 11779: /* module 46 call 3 */
        return 2;
    case 11780: /* module 46 call 4 */
        return 3;
    case 11781: /* module 46 call 5 */
        return 8;
    case 11782: /* module 46 call 6 */
        return 2;
    case 11783: /* module 46 call 7 */
        return 1;
    case 11784: /* module 46 call 8 */
        return 2;
    case 12032: /* module 47 call 0 */
        return 4;
    case 12033: /* module 47 call 1 */
        return 2;
    case 12034: /* module 47 call 2 */
        return 2;
    case 12035: /* module 47 call 3 */
        return 2;
    case 12036: /* module 47 call 4 */
        return 2;
    case 12037: /* module 47 call 5 */
        return 1;
    case 12288: /* module 48 call 0 */
        return 7;
    case 12289: /* module 48 call 1 */
        return 1;
    case 12290: /* module 48 call 2 */
        return 2;
    case 12291: /* module 48 call 3 */
        return 1;
    case 12292: /* module 48 call 4 */
        return 1;
    case 12544: /* module 49 call 0 */
        return 1;
    case 12545: /* module 49 call 1 */
        return 1;
    case 12546: /* module 49 call 2 */
        return 2;
    case 12547: /* module 49 call 3 */
        return 2;
    case 12800: /* module 50 call 0 */
        return 2;
    case 12801: /* module 50 call 1 */
        return 1;
    case 12802: /* module 50 call 2 */
        return 0;
    case 12803: /* module 50 call 3 */
        return 1;
#endif
    default:
        return 0;
    }

    return 0;
}

const char* _getMethod_ItemName_V7(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_memo;
        default:
            return NULL;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signers_to_remove;
        default:
            return NULL;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_rotation_auth_id;
        case 1:
            return STR_IT_optional_cdd_auth_id;
        default:
            return NULL;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_did;
        default:
            return NULL;
        }
    case 1545: /* module 6 call 9 */
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
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_claim;
        default:
            return NULL;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        case 1:
            return STR_IT_permissions;
        default:
            return NULL;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        case 1:
            return STR_IT_permissions;
        default:
            return NULL;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_authorization_data;
        case 2:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 1553: /* module 6 call 17 */
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
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional_keys;
        case 1:
            return STR_IT_expires_at;
        default:
            return NULL;
        }
    case 1557: /* module 6 call 21 */
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
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_additional;
        default:
            return NULL;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefs;
        default:
            return NULL;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2054: /* module 8 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_payee;
        default:
            return NULL;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signers;
        case 1:
            return STR_IT_sigs_required;
        default:
            return NULL;
        }
    case 4609: /* module 18 call 1 */
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
    case 4610: /* module 18 call 2 */
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
    case 4611: /* module 18 call 3 */
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
    case 4612: /* module 18 call 4 */
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
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        default:
            return NULL;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 4618: /* module 18 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        default:
            return NULL;
        }
    case 4620: /* module 18 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        default:
            return NULL;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_signers;
        default:
            return NULL;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_signers;
        default:
            return NULL;
        }
    case 4623: /* module 18 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_sigs_required;
        default:
            return NULL;
        }
    case 4624: /* module 18 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        default:
            return NULL;
        }
    case 4625: /* module 18 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_optional_cdd_auth_id;
        default:
            return NULL;
        }
    case 4626: /* module 18 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_multisig;
        case 1:
            return STR_IT_proposal_id;
        case 2:
            return STR_IT_multisig_did;
        case 3:
            return STR_IT_proposal_weight;
        default:
            return NULL;
        }
    case 6150: /* module 24 call 6 */
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
    case 6151: /* module 24 call 7 */
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
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_changes_trie_config;
        default:
            return NULL;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_items;
        default:
            return NULL;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        default:
            return NULL;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prefix;
        case 1:
            return STR_IT__subkeys;
        default:
            return NULL;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
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
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1027: /* module 4 call 3 */
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
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_source;
        case 1:
            return STR_IT_dest;
        case 2:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target_account;
        case 1:
            return STR_IT_secondary_keys;
        default:
            return NULL;
        }
    case 1537: /* module 6 call 1 */
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
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_required;
        default:
            return NULL;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target_did;
        case 1:
            return STR_IT_proposal;
        default:
            return NULL;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_signer;
        case 1:
            return STR_IT_auth;
        default:
            return NULL;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        case 1:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target;
        default:
            return NULL;
        }
    case 1560: /* module 6 call 24 */
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
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_uncles;
        default:
            return NULL;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 9729: /* module 38 call 1 */
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
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 9734: /* module 38 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_additional;
        default:
            return NULL;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_factor;
        default:
            return NULL;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        case 1:
            return STR_IT_intended_count;
        default:
            return NULL;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        default:
            return NULL;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_cap;
        default:
            return NULL;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_value;
        default:
            return NULL;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validators;
        default:
            return NULL;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_era;
        case 1:
            return STR_IT_slash_indices;
        default:
            return NULL;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_history_depth;
        case 1:
            return STR_IT__era_items_deleted;
        default:
            return NULL;
        }
    case 2074: /* module 8 call 26 */
        switch (itemIdx) {
        case 0:
            return STR_IT_stash;
        case 1:
            return STR_IT_num_slashing_spans;
        default:
            return NULL;
        }
    case 2075: /* module 8 call 27 */
        switch (itemIdx) {
        case 0:
            return STR_IT_winners;
        case 1:
            return STR_IT_compact;
        case 2:
            return STR_IT_score;
        case 3:
            return STR_IT_era;
        case 4:
            return STR_IT_size;
        default:
            return NULL;
        }
    case 2076: /* module 8 call 28 */
        switch (itemIdx) {
        case 0:
            return STR_IT_winners;
        case 1:
            return STR_IT_compact;
        case 2:
            return STR_IT_score;
        case 3:
            return STR_IT_era;
        case 4:
            return STR_IT_size;
        default:
            return NULL;
        }
    case 2077: /* module 8 call 29 */
        switch (itemIdx) {
        case 0:
            return STR_IT_validator_stash;
        case 1:
            return STR_IT_era;
        default:
            return NULL;
        }
    case 2078: /* module 8 call 30 */
        switch (itemIdx) {
        case 0:
            return STR_IT_slashing_switch;
        default:
            return NULL;
        }
    case 2079: /* module 8 call 31 */
        switch (itemIdx) {
        case 0:
            return STR_IT_identity;
        case 1:
            return STR_IT_new_intended_count;
        default:
            return NULL;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_keys;
        case 1:
            return STR_IT_proof;
        default:
            return NULL;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_hint;
        default:
            return NULL;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_equivocation_proof;
        case 1:
            return STR_IT_key_owner_proof;
        default:
            return NULL;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_delay;
        case 1:
            return STR_IT_best_finalized_block_number;
        default:
            return NULL;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_heartbeat;
        case 1:
            return STR_IT__signature;
        default:
            return NULL;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_call;
        case 1:
            return STR_IT__weight;
        default:
            return NULL;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_new_;
        default:
            return NULL;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_is_enabled;
        default:
            return NULL;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_meta_info;
        case 1:
            return STR_IT_instantiation_fee;
        case 2:
            return STR_IT_code;
        default:
            return NULL;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_dest;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_gas_limit;
        case 3:
            return STR_IT_data;
        default:
            return NULL;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_endowment;
        case 1:
            return STR_IT_gas_limit;
        case 2:
            return STR_IT_code_hash;
        case 3:
            return STR_IT_data;
        case 4:
            return STR_IT_max_fee;
        default:
            return NULL;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 5126: /* module 20 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        default:
            return NULL;
        }
    case 5127: /* module 20 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        case 1:
            return STR_IT_new_owner;
        default:
            return NULL;
        }
    case 5128: /* module 20 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        case 1:
            return STR_IT_new_instantiation_fee;
        case 2:
            return STR_IT_new_usage_fee;
        default:
            return NULL;
        }
    case 5129: /* module 20 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_code_hash;
        case 1:
            return STR_IT_new_url;
        default:
            return NULL;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_beneficiaries;
        default:
            return NULL;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        default:
            return NULL;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_n;
        case 1:
            return STR_IT_d;
        default:
            return NULL;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 5636: /* module 22 call 4 */
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
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 5889: /* module 23 call 1 */
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
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_prune;
        default:
            return NULL;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_deposit;
        default:
            return NULL;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max;
        default:
            return NULL;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6153: /* module 24 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6154: /* module 24 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6155: /* module 24 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_until;
        default:
            return NULL;
        }
    case 6156: /* module 24 call 12 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6157: /* module 24 call 13 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6158: /* module 24 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_results;
        default:
            return NULL;
        }
    case 6159: /* module 24 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6160: /* module 24 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_did;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_n;
        case 1:
            return STR_IT_d;
        default:
            return NULL;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6404: /* module 25 call 4 */
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
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 6657: /* module 26 call 1 */
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
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_n;
        case 1:
            return STR_IT_d;
        default:
            return NULL;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_expiry;
        default:
            return NULL;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_approve;
        case 1:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 6916: /* module 27 call 4 */
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
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_limit;
        default:
            return NULL;
        }
    case 7169: /* module 28 call 1 */
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
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_who;
        default:
            return NULL;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_remove;
        case 1:
            return STR_IT_add;
        default:
            return NULL;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_members;
        default:
            return NULL;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_auth_id;
        default:
            return NULL;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_name;
        case 1:
            return STR_IT_ticker;
        case 2:
            return STR_IT_total_supply;
        case 3:
            return STR_IT_divisible;
        case 4:
            return STR_IT_asset_type;
        case 5:
            return STR_IT_identifiers;
        case 6:
            return STR_IT_funding_round;
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
        default:
            return NULL;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_value;
        default:
            return NULL;
        }
    case 7434: /* module 29 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7435: /* module 29 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_docs;
        case 1:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7436: /* module 29 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ids;
        case 1:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7437: /* module 29 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 7438: /* module 29 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_identifiers;
        default:
            return NULL;
        }
    case 7439: /* module 29 call 15 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_extension_details;
        default:
            return NULL;
        }
    case 7440: /* module 29 call 16 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_extension_id;
        default:
            return NULL;
        }
    case 7441: /* module 29 call 17 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_extension_id;
        default:
            return NULL;
        }
    case 7442: /* module 29 call 18 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_extension_id;
        default:
            return NULL;
        }
    case 7443: /* module 29 call 19 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 7444: /* module 29 call 20 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_ethereum_signature;
        default:
            return NULL;
        }
    case 7445: /* module 29 call 21 */
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
    case 7446: /* module 29 call 22 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_value;
        case 2:
            return STR_IT_from_portfolio;
        default:
            return NULL;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_controller;
        default:
            return NULL;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_admin;
        default:
            return NULL;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_timelock;
        default:
            return NULL;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_amount;
        case 1:
            return STR_IT_duration;
        default:
            return NULL;
        }
    case 7942: /* module 31 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_exempted;
        default:
            return NULL;
        }
    case 7943: /* module 31 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_txs;
        default:
            return NULL;
        }
    case 7945: /* module 31 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 7946: /* module 31 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 7947: /* module 31 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_txs;
        default:
            return NULL;
        }
    case 7948: /* module 31 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_txs;
        default:
            return NULL;
        }
    case 7949: /* module 31 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_bridge_tx;
        default:
            return NULL;
        }
    case 8192: /* module 32 call 0 */
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
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_asset_compliance;
        default:
            return NULL;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 8197: /* module 32 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 8198: /* module 32 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_issuer;
        default:
            return NULL;
        }
    case 8199: /* module 32 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_issuer;
        default:
            return NULL;
        }
    case 8200: /* module 32 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_new_req;
        default:
            return NULL;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_details;
        case 1:
            return STR_IT_signers;
        case 2:
            return STR_IT_venue_type;
        default:
            return NULL;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_venue_id;
        case 1:
            return STR_IT_details;
        case 2:
            return STR_IT_typ;
        default:
            return NULL;
        }
    case 9218: /* module 36 call 2 */
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
    case 9219: /* module 36 call 3 */
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
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_portfolios;
        case 2:
            return STR_IT_max_legs_count;
        default:
            return NULL;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_portfolios;
        case 2:
            return STR_IT_max_legs_count;
        default:
            return NULL;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_portfolios;
        case 2:
            return STR_IT_max_legs_count;
        default:
            return NULL;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_receipt_details;
        case 2:
            return STR_IT_portfolios;
        case 3:
            return STR_IT_max_legs_count;
        default:
            return NULL;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_receipt_details;
        default:
            return NULL;
        }
    case 9225: /* module 36 call 9 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_leg_id;
        default:
            return NULL;
        }
    case 9226: /* module 36 call 10 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_enabled;
        default:
            return NULL;
        }
    case 9227: /* module 36 call 11 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_venues;
        default:
            return NULL;
        }
    case 9228: /* module 36 call 12 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_venues;
        default:
            return NULL;
        }
    case 9229: /* module 36 call 13 */
        switch (itemIdx) {
        case 0:
            return STR_IT_receipt_uid;
        case 1:
            return STR_IT_validity;
        default:
            return NULL;
        }
    case 9230: /* module 36 call 14 */
        switch (itemIdx) {
        case 0:
            return STR_IT_instruction_id;
        case 1:
            return STR_IT_legs_count;
        default:
            return NULL;
        }
    case 9472: /* module 37 call 0 */
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
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_investment_portfolio;
        case 1:
            return STR_IT_funding_portfolio;
        case 2:
            return STR_IT_offering_asset;
        case 3:
            return STR_IT_fundraiser_id;
        case 4:
            return STR_IT_purchase_amount;
        case 5:
            return STR_IT_max_price;
        case 6:
            return STR_IT_receipt;
        default:
            return NULL;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_fundraiser_id;
        default:
            return NULL;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_fundraiser_id;
        default:
            return NULL;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_fundraiser_id;
        case 2:
            return STR_IT_start;
        case 3:
            return STR_IT_end;
        default:
            return NULL;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_offering_asset;
        case 1:
            return STR_IT_fundraiser_id;
        default:
            return NULL;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_new_transfer_manager;
        default:
            return NULL;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_transfer_manager;
        default:
            return NULL;
        }
    case 9986: /* module 39 call 2 */
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
    case 9987: /* module 39 call 3 */
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
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_coefficient;
        default:
            return NULL;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_op;
        case 1:
            return STR_IT_base_fee;
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
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_name;
        default:
            return NULL;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num;
        default:
            return NULL;
        }
    case 10754: /* module 42 call 2 */
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
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_num;
        case 1:
            return STR_IT_to_name;
        default:
            return NULL;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_when;
        case 1:
            return STR_IT_index;
        default:
            return NULL;
        }
    case 11522: /* module 45 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_when;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 11523: /* module 45 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 11524: /* module 45 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_after;
        case 1:
            return STR_IT_maybe_periodic;
        case 2:
            return STR_IT_priority;
        case 3:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 11525: /* module 45 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_after;
        case 2:
            return STR_IT_maybe_periodic;
        case 3:
            return STR_IT_priority;
        case 4:
            return STR_IT_call;
        default:
            return NULL;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_length;
        default:
            return NULL;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_targets;
        default:
            return NULL;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_tax;
        default:
            return NULL;
        }
    case 11780: /* module 46 call 4 */
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
    case 11781: /* module 46 call 5 */
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
    case 11782: /* module 46 call 6 */
        switch (itemIdx) {
        case 0:
            return STR_IT_id;
        case 1:
            return STR_IT_docs;
        default:
            return NULL;
        }
    case 11783: /* module 46 call 7 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 11784: /* module 46 call 8 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_record_date;
        default:
            return NULL;
        }
    case 12032: /* module 47 call 0 */
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
    case 12033: /* module 47 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_votes;
        default:
            return NULL;
        }
    case 12034: /* module 47 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_end;
        default:
            return NULL;
        }
    case 12035: /* module 47 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_meta;
        default:
            return NULL;
        }
    case 12036: /* module 47 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_rcv;
        default:
            return NULL;
        }
    case 12037: /* module 47 call 5 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 12288: /* module 48 call 0 */
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
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        case 1:
            return STR_IT_holder;
        default:
            return NULL;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 12292: /* module 48 call 4 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ca_id;
        default:
            return NULL;
        }
    case 12544: /* module 49 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        default:
            return NULL;
        }
    case 12545: /* module 49 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_max_complexity;
        default:
            return NULL;
        }
    case 12546: /* module 49 call 2 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_schedule;
        default:
            return NULL;
        }
    case 12547: /* module 49 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_ticker;
        case 1:
            return STR_IT_id;
        default:
            return NULL;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0:
            return STR_IT_uid;
        case 1:
            return STR_IT_secondary_keys;
        default:
            return NULL;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0:
            return STR_IT_target_account;
        default:
            return NULL;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        default:
            return NULL;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0:
            return STR_IT_of;
        default:
            return NULL;
        }
#endif
    default:
        return NULL;
    }

    return NULL;
}

parser_error_t _getMethod_ItemValue_V7(
    pd_Method_V7_t* m,
    uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx,
    char* outValue, uint16_t outValueLen,
    uint8_t pageIdx, uint8_t* pageCount)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1024: /* module 4 call 0 */
        switch (itemIdx) {
        case 0: /* balances_transfer_V7 - dest */;
            return _toStringLookupSource_V7(
                &m->nested.balances_transfer_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_V7 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1025: /* module 4 call 1 */
        switch (itemIdx) {
        case 0: /* balances_transfer_with_memo_V7 - dest */;
            return _toStringLookupSource_V7(
                &m->nested.balances_transfer_with_memo_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_transfer_with_memo_V7 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_transfer_with_memo_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_transfer_with_memo_V7 - memo */;
            return _toStringOptionMemo_V7(
                &m->nested.balances_transfer_with_memo_V7.memo,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1538: /* module 6 call 2 */
        switch (itemIdx) {
        case 0: /* identity_remove_secondary_keys_V7 - signers_to_remove */;
            return _toStringVecSignatory_V7(
                &m->nested.identity_remove_secondary_keys_V7.signers_to_remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1539: /* module 6 call 3 */
        switch (itemIdx) {
        case 0: /* identity_accept_primary_key_V7 - rotation_auth_id */;
            return _toStringu64(
                &m->nested.identity_accept_primary_key_V7.rotation_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_accept_primary_key_V7 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->nested.identity_accept_primary_key_V7.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1541: /* module 6 call 5 */
        switch (itemIdx) {
        case 0: /* identity_join_identity_as_key_V7 - auth_id */;
            return _toStringu64(
                &m->nested.identity_join_identity_as_key_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1542: /* module 6 call 6 */
        switch (itemIdx) {
        case 0: /* identity_join_identity_as_identity_V7 - auth_id */;
            return _toStringu64(
                &m->nested.identity_join_identity_as_identity_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1543: /* module 6 call 7 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1544: /* module 6 call 8 */
        switch (itemIdx) {
        case 0: /* identity_leave_identity_as_identity_V7 - did */;
            return _toStringIdentityId_V7(
                &m->nested.identity_leave_identity_as_identity_V7.did,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1545: /* module 6 call 9 */
        switch (itemIdx) {
        case 0: /* identity_add_claim_V7 - target */;
            return _toStringIdentityId_V7(
                &m->nested.identity_add_claim_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_claim_V7 - claim */;
            return _toStringClaim_V7(
                &m->nested.identity_add_claim_V7.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_claim_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.identity_add_claim_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1547: /* module 6 call 11 */
        switch (itemIdx) {
        case 0: /* identity_revoke_claim_V7 - target */;
            return _toStringIdentityId_V7(
                &m->nested.identity_revoke_claim_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_claim_V7 - claim */;
            return _toStringClaim_V7(
                &m->nested.identity_revoke_claim_V7.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1548: /* module 6 call 12 */
        switch (itemIdx) {
        case 0: /* identity_set_permission_to_signer_V7 - signer */;
            return _toStringSignatory_V7(
                &m->nested.identity_set_permission_to_signer_V7.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_set_permission_to_signer_V7 - permissions */;
            return _toStringPermissions_V7(
                &m->nested.identity_set_permission_to_signer_V7.permissions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1549: /* module 6 call 13 */
        switch (itemIdx) {
        case 0: /* identity_legacy_set_permission_to_signer_V7 - signer */;
            return _toStringSignatory_V7(
                &m->nested.identity_legacy_set_permission_to_signer_V7.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_legacy_set_permission_to_signer_V7 - permissions */;
            return _toStringLegacyPermissions_V7(
                &m->nested.identity_legacy_set_permission_to_signer_V7.permissions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1550: /* module 6 call 14 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1551: /* module 6 call 15 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 1552: /* module 6 call 16 */
        switch (itemIdx) {
        case 0: /* identity_add_authorization_V7 - target */;
            return _toStringSignatory_V7(
                &m->nested.identity_add_authorization_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_authorization_V7 - authorization_data */;
            return _toStringAuthorizationData_V7(
                &m->nested.identity_add_authorization_V7.authorization_data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_authorization_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.identity_add_authorization_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1553: /* module 6 call 17 */
        switch (itemIdx) {
        case 0: /* identity_remove_authorization_V7 - target */;
            return _toStringSignatory_V7(
                &m->nested.identity_remove_authorization_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_remove_authorization_V7 - auth_id */;
            return _toStringu64(
                &m->nested.identity_remove_authorization_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_remove_authorization_V7 - _auth_issuer_pays */;
            return _toStringbool(
                &m->nested.identity_remove_authorization_V7._auth_issuer_pays,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1554: /* module 6 call 18 */
        switch (itemIdx) {
        case 0: /* identity_accept_authorization_V7 - auth_id */;
            return _toStringu64(
                &m->nested.identity_accept_authorization_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1555: /* module 6 call 19 */
        switch (itemIdx) {
        case 0: /* identity_add_secondary_keys_with_authorization_V7 - additional_keys */;
            return _toStringVecSecondaryKeyWithAuth_V7(
                &m->nested.identity_add_secondary_keys_with_authorization_V7.additional_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_secondary_keys_with_authorization_V7 - expires_at */;
            return _toStringMoment_V7(
                &m->nested.identity_add_secondary_keys_with_authorization_V7.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1557: /* module 6 call 21 */
        switch (itemIdx) {
        case 0: /* identity_add_investor_uniqueness_claim_V7 - target */;
            return _toStringIdentityId_V7(
                &m->nested.identity_add_investor_uniqueness_claim_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_investor_uniqueness_claim_V7 - claim */;
            return _toStringClaim_V7(
                &m->nested.identity_add_investor_uniqueness_claim_V7.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_investor_uniqueness_claim_V7 - proof */;
            return _toStringInvestorZKProofData_V7(
                &m->nested.identity_add_investor_uniqueness_claim_V7.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* identity_add_investor_uniqueness_claim_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.identity_add_investor_uniqueness_claim_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2048: /* module 8 call 0 */
        switch (itemIdx) {
        case 0: /* staking_bond_V7 - controller */;
            return _toStringLookupSource_V7(
                &m->nested.staking_bond_V7.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_bond_V7 - value */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_bond_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_bond_V7 - payee */;
            return _toStringRewardDestination_V7(
                &m->nested.staking_bond_V7.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2049: /* module 8 call 1 */
        switch (itemIdx) {
        case 0: /* staking_bond_extra_V7 - max_additional */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_bond_extra_V7.max_additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2050: /* module 8 call 2 */
        switch (itemIdx) {
        case 0: /* staking_unbond_V7 - value */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_unbond_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2051: /* module 8 call 3 */
        switch (itemIdx) {
        case 0: /* staking_withdraw_unbonded_V7 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_withdraw_unbonded_V7.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2052: /* module 8 call 4 */
        switch (itemIdx) {
        case 0: /* staking_validate_V7 - prefs */;
            return _toStringValidatorPrefs_V7(
                &m->nested.staking_validate_V7.prefs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2053: /* module 8 call 5 */
        switch (itemIdx) {
        case 0: /* staking_nominate_V7 - targets */;
            return _toStringVecLookupSource_V7(
                &m->nested.staking_nominate_V7.targets,
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
    case 2055: /* module 8 call 7 */
        switch (itemIdx) {
        case 0: /* staking_set_payee_V7 - payee */;
            return _toStringRewardDestination_V7(
                &m->nested.staking_set_payee_V7.payee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2056: /* module 8 call 8 */
        switch (itemIdx) {
        case 0: /* staking_set_controller_V7 - controller */;
            return _toStringLookupSource_V7(
                &m->nested.staking_set_controller_V7.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2072: /* module 8 call 24 */
        switch (itemIdx) {
        case 0: /* staking_rebond_V7 - value */;
            return _toStringCompactBalanceOf(
                &m->nested.staking_rebond_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4608: /* module 18 call 0 */
        switch (itemIdx) {
        case 0: /* multisig_create_multisig_V7 - signers */;
            return _toStringVecSignatory_V7(
                &m->nested.multisig_create_multisig_V7.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_multisig_V7 - sigs_required */;
            return _toStringu64(
                &m->nested.multisig_create_multisig_V7.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4609: /* module 18 call 1 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_identity_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_identity_V7 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_identity_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_identity_V7 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_identity_V7.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4610: /* module 18 call 2 */
        switch (itemIdx) {
        case 0: /* multisig_create_or_approve_proposal_as_key_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_create_or_approve_proposal_as_key_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_or_approve_proposal_as_key_V7 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_or_approve_proposal_as_key_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_or_approve_proposal_as_key_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.multisig_create_or_approve_proposal_as_key_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_or_approve_proposal_as_key_V7 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_or_approve_proposal_as_key_V7.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4611: /* module 18 call 3 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_identity_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_create_proposal_as_identity_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_identity_V7 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_identity_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_identity_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.multisig_create_proposal_as_identity_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_identity_V7 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_identity_V7.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4612: /* module 18 call 4 */
        switch (itemIdx) {
        case 0: /* multisig_create_proposal_as_key_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_create_proposal_as_key_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_create_proposal_as_key_V7 - proposal */;
            return _toStringProposal(
                &m->nested.multisig_create_proposal_as_key_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_create_proposal_as_key_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.multisig_create_proposal_as_key_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_create_proposal_as_key_V7 - auto_close */;
            return _toStringbool(
                &m->nested.multisig_create_proposal_as_key_V7.auto_close,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4613: /* module 18 call 5 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_identity_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_approve_as_identity_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_identity_V7 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_approve_as_identity_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4614: /* module 18 call 6 */
        switch (itemIdx) {
        case 0: /* multisig_approve_as_key_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_approve_as_key_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_approve_as_key_V7 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_approve_as_key_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4615: /* module 18 call 7 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_identity_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_reject_as_identity_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_identity_V7 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_reject_as_identity_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4616: /* module 18 call 8 */
        switch (itemIdx) {
        case 0: /* multisig_reject_as_key_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_reject_as_key_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_reject_as_key_V7 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_reject_as_key_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4617: /* module 18 call 9 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_identity_V7 - auth_id */;
            return _toStringu64(
                &m->nested.multisig_accept_multisig_signer_as_identity_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4618: /* module 18 call 10 */
        switch (itemIdx) {
        case 0: /* multisig_accept_multisig_signer_as_key_V7 - auth_id */;
            return _toStringu64(
                &m->nested.multisig_accept_multisig_signer_as_key_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4619: /* module 18 call 11 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signer_V7 - signer */;
            return _toStringSignatory_V7(
                &m->nested.multisig_add_multisig_signer_V7.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4620: /* module 18 call 12 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signer_V7 - signer */;
            return _toStringSignatory_V7(
                &m->nested.multisig_remove_multisig_signer_V7.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4621: /* module 18 call 13 */
        switch (itemIdx) {
        case 0: /* multisig_add_multisig_signers_via_creator_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_add_multisig_signers_via_creator_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_add_multisig_signers_via_creator_V7 - signers */;
            return _toStringVecSignatory_V7(
                &m->nested.multisig_add_multisig_signers_via_creator_V7.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4622: /* module 18 call 14 */
        switch (itemIdx) {
        case 0: /* multisig_remove_multisig_signers_via_creator_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_remove_multisig_signers_via_creator_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_remove_multisig_signers_via_creator_V7 - signers */;
            return _toStringVecSignatory_V7(
                &m->nested.multisig_remove_multisig_signers_via_creator_V7.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4623: /* module 18 call 15 */
        switch (itemIdx) {
        case 0: /* multisig_change_sigs_required_V7 - sigs_required */;
            return _toStringu64(
                &m->nested.multisig_change_sigs_required_V7.sigs_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4624: /* module 18 call 16 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_signer_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_make_multisig_signer_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4625: /* module 18 call 17 */
        switch (itemIdx) {
        case 0: /* multisig_make_multisig_primary_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_make_multisig_primary_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_make_multisig_primary_V7 - optional_cdd_auth_id */;
            return _toStringOptionu64(
                &m->nested.multisig_make_multisig_primary_V7.optional_cdd_auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4626: /* module 18 call 18 */
        switch (itemIdx) {
        case 0: /* multisig_execute_scheduled_proposal_V7 - multisig */;
            return _toStringAccountId_V7(
                &m->nested.multisig_execute_scheduled_proposal_V7.multisig,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* multisig_execute_scheduled_proposal_V7 - proposal_id */;
            return _toStringu64(
                &m->nested.multisig_execute_scheduled_proposal_V7.proposal_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* multisig_execute_scheduled_proposal_V7 - multisig_did */;
            return _toStringIdentityId_V7(
                &m->nested.multisig_execute_scheduled_proposal_V7.multisig_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* multisig_execute_scheduled_proposal_V7 - proposal_weight */;
            return _toStringWeight_V7(
                &m->nested.multisig_execute_scheduled_proposal_V7.proposal_weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6150: /* module 24 call 6 */
        switch (itemIdx) {
        case 0: /* pips_propose_V7 - proposal */;
            return _toStringProposal(
                &m->nested.pips_propose_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_propose_V7 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pips_propose_V7.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_propose_V7 - url */;
            return _toStringOptionUrl_V7(
                &m->nested.pips_propose_V7.url,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* pips_propose_V7 - description */;
            return _toStringOptionPipDescription_V7(
                &m->nested.pips_propose_V7.description,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6151: /* module 24 call 7 */
        switch (itemIdx) {
        case 0: /* pips_vote_V7 - id */;
            return _toStringPipId_V7(
                &m->nested.pips_vote_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_vote_V7 - aye_or_nay */;
            return _toStringbool(
                &m->nested.pips_vote_V7.aye_or_nay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* pips_vote_V7 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pips_vote_V7.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10496: /* module 41 call 0 */
        switch (itemIdx) {
        case 0: /* utility_batch_V7 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_V7.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10497: /* module 41 call 1 */
        switch (itemIdx) {
        case 0: /* utility_batch_atomic_V7 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_atomic_V7.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10498: /* module 41 call 2 */
        switch (itemIdx) {
        case 0: /* utility_batch_optimistic_V7 - calls */;
            return _toStringVecCall(
                &m->nested.utility_batch_optimistic_V7.calls,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
#ifdef SUBSTRATE_PARSER_FULL
    case 0: /* module 0 call 0 */
        switch (itemIdx) {
        case 0: /* system_fill_block_V7 - _ratio */;
            return _toStringPerbill_V7(
                &m->nested.system_fill_block_V7._ratio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1: /* module 0 call 1 */
        switch (itemIdx) {
        case 0: /* system_remark_V7 - _remark */;
            return _toStringBytes(
                &m->nested.system_remark_V7._remark,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2: /* module 0 call 2 */
        switch (itemIdx) {
        case 0: /* system_set_heap_pages_V7 - pages */;
            return _toStringu64(
                &m->nested.system_set_heap_pages_V7.pages,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3: /* module 0 call 3 */
        switch (itemIdx) {
        case 0: /* system_set_code_V7 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_V7.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4: /* module 0 call 4 */
        switch (itemIdx) {
        case 0: /* system_set_code_without_checks_V7 - code */;
            return _toStringBytes(
                &m->nested.system_set_code_without_checks_V7.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5: /* module 0 call 5 */
        switch (itemIdx) {
        case 0: /* system_set_changes_trie_config_V7 - changes_trie_config */;
            return _toStringOptionChangesTrieConfiguration_V7(
                &m->nested.system_set_changes_trie_config_V7.changes_trie_config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6: /* module 0 call 6 */
        switch (itemIdx) {
        case 0: /* system_set_storage_V7 - items */;
            return _toStringVecKeyValue_V7(
                &m->nested.system_set_storage_V7.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7: /* module 0 call 7 */
        switch (itemIdx) {
        case 0: /* system_kill_storage_V7 - keys */;
            return _toStringVecKey_V7(
                &m->nested.system_kill_storage_V7.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8: /* module 0 call 8 */
        switch (itemIdx) {
        case 0: /* system_kill_prefix_V7 - prefix */;
            return _toStringKey_V7(
                &m->nested.system_kill_prefix_V7.prefix,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* system_kill_prefix_V7 - _subkeys */;
            return _toStringu32(
                &m->nested.system_kill_prefix_V7._subkeys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9: /* module 0 call 9 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 256: /* module 1 call 0 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_V7 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V7(
                &m->nested.babe_report_equivocation_V7.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_V7 - key_owner_proof */;
            return _toStringKeyOwnerProof_V7(
                &m->nested.babe_report_equivocation_V7.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 257: /* module 1 call 1 */
        switch (itemIdx) {
        case 0: /* babe_report_equivocation_unsigned_V7 - equivocation_proof */;
            return _toStringBabeEquivocationProof_V7(
                &m->nested.babe_report_equivocation_unsigned_V7.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* babe_report_equivocation_unsigned_V7 - key_owner_proof */;
            return _toStringKeyOwnerProof_V7(
                &m->nested.babe_report_equivocation_unsigned_V7.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 512: /* module 2 call 0 */
        switch (itemIdx) {
        case 0: /* timestamp_set_V7 - now */;
            return _toStringCompactMoment_V7(
                &m->nested.timestamp_set_V7.now,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 768: /* module 3 call 0 */
        switch (itemIdx) {
        case 0: /* indices_claim_V7 - index */;
            return _toStringAccountIndex_V7(
                &m->nested.indices_claim_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 769: /* module 3 call 1 */
        switch (itemIdx) {
        case 0: /* indices_transfer_V7 - new_ */;
            return _toStringAccountId_V7(
                &m->nested.indices_transfer_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_transfer_V7 - index */;
            return _toStringAccountIndex_V7(
                &m->nested.indices_transfer_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 770: /* module 3 call 2 */
        switch (itemIdx) {
        case 0: /* indices_free_V7 - index */;
            return _toStringAccountIndex_V7(
                &m->nested.indices_free_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 771: /* module 3 call 3 */
        switch (itemIdx) {
        case 0: /* indices_force_transfer_V7 - new_ */;
            return _toStringAccountId_V7(
                &m->nested.indices_force_transfer_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* indices_force_transfer_V7 - index */;
            return _toStringAccountIndex_V7(
                &m->nested.indices_force_transfer_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* indices_force_transfer_V7 - freeze */;
            return _toStringbool(
                &m->nested.indices_force_transfer_V7.freeze,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 772: /* module 3 call 4 */
        switch (itemIdx) {
        case 0: /* indices_freeze_V7 - index */;
            return _toStringAccountIndex_V7(
                &m->nested.indices_freeze_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1026: /* module 4 call 2 */
        switch (itemIdx) {
        case 0: /* balances_deposit_block_reward_reserve_balance_V7 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_deposit_block_reward_reserve_balance_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1027: /* module 4 call 3 */
        switch (itemIdx) {
        case 0: /* balances_set_balance_V7 - who */;
            return _toStringLookupSource_V7(
                &m->nested.balances_set_balance_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_set_balance_V7 - new_free */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V7.new_free,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_set_balance_V7 - new_reserved */;
            return _toStringCompactBalance(
                &m->nested.balances_set_balance_V7.new_reserved,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1028: /* module 4 call 4 */
        switch (itemIdx) {
        case 0: /* balances_force_transfer_V7 - source */;
            return _toStringLookupSource_V7(
                &m->nested.balances_force_transfer_V7.source,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* balances_force_transfer_V7 - dest */;
            return _toStringLookupSource_V7(
                &m->nested.balances_force_transfer_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* balances_force_transfer_V7 - value */;
            return _toStringCompactBalance(
                &m->nested.balances_force_transfer_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1029: /* module 4 call 5 */
        switch (itemIdx) {
        case 0: /* balances_burn_account_balance_V7 - amount */;
            return _toStringBalance(
                &m->nested.balances_burn_account_balance_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1536: /* module 6 call 0 */
        switch (itemIdx) {
        case 0: /* identity_cdd_register_did_V7 - target_account */;
            return _toStringAccountId_V7(
                &m->nested.identity_cdd_register_did_V7.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_cdd_register_did_V7 - secondary_keys */;
            return _toStringVecSecondaryKey_V7(
                &m->nested.identity_cdd_register_did_V7.secondary_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1537: /* module 6 call 1 */
        switch (itemIdx) {
        case 0: /* identity_invalidate_cdd_claims_V7 - cdd */;
            return _toStringIdentityId_V7(
                &m->nested.identity_invalidate_cdd_claims_V7.cdd,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_invalidate_cdd_claims_V7 - disable_from */;
            return _toStringMoment_V7(
                &m->nested.identity_invalidate_cdd_claims_V7.disable_from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_invalidate_cdd_claims_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.identity_invalidate_cdd_claims_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1540: /* module 6 call 4 */
        switch (itemIdx) {
        case 0: /* identity_change_cdd_requirement_for_mk_rotation_V7 - auth_required */;
            return _toStringbool(
                &m->nested.identity_change_cdd_requirement_for_mk_rotation_V7.auth_required,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1546: /* module 6 call 10 */
        switch (itemIdx) {
        case 0: /* identity_forwarded_call_V7 - target_did */;
            return _toStringIdentityId_V7(
                &m->nested.identity_forwarded_call_V7.target_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_forwarded_call_V7 - proposal */;
            return _toStringProposal(
                &m->nested.identity_forwarded_call_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1556: /* module 6 call 20 */
        switch (itemIdx) {
        case 0: /* identity_revoke_offchain_authorization_V7 - signer */;
            return _toStringSignatory_V7(
                &m->nested.identity_revoke_offchain_authorization_V7.signer,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_revoke_offchain_authorization_V7 - auth */;
            return _toStringTargetIdAuthorization_V7(
                &m->nested.identity_revoke_offchain_authorization_V7.auth,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1558: /* module 6 call 22 */
        switch (itemIdx) {
        case 0: /* identity_gc_add_cdd_claim_V7 - target */;
            return _toStringIdentityId_V7(
                &m->nested.identity_gc_add_cdd_claim_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_gc_add_cdd_claim_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.identity_gc_add_cdd_claim_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1559: /* module 6 call 23 */
        switch (itemIdx) {
        case 0: /* identity_gc_revoke_cdd_claim_V7 - target */;
            return _toStringIdentityId_V7(
                &m->nested.identity_gc_revoke_cdd_claim_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1560: /* module 6 call 24 */
        switch (itemIdx) {
        case 0: /* identity_add_investor_uniqueness_claim_v2_V7 - target */;
            return _toStringIdentityId_V7(
                &m->basic.identity_add_investor_uniqueness_claim_v2_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* identity_add_investor_uniqueness_claim_v2_V7 - claim */;
            return _toStringClaim_V7(
                &m->basic.identity_add_investor_uniqueness_claim_v2_V7.claim,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* identity_add_investor_uniqueness_claim_v2_V7 - proof */;
            return _toStringScopeClaimProof_V7(
                &m->basic.identity_add_investor_uniqueness_claim_v2_V7.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* identity_add_investor_uniqueness_claim_v2_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->basic.identity_add_investor_uniqueness_claim_v2_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 1792: /* module 7 call 0 */
        switch (itemIdx) {
        case 0: /* authorship_set_uncles_V7 - new_uncles */;
            return _toStringVecHeader(
                &m->nested.authorship_set_uncles_V7.new_uncles,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9728: /* module 38 call 0 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_set_active_members_limit_V7 - limit */;
            return _toStringMemberCount_V7(
                &m->nested.cddserviceproviders_set_active_members_limit_V7.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9729: /* module 38 call 1 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_disable_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.cddserviceproviders_disable_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_disable_member_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.cddserviceproviders_disable_member_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* cddserviceproviders_disable_member_V7 - at */;
            return _toStringOptionMoment_V7(
                &m->nested.cddserviceproviders_disable_member_V7.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9730: /* module 38 call 2 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_add_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.cddserviceproviders_add_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9731: /* module 38 call 3 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_remove_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.cddserviceproviders_remove_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9732: /* module 38 call 4 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_swap_member_V7 - remove */;
            return _toStringIdentityId_V7(
                &m->nested.cddserviceproviders_swap_member_V7.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* cddserviceproviders_swap_member_V7 - add */;
            return _toStringIdentityId_V7(
                &m->nested.cddserviceproviders_swap_member_V7.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9733: /* module 38 call 5 */
        switch (itemIdx) {
        case 0: /* cddserviceproviders_reset_members_V7 - members */;
            return _toStringVecIdentityId_V7(
                &m->nested.cddserviceproviders_reset_members_V7.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9734: /* module 38 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2057: /* module 8 call 9 */
        switch (itemIdx) {
        case 0: /* staking_set_validator_count_V7 - new_ */;
            return _toStringCompactu32(
                &m->nested.staking_set_validator_count_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2058: /* module 8 call 10 */
        switch (itemIdx) {
        case 0: /* staking_increase_validator_count_V7 - additional */;
            return _toStringCompactu32(
                &m->nested.staking_increase_validator_count_V7.additional,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2059: /* module 8 call 11 */
        switch (itemIdx) {
        case 0: /* staking_scale_validator_count_V7 - factor */;
            return _toStringPercent_V7(
                &m->nested.staking_scale_validator_count_V7.factor,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2060: /* module 8 call 12 */
        switch (itemIdx) {
        case 0: /* staking_add_permissioned_validator_V7 - identity */;
            return _toStringIdentityId_V7(
                &m->nested.staking_add_permissioned_validator_V7.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_add_permissioned_validator_V7 - intended_count */;
            return _toStringOptionu32(
                &m->nested.staking_add_permissioned_validator_V7.intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2061: /* module 8 call 13 */
        switch (itemIdx) {
        case 0: /* staking_remove_permissioned_validator_V7 - identity */;
            return _toStringIdentityId_V7(
                &m->nested.staking_remove_permissioned_validator_V7.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2062: /* module 8 call 14 */
        switch (itemIdx) {
        case 0: /* staking_validate_cdd_expiry_nominators_V7 - targets */;
            return _toStringVecAccountId_V7(
                &m->nested.staking_validate_cdd_expiry_nominators_V7.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2063: /* module 8 call 15 */
        switch (itemIdx) {
        case 0: /* staking_set_commission_cap_V7 - new_cap */;
            return _toStringPerbill_V7(
                &m->nested.staking_set_commission_cap_V7.new_cap,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2064: /* module 8 call 16 */
        switch (itemIdx) {
        case 0: /* staking_set_min_bond_threshold_V7 - new_value */;
            return _toStringBalanceOf(
                &m->nested.staking_set_min_bond_threshold_V7.new_value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2065: /* module 8 call 17 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2066: /* module 8 call 18 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2067: /* module 8 call 19 */
        switch (itemIdx) {
        case 0: /* staking_set_invulnerables_V7 - validators */;
            return _toStringVecAccountId_V7(
                &m->nested.staking_set_invulnerables_V7.validators,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2068: /* module 8 call 20 */
        switch (itemIdx) {
        case 0: /* staking_force_unstake_V7 - stash */;
            return _toStringAccountId_V7(
                &m->nested.staking_force_unstake_V7.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_force_unstake_V7 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_force_unstake_V7.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2069: /* module 8 call 21 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2070: /* module 8 call 22 */
        switch (itemIdx) {
        case 0: /* staking_cancel_deferred_slash_V7 - era */;
            return _toStringEraIndex_V7(
                &m->nested.staking_cancel_deferred_slash_V7.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_cancel_deferred_slash_V7 - slash_indices */;
            return _toStringVecu32(
                &m->nested.staking_cancel_deferred_slash_V7.slash_indices,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2071: /* module 8 call 23 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_V7 - validator_stash */;
            return _toStringAccountId_V7(
                &m->nested.staking_payout_stakers_V7.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_V7 - era */;
            return _toStringEraIndex_V7(
                &m->nested.staking_payout_stakers_V7.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2073: /* module 8 call 25 */
        switch (itemIdx) {
        case 0: /* staking_set_history_depth_V7 - new_history_depth */;
            return _toStringCompactEraIndex_V7(
                &m->nested.staking_set_history_depth_V7.new_history_depth,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_set_history_depth_V7 - _era_items_deleted */;
            return _toStringCompactu32(
                &m->nested.staking_set_history_depth_V7._era_items_deleted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2074: /* module 8 call 26 */
        switch (itemIdx) {
        case 0: /* staking_reap_stash_V7 - stash */;
            return _toStringAccountId_V7(
                &m->nested.staking_reap_stash_V7.stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_reap_stash_V7 - num_slashing_spans */;
            return _toStringu32(
                &m->nested.staking_reap_stash_V7.num_slashing_spans,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2075: /* module 8 call 27 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_V7 - winners */;
            return _toStringVecValidatorIndex_V7(
                &m->nested.staking_submit_election_solution_V7.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_V7 - compact */;
            return _toStringCompactAssignments_V7(
                &m->nested.staking_submit_election_solution_V7.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_V7 - score */;
            return _toStringElectionScore_V7(
                &m->nested.staking_submit_election_solution_V7.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_V7 - era */;
            return _toStringEraIndex_V7(
                &m->nested.staking_submit_election_solution_V7.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_V7 - size */;
            return _toStringElectionSize_V7(
                &m->nested.staking_submit_election_solution_V7.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2076: /* module 8 call 28 */
        switch (itemIdx) {
        case 0: /* staking_submit_election_solution_unsigned_V7 - winners */;
            return _toStringVecValidatorIndex_V7(
                &m->nested.staking_submit_election_solution_unsigned_V7.winners,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_submit_election_solution_unsigned_V7 - compact */;
            return _toStringCompactAssignments_V7(
                &m->nested.staking_submit_election_solution_unsigned_V7.compact,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* staking_submit_election_solution_unsigned_V7 - score */;
            return _toStringElectionScore_V7(
                &m->nested.staking_submit_election_solution_unsigned_V7.score,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* staking_submit_election_solution_unsigned_V7 - era */;
            return _toStringEraIndex_V7(
                &m->nested.staking_submit_election_solution_unsigned_V7.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* staking_submit_election_solution_unsigned_V7 - size */;
            return _toStringElectionSize_V7(
                &m->nested.staking_submit_election_solution_unsigned_V7.size,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2077: /* module 8 call 29 */
        switch (itemIdx) {
        case 0: /* staking_payout_stakers_by_system_V7 - validator_stash */;
            return _toStringAccountId_V7(
                &m->nested.staking_payout_stakers_by_system_V7.validator_stash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_payout_stakers_by_system_V7 - era */;
            return _toStringEraIndex_V7(
                &m->nested.staking_payout_stakers_by_system_V7.era,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2078: /* module 8 call 30 */
        switch (itemIdx) {
        case 0: /* staking_change_slashing_allowed_for_V7 - slashing_switch */;
            return _toStringSlashingSwitch_V7(
                &m->nested.staking_change_slashing_allowed_for_V7.slashing_switch,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2079: /* module 8 call 31 */
        switch (itemIdx) {
        case 0: /* staking_update_permissioned_validator_intended_count_V7 - identity */;
            return _toStringIdentityId_V7(
                &m->nested.staking_update_permissioned_validator_intended_count_V7.identity,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* staking_update_permissioned_validator_intended_count_V7 - new_intended_count */;
            return _toStringu32(
                &m->nested.staking_update_permissioned_validator_intended_count_V7.new_intended_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2560: /* module 10 call 0 */
        switch (itemIdx) {
        case 0: /* session_set_keys_V7 - keys */;
            return _toStringKeys_V7(
                &m->nested.session_set_keys_V7.keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* session_set_keys_V7 - proof */;
            return _toStringBytes(
                &m->nested.session_set_keys_V7.proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 2561: /* module 10 call 1 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 2816: /* module 11 call 0 */
        switch (itemIdx) {
        case 0: /* finalitytracker_final_hint_V7 - hint */;
            return _toStringCompactBlockNumber(
                &m->nested.finalitytracker_final_hint_V7.hint,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3072: /* module 12 call 0 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_V7 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V7(
                &m->nested.grandpa_report_equivocation_V7.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_V7 - key_owner_proof */;
            return _toStringKeyOwnerProof_V7(
                &m->nested.grandpa_report_equivocation_V7.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3073: /* module 12 call 1 */
        switch (itemIdx) {
        case 0: /* grandpa_report_equivocation_unsigned_V7 - equivocation_proof */;
            return _toStringGrandpaEquivocationProof_V7(
                &m->nested.grandpa_report_equivocation_unsigned_V7.equivocation_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_report_equivocation_unsigned_V7 - key_owner_proof */;
            return _toStringKeyOwnerProof_V7(
                &m->nested.grandpa_report_equivocation_unsigned_V7.key_owner_proof,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3074: /* module 12 call 2 */
        switch (itemIdx) {
        case 0: /* grandpa_note_stalled_V7 - delay */;
            return _toStringBlockNumber(
                &m->nested.grandpa_note_stalled_V7.delay,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* grandpa_note_stalled_V7 - best_finalized_block_number */;
            return _toStringBlockNumber(
                &m->nested.grandpa_note_stalled_V7.best_finalized_block_number,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 3328: /* module 13 call 0 */
        switch (itemIdx) {
        case 0: /* imonline_heartbeat_V7 - heartbeat */;
            return _toStringHeartbeat(
                &m->nested.imonline_heartbeat_V7.heartbeat,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* imonline_heartbeat_V7 - _signature */;
            return _toStringSignature_V7(
                &m->nested.imonline_heartbeat_V7._signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4352: /* module 17 call 0 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_V7 - call */;
            return _toStringCall(
                &m->nested.sudo_sudo_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4353: /* module 17 call 1 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_unchecked_weight_V7 - call */;
            return _toStringCall(
                &m->nested.sudo_sudo_unchecked_weight_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_unchecked_weight_V7 - _weight */;
            return _toStringWeight_V7(
                &m->nested.sudo_sudo_unchecked_weight_V7._weight,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4354: /* module 17 call 2 */
        switch (itemIdx) {
        case 0: /* sudo_set_key_V7 - new_ */;
            return _toStringLookupSource_V7(
                &m->nested.sudo_set_key_V7.new_,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 4355: /* module 17 call 3 */
        switch (itemIdx) {
        case 0: /* sudo_sudo_as_V7 - who */;
            return _toStringLookupSource_V7(
                &m->nested.sudo_sudo_as_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sudo_sudo_as_V7 - call */;
            return _toStringCall(
                &m->nested.sudo_sudo_as_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5120: /* module 20 call 0 */
        switch (itemIdx) {
        case 0: /* contracts_update_schedule_V7 - schedule */;
            return _toStringSchedule_V7(
                &m->nested.contracts_update_schedule_V7.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5121: /* module 20 call 1 */
        switch (itemIdx) {
        case 0: /* contracts_set_put_code_flag_V7 - is_enabled */;
            return _toStringbool(
                &m->basic.contracts_set_put_code_flag_V7.is_enabled,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5122: /* module 20 call 2 */
        switch (itemIdx) {
        case 0: /* contracts_put_code_V7 - meta_info */;
            return _toStringTemplateMetadata_V7(
                &m->nested.contracts_put_code_V7.meta_info,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_put_code_V7 - instantiation_fee */;
            return _toStringBalanceOf(
                &m->nested.contracts_put_code_V7.instantiation_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_put_code_V7 - code */;
            return _toStringBytes(
                &m->nested.contracts_put_code_V7.code,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5123: /* module 20 call 3 */
        switch (itemIdx) {
        case 0: /* contracts_call_V7 - dest */;
            return _toStringLookupSource_V7(
                &m->nested.contracts_call_V7.dest,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_call_V7 - value */;
            return _toStringCompactBalanceOf(
                &m->nested.contracts_call_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_call_V7 - gas_limit */;
            return _toStringCompactGas_V7(
                &m->nested.contracts_call_V7.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_call_V7 - data */;
            return _toStringBytes(
                &m->nested.contracts_call_V7.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5124: /* module 20 call 4 */
        switch (itemIdx) {
        case 0: /* contracts_instantiate_V7 - endowment */;
            return _toStringCompactBalanceOf(
                &m->nested.contracts_instantiate_V7.endowment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_instantiate_V7 - gas_limit */;
            return _toStringCompactGas_V7(
                &m->nested.contracts_instantiate_V7.gas_limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_instantiate_V7 - code_hash */;
            return _toStringCodeHash_V7(
                &m->nested.contracts_instantiate_V7.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* contracts_instantiate_V7 - data */;
            return _toStringBytes(
                &m->nested.contracts_instantiate_V7.data,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* contracts_instantiate_V7 - max_fee */;
            return _toStringBalanceOf(
                &m->nested.contracts_instantiate_V7.max_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5125: /* module 20 call 5 */
        switch (itemIdx) {
        case 0: /* contracts_freeze_instantiation_V7 - code_hash */;
            return _toStringCodeHash_V7(
                &m->nested.contracts_freeze_instantiation_V7.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5126: /* module 20 call 6 */
        switch (itemIdx) {
        case 0: /* contracts_unfreeze_instantiation_V7 - code_hash */;
            return _toStringCodeHash_V7(
                &m->nested.contracts_unfreeze_instantiation_V7.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5127: /* module 20 call 7 */
        switch (itemIdx) {
        case 0: /* contracts_transfer_template_ownership_V7 - code_hash */;
            return _toStringCodeHash_V7(
                &m->nested.contracts_transfer_template_ownership_V7.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_transfer_template_ownership_V7 - new_owner */;
            return _toStringIdentityId_V7(
                &m->nested.contracts_transfer_template_ownership_V7.new_owner,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5128: /* module 20 call 8 */
        switch (itemIdx) {
        case 0: /* contracts_change_template_fees_V7 - code_hash */;
            return _toStringCodeHash_V7(
                &m->nested.contracts_change_template_fees_V7.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_change_template_fees_V7 - new_instantiation_fee */;
            return _toStringOptionBalanceOf(
                &m->nested.contracts_change_template_fees_V7.new_instantiation_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* contracts_change_template_fees_V7 - new_usage_fee */;
            return _toStringOptionBalanceOf(
                &m->nested.contracts_change_template_fees_V7.new_usage_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5129: /* module 20 call 9 */
        switch (itemIdx) {
        case 0: /* contracts_change_template_meta_url_V7 - code_hash */;
            return _toStringCodeHash_V7(
                &m->nested.contracts_change_template_meta_url_V7.code_hash,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* contracts_change_template_meta_url_V7 - new_url */;
            return _toStringOptionMetaUrl_V7(
                &m->nested.contracts_change_template_meta_url_V7.new_url,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5376: /* module 21 call 0 */
        switch (itemIdx) {
        case 0: /* treasury_disbursement_V7 - beneficiaries */;
            return _toStringVecBeneficiary_V7(
                &m->nested.treasury_disbursement_V7.beneficiaries,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5377: /* module 21 call 1 */
        switch (itemIdx) {
        case 0: /* treasury_reimbursement_V7 - amount */;
            return _toStringBalanceOf(
                &m->nested.treasury_reimbursement_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5632: /* module 22 call 0 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_vote_threshold_V7 - n */;
            return _toStringu32(
                &m->nested.polymeshcommittee_set_vote_threshold_V7.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_set_vote_threshold_V7 - d */;
            return _toStringu32(
                &m->nested.polymeshcommittee_set_vote_threshold_V7.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5633: /* module 22 call 1 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_release_coordinator_V7 - id */;
            return _toStringIdentityId_V7(
                &m->nested.polymeshcommittee_set_release_coordinator_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5634: /* module 22 call 2 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_set_expires_after_V7 - expiry */;
            return _toStringMaybeBlock_V7(
                &m->nested.polymeshcommittee_set_expires_after_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5635: /* module 22 call 3 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_or_propose_V7 - approve */;
            return _toStringbool(
                &m->nested.polymeshcommittee_vote_or_propose_V7.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_or_propose_V7 - call */;
            return _toStringCall(
                &m->nested.polymeshcommittee_vote_or_propose_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5636: /* module 22 call 4 */
        switch (itemIdx) {
        case 0: /* polymeshcommittee_vote_V7 - proposal */;
            return _toStringHash(
                &m->nested.polymeshcommittee_vote_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* polymeshcommittee_vote_V7 - index */;
            return _toStringProposalIndex_V7(
                &m->nested.polymeshcommittee_vote_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* polymeshcommittee_vote_V7 - approve */;
            return _toStringbool(
                &m->nested.polymeshcommittee_vote_V7.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5888: /* module 23 call 0 */
        switch (itemIdx) {
        case 0: /* committeemembership_set_active_members_limit_V7 - limit */;
            return _toStringMemberCount_V7(
                &m->nested.committeemembership_set_active_members_limit_V7.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5889: /* module 23 call 1 */
        switch (itemIdx) {
        case 0: /* committeemembership_disable_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.committeemembership_disable_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_disable_member_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.committeemembership_disable_member_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* committeemembership_disable_member_V7 - at */;
            return _toStringOptionMoment_V7(
                &m->nested.committeemembership_disable_member_V7.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5890: /* module 23 call 2 */
        switch (itemIdx) {
        case 0: /* committeemembership_add_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.committeemembership_add_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5891: /* module 23 call 3 */
        switch (itemIdx) {
        case 0: /* committeemembership_remove_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.committeemembership_remove_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5892: /* module 23 call 4 */
        switch (itemIdx) {
        case 0: /* committeemembership_swap_member_V7 - remove */;
            return _toStringIdentityId_V7(
                &m->nested.committeemembership_swap_member_V7.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* committeemembership_swap_member_V7 - add */;
            return _toStringIdentityId_V7(
                &m->nested.committeemembership_swap_member_V7.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5893: /* module 23 call 5 */
        switch (itemIdx) {
        case 0: /* committeemembership_reset_members_V7 - members */;
            return _toStringVecIdentityId_V7(
                &m->nested.committeemembership_reset_members_V7.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 5894: /* module 23 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6144: /* module 24 call 0 */
        switch (itemIdx) {
        case 0: /* pips_set_prune_historical_pips_V7 - prune */;
            return _toStringbool(
                &m->nested.pips_set_prune_historical_pips_V7.prune,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6145: /* module 24 call 1 */
        switch (itemIdx) {
        case 0: /* pips_set_min_proposal_deposit_V7 - deposit */;
            return _toStringBalanceOf(
                &m->nested.pips_set_min_proposal_deposit_V7.deposit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6146: /* module 24 call 2 */
        switch (itemIdx) {
        case 0: /* pips_set_default_enactment_period_V7 - duration */;
            return _toStringBlockNumber(
                &m->nested.pips_set_default_enactment_period_V7.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6147: /* module 24 call 3 */
        switch (itemIdx) {
        case 0: /* pips_set_pending_pip_expiry_V7 - expiry */;
            return _toStringMaybeBlock_V7(
                &m->nested.pips_set_pending_pip_expiry_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6148: /* module 24 call 4 */
        switch (itemIdx) {
        case 0: /* pips_set_max_pip_skip_count_V7 - max */;
            return _toStringSkippedCount_V7(
                &m->nested.pips_set_max_pip_skip_count_V7.max,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6149: /* module 24 call 5 */
        switch (itemIdx) {
        case 0: /* pips_set_active_pip_limit_V7 - limit */;
            return _toStringu32(
                &m->nested.pips_set_active_pip_limit_V7.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6152: /* module 24 call 8 */
        switch (itemIdx) {
        case 0: /* pips_approve_committee_proposal_V7 - id */;
            return _toStringPipId_V7(
                &m->nested.pips_approve_committee_proposal_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6153: /* module 24 call 9 */
        switch (itemIdx) {
        case 0: /* pips_reject_proposal_V7 - id */;
            return _toStringPipId_V7(
                &m->nested.pips_reject_proposal_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6154: /* module 24 call 10 */
        switch (itemIdx) {
        case 0: /* pips_prune_proposal_V7 - id */;
            return _toStringPipId_V7(
                &m->nested.pips_prune_proposal_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6155: /* module 24 call 11 */
        switch (itemIdx) {
        case 0: /* pips_reschedule_execution_V7 - id */;
            return _toStringPipId_V7(
                &m->nested.pips_reschedule_execution_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_reschedule_execution_V7 - until */;
            return _toStringOptionBlockNumber(
                &m->nested.pips_reschedule_execution_V7.until,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6156: /* module 24 call 12 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6157: /* module 24 call 13 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6158: /* module 24 call 14 */
        switch (itemIdx) {
        case 0: /* pips_enact_snapshot_results_V7 - results */;
            return _toStringVecTuplePipIdSnapshotResult_V7(
                &m->nested.pips_enact_snapshot_results_V7.results,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6159: /* module 24 call 15 */
        switch (itemIdx) {
        case 0: /* pips_execute_scheduled_pip_V7 - id */;
            return _toStringPipId_V7(
                &m->nested.pips_execute_scheduled_pip_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6160: /* module 24 call 16 */
        switch (itemIdx) {
        case 0: /* pips_expire_scheduled_pip_V7 - did */;
            return _toStringIdentityId_V7(
                &m->nested.pips_expire_scheduled_pip_V7.did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* pips_expire_scheduled_pip_V7 - id */;
            return _toStringPipId_V7(
                &m->nested.pips_expire_scheduled_pip_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6400: /* module 25 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_vote_threshold_V7 - n */;
            return _toStringu32(
                &m->nested.technicalcommittee_set_vote_threshold_V7.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_set_vote_threshold_V7 - d */;
            return _toStringu32(
                &m->nested.technicalcommittee_set_vote_threshold_V7.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6401: /* module 25 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_release_coordinator_V7 - id */;
            return _toStringIdentityId_V7(
                &m->nested.technicalcommittee_set_release_coordinator_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6402: /* module 25 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_set_expires_after_V7 - expiry */;
            return _toStringMaybeBlock_V7(
                &m->nested.technicalcommittee_set_expires_after_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6403: /* module 25 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_or_propose_V7 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_or_propose_V7.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_or_propose_V7 - call */;
            return _toStringCall(
                &m->nested.technicalcommittee_vote_or_propose_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6404: /* module 25 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommittee_vote_V7 - proposal */;
            return _toStringHash(
                &m->nested.technicalcommittee_vote_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommittee_vote_V7 - index */;
            return _toStringProposalIndex_V7(
                &m->nested.technicalcommittee_vote_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommittee_vote_V7 - approve */;
            return _toStringbool(
                &m->nested.technicalcommittee_vote_V7.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6656: /* module 26 call 0 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_set_active_members_limit_V7 - limit */;
            return _toStringMemberCount_V7(
                &m->nested.technicalcommitteemembership_set_active_members_limit_V7.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6657: /* module 26 call 1 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_disable_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.technicalcommitteemembership_disable_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_disable_member_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.technicalcommitteemembership_disable_member_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* technicalcommitteemembership_disable_member_V7 - at */;
            return _toStringOptionMoment_V7(
                &m->nested.technicalcommitteemembership_disable_member_V7.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6658: /* module 26 call 2 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_add_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.technicalcommitteemembership_add_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6659: /* module 26 call 3 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_remove_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.technicalcommitteemembership_remove_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6660: /* module 26 call 4 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_swap_member_V7 - remove */;
            return _toStringIdentityId_V7(
                &m->nested.technicalcommitteemembership_swap_member_V7.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* technicalcommitteemembership_swap_member_V7 - add */;
            return _toStringIdentityId_V7(
                &m->nested.technicalcommitteemembership_swap_member_V7.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6661: /* module 26 call 5 */
        switch (itemIdx) {
        case 0: /* technicalcommitteemembership_reset_members_V7 - members */;
            return _toStringVecIdentityId_V7(
                &m->nested.technicalcommitteemembership_reset_members_V7.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6662: /* module 26 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 6912: /* module 27 call 0 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_vote_threshold_V7 - n */;
            return _toStringu32(
                &m->nested.upgradecommittee_set_vote_threshold_V7.n,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_set_vote_threshold_V7 - d */;
            return _toStringu32(
                &m->nested.upgradecommittee_set_vote_threshold_V7.d,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6913: /* module 27 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_release_coordinator_V7 - id */;
            return _toStringIdentityId_V7(
                &m->nested.upgradecommittee_set_release_coordinator_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6914: /* module 27 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_set_expires_after_V7 - expiry */;
            return _toStringMaybeBlock_V7(
                &m->nested.upgradecommittee_set_expires_after_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6915: /* module 27 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_or_propose_V7 - approve */;
            return _toStringbool(
                &m->nested.upgradecommittee_vote_or_propose_V7.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_or_propose_V7 - call */;
            return _toStringCall(
                &m->nested.upgradecommittee_vote_or_propose_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 6916: /* module 27 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommittee_vote_V7 - proposal */;
            return _toStringHash(
                &m->nested.upgradecommittee_vote_V7.proposal,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommittee_vote_V7 - index */;
            return _toStringProposalIndex_V7(
                &m->nested.upgradecommittee_vote_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommittee_vote_V7 - approve */;
            return _toStringbool(
                &m->nested.upgradecommittee_vote_V7.approve,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7168: /* module 28 call 0 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_set_active_members_limit_V7 - limit */;
            return _toStringMemberCount_V7(
                &m->nested.upgradecommitteemembership_set_active_members_limit_V7.limit,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7169: /* module 28 call 1 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_disable_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.upgradecommitteemembership_disable_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_disable_member_V7 - expiry */;
            return _toStringOptionMoment_V7(
                &m->nested.upgradecommitteemembership_disable_member_V7.expiry,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* upgradecommitteemembership_disable_member_V7 - at */;
            return _toStringOptionMoment_V7(
                &m->nested.upgradecommitteemembership_disable_member_V7.at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7170: /* module 28 call 2 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_add_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.upgradecommitteemembership_add_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7171: /* module 28 call 3 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_remove_member_V7 - who */;
            return _toStringIdentityId_V7(
                &m->nested.upgradecommitteemembership_remove_member_V7.who,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7172: /* module 28 call 4 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_swap_member_V7 - remove */;
            return _toStringIdentityId_V7(
                &m->nested.upgradecommitteemembership_swap_member_V7.remove,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* upgradecommitteemembership_swap_member_V7 - add */;
            return _toStringIdentityId_V7(
                &m->nested.upgradecommitteemembership_swap_member_V7.add,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7173: /* module 28 call 5 */
        switch (itemIdx) {
        case 0: /* upgradecommitteemembership_reset_members_V7 - members */;
            return _toStringVecIdentityId_V7(
                &m->nested.upgradecommitteemembership_reset_members_V7.members,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7174: /* module 28 call 6 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7424: /* module 29 call 0 */
        switch (itemIdx) {
        case 0: /* asset_register_ticker_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_register_ticker_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7425: /* module 29 call 1 */
        switch (itemIdx) {
        case 0: /* asset_accept_ticker_transfer_V7 - auth_id */;
            return _toStringu64(
                &m->nested.asset_accept_ticker_transfer_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7426: /* module 29 call 2 */
        switch (itemIdx) {
        case 0: /* asset_accept_primary_issuance_agent_transfer_V7 - auth_id */;
            return _toStringu64(
                &m->nested.asset_accept_primary_issuance_agent_transfer_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7427: /* module 29 call 3 */
        switch (itemIdx) {
        case 0: /* asset_accept_asset_ownership_transfer_V7 - auth_id */;
            return _toStringu64(
                &m->nested.asset_accept_asset_ownership_transfer_V7.auth_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7428: /* module 29 call 4 */
        switch (itemIdx) {
        case 0: /* asset_create_asset_V7 - name */;
            return _toStringAssetName_V7(
                &m->nested.asset_create_asset_V7.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_create_asset_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_create_asset_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_create_asset_V7 - total_supply */;
            return _toStringBalanceNoSymbol(
                &m->nested.asset_create_asset_V7.total_supply,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* asset_create_asset_V7 - divisible */;
            return _toStringbool(
                &m->nested.asset_create_asset_V7.divisible,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* asset_create_asset_V7 - asset_type */;
            return _toStringAssetType_V7(
                &m->nested.asset_create_asset_V7.asset_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* asset_create_asset_V7 - identifiers */;
            return _toStringVecAssetIdentifier_V7(
                &m->nested.asset_create_asset_V7.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* asset_create_asset_V7 - funding_round */;
            return _toStringOptionFundingRoundName_V7(
                &m->nested.asset_create_asset_V7.funding_round,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7429: /* module 29 call 5 */
        switch (itemIdx) {
        case 0: /* asset_freeze_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_freeze_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7430: /* module 29 call 6 */
        switch (itemIdx) {
        case 0: /* asset_unfreeze_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_unfreeze_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7431: /* module 29 call 7 */
        switch (itemIdx) {
        case 0: /* asset_rename_asset_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_rename_asset_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_rename_asset_V7 - name */;
            return _toStringAssetName_V7(
                &m->nested.asset_rename_asset_V7.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7432: /* module 29 call 8 */
        switch (itemIdx) {
        case 0: /* asset_issue_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_issue_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_issue_V7 - value */;
            return _toStringBalanceNoSymbol(
                &m->nested.asset_issue_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7433: /* module 29 call 9 */
        switch (itemIdx) {
        case 0: /* asset_redeem_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_redeem_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_redeem_V7 - value */;
            return _toStringBalanceNoSymbol(
                &m->nested.asset_redeem_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7434: /* module 29 call 10 */
        switch (itemIdx) {
        case 0: /* asset_make_divisible_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_make_divisible_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7435: /* module 29 call 11 */
        switch (itemIdx) {
        case 0: /* asset_add_documents_V7 - docs */;
            return _toStringVecDocument_V7(
                &m->nested.asset_add_documents_V7.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_add_documents_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_add_documents_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7436: /* module 29 call 12 */
        switch (itemIdx) {
        case 0: /* asset_remove_documents_V7 - ids */;
            return _toStringVecDocumentId_V7(
                &m->nested.asset_remove_documents_V7.ids,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_documents_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_remove_documents_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7437: /* module 29 call 13 */
        switch (itemIdx) {
        case 0: /* asset_set_funding_round_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_set_funding_round_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_set_funding_round_V7 - name */;
            return _toStringFundingRoundName_V7(
                &m->nested.asset_set_funding_round_V7.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7438: /* module 29 call 14 */
        switch (itemIdx) {
        case 0: /* asset_update_identifiers_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_update_identifiers_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_update_identifiers_V7 - identifiers */;
            return _toStringVecAssetIdentifier_V7(
                &m->nested.asset_update_identifiers_V7.identifiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7439: /* module 29 call 15 */
        switch (itemIdx) {
        case 0: /* asset_add_extension_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_add_extension_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_add_extension_V7 - extension_details */;
            return _toStringSmartExtension_V7(
                &m->nested.asset_add_extension_V7.extension_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7440: /* module 29 call 16 */
        switch (itemIdx) {
        case 0: /* asset_remove_smart_extension_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_remove_smart_extension_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_remove_smart_extension_V7 - extension_id */;
            return _toStringAccountId_V7(
                &m->nested.asset_remove_smart_extension_V7.extension_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7441: /* module 29 call 17 */
        switch (itemIdx) {
        case 0: /* asset_archive_extension_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_archive_extension_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_archive_extension_V7 - extension_id */;
            return _toStringAccountId_V7(
                &m->nested.asset_archive_extension_V7.extension_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7442: /* module 29 call 18 */
        switch (itemIdx) {
        case 0: /* asset_unarchive_extension_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_unarchive_extension_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_unarchive_extension_V7 - extension_id */;
            return _toStringAccountId_V7(
                &m->nested.asset_unarchive_extension_V7.extension_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7443: /* module 29 call 19 */
        switch (itemIdx) {
        case 0: /* asset_remove_primary_issuance_agent_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_remove_primary_issuance_agent_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7444: /* module 29 call 20 */
        switch (itemIdx) {
        case 0: /* asset_claim_classic_ticker_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.asset_claim_classic_ticker_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_claim_classic_ticker_V7 - ethereum_signature */;
            return _toStringEcdsaSignature_V7(
                &m->nested.asset_claim_classic_ticker_V7.ethereum_signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7445: /* module 29 call 21 */
        switch (itemIdx) {
        case 0: /* asset_reserve_classic_ticker_V7 - classic_ticker_import */;
            return _toStringClassicTickerImport_V7(
                &m->nested.asset_reserve_classic_ticker_V7.classic_ticker_import,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_reserve_classic_ticker_V7 - contract_did */;
            return _toStringIdentityId_V7(
                &m->nested.asset_reserve_classic_ticker_V7.contract_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_reserve_classic_ticker_V7 - config */;
            return _toStringTickerRegistrationConfig_V7(
                &m->nested.asset_reserve_classic_ticker_V7.config,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7446: /* module 29 call 22 */
        switch (itemIdx) {
        case 0: /* asset_controller_transfer_V7 - ticker */;
            return _toStringTicker_V7(
                &m->basic.asset_controller_transfer_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* asset_controller_transfer_V7 - value */;
            return _toStringBalanceNoSymbol(
                &m->basic.asset_controller_transfer_V7.value,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* asset_controller_transfer_V7 - from_portfolio */;
            return _toStringPortfolioId_V7(
                &m->basic.asset_controller_transfer_V7.from_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7936: /* module 31 call 0 */
        switch (itemIdx) {
        case 0: /* bridge_change_controller_V7 - controller */;
            return _toStringAccountId_V7(
                &m->nested.bridge_change_controller_V7.controller,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7937: /* module 31 call 1 */
        switch (itemIdx) {
        case 0: /* bridge_change_admin_V7 - admin */;
            return _toStringAccountId_V7(
                &m->nested.bridge_change_admin_V7.admin,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7938: /* module 31 call 2 */
        switch (itemIdx) {
        case 0: /* bridge_change_timelock_V7 - timelock */;
            return _toStringBlockNumber(
                &m->nested.bridge_change_timelock_V7.timelock,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7939: /* module 31 call 3 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7940: /* module 31 call 4 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 7941: /* module 31 call 5 */
        switch (itemIdx) {
        case 0: /* bridge_change_bridge_limit_V7 - amount */;
            return _toStringBalance(
                &m->nested.bridge_change_bridge_limit_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* bridge_change_bridge_limit_V7 - duration */;
            return _toStringBlockNumber(
                &m->nested.bridge_change_bridge_limit_V7.duration,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7942: /* module 31 call 6 */
        switch (itemIdx) {
        case 0: /* bridge_change_bridge_exempted_V7 - exempted */;
            return _toStringVecTupleIdentityIdbool_V7(
                &m->nested.bridge_change_bridge_exempted_V7.exempted,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7943: /* module 31 call 7 */
        switch (itemIdx) {
        case 0: /* bridge_force_handle_bridge_tx_V7 - bridge_tx */;
            return _toStringBridgeTx_V7(
                &m->nested.bridge_force_handle_bridge_tx_V7.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7944: /* module 31 call 8 */
        switch (itemIdx) {
        case 0: /* bridge_batch_propose_bridge_tx_V7 - bridge_txs */;
            return _toStringVecBridgeTx_V7(
                &m->nested.bridge_batch_propose_bridge_tx_V7.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7945: /* module 31 call 9 */
        switch (itemIdx) {
        case 0: /* bridge_propose_bridge_tx_V7 - bridge_tx */;
            return _toStringBridgeTx_V7(
                &m->nested.bridge_propose_bridge_tx_V7.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7946: /* module 31 call 10 */
        switch (itemIdx) {
        case 0: /* bridge_handle_bridge_tx_V7 - bridge_tx */;
            return _toStringBridgeTx_V7(
                &m->nested.bridge_handle_bridge_tx_V7.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7947: /* module 31 call 11 */
        switch (itemIdx) {
        case 0: /* bridge_freeze_txs_V7 - bridge_txs */;
            return _toStringVecBridgeTx_V7(
                &m->nested.bridge_freeze_txs_V7.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7948: /* module 31 call 12 */
        switch (itemIdx) {
        case 0: /* bridge_unfreeze_txs_V7 - bridge_txs */;
            return _toStringVecBridgeTx_V7(
                &m->nested.bridge_unfreeze_txs_V7.bridge_txs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 7949: /* module 31 call 13 */
        switch (itemIdx) {
        case 0: /* bridge_handle_scheduled_bridge_tx_V7 - bridge_tx */;
            return _toStringBridgeTx_V7(
                &m->nested.bridge_handle_scheduled_bridge_tx_V7.bridge_tx,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8192: /* module 32 call 0 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_compliance_requirement_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_add_compliance_requirement_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_compliance_requirement_V7 - sender_conditions */;
            return _toStringVecCondition_V7(
                &m->nested.compliancemanager_add_compliance_requirement_V7.sender_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* compliancemanager_add_compliance_requirement_V7 - receiver_conditions */;
            return _toStringVecCondition_V7(
                &m->nested.compliancemanager_add_compliance_requirement_V7.receiver_conditions,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8193: /* module 32 call 1 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_compliance_requirement_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_remove_compliance_requirement_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_compliance_requirement_V7 - id */;
            return _toStringu32(
                &m->nested.compliancemanager_remove_compliance_requirement_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8194: /* module 32 call 2 */
        switch (itemIdx) {
        case 0: /* compliancemanager_replace_asset_compliance_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_replace_asset_compliance_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_replace_asset_compliance_V7 - asset_compliance */;
            return _toStringVecComplianceRequirement_V7(
                &m->nested.compliancemanager_replace_asset_compliance_V7.asset_compliance,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8195: /* module 32 call 3 */
        switch (itemIdx) {
        case 0: /* compliancemanager_reset_asset_compliance_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_reset_asset_compliance_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8196: /* module 32 call 4 */
        switch (itemIdx) {
        case 0: /* compliancemanager_pause_asset_compliance_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_pause_asset_compliance_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8197: /* module 32 call 5 */
        switch (itemIdx) {
        case 0: /* compliancemanager_resume_asset_compliance_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_resume_asset_compliance_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8198: /* module 32 call 6 */
        switch (itemIdx) {
        case 0: /* compliancemanager_add_default_trusted_claim_issuer_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_add_default_trusted_claim_issuer_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_add_default_trusted_claim_issuer_V7 - issuer */;
            return _toStringTrustedIssuer_V7(
                &m->nested.compliancemanager_add_default_trusted_claim_issuer_V7.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8199: /* module 32 call 7 */
        switch (itemIdx) {
        case 0: /* compliancemanager_remove_default_trusted_claim_issuer_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_remove_default_trusted_claim_issuer_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_remove_default_trusted_claim_issuer_V7 - issuer */;
            return _toStringIdentityId_V7(
                &m->nested.compliancemanager_remove_default_trusted_claim_issuer_V7.issuer,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 8200: /* module 32 call 8 */
        switch (itemIdx) {
        case 0: /* compliancemanager_change_compliance_requirement_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.compliancemanager_change_compliance_requirement_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* compliancemanager_change_compliance_requirement_V7 - new_req */;
            return _toStringComplianceRequirement_V7(
                &m->nested.compliancemanager_change_compliance_requirement_V7.new_req,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9216: /* module 36 call 0 */
        switch (itemIdx) {
        case 0: /* settlement_create_venue_V7 - details */;
            return _toStringVenueDetails_V7(
                &m->nested.settlement_create_venue_V7.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_create_venue_V7 - signers */;
            return _toStringVecAccountId_V7(
                &m->nested.settlement_create_venue_V7.signers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_create_venue_V7 - venue_type */;
            return _toStringVenueType_V7(
                &m->nested.settlement_create_venue_V7.venue_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9217: /* module 36 call 1 */
        switch (itemIdx) {
        case 0: /* settlement_update_venue_V7 - venue_id */;
            return _toStringu64(
                &m->nested.settlement_update_venue_V7.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_update_venue_V7 - details */;
            return _toStringOptionVenueDetails_V7(
                &m->nested.settlement_update_venue_V7.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_update_venue_V7 - typ */;
            return _toStringOptionVenueType_V7(
                &m->nested.settlement_update_venue_V7.typ,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9218: /* module 36 call 2 */
        switch (itemIdx) {
        case 0: /* settlement_add_instruction_V7 - venue_id */;
            return _toStringu64(
                &m->nested.settlement_add_instruction_V7.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_instruction_V7 - settlement_type */;
            return _toStringSettlementType_V7(
                &m->nested.settlement_add_instruction_V7.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_instruction_V7 - trade_date */;
            return _toStringOptionMoment_V7(
                &m->nested.settlement_add_instruction_V7.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_instruction_V7 - value_date */;
            return _toStringOptionMoment_V7(
                &m->nested.settlement_add_instruction_V7.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_instruction_V7 - legs */;
            return _toStringVecLeg_V7(
                &m->nested.settlement_add_instruction_V7.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9219: /* module 36 call 3 */
        switch (itemIdx) {
        case 0: /* settlement_add_and_affirm_instruction_V7 - venue_id */;
            return _toStringu64(
                &m->nested.settlement_add_and_affirm_instruction_V7.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_add_and_affirm_instruction_V7 - settlement_type */;
            return _toStringSettlementType_V7(
                &m->nested.settlement_add_and_affirm_instruction_V7.settlement_type,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_add_and_affirm_instruction_V7 - trade_date */;
            return _toStringOptionMoment_V7(
                &m->nested.settlement_add_and_affirm_instruction_V7.trade_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_add_and_affirm_instruction_V7 - value_date */;
            return _toStringOptionMoment_V7(
                &m->nested.settlement_add_and_affirm_instruction_V7.value_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* settlement_add_and_affirm_instruction_V7 - legs */;
            return _toStringVecLeg_V7(
                &m->nested.settlement_add_and_affirm_instruction_V7.legs,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* settlement_add_and_affirm_instruction_V7 - portfolios */;
            return _toStringVecPortfolioId_V7(
                &m->nested.settlement_add_and_affirm_instruction_V7.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9220: /* module 36 call 4 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_instruction_V7 - instruction_id */;
            return _toStringu64(
                &m->nested.settlement_affirm_instruction_V7.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_instruction_V7 - portfolios */;
            return _toStringVecPortfolioId_V7(
                &m->nested.settlement_affirm_instruction_V7.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_instruction_V7 - max_legs_count */;
            return _toStringu32(
                &m->nested.settlement_affirm_instruction_V7.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9221: /* module 36 call 5 */
        switch (itemIdx) {
        case 0: /* settlement_withdraw_affirmation_V7 - instruction_id */;
            return _toStringu64(
                &m->nested.settlement_withdraw_affirmation_V7.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_withdraw_affirmation_V7 - portfolios */;
            return _toStringVecPortfolioId_V7(
                &m->nested.settlement_withdraw_affirmation_V7.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_withdraw_affirmation_V7 - max_legs_count */;
            return _toStringu32(
                &m->nested.settlement_withdraw_affirmation_V7.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9222: /* module 36 call 6 */
        switch (itemIdx) {
        case 0: /* settlement_reject_instruction_V7 - instruction_id */;
            return _toStringu64(
                &m->nested.settlement_reject_instruction_V7.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_reject_instruction_V7 - portfolios */;
            return _toStringVecPortfolioId_V7(
                &m->nested.settlement_reject_instruction_V7.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_reject_instruction_V7 - max_legs_count */;
            return _toStringu32(
                &m->nested.settlement_reject_instruction_V7.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9223: /* module 36 call 7 */
        switch (itemIdx) {
        case 0: /* settlement_affirm_with_receipts_V7 - instruction_id */;
            return _toStringu64(
                &m->nested.settlement_affirm_with_receipts_V7.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_affirm_with_receipts_V7 - receipt_details */;
            return _toStringVecReceiptDetails_V7(
                &m->nested.settlement_affirm_with_receipts_V7.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* settlement_affirm_with_receipts_V7 - portfolios */;
            return _toStringVecPortfolioId_V7(
                &m->nested.settlement_affirm_with_receipts_V7.portfolios,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* settlement_affirm_with_receipts_V7 - max_legs_count */;
            return _toStringu32(
                &m->nested.settlement_affirm_with_receipts_V7.max_legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9224: /* module 36 call 8 */
        switch (itemIdx) {
        case 0: /* settlement_claim_receipt_V7 - instruction_id */;
            return _toStringu64(
                &m->nested.settlement_claim_receipt_V7.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_claim_receipt_V7 - receipt_details */;
            return _toStringReceiptDetails_V7(
                &m->nested.settlement_claim_receipt_V7.receipt_details,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9225: /* module 36 call 9 */
        switch (itemIdx) {
        case 0: /* settlement_unclaim_receipt_V7 - instruction_id */;
            return _toStringu64(
                &m->nested.settlement_unclaim_receipt_V7.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_unclaim_receipt_V7 - leg_id */;
            return _toStringu64(
                &m->nested.settlement_unclaim_receipt_V7.leg_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9226: /* module 36 call 10 */
        switch (itemIdx) {
        case 0: /* settlement_set_venue_filtering_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.settlement_set_venue_filtering_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_set_venue_filtering_V7 - enabled */;
            return _toStringbool(
                &m->nested.settlement_set_venue_filtering_V7.enabled,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9227: /* module 36 call 11 */
        switch (itemIdx) {
        case 0: /* settlement_allow_venues_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.settlement_allow_venues_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_allow_venues_V7 - venues */;
            return _toStringVecu64(
                &m->nested.settlement_allow_venues_V7.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9228: /* module 36 call 12 */
        switch (itemIdx) {
        case 0: /* settlement_disallow_venues_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.settlement_disallow_venues_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_disallow_venues_V7 - venues */;
            return _toStringVecu64(
                &m->nested.settlement_disallow_venues_V7.venues,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9229: /* module 36 call 13 */
        switch (itemIdx) {
        case 0: /* settlement_change_receipt_validity_V7 - receipt_uid */;
            return _toStringu64(
                &m->basic.settlement_change_receipt_validity_V7.receipt_uid,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_change_receipt_validity_V7 - validity */;
            return _toStringbool(
                &m->basic.settlement_change_receipt_validity_V7.validity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9230: /* module 36 call 14 */
        switch (itemIdx) {
        case 0: /* settlement_execute_scheduled_instruction_V7 - instruction_id */;
            return _toStringu64(
                &m->nested.settlement_execute_scheduled_instruction_V7.instruction_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* settlement_execute_scheduled_instruction_V7 - legs_count */;
            return _toStringu32(
                &m->nested.settlement_execute_scheduled_instruction_V7.legs_count,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9472: /* module 37 call 0 */
        switch (itemIdx) {
        case 0: /* sto_create_fundraiser_V7 - offering_portfolio */;
            return _toStringPortfolioId_V7(
                &m->basic.sto_create_fundraiser_V7.offering_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_create_fundraiser_V7 - offering_asset */;
            return _toStringTicker_V7(
                &m->basic.sto_create_fundraiser_V7.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_create_fundraiser_V7 - raising_portfolio */;
            return _toStringPortfolioId_V7(
                &m->basic.sto_create_fundraiser_V7.raising_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_create_fundraiser_V7 - raising_asset */;
            return _toStringTicker_V7(
                &m->basic.sto_create_fundraiser_V7.raising_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_create_fundraiser_V7 - tiers */;
            return _toStringVecPriceTier_V7(
                &m->basic.sto_create_fundraiser_V7.tiers,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_create_fundraiser_V7 - venue_id */;
            return _toStringu64(
                &m->basic.sto_create_fundraiser_V7.venue_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_create_fundraiser_V7 - start */;
            return _toStringOptionMoment_V7(
                &m->basic.sto_create_fundraiser_V7.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* sto_create_fundraiser_V7 - end */;
            return _toStringOptionMoment_V7(
                &m->basic.sto_create_fundraiser_V7.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 8: /* sto_create_fundraiser_V7 - minimum_investment */;
            return _toStringBalanceNoSymbol(
                &m->basic.sto_create_fundraiser_V7.minimum_investment,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 9: /* sto_create_fundraiser_V7 - fundraiser_name */;
            return _toStringFundraiserName_V7(
                &m->basic.sto_create_fundraiser_V7.fundraiser_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9473: /* module 37 call 1 */
        switch (itemIdx) {
        case 0: /* sto_invest_V7 - investment_portfolio */;
            return _toStringPortfolioId_V7(
                &m->basic.sto_invest_V7.investment_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_invest_V7 - funding_portfolio */;
            return _toStringPortfolioId_V7(
                &m->basic.sto_invest_V7.funding_portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_invest_V7 - offering_asset */;
            return _toStringTicker_V7(
                &m->basic.sto_invest_V7.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_invest_V7 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_invest_V7.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* sto_invest_V7 - purchase_amount */;
            return _toStringBalanceNoSymbol(
                &m->basic.sto_invest_V7.purchase_amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* sto_invest_V7 - max_price */;
            return _toStringOptionBalance(
                &m->basic.sto_invest_V7.max_price,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* sto_invest_V7 - receipt */;
            return _toStringOptionReceiptDetails_V7(
                &m->basic.sto_invest_V7.receipt,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9474: /* module 37 call 2 */
        switch (itemIdx) {
        case 0: /* sto_freeze_fundraiser_V7 - offering_asset */;
            return _toStringTicker_V7(
                &m->basic.sto_freeze_fundraiser_V7.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_freeze_fundraiser_V7 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_freeze_fundraiser_V7.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9475: /* module 37 call 3 */
        switch (itemIdx) {
        case 0: /* sto_unfreeze_fundraiser_V7 - offering_asset */;
            return _toStringTicker_V7(
                &m->basic.sto_unfreeze_fundraiser_V7.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_unfreeze_fundraiser_V7 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_unfreeze_fundraiser_V7.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9476: /* module 37 call 4 */
        switch (itemIdx) {
        case 0: /* sto_modify_fundraiser_window_V7 - offering_asset */;
            return _toStringTicker_V7(
                &m->basic.sto_modify_fundraiser_window_V7.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_modify_fundraiser_window_V7 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_modify_fundraiser_window_V7.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* sto_modify_fundraiser_window_V7 - start */;
            return _toStringMoment_V7(
                &m->basic.sto_modify_fundraiser_window_V7.start,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* sto_modify_fundraiser_window_V7 - end */;
            return _toStringOptionMoment_V7(
                &m->basic.sto_modify_fundraiser_window_V7.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9477: /* module 37 call 5 */
        switch (itemIdx) {
        case 0: /* sto_stop_V7 - offering_asset */;
            return _toStringTicker_V7(
                &m->basic.sto_stop_V7.offering_asset,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* sto_stop_V7 - fundraiser_id */;
            return _toStringu64(
                &m->basic.sto_stop_V7.fundraiser_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9984: /* module 39 call 0 */
        switch (itemIdx) {
        case 0: /* statistics_add_transfer_manager_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.statistics_add_transfer_manager_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_add_transfer_manager_V7 - new_transfer_manager */;
            return _toStringTransferManager_V7(
                &m->nested.statistics_add_transfer_manager_V7.new_transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9985: /* module 39 call 1 */
        switch (itemIdx) {
        case 0: /* statistics_remove_transfer_manager_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.statistics_remove_transfer_manager_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_remove_transfer_manager_V7 - transfer_manager */;
            return _toStringTransferManager_V7(
                &m->nested.statistics_remove_transfer_manager_V7.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9986: /* module 39 call 2 */
        switch (itemIdx) {
        case 0: /* statistics_add_exempted_entities_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.statistics_add_exempted_entities_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_add_exempted_entities_V7 - transfer_manager */;
            return _toStringTransferManager_V7(
                &m->nested.statistics_add_exempted_entities_V7.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* statistics_add_exempted_entities_V7 - exempted_entities */;
            return _toStringVecScopeId_V7(
                &m->nested.statistics_add_exempted_entities_V7.exempted_entities,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 9987: /* module 39 call 3 */
        switch (itemIdx) {
        case 0: /* statistics_remove_exempted_entities_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.statistics_remove_exempted_entities_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* statistics_remove_exempted_entities_V7 - transfer_manager */;
            return _toStringTransferManager_V7(
                &m->nested.statistics_remove_exempted_entities_V7.transfer_manager,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* statistics_remove_exempted_entities_V7 - entities */;
            return _toStringVecScopeId_V7(
                &m->nested.statistics_remove_exempted_entities_V7.entities,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10240: /* module 40 call 0 */
        switch (itemIdx) {
        case 0: /* protocolfee_change_coefficient_V7 - coefficient */;
            return _toStringPosRatio_V7(
                &m->nested.protocolfee_change_coefficient_V7.coefficient,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10241: /* module 40 call 1 */
        switch (itemIdx) {
        case 0: /* protocolfee_change_base_fee_V7 - op */;
            return _toStringProtocolOp_V7(
                &m->nested.protocolfee_change_base_fee_V7.op,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* protocolfee_change_base_fee_V7 - base_fee */;
            return _toStringBalanceOf(
                &m->nested.protocolfee_change_base_fee_V7.base_fee,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10499: /* module 41 call 3 */
        switch (itemIdx) {
        case 0: /* utility_relay_tx_V7 - target */;
            return _toStringAccountId_V7(
                &m->nested.utility_relay_tx_V7.target,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* utility_relay_tx_V7 - signature */;
            return _toStringOffChainSignature_V7(
                &m->nested.utility_relay_tx_V7.signature,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* utility_relay_tx_V7 - call */;
            return _toStringUniqueCall_V7(
                &m->nested.utility_relay_tx_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10752: /* module 42 call 0 */
        switch (itemIdx) {
        case 0: /* portfolio_create_portfolio_V7 - name */;
            return _toStringPortfolioName_V7(
                &m->nested.portfolio_create_portfolio_V7.name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10753: /* module 42 call 1 */
        switch (itemIdx) {
        case 0: /* portfolio_delete_portfolio_V7 - num */;
            return _toStringPortfolioNumber_V7(
                &m->nested.portfolio_delete_portfolio_V7.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10754: /* module 42 call 2 */
        switch (itemIdx) {
        case 0: /* portfolio_move_portfolio_funds_V7 - from */;
            return _toStringPortfolioId_V7(
                &m->nested.portfolio_move_portfolio_funds_V7.from,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_move_portfolio_funds_V7 - to */;
            return _toStringPortfolioId_V7(
                &m->nested.portfolio_move_portfolio_funds_V7.to,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* portfolio_move_portfolio_funds_V7 - items */;
            return _toStringVecMovePortfolioItem_V7(
                &m->nested.portfolio_move_portfolio_funds_V7.items,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 10755: /* module 42 call 3 */
        switch (itemIdx) {
        case 0: /* portfolio_rename_portfolio_V7 - num */;
            return _toStringPortfolioNumber_V7(
                &m->nested.portfolio_rename_portfolio_V7.num,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* portfolio_rename_portfolio_V7 - to_name */;
            return _toStringPortfolioName_V7(
                &m->nested.portfolio_rename_portfolio_V7.to_name,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11520: /* module 45 call 0 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_V7 - when */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_V7.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_V7 - maybe_periodic */;
            return _toStringOptionPeriod_V7(
                &m->nested.scheduler_schedule_V7.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_V7 - priority */;
            return _toStringPriority_V7(
                &m->nested.scheduler_schedule_V7.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_V7 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11521: /* module 45 call 1 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_V7 - when */;
            return _toStringBlockNumber(
                &m->nested.scheduler_cancel_V7.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_cancel_V7 - index */;
            return _toStringu32(
                &m->nested.scheduler_cancel_V7.index,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11522: /* module 45 call 2 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_V7 - id */;
            return _toStringBytes(
                &m->nested.scheduler_schedule_named_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_V7 - when */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_named_V7.when,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_V7 - maybe_periodic */;
            return _toStringOptionPeriod_V7(
                &m->nested.scheduler_schedule_named_V7.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_V7 - priority */;
            return _toStringPriority_V7(
                &m->nested.scheduler_schedule_named_V7.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_V7 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_named_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11523: /* module 45 call 3 */
        switch (itemIdx) {
        case 0: /* scheduler_cancel_named_V7 - id */;
            return _toStringBytes(
                &m->nested.scheduler_cancel_named_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11524: /* module 45 call 4 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_after_V7 - after */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_after_V7.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_after_V7 - maybe_periodic */;
            return _toStringOptionPeriod_V7(
                &m->nested.scheduler_schedule_after_V7.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_after_V7 - priority */;
            return _toStringPriority_V7(
                &m->nested.scheduler_schedule_after_V7.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_after_V7 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_after_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11525: /* module 45 call 5 */
        switch (itemIdx) {
        case 0: /* scheduler_schedule_named_after_V7 - id */;
            return _toStringBytes(
                &m->nested.scheduler_schedule_named_after_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* scheduler_schedule_named_after_V7 - after */;
            return _toStringBlockNumber(
                &m->nested.scheduler_schedule_named_after_V7.after,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* scheduler_schedule_named_after_V7 - maybe_periodic */;
            return _toStringOptionPeriod_V7(
                &m->nested.scheduler_schedule_named_after_V7.maybe_periodic,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* scheduler_schedule_named_after_V7 - priority */;
            return _toStringPriority_V7(
                &m->nested.scheduler_schedule_named_after_V7.priority,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* scheduler_schedule_named_after_V7 - call */;
            return _toStringCall(
                &m->nested.scheduler_schedule_named_after_V7.call,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11776: /* module 46 call 0 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_max_details_length_V7 - length */;
            return _toStringu32(
                &m->nested.corporateaction_set_max_details_length_V7.length,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11777: /* module 46 call 1 */
        switch (itemIdx) {
        case 0: /* corporateaction_reset_caa_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.corporateaction_reset_caa_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11778: /* module 46 call 2 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_targets_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.corporateaction_set_default_targets_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_targets_V7 - targets */;
            return _toStringTargetIdentities_V7(
                &m->nested.corporateaction_set_default_targets_V7.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11779: /* module 46 call 3 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_default_withholding_tax_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.corporateaction_set_default_withholding_tax_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_default_withholding_tax_V7 - tax */;
            return _toStringTax_V7(
                &m->nested.corporateaction_set_default_withholding_tax_V7.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11780: /* module 46 call 4 */
        switch (itemIdx) {
        case 0: /* corporateaction_set_did_withholding_tax_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.corporateaction_set_did_withholding_tax_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_set_did_withholding_tax_V7 - taxed_did */;
            return _toStringIdentityId_V7(
                &m->nested.corporateaction_set_did_withholding_tax_V7.taxed_did,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_set_did_withholding_tax_V7 - tax */;
            return _toStringOptionTax_V7(
                &m->nested.corporateaction_set_did_withholding_tax_V7.tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11781: /* module 46 call 5 */
        switch (itemIdx) {
        case 0: /* corporateaction_initiate_corporate_action_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_initiate_corporate_action_V7 - kind */;
            return _toStringCAKind_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.kind,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateaction_initiate_corporate_action_V7 - decl_date */;
            return _toStringMoment_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.decl_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateaction_initiate_corporate_action_V7 - record_date */;
            return _toStringOptionRecordDateSpec_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* corporateaction_initiate_corporate_action_V7 - details */;
            return _toStringCADetails_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.details,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* corporateaction_initiate_corporate_action_V7 - targets */;
            return _toStringOptionTargetIdentities_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.targets,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* corporateaction_initiate_corporate_action_V7 - default_withholding_tax */;
            return _toStringOptionTax_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.default_withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 7: /* corporateaction_initiate_corporate_action_V7 - withholding_tax */;
            return _toStringOptionVecTupleIdentityIdTax_V7(
                &m->nested.corporateaction_initiate_corporate_action_V7.withholding_tax,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11782: /* module 46 call 6 */
        switch (itemIdx) {
        case 0: /* corporateaction_link_ca_doc_V7 - id */;
            return _toStringCAId_V7(
                &m->nested.corporateaction_link_ca_doc_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_link_ca_doc_V7 - docs */;
            return _toStringVecDocumentId_V7(
                &m->nested.corporateaction_link_ca_doc_V7.docs,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11783: /* module 46 call 7 */
        switch (itemIdx) {
        case 0: /* corporateaction_remove_ca_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateaction_remove_ca_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 11784: /* module 46 call 8 */
        switch (itemIdx) {
        case 0: /* corporateaction_change_record_date_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateaction_change_record_date_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateaction_change_record_date_V7 - record_date */;
            return _toStringOptionRecordDateSpec_V7(
                &m->nested.corporateaction_change_record_date_V7.record_date,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12032: /* module 47 call 0 */
        switch (itemIdx) {
        case 0: /* corporateballot_attach_ballot_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateballot_attach_ballot_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_attach_ballot_V7 - range */;
            return _toStringBallotTimeRange_V7(
                &m->nested.corporateballot_attach_ballot_V7.range,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* corporateballot_attach_ballot_V7 - meta */;
            return _toStringBallotMeta_V7(
                &m->nested.corporateballot_attach_ballot_V7.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* corporateballot_attach_ballot_V7 - rcv */;
            return _toStringbool(
                &m->nested.corporateballot_attach_ballot_V7.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12033: /* module 47 call 1 */
        switch (itemIdx) {
        case 0: /* corporateballot_vote_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateballot_vote_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_vote_V7 - votes */;
            return _toStringVecBallotVote_V7(
                &m->nested.corporateballot_vote_V7.votes,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12034: /* module 47 call 2 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_end_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateballot_change_end_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_end_V7 - end */;
            return _toStringMoment_V7(
                &m->nested.corporateballot_change_end_V7.end,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12035: /* module 47 call 3 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_meta_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateballot_change_meta_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_meta_V7 - meta */;
            return _toStringBallotMeta_V7(
                &m->nested.corporateballot_change_meta_V7.meta,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12036: /* module 47 call 4 */
        switch (itemIdx) {
        case 0: /* corporateballot_change_rcv_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateballot_change_rcv_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* corporateballot_change_rcv_V7 - rcv */;
            return _toStringbool(
                &m->nested.corporateballot_change_rcv_V7.rcv,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12037: /* module 47 call 5 */
        switch (itemIdx) {
        case 0: /* corporateballot_remove_ballot_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.corporateballot_remove_ballot_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12288: /* module 48 call 0 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_distribute_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.capitaldistribution_distribute_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_distribute_V7 - portfolio */;
            return _toStringOptionPortfolioNumber_V7(
                &m->nested.capitaldistribution_distribute_V7.portfolio,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 2: /* capitaldistribution_distribute_V7 - currency */;
            return _toStringTicker_V7(
                &m->nested.capitaldistribution_distribute_V7.currency,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 3: /* capitaldistribution_distribute_V7 - per_share */;
            return _toStringBalance(
                &m->nested.capitaldistribution_distribute_V7.per_share,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 4: /* capitaldistribution_distribute_V7 - amount */;
            return _toStringBalance(
                &m->nested.capitaldistribution_distribute_V7.amount,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 5: /* capitaldistribution_distribute_V7 - payment_at */;
            return _toStringMoment_V7(
                &m->nested.capitaldistribution_distribute_V7.payment_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 6: /* capitaldistribution_distribute_V7 - expires_at */;
            return _toStringOptionMoment_V7(
                &m->nested.capitaldistribution_distribute_V7.expires_at,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12289: /* module 48 call 1 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_claim_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.capitaldistribution_claim_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12290: /* module 48 call 2 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_push_benefit_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.capitaldistribution_push_benefit_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* capitaldistribution_push_benefit_V7 - holder */;
            return _toStringIdentityId_V7(
                &m->nested.capitaldistribution_push_benefit_V7.holder,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12291: /* module 48 call 3 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_reclaim_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.capitaldistribution_reclaim_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12292: /* module 48 call 4 */
        switch (itemIdx) {
        case 0: /* capitaldistribution_remove_distribution_V7 - ca_id */;
            return _toStringCAId_V7(
                &m->nested.capitaldistribution_remove_distribution_V7.ca_id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12544: /* module 49 call 0 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_checkpoint_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.checkpoint_create_checkpoint_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12545: /* module 49 call 1 */
        switch (itemIdx) {
        case 0: /* checkpoint_set_schedules_max_complexity_V7 - max_complexity */;
            return _toStringu64(
                &m->nested.checkpoint_set_schedules_max_complexity_V7.max_complexity,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12546: /* module 49 call 2 */
        switch (itemIdx) {
        case 0: /* checkpoint_create_schedule_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.checkpoint_create_schedule_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_create_schedule_V7 - schedule */;
            return _toStringScheduleSpec_V7(
                &m->nested.checkpoint_create_schedule_V7.schedule,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12547: /* module 49 call 3 */
        switch (itemIdx) {
        case 0: /* checkpoint_remove_schedule_V7 - ticker */;
            return _toStringTicker_V7(
                &m->nested.checkpoint_remove_schedule_V7.ticker,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* checkpoint_remove_schedule_V7 - id */;
            return _toStringScheduleId_V7(
                &m->nested.checkpoint_remove_schedule_V7.id,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12800: /* module 50 call 0 */
        switch (itemIdx) {
        case 0: /* testutils_register_did_V7 - uid */;
            return _toStringInvestorUid_V7(
                &m->basic.testutils_register_did_V7.uid,
                outValue, outValueLen,
                pageIdx, pageCount);
        case 1: /* testutils_register_did_V7 - secondary_keys */;
            return _toStringVecSecondaryKey_V7(
                &m->basic.testutils_register_did_V7.secondary_keys,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12801: /* module 50 call 1 */
        switch (itemIdx) {
        case 0: /* testutils_mock_cdd_register_did_V7 - target_account */;
            return _toStringAccountId_V7(
                &m->basic.testutils_mock_cdd_register_did_V7.target_account,
                outValue, outValueLen,
                pageIdx, pageCount);
        default:
            return parser_no_data;
        }
    case 12802: /* module 50 call 2 */
        switch (itemIdx) {
        default:
            return parser_no_data;
        }
    case 12803: /* module 50 call 3 */
        switch (itemIdx) {
        case 0: /* testutils_get_cdd_of_V7 - of */;
            return _toStringAccountId_V7(
                &m->basic.testutils_get_cdd_of_V7.of,
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

bool _getMethod_ItemIsExpert_V7(uint8_t moduleIdx, uint8_t callIdx, uint8_t itemIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 2051: // Staking:Withdraw Unbonded
        switch (itemIdx) {
        case 0: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2068: // Staking:Force unstake
        switch (itemIdx) {
        case 1: // Num slashing spans
            return true;
        default:
            return false;
        }
    case 2074: // Staking:Reap stash
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

bool _getMethod_IsNestingSupported_V7(uint8_t moduleIdx, uint8_t callIdx)
{
    uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

    switch (callPrivIdx) {
    case 1560: // Identity:Add investor uniqueness claim v2
    case 5121: // Contracts:Set put code flag
    case 7446: // Asset:Controller transfer
    case 9229: // Settlement:Change receipt validity
    case 9472: // Sto:Create fundraiser
    case 9473: // Sto:Invest
    case 9474: // Sto:Freeze fundraiser
    case 9475: // Sto:Unfreeze fundraiser
    case 9476: // Sto:Modify fundraiser window
    case 9477: // Sto:Stop
    case 12800: // TestUtils:Register did
    case 12801: // TestUtils:Mock cdd register did
    case 12802: // TestUtils:Get my did
    case 12803: // TestUtils:Get cdd of
        return false;
    default:
        return true;
    }
}
