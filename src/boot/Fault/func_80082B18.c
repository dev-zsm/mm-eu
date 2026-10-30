// FLAGS: -O2 -g0 -mips2 -trapuv
#include "fault.h"

OSThread *Fault_FindFaultedThread(void) {
    OSThread *thread = __osGetActiveQueue();

    while (thread->priority != -1) {
        if (thread->priority > 0 && thread->priority < 0x7F &&
            (thread->flags & (OS_FLAG_CPU_BREAK | OS_FLAG_FAULT)) != 0) {
            return thread;
        }
        thread = thread->tlnext;
    }
    return NULL;
}
