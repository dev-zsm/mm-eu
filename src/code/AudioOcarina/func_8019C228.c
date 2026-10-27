// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801CF958;
extern u8 D_801CF95C;

void AudioOcarina_SetSongStartingPos(void) {
    D_801CF95C = D_801CF958;
}
