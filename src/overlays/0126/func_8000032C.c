// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000032C(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2BC) = 7;
    M2C_FIELD(arg0, s16 *, 0x2BE) = 0x19;
    M2C_FIELD(arg0, s8 *, 0x290) = 0xC;
    M2C_FIELD(arg0, u8 *, 0x28D) = (u8) (M2C_FIELD(arg0, u8 *, 0x28D) | 4);
    M2C_FIELD(arg0, s16 *, 0x272) = 0x19;
}
