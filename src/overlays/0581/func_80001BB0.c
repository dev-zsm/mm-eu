// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BBEC18;

void func_80001BB0(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x31E) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x1D8) = &D_80BBEC18;
}
