// FLAGS: -O2 -g0
#include "types.h"
extern u32 D_8009D120;

f32 Rand_Centered_Variable(u32 *a) {
    u32 v = *a * 0x19660D + 0x3C6EF35F;
    *a = v;
    D_8009D120 = (v >> 9) | 0x3F800000;
    return *(f32 *)&D_8009D120 - 1.5f;
}
