// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 pad[0x2D0]; } Reverb;
typedef struct {
    s8 unk0;
    s8 numReverbs;
    u8 pad2[0x16];
    Reverb reverbs[1];
} AudioHeapState;

extern AudioHeapState D_801F84B0;
void AudioHeap_UpdateReverb(Reverb *reverb);

void AudioHeap_UpdateReverbs(void) {
    s32 i;
    s32 j;
    s32 count;

    if (*(s16 *)((u8 *)&D_801F84B0 + 0x286C) == 2) {
        count = 2;
    } else {
        count = 1;
    }
    for (i = 0; i < D_801F84B0.numReverbs; i++) {
        for (j = 0; j < count; j++) {
            AudioHeap_UpdateReverb(&D_801F84B0.reverbs[i]);
        }
    }
}
