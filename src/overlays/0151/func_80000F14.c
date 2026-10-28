// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80917EC8;

void func_80000F14(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0xBD6) = 1;
    M2C_FIELD(arg0, s8 *, 0xBCD) = 1;
    M2C_FIELD(arg0, s16 *, 0xBCA) = 0x64;
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80917EC8;
    M2C_FIELD(arg0, f32 *, 0xBBC) = 4.0f;
}
