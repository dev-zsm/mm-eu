// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
extern f32 D_801C9EA0[];
extern f32 D_801C9ED0;
f32 func_8017A6B0(s32 n) {
    f32 r;
    s32 i;
    if (n >= 13) {
        r = D_801C9ED0;
        for (i = 13; i <= n; i++) {
            r *= i;
        }
    } else {
        r = D_801C9EA0[n];
    }
    return r;
}
