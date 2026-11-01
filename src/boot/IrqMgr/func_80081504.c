// FLAGS: -O2 -g0 -mips2
#include "boot/irqmgr.h"
#include "boot/stackcheck.h"

void IrqMgr_CheckStacks(void) {
    StackCheck_Check(NULL);
}
