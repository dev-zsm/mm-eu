// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr.h"

void PadMgr_ThreadEntry(void) {
    s16* interruptMsg = NULL;
    s32 actionBits;
    s32 exit;

    PRINTF(T("コントローラスレッド実行開始\n", "Controller thread execution started\n"));

    osCreateMesgQueue(&sPadMgrInstance->interruptQueue, sPadMgrInstance->interruptMsgBuf,
                      ARRAY_COUNT(sPadMgrInstance->interruptMsgBuf));
    IrqMgr_AddClient(sPadMgrInstance->irqMgr, &sPadMgrInstance->irqClient, &sPadMgrInstance->interruptQueue);

    actionBits = 0;
    exit = false;

    while (!exit) {
        
        
        do {
            osRecvMesg(&sPadMgrInstance->interruptQueue, (OSMesg*)&interruptMsg, OS_MESG_BLOCK);
            switch (*interruptMsg) {
                case OS_SC_RETRACE_MSG:
                    actionBits |= PADMGR_RETRACE_MSG;
                    break;

                case OS_SC_PRE_NMI_MSG:
                    actionBits |= PADMGR_PRE_NMI_MSG;
                    break;

                case OS_SC_NMI_MSG:
                    actionBits |= PADMGR_NMI_MSG;
                    break;
            }
        } while (!MQ_IS_EMPTY(&sPadMgrInstance->interruptQueue));

        
        while (actionBits != 0) {
            if (actionBits & PADMGR_NMI_MSG) {
                actionBits &= ~PADMGR_NMI_MSG;
                exit = true;
            } else if (actionBits & PADMGR_PRE_NMI_MSG) {
                actionBits &= ~PADMGR_PRE_NMI_MSG;
                PadMgr_HandlePreNMI();
            } else if (actionBits & PADMGR_RETRACE_MSG) {
                actionBits &= ~PADMGR_RETRACE_MSG;
                PadMgr_HandleRetrace();
            }
        }
    }

    IrqMgr_RemoveClient(sPadMgrInstance->irqMgr, &sPadMgrInstance->irqClient);

    PRINTF(T("コントローラスレッド実行終了\n", "Controller thread execution finished\n"));
}
