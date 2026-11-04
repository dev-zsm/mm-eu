// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

void SkinMatrix_MulXRotation(MtxF* mf, s16 a) {
    f32 sinA;
    f32 cosA;
    f32 ry;
    f32 rz;

    if (a != 0) {
        sinA = Math_SinS(a);
        cosA = Math_CosS(a);

        ry = mf->xy;
        rz = mf->xz;
        mf->xy = ry * cosA + rz * sinA;
        mf->xz = rz * cosA - ry * sinA;

        ry = mf->yy;
        rz = mf->yz;
        mf->yy = ry * cosA + rz * sinA;
        mf->yz = rz * cosA - ry * sinA;

        ry = mf->zy;
        rz = mf->zz;
        mf->zy = ry * cosA + rz * sinA;
        mf->zz = rz * cosA - ry * sinA;

        ry = mf->wy;
        rz = mf->wz;
        mf->wy = ry * cosA + rz * sinA;
        mf->wz = rz * cosA - ry * sinA;
    }
}
