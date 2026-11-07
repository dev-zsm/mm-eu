// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B841A0(BgDblueWaterfall* this, PlayState* play) {
    Vec3f sp94;
    s32 i;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    s32 temp_s3;
    s32 phi_s2;

    if (this->collider.elem.acElemFlags & ACELEM_HIT) {
        temp_f22 = this->collider.elem.acDmgInfo.hitPos.x;
        temp_f24 = this->collider.elem.acDmgInfo.hitPos.y;
        temp_f26 = this->collider.elem.acDmgInfo.hitPos.z;

        for (i = 0, phi_s2 = 0; i < 10; i++, phi_s2 += 0x1999) {
            temp_s3 = (s32)(Rand_ZeroOne() * 6553.0f) + phi_s2;
            temp_f0 = Rand_ZeroOne();
            temp_f20 = (1.0f - SQ(temp_f0)) * 14.0f;

            sp94.x = (Math_SinS(temp_s3) * temp_f20) + temp_f22;
            sp94.y = ((Rand_ZeroOne() * 20.0f) - 10.0f) + temp_f24;
            sp94.z = (Math_CosS(temp_s3) * temp_f20) + temp_f26;

            EffectSsGSplash_Spawn(play, &sp94, NULL, NULL, 0, 250);
        }

        Actor_PlaySfx(&this->actor, NA_SE_IT_REFLECTION_WATER);
    }
}
