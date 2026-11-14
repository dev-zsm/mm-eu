// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_TryToGiveRedPotionAfterSurprised), score 0.00 (0 differ, size +0)
#include "generated/mm/z_en_trt.h"

void func_8000225C(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);

    this->blinkFunc = EnTrt_Blink;
    if ((talkState == TEXT_STATE_DONE) && Message_ShouldAdvance(play)) {
        if (Inventory_HasEmptyBottle() || !CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_KOTAKE_BOTTLE)) {
            if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING) {
                CutsceneManager_Stop(this->csId);
                this->cutsceneState = ENTRT_CUTSCENESTATE_STOPPED;
            }
            this->actionFunc = EnTrt_GiveRedPotionForKoume;
        } else {
            this->prevTextId = this->textId;
            this->textId = 0x88E;
            SET_WEEKEVENTREG(WEEKEVENTREG_FAILED_RECEIVED_RED_POTION_FOR_KOUME_SHOP);
            Message_StartTextbox(play, this->textId, &this->actor);
            this->actionFunc = EnTrt_EndConversation;
        }
    }
}
