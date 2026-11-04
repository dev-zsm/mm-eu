// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_TrisVsTris(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                  Collider* acCol) {
    ColliderTris* atTris = (ColliderTris*)atCol;
    ColliderTrisElement* atTrisElem;
    ColliderTris* acTris = (ColliderTris*)acCol;
    ColliderTrisElement* acTrisElem;

    if ((acTris->count > 0) && (acTris->elements != NULL) && (atTris->count > 0) && (atTris->elements != NULL)) {
        for (acTrisElem = acTris->elements; acTrisElem < &acTris->elements[acTris->count]; acTrisElem++) {
            if (CollisionCheck_IsElementNotAC(&acTrisElem->base)) {
                continue;
            }
            for (atTrisElem = atTris->elements; atTrisElem < &atTris->elements[atTris->count]; atTrisElem++) {
                if (CollisionCheck_IsElementNotAT(&atTrisElem->base)) {
                    continue;
                }
                if (CollisionCheck_NoSharedFlags(&atTrisElem->base, &acTrisElem->base)) {
                    continue;
                }
                if (Math3D_TriVsTriIntersect(&atTrisElem->dim, &acTrisElem->dim, &ref_D_801EDE20)) {
                    Vec3f atPos;
                    Vec3f acPos;

                    CollisionCheck_TrisAvgPoint(atTrisElem, &atPos);
                    CollisionCheck_TrisAvgPoint(acTrisElem, &acPos);
                    CollisionCheck_SetATvsAC(play, &atTris->base, &atTrisElem->base, &atPos, &acTris->base,
                                             &acTrisElem->base, &acPos, &ref_D_801EDE20);
                    return;
                }
            }
        }
    }
}
