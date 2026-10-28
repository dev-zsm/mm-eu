// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000C90(u8 *arg0) {
    s8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s8 *, 0x309);
    if (temp_v0 < M2C_FIELD(arg0, s8 *, 0x308)) {
        M2C_FIELD(arg0, s8 *, 0x309) = (s8) (temp_v0 + 1);
    }
}
