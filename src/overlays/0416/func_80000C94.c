// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0416.h"

extern M2C_UNK D_80AB3D08;

void func_80000C94(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x15C) = &D_80AB3D08;
}
