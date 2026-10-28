// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800030C0(u8 *arg0) {
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3D6) - 1;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x3D6) = temp_v0;
        return;
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x3D8) + 1;
    if (temp_v0_2 >= 3) {
        M2C_FIELD(arg0, s16 *, 0x3D8) = 1;
        M2C_FIELD(arg0, s16 *, 0x3D6) = 0x14;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x3D8) = temp_v0_2;
    M2C_FIELD(arg0, s16 *, 0x3D6) = 3;
}
