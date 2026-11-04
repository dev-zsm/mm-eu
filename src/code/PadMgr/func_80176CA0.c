// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr.h"

void PadMgr_UpdateConnections(void) {
    s32 ctrlrMask = 0;
    s32 i;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (sPadMgrInstance->padStatus[i].errno == 0) {
            switch (sPadMgrInstance->padStatus[i].type & CONT_TYPE_MASK) {
                case CONT_TYPE_NORMAL:
                    
                    ctrlrMask |= (1 << i);
                    if (sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NONE) {
                        sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_NORMAL;
                    }
                    break;

                case CONT_TYPE_MOUSE:
                    
                    if (sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NONE) {
                        sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_MOUSE;
                    }
                    break;

                case CONT_TYPE_VOICE:
                    
                    if (sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NONE) {
                        sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_VOICE_PLUGGED;
                        sPadMgrInstance->pakType[i] = CONT_PAK_NONE;
                    }
                    break;

                default:
                    
                    if (sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NONE) {
                        sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_UNK;
#if MM_VERSION >= N64_US
                        {
                            char msg[50];
                            sprintf(msg,
                                    T("知らない種類のコントローラ(%04x)を認識しました",
                                      "Recognized an unknown type of controller (%04x)"),
                                    sPadMgrInstance->padStatus[i].type);
                        }
#endif
                    }
                    
            }
        } else if (sPadMgrInstance->ctrlrType[i] != PADMGR_CONT_NONE) {
            
#if MM_VERSION >= N64_US
            sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_NONE;
            sPadMgrInstance->pakType[i] = CONT_PAK_NONE;
            sPadMgrInstance->rumbleTimer[i] = 0xFF;
#else
            if (sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NORMAL) {
                sPadMgrInstance->pakType[i] = CONT_PAK_NONE;
                sPadMgrInstance->rumbleTimer[i] = 0xFF;
            }
            sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_NONE;
#endif
        }
    }
    sPadMgrInstance->validCtrlrsMask = ctrlrMask;
}
