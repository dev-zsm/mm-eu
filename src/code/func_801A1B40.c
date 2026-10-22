// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801CF024;

void Audio_ClearSariaBgmAtPos(s32 arg0) {
    if (arg0 == D_801CF024) {
        D_801CF024 = 0;
    }
}
