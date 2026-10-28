// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8018453C(u8 *, u8 *);              /* extern */

void func_80000100(u8 *arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(arg0, s16 *, 0x1C) & 0xF) != 1) {
        func_8018453C(arg0 + 0x144, arg0);
    }
}
