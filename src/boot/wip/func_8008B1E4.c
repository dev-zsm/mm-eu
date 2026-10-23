// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// best attempt: 46 instr differ = same instruction sequence, but the frame is 8 bytes too big (376 vs 368) so every sp offset shifts; one sh is scheduled differently
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
    u8 pad[0x1B];
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

s32 osPfsReadWriteFile(Pfs *pfs, s32 fileNo, u8 flag, s32 offset, s32 size, u8 *buffer) {
    Dir dir;
    Inode inode;
    InodeUnit curPage;
    u8 bank;
    s32 ret;
    s32 index;
    s32 blocks;
    u16 address;
    u8 *ptr;

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
    curPage = dir.startPage;
    index = offset / 32;
    while (index >= 8) {
        ret = __osPfsGetNextPage(pfs, &bank, &inode, &curPage);
        if (ret != 0) {
            return ret;
        }
        index -= 8;
    }
    ptr = buffer;
    blocks = size / 32;
    while (blocks > 0) {
        if (index == 8) {
            ret = __osPfsGetNextPage(pfs, &bank, &inode, &curPage);
            if (ret != 0) {
                return ret;
            }
            index = 0;
        }
        if (curPage.t.bank != pfs->activeBank) {
            ret = __osPfsSelectBank(pfs, curPage.t.bank);
            if (ret != 0) {
                return ret;
            }
        }
        address = curPage.t.page * 8 + index;
        if (flag == 0) {
            ret = __osContRamRead(pfs->queue, pfs->channel, address, ptr);
        } else {
            ret = __osContRamWrite(pfs->queue, pfs->channel, address, ptr, 0);
        }
        ptr += 32;
        if (ret != 0) {
            return ret;
        }
        blocks--;
        index++;
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
