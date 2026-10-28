// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000DC8(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, f32 *, 0x1E0) = 100.0f;
    M2C_FIELD(arg0, f32 *, 0x1DC) = 13.0f;
}
