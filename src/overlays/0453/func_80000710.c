// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000710(u8 *arg0) {
    s16 temp_v0_2;
    s16 temp_v0_3;
    u16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x24C);
    switch (temp_v0) {                              /* irregular */
    case 6:
        if (M2C_FIELD(arg0, f32 *, 0x15C) >= 90.0f) {
            temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x24E);
            if (temp_v0_2 > 0) {
                M2C_FIELD(arg0, s16 *, 0x24E) = (s16) (temp_v0_2 - 0xC);
                return;
            }
        }
        return;
    case 14:
        M2C_FIELD(arg0, s16 *, 0x24E) = (s16) (M2C_FIELD(arg0, s16 *, 0x24E) - 0xC);
        return;
    default:
        temp_v0_3 = M2C_FIELD(arg0, s16 *, 0x24E);
        if (temp_v0_3 < 0xFF) {
            M2C_FIELD(arg0, s16 *, 0x24E) = (s16) (temp_v0_3 + 8);
        }
        break;
    }
}
