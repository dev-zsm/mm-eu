// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80102484(s32, s32, s32, s32);          /* extern */

void func_80000304(u8 *arg0, s32 arg1) {
    func_80102484(arg1, arg1 + 0x818, M2C_FIELD(arg0, s32 *, 0x2FC), arg1);
}
