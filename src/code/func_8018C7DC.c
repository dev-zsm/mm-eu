// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x4454];
    /* 0x4454 */ s32 unk4454;
    /* 0x4458 */ s32 unk4458;
} AudioContext;

extern AudioContext D_801F84B0;
extern u8 D_801FAE70[];
extern s32 D_801FAE80;
extern u8 D_801FAE90[];
extern s32 D_801FC904;

void AudioHeap_InitPool(void *pool, s32 start, s32 size);

void AudioHeap_InitMainPool(s32 size) {
    AudioHeap_InitPool(D_801FAE90, D_801FC904, size);
    AudioHeap_InitPool(D_801FAE70, D_801F84B0.unk4454 + size, D_801F84B0.unk4458 - size);
    D_801FAE80 = 0;
}
