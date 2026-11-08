// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0506.h"

extern M2C_UNK D_80B55F6C;

void func_80000968(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x228) = &D_80B55F6C;
}
