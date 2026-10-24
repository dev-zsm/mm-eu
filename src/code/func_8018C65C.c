// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 pad18[6];
    s16 unk1E;
    s32 unk20;
    u8 pad24[6];
    s16 unk2A;
} Heap;

void AudioHeap_InitTemporaryCache(Heap *arg0) {
    arg0->unk10 = 0;
    arg0->unk0 = 0;
    arg0->unk20 = arg0->unk4 + arg0->unkC;
    arg0->unk1E = -1;
    arg0->unk2A = -1;
    arg0->unk8 = arg0->unk4;
    arg0->unk14 = arg0->unk4;
}
