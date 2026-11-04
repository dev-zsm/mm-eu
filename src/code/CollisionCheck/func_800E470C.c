// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_TrisVsJntSph(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                    Collider* acCol) {
    ColliderTris* atTris = (ColliderTris*)atCol;
    ColliderJntSphElement* acJntSphElem;
    ColliderJntSph* acJntSph = (ColliderJntSph*)acCol;
    ColliderTrisElement* atTrisElem;
    Vec3f hitPos;

    if ((acJntSph->count > 0) && (acJntSph->elements != NULL) && (atTris->count > 0) && (atTris->elements != NULL)) {
        for (acJntSphElem = acJntSph->elements; acJntSphElem < &acJntSph->elements[acJntSph->count]; acJntSphElem++) {
            if (CollisionCheck_IsElementNotAC(&acJntSphElem->base)) {
                continue;
            }
            for (atTrisElem = atTris->elements; atTrisElem < &atTris->elements[atTris->count]; atTrisElem++) {
                if (CollisionCheck_IsElementNotAT(&atTrisElem->base)) {
                    continue;
                }
                if (CollisionCheck_NoSharedFlags(&atTrisElem->base, &acJntSphElem->base)) {
                    continue;
                }
                if (Math3D_TriVsSphIntersect(&acJntSphElem->dim.worldSphere, &atTrisElem->dim, &hitPos)) {
                    Vec3f atPos;
                    Vec3f acPos;

                    Math_Vec3s_ToVec3f(&acPos, &acJntSphElem->dim.worldSphere.center);
                    CollisionCheck_TrisAvgPoint(atTrisElem, &atPos);
                    CollisionCheck_SetATvsAC(play, &atTris->base, &atTrisElem->base, &atPos, &acJntSph->base,
                                             &acJntSphElem->base, &acPos, &hitPos);

                    if (!(acJntSph->base.ocFlags2 & OC2_FIRST_ONLY)) {
                        return;
                    }
                }
            }
        }
    }
}
