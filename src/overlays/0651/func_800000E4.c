// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0651.h"

extern M2C_UNK D_80C03878;

void func_800000E4(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80C03878;
}
