// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF3F4(u8 *, u8 *, u8 *, u8 *); /* extern */

void func_8000022C(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg1, s32 *, 4) = (s32) (M2C_FIELD(arg1, s32 *, 4) | 0x2000);
    M2C_FIELD(arg0, u8 **, 0x1F8) = arg1;
    func_800FF3F4(arg1 + 0x24, arg0 + 0x24, arg0 + 0x1FC, arg1);
}
