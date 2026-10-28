// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000B64(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x309) = (s8) (M2C_FIELD(arg0, s8 *, 0x309) + 1);
    if (M2C_FIELD(arg0, s8 *, 0x309) >= M2C_FIELD(arg0, s8 *, 0x308)) {
        M2C_FIELD(arg0, s8 *, 0x309) = 0;
    }
}
