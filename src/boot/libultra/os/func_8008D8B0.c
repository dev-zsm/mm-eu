// FLAGS: -O2 -g0 -mips2
#include "irqmgr.h"
#include "os_sp.h"

void osAfterPreNMI(void) {
    __osSpSetPc(0);
}
