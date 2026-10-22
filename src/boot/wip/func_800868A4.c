// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_80099350;

// best attempt: ~4 real diffs (missing nop before loop at +0x14; next-sum temp is f18 instead of f16)
f32 func_800868A4(f32 arg0) {
    f32 sq, cube, sum, t, nx;
    f32 *p;

    sq = arg0 * arg0;
    sum = arg0;
    p = &D_80099350;
    cube = arg0 * sq;
    for (;;) {
        t = *p * cube;
        p++;
        nx = sum + t;
        if (sum == nx) break;
        cube *= sq;
        sum = nx;
    }
    return sum;
}
