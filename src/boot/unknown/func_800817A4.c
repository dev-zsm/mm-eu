// FLAGS: -O2 -g3
#include "os_internal.h"

void func_800817A4(IrqMgr *irqMgr, void *stack, OSPri pri, u8 retraceCount) {
    irqMgr->clients = NULL;
    *(s16 *)irqMgr->retraceMsg = 1; /* type of each message */
    *(s16 *)irqMgr->prenmiMsg = 4;
    *(s16 *)irqMgr->prenmi450Msg = 3;
    irqMgr->resetStatus = 0;
    irqMgr->resetTime = 0;
    osCreateMesgQueue(&irqMgr->irqQueue, irqMgr->irqBuffer, 8);
    osSetEventMesg(OS_EVENT_PRENMI, &irqMgr->irqQueue, (OSMesg)0x29D);
    osViSetEvent(&irqMgr->irqQueue, (OSMesg)0x29A, retraceCount);
    osCreateThread(&irqMgr->thread, 0x13, (void (*)(void *))func_800816D4, irqMgr, stack, pri);
    osStartThread(&irqMgr->thread);
}
