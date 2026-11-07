// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

void EnKujiya_ChooseNextDialogue(EnKujiya* this, PlayState* play) {
    
    if (this->textId == 0x2B65) { 
        if (this->timer != 0) {
            this->timer--;
            return;
        }
    }

    if (Message_ShouldAdvance(play)) {
        switch (this->textId) {
            case 0x2B5C:
                Message_StartTextbox(play, 0x2B5D, &this->actor);
                this->textId = 0x2B5D; 
                break;

            case 0x2B60:
                EnKujiya_SetBoughtTicket();
                Message_CloseTextbox(play);
                EnKujiya_SetupTurnToClosed(this);
                break;

            case 0x2B64:
                EnKujiya_UnsetBoughtTicket();
                this->timer = 20;
                Message_StartTextbox(play, 0x2B65, &this->actor);
                this->textId = 0x2B65; 
                break;

            case 0x2B65:
                if (CHECK_LOTTERY_NUMBERS()) {
                    Message_StartTextbox(play, 0x2B66, &this->actor);
                    this->textId = 0x2B66; 
                } else {
                    Message_StartTextbox(play, 0x2B67, &this->actor);
                    this->textId = 0x2B67; 
                }
                break;

            case 0x2B66:
                Message_CloseTextbox(play);
                EnKujiya_SetupGivePrize(this);
                EnKujiya_GivePrize(this, play);
                break;

            default:
                break;
        }
    }
}
