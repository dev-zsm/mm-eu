// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BEDA50;

void func_80000204(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x168) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BEDA50;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0xC) + 450.0f);
}
