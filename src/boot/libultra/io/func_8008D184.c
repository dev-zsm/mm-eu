// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: offset via ternary, sum compared as inode->inodePage[0].inode_t.page != sum
#include "os_pfs.h"

s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank) {
    u8 sum;
    s32 j;
    s32 ret;
    s32 offset;
    u8 *addr;

    if (flag == PFS_READ && bank == D_800980F4 && pfs->channel == D_800980F0) {
        bcopy(&D_8009E7E0, inode, PFS_PAGE_SIZE);
        return 0;
    }
    if (pfs->activeBank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    offset = (bank > 0) ? 1 : pfs->inodeStartPage;
    if (flag == PFS_WRITE) {
        inode->inodePage[0].inode_t.page = __osSumcalc(addr = (u8 *)inode + offset * 2, -offset * 2 + PFS_PAGE_SIZE);
    }
    for (j = 0; j < PFS_ONE_PAGE; j++) {
        addr = (u8 *)inode + j * PFS_BLOCKSIZE;
        if (flag == PFS_WRITE) {
            __osContRamWrite(pfs->queue, pfs->channel, pfs->inodeTable + bank * PFS_ONE_PAGE + j, addr, 0);
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minodeTable + bank * PFS_ONE_PAGE + j, addr, 0);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inodeTable + bank * PFS_ONE_PAGE + j, addr);
        }
        if (ret != 0) {
            return ret;
        }
    }
    if (flag == PFS_READ) {
        sum = __osSumcalc(addr = (u8 *)inode + offset * 2, -offset * 2 + PFS_PAGE_SIZE);
        if (inode->inodePage[0].inode_t.page != sum) {
            for (j = 0; j < PFS_ONE_PAGE; j++) {
                addr = (u8 *)inode + j * PFS_BLOCKSIZE;
                __osContRamRead(pfs->queue, pfs->channel, pfs->minodeTable + bank * PFS_ONE_PAGE + j, addr);
            }
            sum = __osSumcalc(addr = (u8 *)inode + offset * 2, -offset * 2 + PFS_PAGE_SIZE);
            if (inode->inodePage[0].inode_t.page != sum) {
                return PFS_ERR_INCONSISTENT;
            }
            for (j = 0; j < PFS_ONE_PAGE; j++) {
                addr = (u8 *)inode + j * PFS_BLOCKSIZE;
                __osContRamWrite(pfs->queue, pfs->channel, pfs->inodeTable + bank * PFS_ONE_PAGE + j, addr, 0);
            }
        }
    }
    D_800980F4 = bank;
    bcopy(inode, &D_8009E7E0, PFS_PAGE_SIZE);
    D_800980F0 = pfs->channel;
    return 0;
}
