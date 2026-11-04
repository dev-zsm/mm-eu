// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    void *sampleAddr;
} Sample;

s32 AudioLoad_AddToSampleSet(Sample *sample, s32 numSamples, Sample **set) {
    s32 i;

    for (i = 0; i < numSamples; i++) {
        if (sample->sampleAddr == set[i]->sampleAddr) {
            break;
        }
    }
    if (i == numSamples) {
        set[numSamples++] = sample;
    }
    return numSamples;
}
