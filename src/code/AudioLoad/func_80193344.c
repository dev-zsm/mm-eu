#include "types.h"

typedef struct {
    u32 unk0 : 4;
    u32 unk1 : 2;
    u32 unk2 : 1;
    u32 unk3 : 1;
    u32 size : 24;
} Sample;

typedef struct {
    u8 pad0[0xB88];
    Sample *usedSamples[0x300];
    s32 numUsedSamples;
} AudioState;

extern AudioState D_801F84B0;

void AudioLoad_AddUsedSample(Sample **sampleP) {
    Sample *sample = *sampleP;

    if (sample->size != 0 && sample->unk2 && sample->unk1 != 0) {
        D_801F84B0.usedSamples[D_801F84B0.numUsedSamples] = sample;
        D_801F84B0.numUsedSamples++;
    }
}
