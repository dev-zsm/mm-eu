// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A029FC(u8 *);                      /* extern */
M2C_UNK func_80A02BB4(u8 *);                      /* extern */
s32 func_80A02BE8(u8 *);                          /* extern */
s32 func_80A03378(u8 *, s32, M2C_UNK);            /* extern */
M2C_UNK func_80A03740(u8 *);                      /* extern */

void func_80001284(u8 *arg0, s32 arg1) {
    s32 sp24;

    sp24 = func_80A02BE8(arg0);
    if (func_80A03378(arg0, arg1, 1) != 0) {
        func_80A02BB4(arg0);
        func_80A029FC(arg0);
        M2C_FIELD(arg0, s16 *, 0x4DE) = 0x7D0;
        func_80A03740(arg0);
        return;
    }
    if (sp24 != 0) {
        func_80A02BB4(arg0);
        func_80A029FC(arg0);
        M2C_FIELD(arg0, s16 *, 0x4DE) = 0x78;
        func_80A03740(arg0);
    }
}
