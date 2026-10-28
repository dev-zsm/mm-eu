// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000D08(u8 *arg0, u8 *arg1) {
    if ((M2C_FIELD(arg0, s8 *, 0x1AE) == 0) && (M2C_FIELD(arg0, s8 *, 0x1AF) != M2C_FIELD(arg1, s8 *, 0x186E0))) {
        M2C_FIELD(arg0, s8 *, 0x1AE) = 1;
    }
}
