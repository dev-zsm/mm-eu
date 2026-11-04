// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

void SkinMatrix_Vec3fMtxFMultXYZ(MtxF* mf, Vec3f* src, Vec3f* dest) {
    f32 mx = mf->xx;
    f32 my = mf->xy;
    f32 mz = mf->xz;
    f32 mw = mf->xw;

    dest->x = mw + ((src->x * mx) + (src->y * my) + (src->z * mz));

    mx = mf->yx;
    my = mf->yy;
    mz = mf->yz;
    mw = mf->yw;
    dest->y = mw + ((src->x * mx) + (src->y * my) + (src->z * mz));

    mx = mf->zx;
    my = mf->zy;
    mz = mf->zz;
    mw = mf->zw;
    dest->z = mw + ((src->x * mx) + (src->y * my) + (src->z * mz));
}
