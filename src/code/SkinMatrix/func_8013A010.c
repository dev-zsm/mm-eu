// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

void SkinMatrix_SetRotateAroundVec(MtxF* mf, s16 a, f32 x, f32 y, f32 z) {
    f32 sinA;
    f32 cosA;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xy;
    f32 yz;
    f32 xz;
    s32 pad;

    sinA = Math_SinS(a);
    cosA = Math_CosS(a);

    xx = x * x;
    yy = y * y;
    zz = z * z;
    xy = x * y;
    yz = y * z;
    xz = x * z;

    mf->xx = (1.0f - xx) * cosA + xx;
    mf->yx = (1.0f - cosA) * xy + z * sinA;
    mf->zx = (1.0f - cosA) * xz - y * sinA;
    mf->wx = 0.0f;

    mf->xy = (1.0f - cosA) * xy - z * sinA;
    mf->yy = (1.0f - yy) * cosA + yy;
    mf->zy = (1.0f - cosA) * yz + x * sinA;
    mf->wy = 0.0f;

    mf->xz = (1.0f - cosA) * xz + y * sinA;
    mf->yz = (1.0f - cosA) * yz - x * sinA;
    mf->zz = (1.0f - zz) * cosA + zz;
    mf->wz = 0.0f;

    mf->xw = mf->yw = mf->zw = 0.0f;
    mf->ww = 1.0f;
}
