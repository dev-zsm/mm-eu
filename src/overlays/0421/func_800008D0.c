// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80ABB1D4;

void func_800008D0(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x10);
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80ABB1D4;
}
