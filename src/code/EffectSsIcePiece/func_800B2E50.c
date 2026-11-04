// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite_old_init.h"

void EffectSsIcePiece_SpawnBurst(PlayState* play, Vec3f* refPos, f32 scale) {
    static Vec3f sAccel = { 0.0f, 0.0f, 0.0f };
    static Vec3f sVecScales[] = {
        { 0.0f, 70.0f, 0.0f },
        { 0.0f, 45.0f, 20.0f },
        { 17.320474f, 45.0f, 9.999695f },
        { 17.320474f, 45.0f, -9.999695f },
        { 0.0f, 45.0f, -20.0f },
        { -17.320474f, 45.0f, -9.999695f },
        { -17.320474f, 45.0f, 9.999695f },
        { 0.0f, 20.0f, 20.0f },
        { 17.320474f, 20.0f, -9.999695f },
        { -17.320474f, 20.0f, -9.999695f },
    };
    s32 i;
    Vec3f velocity;
    Vec3f pos;
    f32 velocityScale;

    sAccel.y = -0.2f;

    for (i = 0; i < ARRAY_COUNT(sVecScales); i++) {
        pos = *refPos;
        velocityScale = Rand_ZeroFloat(1.0f) + 0.5f;
        velocity.x = (sVecScales[i].x * 0.18f) * velocityScale;
        velocity.y = (sVecScales[i].y * 0.18f) * velocityScale;
        velocity.z = (sVecScales[i].z * 0.18f) * velocityScale;
        pos.x += sVecScales[i].x;
        pos.y += sVecScales[i].y;
        pos.z += sVecScales[i].z;

        EffectSsIcePiece_Spawn(play, &pos, (Rand_ZeroFloat(1.0f) + 0.5f) * ((scale * 1.3f) * 100.0f), &velocity,
                               &sAccel, 25);
    }
}
