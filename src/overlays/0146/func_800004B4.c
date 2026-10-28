// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800004B4(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C) & 7;
    switch (temp_v0) {                              /* irregular */
    case 0:
        return 0x1D1;
    case 1:
        return 0x1D2;
    case 2:
        return 0x1D3;
    case 3:
        return 0x1D4;
    default:
        return 0;
    }
}
