// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_PointDistSqToLineYZ(f32 y0, f32 z0, Vec3f* p1, Vec3f* p2, f32* lineLenSq) {
    f32 perpendicularRatio;
    f32 yDiff = p2->y - p1->y;
    f32 zDiff = p2->z - p1->z;
    f32 distSq = SQ(yDiff) + SQ(zDiff);
    f32 perpY;
    f32 perpZ;
    s32 ret = false;

    if (IS_ZERO(distSq)) {
        *lineLenSq = 0.0f;
        return false;
    }

    perpendicularRatio = ((y0 - p1->y) * yDiff + (z0 - p1->z) * zDiff) / distSq;
    if ((perpendicularRatio >= 0.0f) && (perpendicularRatio <= 1.0f)) {
        ret = true;
    }
    perpY = (yDiff * perpendicularRatio) + p1->y;
    perpZ = (zDiff * perpendicularRatio) + p1->z;
    *lineLenSq = SQ(perpY - y0) + SQ(perpZ - z0);

    return ret;
}
