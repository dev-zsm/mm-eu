// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_JntSphVsCyl(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                   Collider* acCol) {
    ColliderJntSph* atJntSph = (ColliderJntSph*)atCol;
    ColliderJntSphElement* atJntSphElem;
    ColliderCylinder* acCyl = (ColliderCylinder*)acCol;
    f32 overlapSize;
    f32 centerDist;

    if ((atJntSph->count > 0) && (atJntSph->elements != NULL) && (acCyl->dim.radius > 0) && (acCyl->dim.height > 0)) {
        if (CollisionCheck_IsElementNotAC(&acCyl->elem)) {
            return;
        }
        for (atJntSphElem = atJntSph->elements; atJntSphElem < &atJntSph->elements[atJntSph->count]; atJntSphElem++) {
            if (CollisionCheck_IsElementNotAT(&atJntSphElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atJntSphElem->base, &acCyl->elem)) {
                continue;
            }
            if (Math3D_SphVsCylOverlapCenterDist(&atJntSphElem->dim.worldSphere, &acCyl->dim, &overlapSize,
                                                 &centerDist)) {
                Vec3f hitPos;
                Vec3f atPos;
                Vec3f acPos;
                f32 acToHit;

                Math_Vec3s_ToVec3f(&atPos, &atJntSphElem->dim.worldSphere.center);
                Math_Vec3s_ToVec3f(&acPos, &acCyl->dim.pos);
                if (!IS_ZERO(centerDist)) {
                    acToHit = acCyl->dim.radius / centerDist;
                    if (acToHit <= 1.0f) {
                        hitPos.x = ((atPos.x - acPos.x) * acToHit) + acPos.x;
                        hitPos.y = ((atPos.y - acPos.y) * acToHit) + acPos.y;
                        hitPos.z = ((atPos.z - acPos.z) * acToHit) + acPos.z;
                    } else {
                        Math_Vec3f_Copy(&hitPos, &atPos);
                    }
                } else {
                    Math_Vec3f_Copy(&hitPos, &atPos);
                }
                CollisionCheck_SetATvsAC(play, &atJntSph->base, &atJntSphElem->base, &atPos, &acCyl->base, &acCyl->elem,
                                         &acPos, &hitPos);
                return;
            }
        }
    }
}
