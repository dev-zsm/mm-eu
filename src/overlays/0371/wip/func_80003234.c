// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_TalkToShopkeeper), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_trt.h"

void func_80003234(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);
    Player* player = GET_PLAYER(play);
    PlayerItemAction itemAction;

    if (talkState == TEXT_STATE_EVENT) {
        if (Message_ShouldAdvance(play)) {
            if ((this->talkOptionTextId == 0x845) || (this->talkOptionTextId == 0x882)) {
                Message_ContinueTextbox(play, 0xFF);
            } else {
                EnTrt_StartShopping(play, this);
            }
        }
    } else if (talkState == TEXT_STATE_PAUSE_MENU) {
        itemAction = ref_func_80123810(play);
        if (itemAction > PLAYER_IA_NONE) {
            if (itemAction == PLAYER_IA_BOTTLE_MUSHROOM) {
                if (CHECK_WEEKEVENTREG(WEEKEVENTREG_GAVE_KOTAKE_MUSHROOM)) {
                    player->actor.textId = 0x888;
                } else {
                    player->actor.textId = 0x883;
                }
                this->textId = player->actor.textId;
                player->exchangeItemAction = itemAction;
                this->actionFunc = EnTrt_GetMushroom;
            } else {
                if (this->flags & ENTRT_GIVEN_MUSHROOM) {
                    player->actor.textId = 0x88B;
                } else {
                    player->actor.textId = 0x886;
                }
                this->textId = player->actor.textId;
                this->actionFunc = EnTrt_Goodbye;
            }
            Message_CloseTextbox(play);
        } else if (itemAction <= PLAYER_IA_MINUS1) {
            if (this->flags & ENTRT_GIVEN_MUSHROOM) {
                this->textId = 0x88B;
            } else {
                this->textId = 0x886;
            }
            Message_StartTextbox(play, this->textId, &this->actor);
            this->actionFunc = EnTrt_Goodbye;
        }
    }
}
