// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000478(u8 *arg0) {
    if (M2C_FIELD(arg0, s16 *, 0x3CC) == 2) {
        if (M2C_FIELD(&D_801E6EF0, s32 *, 0x18) == 1) {
            return 0x64C;
        }
        if (M2C_FIELD(&D_801E6EF0, s32 *, 0x18) == 2) {
            return 0x64D;
        }
        if (M2C_FIELD(&D_801E6EF0, s32 *, 0x10) == 0) {
            return 0x64E;
        }
        return 0x64F;
    }
    return 0x64C;
}
