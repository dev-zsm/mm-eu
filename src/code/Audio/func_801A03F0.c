// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern s8 D_801CF020;

void Audio_SetSfxUnderwaterReverb(s8 isUnderwaterReverbActivated) {
    if (isUnderwaterReverbActivated != 0) {
        D_801CF020 = -0x80;
        return;
    }
    D_801CF020 = 0;
}
