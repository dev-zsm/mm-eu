// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_SphereVsCylinder(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                        Collider* acCol) {
    ColliderCylinder* acCyl = (ColliderCylinder*)acCol;
    ColliderSphere* atSph = (ColliderSphere*)atCol;
    f32 overlapSize;
    f32 centerDist;

    if (CollisionCheck_IsElementNotAT(&atSph->elem)) {
        return;
    }
    if (CollisionCheck_IsElementNotAC(&acCyl->elem)) {
        return;
    }
    if (CollisionCheck_NoSharedFlags(&atSph->elem, &acCyl->elem)) {
        return;
    }

    if (Math3D_SphVsCylOverlapCenterDist(&atSph->dim.worldSphere, &acCyl->dim, &overlapSize, &centerDist)) {
        Vec3f hitPos;
        Vec3f atPos;
        Vec3f acPos;

        Math_Vec3s_ToVec3f(&atPos, &atSph->dim.worldSphere.center);
        Math_Vec3s_ToVec3f(&acPos, &acCyl->dim.pos);

        if (!IS_ZERO(centerDist)) {
            f32 acToHit = acCyl->dim.radius / centerDist;

            if (acToHit <= 1.0f) {
                hitPos.x = (atPos.x - acPos.x) * acToHit + acPos.x;
                hitPos.y = (atPos.y - acPos.y) * acToHit + acPos.y;
                hitPos.z = (atPos.z - acPos.z) * acToHit + acPos.z;
            } else {
                Math_Vec3f_Copy(&hitPos, &atPos);
            }
        } else {
            Math_Vec3f_Copy(&hitPos, &atPos);
        }
        CollisionCheck_SetATvsAC(play, &atSph->base, &atSph->elem, &atPos, &acCyl->base, &acCyl->elem, &acPos, &hitPos);
    }

    if (atSph) {}
}
