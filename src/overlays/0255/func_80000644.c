// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8098955C;

void func_80000644(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x190) = &D_8098955C;
    M2C_FIELD(arg0, s16 *, 0x1B0) = 0;
}
