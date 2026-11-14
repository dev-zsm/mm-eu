// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kakasi.h"

void func_800006E4(EnKakasi* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if ((gSaveContext.respawnFlag != -4) && (gSaveContext.respawnFlag != -8)) {
        if ((CURRENT_TIME != CLOCK_TIME(6, 0)) && (CURRENT_TIME != CLOCK_TIME(18, 0)) && !CHECK_EVENTINF(EVENTINF_17)) {

            if (this->picto.actor.textId == 0) {
                
                this->picto.actor.textId = 0x1653;
                CLEAR_WEEKEVENTREG(WEEKEVENTREG_83_01);
                this->talkState = TEXT_STATE_EVENT;
                player->stateFlags1 |= PLAYER_STATE1_20;
                this->picto.actor.flags |= ACTOR_FLAG_TALK_OFFER_AUTO_ACCEPTED;
            }

            if (Actor_TalkOfferAccepted(&this->picto.actor, &play->state)) {
                player->stateFlags1 &= ~PLAYER_STATE1_20;
                this->unkState196 = 2;
                this->picto.actor.flags &= ~ACTOR_FLAG_TALK_OFFER_AUTO_ACCEPTED;
                this->actionFunc = EnKakasi_RegularDialogue;
            } else {
                Actor_OfferTalkExchange(&this->picto.actor, play, 9999.9f, 9999.9f, PLAYER_IA_MINUS1);
            }
        }
    }
}
