// FLAGS: -O2 -g3 -mips2
#include "dmamgr.h"

// Runs one transfer and waits for its completion. Returns -1 if the request could not be queued.
s32 DmaMgr_RequestSync(void *ram, u32 vrom, u32 size) {
    DmaRequest req;
    OSMesgQueue queue;
    OSMesg msg[1];
    s32 ret;

    osCreateMesgQueue(&queue, msg, 1);
    ret = DmaMgr_RequestAsync(&req, ram, vrom, size, 0, &queue, NULL);
    if (ret == -1) {
        return ret;
    }
    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    return 0;
}
