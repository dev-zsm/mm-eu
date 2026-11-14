// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTsn_Object_Idle), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_tsn.h"

void func_80000FE8(EnTsn* this, PlayState* play) {
    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        this->actionFunc = EnTsn_Object_Talk;
        if ((this->actor.textId == 0x108A) || (this->actor.textId == 0x1091)) {
            this->flags |= ENTSN_CS_QUEUED;
            ENTSN_SET_Z(&this->fisherman->actor, true);
        }
    } else if (this->actor.isLockedOn) {
        Actor_OfferTalk(&this->actor, play, 1000.0f);
    }
}
