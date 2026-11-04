// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite_old_init.h"

void EffectSsGSpk_SpawnRandColor(PlayState* play, Actor* actor, Vec3f* pos, Vec3f* velocity, Vec3f* accel, s16 scale,
                                 s16 scaleStep) {
    Color_RGBA8 primColor = { 255, 255, 150, 255 };
    Color_RGBA8 envColor = { 255, 0, 0, 0 };
    s32 randOffset = (Rand_ZeroOne() * 20.0f) - 10.0f;

    primColor.r += randOffset;
    primColor.g += randOffset;
    primColor.b += randOffset;
    primColor.a += randOffset;
    envColor.r += randOffset;
    envColor.g += randOffset;
    envColor.b += randOffset;
    envColor.a += randOffset;

    EffectSsGSpk_SpawnAccel(play, actor, pos, velocity, accel, &primColor, &envColor, scale, scaleStep);
}
