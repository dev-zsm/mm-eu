// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "libultra_libc.h"

s32 corrupted_init(OSPfs *pfs, __OSInodeCache *cache) {
    s32 i;
    s32 n;
    s32 offset;
    u8 bank;
    __OSInodeUnit tpage;
    __OSInode tempInode;
    s32 ret;

    for (i = 0; i < 256; i++) {
        cache->map[i] = 0;
    }
    cache->bank = 255;
    for (bank = 0; bank < pfs->banks; bank++) {
        if (bank > 0) {
            offset = 1;
        } else {
            offset = pfs->inodeStartPage;
        }
        ret = __osPfsRWInode(pfs, &tempInode, 0, bank);
        if (ret != 0 && ret != 3) {
            return ret;
        }
        for (i = offset; i < 128; i++) {
            tpage = tempInode.inodePage[i];
            if (tpage.ipage >= pfs->inodeStartPage && tpage.inode_t.bank != bank) {
                n = (tpage.inode_t.page & 0x7F) / 4 + (tpage.inode_t.bank % 8) * 32;
                cache->map[n] |= 1 << (bank % 8);
            }
        }
    }
    return 0;
}
