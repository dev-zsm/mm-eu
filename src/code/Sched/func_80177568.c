// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sched.h"

void Sched_HandleAudioCancel(Scheduler* sched) {
    s32 i;

    osSyncPrintf(T("AUDIO SP キャンセルします\n", "I am canceling the AUDIO SP\n"));

    if ((sched->curRSPTask != NULL) && (sched->curRSPTask->list.t.type == M_AUDTASK)) {
        if (!(IO_READ(SP_STATUS_REG) & SP_STATUS_HALT)) {
            osSyncPrintf(T("AUDIO SP止めようとします\n", "Attempting to stop AUDIO SP\n"));

            IO_WRITE(SP_STATUS_REG, SP_SET_HALT);

            i = 0;
            while (!(IO_READ(SP_STATUS_REG) & SP_STATUS_HALT)) {
                if (i++ > 100) {
                    osSyncPrintf(
                        T("AUDIO SP止まりませんでした(10msタイムアウト)\n", "AUDIO SP did not stop (10ms timeout)\n"));
                    goto send_mesg;
                }
                usleep(100);
            }
            osSyncPrintf(T("AUDIO SP止まりました(%d * 100us)\n", "AUDIO SP stopped (%d * 100us)\n"), i);
        } else {
            osSyncPrintf(T("AUDIO SP止まっているようです\n", "AUDIO SP seems to be stopped\n"));
        }

    send_mesg:
        osSendMesg(&sched->interruptQueue, (OSMesg)RSP_DONE_MSG, OS_MESG_NOBLOCK);
        return;
    }

    if (sched->audioListHead != NULL) {
        OSScTask* cur = sched->audioListHead;
        OSScTask* next = cur->next;

        sched->audioListHead = next;
        if (next == NULL) {
            sched->audioListTail = NULL;
        }
        if (cur->msgQ != NULL) {
            osSendMesg(cur->msgQ, cur->msg, OS_MESG_BLOCK);
        }
        osSyncPrintf(T("AUDIO SP タスクを実行待ちリストから削除しました\n",
                       "The AUDIO SP task has been removed from the pending list\n"));
        return;
    }

    osSyncPrintf(T("キャンセルすべき AUDIO SP タスクがありません\n", "There are no AUDIO SP tasks to cancel\n"));
}
