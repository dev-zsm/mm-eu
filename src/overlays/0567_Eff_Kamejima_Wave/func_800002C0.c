// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_kamejima_wave.h"

void ref_func_80BCEDE0(EffKamejimaWave* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_502)) {
        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_502));
        if (play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_502)]->id == 2) {
            this->scaleOffset = 0.03f;
            this->actor.scale.x = 0.35f;
            this->actionFunc = ref_func_80BCED34;
            this->actor.draw = EffKamejimaWave_Draw;
            this->actor.shape.rot.x = 0;
        }
    } else {
        this->actor.draw = NULL;
    }
}
