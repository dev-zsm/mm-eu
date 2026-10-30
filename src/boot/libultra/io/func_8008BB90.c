// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 osPfsAllocateFile(OSPfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName, s32 fileSizeInBytes,
                      s32 *fileNo) {
    s32 startPage;
    s32 declPage;
    s32 lastPage;
    s32 ret;
    s32 fileSizeInPages;
    s32 prevPage = 0;
    __OSInode inode;
    __OSInode backup;
    __OSDir dir;
    u8 oldBank = 0;
    s32 j = 0;
    s32 freeBytes;
    __OSInodeUnit firstPage;
    u8 bank;

    if (companyCode == 0 || gameCode == 0) {
        return PFS_ERR_INVALID;
    }
    fileSizeInPages = (fileSizeInBytes + PFS_PAGE_SIZE - 1) / PFS_PAGE_SIZE;
    ret = osPfsFindFile(pfs, companyCode, gameCode, gameName, extName, fileNo);
    if (ret != 0 && ret != PFS_ERR_INVALID) {
        return ret;
    }
    if (*fileNo != -1) {
        return PFS_ERR_EXIST;
    }
    osPfsFreeBlocks(pfs, &freeBytes);
    if (freeBytes < fileSizeInBytes) {
        return PFS_DATA_FULL;
    }
    if (fileSizeInPages == 0) {
        return PFS_ERR_INVALID;
    }
    ret = osPfsFindFile(pfs, 0, 0, NULL, NULL, fileNo);
    if (ret != 0 && ret != PFS_ERR_INVALID) {
        return ret;
    }
    if (*fileNo == -1) {
        return PFS_DIR_FULL;
    }
    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &inode, 0, bank);
        if (ret != 0) {
            return ret;
        }
        ret = __osPfsDeclearPage(pfs, &inode, fileSizeInPages, &startPage, bank, &declPage, &lastPage);
        if (ret != 0) {
            return ret;
        }
        if (startPage != -1) {
            if (j == 0) {
                firstPage.inode_t.page = startPage;
                firstPage.inode_t.bank = bank;
            } else {
                backup.inodePage[prevPage].inode_t.bank = bank;
                backup.inodePage[prevPage].inode_t.page = startPage;
                ret = __osPfsRWInode(pfs, &backup, 1, oldBank);
                if (ret != 0) {
                    return ret;
                }
            }
            if (declPage < fileSizeInPages) {
                bcopy(&inode, &backup, PFS_PAGE_SIZE);
                prevPage = lastPage;
                oldBank = bank;
                j++;
                fileSizeInPages -= declPage;
            } else {
                fileSizeInPages = 0;
                ret = __osPfsRWInode(pfs, &inode, 1, bank);
                if (ret != 0) {
                    return ret;
                }
                break;
            }
        }
    }
    if (fileSizeInPages > 0 || startPage == -1) {
        return PFS_ERR_INCONSISTENT;
    }
    dir.startPage = firstPage;
    dir.dataSum = 0;
    dir.companyCode = companyCode;
    dir.gameCode = gameCode;
    bcopy(gameName, dir.gameName, 16);
    bcopy(extName, dir.extName, 4);
    return __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + *fileNo, (u8 *)&dir, 0);
}
