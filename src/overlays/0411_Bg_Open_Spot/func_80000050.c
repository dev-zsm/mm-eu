// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_open_spot.h"

void BgOpenSpot_Update(Actor* thisx, PlayState* play) {
    BgOpenSpot* this = (BgOpenSpot*)thisx;
    u32 cueId;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_125)) {
        cueId = play->csCtx.actorCues[Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_125)]->id;
        if (cueId == 1) {
            this->actor.draw = NULL;
        } else if (cueId == 2) {
            this->actor.draw = BgOpenSpot_Draw;
        }
    }
}
