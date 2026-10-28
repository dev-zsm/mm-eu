// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000228(u8 *arg0) {
    M2C_FIELD(arg0, s8 *, 0x3C0) = 6;
    M2C_FIELD(arg0, u8 *, 0x3BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x3BD) & 0xFFFB);
}
