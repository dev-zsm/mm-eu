// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_SetJntSphHitFX(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* col) {
    ColliderJntSph* jntSph = (ColliderJntSph*)col;
    ColliderJntSphElement* jntSphElem;

    for (jntSphElem = jntSph->elements; jntSphElem < &jntSph->elements[jntSph->count]; jntSphElem++) {
        if ((jntSphElem->base.acElemFlags & ACELEM_DRAW_HITMARK) && (jntSphElem->base.acHitElem != NULL) &&
            !(jntSphElem->base.acHitElem->atElemFlags & ATELEM_DREW_HITMARK)) {
            Vec3f hitPos;

            Math_Vec3s_ToVec3f(&hitPos, &jntSphElem->base.acDmgInfo.hitPos);
            CollisionCheck_HitEffects(play, jntSphElem->base.acHit, jntSphElem->base.acHitElem, &jntSph->base,
                                      &jntSphElem->base, &hitPos);
            jntSphElem->base.acHitElem->atElemFlags |= ATELEM_DREW_HITMARK;
            return;
        }
    }
}
