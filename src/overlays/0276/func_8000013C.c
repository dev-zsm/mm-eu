// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_icicle.h"

void BgIcicle_Break(BgIcicle* this, PlayState* play, f32 arg2) {
    static Vec3f sAccel = { 0.0f, -1.0f, 0.0f };
    static Color_RGBA8 sPrimColor = { 170, 255, 255, 255 };
    static Color_RGBA8 sEnvColor = { 0, 50, 100, 255 };
    Vec3f velocity;
    Vec3f pos;
    s32 j;
    s32 i;

    SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 30, NA_SE_EV_ICE_BROKEN);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 10; j++) {
            pos.x = this->dyna.actor.world.pos.x + Rand_CenteredFloat(8.0f);
            pos.y = this->dyna.actor.world.pos.y + (Rand_ZeroOne() * arg2) + (i * arg2);
            pos.z = this->dyna.actor.world.pos.z + Rand_CenteredFloat(8.0f);

            velocity.x = Rand_CenteredFloat(7.0f);
            velocity.z = Rand_CenteredFloat(7.0f);
            velocity.y = (Rand_ZeroOne() * 4.0f) + 8.0f;

            EffectSsEnIce_Spawn(play, &pos, (Rand_ZeroOne() * 0.2f) + 0.1f, &velocity, &sAccel, &sPrimColor, &sEnvColor,
                                30);
        }
    }
}
