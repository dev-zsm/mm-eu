// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s16 intPart[4][4];
    u16 fracPart[4][4];
} Mtx;

void MtxConv_F2L(Mtx *mtx, f32 mf[4][4]) {
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
