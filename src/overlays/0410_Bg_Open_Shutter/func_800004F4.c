// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_open_shutter.h"

void BgOpenShutter_Update(Actor* thisx, PlayState* play2) {
    BgOpenShutter* this = (BgOpenShutter*)thisx;
    PlayState* play = play2;
    s32 cueChannel;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_124)) {
        cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_124);
        if (play->csCtx.actorCues[cueChannel]->id == BGOPENSHUTTER_DOOR_OPEN) {
            if (this->actionFunc == ref_func_80ACAD88) {
                Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_SLIDE_DOOR_OPEN);
                this->actionFunc = ref_func_80ACAE5C;
                this->slidingDoor.dyna.actor.velocity.y = 0.0f;
            }
            this->unk_164 = 0;
        } else if (play->csCtx.actorCues[cueChannel]->id == BGOPENSHUTTER_DOOR_CLOSED) {
            if (this->actionFunc == ref_func_80ACAE5C) {
                Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_SLIDE_DOOR_CLOSE);
                this->actionFunc = ref_func_80ACAEF0;
            }
        }
    }
    this->actionFunc(this, play);
}
