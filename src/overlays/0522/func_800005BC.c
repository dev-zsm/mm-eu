// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_80B77218;

void func_800005BC(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x169) = 0x3C;
    M2C_FIELD(arg0, M2C_UNK **, 0x15C) = &D_80B77218;
}
