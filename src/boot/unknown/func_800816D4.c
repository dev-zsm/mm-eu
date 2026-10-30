// FLAGS: -O2 -g3
#include "os_internal.h"

void func_800816D4(IrqMgr *irqMgr) {
    s32 msg;
    OSMesgQueue *queue;
    s32 done;

    done = (msg = 0);
    queue = &irqMgr->irqQueue;
    while (done == 0) {
        osRecvMesg(queue, (OSMesg *)&msg, OS_MESG_BLOCK);
        switch (msg) {
            case 0x29A:
                IrqMgr_HandleRetrace(irqMgr);
                break;

            case 0x29D:
                IrqMgr_HandlePreNMI(irqMgr);
                do {
                } while (0); // matching
                break;

            case 0x29F:
                IrqMgr_HandlePRENMI450(irqMgr);
                break;

            case 0x2A0:
                IrqMgr_HandlePRENMI480(irqMgr);
                break;

            case 0x2A1:
                IrqMgr_HandlePRENMI500(irqMgr);
                break;
        }
    }
}
