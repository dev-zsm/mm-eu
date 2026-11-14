// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnOsn_Talk), score 3.00 (3 differ, size +1)
#include "generated/mm/z_en_osn.h"

void func_80001170(EnOsn* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);

    if (((talkState == TEXT_STATE_DONE) || (talkState == TEXT_STATE_EVENT)) && Message_ShouldAdvance(play)) {
        if (this->stateFlags & OSN_STATE_END_CONVERSATION) {
            this->stateFlags &= ~OSN_STATE_END_CONVERSATION;
            play->msgCtx.msgMode = MSGMODE_TEXT_CLOSING;
            play->msgCtx.stateTimer = 4;
            this->actionFunc = EnOsn_Idle;
        } else {
            EnOsn_HandleConversation(this, play);
        }
    }
}
