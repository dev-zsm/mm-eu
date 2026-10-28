// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AC3D80;

void func_800004AC(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80AC3D80;
}
