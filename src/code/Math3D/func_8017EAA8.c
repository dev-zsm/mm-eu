// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_PointDistSqToLineZX(f32 z0, f32 x0, Vec3f* p1, Vec3f* p2, f32* lineLenSq) {
    f32 perpendicularRatio;
    f32 zDiff = p2->z - p1->z;
    f32 xDiff = p2->x - p1->x;
    f32 distSq = SQ(zDiff) + SQ(xDiff);
    f32 perpZ;
    f32 perpX;
    s32 ret = false;

    if (IS_ZERO(distSq)) {
        *lineLenSq = 0.0f;
        return false;
    }

    perpendicularRatio = ((z0 - p1->z) * zDiff + (x0 - p1->x) * xDiff) / distSq;
    if ((perpendicularRatio >= 0.0f) && (perpendicularRatio <= 1.0f)) {
        ret = true;
    }
    perpZ = (zDiff * perpendicularRatio) + p1->z;
    perpX = (xDiff * perpendicularRatio) + p1->x;
    *lineLenSq = SQ(perpZ - z0) + SQ(perpX - x0);

    return ret;
}
