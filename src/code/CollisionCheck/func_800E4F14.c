// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC_QuadVsJntSph(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol,
                                    Collider* acCol) {
    ColliderJntSphElement* acJntSphElem;
    Vec3f hitPos;
    ColliderQuad* atQuad = (ColliderQuad*)atCol;
    ColliderJntSph* acJntSph = (ColliderJntSph*)acCol;

    if ((acJntSph->count > 0) && (acJntSph->elements != NULL)) {
        if (CollisionCheck_IsElementNotAT(&atQuad->elem)) {
            return;
        }
        Math3D_TriNorm(&ref_D_801EDEC8, &atQuad->dim.quad[2], &atQuad->dim.quad[3], &atQuad->dim.quad[1]);
        Math3D_TriNorm(&ref_D_801EDF00, &atQuad->dim.quad[2], &atQuad->dim.quad[1], &atQuad->dim.quad[0]);

        for (acJntSphElem = acJntSph->elements; acJntSphElem < &acJntSph->elements[acJntSph->count]; acJntSphElem++) {
            if (CollisionCheck_IsElementNotAC(&acJntSphElem->base)) {
                continue;
            }
            if (CollisionCheck_NoSharedFlags(&atQuad->elem, &acJntSphElem->base)) {
                continue;
            }
            if (Math3D_TriVsSphIntersect(&acJntSphElem->dim.worldSphere, &ref_D_801EDEC8, &hitPos) ||
                Math3D_TriVsSphIntersect(&acJntSphElem->dim.worldSphere, &ref_D_801EDF00, &hitPos)) {
                Vec3f atPos;
                Vec3f acPos;

                if (!Collider_QuadSetNearestAC(play, atQuad, &hitPos)) {
                    continue;
                }
                Math_Vec3s_ToVec3f(&acPos, &acJntSphElem->dim.worldSphere.center);
                CollisionCheck_QuadAvgPoint(atQuad, &atPos);
                CollisionCheck_SetATvsAC(play, &atQuad->base, &atQuad->elem, &atPos, &acJntSph->base,
                                         &acJntSphElem->base, &acPos, &hitPos);

                if (!(acJntSph->base.ocFlags2 & OC2_FIRST_ONLY)) {
                    break;
                }
            }
        }
    }
}
