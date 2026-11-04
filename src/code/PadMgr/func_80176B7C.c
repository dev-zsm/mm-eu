// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr.h"

void PadMgr_InitVoice(void) {
    s32 i;
    OSMesgQueue* serialEventQueue;
    s32 ret;

    for (i = 0; i < sPadMgrInstance->nControllers; i++) {
        if (sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_VOICE_PLUGGED) {
            serialEventQueue = PadMgr_AcquireSerialEventQueue();

            ret = osVoiceInit(serialEventQueue, &gVoiceHandle, i);

            PadMgr_ReleaseSerialEventQueue(serialEventQueue);

            if (1) {}

            if (ret != 0) {
                PRINTF("osVoiceInit rt=%d\n", ret);
            } else {
                sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_VOICE;
                sVoiceInitStatus = VOICE_INIT_SUCCESS;
                AudioVoice_Noop();
            }
        }

        if (0) {}
    }
    
    if (sVoiceInitStatus == VOICE_INIT_TRY) {
        sVoiceInitStatus = VOICE_INIT_FAILED;
    }
}
