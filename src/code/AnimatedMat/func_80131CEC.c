// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void AnimatedMat_DrawMain(s32 a0, s32 a1, f32 a2, s32 a3, s32 a4);
void AnimatedMat_DrawAlphaStepOpa(s32 a0, s32 a1, f32 a2, s32 a3) {
    AnimatedMat_DrawMain(a0, a1, a2, a3, 1);
}
