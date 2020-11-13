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
#include "substrate_dispatch.h"

#include "zxmacros.h"
#include <stdint.h>

__Z_INLINE parser_error_t
_readMethod_system_fill_block(parser_context_t *c, pd_system_fill_block_t *m) {
  CHECK_ERROR(_readPerbill(c, &m->_ratio))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_remark(parser_context_t *c,
                                                    pd_system_remark_t *m) {
  CHECK_ERROR(_readBytes(c, &m->_remark))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_heap_pages(
    parser_context_t *c, pd_system_set_heap_pages_t *m) {
  CHECK_ERROR(_readu64(c, &m->pages))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code(parser_context_t *c,
                                                      pd_system_set_code_t *m) {
  CHECK_ERROR(_readBytes(c, &m->code))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_code_without_checks(
    parser_context_t *c, pd_system_set_code_without_checks_t *m) {
  CHECK_ERROR(_readBytes(c, &m->code))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_changes_trie_config(
    parser_context_t *c, pd_system_set_changes_trie_config_t *m) {
  CHECK_ERROR(_readOptionChangesTrieConfiguration(c, &m->changes_trie_config))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_set_storage(
    parser_context_t *c, pd_system_set_storage_t *m) {
  CHECK_ERROR(_readVecKeyValue(c, &m->items))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_storage(
    parser_context_t *c, pd_system_kill_storage_t *m) {
  CHECK_ERROR(_readVecKey(c, &m->keys))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_kill_prefix(
    parser_context_t *c, pd_system_kill_prefix_t *m) {
  CHECK_ERROR(_readKey(c, &m->prefix))
  CHECK_ERROR(_readu32(c, &m->_subkeys))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_system_suicide(parser_context_t *c,
                                                     pd_system_suicide_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation(
    parser_context_t *c, pd_babe_report_equivocation_t *m) {
  CHECK_ERROR(_readEquivocationProof(c, &m->equivocation_proof))
  CHECK_ERROR(_readKeyOwnerProof(c, &m->key_owner_proof))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_babe_report_equivocation_unsigned(
    parser_context_t *c, pd_babe_report_equivocation_unsigned_t *m) {
  CHECK_ERROR(_readEquivocationProof(c, &m->equivocation_proof))
  CHECK_ERROR(_readKeyOwnerProof(c, &m->key_owner_proof))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_timestamp_set(parser_context_t *c,
                                                    pd_timestamp_set_t *m) {
  CHECK_ERROR(_readCompactMoment(c, &m->now))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_claim(parser_context_t *c,
                                                    pd_indices_claim_t *m) {
  CHECK_ERROR(_readAccountIndex(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_indices_transfer(parser_context_t *c, pd_indices_transfer_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->new_))
  CHECK_ERROR(_readAccountIndex(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_free(parser_context_t *c,
                                                   pd_indices_free_t *m) {
  CHECK_ERROR(_readAccountIndex(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_force_transfer(
    parser_context_t *c, pd_indices_force_transfer_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->new_))
  CHECK_ERROR(_readAccountIndex(c, &m->index))
  CHECK_ERROR(_readbool(c, &m->freeze))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_indices_freeze(parser_context_t *c,
                                                     pd_indices_freeze_t *m) {
  CHECK_ERROR(_readAccountIndex(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_balances_transfer(parser_context_t *c, pd_balances_transfer_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->dest))
  CHECK_ERROR(_readCompactBalance(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_transfer_with_memo(
    parser_context_t *c, pd_balances_transfer_with_memo_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->dest))
  CHECK_ERROR(_readCompactBalance(c, &m->value))
  CHECK_ERROR(_readOptionMemo(c, &m->memo))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_balances_deposit_block_reward_reserve_balance(
    parser_context_t *c,
    pd_balances_deposit_block_reward_reserve_balance_t *m) {
  CHECK_ERROR(_readCompactBalance(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_set_balance(
    parser_context_t *c, pd_balances_set_balance_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->who))
  CHECK_ERROR(_readCompactBalance(c, &m->new_free))
  CHECK_ERROR(_readCompactBalance(c, &m->new_reserved))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_force_transfer(
    parser_context_t *c, pd_balances_force_transfer_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->source))
  CHECK_ERROR(_readLookupSource(c, &m->dest))
  CHECK_ERROR(_readCompactBalance(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_balances_burn_account_balance(
    parser_context_t *c, pd_balances_burn_account_balance_t *m) {
  CHECK_ERROR(_readBalance(c, &m->amount))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_authorship_set_uncles(
    parser_context_t *c, pd_authorship_set_uncles_t *m) {
  CHECK_ERROR(_readVecHeader(c, &m->new_uncles))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond(parser_context_t *c,
                                                   pd_staking_bond_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->controller))
  CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
  CHECK_ERROR(_readRewardDestination(c, &m->payee))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_bond_extra(
    parser_context_t *c, pd_staking_bond_extra_t *m) {
  CHECK_ERROR(_readCompactBalanceOf(c, &m->max_additional))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_unbond(parser_context_t *c,
                                                     pd_staking_unbond_t *m) {
  CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_withdraw_unbonded(
    parser_context_t *c, pd_staking_withdraw_unbonded_t *m) {
  CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_staking_validate(parser_context_t *c, pd_staking_validate_t *m) {
  CHECK_ERROR(_readValidatorPrefs(c, &m->prefs))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_staking_nominate(parser_context_t *c, pd_staking_nominate_t *m) {
  CHECK_ERROR(_readVecLookupSource(c, &m->targets))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_chill(parser_context_t *c,
                                                    pd_staking_chill_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_staking_set_payee(parser_context_t *c, pd_staking_set_payee_t *m) {
  CHECK_ERROR(_readRewardDestination(c, &m->payee))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_controller(
    parser_context_t *c, pd_staking_set_controller_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->controller))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_validator_count(
    parser_context_t *c, pd_staking_set_validator_count_t *m) {
  CHECK_ERROR(_readCompactu32(c, &m->new_))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_increase_validator_count(
    parser_context_t *c, pd_staking_increase_validator_count_t *m) {
  CHECK_ERROR(_readCompactu32(c, &m->additional))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_scale_validator_count(
    parser_context_t *c, pd_staking_scale_validator_count_t *m) {
  CHECK_ERROR(_readPercent(c, &m->factor))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_add_permissioned_validator(
    parser_context_t *c, pd_staking_add_permissioned_validator_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->identity))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_remove_permissioned_validator(
    parser_context_t *c, pd_staking_remove_permissioned_validator_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->identity))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_validate_cdd_expiry_nominators(
    parser_context_t *c, pd_staking_validate_cdd_expiry_nominators_t *m) {
  CHECK_ERROR(_readVecAccountId(c, &m->targets))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_commission_cap(
    parser_context_t *c, pd_staking_set_commission_cap_t *m) {
  CHECK_ERROR(_readPerbill(c, &m->new_cap))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_min_bond_threshold(
    parser_context_t *c, pd_staking_set_min_bond_threshold_t *m) {
  CHECK_ERROR(_readBalanceOf(c, &m->new_value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_no_eras(
    parser_context_t *c, pd_staking_force_no_eras_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era(
    parser_context_t *c, pd_staking_force_new_era_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_invulnerables(
    parser_context_t *c, pd_staking_set_invulnerables_t *m) {
  CHECK_ERROR(_readVecAccountId(c, &m->validators))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_unstake(
    parser_context_t *c, pd_staking_force_unstake_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->stash))
  CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_force_new_era_always(
    parser_context_t *c, pd_staking_force_new_era_always_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_cancel_deferred_slash(
    parser_context_t *c, pd_staking_cancel_deferred_slash_t *m) {
  CHECK_ERROR(_readEraIndex(c, &m->era))
  CHECK_ERROR(_readVecu32(c, &m->slash_indices))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers(
    parser_context_t *c, pd_staking_payout_stakers_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->validator_stash))
  CHECK_ERROR(_readEraIndex(c, &m->era))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_rebond(parser_context_t *c,
                                                     pd_staking_rebond_t *m) {
  CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_set_history_depth(
    parser_context_t *c, pd_staking_set_history_depth_t *m) {
  CHECK_ERROR(_readCompactEraIndex(c, &m->new_history_depth))
  CHECK_ERROR(_readCompactu32(c, &m->_era_items_deleted))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_reap_stash(
    parser_context_t *c, pd_staking_reap_stash_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->stash))
  CHECK_ERROR(_readu32(c, &m->num_slashing_spans))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution(
    parser_context_t *c, pd_staking_submit_election_solution_t *m) {
  CHECK_ERROR(_readVecValidatorIndex(c, &m->winners))
  CHECK_ERROR(_readCompactAssignments(c, &m->compact))
  CHECK_ERROR(_readElectionScore(c, &m->score))
  CHECK_ERROR(_readEraIndex(c, &m->era))
  CHECK_ERROR(_readElectionSize(c, &m->size))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_submit_election_solution_unsigned(
    parser_context_t *c, pd_staking_submit_election_solution_unsigned_t *m) {
  CHECK_ERROR(_readVecValidatorIndex(c, &m->winners))
  CHECK_ERROR(_readCompactAssignments(c, &m->compact))
  CHECK_ERROR(_readElectionScore(c, &m->score))
  CHECK_ERROR(_readEraIndex(c, &m->era))
  CHECK_ERROR(_readElectionSize(c, &m->size))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_payout_stakers_by_system(
    parser_context_t *c, pd_staking_payout_stakers_by_system_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->validator_stash))
  CHECK_ERROR(_readEraIndex(c, &m->era))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_staking_change_slashing_allowed_for(
    parser_context_t *c, pd_staking_change_slashing_allowed_for_t *m) {
  CHECK_ERROR(_readSlashingSwitch(c, &m->slashing_switch))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_session_set_keys(parser_context_t *c, pd_session_set_keys_t *m) {
  CHECK_ERROR(_readKeys(c, &m->keys))
  CHECK_ERROR(_readBytes(c, &m->proof))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_session_purge_keys(
    parser_context_t *c, pd_session_purge_keys_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_finalitytracker_final_hint(
    parser_context_t *c, pd_finalitytracker_final_hint_t *m) {
  CHECK_ERROR(_readCompactBlockNumber(c, &m->hint))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation(
    parser_context_t *c, pd_grandpa_report_equivocation_t *m) {
  CHECK_ERROR(_readEquivocationProof(c, &m->equivocation_proof))
  CHECK_ERROR(_readKeyOwnerProof(c, &m->key_owner_proof))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_report_equivocation_unsigned(
    parser_context_t *c, pd_grandpa_report_equivocation_unsigned_t *m) {
  CHECK_ERROR(_readEquivocationProof(c, &m->equivocation_proof))
  CHECK_ERROR(_readKeyOwnerProof(c, &m->key_owner_proof))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_grandpa_note_stalled(
    parser_context_t *c, pd_grandpa_note_stalled_t *m) {
  CHECK_ERROR(_readBlockNumber(c, &m->delay))
  CHECK_ERROR(_readBlockNumber(c, &m->best_finalized_block_number))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_heartbeat(
    parser_context_t *c, pd_imonline_heartbeat_t *m) {
  CHECK_ERROR(_readHeartbeat(c, &m->heartbeat))
  CHECK_ERROR(_readSignature(c, &m->_signature))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_imonline_set_slashing_params(
    parser_context_t *c, pd_imonline_set_slashing_params_t *m) {
  CHECK_ERROR(_readOfflineSlashingParams(c, &m->params))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo(parser_context_t *c,
                                                pd_sudo_sudo_t *m) {
  CHECK_ERROR(_readCall(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_unchecked_weight(
    parser_context_t *c, pd_sudo_sudo_unchecked_weight_t *m) {
  CHECK_ERROR(_readCall(c, &m->call))
  CHECK_ERROR(_readWeight(c, &m->_weight))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_set_key(parser_context_t *c,
                                                   pd_sudo_set_key_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->new_))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sudo_sudo_as(parser_context_t *c,
                                                   pd_sudo_sudo_as_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->who))
  CHECK_ERROR(_readCall(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_multisig(
    parser_context_t *c, pd_multisig_create_multisig_t *m) {
  CHECK_ERROR(_readVecSignatory(c, &m->signers))
  CHECK_ERROR(_readu64(c, &m->sigs_required))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_multisig_create_or_approve_proposal_as_identity(
    parser_context_t *c,
    pd_multisig_create_or_approve_proposal_as_identity_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readProposal(c, &m->proposal))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readbool(c, &m->auto_close))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_multisig_create_or_approve_proposal_as_key(
    parser_context_t *c, pd_multisig_create_or_approve_proposal_as_key_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readProposal(c, &m->proposal))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readbool(c, &m->auto_close))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_identity(
    parser_context_t *c, pd_multisig_create_proposal_as_identity_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readProposal(c, &m->proposal))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readbool(c, &m->auto_close))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_create_proposal_as_key(
    parser_context_t *c, pd_multisig_create_proposal_as_key_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readProposal(c, &m->proposal))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readbool(c, &m->auto_close))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_identity(
    parser_context_t *c, pd_multisig_approve_as_identity_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readu64(c, &m->proposal_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_approve_as_key(
    parser_context_t *c, pd_multisig_approve_as_key_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readu64(c, &m->proposal_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_identity(
    parser_context_t *c, pd_multisig_reject_as_identity_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readu64(c, &m->proposal_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_reject_as_key(
    parser_context_t *c, pd_multisig_reject_as_key_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readu64(c, &m->proposal_id))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_multisig_accept_multisig_signer_as_identity(
    parser_context_t *c, pd_multisig_accept_multisig_signer_as_identity_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_accept_multisig_signer_as_key(
    parser_context_t *c, pd_multisig_accept_multisig_signer_as_key_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signer(
    parser_context_t *c, pd_multisig_add_multisig_signer_t *m) {
  CHECK_ERROR(_readSignatory(c, &m->signer))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_remove_multisig_signer(
    parser_context_t *c, pd_multisig_remove_multisig_signer_t *m) {
  CHECK_ERROR(_readSignatory(c, &m->signer))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_add_multisig_signers_via_creator(
    parser_context_t *c, pd_multisig_add_multisig_signers_via_creator_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readVecSignatory(c, &m->signers))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_multisig_remove_multisig_signers_via_creator(
    parser_context_t *c, pd_multisig_remove_multisig_signers_via_creator_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readVecSignatory(c, &m->signers))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_change_sigs_required(
    parser_context_t *c, pd_multisig_change_sigs_required_t *m) {
  CHECK_ERROR(_readu64(c, &m->sigs_required))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_multisig_change_all_signers_and_sigs_required(
    parser_context_t *c,
    pd_multisig_change_all_signers_and_sigs_required_t *m) {
  CHECK_ERROR(_readVecSignatory(c, &m->signers))
  CHECK_ERROR(_readu64(c, &m->sigs_required))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_signer(
    parser_context_t *c, pd_multisig_make_multisig_signer_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_multisig_make_multisig_primary(
    parser_context_t *c, pd_multisig_make_multisig_primary_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->multisig))
  CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_update_schedule(
    parser_context_t *c, pd_contracts_update_schedule_t *m) {
  CHECK_ERROR(_readSchedule(c, &m->schedule))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_put_code(
    parser_context_t *c, pd_contracts_put_code_t *m) {
  CHECK_ERROR(_readTemplateMetadata(c, &m->meta_info))
  CHECK_ERROR(_readBalanceOf(c, &m->instantiation_fee))
  CHECK_ERROR(_readBytes(c, &m->code))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_call(parser_context_t *c,
                                                     pd_contracts_call_t *m) {
  CHECK_ERROR(_readLookupSource(c, &m->dest))
  CHECK_ERROR(_readCompactBalanceOf(c, &m->value))
  CHECK_ERROR(_readCompactGas(c, &m->gas_limit))
  CHECK_ERROR(_readBytes(c, &m->data))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_instantiate(
    parser_context_t *c, pd_contracts_instantiate_t *m) {
  CHECK_ERROR(_readCompactBalanceOf(c, &m->endowment))
  CHECK_ERROR(_readCompactGas(c, &m->gas_limit))
  CHECK_ERROR(_readCodeHash(c, &m->code_hash))
  CHECK_ERROR(_readBytes(c, &m->data))
  CHECK_ERROR(_readBalanceOf(c, &m->max_fee))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_freeze_instantiation(
    parser_context_t *c, pd_contracts_freeze_instantiation_t *m) {
  CHECK_ERROR(_readCodeHash(c, &m->code_hash))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_unfreeze_instantiation(
    parser_context_t *c, pd_contracts_unfreeze_instantiation_t *m) {
  CHECK_ERROR(_readCodeHash(c, &m->code_hash))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_transfer_template_ownership(
    parser_context_t *c, pd_contracts_transfer_template_ownership_t *m) {
  CHECK_ERROR(_readCodeHash(c, &m->code_hash))
  CHECK_ERROR(_readIdentityId(c, &m->new_owner))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_change_template_fees(
    parser_context_t *c, pd_contracts_change_template_fees_t *m) {
  CHECK_ERROR(_readCodeHash(c, &m->code_hash))
  CHECK_ERROR(_readOptionBalanceOf(c, &m->new_instantiation_fee))
  CHECK_ERROR(_readOptionBalanceOf(c, &m->new_usage_fee))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_contracts_change_template_meta_url(
    parser_context_t *c, pd_contracts_change_template_meta_url_t *m) {
  CHECK_ERROR(_readCodeHash(c, &m->code_hash))
  CHECK_ERROR(_readOptionMetaUrl(c, &m->new_url))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_disbursement(
    parser_context_t *c, pd_treasury_disbursement_t *m) {
  CHECK_ERROR(_readVecBeneficiary(c, &m->beneficiaries))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_treasury_reimbursement(
    parser_context_t *c, pd_treasury_reimbursement_t *m) {
  CHECK_ERROR(_readBalanceOf(c, &m->amount))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_vote_threshold(
    parser_context_t *c, pd_polymeshcommittee_set_vote_threshold_t *m) {
  CHECK_ERROR(_readu32(c, &m->n))
  CHECK_ERROR(_readu32(c, &m->d))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_release_coordinator(
    parser_context_t *c, pd_polymeshcommittee_set_release_coordinator_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_set_expires_after(
    parser_context_t *c, pd_polymeshcommittee_set_expires_after_t *m) {
  CHECK_ERROR(_readMaybeBlock(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_close(
    parser_context_t *c, pd_polymeshcommittee_close_t *m) {
  CHECK_ERROR(_readHash(c, &m->proposal))
  CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote_or_propose(
    parser_context_t *c, pd_polymeshcommittee_vote_or_propose_t *m) {
  CHECK_ERROR(_readbool(c, &m->approve))
  CHECK_ERROR(_readProposal(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_polymeshcommittee_vote(
    parser_context_t *c, pd_polymeshcommittee_vote_t *m) {
  CHECK_ERROR(_readHash(c, &m->proposal))
  CHECK_ERROR(_readProposalIndex(c, &m->index))
  CHECK_ERROR(_readbool(c, &m->approve))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_committeemembership_set_active_members_limit(
    parser_context_t *c, pd_committeemembership_set_active_members_limit_t *m) {
  CHECK_ERROR(_readMemberCount(c, &m->limit))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_disable_member(
    parser_context_t *c, pd_committeemembership_disable_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readOptionMoment(c, &m->at))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_add_member(
    parser_context_t *c, pd_committeemembership_add_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_remove_member(
    parser_context_t *c, pd_committeemembership_remove_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_swap_member(
    parser_context_t *c, pd_committeemembership_swap_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->remove))
  CHECK_ERROR(_readIdentityId(c, &m->add))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_reset_members(
    parser_context_t *c, pd_committeemembership_reset_members_t *m) {
  CHECK_ERROR(_readVecIdentityId(c, &m->members))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_committeemembership_abdicate_membership(
    parser_context_t *c, pd_committeemembership_abdicate_membership_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_prune_historical_pips(
    parser_context_t *c, pd_pips_set_prune_historical_pips_t *m) {
  CHECK_ERROR(_readbool(c, &m->new_value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_min_proposal_deposit(
    parser_context_t *c, pd_pips_set_min_proposal_deposit_t *m) {
  CHECK_ERROR(_readBalanceOf(c, &m->deposit))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_proposal_cool_off_period(
    parser_context_t *c, pd_pips_set_proposal_cool_off_period_t *m) {
  CHECK_ERROR(_readBlockNumber(c, &m->duration))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_default_enactment_period(
    parser_context_t *c, pd_pips_set_default_enactment_period_t *m) {
  CHECK_ERROR(_readBlockNumber(c, &m->duration))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_pending_pip_expiry(
    parser_context_t *c, pd_pips_set_pending_pip_expiry_t *m) {
  CHECK_ERROR(_readMaybeBlock(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_max_pip_skip_count(
    parser_context_t *c, pd_pips_set_max_pip_skip_count_t *m) {
  CHECK_ERROR(_readSkippedCount(c, &m->new_max))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_set_active_pip_limit(
    parser_context_t *c, pd_pips_set_active_pip_limit_t *m) {
  CHECK_ERROR(_readu32(c, &m->new_max))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_propose(parser_context_t *c,
                                                   pd_pips_propose_t *m) {
  CHECK_ERROR(_readProposal(c, &m->proposal))
  CHECK_ERROR(_readBalanceOf(c, &m->deposit))
  CHECK_ERROR(_readOptionUrl(c, &m->url))
  CHECK_ERROR(_readOptionPipDescription(c, &m->description))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_amend_proposal(
    parser_context_t *c, pd_pips_amend_proposal_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  CHECK_ERROR(_readOptionUrl(c, &m->url))
  CHECK_ERROR(_readOptionPipDescription(c, &m->description))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_cancel_proposal(
    parser_context_t *c, pd_pips_cancel_proposal_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_vote(parser_context_t *c,
                                                pd_pips_vote_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  CHECK_ERROR(_readbool(c, &m->aye_or_nay))
  CHECK_ERROR(_readBalanceOf(c, &m->deposit))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_approve_committee_proposal(
    parser_context_t *c, pd_pips_approve_committee_proposal_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reject_proposal(
    parser_context_t *c, pd_pips_reject_proposal_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_prune_proposal(
    parser_context_t *c, pd_pips_prune_proposal_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_reschedule_execution(
    parser_context_t *c, pd_pips_reschedule_execution_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  CHECK_ERROR(_readOptionBlockNumber(c, &m->until))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_clear_snapshot(
    parser_context_t *c, pd_pips_clear_snapshot_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_snapshot(parser_context_t *c,
                                                    pd_pips_snapshot_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_enact_snapshot_results(
    parser_context_t *c, pd_pips_enact_snapshot_results_t *m) {
  CHECK_ERROR(_readVecTuplePipIdSnapshotResult(c, &m->results))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_execute_scheduled_pip(
    parser_context_t *c, pd_pips_execute_scheduled_pip_t *m) {
  CHECK_ERROR(_readPipId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_pips_expire_scheduled_pip(
    parser_context_t *c, pd_pips_expire_scheduled_pip_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->did))
  CHECK_ERROR(_readPipId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_vote_threshold(
    parser_context_t *c, pd_technicalcommittee_set_vote_threshold_t *m) {
  CHECK_ERROR(_readu32(c, &m->n))
  CHECK_ERROR(_readu32(c, &m->d))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_technicalcommittee_set_release_coordinator(
    parser_context_t *c, pd_technicalcommittee_set_release_coordinator_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_set_expires_after(
    parser_context_t *c, pd_technicalcommittee_set_expires_after_t *m) {
  CHECK_ERROR(_readMaybeBlock(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_close(
    parser_context_t *c, pd_technicalcommittee_close_t *m) {
  CHECK_ERROR(_readHash(c, &m->proposal))
  CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote_or_propose(
    parser_context_t *c, pd_technicalcommittee_vote_or_propose_t *m) {
  CHECK_ERROR(_readbool(c, &m->approve))
  CHECK_ERROR(_readProposal(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommittee_vote(
    parser_context_t *c, pd_technicalcommittee_vote_t *m) {
  CHECK_ERROR(_readHash(c, &m->proposal))
  CHECK_ERROR(_readProposalIndex(c, &m->index))
  CHECK_ERROR(_readbool(c, &m->approve))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_technicalcommitteemembership_set_active_members_limit(
    parser_context_t *c,
    pd_technicalcommitteemembership_set_active_members_limit_t *m) {
  CHECK_ERROR(_readMemberCount(c, &m->limit))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_technicalcommitteemembership_disable_member(
    parser_context_t *c, pd_technicalcommitteemembership_disable_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readOptionMoment(c, &m->at))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_add_member(
    parser_context_t *c, pd_technicalcommitteemembership_add_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_technicalcommitteemembership_remove_member(
    parser_context_t *c, pd_technicalcommitteemembership_remove_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_technicalcommitteemembership_swap_member(
    parser_context_t *c, pd_technicalcommitteemembership_swap_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->remove))
  CHECK_ERROR(_readIdentityId(c, &m->add))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_technicalcommitteemembership_reset_members(
    parser_context_t *c, pd_technicalcommitteemembership_reset_members_t *m) {
  CHECK_ERROR(_readVecIdentityId(c, &m->members))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_technicalcommitteemembership_abdicate_membership(
    parser_context_t *c,
    pd_technicalcommitteemembership_abdicate_membership_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_vote_threshold(
    parser_context_t *c, pd_upgradecommittee_set_vote_threshold_t *m) {
  CHECK_ERROR(_readu32(c, &m->n))
  CHECK_ERROR(_readu32(c, &m->d))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_release_coordinator(
    parser_context_t *c, pd_upgradecommittee_set_release_coordinator_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_set_expires_after(
    parser_context_t *c, pd_upgradecommittee_set_expires_after_t *m) {
  CHECK_ERROR(_readMaybeBlock(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_close(
    parser_context_t *c, pd_upgradecommittee_close_t *m) {
  CHECK_ERROR(_readHash(c, &m->proposal))
  CHECK_ERROR(_readCompactProposalIndex(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote_or_propose(
    parser_context_t *c, pd_upgradecommittee_vote_or_propose_t *m) {
  CHECK_ERROR(_readbool(c, &m->approve))
  CHECK_ERROR(_readProposal(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommittee_vote(
    parser_context_t *c, pd_upgradecommittee_vote_t *m) {
  CHECK_ERROR(_readHash(c, &m->proposal))
  CHECK_ERROR(_readProposalIndex(c, &m->index))
  CHECK_ERROR(_readbool(c, &m->approve))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_upgradecommitteemembership_set_active_members_limit(
    parser_context_t *c,
    pd_upgradecommitteemembership_set_active_members_limit_t *m) {
  CHECK_ERROR(_readMemberCount(c, &m->limit))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_disable_member(
    parser_context_t *c, pd_upgradecommitteemembership_disable_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readOptionMoment(c, &m->at))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_add_member(
    parser_context_t *c, pd_upgradecommitteemembership_add_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_remove_member(
    parser_context_t *c, pd_upgradecommitteemembership_remove_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_swap_member(
    parser_context_t *c, pd_upgradecommitteemembership_swap_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->remove))
  CHECK_ERROR(_readIdentityId(c, &m->add))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_upgradecommitteemembership_reset_members(
    parser_context_t *c, pd_upgradecommitteemembership_reset_members_t *m) {
  CHECK_ERROR(_readVecIdentityId(c, &m->members))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_upgradecommitteemembership_abdicate_membership(
    parser_context_t *c,
    pd_upgradecommitteemembership_abdicate_membership_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_register_ticker(
    parser_context_t *c, pd_asset_register_ticker_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_ticker_transfer(
    parser_context_t *c, pd_asset_accept_ticker_transfer_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_asset_accept_primary_issuance_agent_transfer(
    parser_context_t *c, pd_asset_accept_primary_issuance_agent_transfer_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_accept_asset_ownership_transfer(
    parser_context_t *c, pd_asset_accept_asset_ownership_transfer_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_create_asset(
    parser_context_t *c, pd_asset_create_asset_t *m) {
  CHECK_ERROR(_readAssetName(c, &m->name))
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readBalance(c, &m->total_supply))
  CHECK_ERROR(_readbool(c, &m->divisible))
  CHECK_ERROR(_readAssetType(c, &m->asset_type))
  CHECK_ERROR(_readVecAssetIdentifier(c, &m->identifiers))
  CHECK_ERROR(_readOptionFundingRoundName(c, &m->funding_round))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_freeze(parser_context_t *c,
                                                   pd_asset_freeze_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unfreeze(parser_context_t *c,
                                                     pd_asset_unfreeze_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_rename_asset(
    parser_context_t *c, pd_asset_rename_asset_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readAssetName(c, &m->name))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_issue(parser_context_t *c,
                                                  pd_asset_issue_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readBalance(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_redeem(parser_context_t *c,
                                                   pd_asset_redeem_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readBalance(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_make_divisible(
    parser_context_t *c, pd_asset_make_divisible_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_documents(
    parser_context_t *c, pd_asset_add_documents_t *m) {
  CHECK_ERROR(_readVecDocument(c, &m->docs))
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_documents(
    parser_context_t *c, pd_asset_remove_documents_t *m) {
  CHECK_ERROR(_readVecDocumentId(c, &m->ids))
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_set_funding_round(
    parser_context_t *c, pd_asset_set_funding_round_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readFundingRoundName(c, &m->name))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_update_identifiers(
    parser_context_t *c, pd_asset_update_identifiers_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readVecAssetIdentifier(c, &m->identifiers))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_add_extension(
    parser_context_t *c, pd_asset_add_extension_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readSmartExtension(c, &m->extension_details))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_archive_extension(
    parser_context_t *c, pd_asset_archive_extension_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readAccountId(c, &m->extension_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_unarchive_extension(
    parser_context_t *c, pd_asset_unarchive_extension_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readAccountId(c, &m->extension_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_primary_issuance_agent(
    parser_context_t *c, pd_asset_remove_primary_issuance_agent_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_remove_smart_extension(
    parser_context_t *c, pd_asset_remove_smart_extension_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readAccountId(c, &m->extension_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_claim_classic_ticker(
    parser_context_t *c, pd_asset_claim_classic_ticker_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readEcdsaSignature(c, &m->ethereum_signature))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_asset_reserve_classic_ticker(
    parser_context_t *c, pd_asset_reserve_classic_ticker_t *m) {
  CHECK_ERROR(_readClassicTickerImport(c, &m->classic_ticker_import))
  CHECK_ERROR(_readIdentityId(c, &m->contract_did))
  CHECK_ERROR(_readTickerRegistrationConfig(c, &m->config))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dividend_new(parser_context_t *c,
                                                   pd_dividend_new_t *m) {
  CHECK_ERROR(_readBalance(c, &m->amount))
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readMoment(c, &m->matures_at))
  CHECK_ERROR(_readMoment(c, &m->expires_at))
  CHECK_ERROR(_readTicker(c, &m->payout_ticker))
  CHECK_ERROR(_readCheckpointId(c, &m->checkpoint_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dividend_cancel(parser_context_t *c,
                                                      pd_dividend_cancel_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu32(c, &m->dividend_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dividend_claim(parser_context_t *c,
                                                     pd_dividend_claim_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu32(c, &m->dividend_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_dividend_claim_unclaimed(
    parser_context_t *c, pd_dividend_claim_unclaimed_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu32(c, &m->dividend_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_register_did(
    parser_context_t *c, pd_identity_register_did_t *m) {
  CHECK_ERROR(_readInvestorUid(c, &m->uid))
  CHECK_ERROR(_readVecSecondaryKey(c, &m->secondary_keys))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_cdd_register_did(
    parser_context_t *c, pd_identity_cdd_register_did_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->target_account))
  CHECK_ERROR(_readVecSecondaryKey(c, &m->secondary_keys))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_mock_cdd_register_did(
    parser_context_t *c, pd_identity_mock_cdd_register_did_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->target_account))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_invalidate_cdd_claims(
    parser_context_t *c, pd_identity_invalidate_cdd_claims_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->cdd))
  CHECK_ERROR(_readMoment(c, &m->disable_from))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_secondary_keys(
    parser_context_t *c, pd_identity_remove_secondary_keys_t *m) {
  CHECK_ERROR(_readVecSignatory(c, &m->signers_to_remove))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_primary_key(
    parser_context_t *c, pd_identity_accept_primary_key_t *m) {
  CHECK_ERROR(_readu64(c, &m->rotation_auth_id))
  CHECK_ERROR(_readOptionu64(c, &m->optional_cdd_auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_identity_change_cdd_requirement_for_mk_rotation(
    parser_context_t *c,
    pd_identity_change_cdd_requirement_for_mk_rotation_t *m) {
  CHECK_ERROR(_readbool(c, &m->auth_required))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_key(
    parser_context_t *c, pd_identity_join_identity_as_key_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_join_identity_as_identity(
    parser_context_t *c, pd_identity_join_identity_as_identity_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_key(
    parser_context_t *c, pd_identity_leave_identity_as_key_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_leave_identity_as_identity(
    parser_context_t *c, pd_identity_leave_identity_as_identity_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->did))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_claim(
    parser_context_t *c, pd_identity_add_claim_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target))
  CHECK_ERROR(_readClaim(c, &m->claim))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_forwarded_call(
    parser_context_t *c, pd_identity_forwarded_call_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target_did))
  CHECK_ERROR(_readProposal(c, &m->proposal))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_claim(
    parser_context_t *c, pd_identity_revoke_claim_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target))
  CHECK_ERROR(_readClaim(c, &m->claim))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_set_permission_to_signer(
    parser_context_t *c, pd_identity_set_permission_to_signer_t *m) {
  CHECK_ERROR(_readSignatory(c, &m->signer))
  CHECK_ERROR(_readPermissions(c, &m->permissions))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_legacy_set_permission_to_signer(
    parser_context_t *c, pd_identity_legacy_set_permission_to_signer_t *m) {
  CHECK_ERROR(_readSignatory(c, &m->signer))
  CHECK_ERROR(_readLegacyPermissions(c, &m->permissions))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_freeze_secondary_keys(
    parser_context_t *c, pd_identity_freeze_secondary_keys_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_unfreeze_secondary_keys(
    parser_context_t *c, pd_identity_unfreeze_secondary_keys_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_get_my_did(
    parser_context_t *c, pd_identity_get_my_did_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_get_cdd_of(
    parser_context_t *c, pd_identity_get_cdd_of_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->of))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_authorization(
    parser_context_t *c, pd_identity_add_authorization_t *m) {
  CHECK_ERROR(_readSignatory(c, &m->target))
  CHECK_ERROR(_readAuthorizationData(c, &m->authorization_data))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_remove_authorization(
    parser_context_t *c, pd_identity_remove_authorization_t *m) {
  CHECK_ERROR(_readSignatory(c, &m->target))
  CHECK_ERROR(_readu64(c, &m->auth_id))
  CHECK_ERROR(_readbool(c, &m->_auth_issuer_pays))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_accept_authorization(
    parser_context_t *c, pd_identity_accept_authorization_t *m) {
  CHECK_ERROR(_readu64(c, &m->auth_id))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_identity_add_secondary_keys_with_authorization(
    parser_context_t *c,
    pd_identity_add_secondary_keys_with_authorization_t *m) {
  CHECK_ERROR(_readVecSecondaryKeyWithAuth(c, &m->additional_keys))
  CHECK_ERROR(_readMoment(c, &m->expires_at))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_revoke_offchain_authorization(
    parser_context_t *c, pd_identity_revoke_offchain_authorization_t *m) {
  CHECK_ERROR(_readSignatory(c, &m->signer))
  CHECK_ERROR(_readTargetIdAuthorization(c, &m->auth))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_add_investor_uniqueness_claim(
    parser_context_t *c, pd_identity_add_investor_uniqueness_claim_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target))
  CHECK_ERROR(_readClaim(c, &m->claim))
  CHECK_ERROR(_readInvestorZKProofData(c, &m->proof))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_add_cdd_claim(
    parser_context_t *c, pd_identity_gc_add_cdd_claim_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_identity_gc_revoke_cdd_claim(
    parser_context_t *c, pd_identity_gc_revoke_cdd_claim_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_controller(
    parser_context_t *c, pd_bridge_change_controller_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->controller))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_admin(
    parser_context_t *c, pd_bridge_change_admin_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->admin))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_timelock(
    parser_context_t *c, pd_bridge_change_timelock_t *m) {
  CHECK_ERROR(_readBlockNumber(c, &m->timelock))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_freeze(parser_context_t *c,
                                                    pd_bridge_freeze_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze(parser_context_t *c,
                                                      pd_bridge_unfreeze_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_limit(
    parser_context_t *c, pd_bridge_change_bridge_limit_t *m) {
  CHECK_ERROR(_readBalance(c, &m->amount))
  CHECK_ERROR(_readBlockNumber(c, &m->duration))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_change_bridge_exempted(
    parser_context_t *c, pd_bridge_change_bridge_exempted_t *m) {
  CHECK_ERROR(_readVecTupleIdentityIdbool(c, &m->exempted))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_force_handle_bridge_tx(
    parser_context_t *c, pd_bridge_force_handle_bridge_tx_t *m) {
  CHECK_ERROR(_readBridgeTx(c, &m->bridge_tx))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_batch_propose_bridge_tx(
    parser_context_t *c, pd_bridge_batch_propose_bridge_tx_t *m) {
  CHECK_ERROR(_readVecBridgeTx(c, &m->bridge_txs))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_propose_bridge_tx(
    parser_context_t *c, pd_bridge_propose_bridge_tx_t *m) {
  CHECK_ERROR(_readBridgeTx(c, &m->bridge_tx))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_bridge_tx(
    parser_context_t *c, pd_bridge_handle_bridge_tx_t *m) {
  CHECK_ERROR(_readBridgeTx(c, &m->bridge_tx))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_bridge_freeze_txs(parser_context_t *c, pd_bridge_freeze_txs_t *m) {
  CHECK_ERROR(_readVecBridgeTx(c, &m->bridge_txs))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_unfreeze_txs(
    parser_context_t *c, pd_bridge_unfreeze_txs_t *m) {
  CHECK_ERROR(_readVecBridgeTx(c, &m->bridge_txs))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_bridge_handle_scheduled_bridge_tx(
    parser_context_t *c, pd_bridge_handle_scheduled_bridge_tx_t *m) {
  CHECK_ERROR(_readBridgeTx(c, &m->bridge_tx))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_compliancemanager_add_compliance_requirement(
    parser_context_t *c, pd_compliancemanager_add_compliance_requirement_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readVecCondition(c, &m->sender_conditions))
  CHECK_ERROR(_readVecCondition(c, &m->receiver_conditions))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_compliancemanager_remove_compliance_requirement(
    parser_context_t *c,
    pd_compliancemanager_remove_compliance_requirement_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu32(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_compliancemanager_replace_asset_compliance(
    parser_context_t *c, pd_compliancemanager_replace_asset_compliance_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readVecComplianceRequirement(c, &m->asset_compliance))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_reset_asset_compliance(
    parser_context_t *c, pd_compliancemanager_reset_asset_compliance_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_pause_asset_compliance(
    parser_context_t *c, pd_compliancemanager_pause_asset_compliance_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_compliancemanager_resume_asset_compliance(
    parser_context_t *c, pd_compliancemanager_resume_asset_compliance_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_compliancemanager_add_default_trusted_claim_issuer(
    parser_context_t *c,
    pd_compliancemanager_add_default_trusted_claim_issuer_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readTrustedIssuer(c, &m->issuer))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_compliancemanager_remove_default_trusted_claim_issuer(
    parser_context_t *c,
    pd_compliancemanager_remove_default_trusted_claim_issuer_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readTrustedIssuer(c, &m->issuer))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_compliancemanager_change_compliance_requirement(
    parser_context_t *c,
    pd_compliancemanager_change_compliance_requirement_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readComplianceRequirement(c, &m->new_req))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_voting_add_ballot(parser_context_t *c, pd_voting_add_ballot_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readBytes(c, &m->ballot_name))
  CHECK_ERROR(_readBallot(c, &m->ballot_details))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voting_vote(parser_context_t *c,
                                                  pd_voting_vote_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readBytes(c, &m->ballot_name))
  CHECK_ERROR(_readVecBalance(c, &m->votes))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_voting_cancel_ballot(
    parser_context_t *c, pd_voting_cancel_ballot_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readBytes(c, &m->ballot_name))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stocapped_launch_sto(
    parser_context_t *c, pd_stocapped_launch_sto_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readIdentityId(c, &m->beneficiary_did))
  CHECK_ERROR(_readBalance(c, &m->cap))
  CHECK_ERROR(_readu128(c, &m->rate))
  CHECK_ERROR(_readMoment(c, &m->start_date))
  CHECK_ERROR(_readMoment(c, &m->end_date))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stocapped_buy_tokens(
    parser_context_t *c, pd_stocapped_buy_tokens_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu32(c, &m->sto_id))
  CHECK_ERROR(_readBalance(c, &m->value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stocapped_pause_sto(
    parser_context_t *c, pd_stocapped_pause_sto_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu32(c, &m->sto_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_stocapped_unpause_sto(
    parser_context_t *c, pd_stocapped_unpause_sto_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu32(c, &m->sto_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_exemption_modify_exemption_list(
    parser_context_t *c, pd_exemption_modify_exemption_list_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu16(c, &m->_tm))
  CHECK_ERROR(_readIdentityId(c, &m->asset_holder_did))
  CHECK_ERROR(_readbool(c, &m->exempted))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_create_venue(
    parser_context_t *c, pd_settlement_create_venue_t *m) {
  CHECK_ERROR(_readVenueDetails(c, &m->details))
  CHECK_ERROR(_readVecAccountId(c, &m->signers))
  CHECK_ERROR(_readVenueType(c, &m->venue_type))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_update_venue(
    parser_context_t *c, pd_settlement_update_venue_t *m) {
  CHECK_ERROR(_readu64(c, &m->venue_id))
  CHECK_ERROR(_readOptionVenueDetails(c, &m->details))
  CHECK_ERROR(_readOptionVenueType(c, &m->venue_type))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_instruction(
    parser_context_t *c, pd_settlement_add_instruction_t *m) {
  CHECK_ERROR(_readu64(c, &m->venue_id))
  CHECK_ERROR(_readSettlementType(c, &m->settlement_type))
  CHECK_ERROR(_readOptionMoment(c, &m->valid_from))
  CHECK_ERROR(_readVecLeg(c, &m->legs))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_add_and_affirm_instruction(
    parser_context_t *c, pd_settlement_add_and_affirm_instruction_t *m) {
  CHECK_ERROR(_readu64(c, &m->venue_id))
  CHECK_ERROR(_readSettlementType(c, &m->settlement_type))
  CHECK_ERROR(_readOptionMoment(c, &m->valid_from))
  CHECK_ERROR(_readVecLeg(c, &m->legs))
  CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_instruction(
    parser_context_t *c, pd_settlement_affirm_instruction_t *m) {
  CHECK_ERROR(_readu64(c, &m->instruction_id))
  CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_withdraw_affirmation(
    parser_context_t *c, pd_settlement_withdraw_affirmation_t *m) {
  CHECK_ERROR(_readu64(c, &m->instruction_id))
  CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_reject_instruction(
    parser_context_t *c, pd_settlement_reject_instruction_t *m) {
  CHECK_ERROR(_readu64(c, &m->instruction_id))
  CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_affirm_with_receipts(
    parser_context_t *c, pd_settlement_affirm_with_receipts_t *m) {
  CHECK_ERROR(_readu64(c, &m->instruction_id))
  CHECK_ERROR(_readVecReceiptDetails(c, &m->receipt_details))
  CHECK_ERROR(_readVecPortfolioId(c, &m->portfolios))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_claim_receipt(
    parser_context_t *c, pd_settlement_claim_receipt_t *m) {
  CHECK_ERROR(_readu64(c, &m->instruction_id))
  CHECK_ERROR(_readReceiptDetails(c, &m->receipt_details))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_unclaim_receipt(
    parser_context_t *c, pd_settlement_unclaim_receipt_t *m) {
  CHECK_ERROR(_readu64(c, &m->instruction_id))
  CHECK_ERROR(_readu64(c, &m->leg_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_set_venue_filtering(
    parser_context_t *c, pd_settlement_set_venue_filtering_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readbool(c, &m->enabled))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_allow_venues(
    parser_context_t *c, pd_settlement_allow_venues_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readVecu64(c, &m->venues))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_disallow_venues(
    parser_context_t *c, pd_settlement_disallow_venues_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readVecu64(c, &m->venues))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_settlement_execute_scheduled_instruction(
    parser_context_t *c, pd_settlement_execute_scheduled_instruction_t *m) {
  CHECK_ERROR(_readu64(c, &m->instruction_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_create_fundraiser(
    parser_context_t *c, pd_sto_create_fundraiser_t *m) {
  CHECK_ERROR(_readPortfolioId(c, &m->offering_portfolio))
  CHECK_ERROR(_readTicker(c, &m->offering_asset))
  CHECK_ERROR(_readPortfolioId(c, &m->raising_portfolio))
  CHECK_ERROR(_readTicker(c, &m->raising_asset))
  CHECK_ERROR(_readVecPriceTier(c, &m->tiers))
  CHECK_ERROR(_readu64(c, &m->venue_id))
  CHECK_ERROR(_readOptionMoment(c, &m->start))
  CHECK_ERROR(_readOptionMoment(c, &m->end))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_invest(parser_context_t *c,
                                                 pd_sto_invest_t *m) {
  CHECK_ERROR(_readPortfolioId(c, &m->investment_portfolio))
  CHECK_ERROR(_readPortfolioId(c, &m->funding_portfolio))
  CHECK_ERROR(_readTicker(c, &m->offering_asset))
  CHECK_ERROR(_readu64(c, &m->fundraiser_id))
  CHECK_ERROR(_readBalance(c, &m->investment_amount))
  CHECK_ERROR(_readOptionBalance(c, &m->max_price))
  CHECK_ERROR(_readOptionReceiptDetails(c, &m->receipt))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_freeze_fundraiser(
    parser_context_t *c, pd_sto_freeze_fundraiser_t *m) {
  CHECK_ERROR(_readTicker(c, &m->offering_asset))
  CHECK_ERROR(_readu64(c, &m->fundraiser_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_unfreeze_fundraiser(
    parser_context_t *c, pd_sto_unfreeze_fundraiser_t *m) {
  CHECK_ERROR(_readTicker(c, &m->offering_asset))
  CHECK_ERROR(_readu64(c, &m->fundraiser_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_modify_fundraiser_window(
    parser_context_t *c, pd_sto_modify_fundraiser_window_t *m) {
  CHECK_ERROR(_readTicker(c, &m->offering_asset))
  CHECK_ERROR(_readu64(c, &m->fundraiser_id))
  CHECK_ERROR(_readMoment(c, &m->start))
  CHECK_ERROR(_readOptionMoment(c, &m->end))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_sto_stop(parser_context_t *c,
                                               pd_sto_stop_t *m) {
  CHECK_ERROR(_readTicker(c, &m->offering_asset))
  CHECK_ERROR(_readu64(c, &m->fundraiser_id))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_cddserviceproviders_set_active_members_limit(
    parser_context_t *c, pd_cddserviceproviders_set_active_members_limit_t *m) {
  CHECK_ERROR(_readMemberCount(c, &m->limit))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_disable_member(
    parser_context_t *c, pd_cddserviceproviders_disable_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  CHECK_ERROR(_readOptionMoment(c, &m->expiry))
  CHECK_ERROR(_readOptionMoment(c, &m->at))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_add_member(
    parser_context_t *c, pd_cddserviceproviders_add_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_remove_member(
    parser_context_t *c, pd_cddserviceproviders_remove_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->who))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_swap_member(
    parser_context_t *c, pd_cddserviceproviders_swap_member_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->remove))
  CHECK_ERROR(_readIdentityId(c, &m->add))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_reset_members(
    parser_context_t *c, pd_cddserviceproviders_reset_members_t *m) {
  CHECK_ERROR(_readVecIdentityId(c, &m->members))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_cddserviceproviders_abdicate_membership(
    parser_context_t *c, pd_cddserviceproviders_abdicate_membership_t *m) {
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_coefficient(
    parser_context_t *c, pd_protocolfee_change_coefficient_t *m) {
  CHECK_ERROR(_readPosRatio(c, &m->coefficient))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_protocolfee_change_base_fee(
    parser_context_t *c, pd_protocolfee_change_base_fee_t *m) {
  CHECK_ERROR(_readProtocolOp(c, &m->op))
  CHECK_ERROR(_readBalanceOf(c, &m->base_fee))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch(parser_context_t *c,
                                                    pd_utility_batch_t *m) {
  CHECK_ERROR(_readVecCall(c, &m->calls))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_atomic(
    parser_context_t *c, pd_utility_batch_atomic_t *m) {
  CHECK_ERROR(_readVecCall(c, &m->calls))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_utility_batch_optimistic(
    parser_context_t *c, pd_utility_batch_optimistic_t *m) {
  CHECK_ERROR(_readVecCall(c, &m->calls))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_utility_relay_tx(parser_context_t *c, pd_utility_relay_tx_t *m) {
  CHECK_ERROR(_readAccountId(c, &m->target))
  CHECK_ERROR(_readOffChainSignature(c, &m->signature))
  CHECK_ERROR(_readUniqueCall(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_create_portfolio(
    parser_context_t *c, pd_portfolio_create_portfolio_t *m) {
  CHECK_ERROR(_readPortfolioName(c, &m->name))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_delete_portfolio(
    parser_context_t *c, pd_portfolio_delete_portfolio_t *m) {
  CHECK_ERROR(_readPortfolioNumber(c, &m->num))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_move_portfolio_funds(
    parser_context_t *c, pd_portfolio_move_portfolio_funds_t *m) {
  CHECK_ERROR(_readPortfolioId(c, &m->from))
  CHECK_ERROR(_readPortfolioId(c, &m->to))
  CHECK_ERROR(_readVecMovePortfolioItem(c, &m->items))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_portfolio_rename_portfolio(
    parser_context_t *c, pd_portfolio_rename_portfolio_t *m) {
  CHECK_ERROR(_readPortfolioNumber(c, &m->num))
  CHECK_ERROR(_readPortfolioName(c, &m->to_name))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_confidential_add_range_proof(
    parser_context_t *c, pd_confidential_add_range_proof_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target_id))
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readu64(c, &m->secret_value))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_confidential_add_verify_range_proof(
    parser_context_t *c, pd_confidential_add_verify_range_proof_t *m) {
  CHECK_ERROR(_readIdentityId(c, &m->target))
  CHECK_ERROR(_readIdentityId(c, &m->prover))
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule(
    parser_context_t *c, pd_scheduler_schedule_t *m) {
  CHECK_ERROR(_readBlockNumber(c, &m->when))
  CHECK_ERROR(_readOptionPeriod(c, &m->maybe_periodic))
  CHECK_ERROR(_readPriority(c, &m->priority))
  CHECK_ERROR(_readCall(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_scheduler_cancel(parser_context_t *c, pd_scheduler_cancel_t *m) {
  CHECK_ERROR(_readBlockNumber(c, &m->when))
  CHECK_ERROR(_readu32(c, &m->index))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named(
    parser_context_t *c, pd_scheduler_schedule_named_t *m) {
  CHECK_ERROR(_readBytes(c, &m->id))
  CHECK_ERROR(_readBlockNumber(c, &m->when))
  CHECK_ERROR(_readOptionPeriod(c, &m->maybe_periodic))
  CHECK_ERROR(_readPriority(c, &m->priority))
  CHECK_ERROR(_readCall(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_cancel_named(
    parser_context_t *c, pd_scheduler_cancel_named_t *m) {
  CHECK_ERROR(_readBytes(c, &m->id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_after(
    parser_context_t *c, pd_scheduler_schedule_after_t *m) {
  CHECK_ERROR(_readBlockNumber(c, &m->after))
  CHECK_ERROR(_readOptionPeriod(c, &m->maybe_periodic))
  CHECK_ERROR(_readPriority(c, &m->priority))
  CHECK_ERROR(_readCall(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_scheduler_schedule_named_after(
    parser_context_t *c, pd_scheduler_schedule_named_after_t *m) {
  CHECK_ERROR(_readBytes(c, &m->id))
  CHECK_ERROR(_readBlockNumber(c, &m->after))
  CHECK_ERROR(_readOptionPeriod(c, &m->maybe_periodic))
  CHECK_ERROR(_readPriority(c, &m->priority))
  CHECK_ERROR(_readCall(c, &m->call))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_max_details_length(
    parser_context_t *c, pd_corporateaction_set_max_details_length_t *m) {
  CHECK_ERROR(_readu32(c, &m->length))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_reset_caa(
    parser_context_t *c, pd_corporateaction_reset_caa_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_default_targets(
    parser_context_t *c, pd_corporateaction_set_default_targets_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readTargetIdentities(c, &m->targets))
  return parser_ok;
}

__Z_INLINE parser_error_t
_readMethod_corporateaction_set_default_withholding_tax(
    parser_context_t *c, pd_corporateaction_set_default_withholding_tax_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readTax(c, &m->tax))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_set_did_withholding_tax(
    parser_context_t *c, pd_corporateaction_set_did_withholding_tax_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readIdentityId(c, &m->taxed_did))
  CHECK_ERROR(_readOptionTax(c, &m->tax))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_initiate_corporate_action(
    parser_context_t *c, pd_corporateaction_initiate_corporate_action_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readCAKind(c, &m->kind))
  CHECK_ERROR(_readOptionRecordDateSpec(c, &m->record_date))
  CHECK_ERROR(_readCADetails(c, &m->details))
  CHECK_ERROR(_readOptionTargetIdentities(c, &m->targets))
  CHECK_ERROR(_readOptionTax(c, &m->default_withholding_tax))
  CHECK_ERROR(_readOptionVecTupleIdentityIdTax(c, &m->withholding_tax))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_link_ca_doc(
    parser_context_t *c, pd_corporateaction_link_ca_doc_t *m) {
  CHECK_ERROR(_readCAId(c, &m->id))
  CHECK_ERROR(_readVecDocumentId(c, &m->docs))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_remove_ca(
    parser_context_t *c, pd_corporateaction_remove_ca_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateaction_change_record_date(
    parser_context_t *c, pd_corporateaction_change_record_date_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readOptionRecordDateSpec(c, &m->record_date))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_attach_ballot(
    parser_context_t *c, pd_corporateballot_attach_ballot_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readBallotTimeRange(c, &m->range))
  CHECK_ERROR(_readBallotMeta(c, &m->meta))
  CHECK_ERROR(_readbool(c, &m->rcv))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_vote(
    parser_context_t *c, pd_corporateballot_vote_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readVecBallotVote(c, &m->votes))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_end(
    parser_context_t *c, pd_corporateballot_change_end_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readMoment(c, &m->end))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_meta(
    parser_context_t *c, pd_corporateballot_change_meta_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readBallotMeta(c, &m->meta))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_change_rcv(
    parser_context_t *c, pd_corporateballot_change_rcv_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readbool(c, &m->rcv))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_corporateballot_remove_ballot(
    parser_context_t *c, pd_corporateballot_remove_ballot_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_distribute(
    parser_context_t *c, pd_capitaldistribution_distribute_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readOptionPortfolioNumber(c, &m->portfolio))
  CHECK_ERROR(_readTicker(c, &m->currency))
  CHECK_ERROR(_readBalance(c, &m->amount))
  CHECK_ERROR(_readMoment(c, &m->payment_at))
  CHECK_ERROR(_readOptionMoment(c, &m->expires_at))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_claim(
    parser_context_t *c, pd_capitaldistribution_claim_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_push_benefit(
    parser_context_t *c, pd_capitaldistribution_push_benefit_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  CHECK_ERROR(_readIdentityId(c, &m->holder))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_reclaim(
    parser_context_t *c, pd_capitaldistribution_reclaim_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_capitaldistribution_remove_distribution(
    parser_context_t *c, pd_capitaldistribution_remove_distribution_t *m) {
  CHECK_ERROR(_readCAId(c, &m->ca_id))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_checkpoint(
    parser_context_t *c, pd_checkpoint_create_checkpoint_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_set_schedules_max_complexity(
    parser_context_t *c, pd_checkpoint_set_schedules_max_complexity_t *m) {
  CHECK_ERROR(_readu64(c, &m->max_complexity))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_create_schedule(
    parser_context_t *c, pd_checkpoint_create_schedule_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readScheduleSpec(c, &m->schedule))
  return parser_ok;
}

__Z_INLINE parser_error_t _readMethod_checkpoint_remove_schedule(
    parser_context_t *c, pd_checkpoint_remove_schedule_t *m) {
  CHECK_ERROR(_readTicker(c, &m->ticker))
  CHECK_ERROR(_readScheduleId(c, &m->id))
  return parser_ok;
}

parser_error_t _readMethodBasic(parser_context_t *c, uint8_t moduleIdx,
                                uint8_t callIdx, pd_MethodBasic_t *method) {
  uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

  switch (callPrivIdx) {
  case 0: /* module 0 call 0 */
    CHECK_ERROR(_readMethod_system_fill_block(c, &method->system_fill_block))
    break;
  case 1: /* module 0 call 1 */
    CHECK_ERROR(_readMethod_system_remark(c, &method->system_remark))
    break;
  case 2: /* module 0 call 2 */
    CHECK_ERROR(
        _readMethod_system_set_heap_pages(c, &method->system_set_heap_pages))
    break;
  case 3: /* module 0 call 3 */
    CHECK_ERROR(_readMethod_system_set_code(c, &method->system_set_code))
    break;
  case 4: /* module 0 call 4 */
    CHECK_ERROR(_readMethod_system_set_code_without_checks(
        c, &method->system_set_code_without_checks))
    break;
  case 5: /* module 0 call 5 */
    CHECK_ERROR(_readMethod_system_set_changes_trie_config(
        c, &method->system_set_changes_trie_config))
    break;
  case 6: /* module 0 call 6 */
    CHECK_ERROR(_readMethod_system_set_storage(c, &method->system_set_storage))
    break;
  case 7: /* module 0 call 7 */
    CHECK_ERROR(
        _readMethod_system_kill_storage(c, &method->system_kill_storage))
    break;
  case 8: /* module 0 call 8 */
    CHECK_ERROR(_readMethod_system_kill_prefix(c, &method->system_kill_prefix))
    break;
  case 9: /* module 0 call 9 */
    CHECK_ERROR(_readMethod_system_suicide(c, &method->system_suicide))
    break;
  case 256: /* module 1 call 0 */
    CHECK_ERROR(_readMethod_babe_report_equivocation(
        c, &method->babe_report_equivocation))
    break;
  case 257: /* module 1 call 1 */
    CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned(
        c, &method->babe_report_equivocation_unsigned))
    break;
  case 512: /* module 2 call 0 */
    CHECK_ERROR(_readMethod_timestamp_set(c, &method->timestamp_set))
    break;
  case 768: /* module 3 call 0 */
    CHECK_ERROR(_readMethod_indices_claim(c, &method->indices_claim))
    break;
  case 769: /* module 3 call 1 */
    CHECK_ERROR(_readMethod_indices_transfer(c, &method->indices_transfer))
    break;
  case 770: /* module 3 call 2 */
    CHECK_ERROR(_readMethod_indices_free(c, &method->indices_free))
    break;
  case 771: /* module 3 call 3 */
    CHECK_ERROR(
        _readMethod_indices_force_transfer(c, &method->indices_force_transfer))
    break;
  case 772: /* module 3 call 4 */
    CHECK_ERROR(_readMethod_indices_freeze(c, &method->indices_freeze))
    break;
  case 1024: /* module 4 call 0 */
    CHECK_ERROR(_readMethod_balances_transfer(c, &method->balances_transfer))
    break;
  case 1025: /* module 4 call 1 */
    CHECK_ERROR(_readMethod_balances_transfer_with_memo(
        c, &method->balances_transfer_with_memo))
    break;
  case 1026: /* module 4 call 2 */
    CHECK_ERROR(_readMethod_balances_deposit_block_reward_reserve_balance(
        c, &method->balances_deposit_block_reward_reserve_balance))
    break;
  case 1027: /* module 4 call 3 */
    CHECK_ERROR(
        _readMethod_balances_set_balance(c, &method->balances_set_balance))
    break;
  case 1028: /* module 4 call 4 */
    CHECK_ERROR(_readMethod_balances_force_transfer(
        c, &method->balances_force_transfer))
    break;
  case 1029: /* module 4 call 5 */
    CHECK_ERROR(_readMethod_balances_burn_account_balance(
        c, &method->balances_burn_account_balance))
    break;
  case 1536: /* module 6 call 0 */
    CHECK_ERROR(
        _readMethod_authorship_set_uncles(c, &method->authorship_set_uncles))
    break;
  case 1792: /* module 7 call 0 */
    CHECK_ERROR(_readMethod_staking_bond(c, &method->staking_bond))
    break;
  case 1793: /* module 7 call 1 */
    CHECK_ERROR(_readMethod_staking_bond_extra(c, &method->staking_bond_extra))
    break;
  case 1794: /* module 7 call 2 */
    CHECK_ERROR(_readMethod_staking_unbond(c, &method->staking_unbond))
    break;
  case 1795: /* module 7 call 3 */
    CHECK_ERROR(_readMethod_staking_withdraw_unbonded(
        c, &method->staking_withdraw_unbonded))
    break;
  case 1796: /* module 7 call 4 */
    CHECK_ERROR(_readMethod_staking_validate(c, &method->staking_validate))
    break;
  case 1797: /* module 7 call 5 */
    CHECK_ERROR(_readMethod_staking_nominate(c, &method->staking_nominate))
    break;
  case 1798: /* module 7 call 6 */
    CHECK_ERROR(_readMethod_staking_chill(c, &method->staking_chill))
    break;
  case 1799: /* module 7 call 7 */
    CHECK_ERROR(_readMethod_staking_set_payee(c, &method->staking_set_payee))
    break;
  case 1800: /* module 7 call 8 */
    CHECK_ERROR(
        _readMethod_staking_set_controller(c, &method->staking_set_controller))
    break;
  case 1801: /* module 7 call 9 */
    CHECK_ERROR(_readMethod_staking_set_validator_count(
        c, &method->staking_set_validator_count))
    break;
  case 1802: /* module 7 call 10 */
    CHECK_ERROR(_readMethod_staking_increase_validator_count(
        c, &method->staking_increase_validator_count))
    break;
  case 1803: /* module 7 call 11 */
    CHECK_ERROR(_readMethod_staking_scale_validator_count(
        c, &method->staking_scale_validator_count))
    break;
  case 1804: /* module 7 call 12 */
    CHECK_ERROR(_readMethod_staking_add_permissioned_validator(
        c, &method->staking_add_permissioned_validator))
    break;
  case 1805: /* module 7 call 13 */
    CHECK_ERROR(_readMethod_staking_remove_permissioned_validator(
        c, &method->staking_remove_permissioned_validator))
    break;
  case 1806: /* module 7 call 14 */
    CHECK_ERROR(_readMethod_staking_validate_cdd_expiry_nominators(
        c, &method->staking_validate_cdd_expiry_nominators))
    break;
  case 1807: /* module 7 call 15 */
    CHECK_ERROR(_readMethod_staking_set_commission_cap(
        c, &method->staking_set_commission_cap))
    break;
  case 1808: /* module 7 call 16 */
    CHECK_ERROR(_readMethod_staking_set_min_bond_threshold(
        c, &method->staking_set_min_bond_threshold))
    break;
  case 1809: /* module 7 call 17 */
    CHECK_ERROR(
        _readMethod_staking_force_no_eras(c, &method->staking_force_no_eras))
    break;
  case 1810: /* module 7 call 18 */
    CHECK_ERROR(
        _readMethod_staking_force_new_era(c, &method->staking_force_new_era))
    break;
  case 1811: /* module 7 call 19 */
    CHECK_ERROR(_readMethod_staking_set_invulnerables(
        c, &method->staking_set_invulnerables))
    break;
  case 1812: /* module 7 call 20 */
    CHECK_ERROR(
        _readMethod_staking_force_unstake(c, &method->staking_force_unstake))
    break;
  case 1813: /* module 7 call 21 */
    CHECK_ERROR(_readMethod_staking_force_new_era_always(
        c, &method->staking_force_new_era_always))
    break;
  case 1814: /* module 7 call 22 */
    CHECK_ERROR(_readMethod_staking_cancel_deferred_slash(
        c, &method->staking_cancel_deferred_slash))
    break;
  case 1815: /* module 7 call 23 */
    CHECK_ERROR(
        _readMethod_staking_payout_stakers(c, &method->staking_payout_stakers))
    break;
  case 1816: /* module 7 call 24 */
    CHECK_ERROR(_readMethod_staking_rebond(c, &method->staking_rebond))
    break;
  case 1817: /* module 7 call 25 */
    CHECK_ERROR(_readMethod_staking_set_history_depth(
        c, &method->staking_set_history_depth))
    break;
  case 1818: /* module 7 call 26 */
    CHECK_ERROR(_readMethod_staking_reap_stash(c, &method->staking_reap_stash))
    break;
  case 1819: /* module 7 call 27 */
    CHECK_ERROR(_readMethod_staking_submit_election_solution(
        c, &method->staking_submit_election_solution))
    break;
  case 1820: /* module 7 call 28 */
    CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned(
        c, &method->staking_submit_election_solution_unsigned))
    break;
  case 1821: /* module 7 call 29 */
    CHECK_ERROR(_readMethod_staking_payout_stakers_by_system(
        c, &method->staking_payout_stakers_by_system))
    break;
  case 1822: /* module 7 call 30 */
    CHECK_ERROR(_readMethod_staking_change_slashing_allowed_for(
        c, &method->staking_change_slashing_allowed_for))
    break;
  case 2304: /* module 9 call 0 */
    CHECK_ERROR(_readMethod_session_set_keys(c, &method->session_set_keys))
    break;
  case 2305: /* module 9 call 1 */
    CHECK_ERROR(_readMethod_session_purge_keys(c, &method->session_purge_keys))
    break;
  case 2560: /* module 10 call 0 */
    CHECK_ERROR(_readMethod_finalitytracker_final_hint(
        c, &method->finalitytracker_final_hint))
    break;
  case 2816: /* module 11 call 0 */
    CHECK_ERROR(_readMethod_grandpa_report_equivocation(
        c, &method->grandpa_report_equivocation))
    break;
  case 2817: /* module 11 call 1 */
    CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned(
        c, &method->grandpa_report_equivocation_unsigned))
    break;
  case 2818: /* module 11 call 2 */
    CHECK_ERROR(
        _readMethod_grandpa_note_stalled(c, &method->grandpa_note_stalled))
    break;
  case 3072: /* module 12 call 0 */
    CHECK_ERROR(_readMethod_imonline_heartbeat(c, &method->imonline_heartbeat))
    break;
  case 3073: /* module 12 call 1 */
    CHECK_ERROR(_readMethod_imonline_set_slashing_params(
        c, &method->imonline_set_slashing_params))
    break;
  case 4096: /* module 16 call 0 */
    CHECK_ERROR(_readMethod_sudo_sudo(c, &method->sudo_sudo))
    break;
  case 4097: /* module 16 call 1 */
    CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight(
        c, &method->sudo_sudo_unchecked_weight))
    break;
  case 4098: /* module 16 call 2 */
    CHECK_ERROR(_readMethod_sudo_set_key(c, &method->sudo_set_key))
    break;
  case 4099: /* module 16 call 3 */
    CHECK_ERROR(_readMethod_sudo_sudo_as(c, &method->sudo_sudo_as))
    break;
  case 4352: /* module 17 call 0 */
    CHECK_ERROR(_readMethod_multisig_create_multisig(
        c, &method->multisig_create_multisig))
    break;
  case 4357: /* module 17 call 5 */
    CHECK_ERROR(_readMethod_multisig_approve_as_identity(
        c, &method->multisig_approve_as_identity))
    break;
  case 4358: /* module 17 call 6 */
    CHECK_ERROR(_readMethod_multisig_approve_as_key(
        c, &method->multisig_approve_as_key))
    break;
  case 4359: /* module 17 call 7 */
    CHECK_ERROR(_readMethod_multisig_reject_as_identity(
        c, &method->multisig_reject_as_identity))
    break;
  case 4360: /* module 17 call 8 */
    CHECK_ERROR(
        _readMethod_multisig_reject_as_key(c, &method->multisig_reject_as_key))
    break;
  case 4361: /* module 17 call 9 */
    CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_identity(
        c, &method->multisig_accept_multisig_signer_as_identity))
    break;
  case 4362: /* module 17 call 10 */
    CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_key(
        c, &method->multisig_accept_multisig_signer_as_key))
    break;
  case 4363: /* module 17 call 11 */
    CHECK_ERROR(_readMethod_multisig_add_multisig_signer(
        c, &method->multisig_add_multisig_signer))
    break;
  case 4364: /* module 17 call 12 */
    CHECK_ERROR(_readMethod_multisig_remove_multisig_signer(
        c, &method->multisig_remove_multisig_signer))
    break;
  case 4365: /* module 17 call 13 */
    CHECK_ERROR(_readMethod_multisig_add_multisig_signers_via_creator(
        c, &method->multisig_add_multisig_signers_via_creator))
    break;
  case 4366: /* module 17 call 14 */
    CHECK_ERROR(_readMethod_multisig_remove_multisig_signers_via_creator(
        c, &method->multisig_remove_multisig_signers_via_creator))
    break;
  case 4367: /* module 17 call 15 */
    CHECK_ERROR(_readMethod_multisig_change_sigs_required(
        c, &method->multisig_change_sigs_required))
    break;
  case 4368: /* module 17 call 16 */
    CHECK_ERROR(_readMethod_multisig_change_all_signers_and_sigs_required(
        c, &method->multisig_change_all_signers_and_sigs_required))
    break;
  case 4369: /* module 17 call 17 */
    CHECK_ERROR(_readMethod_multisig_make_multisig_signer(
        c, &method->multisig_make_multisig_signer))
    break;
  case 4370: /* module 17 call 18 */
    CHECK_ERROR(_readMethod_multisig_make_multisig_primary(
        c, &method->multisig_make_multisig_primary))
    break;
  case 4864: /* module 19 call 0 */
    CHECK_ERROR(_readMethod_contracts_update_schedule(
        c, &method->contracts_update_schedule))
    break;
  case 4865: /* module 19 call 1 */
    CHECK_ERROR(_readMethod_contracts_put_code(c, &method->contracts_put_code))
    break;
  case 4866: /* module 19 call 2 */
    CHECK_ERROR(_readMethod_contracts_call(c, &method->contracts_call))
    break;
  case 4867: /* module 19 call 3 */
    CHECK_ERROR(
        _readMethod_contracts_instantiate(c, &method->contracts_instantiate))
    break;
  case 4868: /* module 19 call 4 */
    CHECK_ERROR(_readMethod_contracts_freeze_instantiation(
        c, &method->contracts_freeze_instantiation))
    break;
  case 4869: /* module 19 call 5 */
    CHECK_ERROR(_readMethod_contracts_unfreeze_instantiation(
        c, &method->contracts_unfreeze_instantiation))
    break;
  case 4870: /* module 19 call 6 */
    CHECK_ERROR(_readMethod_contracts_transfer_template_ownership(
        c, &method->contracts_transfer_template_ownership))
    break;
  case 4871: /* module 19 call 7 */
    CHECK_ERROR(_readMethod_contracts_change_template_fees(
        c, &method->contracts_change_template_fees))
    break;
  case 4872: /* module 19 call 8 */
    CHECK_ERROR(_readMethod_contracts_change_template_meta_url(
        c, &method->contracts_change_template_meta_url))
    break;
  case 5120: /* module 20 call 0 */
    CHECK_ERROR(
        _readMethod_treasury_disbursement(c, &method->treasury_disbursement))
    break;
  case 5121: /* module 20 call 1 */
    CHECK_ERROR(
        _readMethod_treasury_reimbursement(c, &method->treasury_reimbursement))
    break;
  case 5376: /* module 21 call 0 */
    CHECK_ERROR(_readMethod_polymeshcommittee_set_vote_threshold(
        c, &method->polymeshcommittee_set_vote_threshold))
    break;
  case 5377: /* module 21 call 1 */
    CHECK_ERROR(_readMethod_polymeshcommittee_set_release_coordinator(
        c, &method->polymeshcommittee_set_release_coordinator))
    break;
  case 5378: /* module 21 call 2 */
    CHECK_ERROR(_readMethod_polymeshcommittee_set_expires_after(
        c, &method->polymeshcommittee_set_expires_after))
    break;
  case 5379: /* module 21 call 3 */
    CHECK_ERROR(_readMethod_polymeshcommittee_close(
        c, &method->polymeshcommittee_close))
    break;
  case 5381: /* module 21 call 5 */
    CHECK_ERROR(
        _readMethod_polymeshcommittee_vote(c, &method->polymeshcommittee_vote))
    break;
  case 5632: /* module 22 call 0 */
    CHECK_ERROR(_readMethod_committeemembership_set_active_members_limit(
        c, &method->committeemembership_set_active_members_limit))
    break;
  case 5633: /* module 22 call 1 */
    CHECK_ERROR(_readMethod_committeemembership_disable_member(
        c, &method->committeemembership_disable_member))
    break;
  case 5634: /* module 22 call 2 */
    CHECK_ERROR(_readMethod_committeemembership_add_member(
        c, &method->committeemembership_add_member))
    break;
  case 5635: /* module 22 call 3 */
    CHECK_ERROR(_readMethod_committeemembership_remove_member(
        c, &method->committeemembership_remove_member))
    break;
  case 5636: /* module 22 call 4 */
    CHECK_ERROR(_readMethod_committeemembership_swap_member(
        c, &method->committeemembership_swap_member))
    break;
  case 5637: /* module 22 call 5 */
    CHECK_ERROR(_readMethod_committeemembership_reset_members(
        c, &method->committeemembership_reset_members))
    break;
  case 5638: /* module 22 call 6 */
    CHECK_ERROR(_readMethod_committeemembership_abdicate_membership(
        c, &method->committeemembership_abdicate_membership))
    break;
  case 5888: /* module 23 call 0 */
    CHECK_ERROR(_readMethod_pips_set_prune_historical_pips(
        c, &method->pips_set_prune_historical_pips))
    break;
  case 5889: /* module 23 call 1 */
    CHECK_ERROR(_readMethod_pips_set_min_proposal_deposit(
        c, &method->pips_set_min_proposal_deposit))
    break;
  case 5890: /* module 23 call 2 */
    CHECK_ERROR(_readMethod_pips_set_proposal_cool_off_period(
        c, &method->pips_set_proposal_cool_off_period))
    break;
  case 5891: /* module 23 call 3 */
    CHECK_ERROR(_readMethod_pips_set_default_enactment_period(
        c, &method->pips_set_default_enactment_period))
    break;
  case 5892: /* module 23 call 4 */
    CHECK_ERROR(_readMethod_pips_set_pending_pip_expiry(
        c, &method->pips_set_pending_pip_expiry))
    break;
  case 5893: /* module 23 call 5 */
    CHECK_ERROR(_readMethod_pips_set_max_pip_skip_count(
        c, &method->pips_set_max_pip_skip_count))
    break;
  case 5894: /* module 23 call 6 */
    CHECK_ERROR(_readMethod_pips_set_active_pip_limit(
        c, &method->pips_set_active_pip_limit))
    break;
  case 5896: /* module 23 call 8 */
    CHECK_ERROR(
        _readMethod_pips_amend_proposal(c, &method->pips_amend_proposal))
    break;
  case 5897: /* module 23 call 9 */
    CHECK_ERROR(
        _readMethod_pips_cancel_proposal(c, &method->pips_cancel_proposal))
    break;
  case 5898: /* module 23 call 10 */
    CHECK_ERROR(_readMethod_pips_vote(c, &method->pips_vote))
    break;
  case 5899: /* module 23 call 11 */
    CHECK_ERROR(_readMethod_pips_approve_committee_proposal(
        c, &method->pips_approve_committee_proposal))
    break;
  case 5900: /* module 23 call 12 */
    CHECK_ERROR(
        _readMethod_pips_reject_proposal(c, &method->pips_reject_proposal))
    break;
  case 5901: /* module 23 call 13 */
    CHECK_ERROR(
        _readMethod_pips_prune_proposal(c, &method->pips_prune_proposal))
    break;
  case 5902: /* module 23 call 14 */
    CHECK_ERROR(_readMethod_pips_reschedule_execution(
        c, &method->pips_reschedule_execution))
    break;
  case 5903: /* module 23 call 15 */
    CHECK_ERROR(
        _readMethod_pips_clear_snapshot(c, &method->pips_clear_snapshot))
    break;
  case 5904: /* module 23 call 16 */
    CHECK_ERROR(_readMethod_pips_snapshot(c, &method->pips_snapshot))
    break;
  case 5905: /* module 23 call 17 */
    CHECK_ERROR(_readMethod_pips_enact_snapshot_results(
        c, &method->pips_enact_snapshot_results))
    break;
  case 5906: /* module 23 call 18 */
    CHECK_ERROR(_readMethod_pips_execute_scheduled_pip(
        c, &method->pips_execute_scheduled_pip))
    break;
  case 5907: /* module 23 call 19 */
    CHECK_ERROR(_readMethod_pips_expire_scheduled_pip(
        c, &method->pips_expire_scheduled_pip))
    break;
  case 6144: /* module 24 call 0 */
    CHECK_ERROR(_readMethod_technicalcommittee_set_vote_threshold(
        c, &method->technicalcommittee_set_vote_threshold))
    break;
  case 6145: /* module 24 call 1 */
    CHECK_ERROR(_readMethod_technicalcommittee_set_release_coordinator(
        c, &method->technicalcommittee_set_release_coordinator))
    break;
  case 6146: /* module 24 call 2 */
    CHECK_ERROR(_readMethod_technicalcommittee_set_expires_after(
        c, &method->technicalcommittee_set_expires_after))
    break;
  case 6147: /* module 24 call 3 */
    CHECK_ERROR(_readMethod_technicalcommittee_close(
        c, &method->technicalcommittee_close))
    break;
  case 6149: /* module 24 call 5 */
    CHECK_ERROR(_readMethod_technicalcommittee_vote(
        c, &method->technicalcommittee_vote))
    break;
  case 6400: /* module 25 call 0 */
    CHECK_ERROR(
        _readMethod_technicalcommitteemembership_set_active_members_limit(
            c, &method->technicalcommitteemembership_set_active_members_limit))
    break;
  case 6401: /* module 25 call 1 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_disable_member(
        c, &method->technicalcommitteemembership_disable_member))
    break;
  case 6402: /* module 25 call 2 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member(
        c, &method->technicalcommitteemembership_add_member))
    break;
  case 6403: /* module 25 call 3 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member(
        c, &method->technicalcommitteemembership_remove_member))
    break;
  case 6404: /* module 25 call 4 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member(
        c, &method->technicalcommitteemembership_swap_member))
    break;
  case 6405: /* module 25 call 5 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members(
        c, &method->technicalcommitteemembership_reset_members))
    break;
  case 6406: /* module 25 call 6 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_abdicate_membership(
        c, &method->technicalcommitteemembership_abdicate_membership))
    break;
  case 6656: /* module 26 call 0 */
    CHECK_ERROR(_readMethod_upgradecommittee_set_vote_threshold(
        c, &method->upgradecommittee_set_vote_threshold))
    break;
  case 6657: /* module 26 call 1 */
    CHECK_ERROR(_readMethod_upgradecommittee_set_release_coordinator(
        c, &method->upgradecommittee_set_release_coordinator))
    break;
  case 6658: /* module 26 call 2 */
    CHECK_ERROR(_readMethod_upgradecommittee_set_expires_after(
        c, &method->upgradecommittee_set_expires_after))
    break;
  case 6659: /* module 26 call 3 */
    CHECK_ERROR(
        _readMethod_upgradecommittee_close(c, &method->upgradecommittee_close))
    break;
  case 6661: /* module 26 call 5 */
    CHECK_ERROR(
        _readMethod_upgradecommittee_vote(c, &method->upgradecommittee_vote))
    break;
  case 6912: /* module 27 call 0 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_set_active_members_limit(
        c, &method->upgradecommitteemembership_set_active_members_limit))
    break;
  case 6913: /* module 27 call 1 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_disable_member(
        c, &method->upgradecommitteemembership_disable_member))
    break;
  case 6914: /* module 27 call 2 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_add_member(
        c, &method->upgradecommitteemembership_add_member))
    break;
  case 6915: /* module 27 call 3 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_remove_member(
        c, &method->upgradecommitteemembership_remove_member))
    break;
  case 6916: /* module 27 call 4 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_swap_member(
        c, &method->upgradecommitteemembership_swap_member))
    break;
  case 6917: /* module 27 call 5 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_reset_members(
        c, &method->upgradecommitteemembership_reset_members))
    break;
  case 6918: /* module 27 call 6 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_abdicate_membership(
        c, &method->upgradecommitteemembership_abdicate_membership))
    break;
  case 7168: /* module 28 call 0 */
    CHECK_ERROR(
        _readMethod_asset_register_ticker(c, &method->asset_register_ticker))
    break;
  case 7169: /* module 28 call 1 */
    CHECK_ERROR(_readMethod_asset_accept_ticker_transfer(
        c, &method->asset_accept_ticker_transfer))
    break;
  case 7170: /* module 28 call 2 */
    CHECK_ERROR(_readMethod_asset_accept_primary_issuance_agent_transfer(
        c, &method->asset_accept_primary_issuance_agent_transfer))
    break;
  case 7171: /* module 28 call 3 */
    CHECK_ERROR(_readMethod_asset_accept_asset_ownership_transfer(
        c, &method->asset_accept_asset_ownership_transfer))
    break;
  case 7172: /* module 28 call 4 */
    CHECK_ERROR(_readMethod_asset_create_asset(c, &method->asset_create_asset))
    break;
  case 7173: /* module 28 call 5 */
    CHECK_ERROR(_readMethod_asset_freeze(c, &method->asset_freeze))
    break;
  case 7174: /* module 28 call 6 */
    CHECK_ERROR(_readMethod_asset_unfreeze(c, &method->asset_unfreeze))
    break;
  case 7175: /* module 28 call 7 */
    CHECK_ERROR(_readMethod_asset_rename_asset(c, &method->asset_rename_asset))
    break;
  case 7176: /* module 28 call 8 */
    CHECK_ERROR(_readMethod_asset_issue(c, &method->asset_issue))
    break;
  case 7177: /* module 28 call 9 */
    CHECK_ERROR(_readMethod_asset_redeem(c, &method->asset_redeem))
    break;
  case 7178: /* module 28 call 10 */
    CHECK_ERROR(
        _readMethod_asset_make_divisible(c, &method->asset_make_divisible))
    break;
  case 7179: /* module 28 call 11 */
    CHECK_ERROR(
        _readMethod_asset_add_documents(c, &method->asset_add_documents))
    break;
  case 7180: /* module 28 call 12 */
    CHECK_ERROR(
        _readMethod_asset_remove_documents(c, &method->asset_remove_documents))
    break;
  case 7181: /* module 28 call 13 */
    CHECK_ERROR(_readMethod_asset_set_funding_round(
        c, &method->asset_set_funding_round))
    break;
  case 7182: /* module 28 call 14 */
    CHECK_ERROR(_readMethod_asset_update_identifiers(
        c, &method->asset_update_identifiers))
    break;
  case 7183: /* module 28 call 15 */
    CHECK_ERROR(
        _readMethod_asset_add_extension(c, &method->asset_add_extension))
    break;
  case 7184: /* module 28 call 16 */
    CHECK_ERROR(_readMethod_asset_archive_extension(
        c, &method->asset_archive_extension))
    break;
  case 7185: /* module 28 call 17 */
    CHECK_ERROR(_readMethod_asset_unarchive_extension(
        c, &method->asset_unarchive_extension))
    break;
  case 7186: /* module 28 call 18 */
    CHECK_ERROR(_readMethod_asset_remove_primary_issuance_agent(
        c, &method->asset_remove_primary_issuance_agent))
    break;
  case 7187: /* module 28 call 19 */
    CHECK_ERROR(_readMethod_asset_remove_smart_extension(
        c, &method->asset_remove_smart_extension))
    break;
  case 7188: /* module 28 call 20 */
    CHECK_ERROR(_readMethod_asset_claim_classic_ticker(
        c, &method->asset_claim_classic_ticker))
    break;
  case 7189: /* module 28 call 21 */
    CHECK_ERROR(_readMethod_asset_reserve_classic_ticker(
        c, &method->asset_reserve_classic_ticker))
    break;
  case 7424: /* module 29 call 0 */
    CHECK_ERROR(_readMethod_dividend_new(c, &method->dividend_new))
    break;
  case 7425: /* module 29 call 1 */
    CHECK_ERROR(_readMethod_dividend_cancel(c, &method->dividend_cancel))
    break;
  case 7426: /* module 29 call 2 */
    CHECK_ERROR(_readMethod_dividend_claim(c, &method->dividend_claim))
    break;
  case 7427: /* module 29 call 3 */
    CHECK_ERROR(_readMethod_dividend_claim_unclaimed(
        c, &method->dividend_claim_unclaimed))
    break;
  case 7680: /* module 30 call 0 */
    CHECK_ERROR(
        _readMethod_identity_register_did(c, &method->identity_register_did))
    break;
  case 7681: /* module 30 call 1 */
    CHECK_ERROR(_readMethod_identity_cdd_register_did(
        c, &method->identity_cdd_register_did))
    break;
  case 7682: /* module 30 call 2 */
    CHECK_ERROR(_readMethod_identity_mock_cdd_register_did(
        c, &method->identity_mock_cdd_register_did))
    break;
  case 7683: /* module 30 call 3 */
    CHECK_ERROR(_readMethod_identity_invalidate_cdd_claims(
        c, &method->identity_invalidate_cdd_claims))
    break;
  case 7684: /* module 30 call 4 */
    CHECK_ERROR(_readMethod_identity_remove_secondary_keys(
        c, &method->identity_remove_secondary_keys))
    break;
  case 7685: /* module 30 call 5 */
    CHECK_ERROR(_readMethod_identity_accept_primary_key(
        c, &method->identity_accept_primary_key))
    break;
  case 7686: /* module 30 call 6 */
    CHECK_ERROR(_readMethod_identity_change_cdd_requirement_for_mk_rotation(
        c, &method->identity_change_cdd_requirement_for_mk_rotation))
    break;
  case 7687: /* module 30 call 7 */
    CHECK_ERROR(_readMethod_identity_join_identity_as_key(
        c, &method->identity_join_identity_as_key))
    break;
  case 7688: /* module 30 call 8 */
    CHECK_ERROR(_readMethod_identity_join_identity_as_identity(
        c, &method->identity_join_identity_as_identity))
    break;
  case 7689: /* module 30 call 9 */
    CHECK_ERROR(_readMethod_identity_leave_identity_as_key(
        c, &method->identity_leave_identity_as_key))
    break;
  case 7690: /* module 30 call 10 */
    CHECK_ERROR(_readMethod_identity_leave_identity_as_identity(
        c, &method->identity_leave_identity_as_identity))
    break;
  case 7691: /* module 30 call 11 */
    CHECK_ERROR(_readMethod_identity_add_claim(c, &method->identity_add_claim))
    break;
  case 7693: /* module 30 call 13 */
    CHECK_ERROR(
        _readMethod_identity_revoke_claim(c, &method->identity_revoke_claim))
    break;
  case 7694: /* module 30 call 14 */
    CHECK_ERROR(_readMethod_identity_set_permission_to_signer(
        c, &method->identity_set_permission_to_signer))
    break;
  case 7695: /* module 30 call 15 */
    CHECK_ERROR(_readMethod_identity_legacy_set_permission_to_signer(
        c, &method->identity_legacy_set_permission_to_signer))
    break;
  case 7696: /* module 30 call 16 */
    CHECK_ERROR(_readMethod_identity_freeze_secondary_keys(
        c, &method->identity_freeze_secondary_keys))
    break;
  case 7697: /* module 30 call 17 */
    CHECK_ERROR(_readMethod_identity_unfreeze_secondary_keys(
        c, &method->identity_unfreeze_secondary_keys))
    break;
  case 7698: /* module 30 call 18 */
    CHECK_ERROR(
        _readMethod_identity_get_my_did(c, &method->identity_get_my_did))
    break;
  case 7699: /* module 30 call 19 */
    CHECK_ERROR(
        _readMethod_identity_get_cdd_of(c, &method->identity_get_cdd_of))
    break;
  case 7700: /* module 30 call 20 */
    CHECK_ERROR(_readMethod_identity_add_authorization(
        c, &method->identity_add_authorization))
    break;
  case 7701: /* module 30 call 21 */
    CHECK_ERROR(_readMethod_identity_remove_authorization(
        c, &method->identity_remove_authorization))
    break;
  case 7702: /* module 30 call 22 */
    CHECK_ERROR(_readMethod_identity_accept_authorization(
        c, &method->identity_accept_authorization))
    break;
  case 7703: /* module 30 call 23 */
    CHECK_ERROR(_readMethod_identity_add_secondary_keys_with_authorization(
        c, &method->identity_add_secondary_keys_with_authorization))
    break;
  case 7704: /* module 30 call 24 */
    CHECK_ERROR(_readMethod_identity_revoke_offchain_authorization(
        c, &method->identity_revoke_offchain_authorization))
    break;
  case 7705: /* module 30 call 25 */
    CHECK_ERROR(_readMethod_identity_add_investor_uniqueness_claim(
        c, &method->identity_add_investor_uniqueness_claim))
    break;
  case 7706: /* module 30 call 26 */
    CHECK_ERROR(_readMethod_identity_gc_add_cdd_claim(
        c, &method->identity_gc_add_cdd_claim))
    break;
  case 7707: /* module 30 call 27 */
    CHECK_ERROR(_readMethod_identity_gc_revoke_cdd_claim(
        c, &method->identity_gc_revoke_cdd_claim))
    break;
  case 7936: /* module 31 call 0 */
    CHECK_ERROR(_readMethod_bridge_change_controller(
        c, &method->bridge_change_controller))
    break;
  case 7937: /* module 31 call 1 */
    CHECK_ERROR(
        _readMethod_bridge_change_admin(c, &method->bridge_change_admin))
    break;
  case 7938: /* module 31 call 2 */
    CHECK_ERROR(
        _readMethod_bridge_change_timelock(c, &method->bridge_change_timelock))
    break;
  case 7939: /* module 31 call 3 */
    CHECK_ERROR(_readMethod_bridge_freeze(c, &method->bridge_freeze))
    break;
  case 7940: /* module 31 call 4 */
    CHECK_ERROR(_readMethod_bridge_unfreeze(c, &method->bridge_unfreeze))
    break;
  case 7941: /* module 31 call 5 */
    CHECK_ERROR(_readMethod_bridge_change_bridge_limit(
        c, &method->bridge_change_bridge_limit))
    break;
  case 7942: /* module 31 call 6 */
    CHECK_ERROR(_readMethod_bridge_change_bridge_exempted(
        c, &method->bridge_change_bridge_exempted))
    break;
  case 7943: /* module 31 call 7 */
    CHECK_ERROR(_readMethod_bridge_force_handle_bridge_tx(
        c, &method->bridge_force_handle_bridge_tx))
    break;
  case 7944: /* module 31 call 8 */
    CHECK_ERROR(_readMethod_bridge_batch_propose_bridge_tx(
        c, &method->bridge_batch_propose_bridge_tx))
    break;
  case 7945: /* module 31 call 9 */
    CHECK_ERROR(_readMethod_bridge_propose_bridge_tx(
        c, &method->bridge_propose_bridge_tx))
    break;
  case 7946: /* module 31 call 10 */
    CHECK_ERROR(_readMethod_bridge_handle_bridge_tx(
        c, &method->bridge_handle_bridge_tx))
    break;
  case 7947: /* module 31 call 11 */
    CHECK_ERROR(_readMethod_bridge_freeze_txs(c, &method->bridge_freeze_txs))
    break;
  case 7948: /* module 31 call 12 */
    CHECK_ERROR(
        _readMethod_bridge_unfreeze_txs(c, &method->bridge_unfreeze_txs))
    break;
  case 7949: /* module 31 call 13 */
    CHECK_ERROR(_readMethod_bridge_handle_scheduled_bridge_tx(
        c, &method->bridge_handle_scheduled_bridge_tx))
    break;
  case 8192: /* module 32 call 0 */
    CHECK_ERROR(_readMethod_compliancemanager_add_compliance_requirement(
        c, &method->compliancemanager_add_compliance_requirement))
    break;
  case 8193: /* module 32 call 1 */
    CHECK_ERROR(_readMethod_compliancemanager_remove_compliance_requirement(
        c, &method->compliancemanager_remove_compliance_requirement))
    break;
  case 8194: /* module 32 call 2 */
    CHECK_ERROR(_readMethod_compliancemanager_replace_asset_compliance(
        c, &method->compliancemanager_replace_asset_compliance))
    break;
  case 8195: /* module 32 call 3 */
    CHECK_ERROR(_readMethod_compliancemanager_reset_asset_compliance(
        c, &method->compliancemanager_reset_asset_compliance))
    break;
  case 8196: /* module 32 call 4 */
    CHECK_ERROR(_readMethod_compliancemanager_pause_asset_compliance(
        c, &method->compliancemanager_pause_asset_compliance))
    break;
  case 8197: /* module 32 call 5 */
    CHECK_ERROR(_readMethod_compliancemanager_resume_asset_compliance(
        c, &method->compliancemanager_resume_asset_compliance))
    break;
  case 8198: /* module 32 call 6 */
    CHECK_ERROR(_readMethod_compliancemanager_add_default_trusted_claim_issuer(
        c, &method->compliancemanager_add_default_trusted_claim_issuer))
    break;
  case 8199: /* module 32 call 7 */
    CHECK_ERROR(
        _readMethod_compliancemanager_remove_default_trusted_claim_issuer(
            c, &method->compliancemanager_remove_default_trusted_claim_issuer))
    break;
  case 8200: /* module 32 call 8 */
    CHECK_ERROR(_readMethod_compliancemanager_change_compliance_requirement(
        c, &method->compliancemanager_change_compliance_requirement))
    break;
  case 8448: /* module 33 call 0 */
    CHECK_ERROR(_readMethod_voting_add_ballot(c, &method->voting_add_ballot))
    break;
  case 8449: /* module 33 call 1 */
    CHECK_ERROR(_readMethod_voting_vote(c, &method->voting_vote))
    break;
  case 8450: /* module 33 call 2 */
    CHECK_ERROR(
        _readMethod_voting_cancel_ballot(c, &method->voting_cancel_ballot))
    break;
  case 8704: /* module 34 call 0 */
    CHECK_ERROR(
        _readMethod_stocapped_launch_sto(c, &method->stocapped_launch_sto))
    break;
  case 8705: /* module 34 call 1 */
    CHECK_ERROR(
        _readMethod_stocapped_buy_tokens(c, &method->stocapped_buy_tokens))
    break;
  case 8706: /* module 34 call 2 */
    CHECK_ERROR(
        _readMethod_stocapped_pause_sto(c, &method->stocapped_pause_sto))
    break;
  case 8707: /* module 34 call 3 */
    CHECK_ERROR(
        _readMethod_stocapped_unpause_sto(c, &method->stocapped_unpause_sto))
    break;
  case 8960: /* module 35 call 0 */
    CHECK_ERROR(_readMethod_exemption_modify_exemption_list(
        c, &method->exemption_modify_exemption_list))
    break;
  case 9216: /* module 36 call 0 */
    CHECK_ERROR(_readMethod_settlement_create_venue(
        c, &method->settlement_create_venue))
    break;
  case 9217: /* module 36 call 1 */
    CHECK_ERROR(_readMethod_settlement_update_venue(
        c, &method->settlement_update_venue))
    break;
  case 9218: /* module 36 call 2 */
    CHECK_ERROR(_readMethod_settlement_add_instruction(
        c, &method->settlement_add_instruction))
    break;
  case 9219: /* module 36 call 3 */
    CHECK_ERROR(_readMethod_settlement_add_and_affirm_instruction(
        c, &method->settlement_add_and_affirm_instruction))
    break;
  case 9220: /* module 36 call 4 */
    CHECK_ERROR(_readMethod_settlement_affirm_instruction(
        c, &method->settlement_affirm_instruction))
    break;
  case 9221: /* module 36 call 5 */
    CHECK_ERROR(_readMethod_settlement_withdraw_affirmation(
        c, &method->settlement_withdraw_affirmation))
    break;
  case 9222: /* module 36 call 6 */
    CHECK_ERROR(_readMethod_settlement_reject_instruction(
        c, &method->settlement_reject_instruction))
    break;
  case 9223: /* module 36 call 7 */
    CHECK_ERROR(_readMethod_settlement_affirm_with_receipts(
        c, &method->settlement_affirm_with_receipts))
    break;
  case 9224: /* module 36 call 8 */
    CHECK_ERROR(_readMethod_settlement_claim_receipt(
        c, &method->settlement_claim_receipt))
    break;
  case 9225: /* module 36 call 9 */
    CHECK_ERROR(_readMethod_settlement_unclaim_receipt(
        c, &method->settlement_unclaim_receipt))
    break;
  case 9226: /* module 36 call 10 */
    CHECK_ERROR(_readMethod_settlement_set_venue_filtering(
        c, &method->settlement_set_venue_filtering))
    break;
  case 9227: /* module 36 call 11 */
    CHECK_ERROR(_readMethod_settlement_allow_venues(
        c, &method->settlement_allow_venues))
    break;
  case 9228: /* module 36 call 12 */
    CHECK_ERROR(_readMethod_settlement_disallow_venues(
        c, &method->settlement_disallow_venues))
    break;
  case 9229: /* module 36 call 13 */
    CHECK_ERROR(_readMethod_settlement_execute_scheduled_instruction(
        c, &method->settlement_execute_scheduled_instruction))
    break;
  case 9472: /* module 37 call 0 */
    CHECK_ERROR(
        _readMethod_sto_create_fundraiser(c, &method->sto_create_fundraiser))
    break;
  case 9473: /* module 37 call 1 */
    CHECK_ERROR(_readMethod_sto_invest(c, &method->sto_invest))
    break;
  case 9474: /* module 37 call 2 */
    CHECK_ERROR(
        _readMethod_sto_freeze_fundraiser(c, &method->sto_freeze_fundraiser))
    break;
  case 9475: /* module 37 call 3 */
    CHECK_ERROR(_readMethod_sto_unfreeze_fundraiser(
        c, &method->sto_unfreeze_fundraiser))
    break;
  case 9476: /* module 37 call 4 */
    CHECK_ERROR(_readMethod_sto_modify_fundraiser_window(
        c, &method->sto_modify_fundraiser_window))
    break;
  case 9477: /* module 37 call 5 */
    CHECK_ERROR(_readMethod_sto_stop(c, &method->sto_stop))
    break;
  case 9728: /* module 38 call 0 */
    CHECK_ERROR(_readMethod_cddserviceproviders_set_active_members_limit(
        c, &method->cddserviceproviders_set_active_members_limit))
    break;
  case 9729: /* module 38 call 1 */
    CHECK_ERROR(_readMethod_cddserviceproviders_disable_member(
        c, &method->cddserviceproviders_disable_member))
    break;
  case 9730: /* module 38 call 2 */
    CHECK_ERROR(_readMethod_cddserviceproviders_add_member(
        c, &method->cddserviceproviders_add_member))
    break;
  case 9731: /* module 38 call 3 */
    CHECK_ERROR(_readMethod_cddserviceproviders_remove_member(
        c, &method->cddserviceproviders_remove_member))
    break;
  case 9732: /* module 38 call 4 */
    CHECK_ERROR(_readMethod_cddserviceproviders_swap_member(
        c, &method->cddserviceproviders_swap_member))
    break;
  case 9733: /* module 38 call 5 */
    CHECK_ERROR(_readMethod_cddserviceproviders_reset_members(
        c, &method->cddserviceproviders_reset_members))
    break;
  case 9734: /* module 38 call 6 */
    CHECK_ERROR(_readMethod_cddserviceproviders_abdicate_membership(
        c, &method->cddserviceproviders_abdicate_membership))
    break;
  case 10240: /* module 40 call 0 */
    CHECK_ERROR(_readMethod_protocolfee_change_coefficient(
        c, &method->protocolfee_change_coefficient))
    break;
  case 10241: /* module 40 call 1 */
    CHECK_ERROR(_readMethod_protocolfee_change_base_fee(
        c, &method->protocolfee_change_base_fee))
    break;
  case 10496: /* module 41 call 0 */
    CHECK_ERROR(_readMethod_utility_batch(c, &method->utility_batch))
    break;
  case 10497: /* module 41 call 1 */
    CHECK_ERROR(
        _readMethod_utility_batch_atomic(c, &method->utility_batch_atomic))
    break;
  case 10498: /* module 41 call 2 */
    CHECK_ERROR(_readMethod_utility_batch_optimistic(
        c, &method->utility_batch_optimistic))
    break;
  case 10499: /* module 41 call 3 */
    CHECK_ERROR(_readMethod_utility_relay_tx(c, &method->utility_relay_tx))
    break;
  case 10752: /* module 42 call 0 */
    CHECK_ERROR(_readMethod_portfolio_create_portfolio(
        c, &method->portfolio_create_portfolio))
    break;
  case 10753: /* module 42 call 1 */
    CHECK_ERROR(_readMethod_portfolio_delete_portfolio(
        c, &method->portfolio_delete_portfolio))
    break;
  case 10754: /* module 42 call 2 */
    CHECK_ERROR(_readMethod_portfolio_move_portfolio_funds(
        c, &method->portfolio_move_portfolio_funds))
    break;
  case 10755: /* module 42 call 3 */
    CHECK_ERROR(_readMethod_portfolio_rename_portfolio(
        c, &method->portfolio_rename_portfolio))
    break;
  case 11008: /* module 43 call 0 */
    CHECK_ERROR(_readMethod_confidential_add_range_proof(
        c, &method->confidential_add_range_proof))
    break;
  case 11009: /* module 43 call 1 */
    CHECK_ERROR(_readMethod_confidential_add_verify_range_proof(
        c, &method->confidential_add_verify_range_proof))
    break;
  case 11520: /* module 45 call 0 */
    CHECK_ERROR(_readMethod_scheduler_schedule(c, &method->scheduler_schedule))
    break;
  case 11521: /* module 45 call 1 */
    CHECK_ERROR(_readMethod_scheduler_cancel(c, &method->scheduler_cancel))
    break;
  case 11522: /* module 45 call 2 */
    CHECK_ERROR(_readMethod_scheduler_schedule_named(
        c, &method->scheduler_schedule_named))
    break;
  case 11523: /* module 45 call 3 */
    CHECK_ERROR(
        _readMethod_scheduler_cancel_named(c, &method->scheduler_cancel_named))
    break;
  case 11524: /* module 45 call 4 */
    CHECK_ERROR(_readMethod_scheduler_schedule_after(
        c, &method->scheduler_schedule_after))
    break;
  case 11525: /* module 45 call 5 */
    CHECK_ERROR(_readMethod_scheduler_schedule_named_after(
        c, &method->scheduler_schedule_named_after))
    break;
  case 11776: /* module 46 call 0 */
    CHECK_ERROR(_readMethod_corporateaction_set_max_details_length(
        c, &method->corporateaction_set_max_details_length))
    break;
  case 11777: /* module 46 call 1 */
    CHECK_ERROR(_readMethod_corporateaction_reset_caa(
        c, &method->corporateaction_reset_caa))
    break;
  case 11778: /* module 46 call 2 */
    CHECK_ERROR(_readMethod_corporateaction_set_default_targets(
        c, &method->corporateaction_set_default_targets))
    break;
  case 11779: /* module 46 call 3 */
    CHECK_ERROR(_readMethod_corporateaction_set_default_withholding_tax(
        c, &method->corporateaction_set_default_withholding_tax))
    break;
  case 11780: /* module 46 call 4 */
    CHECK_ERROR(_readMethod_corporateaction_set_did_withholding_tax(
        c, &method->corporateaction_set_did_withholding_tax))
    break;
  case 11781: /* module 46 call 5 */
    CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action(
        c, &method->corporateaction_initiate_corporate_action))
    break;
  case 11782: /* module 46 call 6 */
    CHECK_ERROR(_readMethod_corporateaction_link_ca_doc(
        c, &method->corporateaction_link_ca_doc))
    break;
  case 11783: /* module 46 call 7 */
    CHECK_ERROR(_readMethod_corporateaction_remove_ca(
        c, &method->corporateaction_remove_ca))
    break;
  case 11784: /* module 46 call 8 */
    CHECK_ERROR(_readMethod_corporateaction_change_record_date(
        c, &method->corporateaction_change_record_date))
    break;
  case 12032: /* module 47 call 0 */
    CHECK_ERROR(_readMethod_corporateballot_attach_ballot(
        c, &method->corporateballot_attach_ballot))
    break;
  case 12033: /* module 47 call 1 */
    CHECK_ERROR(
        _readMethod_corporateballot_vote(c, &method->corporateballot_vote))
    break;
  case 12034: /* module 47 call 2 */
    CHECK_ERROR(_readMethod_corporateballot_change_end(
        c, &method->corporateballot_change_end))
    break;
  case 12035: /* module 47 call 3 */
    CHECK_ERROR(_readMethod_corporateballot_change_meta(
        c, &method->corporateballot_change_meta))
    break;
  case 12036: /* module 47 call 4 */
    CHECK_ERROR(_readMethod_corporateballot_change_rcv(
        c, &method->corporateballot_change_rcv))
    break;
  case 12037: /* module 47 call 5 */
    CHECK_ERROR(_readMethod_corporateballot_remove_ballot(
        c, &method->corporateballot_remove_ballot))
    break;
  case 12288: /* module 48 call 0 */
    CHECK_ERROR(_readMethod_capitaldistribution_distribute(
        c, &method->capitaldistribution_distribute))
    break;
  case 12289: /* module 48 call 1 */
    CHECK_ERROR(_readMethod_capitaldistribution_claim(
        c, &method->capitaldistribution_claim))
    break;
  case 12290: /* module 48 call 2 */
    CHECK_ERROR(_readMethod_capitaldistribution_push_benefit(
        c, &method->capitaldistribution_push_benefit))
    break;
  case 12291: /* module 48 call 3 */
    CHECK_ERROR(_readMethod_capitaldistribution_reclaim(
        c, &method->capitaldistribution_reclaim))
    break;
  case 12292: /* module 48 call 4 */
    CHECK_ERROR(_readMethod_capitaldistribution_remove_distribution(
        c, &method->capitaldistribution_remove_distribution))
    break;
  case 12544: /* module 49 call 0 */
    CHECK_ERROR(_readMethod_checkpoint_create_checkpoint(
        c, &method->checkpoint_create_checkpoint))
    break;
  case 12545: /* module 49 call 1 */
    CHECK_ERROR(_readMethod_checkpoint_set_schedules_max_complexity(
        c, &method->checkpoint_set_schedules_max_complexity))
    break;
  case 12546: /* module 49 call 2 */
    CHECK_ERROR(_readMethod_checkpoint_create_schedule(
        c, &method->checkpoint_create_schedule))
    break;
  case 12547: /* module 49 call 3 */
    CHECK_ERROR(_readMethod_checkpoint_remove_schedule(
        c, &method->checkpoint_remove_schedule))
    break;
  default:
    return parser_unexpected_callIndex;
  }

  return parser_ok;
}

parser_error_t _readMethod(parser_context_t *c, uint8_t moduleIdx,
                           uint8_t callIdx, pd_Method_t *method) {
  uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

  switch (callPrivIdx) {
  case 0: /* module 0 call 0 */
    CHECK_ERROR(
        _readMethod_system_fill_block(c, &method->basic.system_fill_block))
    break;
  case 1: /* module 0 call 1 */
    CHECK_ERROR(_readMethod_system_remark(c, &method->basic.system_remark))
    break;
  case 2: /* module 0 call 2 */
    CHECK_ERROR(_readMethod_system_set_heap_pages(
        c, &method->basic.system_set_heap_pages))
    break;
  case 3: /* module 0 call 3 */
    CHECK_ERROR(_readMethod_system_set_code(c, &method->basic.system_set_code))
    break;
  case 4: /* module 0 call 4 */
    CHECK_ERROR(_readMethod_system_set_code_without_checks(
        c, &method->basic.system_set_code_without_checks))
    break;
  case 5: /* module 0 call 5 */
    CHECK_ERROR(_readMethod_system_set_changes_trie_config(
        c, &method->basic.system_set_changes_trie_config))
    break;
  case 6: /* module 0 call 6 */
    CHECK_ERROR(
        _readMethod_system_set_storage(c, &method->basic.system_set_storage))
    break;
  case 7: /* module 0 call 7 */
    CHECK_ERROR(
        _readMethod_system_kill_storage(c, &method->basic.system_kill_storage))
    break;
  case 8: /* module 0 call 8 */
    CHECK_ERROR(
        _readMethod_system_kill_prefix(c, &method->basic.system_kill_prefix))
    break;
  case 9: /* module 0 call 9 */
    CHECK_ERROR(_readMethod_system_suicide(c, &method->basic.system_suicide))
    break;
  case 256: /* module 1 call 0 */
    CHECK_ERROR(_readMethod_babe_report_equivocation(
        c, &method->basic.babe_report_equivocation))
    break;
  case 257: /* module 1 call 1 */
    CHECK_ERROR(_readMethod_babe_report_equivocation_unsigned(
        c, &method->basic.babe_report_equivocation_unsigned))
    break;
  case 512: /* module 2 call 0 */
    CHECK_ERROR(_readMethod_timestamp_set(c, &method->basic.timestamp_set))
    break;
  case 768: /* module 3 call 0 */
    CHECK_ERROR(_readMethod_indices_claim(c, &method->basic.indices_claim))
    break;
  case 769: /* module 3 call 1 */
    CHECK_ERROR(
        _readMethod_indices_transfer(c, &method->basic.indices_transfer))
    break;
  case 770: /* module 3 call 2 */
    CHECK_ERROR(_readMethod_indices_free(c, &method->basic.indices_free))
    break;
  case 771: /* module 3 call 3 */
    CHECK_ERROR(_readMethod_indices_force_transfer(
        c, &method->basic.indices_force_transfer))
    break;
  case 772: /* module 3 call 4 */
    CHECK_ERROR(_readMethod_indices_freeze(c, &method->basic.indices_freeze))
    break;
  case 1024: /* module 4 call 0 */
    CHECK_ERROR(
        _readMethod_balances_transfer(c, &method->basic.balances_transfer))
    break;
  case 1025: /* module 4 call 1 */
    CHECK_ERROR(_readMethod_balances_transfer_with_memo(
        c, &method->basic.balances_transfer_with_memo))
    break;
  case 1026: /* module 4 call 2 */
    CHECK_ERROR(_readMethod_balances_deposit_block_reward_reserve_balance(
        c, &method->basic.balances_deposit_block_reward_reserve_balance))
    break;
  case 1027: /* module 4 call 3 */
    CHECK_ERROR(_readMethod_balances_set_balance(
        c, &method->basic.balances_set_balance))
    break;
  case 1028: /* module 4 call 4 */
    CHECK_ERROR(_readMethod_balances_force_transfer(
        c, &method->basic.balances_force_transfer))
    break;
  case 1029: /* module 4 call 5 */
    CHECK_ERROR(_readMethod_balances_burn_account_balance(
        c, &method->basic.balances_burn_account_balance))
    break;
  case 1536: /* module 6 call 0 */
    CHECK_ERROR(_readMethod_authorship_set_uncles(
        c, &method->basic.authorship_set_uncles))
    break;
  case 1792: /* module 7 call 0 */
    CHECK_ERROR(_readMethod_staking_bond(c, &method->basic.staking_bond))
    break;
  case 1793: /* module 7 call 1 */
    CHECK_ERROR(
        _readMethod_staking_bond_extra(c, &method->basic.staking_bond_extra))
    break;
  case 1794: /* module 7 call 2 */
    CHECK_ERROR(_readMethod_staking_unbond(c, &method->basic.staking_unbond))
    break;
  case 1795: /* module 7 call 3 */
    CHECK_ERROR(_readMethod_staking_withdraw_unbonded(
        c, &method->basic.staking_withdraw_unbonded))
    break;
  case 1796: /* module 7 call 4 */
    CHECK_ERROR(
        _readMethod_staking_validate(c, &method->basic.staking_validate))
    break;
  case 1797: /* module 7 call 5 */
    CHECK_ERROR(
        _readMethod_staking_nominate(c, &method->basic.staking_nominate))
    break;
  case 1798: /* module 7 call 6 */
    CHECK_ERROR(_readMethod_staking_chill(c, &method->basic.staking_chill))
    break;
  case 1799: /* module 7 call 7 */
    CHECK_ERROR(
        _readMethod_staking_set_payee(c, &method->basic.staking_set_payee))
    break;
  case 1800: /* module 7 call 8 */
    CHECK_ERROR(_readMethod_staking_set_controller(
        c, &method->basic.staking_set_controller))
    break;
  case 1801: /* module 7 call 9 */
    CHECK_ERROR(_readMethod_staking_set_validator_count(
        c, &method->basic.staking_set_validator_count))
    break;
  case 1802: /* module 7 call 10 */
    CHECK_ERROR(_readMethod_staking_increase_validator_count(
        c, &method->basic.staking_increase_validator_count))
    break;
  case 1803: /* module 7 call 11 */
    CHECK_ERROR(_readMethod_staking_scale_validator_count(
        c, &method->basic.staking_scale_validator_count))
    break;
  case 1804: /* module 7 call 12 */
    CHECK_ERROR(_readMethod_staking_add_permissioned_validator(
        c, &method->basic.staking_add_permissioned_validator))
    break;
  case 1805: /* module 7 call 13 */
    CHECK_ERROR(_readMethod_staking_remove_permissioned_validator(
        c, &method->basic.staking_remove_permissioned_validator))
    break;
  case 1806: /* module 7 call 14 */
    CHECK_ERROR(_readMethod_staking_validate_cdd_expiry_nominators(
        c, &method->basic.staking_validate_cdd_expiry_nominators))
    break;
  case 1807: /* module 7 call 15 */
    CHECK_ERROR(_readMethod_staking_set_commission_cap(
        c, &method->basic.staking_set_commission_cap))
    break;
  case 1808: /* module 7 call 16 */
    CHECK_ERROR(_readMethod_staking_set_min_bond_threshold(
        c, &method->basic.staking_set_min_bond_threshold))
    break;
  case 1809: /* module 7 call 17 */
    CHECK_ERROR(_readMethod_staking_force_no_eras(
        c, &method->basic.staking_force_no_eras))
    break;
  case 1810: /* module 7 call 18 */
    CHECK_ERROR(_readMethod_staking_force_new_era(
        c, &method->basic.staking_force_new_era))
    break;
  case 1811: /* module 7 call 19 */
    CHECK_ERROR(_readMethod_staking_set_invulnerables(
        c, &method->basic.staking_set_invulnerables))
    break;
  case 1812: /* module 7 call 20 */
    CHECK_ERROR(_readMethod_staking_force_unstake(
        c, &method->basic.staking_force_unstake))
    break;
  case 1813: /* module 7 call 21 */
    CHECK_ERROR(_readMethod_staking_force_new_era_always(
        c, &method->basic.staking_force_new_era_always))
    break;
  case 1814: /* module 7 call 22 */
    CHECK_ERROR(_readMethod_staking_cancel_deferred_slash(
        c, &method->basic.staking_cancel_deferred_slash))
    break;
  case 1815: /* module 7 call 23 */
    CHECK_ERROR(_readMethod_staking_payout_stakers(
        c, &method->basic.staking_payout_stakers))
    break;
  case 1816: /* module 7 call 24 */
    CHECK_ERROR(_readMethod_staking_rebond(c, &method->basic.staking_rebond))
    break;
  case 1817: /* module 7 call 25 */
    CHECK_ERROR(_readMethod_staking_set_history_depth(
        c, &method->basic.staking_set_history_depth))
    break;
  case 1818: /* module 7 call 26 */
    CHECK_ERROR(
        _readMethod_staking_reap_stash(c, &method->basic.staking_reap_stash))
    break;
  case 1819: /* module 7 call 27 */
    CHECK_ERROR(_readMethod_staking_submit_election_solution(
        c, &method->basic.staking_submit_election_solution))
    break;
  case 1820: /* module 7 call 28 */
    CHECK_ERROR(_readMethod_staking_submit_election_solution_unsigned(
        c, &method->basic.staking_submit_election_solution_unsigned))
    break;
  case 1821: /* module 7 call 29 */
    CHECK_ERROR(_readMethod_staking_payout_stakers_by_system(
        c, &method->basic.staking_payout_stakers_by_system))
    break;
  case 1822: /* module 7 call 30 */
    CHECK_ERROR(_readMethod_staking_change_slashing_allowed_for(
        c, &method->basic.staking_change_slashing_allowed_for))
    break;
  case 2304: /* module 9 call 0 */
    CHECK_ERROR(
        _readMethod_session_set_keys(c, &method->basic.session_set_keys))
    break;
  case 2305: /* module 9 call 1 */
    CHECK_ERROR(
        _readMethod_session_purge_keys(c, &method->basic.session_purge_keys))
    break;
  case 2560: /* module 10 call 0 */
    CHECK_ERROR(_readMethod_finalitytracker_final_hint(
        c, &method->basic.finalitytracker_final_hint))
    break;
  case 2816: /* module 11 call 0 */
    CHECK_ERROR(_readMethod_grandpa_report_equivocation(
        c, &method->basic.grandpa_report_equivocation))
    break;
  case 2817: /* module 11 call 1 */
    CHECK_ERROR(_readMethod_grandpa_report_equivocation_unsigned(
        c, &method->basic.grandpa_report_equivocation_unsigned))
    break;
  case 2818: /* module 11 call 2 */
    CHECK_ERROR(_readMethod_grandpa_note_stalled(
        c, &method->basic.grandpa_note_stalled))
    break;
  case 3072: /* module 12 call 0 */
    CHECK_ERROR(
        _readMethod_imonline_heartbeat(c, &method->basic.imonline_heartbeat))
    break;
  case 3073: /* module 12 call 1 */
    CHECK_ERROR(_readMethod_imonline_set_slashing_params(
        c, &method->basic.imonline_set_slashing_params))
    break;
  case 4096: /* module 16 call 0 */
    CHECK_ERROR(_readMethod_sudo_sudo(c, &method->basic.sudo_sudo))
    break;
  case 4097: /* module 16 call 1 */
    CHECK_ERROR(_readMethod_sudo_sudo_unchecked_weight(
        c, &method->basic.sudo_sudo_unchecked_weight))
    break;
  case 4098: /* module 16 call 2 */
    CHECK_ERROR(_readMethod_sudo_set_key(c, &method->basic.sudo_set_key))
    break;
  case 4099: /* module 16 call 3 */
    CHECK_ERROR(_readMethod_sudo_sudo_as(c, &method->basic.sudo_sudo_as))
    break;
  case 4352: /* module 17 call 0 */
    CHECK_ERROR(_readMethod_multisig_create_multisig(
        c, &method->basic.multisig_create_multisig))
    break;
  case 4353: /* module 17 call 1 */
    CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_identity(
        c, &method->nested.multisig_create_or_approve_proposal_as_identity))
    break;
  case 4354: /* module 17 call 2 */
    CHECK_ERROR(_readMethod_multisig_create_or_approve_proposal_as_key(
        c, &method->nested.multisig_create_or_approve_proposal_as_key))
    break;
  case 4355: /* module 17 call 3 */
    CHECK_ERROR(_readMethod_multisig_create_proposal_as_identity(
        c, &method->nested.multisig_create_proposal_as_identity))
    break;
  case 4356: /* module 17 call 4 */
    CHECK_ERROR(_readMethod_multisig_create_proposal_as_key(
        c, &method->nested.multisig_create_proposal_as_key))
    break;
  case 4357: /* module 17 call 5 */
    CHECK_ERROR(_readMethod_multisig_approve_as_identity(
        c, &method->basic.multisig_approve_as_identity))
    break;
  case 4358: /* module 17 call 6 */
    CHECK_ERROR(_readMethod_multisig_approve_as_key(
        c, &method->basic.multisig_approve_as_key))
    break;
  case 4359: /* module 17 call 7 */
    CHECK_ERROR(_readMethod_multisig_reject_as_identity(
        c, &method->basic.multisig_reject_as_identity))
    break;
  case 4360: /* module 17 call 8 */
    CHECK_ERROR(_readMethod_multisig_reject_as_key(
        c, &method->basic.multisig_reject_as_key))
    break;
  case 4361: /* module 17 call 9 */
    CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_identity(
        c, &method->basic.multisig_accept_multisig_signer_as_identity))
    break;
  case 4362: /* module 17 call 10 */
    CHECK_ERROR(_readMethod_multisig_accept_multisig_signer_as_key(
        c, &method->basic.multisig_accept_multisig_signer_as_key))
    break;
  case 4363: /* module 17 call 11 */
    CHECK_ERROR(_readMethod_multisig_add_multisig_signer(
        c, &method->basic.multisig_add_multisig_signer))
    break;
  case 4364: /* module 17 call 12 */
    CHECK_ERROR(_readMethod_multisig_remove_multisig_signer(
        c, &method->basic.multisig_remove_multisig_signer))
    break;
  case 4365: /* module 17 call 13 */
    CHECK_ERROR(_readMethod_multisig_add_multisig_signers_via_creator(
        c, &method->basic.multisig_add_multisig_signers_via_creator))
    break;
  case 4366: /* module 17 call 14 */
    CHECK_ERROR(_readMethod_multisig_remove_multisig_signers_via_creator(
        c, &method->basic.multisig_remove_multisig_signers_via_creator))
    break;
  case 4367: /* module 17 call 15 */
    CHECK_ERROR(_readMethod_multisig_change_sigs_required(
        c, &method->basic.multisig_change_sigs_required))
    break;
  case 4368: /* module 17 call 16 */
    CHECK_ERROR(_readMethod_multisig_change_all_signers_and_sigs_required(
        c, &method->basic.multisig_change_all_signers_and_sigs_required))
    break;
  case 4369: /* module 17 call 17 */
    CHECK_ERROR(_readMethod_multisig_make_multisig_signer(
        c, &method->basic.multisig_make_multisig_signer))
    break;
  case 4370: /* module 17 call 18 */
    CHECK_ERROR(_readMethod_multisig_make_multisig_primary(
        c, &method->basic.multisig_make_multisig_primary))
    break;
  case 4864: /* module 19 call 0 */
    CHECK_ERROR(_readMethod_contracts_update_schedule(
        c, &method->basic.contracts_update_schedule))
    break;
  case 4865: /* module 19 call 1 */
    CHECK_ERROR(
        _readMethod_contracts_put_code(c, &method->basic.contracts_put_code))
    break;
  case 4866: /* module 19 call 2 */
    CHECK_ERROR(_readMethod_contracts_call(c, &method->basic.contracts_call))
    break;
  case 4867: /* module 19 call 3 */
    CHECK_ERROR(_readMethod_contracts_instantiate(
        c, &method->basic.contracts_instantiate))
    break;
  case 4868: /* module 19 call 4 */
    CHECK_ERROR(_readMethod_contracts_freeze_instantiation(
        c, &method->basic.contracts_freeze_instantiation))
    break;
  case 4869: /* module 19 call 5 */
    CHECK_ERROR(_readMethod_contracts_unfreeze_instantiation(
        c, &method->basic.contracts_unfreeze_instantiation))
    break;
  case 4870: /* module 19 call 6 */
    CHECK_ERROR(_readMethod_contracts_transfer_template_ownership(
        c, &method->basic.contracts_transfer_template_ownership))
    break;
  case 4871: /* module 19 call 7 */
    CHECK_ERROR(_readMethod_contracts_change_template_fees(
        c, &method->basic.contracts_change_template_fees))
    break;
  case 4872: /* module 19 call 8 */
    CHECK_ERROR(_readMethod_contracts_change_template_meta_url(
        c, &method->basic.contracts_change_template_meta_url))
    break;
  case 5120: /* module 20 call 0 */
    CHECK_ERROR(_readMethod_treasury_disbursement(
        c, &method->basic.treasury_disbursement))
    break;
  case 5121: /* module 20 call 1 */
    CHECK_ERROR(_readMethod_treasury_reimbursement(
        c, &method->basic.treasury_reimbursement))
    break;
  case 5376: /* module 21 call 0 */
    CHECK_ERROR(_readMethod_polymeshcommittee_set_vote_threshold(
        c, &method->basic.polymeshcommittee_set_vote_threshold))
    break;
  case 5377: /* module 21 call 1 */
    CHECK_ERROR(_readMethod_polymeshcommittee_set_release_coordinator(
        c, &method->basic.polymeshcommittee_set_release_coordinator))
    break;
  case 5378: /* module 21 call 2 */
    CHECK_ERROR(_readMethod_polymeshcommittee_set_expires_after(
        c, &method->basic.polymeshcommittee_set_expires_after))
    break;
  case 5379: /* module 21 call 3 */
    CHECK_ERROR(_readMethod_polymeshcommittee_close(
        c, &method->basic.polymeshcommittee_close))
    break;
  case 5380: /* module 21 call 4 */
    CHECK_ERROR(_readMethod_polymeshcommittee_vote_or_propose(
        c, &method->nested.polymeshcommittee_vote_or_propose))
    break;
  case 5381: /* module 21 call 5 */
    CHECK_ERROR(_readMethod_polymeshcommittee_vote(
        c, &method->basic.polymeshcommittee_vote))
    break;
  case 5632: /* module 22 call 0 */
    CHECK_ERROR(_readMethod_committeemembership_set_active_members_limit(
        c, &method->basic.committeemembership_set_active_members_limit))
    break;
  case 5633: /* module 22 call 1 */
    CHECK_ERROR(_readMethod_committeemembership_disable_member(
        c, &method->basic.committeemembership_disable_member))
    break;
  case 5634: /* module 22 call 2 */
    CHECK_ERROR(_readMethod_committeemembership_add_member(
        c, &method->basic.committeemembership_add_member))
    break;
  case 5635: /* module 22 call 3 */
    CHECK_ERROR(_readMethod_committeemembership_remove_member(
        c, &method->basic.committeemembership_remove_member))
    break;
  case 5636: /* module 22 call 4 */
    CHECK_ERROR(_readMethod_committeemembership_swap_member(
        c, &method->basic.committeemembership_swap_member))
    break;
  case 5637: /* module 22 call 5 */
    CHECK_ERROR(_readMethod_committeemembership_reset_members(
        c, &method->basic.committeemembership_reset_members))
    break;
  case 5638: /* module 22 call 6 */
    CHECK_ERROR(_readMethod_committeemembership_abdicate_membership(
        c, &method->basic.committeemembership_abdicate_membership))
    break;
  case 5888: /* module 23 call 0 */
    CHECK_ERROR(_readMethod_pips_set_prune_historical_pips(
        c, &method->basic.pips_set_prune_historical_pips))
    break;
  case 5889: /* module 23 call 1 */
    CHECK_ERROR(_readMethod_pips_set_min_proposal_deposit(
        c, &method->basic.pips_set_min_proposal_deposit))
    break;
  case 5890: /* module 23 call 2 */
    CHECK_ERROR(_readMethod_pips_set_proposal_cool_off_period(
        c, &method->basic.pips_set_proposal_cool_off_period))
    break;
  case 5891: /* module 23 call 3 */
    CHECK_ERROR(_readMethod_pips_set_default_enactment_period(
        c, &method->basic.pips_set_default_enactment_period))
    break;
  case 5892: /* module 23 call 4 */
    CHECK_ERROR(_readMethod_pips_set_pending_pip_expiry(
        c, &method->basic.pips_set_pending_pip_expiry))
    break;
  case 5893: /* module 23 call 5 */
    CHECK_ERROR(_readMethod_pips_set_max_pip_skip_count(
        c, &method->basic.pips_set_max_pip_skip_count))
    break;
  case 5894: /* module 23 call 6 */
    CHECK_ERROR(_readMethod_pips_set_active_pip_limit(
        c, &method->basic.pips_set_active_pip_limit))
    break;
  case 5895: /* module 23 call 7 */
    CHECK_ERROR(_readMethod_pips_propose(c, &method->nested.pips_propose))
    break;
  case 5896: /* module 23 call 8 */
    CHECK_ERROR(
        _readMethod_pips_amend_proposal(c, &method->basic.pips_amend_proposal))
    break;
  case 5897: /* module 23 call 9 */
    CHECK_ERROR(_readMethod_pips_cancel_proposal(
        c, &method->basic.pips_cancel_proposal))
    break;
  case 5898: /* module 23 call 10 */
    CHECK_ERROR(_readMethod_pips_vote(c, &method->basic.pips_vote))
    break;
  case 5899: /* module 23 call 11 */
    CHECK_ERROR(_readMethod_pips_approve_committee_proposal(
        c, &method->basic.pips_approve_committee_proposal))
    break;
  case 5900: /* module 23 call 12 */
    CHECK_ERROR(_readMethod_pips_reject_proposal(
        c, &method->basic.pips_reject_proposal))
    break;
  case 5901: /* module 23 call 13 */
    CHECK_ERROR(
        _readMethod_pips_prune_proposal(c, &method->basic.pips_prune_proposal))
    break;
  case 5902: /* module 23 call 14 */
    CHECK_ERROR(_readMethod_pips_reschedule_execution(
        c, &method->basic.pips_reschedule_execution))
    break;
  case 5903: /* module 23 call 15 */
    CHECK_ERROR(
        _readMethod_pips_clear_snapshot(c, &method->basic.pips_clear_snapshot))
    break;
  case 5904: /* module 23 call 16 */
    CHECK_ERROR(_readMethod_pips_snapshot(c, &method->basic.pips_snapshot))
    break;
  case 5905: /* module 23 call 17 */
    CHECK_ERROR(_readMethod_pips_enact_snapshot_results(
        c, &method->basic.pips_enact_snapshot_results))
    break;
  case 5906: /* module 23 call 18 */
    CHECK_ERROR(_readMethod_pips_execute_scheduled_pip(
        c, &method->basic.pips_execute_scheduled_pip))
    break;
  case 5907: /* module 23 call 19 */
    CHECK_ERROR(_readMethod_pips_expire_scheduled_pip(
        c, &method->basic.pips_expire_scheduled_pip))
    break;
  case 6144: /* module 24 call 0 */
    CHECK_ERROR(_readMethod_technicalcommittee_set_vote_threshold(
        c, &method->basic.technicalcommittee_set_vote_threshold))
    break;
  case 6145: /* module 24 call 1 */
    CHECK_ERROR(_readMethod_technicalcommittee_set_release_coordinator(
        c, &method->basic.technicalcommittee_set_release_coordinator))
    break;
  case 6146: /* module 24 call 2 */
    CHECK_ERROR(_readMethod_technicalcommittee_set_expires_after(
        c, &method->basic.technicalcommittee_set_expires_after))
    break;
  case 6147: /* module 24 call 3 */
    CHECK_ERROR(_readMethod_technicalcommittee_close(
        c, &method->basic.technicalcommittee_close))
    break;
  case 6148: /* module 24 call 4 */
    CHECK_ERROR(_readMethod_technicalcommittee_vote_or_propose(
        c, &method->nested.technicalcommittee_vote_or_propose))
    break;
  case 6149: /* module 24 call 5 */
    CHECK_ERROR(_readMethod_technicalcommittee_vote(
        c, &method->basic.technicalcommittee_vote))
    break;
  case 6400: /* module 25 call 0 */
    CHECK_ERROR(
        _readMethod_technicalcommitteemembership_set_active_members_limit(
            c, &method->basic
                    .technicalcommitteemembership_set_active_members_limit))
    break;
  case 6401: /* module 25 call 1 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_disable_member(
        c, &method->basic.technicalcommitteemembership_disable_member))
    break;
  case 6402: /* module 25 call 2 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_add_member(
        c, &method->basic.technicalcommitteemembership_add_member))
    break;
  case 6403: /* module 25 call 3 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_remove_member(
        c, &method->basic.technicalcommitteemembership_remove_member))
    break;
  case 6404: /* module 25 call 4 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_swap_member(
        c, &method->basic.technicalcommitteemembership_swap_member))
    break;
  case 6405: /* module 25 call 5 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_reset_members(
        c, &method->basic.technicalcommitteemembership_reset_members))
    break;
  case 6406: /* module 25 call 6 */
    CHECK_ERROR(_readMethod_technicalcommitteemembership_abdicate_membership(
        c, &method->basic.technicalcommitteemembership_abdicate_membership))
    break;
  case 6656: /* module 26 call 0 */
    CHECK_ERROR(_readMethod_upgradecommittee_set_vote_threshold(
        c, &method->basic.upgradecommittee_set_vote_threshold))
    break;
  case 6657: /* module 26 call 1 */
    CHECK_ERROR(_readMethod_upgradecommittee_set_release_coordinator(
        c, &method->basic.upgradecommittee_set_release_coordinator))
    break;
  case 6658: /* module 26 call 2 */
    CHECK_ERROR(_readMethod_upgradecommittee_set_expires_after(
        c, &method->basic.upgradecommittee_set_expires_after))
    break;
  case 6659: /* module 26 call 3 */
    CHECK_ERROR(_readMethod_upgradecommittee_close(
        c, &method->basic.upgradecommittee_close))
    break;
  case 6660: /* module 26 call 4 */
    CHECK_ERROR(_readMethod_upgradecommittee_vote_or_propose(
        c, &method->nested.upgradecommittee_vote_or_propose))
    break;
  case 6661: /* module 26 call 5 */
    CHECK_ERROR(_readMethod_upgradecommittee_vote(
        c, &method->basic.upgradecommittee_vote))
    break;
  case 6912: /* module 27 call 0 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_set_active_members_limit(
        c, &method->basic.upgradecommitteemembership_set_active_members_limit))
    break;
  case 6913: /* module 27 call 1 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_disable_member(
        c, &method->basic.upgradecommitteemembership_disable_member))
    break;
  case 6914: /* module 27 call 2 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_add_member(
        c, &method->basic.upgradecommitteemembership_add_member))
    break;
  case 6915: /* module 27 call 3 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_remove_member(
        c, &method->basic.upgradecommitteemembership_remove_member))
    break;
  case 6916: /* module 27 call 4 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_swap_member(
        c, &method->basic.upgradecommitteemembership_swap_member))
    break;
  case 6917: /* module 27 call 5 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_reset_members(
        c, &method->basic.upgradecommitteemembership_reset_members))
    break;
  case 6918: /* module 27 call 6 */
    CHECK_ERROR(_readMethod_upgradecommitteemembership_abdicate_membership(
        c, &method->basic.upgradecommitteemembership_abdicate_membership))
    break;
  case 7168: /* module 28 call 0 */
    CHECK_ERROR(_readMethod_asset_register_ticker(
        c, &method->basic.asset_register_ticker))
    break;
  case 7169: /* module 28 call 1 */
    CHECK_ERROR(_readMethod_asset_accept_ticker_transfer(
        c, &method->basic.asset_accept_ticker_transfer))
    break;
  case 7170: /* module 28 call 2 */
    CHECK_ERROR(_readMethod_asset_accept_primary_issuance_agent_transfer(
        c, &method->basic.asset_accept_primary_issuance_agent_transfer))
    break;
  case 7171: /* module 28 call 3 */
    CHECK_ERROR(_readMethod_asset_accept_asset_ownership_transfer(
        c, &method->basic.asset_accept_asset_ownership_transfer))
    break;
  case 7172: /* module 28 call 4 */
    CHECK_ERROR(
        _readMethod_asset_create_asset(c, &method->basic.asset_create_asset))
    break;
  case 7173: /* module 28 call 5 */
    CHECK_ERROR(_readMethod_asset_freeze(c, &method->basic.asset_freeze))
    break;
  case 7174: /* module 28 call 6 */
    CHECK_ERROR(_readMethod_asset_unfreeze(c, &method->basic.asset_unfreeze))
    break;
  case 7175: /* module 28 call 7 */
    CHECK_ERROR(
        _readMethod_asset_rename_asset(c, &method->basic.asset_rename_asset))
    break;
  case 7176: /* module 28 call 8 */
    CHECK_ERROR(_readMethod_asset_issue(c, &method->basic.asset_issue))
    break;
  case 7177: /* module 28 call 9 */
    CHECK_ERROR(_readMethod_asset_redeem(c, &method->basic.asset_redeem))
    break;
  case 7178: /* module 28 call 10 */
    CHECK_ERROR(_readMethod_asset_make_divisible(
        c, &method->basic.asset_make_divisible))
    break;
  case 7179: /* module 28 call 11 */
    CHECK_ERROR(
        _readMethod_asset_add_documents(c, &method->basic.asset_add_documents))
    break;
  case 7180: /* module 28 call 12 */
    CHECK_ERROR(_readMethod_asset_remove_documents(
        c, &method->basic.asset_remove_documents))
    break;
  case 7181: /* module 28 call 13 */
    CHECK_ERROR(_readMethod_asset_set_funding_round(
        c, &method->basic.asset_set_funding_round))
    break;
  case 7182: /* module 28 call 14 */
    CHECK_ERROR(_readMethod_asset_update_identifiers(
        c, &method->basic.asset_update_identifiers))
    break;
  case 7183: /* module 28 call 15 */
    CHECK_ERROR(
        _readMethod_asset_add_extension(c, &method->basic.asset_add_extension))
    break;
  case 7184: /* module 28 call 16 */
    CHECK_ERROR(_readMethod_asset_archive_extension(
        c, &method->basic.asset_archive_extension))
    break;
  case 7185: /* module 28 call 17 */
    CHECK_ERROR(_readMethod_asset_unarchive_extension(
        c, &method->basic.asset_unarchive_extension))
    break;
  case 7186: /* module 28 call 18 */
    CHECK_ERROR(_readMethod_asset_remove_primary_issuance_agent(
        c, &method->basic.asset_remove_primary_issuance_agent))
    break;
  case 7187: /* module 28 call 19 */
    CHECK_ERROR(_readMethod_asset_remove_smart_extension(
        c, &method->basic.asset_remove_smart_extension))
    break;
  case 7188: /* module 28 call 20 */
    CHECK_ERROR(_readMethod_asset_claim_classic_ticker(
        c, &method->basic.asset_claim_classic_ticker))
    break;
  case 7189: /* module 28 call 21 */
    CHECK_ERROR(_readMethod_asset_reserve_classic_ticker(
        c, &method->basic.asset_reserve_classic_ticker))
    break;
  case 7424: /* module 29 call 0 */
    CHECK_ERROR(_readMethod_dividend_new(c, &method->basic.dividend_new))
    break;
  case 7425: /* module 29 call 1 */
    CHECK_ERROR(_readMethod_dividend_cancel(c, &method->basic.dividend_cancel))
    break;
  case 7426: /* module 29 call 2 */
    CHECK_ERROR(_readMethod_dividend_claim(c, &method->basic.dividend_claim))
    break;
  case 7427: /* module 29 call 3 */
    CHECK_ERROR(_readMethod_dividend_claim_unclaimed(
        c, &method->basic.dividend_claim_unclaimed))
    break;
  case 7680: /* module 30 call 0 */
    CHECK_ERROR(_readMethod_identity_register_did(
        c, &method->basic.identity_register_did))
    break;
  case 7681: /* module 30 call 1 */
    CHECK_ERROR(_readMethod_identity_cdd_register_did(
        c, &method->basic.identity_cdd_register_did))
    break;
  case 7682: /* module 30 call 2 */
    CHECK_ERROR(_readMethod_identity_mock_cdd_register_did(
        c, &method->basic.identity_mock_cdd_register_did))
    break;
  case 7683: /* module 30 call 3 */
    CHECK_ERROR(_readMethod_identity_invalidate_cdd_claims(
        c, &method->basic.identity_invalidate_cdd_claims))
    break;
  case 7684: /* module 30 call 4 */
    CHECK_ERROR(_readMethod_identity_remove_secondary_keys(
        c, &method->basic.identity_remove_secondary_keys))
    break;
  case 7685: /* module 30 call 5 */
    CHECK_ERROR(_readMethod_identity_accept_primary_key(
        c, &method->basic.identity_accept_primary_key))
    break;
  case 7686: /* module 30 call 6 */
    CHECK_ERROR(_readMethod_identity_change_cdd_requirement_for_mk_rotation(
        c, &method->basic.identity_change_cdd_requirement_for_mk_rotation))
    break;
  case 7687: /* module 30 call 7 */
    CHECK_ERROR(_readMethod_identity_join_identity_as_key(
        c, &method->basic.identity_join_identity_as_key))
    break;
  case 7688: /* module 30 call 8 */
    CHECK_ERROR(_readMethod_identity_join_identity_as_identity(
        c, &method->basic.identity_join_identity_as_identity))
    break;
  case 7689: /* module 30 call 9 */
    CHECK_ERROR(_readMethod_identity_leave_identity_as_key(
        c, &method->basic.identity_leave_identity_as_key))
    break;
  case 7690: /* module 30 call 10 */
    CHECK_ERROR(_readMethod_identity_leave_identity_as_identity(
        c, &method->basic.identity_leave_identity_as_identity))
    break;
  case 7691: /* module 30 call 11 */
    CHECK_ERROR(
        _readMethod_identity_add_claim(c, &method->basic.identity_add_claim))
    break;
  case 7692: /* module 30 call 12 */
    CHECK_ERROR(_readMethod_identity_forwarded_call(
        c, &method->nested.identity_forwarded_call))
    break;
  case 7693: /* module 30 call 13 */
    CHECK_ERROR(_readMethod_identity_revoke_claim(
        c, &method->basic.identity_revoke_claim))
    break;
  case 7694: /* module 30 call 14 */
    CHECK_ERROR(_readMethod_identity_set_permission_to_signer(
        c, &method->basic.identity_set_permission_to_signer))
    break;
  case 7695: /* module 30 call 15 */
    CHECK_ERROR(_readMethod_identity_legacy_set_permission_to_signer(
        c, &method->basic.identity_legacy_set_permission_to_signer))
    break;
  case 7696: /* module 30 call 16 */
    CHECK_ERROR(_readMethod_identity_freeze_secondary_keys(
        c, &method->basic.identity_freeze_secondary_keys))
    break;
  case 7697: /* module 30 call 17 */
    CHECK_ERROR(_readMethod_identity_unfreeze_secondary_keys(
        c, &method->basic.identity_unfreeze_secondary_keys))
    break;
  case 7698: /* module 30 call 18 */
    CHECK_ERROR(
        _readMethod_identity_get_my_did(c, &method->basic.identity_get_my_did))
    break;
  case 7699: /* module 30 call 19 */
    CHECK_ERROR(
        _readMethod_identity_get_cdd_of(c, &method->basic.identity_get_cdd_of))
    break;
  case 7700: /* module 30 call 20 */
    CHECK_ERROR(_readMethod_identity_add_authorization(
        c, &method->basic.identity_add_authorization))
    break;
  case 7701: /* module 30 call 21 */
    CHECK_ERROR(_readMethod_identity_remove_authorization(
        c, &method->basic.identity_remove_authorization))
    break;
  case 7702: /* module 30 call 22 */
    CHECK_ERROR(_readMethod_identity_accept_authorization(
        c, &method->basic.identity_accept_authorization))
    break;
  case 7703: /* module 30 call 23 */
    CHECK_ERROR(_readMethod_identity_add_secondary_keys_with_authorization(
        c, &method->basic.identity_add_secondary_keys_with_authorization))
    break;
  case 7704: /* module 30 call 24 */
    CHECK_ERROR(_readMethod_identity_revoke_offchain_authorization(
        c, &method->basic.identity_revoke_offchain_authorization))
    break;
  case 7705: /* module 30 call 25 */
    CHECK_ERROR(_readMethod_identity_add_investor_uniqueness_claim(
        c, &method->basic.identity_add_investor_uniqueness_claim))
    break;
  case 7706: /* module 30 call 26 */
    CHECK_ERROR(_readMethod_identity_gc_add_cdd_claim(
        c, &method->basic.identity_gc_add_cdd_claim))
    break;
  case 7707: /* module 30 call 27 */
    CHECK_ERROR(_readMethod_identity_gc_revoke_cdd_claim(
        c, &method->basic.identity_gc_revoke_cdd_claim))
    break;
  case 7936: /* module 31 call 0 */
    CHECK_ERROR(_readMethod_bridge_change_controller(
        c, &method->basic.bridge_change_controller))
    break;
  case 7937: /* module 31 call 1 */
    CHECK_ERROR(
        _readMethod_bridge_change_admin(c, &method->basic.bridge_change_admin))
    break;
  case 7938: /* module 31 call 2 */
    CHECK_ERROR(_readMethod_bridge_change_timelock(
        c, &method->basic.bridge_change_timelock))
    break;
  case 7939: /* module 31 call 3 */
    CHECK_ERROR(_readMethod_bridge_freeze(c, &method->basic.bridge_freeze))
    break;
  case 7940: /* module 31 call 4 */
    CHECK_ERROR(_readMethod_bridge_unfreeze(c, &method->basic.bridge_unfreeze))
    break;
  case 7941: /* module 31 call 5 */
    CHECK_ERROR(_readMethod_bridge_change_bridge_limit(
        c, &method->basic.bridge_change_bridge_limit))
    break;
  case 7942: /* module 31 call 6 */
    CHECK_ERROR(_readMethod_bridge_change_bridge_exempted(
        c, &method->basic.bridge_change_bridge_exempted))
    break;
  case 7943: /* module 31 call 7 */
    CHECK_ERROR(_readMethod_bridge_force_handle_bridge_tx(
        c, &method->basic.bridge_force_handle_bridge_tx))
    break;
  case 7944: /* module 31 call 8 */
    CHECK_ERROR(_readMethod_bridge_batch_propose_bridge_tx(
        c, &method->basic.bridge_batch_propose_bridge_tx))
    break;
  case 7945: /* module 31 call 9 */
    CHECK_ERROR(_readMethod_bridge_propose_bridge_tx(
        c, &method->basic.bridge_propose_bridge_tx))
    break;
  case 7946: /* module 31 call 10 */
    CHECK_ERROR(_readMethod_bridge_handle_bridge_tx(
        c, &method->basic.bridge_handle_bridge_tx))
    break;
  case 7947: /* module 31 call 11 */
    CHECK_ERROR(
        _readMethod_bridge_freeze_txs(c, &method->basic.bridge_freeze_txs))
    break;
  case 7948: /* module 31 call 12 */
    CHECK_ERROR(
        _readMethod_bridge_unfreeze_txs(c, &method->basic.bridge_unfreeze_txs))
    break;
  case 7949: /* module 31 call 13 */
    CHECK_ERROR(_readMethod_bridge_handle_scheduled_bridge_tx(
        c, &method->basic.bridge_handle_scheduled_bridge_tx))
    break;
  case 8192: /* module 32 call 0 */
    CHECK_ERROR(_readMethod_compliancemanager_add_compliance_requirement(
        c, &method->basic.compliancemanager_add_compliance_requirement))
    break;
  case 8193: /* module 32 call 1 */
    CHECK_ERROR(_readMethod_compliancemanager_remove_compliance_requirement(
        c, &method->basic.compliancemanager_remove_compliance_requirement))
    break;
  case 8194: /* module 32 call 2 */
    CHECK_ERROR(_readMethod_compliancemanager_replace_asset_compliance(
        c, &method->basic.compliancemanager_replace_asset_compliance))
    break;
  case 8195: /* module 32 call 3 */
    CHECK_ERROR(_readMethod_compliancemanager_reset_asset_compliance(
        c, &method->basic.compliancemanager_reset_asset_compliance))
    break;
  case 8196: /* module 32 call 4 */
    CHECK_ERROR(_readMethod_compliancemanager_pause_asset_compliance(
        c, &method->basic.compliancemanager_pause_asset_compliance))
    break;
  case 8197: /* module 32 call 5 */
    CHECK_ERROR(_readMethod_compliancemanager_resume_asset_compliance(
        c, &method->basic.compliancemanager_resume_asset_compliance))
    break;
  case 8198: /* module 32 call 6 */
    CHECK_ERROR(_readMethod_compliancemanager_add_default_trusted_claim_issuer(
        c, &method->basic.compliancemanager_add_default_trusted_claim_issuer))
    break;
  case 8199: /* module 32 call 7 */
    CHECK_ERROR(
        _readMethod_compliancemanager_remove_default_trusted_claim_issuer(
            c, &method->basic
                    .compliancemanager_remove_default_trusted_claim_issuer))
    break;
  case 8200: /* module 32 call 8 */
    CHECK_ERROR(_readMethod_compliancemanager_change_compliance_requirement(
        c, &method->basic.compliancemanager_change_compliance_requirement))
    break;
  case 8448: /* module 33 call 0 */
    CHECK_ERROR(
        _readMethod_voting_add_ballot(c, &method->basic.voting_add_ballot))
    break;
  case 8449: /* module 33 call 1 */
    CHECK_ERROR(_readMethod_voting_vote(c, &method->basic.voting_vote))
    break;
  case 8450: /* module 33 call 2 */
    CHECK_ERROR(_readMethod_voting_cancel_ballot(
        c, &method->basic.voting_cancel_ballot))
    break;
  case 8704: /* module 34 call 0 */
    CHECK_ERROR(_readMethod_stocapped_launch_sto(
        c, &method->basic.stocapped_launch_sto))
    break;
  case 8705: /* module 34 call 1 */
    CHECK_ERROR(_readMethod_stocapped_buy_tokens(
        c, &method->basic.stocapped_buy_tokens))
    break;
  case 8706: /* module 34 call 2 */
    CHECK_ERROR(
        _readMethod_stocapped_pause_sto(c, &method->basic.stocapped_pause_sto))
    break;
  case 8707: /* module 34 call 3 */
    CHECK_ERROR(_readMethod_stocapped_unpause_sto(
        c, &method->basic.stocapped_unpause_sto))
    break;
  case 8960: /* module 35 call 0 */
    CHECK_ERROR(_readMethod_exemption_modify_exemption_list(
        c, &method->basic.exemption_modify_exemption_list))
    break;
  case 9216: /* module 36 call 0 */
    CHECK_ERROR(_readMethod_settlement_create_venue(
        c, &method->basic.settlement_create_venue))
    break;
  case 9217: /* module 36 call 1 */
    CHECK_ERROR(_readMethod_settlement_update_venue(
        c, &method->basic.settlement_update_venue))
    break;
  case 9218: /* module 36 call 2 */
    CHECK_ERROR(_readMethod_settlement_add_instruction(
        c, &method->basic.settlement_add_instruction))
    break;
  case 9219: /* module 36 call 3 */
    CHECK_ERROR(_readMethod_settlement_add_and_affirm_instruction(
        c, &method->basic.settlement_add_and_affirm_instruction))
    break;
  case 9220: /* module 36 call 4 */
    CHECK_ERROR(_readMethod_settlement_affirm_instruction(
        c, &method->basic.settlement_affirm_instruction))
    break;
  case 9221: /* module 36 call 5 */
    CHECK_ERROR(_readMethod_settlement_withdraw_affirmation(
        c, &method->basic.settlement_withdraw_affirmation))
    break;
  case 9222: /* module 36 call 6 */
    CHECK_ERROR(_readMethod_settlement_reject_instruction(
        c, &method->basic.settlement_reject_instruction))
    break;
  case 9223: /* module 36 call 7 */
    CHECK_ERROR(_readMethod_settlement_affirm_with_receipts(
        c, &method->basic.settlement_affirm_with_receipts))
    break;
  case 9224: /* module 36 call 8 */
    CHECK_ERROR(_readMethod_settlement_claim_receipt(
        c, &method->basic.settlement_claim_receipt))
    break;
  case 9225: /* module 36 call 9 */
    CHECK_ERROR(_readMethod_settlement_unclaim_receipt(
        c, &method->basic.settlement_unclaim_receipt))
    break;
  case 9226: /* module 36 call 10 */
    CHECK_ERROR(_readMethod_settlement_set_venue_filtering(
        c, &method->basic.settlement_set_venue_filtering))
    break;
  case 9227: /* module 36 call 11 */
    CHECK_ERROR(_readMethod_settlement_allow_venues(
        c, &method->basic.settlement_allow_venues))
    break;
  case 9228: /* module 36 call 12 */
    CHECK_ERROR(_readMethod_settlement_disallow_venues(
        c, &method->basic.settlement_disallow_venues))
    break;
  case 9229: /* module 36 call 13 */
    CHECK_ERROR(_readMethod_settlement_execute_scheduled_instruction(
        c, &method->basic.settlement_execute_scheduled_instruction))
    break;
  case 9472: /* module 37 call 0 */
    CHECK_ERROR(_readMethod_sto_create_fundraiser(
        c, &method->basic.sto_create_fundraiser))
    break;
  case 9473: /* module 37 call 1 */
    CHECK_ERROR(_readMethod_sto_invest(c, &method->basic.sto_invest))
    break;
  case 9474: /* module 37 call 2 */
    CHECK_ERROR(_readMethod_sto_freeze_fundraiser(
        c, &method->basic.sto_freeze_fundraiser))
    break;
  case 9475: /* module 37 call 3 */
    CHECK_ERROR(_readMethod_sto_unfreeze_fundraiser(
        c, &method->basic.sto_unfreeze_fundraiser))
    break;
  case 9476: /* module 37 call 4 */
    CHECK_ERROR(_readMethod_sto_modify_fundraiser_window(
        c, &method->basic.sto_modify_fundraiser_window))
    break;
  case 9477: /* module 37 call 5 */
    CHECK_ERROR(_readMethod_sto_stop(c, &method->basic.sto_stop))
    break;
  case 9728: /* module 38 call 0 */
    CHECK_ERROR(_readMethod_cddserviceproviders_set_active_members_limit(
        c, &method->basic.cddserviceproviders_set_active_members_limit))
    break;
  case 9729: /* module 38 call 1 */
    CHECK_ERROR(_readMethod_cddserviceproviders_disable_member(
        c, &method->basic.cddserviceproviders_disable_member))
    break;
  case 9730: /* module 38 call 2 */
    CHECK_ERROR(_readMethod_cddserviceproviders_add_member(
        c, &method->basic.cddserviceproviders_add_member))
    break;
  case 9731: /* module 38 call 3 */
    CHECK_ERROR(_readMethod_cddserviceproviders_remove_member(
        c, &method->basic.cddserviceproviders_remove_member))
    break;
  case 9732: /* module 38 call 4 */
    CHECK_ERROR(_readMethod_cddserviceproviders_swap_member(
        c, &method->basic.cddserviceproviders_swap_member))
    break;
  case 9733: /* module 38 call 5 */
    CHECK_ERROR(_readMethod_cddserviceproviders_reset_members(
        c, &method->basic.cddserviceproviders_reset_members))
    break;
  case 9734: /* module 38 call 6 */
    CHECK_ERROR(_readMethod_cddserviceproviders_abdicate_membership(
        c, &method->basic.cddserviceproviders_abdicate_membership))
    break;
  case 10240: /* module 40 call 0 */
    CHECK_ERROR(_readMethod_protocolfee_change_coefficient(
        c, &method->basic.protocolfee_change_coefficient))
    break;
  case 10241: /* module 40 call 1 */
    CHECK_ERROR(_readMethod_protocolfee_change_base_fee(
        c, &method->basic.protocolfee_change_base_fee))
    break;
  case 10496: /* module 41 call 0 */
    CHECK_ERROR(_readMethod_utility_batch(c, &method->basic.utility_batch))
    break;
  case 10497: /* module 41 call 1 */
    CHECK_ERROR(_readMethod_utility_batch_atomic(
        c, &method->basic.utility_batch_atomic))
    break;
  case 10498: /* module 41 call 2 */
    CHECK_ERROR(_readMethod_utility_batch_optimistic(
        c, &method->basic.utility_batch_optimistic))
    break;
  case 10499: /* module 41 call 3 */
    CHECK_ERROR(
        _readMethod_utility_relay_tx(c, &method->basic.utility_relay_tx))
    break;
  case 10752: /* module 42 call 0 */
    CHECK_ERROR(_readMethod_portfolio_create_portfolio(
        c, &method->basic.portfolio_create_portfolio))
    break;
  case 10753: /* module 42 call 1 */
    CHECK_ERROR(_readMethod_portfolio_delete_portfolio(
        c, &method->basic.portfolio_delete_portfolio))
    break;
  case 10754: /* module 42 call 2 */
    CHECK_ERROR(_readMethod_portfolio_move_portfolio_funds(
        c, &method->basic.portfolio_move_portfolio_funds))
    break;
  case 10755: /* module 42 call 3 */
    CHECK_ERROR(_readMethod_portfolio_rename_portfolio(
        c, &method->basic.portfolio_rename_portfolio))
    break;
  case 11008: /* module 43 call 0 */
    CHECK_ERROR(_readMethod_confidential_add_range_proof(
        c, &method->basic.confidential_add_range_proof))
    break;
  case 11009: /* module 43 call 1 */
    CHECK_ERROR(_readMethod_confidential_add_verify_range_proof(
        c, &method->basic.confidential_add_verify_range_proof))
    break;
  case 11520: /* module 45 call 0 */
    CHECK_ERROR(
        _readMethod_scheduler_schedule(c, &method->basic.scheduler_schedule))
    break;
  case 11521: /* module 45 call 1 */
    CHECK_ERROR(
        _readMethod_scheduler_cancel(c, &method->basic.scheduler_cancel))
    break;
  case 11522: /* module 45 call 2 */
    CHECK_ERROR(_readMethod_scheduler_schedule_named(
        c, &method->basic.scheduler_schedule_named))
    break;
  case 11523: /* module 45 call 3 */
    CHECK_ERROR(_readMethod_scheduler_cancel_named(
        c, &method->basic.scheduler_cancel_named))
    break;
  case 11524: /* module 45 call 4 */
    CHECK_ERROR(_readMethod_scheduler_schedule_after(
        c, &method->basic.scheduler_schedule_after))
    break;
  case 11525: /* module 45 call 5 */
    CHECK_ERROR(_readMethod_scheduler_schedule_named_after(
        c, &method->basic.scheduler_schedule_named_after))
    break;
  case 11776: /* module 46 call 0 */
    CHECK_ERROR(_readMethod_corporateaction_set_max_details_length(
        c, &method->basic.corporateaction_set_max_details_length))
    break;
  case 11777: /* module 46 call 1 */
    CHECK_ERROR(_readMethod_corporateaction_reset_caa(
        c, &method->basic.corporateaction_reset_caa))
    break;
  case 11778: /* module 46 call 2 */
    CHECK_ERROR(_readMethod_corporateaction_set_default_targets(
        c, &method->basic.corporateaction_set_default_targets))
    break;
  case 11779: /* module 46 call 3 */
    CHECK_ERROR(_readMethod_corporateaction_set_default_withholding_tax(
        c, &method->basic.corporateaction_set_default_withholding_tax))
    break;
  case 11780: /* module 46 call 4 */
    CHECK_ERROR(_readMethod_corporateaction_set_did_withholding_tax(
        c, &method->basic.corporateaction_set_did_withholding_tax))
    break;
  case 11781: /* module 46 call 5 */
    CHECK_ERROR(_readMethod_corporateaction_initiate_corporate_action(
        c, &method->basic.corporateaction_initiate_corporate_action))
    break;
  case 11782: /* module 46 call 6 */
    CHECK_ERROR(_readMethod_corporateaction_link_ca_doc(
        c, &method->basic.corporateaction_link_ca_doc))
    break;
  case 11783: /* module 46 call 7 */
    CHECK_ERROR(_readMethod_corporateaction_remove_ca(
        c, &method->basic.corporateaction_remove_ca))
    break;
  case 11784: /* module 46 call 8 */
    CHECK_ERROR(_readMethod_corporateaction_change_record_date(
        c, &method->basic.corporateaction_change_record_date))
    break;
  case 12032: /* module 47 call 0 */
    CHECK_ERROR(_readMethod_corporateballot_attach_ballot(
        c, &method->basic.corporateballot_attach_ballot))
    break;
  case 12033: /* module 47 call 1 */
    CHECK_ERROR(_readMethod_corporateballot_vote(
        c, &method->basic.corporateballot_vote))
    break;
  case 12034: /* module 47 call 2 */
    CHECK_ERROR(_readMethod_corporateballot_change_end(
        c, &method->basic.corporateballot_change_end))
    break;
  case 12035: /* module 47 call 3 */
    CHECK_ERROR(_readMethod_corporateballot_change_meta(
        c, &method->basic.corporateballot_change_meta))
    break;
  case 12036: /* module 47 call 4 */
    CHECK_ERROR(_readMethod_corporateballot_change_rcv(
        c, &method->basic.corporateballot_change_rcv))
    break;
  case 12037: /* module 47 call 5 */
    CHECK_ERROR(_readMethod_corporateballot_remove_ballot(
        c, &method->basic.corporateballot_remove_ballot))
    break;
  case 12288: /* module 48 call 0 */
    CHECK_ERROR(_readMethod_capitaldistribution_distribute(
        c, &method->basic.capitaldistribution_distribute))
    break;
  case 12289: /* module 48 call 1 */
    CHECK_ERROR(_readMethod_capitaldistribution_claim(
        c, &method->basic.capitaldistribution_claim))
    break;
  case 12290: /* module 48 call 2 */
    CHECK_ERROR(_readMethod_capitaldistribution_push_benefit(
        c, &method->basic.capitaldistribution_push_benefit))
    break;
  case 12291: /* module 48 call 3 */
    CHECK_ERROR(_readMethod_capitaldistribution_reclaim(
        c, &method->basic.capitaldistribution_reclaim))
    break;
  case 12292: /* module 48 call 4 */
    CHECK_ERROR(_readMethod_capitaldistribution_remove_distribution(
        c, &method->basic.capitaldistribution_remove_distribution))
    break;
  case 12544: /* module 49 call 0 */
    CHECK_ERROR(_readMethod_checkpoint_create_checkpoint(
        c, &method->basic.checkpoint_create_checkpoint))
    break;
  case 12545: /* module 49 call 1 */
    CHECK_ERROR(_readMethod_checkpoint_set_schedules_max_complexity(
        c, &method->basic.checkpoint_set_schedules_max_complexity))
    break;
  case 12546: /* module 49 call 2 */
    CHECK_ERROR(_readMethod_checkpoint_create_schedule(
        c, &method->basic.checkpoint_create_schedule))
    break;
  case 12547: /* module 49 call 3 */
    CHECK_ERROR(_readMethod_checkpoint_remove_schedule(
        c, &method->basic.checkpoint_remove_schedule))
    break;
  default:
    return parser_unexpected_callIndex;
  }

  return parser_ok;
}

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////

const char *_getMethod_ModuleName(uint8_t moduleIdx) {
  switch (moduleIdx) {
  case 0:
    return "System";
  case 1:
    return "Babe";
  case 2:
    return "Timestamp";
  case 3:
    return "Indices";
  case 4:
    return "Balances";
  case 6:
    return "Authorship";
  case 7:
    return "Staking";
  case 8:
    return "Offences";
  case 9:
    return "Session";
  case 10:
    return "Finalitytracker";
  case 11:
    return "Grandpa";
  case 12:
    return "Imonline";
  case 13:
    return "Authoritydiscovery";
  case 14:
    return "Randomnesscollectiveflip";
  case 16:
    return "Sudo";
  case 17:
    return "Multisig";
  case 19:
    return "Contracts";
  case 20:
    return "Treasury";
  case 21:
    return "Polymeshcommittee";
  case 22:
    return "Committeemembership";
  case 23:
    return "Pips";
  case 24:
    return "Technicalcommittee";
  case 25:
    return "Technicalcommitteemembership";
  case 26:
    return "Upgradecommittee";
  case 27:
    return "Upgradecommitteemembership";
  case 28:
    return "Asset";
  case 29:
    return "Dividend";
  case 30:
    return "Identity";
  case 31:
    return "Bridge";
  case 32:
    return "Compliancemanager";
  case 33:
    return "Voting";
  case 34:
    return "Stocapped";
  case 35:
    return "Exemption";
  case 36:
    return "Settlement";
  case 37:
    return "Sto";
  case 38:
    return "Cddserviceproviders";
  case 39:
    return "Statistic";
  case 40:
    return "Protocolfee";
  case 41:
    return "Utility";
  case 42:
    return "Portfolio";
  case 43:
    return "Confidential";
  case 45:
    return "Scheduler";
  case 46:
    return "Corporateaction";
  case 47:
    return "Corporateballot";
  case 48:
    return "Capitaldistribution";
  case 49:
    return "Checkpoint";
  default:
    return NULL;
  }

  return NULL;
}

const char *_getMethod_Name(uint8_t moduleIdx, uint8_t callIdx) {
  uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

  switch (callPrivIdx) {
  case 0: /* module 0 call 0 */
    return "Fill block";
  case 1: /* module 0 call 1 */
    return "Remark";
  case 2: /* module 0 call 2 */
    return "Set heap pages";
  case 3: /* module 0 call 3 */
    return "Set code";
  case 4: /* module 0 call 4 */
    return "Set code without checks";
  case 5: /* module 0 call 5 */
    return "Set changes trie config";
  case 6: /* module 0 call 6 */
    return "Set storage";
  case 7: /* module 0 call 7 */
    return "Kill storage";
  case 8: /* module 0 call 8 */
    return "Kill prefix";
  case 9: /* module 0 call 9 */
    return "Suicide";
  case 256: /* module 1 call 0 */
    return "Report equivocation";
  case 257: /* module 1 call 1 */
    return "Report equivocation unsigned";
  case 512: /* module 2 call 0 */
    return "Set";
  case 768: /* module 3 call 0 */
    return "Claim";
  case 769: /* module 3 call 1 */
    return "Transfer";
  case 770: /* module 3 call 2 */
    return "Free";
  case 771: /* module 3 call 3 */
    return "Force transfer";
  case 772: /* module 3 call 4 */
    return "Freeze";
  case 1024: /* module 4 call 0 */
    return "Transfer";
  case 1025: /* module 4 call 1 */
    return "Transfer with memo";
  case 1026: /* module 4 call 2 */
    return "Deposit block reward reserve balance";
  case 1027: /* module 4 call 3 */
    return "Set balance";
  case 1028: /* module 4 call 4 */
    return "Force transfer";
  case 1029: /* module 4 call 5 */
    return "Burn account balance";
  case 1536: /* module 6 call 0 */
    return "Set uncles";
  case 1792: /* module 7 call 0 */
    return "Bond";
  case 1793: /* module 7 call 1 */
    return "Bond extra";
  case 1794: /* module 7 call 2 */
    return "Unbond";
  case 1795: /* module 7 call 3 */
    return "Withdraw unbonded";
  case 1796: /* module 7 call 4 */
    return "Validate";
  case 1797: /* module 7 call 5 */
    return "Nominate";
  case 1798: /* module 7 call 6 */
    return "Chill";
  case 1799: /* module 7 call 7 */
    return "Set payee";
  case 1800: /* module 7 call 8 */
    return "Set controller";
  case 1801: /* module 7 call 9 */
    return "Set validator count";
  case 1802: /* module 7 call 10 */
    return "Increase validator count";
  case 1803: /* module 7 call 11 */
    return "Scale validator count";
  case 1804: /* module 7 call 12 */
    return "Add permissioned validator";
  case 1805: /* module 7 call 13 */
    return "Remove permissioned validator";
  case 1806: /* module 7 call 14 */
    return "Validate cdd expiry nominators";
  case 1807: /* module 7 call 15 */
    return "Set commission cap";
  case 1808: /* module 7 call 16 */
    return "Set min bond threshold";
  case 1809: /* module 7 call 17 */
    return "Force no eras";
  case 1810: /* module 7 call 18 */
    return "Force new era";
  case 1811: /* module 7 call 19 */
    return "Set invulnerables";
  case 1812: /* module 7 call 20 */
    return "Force unstake";
  case 1813: /* module 7 call 21 */
    return "Force new era always";
  case 1814: /* module 7 call 22 */
    return "Cancel deferred slash";
  case 1815: /* module 7 call 23 */
    return "Payout stakers";
  case 1816: /* module 7 call 24 */
    return "Rebond";
  case 1817: /* module 7 call 25 */
    return "Set history depth";
  case 1818: /* module 7 call 26 */
    return "Reap stash";
  case 1819: /* module 7 call 27 */
    return "Submit election solution";
  case 1820: /* module 7 call 28 */
    return "Submit election solution unsigned";
  case 1821: /* module 7 call 29 */
    return "Payout stakers by system";
  case 1822: /* module 7 call 30 */
    return "Change slashing allowed for";
  case 2304: /* module 9 call 0 */
    return "Set keys";
  case 2305: /* module 9 call 1 */
    return "Purge keys";
  case 2560: /* module 10 call 0 */
    return "Final hint";
  case 2816: /* module 11 call 0 */
    return "Report equivocation";
  case 2817: /* module 11 call 1 */
    return "Report equivocation unsigned";
  case 2818: /* module 11 call 2 */
    return "Note stalled";
  case 3072: /* module 12 call 0 */
    return "Heartbeat";
  case 3073: /* module 12 call 1 */
    return "Set slashing params";
  case 4096: /* module 16 call 0 */
    return "Sudo";
  case 4097: /* module 16 call 1 */
    return "Sudo unchecked weight";
  case 4098: /* module 16 call 2 */
    return "Set key";
  case 4099: /* module 16 call 3 */
    return "Sudo as";
  case 4352: /* module 17 call 0 */
    return "Create multisig";
  case 4353: /* module 17 call 1 */
    return "Create or approve proposal as identity";
  case 4354: /* module 17 call 2 */
    return "Create or approve proposal as key";
  case 4355: /* module 17 call 3 */
    return "Create proposal as identity";
  case 4356: /* module 17 call 4 */
    return "Create proposal as key";
  case 4357: /* module 17 call 5 */
    return "Approve as identity";
  case 4358: /* module 17 call 6 */
    return "Approve as key";
  case 4359: /* module 17 call 7 */
    return "Reject as identity";
  case 4360: /* module 17 call 8 */
    return "Reject as key";
  case 4361: /* module 17 call 9 */
    return "Accept multisig signer as identity";
  case 4362: /* module 17 call 10 */
    return "Accept multisig signer as key";
  case 4363: /* module 17 call 11 */
    return "Add multisig signer";
  case 4364: /* module 17 call 12 */
    return "Remove multisig signer";
  case 4365: /* module 17 call 13 */
    return "Add multisig signers via creator";
  case 4366: /* module 17 call 14 */
    return "Remove multisig signers via creator";
  case 4367: /* module 17 call 15 */
    return "Change sigs required";
  case 4368: /* module 17 call 16 */
    return "Change all signers and sigs required";
  case 4369: /* module 17 call 17 */
    return "Make multisig signer";
  case 4370: /* module 17 call 18 */
    return "Make multisig primary";
  case 4864: /* module 19 call 0 */
    return "Update schedule";
  case 4865: /* module 19 call 1 */
    return "Put code";
  case 4866: /* module 19 call 2 */
    return "Call";
  case 4867: /* module 19 call 3 */
    return "Instantiate";
  case 4868: /* module 19 call 4 */
    return "Freeze instantiation";
  case 4869: /* module 19 call 5 */
    return "Unfreeze instantiation";
  case 4870: /* module 19 call 6 */
    return "Transfer template ownership";
  case 4871: /* module 19 call 7 */
    return "Change template fees";
  case 4872: /* module 19 call 8 */
    return "Change template meta url";
  case 5120: /* module 20 call 0 */
    return "Disbursement";
  case 5121: /* module 20 call 1 */
    return "Reimbursement";
  case 5376: /* module 21 call 0 */
    return "Set vote threshold";
  case 5377: /* module 21 call 1 */
    return "Set release coordinator";
  case 5378: /* module 21 call 2 */
    return "Set expires after";
  case 5379: /* module 21 call 3 */
    return "Close";
  case 5380: /* module 21 call 4 */
    return "Vote or propose";
  case 5381: /* module 21 call 5 */
    return "Vote";
  case 5632: /* module 22 call 0 */
    return "Set active members limit";
  case 5633: /* module 22 call 1 */
    return "Disable member";
  case 5634: /* module 22 call 2 */
    return "Add member";
  case 5635: /* module 22 call 3 */
    return "Remove member";
  case 5636: /* module 22 call 4 */
    return "Swap member";
  case 5637: /* module 22 call 5 */
    return "Reset members";
  case 5638: /* module 22 call 6 */
    return "Abdicate membership";
  case 5888: /* module 23 call 0 */
    return "Set prune historical pips";
  case 5889: /* module 23 call 1 */
    return "Set min proposal deposit";
  case 5890: /* module 23 call 2 */
    return "Set proposal cool off period";
  case 5891: /* module 23 call 3 */
    return "Set default enactment period";
  case 5892: /* module 23 call 4 */
    return "Set pending pip expiry";
  case 5893: /* module 23 call 5 */
    return "Set max pip skip count";
  case 5894: /* module 23 call 6 */
    return "Set active pip limit";
  case 5895: /* module 23 call 7 */
    return "Propose";
  case 5896: /* module 23 call 8 */
    return "Amend proposal";
  case 5897: /* module 23 call 9 */
    return "Cancel proposal";
  case 5898: /* module 23 call 10 */
    return "Vote";
  case 5899: /* module 23 call 11 */
    return "Approve committee proposal";
  case 5900: /* module 23 call 12 */
    return "Reject proposal";
  case 5901: /* module 23 call 13 */
    return "Prune proposal";
  case 5902: /* module 23 call 14 */
    return "Reschedule execution";
  case 5903: /* module 23 call 15 */
    return "Clear snapshot";
  case 5904: /* module 23 call 16 */
    return "Snapshot";
  case 5905: /* module 23 call 17 */
    return "Enact snapshot results";
  case 5906: /* module 23 call 18 */
    return "Execute scheduled pip";
  case 5907: /* module 23 call 19 */
    return "Expire scheduled pip";
  case 6144: /* module 24 call 0 */
    return "Set vote threshold";
  case 6145: /* module 24 call 1 */
    return "Set release coordinator";
  case 6146: /* module 24 call 2 */
    return "Set expires after";
  case 6147: /* module 24 call 3 */
    return "Close";
  case 6148: /* module 24 call 4 */
    return "Vote or propose";
  case 6149: /* module 24 call 5 */
    return "Vote";
  case 6400: /* module 25 call 0 */
    return "Set active members limit";
  case 6401: /* module 25 call 1 */
    return "Disable member";
  case 6402: /* module 25 call 2 */
    return "Add member";
  case 6403: /* module 25 call 3 */
    return "Remove member";
  case 6404: /* module 25 call 4 */
    return "Swap member";
  case 6405: /* module 25 call 5 */
    return "Reset members";
  case 6406: /* module 25 call 6 */
    return "Abdicate membership";
  case 6656: /* module 26 call 0 */
    return "Set vote threshold";
  case 6657: /* module 26 call 1 */
    return "Set release coordinator";
  case 6658: /* module 26 call 2 */
    return "Set expires after";
  case 6659: /* module 26 call 3 */
    return "Close";
  case 6660: /* module 26 call 4 */
    return "Vote or propose";
  case 6661: /* module 26 call 5 */
    return "Vote";
  case 6912: /* module 27 call 0 */
    return "Set active members limit";
  case 6913: /* module 27 call 1 */
    return "Disable member";
  case 6914: /* module 27 call 2 */
    return "Add member";
  case 6915: /* module 27 call 3 */
    return "Remove member";
  case 6916: /* module 27 call 4 */
    return "Swap member";
  case 6917: /* module 27 call 5 */
    return "Reset members";
  case 6918: /* module 27 call 6 */
    return "Abdicate membership";
  case 7168: /* module 28 call 0 */
    return "Register ticker";
  case 7169: /* module 28 call 1 */
    return "Accept ticker transfer";
  case 7170: /* module 28 call 2 */
    return "Accept primary issuance agent transfer";
  case 7171: /* module 28 call 3 */
    return "Accept asset ownership transfer";
  case 7172: /* module 28 call 4 */
    return "Create asset";
  case 7173: /* module 28 call 5 */
    return "Freeze";
  case 7174: /* module 28 call 6 */
    return "Unfreeze";
  case 7175: /* module 28 call 7 */
    return "Rename asset";
  case 7176: /* module 28 call 8 */
    return "Issue";
  case 7177: /* module 28 call 9 */
    return "Redeem";
  case 7178: /* module 28 call 10 */
    return "Make divisible";
  case 7179: /* module 28 call 11 */
    return "Add documents";
  case 7180: /* module 28 call 12 */
    return "Remove documents";
  case 7181: /* module 28 call 13 */
    return "Set funding round";
  case 7182: /* module 28 call 14 */
    return "Update identifiers";
  case 7183: /* module 28 call 15 */
    return "Add extension";
  case 7184: /* module 28 call 16 */
    return "Archive extension";
  case 7185: /* module 28 call 17 */
    return "Unarchive extension";
  case 7186: /* module 28 call 18 */
    return "Remove primary issuance agent";
  case 7187: /* module 28 call 19 */
    return "Remove smart extension";
  case 7188: /* module 28 call 20 */
    return "Claim classic ticker";
  case 7189: /* module 28 call 21 */
    return "Reserve classic ticker";
  case 7424: /* module 29 call 0 */
    return "New";
  case 7425: /* module 29 call 1 */
    return "Cancel";
  case 7426: /* module 29 call 2 */
    return "Claim";
  case 7427: /* module 29 call 3 */
    return "Claim unclaimed";
  case 7680: /* module 30 call 0 */
    return "Register did";
  case 7681: /* module 30 call 1 */
    return "Cdd register did";
  case 7682: /* module 30 call 2 */
    return "Mock cdd register did";
  case 7683: /* module 30 call 3 */
    return "Invalidate cdd claims";
  case 7684: /* module 30 call 4 */
    return "Remove secondary keys";
  case 7685: /* module 30 call 5 */
    return "Accept primary key";
  case 7686: /* module 30 call 6 */
    return "Change cdd requirement for mk rotation";
  case 7687: /* module 30 call 7 */
    return "Join identity as key";
  case 7688: /* module 30 call 8 */
    return "Join identity as identity";
  case 7689: /* module 30 call 9 */
    return "Leave identity as key";
  case 7690: /* module 30 call 10 */
    return "Leave identity as identity";
  case 7691: /* module 30 call 11 */
    return "Add claim";
  case 7692: /* module 30 call 12 */
    return "Forwarded call";
  case 7693: /* module 30 call 13 */
    return "Revoke claim";
  case 7694: /* module 30 call 14 */
    return "Set permission to signer";
  case 7695: /* module 30 call 15 */
    return "Legacy set permission to signer";
  case 7696: /* module 30 call 16 */
    return "Freeze secondary keys";
  case 7697: /* module 30 call 17 */
    return "Unfreeze secondary keys";
  case 7698: /* module 30 call 18 */
    return "Get my did";
  case 7699: /* module 30 call 19 */
    return "Get cdd of";
  case 7700: /* module 30 call 20 */
    return "Add authorization";
  case 7701: /* module 30 call 21 */
    return "Remove authorization";
  case 7702: /* module 30 call 22 */
    return "Accept authorization";
  case 7703: /* module 30 call 23 */
    return "Add secondary keys with authorization";
  case 7704: /* module 30 call 24 */
    return "Revoke offchain authorization";
  case 7705: /* module 30 call 25 */
    return "Add investor uniqueness claim";
  case 7706: /* module 30 call 26 */
    return "Gc add cdd claim";
  case 7707: /* module 30 call 27 */
    return "Gc revoke cdd claim";
  case 7936: /* module 31 call 0 */
    return "Change controller";
  case 7937: /* module 31 call 1 */
    return "Change admin";
  case 7938: /* module 31 call 2 */
    return "Change timelock";
  case 7939: /* module 31 call 3 */
    return "Freeze";
  case 7940: /* module 31 call 4 */
    return "Unfreeze";
  case 7941: /* module 31 call 5 */
    return "Change bridge limit";
  case 7942: /* module 31 call 6 */
    return "Change bridge exempted";
  case 7943: /* module 31 call 7 */
    return "Force handle bridge tx";
  case 7944: /* module 31 call 8 */
    return "Batch propose bridge tx";
  case 7945: /* module 31 call 9 */
    return "Propose bridge tx";
  case 7946: /* module 31 call 10 */
    return "Handle bridge tx";
  case 7947: /* module 31 call 11 */
    return "Freeze txs";
  case 7948: /* module 31 call 12 */
    return "Unfreeze txs";
  case 7949: /* module 31 call 13 */
    return "Handle scheduled bridge tx";
  case 8192: /* module 32 call 0 */
    return "Add compliance requirement";
  case 8193: /* module 32 call 1 */
    return "Remove compliance requirement";
  case 8194: /* module 32 call 2 */
    return "Replace asset compliance";
  case 8195: /* module 32 call 3 */
    return "Reset asset compliance";
  case 8196: /* module 32 call 4 */
    return "Pause asset compliance";
  case 8197: /* module 32 call 5 */
    return "Resume asset compliance";
  case 8198: /* module 32 call 6 */
    return "Add default trusted claim issuer";
  case 8199: /* module 32 call 7 */
    return "Remove default trusted claim issuer";
  case 8200: /* module 32 call 8 */
    return "Change compliance requirement";
  case 8448: /* module 33 call 0 */
    return "Add ballot";
  case 8449: /* module 33 call 1 */
    return "Vote";
  case 8450: /* module 33 call 2 */
    return "Cancel ballot";
  case 8704: /* module 34 call 0 */
    return "Launch sto";
  case 8705: /* module 34 call 1 */
    return "Buy tokens";
  case 8706: /* module 34 call 2 */
    return "Pause sto";
  case 8707: /* module 34 call 3 */
    return "Unpause sto";
  case 8960: /* module 35 call 0 */
    return "Modify exemption list";
  case 9216: /* module 36 call 0 */
    return "Create venue";
  case 9217: /* module 36 call 1 */
    return "Update venue";
  case 9218: /* module 36 call 2 */
    return "Add instruction";
  case 9219: /* module 36 call 3 */
    return "Add and affirm instruction";
  case 9220: /* module 36 call 4 */
    return "Affirm instruction";
  case 9221: /* module 36 call 5 */
    return "Withdraw affirmation";
  case 9222: /* module 36 call 6 */
    return "Reject instruction";
  case 9223: /* module 36 call 7 */
    return "Affirm with receipts";
  case 9224: /* module 36 call 8 */
    return "Claim receipt";
  case 9225: /* module 36 call 9 */
    return "Unclaim receipt";
  case 9226: /* module 36 call 10 */
    return "Set venue filtering";
  case 9227: /* module 36 call 11 */
    return "Allow venues";
  case 9228: /* module 36 call 12 */
    return "Disallow venues";
  case 9229: /* module 36 call 13 */
    return "Execute scheduled instruction";
  case 9472: /* module 37 call 0 */
    return "Create fundraiser";
  case 9473: /* module 37 call 1 */
    return "Invest";
  case 9474: /* module 37 call 2 */
    return "Freeze fundraiser";
  case 9475: /* module 37 call 3 */
    return "Unfreeze fundraiser";
  case 9476: /* module 37 call 4 */
    return "Modify fundraiser window";
  case 9477: /* module 37 call 5 */
    return "Stop";
  case 9728: /* module 38 call 0 */
    return "Set active members limit";
  case 9729: /* module 38 call 1 */
    return "Disable member";
  case 9730: /* module 38 call 2 */
    return "Add member";
  case 9731: /* module 38 call 3 */
    return "Remove member";
  case 9732: /* module 38 call 4 */
    return "Swap member";
  case 9733: /* module 38 call 5 */
    return "Reset members";
  case 9734: /* module 38 call 6 */
    return "Abdicate membership";
  case 10240: /* module 40 call 0 */
    return "Change coefficient";
  case 10241: /* module 40 call 1 */
    return "Change base fee";
  case 10496: /* module 41 call 0 */
    return "Batch";
  case 10497: /* module 41 call 1 */
    return "Batch atomic";
  case 10498: /* module 41 call 2 */
    return "Batch optimistic";
  case 10499: /* module 41 call 3 */
    return "Relay tx";
  case 10752: /* module 42 call 0 */
    return "Create portfolio";
  case 10753: /* module 42 call 1 */
    return "Delete portfolio";
  case 10754: /* module 42 call 2 */
    return "Move portfolio funds";
  case 10755: /* module 42 call 3 */
    return "Rename portfolio";
  case 11008: /* module 43 call 0 */
    return "Add range proof";
  case 11009: /* module 43 call 1 */
    return "Add verify range proof";
  case 11520: /* module 45 call 0 */
    return "Schedule";
  case 11521: /* module 45 call 1 */
    return "Cancel";
  case 11522: /* module 45 call 2 */
    return "Schedule named";
  case 11523: /* module 45 call 3 */
    return "Cancel named";
  case 11524: /* module 45 call 4 */
    return "Schedule after";
  case 11525: /* module 45 call 5 */
    return "Schedule named after";
  case 11776: /* module 46 call 0 */
    return "Set max details length";
  case 11777: /* module 46 call 1 */
    return "Reset caa";
  case 11778: /* module 46 call 2 */
    return "Set default targets";
  case 11779: /* module 46 call 3 */
    return "Set default withholding tax";
  case 11780: /* module 46 call 4 */
    return "Set did withholding tax";
  case 11781: /* module 46 call 5 */
    return "Initiate corporate action";
  case 11782: /* module 46 call 6 */
    return "Link ca doc";
  case 11783: /* module 46 call 7 */
    return "Remove ca";
  case 11784: /* module 46 call 8 */
    return "Change record date";
  case 12032: /* module 47 call 0 */
    return "Attach ballot";
  case 12033: /* module 47 call 1 */
    return "Vote";
  case 12034: /* module 47 call 2 */
    return "Change end";
  case 12035: /* module 47 call 3 */
    return "Change meta";
  case 12036: /* module 47 call 4 */
    return "Change rcv";
  case 12037: /* module 47 call 5 */
    return "Remove ballot";
  case 12288: /* module 48 call 0 */
    return "Distribute";
  case 12289: /* module 48 call 1 */
    return "Claim";
  case 12290: /* module 48 call 2 */
    return "Push benefit";
  case 12291: /* module 48 call 3 */
    return "Reclaim";
  case 12292: /* module 48 call 4 */
    return "Remove distribution";
  case 12544: /* module 49 call 0 */
    return "Create checkpoint";
  case 12545: /* module 49 call 1 */
    return "Set schedules max complexity";
  case 12546: /* module 49 call 2 */
    return "Create schedule";
  case 12547: /* module 49 call 3 */
    return "Remove schedule";
  default:
    return NULL;
  }

  return NULL;
}

uint8_t _getMethod_NumItems(uint8_t moduleIdx, uint8_t callIdx,
                            pd_Method_t *method) {
  uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

  switch (callPrivIdx) {
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
  case 1024: /* module 4 call 0 */
    return 2;
  case 1025: /* module 4 call 1 */
    return 3;
  case 1026: /* module 4 call 2 */
    return 1;
  case 1027: /* module 4 call 3 */
    return 3;
  case 1028: /* module 4 call 4 */
    return 3;
  case 1029: /* module 4 call 5 */
    return 1;
  case 1536: /* module 6 call 0 */
    return 1;
  case 1792: /* module 7 call 0 */
    return 3;
  case 1793: /* module 7 call 1 */
    return 1;
  case 1794: /* module 7 call 2 */
    return 1;
  case 1795: /* module 7 call 3 */
    return 1;
  case 1796: /* module 7 call 4 */
    return 1;
  case 1797: /* module 7 call 5 */
    return 1;
  case 1798: /* module 7 call 6 */
    return 0;
  case 1799: /* module 7 call 7 */
    return 1;
  case 1800: /* module 7 call 8 */
    return 1;
  case 1801: /* module 7 call 9 */
    return 1;
  case 1802: /* module 7 call 10 */
    return 1;
  case 1803: /* module 7 call 11 */
    return 1;
  case 1804: /* module 7 call 12 */
    return 1;
  case 1805: /* module 7 call 13 */
    return 1;
  case 1806: /* module 7 call 14 */
    return 1;
  case 1807: /* module 7 call 15 */
    return 1;
  case 1808: /* module 7 call 16 */
    return 1;
  case 1809: /* module 7 call 17 */
    return 0;
  case 1810: /* module 7 call 18 */
    return 0;
  case 1811: /* module 7 call 19 */
    return 1;
  case 1812: /* module 7 call 20 */
    return 2;
  case 1813: /* module 7 call 21 */
    return 0;
  case 1814: /* module 7 call 22 */
    return 2;
  case 1815: /* module 7 call 23 */
    return 2;
  case 1816: /* module 7 call 24 */
    return 1;
  case 1817: /* module 7 call 25 */
    return 2;
  case 1818: /* module 7 call 26 */
    return 2;
  case 1819: /* module 7 call 27 */
    return 5;
  case 1820: /* module 7 call 28 */
    return 5;
  case 1821: /* module 7 call 29 */
    return 2;
  case 1822: /* module 7 call 30 */
    return 1;
  case 2304: /* module 9 call 0 */
    return 2;
  case 2305: /* module 9 call 1 */
    return 0;
  case 2560: /* module 10 call 0 */
    return 1;
  case 2816: /* module 11 call 0 */
    return 2;
  case 2817: /* module 11 call 1 */
    return 2;
  case 2818: /* module 11 call 2 */
    return 2;
  case 3072: /* module 12 call 0 */
    return 2;
  case 3073: /* module 12 call 1 */
    return 1;
  case 4096: /* module 16 call 0 */
    return 1;
  case 4097: /* module 16 call 1 */
    return 2;
  case 4098: /* module 16 call 2 */
    return 1;
  case 4099: /* module 16 call 3 */
    return 2;
  case 4352: /* module 17 call 0 */
    return 2;
  case 4353: /* module 17 call 1 */
    return 4;
  case 4354: /* module 17 call 2 */
    return 4;
  case 4355: /* module 17 call 3 */
    return 4;
  case 4356: /* module 17 call 4 */
    return 4;
  case 4357: /* module 17 call 5 */
    return 2;
  case 4358: /* module 17 call 6 */
    return 2;
  case 4359: /* module 17 call 7 */
    return 2;
  case 4360: /* module 17 call 8 */
    return 2;
  case 4361: /* module 17 call 9 */
    return 1;
  case 4362: /* module 17 call 10 */
    return 1;
  case 4363: /* module 17 call 11 */
    return 1;
  case 4364: /* module 17 call 12 */
    return 1;
  case 4365: /* module 17 call 13 */
    return 2;
  case 4366: /* module 17 call 14 */
    return 2;
  case 4367: /* module 17 call 15 */
    return 1;
  case 4368: /* module 17 call 16 */
    return 2;
  case 4369: /* module 17 call 17 */
    return 1;
  case 4370: /* module 17 call 18 */
    return 2;
  case 4864: /* module 19 call 0 */
    return 1;
  case 4865: /* module 19 call 1 */
    return 3;
  case 4866: /* module 19 call 2 */
    return 4;
  case 4867: /* module 19 call 3 */
    return 5;
  case 4868: /* module 19 call 4 */
    return 1;
  case 4869: /* module 19 call 5 */
    return 1;
  case 4870: /* module 19 call 6 */
    return 2;
  case 4871: /* module 19 call 7 */
    return 3;
  case 4872: /* module 19 call 8 */
    return 2;
  case 5120: /* module 20 call 0 */
    return 1;
  case 5121: /* module 20 call 1 */
    return 1;
  case 5376: /* module 21 call 0 */
    return 2;
  case 5377: /* module 21 call 1 */
    return 1;
  case 5378: /* module 21 call 2 */
    return 1;
  case 5379: /* module 21 call 3 */
    return 2;
  case 5380: /* module 21 call 4 */
    return 2;
  case 5381: /* module 21 call 5 */
    return 3;
  case 5632: /* module 22 call 0 */
    return 1;
  case 5633: /* module 22 call 1 */
    return 3;
  case 5634: /* module 22 call 2 */
    return 1;
  case 5635: /* module 22 call 3 */
    return 1;
  case 5636: /* module 22 call 4 */
    return 2;
  case 5637: /* module 22 call 5 */
    return 1;
  case 5638: /* module 22 call 6 */
    return 0;
  case 5888: /* module 23 call 0 */
    return 1;
  case 5889: /* module 23 call 1 */
    return 1;
  case 5890: /* module 23 call 2 */
    return 1;
  case 5891: /* module 23 call 3 */
    return 1;
  case 5892: /* module 23 call 4 */
    return 1;
  case 5893: /* module 23 call 5 */
    return 1;
  case 5894: /* module 23 call 6 */
    return 1;
  case 5895: /* module 23 call 7 */
    return 4;
  case 5896: /* module 23 call 8 */
    return 3;
  case 5897: /* module 23 call 9 */
    return 1;
  case 5898: /* module 23 call 10 */
    return 3;
  case 5899: /* module 23 call 11 */
    return 1;
  case 5900: /* module 23 call 12 */
    return 1;
  case 5901: /* module 23 call 13 */
    return 1;
  case 5902: /* module 23 call 14 */
    return 2;
  case 5903: /* module 23 call 15 */
    return 0;
  case 5904: /* module 23 call 16 */
    return 0;
  case 5905: /* module 23 call 17 */
    return 1;
  case 5906: /* module 23 call 18 */
    return 1;
  case 5907: /* module 23 call 19 */
    return 2;
  case 6144: /* module 24 call 0 */
    return 2;
  case 6145: /* module 24 call 1 */
    return 1;
  case 6146: /* module 24 call 2 */
    return 1;
  case 6147: /* module 24 call 3 */
    return 2;
  case 6148: /* module 24 call 4 */
    return 2;
  case 6149: /* module 24 call 5 */
    return 3;
  case 6400: /* module 25 call 0 */
    return 1;
  case 6401: /* module 25 call 1 */
    return 3;
  case 6402: /* module 25 call 2 */
    return 1;
  case 6403: /* module 25 call 3 */
    return 1;
  case 6404: /* module 25 call 4 */
    return 2;
  case 6405: /* module 25 call 5 */
    return 1;
  case 6406: /* module 25 call 6 */
    return 0;
  case 6656: /* module 26 call 0 */
    return 2;
  case 6657: /* module 26 call 1 */
    return 1;
  case 6658: /* module 26 call 2 */
    return 1;
  case 6659: /* module 26 call 3 */
    return 2;
  case 6660: /* module 26 call 4 */
    return 2;
  case 6661: /* module 26 call 5 */
    return 3;
  case 6912: /* module 27 call 0 */
    return 1;
  case 6913: /* module 27 call 1 */
    return 3;
  case 6914: /* module 27 call 2 */
    return 1;
  case 6915: /* module 27 call 3 */
    return 1;
  case 6916: /* module 27 call 4 */
    return 2;
  case 6917: /* module 27 call 5 */
    return 1;
  case 6918: /* module 27 call 6 */
    return 0;
  case 7168: /* module 28 call 0 */
    return 1;
  case 7169: /* module 28 call 1 */
    return 1;
  case 7170: /* module 28 call 2 */
    return 1;
  case 7171: /* module 28 call 3 */
    return 1;
  case 7172: /* module 28 call 4 */
    return 7;
  case 7173: /* module 28 call 5 */
    return 1;
  case 7174: /* module 28 call 6 */
    return 1;
  case 7175: /* module 28 call 7 */
    return 2;
  case 7176: /* module 28 call 8 */
    return 2;
  case 7177: /* module 28 call 9 */
    return 2;
  case 7178: /* module 28 call 10 */
    return 1;
  case 7179: /* module 28 call 11 */
    return 2;
  case 7180: /* module 28 call 12 */
    return 2;
  case 7181: /* module 28 call 13 */
    return 2;
  case 7182: /* module 28 call 14 */
    return 2;
  case 7183: /* module 28 call 15 */
    return 2;
  case 7184: /* module 28 call 16 */
    return 2;
  case 7185: /* module 28 call 17 */
    return 2;
  case 7186: /* module 28 call 18 */
    return 1;
  case 7187: /* module 28 call 19 */
    return 2;
  case 7188: /* module 28 call 20 */
    return 2;
  case 7189: /* module 28 call 21 */
    return 3;
  case 7424: /* module 29 call 0 */
    return 6;
  case 7425: /* module 29 call 1 */
    return 2;
  case 7426: /* module 29 call 2 */
    return 2;
  case 7427: /* module 29 call 3 */
    return 2;
  case 7680: /* module 30 call 0 */
    return 2;
  case 7681: /* module 30 call 1 */
    return 2;
  case 7682: /* module 30 call 2 */
    return 1;
  case 7683: /* module 30 call 3 */
    return 3;
  case 7684: /* module 30 call 4 */
    return 1;
  case 7685: /* module 30 call 5 */
    return 2;
  case 7686: /* module 30 call 6 */
    return 1;
  case 7687: /* module 30 call 7 */
    return 1;
  case 7688: /* module 30 call 8 */
    return 1;
  case 7689: /* module 30 call 9 */
    return 0;
  case 7690: /* module 30 call 10 */
    return 1;
  case 7691: /* module 30 call 11 */
    return 3;
  case 7692: /* module 30 call 12 */
    return 2;
  case 7693: /* module 30 call 13 */
    return 2;
  case 7694: /* module 30 call 14 */
    return 2;
  case 7695: /* module 30 call 15 */
    return 2;
  case 7696: /* module 30 call 16 */
    return 0;
  case 7697: /* module 30 call 17 */
    return 0;
  case 7698: /* module 30 call 18 */
    return 0;
  case 7699: /* module 30 call 19 */
    return 1;
  case 7700: /* module 30 call 20 */
    return 3;
  case 7701: /* module 30 call 21 */
    return 3;
  case 7702: /* module 30 call 22 */
    return 1;
  case 7703: /* module 30 call 23 */
    return 2;
  case 7704: /* module 30 call 24 */
    return 2;
  case 7705: /* module 30 call 25 */
    return 4;
  case 7706: /* module 30 call 26 */
    return 2;
  case 7707: /* module 30 call 27 */
    return 1;
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
  case 8448: /* module 33 call 0 */
    return 3;
  case 8449: /* module 33 call 1 */
    return 3;
  case 8450: /* module 33 call 2 */
    return 2;
  case 8704: /* module 34 call 0 */
    return 6;
  case 8705: /* module 34 call 1 */
    return 3;
  case 8706: /* module 34 call 2 */
    return 2;
  case 8707: /* module 34 call 3 */
    return 2;
  case 8960: /* module 35 call 0 */
    return 4;
  case 9216: /* module 36 call 0 */
    return 3;
  case 9217: /* module 36 call 1 */
    return 3;
  case 9218: /* module 36 call 2 */
    return 4;
  case 9219: /* module 36 call 3 */
    return 5;
  case 9220: /* module 36 call 4 */
    return 2;
  case 9221: /* module 36 call 5 */
    return 2;
  case 9222: /* module 36 call 6 */
    return 2;
  case 9223: /* module 36 call 7 */
    return 3;
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
    return 1;
  case 9472: /* module 37 call 0 */
    return 8;
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
  case 10240: /* module 40 call 0 */
    return 1;
  case 10241: /* module 40 call 1 */
    return 2;
  case 10496: /* module 41 call 0 */
    return 1;
  case 10497: /* module 41 call 1 */
    return 1;
  case 10498: /* module 41 call 2 */
    return 1;
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
  case 11008: /* module 43 call 0 */
    return 3;
  case 11009: /* module 43 call 1 */
    return 3;
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
    return 7;
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
    return 6;
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
  default:
    return 0;
  }

  return 0;
}

const char *_getMethod_ItemName(uint8_t moduleIdx, uint8_t callIdx,
                                uint8_t itemIdx) {
  uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

  switch (callPrivIdx) {
  case 0: /* module 0 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ratio";
    default:
      return NULL;
    }
  case 1: /* module 0 call 1 */
    switch (itemIdx) {
    case 0:
      return "Remark";
    default:
      return NULL;
    }
  case 2: /* module 0 call 2 */
    switch (itemIdx) {
    case 0:
      return "Pages";
    default:
      return NULL;
    }
  case 3: /* module 0 call 3 */
    switch (itemIdx) {
    case 0:
      return "Code";
    default:
      return NULL;
    }
  case 4: /* module 0 call 4 */
    switch (itemIdx) {
    case 0:
      return "Code";
    default:
      return NULL;
    }
  case 5: /* module 0 call 5 */
    switch (itemIdx) {
    case 0:
      return "Changes trie config";
    default:
      return NULL;
    }
  case 6: /* module 0 call 6 */
    switch (itemIdx) {
    case 0:
      return "Items";
    default:
      return NULL;
    }
  case 7: /* module 0 call 7 */
    switch (itemIdx) {
    case 0:
      return "Keys";
    default:
      return NULL;
    }
  case 8: /* module 0 call 8 */
    switch (itemIdx) {
    case 0:
      return "Prefix";
    case 1:
      return "Subkeys";
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
      return "Equivocation proof";
    case 1:
      return "Key owner proof";
    default:
      return NULL;
    }
  case 257: /* module 1 call 1 */
    switch (itemIdx) {
    case 0:
      return "Equivocation proof";
    case 1:
      return "Key owner proof";
    default:
      return NULL;
    }
  case 512: /* module 2 call 0 */
    switch (itemIdx) {
    case 0:
      return "Now";
    default:
      return NULL;
    }
  case 768: /* module 3 call 0 */
    switch (itemIdx) {
    case 0:
      return "Index";
    default:
      return NULL;
    }
  case 769: /* module 3 call 1 */
    switch (itemIdx) {
    case 0:
      return "New";
    case 1:
      return "Index";
    default:
      return NULL;
    }
  case 770: /* module 3 call 2 */
    switch (itemIdx) {
    case 0:
      return "Index";
    default:
      return NULL;
    }
  case 771: /* module 3 call 3 */
    switch (itemIdx) {
    case 0:
      return "New";
    case 1:
      return "Index";
    case 2:
      return "Freeze";
    default:
      return NULL;
    }
  case 772: /* module 3 call 4 */
    switch (itemIdx) {
    case 0:
      return "Index";
    default:
      return NULL;
    }
  case 1024: /* module 4 call 0 */
    switch (itemIdx) {
    case 0:
      return "Dest";
    case 1:
      return "Value";
    default:
      return NULL;
    }
  case 1025: /* module 4 call 1 */
    switch (itemIdx) {
    case 0:
      return "Dest";
    case 1:
      return "Value";
    case 2:
      return "Memo";
    default:
      return NULL;
    }
  case 1026: /* module 4 call 2 */
    switch (itemIdx) {
    case 0:
      return "Value";
    default:
      return NULL;
    }
  case 1027: /* module 4 call 3 */
    switch (itemIdx) {
    case 0:
      return "Who";
    case 1:
      return "New free";
    case 2:
      return "New reserved";
    default:
      return NULL;
    }
  case 1028: /* module 4 call 4 */
    switch (itemIdx) {
    case 0:
      return "Source";
    case 1:
      return "Dest";
    case 2:
      return "Value";
    default:
      return NULL;
    }
  case 1029: /* module 4 call 5 */
    switch (itemIdx) {
    case 0:
      return "Amount";
    default:
      return NULL;
    }
  case 1536: /* module 6 call 0 */
    switch (itemIdx) {
    case 0:
      return "New uncles";
    default:
      return NULL;
    }
  case 1792: /* module 7 call 0 */
    switch (itemIdx) {
    case 0:
      return "Controller";
    case 1:
      return "Value";
    case 2:
      return "Payee";
    default:
      return NULL;
    }
  case 1793: /* module 7 call 1 */
    switch (itemIdx) {
    case 0:
      return "Max additional";
    default:
      return NULL;
    }
  case 1794: /* module 7 call 2 */
    switch (itemIdx) {
    case 0:
      return "Value";
    default:
      return NULL;
    }
  case 1795: /* module 7 call 3 */
    switch (itemIdx) {
    case 0:
      return "Num slashing spans";
    default:
      return NULL;
    }
  case 1796: /* module 7 call 4 */
    switch (itemIdx) {
    case 0:
      return "Prefs";
    default:
      return NULL;
    }
  case 1797: /* module 7 call 5 */
    switch (itemIdx) {
    case 0:
      return "Targets";
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
      return "Payee";
    default:
      return NULL;
    }
  case 1800: /* module 7 call 8 */
    switch (itemIdx) {
    case 0:
      return "Controller";
    default:
      return NULL;
    }
  case 1801: /* module 7 call 9 */
    switch (itemIdx) {
    case 0:
      return "New";
    default:
      return NULL;
    }
  case 1802: /* module 7 call 10 */
    switch (itemIdx) {
    case 0:
      return "Additional";
    default:
      return NULL;
    }
  case 1803: /* module 7 call 11 */
    switch (itemIdx) {
    case 0:
      return "Factor";
    default:
      return NULL;
    }
  case 1804: /* module 7 call 12 */
    switch (itemIdx) {
    case 0:
      return "Identity";
    default:
      return NULL;
    }
  case 1805: /* module 7 call 13 */
    switch (itemIdx) {
    case 0:
      return "Identity";
    default:
      return NULL;
    }
  case 1806: /* module 7 call 14 */
    switch (itemIdx) {
    case 0:
      return "Targets";
    default:
      return NULL;
    }
  case 1807: /* module 7 call 15 */
    switch (itemIdx) {
    case 0:
      return "New cap";
    default:
      return NULL;
    }
  case 1808: /* module 7 call 16 */
    switch (itemIdx) {
    case 0:
      return "New value";
    default:
      return NULL;
    }
  case 1809: /* module 7 call 17 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 1810: /* module 7 call 18 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 1811: /* module 7 call 19 */
    switch (itemIdx) {
    case 0:
      return "Validators";
    default:
      return NULL;
    }
  case 1812: /* module 7 call 20 */
    switch (itemIdx) {
    case 0:
      return "Stash";
    case 1:
      return "Num slashing spans";
    default:
      return NULL;
    }
  case 1813: /* module 7 call 21 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 1814: /* module 7 call 22 */
    switch (itemIdx) {
    case 0:
      return "Era";
    case 1:
      return "Slash indices";
    default:
      return NULL;
    }
  case 1815: /* module 7 call 23 */
    switch (itemIdx) {
    case 0:
      return "Validator stash";
    case 1:
      return "Era";
    default:
      return NULL;
    }
  case 1816: /* module 7 call 24 */
    switch (itemIdx) {
    case 0:
      return "Value";
    default:
      return NULL;
    }
  case 1817: /* module 7 call 25 */
    switch (itemIdx) {
    case 0:
      return "New history depth";
    case 1:
      return "Era items deleted";
    default:
      return NULL;
    }
  case 1818: /* module 7 call 26 */
    switch (itemIdx) {
    case 0:
      return "Stash";
    case 1:
      return "Num slashing spans";
    default:
      return NULL;
    }
  case 1819: /* module 7 call 27 */
    switch (itemIdx) {
    case 0:
      return "Winners";
    case 1:
      return "Compact";
    case 2:
      return "Score";
    case 3:
      return "Era";
    case 4:
      return "Size";
    default:
      return NULL;
    }
  case 1820: /* module 7 call 28 */
    switch (itemIdx) {
    case 0:
      return "Winners";
    case 1:
      return "Compact";
    case 2:
      return "Score";
    case 3:
      return "Era";
    case 4:
      return "Size";
    default:
      return NULL;
    }
  case 1821: /* module 7 call 29 */
    switch (itemIdx) {
    case 0:
      return "Validator stash";
    case 1:
      return "Era";
    default:
      return NULL;
    }
  case 1822: /* module 7 call 30 */
    switch (itemIdx) {
    case 0:
      return "Slashing switch";
    default:
      return NULL;
    }
  case 2304: /* module 9 call 0 */
    switch (itemIdx) {
    case 0:
      return "Keys";
    case 1:
      return "Proof";
    default:
      return NULL;
    }
  case 2305: /* module 9 call 1 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 2560: /* module 10 call 0 */
    switch (itemIdx) {
    case 0:
      return "Hint";
    default:
      return NULL;
    }
  case 2816: /* module 11 call 0 */
    switch (itemIdx) {
    case 0:
      return "Equivocation proof";
    case 1:
      return "Key owner proof";
    default:
      return NULL;
    }
  case 2817: /* module 11 call 1 */
    switch (itemIdx) {
    case 0:
      return "Equivocation proof";
    case 1:
      return "Key owner proof";
    default:
      return NULL;
    }
  case 2818: /* module 11 call 2 */
    switch (itemIdx) {
    case 0:
      return "Delay";
    case 1:
      return "Best finalized block number";
    default:
      return NULL;
    }
  case 3072: /* module 12 call 0 */
    switch (itemIdx) {
    case 0:
      return "Heartbeat";
    case 1:
      return "Signature";
    default:
      return NULL;
    }
  case 3073: /* module 12 call 1 */
    switch (itemIdx) {
    case 0:
      return "Params";
    default:
      return NULL;
    }
  case 4096: /* module 16 call 0 */
    switch (itemIdx) {
    case 0:
      return "Call";
    default:
      return NULL;
    }
  case 4097: /* module 16 call 1 */
    switch (itemIdx) {
    case 0:
      return "Call";
    case 1:
      return "Weight";
    default:
      return NULL;
    }
  case 4098: /* module 16 call 2 */
    switch (itemIdx) {
    case 0:
      return "New";
    default:
      return NULL;
    }
  case 4099: /* module 16 call 3 */
    switch (itemIdx) {
    case 0:
      return "Who";
    case 1:
      return "Call";
    default:
      return NULL;
    }
  case 4352: /* module 17 call 0 */
    switch (itemIdx) {
    case 0:
      return "Signers";
    case 1:
      return "Sigs required";
    default:
      return NULL;
    }
  case 4353: /* module 17 call 1 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal";
    case 2:
      return "Expiry";
    case 3:
      return "Auto close";
    default:
      return NULL;
    }
  case 4354: /* module 17 call 2 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal";
    case 2:
      return "Expiry";
    case 3:
      return "Auto close";
    default:
      return NULL;
    }
  case 4355: /* module 17 call 3 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal";
    case 2:
      return "Expiry";
    case 3:
      return "Auto close";
    default:
      return NULL;
    }
  case 4356: /* module 17 call 4 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal";
    case 2:
      return "Expiry";
    case 3:
      return "Auto close";
    default:
      return NULL;
    }
  case 4357: /* module 17 call 5 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal id";
    default:
      return NULL;
    }
  case 4358: /* module 17 call 6 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal id";
    default:
      return NULL;
    }
  case 4359: /* module 17 call 7 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal id";
    default:
      return NULL;
    }
  case 4360: /* module 17 call 8 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Proposal id";
    default:
      return NULL;
    }
  case 4361: /* module 17 call 9 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 4362: /* module 17 call 10 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 4363: /* module 17 call 11 */
    switch (itemIdx) {
    case 0:
      return "Signer";
    default:
      return NULL;
    }
  case 4364: /* module 17 call 12 */
    switch (itemIdx) {
    case 0:
      return "Signer";
    default:
      return NULL;
    }
  case 4365: /* module 17 call 13 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Signers";
    default:
      return NULL;
    }
  case 4366: /* module 17 call 14 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Signers";
    default:
      return NULL;
    }
  case 4367: /* module 17 call 15 */
    switch (itemIdx) {
    case 0:
      return "Sigs required";
    default:
      return NULL;
    }
  case 4368: /* module 17 call 16 */
    switch (itemIdx) {
    case 0:
      return "Signers";
    case 1:
      return "Sigs required";
    default:
      return NULL;
    }
  case 4369: /* module 17 call 17 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    default:
      return NULL;
    }
  case 4370: /* module 17 call 18 */
    switch (itemIdx) {
    case 0:
      return "Multisig";
    case 1:
      return "Optional cdd auth id";
    default:
      return NULL;
    }
  case 4864: /* module 19 call 0 */
    switch (itemIdx) {
    case 0:
      return "Schedule";
    default:
      return NULL;
    }
  case 4865: /* module 19 call 1 */
    switch (itemIdx) {
    case 0:
      return "Meta info";
    case 1:
      return "Instantiation fee";
    case 2:
      return "Code";
    default:
      return NULL;
    }
  case 4866: /* module 19 call 2 */
    switch (itemIdx) {
    case 0:
      return "Dest";
    case 1:
      return "Value";
    case 2:
      return "Gas limit";
    case 3:
      return "Data";
    default:
      return NULL;
    }
  case 4867: /* module 19 call 3 */
    switch (itemIdx) {
    case 0:
      return "Endowment";
    case 1:
      return "Gas limit";
    case 2:
      return "Code hash";
    case 3:
      return "Data";
    case 4:
      return "Max fee";
    default:
      return NULL;
    }
  case 4868: /* module 19 call 4 */
    switch (itemIdx) {
    case 0:
      return "Code hash";
    default:
      return NULL;
    }
  case 4869: /* module 19 call 5 */
    switch (itemIdx) {
    case 0:
      return "Code hash";
    default:
      return NULL;
    }
  case 4870: /* module 19 call 6 */
    switch (itemIdx) {
    case 0:
      return "Code hash";
    case 1:
      return "New owner";
    default:
      return NULL;
    }
  case 4871: /* module 19 call 7 */
    switch (itemIdx) {
    case 0:
      return "Code hash";
    case 1:
      return "New instantiation fee";
    case 2:
      return "New usage fee";
    default:
      return NULL;
    }
  case 4872: /* module 19 call 8 */
    switch (itemIdx) {
    case 0:
      return "Code hash";
    case 1:
      return "New url";
    default:
      return NULL;
    }
  case 5120: /* module 20 call 0 */
    switch (itemIdx) {
    case 0:
      return "Beneficiaries";
    default:
      return NULL;
    }
  case 5121: /* module 20 call 1 */
    switch (itemIdx) {
    case 0:
      return "Amount";
    default:
      return NULL;
    }
  case 5376: /* module 21 call 0 */
    switch (itemIdx) {
    case 0:
      return "N";
    case 1:
      return "D";
    default:
      return NULL;
    }
  case 5377: /* module 21 call 1 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 5378: /* module 21 call 2 */
    switch (itemIdx) {
    case 0:
      return "Expiry";
    default:
      return NULL;
    }
  case 5379: /* module 21 call 3 */
    switch (itemIdx) {
    case 0:
      return "Proposal";
    case 1:
      return "Index";
    default:
      return NULL;
    }
  case 5380: /* module 21 call 4 */
    switch (itemIdx) {
    case 0:
      return "Approve";
    case 1:
      return "Call";
    default:
      return NULL;
    }
  case 5381: /* module 21 call 5 */
    switch (itemIdx) {
    case 0:
      return "Proposal";
    case 1:
      return "Index";
    case 2:
      return "Approve";
    default:
      return NULL;
    }
  case 5632: /* module 22 call 0 */
    switch (itemIdx) {
    case 0:
      return "Limit";
    default:
      return NULL;
    }
  case 5633: /* module 22 call 1 */
    switch (itemIdx) {
    case 0:
      return "Who";
    case 1:
      return "Expiry";
    case 2:
      return "At";
    default:
      return NULL;
    }
  case 5634: /* module 22 call 2 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 5635: /* module 22 call 3 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 5636: /* module 22 call 4 */
    switch (itemIdx) {
    case 0:
      return "Remove";
    case 1:
      return "Add";
    default:
      return NULL;
    }
  case 5637: /* module 22 call 5 */
    switch (itemIdx) {
    case 0:
      return "Members";
    default:
      return NULL;
    }
  case 5638: /* module 22 call 6 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 5888: /* module 23 call 0 */
    switch (itemIdx) {
    case 0:
      return "New value";
    default:
      return NULL;
    }
  case 5889: /* module 23 call 1 */
    switch (itemIdx) {
    case 0:
      return "Deposit";
    default:
      return NULL;
    }
  case 5890: /* module 23 call 2 */
    switch (itemIdx) {
    case 0:
      return "Duration";
    default:
      return NULL;
    }
  case 5891: /* module 23 call 3 */
    switch (itemIdx) {
    case 0:
      return "Duration";
    default:
      return NULL;
    }
  case 5892: /* module 23 call 4 */
    switch (itemIdx) {
    case 0:
      return "Expiry";
    default:
      return NULL;
    }
  case 5893: /* module 23 call 5 */
    switch (itemIdx) {
    case 0:
      return "New max";
    default:
      return NULL;
    }
  case 5894: /* module 23 call 6 */
    switch (itemIdx) {
    case 0:
      return "New max";
    default:
      return NULL;
    }
  case 5895: /* module 23 call 7 */
    switch (itemIdx) {
    case 0:
      return "Proposal";
    case 1:
      return "Deposit";
    case 2:
      return "Url";
    case 3:
      return "Description";
    default:
      return NULL;
    }
  case 5896: /* module 23 call 8 */
    switch (itemIdx) {
    case 0:
      return "Id";
    case 1:
      return "Url";
    case 2:
      return "Description";
    default:
      return NULL;
    }
  case 5897: /* module 23 call 9 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 5898: /* module 23 call 10 */
    switch (itemIdx) {
    case 0:
      return "Id";
    case 1:
      return "Aye or nay";
    case 2:
      return "Deposit";
    default:
      return NULL;
    }
  case 5899: /* module 23 call 11 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 5900: /* module 23 call 12 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 5901: /* module 23 call 13 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 5902: /* module 23 call 14 */
    switch (itemIdx) {
    case 0:
      return "Id";
    case 1:
      return "Until";
    default:
      return NULL;
    }
  case 5903: /* module 23 call 15 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 5904: /* module 23 call 16 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 5905: /* module 23 call 17 */
    switch (itemIdx) {
    case 0:
      return "Results";
    default:
      return NULL;
    }
  case 5906: /* module 23 call 18 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 5907: /* module 23 call 19 */
    switch (itemIdx) {
    case 0:
      return "Did";
    case 1:
      return "Id";
    default:
      return NULL;
    }
  case 6144: /* module 24 call 0 */
    switch (itemIdx) {
    case 0:
      return "N";
    case 1:
      return "D";
    default:
      return NULL;
    }
  case 6145: /* module 24 call 1 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 6146: /* module 24 call 2 */
    switch (itemIdx) {
    case 0:
      return "Expiry";
    default:
      return NULL;
    }
  case 6147: /* module 24 call 3 */
    switch (itemIdx) {
    case 0:
      return "Proposal";
    case 1:
      return "Index";
    default:
      return NULL;
    }
  case 6148: /* module 24 call 4 */
    switch (itemIdx) {
    case 0:
      return "Approve";
    case 1:
      return "Call";
    default:
      return NULL;
    }
  case 6149: /* module 24 call 5 */
    switch (itemIdx) {
    case 0:
      return "Proposal";
    case 1:
      return "Index";
    case 2:
      return "Approve";
    default:
      return NULL;
    }
  case 6400: /* module 25 call 0 */
    switch (itemIdx) {
    case 0:
      return "Limit";
    default:
      return NULL;
    }
  case 6401: /* module 25 call 1 */
    switch (itemIdx) {
    case 0:
      return "Who";
    case 1:
      return "Expiry";
    case 2:
      return "At";
    default:
      return NULL;
    }
  case 6402: /* module 25 call 2 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 6403: /* module 25 call 3 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 6404: /* module 25 call 4 */
    switch (itemIdx) {
    case 0:
      return "Remove";
    case 1:
      return "Add";
    default:
      return NULL;
    }
  case 6405: /* module 25 call 5 */
    switch (itemIdx) {
    case 0:
      return "Members";
    default:
      return NULL;
    }
  case 6406: /* module 25 call 6 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 6656: /* module 26 call 0 */
    switch (itemIdx) {
    case 0:
      return "N";
    case 1:
      return "D";
    default:
      return NULL;
    }
  case 6657: /* module 26 call 1 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 6658: /* module 26 call 2 */
    switch (itemIdx) {
    case 0:
      return "Expiry";
    default:
      return NULL;
    }
  case 6659: /* module 26 call 3 */
    switch (itemIdx) {
    case 0:
      return "Proposal";
    case 1:
      return "Index";
    default:
      return NULL;
    }
  case 6660: /* module 26 call 4 */
    switch (itemIdx) {
    case 0:
      return "Approve";
    case 1:
      return "Call";
    default:
      return NULL;
    }
  case 6661: /* module 26 call 5 */
    switch (itemIdx) {
    case 0:
      return "Proposal";
    case 1:
      return "Index";
    case 2:
      return "Approve";
    default:
      return NULL;
    }
  case 6912: /* module 27 call 0 */
    switch (itemIdx) {
    case 0:
      return "Limit";
    default:
      return NULL;
    }
  case 6913: /* module 27 call 1 */
    switch (itemIdx) {
    case 0:
      return "Who";
    case 1:
      return "Expiry";
    case 2:
      return "At";
    default:
      return NULL;
    }
  case 6914: /* module 27 call 2 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 6915: /* module 27 call 3 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 6916: /* module 27 call 4 */
    switch (itemIdx) {
    case 0:
      return "Remove";
    case 1:
      return "Add";
    default:
      return NULL;
    }
  case 6917: /* module 27 call 5 */
    switch (itemIdx) {
    case 0:
      return "Members";
    default:
      return NULL;
    }
  case 6918: /* module 27 call 6 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 7168: /* module 28 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 7169: /* module 28 call 1 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 7170: /* module 28 call 2 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 7171: /* module 28 call 3 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 7172: /* module 28 call 4 */
    switch (itemIdx) {
    case 0:
      return "Name";
    case 1:
      return "Ticker";
    case 2:
      return "Total supply";
    case 3:
      return "Divisible";
    case 4:
      return "Asset type";
    case 5:
      return "Identifiers";
    case 6:
      return "Funding round";
    default:
      return NULL;
    }
  case 7173: /* module 28 call 5 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 7174: /* module 28 call 6 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 7175: /* module 28 call 7 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Name";
    default:
      return NULL;
    }
  case 7176: /* module 28 call 8 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Value";
    default:
      return NULL;
    }
  case 7177: /* module 28 call 9 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Value";
    default:
      return NULL;
    }
  case 7178: /* module 28 call 10 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 7179: /* module 28 call 11 */
    switch (itemIdx) {
    case 0:
      return "Docs";
    case 1:
      return "Ticker";
    default:
      return NULL;
    }
  case 7180: /* module 28 call 12 */
    switch (itemIdx) {
    case 0:
      return "Ids";
    case 1:
      return "Ticker";
    default:
      return NULL;
    }
  case 7181: /* module 28 call 13 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Name";
    default:
      return NULL;
    }
  case 7182: /* module 28 call 14 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Identifiers";
    default:
      return NULL;
    }
  case 7183: /* module 28 call 15 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Extension details";
    default:
      return NULL;
    }
  case 7184: /* module 28 call 16 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Extension id";
    default:
      return NULL;
    }
  case 7185: /* module 28 call 17 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Extension id";
    default:
      return NULL;
    }
  case 7186: /* module 28 call 18 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 7187: /* module 28 call 19 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Extension id";
    default:
      return NULL;
    }
  case 7188: /* module 28 call 20 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Ethereum signature";
    default:
      return NULL;
    }
  case 7189: /* module 28 call 21 */
    switch (itemIdx) {
    case 0:
      return "Classic ticker import";
    case 1:
      return "Contract did";
    case 2:
      return "Config";
    default:
      return NULL;
    }
  case 7424: /* module 29 call 0 */
    switch (itemIdx) {
    case 0:
      return "Amount";
    case 1:
      return "Ticker";
    case 2:
      return "Matures at";
    case 3:
      return "Expires at";
    case 4:
      return "Payout ticker";
    case 5:
      return "Checkpoint id";
    default:
      return NULL;
    }
  case 7425: /* module 29 call 1 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Dividend id";
    default:
      return NULL;
    }
  case 7426: /* module 29 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Dividend id";
    default:
      return NULL;
    }
  case 7427: /* module 29 call 3 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Dividend id";
    default:
      return NULL;
    }
  case 7680: /* module 30 call 0 */
    switch (itemIdx) {
    case 0:
      return "Uid";
    case 1:
      return "Secondary keys";
    default:
      return NULL;
    }
  case 7681: /* module 30 call 1 */
    switch (itemIdx) {
    case 0:
      return "Target account";
    case 1:
      return "Secondary keys";
    default:
      return NULL;
    }
  case 7682: /* module 30 call 2 */
    switch (itemIdx) {
    case 0:
      return "Target account";
    default:
      return NULL;
    }
  case 7683: /* module 30 call 3 */
    switch (itemIdx) {
    case 0:
      return "Cdd";
    case 1:
      return "Disable from";
    case 2:
      return "Expiry";
    default:
      return NULL;
    }
  case 7684: /* module 30 call 4 */
    switch (itemIdx) {
    case 0:
      return "Signers to remove";
    default:
      return NULL;
    }
  case 7685: /* module 30 call 5 */
    switch (itemIdx) {
    case 0:
      return "Rotation auth id";
    case 1:
      return "Optional cdd auth id";
    default:
      return NULL;
    }
  case 7686: /* module 30 call 6 */
    switch (itemIdx) {
    case 0:
      return "Auth required";
    default:
      return NULL;
    }
  case 7687: /* module 30 call 7 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 7688: /* module 30 call 8 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 7689: /* module 30 call 9 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 7690: /* module 30 call 10 */
    switch (itemIdx) {
    case 0:
      return "Did";
    default:
      return NULL;
    }
  case 7691: /* module 30 call 11 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Claim";
    case 2:
      return "Expiry";
    default:
      return NULL;
    }
  case 7692: /* module 30 call 12 */
    switch (itemIdx) {
    case 0:
      return "Target did";
    case 1:
      return "Proposal";
    default:
      return NULL;
    }
  case 7693: /* module 30 call 13 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Claim";
    default:
      return NULL;
    }
  case 7694: /* module 30 call 14 */
    switch (itemIdx) {
    case 0:
      return "Signer";
    case 1:
      return "Permissions";
    default:
      return NULL;
    }
  case 7695: /* module 30 call 15 */
    switch (itemIdx) {
    case 0:
      return "Signer";
    case 1:
      return "Permissions";
    default:
      return NULL;
    }
  case 7696: /* module 30 call 16 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 7697: /* module 30 call 17 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 7698: /* module 30 call 18 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 7699: /* module 30 call 19 */
    switch (itemIdx) {
    case 0:
      return "Of";
    default:
      return NULL;
    }
  case 7700: /* module 30 call 20 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Authorization data";
    case 2:
      return "Expiry";
    default:
      return NULL;
    }
  case 7701: /* module 30 call 21 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Auth id";
    case 2:
      return "Auth issuer pays";
    default:
      return NULL;
    }
  case 7702: /* module 30 call 22 */
    switch (itemIdx) {
    case 0:
      return "Auth id";
    default:
      return NULL;
    }
  case 7703: /* module 30 call 23 */
    switch (itemIdx) {
    case 0:
      return "Additional keys";
    case 1:
      return "Expires at";
    default:
      return NULL;
    }
  case 7704: /* module 30 call 24 */
    switch (itemIdx) {
    case 0:
      return "Signer";
    case 1:
      return "Auth";
    default:
      return NULL;
    }
  case 7705: /* module 30 call 25 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Claim";
    case 2:
      return "Proof";
    case 3:
      return "Expiry";
    default:
      return NULL;
    }
  case 7706: /* module 30 call 26 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Expiry";
    default:
      return NULL;
    }
  case 7707: /* module 30 call 27 */
    switch (itemIdx) {
    case 0:
      return "Target";
    default:
      return NULL;
    }
  case 7936: /* module 31 call 0 */
    switch (itemIdx) {
    case 0:
      return "Controller";
    default:
      return NULL;
    }
  case 7937: /* module 31 call 1 */
    switch (itemIdx) {
    case 0:
      return "Admin";
    default:
      return NULL;
    }
  case 7938: /* module 31 call 2 */
    switch (itemIdx) {
    case 0:
      return "Timelock";
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
      return "Amount";
    case 1:
      return "Duration";
    default:
      return NULL;
    }
  case 7942: /* module 31 call 6 */
    switch (itemIdx) {
    case 0:
      return "Exempted";
    default:
      return NULL;
    }
  case 7943: /* module 31 call 7 */
    switch (itemIdx) {
    case 0:
      return "Bridge tx";
    default:
      return NULL;
    }
  case 7944: /* module 31 call 8 */
    switch (itemIdx) {
    case 0:
      return "Bridge txs";
    default:
      return NULL;
    }
  case 7945: /* module 31 call 9 */
    switch (itemIdx) {
    case 0:
      return "Bridge tx";
    default:
      return NULL;
    }
  case 7946: /* module 31 call 10 */
    switch (itemIdx) {
    case 0:
      return "Bridge tx";
    default:
      return NULL;
    }
  case 7947: /* module 31 call 11 */
    switch (itemIdx) {
    case 0:
      return "Bridge txs";
    default:
      return NULL;
    }
  case 7948: /* module 31 call 12 */
    switch (itemIdx) {
    case 0:
      return "Bridge txs";
    default:
      return NULL;
    }
  case 7949: /* module 31 call 13 */
    switch (itemIdx) {
    case 0:
      return "Bridge tx";
    default:
      return NULL;
    }
  case 8192: /* module 32 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Sender conditions";
    case 2:
      return "Receiver conditions";
    default:
      return NULL;
    }
  case 8193: /* module 32 call 1 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Id";
    default:
      return NULL;
    }
  case 8194: /* module 32 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Asset compliance";
    default:
      return NULL;
    }
  case 8195: /* module 32 call 3 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 8196: /* module 32 call 4 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 8197: /* module 32 call 5 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 8198: /* module 32 call 6 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Issuer";
    default:
      return NULL;
    }
  case 8199: /* module 32 call 7 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Issuer";
    default:
      return NULL;
    }
  case 8200: /* module 32 call 8 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "New req";
    default:
      return NULL;
    }
  case 8448: /* module 33 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Ballot name";
    case 2:
      return "Ballot details";
    default:
      return NULL;
    }
  case 8449: /* module 33 call 1 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Ballot name";
    case 2:
      return "Votes";
    default:
      return NULL;
    }
  case 8450: /* module 33 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Ballot name";
    default:
      return NULL;
    }
  case 8704: /* module 34 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Beneficiary did";
    case 2:
      return "Cap";
    case 3:
      return "Rate";
    case 4:
      return "Start date";
    case 5:
      return "End date";
    default:
      return NULL;
    }
  case 8705: /* module 34 call 1 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Sto id";
    case 2:
      return "Value";
    default:
      return NULL;
    }
  case 8706: /* module 34 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Sto id";
    default:
      return NULL;
    }
  case 8707: /* module 34 call 3 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Sto id";
    default:
      return NULL;
    }
  case 8960: /* module 35 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Tm";
    case 2:
      return "Asset holder did";
    case 3:
      return "Exempted";
    default:
      return NULL;
    }
  case 9216: /* module 36 call 0 */
    switch (itemIdx) {
    case 0:
      return "Details";
    case 1:
      return "Signers";
    case 2:
      return "Venue type";
    default:
      return NULL;
    }
  case 9217: /* module 36 call 1 */
    switch (itemIdx) {
    case 0:
      return "Venue id";
    case 1:
      return "Details";
    case 2:
      return "Venue type";
    default:
      return NULL;
    }
  case 9218: /* module 36 call 2 */
    switch (itemIdx) {
    case 0:
      return "Venue id";
    case 1:
      return "Settlement type";
    case 2:
      return "Valid from";
    case 3:
      return "Legs";
    default:
      return NULL;
    }
  case 9219: /* module 36 call 3 */
    switch (itemIdx) {
    case 0:
      return "Venue id";
    case 1:
      return "Settlement type";
    case 2:
      return "Valid from";
    case 3:
      return "Legs";
    case 4:
      return "Portfolios";
    default:
      return NULL;
    }
  case 9220: /* module 36 call 4 */
    switch (itemIdx) {
    case 0:
      return "Instruction id";
    case 1:
      return "Portfolios";
    default:
      return NULL;
    }
  case 9221: /* module 36 call 5 */
    switch (itemIdx) {
    case 0:
      return "Instruction id";
    case 1:
      return "Portfolios";
    default:
      return NULL;
    }
  case 9222: /* module 36 call 6 */
    switch (itemIdx) {
    case 0:
      return "Instruction id";
    case 1:
      return "Portfolios";
    default:
      return NULL;
    }
  case 9223: /* module 36 call 7 */
    switch (itemIdx) {
    case 0:
      return "Instruction id";
    case 1:
      return "Receipt details";
    case 2:
      return "Portfolios";
    default:
      return NULL;
    }
  case 9224: /* module 36 call 8 */
    switch (itemIdx) {
    case 0:
      return "Instruction id";
    case 1:
      return "Receipt details";
    default:
      return NULL;
    }
  case 9225: /* module 36 call 9 */
    switch (itemIdx) {
    case 0:
      return "Instruction id";
    case 1:
      return "Leg id";
    default:
      return NULL;
    }
  case 9226: /* module 36 call 10 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Enabled";
    default:
      return NULL;
    }
  case 9227: /* module 36 call 11 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Venues";
    default:
      return NULL;
    }
  case 9228: /* module 36 call 12 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Venues";
    default:
      return NULL;
    }
  case 9229: /* module 36 call 13 */
    switch (itemIdx) {
    case 0:
      return "Instruction id";
    default:
      return NULL;
    }
  case 9472: /* module 37 call 0 */
    switch (itemIdx) {
    case 0:
      return "Offering portfolio";
    case 1:
      return "Offering asset";
    case 2:
      return "Raising portfolio";
    case 3:
      return "Raising asset";
    case 4:
      return "Tiers";
    case 5:
      return "Venue id";
    case 6:
      return "Start";
    case 7:
      return "End";
    default:
      return NULL;
    }
  case 9473: /* module 37 call 1 */
    switch (itemIdx) {
    case 0:
      return "Investment portfolio";
    case 1:
      return "Funding portfolio";
    case 2:
      return "Offering asset";
    case 3:
      return "Fundraiser id";
    case 4:
      return "Investment amount";
    case 5:
      return "Max price";
    case 6:
      return "Receipt";
    default:
      return NULL;
    }
  case 9474: /* module 37 call 2 */
    switch (itemIdx) {
    case 0:
      return "Offering asset";
    case 1:
      return "Fundraiser id";
    default:
      return NULL;
    }
  case 9475: /* module 37 call 3 */
    switch (itemIdx) {
    case 0:
      return "Offering asset";
    case 1:
      return "Fundraiser id";
    default:
      return NULL;
    }
  case 9476: /* module 37 call 4 */
    switch (itemIdx) {
    case 0:
      return "Offering asset";
    case 1:
      return "Fundraiser id";
    case 2:
      return "Start";
    case 3:
      return "End";
    default:
      return NULL;
    }
  case 9477: /* module 37 call 5 */
    switch (itemIdx) {
    case 0:
      return "Offering asset";
    case 1:
      return "Fundraiser id";
    default:
      return NULL;
    }
  case 9728: /* module 38 call 0 */
    switch (itemIdx) {
    case 0:
      return "Limit";
    default:
      return NULL;
    }
  case 9729: /* module 38 call 1 */
    switch (itemIdx) {
    case 0:
      return "Who";
    case 1:
      return "Expiry";
    case 2:
      return "At";
    default:
      return NULL;
    }
  case 9730: /* module 38 call 2 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 9731: /* module 38 call 3 */
    switch (itemIdx) {
    case 0:
      return "Who";
    default:
      return NULL;
    }
  case 9732: /* module 38 call 4 */
    switch (itemIdx) {
    case 0:
      return "Remove";
    case 1:
      return "Add";
    default:
      return NULL;
    }
  case 9733: /* module 38 call 5 */
    switch (itemIdx) {
    case 0:
      return "Members";
    default:
      return NULL;
    }
  case 9734: /* module 38 call 6 */
    switch (itemIdx) {
    default:
      return NULL;
    }
  case 10240: /* module 40 call 0 */
    switch (itemIdx) {
    case 0:
      return "Coefficient";
    default:
      return NULL;
    }
  case 10241: /* module 40 call 1 */
    switch (itemIdx) {
    case 0:
      return "Op";
    case 1:
      return "Base fee";
    default:
      return NULL;
    }
  case 10496: /* module 41 call 0 */
    switch (itemIdx) {
    case 0:
      return "Calls";
    default:
      return NULL;
    }
  case 10497: /* module 41 call 1 */
    switch (itemIdx) {
    case 0:
      return "Calls";
    default:
      return NULL;
    }
  case 10498: /* module 41 call 2 */
    switch (itemIdx) {
    case 0:
      return "Calls";
    default:
      return NULL;
    }
  case 10499: /* module 41 call 3 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Signature";
    case 2:
      return "Call";
    default:
      return NULL;
    }
  case 10752: /* module 42 call 0 */
    switch (itemIdx) {
    case 0:
      return "Name";
    default:
      return NULL;
    }
  case 10753: /* module 42 call 1 */
    switch (itemIdx) {
    case 0:
      return "Num";
    default:
      return NULL;
    }
  case 10754: /* module 42 call 2 */
    switch (itemIdx) {
    case 0:
      return "From";
    case 1:
      return "To";
    case 2:
      return "Items";
    default:
      return NULL;
    }
  case 10755: /* module 42 call 3 */
    switch (itemIdx) {
    case 0:
      return "Num";
    case 1:
      return "To name";
    default:
      return NULL;
    }
  case 11008: /* module 43 call 0 */
    switch (itemIdx) {
    case 0:
      return "Target id";
    case 1:
      return "Ticker";
    case 2:
      return "Secret value";
    default:
      return NULL;
    }
  case 11009: /* module 43 call 1 */
    switch (itemIdx) {
    case 0:
      return "Target";
    case 1:
      return "Prover";
    case 2:
      return "Ticker";
    default:
      return NULL;
    }
  case 11520: /* module 45 call 0 */
    switch (itemIdx) {
    case 0:
      return "When";
    case 1:
      return "Maybe periodic";
    case 2:
      return "Priority";
    case 3:
      return "Call";
    default:
      return NULL;
    }
  case 11521: /* module 45 call 1 */
    switch (itemIdx) {
    case 0:
      return "When";
    case 1:
      return "Index";
    default:
      return NULL;
    }
  case 11522: /* module 45 call 2 */
    switch (itemIdx) {
    case 0:
      return "Id";
    case 1:
      return "When";
    case 2:
      return "Maybe periodic";
    case 3:
      return "Priority";
    case 4:
      return "Call";
    default:
      return NULL;
    }
  case 11523: /* module 45 call 3 */
    switch (itemIdx) {
    case 0:
      return "Id";
    default:
      return NULL;
    }
  case 11524: /* module 45 call 4 */
    switch (itemIdx) {
    case 0:
      return "After";
    case 1:
      return "Maybe periodic";
    case 2:
      return "Priority";
    case 3:
      return "Call";
    default:
      return NULL;
    }
  case 11525: /* module 45 call 5 */
    switch (itemIdx) {
    case 0:
      return "Id";
    case 1:
      return "After";
    case 2:
      return "Maybe periodic";
    case 3:
      return "Priority";
    case 4:
      return "Call";
    default:
      return NULL;
    }
  case 11776: /* module 46 call 0 */
    switch (itemIdx) {
    case 0:
      return "Length";
    default:
      return NULL;
    }
  case 11777: /* module 46 call 1 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 11778: /* module 46 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Targets";
    default:
      return NULL;
    }
  case 11779: /* module 46 call 3 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Tax";
    default:
      return NULL;
    }
  case 11780: /* module 46 call 4 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Taxed did";
    case 2:
      return "Tax";
    default:
      return NULL;
    }
  case 11781: /* module 46 call 5 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Kind";
    case 2:
      return "Record date";
    case 3:
      return "Details";
    case 4:
      return "Targets";
    case 5:
      return "Default withholding tax";
    case 6:
      return "Withholding tax";
    default:
      return NULL;
    }
  case 11782: /* module 46 call 6 */
    switch (itemIdx) {
    case 0:
      return "Id";
    case 1:
      return "Docs";
    default:
      return NULL;
    }
  case 11783: /* module 46 call 7 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    default:
      return NULL;
    }
  case 11784: /* module 46 call 8 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "Record date";
    default:
      return NULL;
    }
  case 12032: /* module 47 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "Range";
    case 2:
      return "Meta";
    case 3:
      return "Rcv";
    default:
      return NULL;
    }
  case 12033: /* module 47 call 1 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "Votes";
    default:
      return NULL;
    }
  case 12034: /* module 47 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "End";
    default:
      return NULL;
    }
  case 12035: /* module 47 call 3 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "Meta";
    default:
      return NULL;
    }
  case 12036: /* module 47 call 4 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "Rcv";
    default:
      return NULL;
    }
  case 12037: /* module 47 call 5 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    default:
      return NULL;
    }
  case 12288: /* module 48 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "Portfolio";
    case 2:
      return "Currency";
    case 3:
      return "Amount";
    case 4:
      return "Payment at";
    case 5:
      return "Expires at";
    default:
      return NULL;
    }
  case 12289: /* module 48 call 1 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    default:
      return NULL;
    }
  case 12290: /* module 48 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    case 1:
      return "Holder";
    default:
      return NULL;
    }
  case 12291: /* module 48 call 3 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    default:
      return NULL;
    }
  case 12292: /* module 48 call 4 */
    switch (itemIdx) {
    case 0:
      return "Ca id";
    default:
      return NULL;
    }
  case 12544: /* module 49 call 0 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    default:
      return NULL;
    }
  case 12545: /* module 49 call 1 */
    switch (itemIdx) {
    case 0:
      return "Max complexity";
    default:
      return NULL;
    }
  case 12546: /* module 49 call 2 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Schedule";
    default:
      return NULL;
    }
  case 12547: /* module 49 call 3 */
    switch (itemIdx) {
    case 0:
      return "Ticker";
    case 1:
      return "Id";
    default:
      return NULL;
    }
  default:
    return NULL;
  }

  return NULL;
}

parser_error_t _getMethod_ItemValue(pd_Method_t *m, uint8_t moduleIdx,
                                    uint8_t callIdx, uint8_t itemIdx,
                                    char *outValue, uint16_t outValueLen,
                                    uint8_t pageIdx, uint8_t *pageCount) {
  uint16_t callPrivIdx = ((uint16_t)moduleIdx << 8u) + callIdx;

  switch (callPrivIdx) {
  case 0: /* module 0 call 0 */
    switch (itemIdx) {
    case 0: /* system_fill_block - _ratio */;
      return _toStringPerbill(&m->basic.system_fill_block._ratio, outValue,
                              outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1: /* module 0 call 1 */
    switch (itemIdx) {
    case 0: /* system_remark - _remark */;
      return _toStringBytes(&m->basic.system_remark._remark, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 2: /* module 0 call 2 */
    switch (itemIdx) {
    case 0: /* system_set_heap_pages - pages */;
      return _toStringu64(&m->basic.system_set_heap_pages.pages, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 3: /* module 0 call 3 */
    switch (itemIdx) {
    case 0: /* system_set_code - code */;
      return _toStringBytes(&m->basic.system_set_code.code, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4: /* module 0 call 4 */
    switch (itemIdx) {
    case 0: /* system_set_code_without_checks - code */;
      return _toStringBytes(&m->basic.system_set_code_without_checks.code,
                            outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5: /* module 0 call 5 */
    switch (itemIdx) {
    case 0: /* system_set_changes_trie_config - changes_trie_config */;
      return _toStringOptionChangesTrieConfiguration(
          &m->basic.system_set_changes_trie_config.changes_trie_config,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6: /* module 0 call 6 */
    switch (itemIdx) {
    case 0: /* system_set_storage - items */;
      return _toStringVecKeyValue(&m->basic.system_set_storage.items, outValue,
                                  outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7: /* module 0 call 7 */
    switch (itemIdx) {
    case 0: /* system_kill_storage - keys */;
      return _toStringVecKey(&m->basic.system_kill_storage.keys, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8: /* module 0 call 8 */
    switch (itemIdx) {
    case 0: /* system_kill_prefix - prefix */;
      return _toStringKey(&m->basic.system_kill_prefix.prefix, outValue,
                          outValueLen, pageIdx, pageCount);
    case 1: /* system_kill_prefix - _subkeys */;
      return _toStringu32(&m->basic.system_kill_prefix._subkeys, outValue,
                          outValueLen, pageIdx, pageCount);
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
    case 0: /* babe_report_equivocation - equivocation_proof */;
      return _toStringEquivocationProof(
          &m->basic.babe_report_equivocation.equivocation_proof, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* babe_report_equivocation - key_owner_proof */;
      return _toStringKeyOwnerProof(
          &m->basic.babe_report_equivocation.key_owner_proof, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 257: /* module 1 call 1 */
    switch (itemIdx) {
    case 0: /* babe_report_equivocation_unsigned - equivocation_proof */;
      return _toStringEquivocationProof(
          &m->basic.babe_report_equivocation_unsigned.equivocation_proof,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* babe_report_equivocation_unsigned - key_owner_proof */;
      return _toStringKeyOwnerProof(
          &m->basic.babe_report_equivocation_unsigned.key_owner_proof, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 512: /* module 2 call 0 */
    switch (itemIdx) {
    case 0: /* timestamp_set - now */;
      return _toStringCompactMoment(&m->basic.timestamp_set.now, outValue,
                                    outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 768: /* module 3 call 0 */
    switch (itemIdx) {
    case 0: /* indices_claim - index */;
      return _toStringAccountIndex(&m->basic.indices_claim.index, outValue,
                                   outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 769: /* module 3 call 1 */
    switch (itemIdx) {
    case 0: /* indices_transfer - new_ */;
      return _toStringAccountId(&m->basic.indices_transfer.new_, outValue,
                                outValueLen, pageIdx, pageCount);
    case 1: /* indices_transfer - index */;
      return _toStringAccountIndex(&m->basic.indices_transfer.index, outValue,
                                   outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 770: /* module 3 call 2 */
    switch (itemIdx) {
    case 0: /* indices_free - index */;
      return _toStringAccountIndex(&m->basic.indices_free.index, outValue,
                                   outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 771: /* module 3 call 3 */
    switch (itemIdx) {
    case 0: /* indices_force_transfer - new_ */;
      return _toStringAccountId(&m->basic.indices_force_transfer.new_, outValue,
                                outValueLen, pageIdx, pageCount);
    case 1: /* indices_force_transfer - index */;
      return _toStringAccountIndex(&m->basic.indices_force_transfer.index,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 2: /* indices_force_transfer - freeze */;
      return _toStringbool(&m->basic.indices_force_transfer.freeze, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 772: /* module 3 call 4 */
    switch (itemIdx) {
    case 0: /* indices_freeze - index */;
      return _toStringAccountIndex(&m->basic.indices_freeze.index, outValue,
                                   outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1024: /* module 4 call 0 */
    switch (itemIdx) {
    case 0: /* balances_transfer - dest */;
      return _toStringLookupSource(&m->basic.balances_transfer.dest, outValue,
                                   outValueLen, pageIdx, pageCount);
    case 1: /* balances_transfer - value */;
      return _toStringCompactBalance(&m->basic.balances_transfer.value,
                                     outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1025: /* module 4 call 1 */
    switch (itemIdx) {
    case 0: /* balances_transfer_with_memo - dest */;
      return _toStringLookupSource(&m->basic.balances_transfer_with_memo.dest,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 1: /* balances_transfer_with_memo - value */;
      return _toStringCompactBalance(
          &m->basic.balances_transfer_with_memo.value, outValue, outValueLen,
          pageIdx, pageCount);
    case 2: /* balances_transfer_with_memo - memo */;
      return _toStringOptionMemo(&m->basic.balances_transfer_with_memo.memo,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1026: /* module 4 call 2 */
    switch (itemIdx) {
    case 0: /* balances_deposit_block_reward_reserve_balance - value */;
      return _toStringCompactBalance(
          &m->basic.balances_deposit_block_reward_reserve_balance.value,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1027: /* module 4 call 3 */
    switch (itemIdx) {
    case 0: /* balances_set_balance - who */;
      return _toStringLookupSource(&m->basic.balances_set_balance.who, outValue,
                                   outValueLen, pageIdx, pageCount);
    case 1: /* balances_set_balance - new_free */;
      return _toStringCompactBalance(&m->basic.balances_set_balance.new_free,
                                     outValue, outValueLen, pageIdx, pageCount);
    case 2: /* balances_set_balance - new_reserved */;
      return _toStringCompactBalance(
          &m->basic.balances_set_balance.new_reserved, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1028: /* module 4 call 4 */
    switch (itemIdx) {
    case 0: /* balances_force_transfer - source */;
      return _toStringLookupSource(&m->basic.balances_force_transfer.source,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 1: /* balances_force_transfer - dest */;
      return _toStringLookupSource(&m->basic.balances_force_transfer.dest,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 2: /* balances_force_transfer - value */;
      return _toStringCompactBalance(&m->basic.balances_force_transfer.value,
                                     outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1029: /* module 4 call 5 */
    switch (itemIdx) {
    case 0: /* balances_burn_account_balance - amount */;
      return _toStringBalance(&m->basic.balances_burn_account_balance.amount,
                              outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1536: /* module 6 call 0 */
    switch (itemIdx) {
    case 0: /* authorship_set_uncles - new_uncles */;
      return _toStringVecHeader(&m->basic.authorship_set_uncles.new_uncles,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1792: /* module 7 call 0 */
    switch (itemIdx) {
    case 0: /* staking_bond - controller */;
      return _toStringLookupSource(&m->basic.staking_bond.controller, outValue,
                                   outValueLen, pageIdx, pageCount);
    case 1: /* staking_bond - value */;
      return _toStringCompactBalanceOf(&m->basic.staking_bond.value, outValue,
                                       outValueLen, pageIdx, pageCount);
    case 2: /* staking_bond - payee */;
      return _toStringRewardDestination(&m->basic.staking_bond.payee, outValue,
                                        outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1793: /* module 7 call 1 */
    switch (itemIdx) {
    case 0: /* staking_bond_extra - max_additional */;
      return _toStringCompactBalanceOf(
          &m->basic.staking_bond_extra.max_additional, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1794: /* module 7 call 2 */
    switch (itemIdx) {
    case 0: /* staking_unbond - value */;
      return _toStringCompactBalanceOf(&m->basic.staking_unbond.value, outValue,
                                       outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1795: /* module 7 call 3 */
    switch (itemIdx) {
    case 0: /* staking_withdraw_unbonded - num_slashing_spans */;
      return _toStringu32(
          &m->basic.staking_withdraw_unbonded.num_slashing_spans, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1796: /* module 7 call 4 */
    switch (itemIdx) {
    case 0: /* staking_validate - prefs */;
      return _toStringValidatorPrefs(&m->basic.staking_validate.prefs, outValue,
                                     outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1797: /* module 7 call 5 */
    switch (itemIdx) {
    case 0: /* staking_nominate - targets */;
      return _toStringVecLookupSource(&m->basic.staking_nominate.targets,
                                      outValue, outValueLen, pageIdx,
                                      pageCount);
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
    case 0: /* staking_set_payee - payee */;
      return _toStringRewardDestination(&m->basic.staking_set_payee.payee,
                                        outValue, outValueLen, pageIdx,
                                        pageCount);
    default:
      return parser_no_data;
    }
  case 1800: /* module 7 call 8 */
    switch (itemIdx) {
    case 0: /* staking_set_controller - controller */;
      return _toStringLookupSource(&m->basic.staking_set_controller.controller,
                                   outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1801: /* module 7 call 9 */
    switch (itemIdx) {
    case 0: /* staking_set_validator_count - new_ */;
      return _toStringCompactu32(&m->basic.staking_set_validator_count.new_,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1802: /* module 7 call 10 */
    switch (itemIdx) {
    case 0: /* staking_increase_validator_count - additional */;
      return _toStringCompactu32(
          &m->basic.staking_increase_validator_count.additional, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1803: /* module 7 call 11 */
    switch (itemIdx) {
    case 0: /* staking_scale_validator_count - factor */;
      return _toStringPercent(&m->basic.staking_scale_validator_count.factor,
                              outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1804: /* module 7 call 12 */
    switch (itemIdx) {
    case 0: /* staking_add_permissioned_validator - identity */;
      return _toStringIdentityId(
          &m->basic.staking_add_permissioned_validator.identity, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1805: /* module 7 call 13 */
    switch (itemIdx) {
    case 0: /* staking_remove_permissioned_validator - identity */;
      return _toStringIdentityId(
          &m->basic.staking_remove_permissioned_validator.identity, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1806: /* module 7 call 14 */
    switch (itemIdx) {
    case 0: /* staking_validate_cdd_expiry_nominators - targets */;
      return _toStringVecAccountId(
          &m->basic.staking_validate_cdd_expiry_nominators.targets, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1807: /* module 7 call 15 */
    switch (itemIdx) {
    case 0: /* staking_set_commission_cap - new_cap */;
      return _toStringPerbill(&m->basic.staking_set_commission_cap.new_cap,
                              outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1808: /* module 7 call 16 */
    switch (itemIdx) {
    case 0: /* staking_set_min_bond_threshold - new_value */;
      return _toStringBalanceOf(
          &m->basic.staking_set_min_bond_threshold.new_value, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1809: /* module 7 call 17 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 1810: /* module 7 call 18 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 1811: /* module 7 call 19 */
    switch (itemIdx) {
    case 0: /* staking_set_invulnerables - validators */;
      return _toStringVecAccountId(
          &m->basic.staking_set_invulnerables.validators, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1812: /* module 7 call 20 */
    switch (itemIdx) {
    case 0: /* staking_force_unstake - stash */;
      return _toStringAccountId(&m->basic.staking_force_unstake.stash, outValue,
                                outValueLen, pageIdx, pageCount);
    case 1: /* staking_force_unstake - num_slashing_spans */;
      return _toStringu32(&m->basic.staking_force_unstake.num_slashing_spans,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1813: /* module 7 call 21 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 1814: /* module 7 call 22 */
    switch (itemIdx) {
    case 0: /* staking_cancel_deferred_slash - era */;
      return _toStringEraIndex(&m->basic.staking_cancel_deferred_slash.era,
                               outValue, outValueLen, pageIdx, pageCount);
    case 1: /* staking_cancel_deferred_slash - slash_indices */;
      return _toStringVecu32(
          &m->basic.staking_cancel_deferred_slash.slash_indices, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1815: /* module 7 call 23 */
    switch (itemIdx) {
    case 0: /* staking_payout_stakers - validator_stash */;
      return _toStringAccountId(
          &m->basic.staking_payout_stakers.validator_stash, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* staking_payout_stakers - era */;
      return _toStringEraIndex(&m->basic.staking_payout_stakers.era, outValue,
                               outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1816: /* module 7 call 24 */
    switch (itemIdx) {
    case 0: /* staking_rebond - value */;
      return _toStringCompactBalanceOf(&m->basic.staking_rebond.value, outValue,
                                       outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1817: /* module 7 call 25 */
    switch (itemIdx) {
    case 0: /* staking_set_history_depth - new_history_depth */;
      return _toStringCompactEraIndex(
          &m->basic.staking_set_history_depth.new_history_depth, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* staking_set_history_depth - _era_items_deleted */;
      return _toStringCompactu32(
          &m->basic.staking_set_history_depth._era_items_deleted, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1818: /* module 7 call 26 */
    switch (itemIdx) {
    case 0: /* staking_reap_stash - stash */;
      return _toStringAccountId(&m->basic.staking_reap_stash.stash, outValue,
                                outValueLen, pageIdx, pageCount);
    case 1: /* staking_reap_stash - num_slashing_spans */;
      return _toStringu32(&m->basic.staking_reap_stash.num_slashing_spans,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1819: /* module 7 call 27 */
    switch (itemIdx) {
    case 0: /* staking_submit_election_solution - winners */;
      return _toStringVecValidatorIndex(
          &m->basic.staking_submit_election_solution.winners, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* staking_submit_election_solution - compact */;
      return _toStringCompactAssignments(
          &m->basic.staking_submit_election_solution.compact, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* staking_submit_election_solution - score */;
      return _toStringElectionScore(
          &m->basic.staking_submit_election_solution.score, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* staking_submit_election_solution - era */;
      return _toStringEraIndex(&m->basic.staking_submit_election_solution.era,
                               outValue, outValueLen, pageIdx, pageCount);
    case 4: /* staking_submit_election_solution - size */;
      return _toStringElectionSize(
          &m->basic.staking_submit_election_solution.size, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1820: /* module 7 call 28 */
    switch (itemIdx) {
    case 0: /* staking_submit_election_solution_unsigned - winners */;
      return _toStringVecValidatorIndex(
          &m->basic.staking_submit_election_solution_unsigned.winners, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* staking_submit_election_solution_unsigned - compact */;
      return _toStringCompactAssignments(
          &m->basic.staking_submit_election_solution_unsigned.compact, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* staking_submit_election_solution_unsigned - score */;
      return _toStringElectionScore(
          &m->basic.staking_submit_election_solution_unsigned.score, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* staking_submit_election_solution_unsigned - era */;
      return _toStringEraIndex(
          &m->basic.staking_submit_election_solution_unsigned.era, outValue,
          outValueLen, pageIdx, pageCount);
    case 4: /* staking_submit_election_solution_unsigned - size */;
      return _toStringElectionSize(
          &m->basic.staking_submit_election_solution_unsigned.size, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1821: /* module 7 call 29 */
    switch (itemIdx) {
    case 0: /* staking_payout_stakers_by_system - validator_stash */;
      return _toStringAccountId(
          &m->basic.staking_payout_stakers_by_system.validator_stash, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* staking_payout_stakers_by_system - era */;
      return _toStringEraIndex(&m->basic.staking_payout_stakers_by_system.era,
                               outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 1822: /* module 7 call 30 */
    switch (itemIdx) {
    case 0: /* staking_change_slashing_allowed_for - slashing_switch */;
      return _toStringSlashingSwitch(
          &m->basic.staking_change_slashing_allowed_for.slashing_switch,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 2304: /* module 9 call 0 */
    switch (itemIdx) {
    case 0: /* session_set_keys - keys */;
      return _toStringKeys(&m->basic.session_set_keys.keys, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* session_set_keys - proof */;
      return _toStringBytes(&m->basic.session_set_keys.proof, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 2305: /* module 9 call 1 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 2560: /* module 10 call 0 */
    switch (itemIdx) {
    case 0: /* finalitytracker_final_hint - hint */;
      return _toStringCompactBlockNumber(
          &m->basic.finalitytracker_final_hint.hint, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 2816: /* module 11 call 0 */
    switch (itemIdx) {
    case 0: /* grandpa_report_equivocation - equivocation_proof */;
      return _toStringEquivocationProof(
          &m->basic.grandpa_report_equivocation.equivocation_proof, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* grandpa_report_equivocation - key_owner_proof */;
      return _toStringKeyOwnerProof(
          &m->basic.grandpa_report_equivocation.key_owner_proof, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 2817: /* module 11 call 1 */
    switch (itemIdx) {
    case 0: /* grandpa_report_equivocation_unsigned - equivocation_proof */;
      return _toStringEquivocationProof(
          &m->basic.grandpa_report_equivocation_unsigned.equivocation_proof,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* grandpa_report_equivocation_unsigned - key_owner_proof */;
      return _toStringKeyOwnerProof(
          &m->basic.grandpa_report_equivocation_unsigned.key_owner_proof,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 2818: /* module 11 call 2 */
    switch (itemIdx) {
    case 0: /* grandpa_note_stalled - delay */;
      return _toStringBlockNumber(&m->basic.grandpa_note_stalled.delay,
                                  outValue, outValueLen, pageIdx, pageCount);
    case 1: /* grandpa_note_stalled - best_finalized_block_number */;
      return _toStringBlockNumber(
          &m->basic.grandpa_note_stalled.best_finalized_block_number, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 3072: /* module 12 call 0 */
    switch (itemIdx) {
    case 0: /* imonline_heartbeat - heartbeat */;
      return _toStringHeartbeat(&m->basic.imonline_heartbeat.heartbeat,
                                outValue, outValueLen, pageIdx, pageCount);
    case 1: /* imonline_heartbeat - _signature */;
      return _toStringSignature(&m->basic.imonline_heartbeat._signature,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 3073: /* module 12 call 1 */
    switch (itemIdx) {
    case 0: /* imonline_set_slashing_params - params */;
      return _toStringOfflineSlashingParams(
          &m->basic.imonline_set_slashing_params.params, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4096: /* module 16 call 0 */
    switch (itemIdx) {
    case 0: /* sudo_sudo - call */;
      return _toStringCall(&m->basic.sudo_sudo.call, outValue, outValueLen,
                           pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4097: /* module 16 call 1 */
    switch (itemIdx) {
    case 0: /* sudo_sudo_unchecked_weight - call */;
      return _toStringCall(&m->basic.sudo_sudo_unchecked_weight.call, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* sudo_sudo_unchecked_weight - _weight */;
      return _toStringWeight(&m->basic.sudo_sudo_unchecked_weight._weight,
                             outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4098: /* module 16 call 2 */
    switch (itemIdx) {
    case 0: /* sudo_set_key - new_ */;
      return _toStringLookupSource(&m->basic.sudo_set_key.new_, outValue,
                                   outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4099: /* module 16 call 3 */
    switch (itemIdx) {
    case 0: /* sudo_sudo_as - who */;
      return _toStringLookupSource(&m->basic.sudo_sudo_as.who, outValue,
                                   outValueLen, pageIdx, pageCount);
    case 1: /* sudo_sudo_as - call */;
      return _toStringCall(&m->basic.sudo_sudo_as.call, outValue, outValueLen,
                           pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4352: /* module 17 call 0 */
    switch (itemIdx) {
    case 0: /* multisig_create_multisig - signers */;
      return _toStringVecSignatory(&m->basic.multisig_create_multisig.signers,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_create_multisig - sigs_required */;
      return _toStringu64(&m->basic.multisig_create_multisig.sigs_required,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4353: /* module 17 call 1 */
    switch (itemIdx) {
    case 0: /* multisig_create_or_approve_proposal_as_identity - multisig */;
      return _toStringAccountId(
          &m->nested.multisig_create_or_approve_proposal_as_identity.multisig,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_create_or_approve_proposal_as_identity - proposal */;
      return _toStringProposal(
          &m->nested.multisig_create_or_approve_proposal_as_identity.proposal,
          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* multisig_create_or_approve_proposal_as_identity - expiry */;
      return _toStringOptionMoment(
          &m->nested.multisig_create_or_approve_proposal_as_identity.expiry,
          outValue, outValueLen, pageIdx, pageCount);
    case 3: /* multisig_create_or_approve_proposal_as_identity - auto_close */;
      return _toStringbool(
          &m->nested.multisig_create_or_approve_proposal_as_identity.auto_close,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4354: /* module 17 call 2 */
    switch (itemIdx) {
    case 0: /* multisig_create_or_approve_proposal_as_key - multisig */;
      return _toStringAccountId(
          &m->nested.multisig_create_or_approve_proposal_as_key.multisig,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_create_or_approve_proposal_as_key - proposal */;
      return _toStringProposal(
          &m->nested.multisig_create_or_approve_proposal_as_key.proposal,
          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* multisig_create_or_approve_proposal_as_key - expiry */;
      return _toStringOptionMoment(
          &m->nested.multisig_create_or_approve_proposal_as_key.expiry,
          outValue, outValueLen, pageIdx, pageCount);
    case 3: /* multisig_create_or_approve_proposal_as_key - auto_close */;
      return _toStringbool(
          &m->nested.multisig_create_or_approve_proposal_as_key.auto_close,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4355: /* module 17 call 3 */
    switch (itemIdx) {
    case 0: /* multisig_create_proposal_as_identity - multisig */;
      return _toStringAccountId(
          &m->nested.multisig_create_proposal_as_identity.multisig, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* multisig_create_proposal_as_identity - proposal */;
      return _toStringProposal(
          &m->nested.multisig_create_proposal_as_identity.proposal, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* multisig_create_proposal_as_identity - expiry */;
      return _toStringOptionMoment(
          &m->nested.multisig_create_proposal_as_identity.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* multisig_create_proposal_as_identity - auto_close */;
      return _toStringbool(
          &m->nested.multisig_create_proposal_as_identity.auto_close, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4356: /* module 17 call 4 */
    switch (itemIdx) {
    case 0: /* multisig_create_proposal_as_key - multisig */;
      return _toStringAccountId(
          &m->nested.multisig_create_proposal_as_key.multisig, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* multisig_create_proposal_as_key - proposal */;
      return _toStringProposal(
          &m->nested.multisig_create_proposal_as_key.proposal, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* multisig_create_proposal_as_key - expiry */;
      return _toStringOptionMoment(
          &m->nested.multisig_create_proposal_as_key.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* multisig_create_proposal_as_key - auto_close */;
      return _toStringbool(
          &m->nested.multisig_create_proposal_as_key.auto_close, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4357: /* module 17 call 5 */
    switch (itemIdx) {
    case 0: /* multisig_approve_as_identity - multisig */;
      return _toStringAccountId(&m->basic.multisig_approve_as_identity.multisig,
                                outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_approve_as_identity - proposal_id */;
      return _toStringu64(&m->basic.multisig_approve_as_identity.proposal_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4358: /* module 17 call 6 */
    switch (itemIdx) {
    case 0: /* multisig_approve_as_key - multisig */;
      return _toStringAccountId(&m->basic.multisig_approve_as_key.multisig,
                                outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_approve_as_key - proposal_id */;
      return _toStringu64(&m->basic.multisig_approve_as_key.proposal_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4359: /* module 17 call 7 */
    switch (itemIdx) {
    case 0: /* multisig_reject_as_identity - multisig */;
      return _toStringAccountId(&m->basic.multisig_reject_as_identity.multisig,
                                outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_reject_as_identity - proposal_id */;
      return _toStringu64(&m->basic.multisig_reject_as_identity.proposal_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4360: /* module 17 call 8 */
    switch (itemIdx) {
    case 0: /* multisig_reject_as_key - multisig */;
      return _toStringAccountId(&m->basic.multisig_reject_as_key.multisig,
                                outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_reject_as_key - proposal_id */;
      return _toStringu64(&m->basic.multisig_reject_as_key.proposal_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4361: /* module 17 call 9 */
    switch (itemIdx) {
    case 0: /* multisig_accept_multisig_signer_as_identity - auth_id */;
      return _toStringu64(
          &m->basic.multisig_accept_multisig_signer_as_identity.auth_id,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4362: /* module 17 call 10 */
    switch (itemIdx) {
    case 0: /* multisig_accept_multisig_signer_as_key - auth_id */;
      return _toStringu64(
          &m->basic.multisig_accept_multisig_signer_as_key.auth_id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4363: /* module 17 call 11 */
    switch (itemIdx) {
    case 0: /* multisig_add_multisig_signer - signer */;
      return _toStringSignatory(&m->basic.multisig_add_multisig_signer.signer,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4364: /* module 17 call 12 */
    switch (itemIdx) {
    case 0: /* multisig_remove_multisig_signer - signer */;
      return _toStringSignatory(
          &m->basic.multisig_remove_multisig_signer.signer, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4365: /* module 17 call 13 */
    switch (itemIdx) {
    case 0: /* multisig_add_multisig_signers_via_creator - multisig */;
      return _toStringAccountId(
          &m->basic.multisig_add_multisig_signers_via_creator.multisig,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_add_multisig_signers_via_creator - signers */;
      return _toStringVecSignatory(
          &m->basic.multisig_add_multisig_signers_via_creator.signers, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4366: /* module 17 call 14 */
    switch (itemIdx) {
    case 0: /* multisig_remove_multisig_signers_via_creator - multisig */;
      return _toStringAccountId(
          &m->basic.multisig_remove_multisig_signers_via_creator.multisig,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_remove_multisig_signers_via_creator - signers */;
      return _toStringVecSignatory(
          &m->basic.multisig_remove_multisig_signers_via_creator.signers,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4367: /* module 17 call 15 */
    switch (itemIdx) {
    case 0: /* multisig_change_sigs_required - sigs_required */;
      return _toStringu64(&m->basic.multisig_change_sigs_required.sigs_required,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4368: /* module 17 call 16 */
    switch (itemIdx) {
    case 0: /* multisig_change_all_signers_and_sigs_required - signers */;
      return _toStringVecSignatory(
          &m->basic.multisig_change_all_signers_and_sigs_required.signers,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* multisig_change_all_signers_and_sigs_required - sigs_required */;
      return _toStringu64(
          &m->basic.multisig_change_all_signers_and_sigs_required.sigs_required,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4369: /* module 17 call 17 */
    switch (itemIdx) {
    case 0: /* multisig_make_multisig_signer - multisig */;
      return _toStringAccountId(
          &m->basic.multisig_make_multisig_signer.multisig, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4370: /* module 17 call 18 */
    switch (itemIdx) {
    case 0: /* multisig_make_multisig_primary - multisig */;
      return _toStringAccountId(
          &m->basic.multisig_make_multisig_primary.multisig, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* multisig_make_multisig_primary - optional_cdd_auth_id */;
      return _toStringOptionu64(
          &m->basic.multisig_make_multisig_primary.optional_cdd_auth_id,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4864: /* module 19 call 0 */
    switch (itemIdx) {
    case 0: /* contracts_update_schedule - schedule */;
      return _toStringSchedule(&m->basic.contracts_update_schedule.schedule,
                               outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4865: /* module 19 call 1 */
    switch (itemIdx) {
    case 0: /* contracts_put_code - meta_info */;
      return _toStringTemplateMetadata(&m->basic.contracts_put_code.meta_info,
                                       outValue, outValueLen, pageIdx,
                                       pageCount);
    case 1: /* contracts_put_code - instantiation_fee */;
      return _toStringBalanceOf(&m->basic.contracts_put_code.instantiation_fee,
                                outValue, outValueLen, pageIdx, pageCount);
    case 2: /* contracts_put_code - code */;
      return _toStringBytes(&m->basic.contracts_put_code.code, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4866: /* module 19 call 2 */
    switch (itemIdx) {
    case 0: /* contracts_call - dest */;
      return _toStringLookupSource(&m->basic.contracts_call.dest, outValue,
                                   outValueLen, pageIdx, pageCount);
    case 1: /* contracts_call - value */;
      return _toStringCompactBalanceOf(&m->basic.contracts_call.value, outValue,
                                       outValueLen, pageIdx, pageCount);
    case 2: /* contracts_call - gas_limit */;
      return _toStringCompactGas(&m->basic.contracts_call.gas_limit, outValue,
                                 outValueLen, pageIdx, pageCount);
    case 3: /* contracts_call - data */;
      return _toStringBytes(&m->basic.contracts_call.data, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4867: /* module 19 call 3 */
    switch (itemIdx) {
    case 0: /* contracts_instantiate - endowment */;
      return _toStringCompactBalanceOf(
          &m->basic.contracts_instantiate.endowment, outValue, outValueLen,
          pageIdx, pageCount);
    case 1: /* contracts_instantiate - gas_limit */;
      return _toStringCompactGas(&m->basic.contracts_instantiate.gas_limit,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 2: /* contracts_instantiate - code_hash */;
      return _toStringCodeHash(&m->basic.contracts_instantiate.code_hash,
                               outValue, outValueLen, pageIdx, pageCount);
    case 3: /* contracts_instantiate - data */;
      return _toStringBytes(&m->basic.contracts_instantiate.data, outValue,
                            outValueLen, pageIdx, pageCount);
    case 4: /* contracts_instantiate - max_fee */;
      return _toStringBalanceOf(&m->basic.contracts_instantiate.max_fee,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4868: /* module 19 call 4 */
    switch (itemIdx) {
    case 0: /* contracts_freeze_instantiation - code_hash */;
      return _toStringCodeHash(
          &m->basic.contracts_freeze_instantiation.code_hash, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4869: /* module 19 call 5 */
    switch (itemIdx) {
    case 0: /* contracts_unfreeze_instantiation - code_hash */;
      return _toStringCodeHash(
          &m->basic.contracts_unfreeze_instantiation.code_hash, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4870: /* module 19 call 6 */
    switch (itemIdx) {
    case 0: /* contracts_transfer_template_ownership - code_hash */;
      return _toStringCodeHash(
          &m->basic.contracts_transfer_template_ownership.code_hash, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* contracts_transfer_template_ownership - new_owner */;
      return _toStringIdentityId(
          &m->basic.contracts_transfer_template_ownership.new_owner, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4871: /* module 19 call 7 */
    switch (itemIdx) {
    case 0: /* contracts_change_template_fees - code_hash */;
      return _toStringCodeHash(
          &m->basic.contracts_change_template_fees.code_hash, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* contracts_change_template_fees - new_instantiation_fee */;
      return _toStringOptionBalanceOf(
          &m->basic.contracts_change_template_fees.new_instantiation_fee,
          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* contracts_change_template_fees - new_usage_fee */;
      return _toStringOptionBalanceOf(
          &m->basic.contracts_change_template_fees.new_usage_fee, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 4872: /* module 19 call 8 */
    switch (itemIdx) {
    case 0: /* contracts_change_template_meta_url - code_hash */;
      return _toStringCodeHash(
          &m->basic.contracts_change_template_meta_url.code_hash, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* contracts_change_template_meta_url - new_url */;
      return _toStringOptionMetaUrl(
          &m->basic.contracts_change_template_meta_url.new_url, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5120: /* module 20 call 0 */
    switch (itemIdx) {
    case 0: /* treasury_disbursement - beneficiaries */;
      return _toStringVecBeneficiary(
          &m->basic.treasury_disbursement.beneficiaries, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5121: /* module 20 call 1 */
    switch (itemIdx) {
    case 0: /* treasury_reimbursement - amount */;
      return _toStringBalanceOf(&m->basic.treasury_reimbursement.amount,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5376: /* module 21 call 0 */
    switch (itemIdx) {
    case 0: /* polymeshcommittee_set_vote_threshold - n */;
      return _toStringu32(&m->basic.polymeshcommittee_set_vote_threshold.n,
                          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* polymeshcommittee_set_vote_threshold - d */;
      return _toStringu32(&m->basic.polymeshcommittee_set_vote_threshold.d,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5377: /* module 21 call 1 */
    switch (itemIdx) {
    case 0: /* polymeshcommittee_set_release_coordinator - id */;
      return _toStringIdentityId(
          &m->basic.polymeshcommittee_set_release_coordinator.id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5378: /* module 21 call 2 */
    switch (itemIdx) {
    case 0: /* polymeshcommittee_set_expires_after - expiry */;
      return _toStringMaybeBlock(
          &m->basic.polymeshcommittee_set_expires_after.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5379: /* module 21 call 3 */
    switch (itemIdx) {
    case 0: /* polymeshcommittee_close - proposal */;
      return _toStringHash(&m->basic.polymeshcommittee_close.proposal, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* polymeshcommittee_close - index */;
      return _toStringCompactProposalIndex(
          &m->basic.polymeshcommittee_close.index, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5380: /* module 21 call 4 */
    switch (itemIdx) {
    case 0: /* polymeshcommittee_vote_or_propose - approve */;
      return _toStringbool(&m->nested.polymeshcommittee_vote_or_propose.approve,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* polymeshcommittee_vote_or_propose - call */;
      return _toStringProposal(
          &m->nested.polymeshcommittee_vote_or_propose.call, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5381: /* module 21 call 5 */
    switch (itemIdx) {
    case 0: /* polymeshcommittee_vote - proposal */;
      return _toStringHash(&m->basic.polymeshcommittee_vote.proposal, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* polymeshcommittee_vote - index */;
      return _toStringProposalIndex(&m->basic.polymeshcommittee_vote.index,
                                    outValue, outValueLen, pageIdx, pageCount);
    case 2: /* polymeshcommittee_vote - approve */;
      return _toStringbool(&m->basic.polymeshcommittee_vote.approve, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5632: /* module 22 call 0 */
    switch (itemIdx) {
    case 0: /* committeemembership_set_active_members_limit - limit */;
      return _toStringMemberCount(
          &m->basic.committeemembership_set_active_members_limit.limit,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5633: /* module 22 call 1 */
    switch (itemIdx) {
    case 0: /* committeemembership_disable_member - who */;
      return _toStringIdentityId(
          &m->basic.committeemembership_disable_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* committeemembership_disable_member - expiry */;
      return _toStringOptionMoment(
          &m->basic.committeemembership_disable_member.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* committeemembership_disable_member - at */;
      return _toStringOptionMoment(
          &m->basic.committeemembership_disable_member.at, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5634: /* module 22 call 2 */
    switch (itemIdx) {
    case 0: /* committeemembership_add_member - who */;
      return _toStringIdentityId(&m->basic.committeemembership_add_member.who,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5635: /* module 22 call 3 */
    switch (itemIdx) {
    case 0: /* committeemembership_remove_member - who */;
      return _toStringIdentityId(
          &m->basic.committeemembership_remove_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5636: /* module 22 call 4 */
    switch (itemIdx) {
    case 0: /* committeemembership_swap_member - remove */;
      return _toStringIdentityId(
          &m->basic.committeemembership_swap_member.remove, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* committeemembership_swap_member - add */;
      return _toStringIdentityId(&m->basic.committeemembership_swap_member.add,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5637: /* module 22 call 5 */
    switch (itemIdx) {
    case 0: /* committeemembership_reset_members - members */;
      return _toStringVecIdentityId(
          &m->basic.committeemembership_reset_members.members, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5638: /* module 22 call 6 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 5888: /* module 23 call 0 */
    switch (itemIdx) {
    case 0: /* pips_set_prune_historical_pips - new_value */;
      return _toStringbool(&m->basic.pips_set_prune_historical_pips.new_value,
                           outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5889: /* module 23 call 1 */
    switch (itemIdx) {
    case 0: /* pips_set_min_proposal_deposit - deposit */;
      return _toStringBalanceOf(&m->basic.pips_set_min_proposal_deposit.deposit,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5890: /* module 23 call 2 */
    switch (itemIdx) {
    case 0: /* pips_set_proposal_cool_off_period - duration */;
      return _toStringBlockNumber(
          &m->basic.pips_set_proposal_cool_off_period.duration, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5891: /* module 23 call 3 */
    switch (itemIdx) {
    case 0: /* pips_set_default_enactment_period - duration */;
      return _toStringBlockNumber(
          &m->basic.pips_set_default_enactment_period.duration, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5892: /* module 23 call 4 */
    switch (itemIdx) {
    case 0: /* pips_set_pending_pip_expiry - expiry */;
      return _toStringMaybeBlock(&m->basic.pips_set_pending_pip_expiry.expiry,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5893: /* module 23 call 5 */
    switch (itemIdx) {
    case 0: /* pips_set_max_pip_skip_count - new_max */;
      return _toStringSkippedCount(
          &m->basic.pips_set_max_pip_skip_count.new_max, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5894: /* module 23 call 6 */
    switch (itemIdx) {
    case 0: /* pips_set_active_pip_limit - new_max */;
      return _toStringu32(&m->basic.pips_set_active_pip_limit.new_max, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5895: /* module 23 call 7 */
    switch (itemIdx) {
    case 0: /* pips_propose - proposal */;
      return _toStringProposal(&m->nested.pips_propose.proposal, outValue,
                               outValueLen, pageIdx, pageCount);
    case 1: /* pips_propose - deposit */;
      return _toStringBalanceOf(&m->nested.pips_propose.deposit, outValue,
                                outValueLen, pageIdx, pageCount);
    case 2: /* pips_propose - url */;
      return _toStringOptionUrl(&m->nested.pips_propose.url, outValue,
                                outValueLen, pageIdx, pageCount);
    case 3: /* pips_propose - description */;
      return _toStringOptionPipDescription(&m->nested.pips_propose.description,
                                           outValue, outValueLen, pageIdx,
                                           pageCount);
    default:
      return parser_no_data;
    }
  case 5896: /* module 23 call 8 */
    switch (itemIdx) {
    case 0: /* pips_amend_proposal - id */;
      return _toStringPipId(&m->basic.pips_amend_proposal.id, outValue,
                            outValueLen, pageIdx, pageCount);
    case 1: /* pips_amend_proposal - url */;
      return _toStringOptionUrl(&m->basic.pips_amend_proposal.url, outValue,
                                outValueLen, pageIdx, pageCount);
    case 2: /* pips_amend_proposal - description */;
      return _toStringOptionPipDescription(
          &m->basic.pips_amend_proposal.description, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5897: /* module 23 call 9 */
    switch (itemIdx) {
    case 0: /* pips_cancel_proposal - id */;
      return _toStringPipId(&m->basic.pips_cancel_proposal.id, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5898: /* module 23 call 10 */
    switch (itemIdx) {
    case 0: /* pips_vote - id */;
      return _toStringPipId(&m->basic.pips_vote.id, outValue, outValueLen,
                            pageIdx, pageCount);
    case 1: /* pips_vote - aye_or_nay */;
      return _toStringbool(&m->basic.pips_vote.aye_or_nay, outValue,
                           outValueLen, pageIdx, pageCount);
    case 2: /* pips_vote - deposit */;
      return _toStringBalanceOf(&m->basic.pips_vote.deposit, outValue,
                                outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5899: /* module 23 call 11 */
    switch (itemIdx) {
    case 0: /* pips_approve_committee_proposal - id */;
      return _toStringPipId(&m->basic.pips_approve_committee_proposal.id,
                            outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5900: /* module 23 call 12 */
    switch (itemIdx) {
    case 0: /* pips_reject_proposal - id */;
      return _toStringPipId(&m->basic.pips_reject_proposal.id, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5901: /* module 23 call 13 */
    switch (itemIdx) {
    case 0: /* pips_prune_proposal - id */;
      return _toStringPipId(&m->basic.pips_prune_proposal.id, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5902: /* module 23 call 14 */
    switch (itemIdx) {
    case 0: /* pips_reschedule_execution - id */;
      return _toStringPipId(&m->basic.pips_reschedule_execution.id, outValue,
                            outValueLen, pageIdx, pageCount);
    case 1: /* pips_reschedule_execution - until */;
      return _toStringOptionBlockNumber(
          &m->basic.pips_reschedule_execution.until, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5903: /* module 23 call 15 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 5904: /* module 23 call 16 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 5905: /* module 23 call 17 */
    switch (itemIdx) {
    case 0: /* pips_enact_snapshot_results - results */;
      return _toStringVecTuplePipIdSnapshotResult(
          &m->basic.pips_enact_snapshot_results.results, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5906: /* module 23 call 18 */
    switch (itemIdx) {
    case 0: /* pips_execute_scheduled_pip - id */;
      return _toStringPipId(&m->basic.pips_execute_scheduled_pip.id, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 5907: /* module 23 call 19 */
    switch (itemIdx) {
    case 0: /* pips_expire_scheduled_pip - did */;
      return _toStringIdentityId(&m->basic.pips_expire_scheduled_pip.did,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 1: /* pips_expire_scheduled_pip - id */;
      return _toStringPipId(&m->basic.pips_expire_scheduled_pip.id, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6144: /* module 24 call 0 */
    switch (itemIdx) {
    case 0: /* technicalcommittee_set_vote_threshold - n */;
      return _toStringu32(&m->basic.technicalcommittee_set_vote_threshold.n,
                          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* technicalcommittee_set_vote_threshold - d */;
      return _toStringu32(&m->basic.technicalcommittee_set_vote_threshold.d,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6145: /* module 24 call 1 */
    switch (itemIdx) {
    case 0: /* technicalcommittee_set_release_coordinator - id */;
      return _toStringIdentityId(
          &m->basic.technicalcommittee_set_release_coordinator.id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6146: /* module 24 call 2 */
    switch (itemIdx) {
    case 0: /* technicalcommittee_set_expires_after - expiry */;
      return _toStringMaybeBlock(
          &m->basic.technicalcommittee_set_expires_after.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6147: /* module 24 call 3 */
    switch (itemIdx) {
    case 0: /* technicalcommittee_close - proposal */;
      return _toStringHash(&m->basic.technicalcommittee_close.proposal,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* technicalcommittee_close - index */;
      return _toStringCompactProposalIndex(
          &m->basic.technicalcommittee_close.index, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6148: /* module 24 call 4 */
    switch (itemIdx) {
    case 0: /* technicalcommittee_vote_or_propose - approve */;
      return _toStringbool(
          &m->nested.technicalcommittee_vote_or_propose.approve, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* technicalcommittee_vote_or_propose - call */;
      return _toStringProposal(
          &m->nested.technicalcommittee_vote_or_propose.call, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6149: /* module 24 call 5 */
    switch (itemIdx) {
    case 0: /* technicalcommittee_vote - proposal */;
      return _toStringHash(&m->basic.technicalcommittee_vote.proposal, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* technicalcommittee_vote - index */;
      return _toStringProposalIndex(&m->basic.technicalcommittee_vote.index,
                                    outValue, outValueLen, pageIdx, pageCount);
    case 2: /* technicalcommittee_vote - approve */;
      return _toStringbool(&m->basic.technicalcommittee_vote.approve, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6400: /* module 25 call 0 */
    switch (itemIdx) {
    case 0: /* technicalcommitteemembership_set_active_members_limit - limit */;
      return _toStringMemberCount(
          &m->basic.technicalcommitteemembership_set_active_members_limit.limit,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6401: /* module 25 call 1 */
    switch (itemIdx) {
    case 0: /* technicalcommitteemembership_disable_member - who */;
      return _toStringIdentityId(
          &m->basic.technicalcommitteemembership_disable_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* technicalcommitteemembership_disable_member - expiry */;
      return _toStringOptionMoment(
          &m->basic.technicalcommitteemembership_disable_member.expiry,
          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* technicalcommitteemembership_disable_member - at */;
      return _toStringOptionMoment(
          &m->basic.technicalcommitteemembership_disable_member.at, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6402: /* module 25 call 2 */
    switch (itemIdx) {
    case 0: /* technicalcommitteemembership_add_member - who */;
      return _toStringIdentityId(
          &m->basic.technicalcommitteemembership_add_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6403: /* module 25 call 3 */
    switch (itemIdx) {
    case 0: /* technicalcommitteemembership_remove_member - who */;
      return _toStringIdentityId(
          &m->basic.technicalcommitteemembership_remove_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6404: /* module 25 call 4 */
    switch (itemIdx) {
    case 0: /* technicalcommitteemembership_swap_member - remove */;
      return _toStringIdentityId(
          &m->basic.technicalcommitteemembership_swap_member.remove, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* technicalcommitteemembership_swap_member - add */;
      return _toStringIdentityId(
          &m->basic.technicalcommitteemembership_swap_member.add, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6405: /* module 25 call 5 */
    switch (itemIdx) {
    case 0: /* technicalcommitteemembership_reset_members - members */;
      return _toStringVecIdentityId(
          &m->basic.technicalcommitteemembership_reset_members.members,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6406: /* module 25 call 6 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 6656: /* module 26 call 0 */
    switch (itemIdx) {
    case 0: /* upgradecommittee_set_vote_threshold - n */;
      return _toStringu32(&m->basic.upgradecommittee_set_vote_threshold.n,
                          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* upgradecommittee_set_vote_threshold - d */;
      return _toStringu32(&m->basic.upgradecommittee_set_vote_threshold.d,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6657: /* module 26 call 1 */
    switch (itemIdx) {
    case 0: /* upgradecommittee_set_release_coordinator - id */;
      return _toStringIdentityId(
          &m->basic.upgradecommittee_set_release_coordinator.id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6658: /* module 26 call 2 */
    switch (itemIdx) {
    case 0: /* upgradecommittee_set_expires_after - expiry */;
      return _toStringMaybeBlock(
          &m->basic.upgradecommittee_set_expires_after.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6659: /* module 26 call 3 */
    switch (itemIdx) {
    case 0: /* upgradecommittee_close - proposal */;
      return _toStringHash(&m->basic.upgradecommittee_close.proposal, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* upgradecommittee_close - index */;
      return _toStringCompactProposalIndex(
          &m->basic.upgradecommittee_close.index, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6660: /* module 26 call 4 */
    switch (itemIdx) {
    case 0: /* upgradecommittee_vote_or_propose - approve */;
      return _toStringbool(&m->nested.upgradecommittee_vote_or_propose.approve,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* upgradecommittee_vote_or_propose - call */;
      return _toStringProposal(&m->nested.upgradecommittee_vote_or_propose.call,
                               outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6661: /* module 26 call 5 */
    switch (itemIdx) {
    case 0: /* upgradecommittee_vote - proposal */;
      return _toStringHash(&m->basic.upgradecommittee_vote.proposal, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* upgradecommittee_vote - index */;
      return _toStringProposalIndex(&m->basic.upgradecommittee_vote.index,
                                    outValue, outValueLen, pageIdx, pageCount);
    case 2: /* upgradecommittee_vote - approve */;
      return _toStringbool(&m->basic.upgradecommittee_vote.approve, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6912: /* module 27 call 0 */
    switch (itemIdx) {
    case 0: /* upgradecommitteemembership_set_active_members_limit - limit */;
      return _toStringMemberCount(
          &m->basic.upgradecommitteemembership_set_active_members_limit.limit,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6913: /* module 27 call 1 */
    switch (itemIdx) {
    case 0: /* upgradecommitteemembership_disable_member - who */;
      return _toStringIdentityId(
          &m->basic.upgradecommitteemembership_disable_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* upgradecommitteemembership_disable_member - expiry */;
      return _toStringOptionMoment(
          &m->basic.upgradecommitteemembership_disable_member.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* upgradecommitteemembership_disable_member - at */;
      return _toStringOptionMoment(
          &m->basic.upgradecommitteemembership_disable_member.at, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6914: /* module 27 call 2 */
    switch (itemIdx) {
    case 0: /* upgradecommitteemembership_add_member - who */;
      return _toStringIdentityId(
          &m->basic.upgradecommitteemembership_add_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6915: /* module 27 call 3 */
    switch (itemIdx) {
    case 0: /* upgradecommitteemembership_remove_member - who */;
      return _toStringIdentityId(
          &m->basic.upgradecommitteemembership_remove_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6916: /* module 27 call 4 */
    switch (itemIdx) {
    case 0: /* upgradecommitteemembership_swap_member - remove */;
      return _toStringIdentityId(
          &m->basic.upgradecommitteemembership_swap_member.remove, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* upgradecommitteemembership_swap_member - add */;
      return _toStringIdentityId(
          &m->basic.upgradecommitteemembership_swap_member.add, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6917: /* module 27 call 5 */
    switch (itemIdx) {
    case 0: /* upgradecommitteemembership_reset_members - members */;
      return _toStringVecIdentityId(
          &m->basic.upgradecommitteemembership_reset_members.members, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 6918: /* module 27 call 6 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 7168: /* module 28 call 0 */
    switch (itemIdx) {
    case 0: /* asset_register_ticker - ticker */;
      return _toStringTicker(&m->basic.asset_register_ticker.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7169: /* module 28 call 1 */
    switch (itemIdx) {
    case 0: /* asset_accept_ticker_transfer - auth_id */;
      return _toStringu64(&m->basic.asset_accept_ticker_transfer.auth_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7170: /* module 28 call 2 */
    switch (itemIdx) {
    case 0: /* asset_accept_primary_issuance_agent_transfer - auth_id */;
      return _toStringu64(
          &m->basic.asset_accept_primary_issuance_agent_transfer.auth_id,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7171: /* module 28 call 3 */
    switch (itemIdx) {
    case 0: /* asset_accept_asset_ownership_transfer - auth_id */;
      return _toStringu64(
          &m->basic.asset_accept_asset_ownership_transfer.auth_id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7172: /* module 28 call 4 */
    switch (itemIdx) {
    case 0: /* asset_create_asset - name */;
      return _toStringAssetName(&m->basic.asset_create_asset.name, outValue,
                                outValueLen, pageIdx, pageCount);
    case 1: /* asset_create_asset - ticker */;
      return _toStringTicker(&m->basic.asset_create_asset.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 2: /* asset_create_asset - total_supply */;
      return _toStringBalance(&m->basic.asset_create_asset.total_supply,
                              outValue, outValueLen, pageIdx, pageCount);
    case 3: /* asset_create_asset - divisible */;
      return _toStringbool(&m->basic.asset_create_asset.divisible, outValue,
                           outValueLen, pageIdx, pageCount);
    case 4: /* asset_create_asset - asset_type */;
      return _toStringAssetType(&m->basic.asset_create_asset.asset_type,
                                outValue, outValueLen, pageIdx, pageCount);
    case 5: /* asset_create_asset - identifiers */;
      return _toStringVecAssetIdentifier(
          &m->basic.asset_create_asset.identifiers, outValue, outValueLen,
          pageIdx, pageCount);
    case 6: /* asset_create_asset - funding_round */;
      return _toStringOptionFundingRoundName(
          &m->basic.asset_create_asset.funding_round, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7173: /* module 28 call 5 */
    switch (itemIdx) {
    case 0: /* asset_freeze - ticker */;
      return _toStringTicker(&m->basic.asset_freeze.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7174: /* module 28 call 6 */
    switch (itemIdx) {
    case 0: /* asset_unfreeze - ticker */;
      return _toStringTicker(&m->basic.asset_unfreeze.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7175: /* module 28 call 7 */
    switch (itemIdx) {
    case 0: /* asset_rename_asset - ticker */;
      return _toStringTicker(&m->basic.asset_rename_asset.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* asset_rename_asset - name */;
      return _toStringAssetName(&m->basic.asset_rename_asset.name, outValue,
                                outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7176: /* module 28 call 8 */
    switch (itemIdx) {
    case 0: /* asset_issue - ticker */;
      return _toStringTicker(&m->basic.asset_issue.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* asset_issue - value */;
      return _toStringBalance(&m->basic.asset_issue.value, outValue,
                              outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7177: /* module 28 call 9 */
    switch (itemIdx) {
    case 0: /* asset_redeem - ticker */;
      return _toStringTicker(&m->basic.asset_redeem.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* asset_redeem - value */;
      return _toStringBalance(&m->basic.asset_redeem.value, outValue,
                              outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7178: /* module 28 call 10 */
    switch (itemIdx) {
    case 0: /* asset_make_divisible - ticker */;
      return _toStringTicker(&m->basic.asset_make_divisible.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7179: /* module 28 call 11 */
    switch (itemIdx) {
    case 0: /* asset_add_documents - docs */;
      return _toStringVecDocument(&m->basic.asset_add_documents.docs, outValue,
                                  outValueLen, pageIdx, pageCount);
    case 1: /* asset_add_documents - ticker */;
      return _toStringTicker(&m->basic.asset_add_documents.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7180: /* module 28 call 12 */
    switch (itemIdx) {
    case 0: /* asset_remove_documents - ids */;
      return _toStringVecDocumentId(&m->basic.asset_remove_documents.ids,
                                    outValue, outValueLen, pageIdx, pageCount);
    case 1: /* asset_remove_documents - ticker */;
      return _toStringTicker(&m->basic.asset_remove_documents.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7181: /* module 28 call 13 */
    switch (itemIdx) {
    case 0: /* asset_set_funding_round - ticker */;
      return _toStringTicker(&m->basic.asset_set_funding_round.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* asset_set_funding_round - name */;
      return _toStringFundingRoundName(&m->basic.asset_set_funding_round.name,
                                       outValue, outValueLen, pageIdx,
                                       pageCount);
    default:
      return parser_no_data;
    }
  case 7182: /* module 28 call 14 */
    switch (itemIdx) {
    case 0: /* asset_update_identifiers - ticker */;
      return _toStringTicker(&m->basic.asset_update_identifiers.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* asset_update_identifiers - identifiers */;
      return _toStringVecAssetIdentifier(
          &m->basic.asset_update_identifiers.identifiers, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7183: /* module 28 call 15 */
    switch (itemIdx) {
    case 0: /* asset_add_extension - ticker */;
      return _toStringTicker(&m->basic.asset_add_extension.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* asset_add_extension - extension_details */;
      return _toStringSmartExtension(
          &m->basic.asset_add_extension.extension_details, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7184: /* module 28 call 16 */
    switch (itemIdx) {
    case 0: /* asset_archive_extension - ticker */;
      return _toStringTicker(&m->basic.asset_archive_extension.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* asset_archive_extension - extension_id */;
      return _toStringAccountId(&m->basic.asset_archive_extension.extension_id,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7185: /* module 28 call 17 */
    switch (itemIdx) {
    case 0: /* asset_unarchive_extension - ticker */;
      return _toStringTicker(&m->basic.asset_unarchive_extension.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* asset_unarchive_extension - extension_id */;
      return _toStringAccountId(
          &m->basic.asset_unarchive_extension.extension_id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7186: /* module 28 call 18 */
    switch (itemIdx) {
    case 0: /* asset_remove_primary_issuance_agent - ticker */;
      return _toStringTicker(
          &m->basic.asset_remove_primary_issuance_agent.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7187: /* module 28 call 19 */
    switch (itemIdx) {
    case 0: /* asset_remove_smart_extension - ticker */;
      return _toStringTicker(&m->basic.asset_remove_smart_extension.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* asset_remove_smart_extension - extension_id */;
      return _toStringAccountId(
          &m->basic.asset_remove_smart_extension.extension_id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7188: /* module 28 call 20 */
    switch (itemIdx) {
    case 0: /* asset_claim_classic_ticker - ticker */;
      return _toStringTicker(&m->basic.asset_claim_classic_ticker.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* asset_claim_classic_ticker - ethereum_signature */;
      return _toStringEcdsaSignature(
          &m->basic.asset_claim_classic_ticker.ethereum_signature, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7189: /* module 28 call 21 */
    switch (itemIdx) {
    case 0: /* asset_reserve_classic_ticker - classic_ticker_import */;
      return _toStringClassicTickerImport(
          &m->basic.asset_reserve_classic_ticker.classic_ticker_import,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* asset_reserve_classic_ticker - contract_did */;
      return _toStringIdentityId(
          &m->basic.asset_reserve_classic_ticker.contract_did, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* asset_reserve_classic_ticker - config */;
      return _toStringTickerRegistrationConfig(
          &m->basic.asset_reserve_classic_ticker.config, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7424: /* module 29 call 0 */
    switch (itemIdx) {
    case 0: /* dividend_new - amount */;
      return _toStringBalance(&m->basic.dividend_new.amount, outValue,
                              outValueLen, pageIdx, pageCount);
    case 1: /* dividend_new - ticker */;
      return _toStringTicker(&m->basic.dividend_new.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 2: /* dividend_new - matures_at */;
      return _toStringMoment(&m->basic.dividend_new.matures_at, outValue,
                             outValueLen, pageIdx, pageCount);
    case 3: /* dividend_new - expires_at */;
      return _toStringMoment(&m->basic.dividend_new.expires_at, outValue,
                             outValueLen, pageIdx, pageCount);
    case 4: /* dividend_new - payout_ticker */;
      return _toStringTicker(&m->basic.dividend_new.payout_ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 5: /* dividend_new - checkpoint_id */;
      return _toStringCheckpointId(&m->basic.dividend_new.checkpoint_id,
                                   outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7425: /* module 29 call 1 */
    switch (itemIdx) {
    case 0: /* dividend_cancel - ticker */;
      return _toStringTicker(&m->basic.dividend_cancel.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* dividend_cancel - dividend_id */;
      return _toStringu32(&m->basic.dividend_cancel.dividend_id, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7426: /* module 29 call 2 */
    switch (itemIdx) {
    case 0: /* dividend_claim - ticker */;
      return _toStringTicker(&m->basic.dividend_claim.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* dividend_claim - dividend_id */;
      return _toStringu32(&m->basic.dividend_claim.dividend_id, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7427: /* module 29 call 3 */
    switch (itemIdx) {
    case 0: /* dividend_claim_unclaimed - ticker */;
      return _toStringTicker(&m->basic.dividend_claim_unclaimed.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* dividend_claim_unclaimed - dividend_id */;
      return _toStringu32(&m->basic.dividend_claim_unclaimed.dividend_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7680: /* module 30 call 0 */
    switch (itemIdx) {
    case 0: /* identity_register_did - uid */;
      return _toStringInvestorUid(&m->basic.identity_register_did.uid, outValue,
                                  outValueLen, pageIdx, pageCount);
    case 1: /* identity_register_did - secondary_keys */;
      return _toStringVecSecondaryKey(
          &m->basic.identity_register_did.secondary_keys, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7681: /* module 30 call 1 */
    switch (itemIdx) {
    case 0: /* identity_cdd_register_did - target_account */;
      return _toStringAccountId(
          &m->basic.identity_cdd_register_did.target_account, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* identity_cdd_register_did - secondary_keys */;
      return _toStringVecSecondaryKey(
          &m->basic.identity_cdd_register_did.secondary_keys, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7682: /* module 30 call 2 */
    switch (itemIdx) {
    case 0: /* identity_mock_cdd_register_did - target_account */;
      return _toStringAccountId(
          &m->basic.identity_mock_cdd_register_did.target_account, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7683: /* module 30 call 3 */
    switch (itemIdx) {
    case 0: /* identity_invalidate_cdd_claims - cdd */;
      return _toStringIdentityId(&m->basic.identity_invalidate_cdd_claims.cdd,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 1: /* identity_invalidate_cdd_claims - disable_from */;
      return _toStringMoment(
          &m->basic.identity_invalidate_cdd_claims.disable_from, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* identity_invalidate_cdd_claims - expiry */;
      return _toStringOptionMoment(
          &m->basic.identity_invalidate_cdd_claims.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7684: /* module 30 call 4 */
    switch (itemIdx) {
    case 0: /* identity_remove_secondary_keys - signers_to_remove */;
      return _toStringVecSignatory(
          &m->basic.identity_remove_secondary_keys.signers_to_remove, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7685: /* module 30 call 5 */
    switch (itemIdx) {
    case 0: /* identity_accept_primary_key - rotation_auth_id */;
      return _toStringu64(
          &m->basic.identity_accept_primary_key.rotation_auth_id, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* identity_accept_primary_key - optional_cdd_auth_id */;
      return _toStringOptionu64(
          &m->basic.identity_accept_primary_key.optional_cdd_auth_id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7686: /* module 30 call 6 */
    switch (itemIdx) {
    case 0: /* identity_change_cdd_requirement_for_mk_rotation - auth_required
             */
        ;
      return _toStringbool(
          &m->basic.identity_change_cdd_requirement_for_mk_rotation
               .auth_required,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7687: /* module 30 call 7 */
    switch (itemIdx) {
    case 0: /* identity_join_identity_as_key - auth_id */;
      return _toStringu64(&m->basic.identity_join_identity_as_key.auth_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7688: /* module 30 call 8 */
    switch (itemIdx) {
    case 0: /* identity_join_identity_as_identity - auth_id */;
      return _toStringu64(&m->basic.identity_join_identity_as_identity.auth_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7689: /* module 30 call 9 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 7690: /* module 30 call 10 */
    switch (itemIdx) {
    case 0: /* identity_leave_identity_as_identity - did */;
      return _toStringIdentityId(
          &m->basic.identity_leave_identity_as_identity.did, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7691: /* module 30 call 11 */
    switch (itemIdx) {
    case 0: /* identity_add_claim - target */;
      return _toStringIdentityId(&m->basic.identity_add_claim.target, outValue,
                                 outValueLen, pageIdx, pageCount);
    case 1: /* identity_add_claim - claim */;
      return _toStringClaim(&m->basic.identity_add_claim.claim, outValue,
                            outValueLen, pageIdx, pageCount);
    case 2: /* identity_add_claim - expiry */;
      return _toStringOptionMoment(&m->basic.identity_add_claim.expiry,
                                   outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7692: /* module 30 call 12 */
    switch (itemIdx) {
    case 0: /* identity_forwarded_call - target_did */;
      return _toStringIdentityId(&m->nested.identity_forwarded_call.target_did,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 1: /* identity_forwarded_call - proposal */;
      return _toStringProposal(&m->nested.identity_forwarded_call.proposal,
                               outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7693: /* module 30 call 13 */
    switch (itemIdx) {
    case 0: /* identity_revoke_claim - target */;
      return _toStringIdentityId(&m->basic.identity_revoke_claim.target,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 1: /* identity_revoke_claim - claim */;
      return _toStringClaim(&m->basic.identity_revoke_claim.claim, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7694: /* module 30 call 14 */
    switch (itemIdx) {
    case 0: /* identity_set_permission_to_signer - signer */;
      return _toStringSignatory(
          &m->basic.identity_set_permission_to_signer.signer, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* identity_set_permission_to_signer - permissions */;
      return _toStringPermissions(
          &m->basic.identity_set_permission_to_signer.permissions, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7695: /* module 30 call 15 */
    switch (itemIdx) {
    case 0: /* identity_legacy_set_permission_to_signer - signer */;
      return _toStringSignatory(
          &m->basic.identity_legacy_set_permission_to_signer.signer, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* identity_legacy_set_permission_to_signer - permissions */;
      return _toStringLegacyPermissions(
          &m->basic.identity_legacy_set_permission_to_signer.permissions,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7696: /* module 30 call 16 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 7697: /* module 30 call 17 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 7698: /* module 30 call 18 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 7699: /* module 30 call 19 */
    switch (itemIdx) {
    case 0: /* identity_get_cdd_of - of */;
      return _toStringAccountId(&m->basic.identity_get_cdd_of.of, outValue,
                                outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7700: /* module 30 call 20 */
    switch (itemIdx) {
    case 0: /* identity_add_authorization - target */;
      return _toStringSignatory(&m->basic.identity_add_authorization.target,
                                outValue, outValueLen, pageIdx, pageCount);
    case 1: /* identity_add_authorization - authorization_data */;
      return _toStringAuthorizationData(
          &m->basic.identity_add_authorization.authorization_data, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* identity_add_authorization - expiry */;
      return _toStringOptionMoment(&m->basic.identity_add_authorization.expiry,
                                   outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7701: /* module 30 call 21 */
    switch (itemIdx) {
    case 0: /* identity_remove_authorization - target */;
      return _toStringSignatory(&m->basic.identity_remove_authorization.target,
                                outValue, outValueLen, pageIdx, pageCount);
    case 1: /* identity_remove_authorization - auth_id */;
      return _toStringu64(&m->basic.identity_remove_authorization.auth_id,
                          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* identity_remove_authorization - _auth_issuer_pays */;
      return _toStringbool(
          &m->basic.identity_remove_authorization._auth_issuer_pays, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7702: /* module 30 call 22 */
    switch (itemIdx) {
    case 0: /* identity_accept_authorization - auth_id */;
      return _toStringu64(&m->basic.identity_accept_authorization.auth_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7703: /* module 30 call 23 */
    switch (itemIdx) {
    case 0: /* identity_add_secondary_keys_with_authorization - additional_keys
             */
        ;
      return _toStringVecSecondaryKeyWithAuth(
          &m->basic.identity_add_secondary_keys_with_authorization
               .additional_keys,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* identity_add_secondary_keys_with_authorization - expires_at */;
      return _toStringMoment(
          &m->basic.identity_add_secondary_keys_with_authorization.expires_at,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7704: /* module 30 call 24 */
    switch (itemIdx) {
    case 0: /* identity_revoke_offchain_authorization - signer */;
      return _toStringSignatory(
          &m->basic.identity_revoke_offchain_authorization.signer, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* identity_revoke_offchain_authorization - auth */;
      return _toStringTargetIdAuthorization(
          &m->basic.identity_revoke_offchain_authorization.auth, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7705: /* module 30 call 25 */
    switch (itemIdx) {
    case 0: /* identity_add_investor_uniqueness_claim - target */;
      return _toStringIdentityId(
          &m->basic.identity_add_investor_uniqueness_claim.target, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* identity_add_investor_uniqueness_claim - claim */;
      return _toStringClaim(
          &m->basic.identity_add_investor_uniqueness_claim.claim, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* identity_add_investor_uniqueness_claim - proof */;
      return _toStringInvestorZKProofData(
          &m->basic.identity_add_investor_uniqueness_claim.proof, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* identity_add_investor_uniqueness_claim - expiry */;
      return _toStringOptionMoment(
          &m->basic.identity_add_investor_uniqueness_claim.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7706: /* module 30 call 26 */
    switch (itemIdx) {
    case 0: /* identity_gc_add_cdd_claim - target */;
      return _toStringIdentityId(&m->basic.identity_gc_add_cdd_claim.target,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 1: /* identity_gc_add_cdd_claim - expiry */;
      return _toStringOptionMoment(&m->basic.identity_gc_add_cdd_claim.expiry,
                                   outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7707: /* module 30 call 27 */
    switch (itemIdx) {
    case 0: /* identity_gc_revoke_cdd_claim - target */;
      return _toStringIdentityId(&m->basic.identity_gc_revoke_cdd_claim.target,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7936: /* module 31 call 0 */
    switch (itemIdx) {
    case 0: /* bridge_change_controller - controller */;
      return _toStringAccountId(&m->basic.bridge_change_controller.controller,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7937: /* module 31 call 1 */
    switch (itemIdx) {
    case 0: /* bridge_change_admin - admin */;
      return _toStringAccountId(&m->basic.bridge_change_admin.admin, outValue,
                                outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7938: /* module 31 call 2 */
    switch (itemIdx) {
    case 0: /* bridge_change_timelock - timelock */;
      return _toStringBlockNumber(&m->basic.bridge_change_timelock.timelock,
                                  outValue, outValueLen, pageIdx, pageCount);
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
    case 0: /* bridge_change_bridge_limit - amount */;
      return _toStringBalance(&m->basic.bridge_change_bridge_limit.amount,
                              outValue, outValueLen, pageIdx, pageCount);
    case 1: /* bridge_change_bridge_limit - duration */;
      return _toStringBlockNumber(&m->basic.bridge_change_bridge_limit.duration,
                                  outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7942: /* module 31 call 6 */
    switch (itemIdx) {
    case 0: /* bridge_change_bridge_exempted - exempted */;
      return _toStringVecTupleIdentityIdbool(
          &m->basic.bridge_change_bridge_exempted.exempted, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7943: /* module 31 call 7 */
    switch (itemIdx) {
    case 0: /* bridge_force_handle_bridge_tx - bridge_tx */;
      return _toStringBridgeTx(
          &m->basic.bridge_force_handle_bridge_tx.bridge_tx, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7944: /* module 31 call 8 */
    switch (itemIdx) {
    case 0: /* bridge_batch_propose_bridge_tx - bridge_txs */;
      return _toStringVecBridgeTx(
          &m->basic.bridge_batch_propose_bridge_tx.bridge_txs, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7945: /* module 31 call 9 */
    switch (itemIdx) {
    case 0: /* bridge_propose_bridge_tx - bridge_tx */;
      return _toStringBridgeTx(&m->basic.bridge_propose_bridge_tx.bridge_tx,
                               outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7946: /* module 31 call 10 */
    switch (itemIdx) {
    case 0: /* bridge_handle_bridge_tx - bridge_tx */;
      return _toStringBridgeTx(&m->basic.bridge_handle_bridge_tx.bridge_tx,
                               outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7947: /* module 31 call 11 */
    switch (itemIdx) {
    case 0: /* bridge_freeze_txs - bridge_txs */;
      return _toStringVecBridgeTx(&m->basic.bridge_freeze_txs.bridge_txs,
                                  outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7948: /* module 31 call 12 */
    switch (itemIdx) {
    case 0: /* bridge_unfreeze_txs - bridge_txs */;
      return _toStringVecBridgeTx(&m->basic.bridge_unfreeze_txs.bridge_txs,
                                  outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 7949: /* module 31 call 13 */
    switch (itemIdx) {
    case 0: /* bridge_handle_scheduled_bridge_tx - bridge_tx */;
      return _toStringBridgeTx(
          &m->basic.bridge_handle_scheduled_bridge_tx.bridge_tx, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8192: /* module 32 call 0 */
    switch (itemIdx) {
    case 0: /* compliancemanager_add_compliance_requirement - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_add_compliance_requirement.ticker,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* compliancemanager_add_compliance_requirement - sender_conditions
             */
        ;
      return _toStringVecCondition(
          &m->basic.compliancemanager_add_compliance_requirement
               .sender_conditions,
          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* compliancemanager_add_compliance_requirement -
               receiver_conditions */
        ;
      return _toStringVecCondition(
          &m->basic.compliancemanager_add_compliance_requirement
               .receiver_conditions,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8193: /* module 32 call 1 */
    switch (itemIdx) {
    case 0: /* compliancemanager_remove_compliance_requirement - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_remove_compliance_requirement.ticker,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* compliancemanager_remove_compliance_requirement - id */;
      return _toStringu32(
          &m->basic.compliancemanager_remove_compliance_requirement.id,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8194: /* module 32 call 2 */
    switch (itemIdx) {
    case 0: /* compliancemanager_replace_asset_compliance - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_replace_asset_compliance.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* compliancemanager_replace_asset_compliance - asset_compliance */;
      return _toStringVecComplianceRequirement(
          &m->basic.compliancemanager_replace_asset_compliance.asset_compliance,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8195: /* module 32 call 3 */
    switch (itemIdx) {
    case 0: /* compliancemanager_reset_asset_compliance - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_reset_asset_compliance.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8196: /* module 32 call 4 */
    switch (itemIdx) {
    case 0: /* compliancemanager_pause_asset_compliance - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_pause_asset_compliance.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8197: /* module 32 call 5 */
    switch (itemIdx) {
    case 0: /* compliancemanager_resume_asset_compliance - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_resume_asset_compliance.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8198: /* module 32 call 6 */
    switch (itemIdx) {
    case 0: /* compliancemanager_add_default_trusted_claim_issuer - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_add_default_trusted_claim_issuer.ticker,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* compliancemanager_add_default_trusted_claim_issuer - issuer */;
      return _toStringTrustedIssuer(
          &m->basic.compliancemanager_add_default_trusted_claim_issuer.issuer,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8199: /* module 32 call 7 */
    switch (itemIdx) {
    case 0: /* compliancemanager_remove_default_trusted_claim_issuer - ticker */
        ;
      return _toStringTicker(
          &m->basic.compliancemanager_remove_default_trusted_claim_issuer
               .ticker,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* compliancemanager_remove_default_trusted_claim_issuer - issuer */
        ;
      return _toStringTrustedIssuer(
          &m->basic.compliancemanager_remove_default_trusted_claim_issuer
               .issuer,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8200: /* module 32 call 8 */
    switch (itemIdx) {
    case 0: /* compliancemanager_change_compliance_requirement - ticker */;
      return _toStringTicker(
          &m->basic.compliancemanager_change_compliance_requirement.ticker,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* compliancemanager_change_compliance_requirement - new_req */;
      return _toStringComplianceRequirement(
          &m->basic.compliancemanager_change_compliance_requirement.new_req,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8448: /* module 33 call 0 */
    switch (itemIdx) {
    case 0: /* voting_add_ballot - ticker */;
      return _toStringTicker(&m->basic.voting_add_ballot.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* voting_add_ballot - ballot_name */;
      return _toStringBytes(&m->basic.voting_add_ballot.ballot_name, outValue,
                            outValueLen, pageIdx, pageCount);
    case 2: /* voting_add_ballot - ballot_details */;
      return _toStringBallot(&m->basic.voting_add_ballot.ballot_details,
                             outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8449: /* module 33 call 1 */
    switch (itemIdx) {
    case 0: /* voting_vote - ticker */;
      return _toStringTicker(&m->basic.voting_vote.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* voting_vote - ballot_name */;
      return _toStringBytes(&m->basic.voting_vote.ballot_name, outValue,
                            outValueLen, pageIdx, pageCount);
    case 2: /* voting_vote - votes */;
      return _toStringVecBalance(&m->basic.voting_vote.votes, outValue,
                                 outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8450: /* module 33 call 2 */
    switch (itemIdx) {
    case 0: /* voting_cancel_ballot - ticker */;
      return _toStringTicker(&m->basic.voting_cancel_ballot.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* voting_cancel_ballot - ballot_name */;
      return _toStringBytes(&m->basic.voting_cancel_ballot.ballot_name,
                            outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8704: /* module 34 call 0 */
    switch (itemIdx) {
    case 0: /* stocapped_launch_sto - ticker */;
      return _toStringTicker(&m->basic.stocapped_launch_sto.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* stocapped_launch_sto - beneficiary_did */;
      return _toStringIdentityId(&m->basic.stocapped_launch_sto.beneficiary_did,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 2: /* stocapped_launch_sto - cap */;
      return _toStringBalance(&m->basic.stocapped_launch_sto.cap, outValue,
                              outValueLen, pageIdx, pageCount);
    case 3: /* stocapped_launch_sto - rate */;
      return _toStringu128(&m->basic.stocapped_launch_sto.rate, outValue,
                           outValueLen, pageIdx, pageCount);
    case 4: /* stocapped_launch_sto - start_date */;
      return _toStringMoment(&m->basic.stocapped_launch_sto.start_date,
                             outValue, outValueLen, pageIdx, pageCount);
    case 5: /* stocapped_launch_sto - end_date */;
      return _toStringMoment(&m->basic.stocapped_launch_sto.end_date, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8705: /* module 34 call 1 */
    switch (itemIdx) {
    case 0: /* stocapped_buy_tokens - ticker */;
      return _toStringTicker(&m->basic.stocapped_buy_tokens.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* stocapped_buy_tokens - sto_id */;
      return _toStringu32(&m->basic.stocapped_buy_tokens.sto_id, outValue,
                          outValueLen, pageIdx, pageCount);
    case 2: /* stocapped_buy_tokens - value */;
      return _toStringBalance(&m->basic.stocapped_buy_tokens.value, outValue,
                              outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8706: /* module 34 call 2 */
    switch (itemIdx) {
    case 0: /* stocapped_pause_sto - ticker */;
      return _toStringTicker(&m->basic.stocapped_pause_sto.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* stocapped_pause_sto - sto_id */;
      return _toStringu32(&m->basic.stocapped_pause_sto.sto_id, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8707: /* module 34 call 3 */
    switch (itemIdx) {
    case 0: /* stocapped_unpause_sto - ticker */;
      return _toStringTicker(&m->basic.stocapped_unpause_sto.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* stocapped_unpause_sto - sto_id */;
      return _toStringu32(&m->basic.stocapped_unpause_sto.sto_id, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 8960: /* module 35 call 0 */
    switch (itemIdx) {
    case 0: /* exemption_modify_exemption_list - ticker */;
      return _toStringTicker(&m->basic.exemption_modify_exemption_list.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* exemption_modify_exemption_list - _tm */;
      return _toStringu16(&m->basic.exemption_modify_exemption_list._tm,
                          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* exemption_modify_exemption_list - asset_holder_did */;
      return _toStringIdentityId(
          &m->basic.exemption_modify_exemption_list.asset_holder_did, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* exemption_modify_exemption_list - exempted */;
      return _toStringbool(&m->basic.exemption_modify_exemption_list.exempted,
                           outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9216: /* module 36 call 0 */
    switch (itemIdx) {
    case 0: /* settlement_create_venue - details */;
      return _toStringVenueDetails(&m->basic.settlement_create_venue.details,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 1: /* settlement_create_venue - signers */;
      return _toStringVecAccountId(&m->basic.settlement_create_venue.signers,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 2: /* settlement_create_venue - venue_type */;
      return _toStringVenueType(&m->basic.settlement_create_venue.venue_type,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9217: /* module 36 call 1 */
    switch (itemIdx) {
    case 0: /* settlement_update_venue - venue_id */;
      return _toStringu64(&m->basic.settlement_update_venue.venue_id, outValue,
                          outValueLen, pageIdx, pageCount);
    case 1: /* settlement_update_venue - details */;
      return _toStringOptionVenueDetails(
          &m->basic.settlement_update_venue.details, outValue, outValueLen,
          pageIdx, pageCount);
    case 2: /* settlement_update_venue - venue_type */;
      return _toStringOptionVenueType(
          &m->basic.settlement_update_venue.venue_type, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9218: /* module 36 call 2 */
    switch (itemIdx) {
    case 0: /* settlement_add_instruction - venue_id */;
      return _toStringu64(&m->basic.settlement_add_instruction.venue_id,
                          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* settlement_add_instruction - settlement_type */;
      return _toStringSettlementType(
          &m->basic.settlement_add_instruction.settlement_type, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* settlement_add_instruction - valid_from */;
      return _toStringOptionMoment(
          &m->basic.settlement_add_instruction.valid_from, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* settlement_add_instruction - legs */;
      return _toStringVecLeg(&m->basic.settlement_add_instruction.legs,
                             outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9219: /* module 36 call 3 */
    switch (itemIdx) {
    case 0: /* settlement_add_and_affirm_instruction - venue_id */;
      return _toStringu64(
          &m->basic.settlement_add_and_affirm_instruction.venue_id, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* settlement_add_and_affirm_instruction - settlement_type */;
      return _toStringSettlementType(
          &m->basic.settlement_add_and_affirm_instruction.settlement_type,
          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* settlement_add_and_affirm_instruction - valid_from */;
      return _toStringOptionMoment(
          &m->basic.settlement_add_and_affirm_instruction.valid_from, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* settlement_add_and_affirm_instruction - legs */;
      return _toStringVecLeg(
          &m->basic.settlement_add_and_affirm_instruction.legs, outValue,
          outValueLen, pageIdx, pageCount);
    case 4: /* settlement_add_and_affirm_instruction - portfolios */;
      return _toStringVecPortfolioId(
          &m->basic.settlement_add_and_affirm_instruction.portfolios, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9220: /* module 36 call 4 */
    switch (itemIdx) {
    case 0: /* settlement_affirm_instruction - instruction_id */;
      return _toStringu64(
          &m->basic.settlement_affirm_instruction.instruction_id, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* settlement_affirm_instruction - portfolios */;
      return _toStringVecPortfolioId(
          &m->basic.settlement_affirm_instruction.portfolios, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9221: /* module 36 call 5 */
    switch (itemIdx) {
    case 0: /* settlement_withdraw_affirmation - instruction_id */;
      return _toStringu64(
          &m->basic.settlement_withdraw_affirmation.instruction_id, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* settlement_withdraw_affirmation - portfolios */;
      return _toStringVecPortfolioId(
          &m->basic.settlement_withdraw_affirmation.portfolios, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9222: /* module 36 call 6 */
    switch (itemIdx) {
    case 0: /* settlement_reject_instruction - instruction_id */;
      return _toStringu64(
          &m->basic.settlement_reject_instruction.instruction_id, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* settlement_reject_instruction - portfolios */;
      return _toStringVecPortfolioId(
          &m->basic.settlement_reject_instruction.portfolios, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9223: /* module 36 call 7 */
    switch (itemIdx) {
    case 0: /* settlement_affirm_with_receipts - instruction_id */;
      return _toStringu64(
          &m->basic.settlement_affirm_with_receipts.instruction_id, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* settlement_affirm_with_receipts - receipt_details */;
      return _toStringVecReceiptDetails(
          &m->basic.settlement_affirm_with_receipts.receipt_details, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* settlement_affirm_with_receipts - portfolios */;
      return _toStringVecPortfolioId(
          &m->basic.settlement_affirm_with_receipts.portfolios, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9224: /* module 36 call 8 */
    switch (itemIdx) {
    case 0: /* settlement_claim_receipt - instruction_id */;
      return _toStringu64(&m->basic.settlement_claim_receipt.instruction_id,
                          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* settlement_claim_receipt - receipt_details */;
      return _toStringReceiptDetails(
          &m->basic.settlement_claim_receipt.receipt_details, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9225: /* module 36 call 9 */
    switch (itemIdx) {
    case 0: /* settlement_unclaim_receipt - instruction_id */;
      return _toStringu64(&m->basic.settlement_unclaim_receipt.instruction_id,
                          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* settlement_unclaim_receipt - leg_id */;
      return _toStringu64(&m->basic.settlement_unclaim_receipt.leg_id, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9226: /* module 36 call 10 */
    switch (itemIdx) {
    case 0: /* settlement_set_venue_filtering - ticker */;
      return _toStringTicker(&m->basic.settlement_set_venue_filtering.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* settlement_set_venue_filtering - enabled */;
      return _toStringbool(&m->basic.settlement_set_venue_filtering.enabled,
                           outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9227: /* module 36 call 11 */
    switch (itemIdx) {
    case 0: /* settlement_allow_venues - ticker */;
      return _toStringTicker(&m->basic.settlement_allow_venues.ticker, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* settlement_allow_venues - venues */;
      return _toStringVecu64(&m->basic.settlement_allow_venues.venues, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9228: /* module 36 call 12 */
    switch (itemIdx) {
    case 0: /* settlement_disallow_venues - ticker */;
      return _toStringTicker(&m->basic.settlement_disallow_venues.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* settlement_disallow_venues - venues */;
      return _toStringVecu64(&m->basic.settlement_disallow_venues.venues,
                             outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9229: /* module 36 call 13 */
    switch (itemIdx) {
    case 0: /* settlement_execute_scheduled_instruction - instruction_id */;
      return _toStringu64(
          &m->basic.settlement_execute_scheduled_instruction.instruction_id,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9472: /* module 37 call 0 */
    switch (itemIdx) {
    case 0: /* sto_create_fundraiser - offering_portfolio */;
      return _toStringPortfolioId(
          &m->basic.sto_create_fundraiser.offering_portfolio, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* sto_create_fundraiser - offering_asset */;
      return _toStringTicker(&m->basic.sto_create_fundraiser.offering_asset,
                             outValue, outValueLen, pageIdx, pageCount);
    case 2: /* sto_create_fundraiser - raising_portfolio */;
      return _toStringPortfolioId(
          &m->basic.sto_create_fundraiser.raising_portfolio, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* sto_create_fundraiser - raising_asset */;
      return _toStringTicker(&m->basic.sto_create_fundraiser.raising_asset,
                             outValue, outValueLen, pageIdx, pageCount);
    case 4: /* sto_create_fundraiser - tiers */;
      return _toStringVecPriceTier(&m->basic.sto_create_fundraiser.tiers,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 5: /* sto_create_fundraiser - venue_id */;
      return _toStringu64(&m->basic.sto_create_fundraiser.venue_id, outValue,
                          outValueLen, pageIdx, pageCount);
    case 6: /* sto_create_fundraiser - start */;
      return _toStringOptionMoment(&m->basic.sto_create_fundraiser.start,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 7: /* sto_create_fundraiser - end */;
      return _toStringOptionMoment(&m->basic.sto_create_fundraiser.end,
                                   outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9473: /* module 37 call 1 */
    switch (itemIdx) {
    case 0: /* sto_invest - investment_portfolio */;
      return _toStringPortfolioId(&m->basic.sto_invest.investment_portfolio,
                                  outValue, outValueLen, pageIdx, pageCount);
    case 1: /* sto_invest - funding_portfolio */;
      return _toStringPortfolioId(&m->basic.sto_invest.funding_portfolio,
                                  outValue, outValueLen, pageIdx, pageCount);
    case 2: /* sto_invest - offering_asset */;
      return _toStringTicker(&m->basic.sto_invest.offering_asset, outValue,
                             outValueLen, pageIdx, pageCount);
    case 3: /* sto_invest - fundraiser_id */;
      return _toStringu64(&m->basic.sto_invest.fundraiser_id, outValue,
                          outValueLen, pageIdx, pageCount);
    case 4: /* sto_invest - investment_amount */;
      return _toStringBalance(&m->basic.sto_invest.investment_amount, outValue,
                              outValueLen, pageIdx, pageCount);
    case 5: /* sto_invest - max_price */;
      return _toStringOptionBalance(&m->basic.sto_invest.max_price, outValue,
                                    outValueLen, pageIdx, pageCount);
    case 6: /* sto_invest - receipt */;
      return _toStringOptionReceiptDetails(&m->basic.sto_invest.receipt,
                                           outValue, outValueLen, pageIdx,
                                           pageCount);
    default:
      return parser_no_data;
    }
  case 9474: /* module 37 call 2 */
    switch (itemIdx) {
    case 0: /* sto_freeze_fundraiser - offering_asset */;
      return _toStringTicker(&m->basic.sto_freeze_fundraiser.offering_asset,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* sto_freeze_fundraiser - fundraiser_id */;
      return _toStringu64(&m->basic.sto_freeze_fundraiser.fundraiser_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9475: /* module 37 call 3 */
    switch (itemIdx) {
    case 0: /* sto_unfreeze_fundraiser - offering_asset */;
      return _toStringTicker(&m->basic.sto_unfreeze_fundraiser.offering_asset,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* sto_unfreeze_fundraiser - fundraiser_id */;
      return _toStringu64(&m->basic.sto_unfreeze_fundraiser.fundraiser_id,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9476: /* module 37 call 4 */
    switch (itemIdx) {
    case 0: /* sto_modify_fundraiser_window - offering_asset */;
      return _toStringTicker(
          &m->basic.sto_modify_fundraiser_window.offering_asset, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* sto_modify_fundraiser_window - fundraiser_id */;
      return _toStringu64(&m->basic.sto_modify_fundraiser_window.fundraiser_id,
                          outValue, outValueLen, pageIdx, pageCount);
    case 2: /* sto_modify_fundraiser_window - start */;
      return _toStringMoment(&m->basic.sto_modify_fundraiser_window.start,
                             outValue, outValueLen, pageIdx, pageCount);
    case 3: /* sto_modify_fundraiser_window - end */;
      return _toStringOptionMoment(&m->basic.sto_modify_fundraiser_window.end,
                                   outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9477: /* module 37 call 5 */
    switch (itemIdx) {
    case 0: /* sto_stop - offering_asset */;
      return _toStringTicker(&m->basic.sto_stop.offering_asset, outValue,
                             outValueLen, pageIdx, pageCount);
    case 1: /* sto_stop - fundraiser_id */;
      return _toStringu64(&m->basic.sto_stop.fundraiser_id, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9728: /* module 38 call 0 */
    switch (itemIdx) {
    case 0: /* cddserviceproviders_set_active_members_limit - limit */;
      return _toStringMemberCount(
          &m->basic.cddserviceproviders_set_active_members_limit.limit,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9729: /* module 38 call 1 */
    switch (itemIdx) {
    case 0: /* cddserviceproviders_disable_member - who */;
      return _toStringIdentityId(
          &m->basic.cddserviceproviders_disable_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* cddserviceproviders_disable_member - expiry */;
      return _toStringOptionMoment(
          &m->basic.cddserviceproviders_disable_member.expiry, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* cddserviceproviders_disable_member - at */;
      return _toStringOptionMoment(
          &m->basic.cddserviceproviders_disable_member.at, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9730: /* module 38 call 2 */
    switch (itemIdx) {
    case 0: /* cddserviceproviders_add_member - who */;
      return _toStringIdentityId(&m->basic.cddserviceproviders_add_member.who,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9731: /* module 38 call 3 */
    switch (itemIdx) {
    case 0: /* cddserviceproviders_remove_member - who */;
      return _toStringIdentityId(
          &m->basic.cddserviceproviders_remove_member.who, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9732: /* module 38 call 4 */
    switch (itemIdx) {
    case 0: /* cddserviceproviders_swap_member - remove */;
      return _toStringIdentityId(
          &m->basic.cddserviceproviders_swap_member.remove, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* cddserviceproviders_swap_member - add */;
      return _toStringIdentityId(&m->basic.cddserviceproviders_swap_member.add,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9733: /* module 38 call 5 */
    switch (itemIdx) {
    case 0: /* cddserviceproviders_reset_members - members */;
      return _toStringVecIdentityId(
          &m->basic.cddserviceproviders_reset_members.members, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 9734: /* module 38 call 6 */
    switch (itemIdx) {
    default:
      return parser_no_data;
    }
  case 10240: /* module 40 call 0 */
    switch (itemIdx) {
    case 0: /* protocolfee_change_coefficient - coefficient */;
      return _toStringPosRatio(
          &m->basic.protocolfee_change_coefficient.coefficient, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10241: /* module 40 call 1 */
    switch (itemIdx) {
    case 0: /* protocolfee_change_base_fee - op */;
      return _toStringProtocolOp(&m->basic.protocolfee_change_base_fee.op,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 1: /* protocolfee_change_base_fee - base_fee */;
      return _toStringBalanceOf(&m->basic.protocolfee_change_base_fee.base_fee,
                                outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10496: /* module 41 call 0 */
    switch (itemIdx) {
    case 0: /* utility_batch - calls */;
      return _toStringVecCall(&m->basic.utility_batch.calls, outValue,
                              outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10497: /* module 41 call 1 */
    switch (itemIdx) {
    case 0: /* utility_batch_atomic - calls */;
      return _toStringVecCall(&m->basic.utility_batch_atomic.calls, outValue,
                              outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10498: /* module 41 call 2 */
    switch (itemIdx) {
    case 0: /* utility_batch_optimistic - calls */;
      return _toStringVecCall(&m->basic.utility_batch_optimistic.calls,
                              outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10499: /* module 41 call 3 */
    switch (itemIdx) {
    case 0: /* utility_relay_tx - target */;
      return _toStringAccountId(&m->basic.utility_relay_tx.target, outValue,
                                outValueLen, pageIdx, pageCount);
    case 1: /* utility_relay_tx - signature */;
      return _toStringOffChainSignature(&m->basic.utility_relay_tx.signature,
                                        outValue, outValueLen, pageIdx,
                                        pageCount);
    case 2: /* utility_relay_tx - call */;
      return _toStringUniqueCall(&m->basic.utility_relay_tx.call, outValue,
                                 outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10752: /* module 42 call 0 */
    switch (itemIdx) {
    case 0: /* portfolio_create_portfolio - name */;
      return _toStringPortfolioName(&m->basic.portfolio_create_portfolio.name,
                                    outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10753: /* module 42 call 1 */
    switch (itemIdx) {
    case 0: /* portfolio_delete_portfolio - num */;
      return _toStringPortfolioNumber(&m->basic.portfolio_delete_portfolio.num,
                                      outValue, outValueLen, pageIdx,
                                      pageCount);
    default:
      return parser_no_data;
    }
  case 10754: /* module 42 call 2 */
    switch (itemIdx) {
    case 0: /* portfolio_move_portfolio_funds - from */;
      return _toStringPortfolioId(&m->basic.portfolio_move_portfolio_funds.from,
                                  outValue, outValueLen, pageIdx, pageCount);
    case 1: /* portfolio_move_portfolio_funds - to */;
      return _toStringPortfolioId(&m->basic.portfolio_move_portfolio_funds.to,
                                  outValue, outValueLen, pageIdx, pageCount);
    case 2: /* portfolio_move_portfolio_funds - items */;
      return _toStringVecMovePortfolioItem(
          &m->basic.portfolio_move_portfolio_funds.items, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 10755: /* module 42 call 3 */
    switch (itemIdx) {
    case 0: /* portfolio_rename_portfolio - num */;
      return _toStringPortfolioNumber(&m->basic.portfolio_rename_portfolio.num,
                                      outValue, outValueLen, pageIdx,
                                      pageCount);
    case 1: /* portfolio_rename_portfolio - to_name */;
      return _toStringPortfolioName(
          &m->basic.portfolio_rename_portfolio.to_name, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11008: /* module 43 call 0 */
    switch (itemIdx) {
    case 0: /* confidential_add_range_proof - target_id */;
      return _toStringIdentityId(
          &m->basic.confidential_add_range_proof.target_id, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* confidential_add_range_proof - ticker */;
      return _toStringTicker(&m->basic.confidential_add_range_proof.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 2: /* confidential_add_range_proof - secret_value */;
      return _toStringu64(&m->basic.confidential_add_range_proof.secret_value,
                          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11009: /* module 43 call 1 */
    switch (itemIdx) {
    case 0: /* confidential_add_verify_range_proof - target */;
      return _toStringIdentityId(
          &m->basic.confidential_add_verify_range_proof.target, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* confidential_add_verify_range_proof - prover */;
      return _toStringIdentityId(
          &m->basic.confidential_add_verify_range_proof.prover, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* confidential_add_verify_range_proof - ticker */;
      return _toStringTicker(
          &m->basic.confidential_add_verify_range_proof.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11520: /* module 45 call 0 */
    switch (itemIdx) {
    case 0: /* scheduler_schedule - when */;
      return _toStringBlockNumber(&m->basic.scheduler_schedule.when, outValue,
                                  outValueLen, pageIdx, pageCount);
    case 1: /* scheduler_schedule - maybe_periodic */;
      return _toStringOptionPeriod(&m->basic.scheduler_schedule.maybe_periodic,
                                   outValue, outValueLen, pageIdx, pageCount);
    case 2: /* scheduler_schedule - priority */;
      return _toStringPriority(&m->basic.scheduler_schedule.priority, outValue,
                               outValueLen, pageIdx, pageCount);
    case 3: /* scheduler_schedule - call */;
      return _toStringCall(&m->basic.scheduler_schedule.call, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11521: /* module 45 call 1 */
    switch (itemIdx) {
    case 0: /* scheduler_cancel - when */;
      return _toStringBlockNumber(&m->basic.scheduler_cancel.when, outValue,
                                  outValueLen, pageIdx, pageCount);
    case 1: /* scheduler_cancel - index */;
      return _toStringu32(&m->basic.scheduler_cancel.index, outValue,
                          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11522: /* module 45 call 2 */
    switch (itemIdx) {
    case 0: /* scheduler_schedule_named - id */;
      return _toStringBytes(&m->basic.scheduler_schedule_named.id, outValue,
                            outValueLen, pageIdx, pageCount);
    case 1: /* scheduler_schedule_named - when */;
      return _toStringBlockNumber(&m->basic.scheduler_schedule_named.when,
                                  outValue, outValueLen, pageIdx, pageCount);
    case 2: /* scheduler_schedule_named - maybe_periodic */;
      return _toStringOptionPeriod(
          &m->basic.scheduler_schedule_named.maybe_periodic, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* scheduler_schedule_named - priority */;
      return _toStringPriority(&m->basic.scheduler_schedule_named.priority,
                               outValue, outValueLen, pageIdx, pageCount);
    case 4: /* scheduler_schedule_named - call */;
      return _toStringCall(&m->basic.scheduler_schedule_named.call, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11523: /* module 45 call 3 */
    switch (itemIdx) {
    case 0: /* scheduler_cancel_named - id */;
      return _toStringBytes(&m->basic.scheduler_cancel_named.id, outValue,
                            outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11524: /* module 45 call 4 */
    switch (itemIdx) {
    case 0: /* scheduler_schedule_after - after */;
      return _toStringBlockNumber(&m->basic.scheduler_schedule_after.after,
                                  outValue, outValueLen, pageIdx, pageCount);
    case 1: /* scheduler_schedule_after - maybe_periodic */;
      return _toStringOptionPeriod(
          &m->basic.scheduler_schedule_after.maybe_periodic, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* scheduler_schedule_after - priority */;
      return _toStringPriority(&m->basic.scheduler_schedule_after.priority,
                               outValue, outValueLen, pageIdx, pageCount);
    case 3: /* scheduler_schedule_after - call */;
      return _toStringCall(&m->basic.scheduler_schedule_after.call, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11525: /* module 45 call 5 */
    switch (itemIdx) {
    case 0: /* scheduler_schedule_named_after - id */;
      return _toStringBytes(&m->basic.scheduler_schedule_named_after.id,
                            outValue, outValueLen, pageIdx, pageCount);
    case 1: /* scheduler_schedule_named_after - after */;
      return _toStringBlockNumber(
          &m->basic.scheduler_schedule_named_after.after, outValue, outValueLen,
          pageIdx, pageCount);
    case 2: /* scheduler_schedule_named_after - maybe_periodic */;
      return _toStringOptionPeriod(
          &m->basic.scheduler_schedule_named_after.maybe_periodic, outValue,
          outValueLen, pageIdx, pageCount);
    case 3: /* scheduler_schedule_named_after - priority */;
      return _toStringPriority(
          &m->basic.scheduler_schedule_named_after.priority, outValue,
          outValueLen, pageIdx, pageCount);
    case 4: /* scheduler_schedule_named_after - call */;
      return _toStringCall(&m->basic.scheduler_schedule_named_after.call,
                           outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11776: /* module 46 call 0 */
    switch (itemIdx) {
    case 0: /* corporateaction_set_max_details_length - length */;
      return _toStringu32(
          &m->basic.corporateaction_set_max_details_length.length, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11777: /* module 46 call 1 */
    switch (itemIdx) {
    case 0: /* corporateaction_reset_caa - ticker */;
      return _toStringTicker(&m->basic.corporateaction_reset_caa.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11778: /* module 46 call 2 */
    switch (itemIdx) {
    case 0: /* corporateaction_set_default_targets - ticker */;
      return _toStringTicker(
          &m->basic.corporateaction_set_default_targets.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* corporateaction_set_default_targets - targets */;
      return _toStringTargetIdentities(
          &m->basic.corporateaction_set_default_targets.targets, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11779: /* module 46 call 3 */
    switch (itemIdx) {
    case 0: /* corporateaction_set_default_withholding_tax - ticker */;
      return _toStringTicker(
          &m->basic.corporateaction_set_default_withholding_tax.ticker,
          outValue, outValueLen, pageIdx, pageCount);
    case 1: /* corporateaction_set_default_withholding_tax - tax */;
      return _toStringTax(
          &m->basic.corporateaction_set_default_withholding_tax.tax, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11780: /* module 46 call 4 */
    switch (itemIdx) {
    case 0: /* corporateaction_set_did_withholding_tax - ticker */;
      return _toStringTicker(
          &m->basic.corporateaction_set_did_withholding_tax.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* corporateaction_set_did_withholding_tax - taxed_did */;
      return _toStringIdentityId(
          &m->basic.corporateaction_set_did_withholding_tax.taxed_did, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* corporateaction_set_did_withholding_tax - tax */;
      return _toStringOptionTax(
          &m->basic.corporateaction_set_did_withholding_tax.tax, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11781: /* module 46 call 5 */
    switch (itemIdx) {
    case 0: /* corporateaction_initiate_corporate_action - ticker */;
      return _toStringTicker(
          &m->basic.corporateaction_initiate_corporate_action.ticker, outValue,
          outValueLen, pageIdx, pageCount);
    case 1: /* corporateaction_initiate_corporate_action - kind */;
      return _toStringCAKind(
          &m->basic.corporateaction_initiate_corporate_action.kind, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* corporateaction_initiate_corporate_action - record_date */;
      return _toStringOptionRecordDateSpec(
          &m->basic.corporateaction_initiate_corporate_action.record_date,
          outValue, outValueLen, pageIdx, pageCount);
    case 3: /* corporateaction_initiate_corporate_action - details */;
      return _toStringCADetails(
          &m->basic.corporateaction_initiate_corporate_action.details, outValue,
          outValueLen, pageIdx, pageCount);
    case 4: /* corporateaction_initiate_corporate_action - targets */;
      return _toStringOptionTargetIdentities(
          &m->basic.corporateaction_initiate_corporate_action.targets, outValue,
          outValueLen, pageIdx, pageCount);
    case 5: /* corporateaction_initiate_corporate_action -
               default_withholding_tax */
        ;
      return _toStringOptionTax(
          &m->basic.corporateaction_initiate_corporate_action
               .default_withholding_tax,
          outValue, outValueLen, pageIdx, pageCount);
    case 6: /* corporateaction_initiate_corporate_action - withholding_tax */;
      return _toStringOptionVecTupleIdentityIdTax(
          &m->basic.corporateaction_initiate_corporate_action.withholding_tax,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11782: /* module 46 call 6 */
    switch (itemIdx) {
    case 0: /* corporateaction_link_ca_doc - id */;
      return _toStringCAId(&m->basic.corporateaction_link_ca_doc.id, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* corporateaction_link_ca_doc - docs */;
      return _toStringVecDocumentId(&m->basic.corporateaction_link_ca_doc.docs,
                                    outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11783: /* module 46 call 7 */
    switch (itemIdx) {
    case 0: /* corporateaction_remove_ca - ca_id */;
      return _toStringCAId(&m->basic.corporateaction_remove_ca.ca_id, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 11784: /* module 46 call 8 */
    switch (itemIdx) {
    case 0: /* corporateaction_change_record_date - ca_id */;
      return _toStringCAId(&m->basic.corporateaction_change_record_date.ca_id,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* corporateaction_change_record_date - record_date */;
      return _toStringOptionRecordDateSpec(
          &m->basic.corporateaction_change_record_date.record_date, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12032: /* module 47 call 0 */
    switch (itemIdx) {
    case 0: /* corporateballot_attach_ballot - ca_id */;
      return _toStringCAId(&m->basic.corporateballot_attach_ballot.ca_id,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* corporateballot_attach_ballot - range */;
      return _toStringBallotTimeRange(
          &m->basic.corporateballot_attach_ballot.range, outValue, outValueLen,
          pageIdx, pageCount);
    case 2: /* corporateballot_attach_ballot - meta */;
      return _toStringBallotMeta(&m->basic.corporateballot_attach_ballot.meta,
                                 outValue, outValueLen, pageIdx, pageCount);
    case 3: /* corporateballot_attach_ballot - rcv */;
      return _toStringbool(&m->basic.corporateballot_attach_ballot.rcv,
                           outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12033: /* module 47 call 1 */
    switch (itemIdx) {
    case 0: /* corporateballot_vote - ca_id */;
      return _toStringCAId(&m->basic.corporateballot_vote.ca_id, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* corporateballot_vote - votes */;
      return _toStringVecBallotVote(&m->basic.corporateballot_vote.votes,
                                    outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12034: /* module 47 call 2 */
    switch (itemIdx) {
    case 0: /* corporateballot_change_end - ca_id */;
      return _toStringCAId(&m->basic.corporateballot_change_end.ca_id, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* corporateballot_change_end - end */;
      return _toStringMoment(&m->basic.corporateballot_change_end.end, outValue,
                             outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12035: /* module 47 call 3 */
    switch (itemIdx) {
    case 0: /* corporateballot_change_meta - ca_id */;
      return _toStringCAId(&m->basic.corporateballot_change_meta.ca_id,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* corporateballot_change_meta - meta */;
      return _toStringBallotMeta(&m->basic.corporateballot_change_meta.meta,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12036: /* module 47 call 4 */
    switch (itemIdx) {
    case 0: /* corporateballot_change_rcv - ca_id */;
      return _toStringCAId(&m->basic.corporateballot_change_rcv.ca_id, outValue,
                           outValueLen, pageIdx, pageCount);
    case 1: /* corporateballot_change_rcv - rcv */;
      return _toStringbool(&m->basic.corporateballot_change_rcv.rcv, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12037: /* module 47 call 5 */
    switch (itemIdx) {
    case 0: /* corporateballot_remove_ballot - ca_id */;
      return _toStringCAId(&m->basic.corporateballot_remove_ballot.ca_id,
                           outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12288: /* module 48 call 0 */
    switch (itemIdx) {
    case 0: /* capitaldistribution_distribute - ca_id */;
      return _toStringCAId(&m->basic.capitaldistribution_distribute.ca_id,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* capitaldistribution_distribute - portfolio */;
      return _toStringOptionPortfolioNumber(
          &m->basic.capitaldistribution_distribute.portfolio, outValue,
          outValueLen, pageIdx, pageCount);
    case 2: /* capitaldistribution_distribute - currency */;
      return _toStringTicker(&m->basic.capitaldistribution_distribute.currency,
                             outValue, outValueLen, pageIdx, pageCount);
    case 3: /* capitaldistribution_distribute - amount */;
      return _toStringBalance(&m->basic.capitaldistribution_distribute.amount,
                              outValue, outValueLen, pageIdx, pageCount);
    case 4: /* capitaldistribution_distribute - payment_at */;
      return _toStringMoment(
          &m->basic.capitaldistribution_distribute.payment_at, outValue,
          outValueLen, pageIdx, pageCount);
    case 5: /* capitaldistribution_distribute - expires_at */;
      return _toStringOptionMoment(
          &m->basic.capitaldistribution_distribute.expires_at, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12289: /* module 48 call 1 */
    switch (itemIdx) {
    case 0: /* capitaldistribution_claim - ca_id */;
      return _toStringCAId(&m->basic.capitaldistribution_claim.ca_id, outValue,
                           outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12290: /* module 48 call 2 */
    switch (itemIdx) {
    case 0: /* capitaldistribution_push_benefit - ca_id */;
      return _toStringCAId(&m->basic.capitaldistribution_push_benefit.ca_id,
                           outValue, outValueLen, pageIdx, pageCount);
    case 1: /* capitaldistribution_push_benefit - holder */;
      return _toStringIdentityId(
          &m->basic.capitaldistribution_push_benefit.holder, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12291: /* module 48 call 3 */
    switch (itemIdx) {
    case 0: /* capitaldistribution_reclaim - ca_id */;
      return _toStringCAId(&m->basic.capitaldistribution_reclaim.ca_id,
                           outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12292: /* module 48 call 4 */
    switch (itemIdx) {
    case 0: /* capitaldistribution_remove_distribution - ca_id */;
      return _toStringCAId(
          &m->basic.capitaldistribution_remove_distribution.ca_id, outValue,
          outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12544: /* module 49 call 0 */
    switch (itemIdx) {
    case 0: /* checkpoint_create_checkpoint - ticker */;
      return _toStringTicker(&m->basic.checkpoint_create_checkpoint.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12545: /* module 49 call 1 */
    switch (itemIdx) {
    case 0: /* checkpoint_set_schedules_max_complexity - max_complexity */;
      return _toStringu64(
          &m->basic.checkpoint_set_schedules_max_complexity.max_complexity,
          outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12546: /* module 49 call 2 */
    switch (itemIdx) {
    case 0: /* checkpoint_create_schedule - ticker */;
      return _toStringTicker(&m->basic.checkpoint_create_schedule.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* checkpoint_create_schedule - schedule */;
      return _toStringScheduleSpec(
          &m->basic.checkpoint_create_schedule.schedule, outValue, outValueLen,
          pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  case 12547: /* module 49 call 3 */
    switch (itemIdx) {
    case 0: /* checkpoint_remove_schedule - ticker */;
      return _toStringTicker(&m->basic.checkpoint_remove_schedule.ticker,
                             outValue, outValueLen, pageIdx, pageCount);
    case 1: /* checkpoint_remove_schedule - id */;
      return _toStringScheduleId(&m->basic.checkpoint_remove_schedule.id,
                                 outValue, outValueLen, pageIdx, pageCount);
    default:
      return parser_no_data;
    }
  default:
    return parser_ok;
  }

  return parser_ok;
}
