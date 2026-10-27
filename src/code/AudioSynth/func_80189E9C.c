// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xE];
    u16 unkE;
    s16 unk10;
    s16 unk12;
    u8 pad14[0x1C - 0x14];
} SubReverb;

typedef struct {
    u8 pad0[3];
    u8 index;
    u8 pad4[0x158 - 4];
    u8 table[1];
} SynthCtx;

void *AudioSynth_SaveReverbSamplesImpl(void *cmd, u16 a, u16 b, s16 c, SynthCtx *ctx);

void *AudioSynth_SaveSubReverbSamples(void *cmd, SynthCtx *ctx, s16 i) {
    SubReverb *sub;

    sub = (SubReverb *)(ctx->table + ctx->index * 0x8C + i * 0x1C);
    cmd = AudioSynth_SaveReverbSamplesImpl(cmd, 0xC70, sub->unkE, sub->unk10, ctx);
    if (sub->unk12 != 0) {
        cmd = AudioSynth_SaveReverbSamplesImpl(cmd, sub->unk10 + 0xC70, 0, sub->unk12, ctx);
    }
    return cmd;
}
