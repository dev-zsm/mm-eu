// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F4BF0;

void Audio_SetPauseState(u8 state) {
    if ((state == 0) && (D_801F4BF0 != 0)) {
        D_801F4BF0 = 1;
        return;
    }
    D_801F4BF0 = state << 1;
}
