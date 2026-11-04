// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/audio_thread_manager.h"

void AudioMgr_HandleRetrace(AudioMgr* audioMgr) {
    AudioTask* rspTask;
    s32 timerMsgVal = 666;
    OSTimer timer;
    s32 msg;

    if (R_AUDIOMGR_DEBUG_LEVEL > 0) {
        audioMgr->rspTask = NULL;
    }

#if MM_VERSION >= N64_US
    while (!MQ_IS_EMPTY(&audioMgr->cmdQueue)) {
        osRecvMesg(&audioMgr->cmdQueue, NULL, OS_MESG_NOBLOCK);
    }
#endif

    if (audioMgr->rspTask != NULL) {
        audioMgr->audioTask.next = NULL;
        audioMgr->audioTask.flags = OS_SC_NEEDS_RSP;
        audioMgr->audioTask.framebuffer = NULL;

        audioMgr->audioTask.list = audioMgr->rspTask->task;
        audioMgr->audioTask.msgQ = &audioMgr->cmdQueue;

        audioMgr->audioTask.msg = NULL;
        osSendMesg(&audioMgr->sched->cmdQueue, &audioMgr->audioTask, OS_MESG_BLOCK);
        Sched_SendNotifyMsg(audioMgr->sched);
    }

    if (R_AUDIOMGR_DEBUG_LEVEL >= 2) {
        rspTask = NULL;
    } else {
        rspTask = AudioThread_Update();
    }

    if (audioMgr->rspTask != NULL) {
#if MM_VERSION >= N64_US
        static s32 sRetryCount = 10;
        while (true) {
            osSetTimer(&timer, OS_USEC_TO_CYCLES(32000), 0, &audioMgr->cmdQueue, (OSMesg)timerMsgVal);
            osRecvMesg(&audioMgr->cmdQueue, (OSMesg*)&msg, OS_MESG_BLOCK);
            osStopTimer(&timer);
            if (msg == timerMsgVal) {
                osSyncPrintf("AUDIO SP TIMEOUT %08x %08x\n", audioMgr->rspTask, audioMgr->rspTask->task);
                if (sRetryCount >= 0) {
                    sRetryCount--;
                    Sched_SendAudioCancelMsg(audioMgr->sched);
                } else {
                    osSyncPrintf(T("audioMgr.c:もうダメ！死ぬ！\n", "audioMgr.c: I can't go on! I'm dying!\n"));
                    osDestroyThread(NULL);
                    break;
                }
            } else {
                break;
            }
        }
        AudioMgr_NotifyTaskDone(audioMgr);
#else
        
        
        
        
        osRecvMesg(&audioMgr->cmdQueue, NULL, OS_MESG_BLOCK);
        
        
        
        
        
        AudioMgr_NotifyTaskDone(audioMgr);
#endif
    }

    audioMgr->rspTask = rspTask;
}
