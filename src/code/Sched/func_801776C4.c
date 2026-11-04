// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sched.h"

void Sched_HandleGfxCancel(Scheduler* sched) {
    s32 i;

    osSyncPrintf(T("GRAPH SP キャンセルします\n", "I am canceling the GRAPH SP\n"));

    if ((sched->curRSPTask != NULL) && (sched->curRSPTask->list.t.type == M_GFXTASK)) {
        if (!(IO_READ(SP_STATUS_REG) & SP_STATUS_HALT)) {
            osSyncPrintf(T("GRAPH SP止めようとします\n", "Attempting to stop GRAPH SP\n"));

            IO_WRITE(SP_STATUS_REG, SP_SET_HALT);

            i = 0;
            while (!(IO_READ(SP_STATUS_REG) & SP_STATUS_HALT)) {
                if (i++ > 100) {
                    osSyncPrintf(
                        T("GRAPH SP止まりませんでした(10msタイムアウト)\n", "GRAPH SP did not stop (10ms timeout)\n"));
                    goto send_mesg;
                }
                usleep(100);
            }
            osSyncPrintf(T("GRAPH SP止まりました(%d * 100us)\n", "GRAPH SP stopped (%d * 100us)\n"), i);
        } else {
            osSyncPrintf(T("GRAPH SP止まっているようです\n", "GRAPH SP seems to be stopped\n"));
        }

    send_mesg:
        osSendMesg(&sched->interruptQueue, (OSMesg)RSP_DONE_MSG, OS_MESG_NOBLOCK);
        goto halt_rdp;
    }

    if (sched->gfxListHead != NULL) {
        OSScTask* cur = sched->gfxListHead;
        OSScTask* next = cur->next;

        sched->gfxListHead = next;
        if (next == NULL) {
            sched->gfxListTail = NULL;
        }
        if (cur->msgQ != NULL) {
            osSendMesg(cur->msgQ, cur->msg, OS_MESG_BLOCK);
        }
        goto halt_rdp;
    }

    osSyncPrintf(T("キャンセルすべき GRAPH SP タスクがありません\n", "There are no GRAPH SP tasks to cancel\n"));

halt_rdp:
    if (sched->curRDPTask != NULL) {
        OSTask_t* dpTask = &sched->curRDPTask->list.t;

        if (dpTask->type == M_GFXTASK) {
            osSyncPrintf(T("DP止めようとします\n", "Attempting to stop DP\n"));
            bzero(dpTask->output_buff, (uintptr_t)dpTask->output_buff_size - (uintptr_t)dpTask->output_buff);
            osSendMesg(&sched->interruptQueue, (OSMesg)RDP_DONE_MSG, OS_MESG_NOBLOCK);
        }
    }
}
