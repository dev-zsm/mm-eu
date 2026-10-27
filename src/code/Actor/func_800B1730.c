#include "types.h"

extern u8 D_801AF270[];
extern u8 D_801AF274[];

extern void EffectSsDust_Spawn(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u8 *arg5, u8 *arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10);

void func_800B1730(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5) {
    EffectSsDust_Spawn(arg0, 5, arg1, arg2, arg3, D_801AF270, D_801AF274, arg4, arg5, 0xA, 0);
}
