// FLAGS: -O2 -g0 -mips2
#include "ultra64.h"

s32 osEPiStartDma(OSPiHandle *handle, OSIoMesg *mb, s32 direction) {
    s32 ret;

    if (D_80098060.active == 0) {
        return -1;
    }
    mb->piHandle = handle;
    if (direction == OS_READ) {
        mb->hdr.type = OS_MESG_TYPE_EDMAREAD;
    } else {
        mb->hdr.type = OS_MESG_TYPE_EDMAWRITE;
    }
    if (mb->hdr.pri == OS_MESG_PRI_HIGH) {
        ret = osJamMesg(osPiGetCmdQueue(), mb, OS_MESG_NOBLOCK);
    } else {
        ret = osSendMesg(osPiGetCmdQueue(), mb, OS_MESG_NOBLOCK);
    }
    return ret;
}
