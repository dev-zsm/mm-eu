// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

s32 osStopTimer(OSTimer *t) {
    register OSIntMask saveMask;
    OSTimer *timep;

    if (t->next == NULL) {
        return -1;
    }
    saveMask = __osDisableInt();
    timep = t->next;
    if (timep != D_80098160) {
        timep->value += t->value;
    }
    t->prev->next = t->next;
    t->next->prev = t->prev;
    t->next = NULL;
    t->prev = NULL;
    if (D_80098160->next == D_80098160) {
        __osSetCompare(0);
    }
    __osRestoreInt(saveMask);
    return 0;
}
