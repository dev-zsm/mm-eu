// FLAGS: -O2 -g3 -mips2
#include "irqmgr.h"

void IrqMgr_HandlePreNMI(IrqMgr *irqMgr) {
    D_80096D00 = 1;
    irqMgr->resetStatus = 1;
    D_80096D08 = irqMgr->resetTime = osGetTime();
    osSetTimer(&irqMgr->timer, 0x141DD76, 0, &irqMgr->irqQueue, (OSMesg)0x29F);
    IrqMgr_JamMesgToClients(irqMgr, &irqMgr->prenmiMsg);
}
