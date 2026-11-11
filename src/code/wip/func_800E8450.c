// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 8.00 (13 differ, size +3)
#include "generated/mm/z_collision_check.h"

void CollisionCheck_SpawnShieldParticlesWood(struct PlayState* play, Vec3f* v, Vec3f* pos) {
    static EffectShieldParticleInit sShieldParticleInitWood = {
        16,
        { 0, 0, 0 },
        { 0, 200, 255, 255 },
        { 255, 255, 255, 255 },
        { 255, 255, 128, 255 },
        { 255, 255, 0, 255 },
        { 255, 64, 0, 200 },
        { 255, 0, 0, 255 },
        2.1f,
        35.0f,
        30.0f,
        8,
        { 0, 0, 0, { 0, 128, 255 }, 0, 300 },
        0,
    };
    s32 effectIndex;

    sShieldParticleInitWood.position.x = v->x;
    sShieldParticleInitWood.position.y = v->y;
    sShieldParticleInitWood.position.z = v->z;
    sShieldParticleInitWood.lightPoint.x = sShieldParticleInitWood.position.x;
    sShieldParticleInitWood.lightPoint.y = sShieldParticleInitWood.position.y;
    sShieldParticleInitWood.lightPoint.z = sShieldParticleInitWood.position.z;

    Effect_Add(play, &effectIndex, EFFECT_SHIELD_PARTICLE, 0, 1, &sShieldParticleInitWood);
    Audio_PlaySfx_AtPos(pos, NA_SE_IT_REFLECTION_WOOD);
}
