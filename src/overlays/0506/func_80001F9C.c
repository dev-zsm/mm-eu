// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_80001F9C(u8 *arg0) {
    s16 var_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
    if (temp_v0 == NULL) {
        var_v1 = M2C_FIELD(arg0, s16 *, 0x3F8);
    } else {
        var_v1 = M2C_FIELD(temp_v0, s16 *, 0x3F8);
    }
    return var_v1;
}
