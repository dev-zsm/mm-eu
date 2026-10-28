// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct OSTimer {
    struct OSTimer *next;
    struct OSTimer *prev;
    u64 interval;
    u64 value;
} OSTimer;

extern OSTimer *D_80098160;
extern s32 __osDisableInt(void);
extern void __osRestoreInt(s32 a);

u64 __osInsertTimer(OSTimer *t) {
    OSTimer *timep;
    u64 tim;
    s32 savedMask;

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
