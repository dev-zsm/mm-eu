// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B5624C();                            /* extern */

void func_80000C18(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x13C) != 0) {
        M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    }
    if (M2C_FIELD(arg0, s32 *, 0x2E4) == M2C_FIELD(arg0, s32 *, 0x2E0)) {
        func_80B5624C();
    }
}
