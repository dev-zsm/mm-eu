// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

void EnKujiya_Talk(EnKujiya* this, PlayState* play) {
    switch (Message_GetState(&play->msgCtx)) {
        case TEXT_STATE_NONE:
            break;

        case TEXT_STATE_CHOICE:
            EnKujiya_HandlePlayerChoice(this, play);
            break;

        case TEXT_STATE_EVENT:
            EnKujiya_ChooseNextDialogue(this, play);
            break;

        case TEXT_STATE_DONE:
            if (Message_ShouldAdvance(play)) {
                EnKujiya_SetupWait(this);
            }
            break;

        case TEXT_STATE_INPUT_LOTTERY_CODE:
            if (Message_ShouldAdvance(play)) {
                Inventory_SaveLotteryCodeGuess(play);
                Message_StartTextbox(play, 0x2B60, &this->actor);
                this->textId = 0x2B60; 
            }
            break;

        default:
            break;
    }
}
