#include "types.h"

extern void EffectSsBlast_Spawn(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s16 arg9);

void EffectSsBlast_SpawnShockwave(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4, s32 arg5, s16 arg6) {
    EffectSsBlast_Spawn(arg0, arg1, arg2, arg3, arg4, arg5, 100, 0x177, 0x23, arg6);
}
