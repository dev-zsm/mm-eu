// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809209F4;

void func_80001320(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809209F4;
}
