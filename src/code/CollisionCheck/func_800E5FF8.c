// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_SetTrisHitFX(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* col) {
    ColliderTris* tris = (ColliderTris*)col;
    ColliderTrisElement* trisElem;

    for (trisElem = tris->elements; trisElem < &tris->elements[tris->count]; trisElem++) {
        if ((trisElem->base.acElemFlags & ACELEM_DRAW_HITMARK) && (trisElem->base.acHitElem != NULL) &&
            !(trisElem->base.acHitElem->atElemFlags & ATELEM_DREW_HITMARK)) {
            Vec3f hitPos;

            Math_Vec3s_ToVec3f(&hitPos, &trisElem->base.acDmgInfo.hitPos);
            CollisionCheck_HitEffects(play, trisElem->base.acHit, trisElem->base.acHitElem, &tris->base,
                                      &trisElem->base, &hitPos);
            trisElem->base.acHitElem->atElemFlags |= ATELEM_DREW_HITMARK;
            return;
        }
    }
}
