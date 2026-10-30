// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

void __osPfsRequestOneChannel(s32 channel, u8 poll) {
    u8 *ptr;
    __OSContRequestFormatShort requestformat;
    s32 i;

    D_8009D2E0 = CONT_CMD_END;
    D_8009E9A0.pifstatus = 1;
    ptr = (u8 *)&D_8009E9A0;
    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = poll;
    requestformat.typel = 0xFF;
    requestformat.typeh = 0xFF;
    requestformat.status = 0xFF;
    for (i = 0; i < channel; i++) {
        *ptr++ = 0;
    }
    *(__OSContRequestFormatShort *)ptr = requestformat;
    ptr += sizeof(__OSContRequestFormatShort);
    ptr[0] = CONT_CMD_END;
}
