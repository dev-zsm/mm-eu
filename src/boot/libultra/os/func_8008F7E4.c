// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

OSTime __osInsertTimer(OSTimer *t) {
    OSTimer *timep;
    OSTime tim;
    OSIntMask savedMask;

    savedMask = __osDisableInt();
    for (timep = D_80098160->next, tim = t->value; timep != D_80098160 && tim > timep->value; tim -= timep->value, timep = timep->next) {
    }
    t->value = tim;
    if (timep != D_80098160) {
        timep->value -= tim;
    }
    t->next = timep;
    t->prev = timep->prev;
    timep->prev->next = t;
    timep->prev = t;
    __osRestoreInt(savedMask);
    return tim;
}
