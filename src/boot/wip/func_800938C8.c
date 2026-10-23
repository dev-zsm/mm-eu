// FLAGS: -O2 -g0 -mips2
// best attempt (94/182 differ): ROM keeps 3 extra words above tmp (unknown locals), and inode at 0x58
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    s32 inodeStartPage;
    u8 banks;
} Ctx;

typedef union {
    u16 ipage;
    struct {
        u8 bank;
        u8 page;
    } t;
} InodeUnit;

s32 __osPfsRWInode(Ctx *pfs, u16 *inode, s32 mode, u8 bank);

s32 corrupted_init(Ctx *pfs, u8 *cache) {
    InodeUnit tmp;
    u16 inode[0x80];
    s32 j;
    s32 start;
    s32 idx;
    s32 ret;
    u8 bank;

    for (j = 0; j < 0x100; j++) {
        cache[0x101 + j] = 0;
    }
    cache[0x100] = 0xFF;
    for (bank = 0; bank < pfs->banks; bank++) {
        if (bank > 0) {
            start = 1;
        } else {
            start = pfs->inodeStartPage;
        }
        ret = __osPfsRWInode(pfs, inode, 0, bank);
        if (ret != 0 && ret != 3) {
            return ret;
        }
        for (j = start; j < 0x80; j++) {
            tmp = *(InodeUnit *)&inode[j];
            if (tmp.ipage >= pfs->inodeStartPage && tmp.t.bank != bank) {
                idx = (tmp.t.page & 0x7F) / 4 + (tmp.t.bank % 8) * 32;
                cache[0x101 + idx] |= 1 << (bank % 8);
            }
        }
    }
    return 0;
}
