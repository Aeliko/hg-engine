.include "asm/include/battle_commands.inc"

.data

_000:
    PrintAttackMessage 
    Wait 
    WaitButtonABTime 30
    // {0} surrounded itself with a veil of petals!
    PrintMessage 1505, TAG_NICKNAME, BATTLER_CATEGORY_MSG_TEMP
    Wait 
    WaitButtonABTime 30
    End