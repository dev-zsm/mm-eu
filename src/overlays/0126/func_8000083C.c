// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808F1118;

void func_8000083C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x1EE) = 0x28;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808F1118;
}
