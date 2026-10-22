// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSsDust_Spawn(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_800B13D0(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, s16 a7, s16 a8) {
    EffectSsDust_Spawn(a0, 0, a1, a2, a3, a4, a5, a6, a7, a8, 0);
}
