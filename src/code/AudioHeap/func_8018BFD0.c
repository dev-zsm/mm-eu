// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_801FAD3C;

f32 AudioHeap_CalculateAdsrDecay(f32 arg0) {
    return (256.0f * D_801FAD3C) / arg0;
}
