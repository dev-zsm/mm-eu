// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 osPfsFreeBlocks(OSPfs *pfs, s32 *bytesNotUsed) {
    /* declaration order decides the stack layout (matching) */
    s32 usedPages;
    s32 start;
    __OSInode inode;
    s32 j;
    s32 ret;
    u8 bank;

    usedPages = 0;
    if (!(pfs->status & PFS_INITIALIZED)) {
        return PFS_ERR_INVALID;
    }
    ret = __osCheckId(pfs);
    if (ret != 0) {
        return ret;
    }
    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &inode, 0, bank);
        if (ret != 0) {
            return ret;
        }
        if (bank > 0) { start = 1; } else { start = pfs->inodeStartPage; }
        for (j = start; j < PFS_INODE_ENTRIES; j++) {
            if (inode.inodePage[j].ipage == 3) {
                usedPages++;
            }
        }
    }
    *bytesNotUsed = usedPages << 8;
    return 0;
}
