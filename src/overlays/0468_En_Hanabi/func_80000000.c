// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B22C00(EnHanabiStruct* arg0) {
    s32 i;

    for (i = 0; i < 400; i++, arg0++) {
        arg0->unk_00 = 0;
    }
}
