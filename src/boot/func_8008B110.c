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
    u8 pad0[0x60];
    s32 inodeStartPage;
    u8 banks;
} Pfs;

typedef struct {
    InodeUnit inodePage[128];
} Inode;

s32 __osPfsRWInode(Pfs *pfs, Inode *inode, u8 flag, u8 bank);

s32 __osPfsGetNextPage(Pfs *pfs, u8 *bank, Inode *inode, InodeUnit *page) {
    s32 ret;
    u16 v;

    if (page->t.bank != *bank) {
        *bank = page->t.bank;
        ret = __osPfsRWInode(pfs, inode, 0, *bank);
        if (ret != 0) {
            return ret;
        }
    }
    *page = inode->inodePage[page->t.page];
    v = page->ipage;
    if (v < pfs->inodeStartPage || page->t.bank >= pfs->banks || page->t.page <= 0 || page->t.page >= 128) {
        if (v == 1) {
            return 5;
        }
        return 3;
    }
    return 0;
}
