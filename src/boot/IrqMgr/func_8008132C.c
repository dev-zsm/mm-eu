// FLAGS: -O2 -g3
#include "irqmgr.h"

void IrqMgr_RemoveClient(IrqMgr *irqMgr, IrqMgrClient *client) {
    IrqMgrClient *cur;
    IrqMgrClient *prev;
    OSIntMask mask;

    prev = NULL;
    cur = irqMgr->clients;
    mask = osSetIntMask(1);
    while (cur != NULL) {
        if (cur == client) {
            if (prev != NULL) {
                prev->next = client->next;
            } else {
                irqMgr->clients = client->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    osSetIntMask(mask);
}
