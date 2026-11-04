// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_PlaneVsPlaneNewLine(f32 planeAA, f32 planeAB, f32 planeAC, f32 planeADist, f32 planeBA, f32 planeBB,
                               f32 planeBC, f32 planeBDist, InfiniteLine* intersect) {
    s32 pad;
    Vec3f planeANormal;
    Vec3f planeBNormal;
    f32 dirX;
    f32 dirY;
    f32 dirZ;

    VEC_SET(planeANormal, planeAA, planeAB, planeAC);
    VEC_SET(planeBNormal, planeBA, planeBB, planeBC);

    Math3D_Vec3f_Cross(&planeANormal, &planeBNormal, &intersect->dir);

    if (IS_ZERO(intersect->dir.x) && IS_ZERO(intersect->dir.y) && IS_ZERO(intersect->dir.z)) {
        
        return false;
    }

    dirX = fabsf(intersect->dir.x);
    dirY = fabsf(intersect->dir.y);
    dirZ = fabsf(intersect->dir.z);

    if ((dirX >= dirY) && (dirX >= dirZ)) {
        Math3D_FindPointOnPlaneIntersect(planeAB, planeAC, planeBB, planeBC, intersect->dir.x, planeADist, planeBDist,
                                         &intersect->point.y, &intersect->point.z);
        intersect->point.x = 0.0f;
    } else if ((dirY >= dirX) && (dirY >= dirZ)) {
        Math3D_FindPointOnPlaneIntersect(planeAC, planeAA, planeBC, planeBA, intersect->dir.y, planeADist, planeBDist,
                                         &intersect->point.z, &intersect->point.x);
        intersect->point.y = 0.0f;
    } else {
        Math3D_FindPointOnPlaneIntersect(planeAA, planeAB, planeBA, planeBB, intersect->dir.z, planeADist, planeBDist,
                                         &intersect->point.x, &intersect->point.y);
        intersect->point.z = 0.0f;
    }
    return true;
}
