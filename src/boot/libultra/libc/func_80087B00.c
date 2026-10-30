// FLAGS: -O2 -g0 -mips2
#include "libultra_libc.h"

void csleep(OSTime cycles) {
    OSMesgQueue mq;
    OSMesg msgBuf[1];
    OSTimer timer;

    osCreateMesgQueue(&mq, msgBuf, 1);
    osSetTimer(&timer, cycles, 0, &mq, NULL);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}
