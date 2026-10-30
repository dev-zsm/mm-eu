// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count) {
    mq->mtqueue = (OSThread *)&D_80098000;
    mq->fullqueue = (OSThread *)&D_80098000;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;
}
