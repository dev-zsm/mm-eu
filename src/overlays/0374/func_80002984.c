// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80002984(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x3CC);
    var_v1 = 0;
    if (temp_v0 != 4) {
        if ((temp_v0 != 5) && (temp_v0 != 0xC)) {
            if (temp_v0 == 0x5A) {
                var_v1 = 0x10F2;
            }
        } else {
            var_v1 = 0x1106;
        }
    } else {
        var_v1 = 0x1109;
    }
    M2C_FIELD(arg0, u16 *, 0x374) = (u16) (M2C_FIELD(arg0, u16 *, 0x374) | 0x20);
    return var_v1;
}
