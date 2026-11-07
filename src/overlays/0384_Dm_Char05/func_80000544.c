// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void ref_func_80AACAE4(DmChar05* this, PlayState* play) {
    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_564)) {
        s32 cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_564);

        if (play->csCtx.actorCues[cueChannel]->id == 2) {
            if (play->csCtx.curFrame == play->csCtx.actorCues[cueChannel]->startFrame) {
                Item_Give(play, ITEM_MASK_COUPLE);
            }
            this->unk_18E = 1;
            this->unk_190.x = play->csCtx.actorCues[cueChannel]->startPos.x;
            this->unk_190.y = play->csCtx.actorCues[cueChannel]->startPos.y;
            this->unk_190.z = play->csCtx.actorCues[cueChannel]->startPos.z;
        } else {
            this->unk_18E = 0;
        }
    }
}
