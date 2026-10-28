// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80B29BC0(u8 *, s32);                 /* extern */
M2C_UNK func_80B30240(u8 *);                      /* extern */

void func_80007EB4(u8 *arg0, s32 arg1) {
    func_800FEE3C(arg0 + 0x70, 0x3F000000, 0x3F800000);
    func_80B29BC0(arg0, arg1);
    if (M2C_FIELD(arg0, s8 *, 0x29C) != 0) {
        func_80B30240(arg0);
    }
}
