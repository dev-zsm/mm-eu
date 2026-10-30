// FLAGS: -O2 -g0
#include "libm.h"

/* Builds a float in [1, 2) from the high bits of the state, then returns it minus 1. */
f32 Rand_ZeroOne(void) {
    D_800976D0 = D_800976D0 * 0x19660D + 0x3C6EF35F;
    D_8009D120 = (D_800976D0 >> 9) | 0x3F800000;
    return *(f32 *)&D_8009D120 - 1.0f;
}
