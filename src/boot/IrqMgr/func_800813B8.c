// FLAGS: -O2 -g3 -mips2
#include "irqmgr.h"

void IrqMgr_SendMesgToClients(IrqMgr *irqMgr, OSMesg msg) {
    IrqMgrClient *client;

    client = irqMgr->clients;
    if (client != NULL) {
        do {
            osSendMesg(client->queue, msg, OS_MESG_NOBLOCK);
            client = client->next;
        } while (client != NULL);
    }
}
