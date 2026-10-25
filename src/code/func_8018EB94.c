#include "types.h"

typedef struct {
    u8 flags;
    s8 unk1;
    u8 pad2[6];
    s32 unk8;
    s32 unkC;
} SampleCacheEntry;

typedef struct {
    u8 unk0_hi : 4;
    u8 unk0_mid : 2;
    u8 unk0_lo : 2;
    u8 pad1[3];
    s32 unk4;
} SampleCacheSample;

void AudioHeap_UnapplySampleCache(SampleCacheEntry *entry, SampleCacheSample *sample) {
    if (sample != NULL) {
        if (sample->unk4 == entry->unk8) {
            sample->unk4 = entry->unkC;
            sample->unk0_mid = entry->unk1;
        }
    }
}
