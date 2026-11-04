// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_CylVsJntSph(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                   Collider* acCol) {
    ColliderCylinder* atCyl = (ColliderCylinder*)atCol;
    ColliderJntSph* acJntSph = (ColliderJntSph*)acCol;
    f32 overlapSize;
    f32 centerDist;
    ColliderJntSphElement* acJntSphElem;

    if ((acJntSph->count > 0) && (acJntSph->elements != NULL) && (atCyl->dim.radius > 0) && (atCyl->dim.height > 0)) {
        if (CollisionCheck_IsElementNotAT(&atCyl->elem)) {
            return;
        }
        for (acJntSphElem = acJntSph->elements; acJntSphElem < &acJntSph->elements[acJntSph->count]; acJntSphElem++) {
            if (CollisionCheck_IsElementNotAC(&acJntSphElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atCyl->elem, &acJntSphElem->base)) {
                continue;
            }
            if (Math3D_SphVsCylOverlapCenterDist(&acJntSphElem->dim.worldSphere, &atCyl->dim, &overlapSize,
                                                 &centerDist)) {
                Vec3f hitPos;
                Vec3f atPos;
                Vec3f acPos;
                f32 acToHit;

                Math_Vec3s_ToVec3f(&atPos, &atCyl->dim.pos);
                Math_Vec3s_ToVec3f(&acPos, &acJntSphElem->dim.worldSphere.center);
                if (!IS_ZERO(centerDist)) {
                    acToHit = acJntSphElem->dim.worldSphere.radius / centerDist;
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
                CollisionCheck_SetATvsAC(play, &atCyl->base, &atCyl->elem, &atPos, &acJntSph->base, &acJntSphElem->base,
                                         &acPos, &hitPos);
                if (!(acJntSph->base.ocFlags2 & OC2_FIRST_ONLY)) {
                    break;
                }
            }
        }
    }
}
