// FLAGS: -O2 -g3 -mips2
#include "irqmgr.h"

void IrqMgr_HandlePRENMI480(IrqMgr *irqMgr) {
    osSetTimer(&irqMgr->timer, 0x173EED8, 0, &irqMgr->irqQueue, (OSMesg)0x2A1);
    osAfterPreNMI();
}
