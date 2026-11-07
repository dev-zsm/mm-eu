// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_lastday.h"

void ref_func_80BEBD0C(EffLastday* this, PlayState* play) {
    u16 cueId;

    if ((Cutscene_IsCueInChannel(play, this->cueType))) {
        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, this->cueType));
        cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;
        switch (cueId) {
            case EFFLASTDAY_ACTION_2:
                this->actor.draw = NULL;
                this->actor.draw = EffLastday_Draw;
                if (this->alpha < 255) {
                    this->alpha += 10;
                }
                if (this->alpha > 255) {
                    this->alpha = 255;
                }
                this->step++;
                break;

            case EFFLASTDAY_ACTION_3:
                this->actor.draw = EffLastday_Draw;
                break;

            default:
                this->actor.draw = NULL;
                this->alpha = 0;
                this->step = 0;
                break;
        }
    } else {
        this->actor.draw = NULL;
    }
}
