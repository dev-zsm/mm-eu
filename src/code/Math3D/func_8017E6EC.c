// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_PointDistSqToLine2DImpl(f32 x0, f32 y0, f32 x1, f32 y1, f32 x2, f32 y2, f32* perpXOut, f32* perpYOut,
                                   f32* lineLenSq) {
    f32 perpendicularRatio;
    f32 xDiff = x2 - x1;
    f32 yDiff = y2 - y1;
    f32 distSq = SQ(xDiff) + SQ(yDiff);
    s32 ret = false;

    if (IS_ZERO(distSq)) {
        *lineLenSq = 0.0f;
        return false;
    }

    perpendicularRatio = ((x0 - x1) * xDiff + (y0 - y1) * yDiff) / distSq;
    if ((perpendicularRatio >= 0.0f) && (perpendicularRatio <= 1.0f)) {
        ret = true;
    }

    *perpXOut = (xDiff * perpendicularRatio) + x1;
    *perpYOut = (yDiff * perpendicularRatio) + y1;

    *lineLenSq = SQ(*perpXOut - x0) + SQ(*perpYOut - y0);
    return ret;
}
