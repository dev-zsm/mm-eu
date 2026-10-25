#include "types.h"

extern void EffectSsDust_Spawn(void *play, s32 type, void *arg2, void *arg3, void *arg4, void *arg5, void *arg6, s16 arg7, s16 arg8, s32 life, s32 flags);

void func_800B1368(void *play, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5, s16 arg6, s16 arg7) {
    EffectSsDust_Spawn(play, 1, arg1, arg2, arg3, arg4, arg5, arg6, arg7, 10, 0);
}
