// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 CollisionPoly_CheckYIntersect(CollisionPoly* poly, Vec3s* vtxList, f32 x, f32 z, f32* yIntersect, f32 checkDist) {
    Vec3s* sVerts;
    f32 nx;
    f32 ny;
    f32 nz;

    sVerts = &vtxList[COLPOLY_VTX_INDEX(poly->flags_vIA)];
    ref_D_801EDA18[0].x = sVerts->x;
    ref_D_801EDA18[0].y = sVerts->y;
    ref_D_801EDA18[0].z = sVerts->z;
    sVerts = &vtxList[COLPOLY_VTX_INDEX(poly->flags_vIB)];
    ref_D_801EDA18[1].x = sVerts->x;
    ref_D_801EDA18[1].y = sVerts->y;
    ref_D_801EDA18[1].z = sVerts->z;
    sVerts = &vtxList[(s32)poly->vIC];
    ref_D_801EDA18[2].x = sVerts->x;
    ref_D_801EDA18[2].y = sVerts->y;
    ref_D_801EDA18[2].z = sVerts->z;

    if (!Math3D_CirSquareVsTriSquareZX(&ref_D_801EDA18[0], &ref_D_801EDA18[1], &ref_D_801EDA18[2], z, x, checkDist)) {
        return 0;
    }
    nx = COLPOLY_GET_NORMAL(poly->normal.x);
    ny = COLPOLY_GET_NORMAL(poly->normal.y);
    nz = COLPOLY_GET_NORMAL(poly->normal.z);
    return Math3D_TriChkPointParaYNoRangeCheckIntersectInsideTri(&ref_D_801EDA18[0], &ref_D_801EDA18[1], &ref_D_801EDA18[2], nx, ny,
                                                                 nz, poly->dist, z, x, yIntersect, checkDist);
}
