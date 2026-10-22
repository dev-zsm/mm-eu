// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x12];
    s16 unk12;
} Anim18;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
} Flex;

Anim18 *func_80100304(s32);
void Keyframe_FlexChangeAnim(Flex *, s32, s32, f32, f32, f32, f32, f32, s32);

void Keyframe_FlexPlayLoop(Flex *arg0, s32 arg1) {
    Keyframe_FlexChangeAnim(arg0, arg0->unk18, arg1, 1.0f, (f32)func_80100304(arg1)->unk12, 1.0f, 1.0f, 0.0f, 1);
}
