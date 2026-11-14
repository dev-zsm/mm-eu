// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_GetMushroom), score 4.00 (4 differ, size +2)
#include "generated/mm/z_en_trt.h"

void func_80000870(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);
    Player* player = GET_PLAYER(play);

    this->tmpGetMushroomCsId = this->getMushroomCsId;
    if (this->cutsceneState != ENTRT_CUTSCENESTATE_PLAYING_SPECIAL) {
        EnTrt_SetupGetMushroomCutscene(this);
        if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING_SPECIAL) {
            player->stateFlags2 &= ~PLAYER_STATE2_20000000;
        }
    } else if ((talkState == TEXT_STATE_EVENT) && Message_ShouldAdvance(play)) {
        switch (this->textId) {
            case 0x883:
                this->textId = 0x884;
                Message_StartTextbox(play, this->textId, &this->actor);
                SET_WEEKEVENTREG(WEEKEVENTREG_GAVE_KOTAKE_MUSHROOM);
                Player_UpdateBottleHeld(play, GET_PLAYER(play), ITEM_BOTTLE, PLAYER_IA_BOTTLE_EMPTY);
                break;

            case 0x888:
                this->textId = 0x889;
                Message_StartTextbox(play, this->textId, &this->actor);
                break;

            case 0x889:
                if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING_SPECIAL) {
                    CutsceneManager_Stop(this->csId);
                    this->cutsceneState = ENTRT_CUTSCENESTATE_STOPPED;
                }
                play->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
                play->msgCtx.stateTimer = 4;
                this->actionFunc = EnTrt_PayForMushroom;
                break;

            default:
                this->cutsceneState = ENTRT_CUTSCENESTATE_PLAYING;
                EnTrt_EndInteraction(play, this);
                break;
        }
    }
}
