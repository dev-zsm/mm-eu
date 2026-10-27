#include "types.h"

extern s16 D_801CB7B0[];

void AudioHeap_LoadLowPassFilter(s16 *filter, s32 index) {
    s32 i;

    for (i = 0; i < 8; i++) {
        filter[i] = D_801CB7B0[index * 8 + i];
    }
}
