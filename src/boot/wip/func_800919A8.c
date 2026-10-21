// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    s32 unk60;
} Ctx;

s32 func_800919A8(Ctx *arg0, u16 *arg1, s32 arg2, s32 arg3, u16 *arg4) {
    volatile u16 spC;
    volatile u16 sp8;
    s32 temp_v0;

    temp_v0 = arg3 & 0xFF;
    spC = (temp_v0 << 8) + (arg2 & 0xFF);
loop_1:
    sp8 = spC;
    spC = arg1[*(volatile u8 *)((u8 *)&spC + 1)];
    arg1[*(volatile u8 *)((u8 *)&sp8 + 1)] = 3;
    if ((s32) spC >= arg0->unk60) {
        if (temp_v0 == *(volatile u8 *)&spC) {
            goto loop_1;
        }
    }
    *arg4 = spC;
    return 0;
}
