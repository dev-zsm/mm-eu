// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_RemoveClient(FaultClient *client) {
    FaultClient *iter;
    FaultClient *lastIter;
    OSIntMask mask;
    s32 listIsEmpty;

    iter = D_8009C220->clients;
    lastIter = NULL;
    listIsEmpty = 0;
    mask = osSetIntMask(OS_IM_NONE);
    while (iter != NULL) {
        if (iter == client) {
            if (lastIter != NULL) {
                lastIter->next = client->next;
            } else {
                D_8009C220->clients = client;
                if (D_8009C220->clients != NULL) {
                    D_8009C220->clients = client->next;
                } else {
                    listIsEmpty = 1;
                }
            }
            break;
        }
        lastIter = iter;
        iter = iter->next;
    }
    osSetIntMask(mask);
    if (listIsEmpty) {
        func_8008198C(D_8009877C, client);
    }
}
