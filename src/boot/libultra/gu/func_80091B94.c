// FLAGS: -O2 -g0 -mips2
#include "types.h"

void guOrthoF(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7);
void guMtxF2L(f32 *arg0, s32 arg1);

void guOrtho(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    f32 sp28[16];

    guOrthoF(sp28, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    guMtxF2L(sp28, arg0);
}
