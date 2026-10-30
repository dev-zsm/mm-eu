// FLAGS: -O2 -g3
#include "irqmgr.h"

void IrqMgr_AddClient(IrqMgr *irqMgr, IrqMgrClient *client, OSMesgQueue *queue) {
    OSIntMask mask;

    mask = osSetIntMask(1);
    client->queue = queue;
    client->next = irqMgr->clients;
    irqMgr->clients = client;
    osSetIntMask(mask);
    if (irqMgr->resetStatus > 0) {
        osSendMesg(client->queue, &irqMgr->prenmiMsg, OS_MESG_NOBLOCK);
    }
    if (irqMgr->resetStatus >= 2) {
        osSendMesg(client->queue, &irqMgr->prenmi450Msg, OS_MESG_NOBLOCK);
    }
}
