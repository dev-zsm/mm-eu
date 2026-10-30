// FLAGS: -O2 -g3 -mips2
#include "irqmgr.h"

void IrqMgr_HandleRetrace(IrqMgr *irqMgr) {
    if (D_80096D10 == 0) {
        if (irqMgr->retraceTime == 0) {
            irqMgr->retraceTime = osGetTime();
        } else {
            D_80096D10 = osGetTime() - irqMgr->retraceTime;
        }
    }
    D_80096D18 += 1;
    IrqMgr_SendMesgToClients(irqMgr, irqMgr->retraceMsg);
}
