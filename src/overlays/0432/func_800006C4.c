// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800006C4(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0x12:
        return 0x24;
    case 0x10:
        return 0x25;
    case 0x4D:
        return 0x26;
    case 0x4E:
        return 0x27;
    case 0x4F:
        return 0x28;
    default:
        return 0;
    }
}
