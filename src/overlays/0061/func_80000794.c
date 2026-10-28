// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_800FEC70(u8 *, s16, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_800FEDB4(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_80866240;

void func_80000794(u8 *arg0, M2C_UNK arg1) {
    s32 var_v0;
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0x1A7);
    if (temp_v0 != 0) {
        if (temp_v0 >= 0) {
            var_v0 = 1;
        } else {
            var_v0 = -1;
        }
        if (func_800FEC70(arg0 + 0x32, (s16) (var_v0 * 0x3E80), 0x7D0, arg0) != 0) {
            func_800FEDB4(arg0 + 0x1A7, 0, 1, arg0);
        }
    } else if (func_800FEC70(arg0 + 0x32, 0, 0x7D0, arg0) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x1C8) = &D_80866240;
        func_800B8C4C(arg0, 0x2878);
    }
}
