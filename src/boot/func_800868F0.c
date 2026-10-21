// FLAGS: -O2 -g0
#include "types.h"

extern f32 D_80099374;   /* small-|x| threshold: use the kernel directly */
extern f32 D_80099378;   /* large-|x| threshold: reduce with 1/x */
extern f32 D_8009937C;   /* pi/2 */
extern f32 D_80099380;   /* pi/4 */
extern f32 D_800976C4;   /* NaN result */
f32 func_800868A4(f32 arg0);

/*
 * Single-precision arctangent (atanf). Reduces |x| with atan(1/x) = pi/2 - atan(x)
 * and atan(x) = pi/4 - atan((1-x)/(1+x)), then calls the kernel func_800868A4.
 * The D_8009937x values are inferred from those identities, not checked against the ROM data.
 */
f32 func_800868F0(f32 x) {
    f32 abs_x;
    f32 angle;
    f32 reduced;

    if (x > 0.0f) {
        abs_x = x;
    } else if (x < 0.0f) {
        abs_x = -x;
    } else if (x == 0.0f) {
        return 0.0f;
    } else {
        return D_800976C4;
    }

    if (abs_x <= D_80099374) {
        return func_800868A4(x);
    }
    if (D_80099378 <= abs_x) {
        reduced = func_800868A4(1.0f / abs_x);
        angle = D_8009937C - reduced;
    } else {
        reduced = func_800868A4((1.0f - abs_x) / (1.0f + abs_x));
        angle = D_80099380 - reduced;
    }
    if (x > 0.0f) {
        return angle;
    }
    return -angle;
}
