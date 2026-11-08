// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void AnimatedMat_DrawMain(void *, s32, f32, s32, s32);

void AnimatedMat_DrawXlu(struct PlayState *play, struct AnimatedMaterial *matAnim) {
    AnimatedMat_DrawMain(play, matAnim, 1.0f, *(s32 *)((u8 *)play + 0x18840), 2);
}
