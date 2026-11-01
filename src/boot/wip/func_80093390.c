// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// matching: best attempt, 46/334 instructions differ (temp register choice for the nextNodeInFile pointer and call argument hoisting)
#include "types.h"

typedef struct {
    s32 status;
    void *queue;
    s32 channel;
    u8 pad0[0x44];
    s32 dirSize;
    s32 inodeTable;
    s32 minodeTable;
    s32 dirTable;
    s32 inodeStartPage;
    u8 banks;
    u8 activeBank;
} OSPfs;

typedef union {
    u16 ipage;
    struct {
        u8 bank;
        u8 page;
    } inode_t;
} __OSInodeUnit;

typedef struct {
    __OSInodeUnit inodePage[128];
} __OSInode;

typedef struct {
    u32 gameCode;
    u16 companyCode;
    __OSInodeUnit startPage;
    u8 status;
    s8 reserved;
    u16 dataSum;
    u8 extName[4];
    u8 gameName[16];
} __OSDir;

typedef struct {
    __OSInode inode;
    u8 bank;
    u8 map[256];
} __OSInodeCache;

#define CHECK_IPAGE(p)                                                                         \
    ((p).ipage >= pfs->inodeStartPage && (p).inode_t.bank < pfs->banks && (p).inode_t.page > 0 && \
     (p).inode_t.page < 128)

s32 __osCheckId(OSPfs *pfs);
s32 __osGetId(OSPfs *pfs);
s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache);
s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);
s32 __osContRamRead(void *mq, s32 channel, u16 address, void *buffer);
s32 __osContRamWrite(void *mq, s32 channel, u16 address, void *buffer, s32 force);
s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);
s32 __osPfsSelectBank(OSPfs *pfs, u8 bank);
void bzero(void *p, s32 n);

s32 osPfsChecker(OSPfs *pfs) {
    s32 j;
    s32 ret;
    __OSInodeUnit next;
    __OSInode checkedInode;
    __OSInode tempInode;
    __OSDir tempDir;
    __OSInodeUnit nextNodeInFile[16];
    __OSInodeCache cache;
    s32 fixed = 0;
    u8 bank = 254;
    u8 prevBank = 254;
    s32 cl;
    s32 cc;
    s32 offset;
    __OSInodeUnit tmp;

    ret = __osCheckId(pfs);
    if (ret == 2) {
        ret = __osGetId(pfs);
    }
    if (ret != 0) {
        return ret;
    }
    ret = corrupted_init(pfs, &cache);
    if (ret != 0) {
        return ret;
    }
    for (j = 0; j < pfs->dirSize; j++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + j, &tempDir);
        if (ret != 0) {
            return ret;
        }
        if (tempDir.companyCode != 0 || tempDir.gameCode != 0) {
            if (tempDir.companyCode == 0 || tempDir.gameCode == 0) {
                cc = -1;
            } else {
                next = tempDir.startPage;
                cl = cc = 0;
                bank = 255;
                while (CHECK_IPAGE(next)) {
                    if (bank != next.inode_t.bank) {
                        bank = next.inode_t.bank;
                        if (prevBank != bank) {
                            ret = __osPfsRWInode(pfs, &tempInode, 0, bank);
                            prevBank = bank;
                        }
                        if (ret != 0 && ret != 3) {
                            return ret;
                        }
                    }
                    cc = corrupted(pfs, next, &cache) - cl;
                    if (cc != 0) {
                        break;
                    }
                    cl = 1;
                    next = tempInode.inodePage[next.inode_t.page];
                }
            }
            if (cc != 0 || next.ipage != 1) {
                bzero(&tempDir, sizeof(__OSDir));
                if (pfs->activeBank != 0) {
                    ret = __osPfsSelectBank(pfs, 0);
                    if (ret != 0) {
                        return ret;
                    }
                }
                ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->dirTable + j, &tempDir, 0);
                if (ret != 0) {
                    return ret;
                }
                fixed++;
            }
        }
    }
    for (j = 0; j < pfs->dirSize; j++) {
        ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + j, &tempDir);
        if (ret != 0) {
            return ret;
        }
        if (tempDir.companyCode != 0 && tempDir.gameCode != 0 && tempDir.startPage.ipage >= (u16)pfs->inodeStartPage) {
            nextNodeInFile[j].ipage = tempDir.startPage.ipage;
        } else {
            nextNodeInFile[j].ipage = 0;
        }
    }
    for (bank = 0; bank < pfs->banks; bank++) {
        ret = __osPfsRWInode(pfs, &tempInode, 0, bank);
        if (ret != 0 && ret != 3) {
            return ret;
        }
        if (bank > 0) {
            offset = 1;
        } else {
            offset = pfs->inodeStartPage;
        }
        for (j = 0; j < offset; j++) {
            checkedInode.inodePage[j].ipage = tempInode.inodePage[j].ipage;
        }
        for (; j < 128; j++) {
            checkedInode.inodePage[j].ipage = 3;
        }
        for (j = 0; j < pfs->dirSize; j++) {
            if (bank == nextNodeInFile[j].inode_t.bank && nextNodeInFile[j].ipage >= (u16)pfs->inodeStartPage) {
                do {
                    tmp = tempInode.inodePage[nextNodeInFile[j].inode_t.page];
                    checkedInode.inodePage[nextNodeInFile[j].inode_t.page] = tmp;
                    nextNodeInFile[j] = tmp;
                } while (bank == nextNodeInFile[j].inode_t.bank && nextNodeInFile[j].ipage >= (u16)pfs->inodeStartPage);
            }
        }
        ret = __osPfsRWInode(pfs, &checkedInode, 1, bank);
        if (ret != 0) {
            return ret;
        }
    }
    if (fixed != 0) {
        pfs->status |= 2;
    } else {
        pfs->status &= ~2;
    }
    return 0;
}
