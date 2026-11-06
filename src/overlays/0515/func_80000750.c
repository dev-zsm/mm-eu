// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

bool ref_func_80B82B00(s16 arg0, s16 arg1, s16 arg2) {
    if (arg0 < arg1) {
        return (arg0 < arg2 && arg1 >= arg2);
    }
    return (arg0 < arg2 || arg1 >= arg2);
}
