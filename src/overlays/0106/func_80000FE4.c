// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80100248(u8 *, s32, M2C_UNK, u8 *); /* extern */

void func_80000FE4(u8 *arg0, M2C_UNK arg1) {
    func_80100248(arg0 + 0x24, M2C_FIELD(arg0, s32 *, 0x120) + 0x3C, 0x40A00000, arg0);
}
