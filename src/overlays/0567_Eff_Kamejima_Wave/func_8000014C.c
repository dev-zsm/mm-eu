// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_kamejima_wave.h"

void ref_func_80BCEC6C(EffKamejimaWave* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_480)) {
        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_480));
        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_480)]->id == 2) {
            this->scaleOffset = 0.05f;
            this->actionFunc = ref_func_80BCEBC0;
            this->actor.draw = EffKamejimaWave_Draw;
            sVtxAlpha = 255;
            this->actor.shape.rot.x = 0;
            Actor_PlaySfx(&this->actor, NA_SE_EV_TORTOISE_WAKE_UP);
        }
    } else {
        this->actor.draw = NULL;
    }
}
