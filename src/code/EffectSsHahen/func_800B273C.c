// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_effect_soft_sprite_old_init.h"

void EffectSsHahen_SpawnBurst(PlayState* play, Vec3f* pos, f32 burstScale, s16 flags, s16 scale, s16 randScaleRange,
                              s16 count, s16 objectId, s16 life, Gfx* dList) {
    s32 i;
    Vec3f velocity;
    Vec3f accel;

    accel.y = -0.07f * burstScale;
    accel.x = accel.z = 0.0f;

    for (i = 0; i < count; i++) {
        velocity.x = (Rand_ZeroOne() - 0.5f) * burstScale;
        velocity.z = (Rand_ZeroOne() - 0.5f) * burstScale;
        velocity.y = ((Rand_ZeroOne() * 0.5f) + 0.5f) * burstScale;

        EffectSsHahen_Spawn(play, pos, &velocity, &accel, flags, Rand_S16Offset(scale, randScaleRange), objectId, life,
                            dList);
    }
}
