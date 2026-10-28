// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8091CFF4;

void func_800017F8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1AC) = 0x33E9;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_8091CFF4;
}
