// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B96FBC;

void func_80001DAC(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x244);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x244) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x244);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x244) = 0x41;
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B96FBC;
    }
}
