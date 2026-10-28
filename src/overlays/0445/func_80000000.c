// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000000(s32 arg0, u8 *arg1) {
    f32 temp_f0;
    s32 var_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x48);
    var_v1 = 0;
    temp_f0 = M2C_FIELD(temp_v0, f32 *, 0x70);
    if (M2C_FIELD(arg1, f32 *, 0x50) < (temp_f0 * temp_f0)) {
        var_v1 = 1;
    } else {
        M2C_FIELD(temp_v0, s16 *, 0x30) = (s16) M2C_FIELD(arg1, s16 *, 0x54);
        M2C_FIELD(temp_v0, s16 *, 0x32) = (s16) M2C_FIELD(arg1, s16 *, 0x56);
    }
    return var_v1;
}
