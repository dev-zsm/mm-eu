// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809E95C0;

void func_8000FEF8(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809E95C0;
}
