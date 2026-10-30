// FLAGS: -O2 -g3 -mips2
#include "irqmgr.h"

void IrqMgr_JamMesgToClients(IrqMgr *irqMgr, OSMesg msg) {
    IrqMgrClient *client;
    OSMesgQueue *queue;

    client = irqMgr->clients;
    if (client != NULL) {
        do {
            queue = client->queue;
            if (queue->validCount < queue->msgCount) {
                osSendMesg(queue, msg, OS_MESG_NOBLOCK);
            }
            client = client->next;
        } while (client != NULL);
    }
}
