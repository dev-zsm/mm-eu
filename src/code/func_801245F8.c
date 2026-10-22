// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Player_BButtonSwordFromIA(void *, s8);

s32 Player_GetHeldBButtonSword(void *arg0) {
    return Player_BButtonSwordFromIA(arg0, *(s8 *)((u8 *)arg0 + 0x147));
}
