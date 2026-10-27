#include "types.h"

void AnimatedMat_DrawMain(s32 a0, s32 a1, f32 a2, s32 a3, s32 a4);

void AnimatedMat_DrawAlphaXlu(s32 a0, s32 a1, f32 a2) {
    AnimatedMat_DrawMain(a0, a1, a2, *(s32 *)((u8 *)a0 + 0x20000 - 0x77C0), 2);
}
