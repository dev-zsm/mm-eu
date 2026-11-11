// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft, score 34.00 (52 differ, size +5)
#include "generated/mm/sched.h"

void Sched_RunTask(Scheduler* sched, OSScTask* spTask, OSScTask* dpTask) {
    OSTime time;

    if (spTask != NULL) {
        if (spTask->list.t.type == M_NULTASK) {
            if (spTask->flags & OS_SC_NEEDS_RSP) {
                spTask->state &= ~OS_SC_SP;
                sched->curRSPTask = NULL;
            }
            if (spTask->flags & OS_SC_NEEDS_RDP) {
                spTask->state &= ~OS_SC_DP;
                sched->curRDPTask = NULL;
            }
            Sched_TaskComplete(sched, spTask);
            return;
        }
        
        if ((spTask->list.t.type != M_AUDTASK) && !(spTask->state & OS_SC_YIELDED)) {
            osWritebackDCacheAll();
        }
        spTask->state &= ~(OS_SC_YIELD | OS_SC_YIELDED);
        
        osSpTaskLoad(&spTask->list);

        
        time = osGetTime();
        switch (spTask->list.t.type) {
            case M_AUDTASK:
                sRSPAudioStartTime = time;
                break;

            case M_GFXTASK:
                sRSPGFXStartTime = time;
                break;

            default:
                if (1) {}
                sRSPOtherStartTime = time;
                break;
        }

        if (spTask->list.t.type == M_AUDTASK) {
            
            gAudioSPDataPtr = spTask->list.t.data_ptr;
            gAudioSPDataSize = spTask->list.t.data_size;
        }

        
        osSpTaskStartGo(&spTask->list);
        sched->curRSPTask = spTask;
        if (spTask == dpTask && sched->curRDPTask == NULL) {
            sched->curRDPTask = dpTask;
            sRDPStartTime = sRSPGFXStartTime;
        }
    }
}
