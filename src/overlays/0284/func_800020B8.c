// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFC68(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_809B57D4(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_809B6BD4(u8 *, s32, M2C_UNK);        /* extern */

void func_800020B8(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x164);
    func_800B8C4C(arg0, 0x301B);
    func_800FFC68(arg0 + 0x70, 0x3F800000, 0x3FC00000);
    if (M2C_FIELD(arg0, s16 *, 0x14E) == 0) {
        func_809B6BD4(arg0, arg1, 0x64);
    }
    M2C_FIELD(arg0, s8 *, 0x1BB) = 0;
    func_809B57D4(arg0, arg1, 1);
}
