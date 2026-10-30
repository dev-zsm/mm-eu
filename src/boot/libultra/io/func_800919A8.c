// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 __osPfsReleasePages(OSPfs *pfs, __OSInode *inode, u8 startPage, u8 bank, __OSInodeUnit *finalPage) {
    __OSInodeUnit lastPage;
    __OSInodeUnit oldPage;

    lastPage.ipage = (bank << 8) + startPage;
    do {
        oldPage = lastPage;
        lastPage = inode->inodePage[lastPage.inode_t.page];
        inode->inodePage[oldPage.inode_t.page].ipage = 3;
    } while (lastPage.ipage >= pfs->inodeStartPage && lastPage.inode_t.bank == bank);
    *finalPage = lastPage;
    return 0;
}
