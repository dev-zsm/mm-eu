#include "types.h"

extern void AnimatedMat_DrawMain(s32 a0, s32 a1, f32 a2, s32 a3, s32 a4);

void AnimatedMat_DrawStepOpa(s32 a0, s32 a1, s32 a2) {
    AnimatedMat_DrawMain(a0, a1, 1.0f, a2, 1);
}
