// FLAGS: -O2 -g0
#include "libm.h"

/* Single-precision atan2: the quotient y/x goes through Math_FAtanF, pi is added or subtracted by quadrant. */
f32 Math_FAtan2F(f32 y, f32 x) {
    if (x == 0.0f) {
        if (y == 0.0f) {
            return 0.0f;
        }
        if (0.0f < y) {
            return D_8009938C;
        }
        if (y < 0.0f) {
            return D_80099390;
        }
        return D_800976C4;
    }
    if (0.0f <= x) {
        return Math_FAtanF(y / x);
    }
    if (y < 0.0f) {
        return Math_FAtanF(y / x) - D_80099394;
    }
    return D_80099398 - Math_FAtanF(-(y / x));
}
