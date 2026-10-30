// FLAGS: -O2 -g0 -mips2
#include "os_pfs.h"

s32 __osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, s32 fileSizeInPages, s32 *startPage, u8 bank, s32 *decl,
                       s32 *lastPage) {
    s32 v;
    s32 idx;
    s32 found;
    s32 last;

    if (bank > 0) {
        v = 1;
    } else {
        v = pfs->inodeStartPage;
    }
    idx = v;
    while (idx < PFS_INODE_ENTRIES) {
        if (inode->inodePage[idx].ipage == 3) {
            break;
        }
        idx++;
    }
    if (idx == PFS_INODE_ENTRIES) {
        *startPage = -1;
        return 0;
    }
    found = idx;
    *decl = 1;
    last = found;
    idx = found + 1;
    if (fileSizeInPages >= 2 && idx < PFS_INODE_ENTRIES) {
        do {
            if (inode->inodePage[idx].ipage == 3) {
                inode->inodePage[last].inode_t.bank = bank;
                inode->inodePage[last].inode_t.page = idx;
                (*decl)++;
                last = idx;
            }
            idx++;
        } while (*decl < fileSizeInPages && idx < PFS_INODE_ENTRIES);
    }
    *startPage = found;
    if (idx == PFS_INODE_ENTRIES && *decl < fileSizeInPages) {
        *lastPage = last;
    } else {
        inode->inodePage[last].ipage = 1;
        *lastPage = 0;
    }
    return 0;
}
