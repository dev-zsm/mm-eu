// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_SphereVsQuad(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                    Collider* acCol) {
    ColliderSphere* atSph = (ColliderSphere*)atCol;
    Vec3f hitPos;
    ColliderQuad* acQuad = (ColliderQuad*)acCol;

    if (CollisionCheck_IsElementNotAT(&atSph->elem)) {
        return;
    }
    if (CollisionCheck_IsElementNotAC(&acQuad->elem) || CollisionCheck_NoSharedFlags(&atSph->elem, &acQuad->elem)) {
        return;
    }

    Math3D_TriNorm(&ref_D_801EE6C8, &acQuad->dim.quad[2], &acQuad->dim.quad[3], &acQuad->dim.quad[1]);
    Math3D_TriNorm(&ref_D_801EE700, &acQuad->dim.quad[1], &acQuad->dim.quad[0], &acQuad->dim.quad[2]);

    if (Math3D_TriVsSphIntersect(&atSph->dim.worldSphere, &ref_D_801EE6C8, &hitPos) ||
        Math3D_TriVsSphIntersect(&atSph->dim.worldSphere, &ref_D_801EE700, &hitPos)) {
        Vec3f atPos;
        Vec3f acPos;

        Math_Vec3s_ToVec3f(&atPos, &atSph->dim.worldSphere.center);
        CollisionCheck_QuadAvgPoint(acQuad, &acPos);
        CollisionCheck_SetATvsAC(play, &atSph->base, &atSph->elem, &atPos, &acQuad->base, &acQuad->elem, &acPos,
                                 &hitPos);
    }
}
