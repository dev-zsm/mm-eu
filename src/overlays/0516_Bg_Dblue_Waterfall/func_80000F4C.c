// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_waterfall.h"

void ref_func_80B84BCC(BgDblueWaterfall* this, PlayState* play) {
    s32 pad;

    this->unk_19C--;
    if (this->unk_19C > 0) {
        s32 sp38 = this->unk_19C & 1;

        if (this->unk_19C > 56) {
            ref_func_80B84348(this, play, 0.0f, -5500.0f, 0.4f, -15.0f, 370.0f, 100.0f, 6);
        }

        if (!sp38) {
            if ((this->unk_19C < 24) && (this->unk_19C > 10)) {
                if (this->unk_198 > -32000.0f) {
                    ref_func_80B84348(this, play, (this->unk_198 - this->actor.world.pos.y) + 50.0f,
                                  (this->unk_198 - this->actor.world.pos.y), 7.0f, -1.0f, 280.0f, 100.0f, 3);
                }
            }

            if (this->unk_19C > 50) {
                ref_func_80B84348(this, play, 0.0f, -400.0f, 0.6f, -12.0f, 370.0f, 100.0f, 2);
            } else if (this->unk_19C > 40) {
                ref_func_80B84348(this, play, 0.0f, -400.0f, 1.0f, -12.0f, 370.0f, 100.0f, 2);
            } else if (this->unk_19C > 20) {
                ref_func_80B84348(this, play, 0.0f, -400.0f, 1.8f, -12.0f, 370.0f, 100.0f, 2);
            }
        }

        if (this->unk_19E > 6) {
            this->unk_19E -= 6;
        } else {
            this->unk_19E = 0;
        }

        if (this->unk_19C >= 55) {
            if (this->unk_1A0 < 205) {
                this->unk_1A0 += 50;
            } else {
                this->unk_1A0 = 255;
            }
        } else if (this->unk_19C >= 36) {
            if (this->unk_1A0 >= 16) {
                this->unk_1A0 -= 15;
            } else {
                this->unk_1A0 = 0;
            }
        } else {
            this->unk_1A0 = 0;
        }

        if (this->unk_19C < 60) {
            if (this->unk_19F < 245) {
                this->unk_19F += 10;
            } else {
                this->unk_19F = 255;
            }
        }

        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_ICE_FREEZE - SFX_FLAG);
    } else {
        if (this->unk_1A3) {
            CutsceneManager_Stop(this->csId);
        }
        ref_func_80B8484C(this, play);
    }
}
