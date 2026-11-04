// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_SphVsCylOverlapCenterDist(Sphere16* sph, Cylinder16* cyl, f32* overlapSize, f32* centerDist) {
    static Cylinderf sCylf;
    static Spheref sSphf;
    f32 x;
    f32 z;
    f32 combinedRadius;
    f32 cylBottom;
    f32 cylTop;
    f32 sphBottom;
    f32 sphTop;

    if ((sph->radius <= 0) || (cyl->radius <= 0)) {
        
        return false;
    }
    sSphf.center.y = sph->center.y;
    sSphf.radius = sph->radius;
    sCylf.pos.y = cyl->pos.y;
    sCylf.yShift = cyl->yShift;
    sCylf.height = cyl->height;
    x = (f32)sph->center.x - cyl->pos.x;
    z = (f32)sph->center.z - cyl->pos.z;
    combinedRadius = (f32)sph->radius + cyl->radius;
    *centerDist = sqrtf(SQ(x) + SQ(z));
    if (combinedRadius < *centerDist) {
        
        return false;
    }

    cylBottom = (sCylf.pos.y + sCylf.yShift);
    cylTop = cylBottom + sCylf.height;
    sphBottom = sSphf.center.y - sSphf.radius;
    sphTop = sSphf.center.y + sSphf.radius;

    if ((sphTop >= cylBottom) && (sphBottom <= cylTop)) {
        
        
        *overlapSize = combinedRadius - *centerDist;
        return true;
    }
    return false;
}
