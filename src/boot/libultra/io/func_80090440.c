// FLAGS: -O2 -g0 -mips2
#include "os_sp.h"

s32 osSpTaskYielded(OSTask *task) {
    u32 status;
    s32 yielded;

    status = __osSpGetStatus();
    if (status & SP_STATUS_SIG1) {
        yielded = OS_TASK_YIELDED;
    } else {
        yielded = 0;
    }
    if (status & SP_STATUS_SIG0) {
        task->t.flags = task->t.flags | yielded;
        task->t.flags = task->t.flags & ~OS_TASK_DP_WAIT;
    }
    return yielded;
}
