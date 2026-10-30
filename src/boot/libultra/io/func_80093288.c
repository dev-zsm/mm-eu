// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 __osPfsCheckRamArea(OSPfs *pfs) {
    s32 ret;
    s32 i;
    u8 pattern[PFS_BLOCKSIZE];
    u8 readback[PFS_BLOCKSIZE];
    u8 backup[PFS_BLOCKSIZE];

    ret = __osPfsSelectBank(pfs, 0);
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 0, backup);
    if (ret != 0) {
        return ret;
    }
    for (i = 0; i < PFS_BLOCKSIZE; i++) {
        pattern[i] = i;
    }
    ret = __osContRamWrite(pfs->queue, pfs->channel, 0, pattern, 0);
    if (ret != 0) {
        return ret;
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, 0, readback);
    if (ret != 0) {
        return ret;
    }
    if (bcmp(pattern, readback, PFS_BLOCKSIZE) != 0) {
        return PFS_ERR_DEVICE;
    }
    return __osContRamWrite(pfs->queue, pfs->channel, 0, backup, 0);
}
