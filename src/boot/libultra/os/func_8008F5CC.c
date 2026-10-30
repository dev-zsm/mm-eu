// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void __osTimerInterrupt(void) {
    OSTimer *t;
    u32 count;
    u32 elapsed;

    if (D_80098160->next == D_80098160) {
        return;
    }
    while (1) {
        t = D_80098160->next;
        if (t == D_80098160) {
            __osSetCompare(0);
            D_8009E990 = 0;
            break;
        }
        count = osGetCount();
        elapsed = count - D_8009E990;
        D_8009E990 = count;
        if (elapsed < t->value) {
            t->value -= elapsed;
            __osSetTimerIntr(t->value);
            break;
        } else {
            t->prev->next = t->next;
            t->next->prev = t->prev;
            t->next = NULL;
            t->prev = NULL;
            if (t->mq != NULL) {
                osSendMesg(t->mq, t->msg, OS_MESG_NOBLOCK);
            }
            if (t->interval != 0) {
                t->value = t->interval;
                __osInsertTimer(t);
            }
        }
    }
}
