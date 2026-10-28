// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK func_80AA41D8;

void func_800017F4(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &func_80AA41D8;
}
