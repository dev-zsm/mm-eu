// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 __osPfsGetNextPage(OSPfs *pfs, u8 *bank, __OSInode *inode, __OSInodeUnit *page) {
    s32 ret;
    u16 v;

    if (page->inode_t.bank != *bank) {
        *bank = page->inode_t.bank;
        ret = __osPfsRWInode(pfs, inode, 0, *bank);
        if (ret != 0) {
            return ret;
        }
    }
    *page = inode->inodePage[page->inode_t.page];
    v = page->ipage;
    if (v < pfs->inodeStartPage || page->inode_t.bank >= pfs->banks || page->inode_t.page <= 0 ||
        page->inode_t.page >= PFS_INODE_ENTRIES) {
        if (v == 1) {
            return PFS_ERR_INVALID;
        }
        return PFS_ERR_INCONSISTENT;
    }
    return 0;
}
