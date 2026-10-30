// FLAGS: -O1 -g0 -mips2
#include "os_internal.h"

void func_80089610(OSThread *t) {
    register OSIntMask savedMask;
    register OSThread *it;
    register OSThread *next;

    savedMask = __osDisableInt();
    if (t == NULL) {
        t = D_80098010;
    } else if (t->state != OS_STATE_STOPPED) {
        func_800895D0(t->queue, t);
    }

    if (D_8009800C == t) {
        D_8009800C = D_8009800C->tlnext;
    } else {
        it = D_8009800C;
        if (it->priority != -1) {
            do {
                next = it->tlnext;
                if (next == t) {
                    it->tlnext = t->tlnext;
                    break;
                }
                it = next;
            } while (it->priority != -1);
        }
    }

    if (t == D_80098010) {
        func_80089444();
    }
    __osRestoreInt(savedMask);
}
