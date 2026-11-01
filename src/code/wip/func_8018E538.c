// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[1];
    s8 medium;
    s8 unk2;
    u8 pad3[5];
    void *ramAddr;
    s32 unkC;
} SampleCacheEntry;

extern SampleCacheEntry *AudioHeap_AllocTemporarySampleCacheEntry();
extern SampleCacheEntry *AudioHeap_AllocPersistentSampleCacheEntry();

void *AudioHeap_AllocSampleCache(s32 arg0, s32 arg1, s32 arg2, s8 arg3, s32 persistent) {
    SampleCacheEntry *entry;

    if (persistent == 0) {
        entry = AudioHeap_AllocTemporarySampleCacheEntry();
    } else {
        entry = AudioHeap_AllocPersistentSampleCacheEntry();
    }
    if (entry != NULL) {
        entry->unk2 = arg1;
        entry->unkC = arg2;
        entry->medium = arg3;
        return entry->ramAddr;
    }
    return NULL;
}
