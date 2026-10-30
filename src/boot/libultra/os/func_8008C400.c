// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "ultra64.h"

void __osDevMgrMain(void *args) {
    OSIoMesg *mb;
    OSMesg dummy;
    OSMesg em;
    s32 ret;
    OSDevMgr *dm;
    __OSTranxInfo *info;
    __OSBlockInfo *block;
    s32 messageSend;
    u32 stat;

    dm = args;
    mb = NULL;
    while (1) {
        osRecvMesg(dm->cmdQueue, (OSMesg *)&mb, OS_MESG_BLOCK);
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
            osRecvMesg(dm->acsQueue, &em, OS_MESG_BLOCK);
            __osResetGlobalIntMask(0x100401);
            __osEPiRawWriteIo(mb->piHandle, 0x05000510, info->bmCtlShadow | 0x80000000);
            while (1) {
                osRecvMesg(dm->evtQueue, &dummy, OS_MESG_BLOCK);
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
                    IO_WRITE(PI_STATUS_REG, 2);
                    __osSetGlobalIntMask(0x100C01);
                }
                osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                if (messageSend == 1 && mb->piHandle->transferInfo.block[0].errStatus == 0) {
                    messageSend = 0;
                    continue;
                }
                break;
            }
            osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
            if (mb->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
            continue;
        }
        switch (mb->hdr.type) {
            case OS_MESG_TYPE_DMAREAD:
                osRecvMesg(dm->acsQueue, &em, OS_MESG_BLOCK);
                ret = dm->dma(OS_READ, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case OS_MESG_TYPE_DMAWRITE:
                osRecvMesg(dm->acsQueue, &em, OS_MESG_BLOCK);
                ret = dm->dma(OS_WRITE, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case OS_MESG_TYPE_EDMAREAD:
                osRecvMesg(dm->acsQueue, &em, OS_MESG_BLOCK);
                ret = dm->edma(mb->piHandle, OS_READ, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case OS_MESG_TYPE_EDMAWRITE:
                osRecvMesg(dm->acsQueue, &em, OS_MESG_BLOCK);
                ret = dm->edma(mb->piHandle, OS_WRITE, mb->devAddr, mb->dramAddr, mb->size);
                break;
            case OS_MESG_TYPE_LOOPBACK:
                osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
                ret = -1;
                break;
            default:
                ret = -1;
                break;
        }
        if (ret == 0) {
            osRecvMesg(dm->evtQueue, &dummy, OS_MESG_BLOCK);
            osSendMesg(mb->hdr.retQueue, mb, OS_MESG_NOBLOCK);
            osSendMesg(dm->acsQueue, NULL, OS_MESG_NOBLOCK);
        }
    }
}
