// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BAA2CC();                            /* extern */

void func_800006B0(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x32C) = (s16) (M2C_FIELD(arg0, s16 *, 0x32C) + 1);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x1000);
    if (M2C_FIELD(arg0, s16 *, 0x32C) == 0x20) {
        func_80BAA2CC();
    }
}
