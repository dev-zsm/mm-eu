// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u16 unk0;
    u8 pad2[0x21A];
} SeqRequestInfo;

void AudioThread_QueueCmdS32(u32 opArgs, s32 data);
extern u16 D_801FAD28;
extern SeqRequestInfo D_801F7B8A[];

void AudioSeq_StopSequence(u8 seqPlayerIndex, u16 fadeOutDuration) {
    // the (u32) cast is only there to match (it keeps the index in its stack home)
    AudioThread_QueueCmdS32(0x83000000 | ((u32)seqPlayerIndex << 16), (fadeOutDuration * D_801FAD28) / 4);
    D_801F7B8A[seqPlayerIndex].unk0 = 0xFFFF;
}
