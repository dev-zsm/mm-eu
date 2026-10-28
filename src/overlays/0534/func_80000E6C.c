// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80B811F0(s32, s32, s32, u8 *);           /* extern */
M2C_UNK func_80B81E9C(u8 *, s32);                 /* extern */
M2C_UNK func_80B82270(u8 *, s32);                 /* extern */

void func_80000E6C(u8 *arg0, s32 arg1) {
    if ((M2C_FIELD(arg0, u16 *, 0x172) & 1) || (func_80B811F0(arg1, M2C_FIELD(arg0, s32 *, 0x168), M2C_FIELD(arg0, s32 *, 0x164), arg0) != 0)) {
        func_80B82270(arg0, arg1);
        return;
    }
    M2C_FIELD(arg0, u16 *, 0x172) = (u16) (M2C_FIELD(arg0, u16 *, 0x172) | 2);
    func_80B81E9C(arg0, arg1);
}
