// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

u32 func_801244EC();                                /* extern */

s32 func_80000080(void) {
    u32 temp_v0;

    temp_v0 = func_801244EC();
    switch (temp_v0) {
    case 0:
        return 0x29CC;
    case 24:
        return 0x29FC;
    case 22:
    case 23:
        return 0x29FD;
    case 2:
        return 0x2364;
    default:
        return 0x29FE;
    }
}
