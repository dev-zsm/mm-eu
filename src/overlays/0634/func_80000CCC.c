// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0634.h"

extern M2C_UNK D_80BF93B0;

void func_80000CCC(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x1D4) = &D_80BF93B0;
}
