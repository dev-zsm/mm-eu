// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
// best attempt: 33/181 instr differ (locals stack slots 4 bytes lower than ROM, register naming in sum compare)
#include "types.h"

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

extern s32 D_800980F0;
extern u8 D_800980F4;
extern u8 D_8009E7E0[];

u32 __osSumcalc(u8 *ptr, s32 length);
void bcopy(void *src, void *dst, s32 n);
s32 __osPfsSelectBank(Pfs *pfs, u8 bank);
s32 __osContRamWrite(void *mq, s32 channel, u16 address, u8 *buffer, s32 force);
s32 __osContRamRead(void *mq, s32 channel, u16 address, u8 *buffer);

s32 __osPfsRWInode(Pfs *pfs, u8 *inode, u8 flag, u8 bank) {
    s32 j;
    s32 ret;
    u8 *addr;
    s32 offset;
    u8 *ptr;
    u8 sum;

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
    if (bank > 0) {
        offset = 1;
    } else {
        offset = pfs->inodeStartPage;
    }
    if (flag == 1) {
        addr = inode + offset * 2;
        inode[1] = __osSumcalc(addr, -offset * 2 + 0x100);
    }
    ptr = inode;
    for (j = 0; j < 8; j++) {
        if (flag == 1) {
            __osContRamWrite(pfs->queue, pfs->channel, pfs->inodeTable + bank * 8 + j, ptr, 0);
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minodeTable + bank * 8 + j, ptr, 0);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inodeTable + bank * 8 + j, ptr);
        }
        if (ret != 0) {
            return ret;
        }
        ptr += 0x20;
    }
    if (flag == 0) {
        addr = inode + offset * 2;
        sum = __osSumcalc(addr, -offset * 2 + 0x100);
        if (sum != inode[1]) {
            ptr = inode;
            for (j = 0; j < 8; j++) {
                __osContRamRead(pfs->queue, pfs->channel, pfs->minodeTable + bank * 8 + j, ptr);
                ptr += 0x20;
            }
            sum = __osSumcalc(addr, -offset * 2 + 0x100);
            if (sum != inode[1]) {
                return 3;
            }
            ptr = inode;
            for (j = 0; j < 8; j++) {
                __osContRamWrite(pfs->queue, pfs->channel, pfs->inodeTable + bank * 8 + j, ptr, 0);
                ptr += 0x20;
            }
        }
    }
    D_800980F4 = bank;
    bcopy(inode, D_8009E7E0, 0x100);
    D_800980F0 = pfs->channel;
    return 0;
}
