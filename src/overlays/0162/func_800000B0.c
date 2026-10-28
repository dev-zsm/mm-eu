// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B7DD4(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800B7E9C(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_800EE0C0(s32, s16);                    /* extern */

void func_800000B0(u8 *arg0, s32 arg1) {
    func_800B7DD4(arg0, arg1, 0);
    func_800B7E9C(arg0, arg1, 0);
    func_800EE0C0(arg1, (s16) (M2C_FIELD(arg0, s16 *, 0x1C) & 0xFF));
}
