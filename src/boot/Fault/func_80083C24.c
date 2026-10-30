// FLAGS: -O2 -g3 -mips2 -trapuv
#include "fault.h"
#include "libc.h"

void Fault_Init(void) {
    bzero(D_8009C220 = &D_8009C850, sizeof(FaultMgr));
    FaultDrawer_Init();
    FaultDrawer_SetInputCallback(Fault_WaitForInput);
    D_8009C220->exit = 0;
    D_8009C220->msgId = 0;
    D_8009C220->faultHandlerEnabled = 0;
    D_8009C220->faultedThread = NULL;
    D_8009C220->padCallback = Fault_PadCallback;
    D_8009C220->clients = NULL;
    D_8009C220->autoScroll = 0;
    D_8009D01E = 1;
    osCreateMesgQueue(&D_8009C220->queue, D_8009C220->msg, 1);
    StackCheck_Init(&D_8009C830, D_8009C230, D_8009C230 + sizeof(D_8009C230), 0, 0x100, D_80098E68);
    osCreateThread(&D_8009C220->thread, 2, Fault_ThreadEntry, NULL, &D_8009C830, 0x7F);
    osStartThread(&D_8009C220->thread);
}
