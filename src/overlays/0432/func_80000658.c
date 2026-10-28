// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000658(void) {
    if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF19) & 4) && (((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 3)) {
        if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF19) & 8) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF47) & 0x40)) {
            return 0x15;
        }
        return 0x13;
    }
    return 0;
}
