// FLAGS: -O2 -g0
#include "libm.h"

/*
 * Single-precision arctangent. Reduces |x| with atan(1/x) = pi/2 - atan(x)
 * and atan(x) = pi/4 - atan((1-x)/(1+x)), then calls the series Math_FAtanTaylorQF.
 */
f32 Math_FAtanTaylorF(f32 x) {
    f32 absX;
    f32 angle;
    f32 reduced;

    if (x > 0.0f) {
        absX = x;
    } else if (x < 0.0f) {
        absX = -x;
    } else if (x == 0.0f) {
        return 0.0f;
    } else {
        return D_800976C4;
    }

    if (absX <= D_80099374) {
        return Math_FAtanTaylorQF(x);
    }
    if (D_80099378 <= absX) {
        reduced = Math_FAtanTaylorQF(1.0f / absX);
        angle = D_8009937C - reduced;
    } else {
        reduced = Math_FAtanTaylorQF((1.0f - absX) / (1.0f + absX));
        angle = D_80099380 - reduced;
    }
    if (x > 0.0f) {
        return angle;
    }
    return -angle;
}
