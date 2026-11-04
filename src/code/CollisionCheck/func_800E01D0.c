// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

f32 CollisionCheck_GetDamageAndEffectOnElementAC(Collider* atCol, ColliderElement* atElem, Collider* acCol,
                                                 ColliderElement* acElem, u32* effect) {
    static f32 sDamageMultipliers[] = {
        0.0f, 1.0f, 2.0f, 0.5f, 0.25f, 3.0f, 4.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    };
    u32 dmgFlags;
    s32 i;
    f32 damage;

    *effect = 0;
    damage = CollisionCheck_GetElementATDamage(atCol, atElem, acCol, acElem);

    if (acCol->actor->colChkInfo.damageTable != NULL) {
        dmgFlags = atElem->atDmgInfo.dmgFlags;

        for (i = 0; i < ARRAY_COUNT(acCol->actor->colChkInfo.damageTable->attack); i++) {
            if (dmgFlags == 1) {
                break;
            }
            dmgFlags >>= 1;
        }

        damage *= sDamageMultipliers[acCol->actor->colChkInfo.damageTable->attack[i] & 0xF];
        *effect = (acCol->actor->colChkInfo.damageTable->attack[i] >> 4) & 0xF;
    }
    return damage;
}
