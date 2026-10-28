// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80830B44(s32, u8 *, M2C_UNK (*)(u8 *, s32), M2C_UNK); /* extern */
s32 func_80837E78(s32, u8 *);                     /* extern */
M2C_UNK func_808593D4(s32, u8 *, M2C_UNK);        /* extern */
M2C_UNK func_8085A780(u8 *, s32);                 /* extern */

void func_800265C4(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xAE8);
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0xAE8) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0xAE8);
    }
    if ((var_v1 == 0) && (func_80837E78(arg1, arg0) != 0)) {
        func_808593D4(arg1, arg0, 0);
        func_80830B44(arg1, arg0, func_8085A780, 0);
        func_8085A780(arg0, arg1);
    }
}
