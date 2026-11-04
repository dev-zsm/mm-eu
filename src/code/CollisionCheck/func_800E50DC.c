// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_QuadVsCyl(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                 Collider* acCol) {
    ColliderQuad* atQuad = (ColliderQuad*)atCol;
    ColliderCylinder* acCyl = (ColliderCylinder*)acCol;

    if ((acCyl->dim.height > 0) && (acCyl->dim.radius > 0)) {
        if (CollisionCheck_IsElementNotAC(&acCyl->elem)) {
            return;
        }
        if (CollisionCheck_IsElementNotAT(&atQuad->elem)) {
            return;
        }
        if (CollisionCheck_NoSharedFlags(&atQuad->elem, &acCyl->elem)) {
            return;
        }

        Math3D_TriNorm(&ref_D_801EDF58, &atQuad->dim.quad[2], &atQuad->dim.quad[3], &atQuad->dim.quad[1]);
        Math3D_TriNorm(&ref_D_801EDF90, &atQuad->dim.quad[2], &atQuad->dim.quad[1], &atQuad->dim.quad[0]);

        if (Math3D_CylTriVsIntersect(&acCyl->dim, &ref_D_801EDF58, &ref_D_801EDFE0)) {
            if (Collider_QuadSetNearestAC(play, atQuad, &ref_D_801EDFE0)) {
                Vec3f atPos;
                Vec3f acPos;

                CollisionCheck_QuadAvgPoint(atQuad, &atPos);
                Math_Vec3s_ToVec3f(&acPos, &acCyl->dim.pos);
                CollisionCheck_SetATvsAC(play, &atQuad->base, &atQuad->elem, &atPos, &acCyl->base, &acCyl->elem, &acPos,
                                         &ref_D_801EDFE0);
                return;
            }
        }
        if (Math3D_CylTriVsIntersect(&acCyl->dim, &ref_D_801EDF90, &ref_D_801EDFE0)) {
            if (Collider_QuadSetNearestAC(play, atQuad, &ref_D_801EDFE0)) {
                Vec3f atPos;
                Vec3f acPos;

                CollisionCheck_QuadAvgPoint(atQuad, &atPos);
                Math_Vec3s_ToVec3f(&acPos, &acCyl->dim.pos);
                CollisionCheck_SetATvsAC(play, &atQuad->base, &atQuad->elem, &atPos, &acCyl->base, &acCyl->elem, &acPos,
                                         &ref_D_801EDFE0);
            }
        }
    }
}
