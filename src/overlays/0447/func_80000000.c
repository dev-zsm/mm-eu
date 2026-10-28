// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000000(void) {
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF52) & 1) {
        return 4;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) & 0x40) {
        return 3;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF51) & 8) {
        return 2;
    }
    if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4E) & 1) {
        return 1;
    }
    return 0;
}
