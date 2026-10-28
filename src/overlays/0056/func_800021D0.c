// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_800021D0(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0xB44) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0xB40) = 0.0f;
}
