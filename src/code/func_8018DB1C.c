#include "types.h"

typedef struct {
    u8 pad0[0x2876];
    s16 unk2876;
    u8 pad2878[0x28CC - 0x2878];
    s32 index;
    u8 pad28D0[0x2988 - 0x28D0];
    s16 *buffers[3];
    s16 sizes[3];
} AudioContext;

extern AudioContext D_801F84B0;

void AudioHeap_ClearAiBuffers(void) {
    s32 i;
    s32 index = D_801F84B0.index;

    D_801F84B0.sizes[index] = D_801F84B0.unk2876;
    for (i = 0; i < 0x580; i++) {
        D_801F84B0.buffers[index][i] = 0;
    }
}
