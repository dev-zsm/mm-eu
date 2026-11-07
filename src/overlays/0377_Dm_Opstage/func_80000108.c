// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_opstage.h"

void DmOpstage_HandleCutscene(DmOpstage* this, PlayState* play) {
    s32 cueChannel;

    if (DMOPSTAGE_GET_TYPE(&this->dyna.actor) == DMOPSTAGE_TYPE_GROUND) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_115)) {
            cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_115);
            if (play->csCtx.actorCues[cueChannel]->id == 2) {
                this->dyna.actor.scale.x = 0.075f;
                this->dyna.actor.scale.z = 0.3f;
            } else {
                this->dyna.actor.scale.x = 0.1f;
                this->dyna.actor.scale.z = 0.1f;
            }
            Cutscene_ActorTranslateAndYaw(&this->dyna.actor, play, cueChannel);
        }
    } else if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_116 + DMOPSTAGE_GET_CUE_TYPE_OFFSET(&this->dyna.actor))) {
        Cutscene_ActorTranslateAndYaw(
            &this->dyna.actor, play,
            Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_116 + DMOPSTAGE_GET_CUE_TYPE_OFFSET(&this->dyna.actor)));
    }
}
