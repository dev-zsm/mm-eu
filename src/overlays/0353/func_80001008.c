// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0353.h"

extern M2C_UNK D_80A47590;

void func_80001008(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x3A8) = 0;
    M2C_FIELD(thisx, M2C_UNK **, 0x18C) = &D_80A47590;
}
