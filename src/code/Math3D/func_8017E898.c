// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_PointDistSqToLineXY(f32 x0, f32 y0, Vec3f* p1, Vec3f* p2, f32* lineLenSq) {
    f32 perpendicularRatio;
    f32 xDiff = p2->x - p1->x;
    f32 yDiff = p2->y - p1->y;
    f32 distSq = SQ(xDiff) + SQ(yDiff);
    f32 perpX;
    f32 perpY;
    s32 ret = false;

    if (IS_ZERO(distSq)) {
        *lineLenSq = 0.0f;
        return false;
    }

    perpendicularRatio = ((x0 - p1->x) * xDiff + (y0 - p1->y) * yDiff) / distSq;
    if ((perpendicularRatio >= 0.0f) && (perpendicularRatio <= 1.0f)) {
        ret = true;
    }
    perpX = (xDiff * perpendicularRatio) + p1->x;
    perpY = (yDiff * perpendicularRatio) + p1->y;
    *lineLenSq = SQ(perpX - x0) + SQ(perpY - y0);

    return ret;
}
