// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80137C58(u8 *, s32, u8 *);             /* extern */
M2C_UNK func_80AE3868(u8 *);                      /* extern */

void func_800011C8(u8 *arg0, M2C_UNK arg1) {
    if (func_80137C58(arg0 + 0x190, M2C_FIELD(arg0, s32 *, 0x1A0), arg0) != 0) {
        M2C_FIELD(arg0, s8 *, 0xB7) = 8;
        func_80AE3868(arg0);
    }
}
