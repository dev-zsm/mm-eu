// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8091A6AC;

void func_800011B4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8091A6AC;
    M2C_FIELD(arg0, s8 *, 3) = -1;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
}
