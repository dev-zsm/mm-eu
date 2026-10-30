// FLAGS: -O2 -g0 -mips2
#include "irqmgr.h"
#include "stackcheck.h"

void IrqMgr_CheckStacks(void) {
    StackCheck_Check(NULL);
}
