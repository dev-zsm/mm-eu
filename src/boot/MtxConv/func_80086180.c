// FLAGS: -O2 -g0 -mips2 -Wab,-r4300_mul
#include "gu.h"

void MtxConv_F2L(Mtx *mtx, MtxF mf) {
    s32 i;
    s32 j;
    s32 temp;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp = mf[i][j] * 65536.0f;
            mtx->intPart[i][j] = temp >> 16;
            mtx->fracPart[i][j] = temp;
        }
    }
}
