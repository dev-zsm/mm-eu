// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80920200;

void func_80000B24(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80920200;
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg0, f32 *, 0x250);
}
