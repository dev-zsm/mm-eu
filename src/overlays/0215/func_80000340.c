// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000340(s32 arg0, M2C_UNK arg1, u8 *arg2) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 temp_v1;

    temp_v0 = M2C_FIELD(arg2, s16 *, 0x4A);
    temp_v1 = M2C_FIELD(arg2, s16 *, 0x4C);
    if (temp_v0 < temp_v1) {
        M2C_FIELD(arg2, s16 *, 0x4A) = (s16) (temp_v0 + 4);
        M2C_FIELD(arg2, s16 *, 0x48) = (s16) (M2C_FIELD(arg2, s16 *, 0x48) + 4);
        if (temp_v1 < M2C_FIELD(arg2, s16 *, 0x4A)) {
            M2C_FIELD(arg2, s16 *, 0x4A) = temp_v1;
            if (M2C_FIELD(arg2, s16 *, 0x46) != 3) {
                M2C_FIELD(arg2, s16 *, 0x48) = temp_v1;
            }
        }
    } else {
        temp_v0_2 = M2C_FIELD(arg2, s16 *, 0x40);
        if (temp_v0_2 > 0) {
            M2C_FIELD(arg2, s16 *, 0x40) = (s16) (temp_v0_2 - 0xA);
            if (M2C_FIELD(arg2, s16 *, 0x40) <= 0) {
                M2C_FIELD(arg2, s16 *, 0x40) = 0;
                M2C_FIELD(arg2, s16 *, 0x5C) = 0;
            }
        }
    }
    if (M2C_FIELD(arg2, s16 *, 0x46) == 3) {
        M2C_FIELD(arg2, s16 *, 0x48) = (s16) (M2C_FIELD(arg2, s16 *, 0x48) + 1);
    }
}
