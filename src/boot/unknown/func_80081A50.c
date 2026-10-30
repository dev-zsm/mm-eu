// FLAGS: -O2 -g3 -mips2 -trapuv
#include "os_internal.h"

void func_80081A50(FaultClient *client, FaultClientCallback callback, void *arg0, void *arg1) {
    OSIntMask mask;
    s32 isRegistered = 0;

    mask = osSetIntMask(OS_IM_NONE);
    {
        FaultClient *iter = D_8009C220->clients;

        while (iter != NULL) {
            if (iter == client) {
                isRegistered = 1;
                goto end;
            }
            iter = iter->next;
        }
    }
    client->callback = callback;
    client->arg0 = arg0;
    client->arg1 = arg1;
    client->next = D_8009C220->clients;
    D_8009C220->clients = client;
end:
    osSetIntMask(mask);
    if (isRegistered) {
        func_8008198C(D_80098744, client);
    }
}
