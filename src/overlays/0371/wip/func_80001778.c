// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_SelectItem), score 2.00 (2 differ, size +1)
#include "generated/mm/z_en_trt.h"

void func_80001778(EnTrt* this, PlayState* play) {
    EnGirlA* item = this->items[this->cursorIndex];
    u8 talkState = Message_GetState(&play->msgCtx);

    if (EnTrt_TakeItemOffShelf(this)) {
        if (talkState == TEXT_STATE_CHOICE) {
            Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
            if (!EnTrt_TestCancelOption(this, play, CONTROLLER1(&play->state)) && Message_ShouldAdvance(play)) {
                switch (play->msgCtx.choiceIndex) {
                    case 0:
                        EnTrt_HandleCanBuyItem(play, this);
                        break;

                    case 1:
                        Audio_PlaySfx_MessageCancel();
                        this->actionFunc = this->prevActionFunc;
                        Message_ContinueTextbox(play, EnTrt_GetItemTextId(this));
                        break;

                    default:
                        break;
                }
            }
        } else if ((talkState == TEXT_STATE_EVENT) && Message_ShouldAdvance(play)) {
            if (!Inventory_HasEmptyBottle()) {
                Audio_PlaySfx(NA_SE_SY_ERROR);
                EnTrt_SetupCannotBuy(play, this, 0x846);
            } else {
                if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING) {
                    CutsceneManager_Stop(this->csId);
                    this->cutsceneState = ENTRT_CUTSCENESTATE_STOPPED;
                }
                EnTrt_SetupBuyItemWithFanfare(play, this);
                this->drawCursor = 0;
                this->shopItemSelectedTween = 0.0f;
                item->boughtFunc(play, item);
                SET_WEEKEVENTREG(WEEKEVENTREG_RECEIVED_FREE_BLUE_POTION);
            }
        }
    }
}
