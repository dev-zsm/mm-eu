// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/audio_thread_manager.h"

void AudioMgr_ThreadEntry(void* arg) {
    AudioMgr* audioMgr = (AudioMgr*)arg;
    IrqMgrClient irqClient;
    s16* msg = NULL;
    s32 exit;

    PRINTF(T("オーディオマネージャスレッド実行開始\n", "Start running audio manager thread\n"));

    Audio_Init();
    AudioLoad_SetDmaHandler(DmaMgr_AudioDmaHandler);
    Audio_InitSound();
    osSendMesg(&audioMgr->lockQueue, NULL, OS_MESG_BLOCK);
    IrqMgr_AddClient(audioMgr->irqMgr, &irqClient, &audioMgr->interruptQueue);

    exit = false;
    while (!exit) {
        osRecvMesg(&audioMgr->interruptQueue, (OSMesg*)&msg, OS_MESG_BLOCK);
        switch (*msg) {
            case OS_SC_RETRACE_MSG:
                AudioMgr_HandleRetrace(audioMgr);
                while (!MQ_IS_EMPTY(&audioMgr->interruptQueue)) {
                    osRecvMesg(&audioMgr->interruptQueue, (OSMesg*)&msg, OS_MESG_BLOCK);
                    switch (*msg) {
                        case OS_SC_RETRACE_MSG:
                            break;

                        case OS_SC_PRE_NMI_MSG:
                            AudioMgr_HandlePreNMI(audioMgr);
                            break;

                        case OS_SC_NMI_MSG:
                            exit = true;
                            break;
                    }
                }
                break;

            case OS_SC_PRE_NMI_MSG:
                AudioMgr_HandlePreNMI(audioMgr);
                break;

            case OS_SC_NMI_MSG:
                exit = true;
                break;
        }
    }

    IrqMgr_RemoveClient(audioMgr->irqMgr, &irqClient);

    PRINTF(T("オーディオマネージャスレッド実行終了\n", "Audio thread manager thread execution end\n"));
}
