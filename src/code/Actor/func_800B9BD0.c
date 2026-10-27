// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 Actor_AddToLensActors(u8 *a0, s32 a1) {
    u8 n = a0[0x1CAF];
    if (n >= 0x20) {
        return 0;
    }
    *(s32 *)(a0 + (n << 2) + 0x1D40) = a1;
    a0[0x1CAF] = a0[0x1CAF] + 1;
    return 1;
}
