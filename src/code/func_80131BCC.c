#include "types.h"
extern void AnimatedMat_DrawMain(void *a0, s32 a1, f32 a2, void *a3, s32 a4);
void AnimatedMat_DrawAlphaOpa(u8 *a0, s32 a1, f32 a2) {
    void *a3 = *(void **)((a0 + 0x20000) - 0x77C0);
    AnimatedMat_DrawMain(a0, a1, a2, a3, 1);
}
