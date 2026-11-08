// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0550.h"

extern M2C_UNK D_80B9BD18;

void func_80000794(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x144) = &D_80B9BD18;
}
