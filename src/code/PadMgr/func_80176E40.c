// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr.h"

void PadMgr_HandleRetrace(void) {
    OSMesgQueue* serialEventQueue = PadMgr_AcquireSerialEventQueue();

    
    osContStartReadData(serialEventQueue);

    
    if (sPadMgrInstance->rumbleRetraceCallback != NULL) {
        sPadMgrInstance->rumbleRetraceCallback(sPadMgrInstance->rumbleRetraceArg);
    }

    
    osRecvMesg(serialEventQueue, NULL, OS_MESG_BLOCK);
    osContGetReadData(sPadMgrInstance->pads);

    
    bzero(&sPadMgrInstance->pads[1], sizeof(*sPadMgrInstance->pads) * (MAXCONTROLLERS - 1));

    
    if (sPadMgrInstance->isResetting) {
        bzero(sPadMgrInstance->pads, sizeof(sPadMgrInstance->pads));
    }

    
    osContStartQuery(serialEventQueue);
    osRecvMesg(serialEventQueue, NULL, OS_MESG_BLOCK);
    osContGetQuery(sPadMgrInstance->padStatus);

    
    PadMgr_ReleaseSerialEventQueue(serialEventQueue);

    
    PadMgr_UpdateConnections();

    
    PadMgr_LockPadData();

    
    PadMgr_UpdateInputs();

    
    if (sPadMgrInstance->inputRetraceCallback != NULL) {
        sPadMgrInstance->inputRetraceCallback(sPadMgrInstance->inputRetraceArg);
    }

    
    PadMgr_UnlockPadData();

    
    if (sVoiceInitStatus != VOICE_INIT_FAILED) {
        PadMgr_InitVoice();
    }

    
    if (gFaultMgr.msgId != 0) {
        
        PadMgr_RumbleStop();
    } else if (sPadMgrInstance->rumbleOffTimer > 0) {
        
        --sPadMgrInstance->rumbleOffTimer;
        PadMgr_RumbleStop();
    } else if (sPadMgrInstance->rumbleOnTimer == 0) {
        
        PadMgr_RumbleStop();
    } else if (!sPadMgrInstance->isResetting) {
        
        PadMgr_UpdateRumble();
        --sPadMgrInstance->rumbleOnTimer;
    }

    sPadMgrRetraceCount++;
}
