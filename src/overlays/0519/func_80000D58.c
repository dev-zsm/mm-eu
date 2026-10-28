// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

void func_80000D58(u8 *arg0, s16 arg1, s16 arg2) {
    M2C_FIELD(arg0, s16 *, 0x328) = arg1;
    M2C_FIELD(arg0, s16 *, 0x32E) = arg2;
    if (M2C_FIELD(arg0, s16 *, 0x328) == 0) {
        M2C_FIELD(arg0, s16 *, 0x32A) = 0;
    }
}
