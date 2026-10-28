// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000032C(u8 *arg0) {
    s16 temp_v0;

    if (M2C_FIELD(arg0, s16 *, 0x336) == 1) {
        M2C_FIELD(arg0, s32 *, 0x198) = 1;
        return;
    }
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x334);
    if (temp_v0 >= 4) {
        M2C_FIELD(arg0, s16 *, 0x334) = (s16) (temp_v0 - 1);
        return;
    }
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s32 *, 0x198) = 1;
        M2C_FIELD(arg0, s16 *, 0x334) = (s16) (temp_v0 - 1);
        return;
    }
    M2C_FIELD(arg0, s32 *, 0x198) = 0;
    M2C_FIELD(arg0, s16 *, 0x334) = 0x3C;
}
