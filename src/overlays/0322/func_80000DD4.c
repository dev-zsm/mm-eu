// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A1EE44;

void func_80000DD4(u8 *arg0, M2C_UNK arg1) {
    if (M2C_FIELD(arg0, s16 *, 0x144) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x14C) = &D_80A1EE44;
        M2C_FIELD(arg0, s16 *, 0x144) = 0x1E;
    }
}
