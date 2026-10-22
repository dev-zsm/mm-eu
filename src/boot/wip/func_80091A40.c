// FLAGS: -O2 -g0 -mips2
#include "types.h"

void guMtxIdentF(void);

void guOrthoF(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7) {
    s32 i;

    guMtxIdentF();
    arg0[0] = 2.0f / (arg2 - arg1);
    arg0[10] = -2.0f / (arg6 - arg5);
    arg0[5] = 2.0f / (arg4 - arg3);
    arg0[12] = -(arg2 + arg1) / (arg2 - arg1);
    arg0[13] = -(arg4 + arg3) / (arg4 - arg3);
    arg0[15] = 1.0f;
    arg0[14] = -(arg6 + arg5) / (arg6 - arg5);
    for (i = 0; i < 16; i++) {
        arg0[i] = arg0[i] * arg7;
    }
}
