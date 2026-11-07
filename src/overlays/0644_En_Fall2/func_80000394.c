// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall2.h"

void EnFall2_HandleCutscene(EnFall2* this, PlayState* play) {
    Keyframe_UpdateFlex(&this->kfSkelAnime);
    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, this->cueType));
        if (this->cueId != play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id) {
            this->cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;
            ref_func_80C1B8B4(this);
        }
        ref_func_80C1B8F0(this);
        if (this->alphaLevel > 0.0f) {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_MOON_LIGHT_PILLAR - SFX_FLAG);
        }
    } else {
        this->actor.draw = NULL;
    }
    ref_func_80C1B724(this->alphaLevel);
}
