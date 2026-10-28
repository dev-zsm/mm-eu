// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FFCBC(s32, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8098B318(u8 *);                      /* extern */

void func_8000180C(u8 *arg0, M2C_UNK arg1) {
    func_800FFCBC(arg0 + 0x34, 0, 5, 0x3E8, 5);
    if (M2C_FIELD(arg0, u8 *, 0x11C) == 0) {
        func_8098B318(arg0);
    }
}
