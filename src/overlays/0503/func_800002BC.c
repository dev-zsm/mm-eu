// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B53824;

void func_800002BC(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x280) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x27C) = &D_80B53824;
}
