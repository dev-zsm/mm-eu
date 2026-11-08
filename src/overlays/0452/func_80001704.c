// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0452.h"

extern M2C_UNK D_80AE4CEC;

void func_80001704(Actor *thisx) {
    M2C_FIELD(thisx, s32 *, 0x294) = 0;
    M2C_FIELD(thisx, M2C_UNK **, 0x1D4) = &D_80AE4CEC;
}
