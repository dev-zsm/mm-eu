// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_block.h"

bool ref_func_80B7ECFC(BgIkanaBlock* this, PlayState* play) {
    return ref_func_80B7EB64(this, play) && ref_func_80B7EB7C(this, play) && ref_func_80B7EB94(this, play);
}
