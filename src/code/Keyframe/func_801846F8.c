// FLAGS: -O2 -g3 -mips2
#include "types.h"

u8 *func_80100304(s32);
void Keyframe_FlexChangeAnim(u8 *, s32, s32, f32, f32, f32, f32, f32, s32);

void Keyframe_FlexPlayLoopSetSpeed(u8 *arg0, s32 arg1, f32 arg2) {
    Keyframe_FlexChangeAnim(arg0, *(s32 *)(arg0 + 0x18), arg1, 1.0f, (f32) *(s16 *)(func_80100304(arg1) + 0x12), 1.0f, arg2, 0.0f, 1);
}
