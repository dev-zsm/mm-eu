// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_TriChkLineSegParaXIntersect(Vec3f* v0, Vec3f* v1, Vec3f* v2, f32 nx, f32 ny, f32 nz, f32 originDist, f32 y,
                                       f32 z, f32* xIntersect, f32 x0, f32 x1) {
    static Vec3f sPlanePos;
    f32 pointADist;
    f32 pointBDist;

    if (IS_ZERO(nx)) {
        return false;
    }

    sPlanePos.x = x0;
    sPlanePos.y = y;
    sPlanePos.z = z;
    pointADist = Math3D_PlaneF(nx, ny, nz, originDist, &sPlanePos);

    sPlanePos.x = x1;
    pointBDist = Math3D_PlaneF(nx, ny, nz, originDist, &sPlanePos);

    if (((pointADist > 0.0f) && (pointBDist > 0.0f)) || ((pointADist < 0.0f) && (pointBDist < 0.0f))) {
        return false;
    }

    if (Math3D_TriChkPointParaXImpl(v0, v1, v2, y, z, 300.0f, 1.0f, nx)) {
        *xIntersect = (((-ny * y) - (nz * z)) - originDist) / nx;
        return true;
    }
    return false;
}
