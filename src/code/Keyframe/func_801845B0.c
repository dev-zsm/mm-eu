// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 unk12;
} Anim45;

Anim45 *func_80100304(s32);
void Keyframe_FlexChangeAnim(void *, s32, s32, f32, f32, f32, f32, f32, s32);

void Keyframe_FlexPlayOnceSetSpeed(void *arg0, s32 arg1, f32 arg2) {
    Keyframe_FlexChangeAnim(arg0, *(s32 *)((u8 *)arg0 + 0x18), arg1, 1.0f, (f32) func_80100304(arg1)->unk12, 1.0f, arg2, 0.0f, 0);
}
