// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BAE6A8;

void func_8000067C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x270) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x254) = &D_80BAE6A8;
}
