// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_JntSphVsSphere(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                      Collider* acCol) {
    ColliderJntSph* atJntSph = (ColliderJntSph*)atCol;
    ColliderSphere* acSph = (ColliderSphere*)acCol;
    ColliderJntSphElement* atJntSphElem;
    f32 overlapSize;
    f32 centerDist;

    if ((atJntSph->count > 0) && (atJntSph->elements != NULL)) {
        if (CollisionCheck_IsElementNotAC(&acSph->elem)) {
            return;
        }
        for (atJntSphElem = atJntSph->elements; atJntSphElem < &atJntSph->elements[atJntSph->count]; atJntSphElem++) {
            if (CollisionCheck_IsElementNotAT(&atJntSphElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atJntSphElem->base, &acSph->elem)) {
                continue;
            }
            if (Math3D_SphVsSphOverlapCenterDist(&atJntSphElem->dim.worldSphere, &acSph->dim.worldSphere, &overlapSize,
                                                 &centerDist)) {
                f32 acToHit;
                Vec3f hitPos;
                Vec3f atPos;
                Vec3f acPos;

                Math_Vec3s_ToVec3f(&atPos, &atJntSphElem->dim.worldSphere.center);
                Math_Vec3s_ToVec3f(&acPos, &acSph->dim.worldSphere.center);
                if (!IS_ZERO(centerDist)) {
                    acToHit = acSph->dim.worldSphere.radius / centerDist;
                    hitPos.x = ((atPos.x - acPos.x) * acToHit) + acPos.x;
                    hitPos.y = ((atPos.y - acPos.y) * acToHit) + acPos.y;
                    hitPos.z = ((atPos.z - acPos.z) * acToHit) + acPos.z;
                } else {
                    Math_Vec3f_Copy(&hitPos, &atPos);
                }
                CollisionCheck_SetATvsAC(play, &atJntSph->base, &atJntSphElem->base, &atPos, &acSph->base, &acSph->elem,
                                         &acPos, &hitPos);
            }
        }
    }
}
