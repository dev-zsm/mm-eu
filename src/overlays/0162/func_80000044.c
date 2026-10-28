// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5BE8(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */

void func_80000044(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5BE8(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 8) & 0x1F, arg1) != 0) {
        func_800B6490(arg0);
    }
}
