// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_TrisVsSphere(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                    Collider* acCol) {
    ColliderTris* atTris = (ColliderTris*)atCol;
    ColliderTrisElement* atTrisElem;
    ColliderSphere* acSph = (ColliderSphere*)acCol;
    Vec3f hitPos;

    if ((atTris->count > 0) && (atTris->elements != NULL)) {
        if (CollisionCheck_IsElementNotAC(&acSph->elem)) {
            return;
        }
        for (atTrisElem = atTris->elements; atTrisElem < &atTris->elements[atTris->count]; atTrisElem++) {
            if (CollisionCheck_IsElementNotAT(&atTrisElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atTrisElem->base, &acSph->elem)) {
                continue;
            }
            if (Math3D_TriVsSphIntersect(&acSph->dim.worldSphere, &atTrisElem->dim, &hitPos)) {
                Vec3f atPos;
                Vec3f acPos;

                Math_Vec3s_ToVec3f(&acPos, &acSph->dim.worldSphere.center);
                CollisionCheck_TrisAvgPoint(atTrisElem, &atPos);
                CollisionCheck_SetATvsAC(play, &atTris->base, &atTrisElem->base, &atPos, &acSph->base, &acSph->elem,
                                         &acPos, &hitPos);
            }
        }
    }
}
