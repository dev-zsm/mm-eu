// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite_old_init.h"

void EffectSsFireTail_SpawnFlame(PlayState* play, Actor* actor, Vec3f* pos, f32 arg3, s16 bodyPart,
                                 f32 colorIntensity) {
    static Color_RGBA8 sPrimColor = { 255, 255, 0, 255 };
    static Color_RGBA8 sEnvColor = { 255, 0, 0, 255 };

    sPrimColor.g = (s32)(255.0f * colorIntensity);
    sPrimColor.b = 0;

    sEnvColor.g = 0;
    sEnvColor.b = 0;
    sPrimColor.r = sEnvColor.r = (s32)(255.0f * colorIntensity);

    EffectSsFireTail_Spawn(play, actor, pos, arg3, &actor->velocity, 15, &sPrimColor, &sEnvColor,
                           (colorIntensity == 1.0f) ? 0 : 1, bodyPart, 1);
}
