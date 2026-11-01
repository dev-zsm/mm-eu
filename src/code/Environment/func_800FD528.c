// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"

extern s32 D_801E6F0C;

void Environment_ClearEventDayCount(void) {
    D_801E6F0C = 0;
}
