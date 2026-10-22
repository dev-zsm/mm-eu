// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801AF270;
extern s32 D_801AF274;

void EffectSsDust_Spawn(void *, s32, s32, s32, s32, s32 *, s32 *, s32, s32, s32, s32);

void func_800B17A0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    EffectSsDust_Spawn(arg0, 4, arg1, arg2, arg3, &D_801AF270, &D_801AF274, arg4, arg5, arg6, 0);
}
