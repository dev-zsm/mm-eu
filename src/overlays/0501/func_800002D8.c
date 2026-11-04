// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_haka_curtain.h"

void BgHakaCurtain_Update(Actor* thisx, PlayState* play) {
    BgHakaCurtain* this = (BgHakaCurtain*)thisx;
    CsCmdActorCue* cue;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_469)) {
        cue = play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_469)];
        if ((cue->startFrame == play->csCtx.curFrame) && (cue->id == 2)) {
            ref_func_80B6DD80(this);
        }
    }
    this->actionFunc(this, play);
}
