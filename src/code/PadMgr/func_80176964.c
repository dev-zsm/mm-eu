// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr_ctx.h"

void PadMgr_UpdateInputs(void) {
    s32 diff;
    Input* input = &sPadMgrInstance->inputs[0];
    s32 i;
    OSContPad* pad = &sPadMgrInstance->pads[0];

    for (i = 0; i < sPadMgrInstance->nControllers; i++, input++, pad++) {
        s32 isStandardController;

        input->prev = input->cur;
        isStandardController = sPadMgrInstance->ctrlrType[i] == PADMGR_CONT_NORMAL;
        if (isStandardController) {
            switch (pad->errno) {
                case 0:
                    
                    input->cur = *pad;
                    break;

                case CHNL_ERR_OVERRUN >> 4:
                    
                    input->cur = input->prev;
                    break;

                case CHNL_ERR_NORESP >> 4:
                    
                    input->cur.button = 0;
                    input->cur.stick_x = 0;
                    input->cur.stick_y = 0;
                    input->cur.errno = pad->errno;
                    if (sPadMgrInstance->ctrlrType[i] != PADMGR_CONT_NONE) {
                        
                        sPadMgrInstance->ctrlrType[i] = PADMGR_CONT_NONE;
                        sPadMgrInstance->pakType[i] = CONT_PAK_NONE;
                        sPadMgrInstance->rumbleTimer[i] = 0xFF;
                    }
                    break;

                default:
                    
                    Fault_AddHungupAndCrash("../padmgr.c", 1100);
                    break;
            }
        } else {
            input->cur.button = 0;
            input->cur.stick_x = 0;
            input->cur.stick_y = 0;
            input->cur.errno = pad->errno;
        }

        
        if ((input->cur.button & (BTN_DDOWN | BTN_DUP)) == (BTN_DDOWN | BTN_DUP)) {
            input->cur.button &= ~(BTN_DDOWN | BTN_DUP);
        }
        if ((input->cur.button & (BTN_DRIGHT | BTN_DLEFT)) == (BTN_DRIGHT | BTN_DLEFT)) {
            input->cur.button &= ~(BTN_DRIGHT | BTN_DLEFT);
        }

        
        diff = input->prev.button ^ input->cur.button;
        input->press.button |= (u16)(diff & input->cur.button);
        input->rel.button |= (u16)(diff & input->prev.button);

        if (1) {}
        PadMgr_AdjustInput(input);
    }
}
