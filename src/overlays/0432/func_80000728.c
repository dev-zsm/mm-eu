// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000728(void) {
    if (((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) != 3) {
        if ((((u32) (M2C_FIELD(&D_801E6EF0, s32 *, 0xED4) & 0xFF000000) >> 0x18) != 0) || (((u32) (M2C_FIELD(&D_801E6EF0, s32 *, 0xED4) & 0xFF0000) >> 0x10) != 0)) {
            return 1;
        }
        return 0;
    }
    if ((((u32) (M2C_FIELD(&D_801E6EF0, s32 *, 0xED4) & 0xFF000000) >> 0x18) != 0) || (((u32) (M2C_FIELD(&D_801E6EF0, s32 *, 0xED4) & 0xFF0000) >> 0x10) != 0) || !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF19) & 4)) {
        return 1;
    }
    return 0;
}
