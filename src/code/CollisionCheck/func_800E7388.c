// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_ApplyDamage(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* col,
                                ColliderElement* elem) {
    f32 damage;
    f32 finalDamage = 0.0f;
    s32 pad;
    Collider* atCol;
    ColliderElement* atElem;
    s32 pad1;
    u32 effect;

    if ((col->actor == NULL) || !(col->acFlags & AC_HIT)) {
        return;
    }
    if (!(elem->acElemFlags & ACELEM_HIT) || (elem->acElemFlags & ACELEM_NO_DAMAGE)) {
        return;
    }

    atCol = elem->acHit;
    atElem = elem->acHitElem;

    if ((atCol != NULL) && (atElem != NULL) && (col != NULL) && (elem != NULL)) {
        damage = CollisionCheck_GetDamageAndEffectOnElementAC(atCol, atElem, col, elem, &effect);

        if (CollisionCheck_GetElementATDamage(atCol, atElem, col, elem) != 0) {
            if (damage < 1.0f) {
                finalDamage = 0.0f;
                if (effect == 0) {
                    return;
                }
            } else {
                finalDamage = CollisionCheck_ApplyElementATDefense(damage, elem);
                if ((finalDamage < 1.0f) && (effect == 0)) {
                    return;
                }
            }
        }
        if (col->actor->colChkInfo.damageTable != NULL) {
            col->actor->colChkInfo.damageEffect = effect;
        }
        if (!(col->acFlags & AC_HARD) || ((col->acFlags & AC_HARD) && (atElem->atDmgInfo.dmgFlags == 0x20000000))) {
            if (col->actor->colChkInfo.damage < finalDamage) {
                col->actor->colChkInfo.damage = finalDamage;
            }
        }
    }
}
