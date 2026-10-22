// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801E6F08;

s32 Environment_GetTotalDays(void) {
    return D_801E6F08;
}
