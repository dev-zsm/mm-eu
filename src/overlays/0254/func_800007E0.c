// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

void ref_func_809A3BC0(ObjPzlblock* this, PlayState* play) {
    if (Math_StepToF(this->unk_164, this->unk_168, 2.3f)) {
        Player* player = GET_PLAYER(play);
        s32 params = OBJPZLBLOCK_GET_ROTZ(&this->dyna.actor);
        s32 pad;
        s32 sp20 = 0;

        if ((params == 4) || (params == 5) || (params == 6)) {
            if (!ref_func_809A35EC(this, this->unk_16C) || ref_func_809A33E0(this, play, 0x5A)) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
            }
        } else if (ref_func_809A35EC(this, this->unk_16C)) {
            if (ref_func_809A33E0(this, play, 0x5A)) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
            }
        } else {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
            Flags_SetSwitch(play, OBJPZLBLOCK_GET_SWITCH_FLAG(&this->dyna.actor));
            sp20 = 1;
        }

        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
        if (sp20 == 0) {
            ref_func_809A3A48(this);
        } else {
            ref_func_809A3D1C(this);
        }
    } else {
        Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_ROCK_SLIDE - SFX_FLAG);
    }
}
