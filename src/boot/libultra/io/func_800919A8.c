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
} Pfs;

s32 __osPfsReleasePages(Pfs *pfs, InodeUnit *inode, u8 start_page, u8 bank, InodeUnit *final_page) {
    InodeUnit last_page;
    InodeUnit old_page;

    last_page.ipage = (bank << 8) + start_page;
    do {
        old_page = last_page;
        last_page = inode[last_page.t.page];
        inode[old_page.t.page].ipage = 3;
    } while (last_page.ipage >= pfs->inodeStartPage && last_page.t.bank == bank);
    *final_page = last_page;
    return 0;
}
