// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000298(u8 *arg0, u8 *arg1) {
    s32 var_v1;

    if (M2C_FIELD(arg0, u8 *, 0x1D8) == 1) {
        var_v1 = M2C_FIELD(arg0, s32 *, 0x124);
    } else {
        var_v1 = M2C_FIELD(arg1, s32 *, 0x1CCC);
    }
    return var_v1;
}
