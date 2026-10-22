// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801CF024;

void Audio_ClearSariaBgm(void) {
    if (D_801CF024 != 0) {
        D_801CF024 = 0;
    }
}
