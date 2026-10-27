// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s8 D_801CEF9C;

void Audio_ResetIncreasingTranspose(void) {
    D_801CEF9C = 0;
}
