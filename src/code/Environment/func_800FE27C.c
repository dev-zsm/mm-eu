// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s8 D_801EC6B0;

void Environment_StopTime(void) {
    D_801EC6B0 = 1;
}
