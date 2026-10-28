// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B036A0;

void func_80000AA8(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2C8) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2C0) = &D_80B036A0;
}
