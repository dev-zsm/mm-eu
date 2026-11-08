// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0541.h"

extern M2C_UNK D_80B8CAA4;

void func_800028F0(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x1D4) = &D_80B8CAA4;
}
