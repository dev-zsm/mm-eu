// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_80BEFA74(u8 *);                      /* extern */

void func_80000550(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, s16 *, 0x1C) & 0x7F, arg1) != 0) {
        func_80BEFA74(arg0);
    }
}
