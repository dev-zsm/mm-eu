// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809887B4;

void func_80000668(u8 *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_809887B4;
    M2C_FIELD(arg0, s16 *, 0x170) = 0;
    M2C_FIELD(arg0, s16 *, 0x172) = 0;
    M2C_FIELD(arg0, s16 *, 0x174) = 0;
    M2C_FIELD(arg0, s16 *, 0x16E) = 0;
    M2C_FIELD(arg0, s32 *, 0x160) = 4;
}
