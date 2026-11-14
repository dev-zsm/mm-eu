// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_8000244C(EnTrt* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (this->cutsceneState == ENTRT_CUTSCENESTATE_STOPPED) {
        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCsAndSetFlag(this->csId, &this->actor);
            player->stateFlags2 |= PLAYER_STATE2_20000000;
            this->actionFunc = EnTrt_ContinueShopping;
            this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
        } else {
            if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
                CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            }
            this->csId = this->lookToShopkeeperCsId;
            CutsceneManager_Queue(this->csId);
        }
    }
    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        switch (this->textId) {
            case 0x889:
                this->textId = 0x88A;
                break;

            case 0x881:
                this->textId = 0x88C;
                break;

            case 0x838:
            case 0x83C:
            case 0x88E:
            case 0x88F:
                this->textId = 0x83A;
                break;

            default:
                this->textId = 0x849;


        }
        Message_ContinueTextbox(play, this->textId);
    } else {
        Actor_OfferTalkExchangeEquiCylinder(&this->actor, play, 400.0f, PLAYER_IA_MINUS1);
    }
}
