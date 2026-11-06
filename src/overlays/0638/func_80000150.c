// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_demo_moonend.h"

void ref_func_80C17B60(DemoMoonend* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, this->cueType)) {
        u16 cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, this->cueType)]->id;

        Cutscene_ActorTranslateAndYaw(&this->actor, play, Cutscene_GetCueChannel(play, this->cueType));
        if (this->cueId != cueId) {
            this->cueId = cueId;
            switch (this->cueId) {
                case 1:
                    this->actor.draw = NULL;
                    break;

                case 2:
                    this->actor.draw = ref_func_80C17FCC;
                    break;

                default:
                    break;
            }
        }
        if (this->cueId == 2) {
            Actor_PlaySfx_Flagged(&this->actor, NA_SE_EV_RAINBOW - SFX_FLAG);
        }
    } else {
        this->actor.draw = NULL;
    }
}
