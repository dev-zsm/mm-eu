// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_JntSphVsQuad(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                    Collider* acCol) {
    ColliderJntSph* atJntSph = (ColliderJntSph*)atCol;
    ColliderQuad* acQuad = (ColliderQuad*)acCol;
    Vec3f hitPos;
    ColliderJntSphElement* atJntSphElem;

    if ((atJntSph->count > 0) && (atJntSph->elements != NULL)) {
        if (CollisionCheck_IsElementNotAC(&acQuad->elem)) {
            return;
        }
        Math3D_TriNorm(&ref_D_801EF590, &acQuad->dim.quad[2], &acQuad->dim.quad[3], &acQuad->dim.quad[1]);
        Math3D_TriNorm(&ref_D_801EF5C8, &acQuad->dim.quad[1], &acQuad->dim.quad[0], &acQuad->dim.quad[2]);

        for (atJntSphElem = atJntSph->elements; atJntSphElem < &atJntSph->elements[atJntSph->count]; atJntSphElem++) {
            if (CollisionCheck_IsElementNotAT(&atJntSphElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atJntSphElem->base, &acQuad->elem)) {
                continue;
            }
            if (Math3D_TriVsSphIntersect(&atJntSphElem->dim.worldSphere, &ref_D_801EF590, &hitPos) ||
                Math3D_TriVsSphIntersect(&atJntSphElem->dim.worldSphere, &ref_D_801EF5C8, &hitPos)) {
                Vec3f atPos;
                Vec3f acPos;

                Math_Vec3s_ToVec3f(&atPos, &atJntSphElem->dim.worldSphere.center);
                CollisionCheck_QuadAvgPoint(acQuad, &acPos);
                CollisionCheck_SetATvsAC(play, &atJntSph->base, &atJntSphElem->base, &atPos, &acQuad->base,
                                         &acQuad->elem, &acPos, &hitPos);
                return;
            }
        }
    }
}
