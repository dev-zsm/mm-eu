// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

extern M2C_UNK D_80B2FCC4;

void func_800075D0(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x2EC) = &D_80B2FCC4;
}
