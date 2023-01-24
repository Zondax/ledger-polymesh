/*******************************************************************************
 *  (c) 2019 - 2023 Zondax AG
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

// Modules names
static const char* STR_MO_SYSTEM = "System";
static const char* STR_MO_TIMESTAMP = "Timestamp";
static const char* STR_MO_INDICES = "Indices";
static const char* STR_MO_BALANCES = "Balances";
static const char* STR_MO_IDENTITY = "Identity";
static const char* STR_MO_CDDSERVICEPROVIDERS = "Cddserviceproviders";
static const char* STR_MO_POLYMESHCOMMITTEE = "Polymeshcommittee";
static const char* STR_MO_COMMITTEEMEMBERSHIP = "Committeemembership";
static const char* STR_MO_TECHNICALCOMMITTEE = "Technicalcommittee";
static const char* STR_MO_TECHNICALCOMMITTEEMEMBERSHIP = "Technicalcommitteemembership";
static const char* STR_MO_UPGRADECOMMITTEE = "Upgradecommittee";
static const char* STR_MO_UPGRADECOMMITTEEMEMBERSHIP = "Upgradecommitteemembership";
static const char* STR_MO_MULTISIG = "Multisig";
static const char* STR_MO_BRIDGE = "Bridge";
static const char* STR_MO_STAKING = "Staking";
static const char* STR_MO_SESSION = "Session";
static const char* STR_MO_SUDO = "Sudo";
static const char* STR_MO_ASSET = "Asset";
static const char* STR_MO_CAPITALDISTRIBUTION = "Capitaldistribution";
static const char* STR_MO_CHECKPOINT = "Checkpoint";
static const char* STR_MO_COMPLIANCEMANAGER = "Compliancemanager";
static const char* STR_MO_CORPORATEACTION = "Corporateaction";
static const char* STR_MO_CORPORATEBALLOT = "Corporateballot";
static const char* STR_MO_PIPS = "Pips";
static const char* STR_MO_PORTFOLIO = "Portfolio";
static const char* STR_MO_PROTOCOLFEE = "Protocolfee";
static const char* STR_MO_SETTLEMENT = "Settlement";
static const char* STR_MO_STO = "Sto";
static const char* STR_MO_TREASURY = "Treasury";
static const char* STR_MO_UTILITY = "Utility";
static const char* STR_MO_EXTERNALAGENTS = "Externalagents";
static const char* STR_MO_RELAYER = "Relayer";
static const char* STR_MO_REWARDS = "Rewards";
static const char* STR_MO_CONTRACTS = "Contracts";
static const char* STR_MO_POLYMESHCONTRACTS = "Polymeshcontracts";
static const char* STR_MO_PREIMAGE = "Preimage";

// Methods names
static const char* STR_ME_FILL_BLOCK = "Fill block";
static const char* STR_ME_REMARK = "Remark";
static const char* STR_ME_SET_HEAP_PAGES = "Set heap pages";
static const char* STR_ME_SET_CODE = "Set code";
static const char* STR_ME_SET_CODE_WITHOUT_CHECKS = "Set code without checks";
static const char* STR_ME_REMARK_WITH_EVENT = "Remark with event";
static const char* STR_ME_SET = "Set";
static const char* STR_ME_CLAIM = "Claim";
static const char* STR_ME_TRANSFER = "Transfer";
static const char* STR_ME_FREE = "Free";
static const char* STR_ME_FORCE_TRANSFER = "Force transfer";
static const char* STR_ME_FREEZE = "Freeze";
static const char* STR_ME_TRANSFER_WITH_MEMO = "Transfer with memo";
static const char* STR_ME_DEPOSIT_BLOCK_REWARD_RESERVE_BALANCE = "Deposit block reward reserve balance";
static const char* STR_ME_SET_BALANCE = "Set balance";
static const char* STR_ME_BURN_ACCOUNT_BALANCE = "Burn account balance";
static const char* STR_ME_INVALIDATE_CDD_CLAIMS = "Invalidate cdd claims";
static const char* STR_ME_ACCEPT_PRIMARY_KEY = "Accept primary key";
static const char* STR_ME_CHANGE_CDD_REQUIREMENT_FOR_MK_ROTATION = "Change cdd requirement for mk rotation";
static const char* STR_ME_JOIN_IDENTITY_AS_KEY = "Join identity as key";
static const char* STR_ME_LEAVE_IDENTITY_AS_KEY = "Leave identity as key";
static const char* STR_ME_ADD_CLAIM = "Add claim";
static const char* STR_ME_REVOKE_CLAIM = "Revoke claim";
static const char* STR_ME_SET_PERMISSION_TO_SIGNER = "Set permission to signer";
static const char* STR_ME_PLACEHOLDER_LEGACY_SET_PERMISSION_TO_SIGNER = "Placeholder legacy set permission to signer";
static const char* STR_ME_FREEZE_SECONDARY_KEYS = "Freeze secondary keys";
static const char* STR_ME_UNFREEZE_SECONDARY_KEYS = "Unfreeze secondary keys";
static const char* STR_ME_ADD_AUTHORIZATION = "Add authorization";
static const char* STR_ME_REMOVE_AUTHORIZATION = "Remove authorization";
static const char* STR_ME_ADD_INVESTOR_UNIQUENESS_CLAIM = "Add investor uniqueness claim";
static const char* STR_ME_GC_ADD_CDD_CLAIM = "Gc add cdd claim";
static const char* STR_ME_GC_REVOKE_CDD_CLAIM = "Gc revoke cdd claim";
static const char* STR_ME_REVOKE_CLAIM_BY_INDEX = "Revoke claim by index";
static const char* STR_ME_ROTATE_PRIMARY_KEY_TO_SECONDARY = "Rotate primary key to secondary";
static const char* STR_ME_ADD_SECONDARY_KEYS_WITH_AUTHORIZATION = "Add secondary keys with authorization";
static const char* STR_ME_SET_SECONDARY_KEY_PERMISSIONS = "Set secondary key permissions";
static const char* STR_ME_REMOVE_SECONDARY_KEYS = "Remove secondary keys";
static const char* STR_ME_REGISTER_CUSTOM_CLAIM_TYPE = "Register custom claim type";
static const char* STR_ME_SET_ACTIVE_MEMBERS_LIMIT = "Set active members limit";
static const char* STR_ME_DISABLE_MEMBER = "Disable member";
static const char* STR_ME_ADD_MEMBER = "Add member";
static const char* STR_ME_REMOVE_MEMBER = "Remove member";
static const char* STR_ME_SWAP_MEMBER = "Swap member";
static const char* STR_ME_RESET_MEMBERS = "Reset members";
static const char* STR_ME_ABDICATE_MEMBERSHIP = "Abdicate membership";
static const char* STR_ME_SET_VOTE_THRESHOLD = "Set vote threshold";
static const char* STR_ME_SET_RELEASE_COORDINATOR = "Set release coordinator";
static const char* STR_ME_SET_EXPIRES_AFTER = "Set expires after";
static const char* STR_ME_VOTE_OR_PROPOSE = "Vote or propose";
static const char* STR_ME_VOTE = "Vote";
static const char* STR_ME_CREATE_MULTISIG = "Create multisig";
static const char* STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_IDENTITY = "Create or approve proposal as identity";
static const char* STR_ME_CREATE_OR_APPROVE_PROPOSAL_AS_KEY = "Create or approve proposal as key";
static const char* STR_ME_CREATE_PROPOSAL_AS_IDENTITY = "Create proposal as identity";
static const char* STR_ME_CREATE_PROPOSAL_AS_KEY = "Create proposal as key";
static const char* STR_ME_APPROVE_AS_IDENTITY = "Approve as identity";
static const char* STR_ME_APPROVE_AS_KEY = "Approve as key";
static const char* STR_ME_REJECT_AS_IDENTITY = "Reject as identity";
static const char* STR_ME_REJECT_AS_KEY = "Reject as key";
static const char* STR_ME_ACCEPT_MULTISIG_SIGNER_AS_IDENTITY = "Accept multisig signer as identity";
static const char* STR_ME_ACCEPT_MULTISIG_SIGNER_AS_KEY = "Accept multisig signer as key";
static const char* STR_ME_ADD_MULTISIG_SIGNER = "Add multisig signer";
static const char* STR_ME_REMOVE_MULTISIG_SIGNER = "Remove multisig signer";
static const char* STR_ME_ADD_MULTISIG_SIGNERS_VIA_CREATOR = "Add multisig signers via creator";
static const char* STR_ME_REMOVE_MULTISIG_SIGNERS_VIA_CREATOR = "Remove multisig signers via creator";
static const char* STR_ME_CHANGE_SIGS_REQUIRED = "Change sigs required";
static const char* STR_ME_MAKE_MULTISIG_SECONDARY = "Make multisig secondary";
static const char* STR_ME_MAKE_MULTISIG_PRIMARY = "Make multisig primary";
static const char* STR_ME_EXECUTE_SCHEDULED_PROPOSAL = "Execute scheduled proposal";
static const char* STR_ME_CHANGE_CONTROLLER = "Change controller";
static const char* STR_ME_CHANGE_ADMIN = "Change admin";
static const char* STR_ME_CHANGE_TIMELOCK = "Change timelock";
static const char* STR_ME_UNFREEZE = "Unfreeze";
static const char* STR_ME_CHANGE_BRIDGE_LIMIT = "Change bridge limit";
static const char* STR_ME_CHANGE_BRIDGE_EXEMPTED = "Change bridge exempted";
static const char* STR_ME_FORCE_HANDLE_BRIDGE_TX = "Force handle bridge tx";
static const char* STR_ME_BATCH_PROPOSE_BRIDGE_TX = "Batch propose bridge tx";
static const char* STR_ME_PROPOSE_BRIDGE_TX = "Propose bridge tx";
static const char* STR_ME_HANDLE_BRIDGE_TX = "Handle bridge tx";
static const char* STR_ME_FREEZE_TXS = "Freeze txs";
static const char* STR_ME_UNFREEZE_TXS = "Unfreeze txs";
static const char* STR_ME_HANDLE_SCHEDULED_BRIDGE_TX = "Handle scheduled bridge tx";
static const char* STR_ME_ADD_FREEZE_ADMIN = "Add freeze admin";
static const char* STR_ME_REMOVE_FREEZE_ADMIN = "Remove freeze admin";
static const char* STR_ME_REMOVE_TXS = "Remove txs";
static const char* STR_ME_BOND = "Bond";
static const char* STR_ME_BOND_EXTRA = "Bond extra";
static const char* STR_ME_UNBOND = "Unbond";
static const char* STR_ME_WITHDRAW_UNBONDED = "Withdraw Unbonded";
static const char* STR_ME_VALIDATE = "Validate";
static const char* STR_ME_NOMINATE = "Nominate";
static const char* STR_ME_CHILL = "Chill";
static const char* STR_ME_SET_PAYEE = "Set payee";
static const char* STR_ME_SET_CONTROLLER = "Set controller";
static const char* STR_ME_SET_VALIDATOR_COUNT = "Set validator count";
static const char* STR_ME_INCREASE_VALIDATOR_COUNT = "Increase validator count";
static const char* STR_ME_SCALE_VALIDATOR_COUNT = "Scale validator count";
static const char* STR_ME_ADD_PERMISSIONED_VALIDATOR = "Add permissioned validator";
static const char* STR_ME_REMOVE_PERMISSIONED_VALIDATOR = "Remove permissioned validator";
static const char* STR_ME_VALIDATE_CDD_EXPIRY_NOMINATORS = "Validate cdd expiry nominators";
static const char* STR_ME_SET_COMMISSION_CAP = "Set commission cap";
static const char* STR_ME_SET_MIN_BOND_THRESHOLD = "Set min bond threshold";
static const char* STR_ME_FORCE_NO_ERAS = "Force no eras";
static const char* STR_ME_FORCE_NEW_ERA = "Force new era";
static const char* STR_ME_SET_INVULNERABLES = "Set invulnerables";
static const char* STR_ME_FORCE_UNSTAKE = "Force unstake";
static const char* STR_ME_FORCE_NEW_ERA_ALWAYS = "Force new era always";
static const char* STR_ME_CANCEL_DEFERRED_SLASH = "Cancel deferred slash";
static const char* STR_ME_PAYOUT_STAKERS = "Payout stakers";
static const char* STR_ME_REBOND = "Rebond";
static const char* STR_ME_SET_HISTORY_DEPTH = "Set history depth";
static const char* STR_ME_REAP_STASH = "Reap stash";
static const char* STR_ME_PAYOUT_STAKERS_BY_SYSTEM = "Payout stakers by system";
static const char* STR_ME_CHANGE_SLASHING_ALLOWED_FOR = "Change slashing allowed for";
static const char* STR_ME_UPDATE_PERMISSIONED_VALIDATOR_INTENDED_COUNT = "Update permissioned validator intended count";
static const char* STR_ME_SET_KEYS = "Set keys";
static const char* STR_ME_PURGE_KEYS = "Purge keys";
static const char* STR_ME_SUDO_AS = "Sudo as";
static const char* STR_ME_REGISTER_TICKER = "Register ticker";
static const char* STR_ME_ACCEPT_TICKER_TRANSFER = "Accept ticker transfer";
static const char* STR_ME_ACCEPT_ASSET_OWNERSHIP_TRANSFER = "Accept asset ownership transfer";
static const char* STR_ME_CREATE_ASSET = "Create asset";
static const char* STR_ME_RENAME_ASSET = "Rename asset";
static const char* STR_ME_ISSUE = "Issue";
static const char* STR_ME_REDEEM = "Redeem";
static const char* STR_ME_MAKE_DIVISIBLE = "Make divisible";
static const char* STR_ME_ADD_DOCUMENTS = "Add documents";
static const char* STR_ME_REMOVE_DOCUMENTS = "Remove documents";
static const char* STR_ME_SET_FUNDING_ROUND = "Set funding round";
static const char* STR_ME_UPDATE_IDENTIFIERS = "Update identifiers";
static const char* STR_ME_CLAIM_CLASSIC_TICKER = "Claim classic ticker";
static const char* STR_ME_RESERVE_CLASSIC_TICKER = "Reserve classic ticker";
static const char* STR_ME_CONTROLLER_TRANSFER = "Controller transfer";
static const char* STR_ME_REGISTER_CUSTOM_ASSET_TYPE = "Register custom asset type";
static const char* STR_ME_CREATE_ASSET_WITH_CUSTOM_TYPE = "Create asset with custom type";
static const char* STR_ME_SET_ASSET_METADATA = "Set asset metadata";
static const char* STR_ME_SET_ASSET_METADATA_DETAILS = "Set asset metadata details";
static const char* STR_ME_REGISTER_AND_SET_LOCAL_ASSET_METADATA = "Register and set local asset metadata";
static const char* STR_ME_REGISTER_ASSET_METADATA_LOCAL_TYPE = "Register asset metadata local type";
static const char* STR_ME_REGISTER_ASSET_METADATA_GLOBAL_TYPE = "Register asset metadata global type";
static const char* STR_ME_REDEEM_FROM_PORTFOLIO = "Redeem from portfolio";
static const char* STR_ME_DISTRIBUTE = "Distribute";
static const char* STR_ME_PUSH_BENEFIT = "Push benefit";
static const char* STR_ME_RECLAIM = "Reclaim";
static const char* STR_ME_REMOVE_DISTRIBUTION = "Remove distribution";
static const char* STR_ME_CREATE_CHECKPOINT = "Create checkpoint";
static const char* STR_ME_SET_SCHEDULES_MAX_COMPLEXITY = "Set schedules max complexity";
static const char* STR_ME_CREATE_SCHEDULE = "Create schedule";
static const char* STR_ME_REMOVE_SCHEDULE = "Remove schedule";
static const char* STR_ME_ADD_COMPLIANCE_REQUIREMENT = "Add compliance requirement";
static const char* STR_ME_REMOVE_COMPLIANCE_REQUIREMENT = "Remove compliance requirement";
static const char* STR_ME_RESET_ASSET_COMPLIANCE = "Reset asset compliance";
static const char* STR_ME_PAUSE_ASSET_COMPLIANCE = "Pause asset compliance";
static const char* STR_ME_RESUME_ASSET_COMPLIANCE = "Resume asset compliance";
static const char* STR_ME_ADD_DEFAULT_TRUSTED_CLAIM_ISSUER = "Add default trusted claim issuer";
static const char* STR_ME_REMOVE_DEFAULT_TRUSTED_CLAIM_ISSUER = "Remove default trusted claim issuer";
static const char* STR_ME_SET_MAX_DETAILS_LENGTH = "Set max details length";
static const char* STR_ME_SET_DEFAULT_TARGETS = "Set default targets";
static const char* STR_ME_SET_DEFAULT_WITHHOLDING_TAX = "Set default withholding tax";
static const char* STR_ME_SET_DID_WITHHOLDING_TAX = "Set did withholding tax";
static const char* STR_ME_INITIATE_CORPORATE_ACTION = "Initiate corporate action";
static const char* STR_ME_LINK_CA_DOC = "Link ca doc";
static const char* STR_ME_REMOVE_CA = "Remove ca";
static const char* STR_ME_CHANGE_RECORD_DATE = "Change record date";
static const char* STR_ME_ATTACH_BALLOT = "Attach ballot";
static const char* STR_ME_CHANGE_END = "Change end";
static const char* STR_ME_CHANGE_META = "Change meta";
static const char* STR_ME_CHANGE_RCV = "Change rcv";
static const char* STR_ME_REMOVE_BALLOT = "Remove ballot";
static const char* STR_ME_SET_PRUNE_HISTORICAL_PIPS = "Set prune historical pips";
static const char* STR_ME_SET_MIN_PROPOSAL_DEPOSIT = "Set min proposal deposit";
static const char* STR_ME_SET_DEFAULT_ENACTMENT_PERIOD = "Set default enactment period";
static const char* STR_ME_SET_PENDING_PIP_EXPIRY = "Set pending pip expiry";
static const char* STR_ME_SET_MAX_PIP_SKIP_COUNT = "Set max pip skip count";
static const char* STR_ME_SET_ACTIVE_PIP_LIMIT = "Set active pip limit";
static const char* STR_ME_PROPOSE = "Propose";
static const char* STR_ME_APPROVE_COMMITTEE_PROPOSAL = "Approve committee proposal";
static const char* STR_ME_REJECT_PROPOSAL = "Reject proposal";
static const char* STR_ME_PRUNE_PROPOSAL = "Prune proposal";
static const char* STR_ME_RESCHEDULE_EXECUTION = "Reschedule execution";
static const char* STR_ME_CLEAR_SNAPSHOT = "Clear snapshot";
static const char* STR_ME_SNAPSHOT = "Snapshot";
static const char* STR_ME_ENACT_SNAPSHOT_RESULTS = "Enact snapshot results";
static const char* STR_ME_EXECUTE_SCHEDULED_PIP = "Execute scheduled pip";
static const char* STR_ME_EXPIRE_SCHEDULED_PIP = "Expire scheduled pip";
static const char* STR_ME_CREATE_PORTFOLIO = "Create portfolio";
static const char* STR_ME_DELETE_PORTFOLIO = "Delete portfolio";
static const char* STR_ME_MOVE_PORTFOLIO_FUNDS = "Move portfolio funds";
static const char* STR_ME_RENAME_PORTFOLIO = "Rename portfolio";
static const char* STR_ME_QUIT_PORTFOLIO_CUSTODY = "Quit portfolio custody";
static const char* STR_ME_ACCEPT_PORTFOLIO_CUSTODY = "Accept portfolio custody";
static const char* STR_ME_CHANGE_COEFFICIENT = "Change coefficient";
static const char* STR_ME_CREATE_VENUE = "Create venue";
static const char* STR_ME_UPDATE_VENUE_DETAILS = "Update venue details";
static const char* STR_ME_UPDATE_VENUE_TYPE = "Update venue type";
static const char* STR_ME_ADD_INSTRUCTION = "Add instruction";
static const char* STR_ME_ADD_AND_AFFIRM_INSTRUCTION = "Add and affirm instruction";
static const char* STR_ME_AFFIRM_INSTRUCTION = "Affirm instruction";
static const char* STR_ME_WITHDRAW_AFFIRMATION = "Withdraw affirmation";
static const char* STR_ME_REJECT_INSTRUCTION = "Reject instruction";
static const char* STR_ME_AFFIRM_WITH_RECEIPTS = "Affirm with receipts";
static const char* STR_ME_CLAIM_RECEIPT = "Claim receipt";
static const char* STR_ME_UNCLAIM_RECEIPT = "Unclaim receipt";
static const char* STR_ME_SET_VENUE_FILTERING = "Set venue filtering";
static const char* STR_ME_ALLOW_VENUES = "Allow venues";
static const char* STR_ME_DISALLOW_VENUES = "Disallow venues";
static const char* STR_ME_CHANGE_RECEIPT_VALIDITY = "Change receipt validity";
static const char* STR_ME_EXECUTE_SCHEDULED_INSTRUCTION = "Execute scheduled instruction";
static const char* STR_ME_RESCHEDULE_INSTRUCTION = "Reschedule instruction";
static const char* STR_ME_UPDATE_VENUE_SIGNERS = "Update venue signers";
static const char* STR_ME_ADD_INSTRUCTION_WITH_MEMO = "Add instruction with memo";
static const char* STR_ME_ADD_AND_AFFIRM_INSTRUCTION_WITH_MEMO = "Add and affirm instruction with memo";
static const char* STR_ME_CREATE_FUNDRAISER = "Create fundraiser";
static const char* STR_ME_INVEST = "Invest";
static const char* STR_ME_FREEZE_FUNDRAISER = "Freeze fundraiser";
static const char* STR_ME_UNFREEZE_FUNDRAISER = "Unfreeze fundraiser";
static const char* STR_ME_MODIFY_FUNDRAISER_WINDOW = "Modify fundraiser window";
static const char* STR_ME_STOP = "Stop";
static const char* STR_ME_DISBURSEMENT = "Disbursement";
static const char* STR_ME_REIMBURSEMENT = "Reimbursement";
static const char* STR_ME_BATCH = "Batch";
static const char* STR_ME_BATCH_ATOMIC = "Batch atomic";
static const char* STR_ME_BATCH_OPTIMISTIC = "Batch optimistic";
static const char* STR_ME_RELAY_TX = "Relay tx";
static const char* STR_ME_REMOVE_AGENT = "Remove agent";
static const char* STR_ME_ABDICATE = "Abdicate";
static const char* STR_ME_ACCEPT_BECOME_AGENT = "Accept become agent";
static const char* STR_ME_CREATE_GROUP_AND_ADD_AUTH = "Create group and add auth";
static const char* STR_ME_CREATE_AND_CHANGE_CUSTOM_GROUP = "Create and change custom group";
static const char* STR_ME_SET_PAYING_KEY = "Set paying key";
static const char* STR_ME_ACCEPT_PAYING_KEY = "Accept paying key";
static const char* STR_ME_REMOVE_PAYING_KEY = "Remove paying key";
static const char* STR_ME_UPDATE_POLYX_LIMIT = "Update polyx limit";
static const char* STR_ME_INCREASE_POLYX_LIMIT = "Increase polyx limit";
static const char* STR_ME_DECREASE_POLYX_LIMIT = "Decrease polyx limit";
static const char* STR_ME_CLAIM_ITN_REWARD = "Claim itn reward";
static const char* STR_ME_CALL = "Call";
static const char* STR_ME_INSTANTIATE_WITH_CODE = "Instantiate with code";
static const char* STR_ME_INSTANTIATE = "Instantiate";
static const char* STR_ME_UPLOAD_CODE = "Upload code";
static const char* STR_ME_REMOVE_CODE = "Remove code";
static const char* STR_ME_INSTANTIATE_WITH_CODE_PERMS = "Instantiate with code perms";
static const char* STR_ME_INSTANTIATE_WITH_HASH_PERMS = "Instantiate with hash perms";
static const char* STR_ME_NOTE_PREIMAGE = "Note preimage";
static const char* STR_ME_UNNOTE_PREIMAGE = "Unnote preimage";
static const char* STR_ME_REQUEST_PREIMAGE = "Request preimage";
static const char* STR_ME_UNREQUEST_PREIMAGE = "Unrequest preimage";

// Items names
static const char* STR_IT_ratio = "Ratio";
static const char* STR_IT_remark = "Remark";
static const char* STR_IT_pages = "Pages";
static const char* STR_IT_code = "Code";
static const char* STR_IT_items = "Items";
static const char* STR_IT_keys = "Keys";
static const char* STR_IT_prefix = "Prefix";
static const char* STR_IT_subkeys = "Subkeys";
static const char* STR_IT_now = "Now";
static const char* STR_IT_index = "Index";
static const char* STR_IT_new_ = "New";
static const char* STR_IT_freeze = "Freeze";
static const char* STR_IT_dest = "Dest";
static const char* STR_IT_amount = "Amount";
static const char* STR_IT_memo = "Memo";
static const char* STR_IT_who = "Who";
static const char* STR_IT_new_free = "New free";
static const char* STR_IT_new_reserved = "New reserved";
static const char* STR_IT_source = "Source";
static const char* STR_IT_target_account = "Target account";
static const char* STR_IT_secondary_keys = "Secondary keys";
static const char* STR_IT_cdd = "Cdd";
static const char* STR_IT_disable_from = "Disable from";
static const char* STR_IT_expiry = "Expiry";
static const char* STR_IT_keys_to_remove = "Keys to remove";
static const char* STR_IT_rotation_auth_id = "Rotation auth id";
static const char* STR_IT_optional_cdd_auth_id = "Optional cdd auth id";
static const char* STR_IT_auth_required = "Auth required";
static const char* STR_IT_auth_id = "Auth id";
static const char* STR_IT_target = "Target";
static const char* STR_IT_claim = "Claim";
static const char* STR_IT_key = "Key";
static const char* STR_IT_perms = "Perms";
static const char* STR_IT_data = "Data";
static const char* STR_IT__auth_issuer_pays = "Auth issuer pays";
static const char* STR_IT_additional_keys = "Additional keys";
static const char* STR_IT_expires_at = "Expires at";
static const char* STR_IT_proof = "Proof";
static const char* STR_IT_scope = "Scope";
static const char* STR_IT_claim_type = "Claim type";
static const char* STR_IT_ty = "Ty";
static const char* STR_IT_limit = "Limit";
static const char* STR_IT_at = "At";
static const char* STR_IT_remove = "Remove";
static const char* STR_IT_add = "Add";
static const char* STR_IT_members = "Members";
static const char* STR_IT_n = "N";
static const char* STR_IT_d = "D";
static const char* STR_IT_id = "Id";
static const char* STR_IT_approve = "Approve";
static const char* STR_IT_call = "Call";
static const char* STR_IT_proposal = "Proposal";
static const char* STR_IT_signers = "Signers";
static const char* STR_IT_sigs_required = "Sigs required";
static const char* STR_IT_multisig = "Multisig";
static const char* STR_IT_auto_close = "Auto close";
static const char* STR_IT_proposal_id = "Proposal id";
static const char* STR_IT_signer = "Signer";
static const char* STR_IT_multisig_did = "Multisig did";
static const char* STR_IT__proposal_weight = "Proposal weight";
static const char* STR_IT_controller = "Controller";
static const char* STR_IT_admin = "Admin";
static const char* STR_IT_timelock = "Timelock";
static const char* STR_IT_duration = "Duration";
static const char* STR_IT_exempted = "Exempted";
static const char* STR_IT_bridge_tx = "Bridge tx";
static const char* STR_IT_bridge_txs = "Bridge txs";
static const char* STR_IT_freeze_admin = "Freeze admin";
static const char* STR_IT_payee = "Payee";
static const char* STR_IT_num_slashing_spans = "Num slashing spans";
static const char* STR_IT_prefs = "Prefs";
static const char* STR_IT_targets = "Targets";
static const char* STR_IT_additional = "Additional";
static const char* STR_IT_factor = "Factor";
static const char* STR_IT_identity = "Identity";
static const char* STR_IT_intended_count = "Intended count";
static const char* STR_IT_new_cap = "New cap";
static const char* STR_IT_new_value = "New value";
static const char* STR_IT_invulnerables = "Invulnerables";
static const char* STR_IT_stash = "Stash";
static const char* STR_IT_era = "Era";
static const char* STR_IT_slash_indices = "Slash indices";
static const char* STR_IT_validator_stash = "Validator stash";
static const char* STR_IT_new_history_depth = "New history depth";
static const char* STR_IT__era_items_deleted = "Era items deleted";
static const char* STR_IT_winners = "Winners";
static const char* STR_IT_compact = "Compact";
static const char* STR_IT_score = "Score";
static const char* STR_IT_size = "Size";
static const char* STR_IT_slashing_switch = "Slashing switch";
static const char* STR_IT_new_intended_count = "New intended count";
static const char* STR_IT__weight = "Weight";
static const char* STR_IT_ticker = "Ticker";
static const char* STR_IT_name = "Name";
static const char* STR_IT_divisible = "Divisible";
static const char* STR_IT_asset_type = "Asset type";
static const char* STR_IT_identifiers = "Identifiers";
static const char* STR_IT_funding_round = "Funding round";
static const char* STR_IT_disable_iu = "Disable iu";
static const char* STR_IT_docs = "Docs";
static const char* STR_IT_ids = "Ids";
static const char* STR_IT_ethereum_signature = "Ethereum signature";
static const char* STR_IT_classic_ticker_import = "Classic ticker import";
static const char* STR_IT_contract_did = "Contract did";
static const char* STR_IT_config = "Config";
static const char* STR_IT_from_portfolio = "From portfolio";
static const char* STR_IT_custom_asset_type = "Custom asset type";
static const char* STR_IT_value = "Value";
static const char* STR_IT_detail = "Detail";
static const char* STR_IT_spec = "Spec";
static const char* STR_IT_portfolio = "Portfolio";
static const char* STR_IT_ca_id = "Ca id";
static const char* STR_IT_currency = "Currency";
static const char* STR_IT_per_share = "Per share";
static const char* STR_IT_payment_at = "Payment at";
static const char* STR_IT_holder = "Holder";
static const char* STR_IT_max_complexity = "Max complexity";
static const char* STR_IT_schedule = "Schedule";
static const char* STR_IT_sender_conditions = "Sender conditions";
static const char* STR_IT_receiver_conditions = "Receiver conditions";
static const char* STR_IT_asset_compliance = "Asset compliance";
static const char* STR_IT_issuer = "Issuer";
static const char* STR_IT_new_req = "New req";
static const char* STR_IT_length = "Length";
static const char* STR_IT_tax = "Tax";
static const char* STR_IT_taxed_did = "Taxed did";
static const char* STR_IT_kind = "Kind";
static const char* STR_IT_decl_date = "Decl date";
static const char* STR_IT_record_date = "Record date";
static const char* STR_IT_details = "Details";
static const char* STR_IT_default_withholding_tax = "Default withholding tax";
static const char* STR_IT_withholding_tax = "Withholding tax";
static const char* STR_IT_ca_args = "Ca args";
static const char* STR_IT_range = "Range";
static const char* STR_IT_meta = "Meta";
static const char* STR_IT_rcv = "Rcv";
static const char* STR_IT_votes = "Votes";
static const char* STR_IT_end = "End";
static const char* STR_IT_prune = "Prune";
static const char* STR_IT_deposit = "Deposit";
static const char* STR_IT_max = "Max";
static const char* STR_IT_url = "Url";
static const char* STR_IT_description = "Description";
static const char* STR_IT_aye_or_nay = "Aye or nay";
static const char* STR_IT_until = "Until";
static const char* STR_IT_results = "Results";
static const char* STR_IT_did = "Did";
static const char* STR_IT_num = "Num";
static const char* STR_IT_from = "From";
static const char* STR_IT_to = "To";
static const char* STR_IT_to_name = "To name";
static const char* STR_IT_pid = "Pid";
static const char* STR_IT_coefficient = "Coefficient";
static const char* STR_IT_op = "Op";
static const char* STR_IT_base_fee = "Base fee";
static const char* STR_IT_typ = "Typ";
static const char* STR_IT_venue_id = "Venue id";
static const char* STR_IT_settlement_type = "Settlement type";
static const char* STR_IT_trade_date = "Trade date";
static const char* STR_IT_value_date = "Value date";
static const char* STR_IT_legs = "Legs";
static const char* STR_IT_portfolios = "Portfolios";
static const char* STR_IT_max_legs_count = "Max legs count";
static const char* STR_IT_num_of_legs = "Num of legs";
static const char* STR_IT_receipt_details = "Receipt details";
static const char* STR_IT_instruction_id = "Instruction id";
static const char* STR_IT_leg_id = "Leg id";
static const char* STR_IT_enabled = "Enabled";
static const char* STR_IT_venues = "Venues";
static const char* STR_IT_receipt_uid = "Receipt uid";
static const char* STR_IT_validity = "Validity";
static const char* STR_IT__legs_count = "Legs count";
static const char* STR_IT_add_signers = "Add signers";
static const char* STR_IT_instruction_memo = "Instruction memo";
static const char* STR_IT_offering_portfolio = "Offering portfolio";
static const char* STR_IT_offering_asset = "Offering asset";
static const char* STR_IT_raising_portfolio = "Raising portfolio";
static const char* STR_IT_raising_asset = "Raising asset";
static const char* STR_IT_tiers = "Tiers";
static const char* STR_IT_start = "Start";
static const char* STR_IT_minimum_investment = "Minimum investment";
static const char* STR_IT_fundraiser_name = "Fundraiser name";
static const char* STR_IT_investment_portfolio = "Investment portfolio";
static const char* STR_IT_funding_portfolio = "Funding portfolio";
static const char* STR_IT_purchase_amount = "Purchase amount";
static const char* STR_IT_max_price = "Max price";
static const char* STR_IT_receipt = "Receipt";
static const char* STR_IT_beneficiaries = "Beneficiaries";
static const char* STR_IT_calls = "Calls";
static const char* STR_IT_signature = "Signature";
static const char* STR_IT_agent = "Agent";
static const char* STR_IT_group = "Group";
static const char* STR_IT_user_key = "User key";
static const char* STR_IT_polyx_limit = "Polyx limit";
static const char* STR_IT_paying_key = "Paying key";
static const char* STR_IT__reward_address = "Reward address";
static const char* STR_IT__itn_address = "Itn address";
static const char* STR_IT__signature = "Signature";
static const char* STR_IT__status = "Status";
static const char* STR_IT_gas_limit = "Gas limit";
static const char* STR_IT_storage_deposit_limit = "Storage deposit limit";
static const char* STR_IT_salt = "Salt";
static const char* STR_IT_code_hash = "Code hash";
static const char* STR_IT_endowment = "Endowment";
static const char* STR_IT_bytes = "Bytes";
static const char* STR_IT_hash = "Hash";

// Country Codes
static const uint8_t COUNTRY_CODES_SIZE = 250;
static const char* const STR_COUNTRY_CODES[] = {
    "AF",
    "AX",
    "AL",
    "DZ",
    "AS",
    "AD",
    "AO",
    "AI",
    "AQ",
    "AG",
    "AR",
    "AM",
    "AW",
    "AU",
    "AT",
    "AZ",
    "BS",
    "BH",
    "BD",
    "BB",
    "BY",
    "BE",
    "BZ",
    "BJ",
    "BM",
    "BT",
    "BO",
    "BA",
    "BW",
    "BV",
    "BR",
    "VG",
    "IO",
    "BN",
    "BG",
    "BF",
    "BI",
    "KH",
    "CM",
    "CA",
    "CV",
    "KY",
    "CF",
    "TD",
    "CL",
    "CN",
    "HK",
    "MO",
    "CX",
    "CC",
    "CO",
    "KM",
    "CG",
    "CD",
    "CK",
    "CR",
    "CI",
    "HR",
    "CU",
    "CY",
    "CZ",
    "DK",
    "DJ",
    "DM",
    "DO",
    "EC",
    "EG",
    "SV",
    "GQ",
    "ER",
    "EE",
    "ET",
    "FK",
    "FO",
    "FJ",
    "FI",
    "FR",
    "GF",
    "PF",
    "TF",
    "GA",
    "GM",
    "GE",
    "DE",
    "GH",
    "GI",
    "GR",
    "GL",
    "GD",
    "GP",
    "GU",
    "GT",
    "GG",
    "GN",
    "GW",
    "GY",
    "HT",
    "HM",
    "VA",
    "HN",
    "HU",
    "IS",
    "IN",
    "ID",
    "IR",
    "IQ",
    "IE",
    "IM",
    "IL",
    "IT",
    "JM",
    "JP",
    "JE",
    "JO",
    "KZ",
    "KE",
    "KI",
    "KP",
    "KR",
    "KW",
    "KG",
    "LA",
    "LV",
    "LB",
    "LS",
    "LR",
    "LY",
    "LI",
    "LT",
    "LU",
    "MK",
    "MG",
    "MW",
    "MY",
    "MV",
    "ML",
    "MT",
    "MH",
    "MQ",
    "MR",
    "MU",
    "YT",
    "MX",
    "FM",
    "MD",
    "MC",
    "MN",
    "ME",
    "MS",
    "MA",
    "MZ",
    "MM",
    "NA",
    "NR",
    "NP",
    "NL",
    "AN",
    "NC",
    "NZ",
    "NI",
    "NE",
    "NG",
    "NU",
    "NF",
    "MP",
    "NO",
    "OM",
    "PK",
    "PW",
    "PS",
    "PA",
    "PG",
    "PY",
    "PE",
    "PH",
    "PN",
    "PL",
    "PT",
    "PR",
    "QA",
    "RE",
    "RO",
    "RU",
    "RW",
    "BL",
    "SH",
    "KN",
    "LC",
    "MF",
    "PM",
    "VC",
    "WS",
    "SM",
    "ST",
    "SA",
    "SN",
    "RS",
    "SC",
    "SL",
    "SG",
    "SK",
    "SI",
    "SB",
    "SO",
    "ZA",
    "GS",
    "SS",
    "ES",
    "LK",
    "SD",
    "SR",
    "SJ",
    "SZ",
    "SE",
    "CH",
    "SY",
    "TW",
    "TJ",
    "TZ",
    "TH",
    "TL",
    "TG",
    "TK",
    "TO",
    "TT",
    "TN",
    "TR",
    "TM",
    "TC",
    "TV",
    "UG",
    "UA",
    "AE",
    "GB",
    "US",
    "UM",
    "UY",
    "UZ",
    "VU",
    "VE",
    "VN",
    "VI",
    "WF",
    "EH",
    "YE",
    "ZM",
    "ZW",
    "BQ",
    "CW",
    "SX",
};

#ifdef __cplusplus
}
#endif
