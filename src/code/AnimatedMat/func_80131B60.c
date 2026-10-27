// FLAGS: -O2 -g3 -mips2
#include "types.h"

void AnimatedMat_DrawMain(void *, s32, f32, s32, s32);

void AnimatedMat_DrawXlu(void *arg0, s32 arg1) {
    AnimatedMat_DrawMain(arg0, arg1, 1.0f, *(s32 *)((u8 *)arg0 + 0x18840), 2);
}
