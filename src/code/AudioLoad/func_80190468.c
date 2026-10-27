// FLAGS: -O2 -g0 -mips2
#include "types.h"

void AudioLoad_SyncLoadSeqFonts(s32 seqId, u32 *outFontId);
void AudioLoad_SyncLoadSeq(s32 seqId);
s32 func_80087CB0(void *mq, void *msg, s32 flag);
extern u16 D_801FAD14;

void AudioLoad_SyncLoadSeqParts(s32 seqId, s32 flags, s32 retData, void *retQueue) {
    s32 pad; // only to match the stack layout
    u32 fontId;

    if (seqId < D_801FAD14) {
        if (flags & 2) {
            AudioLoad_SyncLoadSeqFonts(seqId, &fontId);
        }
        if (flags & 1) {
            AudioLoad_SyncLoadSeq(seqId);
        }
        if (retData != 0) {
            func_80087CB0(retQueue, (void *)(retData << 24), 0);
        }
    }
}
