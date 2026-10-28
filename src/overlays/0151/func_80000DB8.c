// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80917D64;

void func_80000DB8(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0xBD6) = 2;
    M2C_FIELD(arg0, s16 *, 0xBCA) = 0x14;
    M2C_FIELD(arg0, s16 *, 0xBD2) = 0xFA0;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80917D64;
}
