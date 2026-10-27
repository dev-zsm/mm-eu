// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u16 type;
    u8 pri;
    u8 status;
    void *retQueue;
} OSMesgHdr;

typedef struct {
    OSMesgHdr hdr;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    void *piHandle;
} OSIoMesg;

typedef struct {
    u8 pad[0x18];
} OSMesgQueue;

extern u32 D_80096CF0;
extern void *D_80096CE0;
extern s32 osEPiStartDma(void *handle, OSIoMesg *mb, s32 dir);
extern s32 osRecvMesg(OSMesgQueue *mq, void *msg, s32 flag);
extern void osCreateMesgQueue(OSMesgQueue *mq, void *msgBuf, s32 count);
extern void osInvalDCache(void *addr, u32 size);

s32 func_800807E0(u32 romStart, u8 *vramStart, u32 size) {
    OSIoMesg ioMsg;
    OSMesgQueue queue;
    s32 msg;
    s32 ret;
    u32 buffSize;

    buffSize = D_80096CF0;
    osInvalDCache(vramStart, size);
    osCreateMesgQueue(&queue, &msg, 1);
    if (buffSize != 0 && buffSize < size) {
        do {
            ioMsg.hdr.pri = 0;
            ioMsg.hdr.retQueue = &queue;
            ioMsg.devAddr = romStart;
            ioMsg.dramAddr = vramStart;
            ioMsg.size = buffSize;
            ret = osEPiStartDma(D_80096CE0, &ioMsg, 0);
            if (ret != 0) {
                goto END;
            }
            osRecvMesg(&queue, 0, 1);
            size -= buffSize;
            romStart += buffSize;
            vramStart += buffSize;
        } while (buffSize < size);
    }
    ioMsg.hdr.pri = 0;
    ioMsg.hdr.retQueue = &queue;
    ioMsg.devAddr = romStart;
    ioMsg.dramAddr = vramStart;
    ioMsg.size = size;
    ret = osEPiStartDma(D_80096CE0, &ioMsg, 0);
    if (ret == 0) {
        osRecvMesg(&queue, 0, 1);
        osInvalDCache(vramStart, size);
    }
END:
    return ret;
}
