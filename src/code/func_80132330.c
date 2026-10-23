#include "types.h"
extern void AnimatedMat_DrawStep();
void Scene_DrawConfigMatAnimManualStep(u8 *a0) {
    u8 *v = a0 + 0x18000;
    AnimatedMat_DrawStep(a0, *(s32 *)(v + 0x86C), *(s16 *)(v + 0x75A));
}
