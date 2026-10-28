// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

s32 func_80000AA8(u8 *arg0) {
    s16 temp_v0;
    s32 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C);
    var_v1 = 0;
    if (temp_v0 & 0x8000) {
        if (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) & 0x20) {
            goto block_9;
        }
    } else if (temp_v0 & 0x4000) {
        if ((M2C_FIELD(&D_801E6EF0, u8 *, 0xF01) & 0x80) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) & 0x20)) {
            goto block_9;
        }
    } else if (!(M2C_FIELD(&D_801E6EF0, u8 *, 0xF01) & 0x80) && !(M2C_FIELD(&D_801E6EF0, u8 *, 0xF0F) & 0x20)) {
block_9:
        var_v1 = 1;
    }
    return var_v1;
}
