#include "types.h"
extern u32 D_801FB120;
extern s16 D_801FB212;
extern s16 D_801FB21E;
void AudioHeap_DiscardSampleBank(s16);
void AudioHeap_DiscardSampleBanks(void) {
    u8 *p;
    u32 i;
    if (D_801FB212 != -1) {
        AudioHeap_DiscardSampleBank(D_801FB212);
    }
    if (D_801FB21E != -1) {
        AudioHeap_DiscardSampleBank(D_801FB21E);
    }
    p = (u8 *)&D_801FB120;
    for (i = 0; i < D_801FB120; i++) {
        AudioHeap_DiscardSampleBank(*(s16 *)(p + 0x1E));
        p += 0xC;
    }
}
