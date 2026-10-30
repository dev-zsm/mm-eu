// FLAGS: -O2 -g0
#include "libm.h"

f32 Rand_ZeroOne_Variable(u32 *rand) {
    u32 state = *rand * 0x19660D + 0x3C6EF35F;
    u32 bits = (state >> 9) | 0x3F800000;
    // matching: both stores stay on one line
    *rand = state; D_8009D120 = bits;
    return *(f32 *)&D_8009D120 - 1.0f;
}
