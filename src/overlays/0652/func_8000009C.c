// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80C04220;

void func_8000009C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80C04220;
}
