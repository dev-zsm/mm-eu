// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000124(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x120);
    M2C_FIELD(arg0, u8 **, 0x124) = temp_v0;
    M2C_FIELD(temp_v0, u8 **, 0x120) = arg0;
}
