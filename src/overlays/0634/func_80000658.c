// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BF8D3C;

void func_80000658(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80BF8D3C;
}
