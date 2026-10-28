// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809204D4;

void func_80000DF0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x160) = 6;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809204D4;
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) M2C_FIELD(arg0, f32 *, 0x254);
}
