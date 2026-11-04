// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr.h"

void PadMgr_GetInputNoLock(Input* inputs, s32 gameRequest) {
    s32 i;
    Input* input = &sPadMgrInstance->inputs[0];
    Input* inputOut = &inputs[0];
    s32 buttonDiff;

    for (i = 0; i < MAXCONTROLLERS; i++) {
        if (gameRequest) {
            
            *inputOut = *input;
            
            input->press.button = 0;
            input->rel.button = 0;
        } else {
            
            inputOut->prev = inputOut->cur;
            
            inputOut->cur = input->cur;
            
            buttonDiff = inputOut->prev.button ^ inputOut->cur.button;
            inputOut->press.button = inputOut->cur.button & buttonDiff;
            inputOut->rel.button = inputOut->prev.button & buttonDiff;
            PadUtils_UpdateRelXY(inputOut);
        }
        input++;
        inputOut++;
    }
}
