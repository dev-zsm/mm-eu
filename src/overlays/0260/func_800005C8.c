// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_8099017C;

void func_800005C8(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x19C) = &D_8099017C;
}
