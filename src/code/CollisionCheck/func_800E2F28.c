// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_HitEffects(struct PlayState* play, Collider* at, ColliderElement* atElem, Collider* ac,
                               ColliderElement* acElem, Vec3f* hitPos) {
    if (acElem->acElemFlags & ACELEM_NO_HITMARK) {
        return;
    }

    if (!(atElem->atElemFlags & ATELEM_AT_HITMARK) && (atElem->atElemFlags & ATELEM_DREW_HITMARK)) {
        return;
    }

    if (ac->actor != NULL) {
        sBloodFuncs[sHitInfo[ac->colMaterial].blood](play, ac, hitPos);
    }
    if (ac->actor != NULL) {
        if (sHitInfo[ac->colMaterial].effect == HIT_SOLID) {
            CollisionCheck_HitSolid(play, atElem, ac, hitPos);
        } else if (sHitInfo[ac->colMaterial].effect == HIT_WOOD) {
            if (at->actor == NULL) {
                CollisionCheck_SpawnShieldParticles(play, hitPos);
                Audio_PlaySfx(NA_SE_IT_REFLECTION_WOOD);
            } else {
                CollisionCheck_SpawnShieldParticlesWood(play, hitPos, &at->actor->projectedPos);
            }
        } else if (sHitInfo[ac->colMaterial].effect != HIT_NONE) {
            EffectSsHitmark_SpawnFixedScale(play, sHitInfo[ac->colMaterial].effect, hitPos);
            if (!(acElem->acElemFlags & ACELEM_NO_SWORD_SFX)) {
                CollisionCheck_SwordHitAudio(at, acElem);
            }
        }
    } else {
        EffectSsHitmark_SpawnFixedScale(play, 0, hitPos);
        if (ac->actor == NULL) {
            Audio_PlaySfx(NA_SE_IT_SHIELD_BOUND);
        } else {
            Audio_PlaySfx_AtPos(&ac->actor->projectedPos, NA_SE_IT_SHIELD_BOUND);
        }
    }
}
