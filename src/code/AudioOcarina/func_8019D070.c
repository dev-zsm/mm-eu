// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CF8E4;

void AudioOcarina_EnableInput(u8 arg0) {
    D_801CF8E4 = arg0;
}
