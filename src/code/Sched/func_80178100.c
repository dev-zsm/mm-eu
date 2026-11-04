// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sched.h"

void Sched_HandleRDPDone(Scheduler* sched) {
    OSScTask* curRDP;
    OSScTask* nextRSP = NULL;
    OSScTask* nextRDP = NULL;
    s32 state;

    if (sched->curRDPTask == NULL) {
        osSyncPrintf("__scHandleRDP:sc->curRDPTask == NULL\n");
        return;
    }

    
    gRDPTimeAcc = osGetTime() - sRDPStartTime;

    
    curRDP = sched->curRDPTask;
    sched->curRDPTask = NULL;
    curRDP->state &= ~OS_SC_DP;

    Sched_TaskComplete(sched, curRDP);

    
    state = ((sched->curRSPTask == NULL) << 1) | (sched->curRDPTask == NULL);
    if (Sched_Schedule(sched, &nextRSP, &nextRDP, state) != state) {
        Sched_RunTask(sched, nextRSP, nextRDP);
    }
}
