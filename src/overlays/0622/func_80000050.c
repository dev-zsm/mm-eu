// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_zoraband.h"

void EffZoraband_MikauFadeOut(EffZoraband* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_527)) {
        if ((EFFZORABAND_GET_F(&this->actor) + 2) ==
            play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_527)]->id) {
            this->stateFlags |= 2;
        }
        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_527)]->id == 7) {
            this->actor.draw = NULL;
        } else {
            this->actor.draw = EffZoraband_Draw;
        }
    }
    if ((this->actor.home.rot.z != 0) && (this->actor.draw != NULL)) {
        Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_UFO_LIGHT_BEAM - SFX_FLAG);
    }
    if (this->stateFlags & 2) {
        if (this->alpha < 240) {
            this->alpha += 25;
        } else {
            this->alpha = 255;
        }
    }
}
