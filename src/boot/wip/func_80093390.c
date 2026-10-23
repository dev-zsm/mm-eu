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
    u8 pad[0x204];
} InodeCache;

typedef struct {
    s32 status;
    void *queue;
    s32 channel;
    u8 pad0[0x48];
    s32 dirSize;
    s32 inodeTable;
    s32 minodeTable;
    s32 dirTable;
    s32 inodeStartPage;
    u8 banks;
    u8 activeBank;
} Pfs;

s32 __osCheckId(Pfs *pfs);
s32 __osGetId(Pfs *pfs);
s32 corrupted_init(Pfs *pfs, InodeCache *cache);
s32 corrupted(Pfs *pfs, InodeUnit fixed, InodeCache *cache);
s32 __osContRamRead(void *mq, s32 channel, u16 address, void *buffer);
s32 __osContRamWrite(void *mq, s32 channel, u16 address, void *buffer, s32 force);
s32 __osPfsRWInode(Pfs *pfs, Inode *inode, u8 flag, u8 bank);
s32 __osPfsSelectBank(Pfs *pfs, u8 bank);
void bzero(void *p, s32 n);

s32 osPfsChecker(Pfs *pfs) {
    InodeUnit map[16];
    InodeCache cc;
    s32 isCorrupted = 0;
    Inode inode;
    Inode tmpInode;
    InodeUnit tmp;
    Dir dir;
    InodeUnit next;
    s32 ret;
    s32 j;
    s32 k;
    s32 offset;
    u8 bank;
    u8 lastBank = 0xFE;
    s32 first;
    s32 diff;

    ret = __osCheckId(pfs);
    if (ret == 2) {
        ret = __osGetId(pfs);
    }
    if (ret != 0) {
        return ret;
    }
    ret = corrupted_init(pfs, &cc);
    if (ret != 0) {
        return ret;
    }
    for (j = 0; j < pfs->dirSize; j++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + j, &dir);
        if (ret != 0) {
            return ret;
        }
        if (dir.companyCode != 0 || dir.gameCode != 0) {
            if (dir.companyCode == 0 || dir.gameCode == 0) {
                diff = -1;
            } else {
                diff = 0;
                first = 0;
                next = dir.startPage;
                if (next.ipage >= pfs->inodeStartPage && next.t.bank < pfs->banks && next.t.page > 0 && next.t.page < 128) {
                    bank = 0xFF;
                    do {
                        if (next.t.bank != bank) {
                            bank = next.t.bank;
                            if (next.t.bank != lastBank) {
                                ret = __osPfsRWInode(pfs, &inode, 0, next.t.bank);
                                lastBank = next.t.bank;
                            }
                            if (ret != 0 && ret != 3) {
                                return ret;
                            }
                        }
                        diff = corrupted(pfs, next, &cc) - first;
                        if (diff != 0) {
                            break;
                        }
                        first = 1;
                        next = inode.inodePage[next.t.page];
                    } while (next.ipage >= pfs->inodeStartPage && next.t.bank < pfs->banks && next.t.page > 0 && next.t.page < 128);
                }
            }
            if (diff != 0 || next.ipage != 1) {
                bzero(&dir, 0x20);
                if (pfs->activeBank != 0) {
                    ret = __osPfsSelectBank(pfs, 0);
                    if (ret != 0) {
                        return ret;
                    }
                }
                ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + j, &dir, 0);
                if (ret != 0) {
                    return ret;
                }
                isCorrupted++;
            }
        }
    }
    for (j = 0; j < pfs->dirSize; j++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + j, &dir);
        if (ret != 0) {
            return ret;
        }
        if (dir.companyCode != 0 && dir.gameCode != 0 && dir.startPage.ipage >= (u16)pfs->inodeStartPage) {
            map[j] = dir.startPage;
        } else {
            map[j].ipage = 0;
        }
    }
    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &inode, 0, bank);
        if (ret != 0 && ret != 3) {
            return ret;
        }
        if (bank > 0) {
            offset = 1;
        } else {
            offset = pfs->inodeStartPage;
        }
        for (k = 0; k < offset; k++) {
            tmpInode.inodePage[k].ipage = inode.inodePage[k].ipage;
        }
        for (k = k; k < 128; k++) {
            tmpInode.inodePage[k].ipage = 3;
        }
        for (j = 0; j < pfs->dirSize; j++) {
            if (bank == map[j].t.bank && map[j].ipage >= (u16)pfs->inodeStartPage) {
                do {
                    tmp = inode.inodePage[map[j].t.page];
                    tmpInode.inodePage[map[j].t.page] = tmp;
                    map[j] = tmp;
                } while (bank == map[j].t.bank && map[j].ipage >= (u16)pfs->inodeStartPage);
            }
        }
        ret = __osPfsRWInode(pfs, &tmpInode, 1, bank);
        if (ret != 0) {
            return ret;
        }
    }
    if (isCorrupted != 0) {
        pfs->status |= 2;
    } else {
        pfs->status &= ~2;
    }
    return 0;
}
