#include "types.h"

extern s32 D_801AF34C;
extern s32 D_801AF350[];

void EffectSsDeadDb_Spawn(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 *arg5, s16 arg6, s16 arg7, s32 arg8);

void func_800B3550(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    EffectSsDeadDb_Spawn(arg0, arg1, arg2, arg3, &D_801AF34C, &D_801AF350[arg6], arg4, arg5, 9);
}
