// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFC68(u8 *, M2C_UNK, M2C_UNK, u8 *); /* extern */
M2C_UNK func_80A5DC00(u8 *, s32);                 /* extern */

void func_80001B44(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) - 0x1D4C);
    func_800FFC68(arg0 + 0x378, 0x3E99999A, 0x3C23D70A, arg0);
    func_800FFC68(arg0 + 0xCC, 0x3E99999A, 0x40400000, arg0);
    if (M2C_FIELD(arg0, s16 *, 0x28A) == 0) {
        func_80A5DC00(arg0, arg1);
    }
}
