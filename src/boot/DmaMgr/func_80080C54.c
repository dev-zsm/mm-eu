// FLAGS: -O2 -g3 -mips2
#include "dmamgr.h"
#include "irqmgr.h"

s32 DmaMgr_RequestAsync(DmaRequest *req, void *ram, u32 vrom, u32 size, u32 unused, OSMesgQueue *queue, OSMesg msg) {
    if (D_80096D00 >= 2) {
        return -2;
    }
    req->vromAddr = vrom;
    req->dramAddr = ram;
    req->size = size;
    req->unk14 = 0;
    req->notifyQueue = queue;
    req->notifyMsg = msg;
    osSendMesg(&D_8009B690, req, OS_MESG_BLOCK);
    return 0;
}
