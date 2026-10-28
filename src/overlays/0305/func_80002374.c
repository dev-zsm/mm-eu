// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80002374(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x270) = 0;
    M2C_FIELD(arg0, s16 *, 0x272) = 0;
    M2C_FIELD(arg0, s16 *, 0x274) = 0;
    M2C_FIELD(arg0, s16 *, 0x26E) = 0;
}
