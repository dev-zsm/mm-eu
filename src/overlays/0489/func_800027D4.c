// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800027D4(u8 *arg0) {
    u8 temp_v0;
    u8 temp_v0_2;

    if (M2C_FIELD(arg0, s8 *, 1) >= 0x15) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 2);
        if ((s32) temp_v0 < 0x7D) {
            M2C_FIELD(arg0, u8 *, 2) = (u8) (temp_v0 + 0xA);
            return;
        }
        M2C_FIELD(arg0, u8 *, 2) = 0x87U;
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 2);
    if ((s32) temp_v0_2 >= 0xE) {
        M2C_FIELD(arg0, u8 *, 2) = (u8) (temp_v0_2 - 0xD);
        return;
    }
    M2C_FIELD(arg0, u8 *, 2) = 0U;
}
