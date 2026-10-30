// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_cont.h"

void __osPackReadData(void) {
    u8 *ptr;
    __OSContReadFormat readFormat;
    s32 i;

    ptr = (u8 *)D_8009D2A0.ramarray;
    for (i = 0; i < 15; i++) {
        D_8009D2A0.ramarray[i] = 0;
    }
    D_8009D2A0.pifstatus = 1;
    readFormat.dummy = 0xFF;
    readFormat.txsize = 1;
    readFormat.rxsize = 4;
    readFormat.cmd = CONT_CMD_READ_BUTTON;
    readFormat.button = 0xFFFF;
    readFormat.stick_x = -1;
    readFormat.stick_y = -1;
    for (i = 0; i < D_8009D2E1; i++) {
        *(__OSContReadFormat *)ptr = readFormat;
        ptr += sizeof(__OSContReadFormat);
    }
    *ptr = CONT_CMD_END;
}
