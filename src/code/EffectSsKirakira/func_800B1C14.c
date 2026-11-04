// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite_old_init.h"

void EffectSsKirakira_SpawnDispersed(PlayState* play, Vec3f* pos, Vec3f* velocity, Vec3f* accel, Color_RGBA8* primColor,
                                     Color_RGBA8* envColor, s16 scale, s32 life) {
    EffectSsKirakiraInitParams initParams;

    Math_Vec3f_Copy(&initParams.pos, pos);
    Math_Vec3f_Copy(&initParams.velocity, velocity);
    initParams.velocity.y = ((Rand_ZeroOne() * initParams.velocity.y) + initParams.velocity.y) / 2.0f;
    Math_Vec3f_Copy(&initParams.accel, accel);
    initParams.accel.y = ((Rand_ZeroOne() * initParams.accel.y) + initParams.accel.y) / 2.0f;
    initParams.life = life;
    initParams.updateMode = 0;
    initParams.rotSpeed = 0x1518;
    initParams.yaw = Rand_ZeroOne() * 0x4000;
    initParams.scale = scale;
    initParams.primColor = *primColor;
    initParams.envColor = *envColor;
    initParams.alphaStep = (-(255.0f / initParams.life)) + (-(255.0f / initParams.life));

    EffectSs_Spawn(play, EFFECT_SS_KIRAKIRA, 128, &initParams);
}
