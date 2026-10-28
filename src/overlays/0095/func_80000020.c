// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000020(s32 arg0, M2C_UNK arg1) {
    if ((M2C_FIELD(&D_801E6EF0, s32 *, 0x18) >= 2) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF0E) & 1)) {
        return 0;
    }
    return 1;
}
