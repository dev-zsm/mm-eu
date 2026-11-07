// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

void ref_func_80B7F290(BgIkanaBlock* this, PlayState* play) {
    s32 pad;

    Math_StepToF(&this->unk_16C, 2.0f, 0.4f);

    if (Math_StepToF(this->unk_164, this->unk_168, this->unk_16C)) {
        Player* player = GET_PLAYER(play);

        if (!ref_func_80B7EB94(this, play)) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        }

        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;

        if (ref_func_80B7EDC4(this, play)) {
            ref_func_80B7F0A4(this);
        } else {
            ref_func_80B7F360(this);
        }
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
    }
}
