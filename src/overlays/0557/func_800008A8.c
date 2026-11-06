// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_block.h"

void ref_func_80BC4228(BgF40Block* this, PlayState* play) {
    if (ref_func_80BC3B00(this)) {
        this->dyna.actor.speed = 20.0f;
        if (this->unk_160 < (this->path->count - 1)) {
            this->unk_164 = this->unk_160 + 1;
        } else {
            this->actionFunc = ref_func_80BC4530;
            CutsceneManager_Stop(this->dyna.actor.csId);
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_IKANA_BLOCK_STOP_C);
        }
    }

    if (ref_func_80BC3D08(this, play, false)) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        this->actionFunc = ref_func_80BC41AC;
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_IKANA_BLOCK_STOP_F);
        return;
    }

    switch (this->unk_168) {
        case 0:
        case 3:
            Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_IKANA_BLOCK_MOVE_X - SFX_FLAG);
            break;

        case 1:
        case 4:
            Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_IKANA_BLOCK_MOVE_Y - SFX_FLAG);
            break;

        case 2:
        case 5:
            Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_IKANA_BLOCK_MOVE_Z - SFX_FLAG);
            break;
    }
}
