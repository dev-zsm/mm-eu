// FLAGS: -O2 -g0
#include "libm.h"

void Rand_Seed(u32 seed) {
    D_800976D0 = seed;
}
