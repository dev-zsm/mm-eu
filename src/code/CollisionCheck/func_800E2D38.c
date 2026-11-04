// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_HitSolid(struct PlayState* play, ColliderElement* elem, Collider* col, Vec3f* hitPos) {
    s32 flags = elem->atElemFlags & ATELEM_SFX_NONE;

    if ((flags == ATELEM_SFX_NORMAL) && (col->colMaterial != COL_MATERIAL_METAL)) {
        EffectSsHitmark_SpawnFixedScale(play, 0, hitPos);
        if (col->actor == NULL) {
            Audio_PlaySfx(NA_SE_IT_SHIELD_BOUND);
        } else {
            Audio_PlaySfx_AtPos(&col->actor->projectedPos, NA_SE_IT_SHIELD_BOUND);
        }
    } else if (flags == ATELEM_SFX_NORMAL) {
        EffectSsHitmark_SpawnFixedScale(play, 3, hitPos);
        if (col->actor == NULL) {
            CollisionCheck_SpawnShieldParticlesMetal(play, hitPos);
        } else {
            CollisionCheck_SpawnShieldParticlesMetalSound(play, hitPos, &col->actor->projectedPos);
        }
    } else if (flags == ATELEM_SFX_HARD) {
        EffectSsHitmark_SpawnFixedScale(play, 0, hitPos);
        if (col->actor == NULL) {
            Audio_PlaySfx(NA_SE_IT_SHIELD_BOUND);
        } else {
            Audio_PlaySfx_AtPos(&col->actor->projectedPos, NA_SE_IT_SHIELD_BOUND);
        }
    } else if (flags == ATELEM_SFX_WOOD) {
        EffectSsHitmark_SpawnFixedScale(play, 1, hitPos);
        if (col->actor == NULL) {
            Audio_PlaySfx(NA_SE_IT_REFLECTION_WOOD);
        } else {
            Audio_PlaySfx_AtPos(&col->actor->projectedPos, NA_SE_IT_REFLECTION_WOOD);
        }
    }
}
