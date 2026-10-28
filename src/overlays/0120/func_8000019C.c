// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808E0DE4;

void func_8000019C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x162) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_808E0DE4;
}
