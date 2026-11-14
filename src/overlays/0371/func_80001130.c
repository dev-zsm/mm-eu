// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80001130(EnTrt* this, PlayState* play) {
    if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING) {
        CutsceneManager_Stop(this->csId);
        this->cutsceneState = ENTRT_CUTSCENESTATE_STOPPED;
    }
    if (this->cutsceneState == ENTRT_CUTSCENESTATE_STOPPED) {
        if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
            CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
        }
        this->csId = this->lookToShelfCsId;
        CutsceneManager_Queue(this->csId);
        this->cutsceneState = ENTRT_CUTSCENESTATE_WAITING;
    } else if (this->cutsceneState == ENTRT_CUTSCENESTATE_WAITING) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCsAndSetFlag(this->csId, &this->actor);
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
            EnTrt_UpdateCursorPos(play, this);
            this->actionFunc = EnTrt_BrowseShelf;
            Message_ContinueTextbox(play, EnTrt_GetItemTextId(this));
        } else {
            CutsceneManager_Queue(this->csId);
        }
    }
}
