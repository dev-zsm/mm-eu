// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80000FDC(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);
    u8 cursorIndex;

    if (this->cutsceneState == ENTRT_CUTSCENESTATE_WAITING) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCsAndSetFlag(this->csId, &this->actor);
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
        } else {
            CutsceneManager_Queue(this->csId);
        }
    }
    if (this->cutsceneState == ENTRT_CUTSCENESTATE_STOPPED) {
        if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
            CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
        }
        this->csId = this->lookForwardCutscene;
        CutsceneManager_Queue(this->csId);
        this->cutsceneState = ENTRT_CUTSCENESTATE_WAITING;
    } else if (talkState == TEXT_STATE_CHOICE) {
        Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
        if (!EnTrt_TestEndInteraction(this, play, CONTROLLER1(&play->state))) {
            if ((!Message_ShouldAdvance(play) || !EnTrt_FacingShopkeeperDialogResult(this, play)) &&
            (this->stickAccumX > 0)) {
                cursorIndex = EnTrt_SetCursorIndexFromNeutral(this, 2);
                if (cursorIndex != CURSOR_INVALID) {
                    this->cursorIndex = cursorIndex;
                    this->actionFunc = EnTrt_LookToShelf;
                    Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
                    this->stickRightPrompt.isEnabled = false;
                    Audio_PlaySfx(NA_SE_SY_CURSOR);
                }
            }
        }
    }
}
