// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ladder.h"

void BgLadder_FadeIn(BgLadder* this, PlayState* play) {
    
    this->alpha += 5;
    if (this->alpha >= 255) {
        this->alpha = 255;
        CutsceneManager_Stop(this->dyna.actor.csId);
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        this->dyna.actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED; 
        this->action = BgLadder_DoNothing;
    }
}
