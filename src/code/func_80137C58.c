// FLAGS: -O2 -g3 -mips2
#include "types.h"

void Animation_OnFrameImpl(s32, f32, f32);

void func_80137C58(s32 arg0, f32 arg1) {
    Animation_OnFrameImpl(arg0, arg1, 1.0f);
}
