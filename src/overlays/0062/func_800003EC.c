// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80867334;
extern M2C_UNK D_808673AC;

void func_800003EC(u8 *arg0, M2C_UNK arg1, s32 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0xC) = &D_80867334;
    M2C_FIELD(arg0, M2C_UNK **, 0x10) = &D_808673AC;
    M2C_FIELD(arg0, s32 *, 0x20) = arg2;
}
