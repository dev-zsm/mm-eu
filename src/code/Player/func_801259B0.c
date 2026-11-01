// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Player_AdjustSingleLeg(void *, s32, s32, s32, s32, s32, s32, s32);

void func_801259B0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg2 == 7) { Player_AdjustSingleLeg(arg0, arg1, arg1 + 0x240, arg3, arg4, 7, 8, 9); return; } if (arg2 == 4) { Player_AdjustSingleLeg(arg0, arg1, arg1 + 0x240, arg3, arg4, 4, 5, 6); }
}
