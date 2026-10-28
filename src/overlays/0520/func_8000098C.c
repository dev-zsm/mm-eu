// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(u8 *);                          /* extern */
M2C_UNK func_80151DF4(u8 *, M2C_UNK, u8 *);     /* extern */
M2C_UNK func_801A00B8();                            /* extern */
M2C_UNK func_801A00E0();                            /* extern */
M2C_UNK func_80B75BE8(u8 *, M2C_UNK, M2C_UNK);    /* extern */

void func_8000098C(u8 *arg0, u8 *arg1) {
    if (func_80147B34(arg1) != 0) {
        if (M2C_FIELD(arg1, u8 *, 0x1692D) == 0) {
            func_801A00B8();
            func_80B75BE8(arg0, 0, 3);
            func_80151DF4(arg1, 0x3392, arg0);
            M2C_FIELD(arg0, s16 *, 0x322) = 0x3392;
            return;
        }
        func_801A00E0();
        func_80151DF4(arg1, 0x3391, arg0);
        M2C_FIELD(arg0, s16 *, 0x322) = 0x3391;
    }
}
