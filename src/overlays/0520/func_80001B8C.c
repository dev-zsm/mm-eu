// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK func_80B74DE0;

void func_80001B8C(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &func_80B74DE0;
}
