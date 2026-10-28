// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808AC8AC;

void func_80000850(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1D0) = &D_808AC8AC;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
