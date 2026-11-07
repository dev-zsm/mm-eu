// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4E190(EnMkk* this) {
    this->unk_14E = (s32)(Rand_ZeroOne() * 20.0f) + 10;
    if (this->unk_149 != 0) {
        this->unk_149--;
    }
    this->actionFunc = ref_func_80A4E1F0;
}
