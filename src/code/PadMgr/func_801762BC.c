// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr_ctx.h"

void PadMgr_UpdateRumble(void) {
    s32 i;
    s32 ret;
    OSMesgQueue* serialEventQueue = PadMgr_AcquireSerialEventQueue();
    s32 triedRumbleComm = false;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NORMAL) {
            
            if (sPadMgrInstance->padStatus[i].status & CONT_CARD_ON) {
                if (sPadMgrInstance->pakType[i] == CONT_PAK_RUMBLE) {
                    if (sPadMgrInstance->rumbleEnable[i]) {
                        if (sPadMgrInstance->rumbleTimer[i] < 3) {
                            

                            if (osMotorStart(&sPadMgrInstance->rumblePfs[i]) != 0) {
                                
                                sPadMgrInstance->pakType[i] = CONT_PAK_NONE;
                            } else {
                                sPadMgrInstance->rumbleTimer[i] = 3;
                            }
                            triedRumbleComm = true;
                        }
                    } else {
                        if (sPadMgrInstance->rumbleTimer[i] != 0) {
                            

                            if (osMotorStop(&sPadMgrInstance->rumblePfs[i]) != 0) {
                                
                                sPadMgrInstance->pakType[i] = CONT_PAK_NONE;
                            } else {
                                sPadMgrInstance->rumbleTimer[i]--;
                            }
                            triedRumbleComm = true;
                        }
                    }
                }
            } else if (sPadMgrInstance->pakType[i] != CONT_PAK_NONE) {
                sPadMgrInstance->pakType[i] = CONT_PAK_NONE;
            }
        }
    }

    if (!triedRumbleComm) {
        
        
        i = sPadMgrRetraceCount % MAXCONTROLLERS;

        if ((sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NORMAL) &&
            (sPadMgrInstance->padStatus[i].status & CONT_CARD_ON) && (sPadMgrInstance->pakType[i] != CONT_PAK_RUMBLE)) {
            ret = osMotorInit(serialEventQueue, &sPadMgrInstance->rumblePfs[i], i);

            if (ret == 0) {
                
                sPadMgrInstance->pakType[i] = CONT_PAK_RUMBLE;
                sPadMgrInstance->rumbleTimer[i] = 2;
            } else if (ret == PFS_ERR_DEVICE) {
                
                if (sPadMgrInstance->pakType[i] != CONT_PAK_OTHER) {
                    sPadMgrInstance->pakType[i] = CONT_PAK_OTHER;
                }
            } else if (ret == PFS_ERR_CONTRFAIL) {
                
            } else if (ret == PFS_ERR_NOPACK) {
                
            } else {
                
                Fault_AddHungupAndCrash("../padmgr.c", 596);
            }
        }
    }

    PadMgr_ReleaseSerialEventQueue(serialEventQueue);
}
