// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(u8 *, s32);                 /* extern */
M2C_UNK func_800E0FAC(u8 *, s32);                 /* extern */

void func_80000248(u8 *arg0, u8 *arg1) {
    func_800E09D8(arg1, arg0 + 0x190);
    func_800E0FAC(arg1, arg0 + 0x144);
    if (M2C_FIELD(arg0, u8 *, 0x1F9) != 0) {
        M2C_FIELD(arg1, u8 *, 0x1CA5) = (u8) (M2C_FIELD(arg1, u8 *, 0x1CA5) & 0xFFFE);
    }
}
