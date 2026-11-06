// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5BDB0(EnKusa2* this, PlayState* play) {
    s32 pad[2];
    s32 i;
    Vec3f sp50;
    s16 phi_s0;

    sp50.y = this->actor.world.pos.y + this->actor.depthInWater;

    for (phi_s0 = 0, i = 0; i < 4; i++, phi_s0 += 0x4000) {
        sp50.x = this->actor.world.pos.x + (Math_SinS((s32)(Rand_ZeroOne() * 7200.0f) + phi_s0) * 15.0f);
        sp50.z = this->actor.world.pos.z + (Math_CosS((s32)(Rand_ZeroOne() * 7200.0f) + phi_s0) * 15.0f);
        EffectSsGSplash_Spawn(play, &sp50, NULL, NULL, 0, 190);
    }

    sp50.x = this->actor.world.pos.x;
    sp50.z = this->actor.world.pos.z;
    EffectSsGSplash_Spawn(play, &sp50, NULL, NULL, 0, 280);
    EffectSsGRipple_Spawn(play, &sp50, 300, 700, 0);
    SoundSource_PlaySfxAtFixedWorldPos(play, &this->actor.world.pos, 40, NA_SE_EV_DIVE_INTO_WATER_L);
}
