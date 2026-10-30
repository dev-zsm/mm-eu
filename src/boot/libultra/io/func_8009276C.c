// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

void __osPfsRequestData(u8 cmd) {
    u8 *ptr = (u8 *)D_8009E9A0.ramarray;
    __OSContRequestFormat requestformat;
    s32 i;

    D_8009D2E0 = cmd;
    D_8009E9A0.pifstatus = 1;
    requestformat.dummy = 0xFF;
    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = cmd;
    requestformat.typeh = 0xFF;
    requestformat.typel = 0xFF;
    requestformat.status = 0xFF;
    requestformat.dummy1 = 0xFF;
    for (i = 0; i < D_8009D2E1; i++) {
        *(__OSContRequestFormat *)ptr = requestformat;
        ptr += sizeof(__OSContRequestFormat);
    }
    *ptr = CONT_CMD_END;
}
