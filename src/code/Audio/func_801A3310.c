// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801CF024;

void Audio_ClearSariaBgm2(void) {
    D_801CF024 = 0;
}
