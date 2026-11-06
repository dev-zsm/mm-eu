// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spdweb.h"

void ref_func_809CE830(BgSpdweb* this, PlayState* play) {
    Vec3f spDC;
    Vec3f spD0;
    Vec3f spC4;
    s32 i;
    s16 temp_s3;
    s16 temp_s0;
    f32 cosF2;
    f32 sinF2;
    f32 cosQ;
    f32 sinQ;
    f32 cosF1;
    f32 sinF1;
    f32 temp_f28;

    if (this->unk_162 != 0) {
        this->unk_162--;
    }

    if (this->unk_162 == 0) {
        if (CutsceneManager_GetLength(this->dyna.actor.csId) == -1) {
            CutsceneManager_Stop(this->dyna.actor.csId);
        }
        Actor_Kill(&this->dyna.actor);
        return;
    }

    if ((this->unk_162 % 3) == 0) {
        temp_s3 = Rand_ZeroOne() * 0x2AAA;
        cosQ = Math_CosS(this->dyna.actor.shape.rot.x);
        sinQ = Math_SinS(this->dyna.actor.shape.rot.x);
        cosF1 = Math_CosS(this->dyna.actor.shape.rot.y);
        sinF1 = Math_SinS(this->dyna.actor.shape.rot.y);

        spC4.x = this->dyna.actor.world.pos.x + 90.0f * sinQ * sinF1;
        spC4.y = this->dyna.actor.world.pos.y + 90.0f * cosQ;
        spC4.z = this->dyna.actor.world.pos.z + 90.0f * sinQ * cosF1;

        for (i = 0; i < 6; i++) {
            temp_s0 = (s32)Rand_CenteredFloat(0x2800) + temp_s3;
            sinF2 = Math_SinS(temp_s0);
            cosF2 = Math_CosS(temp_s0);

            spD0.x = spC4.x + 90.0f * ((cosF1 * sinF2) + (sinQ * sinF1 * cosF2));
            spD0.y = spC4.y + 90.0f * cosQ * cosF2;
            spD0.z = spC4.z + 90.0f * ((sinQ * cosF1 * cosF2) - (sinF1 * sinF2));

            temp_f28 = Math_Vec3f_DistXYZ(&this->dyna.actor.home.pos, &spD0) * (1.0f / 90.0f);
            if (temp_f28 < 0.65f) {
                temp_f28 = 1.0f - temp_f28;
                sinF2 = Math_SinS(BINANG_ROT180(temp_s0));
                cosF2 = Math_CosS(BINANG_ROT180(temp_s0));
            }

            spDC.x = 6.5f * temp_f28 * ((cosF1 * sinF2) + (sinQ * sinF1 * cosF2));
            spDC.y = 6.5f * temp_f28 * cosQ * cosF2;
            spDC.z = 6.5f * temp_f28 * ((sinQ * cosF1 * cosF2) - (sinF1 * sinF2));

            EffectSsDeadDb_Spawn(play, &this->dyna.actor.home.pos, &spDC, &gZeroVec3f, &ref_D_809CF208, &ref_D_809CF20C, 0x3C,
                                 8, 0xE);
            temp_s3 += 0x2AAA;
        }

        SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.home.pos, 11, NA_SE_EN_EXTINCT);
    }
}
