// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flags) {
    register OSIntMask saveMask;
    register OSThread *thread;

    saveMask = __osDisableInt();
    while (mq->validCount == 0) {
        if (flags == OS_MESG_NOBLOCK) {
            __osRestoreInt(saveMask);
            return -1;
        }
        D_80098010->state = OS_STATE_WAITING;
        func_800892E4(&mq->mtqueue);
    }
    if (msg != NULL) {
        *msg = mq->msg[mq->first];
    }
    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;
    if (mq->fullqueue->next != NULL) {
        thread = func_8008942C(&mq->fullqueue);
        osStartThread(thread);
    }
    __osRestoreInt(saveMask);
    return 0;
}
