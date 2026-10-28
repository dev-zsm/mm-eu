// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A0A7D8;

void func_800029FC(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1A8) = &D_80A0A7D8;
    M2C_FIELD(arg0, s16 *, 0x2A0) = 2;
}
