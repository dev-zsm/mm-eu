#include "types.h"

extern u8 D_801AF270[];
extern u8 D_801AF274[];
extern void EffectSsDust_Spawn(void *arg0, s32 arg1, void *arg2, void *arg3, void *arg4, void *arg5, void *arg6, s16 arg7, s16 arg8, s16 arg9, s32 arg10);

void func_800B1810(void *arg0, void *arg1, void *arg2, void *arg3, s16 arg4, s16 arg5, s16 arg6) {
    EffectSsDust_Spawn(arg0, 5, arg1, arg2, arg3, D_801AF270, D_801AF274, arg4, arg5, arg6, 0);
}
