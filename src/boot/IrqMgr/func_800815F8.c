// FLAGS: -O2 -g3 -mips2
#include "irqmgr.h"

void IrqMgr_HandlePRENMI500(IrqMgr *irqMgr) {
    IrqMgr_CheckStacks();
}
