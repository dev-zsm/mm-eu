// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AE2F8C;
extern M2C_UNK D_80AE3380;

void func_800005F4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AE3380;
    M2C_FIELD(arg0, s16 *, 0x148) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80AE2F8C;
}
