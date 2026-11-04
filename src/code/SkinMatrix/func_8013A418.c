// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

void SkinMatrix_MulYRotation(MtxF* mf, s16 a) {
    f32 sinA;
    f32 cosA;
    f32 rx;
    f32 rz;

    if (a != 0) {
        sinA = Math_SinS(a);
        cosA = Math_CosS(a);

        rx = mf->xx;
        rz = mf->xz;
        mf->xx = rx * cosA - rz * sinA;
        mf->xz = rx * sinA + rz * cosA;

        rx = mf->yx;
        rz = mf->yz;
        mf->yx = rx * cosA - rz * sinA;
        mf->yz = rx * sinA + rz * cosA;

        rx = mf->zx;
        rz = mf->zz;
        mf->zx = rx * cosA - rz * sinA;
        mf->zz = rx * sinA + rz * cosA;

        rx = mf->wx;
        rz = mf->wz;
        mf->wx = rx * cosA - rz * sinA;
        mf->wz = rx * sinA + rz * cosA;
    }
}
