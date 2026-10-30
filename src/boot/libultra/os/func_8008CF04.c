// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 __osGetId(OSPfs *pfs) {
    u16 sum;
    u16 isum;
    u8 temp[32];
    __OSPackId newid;
    __OSPackId *id;
    s32 ret;

    if (pfs->activeBank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0) {
        return ret;
    }
    __osIdCheckSum((u16 *)temp, &sum, &isum);
    id = (__OSPackId *)temp;
    if (id->checksum != sum || id->invertedChecksum != isum) {
        ret = __osCheckPackId(pfs, id);
        if (ret == PFS_ERR_ID_FATAL) {
            ret = __osRepairPackId(pfs, id, &newid);
            if (ret != 0) {
                return ret;
            }
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }
    if (!(id->deviceid & 1)) {
        ret = __osRepairPackId(pfs, id, &newid);
        if (ret != 0) {
            return ret;
        }
        id = &newid;
        if (!(id->deviceid & 1)) {
            return PFS_ERR_DEVICE;
        }
    }
    bcopy(id, pfs->id, 0x20);
    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inodeStartPage = pfs->banks * 2 + 3;
    pfs->dirSize = 0x10;
    pfs->inodeTable = 8;
    pfs->minodeTable = pfs->inodeTable + pfs->banks * 8;
    pfs->dirTable = pfs->minodeTable + pfs->banks * 8;
    ret = __osContRamRead(pfs->queue, pfs->channel, 7, pfs->label);
    if (ret != 0) {
        return ret;
    }
    return 0;
}
