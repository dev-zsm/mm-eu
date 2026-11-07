// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall.h"

void EnFall_CrashingMoon_PerformCutsceneActions(EnFall* this, PlayState* play) {
    EnFall_CrashingMoon_HandleGiantsCutscene(this, play);
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133)) {
        if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133) &&
            play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133)]->id == 1) {
            this->actor.draw = NULL;
        } else {
            this->actor.draw = EnFall_Moon_Draw;
            if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_133) &&
                play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133)]->id == 2) {
                Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_133));
            }
        }
    } else {
        this->actor.draw = NULL;
    }
}
