// FLAGS: -O2 -g0 -mips2
#include "boot/irqmgr.h"
#include "sdk/os_sp.h"

void osAfterPreNMI(void) {
    __osSpSetPc(0);
}
