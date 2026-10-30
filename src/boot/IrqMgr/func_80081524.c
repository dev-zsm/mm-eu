// FLAGS: -O2 -g3 -mips2
#include "irqmgr.h"

void IrqMgr_HandlePRENMI450(IrqMgr *irqMgr) {
    D_80096D00 = 2;
    irqMgr->resetStatus = 2;
    osSetTimer(&irqMgr->timer, 0x15752A, 0, &irqMgr->irqQueue, (OSMesg)0x2A0);
    IrqMgr_SendMesgToClients(irqMgr, &irqMgr->prenmi450Msg);
}
