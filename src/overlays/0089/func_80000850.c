// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0089.h"

extern M2C_UNK D_808AC8AC;

void func_80000850(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x1D0) = &D_808AC8AC;
    M2C_FIELD(thisx, f32 *, 0x70) = 0.0f;
}
