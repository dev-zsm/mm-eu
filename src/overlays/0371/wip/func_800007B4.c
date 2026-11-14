// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_Hello), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_trt.h"

void func_800007B4(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);

    if (this->cutsceneState == ENTRT_CUTSCENESTATE_WAITING) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCsAndSetFlag(this->csId, &this->actor);
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
        } else {
            CutsceneManager_Queue(this->csId);
        }
    }
    if ((talkState == TEXT_STATE_EVENT) && Message_ShouldAdvance(play)) {
        Audio_PlaySfx(NA_SE_SY_MESSAGE_PASS);
        if (!EnTrt_TestEndInteraction(this, play, CONTROLLER1(&play->state))) {
            EnTrt_StartShopping(play, this);
        }
    }
}
