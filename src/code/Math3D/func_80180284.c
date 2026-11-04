// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_SphVsSphOverlapCenterDist(Sphere16* sphereA, Sphere16* sphereB, f32* overlapSize, f32* centerDist) {
    Vec3f diff;

    diff.x = (f32)sphereA->center.x - (f32)sphereB->center.x;
    diff.y = (f32)sphereA->center.y - (f32)sphereB->center.y;
    diff.z = (f32)sphereA->center.z - (f32)sphereB->center.z;

    *centerDist = sqrtf(SQ(diff.x) + SQ(diff.y) + SQ(diff.z));

    *overlapSize = (((f32)sphereA->radius + (f32)sphereB->radius) - *centerDist);
    if (*overlapSize > 0.008f) {
        return true;
    }

    *overlapSize = 0.0f;
    return false;
}
