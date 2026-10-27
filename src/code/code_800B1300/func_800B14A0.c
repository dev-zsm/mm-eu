#include "types.h"

extern void EffectSsDust_Spawn(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s16 arg7, s16 arg8, s16 arg9, s32 arg10);

void func_800B14A0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, s16 arg7, s16 arg8) {
    EffectSsDust_Spawn(arg0, 2, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, 0);
}
