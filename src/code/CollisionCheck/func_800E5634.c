// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_QuadVsSphere(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                    Collider* acCol) {
    ColliderQuad* atQuad = (ColliderQuad*)atCol;
    Vec3f hitPos;
    ColliderSphere* acSph = (ColliderSphere*)acCol;

    if (CollisionCheck_IsElementNotAT(&atQuad->elem)) {
        return;
    }
    if (CollisionCheck_IsElementNotAC(&acSph->elem) || CollisionCheck_NoSharedFlags(&atQuad->elem, &acSph->elem)) {
        return;
    }

    Math3D_TriNorm(&ref_D_801EE150, &atQuad->dim.quad[2], &atQuad->dim.quad[3], &atQuad->dim.quad[1]);
    Math3D_TriNorm(&ref_D_801EE188, &atQuad->dim.quad[2], &atQuad->dim.quad[1], &atQuad->dim.quad[0]);

    if ((Math3D_TriVsSphIntersect(&acSph->dim.worldSphere, &ref_D_801EE150, &hitPos)) ||
        (Math3D_TriVsSphIntersect(&acSph->dim.worldSphere, &ref_D_801EE188, &hitPos))) {
        if (Collider_QuadSetNearestAC(play, atQuad, &hitPos)) {
            Vec3f atPos;
            Vec3f acPos;

            Math_Vec3s_ToVec3f(&acPos, &acSph->dim.worldSphere.center);
            CollisionCheck_QuadAvgPoint(atQuad, &atPos);
            CollisionCheck_SetATvsAC(play, &atQuad->base, &atQuad->elem, &atPos, &acSph->base, &acSph->elem, &acPos,
                                     &hitPos);
        }
    }
}
