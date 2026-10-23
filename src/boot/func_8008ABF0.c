// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "types.h"

extern void guMtxIdentF(f32 mf[4][4]);
extern f32 __cosf(f32 x);
extern f32 __sinf(f32 x);

void func_8008ABF0(f32 mf[4][4], u16 *perspNorm, f32 fovy, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 cot;
    s32 i;
    s32 j;

    guMtxIdentF(mf);
    fovy *= 3.1415926 / 180.0;
    cot = __cosf(fovy / 2) / __sinf(fovy / 2);
    mf[0][0] = cot / aspect;
    mf[1][1] = cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = -1;
    mf[3][2] = (2 * near * far) / (near - far);
    mf[3][3] = 0.0f;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            mf[i][j] *= scale;
        }
    }
    if (perspNorm != NULL) {
        if (near + far <= 2.0) {
            *perspNorm = 65535;
        } else {
            *perspNorm = (2.0 * 65536.0) / (near + far);
            if (*perspNorm <= 0) {
                *perspNorm = 1;
            }
        }
    }
}
