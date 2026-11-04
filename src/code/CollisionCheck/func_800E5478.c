// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_QuadVsQuad(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                  Collider* acCol) {
    ColliderQuad* atQuad = (ColliderQuad*)atCol;
    ColliderQuad* acQuad = (ColliderQuad*)acCol;
    s32 i;
    s32 j;

    if (CollisionCheck_IsElementNotAT(&atQuad->elem)) {
        return;
    }
    if (CollisionCheck_IsElementNotAC(&acQuad->elem)) {
        return;
    }
    if (CollisionCheck_NoSharedFlags(&atQuad->elem, &acQuad->elem)) {
        return;
    }

    Math3D_TriNorm(&ref_D_801EE0E8[0], &atQuad->dim.quad[2], &atQuad->dim.quad[3], &atQuad->dim.quad[1]);
    Math3D_TriNorm(&ref_D_801EE0E8[1], &atQuad->dim.quad[2], &atQuad->dim.quad[1], &atQuad->dim.quad[0]);
    Math3D_TriNorm(&ref_D_801EE070[0], &acQuad->dim.quad[2], &acQuad->dim.quad[3], &acQuad->dim.quad[1]);
    Math3D_TriNorm(&ref_D_801EE070[1], &acQuad->dim.quad[2], &acQuad->dim.quad[1], &acQuad->dim.quad[0]);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (Math3D_TriVsTriIntersect(&ref_D_801EE0E8[j], &ref_D_801EE070[i], &ref_D_801EE0D8) &&
                Collider_QuadSetNearestAC(play, atQuad, &ref_D_801EE0D8)) {
                Vec3f atPos;
                Vec3f acPos;

                CollisionCheck_QuadAvgPoint(atQuad, &atPos);
                CollisionCheck_QuadAvgPoint(acQuad, &acPos);
                CollisionCheck_SetATvsAC(play, &atQuad->base, &atQuad->elem, &atPos, &acQuad->base, &acQuad->elem,
                                         &acPos, &ref_D_801EE0D8);
                return;
            }
        }
    }
}
