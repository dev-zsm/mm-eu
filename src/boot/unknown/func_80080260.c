// FLAGS: -O2 -g0 -mips2
#include "os_internal.h"
#include "dmamgr.h"

void func_80080260(void) {
    DmaRequest req;
    OSMesgQueue queue;
    OSMesg msg;
    u32 savedChunk;

    osCreateMesgQueue(&queue, &msg, 1);
    savedChunk = D_80096CF0;
    D_80096CF0 = 0;
    DmaMgr_RequestAsync(&req, D_800A5FE0, (u32)D_C8A000, D_DBF850 - D_C8A000, 0, &queue, NULL);
    func_8008019C();
    func_800801FC();
    osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
    D_80096CF0 = savedChunk;
    func_80080150(D_801DB830, D_802006E0);
}
