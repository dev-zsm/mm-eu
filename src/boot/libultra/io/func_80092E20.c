// FLAGS: -O2 -g0 -mips2
#include "os_cont.h"

s32 osContSetCh(u8 channels) {
    __osSiGetAccess();
    if (channels >= MAXCONTROLLERS + 1) {
        D_8009D2E1 = MAXCONTROLLERS;
    } else {
        D_8009D2E1 = channels;
    }
    D_8009D2E0 = CONT_CMD_END;
    __osSiRelAccess();
    return 0;
}
