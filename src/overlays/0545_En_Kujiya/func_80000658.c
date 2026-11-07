// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

void EnKujiya_GivePrize(EnKujiya* this, PlayState* play) {
    if (Actor_HasParent(&this->actor, play)) {
        EnKujiya_SetupFinishGivePrize(this);
    } else {
        Actor_OfferGetItem(&this->actor, play, GI_RUPEE_PURPLE, 500.0f, 100.0f);
    }
}
