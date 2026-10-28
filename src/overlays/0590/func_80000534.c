// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80000534(u8 *arg0) {
    u8 temp_v1;
    u8 *temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 **, 0x1CCC);
    temp_v1 = M2C_FIELD(temp_v0, u8 *, 0x14B);
    switch (temp_v1) {                              /* irregular */
    case 3:
        return 0;
    case 1:
        return 1;
    case 2:
        return 0;
    case 4:
        if (M2C_FIELD(temp_v0, s32 *, 0xA6C) & 0x800000) {
            return 1;
        }
        return 0;
    default:
        return 0;
    }
}
