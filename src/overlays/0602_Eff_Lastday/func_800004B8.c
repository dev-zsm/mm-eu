// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_lastday.h"

void ref_func_80BEBF78(EffLastday* this, PlayState* play) {
    u16 cueId;

    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, this->cueType));
        cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;
        switch (cueId) {
            case EFFLASTDAY_ACTION_2:
                if (!this->actor.home.rot.z) {
                    this->actor.home.rot.z = true;
                    Actor_PlaySfx(&this->actor, NA_SE_EV_COMING_FIRE);
                }
                this->actor.draw = EffLastday_Draw;
                if (this->alpha < 255) {
                    this->alpha += 5;
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
