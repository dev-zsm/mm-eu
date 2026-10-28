// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEE3C(u8 *, s32, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80AFAF74(u8 *, s32);                 /* extern */

void func_80000E50(u8 *arg0, s32 arg1) {
    if (func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, s32 *, 0xC), 0x40C00000, arg0) != 0) {
        func_80AFAF74(arg0, arg1);
    }
}
