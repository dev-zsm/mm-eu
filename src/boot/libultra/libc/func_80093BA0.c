// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 pad0[0x60];
    s32 inodeStartPage;
    u8 banks;
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
    __OSInode inode;
    u8 bank;
    u8 map[256];
} __OSInodeCache;

s32 __osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank);

s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache) {
    s32 j;
    s32 n;
    s32 hit = 0;
    u8 bank;
    s32 offset;
    s32 ret = 0;

    n = (fpage.inode_t.page / 4) + (fpage.inode_t.bank % 8) * 32;
    for (bank = 0; bank < pfs->banks; bank++) {
        if (bank > 0) {
            offset = 1;
        } else {
            offset = pfs->inodeStartPage;
        }
        if (bank == fpage.inode_t.bank || (cache->map[n] & (1 << (bank % 8)))) {
            if (bank != cache->bank) {
                ret = __osPfsRWInode(pfs, &cache->inode, 0, bank);
                if (ret != 0 && ret != 3) {
                    return ret;
                }
                cache->bank = bank;
            }
            for (j = offset; hit < 2 && j < 128; j++) {
                if (fpage.ipage == cache->inode.inodePage[j].ipage) {
                    hit++;
                }
            }
            if (hit >= 2) {
                return 2;
            }
        }
    }
    return hit;
}
