// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800007EC(s32 arg0, M2C_UNK arg1, u8 *arg2) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg2, s16 *, 0x5C);
    if (temp_v0 < 0xA) {
        M2C_FIELD(arg2, s16 *, 0x46) = (s16) (M2C_FIELD(arg2, s16 *, 0x46) - 0x14);
        return;
    }
    if (temp_v0 >= 0x2D) {
        if (temp_v0 < 0x55) {
            M2C_FIELD(arg2, s16 *, 0x50) = (s16) (M2C_FIELD(arg2, s16 *, 0x50) + 0xC);
            M2C_FIELD(arg2, s16 *, 0x48) = (s16) (M2C_FIELD(arg2, s16 *, 0x48) - M2C_FIELD(arg2, s16 *, 0x4A));
            return;
        }
        M2C_FIELD(arg2, s16 *, 0x50) = 0x3E8;
    }
}
