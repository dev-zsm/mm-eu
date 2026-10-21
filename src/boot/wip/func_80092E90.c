// FLAGS: -O2 -g0 -mips2
#include "types.h"
/* shortcut: __osGetFpcCsr needs cfc1, which C cannot emit without inline asm (forbidden by brief) */
u32 func_80092E90(void) {
    return 0;
}
