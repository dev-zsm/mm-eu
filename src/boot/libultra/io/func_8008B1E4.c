// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 osPfsReadWriteFile(OSPfs *pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8 *data) {
    u16 blockno;
    s32 ret;
    /* matching: the frame only fits if the entry is declared 4 bytes short (the real entry is 0x20) */
    struct {
        u32 gameCode;
        u16 companyCode;
        __OSInodeUnit startPage;
        u8 status;
        u8 pad[0x13];
    } dir;
    __OSInode inode;
    __OSInodeUnit curPage;
    s32 curBlock;
    s32 blockSize;
    u8 *buffer;
    u8 bank;

    if (fileNo >= pfs->dirSize || fileNo < 0) {
        return PFS_ERR_INVALID;
    }
    if (size <= 0 || (size & (PFS_BLOCKSIZE - 1))) {
        return PFS_ERR_INVALID;
    }
    if (offset < 0 || (offset & (PFS_BLOCKSIZE - 1))) {
        return PFS_ERR_INVALID;
    }
    if (!(pfs->status & PFS_INITIALIZED)) {
        return PFS_ERR_INVALID;
    }
    if (__osCheckId(pfs) == PFS_ERR_NEW_PACK) {
        return PFS_ERR_NEW_PACK;
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
    if (dir.companyCode == 0 || dir.gameCode == 0) {
        return PFS_ERR_INVALID;
    }
    if (dir.startPage.ipage < pfs->inodeStartPage || dir.startPage.inode_t.bank >= pfs->banks ||
        dir.startPage.inode_t.page <= 0 || dir.startPage.inode_t.page >= PFS_INODE_ENTRIES) {
        if (dir.startPage.ipage == 1) {
            return PFS_ERR_INVALID;
        }
        return PFS_ERR_INCONSISTENT;
    }
    if (flag == PFS_READ && !(dir.status & 2)) {
        return PFS_ERR_BAD_DATA;
    }
    bank = 0xFF;
    curBlock = offset / PFS_BLOCKSIZE;
    curPage = dir.startPage;
    while (curBlock >= PFS_ONE_PAGE) {
        ret = __osPfsGetNextPage(pfs, &bank, &inode, &curPage);
        if (ret != 0) {
            return ret;
        }
        curBlock -= PFS_ONE_PAGE;
    }
    buffer = data;
    blockSize = size / PFS_BLOCKSIZE;
    while (blockSize > 0) {
        if (curBlock == PFS_ONE_PAGE) {
            ret = __osPfsGetNextPage(pfs, &bank, &inode, &curPage);
            if (ret != 0) {
                return ret;
            }
            curBlock = 0;
        }
        if (pfs->activeBank != curPage.inode_t.bank) {
            ret = __osPfsSelectBank(pfs, curPage.inode_t.bank);
            if (ret != 0) {
                return ret;
            }
        }
        blockno = curPage.inode_t.page * PFS_ONE_PAGE + curBlock;
        if (flag == PFS_READ) {
            ret = __osContRamRead(pfs->queue, pfs->channel, blockno, buffer);
        } else {
            ret = __osContRamWrite(pfs->queue, pfs->channel, blockno, buffer, 0);
        }
        buffer += PFS_BLOCKSIZE;
        if (ret != 0) {
            return ret;
        }
        blockSize--;
        curBlock++;
    }
    if (flag == PFS_WRITE && !(dir.status & 2)) {
        dir.status |= 2;
        if (pfs->activeBank != 0) {
            ret = __osPfsSelectBank(pfs, 0);
            if (ret != 0) {
                return ret;
            }
        }
        ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&dir, 0);
        if (ret != 0) {
            return ret;
        }
    }
    return __osPfsGetStatus(pfs->queue, pfs->channel);
}
