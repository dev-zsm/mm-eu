// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_CylVsQuad(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                 Collider* acCol) {
    ColliderCylinder* atCyl = (ColliderCylinder*)atCol;
    ColliderQuad* acQuad = (ColliderQuad*)acCol;

    if ((atCyl->dim.height > 0) && (atCyl->dim.radius > 0)) {
        if (CollisionCheck_IsElementNotAT(&atCyl->elem)) {
            return;
        }
        if (CollisionCheck_IsElementNotAC(&acQuad->elem)) {
            return;
        }
        if (CollisionCheck_NoSharedFlags(&atCyl->elem, &acQuad->elem)) {
            return;
        }
        Math3D_TriNorm(&ref_D_801EF600, &acQuad->dim.quad[2], &acQuad->dim.quad[3], &acQuad->dim.quad[1]);
        Math3D_TriNorm(&ref_D_801EF638, &acQuad->dim.quad[1], &acQuad->dim.quad[0], &acQuad->dim.quad[2]);

        if (Math3D_CylTriVsIntersect(&atCyl->dim, &ref_D_801EF600, &ref_D_801EDE00)) {
            Vec3f atPos;
            Vec3f acPos;

            Math_Vec3s_ToVec3f(&atPos, &atCyl->dim.pos);
            CollisionCheck_QuadAvgPoint(acQuad, &acPos);
            CollisionCheck_SetATvsAC(play, &atCyl->base, &atCyl->elem, &atPos, &acQuad->base, &acQuad->elem, &acPos,
                                     &ref_D_801EDE00);
        } else if (Math3D_CylTriVsIntersect(&atCyl->dim, &ref_D_801EF638, &ref_D_801EDE00)) {
            Vec3f atPos;
            Vec3f acPos;

            Math_Vec3s_ToVec3f(&atPos, &atCyl->dim.pos);
            CollisionCheck_QuadAvgPoint(acQuad, &acPos);
            CollisionCheck_SetATvsAC(play, &atCyl->base, &atCyl->elem, &atPos, &acQuad->base, &acQuad->elem, &acPos,
                                     &ref_D_801EDE00);
        }
    }
}
