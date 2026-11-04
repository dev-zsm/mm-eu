// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sched.h"

void Sched_HandleNotify(Scheduler* sched) {
    OSScTask* nextRSP = NULL;
    OSScTask* nextRDP = NULL;
    OSScTask* task = NULL;
    s32 state;

    
    while (osRecvMesg(&sched->cmdQueue, (OSMesg*)&task, OS_MESG_NOBLOCK) != -1) {
        Sched_QueueTask(sched, task);
    }

    
    if ((sched->audioListHead != NULL) && (sched->curRSPTask != NULL)) {
        Sched_Yield(sched);
        return;
    }
    
    state = ((sched->curRSPTask == NULL) << 1) | (sched->curRDPTask == NULL);
    if (Sched_Schedule(sched, &nextRSP, &nextRDP, state) != state) {
        Sched_RunTask(sched, nextRSP, nextRDP);
    }
}
