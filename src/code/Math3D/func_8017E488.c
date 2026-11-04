// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriLineIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, Vec3f* linePointA,
                            Vec3f* linePointB, Vec3f* intersect, s32 fromFront) {

    if (!Math3D_LineSegVsPlane(nx, ny, nz, originDist, linePointA, linePointB, intersect, fromFront)) {
        return false;
    }

    if (((nx == 0.0f) || Math3D_TriChkPointParaX(v0, v1, v2, nx, intersect->y, intersect->z)) &&
        ((ny == 0.0f) || Math3D_TriChkPointParaY(v0, v1, v2, ny, intersect->z, intersect->x)) &&
        ((nz == 0.0f) || Math3D_TriChkPointParaZ(v0, v1, v2, nz, intersect->x, intersect->y))) {
        return true;
    }

    *intersect = *linePointB;
    return false;
}
