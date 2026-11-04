// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hgdoor.h"

void ObjHgdoor_HandleCutscene(ObjHgdoor* this, PlayState* play) {
    s32 cueChannel;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_483)) {
        cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_483);
        if (this->cueId != play->csCtx.actorCues[cueChannel]->id) {
            this->cueId = play->csCtx.actorCues[cueChannel]->id;
            switch (play->csCtx.actorCues[cueChannel]->id) {
                case 1:
                    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_WOOD_DOOR_OPEN_SPEEDY);
                    if ((this->dyna.actor.parent != NULL) && (this->dyna.actor.parent->id == ACTOR_EN_HG)) {
                        this->dyna.actor.parent->colChkInfo.health = 1;
                    }
                    sOpenFlag = 1;
                    break;

                case 2:
                    break;
            }
        }
        if ((sOpenFlag == 1) && ObjHgdoor_Rotate(this, play)) {
            ObjHgdoor_SetupStopCs(this);
        }
    } else {
        this->cueId = 99;
    }
}
