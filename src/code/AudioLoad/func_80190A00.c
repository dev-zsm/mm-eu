// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x15C];
} SeqPlayerEntry;

typedef struct {
    u8 pad0[0x29A4];
    s32 unk29A4;
    u8 pad29A8[0x1B94];
    SeqPlayerEntry seqPlayers[1];
} AudioContext;

extern AudioContext D_801F84B0;


s32 AudioLoad_SyncInitSeqPlayerSkipTicks(s32 seqPlayerIndex, s32 seqId, s32 skipTicks) {
    if (D_801F84B0.unk29A4 != 0) {
        return 0;
    }
    D_801F84B0.seqPlayers[seqPlayerIndex].unk0 = skipTicks;
    return AudioLoad_SyncInitSeqPlayerInternal(seqPlayerIndex, seqId, 0);
}
