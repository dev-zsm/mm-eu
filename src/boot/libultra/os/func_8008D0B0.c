// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 __osCheckId(OSPfs *pfs) {
    u8 temp[0x20];
    s32 ret;
    s32 selectRet;

    if (pfs->activeBank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        selectRet = ret;
        if (ret == PFS_ERR_NEW_PACK) {
            ret = __osPfsSelectBank(pfs, 0);
            selectRet = ret;
        }
        if (ret != 0) {
            return selectRet;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0) {
        if (ret != PFS_ERR_NEW_PACK) {
            return ret;
        }
        ret = __osContRamRead(pfs->queue, pfs->channel, 1, temp);
        if (ret != 0) {
            return ret;
        }
    }
    if (bcmp(pfs->id, temp, 0x20) != 0) {
        return PFS_ERR_NEW_PACK;
    }
    return 0;
}
