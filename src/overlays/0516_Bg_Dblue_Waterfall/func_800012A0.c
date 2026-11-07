// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B84F20(BgDblueWaterfall* this, PlayState* play) {
    this->unk_19C--;

    if (this->unk_19C > 0) {
        if (this->unk_19C >= 58) {
            ref_func_80B84348(this, play, 100.0f, -100.0f, 4.0f, -6.0f, 370.0f, 100.0f, 0xC);
        }

        if (this->unk_19C < 50) {
            if (this->unk_19E < 250) {
                this->unk_19E += 5;
            } else {
                this->unk_19E = 255;
            }
        }

        if (this->unk_19F >= 6) {
            this->unk_19F -= 5;
        } else {
            this->unk_19F = 0;
        }

        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_ICE_MELT_LEVEL - SFX_FLAG);
    } else {
        if (this->unk_1A3) {
            CutsceneManager_Stop(this->csId);
        }
        ref_func_80B8484C(this, play);
    }
}
