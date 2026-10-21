// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_80099374;
extern f32 D_80099378;
extern f32 D_8009937C;
extern f32 D_80099380;
extern f32 D_800976C4;
f32 func_800868A4(f32 arg0);

f32 func_800868F0(f32 arg0) {
    f32 ax;
    f32 temp_f2;
    f32 r;

    if (arg0 > 0.0f) {
        ax = arg0;
    } else if (arg0 < 0.0f) {
        ax = -arg0;
    } else if (arg0 == 0.0f) {
        return 0.0f;
    } else {
        return D_800976C4;
    }

    if (ax <= D_80099374) {
        return func_800868A4(arg0);
    }
    if (D_80099378 <= ax) {
        r = func_800868A4(1.0f / ax);
        temp_f2 = D_8009937C - r;
    } else {
        r = func_800868A4((1.0f - ax) / (1.0f + ax));
        temp_f2 = D_80099380 - r;
    }
    if (arg0 > 0.0f) {
        return temp_f2;
    }
    return -temp_f2;
}
