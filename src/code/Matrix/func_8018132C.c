// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_matrix_ctx.h"

void Matrix_Translate(f32 x, f32 y, f32 z, MatrixMode mode) {
    MtxF* cmf = sCurrentMatrix;
    f32 tempX;
    f32 tempY;

    if (mode == MTXMODE_APPLY) {
        tempX = cmf->xx;
        tempY = cmf->xy;
        cmf->xw += tempX * x + tempY * y + cmf->xz * z;
        tempX = cmf->yx;
        tempY = cmf->yy;
        cmf->yw += tempX * x + tempY * y + cmf->yz * z;
        tempX = cmf->zx;
        tempY = cmf->zy;
        cmf->zw += tempX * x + tempY * y + cmf->zz * z;
        tempX = cmf->wx;
        tempY = cmf->wy;
        cmf->ww += tempX * x + tempY * y + cmf->wz * z;
    } else {
        SkinMatrix_SetTranslate(cmf, x, y, z);
    }
}
