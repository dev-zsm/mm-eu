// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct Timer {
    struct Timer *next;
    struct Timer *prev;
    u64 interval;
    u64 value;
    void *mq;
    void *msg;
} Timer;

extern Timer *D_80098160;
extern u64 D_8009E980;
extern u32 D_8009E988;
extern u32 D_8009E98C;

void __osTimerServicesInit(void) {
    D_8009E980 = 0;
    D_8009E988 = 0;
    D_8009E98C = 0;
    D_80098160->prev = D_80098160;
    D_80098160->next = D_80098160->prev;
    D_80098160->value = 0;
    D_80098160->interval = D_80098160->value;
    D_80098160->mq = 0;
    D_80098160->msg = 0;
}
