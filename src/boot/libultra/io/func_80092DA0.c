// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 __osPfsSelectBank(OSPfs *pfs, u8 bank) {
    u8 temp[PFS_BLOCKSIZE];
    s32 i;
    s32 ret;

    for (i = 0; i < PFS_BLOCKSIZE; i++) {
        temp[i] = bank;
    }
    ret = __osContRamWrite(pfs->queue, pfs->channel, 0x400, temp, 0);
    if (ret == 0) {
        pfs->activeBank = bank;
    }
    return ret;
}
