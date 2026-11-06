// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char03.h"

void ref_func_80AAB644(DmChar03* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_136)) {
        s32 cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_136);

        if (play->csCtx.actorCues[cueChannel]->id == 4) {
            this->unk_18E = true;
            this->offset.x = play->csCtx.actorCues[cueChannel]->startPos.x;
            this->offset.y = play->csCtx.actorCues[cueChannel]->startPos.y;
            this->offset.z = play->csCtx.actorCues[cueChannel]->startPos.z;
        }
    }
}
