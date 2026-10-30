// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_cont.h"

void __osPackRequestData(u8 cmd) {
    u8 *ptr;
    __OSContRequestFormat requestHeader;
    s32 i;

    for (i = 0; i < 15; i++) {
        D_8009D2A0.ramarray[i] = 0;
    }
    D_8009D2A0.pifstatus = 1;
    ptr = (u8 *)D_8009D2A0.ramarray;
    requestHeader.dummy = 0xFF;
    requestHeader.txsize = 1;
    requestHeader.rxsize = 3;
    requestHeader.cmd = cmd;
    requestHeader.typeh = 0xFF;
    requestHeader.typel = 0xFF;
    requestHeader.status = 0xFF;
    requestHeader.dummy1 = 0xFF;
    for (i = 0; i < D_8009D2E1; i++) {
        *(__OSContRequestFormat *)ptr = requestHeader;
        ptr += sizeof(__OSContRequestFormat);
    }
    *ptr = CONT_CMD_END;
}
