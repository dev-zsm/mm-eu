// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK func_80BF92F4;

void func_80000C10(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &func_80BF92F4;
}
