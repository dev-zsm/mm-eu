// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000440(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x2C0) = 0;
    M2C_FIELD(arg0, s16 *, 0x2AE) = 0;
    M2C_FIELD(arg0, s16 *, 0x2B0) = 0;
    M2C_FIELD(arg0, s16 *, 0x2CC) = 0;
    M2C_FIELD(arg0, s16 *, 0x290) = 0;
}
