// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7DF6;

s32 func_8000016C(void) {
    s32 var_v1;

    var_v1 = 0;
    if (D_801E7DF6 & 0x10) {
        var_v1 = 1;
    }
    if (D_801E7DF6 & 0x20) {
        var_v1 += 1;
    }
    if (D_801E7DF6 & 0x40) {
        var_v1 += 1;
    }
    return var_v1;
}
