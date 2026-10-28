// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80913980;

void func_80000958(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x222) = 3;
    M2C_FIELD(arg0, s16 *, 0x220) = 0x50;
    M2C_FIELD(arg0, s16 *, 0x224) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80913980;
}
