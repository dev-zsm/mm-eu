// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void osSetThreadPri(OSThread *t, OSPri pri) {
    register OSIntMask saveMask;

    saveMask = __osDisableInt();
    if (t == NULL) {
        t = D_80098010;
    }
    if (t->priority != pri) {
        t->priority = pri;
        if ((t != D_80098010) && (t->state != OS_STATE_STOPPED)) {
            func_800895D0(t->queue, t);
            func_800893E4(t->queue, t);
        }
        if (D_80098010->priority < D_80098008->priority) {
            D_80098010->state = OS_STATE_RUNNABLE;
            func_800892E4(&D_80098008);
        }
    }
    __osRestoreInt(saveMask);
}
