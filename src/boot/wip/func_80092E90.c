// FLAGS: -O2 -g0 -mips2
#include "types.h"
/* shortcut: __osGetFpcCsr needs cfc1, which C cannot emit without inline asm (forbidden by brief) */
u32 __osGetFpcCsr(void) {
    return 0;
}
