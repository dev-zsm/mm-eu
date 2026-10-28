// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137070(u8 *, u8 *);                  /* extern */

s32 func_80000118(u8 *arg0, M2C_UNK arg1) {
    s32 var_v1;
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0x262);
    var_v1 = 0;
    if (temp_v0 < 0) {
        return 0;
    }
    if (temp_v0 >= 0) {
        M2C_FIELD(arg0, f32 *, 0x160) = (f32) M2C_FIELD(arg0, f32 *, 0x3A8);
        var_v1 = func_80137070(arg0 + 0x144, arg0);
    }
    return var_v1;
}
