// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 CollisionPoly_SphVsPoly(CollisionPoly* poly, Vec3s* vtxList, Vec3f* center, f32 radius) {
    static Sphere16 sSphere; 
    static TriNorm sTri;     
    Vec3f intersect;

    CollisionPoly_GetVertices(poly, vtxList, sTri.vtx);
    CollisionPoly_GetNormalF(poly, &sTri.plane.normal.x, &sTri.plane.normal.y, &sTri.plane.normal.z);
    sTri.plane.originDist = poly->dist;
    sSphere.center.x = center->x;
    sSphere.center.y = center->y;
    sSphere.center.z = center->z;
    sSphere.radius = radius;
    return Math3D_TriVsSphIntersect(&sSphere, &sTri, &intersect);
}
