// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

s16 ref_func_80A23090(s16 arg0, s16 arg1, s16 arg2) {
    if (arg0 >= 0) {
        if (arg2 < arg0) {
            return arg2;
        } else if (arg0 < arg1) {
            return arg1;
        }
    } else if (arg0 < -arg2) {
        return -arg2;
    } else if (-arg1 < arg0) {
        return -arg1;
    }

    return arg0;
}
