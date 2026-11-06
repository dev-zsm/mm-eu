// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_egblock.h"

void EnEgblock_Update(Actor* thisx, PlayState* play) {
    EnEgblock* this = (EnEgblock*)thisx;

    this->actionFunc(this, play);

    DECR(this->timer);

    EnEgblock_UpdateEffects(this, play);
}
