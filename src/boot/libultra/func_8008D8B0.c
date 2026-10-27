// FLAGS: -O2 -g0 -mips2
#include "types.h"

void __osSpSetPc(s32 a0);

void osAfterPreNMI(void) {
    __osSpSetPc(0);
}
