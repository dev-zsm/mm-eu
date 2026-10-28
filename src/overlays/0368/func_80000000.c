// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF34C(u8 *, s32, u8 *, s32);    /* extern */

void func_80000000(u8 *arg0, s32 arg1) {
    func_800FF34C(arg0 + 0x24, M2C_FIELD(arg0, s32 *, 0x1B4) + (arg1 * 6), arg0, arg1);
}
