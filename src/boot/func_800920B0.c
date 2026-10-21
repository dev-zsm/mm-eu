// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_80098060;

s32 func_800920B0(void) {
    if (*(s32 *)&D_80098060 == 0) {
        return 0;
    }
    return ((s32 *)&D_80098060)[2];
}
