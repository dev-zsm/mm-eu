// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

void Math3D_GetSphVsTriIntersectPoint(Sphere16* sphere, TriNorm* tri, Vec3f* intersectPoint) {
    static Vec3f sV0V1Center;
    static Vec3f sSphereCenter;
    f32 dist;
    f32 splitRatio;

    sV0V1Center.x = (tri->vtx[0].x + tri->vtx[1].x) * 0.5f;
    sV0V1Center.y = (tri->vtx[0].y + tri->vtx[1].y) * 0.5f;
    sV0V1Center.z = (tri->vtx[0].z + tri->vtx[1].z) * 0.5f;
    sSphereCenter.x = sphere->center.x;
    sSphereCenter.y = sphere->center.y;
    sSphereCenter.z = sphere->center.z;
    dist = Math3D_Vec3f_DistXYZ(&sV0V1Center, &sSphereCenter);
    
    if (IS_ZERO(dist)) {
        intersectPoint->x = sSphereCenter.x;
        intersectPoint->y = sSphereCenter.y;
        intersectPoint->z = sSphereCenter.z;
        return;
    }
    splitRatio = sphere->radius / dist;
    Math3D_LineSplitRatio(&sSphereCenter, &sV0V1Center, splitRatio, intersectPoint);
}
