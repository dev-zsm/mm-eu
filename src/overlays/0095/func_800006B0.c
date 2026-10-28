// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern s32 D_801E6F00;

void func_800006B0(u8 *arg0, M2C_UNK arg1) {
    u8 temp_v0;
    u8 temp_v0_2;

    if (D_801E6F00 != 0) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0x15E);
        if ((s32) temp_v0 < 0xF5) {
            M2C_FIELD(arg0, u8 *, 0x15E) = (u8) (temp_v0 + 0xA);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x15E) = 0xFFU;
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x15E);
    if ((s32) temp_v0_2 >= 0xB) {
        M2C_FIELD(arg0, u8 *, 0x15E) = (u8) (temp_v0_2 - 0xA);
        return;
    }
    M2C_FIELD(arg0, u8 *, 0x15E) = 0U;
}
