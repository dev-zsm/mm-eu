// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(u8 *, s16, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80A03870(u8 *);                      /* extern */
M2C_UNK func_80A039F0(u8 *);                      /* extern */

void func_80001090(u8 *arg0, M2C_UNK arg1) {
    if (func_800FEC70(arg0 + 0x4DA, M2C_FIELD(arg0, s16 *, 0x4DC), 0x6E, arg0) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x49C) == 0) {
            func_80A03870(arg0);
            return;
        }
        func_80A039F0(arg0);
    }
}
