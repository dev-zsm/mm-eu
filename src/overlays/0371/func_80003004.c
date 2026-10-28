// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80003004(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x3D8);
    if (temp_v0 >= 2) {
        M2C_FIELD(arg0, s16 *, 0x3D8) = 2;
        return;
    }
    M2C_FIELD(arg0, s16 *, 0x3D8) = (s16) (temp_v0 + 1);
}
