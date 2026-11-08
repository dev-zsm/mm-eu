// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"


s32 Player_GetHeldBButtonSword(struct Player *player) {
    return Player_BButtonSwordFromIA(player, *(s8 *)((u8 *)player + 0x147));
}
