// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A20508;

void func_80000714(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1B6) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x1AC) = &D_80A20508;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
