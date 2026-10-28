// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B1C124();                            /* extern */

void func_8000024C(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 temp_v1;
    u8 *temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0xBE);
    temp_v1 = M2C_FIELD(arg0, s16 *, 0x92) - temp_v0;
    if (temp_v1 >= 0x1556) {
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (temp_v0 + 0x2AAA);
    } else if (temp_v1 < -0x1555) {
        M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (temp_v0 - 0x2AAA);
    }
    if (M2C_FIELD(arg0, s16 *, 0x220) == 1) {
        func_80B1C124();
    }
    temp_v0_2 = M2C_FIELD(arg0, u8 **, 0x120);
    if ((temp_v0_2 != NULL) && (M2C_FIELD(temp_v0_2, s16 *, 0) == 0x1EF)) {
        M2C_FIELD(temp_v0_2, u8 *, 0x292) = (u8) M2C_FIELD(arg0, u8 *, 0x114);
    }
}
