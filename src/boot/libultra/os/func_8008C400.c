// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    s32 errStatus;
    void *dramAddr;
    void *C2Addr;
    u32 sectorSize;
    s32 C1ErrNum;
    s32 C1ErrSector[4];
} BlockInfo;

typedef struct {
    u32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    u32 unkC;
    u32 bmCtlShadow;
    u32 seqCtlShadow;
    BlockInfo block[2];
} TranxInfo;

typedef struct PiHandle {
    struct PiHandle *next;
    u8 type;
    u8 latency;
    u8 pageSize;
    u8 relDuration;
    u8 pulse;
    u8 domain;
    u8 pad[2];
    u32 baseAddress;
    u32 speed;
    TranxInfo transferInfo;
} PiHandle;

typedef struct {
    struct {
        u16 type;
        u8 pri;
        u8 status;
        void *retQueue;
    } hdr;
    void *dramAddr;
    u32 devAddr;
    u32 size;
    PiHandle *piHandle;
} IoMesg;

typedef struct {
    s32 active;
    void *thread;
    void *cmdQueue;
    void *evtQueue;
    void *acsQueue;
    s32 (*dma)(s32, u32, void *, u32);
    s32 (*edma)(PiHandle *, s32, u32, void *, u32);
} DevMgr;

void osRecvMesg(void *mq, void *msg, s32 flag);
void osSendMesg(void *mq, void *msg, s32 flag);
void __osResetGlobalIntMask(u32 mask);
void __osSetGlobalIntMask(u32 mask);
void __osEPiRawWriteIo(PiHandle *handle, u32 devAddr, u32 data);
void __osEPiRawReadIo(PiHandle *handle, u32 devAddr, u32 *data);
void osYieldThread(void);

void __osDevMgrMain(void *args) {
    IoMesg *mb;
    void *dummy;
    void *em;
    s32 ret;
    DevMgr *dm;
    TranxInfo *info;
    BlockInfo *block;
    s32 messageSend;
    u32 stat;

    dm = args;
    mb = NULL;
    while (1) {
        osRecvMesg(dm->cmdQueue, &mb, 1);
        if (mb->piHandle != NULL && mb->piHandle->type == 2 &&
            (mb->piHandle->transferInfo.cmdType == 0 || mb->piHandle->transferInfo.cmdType == 1)) {
            info = &mb->piHandle->transferInfo;
            block = &info->block[info->blockNum];
            info->sectorNum = -1;
            if (info->transferMode != 3) {
                block->dramAddr = (u8 *)block->dramAddr - block->sectorSize;
            }
            if (info->transferMode == 2 && mb->piHandle->transferInfo.cmdType == 0) {
                messageSend = 1;
            } else {
                messageSend = 0;
            }
            osRecvMesg(dm->acsQueue, &em, 1);
            __osResetGlobalIntMask(0x100401);
            __osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x80000000);
            while (1) {
                osRecvMesg(dm->evtQueue, &dummy, 1);
                info = &mb->piHandle->transferInfo;
                block = &info->block[info->blockNum];
                if (block->errStatus == 0x1D) {
                    __osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x10000000);
                    __osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow);
                    __osEPiRawReadIo(mb->piHandle, 0x05000508, &stat);
                    if (stat & 0x02000000) {
                        __osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x01000000);
                    }
                    block->errStatus = 4;
                    *(volatile u32 *)0xA4600010 = 2;
                    __osSetGlobalIntMask(0x100C01);
                }
                osSendMesg(mb->hdr.retQueue, mb, 0);
                if (messageSend == 1 && mb->piHandle->transferInfo.block[0].errStatus == 0) {
                    messageSend = 0;
                    continue;
                }
                break;
            }
            osSendMesg(dm->acsQueue, NULL, 0);
            if (mb->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
            continue;
        }
        switch (mb->hdr.type) {
            case 11:
                osRecvMesg(dm->acsQueue, &em, 1);
                ret = dm->dma(0, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case 12:
                osRecvMesg(dm->acsQueue, &em, 1);
                ret = dm->dma(1, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case 15:
                osRecvMesg(dm->acsQueue, &em, 1);
                ret = dm->edma(mb->piHandle, 0, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case 16:
                osRecvMesg(dm->acsQueue, &em, 1);
                ret = dm->edma(mb->piHandle, 1, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case 10:
                osSendMesg(mb->hdr.retQueue, mb, 0);
                ret = -1;
                break;
            default:
                ret = -1;
                break;
        }
        if (ret == 0) {
            osRecvMesg(dm->evtQueue, &dummy, 1);
            osSendMesg(mb->hdr.retQueue, mb, 0);
            osSendMesg(dm->acsQueue, NULL, 0);
        }
    }
}
