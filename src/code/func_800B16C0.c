#include "types.h"

extern u8 D_801AF270[];
extern u8 D_801AF274[];
extern void EffectSsDust_Spawn(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, u8 *a5, u8 *a6, s32 a7, s32 a8, s32 a9, s32 a10);

void func_800B16C0(s32 a0, s32 a1, s32 a2, s32 a3, s16 a4, s16 a5) {
    EffectSsDust_Spawn(a0, 4, a1, a2, a3, D_801AF270, D_801AF274, a4, a5, 10, 0);
}
