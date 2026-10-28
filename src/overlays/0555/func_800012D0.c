// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E0FAC(u8 *, s32, s32);            /* extern */

void func_800012D0(s32 arg0, u8 *arg1) {
    func_800E0FAC(arg1, arg0 + 0x190, arg0);
    M2C_FIELD(arg1, s8 *, 0x16D02) = 3;
}
