// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

void EnKujiya_Wait(EnKujiya* this, PlayState* play) {
    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        if ((CURRENT_TIME >= CLOCK_TIME(6, 0)) && (CURRENT_TIME < CLOCK_TIME(18, 0))) {
            if (EnKujiya_CheckBoughtTicket()) {
                Message_StartTextbox(play, 0x2B61, &this->actor);
                this->textId = 0x2B61; 
            } else {
                Message_StartTextbox(play, 0x2B5C, &this->actor);
                this->textId = 0x2B5C; 
            }
        } else if (EnKujiya_CheckBoughtTicket()) {
            Message_StartTextbox(play, 0x2B64, &this->actor);
            this->textId = 0x2B64; 
        } else {
            Message_StartTextbox(play, 0x2B63, &this->actor);
            this->textId = 0x2B63; 
        }

        EnKujiya_SetupTalk(this);
    } else if ((CURRENT_TIME >= CLOCK_TIME(18, 0)) && EnKujiya_CheckBoughtTicket() && (this->actor.shape.rot.y == 0)) {
        EnKujiya_SetupTurnToOpen(this);
    } else if (this->actor.xzDistToPlayer < 100.0f) {
        Actor_OfferTalk(&this->actor, play, 100.0f);
    }
}
