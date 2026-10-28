// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
s32 func_800CAD00(u8 *);                          /* extern */
M2C_UNK func_8091BA14(u8 *);                      /* extern */
M2C_UNK func_8091BD58(u8 *, s32);                 /* extern */
M2C_UNK func_8091BD98(u8 *);                      /* extern */
M2C_UNK func_8091BDC0(u8 *);                      /* extern */
M2C_UNK func_8091D41C(u8 *);                      /* extern */

void func_80001BB8(u8 *arg0, s32 arg1) {
    func_8091BDC0(arg0);
    if (M2C_FIELD(arg0, s16 *, 0x1D8) == M2C_FIELD(arg0, s16 *, 0x1DA)) {
        func_8091BD58(arg0, arg1);
        func_8091BD98(arg0);
        func_8091D41C(arg0);
    } else if (func_800CAD00(arg0) != 0) {
        func_800B8D94(arg0, 0xCA);
    }
    func_8091BA14(arg0);
}
