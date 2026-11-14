// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_StartRedPotionConversation), score 2.00 (2 differ, size +0)
#include "generated/mm/z_en_trt.h"

void func_80000B18(EnTrt* this, PlayState* play) {
    if ((Message_GetState(&play->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(play)) {
        if (this->textId == 0x88F) {
            if (Inventory_HasEmptyBottle() || !CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_KOTAKE_BOTTLE)) {
                if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING) {
                    CutsceneManager_Stop(this->csId);
                    this->cutsceneState = ENTRT_CUTSCENESTATE_STOPPED;
                }
                play->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
                play->msgCtx.stateTimer = 4;
                this->actionFunc = EnTrt_GiveRedPotionForKoume;
            } else {
                this->prevTextId = this->textId;
                this->textId = 0x88E;
                SET_WEEKEVENTREG(WEEKEVENTREG_FAILED_RECEIVED_RED_POTION_FOR_KOUME_SHOP);
                Message_StartTextbox(play, this->textId, &this->actor);
                this->actionFunc = EnTrt_EndConversation;
            }
        } else {
            if (CHECK_WEEKEVENTREG(WEEKEVENTREG_SAVED_KOUME)) {
                this->textId = 0x83D;
                EnTrt_SetupStartShopping(play, this, 0);
            } else if (CHECK_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_RED_POTION_FOR_KOUME)) {
                this->textId = 0x83B;
                if (Inventory_HasItemInBottle(ITEM_POTION_RED)) {
                    EnTrt_SetupStartShopping(play, this, false);
                } else {
                    this->actionFunc = EnTrt_TryToGiveRedPotion;
                }
            } else if (CHECK_WEEKEVENTREG(WEEKEVENTREG_TALKED_KOUME_INJURED)) {
                this->timer = 30;
                this->textId = 0x838;
                this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING_SPECIAL;
                this->actionFunc = EnTrt_Surprised;
                return;
            } else if (CHECK_WEEKEVENTREG(WEEKEVENTREG_TALKED_KOUME_KIOSK_EMPTY)) {
                this->textId = 0x835;
                EnTrt_SetupStartShopping(play, this, false);
            }
            Message_StartTextbox(play, this->textId, &this->actor);
        }
    }
}
