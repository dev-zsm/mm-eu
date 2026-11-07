// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

s32 ref_func_80B6FEBC(BgKin2Shelf* this, PlayState* play) {
    if (this->unk_164 & 1) {
        return this->unk_167 < 1;
    }

    if (this->unk_164 & 2) {
        return this->unk_166 < 1;
    }

    if (this->unk_164 & 4) {
        return this->unk_167 >= 0;
    }

    if (this->unk_164 & 8) {
        return this->unk_166 >= 0;
    }
    return false;
}
