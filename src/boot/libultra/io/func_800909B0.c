// FLAGS: -O2 -g0 -mips2
#include "os_cont.h"

s32 __osContChannelReset(OSMesgQueue *mq, s32 channels) {
    s32 i;
    s32 ret;
    u8 *ptr;

    ptr = (u8 *)&D_8009E9A0;
    __osSiGetAccess();
    D_8009E9A0.pifstatus = 1;
    for (i = 0; i < channels; i++) {
        *ptr = 0;
        ptr++;
    }

    *ptr = CONT_CMD_CHANNEL_RESET;
    ptr++;
    *ptr = CONT_CMD_END;
    __osSiRawStartDma(OS_WRITE, &D_8009E9A0);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &D_8009E9A0);
    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
    __osSiRelAccess();
    return ret;
}
