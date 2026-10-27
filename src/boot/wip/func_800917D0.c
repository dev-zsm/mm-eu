// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// best attempt: 3 instr differ (two byte loads of the loop tail are swapped)
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
    u8 pad[0x17];
} Dir;

typedef struct {
    u8 pad[0x100];
} Inode;

s32 osPfsFindFile(Pfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName, s32 *fileNo);
s32 __osPfsSelectBank(Pfs *pfs, u8 bank);
s32 __osContRamRead(void *queue, s32 channel, u16 address, void *buffer);
s32 __osPfsRWInode(Pfs *pfs, Inode *inode, u8 flag, u8 bank);
s32 __osPfsReleasePages(Pfs *pfs, Inode *inode, u8 startPage, u8 bank, InodeUnit *lastPage);
void bzero(void *p, u32 n);
s32 __osContRamWrite(void *queue, s32 channel, u16 address, void *buffer, s32 force);

s32 osPfsDeleteFile(Pfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName) {
s32 fileNo; s32 pad; Inode inode; Dir dir; InodeUnit lastPage;
    s32 ret;
    u8 bank;
    u8 startPage;

    if (companyCode == 0 || gameCode == 0) {
        return 5;
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
    ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + fileNo, &dir);
    if (ret != 0) {
        return ret;
    }
    bank = dir.startPage.t.bank;
    startPage = dir.startPage.t.page;
    if (bank < pfs->banks) {
        do {
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
            bank = lastPage.t.bank;
            startPage = lastPage.t.page;
        } while (bank < pfs->banks);
    }
    if (bank >= pfs->banks) {
        return 3;
    }
    bzero(&dir, 0x20);
    return __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + fileNo, &dir, 0);
}
