// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skin_matrix.h"

void SkinMatrix_SetRotateRPY(MtxF* mf, s16 roll, s16 pitch, s16 yaw) {
    f32 cos2;
    f32 sin = Math_SinS(yaw);
    f32 cos = Math_CosS(yaw);
    f32 xy;
    f32 sin2;
    f32 xz;
    f32 yy;
    f32 yz;

    mf->yy = cos;
    mf->xy = -sin;
    mf->wx = mf->wy = mf->wz = 0;
    mf->xw = mf->yw = mf->zw = 0;
    mf->ww = 1;

    if (pitch != 0) {
        sin2 = Math_SinS(pitch);
        cos2 = Math_CosS(pitch);

        mf->xx = cos * cos2;
        mf->xz = cos * sin2;

        mf->yx = sin * cos2;
        mf->yz = sin * sin2;
        mf->zx = -sin2;
        mf->zz = cos2;
    } else {
        mf->xx = cos;
        if (1) {}
        if (1) {}
        xz = sin; 
        mf->yx = sin;
        mf->zx = mf->xz = mf->yz = 0;
        mf->zz = 1;
    }

    if (roll != 0) {
        sin2 = Math_SinS(roll);
        cos2 = Math_CosS(roll);

        xy = mf->xy;
        xz = mf->xz;
        mf->xy = (xy * cos2) + (xz * sin2);
        mf->xz = (xz * cos2) - (xy * sin2);

        if (1) {}
        yz = mf->yz;
        yy = mf->yy;
        mf->yy = (yy * cos2) + (yz * sin2);
        mf->yz = (yz * cos2) - (yy * sin2);

        if (cos2) {}
        mf->zy = mf->zz * sin2;
        mf->zz = mf->zz * cos2;
    } else {
        mf->zy = 0;
    }
}
