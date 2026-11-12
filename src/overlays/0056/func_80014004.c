#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(s32, s32, u8 *);            /* extern */

void func_80014004(u8 *arg0, u8 *arg1) {

    if ((M2C_FIELD(arg0, s8 *, 0x186E0) >= 0) && (M2C_FIELD(arg0, s8 *, 0x186F4) < 0)) {
        func_800FF30C(arg1 + 0x3C0, arg1 + 0x24, arg1);
        M2C_FIELD(arg1, s16 *, 0x3CC) = (s16) M2C_FIELD(arg1, s16 *, 0xBE);
        M2C_FIELD(arg1, s8 *, 0x3CE) = (s8) M2C_FIELD(arg0, s8 *, 0x186E0);
        M2C_FIELD(arg1, s8 *, 0x3CF) = 1;
    }
}
