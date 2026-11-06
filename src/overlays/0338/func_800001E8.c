// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ladder.h"

void BgLadder_StartCutscene(BgLadder* this, PlayState* play) {
    
    if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
        CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        this->dyna.actor.draw = BgLadder_Draw;
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_SECRET_LADDER_APPEAR);
        this->action = BgLadder_FadeIn;
    } else {
        CutsceneManager_Queue(this->dyna.actor.csId);
    }
}
