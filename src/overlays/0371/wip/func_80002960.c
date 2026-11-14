// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_ContinueShopping), score 2.00 (2 differ, size +1)
#include "generated/mm/z_en_trt.h"

void func_80002960(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);
    Player* player = GET_PLAYER(play);
    EnGirlA* item;

    if (talkState == TEXT_STATE_CHOICE) {
        Interface_SetAButtonDoAction(play, DO_ACTION_DECIDE);
        if (Message_ShouldAdvance(play)) {
            EnTrt_ResetItemPosition(this);
            item = this->items[this->cursorIndex];
            item->restockFunc(play, item);
            if (!EnTrt_TestEndInteraction(this, play, CONTROLLER1(&play->state))) {
                switch (play->msgCtx.choiceIndex) {
                    case 0:
                        Audio_PlaySfx_MessageDecide();
                        player->actor.shape.rot.y = BINANG_ROT180(player->actor.shape.rot.y);
                        player->stateFlags2 |= PLAYER_STATE2_20000000;
                        Message_StartTextbox(play, this->textId, &this->actor);
                        EnTrt_SetupStartShopping(play, this, true);
                        Actor_OfferTalkExchangeEquiCylinder(&this->actor, play, 400.0f, PLAYER_IA_MINUS1);
                        break;

                    case 1:
                    default:
                        Audio_PlaySfx_MessageCancel();
                        EnTrt_EndInteraction(play, this);
                        break;
                }
            }
        }
    } else if (talkState == TEXT_STATE_EVENT) {
        if (Message_ShouldAdvance(play)) {
            EnTrt_ResetItemPosition(this);
            item = this->items[this->cursorIndex];
            item->restockFunc(play, item);
            EnTrt_EndInteraction(play, this);
        }
    }
}
