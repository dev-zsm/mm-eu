// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_Moon_PerformDefaultActions(EnFall* this, PlayState* play) {
    u16 currentDay;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133)) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133) &&
            play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133)]->id == 1) {
            this->actor.draw = NULL;
        } else {
            Actor_SetScale(&this->actor, this->scale * 3.6f);
            this->actor.draw = EnFall_Moon_Draw;
            if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133) &&
                play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133)]->id == 2) {
                Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133));
            }
        }
    } else {
        if (this->actor.draw == NULL) {
            this->actor.draw = EnFall_Moon_Draw;
        }
        currentDay = CURRENT_DAY;
        if ((u16)this->currentDay != (u32)currentDay) {
            this->currentDay = currentDay;
            this->dayStartTime = CURRENT_TIME;
        }
        EnFall_Moon_AdjustScaleAndPosition(this, play);
    }
}
