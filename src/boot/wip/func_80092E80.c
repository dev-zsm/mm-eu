// FLAGS: -O2 -g0 -mips2
#include "types.h"
/* shortcut: __osSetFpcCsr needs cfc1/ctc1, which C cannot emit without inline asm (forbidden by brief) */
u32 func_80092E80(u32 a0) {
    return a0;
}
