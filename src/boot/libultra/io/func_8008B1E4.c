// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: Dir is declared 0x1C bytes (the real entry is 0x20) to get the original frame size
#include "types.h"

typedef struct {
    u32 status;
    void *queue;
    s32 channel;
    u8 pad0C[0x44];
    s32 dirSize;
    u8 pad54[8];
    s32 dirTable;
    s32 inodeStartPage;
    u8 banks;
    u8 activeBank;
} Pfs;

typedef union {
    u16 ipage;
    struct {
        u8 bank;
        u8 page;
    } t;
} InodeUnit;

typedef struct {
    u32 gameCode;
    u16 companyCode;
    InodeUnit startPage;
    u8 status;
    u8 pad[0x13];
} Dir;

typedef struct {
    u8 pad[0x100];
} Inode;

s32 __osPfsGetNextPage(Pfs *pfs, u8 *bank, Inode *inode, InodeUnit *page);
s32 __osPfsGetStatus(void *queue, s32 channel);
s32 __osCheckId(Pfs *pfs);
s32 __osContRamRead(void *queue, s32 channel, u16 address, void *buffer);
s32 __osPfsSelectBank(Pfs *pfs, u8 bank);
s32 __osContRamWrite(void *queue, s32 channel, u16 address, void *buffer, s32 force);

s32 osPfsReadWriteFile(Pfs *pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8 *data) {
    u16 blockno;
    s32 ret;
    Dir dir;
    Inode inode;
    InodeUnit curPage;
    s32 curBlock;
    s32 blockSize;
    u8 *buffer;
    u8 bank;

    if (fileNo >= pfs->dirSize || fileNo < 0) {
        return 5;
    }
    if (size <= 0 || (size & 0x1F)) {
        return 5;
    }
    if (offset < 0 || (offset & 0x1F)) {
        return 5;
    }
    if (!(pfs->status & 1)) {
        return 5;
    }
    if (__osCheckId(pfs) == 2) {
        return 2;
    }
    if (pfs->activeBank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + fileNo, &dir);
    if (ret != 0) {
        return ret;
    }
    if (dir.companyCode == 0 || dir.gameCode == 0) {
        return 5;
    }
    if (dir.startPage.ipage < pfs->inodeStartPage || dir.startPage.t.bank >= pfs->banks || dir.startPage.t.page <= 0 ||
        dir.startPage.t.page >= 0x80) {
        if (dir.startPage.ipage == 1) {
            return 5;
        }
        return 3;
    }
    if (flag == 0 && !(dir.status & 2)) {
        return 6;
    }
    bank = 0xFF;
    curBlock = offset / 32;
    curPage = dir.startPage;
    while (curBlock >= 8) {
        ret = __osPfsGetNextPage(pfs, &bank, &inode, &curPage);
        if (ret != 0) {
            return ret;
        }
        curBlock -= 8;
    }
    buffer = data;
    blockSize = size / 32;
    while (blockSize > 0) {
        if (curBlock == 8) {
            ret = __osPfsGetNextPage(pfs, &bank, &inode, &curPage);
            if (ret != 0) {
                return ret;
            }
            curBlock = 0;
        }
        if (pfs->activeBank != curPage.t.bank) {
            ret = __osPfsSelectBank(pfs, curPage.t.bank);
            if (ret != 0) {
                return ret;
            }
        }
        blockno = curPage.t.page * 8 + curBlock;
        if (flag == 0) {
            ret = __osContRamRead(pfs->queue, pfs->channel, blockno, buffer);
        } else {
            ret = __osContRamWrite(pfs->queue, pfs->channel, blockno, buffer, 0);
        }
        buffer += 32;
        if (ret != 0) {
            return ret;
        }
        blockSize--;
        curBlock++;
    }
    if (flag == 1 && !(dir.status & 2)) {
        dir.status |= 2;
        if (pfs->activeBank != 0) {
            ret = __osPfsSelectBank(pfs, 0);
            if (ret != 0) {
                return ret;
            }
        }
        ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + fileNo, &dir, 0);
        if (ret != 0) {
            return ret;
        }
    }
    return __osPfsGetStatus(pfs->queue, pfs->channel);
}
