// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 CollisionPoly_LineVsPoly(BgLineVsPolyTest* a0) {
    static Vec3f sPolyVerts[3]; 
    static Plane sPlane;        
    f32 planeDistA;
    f32 planeDistB;
    f32 dpA;
    f32 dpB;
    f32 originDist;

    sPlane.originDist = a0->poly->dist;
    originDist = sPlane.originDist;
    planeDistA = originDist;
    planeDistB = originDist;

    dpA = a0->poly->normal.x * a0->posA->x;
    dpB = a0->poly->normal.x * a0->posB->x;
    dpA += a0->poly->normal.y * a0->posA->y;
    dpB += a0->poly->normal.y * a0->posB->y;
    dpA += a0->poly->normal.z * a0->posA->z;
    dpB += a0->poly->normal.z * a0->posB->z;

    dpA = COLPOLY_GET_NORMAL(dpA);
    dpB = COLPOLY_GET_NORMAL(dpB);

    planeDistA += dpA;
    planeDistB += dpB;

    if (((planeDistA >= 0.0f) && (planeDistB >= 0.0f)) || ((planeDistA < 0.0f) && (planeDistB < 0.0f)) ||
        ((a0->checkOneFace != 0) && (planeDistA < 0.0f) && (0.0f < planeDistB)) || IS_ZERO(planeDistA - planeDistB)) {
        return false;
    }

    CollisionPoly_GetNormalF(a0->poly, &sPlane.normal.x, &sPlane.normal.y, &sPlane.normal.z);
    CollisionPoly_GetVertices(a0->poly, a0->vtxList, sPolyVerts);
    Math3D_LineSplitRatio(a0->posA, a0->posB, planeDistA / (planeDistA - planeDistB), a0->planeIntersect);

    if (((fabsf(sPlane.normal.x) > 0.5f) &&
         Math3D_TriChkPointParaXImpl(&sPolyVerts[0], &sPolyVerts[1], &sPolyVerts[2], a0->planeIntersect->y,
                                     a0->planeIntersect->z, 0.0f, a0->checkDist, sPlane.normal.x)) ||
        ((fabsf(sPlane.normal.y) > 0.5f) &&
         Math3D_TriChkPointParaYImpl(&sPolyVerts[0], &sPolyVerts[1], &sPolyVerts[2], a0->planeIntersect->z,
                                     a0->planeIntersect->x, 0.0f, a0->checkDist, sPlane.normal.y)) ||
        ((fabsf(sPlane.normal.z) > 0.5f) &&
         Math3D_TriChkPointParaZImpl(&sPolyVerts[0], &sPolyVerts[1], &sPolyVerts[2], a0->planeIntersect->x,
                                     a0->planeIntersect->y, 0.0f, a0->checkDist, sPlane.normal.z))) {
        return true;
    }
    return false;
}
