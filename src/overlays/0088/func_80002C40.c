// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_808AA434;

void func_80002C40(u8 *arg0) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1E2) - 1;
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, s16 *, 0x1E2) = temp_v0;
        return;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x1E4) = &D_808AA434;
}
