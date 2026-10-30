// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flags) {
    register OSIntMask saveMask;
    register OSThread *thread;

    saveMask = __osDisableInt();
    while (mq->validCount >= mq->msgCount) {
        if (flags == OS_MESG_BLOCK) {
            D_80098010->state = OS_STATE_WAITING;
            func_800892E4(&mq->fullqueue);
        } else {
            __osRestoreInt(saveMask);
            return -1;
        }
    }
    mq->first = (mq->first + mq->msgCount - 1) % mq->msgCount;
    mq->msg[mq->first] = msg;
    mq->validCount = mq->validCount + 1;
    if (mq->mtqueue->next != NULL) {
        thread = func_8008942C(&mq->mtqueue);
        osStartThread(thread);
    }
    __osRestoreInt(saveMask);
    return 0;
}
