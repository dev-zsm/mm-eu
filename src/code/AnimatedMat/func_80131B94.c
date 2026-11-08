// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void AnimatedMat_DrawMain(void *a0, s32 a1, f32 a2, s32 a3, s32 a4);

void AnimatedMat_DrawAlpha(struct PlayState *play, struct AnimatedMaterial *matAnim, f32 alphaRatio) {
    AnimatedMat_DrawMain(play, matAnim, alphaRatio, *(s32 *)((u8 *)play + 0x18840), 3);
}
