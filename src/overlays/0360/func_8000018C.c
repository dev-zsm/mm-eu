// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_8000018C(u8 *arg0) {
    s16 var_v0;

    var_v0 = M2C_FIELD(arg0, s16 *, 0x92) - M2C_FIELD(arg0, s16 *, 0xBE);
    if (var_v0 < 0) {
        var_v0 *= -1;
    }
    if (var_v0 < 0x4000) {
        return 1;
    }
    return 0;
}
