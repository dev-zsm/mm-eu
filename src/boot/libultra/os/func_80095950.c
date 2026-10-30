// FLAGS: -O1 -g0 -mips2
#include "ultra64.h"

void osStartThread(OSThread *t) {
    register OSIntMask saveMask;

    saveMask = __osDisableInt();
    switch (t->state) {
        case OS_STATE_WAITING:
            t->state = OS_STATE_RUNNABLE;
            func_800893E4(&D_80098008, t);
            break;
        case OS_STATE_STOPPED:
            if (t->queue == NULL || t->queue == &D_80098008) {
                t->state = OS_STATE_RUNNABLE;
                func_800893E4(&D_80098008, t);
            } else {
                t->state = OS_STATE_WAITING;
                func_800893E4(t->queue, t);
                func_800893E4(&D_80098008, func_8008942C(t->queue));
            }
            break;
    }
    if (D_80098010 == NULL) {
        func_80089444();
    } else {
        if (D_80098010->priority < D_80098008->priority) {
            D_80098010->state = OS_STATE_RUNNABLE;
            func_800892E4(&D_80098008);
        }
    }
    __osRestoreInt(saveMask);
}
