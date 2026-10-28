// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */

void func_800007F0(s32 arg0, M2C_UNK arg1) {
    func_800FFCBC(arg0 + 0x262, 0x2710, 2, 0x1B58, 0x3E8);
    func_800FFCBC(arg0 + 0x260, 0, 2, 0x1B58, 0x3E8);
    func_800FFCBC(arg0 + 0x25E, 0x36B0, 2, 0x1B58, 0x3E8);
}
