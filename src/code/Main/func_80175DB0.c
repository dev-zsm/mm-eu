// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/main.h"

void Main(void* arg) {
    uintptr_t fb;
    uintptr_t sysHeap;
    s32 exit;
    s16* msg;

    PRINTF(T("mainproc 実行開始\n", "mainproc Start running\n"));

    gScreenWidth = SCREEN_WIDTH;
    gScreenHeight = SCREEN_HEIGHT;

    Nmi_Init();
    Fault_Init();
    Check_RegionIsSupported();
    Check_ExpansionPak();

    sysHeap = (uintptr_t)SEGMENT_END(buffers);
    fb = FRAMEBUFFERS_START_ADDR;
    gSystemHeapSize = fb - sysHeap;
    PRINTF(T("システムヒープ初期化 %08x-%08x %08x\n", "System heap initialization %08x-%08x %08x\n"), systemHeapStart,
           fb, sysHeap);
    SystemHeap_Init((void*)sysHeap, gSystemHeapSize);

    Regs_Init();

    R_ENABLE_ARENA_DBG = 0;

    osCreateMesgQueue(&sSerialEventQueue, sSerialMsgBuf, ARRAY_COUNT(sSerialMsgBuf));
    osSetEventMesg(OS_EVENT_SI, &sSerialEventQueue, NULL);

    osCreateMesgQueue(&sIrqMgrMsgQueue, sIrqMgrMsgBuf, ARRAY_COUNT(sIrqMgrMsgBuf));

    StackCheck_Init(&sSchedStackInfo, sSchedStack, STACK_TOP(sSchedStack), 0, 0x100, "sched");
    Sched_Init(&gScheduler, STACK_TOP(sSchedStack), Z_PRIORITY_SCHED, gViConfigModeType, 1, &gIrqMgr);

    CIC6105_AddRomInfoFaultPage();
#if MM_VERSION < N64_US
    CIC6105_ScheduleCICTask();
#endif

    IrqMgr_AddClient(&gIrqMgr, &sIrqClient, &sIrqMgrMsgQueue);

    StackCheck_Init(&sAudioStackInfo, sAudioStack, STACK_TOP(sAudioStack), 0, 0x100, "audio");
    AudioMgr_Init(&sAudioMgr, STACK_TOP(sAudioStack), Z_PRIORITY_AUDIOMGR, Z_THREAD_ID_AUDIOMGR, &gScheduler, &gIrqMgr);

    StackCheck_Init(&sPadMgrStackInfo, sPadMgrStack, STACK_TOP(sPadMgrStack), 0, 0x100, "padmgr");
    PadMgr_Init(&sSerialEventQueue, &gIrqMgr, Z_THREAD_ID_PADMGR, Z_PRIORITY_PADMGR, STACK_TOP(sPadMgrStack));

    AudioMgr_Unlock(&sAudioMgr);

    StackCheck_Init(&sGraphStackInfo, sGraphStack, STACK_TOP(sGraphStack), 0, 0x100, "graph");
    osCreateThread(&gGraphThread, Z_THREAD_ID_GRAPH, Graph_ThreadEntry, arg, STACK_TOP(sGraphStack), Z_PRIORITY_GRAPH);
    osStartThread(&gGraphThread);

    exit = false;

    while (!exit) {
        msg = NULL;
        osRecvMesg(&sIrqMgrMsgQueue, (OSMesg*)&msg, OS_MESG_BLOCK);
        if (msg == NULL) {
            break;
        }

        switch (*msg) {
            case OS_SC_PRE_NMI_MSG:
                PRINTF(T("main.c: リセットされたみたいだよ\n", "main.c: Looks like it's been reset\n"));
                Nmi_SetPrenmiStart();
                break;

            case OS_SC_NMI_MSG:
                PRINTF("main.c IRQMGR_PRENMI500_MSG\n");
                exit = true;
                break;
        }
    }

    IrqMgr_RemoveClient(&gIrqMgr, &sIrqClient);
    PRINTF(T("mainproc 後始末\n", "mainproc Cleanup\n"));
    osDestroyThread(&gGraphThread);
    PRINTF(T("mainproc 実行終了\n", "mainproc End of execution\n"));
}
