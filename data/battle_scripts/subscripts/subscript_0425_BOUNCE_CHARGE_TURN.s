.include "asm/include/battle_commands.inc"

.data

_000:
    PrintAttackMessage 
    Wait 
    WaitButtonABTime 30
    // {0} flew up high!
    BufferMessage 232, TAG_NICKNAME, BATTLER_CATEGORY_ATTACKER
    UpdateMonData OPCODE_FLAG_ON, BATTLER_CATEGORY_ATTACKER, BMON_DATA_MOVE_EFFECT, MOVE_EFFECT_FLAG_FLY
    UpdateVar OPCODE_FLAG_ON, BSCRIPT_VAR_BATTLE_STATUS, BATTLE_STATUS_CHARGE_TURN|BATTLE_STATUS_CHECK_LOOP_ONLY_ONCE|BATTLE_STATUS_NO_ATTACK_MESSAGE
    PlayMoveAnimation BATTLER_CATEGORY_ATTACKER
    Wait 
    PrintBufferedMessage 
    Wait 
    WaitButtonABTime 30
    LockMoveChoice BATTLER_CATEGORY_ATTACKER
    CompareMonDataToValue OPCODE_FLAG_NOT, BATTLER_CATEGORY_ATTACKER, BMON_DATA_MOVE_EFFECT, MOVE_EFFECT_FLAG_SEMI_INVULNERABLE, _017
    ToggleVanish BATTLER_CATEGORY_ATTACKER, TRUE

_017:
    End 
