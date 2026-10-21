// FLAGS: -O2 -g0
#include "types.h"
extern u32 D_800976D0;
extern u32 D_8009D120;
f32 func_8008704C(void) {
    u32 *a = &D_800976D0;
    u32 *b = &D_8009D120;
    u32 seed = *a * 0x19660D + 0x3C6EF35F;
    u32 t = (seed >> 9) | 0x3F800000;
    *b = t;
    *a = seed;
    return *(f32 *)b - 1.0f;
}
