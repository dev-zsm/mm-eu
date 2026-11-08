// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0653.h"

extern M2C_UNK D_80C05670;

void func_80000BCC(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x228) = &D_80C05670;
}
