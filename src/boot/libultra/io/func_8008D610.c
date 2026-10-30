// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 osPfsFindFile(OSPfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName, s32 *fileNo) {
    s32 i;
    s32 ret;
    __OSDir dir;
    s32 j;
    s32 mismatch;

    if (!(pfs->status & PFS_INITIALIZED)) {
        return PFS_ERR_INVALID;
    }
    ret = __osCheckId(pfs);
    if (ret != 0) {
        return ret;
    }
    for (i = 0; i < pfs->dirSize; i++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, (u16)(pfs->dirTable + i), (u8 *)&dir);
        if (ret != 0) {
            return ret;
        }
        ret = __osPfsGetStatus(pfs->queue, pfs->channel);
        if (ret != 0) {
            return ret;
        }
        if (dir.companyCode == companyCode && dir.gameCode == gameCode) {
            mismatch = 0;
            if (gameName != NULL) {
                for (j = 0; j < 16; j++) {
                    if (dir.gameName[j] != gameName[j]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (extName != NULL && mismatch == 0) {
                for (j = 0; j < 4; j++) {
                    if (dir.extName[j] != extName[j]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (mismatch == 0) {
                *fileNo = i;
                return ret;
            }
        }
    }
    *fileNo = -1;
    return PFS_ERR_INVALID;
}
