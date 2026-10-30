// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

s32 osSetTimer(OSTimer *t, OSTime value, OSTime interval, OSMesgQueue *mq, OSMesg msg) {
    OSTime time;
    OSTimer *next;
    u32 count;
    u32 elapsed;
    OSIntMask saveMask;
    OSTime *p;

    t->next = NULL;
    t->prev = NULL;
    t->interval = interval;
    if (value != 0) {
        t->value = value;
    } else {
        t->value = interval;
    }
    t->mq = mq;
    t->msg = msg;
    saveMask = __osDisableInt();
    if (D_80098160->next == D_80098160) {} else {
        next = D_80098160->next;
        count = osGetCount();
        elapsed = count - D_8009E990;
        if ((OSTime)elapsed < next->value) {
            p = &next->value;
            *p = *p - (OSTime)elapsed;
        } else {
            next->value = 1;
        }
    }
    time = __osInsertTimer(t);
    __osSetTimerIntr(D_80098160->next->value);
    __osRestoreInt(saveMask);
    return 0;
}
