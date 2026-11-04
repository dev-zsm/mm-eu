// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_LineSegVsPlane(f32 nx, f32 ny, f32 nz, f32 originDist, Vec3f* linePointA, Vec3f* linePointB,
                          Vec3f* intersect, s32 fromFront) {
    f32 pointADist = Math3D_PlaneF(nx, ny, nz, originDist, linePointA);
    f32 pointBDist = Math3D_PlaneF(nx, ny, nz, originDist, linePointB);

    if ((pointADist * pointBDist) > 0.0f) {
        *intersect = *linePointB;
        return false;
    }

    if (fromFront && (pointADist < 0.0f) && (pointBDist > 0.0f)) {
        *intersect = *linePointB;
        return false;
    }

    return Math3D_LineSegFindPlaneIntersect(pointADist, pointBDist, linePointA, linePointB, intersect);
}
