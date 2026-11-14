// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_800002CC(EnTrt* this) {
    if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING) {
        if (this->csId != this->tmpGetMushroomCsId) {
            CutsceneManager_Stop(this->csId);
            if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
                CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            }
            this->csId = this->tmpGetMushroomCsId;
            CutsceneManager_Queue(this->csId);
            this->cutsceneState = ENTRT_CUTSCENESTATE_WAITING;
        }
    }
    if (this->cutsceneState == ENTRT_CUTSCENESTATE_WAITING) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCsAndSetFlag(this->csId, &this->actor);
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING_SPECIAL;
        } else {
            CutsceneManager_Queue(this->csId);
        }
    }
}
