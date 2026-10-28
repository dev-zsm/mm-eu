// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80891994;

void func_800011E8(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, s16 *, 0x252) = 0xA;
    M2C_FIELD(arg0, s16 *, 0x29C) = 1;
    M2C_FIELD(arg0, s16 *, 0x28E) = 1;
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_80891994;
}
