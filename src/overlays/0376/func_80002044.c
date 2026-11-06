// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9CD14(BgHakuginPost* this, PlayState* play) {
    f32 temp_f12 =
        Math_SinS((this->unk_16C - this->unk_164) * 0x8000 / (this->unk_168 - this->unk_164)) * 140.0f + 4.0f;

    temp_f12 = CLAMP_MAX(temp_f12, 40.0f);
    this->unk_16C += temp_f12;
    if (this->unk_168 <= this->unk_16C) {
        BgHakuginPost_RequestQuakeAndRumble(this, play);
        Audio_PlaySfx_2(NA_SE_EV_STONEDOOR_STOP);
        ref_func_80A9CE00(this);
    } else {
        Actor_PlaySfx_FlaggedCentered2(&this->dyna.actor, NA_SE_EV_ICE_PILLAR_RISING - SFX_FLAG);
    }
}
