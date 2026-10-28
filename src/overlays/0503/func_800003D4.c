// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B53938;

void func_800003D4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x27C) = &D_80B53938;
}
