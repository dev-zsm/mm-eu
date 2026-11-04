// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_TrisVsQuad(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                  Collider* acCol) {
    ColliderTris* atTris = (ColliderTris*)atCol;
    ColliderQuad* acQuad = (ColliderQuad*)acCol;
    ColliderTrisElement* atTrisElem;

    if ((atTris->count > 0) && (atTris->elements != NULL)) {
        if (CollisionCheck_IsElementNotAC(&acQuad->elem)) {
            return;
        }

        Math3D_TriNorm(&ref_D_801EDE40, &acQuad->dim.quad[2], &acQuad->dim.quad[3], &acQuad->dim.quad[1]);
        Math3D_TriNorm(&ref_D_801EDE78, &acQuad->dim.quad[1], &acQuad->dim.quad[0], &acQuad->dim.quad[2]);

        for (atTrisElem = atTris->elements; atTrisElem < &atTris->elements[atTris->count]; atTrisElem++) {
            if (CollisionCheck_IsElementNotAT(&atTrisElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atTrisElem->base, &acQuad->elem)) {
                continue;
            }
            if (Math3D_TriVsTriIntersect(&ref_D_801EDE40, &atTrisElem->dim, &ref_D_801EDE30) ||
                Math3D_TriVsTriIntersect(&ref_D_801EDE78, &atTrisElem->dim, &ref_D_801EDE30)) {
                Vec3f atPos;
                Vec3f acPos;

                CollisionCheck_TrisAvgPoint(atTrisElem, &atPos);
                CollisionCheck_QuadAvgPoint(acQuad, &acPos);
                CollisionCheck_SetATvsAC(play, &atTris->base, &atTrisElem->base, &atPos, &acQuad->base, &acQuad->elem,
                                         &acPos, &ref_D_801EDE30);
                return;
            }
        }
    }
}
