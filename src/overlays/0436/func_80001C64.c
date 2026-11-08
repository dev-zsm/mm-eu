// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0436.h"

extern M2C_UNK D_80AD03C8;

void func_80001C64(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x1D4) = &D_80AD03C8;
}
