// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801E6F0C;

s32 Environment_GetEventDayCount(void) {
    return D_801E6F0C;
}
