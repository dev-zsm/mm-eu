#include "types.h"
extern void AnimatedMat_Draw();
void Scene_DrawConfigMatAnim(s32 a0) {
    AnimatedMat_Draw(a0, *(s32 *)((u8 *)a0 + 0x20000 - 0x7794));
}
