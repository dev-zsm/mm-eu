// FLAGS: -O2 -g0 -mips2
#include "os_cont.h"

s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *data) {
    OSMesg dummy;
    s32 ret;
    OSTime t;
    OSTimer mytimer;
    OSMesgQueue timerMesgQueue;

    if (D_80098030 != 0) {
        return 0;
    }
    D_80098030 = 1;
    t = osGetTime();
    if (t < 0x0165A0BC) { /* 500 ms in OSTime ticks */
        osCreateMesgQueue(&timerMesgQueue, &dummy, 1);
        osSetTimer(&mytimer, 0x0165A0BC - t, 0, &timerMesgQueue, &dummy);
        osRecvMesg(&timerMesgQueue, &dummy, OS_MESG_BLOCK);
    }
    D_8009D2E1 = MAXCONTROLLERS;
    __osPackRequestData(CONT_CMD_REQUEST_STATUS);
    __osSiRawStartDma(OS_WRITE, &D_8009D2A0);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);
    ret = __osSiRawStartDma(OS_READ, &D_8009D2A0);
    osRecvMesg(mq, &dummy, OS_MESG_BLOCK);
    __osContGetInitData(bitpattern, data);
    D_8009D2E0 = CONT_CMD_REQUEST_STATUS;
    __osSiCreateAccessQueue();
    osCreateMesgQueue(&D_8009D308, D_8009D320, 1);
    return ret;
}
