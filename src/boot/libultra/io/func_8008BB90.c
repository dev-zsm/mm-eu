// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef union {
    struct {
        u8 bank;
        u8 page;
    } t;
    u16 ipage;
} InodeUnit;

typedef struct {
    InodeUnit inodePage[128];
} Inode;

typedef struct {
    u32 gameCode;
    u16 companyCode;
    InodeUnit startPage;
    u8 status;
    s8 reserved;
    u16 dataSum;
    u8 extName[4];
    u8 gameName[16];
} Dir;

typedef struct {
    s32 status;
    void *queue;
    s32 channel;
    u8 pad0[0x50];
    s32 dirTable;
    s32 inodeStartPage;
    u8 banks;
} Pfs;

s32 __osPfsDeclearPage(Pfs *pfs, Inode *inode, s32 fileSizeInPages, s32 *startPage, s32 bank, s32 *declPage, s32 *lastPage);
s32 __osPfsRWInode(Pfs *pfs, Inode *inode, u8 flag, u8 bank);
s32 osPfsFindFile(Pfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName, s32 *fileNo);
s32 osPfsFreeBlocks(Pfs *pfs, s32 *bytesNotUsed);
void bcopy(void *src, void *dst, s32 n);
s32 __osContRamWrite(void *mq, s32 channel, u16 address, u8 *buffer, s32 force);

s32 osPfsAllocateFile(Pfs *pfs, u16 companyCode, u32 gameCode, u8 *gameName, u8 *extName, s32 fileSizeInBytes, s32 *fileNo) {
    s32 startPage;
    s32 declPage;
    s32 lastPage;
    s32 ret;
    s32 fileSizeInPages;
    s32 prevPage = 0;
    Inode inode;
    Inode backup;
    Dir dir;
    u8 oldBank = 0;
    s32 j = 0;
    s32 freeBytes;
    InodeUnit firstPage;
    u8 bank;

    if (companyCode == 0 || gameCode == 0) {
        return 5;
    }
    fileSizeInPages = (fileSizeInBytes + 0xFF) / 0x100;
    ret = osPfsFindFile(pfs, companyCode, gameCode, gameName, extName, fileNo);
    if (ret != 0 && ret != 5) {
        return ret;
    }
    if (*fileNo != -1) {
        return 9;
    }
    osPfsFreeBlocks(pfs, &freeBytes);
    if (freeBytes < fileSizeInBytes) {
        return 7;
    }
    if (fileSizeInPages == 0) {
        return 5;
    }
    ret = osPfsFindFile(pfs, 0, 0, 0, 0, fileNo);
    if (ret != 0 && ret != 5) {
        return ret;
    }
    if (*fileNo == -1) {
        return 8;
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
                firstPage.t.page = startPage;
                firstPage.t.bank = bank;
            } else {
                backup.inodePage[prevPage].t.bank = bank;
                backup.inodePage[prevPage].t.page = startPage;
                ret = __osPfsRWInode(pfs, &backup, 1, oldBank);
                if (ret != 0) {
                    return ret;
                }
            }
            if (declPage < fileSizeInPages) {
                bcopy(&inode, &backup, 0x100);
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
        return 3;
    }
    dir.startPage = firstPage;
    dir.dataSum = 0;
    dir.companyCode = companyCode;
    dir.gameCode = gameCode;
    bcopy(gameName, dir.gameName, 16);
    bcopy(extName, dir.extName, 4);
    return __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + *fileNo, (u8 *)&dir, 0);
}
