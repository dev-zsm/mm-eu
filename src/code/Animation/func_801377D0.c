// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Animation_GetLastFrame(s32);
void Animation_Change(s32, s32, f32, f32, f32, s32, f32);

void Animation_PlayOnce(s32 arg0, s32 arg1) {
    f32 temp;

    temp = (f32) Animation_GetLastFrame(arg1);
    Animation_Change(arg0, arg1, 1.0f, 0.0f, temp, 2, 0.0f);
}
