// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8091E9E4;

void func_80000B30(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x204) = &D_8091E9E4;
}
