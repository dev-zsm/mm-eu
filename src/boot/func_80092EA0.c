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
    u32 fileSize;
    u32 gameCode;
    u16 companyCode;
    u8 extName[4];
    u8 gameName[16];
} PfsState;

typedef struct {
    s32 status;
    void *queue;
    s32 channel;
    u8 id[32];
    u8 label[32];
    s32 version;
    s32 dirSize;
    s32 inodeTable;
    s32 minodeTable;
    s32 dirTable;
    s32 inodeStartPage;
    u8 banks;
    u8 activeBank;
} Pfs;

s32 __osCheckId(Pfs *pfs);
s32 __osPfsSelectBank(Pfs *pfs, u8 bank);
s32 __osContRamRead(void *queue, s32 channel, u16 address, void *buffer);
s32 __osPfsRWInode(Pfs *pfs, Inode *inode, u8 flag, u8 bank);
s32 __osPfsGetStatus(void *queue, s32 channel);
void bcopy(void *src, void *dst, s32 n);

s32 osPfsFileState(Pfs *pfs, s32 fileNo, PfsState *state) {
    s32 ret;
    s32 sum;
    Inode inode;
    Dir dir;
    InodeUnit next;
    u8 bank;

    if (fileNo >= pfs->dirSize || fileNo < 0) {
        return 5;
    }
    if (!(pfs->status & 1)) {
        return 5;
    }
    ret = __osCheckId(pfs);
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
    if (dir.companyCode == 0 || dir.gameCode == 0) {
        return 5;
    }
    next = dir.startPage;
    sum = 0;
    bank = 0xFF;
    for (;;) {
        if (next.ipage < pfs->inodeStartPage) {
            break;
        }
        if (next.t.bank != bank) {
            bank = next.t.bank;
            ret = __osPfsRWInode(pfs, &inode, 0, bank);
            if (ret != 0) {
                return ret;
            }
        }
        sum++;
        next = inode.inodePage[next.t.page];
    }
    if (next.ipage != 1) {
        return 3;
    }
    state->fileSize = sum << 8;
    state->companyCode = dir.companyCode;
    state->gameCode = dir.gameCode;
    bcopy(dir.gameName, state->gameName, 16);
    bcopy(dir.extName, state->extName, 4);
    return __osPfsGetStatus(pfs->queue, pfs->channel);
}
