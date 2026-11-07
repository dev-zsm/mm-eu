// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

void BgDblueBalance_Update(Actor* thisx, PlayState* play) {
    BgDblueBalance* this = (BgDblueBalance*)thisx;

    this->unk_17A = this->unk_178;

    this->actionFunc(this, play);

    ref_func_80B828E4(this, play);
}
