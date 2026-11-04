// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sched.h"

s32 Sched_Schedule(Scheduler* sched, OSScTask** spTask, OSScTask** dpTask, s32 state) {
    s32 nextState = state;
    OSScTask* gfxTask = sched->gfxListHead;
    OSScTask* audioTask = sched->audioListHead;

    if ((state & OS_SC_SP) && (sched->audioListHead != NULL)) {
        *spTask = audioTask;
        nextState &= ~OS_SC_SP;
        sched->audioListHead = sched->audioListHead->next;
        if (sched->audioListHead == NULL) {
            sched->audioListTail = NULL;
        }
    } else if (gfxTask != NULL) {
        if ((gfxTask->state & OS_SC_YIELDED) || !(gfxTask->flags & OS_SC_NEEDS_RDP)) {
            if (state & OS_SC_SP) {
                *spTask = gfxTask;
                nextState &= ~OS_SC_SP;
                sched->gfxListHead = sched->gfxListHead->next;
                if (sched->gfxListHead == NULL) {
                    sched->gfxListTail = NULL;
                }
            }
        } else if (state == (OS_SC_SP | OS_SC_DP)) {
            if ((TASK_FRAMEBUFFER(gfxTask) == NULL) || Sched_TaskFramebuffersValid(sched, gfxTask)) {
                *spTask = *dpTask = gfxTask;
                nextState &= ~(OS_SC_SP | OS_SC_DP);
                sched->gfxListHead = sched->gfxListHead->next;
                if (sched->gfxListHead == NULL) {
                    sched->gfxListTail = NULL;
                }
            }
        }
    }
    return nextState;
}
