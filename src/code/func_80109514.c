// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapData_MID_GetType(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 5)) {
        return 0;
    }
    if ((arg0 >= 0x100) && (arg0 < 0x162)) {
        return 1;
    }
    return 2;
}
