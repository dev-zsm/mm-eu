// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u32 D_801E7DB4;

s8 func_80000000(s16 arg0, s16 arg1) {
    s8 var_v1;

    if ((arg0 == 0) || ((arg0 != 1) && (arg0 != 2) && (arg0 == 3))) {
        var_v1 = 0;
    } else {
        var_v1 = ((u32) D_801E7DB4 >> (arg1 * 3)) & 7;
    }
    return var_v1;
}
