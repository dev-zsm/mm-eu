// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A5B2B4;

void func_80000844(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x1EE) = 0;
    M2C_FIELD(arg0, s16 *, 0x1E4) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + 0x4000);
    M2C_FIELD(arg0, s16 *, 0x1EA) = 2;
    M2C_FIELD(arg0, M2C_UNK **, 0x1C4) = &D_80A5B2B4;
}
