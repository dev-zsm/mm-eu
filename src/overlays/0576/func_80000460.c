// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BBB014;

void func_80000460(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1A8) = &D_80BBB014;
}
