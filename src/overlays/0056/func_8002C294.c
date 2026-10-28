// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80845C1C;

void func_8002C294(s32 arg0, u8 *arg1, M2C_UNK arg2) {
    M2C_FIELD(arg1, M2C_UNK **, 0x13C) = &D_80845C1C;
}
