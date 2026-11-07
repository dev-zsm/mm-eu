// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_zl4.h"

void EnZl4_Update(Actor* thisx, PlayState* play) {
    EnZl4* this = (EnZl4*)thisx;

    SkelAnime_Update(&this->skelAnime);
    this->alpha += 0;
    this->actionFunc(this, play);
}
