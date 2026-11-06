// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

s32 ref_func_80B22F34(EnHanabiStruct* arg0) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 400; i++, arg0++) {
        if (arg0->unk_00 == 1) {
            count++;
        }
    }

    return count;
}
