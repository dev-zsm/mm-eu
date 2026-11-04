// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sched.h"

void Sched_HandleRSPDone(Scheduler* sched) {
    OSScTask* curRSP;
    OSScTask* nextRSP = NULL;
    OSScTask* nextRDP = NULL;
    s32 state;
    OSTime time;

    if (sched->curRSPTask == NULL) {
        osSyncPrintf("__scHandleRSP:sc->curRSPTask == NULL\n");
        return;
    }

    
    time = osGetTime();
    switch (sched->curRSPTask->list.t.type) {
        case M_AUDTASK:
            gRSPAudioTimeAcc += time - sRSPAudioStartTime;
            break;

        case M_GFXTASK:
            gRSPGfxTimeAcc += time - sRSPGFXStartTime;
            break;

        default:
            if (1) {}
            gRSPOtherTimeAcc += time - sRSPOtherStartTime;
            break;
    }

    curRSP = sched->curRSPTask;
    sched->curRSPTask = NULL;

    if (curRSP->list.t.type == M_AUDTASK) {
        
        gAudioSPDataPtr = NULL;
        gAudioSPDataSize = 0;
    }

    if ((curRSP->state & OS_SC_YIELD) && osSpTaskYielded(&curRSP->list)) {
        
        curRSP->state |= OS_SC_YIELDED;
        curRSP->next = sched->gfxListHead;
        sched->gfxListHead = curRSP;
        if (sched->gfxListTail == NULL) {
            sched->gfxListTail = curRSP;
        }
    } else {
        
        curRSP->state &= ~OS_SC_SP;
        Sched_TaskComplete(sched, curRSP);
    }

    
    state = ((sched->curRSPTask == NULL) << 1) | (sched->curRDPTask == NULL);
    if (Sched_Schedule(sched, &nextRSP, &nextRDP, state) != state) {
        Sched_RunTask(sched, nextRSP, nextRDP);
    }
}
