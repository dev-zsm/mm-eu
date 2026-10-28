// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B5B20(M2C_UNK, u8, u8 *, M2C_UNK);    /* extern */
extern M2C_UNK D_808B76C4;

void func_80000480(u8 *arg0, M2C_UNK arg1) {
    if (func_800B5B20(arg1, M2C_FIELD(arg0, u8 *, 0x15D), arg0, arg1) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_808B76C4;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = NULL;
}
