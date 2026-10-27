// FLAGS: -O2 -g3 -mips2
#include "types.h"

void AnimatedMat_DrawMain(void *, void *, s32, s32, s32);

void AnimatedMat_DrawOpa(void *a0, void *a1) {
    AnimatedMat_DrawMain(a0, a1, 0x3F800000, *(s32 *)((u8 *)a0 + 0x18840), 1);
}
