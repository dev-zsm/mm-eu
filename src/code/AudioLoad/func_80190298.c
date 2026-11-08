#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801F84B0[];

void AudioLoad_SetSeqLoadStatus(s32 seqId, s32 loadStatus) {
    if (seqId != 0xFF) {
        if (D_801F84B0[seqId + 0x43C8] != 5) {
            D_801F84B0[seqId + 0x43C8] = loadStatus;
        }
    }
}
