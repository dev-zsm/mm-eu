// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_sekihi.h"

void ref_func_80A450B0(EnSekihi* this, PlayState* play) {
    if (Actor_TalkOfferAccepted(&this->dyna.actor, &play->state)) {
        this->actionFunc = ref_func_80A44F40;
    } else if ((this->dyna.actor.xzDistToPlayer < 100.0f) && Player_IsFacingActor(&this->dyna.actor, 0x2600, play)) {
        Actor_OfferTalk(&this->dyna.actor, play, 120.0f);
    }
}
