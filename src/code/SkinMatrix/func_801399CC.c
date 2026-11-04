// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

void SkinMatrix_SetRotateYRP(MtxF* mf, s16 yaw, s16 roll, s16 pitch) {
    f32 cos2;
    f32 sin;
    f32 cos;
    f32 zx;
    f32 sin2;
    f32 zy;
    f32 xx;
    f32 xy;

    sin = Math_SinS(roll);
    cos = Math_CosS(roll);

    mf->xx = cos;
    mf->zx = -sin;
    mf->wz = 0;
    mf->wy = 0;
    mf->wx = 0;
    mf->zw = 0;
    mf->yw = 0;
    mf->xw = 0;
    mf->ww = 1;

    if (yaw != 0) {
        sin2 = Math_SinS(yaw);
        cos2 = Math_CosS(yaw);

        mf->zz = cos * cos2;
        mf->zy = cos * sin2;

        mf->xz = sin * cos2;
        mf->xy = sin * sin2;
        mf->yz = -sin2;
        mf->yy = cos2;
    } else {
        mf->zz = cos;
        if (1) {}
        if (1) {}
        xy = sin; 
        mf->xz = sin;
        mf->xy = mf->zy = mf->yz = 0;
        mf->yy = 1;
    }

    if (pitch != 0) {
        sin2 = Math_SinS(pitch);
        cos2 = Math_CosS(pitch);
        xx = mf->xx;
        xy = mf->xy;
        mf->xx = (xx * cos2) + (xy * sin2);
        mf->xy = xy * cos2 - (xx * sin2);
        if (1) {}
        zy = mf->zy;
        zx = mf->zx;
        mf->zx = (zx * cos2) + (zy * sin2);
        mf->zy = (zy * cos2) - (zx * sin2);
        if (cos2) {}
        mf->yx = mf->yy * sin2;
        mf->yy = mf->yy * cos2;
    } else {
        mf->yx = 0;
    }
}
