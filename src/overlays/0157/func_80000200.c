// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_80922BD8(u8 *);                      /* extern */

void func_80000200(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, ((s16) M2C_FIELD(arg0, s16 *, 0x1C) >> 8) & 0x7F, arg1) != 0) {
        func_80922BD8(arg0);
    }
}
