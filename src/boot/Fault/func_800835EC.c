// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"

void Fault_ProcessClients(void) {
    FaultClient *client = D_8009C220->clients;
    s32 idx = 0;

    while (client != NULL) {
        if (client->callback != NULL) {
            Fault_FillScreenBlack();
            FaultDrawer_SetCharPad(-2, 0);
            FaultDrawer_Printf(D_80098CB0, idx++, client, client->arg0, client->arg1);
            FaultDrawer_SetCharPad(0, 0);
            client->callback(client->arg0, client->arg1);
            Fault_WaitForInput();
            Fault_DisplayFrameBuffer();
        }
        client = client->next;
    }
}
