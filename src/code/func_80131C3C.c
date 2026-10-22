// FLAGS: -O2 -g3 -mips2
#include "types.h"

void AnimatedMat_DrawStep(void *arg0, s32 arg1, s32 arg2);
void AnimatedMat_DrawMain(void *a0, s32 a1, f32 a2, s32 a3, s32 a4);

void AnimatedMat_DrawStep(void *arg0, s32 arg1, s32 arg2) {
    AnimatedMat_DrawMain(arg0, arg1, 1.0f, arg2, 3);
}
