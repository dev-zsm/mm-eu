#include "types.h"

extern u8 D_801C9EE0[];

extern void EffectSsDeadDs_Spawn(void *arg0, void *arg1, u8 *arg2, u8 *arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7);

void func_800B36DC(void *arg0, void *arg1, s16 arg2, s16 arg3, s16 arg4, s32 arg5) {
    EffectSsDeadDs_Spawn(arg0, arg1, D_801C9EE0, D_801C9EE0, arg2, arg3, arg4, arg5);
}
