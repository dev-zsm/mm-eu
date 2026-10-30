// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, s32 channel) {
    s32 ret;
    u16 sum;
    u16 isum;
    u8 temp[PFS_BLOCKSIZE];
    u8 *id;
    __OSPackId newid;

    __osSiGetAccess();
    ret = __osPfsGetStatus(queue, channel);
    __osSiRelAccess();
    if (ret != 0) {
        return ret;
    }
    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;
    ret = __osPfsCheckRamArea(pfs);
    if (ret != 0) {
        return ret;
    }
    ret = __osPfsSelectBank(pfs, 0);
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0) {
        return ret;
    }
    __osIdCheckSum((u16 *)temp, &sum, &isum);
    id = temp;
    if (((__OSPackId *)temp)->checksum != sum || ((__OSPackId *)temp)->invertedChecksum != isum) {
        ret = __osCheckPackId(pfs, (__OSPackId *)temp);
        if (ret != 0) {
            pfs->status |= PFS_ID_BROKEN;
            return ret;
        }
    }
    if (!(((__OSPackId *)temp)->deviceid & 1)) {
        ret = __osRepairPackId(pfs, (__OSPackId *)temp, &newid);
        if (ret != 0) {
            if (ret == PFS_ERR_ID_FATAL) {
                pfs->status |= PFS_ID_BROKEN;
            }
            return ret;
        }
        id = (u8 *)&newid;
        if (!(newid.deviceid & 1)) {
            return PFS_ERR_DEVICE;
        }
    }
    bcopy(id, pfs->id, PFS_BLOCKSIZE);
    pfs->version = id[0x1B];
    pfs->banks = id[0x1A];
    pfs->inodeStartPage = pfs->banks * 2 + 3;
    pfs->dirSize = 0x10;
    pfs->inodeTable = 8;
    pfs->minodeTable = pfs->inodeTable + pfs->banks * 8;
    pfs->dirTable = pfs->minodeTable + pfs->banks * 8;
    ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);
    if (ret != 0) {
        return ret;
    }
    ret = osPfsChecker(pfs);
    pfs->status |= PFS_INITIALIZED;
    return ret;
}
