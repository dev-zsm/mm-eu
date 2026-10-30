// FLAGS: -O2 -g0 -mips2
#include "os_cont.h"

s32 osContStartReadData(OSMesgQueue *mq) {
    s32 ret;

    __osSiGetAccess();
    if (D_8009D2E0 != CONT_CMD_READ_BUTTON) {
        __osPackReadData();
        __osSiRawStartDma(OS_WRITE, &D_8009D2A0);
        osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    }
    ret = __osSiRawStartDma(OS_READ, &D_8009D2A0);
    D_8009D2E0 = CONT_CMD_READ_BUTTON;
    __osSiRelAccess();
    return ret;
}
