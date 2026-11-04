// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math.h"

f32 Math_FactorialF(f32 n) {
    f32 ret = 1.0f;
    s32 i;

    
    for (i = n; i > 1; i--) {
        ret *= i;
    }
    return ret;
}
