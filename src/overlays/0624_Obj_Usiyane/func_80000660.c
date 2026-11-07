// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_usiyane.h"

void ref_func_80C082E0(ObjUsiyane* this, PlayState* play) {
    CsCmdActorCue* cue;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_552)) {
        this->cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_552);
        cue = play->csCtx.actorCues[this->cueChannel];
        if (this->cueId != cue->id) {
            this->cueId = cue->id;
            if (this->cueId == 2) {
                ref_func_80C07F30(this, play);
                this->actionFunc = ref_func_80C081C8;
            }
        }
    }
}
