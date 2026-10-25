// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801F84B0[];
extern s32 AudioLoad_SyncInitSeqPlayerInternal(s32 playerIdx, s32 seqId);

s32 AudioLoad_SyncInitSeqPlayer(s32 playerIdx, s32 seqId) {
    if (*(s32 *)(D_801F84B0 + 0x29A4) != 0) {
        return 0;
    }
    *(s32 *)(D_801F84B0 + 0x453C + playerIdx * 0x160) = 0;
    return AudioLoad_SyncInitSeqPlayerInternal(playerIdx, seqId);
}
