// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BBA634;

void func_800001E8(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80BBA634;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) M2C_FIELD(arg0, f32 *, 0xC);
}
