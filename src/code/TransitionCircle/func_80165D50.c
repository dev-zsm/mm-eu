// FLAGS: -O2 -g3 -mips2
#include "types.h"

void TransitionCircle_SetType(u8 *arg0, s32 arg1) {
    if (arg1 & 0x80) {
        arg0[0x15] = arg1 & 1;
        return;
    }
    if (arg1 == 1) {
        arg0[0x14] = 1;
        return;
    }
    arg0[0x14] = 0;
}
