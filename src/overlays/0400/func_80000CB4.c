// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80AA80F0;

void func_80000CB4(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x192) = 0xC;
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80AA80F0;
}
