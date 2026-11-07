// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5BF38(EnKusa2* this, s32 arg1) {
    this->actor.shape.shadowAlpha += (u8)arg1;
    if (this->actor.shape.shadowAlpha > 60) {
        this->actor.shape.shadowAlpha = 60;
    }
}
