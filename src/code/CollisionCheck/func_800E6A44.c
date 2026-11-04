// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_OC_JntSphVsCyl(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* leftCol,
                                   Collider* rightCol) {
    ColliderJntSph* leftJntSph = (ColliderJntSph*)leftCol;
    ColliderCylinder* rightCyl = (ColliderCylinder*)rightCol;
    ColliderJntSphElement* leftJntSphElem;
    f32 overlapSize;

    if ((leftJntSph->count > 0) && (leftJntSph->elements != NULL) && (leftJntSph->base.ocFlags1 & OCELEM_ON) &&
        (rightCyl->base.ocFlags1 & OCELEM_ON) && (rightCyl->elem.ocElemFlags & OCELEM_ON)) {

        for (leftJntSphElem = leftJntSph->elements; leftJntSphElem < &leftJntSph->elements[leftJntSph->count];
             leftJntSphElem++) {
            if (!(leftJntSphElem->base.ocElemFlags & OCELEM_ON)) {
                continue;
            }
            if (Math3D_SphVsCylOverlap(&leftJntSphElem->dim.worldSphere, &rightCyl->dim, &overlapSize)) {
                Vec3f leftPos;
                Vec3f rightPos;

                Math_Vec3s_ToVec3f(&leftPos, &leftJntSphElem->dim.worldSphere.center);
                Math_Vec3s_ToVec3f(&rightPos, &rightCyl->dim.pos);
                CollisionCheck_SetOCvsOC(play, &leftJntSph->base, &leftJntSphElem->base, &leftPos, &rightCyl->base,
                                         &rightCyl->elem, &rightPos, overlapSize);
            }
        }
    }
}
