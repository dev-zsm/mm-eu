// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0599.h"

extern M2C_UNK D_80BCFB74;

void func_80001298(Actor *thisx) {
    M2C_FIELD(thisx, s16 *, 0x254) = 5;
    M2C_FIELD(thisx, M2C_UNK **, 0x23C) = &D_80BCFB74;
}
