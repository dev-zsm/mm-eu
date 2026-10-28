// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */

void func_80002A5C(u8 *arg0, M2C_UNK arg1) {
    func_800FFCBC(arg0 + 0xBE, (s16) (M2C_FIELD(arg0, s16 *, 0x92) - 0x4000), 5, 0x3E8, 0x64);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
