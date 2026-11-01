#include "types.h"

typedef struct {
    s16 coefs[8];
} HighPassFilter;

extern HighPassFilter D_801CB8B0[];

/* 18 instructions differ: the instruction sequence is right but IDO allocates different registers. */
void AudioHeap_LoadHighPassFilter(s16 *dest, s32 index) {
    s16 *src = D_801CB8B0[index - 1].coefs;
    s16 *d = dest;
    s32 i;

    for (i = 0; i < 8; i += 4) {
        d[0] = src[0];
        d[1] = src[1];
        d[2] = src[2];
        d[3] = src[3];
        d += 4;
        src += 4;
    }
}
