// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9D0B4(BgHakuginPost* this, PlayState* play) {
    f32 sp24 = (this->unk_164 + this->unk_160) - ref_func_80A9B2B8(&ref_D_80A9E028);
    f32 temp_f14 = Math_SinS((this->unk_16C - sp24) * 0x8000 / (this->unk_168 - sp24)) * 140.0f + 4.0f;

    temp_f14 = CLAMP_MAX(temp_f14, 40.0f);
    this->unk_16C -= temp_f14;
    if (this->unk_16C <= sp24) {
        ref_func_80A9C634(this, play);
        ref_func_80A9B160(&ref_D_80A9E028, play);
        this->unk_16C = this->unk_164;
        BgHakuginPost_RequestQuakeAndRumble(this, play);
        Audio_PlaySfx_2(NA_SE_EV_STONEDOOR_STOP);
        ref_func_80A9CC84(this);
    } else {
        Actor_PlaySfx_FlaggedCentered2(&this->dyna.actor, NA_SE_EV_ICE_PILLAR_FALL - SFX_FLAG);
    }
}
