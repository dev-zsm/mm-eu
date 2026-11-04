// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_JntSphVsTris(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                    Collider* acCol) {
    ColliderJntSph* atJntSph = (ColliderJntSph*)atCol;
    ColliderJntSphElement* atJntSphElem;
    ColliderTris* acTris = (ColliderTris*)acCol;
    ColliderTrisElement* acTrisElem;
    Vec3f hitPos;

    if ((atJntSph->count > 0) && (atJntSph->elements != NULL) && (acTris->count > 0) && (acTris->elements != NULL)) {
        for (atJntSphElem = atJntSph->elements; atJntSphElem < &atJntSph->elements[atJntSph->count]; atJntSphElem++) {
            if (CollisionCheck_IsElementNotAT(&atJntSphElem->base)) {
                continue;
            }
            for (acTrisElem = acTris->elements; acTrisElem < &acTris->elements[acTris->count]; acTrisElem++) {
                if (CollisionCheck_IsElementNotAC(&acTrisElem->base)) {
                    continue;
                }
                if (CollisionCheck_NoSharedFlags(&atJntSphElem->base, &acTrisElem->base)) {
                    continue;
                }
                if (Math3D_TriVsSphIntersect(&atJntSphElem->dim.worldSphere, &acTrisElem->dim, &hitPos)) {
                    Vec3f atPos;
                    Vec3f acPos;

                    Math_Vec3s_ToVec3f(&atPos, &atJntSphElem->dim.worldSphere.center);
                    CollisionCheck_TrisAvgPoint(acTrisElem, &acPos);
                    CollisionCheck_SetATvsAC(play, &atJntSph->base, &atJntSphElem->base, &atPos, &acTris->base,
                                             &acTrisElem->base, &acPos, &hitPos);
                    return;
                }
            }
        }
    }
}
