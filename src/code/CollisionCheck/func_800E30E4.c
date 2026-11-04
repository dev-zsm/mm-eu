// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

s32 CollisionCheck_SetATvsAC(struct PlayState* play, Collider* atCol, ColliderElement* atElem, Vec3f* atPos,
                             Collider* acCol, ColliderElement* acElem, Vec3f* acPos, Vec3f* hitPos) {
    f32 damage;
    u32 effect;

    if (CollisionCheck_GetElementATDamage(atCol, atElem, acCol, acElem) != 0) {
        damage = CollisionCheck_GetDamageAndEffectOnElementAC(atCol, atElem, acCol, acElem, &effect);
        if (damage < 1.0f) {
            if (effect == 0) {
                return 0;
            }
        } else if ((CollisionCheck_ApplyElementATDefense(damage, acElem) < 1.0f) && (effect == 0)) {
            return 0;
        }
    }
    if ((acCol->acFlags & AC_HARD) && (atCol->actor != NULL) && (acCol->actor != NULL)) {
        CollisionCheck_SetBounce(atCol, acCol);
    }
    if (!(acElem->acElemFlags & ACELEM_NO_AT_INFO)) {
        atCol->atFlags |= AT_HIT;
        atCol->at = acCol->actor;
        atElem->atHit = acCol;
        atElem->atElemFlags |= ATELEM_HIT;
        atElem->atHitElem = acElem;
        if (!(atElem->acElemFlags & ACELEM_HIT)) {
            atElem->acDmgInfo.hitPos.x = hitPos->x;
            atElem->acDmgInfo.hitPos.y = hitPos->y;
            atElem->acDmgInfo.hitPos.z = hitPos->z;
        }
        if (atCol->actor != NULL) {
            atCol->actor->colChkInfo.atHitEffect = acElem->acDmgInfo.effect;
        }
    }
    if (!(atElem->ocElemFlags & OCELEM_UNK2)) {
        acCol->acFlags |= AC_HIT;
        acCol->ac = atCol->actor;
        acElem->acHit = atCol;
        acElem->acHitElem = atElem;
        acElem->acElemFlags |= ACELEM_HIT;
        if (acCol->actor != NULL) {
            acCol->actor->colChkInfo.acHitEffect = atElem->atDmgInfo.effect;
        }
        acElem->acDmgInfo.hitPos.x = hitPos->x;
        acElem->acDmgInfo.hitPos.y = hitPos->y;
        acElem->acDmgInfo.hitPos.z = hitPos->z;
    }
    if (!(atElem->atElemFlags & ATELEM_AT_HITMARK) && (acCol->colMaterial != COL_MATERIAL_METAL) &&
        (acCol->colMaterial != COL_MATERIAL_WOOD) && (acCol->colMaterial != COL_MATERIAL_HARD)) {
        acElem->acElemFlags |= ACELEM_DRAW_HITMARK;
    } else {
        CollisionCheck_HitEffects(play, atCol, atElem, acCol, acElem, hitPos);
        atElem->atElemFlags |= ATELEM_DREW_HITMARK;
    }
    return 1;
}
