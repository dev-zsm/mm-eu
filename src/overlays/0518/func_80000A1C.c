// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */

void func_80000A1C(u8 *arg0, M2C_UNK arg1) {
    func_80137070(arg0 + 0x194);
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 2, 0x1000, 0x200);
}
