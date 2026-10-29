// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0xD];
    u8 unkD;
    u8 ttl;
    u8 pad0F;
} SampleDma;

typedef struct {
    u8 pad0[0x263C];
    SampleDma *entries;
    u32 numEntries;
    u32 numPersistent;
    u32 unk2648;
    u8 list0[0x100];
    u8 list1[0x100];
    u8 pad284C[2];
    u8 count0;
    u8 count1;
} AudioCtx;

extern AudioCtx D_801F84B0;

void AudioLoad_DecreaseSampleDmaTtls(void) {
    u32 i;
    SampleDma *dma;

    for (i = 0; i < D_801F84B0.numPersistent; i++) {
        dma = &D_801F84B0.entries[i];
        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->unkD = D_801F84B0.count0;
                D_801F84B0.list0[D_801F84B0.count0] = i;
                D_801F84B0.count0++;
            }
        }
    }
    for (i = D_801F84B0.numPersistent; i < D_801F84B0.numEntries; i++) {
        dma = &D_801F84B0.entries[i];
        if (dma->ttl != 0) {
            dma->ttl--;
            if (dma->ttl == 0) {
                dma->unkD = D_801F84B0.count1;
                D_801F84B0.list1[D_801F84B0.count1] = i;
                D_801F84B0.count1++;
            }
        }
    }
    D_801F84B0.unk2648 = 0;
}
