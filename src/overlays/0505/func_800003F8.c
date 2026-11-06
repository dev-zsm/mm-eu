// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_kin2_shelf.h"

bool ref_func_80B6FF28(BgKin2Shelf* this, PlayState* play) {
    return (this->unk_165 > 8) && ref_func_80B6FE48(this, play) && ref_func_80B6FEBC(this, play) && !ref_func_80B6FE08(this, play);
}
