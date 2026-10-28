// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000178(s32 arg0, M2C_UNK arg1) {
    if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF01) & 0x80) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) & 0x20)) {
        return 0;
    }
    return 1;
}
