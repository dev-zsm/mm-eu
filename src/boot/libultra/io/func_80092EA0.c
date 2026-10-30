// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "os_pfs.h"

s32 osPfsFileState(OSPfs *pfs, s32 fileNo, OSPfsState *state) {
    s32 ret;
    s32 sum;
    __OSInode inode;
    __OSDir dir;
    __OSInodeUnit next;
    u8 bank;

    if (fileNo >= pfs->dirSize || fileNo < 0) {
        return PFS_ERR_INVALID;
    }
    if (!(pfs->status & PFS_INITIALIZED)) {
        return PFS_ERR_INVALID;
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
    ret = __osContRamRead(pfs->queue, pfs->channel, pfs->dirTable + fileNo, (u8 *)&dir);
    if (ret != 0) {
        return ret;
    }
    if (dir.companyCode == 0 || dir.gameCode == 0) {
        return PFS_ERR_INVALID;
    }
    next = dir.startPage;
    sum = 0;
    bank = 0xFF;
    for (;;) {
        if (next.ipage < pfs->inodeStartPage) {
            break;
        }
        if (next.inode_t.bank != bank) {
            bank = next.inode_t.bank;
            ret = __osPfsRWInode(pfs, &inode, 0, bank);
            if (ret != 0) {
                return ret;
            }
        }
        sum++;
        next = inode.inodePage[next.inode_t.page];
    }
    if (next.ipage != 1) {
        return PFS_ERR_INCONSISTENT;
    }
    state->fileSize = sum << 8;
    state->companyCode = dir.companyCode;
    state->gameCode = dir.gameCode;
    bcopy(dir.gameName, state->gameName, 16);
    bcopy(dir.extName, state->extName, 4);
    return __osPfsGetStatus(pfs->queue, pfs->channel);
}
