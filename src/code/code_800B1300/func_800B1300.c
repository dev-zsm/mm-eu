// FLAGS: -O2 -g3 -mips2
#include "types.h"

void EffectSsDust_Spawn(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_800B1300(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7) {
    EffectSsDust_Spawn(arg0, 0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, 0xA, 0);
}
