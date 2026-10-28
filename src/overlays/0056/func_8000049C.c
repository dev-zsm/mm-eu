// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_8000049C(u8 *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x1CA0) == 0) {
        M2C_FIELD(arg0, u8 *, 0x1CA0) = 1U;
    }
}
