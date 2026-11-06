// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B958C(DoorWarp1* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    ref_func_808BB8D4(this, play, 1);

    if (this->unk_1CA > 100) {
        if (player->actor.velocity.y < 10.0f) {
            player->actor.gravity = 0.1f;
        } else {
            player->actor.gravity = 0.0f;
        }
    } else {
        this->unk_1CA++;
    }

    this->unk_1D0++;
    if ((this->unk_1D0 > 120) && (gSaveContext.nextCutsceneIndex == 0xFFEF)) {
        ref_func_808BA10C(this, play);
        play->transitionType = TRANS_TYPE_FADE_WHITE;
        gSaveContext.nextTransitionType = TRANS_TYPE_FADE_WHITE;
    }

    Math_SmoothStepToF(&this->unk_1A8, 6.0f, 0.2f, 0.02f, 0.01f);
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_LINK_WARP - SFX_FLAG);
}
