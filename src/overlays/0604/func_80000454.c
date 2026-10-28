// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000454(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C) & 3;
    switch (temp_v0) {                              /* irregular */
    case 0:
        return 0x35;
    case 1:
        return 0x1D;
    case 2:
        return 0x5C;
    case 3:
        return 0x5D;
    default:
        return 0;
    }
}
