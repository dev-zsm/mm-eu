// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void osStopThread(OSThread *t) {
    register OSIntMask saveMask;
    register u16 state;

    saveMask = __osDisableInt();
    if (t == NULL) {
        state = OS_STATE_RUNNING;
    } else {
        state = t->state;
    }
    switch (state) {
        case OS_STATE_RUNNING:
            D_80098010->state = OS_STATE_STOPPED;
            func_800892E4(NULL);
            break;
        case OS_STATE_RUNNABLE:
        case OS_STATE_WAITING:
            t->state = OS_STATE_STOPPED;
            func_800895D0(t->queue, t);
            break;
        default:
            break;
    }
    __osRestoreInt(saveMask);
}
