// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapData_CPID_GetType(s32 arg0) {
    if (arg0 == -1) {
        return 2;
    }
    if (arg0 < 0x3A) {
        return 1;
    }
    if (arg0 >= 0x3A) {
        return 0;
    }
    return 2;
}
