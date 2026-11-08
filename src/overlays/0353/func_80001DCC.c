// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0353.h"

extern M2C_UNK D_80A48350;

void func_80001DCC(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x18C) = &D_80A48350;
}
