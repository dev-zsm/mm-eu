// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

s32 ref_func_808B900C(DoorWarp1* this, PlayState* play) {
    s32 cueChannel;
    u8 ret = false;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_569)) {
        cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_569);

        if (this->cueId != play->csCtx.actorCues[cueChannel]->id) {
            this->cueId = play->csCtx.actorCues[cueChannel]->id;
            if (play->csCtx.actorCues[cueChannel]->id == 2) {
                ret = true;
            }
        }
    }

    return ret;
}
