// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_QuadVsTris(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                  Collider* acCol) {
    ColliderQuad* atQuad = (ColliderQuad*)atCol;
    ColliderTris* acTris = (ColliderTris*)acCol;
    ColliderTrisElement* acTrisElem;

    if ((acTris->count > 0) && (acTris->elements != NULL)) {
        if (CollisionCheck_IsElementNotAT(&atQuad->elem)) {
            return;
        }

        Math3D_TriNorm(&ref_D_801EE000, &atQuad->dim.quad[2], &atQuad->dim.quad[3], &atQuad->dim.quad[1]);
        Math3D_TriNorm(&ref_D_801EE038, &atQuad->dim.quad[1], &atQuad->dim.quad[0], &atQuad->dim.quad[2]);

        for (acTrisElem = acTris->elements; acTrisElem < &acTris->elements[acTris->count]; acTrisElem++) {
            if (CollisionCheck_IsElementNotAC(&acTrisElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atQuad->elem, &acTrisElem->base)) {
                continue;
            }

            if ((Math3D_TriVsTriIntersect(&ref_D_801EE000, &acTrisElem->dim, &ref_D_801EDFF0)) ||
                (Math3D_TriVsTriIntersect(&ref_D_801EE038, &acTrisElem->dim, &ref_D_801EDFF0))) {
                if (Collider_QuadSetNearestAC(play, atQuad, &ref_D_801EDFF0)) {
                    Vec3f atPos;
                    Vec3f acPos;

                    CollisionCheck_TrisAvgPoint(acTrisElem, &acPos);
                    CollisionCheck_QuadAvgPoint(atQuad, &atPos);
                    CollisionCheck_SetATvsAC(play, &atQuad->base, &atQuad->elem, &atPos, &acTris->base,
                                             &acTrisElem->base, &acPos, &ref_D_801EDFF0);
                    return;
                }
            }
        }
    }
}
