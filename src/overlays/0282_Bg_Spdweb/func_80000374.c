// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void ref_func_809CE234(BgSpdweb* this, PlayState* play) {
    Vec3f spB4;
    Vec3f spA8;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    s16 phi_s2;
    s16 temp_s0;
    s32 i;

    if (this->unk_162 != 0) {
        this->unk_162--;
    }

    if (this->unk_162 == 0) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if ((this->unk_162 % 3) == 0) {
        phi_s2 = Rand_ZeroOne() * 10922.0f;
        spB4.y = 0.0f;
        spA8.y = this->dyna.actor.world.pos.y;

        for (i = 0; i < 6; i++) {
            temp_s0 = (s32)Rand_CenteredFloat(0x2800) + phi_s2;
            temp_f24 = Math_SinS(temp_s0);
            temp_f22 = Math_CosS(temp_s0);

            spA8.x = this->dyna.actor.world.pos.x + (120.0f * temp_f24);
            spA8.z = this->dyna.actor.world.pos.z + (120.0f * temp_f22);

            temp_f20 = Math_Vec3f_DistXZ(&this->dyna.actor.home.pos, &spA8) * (1.0f / 120.0f);
            if (temp_f20 < 0.7f) {
                temp_f20 = 1.0f - temp_f20;
                temp_f24 = Math_SinS(BINANG_ROT180(temp_s0));
                temp_f22 = Math_CosS(BINANG_ROT180(temp_s0));
            }

            spB4.x = 7.0f * temp_f24 * temp_f20;
            spB4.y = 0.0f;
            spB4.z = 7.0f * temp_f22 * temp_f20;

            EffectSsDeadDb_Spawn(play, &this->dyna.actor.home.pos, &spB4, &gZeroVec3f, &ref_D_809CF208, &ref_D_809CF20C, 0x32,
                                 8, 0xE);
            phi_s2 += 0x2AAA;
        }

        SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.home.pos, 11, NA_SE_EN_EXTINCT);
    }
}
