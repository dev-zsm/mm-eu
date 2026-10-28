// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80A4C224;

void func_80000F38(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x24C) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80A4C224;
}
