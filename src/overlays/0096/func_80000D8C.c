// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B921C(DoorWarp1* this, PlayState* play) {
    if (this->unk_1D0 != 0) {
        this->unk_1D0--;
        return;
    }

    Math_SmoothStepToF(&this->unk_1A8, 1.0f, 0.2f, 0.05f, 0.01f);
    this->unk_203 = (u8)(this->unk_1A8 * 200.0f);
    if (this->unk_1A8 > 0.8f) {
        ref_func_808BB8D4(this, play, 1);
    }

    if (ref_func_808B866C(this, play) && !Play_InCsMode(play)) {
        Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_WAIT);
        Message_StartTextbox(play, 0xF2, &this->dyna.actor);
        DoorWarp1_SetupAction(this, ref_func_808B93A0);
    }

    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BOSS_WARP_HOLE - SFX_FLAG);
}
