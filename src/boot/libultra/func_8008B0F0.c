// FLAGS: -O2 -g0 -mips2
#include "types.h"

void __osSpSetStatus(s32 a0);

void osSpTaskYield(void) {
    __osSpSetStatus(0x400);
}
