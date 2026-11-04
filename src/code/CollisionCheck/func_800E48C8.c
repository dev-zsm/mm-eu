// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_TrisVsCyl(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                 Collider* acCol) {
    ColliderTris* atTris = (ColliderTris*)atCol;
    ColliderCylinder* acCyl = (ColliderCylinder*)acCol;
    ColliderTrisElement* atTrisElem;

    if ((acCyl->dim.radius > 0) && (acCyl->dim.height > 0) && (atTris->count > 0) && (atTris->elements != NULL)) {
        if (CollisionCheck_IsElementNotAC(&acCyl->elem)) {
            return;
        }
        for (atTrisElem = atTris->elements; atTrisElem < &atTris->elements[atTris->count]; atTrisElem++) {
            if (CollisionCheck_IsElementNotAT(&atTrisElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atTrisElem->base, &acCyl->elem)) {
                continue;
            }
            if (Math3D_CylTriVsIntersect(&acCyl->dim, &atTrisElem->dim, &ref_D_801EDE10)) {
                Vec3f atPos;
                Vec3f acPos;

                CollisionCheck_TrisAvgPoint(atTrisElem, &atPos);
                Math_Vec3s_ToVec3f(&acPos, &acCyl->dim.pos);
                CollisionCheck_SetATvsAC(play, &atTris->base, &atTrisElem->base, &atPos, &acCyl->base, &acCyl->elem,
                                         &acPos, &ref_D_801EDE10);
                return;
            }
        }
    }
}
