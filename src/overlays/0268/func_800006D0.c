// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_tag.h"

void EnWarpTag_GrottoReturn(EnWarptag* this, PlayState* play) {
    if (CutsceneManager_GetCurrentCsId() != this->dyna.actor.csId) {
        if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
        } else {
            CutsceneManager_Queue(this->dyna.actor.csId);
        }
    }

    if (this->grottoExitDelay++ == 10) {
        play->nextEntrance = play->setupExitList[WARPTAG_GET_EXIT_INDEX(&this->dyna.actor)];
        Scene_SetExitFade(play);
        play->transitionTrigger = TRANS_TRIGGER_START;
        Audio_PlaySfx_2(NA_SE_OC_SECRET_HOLE_OUT);
        Audio_MuteAllSeqExceptSystemAndOcarina(5);
        gSaveContext.seqId = (u8)NA_BGM_DISABLED;
        gSaveContext.ambienceId = AMBIENCE_ID_DISABLED;
    }
}
