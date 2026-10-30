// FLAGS: -O2 -g0
#include "libm.h"

f32 Rand_Centered_Variable(u32 *rand) {
    u32 state = *rand * 0x19660D + 0x3C6EF35F;

    *rand = state;
    D_8009D120 = (state >> 9) | 0x3F800000;
    return *(f32 *)&D_8009D120 - 1.5f;
}
