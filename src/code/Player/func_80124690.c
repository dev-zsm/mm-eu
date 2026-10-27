// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Player_BottleFromIA(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg1 - 0x15;
    if ((temp_v0 >= 0) && (temp_v0 < 0x15)) {
        return temp_v0;
    }
    return -1;
}
