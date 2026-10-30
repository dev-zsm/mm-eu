// FLAGS: -O2 -g3 -mips2
#include "os_internal.h"
#include "os_sp.h"
#include "dmamgr.h"

s32 func_800807E0(u32 romStart, void *ramStart, u32 size) {
    OSIoMesg ioMsg;
    OSMesgQueue queue;
    OSMesg msg;
    s32 ret;
    u32 buffSize;

    buffSize = D_80096CF0;
    osInvalDCache(ramStart, size);
    osCreateMesgQueue(&queue, &msg, 1);
    if (buffSize != 0 && buffSize < size) {
        do {
            ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
            ioMsg.hdr.retQueue = &queue;
            ioMsg.devAddr = romStart;
            ioMsg.dramAddr = ramStart;
            ioMsg.size = buffSize;
            ret = osEPiStartDma(D_80096CE0, &ioMsg, OS_READ);
            if (ret != 0) {
                goto END;
            }
            osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
            size -= buffSize;
            romStart += buffSize;
            ramStart = (u8 *)ramStart + buffSize;
        } while (buffSize < size);
    }
    ioMsg.hdr.pri = OS_MESG_PRI_NORMAL;
    ioMsg.hdr.retQueue = &queue;
    ioMsg.devAddr = romStart;
    ioMsg.dramAddr = ramStart;
    ioMsg.size = size;
    ret = osEPiStartDma(D_80096CE0, &ioMsg, OS_READ);
    if (ret == 0) {
        osRecvMesg(&queue, NULL, OS_MESG_BLOCK);
        osInvalDCache(ramStart, size);
    }
END:
    return ret;
}
