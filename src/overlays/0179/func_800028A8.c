// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800DF888(s32, M2C_UNK, u8 *);        /* extern */

void func_800028A8(u8 *arg0, u8 *arg1) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x542);
    if (temp_v0 == 1) {
        func_800DF888(M2C_FIELD(arg1, s32 *, 0x800), 0x4B, arg1);
        M2C_FIELD(arg1, s8 *, 0x1887E) = 0;
        return;
    }
    if (temp_v0 == 2) {
        M2C_FIELD(arg1, s8 *, 0x1887D) = 0;
        func_800DF888(M2C_FIELD(arg1, s32 *, 0x800), 0x4B, arg1);
    }
}
