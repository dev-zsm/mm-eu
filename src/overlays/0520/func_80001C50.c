// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0520.h"

extern M2C_UNK D_80B74EA4;

void func_80001C50(Actor *thisx) {
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80B74EA4;
}
