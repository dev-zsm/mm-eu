// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A074F0;

void func_80001654(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A074F0;
    M2C_FIELD(arg0, s16 *, 0x17A) = 0x28;
}
