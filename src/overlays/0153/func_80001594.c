// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8091CD88;

void func_80001594(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_8091CD88;
}
