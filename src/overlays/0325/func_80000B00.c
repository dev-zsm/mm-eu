// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800FEC70(u8 *, s16, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80A21D74(u8 *);                      /* extern */

void func_80000B00(u8 *arg0, M2C_UNK arg1) {
    if (func_800FEC70(arg0 + 0x3C0, M2C_FIELD(arg0, s16 *, 0x3C2), 0x6E, arg0) != 0) {
        func_80A21D74(arg0);
    }
}
