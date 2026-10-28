// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000B38(u8 *arg0, s32 arg1) {
    if ((arg1 == 0) || (arg1 == 1)) {
        M2C_FIELD(arg0, u8 **, 0x16C) = (u8 *) (arg0 + 0x24);
    } else {
        M2C_FIELD(arg0, u8 **, 0x16C) = (u8 *) (arg0 + 0x2C);
    }
    M2C_FIELD(arg0, s16 *, 0x170) = arg1;
}
