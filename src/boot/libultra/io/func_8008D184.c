// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"
// matching: offset via ternary, sum compared as inode->page != sum

typedef struct {
    s32 status;
    void *queue;
    s32 channel;
    u8 pad0[0x48];
    s32 inodeTable;
    s32 minodeTable;
    s32 dirTable;
    s32 inodeStartPage;
    u8 banks;
    u8 activeBank;
} Pfs;

typedef struct {
    u8 bank;
    u8 page;
    u8 pad[0xFE];
} Inode;

extern s32 D_800980F0;
extern u8 D_800980F4;
extern u8 D_8009E7E0[];

u32 __osSumcalc(u8 *ptr, s32 length);
void bcopy(void *src, void *dst, s32 n);
s32 __osPfsSelectBank(Pfs *pfs, u8 bank);
s32 __osContRamWrite(void *mq, s32 channel, u16 address, u8 *buffer, s32 force);
s32 __osContRamRead(void *mq, s32 channel, u16 address, u8 *buffer);

s32 __osPfsRWInode(Pfs *pfs, Inode *inode, u8 flag, u8 bank) {
    u8 sum;
    s32 j;
    s32 ret;
    s32 offset;
    u8 *addr;

    if (flag == 0 && bank == D_800980F4 && pfs->channel == D_800980F0) {
        bcopy(D_8009E7E0, inode, 0x100);
        return 0;
    }
    if (pfs->activeBank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    offset = (bank > 0) ? 1 : pfs->inodeStartPage;
    if (flag == 1) {
        inode->page = __osSumcalc(addr = (u8 *)inode + offset * 2, -offset * 2 + 0x100);
    }
    for (j = 0; j < 8; j++) {
        addr = (u8 *)inode + j * 0x20;
        if (flag == 1) {
            __osContRamWrite(pfs->queue, pfs->channel, pfs->inodeTable + bank * 8 + j, addr, 0);
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minodeTable + bank * 8 + j, addr, 0);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inodeTable + bank * 8 + j, addr);
        }
        if (ret != 0) {
            return ret;
        }
    }
    if (flag == 0) {
        sum = __osSumcalc(addr = (u8 *)inode + offset * 2, -offset * 2 + 0x100);
        if (inode->page != sum) {
            for (j = 0; j < 8; j++) {
                addr = (u8 *)inode + j * 0x20;
                __osContRamRead(pfs->queue, pfs->channel, pfs->minodeTable + bank * 8 + j, addr);
            }
            sum = __osSumcalc(addr = (u8 *)inode + offset * 2, -offset * 2 + 0x100);
            if (inode->page != sum) {
                return 3;
            }
            for (j = 0; j < 8; j++) {
                addr = (u8 *)inode + j * 0x20;
                __osContRamWrite(pfs->queue, pfs->channel, pfs->inodeTable + bank * 8 + j, addr, 0);
            }
        }
    }
    D_800980F4 = bank;
    bcopy(inode, D_8009E7E0, 0x100);
    D_800980F0 = pfs->channel;
    return 0;
}
