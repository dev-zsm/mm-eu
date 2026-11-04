// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_CylVsCyl(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                Collider* acCol) {
    ColliderCylinder* atCyl = (ColliderCylinder*)atCol;
    ColliderCylinder* acCyl = (ColliderCylinder*)acCol;
    f32 overlapSize;
    f32 centerDist;

    if ((atCyl->dim.radius > 0) && (atCyl->dim.height > 0) && (acCyl->dim.radius > 0) && (acCyl->dim.height > 0)) {
        if (CollisionCheck_IsElementNotAC(&acCyl->elem)) {
            return;
        }
        if (CollisionCheck_IsElementNotAT(&atCyl->elem)) {
            return;
        }
        if (CollisionCheck_NoSharedFlags(&atCyl->elem, &acCyl->elem)) {
            return;
        }

        if (Math3D_CylVsCylOverlapCenterDist(&atCyl->dim, &acCyl->dim, &overlapSize, &centerDist)) {
            Vec3f hitPos;
            Vec3f atPos;
            Vec3f acPos;

            Math_Vec3s_ToVec3f(&atPos, &atCyl->dim.pos);
            Math_Vec3s_ToVec3f(&acPos, &acCyl->dim.pos);
            if (!IS_ZERO(centerDist)) {
                f32 acToHit = acCyl->dim.radius / centerDist;
                f32 height;

                hitPos.y = (f32)atCyl->dim.pos.y + atCyl->dim.yShift + atCyl->dim.height * 0.5f;
                height = (f32)acCyl->dim.pos.y + acCyl->dim.yShift;

                if (hitPos.y < height) {
                    hitPos.y = height;
                } else {
                    height += acCyl->dim.height;
                    if (hitPos.y > height) {
                        hitPos.y = height;
                    }
                }
                hitPos.x = ((f32)atCyl->dim.pos.x - acCyl->dim.pos.x) * acToHit + acCyl->dim.pos.x;
                hitPos.z = ((f32)atCyl->dim.pos.z - acCyl->dim.pos.z) * acToHit + acCyl->dim.pos.z;
            } else {
                Math_Vec3s_ToVec3f(&hitPos, &acCyl->dim.pos);
            }
            CollisionCheck_SetATvsAC(play, &atCyl->base, &atCyl->elem, &atPos, &acCyl->base, &acCyl->elem, &acPos,
                                     &hitPos);
        }
    }
}
