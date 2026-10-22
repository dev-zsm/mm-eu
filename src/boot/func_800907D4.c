// FLAGS: -O2 -g0 -mips2
#include "types.h"

void guRotateF(f32 *, f32, f32, f32, f32);
void guMtxF2L(f32 *, s32);

void guRotate(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 sp20[16];

    guRotateF(sp20, arg1, arg2, arg3, arg4);
    guMtxF2L(sp20, arg0);
}
