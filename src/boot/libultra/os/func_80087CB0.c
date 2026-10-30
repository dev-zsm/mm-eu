// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flags) {
    register OSIntMask saveMask; /* register: -O1 only allocates saved registers for register locals */
    register s32 last;
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
    last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = msg;
    mq->validCount++;
    if (mq->mtqueue->next != NULL) {
        thread = func_8008942C(&mq->mtqueue);
        osStartThread(thread);
    }
    __osRestoreInt(saveMask);
    return 0;
}
