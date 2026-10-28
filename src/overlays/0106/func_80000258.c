// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000258(u8 *arg0, s32 arg1) {
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg1 != M2C_FIELD(arg0, u8 *, 0x149)) {
        M2C_FIELD(arg0, u8 *, 0x149) = arg1;
        if (arg1 == 1) {
            temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
            M2C_FIELD(temp_v0, s16 *, 0x1C) = (s16) (M2C_FIELD(temp_v0, s16 *, 0x1C) + 1);
            return;
        }
        temp_v0_2 = M2C_FIELD(arg0, u8 **, 0x120);
        M2C_FIELD(temp_v0_2, s16 *, 0x1C) = (s16) (M2C_FIELD(temp_v0_2, s16 *, 0x1C) - 1);
    }
}
