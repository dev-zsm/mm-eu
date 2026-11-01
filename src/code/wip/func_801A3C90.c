#include "types.h"

extern u8 D_801CF030[];

extern u8 AudioSeq_GetActiveSeqId(u8 seqPlayerIndex);

s32 func_801A3C90(u8 seqId) {
    u8 flags = D_801CF030[seqId];
    u8 playerIndex = 0;

    if (flags & 2) {
        playerIndex = 1;
    } else if (flags & 4) {
        playerIndex = 1;
    }
    if (seqId == AudioSeq_GetActiveSeqId(playerIndex)) {
        return 1;
    }
    return 0;
}
