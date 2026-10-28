// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000036C(u8 *arg0, u32 arg1) {
    if (arg1 & 0x80) {
        M2C_FIELD(arg0, s8 *, 0x11) = 0;
        M2C_FIELD(arg0, s8 *, 0x12) = (s8) (arg1 & 1);
        return;
    }
    if (arg1 == 1) {
        M2C_FIELD(arg0, s8 *, 0x10) = 1;
        return;
    }
    M2C_FIELD(arg0, s8 *, 0x10) = 0;
}
