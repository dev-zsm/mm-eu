// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80947500;

void func_80001318(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x54A) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80947500;
}
