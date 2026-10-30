// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "libc.h"
#include "os_pfs.h"

s32 osPfsDeleteFile(OSPfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName) {
    s32 fileNo;
    s32 ret;
    __OSInode inode;
    __OSDir dir;
    __OSInodeUnit lastPage;
    u8 startPage;
    u8 bank;

    if (companyCode == 0 || gameCode == 0) {
        return PFS_ERR_INVALID;
    }
    ret = osPfsFindFile(pfs, companyCode, gameCode, gameName, extName, &fileNo);
    if (ret != 0) {
        return ret;
    }
    if (pfs->activeBank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&dir);
    if (ret != 0) {
        return ret;
    }
    bank = dir.startPage.inode_t.bank;
    startPage = dir.startPage.inode_t.page;
    for (; bank < pfs->banks;) {
        ret = __osPfsRWInode(pfs, &inode, 0, bank);
        if (ret != 0) {
            return ret;
        }
        ret = __osPfsReleasePages(pfs, &inode, startPage, bank, &lastPage);
        if (ret != 0) {
            return ret;
        }
        ret = __osPfsRWInode(pfs, &inode, 1, bank);
        if (ret != 0) {
            return ret;
        }
        if (lastPage.ipage == 1) {
            break;
        }
        bank = lastPage.inode_t.bank;
        startPage = lastPage.inode_t.page;
    }
    if (bank >= pfs->banks) {
        return PFS_ERR_INCONSISTENT;
    }
    bzero(&dir, sizeof(__OSDir));
    return __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&dir, 0);
}
