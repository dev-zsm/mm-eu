// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_matrix_ctx.h"

void Matrix_ReplaceRotation(MtxF* mf) {
    MtxF* cmf = sCurrentMatrix;
    f32 acc;
    f32 component;
    f32 curColNorm;

    
    acc = cmf->xx;
    acc *= acc;
    component = cmf->yx;
    acc += SQ(component);
    component = cmf->zx;
    acc += SQ(component);
    curColNorm = sqrtf(acc);

    cmf->xx = mf->xx * curColNorm;
    cmf->yx = mf->yx * curColNorm;
    cmf->zx = mf->zx * curColNorm;

    
    acc = cmf->xy;
    acc *= acc;
    component = cmf->yy;
    acc += SQ(component);
    component = cmf->zy;
    acc += SQ(component);
    curColNorm = sqrtf(acc);

    cmf->xy = mf->xy * curColNorm;
    cmf->yy = mf->yy * curColNorm;
    cmf->zy = mf->zy * curColNorm;

    
    acc = cmf->xz;
    acc *= acc;
    component = cmf->yz;
    acc += SQ(component);
    component = cmf->zz;
    acc += SQ(component);
    curColNorm = sqrtf(acc);

    cmf->xz = mf->xz * curColNorm;
    cmf->yz = mf->yz * curColNorm;
    cmf->zz = mf->zz * curColNorm;
}
