#include "types.h"
extern void AnimTaskQueue_AddInterp(void *a0, u8 a1, s32 a2, s32 a3, f32 a4);
void PlayerAnimation_InterpJointMorph(void *a0, u8 *a1, f32 a2) {
    AnimTaskQueue_AddInterp(a0, a1[0], *(s32 *)(a1 + 0x20), *(s32 *)(a1 + 0x24), a2);
}
