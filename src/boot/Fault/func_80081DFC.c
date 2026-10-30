// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

u32 Fault_ConvertAddress(u32 addr) {
    FaultAddrConvClient *client = D_8009C220->addrConvClients;
    u32 ret;

    while (client != NULL) {
        if (client->callback != NULL) {
            ret = client->callback(addr, client->arg);
            if (ret != 0) {
                return ret;
            }
        }
        client = client->next;
    }
    return 0;
}
