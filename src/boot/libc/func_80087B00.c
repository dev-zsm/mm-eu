// FLAGS: -O2 -g0 -mips2
#include "types.h"

/* osCreateMesgQueue, osSetTimer(timer, countdown, interval, mq, msg), osRecvMesg(mq, msg, OS_MESG_BLOCK) */
void osCreateMesgQueue(void *mq, void *msgBuf, s32 count);
void osSetTimer(void *timer, u64 countdown, u64 interval, void *mq, void *msg);
void osRecvMesg(void *mq, void *msg, s32 flag);

void csleep(u64 x) {
    u8 mq[0x18];
    u32 msgBuf[1];
    u8 timer[0x24];

    osCreateMesgQueue(mq, msgBuf, 1);
    osSetTimer(timer, x, 0, mq, 0);
    osRecvMesg(mq, 0, 1);
}
