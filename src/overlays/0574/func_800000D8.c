// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80BBA25C;

void func_800000D8(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x13C) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, M2C_UNK **, 0x194) = &D_80BBA25C;
}
