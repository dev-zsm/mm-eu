// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801F4DE0;

s32 AudioVoice_GetVoiceDict(void) {
    return D_801F4DE0;
}
