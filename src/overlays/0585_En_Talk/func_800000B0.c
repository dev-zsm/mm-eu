// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_talk.h"

void ref_func_80BDE090(EnTalk* this, PlayState* play) {
    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        this->actionFunc = ref_func_80BDE058;
        return;
    }

    if (((this->actor.xzDistToPlayer < 40.0f) && Player_IsFacingActor(&this->actor, 0x3000, play)) ||
        this->actor.isLockedOn) {
        Actor_OfferTalk(&this->actor, play, 120.0f);
    }
}
