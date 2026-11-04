// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_CylVsTris(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                 Collider* acCol) {
    ColliderCylinder* atCyl = (ColliderCylinder*)atCol;
    ColliderTris* acTris = (ColliderTris*)acCol;
    ColliderTrisElement* acTrisElem;
    Vec3f hitPos;

    if ((atCyl->dim.radius > 0) && (atCyl->dim.height > 0) && (acTris->count > 0) && (acTris->elements != NULL)) {
        if (CollisionCheck_IsElementNotAT(&atCyl->elem)) {
            return;
        }

        for (acTrisElem = acTris->elements; acTrisElem < &acTris->elements[acTris->count]; acTrisElem++) {
            if (CollisionCheck_IsElementNotAC(&acTrisElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atCyl->elem, &acTrisElem->base)) {
                continue;
            }

            if (Math3D_CylTriVsIntersect(&atCyl->dim, &acTrisElem->dim, &hitPos)) {
                Vec3f atPos;
                Vec3f acPos;

                Math_Vec3s_ToVec3f(&atPos, &atCyl->dim.pos);
                CollisionCheck_TrisAvgPoint(acTrisElem, &acPos);
                CollisionCheck_SetATvsAC(play, &atCyl->base, &atCyl->elem, &atPos, &acTris->base, &acTrisElem->base,
                                         &acPos, &hitPos);
                return;
            }
        }
    }
}
