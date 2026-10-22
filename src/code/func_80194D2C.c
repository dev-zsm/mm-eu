// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801FAE80;

void AudioThread_ResetExternalPool(void) {
    D_801FAE80 = 0;
}
