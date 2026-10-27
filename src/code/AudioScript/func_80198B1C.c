// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 enabled : 1;
    u8 finished : 1;
    u8 pad0b : 6;
    u8 pad1[0x1F];
    s16 unk20;
    u8 pad22[0x32];
    void *layers[4];
    s32 unk64;
    u8 pad68[0x14];
    u8 unk7C;
} Chan;
typedef struct { u8 pad0[0x38]; Chan *channels[16]; } Seq;

extern void AudioScript_SeqLayerFree(Chan *, s32);

void AudioScript_SequenceChannelEnable(Seq *seq, u8 idx, s32 script) {
    Chan *ch = seq->channels[idx];
    s32 i;

    ch->unk7C = 0;
    ch->unk64 = script;
    ch->enabled = 1;
    ch->finished = 0;
    ch->unk20 = 0;
    for (i = 0; i < 4; i++) {
        if (ch->layers[i] != 0) {
            AudioScript_SeqLayerFree(ch, i);
        }
    }
}
