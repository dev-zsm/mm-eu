#include "types.h"

extern u8 D_801AF280[];
extern u8 D_801AF284[];
extern void EffectSsBlast_Spawn();

void EffectSsBlast_SpawnWhiteCustomScale(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    EffectSsBlast_Spawn(arg0, arg1, arg2, arg3, D_801AF280, D_801AF284, arg4, arg5, 0x23, arg6);
}
