#include "types.h"

extern void EffectSsDust_Spawn(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10);

void func_800B1438(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s16 a6, s16 a7, s16 a8) {
    EffectSsDust_Spawn(a0, 1, a1, a2, a3, a4, a5, a6, a7, a8, 0);
}
