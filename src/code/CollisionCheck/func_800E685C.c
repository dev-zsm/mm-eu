// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_OC_JntSphVsJntSph(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* leftCol,
                                      Collider* rightCol) {
    ColliderJntSph* leftJntSph = (ColliderJntSph*)leftCol;
    ColliderJntSph* rightJntSph = (ColliderJntSph*)rightCol;
    ColliderJntSphElement* leftJntSphElem;
    ColliderJntSphElement* rightJntSphElem;
    f32 overlapSize;

    if ((leftJntSph->count > 0) && (leftJntSph->elements != NULL) && (rightJntSph->count > 0) &&
        (rightJntSph->elements != NULL) && (leftJntSph->base.ocFlags1 & OCELEM_ON) &&
        (rightJntSph->base.ocFlags1 & OCELEM_ON)) {

        for (leftJntSphElem = leftJntSph->elements; leftJntSphElem < &leftJntSph->elements[leftJntSph->count];
             leftJntSphElem++) {
            if (!(leftJntSphElem->base.ocElemFlags & OCELEM_ON)) {
                continue;
            }
            for (rightJntSphElem = rightJntSph->elements; rightJntSphElem < &rightJntSph->elements[rightJntSph->count];
                 rightJntSphElem++) {
                if (!(rightJntSphElem->base.ocElemFlags & OCELEM_ON)) {
                    continue;
                }
                if (Math3D_SphVsSphOverlap(&leftJntSphElem->dim.worldSphere, &rightJntSphElem->dim.worldSphere,
                                           &overlapSize)) {
                    Vec3f leftPos;
                    Vec3f rightPos;

                    Math_Vec3s_ToVec3f(&leftPos, &leftJntSphElem->dim.worldSphere.center);
                    Math_Vec3s_ToVec3f(&rightPos, &rightJntSphElem->dim.worldSphere.center);
                    CollisionCheck_SetOCvsOC(play, &leftJntSph->base, &leftJntSphElem->base, &leftPos,
                                             &rightJntSph->base, &rightJntSphElem->base, &rightPos, overlapSize);
                }
            }
        }
    }
}
