// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AD5260;

void func_800003A4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80AD5260;
    M2C_FIELD(arg0, f32 *, 0x70) = (f32) M2C_FIELD(arg0, f32 *, 0x160);
}
